/*
 * Component description for ETH
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
#ifndef _PIC32CZCA80_ETH_COMPONENT_H_
#define _PIC32CZCA80_ETH_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR ETH                                          */
/* ************************************************************************** */

/* -------- ETH_SAB : (ETH Offset: 0x00) (R/W 32) Specific Address Bottom [31:0] Register -------- */
#define ETH_SAB_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_SAB) Specific Address Bottom [31:0] Register  Reset Value */

#define ETH_SAB_ADDR_Pos                      _UINT32_(0)                                          /* (ETH_SAB) Specific Address 1 Position */
#define ETH_SAB_ADDR_Msk                      (_UINT32_(0xFFFFFFFF) << ETH_SAB_ADDR_Pos)           /* (ETH_SAB) Specific Address 1 Mask */
#define ETH_SAB_ADDR(value)                   (ETH_SAB_ADDR_Msk & (_UINT32_(value) << ETH_SAB_ADDR_Pos)) /* Assigment of value for ADDR in the ETH_SAB register */
#define ETH_SAB_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (ETH_SAB) Register Mask  */


/* -------- ETH_SAT : (ETH Offset: 0x04) (R/W 32) Specific Address Top [47:32] Register -------- */
#define ETH_SAT_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_SAT) Specific Address Top [47:32] Register  Reset Value */

#define ETH_SAT_ADDR_Pos                      _UINT32_(0)                                          /* (ETH_SAT) Specific Address 1 Position */
#define ETH_SAT_ADDR_Msk                      (_UINT32_(0xFFFF) << ETH_SAT_ADDR_Pos)               /* (ETH_SAT) Specific Address 1 Mask */
#define ETH_SAT_ADDR(value)                   (ETH_SAT_ADDR_Msk & (_UINT32_(value) << ETH_SAT_ADDR_Pos)) /* Assigment of value for ADDR in the ETH_SAT register */
#define ETH_SAT_Msk                           _UINT32_(0x0000FFFF)                                 /* (ETH_SAT) Register Mask  */


/* -------- ETH_SCRT2CMP0 : (ETH Offset: 0x00) (R/W 32) Screening Type 2 Compare Registers Word 0 -------- */
#define ETH_SCRT2CMP0_RESETVALUE              _UINT32_(0x00)                                       /*  (ETH_SCRT2CMP0) Screening Type 2 Compare Registers Word 0  Reset Value */

#define ETH_SCRT2CMP0_MASK_Pos                _UINT32_(0)                                          /* (ETH_SCRT2CMP0) 2Byte Mask/Compare Value Position */
#define ETH_SCRT2CMP0_MASK_Msk                (_UINT32_(0xFFFF) << ETH_SCRT2CMP0_MASK_Pos)         /* (ETH_SCRT2CMP0) 2Byte Mask/Compare Value Mask */
#define ETH_SCRT2CMP0_MASK(value)             (ETH_SCRT2CMP0_MASK_Msk & (_UINT32_(value) << ETH_SCRT2CMP0_MASK_Pos)) /* Assigment of value for MASK in the ETH_SCRT2CMP0 register */
#define ETH_SCRT2CMP0_CMPVAL_Pos              _UINT32_(16)                                         /* (ETH_SCRT2CMP0) 2Byte Compare Value Position */
#define ETH_SCRT2CMP0_CMPVAL_Msk              (_UINT32_(0xFFFF) << ETH_SCRT2CMP0_CMPVAL_Pos)       /* (ETH_SCRT2CMP0) 2Byte Compare Value Mask */
#define ETH_SCRT2CMP0_CMPVAL(value)           (ETH_SCRT2CMP0_CMPVAL_Msk & (_UINT32_(value) << ETH_SCRT2CMP0_CMPVAL_Pos)) /* Assigment of value for CMPVAL in the ETH_SCRT2CMP0 register */
#define ETH_SCRT2CMP0_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (ETH_SCRT2CMP0) Register Mask  */


/* -------- ETH_SCRT2CMP1 : (ETH Offset: 0x04) (R/W 32) Screening Type 2 Compare Registers Word 1 -------- */
#define ETH_SCRT2CMP1_RESETVALUE              _UINT32_(0x00)                                       /*  (ETH_SCRT2CMP1) Screening Type 2 Compare Registers Word 1  Reset Value */

#define ETH_SCRT2CMP1_Msk                     _UINT32_(0x00000000)                                 /* (ETH_SCRT2CMP1) Register Mask  */


/* -------- ETH_CTRLA : (ETH Offset: 0x00) (R/W 32) CTRLA Register -------- */
#define ETH_CTRLA_RESETVALUE                  _UINT32_(0x00)                                       /*  (ETH_CTRLA) CTRLA Register  Reset Value */

#define ETH_CTRLA_SWRST_Pos                   _UINT32_(0)                                          /* (ETH_CTRLA) Software Reset Bit Position */
#define ETH_CTRLA_SWRST_Msk                   (_UINT32_(0x1) << ETH_CTRLA_SWRST_Pos)               /* (ETH_CTRLA) Software Reset Bit Mask */
#define ETH_CTRLA_SWRST(value)                (ETH_CTRLA_SWRST_Msk & (_UINT32_(value) << ETH_CTRLA_SWRST_Pos)) /* Assigment of value for SWRST in the ETH_CTRLA register */
#define ETH_CTRLA_ENABLE_Pos                  _UINT32_(1)                                          /* (ETH_CTRLA) Macro Enable Position */
#define ETH_CTRLA_ENABLE_Msk                  (_UINT32_(0x1) << ETH_CTRLA_ENABLE_Pos)              /* (ETH_CTRLA) Macro Enable Mask */
#define ETH_CTRLA_ENABLE(value)               (ETH_CTRLA_ENABLE_Msk & (_UINT32_(value) << ETH_CTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the ETH_CTRLA register */
#define ETH_CTRLA_RUNSTDBY_Pos                _UINT32_(6)                                          /* (ETH_CTRLA) Run in standby mode Position */
#define ETH_CTRLA_RUNSTDBY_Msk                (_UINT32_(0x1) << ETH_CTRLA_RUNSTDBY_Pos)            /* (ETH_CTRLA) Run in standby mode Mask */
#define ETH_CTRLA_RUNSTDBY(value)             (ETH_CTRLA_RUNSTDBY_Msk & (_UINT32_(value) << ETH_CTRLA_RUNSTDBY_Pos)) /* Assigment of value for RUNSTDBY in the ETH_CTRLA register */
#define ETH_CTRLA_Msk                         _UINT32_(0x00000043)                                 /* (ETH_CTRLA) Register Mask  */


/* -------- ETH_CTRLB : (ETH Offset: 0x04) (R/W 32) CTRLB Register -------- */
#define ETH_CTRLB_RESETVALUE                  _UINT32_(0xC0)                                       /*  (ETH_CTRLB) CTRLB Register  Reset Value */

#define ETH_CTRLB_GMIIEN_Pos                  _UINT32_(0)                                          /* (ETH_CTRLB) Select GMII/MII mode Position */
#define ETH_CTRLB_GMIIEN_Msk                  (_UINT32_(0x1) << ETH_CTRLB_GMIIEN_Pos)              /* (ETH_CTRLB) Select GMII/MII mode Mask */
#define ETH_CTRLB_GMIIEN(value)               (ETH_CTRLB_GMIIEN_Msk & (_UINT32_(value) << ETH_CTRLB_GMIIEN_Pos)) /* Assigment of value for GMIIEN in the ETH_CTRLB register */
#define ETH_CTRLB_GBITCLKREQ_Pos              _UINT32_(1)                                          /* (ETH_CTRLB) Gigabit clock request Position */
#define ETH_CTRLB_GBITCLKREQ_Msk              (_UINT32_(0x1) << ETH_CTRLB_GBITCLKREQ_Pos)          /* (ETH_CTRLB) Gigabit clock request Mask */
#define ETH_CTRLB_GBITCLKREQ(value)           (ETH_CTRLB_GBITCLKREQ_Msk & (_UINT32_(value) << ETH_CTRLB_GBITCLKREQ_Pos)) /* Assigment of value for GBITCLKREQ in the ETH_CTRLB register */
#define ETH_CTRLB_TSUCLKREQ_Pos               _UINT32_(2)                                          /* (ETH_CTRLB) TSU Clock Request Position */
#define ETH_CTRLB_TSUCLKREQ_Msk               (_UINT32_(0x1) << ETH_CTRLB_TSUCLKREQ_Pos)           /* (ETH_CTRLB) TSU Clock Request Mask */
#define ETH_CTRLB_TSUCLKREQ(value)            (ETH_CTRLB_TSUCLKREQ_Msk & (_UINT32_(value) << ETH_CTRLB_TSUCLKREQ_Pos)) /* Assigment of value for TSUCLKREQ in the ETH_CTRLB register */
#define ETH_CTRLB_TSUMS_Pos                   _UINT32_(5)                                          /* (ETH_CTRLB) Timer Adjust Position */
#define ETH_CTRLB_TSUMS_Msk                   (_UINT32_(0x1) << ETH_CTRLB_TSUMS_Pos)               /* (ETH_CTRLB) Timer Adjust Mask */
#define ETH_CTRLB_TSUMS(value)                (ETH_CTRLB_TSUMS_Msk & (_UINT32_(value) << ETH_CTRLB_TSUMS_Pos)) /* Assigment of value for TSUMS in the ETH_CTRLB register */
#define ETH_CTRLB_TSUINC_Pos                  _UINT32_(6)                                          /* (ETH_CTRLB) Timer Adjust Mode Position */
#define ETH_CTRLB_TSUINC_Msk                  (_UINT32_(0x3) << ETH_CTRLB_TSUINC_Pos)              /* (ETH_CTRLB) Timer Adjust Mode Mask */
#define ETH_CTRLB_TSUINC(value)               (ETH_CTRLB_TSUINC_Msk & (_UINT32_(value) << ETH_CTRLB_TSUINC_Pos)) /* Assigment of value for TSUINC in the ETH_CTRLB register */
#define ETH_CTRLB_Msk                         _UINT32_(0x000000E7)                                 /* (ETH_CTRLB) Register Mask  */


/* -------- ETH_EVCTRL : (ETH Offset: 0x0C) (R/W 32) Event Control Register -------- */
#define ETH_EVCTRL_RESETVALUE                 _UINT32_(0x00)                                       /*  (ETH_EVCTRL) Event Control Register  Reset Value */

#define ETH_EVCTRL_CMPEO_Pos                  _UINT32_(0)                                          /* (ETH_EVCTRL) Compare Event Out enable Position */
#define ETH_EVCTRL_CMPEO_Msk                  (_UINT32_(0x1) << ETH_EVCTRL_CMPEO_Pos)              /* (ETH_EVCTRL) Compare Event Out enable Mask */
#define ETH_EVCTRL_CMPEO(value)               (ETH_EVCTRL_CMPEO_Msk & (_UINT32_(value) << ETH_EVCTRL_CMPEO_Pos)) /* Assigment of value for CMPEO in the ETH_EVCTRL register */
#define ETH_EVCTRL_Msk                        _UINT32_(0x00000001)                                 /* (ETH_EVCTRL) Register Mask  */


/* -------- ETH_SYNCB : (ETH Offset: 0x20) ( R/ 32) Sync Busy Register -------- */
#define ETH_SYNCB_RESETVALUE                  _UINT32_(0x00)                                       /*  (ETH_SYNCB) Sync Busy Register  Reset Value */

#define ETH_SYNCB_SWRST_Pos                   _UINT32_(0)                                          /* (ETH_SYNCB) Software Reset Sync Busy Position */
#define ETH_SYNCB_SWRST_Msk                   (_UINT32_(0x1) << ETH_SYNCB_SWRST_Pos)               /* (ETH_SYNCB) Software Reset Sync Busy Mask */
#define ETH_SYNCB_SWRST(value)                (ETH_SYNCB_SWRST_Msk & (_UINT32_(value) << ETH_SYNCB_SWRST_Pos)) /* Assigment of value for SWRST in the ETH_SYNCB register */
#define ETH_SYNCB_ENABLE_Pos                  _UINT32_(1)                                          /* (ETH_SYNCB) Enable Sync Busy Position */
#define ETH_SYNCB_ENABLE_Msk                  (_UINT32_(0x1) << ETH_SYNCB_ENABLE_Pos)              /* (ETH_SYNCB) Enable Sync Busy Mask */
#define ETH_SYNCB_ENABLE(value)               (ETH_SYNCB_ENABLE_Msk & (_UINT32_(value) << ETH_SYNCB_ENABLE_Pos)) /* Assigment of value for ENABLE in the ETH_SYNCB register */
#define ETH_SYNCB_Msk                         _UINT32_(0x00000003)                                 /* (ETH_SYNCB) Register Mask  */


/* -------- ETH_NCR : (ETH Offset: 0x1000) (R/W 32) Network Control Register -------- */
#define ETH_NCR_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_NCR) Network Control Register  Reset Value */

#define ETH_NCR_LBL_Pos                       _UINT32_(1)                                          /* (ETH_NCR) Loop Back Local Position */
#define ETH_NCR_LBL_Msk                       (_UINT32_(0x1) << ETH_NCR_LBL_Pos)                   /* (ETH_NCR) Loop Back Local Mask */
#define ETH_NCR_LBL(value)                    (ETH_NCR_LBL_Msk & (_UINT32_(value) << ETH_NCR_LBL_Pos)) /* Assigment of value for LBL in the ETH_NCR register */
#define ETH_NCR_RXEN_Pos                      _UINT32_(2)                                          /* (ETH_NCR) Receive Enable Position */
#define ETH_NCR_RXEN_Msk                      (_UINT32_(0x1) << ETH_NCR_RXEN_Pos)                  /* (ETH_NCR) Receive Enable Mask */
#define ETH_NCR_RXEN(value)                   (ETH_NCR_RXEN_Msk & (_UINT32_(value) << ETH_NCR_RXEN_Pos)) /* Assigment of value for RXEN in the ETH_NCR register */
#define ETH_NCR_TXEN_Pos                      _UINT32_(3)                                          /* (ETH_NCR) Transmit Enable Position */
#define ETH_NCR_TXEN_Msk                      (_UINT32_(0x1) << ETH_NCR_TXEN_Pos)                  /* (ETH_NCR) Transmit Enable Mask */
#define ETH_NCR_TXEN(value)                   (ETH_NCR_TXEN_Msk & (_UINT32_(value) << ETH_NCR_TXEN_Pos)) /* Assigment of value for TXEN in the ETH_NCR register */
#define ETH_NCR_MPE_Pos                       _UINT32_(4)                                          /* (ETH_NCR) Management Port Enable Position */
#define ETH_NCR_MPE_Msk                       (_UINT32_(0x1) << ETH_NCR_MPE_Pos)                   /* (ETH_NCR) Management Port Enable Mask */
#define ETH_NCR_MPE(value)                    (ETH_NCR_MPE_Msk & (_UINT32_(value) << ETH_NCR_MPE_Pos)) /* Assigment of value for MPE in the ETH_NCR register */
#define ETH_NCR_CLRSTAT_Pos                   _UINT32_(5)                                          /* (ETH_NCR) Clear Statistics Registers Position */
#define ETH_NCR_CLRSTAT_Msk                   (_UINT32_(0x1) << ETH_NCR_CLRSTAT_Pos)               /* (ETH_NCR) Clear Statistics Registers Mask */
#define ETH_NCR_CLRSTAT(value)                (ETH_NCR_CLRSTAT_Msk & (_UINT32_(value) << ETH_NCR_CLRSTAT_Pos)) /* Assigment of value for CLRSTAT in the ETH_NCR register */
#define ETH_NCR_INCSTAT_Pos                   _UINT32_(6)                                          /* (ETH_NCR) Increment Statistics Registers Position */
#define ETH_NCR_INCSTAT_Msk                   (_UINT32_(0x1) << ETH_NCR_INCSTAT_Pos)               /* (ETH_NCR) Increment Statistics Registers Mask */
#define ETH_NCR_INCSTAT(value)                (ETH_NCR_INCSTAT_Msk & (_UINT32_(value) << ETH_NCR_INCSTAT_Pos)) /* Assigment of value for INCSTAT in the ETH_NCR register */
#define ETH_NCR_WESTAT_Pos                    _UINT32_(7)                                          /* (ETH_NCR) Write Enable for Statistics Registers Position */
#define ETH_NCR_WESTAT_Msk                    (_UINT32_(0x1) << ETH_NCR_WESTAT_Pos)                /* (ETH_NCR) Write Enable for Statistics Registers Mask */
#define ETH_NCR_WESTAT(value)                 (ETH_NCR_WESTAT_Msk & (_UINT32_(value) << ETH_NCR_WESTAT_Pos)) /* Assigment of value for WESTAT in the ETH_NCR register */
#define ETH_NCR_BP_Pos                        _UINT32_(8)                                          /* (ETH_NCR) Back pressure Position */
#define ETH_NCR_BP_Msk                        (_UINT32_(0x1) << ETH_NCR_BP_Pos)                    /* (ETH_NCR) Back pressure Mask */
#define ETH_NCR_BP(value)                     (ETH_NCR_BP_Msk & (_UINT32_(value) << ETH_NCR_BP_Pos)) /* Assigment of value for BP in the ETH_NCR register */
#define ETH_NCR_TSTART_Pos                    _UINT32_(9)                                          /* (ETH_NCR) Start Transmission Position */
#define ETH_NCR_TSTART_Msk                    (_UINT32_(0x1) << ETH_NCR_TSTART_Pos)                /* (ETH_NCR) Start Transmission Mask */
#define ETH_NCR_TSTART(value)                 (ETH_NCR_TSTART_Msk & (_UINT32_(value) << ETH_NCR_TSTART_Pos)) /* Assigment of value for TSTART in the ETH_NCR register */
#define ETH_NCR_THALT_Pos                     _UINT32_(10)                                         /* (ETH_NCR) Transmit Halt Position */
#define ETH_NCR_THALT_Msk                     (_UINT32_(0x1) << ETH_NCR_THALT_Pos)                 /* (ETH_NCR) Transmit Halt Mask */
#define ETH_NCR_THALT(value)                  (ETH_NCR_THALT_Msk & (_UINT32_(value) << ETH_NCR_THALT_Pos)) /* Assigment of value for THALT in the ETH_NCR register */
#define ETH_NCR_TXPF_Pos                      _UINT32_(11)                                         /* (ETH_NCR) Transmit Pause Frame Position */
#define ETH_NCR_TXPF_Msk                      (_UINT32_(0x1) << ETH_NCR_TXPF_Pos)                  /* (ETH_NCR) Transmit Pause Frame Mask */
#define ETH_NCR_TXPF(value)                   (ETH_NCR_TXPF_Msk & (_UINT32_(value) << ETH_NCR_TXPF_Pos)) /* Assigment of value for TXPF in the ETH_NCR register */
#define ETH_NCR_TXZQPF_Pos                    _UINT32_(12)                                         /* (ETH_NCR) Transmit Zero Quantum Pause Frame Position */
#define ETH_NCR_TXZQPF_Msk                    (_UINT32_(0x1) << ETH_NCR_TXZQPF_Pos)                /* (ETH_NCR) Transmit Zero Quantum Pause Frame Mask */
#define ETH_NCR_TXZQPF(value)                 (ETH_NCR_TXZQPF_Msk & (_UINT32_(value) << ETH_NCR_TXZQPF_Pos)) /* Assigment of value for TXZQPF in the ETH_NCR register */
#define ETH_NCR_SRTSM_Pos                     _UINT32_(15)                                         /* (ETH_NCR) Store Receive Time Stamp to Memory Position */
#define ETH_NCR_SRTSM_Msk                     (_UINT32_(0x1) << ETH_NCR_SRTSM_Pos)                 /* (ETH_NCR) Store Receive Time Stamp to Memory Mask */
#define ETH_NCR_SRTSM(value)                  (ETH_NCR_SRTSM_Msk & (_UINT32_(value) << ETH_NCR_SRTSM_Pos)) /* Assigment of value for SRTSM in the ETH_NCR register */
#define ETH_NCR_ENPBPR_Pos                    _UINT32_(16)                                         /* (ETH_NCR) Enable PFC Priority-based Pause Reception Position */
#define ETH_NCR_ENPBPR_Msk                    (_UINT32_(0x1) << ETH_NCR_ENPBPR_Pos)                /* (ETH_NCR) Enable PFC Priority-based Pause Reception Mask */
#define ETH_NCR_ENPBPR(value)                 (ETH_NCR_ENPBPR_Msk & (_UINT32_(value) << ETH_NCR_ENPBPR_Pos)) /* Assigment of value for ENPBPR in the ETH_NCR register */
#define ETH_NCR_TXPBPF_Pos                    _UINT32_(17)                                         /* (ETH_NCR) Transmit PFC Priority-based Pause Frame Position */
#define ETH_NCR_TXPBPF_Msk                    (_UINT32_(0x1) << ETH_NCR_TXPBPF_Pos)                /* (ETH_NCR) Transmit PFC Priority-based Pause Frame Mask */
#define ETH_NCR_TXPBPF(value)                 (ETH_NCR_TXPBPF_Msk & (_UINT32_(value) << ETH_NCR_TXPBPF_Pos)) /* Assigment of value for TXPBPF in the ETH_NCR register */
#define ETH_NCR_FNP_Pos                       _UINT32_(18)                                         /* (ETH_NCR) Flush Next Packet Position */
#define ETH_NCR_FNP_Msk                       (_UINT32_(0x1) << ETH_NCR_FNP_Pos)                   /* (ETH_NCR) Flush Next Packet Mask */
#define ETH_NCR_FNP(value)                    (ETH_NCR_FNP_Msk & (_UINT32_(value) << ETH_NCR_FNP_Pos)) /* Assigment of value for FNP in the ETH_NCR register */
#define ETH_NCR_LPI_Pos                       _UINT32_(19)                                         /* (ETH_NCR) Low Power Idle Enable Position */
#define ETH_NCR_LPI_Msk                       (_UINT32_(0x1) << ETH_NCR_LPI_Pos)                   /* (ETH_NCR) Low Power Idle Enable Mask */
#define ETH_NCR_LPI(value)                    (ETH_NCR_LPI_Msk & (_UINT32_(value) << ETH_NCR_LPI_Pos)) /* Assigment of value for LPI in the ETH_NCR register */
#define ETH_NCR_Msk                           _UINT32_(0x000F9FFE)                                 /* (ETH_NCR) Register Mask  */


/* -------- ETH_NCFGR : (ETH Offset: 0x1004) (R/W 32) Network Configuration Register -------- */
#define ETH_NCFGR_RESETVALUE                  _UINT32_(0x80000)                                    /*  (ETH_NCFGR) Network Configuration Register  Reset Value */

#define ETH_NCFGR_SPD_Pos                     _UINT32_(0)                                          /* (ETH_NCFGR) Speed Position */
#define ETH_NCFGR_SPD_Msk                     (_UINT32_(0x1) << ETH_NCFGR_SPD_Pos)                 /* (ETH_NCFGR) Speed Mask */
#define ETH_NCFGR_SPD(value)                  (ETH_NCFGR_SPD_Msk & (_UINT32_(value) << ETH_NCFGR_SPD_Pos)) /* Assigment of value for SPD in the ETH_NCFGR register */
#define ETH_NCFGR_FD_Pos                      _UINT32_(1)                                          /* (ETH_NCFGR) Full Duplex Position */
#define ETH_NCFGR_FD_Msk                      (_UINT32_(0x1) << ETH_NCFGR_FD_Pos)                  /* (ETH_NCFGR) Full Duplex Mask */
#define ETH_NCFGR_FD(value)                   (ETH_NCFGR_FD_Msk & (_UINT32_(value) << ETH_NCFGR_FD_Pos)) /* Assigment of value for FD in the ETH_NCFGR register */
#define ETH_NCFGR_DNVLAN_Pos                  _UINT32_(2)                                          /* (ETH_NCFGR) Discard Non-VLAN FRAMES Position */
#define ETH_NCFGR_DNVLAN_Msk                  (_UINT32_(0x1) << ETH_NCFGR_DNVLAN_Pos)              /* (ETH_NCFGR) Discard Non-VLAN FRAMES Mask */
#define ETH_NCFGR_DNVLAN(value)               (ETH_NCFGR_DNVLAN_Msk & (_UINT32_(value) << ETH_NCFGR_DNVLAN_Pos)) /* Assigment of value for DNVLAN in the ETH_NCFGR register */
#define ETH_NCFGR_JFRAME_Pos                  _UINT32_(3)                                          /* (ETH_NCFGR) Jumbo Frame Size Position */
#define ETH_NCFGR_JFRAME_Msk                  (_UINT32_(0x1) << ETH_NCFGR_JFRAME_Pos)              /* (ETH_NCFGR) Jumbo Frame Size Mask */
#define ETH_NCFGR_JFRAME(value)               (ETH_NCFGR_JFRAME_Msk & (_UINT32_(value) << ETH_NCFGR_JFRAME_Pos)) /* Assigment of value for JFRAME in the ETH_NCFGR register */
#define ETH_NCFGR_CAF_Pos                     _UINT32_(4)                                          /* (ETH_NCFGR) Copy All Frames Position */
#define ETH_NCFGR_CAF_Msk                     (_UINT32_(0x1) << ETH_NCFGR_CAF_Pos)                 /* (ETH_NCFGR) Copy All Frames Mask */
#define ETH_NCFGR_CAF(value)                  (ETH_NCFGR_CAF_Msk & (_UINT32_(value) << ETH_NCFGR_CAF_Pos)) /* Assigment of value for CAF in the ETH_NCFGR register */
#define ETH_NCFGR_NBC_Pos                     _UINT32_(5)                                          /* (ETH_NCFGR) No Broadcast Position */
#define ETH_NCFGR_NBC_Msk                     (_UINT32_(0x1) << ETH_NCFGR_NBC_Pos)                 /* (ETH_NCFGR) No Broadcast Mask */
#define ETH_NCFGR_NBC(value)                  (ETH_NCFGR_NBC_Msk & (_UINT32_(value) << ETH_NCFGR_NBC_Pos)) /* Assigment of value for NBC in the ETH_NCFGR register */
#define ETH_NCFGR_MTIHEN_Pos                  _UINT32_(6)                                          /* (ETH_NCFGR) Multicast Hash Enable Position */
#define ETH_NCFGR_MTIHEN_Msk                  (_UINT32_(0x1) << ETH_NCFGR_MTIHEN_Pos)              /* (ETH_NCFGR) Multicast Hash Enable Mask */
#define ETH_NCFGR_MTIHEN(value)               (ETH_NCFGR_MTIHEN_Msk & (_UINT32_(value) << ETH_NCFGR_MTIHEN_Pos)) /* Assigment of value for MTIHEN in the ETH_NCFGR register */
#define ETH_NCFGR_UNIHEN_Pos                  _UINT32_(7)                                          /* (ETH_NCFGR) Unicast Hash Enable Position */
#define ETH_NCFGR_UNIHEN_Msk                  (_UINT32_(0x1) << ETH_NCFGR_UNIHEN_Pos)              /* (ETH_NCFGR) Unicast Hash Enable Mask */
#define ETH_NCFGR_UNIHEN(value)               (ETH_NCFGR_UNIHEN_Msk & (_UINT32_(value) << ETH_NCFGR_UNIHEN_Pos)) /* Assigment of value for UNIHEN in the ETH_NCFGR register */
#define ETH_NCFGR_MAXFS_Pos                   _UINT32_(8)                                          /* (ETH_NCFGR) 1536 Maximum Frame Size Position */
#define ETH_NCFGR_MAXFS_Msk                   (_UINT32_(0x1) << ETH_NCFGR_MAXFS_Pos)               /* (ETH_NCFGR) 1536 Maximum Frame Size Mask */
#define ETH_NCFGR_MAXFS(value)                (ETH_NCFGR_MAXFS_Msk & (_UINT32_(value) << ETH_NCFGR_MAXFS_Pos)) /* Assigment of value for MAXFS in the ETH_NCFGR register */
#define ETH_NCFGR_GIGE_Pos                    _UINT32_(10)                                         /* (ETH_NCFGR) Gigabit mode Enable Position */
#define ETH_NCFGR_GIGE_Msk                    (_UINT32_(0x1) << ETH_NCFGR_GIGE_Pos)                /* (ETH_NCFGR) Gigabit mode Enable Mask */
#define ETH_NCFGR_GIGE(value)                 (ETH_NCFGR_GIGE_Msk & (_UINT32_(value) << ETH_NCFGR_GIGE_Pos)) /* Assigment of value for GIGE in the ETH_NCFGR register */
#define ETH_NCFGR_RTY_Pos                     _UINT32_(12)                                         /* (ETH_NCFGR) Retry Test Position */
#define ETH_NCFGR_RTY_Msk                     (_UINT32_(0x1) << ETH_NCFGR_RTY_Pos)                 /* (ETH_NCFGR) Retry Test Mask */
#define ETH_NCFGR_RTY(value)                  (ETH_NCFGR_RTY_Msk & (_UINT32_(value) << ETH_NCFGR_RTY_Pos)) /* Assigment of value for RTY in the ETH_NCFGR register */
#define ETH_NCFGR_PEN_Pos                     _UINT32_(13)                                         /* (ETH_NCFGR) Pause Enable Position */
#define ETH_NCFGR_PEN_Msk                     (_UINT32_(0x1) << ETH_NCFGR_PEN_Pos)                 /* (ETH_NCFGR) Pause Enable Mask */
#define ETH_NCFGR_PEN(value)                  (ETH_NCFGR_PEN_Msk & (_UINT32_(value) << ETH_NCFGR_PEN_Pos)) /* Assigment of value for PEN in the ETH_NCFGR register */
#define ETH_NCFGR_RXBUFO_Pos                  _UINT32_(14)                                         /* (ETH_NCFGR) Receive Buffer Offset Position */
#define ETH_NCFGR_RXBUFO_Msk                  (_UINT32_(0x3) << ETH_NCFGR_RXBUFO_Pos)              /* (ETH_NCFGR) Receive Buffer Offset Mask */
#define ETH_NCFGR_RXBUFO(value)               (ETH_NCFGR_RXBUFO_Msk & (_UINT32_(value) << ETH_NCFGR_RXBUFO_Pos)) /* Assigment of value for RXBUFO in the ETH_NCFGR register */
#define ETH_NCFGR_LFERD_Pos                   _UINT32_(16)                                         /* (ETH_NCFGR) Length Field Error Frame Discard Position */
#define ETH_NCFGR_LFERD_Msk                   (_UINT32_(0x1) << ETH_NCFGR_LFERD_Pos)               /* (ETH_NCFGR) Length Field Error Frame Discard Mask */
#define ETH_NCFGR_LFERD(value)                (ETH_NCFGR_LFERD_Msk & (_UINT32_(value) << ETH_NCFGR_LFERD_Pos)) /* Assigment of value for LFERD in the ETH_NCFGR register */
#define ETH_NCFGR_RFCS_Pos                    _UINT32_(17)                                         /* (ETH_NCFGR) Remove FCS Position */
#define ETH_NCFGR_RFCS_Msk                    (_UINT32_(0x1) << ETH_NCFGR_RFCS_Pos)                /* (ETH_NCFGR) Remove FCS Mask */
#define ETH_NCFGR_RFCS(value)                 (ETH_NCFGR_RFCS_Msk & (_UINT32_(value) << ETH_NCFGR_RFCS_Pos)) /* Assigment of value for RFCS in the ETH_NCFGR register */
#define ETH_NCFGR_CLK_Pos                     _UINT32_(18)                                         /* (ETH_NCFGR) MDC CLock Division Position */
#define ETH_NCFGR_CLK_Msk                     (_UINT32_(0x7) << ETH_NCFGR_CLK_Pos)                 /* (ETH_NCFGR) MDC CLock Division Mask */
#define ETH_NCFGR_CLK(value)                  (ETH_NCFGR_CLK_Msk & (_UINT32_(value) << ETH_NCFGR_CLK_Pos)) /* Assigment of value for CLK in the ETH_NCFGR register */
#define ETH_NCFGR_DBW_Pos                     _UINT32_(21)                                         /* (ETH_NCFGR) Data Bus Width Position */
#define ETH_NCFGR_DBW_Msk                     (_UINT32_(0x3) << ETH_NCFGR_DBW_Pos)                 /* (ETH_NCFGR) Data Bus Width Mask */
#define ETH_NCFGR_DBW(value)                  (ETH_NCFGR_DBW_Msk & (_UINT32_(value) << ETH_NCFGR_DBW_Pos)) /* Assigment of value for DBW in the ETH_NCFGR register */
#define ETH_NCFGR_DCPF_Pos                    _UINT32_(23)                                         /* (ETH_NCFGR) Disable Copy of Pause Frames Position */
#define ETH_NCFGR_DCPF_Msk                    (_UINT32_(0x1) << ETH_NCFGR_DCPF_Pos)                /* (ETH_NCFGR) Disable Copy of Pause Frames Mask */
#define ETH_NCFGR_DCPF(value)                 (ETH_NCFGR_DCPF_Msk & (_UINT32_(value) << ETH_NCFGR_DCPF_Pos)) /* Assigment of value for DCPF in the ETH_NCFGR register */
#define ETH_NCFGR_RXCOEN_Pos                  _UINT32_(24)                                         /* (ETH_NCFGR) Receive Checksum Offload Enable Position */
#define ETH_NCFGR_RXCOEN_Msk                  (_UINT32_(0x1) << ETH_NCFGR_RXCOEN_Pos)              /* (ETH_NCFGR) Receive Checksum Offload Enable Mask */
#define ETH_NCFGR_RXCOEN(value)               (ETH_NCFGR_RXCOEN_Msk & (_UINT32_(value) << ETH_NCFGR_RXCOEN_Pos)) /* Assigment of value for RXCOEN in the ETH_NCFGR register */
#define ETH_NCFGR_EFRHD_Pos                   _UINT32_(25)                                         /* (ETH_NCFGR) Enable Frames Received in Half Duplex Position */
#define ETH_NCFGR_EFRHD_Msk                   (_UINT32_(0x1) << ETH_NCFGR_EFRHD_Pos)               /* (ETH_NCFGR) Enable Frames Received in Half Duplex Mask */
#define ETH_NCFGR_EFRHD(value)                (ETH_NCFGR_EFRHD_Msk & (_UINT32_(value) << ETH_NCFGR_EFRHD_Pos)) /* Assigment of value for EFRHD in the ETH_NCFGR register */
#define ETH_NCFGR_IRXFCS_Pos                  _UINT32_(26)                                         /* (ETH_NCFGR) Ignore RX FCS Position */
#define ETH_NCFGR_IRXFCS_Msk                  (_UINT32_(0x1) << ETH_NCFGR_IRXFCS_Pos)              /* (ETH_NCFGR) Ignore RX FCS Mask */
#define ETH_NCFGR_IRXFCS(value)               (ETH_NCFGR_IRXFCS_Msk & (_UINT32_(value) << ETH_NCFGR_IRXFCS_Pos)) /* Assigment of value for IRXFCS in the ETH_NCFGR register */
#define ETH_NCFGR_IPGSEN_Pos                  _UINT32_(28)                                         /* (ETH_NCFGR) IP Stretch Enable Position */
#define ETH_NCFGR_IPGSEN_Msk                  (_UINT32_(0x1) << ETH_NCFGR_IPGSEN_Pos)              /* (ETH_NCFGR) IP Stretch Enable Mask */
#define ETH_NCFGR_IPGSEN(value)               (ETH_NCFGR_IPGSEN_Msk & (_UINT32_(value) << ETH_NCFGR_IPGSEN_Pos)) /* Assigment of value for IPGSEN in the ETH_NCFGR register */
#define ETH_NCFGR_RXBP_Pos                    _UINT32_(29)                                         /* (ETH_NCFGR) Receive Bad Preamble Position */
#define ETH_NCFGR_RXBP_Msk                    (_UINT32_(0x1) << ETH_NCFGR_RXBP_Pos)                /* (ETH_NCFGR) Receive Bad Preamble Mask */
#define ETH_NCFGR_RXBP(value)                 (ETH_NCFGR_RXBP_Msk & (_UINT32_(value) << ETH_NCFGR_RXBP_Pos)) /* Assigment of value for RXBP in the ETH_NCFGR register */
#define ETH_NCFGR_IRXER_Pos                   _UINT32_(30)                                         /* (ETH_NCFGR) Ignore IPG GRXER Position */
#define ETH_NCFGR_IRXER_Msk                   (_UINT32_(0x1) << ETH_NCFGR_IRXER_Pos)               /* (ETH_NCFGR) Ignore IPG GRXER Mask */
#define ETH_NCFGR_IRXER(value)                (ETH_NCFGR_IRXER_Msk & (_UINT32_(value) << ETH_NCFGR_IRXER_Pos)) /* Assigment of value for IRXER in the ETH_NCFGR register */
#define ETH_NCFGR_Msk                         _UINT32_(0x77FFF5FF)                                 /* (ETH_NCFGR) Register Mask  */


/* -------- ETH_NSR : (ETH Offset: 0x1008) ( R/ 32) Network Status Register -------- */
#define ETH_NSR_RESETVALUE                    _UINT32_(0x04)                                       /*  (ETH_NSR) Network Status Register  Reset Value */

#define ETH_NSR_MDIO_Pos                      _UINT32_(1)                                          /* (ETH_NSR) MDIO Input Status Position */
#define ETH_NSR_MDIO_Msk                      (_UINT32_(0x1) << ETH_NSR_MDIO_Pos)                  /* (ETH_NSR) MDIO Input Status Mask */
#define ETH_NSR_MDIO(value)                   (ETH_NSR_MDIO_Msk & (_UINT32_(value) << ETH_NSR_MDIO_Pos)) /* Assigment of value for MDIO in the ETH_NSR register */
#define ETH_NSR_IDLE_Pos                      _UINT32_(2)                                          /* (ETH_NSR) PHY Management Logic Idle Position */
#define ETH_NSR_IDLE_Msk                      (_UINT32_(0x1) << ETH_NSR_IDLE_Pos)                  /* (ETH_NSR) PHY Management Logic Idle Mask */
#define ETH_NSR_IDLE(value)                   (ETH_NSR_IDLE_Msk & (_UINT32_(value) << ETH_NSR_IDLE_Pos)) /* Assigment of value for IDLE in the ETH_NSR register */
#define ETH_NSR_Msk                           _UINT32_(0x00000006)                                 /* (ETH_NSR) Register Mask  */


/* -------- ETH_UR : (ETH Offset: 0x100C) (R/W 32) User Register -------- */
#define ETH_UR_RESETVALUE                     _UINT32_(0x00)                                       /*  (ETH_UR) User Register  Reset Value */

#define ETH_UR_MII_Pos                        _UINT32_(0)                                          /* (ETH_UR) MII Mode Position */
#define ETH_UR_MII_Msk                        (_UINT32_(0x1) << ETH_UR_MII_Pos)                    /* (ETH_UR) MII Mode Mask */
#define ETH_UR_MII(value)                     (ETH_UR_MII_Msk & (_UINT32_(value) << ETH_UR_MII_Pos)) /* Assigment of value for MII in the ETH_UR register */
#define ETH_UR_Msk                            _UINT32_(0x00000001)                                 /* (ETH_UR) Register Mask  */


/* -------- ETH_DCFGR : (ETH Offset: 0x1010) (R/W 32) DMA Configuration Register -------- */
#define ETH_DCFGR_RESETVALUE                  _UINT32_(0x20704)                                    /*  (ETH_DCFGR) DMA Configuration Register  Reset Value */

#define ETH_DCFGR_FBLDO_Pos                   _UINT32_(0)                                          /* (ETH_DCFGR) Fixed Burst Length for DMA Data Operations: Position */
#define ETH_DCFGR_FBLDO_Msk                   (_UINT32_(0x1F) << ETH_DCFGR_FBLDO_Pos)              /* (ETH_DCFGR) Fixed Burst Length for DMA Data Operations: Mask */
#define ETH_DCFGR_FBLDO(value)                (ETH_DCFGR_FBLDO_Msk & (_UINT32_(value) << ETH_DCFGR_FBLDO_Pos)) /* Assigment of value for FBLDO in the ETH_DCFGR register */
#define ETH_DCFGR_ESMA_Pos                    _UINT32_(6)                                          /* (ETH_DCFGR) Endian Swap Mode Enable for Management Descriptor Accesses Position */
#define ETH_DCFGR_ESMA_Msk                    (_UINT32_(0x1) << ETH_DCFGR_ESMA_Pos)                /* (ETH_DCFGR) Endian Swap Mode Enable for Management Descriptor Accesses Mask */
#define ETH_DCFGR_ESMA(value)                 (ETH_DCFGR_ESMA_Msk & (_UINT32_(value) << ETH_DCFGR_ESMA_Pos)) /* Assigment of value for ESMA in the ETH_DCFGR register */
#define ETH_DCFGR_ESPA_Pos                    _UINT32_(7)                                          /* (ETH_DCFGR) Endian Swap Mode Enable for Packet Data Accesses Position */
#define ETH_DCFGR_ESPA_Msk                    (_UINT32_(0x1) << ETH_DCFGR_ESPA_Pos)                /* (ETH_DCFGR) Endian Swap Mode Enable for Packet Data Accesses Mask */
#define ETH_DCFGR_ESPA(value)                 (ETH_DCFGR_ESPA_Msk & (_UINT32_(value) << ETH_DCFGR_ESPA_Pos)) /* Assigment of value for ESPA in the ETH_DCFGR register */
#define ETH_DCFGR_RXBMS_Pos                   _UINT32_(8)                                          /* (ETH_DCFGR) Receiver Packet Buffer Memory Size Select Position */
#define ETH_DCFGR_RXBMS_Msk                   (_UINT32_(0x3) << ETH_DCFGR_RXBMS_Pos)               /* (ETH_DCFGR) Receiver Packet Buffer Memory Size Select Mask */
#define ETH_DCFGR_RXBMS(value)                (ETH_DCFGR_RXBMS_Msk & (_UINT32_(value) << ETH_DCFGR_RXBMS_Pos)) /* Assigment of value for RXBMS in the ETH_DCFGR register */
#define ETH_DCFGR_TXPBMS_Pos                  _UINT32_(10)                                         /* (ETH_DCFGR) Transmitter Packet Buffer Memory Size Select Position */
#define ETH_DCFGR_TXPBMS_Msk                  (_UINT32_(0x1) << ETH_DCFGR_TXPBMS_Pos)              /* (ETH_DCFGR) Transmitter Packet Buffer Memory Size Select Mask */
#define ETH_DCFGR_TXPBMS(value)               (ETH_DCFGR_TXPBMS_Msk & (_UINT32_(value) << ETH_DCFGR_TXPBMS_Pos)) /* Assigment of value for TXPBMS in the ETH_DCFGR register */
#define ETH_DCFGR_TXCOEN_Pos                  _UINT32_(11)                                         /* (ETH_DCFGR) Transmitter Checksum Generation Offload Enable Position */
#define ETH_DCFGR_TXCOEN_Msk                  (_UINT32_(0x1) << ETH_DCFGR_TXCOEN_Pos)              /* (ETH_DCFGR) Transmitter Checksum Generation Offload Enable Mask */
#define ETH_DCFGR_TXCOEN(value)               (ETH_DCFGR_TXCOEN_Msk & (_UINT32_(value) << ETH_DCFGR_TXCOEN_Pos)) /* Assigment of value for TXCOEN in the ETH_DCFGR register */
#define ETH_DCFGR_DRBS_Pos                    _UINT32_(16)                                         /* (ETH_DCFGR) DMA Receive Buffer Size Position */
#define ETH_DCFGR_DRBS_Msk                    (_UINT32_(0xFF) << ETH_DCFGR_DRBS_Pos)               /* (ETH_DCFGR) DMA Receive Buffer Size Mask */
#define ETH_DCFGR_DRBS(value)                 (ETH_DCFGR_DRBS_Msk & (_UINT32_(value) << ETH_DCFGR_DRBS_Pos)) /* Assigment of value for DRBS in the ETH_DCFGR register */
#define ETH_DCFGR_DDRP_Pos                    _UINT32_(24)                                         /* (ETH_DCFGR) DMA Discard Receive Packets Position */
#define ETH_DCFGR_DDRP_Msk                    (_UINT32_(0x1) << ETH_DCFGR_DDRP_Pos)                /* (ETH_DCFGR) DMA Discard Receive Packets Mask */
#define ETH_DCFGR_DDRP(value)                 (ETH_DCFGR_DDRP_Msk & (_UINT32_(value) << ETH_DCFGR_DDRP_Pos)) /* Assigment of value for DDRP in the ETH_DCFGR register */
#define ETH_DCFGR_Msk                         _UINT32_(0x01FF0FDF)                                 /* (ETH_DCFGR) Register Mask  */


/* -------- ETH_TSR : (ETH Offset: 0x1014) (R/W 32) Transmit Status Register -------- */
#define ETH_TSR_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_TSR) Transmit Status Register  Reset Value */

#define ETH_TSR_UBR_Pos                       _UINT32_(0)                                          /* (ETH_TSR) Used Bit Read Position */
#define ETH_TSR_UBR_Msk                       (_UINT32_(0x1) << ETH_TSR_UBR_Pos)                   /* (ETH_TSR) Used Bit Read Mask */
#define ETH_TSR_UBR(value)                    (ETH_TSR_UBR_Msk & (_UINT32_(value) << ETH_TSR_UBR_Pos)) /* Assigment of value for UBR in the ETH_TSR register */
#define ETH_TSR_COL_Pos                       _UINT32_(1)                                          /* (ETH_TSR) Collision Occurred Position */
#define ETH_TSR_COL_Msk                       (_UINT32_(0x1) << ETH_TSR_COL_Pos)                   /* (ETH_TSR) Collision Occurred Mask */
#define ETH_TSR_COL(value)                    (ETH_TSR_COL_Msk & (_UINT32_(value) << ETH_TSR_COL_Pos)) /* Assigment of value for COL in the ETH_TSR register */
#define ETH_TSR_RLE_Pos                       _UINT32_(2)                                          /* (ETH_TSR) Retry Limit Exceeded Position */
#define ETH_TSR_RLE_Msk                       (_UINT32_(0x1) << ETH_TSR_RLE_Pos)                   /* (ETH_TSR) Retry Limit Exceeded Mask */
#define ETH_TSR_RLE(value)                    (ETH_TSR_RLE_Msk & (_UINT32_(value) << ETH_TSR_RLE_Pos)) /* Assigment of value for RLE in the ETH_TSR register */
#define ETH_TSR_TXGO_Pos                      _UINT32_(3)                                          /* (ETH_TSR) Transmit Go Position */
#define ETH_TSR_TXGO_Msk                      (_UINT32_(0x1) << ETH_TSR_TXGO_Pos)                  /* (ETH_TSR) Transmit Go Mask */
#define ETH_TSR_TXGO(value)                   (ETH_TSR_TXGO_Msk & (_UINT32_(value) << ETH_TSR_TXGO_Pos)) /* Assigment of value for TXGO in the ETH_TSR register */
#define ETH_TSR_TFC_Pos                       _UINT32_(4)                                          /* (ETH_TSR) Transmit Frame Corruption Due to AHB Error Position */
#define ETH_TSR_TFC_Msk                       (_UINT32_(0x1) << ETH_TSR_TFC_Pos)                   /* (ETH_TSR) Transmit Frame Corruption Due to AHB Error Mask */
#define ETH_TSR_TFC(value)                    (ETH_TSR_TFC_Msk & (_UINT32_(value) << ETH_TSR_TFC_Pos)) /* Assigment of value for TFC in the ETH_TSR register */
#define ETH_TSR_TXCOMP_Pos                    _UINT32_(5)                                          /* (ETH_TSR) Transmit Complete Position */
#define ETH_TSR_TXCOMP_Msk                    (_UINT32_(0x1) << ETH_TSR_TXCOMP_Pos)                /* (ETH_TSR) Transmit Complete Mask */
#define ETH_TSR_TXCOMP(value)                 (ETH_TSR_TXCOMP_Msk & (_UINT32_(value) << ETH_TSR_TXCOMP_Pos)) /* Assigment of value for TXCOMP in the ETH_TSR register */
#define ETH_TSR_UND_Pos                       _UINT32_(6)                                          /* (ETH_TSR) Transmit Underrun Position */
#define ETH_TSR_UND_Msk                       (_UINT32_(0x1) << ETH_TSR_UND_Pos)                   /* (ETH_TSR) Transmit Underrun Mask */
#define ETH_TSR_UND(value)                    (ETH_TSR_UND_Msk & (_UINT32_(value) << ETH_TSR_UND_Pos)) /* Assigment of value for UND in the ETH_TSR register */
#define ETH_TSR_LCOL_Pos                      _UINT32_(7)                                          /* (ETH_TSR) Late Colision Occured Position */
#define ETH_TSR_LCOL_Msk                      (_UINT32_(0x1) << ETH_TSR_LCOL_Pos)                  /* (ETH_TSR) Late Colision Occured Mask */
#define ETH_TSR_LCOL(value)                   (ETH_TSR_LCOL_Msk & (_UINT32_(value) << ETH_TSR_LCOL_Pos)) /* Assigment of value for LCOL in the ETH_TSR register */
#define ETH_TSR_HRESP_Pos                     _UINT32_(8)                                          /* (ETH_TSR) HRESP Not OK Position */
#define ETH_TSR_HRESP_Msk                     (_UINT32_(0x1) << ETH_TSR_HRESP_Pos)                 /* (ETH_TSR) HRESP Not OK Mask */
#define ETH_TSR_HRESP(value)                  (ETH_TSR_HRESP_Msk & (_UINT32_(value) << ETH_TSR_HRESP_Pos)) /* Assigment of value for HRESP in the ETH_TSR register */
#define ETH_TSR_Msk                           _UINT32_(0x000001FF)                                 /* (ETH_TSR) Register Mask  */


/* -------- ETH_RBQB : (ETH Offset: 0x1018) (R/W 32) Receive Buffer Queue Base Address -------- */
#define ETH_RBQB_RESETVALUE                   _UINT32_(0x00)                                       /*  (ETH_RBQB) Receive Buffer Queue Base Address  Reset Value */

#define ETH_RBQB_ADDR_Pos                     _UINT32_(2)                                          /* (ETH_RBQB) Receive Buffer Queue Base Address Position */
#define ETH_RBQB_ADDR_Msk                     (_UINT32_(0x3FFFFFFF) << ETH_RBQB_ADDR_Pos)          /* (ETH_RBQB) Receive Buffer Queue Base Address Mask */
#define ETH_RBQB_ADDR(value)                  (ETH_RBQB_ADDR_Msk & (_UINT32_(value) << ETH_RBQB_ADDR_Pos)) /* Assigment of value for ADDR in the ETH_RBQB register */
#define ETH_RBQB_Msk                          _UINT32_(0xFFFFFFFC)                                 /* (ETH_RBQB) Register Mask  */


/* -------- ETH_TBQB : (ETH Offset: 0x101C) (R/W 32) Transmit Buffer Queue Base Address -------- */
#define ETH_TBQB_RESETVALUE                   _UINT32_(0x00)                                       /*  (ETH_TBQB) Transmit Buffer Queue Base Address  Reset Value */

#define ETH_TBQB_ADDR_Pos                     _UINT32_(2)                                          /* (ETH_TBQB) Transmit Buffer Queue Base Address Position */
#define ETH_TBQB_ADDR_Msk                     (_UINT32_(0x3FFFFFFF) << ETH_TBQB_ADDR_Pos)          /* (ETH_TBQB) Transmit Buffer Queue Base Address Mask */
#define ETH_TBQB_ADDR(value)                  (ETH_TBQB_ADDR_Msk & (_UINT32_(value) << ETH_TBQB_ADDR_Pos)) /* Assigment of value for ADDR in the ETH_TBQB register */
#define ETH_TBQB_Msk                          _UINT32_(0xFFFFFFFC)                                 /* (ETH_TBQB) Register Mask  */


/* -------- ETH_RSR : (ETH Offset: 0x1020) (R/W 32) Receive Status Register -------- */
#define ETH_RSR_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_RSR) Receive Status Register  Reset Value */

#define ETH_RSR_BNA_Pos                       _UINT32_(0)                                          /* (ETH_RSR) Buffer Not Available Position */
#define ETH_RSR_BNA_Msk                       (_UINT32_(0x1) << ETH_RSR_BNA_Pos)                   /* (ETH_RSR) Buffer Not Available Mask */
#define ETH_RSR_BNA(value)                    (ETH_RSR_BNA_Msk & (_UINT32_(value) << ETH_RSR_BNA_Pos)) /* Assigment of value for BNA in the ETH_RSR register */
#define ETH_RSR_REC_Pos                       _UINT32_(1)                                          /* (ETH_RSR) Frame Received Position */
#define ETH_RSR_REC_Msk                       (_UINT32_(0x1) << ETH_RSR_REC_Pos)                   /* (ETH_RSR) Frame Received Mask */
#define ETH_RSR_REC(value)                    (ETH_RSR_REC_Msk & (_UINT32_(value) << ETH_RSR_REC_Pos)) /* Assigment of value for REC in the ETH_RSR register */
#define ETH_RSR_RXOVR_Pos                     _UINT32_(2)                                          /* (ETH_RSR) Receive Overrun Position */
#define ETH_RSR_RXOVR_Msk                     (_UINT32_(0x1) << ETH_RSR_RXOVR_Pos)                 /* (ETH_RSR) Receive Overrun Mask */
#define ETH_RSR_RXOVR(value)                  (ETH_RSR_RXOVR_Msk & (_UINT32_(value) << ETH_RSR_RXOVR_Pos)) /* Assigment of value for RXOVR in the ETH_RSR register */
#define ETH_RSR_HNO_Pos                       _UINT32_(3)                                          /* (ETH_RSR) HRESP Not OK Position */
#define ETH_RSR_HNO_Msk                       (_UINT32_(0x1) << ETH_RSR_HNO_Pos)                   /* (ETH_RSR) HRESP Not OK Mask */
#define ETH_RSR_HNO(value)                    (ETH_RSR_HNO_Msk & (_UINT32_(value) << ETH_RSR_HNO_Pos)) /* Assigment of value for HNO in the ETH_RSR register */
#define ETH_RSR_Msk                           _UINT32_(0x0000000F)                                 /* (ETH_RSR) Register Mask  */


/* -------- ETH_ISR : (ETH Offset: 0x1024) (R/W 32) Interrupt Status Register -------- */
#define ETH_ISR_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_ISR) Interrupt Status Register  Reset Value */

#define ETH_ISR_MFS_Pos                       _UINT32_(0)                                          /* (ETH_ISR) Management Frame Sent Position */
#define ETH_ISR_MFS_Msk                       (_UINT32_(0x1) << ETH_ISR_MFS_Pos)                   /* (ETH_ISR) Management Frame Sent Mask */
#define ETH_ISR_MFS(value)                    (ETH_ISR_MFS_Msk & (_UINT32_(value) << ETH_ISR_MFS_Pos)) /* Assigment of value for MFS in the ETH_ISR register */
#define ETH_ISR_RCOMP_Pos                     _UINT32_(1)                                          /* (ETH_ISR) Receive Complete Position */
#define ETH_ISR_RCOMP_Msk                     (_UINT32_(0x1) << ETH_ISR_RCOMP_Pos)                 /* (ETH_ISR) Receive Complete Mask */
#define ETH_ISR_RCOMP(value)                  (ETH_ISR_RCOMP_Msk & (_UINT32_(value) << ETH_ISR_RCOMP_Pos)) /* Assigment of value for RCOMP in the ETH_ISR register */
#define ETH_ISR_RXUBR_Pos                     _UINT32_(2)                                          /* (ETH_ISR) RX Used Bit Read Position */
#define ETH_ISR_RXUBR_Msk                     (_UINT32_(0x1) << ETH_ISR_RXUBR_Pos)                 /* (ETH_ISR) RX Used Bit Read Mask */
#define ETH_ISR_RXUBR(value)                  (ETH_ISR_RXUBR_Msk & (_UINT32_(value) << ETH_ISR_RXUBR_Pos)) /* Assigment of value for RXUBR in the ETH_ISR register */
#define ETH_ISR_TXUBR_Pos                     _UINT32_(3)                                          /* (ETH_ISR) TX Used Bit Read Position */
#define ETH_ISR_TXUBR_Msk                     (_UINT32_(0x1) << ETH_ISR_TXUBR_Pos)                 /* (ETH_ISR) TX Used Bit Read Mask */
#define ETH_ISR_TXUBR(value)                  (ETH_ISR_TXUBR_Msk & (_UINT32_(value) << ETH_ISR_TXUBR_Pos)) /* Assigment of value for TXUBR in the ETH_ISR register */
#define ETH_ISR_TUR_Pos                       _UINT32_(4)                                          /* (ETH_ISR) Transmit Underrun Position */
#define ETH_ISR_TUR_Msk                       (_UINT32_(0x1) << ETH_ISR_TUR_Pos)                   /* (ETH_ISR) Transmit Underrun Mask */
#define ETH_ISR_TUR(value)                    (ETH_ISR_TUR_Msk & (_UINT32_(value) << ETH_ISR_TUR_Pos)) /* Assigment of value for TUR in the ETH_ISR register */
#define ETH_ISR_RLEX_Pos                      _UINT32_(5)                                          /* (ETH_ISR) Retry Limit Exceeded Position */
#define ETH_ISR_RLEX_Msk                      (_UINT32_(0x1) << ETH_ISR_RLEX_Pos)                  /* (ETH_ISR) Retry Limit Exceeded Mask */
#define ETH_ISR_RLEX(value)                   (ETH_ISR_RLEX_Msk & (_UINT32_(value) << ETH_ISR_RLEX_Pos)) /* Assigment of value for RLEX in the ETH_ISR register */
#define ETH_ISR_TFC_Pos                       _UINT32_(6)                                          /* (ETH_ISR) Transmit Frame Corruption Due to AHB Error Position */
#define ETH_ISR_TFC_Msk                       (_UINT32_(0x1) << ETH_ISR_TFC_Pos)                   /* (ETH_ISR) Transmit Frame Corruption Due to AHB Error Mask */
#define ETH_ISR_TFC(value)                    (ETH_ISR_TFC_Msk & (_UINT32_(value) << ETH_ISR_TFC_Pos)) /* Assigment of value for TFC in the ETH_ISR register */
#define ETH_ISR_TCOMP_Pos                     _UINT32_(7)                                          /* (ETH_ISR) Transmit Complete Position */
#define ETH_ISR_TCOMP_Msk                     (_UINT32_(0x1) << ETH_ISR_TCOMP_Pos)                 /* (ETH_ISR) Transmit Complete Mask */
#define ETH_ISR_TCOMP(value)                  (ETH_ISR_TCOMP_Msk & (_UINT32_(value) << ETH_ISR_TCOMP_Pos)) /* Assigment of value for TCOMP in the ETH_ISR register */
#define ETH_ISR_ROVR_Pos                      _UINT32_(10)                                         /* (ETH_ISR) Receive Overrun Position */
#define ETH_ISR_ROVR_Msk                      (_UINT32_(0x1) << ETH_ISR_ROVR_Pos)                  /* (ETH_ISR) Receive Overrun Mask */
#define ETH_ISR_ROVR(value)                   (ETH_ISR_ROVR_Msk & (_UINT32_(value) << ETH_ISR_ROVR_Pos)) /* Assigment of value for ROVR in the ETH_ISR register */
#define ETH_ISR_HRESP_Pos                     _UINT32_(11)                                         /* (ETH_ISR) HRESP Not OK Position */
#define ETH_ISR_HRESP_Msk                     (_UINT32_(0x1) << ETH_ISR_HRESP_Pos)                 /* (ETH_ISR) HRESP Not OK Mask */
#define ETH_ISR_HRESP(value)                  (ETH_ISR_HRESP_Msk & (_UINT32_(value) << ETH_ISR_HRESP_Pos)) /* Assigment of value for HRESP in the ETH_ISR register */
#define ETH_ISR_PFNZ_Pos                      _UINT32_(12)                                         /* (ETH_ISR) Pause Frame with Non-zero Pause Quantum Received Position */
#define ETH_ISR_PFNZ_Msk                      (_UINT32_(0x1) << ETH_ISR_PFNZ_Pos)                  /* (ETH_ISR) Pause Frame with Non-zero Pause Quantum Received Mask */
#define ETH_ISR_PFNZ(value)                   (ETH_ISR_PFNZ_Msk & (_UINT32_(value) << ETH_ISR_PFNZ_Pos)) /* Assigment of value for PFNZ in the ETH_ISR register */
#define ETH_ISR_PTZ_Pos                       _UINT32_(13)                                         /* (ETH_ISR) Pause Time Zero Position */
#define ETH_ISR_PTZ_Msk                       (_UINT32_(0x1) << ETH_ISR_PTZ_Pos)                   /* (ETH_ISR) Pause Time Zero Mask */
#define ETH_ISR_PTZ(value)                    (ETH_ISR_PTZ_Msk & (_UINT32_(value) << ETH_ISR_PTZ_Pos)) /* Assigment of value for PTZ in the ETH_ISR register */
#define ETH_ISR_PFTR_Pos                      _UINT32_(14)                                         /* (ETH_ISR) Pause Frame Transmitted Position */
#define ETH_ISR_PFTR_Msk                      (_UINT32_(0x1) << ETH_ISR_PFTR_Pos)                  /* (ETH_ISR) Pause Frame Transmitted Mask */
#define ETH_ISR_PFTR(value)                   (ETH_ISR_PFTR_Msk & (_UINT32_(value) << ETH_ISR_PFTR_Pos)) /* Assigment of value for PFTR in the ETH_ISR register */
#define ETH_ISR_DRQFR_Pos                     _UINT32_(18)                                         /* (ETH_ISR) PTP Delay Request Frame Received Position */
#define ETH_ISR_DRQFR_Msk                     (_UINT32_(0x1) << ETH_ISR_DRQFR_Pos)                 /* (ETH_ISR) PTP Delay Request Frame Received Mask */
#define ETH_ISR_DRQFR(value)                  (ETH_ISR_DRQFR_Msk & (_UINT32_(value) << ETH_ISR_DRQFR_Pos)) /* Assigment of value for DRQFR in the ETH_ISR register */
#define ETH_ISR_SFR_Pos                       _UINT32_(19)                                         /* (ETH_ISR) PTP Sync Frame Received Position */
#define ETH_ISR_SFR_Msk                       (_UINT32_(0x1) << ETH_ISR_SFR_Pos)                   /* (ETH_ISR) PTP Sync Frame Received Mask */
#define ETH_ISR_SFR(value)                    (ETH_ISR_SFR_Msk & (_UINT32_(value) << ETH_ISR_SFR_Pos)) /* Assigment of value for SFR in the ETH_ISR register */
#define ETH_ISR_DRQFT_Pos                     _UINT32_(20)                                         /* (ETH_ISR) PTP Delay Request Frame Transmitted Position */
#define ETH_ISR_DRQFT_Msk                     (_UINT32_(0x1) << ETH_ISR_DRQFT_Pos)                 /* (ETH_ISR) PTP Delay Request Frame Transmitted Mask */
#define ETH_ISR_DRQFT(value)                  (ETH_ISR_DRQFT_Msk & (_UINT32_(value) << ETH_ISR_DRQFT_Pos)) /* Assigment of value for DRQFT in the ETH_ISR register */
#define ETH_ISR_SFT_Pos                       _UINT32_(21)                                         /* (ETH_ISR) PTP Sync Frame Transmitted Position */
#define ETH_ISR_SFT_Msk                       (_UINT32_(0x1) << ETH_ISR_SFT_Pos)                   /* (ETH_ISR) PTP Sync Frame Transmitted Mask */
#define ETH_ISR_SFT(value)                    (ETH_ISR_SFT_Msk & (_UINT32_(value) << ETH_ISR_SFT_Pos)) /* Assigment of value for SFT in the ETH_ISR register */
#define ETH_ISR_PDRQFR_Pos                    _UINT32_(22)                                         /* (ETH_ISR) PDelay Request Frame Received Position */
#define ETH_ISR_PDRQFR_Msk                    (_UINT32_(0x1) << ETH_ISR_PDRQFR_Pos)                /* (ETH_ISR) PDelay Request Frame Received Mask */
#define ETH_ISR_PDRQFR(value)                 (ETH_ISR_PDRQFR_Msk & (_UINT32_(value) << ETH_ISR_PDRQFR_Pos)) /* Assigment of value for PDRQFR in the ETH_ISR register */
#define ETH_ISR_PDRSFR_Pos                    _UINT32_(23)                                         /* (ETH_ISR) PDelay Response Frame Received Position */
#define ETH_ISR_PDRSFR_Msk                    (_UINT32_(0x1) << ETH_ISR_PDRSFR_Pos)                /* (ETH_ISR) PDelay Response Frame Received Mask */
#define ETH_ISR_PDRSFR(value)                 (ETH_ISR_PDRSFR_Msk & (_UINT32_(value) << ETH_ISR_PDRSFR_Pos)) /* Assigment of value for PDRSFR in the ETH_ISR register */
#define ETH_ISR_PDRQFT_Pos                    _UINT32_(24)                                         /* (ETH_ISR) PDelay Request Frame Transmitted Position */
#define ETH_ISR_PDRQFT_Msk                    (_UINT32_(0x1) << ETH_ISR_PDRQFT_Pos)                /* (ETH_ISR) PDelay Request Frame Transmitted Mask */
#define ETH_ISR_PDRQFT(value)                 (ETH_ISR_PDRQFT_Msk & (_UINT32_(value) << ETH_ISR_PDRQFT_Pos)) /* Assigment of value for PDRQFT in the ETH_ISR register */
#define ETH_ISR_PDRSFT_Pos                    _UINT32_(25)                                         /* (ETH_ISR) PDelay Response Frame Transmitted Position */
#define ETH_ISR_PDRSFT_Msk                    (_UINT32_(0x1) << ETH_ISR_PDRSFT_Pos)                /* (ETH_ISR) PDelay Response Frame Transmitted Mask */
#define ETH_ISR_PDRSFT(value)                 (ETH_ISR_PDRSFT_Msk & (_UINT32_(value) << ETH_ISR_PDRSFT_Pos)) /* Assigment of value for PDRSFT in the ETH_ISR register */
#define ETH_ISR_SRI_Pos                       _UINT32_(26)                                         /* (ETH_ISR) TSU Seconds Register Increment Position */
#define ETH_ISR_SRI_Msk                       (_UINT32_(0x1) << ETH_ISR_SRI_Pos)                   /* (ETH_ISR) TSU Seconds Register Increment Mask */
#define ETH_ISR_SRI(value)                    (ETH_ISR_SRI_Msk & (_UINT32_(value) << ETH_ISR_SRI_Pos)) /* Assigment of value for SRI in the ETH_ISR register */
#define ETH_ISR_WOL_Pos                       _UINT32_(28)                                         /* (ETH_ISR) Wake On LAN Position */
#define ETH_ISR_WOL_Msk                       (_UINT32_(0x1) << ETH_ISR_WOL_Pos)                   /* (ETH_ISR) Wake On LAN Mask */
#define ETH_ISR_WOL(value)                    (ETH_ISR_WOL_Msk & (_UINT32_(value) << ETH_ISR_WOL_Pos)) /* Assigment of value for WOL in the ETH_ISR register */
#define ETH_ISR_TSUCMP_Pos                    _UINT32_(29)                                         /* (ETH_ISR) Tsu timer comparison Position */
#define ETH_ISR_TSUCMP_Msk                    (_UINT32_(0x1) << ETH_ISR_TSUCMP_Pos)                /* (ETH_ISR) Tsu timer comparison Mask */
#define ETH_ISR_TSUCMP(value)                 (ETH_ISR_TSUCMP_Msk & (_UINT32_(value) << ETH_ISR_TSUCMP_Pos)) /* Assigment of value for TSUCMP in the ETH_ISR register */
#define ETH_ISR_Msk                           _UINT32_(0x37FC7CFF)                                 /* (ETH_ISR) Register Mask  */


/* -------- ETH_IER : (ETH Offset: 0x1028) ( /W 32) Interrupt Enable Register -------- */
#define ETH_IER_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_IER) Interrupt Enable Register  Reset Value */

#define ETH_IER_MFS_Pos                       _UINT32_(0)                                          /* (ETH_IER) Management Frame Sent Position */
#define ETH_IER_MFS_Msk                       (_UINT32_(0x1) << ETH_IER_MFS_Pos)                   /* (ETH_IER) Management Frame Sent Mask */
#define ETH_IER_MFS(value)                    (ETH_IER_MFS_Msk & (_UINT32_(value) << ETH_IER_MFS_Pos)) /* Assigment of value for MFS in the ETH_IER register */
#define ETH_IER_RCOMP_Pos                     _UINT32_(1)                                          /* (ETH_IER) Receive Complete Position */
#define ETH_IER_RCOMP_Msk                     (_UINT32_(0x1) << ETH_IER_RCOMP_Pos)                 /* (ETH_IER) Receive Complete Mask */
#define ETH_IER_RCOMP(value)                  (ETH_IER_RCOMP_Msk & (_UINT32_(value) << ETH_IER_RCOMP_Pos)) /* Assigment of value for RCOMP in the ETH_IER register */
#define ETH_IER_RXUBR_Pos                     _UINT32_(2)                                          /* (ETH_IER) RX Used Bit Read Position */
#define ETH_IER_RXUBR_Msk                     (_UINT32_(0x1) << ETH_IER_RXUBR_Pos)                 /* (ETH_IER) RX Used Bit Read Mask */
#define ETH_IER_RXUBR(value)                  (ETH_IER_RXUBR_Msk & (_UINT32_(value) << ETH_IER_RXUBR_Pos)) /* Assigment of value for RXUBR in the ETH_IER register */
#define ETH_IER_TXUBR_Pos                     _UINT32_(3)                                          /* (ETH_IER) TX Used Bit Read Position */
#define ETH_IER_TXUBR_Msk                     (_UINT32_(0x1) << ETH_IER_TXUBR_Pos)                 /* (ETH_IER) TX Used Bit Read Mask */
#define ETH_IER_TXUBR(value)                  (ETH_IER_TXUBR_Msk & (_UINT32_(value) << ETH_IER_TXUBR_Pos)) /* Assigment of value for TXUBR in the ETH_IER register */
#define ETH_IER_TUR_Pos                       _UINT32_(4)                                          /* (ETH_IER) Transmit Underrun Position */
#define ETH_IER_TUR_Msk                       (_UINT32_(0x1) << ETH_IER_TUR_Pos)                   /* (ETH_IER) Transmit Underrun Mask */
#define ETH_IER_TUR(value)                    (ETH_IER_TUR_Msk & (_UINT32_(value) << ETH_IER_TUR_Pos)) /* Assigment of value for TUR in the ETH_IER register */
#define ETH_IER_RLEX_Pos                      _UINT32_(5)                                          /* (ETH_IER) Retry Limit Exceeded or Late Collision Position */
#define ETH_IER_RLEX_Msk                      (_UINT32_(0x1) << ETH_IER_RLEX_Pos)                  /* (ETH_IER) Retry Limit Exceeded or Late Collision Mask */
#define ETH_IER_RLEX(value)                   (ETH_IER_RLEX_Msk & (_UINT32_(value) << ETH_IER_RLEX_Pos)) /* Assigment of value for RLEX in the ETH_IER register */
#define ETH_IER_TFC_Pos                       _UINT32_(6)                                          /* (ETH_IER) Transmit Frame Corruption Due to AHB Error Position */
#define ETH_IER_TFC_Msk                       (_UINT32_(0x1) << ETH_IER_TFC_Pos)                   /* (ETH_IER) Transmit Frame Corruption Due to AHB Error Mask */
#define ETH_IER_TFC(value)                    (ETH_IER_TFC_Msk & (_UINT32_(value) << ETH_IER_TFC_Pos)) /* Assigment of value for TFC in the ETH_IER register */
#define ETH_IER_TCOMP_Pos                     _UINT32_(7)                                          /* (ETH_IER) Transmit Complete Position */
#define ETH_IER_TCOMP_Msk                     (_UINT32_(0x1) << ETH_IER_TCOMP_Pos)                 /* (ETH_IER) Transmit Complete Mask */
#define ETH_IER_TCOMP(value)                  (ETH_IER_TCOMP_Msk & (_UINT32_(value) << ETH_IER_TCOMP_Pos)) /* Assigment of value for TCOMP in the ETH_IER register */
#define ETH_IER_ROVR_Pos                      _UINT32_(10)                                         /* (ETH_IER) Receive Overrun Position */
#define ETH_IER_ROVR_Msk                      (_UINT32_(0x1) << ETH_IER_ROVR_Pos)                  /* (ETH_IER) Receive Overrun Mask */
#define ETH_IER_ROVR(value)                   (ETH_IER_ROVR_Msk & (_UINT32_(value) << ETH_IER_ROVR_Pos)) /* Assigment of value for ROVR in the ETH_IER register */
#define ETH_IER_HRESP_Pos                     _UINT32_(11)                                         /* (ETH_IER) HRESP Not OK Position */
#define ETH_IER_HRESP_Msk                     (_UINT32_(0x1) << ETH_IER_HRESP_Pos)                 /* (ETH_IER) HRESP Not OK Mask */
#define ETH_IER_HRESP(value)                  (ETH_IER_HRESP_Msk & (_UINT32_(value) << ETH_IER_HRESP_Pos)) /* Assigment of value for HRESP in the ETH_IER register */
#define ETH_IER_PFNZ_Pos                      _UINT32_(12)                                         /* (ETH_IER) Pause Frame with Non-zero Pause Quantum Received Position */
#define ETH_IER_PFNZ_Msk                      (_UINT32_(0x1) << ETH_IER_PFNZ_Pos)                  /* (ETH_IER) Pause Frame with Non-zero Pause Quantum Received Mask */
#define ETH_IER_PFNZ(value)                   (ETH_IER_PFNZ_Msk & (_UINT32_(value) << ETH_IER_PFNZ_Pos)) /* Assigment of value for PFNZ in the ETH_IER register */
#define ETH_IER_PTZ_Pos                       _UINT32_(13)                                         /* (ETH_IER) Pause Time Zero Position */
#define ETH_IER_PTZ_Msk                       (_UINT32_(0x1) << ETH_IER_PTZ_Pos)                   /* (ETH_IER) Pause Time Zero Mask */
#define ETH_IER_PTZ(value)                    (ETH_IER_PTZ_Msk & (_UINT32_(value) << ETH_IER_PTZ_Pos)) /* Assigment of value for PTZ in the ETH_IER register */
#define ETH_IER_PFTR_Pos                      _UINT32_(14)                                         /* (ETH_IER) Pause Frame Transmitted Position */
#define ETH_IER_PFTR_Msk                      (_UINT32_(0x1) << ETH_IER_PFTR_Pos)                  /* (ETH_IER) Pause Frame Transmitted Mask */
#define ETH_IER_PFTR(value)                   (ETH_IER_PFTR_Msk & (_UINT32_(value) << ETH_IER_PFTR_Pos)) /* Assigment of value for PFTR in the ETH_IER register */
#define ETH_IER_EXINT_Pos                     _UINT32_(15)                                         /* (ETH_IER) External Interrupt Position */
#define ETH_IER_EXINT_Msk                     (_UINT32_(0x1) << ETH_IER_EXINT_Pos)                 /* (ETH_IER) External Interrupt Mask */
#define ETH_IER_EXINT(value)                  (ETH_IER_EXINT_Msk & (_UINT32_(value) << ETH_IER_EXINT_Pos)) /* Assigment of value for EXINT in the ETH_IER register */
#define ETH_IER_DRQFR_Pos                     _UINT32_(18)                                         /* (ETH_IER) PTP Delay Request Frame Received Position */
#define ETH_IER_DRQFR_Msk                     (_UINT32_(0x1) << ETH_IER_DRQFR_Pos)                 /* (ETH_IER) PTP Delay Request Frame Received Mask */
#define ETH_IER_DRQFR(value)                  (ETH_IER_DRQFR_Msk & (_UINT32_(value) << ETH_IER_DRQFR_Pos)) /* Assigment of value for DRQFR in the ETH_IER register */
#define ETH_IER_SFR_Pos                       _UINT32_(19)                                         /* (ETH_IER) PTP Sync Frame Received Position */
#define ETH_IER_SFR_Msk                       (_UINT32_(0x1) << ETH_IER_SFR_Pos)                   /* (ETH_IER) PTP Sync Frame Received Mask */
#define ETH_IER_SFR(value)                    (ETH_IER_SFR_Msk & (_UINT32_(value) << ETH_IER_SFR_Pos)) /* Assigment of value for SFR in the ETH_IER register */
#define ETH_IER_DRQFT_Pos                     _UINT32_(20)                                         /* (ETH_IER) PTP Delay Request Frame Transmitted Position */
#define ETH_IER_DRQFT_Msk                     (_UINT32_(0x1) << ETH_IER_DRQFT_Pos)                 /* (ETH_IER) PTP Delay Request Frame Transmitted Mask */
#define ETH_IER_DRQFT(value)                  (ETH_IER_DRQFT_Msk & (_UINT32_(value) << ETH_IER_DRQFT_Pos)) /* Assigment of value for DRQFT in the ETH_IER register */
#define ETH_IER_SFT_Pos                       _UINT32_(21)                                         /* (ETH_IER) PTP Sync Frame Transmitted Position */
#define ETH_IER_SFT_Msk                       (_UINT32_(0x1) << ETH_IER_SFT_Pos)                   /* (ETH_IER) PTP Sync Frame Transmitted Mask */
#define ETH_IER_SFT(value)                    (ETH_IER_SFT_Msk & (_UINT32_(value) << ETH_IER_SFT_Pos)) /* Assigment of value for SFT in the ETH_IER register */
#define ETH_IER_PDRQFR_Pos                    _UINT32_(22)                                         /* (ETH_IER) PDelay Request Frame Received Position */
#define ETH_IER_PDRQFR_Msk                    (_UINT32_(0x1) << ETH_IER_PDRQFR_Pos)                /* (ETH_IER) PDelay Request Frame Received Mask */
#define ETH_IER_PDRQFR(value)                 (ETH_IER_PDRQFR_Msk & (_UINT32_(value) << ETH_IER_PDRQFR_Pos)) /* Assigment of value for PDRQFR in the ETH_IER register */
#define ETH_IER_PDRSFR_Pos                    _UINT32_(23)                                         /* (ETH_IER) PDelay Response Frame Received Position */
#define ETH_IER_PDRSFR_Msk                    (_UINT32_(0x1) << ETH_IER_PDRSFR_Pos)                /* (ETH_IER) PDelay Response Frame Received Mask */
#define ETH_IER_PDRSFR(value)                 (ETH_IER_PDRSFR_Msk & (_UINT32_(value) << ETH_IER_PDRSFR_Pos)) /* Assigment of value for PDRSFR in the ETH_IER register */
#define ETH_IER_PDRQFT_Pos                    _UINT32_(24)                                         /* (ETH_IER) PDelay Request Frame Transmitted Position */
#define ETH_IER_PDRQFT_Msk                    (_UINT32_(0x1) << ETH_IER_PDRQFT_Pos)                /* (ETH_IER) PDelay Request Frame Transmitted Mask */
#define ETH_IER_PDRQFT(value)                 (ETH_IER_PDRQFT_Msk & (_UINT32_(value) << ETH_IER_PDRQFT_Pos)) /* Assigment of value for PDRQFT in the ETH_IER register */
#define ETH_IER_PDRSFT_Pos                    _UINT32_(25)                                         /* (ETH_IER) PDelay Response Frame Transmitted Position */
#define ETH_IER_PDRSFT_Msk                    (_UINT32_(0x1) << ETH_IER_PDRSFT_Pos)                /* (ETH_IER) PDelay Response Frame Transmitted Mask */
#define ETH_IER_PDRSFT(value)                 (ETH_IER_PDRSFT_Msk & (_UINT32_(value) << ETH_IER_PDRSFT_Pos)) /* Assigment of value for PDRSFT in the ETH_IER register */
#define ETH_IER_SRI_Pos                       _UINT32_(26)                                         /* (ETH_IER) TSU Seconds Register Increment Position */
#define ETH_IER_SRI_Msk                       (_UINT32_(0x1) << ETH_IER_SRI_Pos)                   /* (ETH_IER) TSU Seconds Register Increment Mask */
#define ETH_IER_SRI(value)                    (ETH_IER_SRI_Msk & (_UINT32_(value) << ETH_IER_SRI_Pos)) /* Assigment of value for SRI in the ETH_IER register */
#define ETH_IER_WOL_Pos                       _UINT32_(28)                                         /* (ETH_IER) Wake On LAN Position */
#define ETH_IER_WOL_Msk                       (_UINT32_(0x1) << ETH_IER_WOL_Pos)                   /* (ETH_IER) Wake On LAN Mask */
#define ETH_IER_WOL(value)                    (ETH_IER_WOL_Msk & (_UINT32_(value) << ETH_IER_WOL_Pos)) /* Assigment of value for WOL in the ETH_IER register */
#define ETH_IER_TSUCMP_Pos                    _UINT32_(29)                                         /* (ETH_IER) Tsu timer comparison Position */
#define ETH_IER_TSUCMP_Msk                    (_UINT32_(0x1) << ETH_IER_TSUCMP_Pos)                /* (ETH_IER) Tsu timer comparison Mask */
#define ETH_IER_TSUCMP(value)                 (ETH_IER_TSUCMP_Msk & (_UINT32_(value) << ETH_IER_TSUCMP_Pos)) /* Assigment of value for TSUCMP in the ETH_IER register */
#define ETH_IER_Msk                           _UINT32_(0x37FCFCFF)                                 /* (ETH_IER) Register Mask  */


/* -------- ETH_IDR : (ETH Offset: 0x102C) ( /W 32) Interrupt Disable Register -------- */
#define ETH_IDR_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_IDR) Interrupt Disable Register  Reset Value */

#define ETH_IDR_MFS_Pos                       _UINT32_(0)                                          /* (ETH_IDR) Management Frame Sent Position */
#define ETH_IDR_MFS_Msk                       (_UINT32_(0x1) << ETH_IDR_MFS_Pos)                   /* (ETH_IDR) Management Frame Sent Mask */
#define ETH_IDR_MFS(value)                    (ETH_IDR_MFS_Msk & (_UINT32_(value) << ETH_IDR_MFS_Pos)) /* Assigment of value for MFS in the ETH_IDR register */
#define ETH_IDR_RCOMP_Pos                     _UINT32_(1)                                          /* (ETH_IDR) Receive Complete Position */
#define ETH_IDR_RCOMP_Msk                     (_UINT32_(0x1) << ETH_IDR_RCOMP_Pos)                 /* (ETH_IDR) Receive Complete Mask */
#define ETH_IDR_RCOMP(value)                  (ETH_IDR_RCOMP_Msk & (_UINT32_(value) << ETH_IDR_RCOMP_Pos)) /* Assigment of value for RCOMP in the ETH_IDR register */
#define ETH_IDR_RXUBR_Pos                     _UINT32_(2)                                          /* (ETH_IDR) RX Used Bit Read Position */
#define ETH_IDR_RXUBR_Msk                     (_UINT32_(0x1) << ETH_IDR_RXUBR_Pos)                 /* (ETH_IDR) RX Used Bit Read Mask */
#define ETH_IDR_RXUBR(value)                  (ETH_IDR_RXUBR_Msk & (_UINT32_(value) << ETH_IDR_RXUBR_Pos)) /* Assigment of value for RXUBR in the ETH_IDR register */
#define ETH_IDR_TXUBR_Pos                     _UINT32_(3)                                          /* (ETH_IDR) TX Used Bit Read Position */
#define ETH_IDR_TXUBR_Msk                     (_UINT32_(0x1) << ETH_IDR_TXUBR_Pos)                 /* (ETH_IDR) TX Used Bit Read Mask */
#define ETH_IDR_TXUBR(value)                  (ETH_IDR_TXUBR_Msk & (_UINT32_(value) << ETH_IDR_TXUBR_Pos)) /* Assigment of value for TXUBR in the ETH_IDR register */
#define ETH_IDR_TUR_Pos                       _UINT32_(4)                                          /* (ETH_IDR) Transmit Underrun Position */
#define ETH_IDR_TUR_Msk                       (_UINT32_(0x1) << ETH_IDR_TUR_Pos)                   /* (ETH_IDR) Transmit Underrun Mask */
#define ETH_IDR_TUR(value)                    (ETH_IDR_TUR_Msk & (_UINT32_(value) << ETH_IDR_TUR_Pos)) /* Assigment of value for TUR in the ETH_IDR register */
#define ETH_IDR_RLEX_Pos                      _UINT32_(5)                                          /* (ETH_IDR) Retry Limit Exceeded or Late Collision Position */
#define ETH_IDR_RLEX_Msk                      (_UINT32_(0x1) << ETH_IDR_RLEX_Pos)                  /* (ETH_IDR) Retry Limit Exceeded or Late Collision Mask */
#define ETH_IDR_RLEX(value)                   (ETH_IDR_RLEX_Msk & (_UINT32_(value) << ETH_IDR_RLEX_Pos)) /* Assigment of value for RLEX in the ETH_IDR register */
#define ETH_IDR_TFC_Pos                       _UINT32_(6)                                          /* (ETH_IDR) Transmit Frame Corruption Due to AHB Error Position */
#define ETH_IDR_TFC_Msk                       (_UINT32_(0x1) << ETH_IDR_TFC_Pos)                   /* (ETH_IDR) Transmit Frame Corruption Due to AHB Error Mask */
#define ETH_IDR_TFC(value)                    (ETH_IDR_TFC_Msk & (_UINT32_(value) << ETH_IDR_TFC_Pos)) /* Assigment of value for TFC in the ETH_IDR register */
#define ETH_IDR_TCOMP_Pos                     _UINT32_(7)                                          /* (ETH_IDR) Transmit Complete Position */
#define ETH_IDR_TCOMP_Msk                     (_UINT32_(0x1) << ETH_IDR_TCOMP_Pos)                 /* (ETH_IDR) Transmit Complete Mask */
#define ETH_IDR_TCOMP(value)                  (ETH_IDR_TCOMP_Msk & (_UINT32_(value) << ETH_IDR_TCOMP_Pos)) /* Assigment of value for TCOMP in the ETH_IDR register */
#define ETH_IDR_ROVR_Pos                      _UINT32_(10)                                         /* (ETH_IDR) Receive Overrun Position */
#define ETH_IDR_ROVR_Msk                      (_UINT32_(0x1) << ETH_IDR_ROVR_Pos)                  /* (ETH_IDR) Receive Overrun Mask */
#define ETH_IDR_ROVR(value)                   (ETH_IDR_ROVR_Msk & (_UINT32_(value) << ETH_IDR_ROVR_Pos)) /* Assigment of value for ROVR in the ETH_IDR register */
#define ETH_IDR_HRESP_Pos                     _UINT32_(11)                                         /* (ETH_IDR) HRESP Not OK Position */
#define ETH_IDR_HRESP_Msk                     (_UINT32_(0x1) << ETH_IDR_HRESP_Pos)                 /* (ETH_IDR) HRESP Not OK Mask */
#define ETH_IDR_HRESP(value)                  (ETH_IDR_HRESP_Msk & (_UINT32_(value) << ETH_IDR_HRESP_Pos)) /* Assigment of value for HRESP in the ETH_IDR register */
#define ETH_IDR_PFNZ_Pos                      _UINT32_(12)                                         /* (ETH_IDR) Pause Frame with Non-zero Pause Quantum Received Position */
#define ETH_IDR_PFNZ_Msk                      (_UINT32_(0x1) << ETH_IDR_PFNZ_Pos)                  /* (ETH_IDR) Pause Frame with Non-zero Pause Quantum Received Mask */
#define ETH_IDR_PFNZ(value)                   (ETH_IDR_PFNZ_Msk & (_UINT32_(value) << ETH_IDR_PFNZ_Pos)) /* Assigment of value for PFNZ in the ETH_IDR register */
#define ETH_IDR_PTZ_Pos                       _UINT32_(13)                                         /* (ETH_IDR) Pause Time Zero Position */
#define ETH_IDR_PTZ_Msk                       (_UINT32_(0x1) << ETH_IDR_PTZ_Pos)                   /* (ETH_IDR) Pause Time Zero Mask */
#define ETH_IDR_PTZ(value)                    (ETH_IDR_PTZ_Msk & (_UINT32_(value) << ETH_IDR_PTZ_Pos)) /* Assigment of value for PTZ in the ETH_IDR register */
#define ETH_IDR_PFTR_Pos                      _UINT32_(14)                                         /* (ETH_IDR) Pause Frame Transmitted Position */
#define ETH_IDR_PFTR_Msk                      (_UINT32_(0x1) << ETH_IDR_PFTR_Pos)                  /* (ETH_IDR) Pause Frame Transmitted Mask */
#define ETH_IDR_PFTR(value)                   (ETH_IDR_PFTR_Msk & (_UINT32_(value) << ETH_IDR_PFTR_Pos)) /* Assigment of value for PFTR in the ETH_IDR register */
#define ETH_IDR_EXINT_Pos                     _UINT32_(15)                                         /* (ETH_IDR) External Interrupt Position */
#define ETH_IDR_EXINT_Msk                     (_UINT32_(0x1) << ETH_IDR_EXINT_Pos)                 /* (ETH_IDR) External Interrupt Mask */
#define ETH_IDR_EXINT(value)                  (ETH_IDR_EXINT_Msk & (_UINT32_(value) << ETH_IDR_EXINT_Pos)) /* Assigment of value for EXINT in the ETH_IDR register */
#define ETH_IDR_DRQFR_Pos                     _UINT32_(18)                                         /* (ETH_IDR) PTP Delay Request Frame Received Position */
#define ETH_IDR_DRQFR_Msk                     (_UINT32_(0x1) << ETH_IDR_DRQFR_Pos)                 /* (ETH_IDR) PTP Delay Request Frame Received Mask */
#define ETH_IDR_DRQFR(value)                  (ETH_IDR_DRQFR_Msk & (_UINT32_(value) << ETH_IDR_DRQFR_Pos)) /* Assigment of value for DRQFR in the ETH_IDR register */
#define ETH_IDR_SFR_Pos                       _UINT32_(19)                                         /* (ETH_IDR) PTP Sync Frame Received Position */
#define ETH_IDR_SFR_Msk                       (_UINT32_(0x1) << ETH_IDR_SFR_Pos)                   /* (ETH_IDR) PTP Sync Frame Received Mask */
#define ETH_IDR_SFR(value)                    (ETH_IDR_SFR_Msk & (_UINT32_(value) << ETH_IDR_SFR_Pos)) /* Assigment of value for SFR in the ETH_IDR register */
#define ETH_IDR_DRQFT_Pos                     _UINT32_(20)                                         /* (ETH_IDR) PTP Delay Request Frame Transmitted Position */
#define ETH_IDR_DRQFT_Msk                     (_UINT32_(0x1) << ETH_IDR_DRQFT_Pos)                 /* (ETH_IDR) PTP Delay Request Frame Transmitted Mask */
#define ETH_IDR_DRQFT(value)                  (ETH_IDR_DRQFT_Msk & (_UINT32_(value) << ETH_IDR_DRQFT_Pos)) /* Assigment of value for DRQFT in the ETH_IDR register */
#define ETH_IDR_SFT_Pos                       _UINT32_(21)                                         /* (ETH_IDR) PTP Sync Frame Transmitted Position */
#define ETH_IDR_SFT_Msk                       (_UINT32_(0x1) << ETH_IDR_SFT_Pos)                   /* (ETH_IDR) PTP Sync Frame Transmitted Mask */
#define ETH_IDR_SFT(value)                    (ETH_IDR_SFT_Msk & (_UINT32_(value) << ETH_IDR_SFT_Pos)) /* Assigment of value for SFT in the ETH_IDR register */
#define ETH_IDR_PDRQFR_Pos                    _UINT32_(22)                                         /* (ETH_IDR) PDelay Request Frame Received Position */
#define ETH_IDR_PDRQFR_Msk                    (_UINT32_(0x1) << ETH_IDR_PDRQFR_Pos)                /* (ETH_IDR) PDelay Request Frame Received Mask */
#define ETH_IDR_PDRQFR(value)                 (ETH_IDR_PDRQFR_Msk & (_UINT32_(value) << ETH_IDR_PDRQFR_Pos)) /* Assigment of value for PDRQFR in the ETH_IDR register */
#define ETH_IDR_PDRSFR_Pos                    _UINT32_(23)                                         /* (ETH_IDR) PDelay Response Frame Received Position */
#define ETH_IDR_PDRSFR_Msk                    (_UINT32_(0x1) << ETH_IDR_PDRSFR_Pos)                /* (ETH_IDR) PDelay Response Frame Received Mask */
#define ETH_IDR_PDRSFR(value)                 (ETH_IDR_PDRSFR_Msk & (_UINT32_(value) << ETH_IDR_PDRSFR_Pos)) /* Assigment of value for PDRSFR in the ETH_IDR register */
#define ETH_IDR_PDRQFT_Pos                    _UINT32_(24)                                         /* (ETH_IDR) PDelay Request Frame Transmitted Position */
#define ETH_IDR_PDRQFT_Msk                    (_UINT32_(0x1) << ETH_IDR_PDRQFT_Pos)                /* (ETH_IDR) PDelay Request Frame Transmitted Mask */
#define ETH_IDR_PDRQFT(value)                 (ETH_IDR_PDRQFT_Msk & (_UINT32_(value) << ETH_IDR_PDRQFT_Pos)) /* Assigment of value for PDRQFT in the ETH_IDR register */
#define ETH_IDR_PDRSFT_Pos                    _UINT32_(25)                                         /* (ETH_IDR) PDelay Response Frame Transmitted Position */
#define ETH_IDR_PDRSFT_Msk                    (_UINT32_(0x1) << ETH_IDR_PDRSFT_Pos)                /* (ETH_IDR) PDelay Response Frame Transmitted Mask */
#define ETH_IDR_PDRSFT(value)                 (ETH_IDR_PDRSFT_Msk & (_UINT32_(value) << ETH_IDR_PDRSFT_Pos)) /* Assigment of value for PDRSFT in the ETH_IDR register */
#define ETH_IDR_SRI_Pos                       _UINT32_(26)                                         /* (ETH_IDR) TSU Seconds Register Increment Position */
#define ETH_IDR_SRI_Msk                       (_UINT32_(0x1) << ETH_IDR_SRI_Pos)                   /* (ETH_IDR) TSU Seconds Register Increment Mask */
#define ETH_IDR_SRI(value)                    (ETH_IDR_SRI_Msk & (_UINT32_(value) << ETH_IDR_SRI_Pos)) /* Assigment of value for SRI in the ETH_IDR register */
#define ETH_IDR_WOL_Pos                       _UINT32_(28)                                         /* (ETH_IDR) Wake On LAN Position */
#define ETH_IDR_WOL_Msk                       (_UINT32_(0x1) << ETH_IDR_WOL_Pos)                   /* (ETH_IDR) Wake On LAN Mask */
#define ETH_IDR_WOL(value)                    (ETH_IDR_WOL_Msk & (_UINT32_(value) << ETH_IDR_WOL_Pos)) /* Assigment of value for WOL in the ETH_IDR register */
#define ETH_IDR_TSUCMP_Pos                    _UINT32_(29)                                         /* (ETH_IDR) Tsu timer comparison Position */
#define ETH_IDR_TSUCMP_Msk                    (_UINT32_(0x1) << ETH_IDR_TSUCMP_Pos)                /* (ETH_IDR) Tsu timer comparison Mask */
#define ETH_IDR_TSUCMP(value)                 (ETH_IDR_TSUCMP_Msk & (_UINT32_(value) << ETH_IDR_TSUCMP_Pos)) /* Assigment of value for TSUCMP in the ETH_IDR register */
#define ETH_IDR_Msk                           _UINT32_(0x37FCFCFF)                                 /* (ETH_IDR) Register Mask  */


/* -------- ETH_IMR : (ETH Offset: 0x1030) ( R/ 32) Interrupt Mask Register -------- */
#define ETH_IMR_RESETVALUE                    _UINT32_(0x3FFFFFFF)                                 /*  (ETH_IMR) Interrupt Mask Register  Reset Value */

#define ETH_IMR_MFS_Pos                       _UINT32_(0)                                          /* (ETH_IMR) Management Frame Sent Position */
#define ETH_IMR_MFS_Msk                       (_UINT32_(0x1) << ETH_IMR_MFS_Pos)                   /* (ETH_IMR) Management Frame Sent Mask */
#define ETH_IMR_MFS(value)                    (ETH_IMR_MFS_Msk & (_UINT32_(value) << ETH_IMR_MFS_Pos)) /* Assigment of value for MFS in the ETH_IMR register */
#define ETH_IMR_RCOMP_Pos                     _UINT32_(1)                                          /* (ETH_IMR) Receive Complete Position */
#define ETH_IMR_RCOMP_Msk                     (_UINT32_(0x1) << ETH_IMR_RCOMP_Pos)                 /* (ETH_IMR) Receive Complete Mask */
#define ETH_IMR_RCOMP(value)                  (ETH_IMR_RCOMP_Msk & (_UINT32_(value) << ETH_IMR_RCOMP_Pos)) /* Assigment of value for RCOMP in the ETH_IMR register */
#define ETH_IMR_RXUBR_Pos                     _UINT32_(2)                                          /* (ETH_IMR) RX Used Bit Read Position */
#define ETH_IMR_RXUBR_Msk                     (_UINT32_(0x1) << ETH_IMR_RXUBR_Pos)                 /* (ETH_IMR) RX Used Bit Read Mask */
#define ETH_IMR_RXUBR(value)                  (ETH_IMR_RXUBR_Msk & (_UINT32_(value) << ETH_IMR_RXUBR_Pos)) /* Assigment of value for RXUBR in the ETH_IMR register */
#define ETH_IMR_TXUBR_Pos                     _UINT32_(3)                                          /* (ETH_IMR) TX Used Bit Read Position */
#define ETH_IMR_TXUBR_Msk                     (_UINT32_(0x1) << ETH_IMR_TXUBR_Pos)                 /* (ETH_IMR) TX Used Bit Read Mask */
#define ETH_IMR_TXUBR(value)                  (ETH_IMR_TXUBR_Msk & (_UINT32_(value) << ETH_IMR_TXUBR_Pos)) /* Assigment of value for TXUBR in the ETH_IMR register */
#define ETH_IMR_TUR_Pos                       _UINT32_(4)                                          /* (ETH_IMR) Transmit Underrun Position */
#define ETH_IMR_TUR_Msk                       (_UINT32_(0x1) << ETH_IMR_TUR_Pos)                   /* (ETH_IMR) Transmit Underrun Mask */
#define ETH_IMR_TUR(value)                    (ETH_IMR_TUR_Msk & (_UINT32_(value) << ETH_IMR_TUR_Pos)) /* Assigment of value for TUR in the ETH_IMR register */
#define ETH_IMR_RLEX_Pos                      _UINT32_(5)                                          /* (ETH_IMR) Retry Limit Exceeded Position */
#define ETH_IMR_RLEX_Msk                      (_UINT32_(0x1) << ETH_IMR_RLEX_Pos)                  /* (ETH_IMR) Retry Limit Exceeded Mask */
#define ETH_IMR_RLEX(value)                   (ETH_IMR_RLEX_Msk & (_UINT32_(value) << ETH_IMR_RLEX_Pos)) /* Assigment of value for RLEX in the ETH_IMR register */
#define ETH_IMR_TFC_Pos                       _UINT32_(6)                                          /* (ETH_IMR) Transmit Frame Corruption Due to AHB Error Position */
#define ETH_IMR_TFC_Msk                       (_UINT32_(0x1) << ETH_IMR_TFC_Pos)                   /* (ETH_IMR) Transmit Frame Corruption Due to AHB Error Mask */
#define ETH_IMR_TFC(value)                    (ETH_IMR_TFC_Msk & (_UINT32_(value) << ETH_IMR_TFC_Pos)) /* Assigment of value for TFC in the ETH_IMR register */
#define ETH_IMR_TCOMP_Pos                     _UINT32_(7)                                          /* (ETH_IMR) Transmit Complete Position */
#define ETH_IMR_TCOMP_Msk                     (_UINT32_(0x1) << ETH_IMR_TCOMP_Pos)                 /* (ETH_IMR) Transmit Complete Mask */
#define ETH_IMR_TCOMP(value)                  (ETH_IMR_TCOMP_Msk & (_UINT32_(value) << ETH_IMR_TCOMP_Pos)) /* Assigment of value for TCOMP in the ETH_IMR register */
#define ETH_IMR_ROVR_Pos                      _UINT32_(10)                                         /* (ETH_IMR) Receive Overrun Position */
#define ETH_IMR_ROVR_Msk                      (_UINT32_(0x1) << ETH_IMR_ROVR_Pos)                  /* (ETH_IMR) Receive Overrun Mask */
#define ETH_IMR_ROVR(value)                   (ETH_IMR_ROVR_Msk & (_UINT32_(value) << ETH_IMR_ROVR_Pos)) /* Assigment of value for ROVR in the ETH_IMR register */
#define ETH_IMR_HRESP_Pos                     _UINT32_(11)                                         /* (ETH_IMR) HRESP Not OK Position */
#define ETH_IMR_HRESP_Msk                     (_UINT32_(0x1) << ETH_IMR_HRESP_Pos)                 /* (ETH_IMR) HRESP Not OK Mask */
#define ETH_IMR_HRESP(value)                  (ETH_IMR_HRESP_Msk & (_UINT32_(value) << ETH_IMR_HRESP_Pos)) /* Assigment of value for HRESP in the ETH_IMR register */
#define ETH_IMR_PFNZ_Pos                      _UINT32_(12)                                         /* (ETH_IMR) Pause Frame with Non-zero Pause Quantum Received Position */
#define ETH_IMR_PFNZ_Msk                      (_UINT32_(0x1) << ETH_IMR_PFNZ_Pos)                  /* (ETH_IMR) Pause Frame with Non-zero Pause Quantum Received Mask */
#define ETH_IMR_PFNZ(value)                   (ETH_IMR_PFNZ_Msk & (_UINT32_(value) << ETH_IMR_PFNZ_Pos)) /* Assigment of value for PFNZ in the ETH_IMR register */
#define ETH_IMR_PTZ_Pos                       _UINT32_(13)                                         /* (ETH_IMR) Pause Time Zero Position */
#define ETH_IMR_PTZ_Msk                       (_UINT32_(0x1) << ETH_IMR_PTZ_Pos)                   /* (ETH_IMR) Pause Time Zero Mask */
#define ETH_IMR_PTZ(value)                    (ETH_IMR_PTZ_Msk & (_UINT32_(value) << ETH_IMR_PTZ_Pos)) /* Assigment of value for PTZ in the ETH_IMR register */
#define ETH_IMR_PFTR_Pos                      _UINT32_(14)                                         /* (ETH_IMR) Pause Frame Transmitted Position */
#define ETH_IMR_PFTR_Msk                      (_UINT32_(0x1) << ETH_IMR_PFTR_Pos)                  /* (ETH_IMR) Pause Frame Transmitted Mask */
#define ETH_IMR_PFTR(value)                   (ETH_IMR_PFTR_Msk & (_UINT32_(value) << ETH_IMR_PFTR_Pos)) /* Assigment of value for PFTR in the ETH_IMR register */
#define ETH_IMR_EXINT_Pos                     _UINT32_(15)                                         /* (ETH_IMR) External Interrupt Position */
#define ETH_IMR_EXINT_Msk                     (_UINT32_(0x1) << ETH_IMR_EXINT_Pos)                 /* (ETH_IMR) External Interrupt Mask */
#define ETH_IMR_EXINT(value)                  (ETH_IMR_EXINT_Msk & (_UINT32_(value) << ETH_IMR_EXINT_Pos)) /* Assigment of value for EXINT in the ETH_IMR register */
#define ETH_IMR_DRQFR_Pos                     _UINT32_(18)                                         /* (ETH_IMR) PTP Delay Request Frame Received Position */
#define ETH_IMR_DRQFR_Msk                     (_UINT32_(0x1) << ETH_IMR_DRQFR_Pos)                 /* (ETH_IMR) PTP Delay Request Frame Received Mask */
#define ETH_IMR_DRQFR(value)                  (ETH_IMR_DRQFR_Msk & (_UINT32_(value) << ETH_IMR_DRQFR_Pos)) /* Assigment of value for DRQFR in the ETH_IMR register */
#define ETH_IMR_SFR_Pos                       _UINT32_(19)                                         /* (ETH_IMR) PTP Sync Frame Received Position */
#define ETH_IMR_SFR_Msk                       (_UINT32_(0x1) << ETH_IMR_SFR_Pos)                   /* (ETH_IMR) PTP Sync Frame Received Mask */
#define ETH_IMR_SFR(value)                    (ETH_IMR_SFR_Msk & (_UINT32_(value) << ETH_IMR_SFR_Pos)) /* Assigment of value for SFR in the ETH_IMR register */
#define ETH_IMR_DRQFT_Pos                     _UINT32_(20)                                         /* (ETH_IMR) PTP Delay Request Frame Transmitted Position */
#define ETH_IMR_DRQFT_Msk                     (_UINT32_(0x1) << ETH_IMR_DRQFT_Pos)                 /* (ETH_IMR) PTP Delay Request Frame Transmitted Mask */
#define ETH_IMR_DRQFT(value)                  (ETH_IMR_DRQFT_Msk & (_UINT32_(value) << ETH_IMR_DRQFT_Pos)) /* Assigment of value for DRQFT in the ETH_IMR register */
#define ETH_IMR_SFT_Pos                       _UINT32_(21)                                         /* (ETH_IMR) PTP Sync Frame Transmitted Position */
#define ETH_IMR_SFT_Msk                       (_UINT32_(0x1) << ETH_IMR_SFT_Pos)                   /* (ETH_IMR) PTP Sync Frame Transmitted Mask */
#define ETH_IMR_SFT(value)                    (ETH_IMR_SFT_Msk & (_UINT32_(value) << ETH_IMR_SFT_Pos)) /* Assigment of value for SFT in the ETH_IMR register */
#define ETH_IMR_PDRQFR_Pos                    _UINT32_(22)                                         /* (ETH_IMR) PDelay Request Frame Received Position */
#define ETH_IMR_PDRQFR_Msk                    (_UINT32_(0x1) << ETH_IMR_PDRQFR_Pos)                /* (ETH_IMR) PDelay Request Frame Received Mask */
#define ETH_IMR_PDRQFR(value)                 (ETH_IMR_PDRQFR_Msk & (_UINT32_(value) << ETH_IMR_PDRQFR_Pos)) /* Assigment of value for PDRQFR in the ETH_IMR register */
#define ETH_IMR_PDRSFR_Pos                    _UINT32_(23)                                         /* (ETH_IMR) PDelay Response Frame Received Position */
#define ETH_IMR_PDRSFR_Msk                    (_UINT32_(0x1) << ETH_IMR_PDRSFR_Pos)                /* (ETH_IMR) PDelay Response Frame Received Mask */
#define ETH_IMR_PDRSFR(value)                 (ETH_IMR_PDRSFR_Msk & (_UINT32_(value) << ETH_IMR_PDRSFR_Pos)) /* Assigment of value for PDRSFR in the ETH_IMR register */
#define ETH_IMR_PDRQFT_Pos                    _UINT32_(24)                                         /* (ETH_IMR) PDelay Request Frame Transmitted Position */
#define ETH_IMR_PDRQFT_Msk                    (_UINT32_(0x1) << ETH_IMR_PDRQFT_Pos)                /* (ETH_IMR) PDelay Request Frame Transmitted Mask */
#define ETH_IMR_PDRQFT(value)                 (ETH_IMR_PDRQFT_Msk & (_UINT32_(value) << ETH_IMR_PDRQFT_Pos)) /* Assigment of value for PDRQFT in the ETH_IMR register */
#define ETH_IMR_PDRSFT_Pos                    _UINT32_(25)                                         /* (ETH_IMR) PDelay Response Frame Transmitted Position */
#define ETH_IMR_PDRSFT_Msk                    (_UINT32_(0x1) << ETH_IMR_PDRSFT_Pos)                /* (ETH_IMR) PDelay Response Frame Transmitted Mask */
#define ETH_IMR_PDRSFT(value)                 (ETH_IMR_PDRSFT_Msk & (_UINT32_(value) << ETH_IMR_PDRSFT_Pos)) /* Assigment of value for PDRSFT in the ETH_IMR register */
#define ETH_IMR_SRI_Pos                       _UINT32_(26)                                         /* (ETH_IMR) TSU Seconds Register Increment Position */
#define ETH_IMR_SRI_Msk                       (_UINT32_(0x1) << ETH_IMR_SRI_Pos)                   /* (ETH_IMR) TSU Seconds Register Increment Mask */
#define ETH_IMR_SRI(value)                    (ETH_IMR_SRI_Msk & (_UINT32_(value) << ETH_IMR_SRI_Pos)) /* Assigment of value for SRI in the ETH_IMR register */
#define ETH_IMR_WOL_Pos                       _UINT32_(28)                                         /* (ETH_IMR) Wake On Lan Position */
#define ETH_IMR_WOL_Msk                       (_UINT32_(0x1) << ETH_IMR_WOL_Pos)                   /* (ETH_IMR) Wake On Lan Mask */
#define ETH_IMR_WOL(value)                    (ETH_IMR_WOL_Msk & (_UINT32_(value) << ETH_IMR_WOL_Pos)) /* Assigment of value for WOL in the ETH_IMR register */
#define ETH_IMR_TSUCMP_Pos                    _UINT32_(29)                                         /* (ETH_IMR) Tsu timer comparison Position */
#define ETH_IMR_TSUCMP_Msk                    (_UINT32_(0x1) << ETH_IMR_TSUCMP_Pos)                /* (ETH_IMR) Tsu timer comparison Mask */
#define ETH_IMR_TSUCMP(value)                 (ETH_IMR_TSUCMP_Msk & (_UINT32_(value) << ETH_IMR_TSUCMP_Pos)) /* Assigment of value for TSUCMP in the ETH_IMR register */
#define ETH_IMR_Msk                           _UINT32_(0x37FCFCFF)                                 /* (ETH_IMR) Register Mask  */


/* -------- ETH_MAN : (ETH Offset: 0x1034) (R/W 32) PHY Maintenance Register -------- */
#define ETH_MAN_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_MAN) PHY Maintenance Register  Reset Value */

#define ETH_MAN_DATA_Pos                      _UINT32_(0)                                          /* (ETH_MAN) PHY Data Position */
#define ETH_MAN_DATA_Msk                      (_UINT32_(0xFFFF) << ETH_MAN_DATA_Pos)               /* (ETH_MAN) PHY Data Mask */
#define ETH_MAN_DATA(value)                   (ETH_MAN_DATA_Msk & (_UINT32_(value) << ETH_MAN_DATA_Pos)) /* Assigment of value for DATA in the ETH_MAN register */
#define ETH_MAN_WTN_Pos                       _UINT32_(16)                                         /* (ETH_MAN) Write Ten Position */
#define ETH_MAN_WTN_Msk                       (_UINT32_(0x3) << ETH_MAN_WTN_Pos)                   /* (ETH_MAN) Write Ten Mask */
#define ETH_MAN_WTN(value)                    (ETH_MAN_WTN_Msk & (_UINT32_(value) << ETH_MAN_WTN_Pos)) /* Assigment of value for WTN in the ETH_MAN register */
#define ETH_MAN_REGA_Pos                      _UINT32_(18)                                         /* (ETH_MAN) Register Address Position */
#define ETH_MAN_REGA_Msk                      (_UINT32_(0x1F) << ETH_MAN_REGA_Pos)                 /* (ETH_MAN) Register Address Mask */
#define ETH_MAN_REGA(value)                   (ETH_MAN_REGA_Msk & (_UINT32_(value) << ETH_MAN_REGA_Pos)) /* Assigment of value for REGA in the ETH_MAN register */
#define ETH_MAN_PHYA_Pos                      _UINT32_(23)                                         /* (ETH_MAN) PHY Address Position */
#define ETH_MAN_PHYA_Msk                      (_UINT32_(0x1F) << ETH_MAN_PHYA_Pos)                 /* (ETH_MAN) PHY Address Mask */
#define ETH_MAN_PHYA(value)                   (ETH_MAN_PHYA_Msk & (_UINT32_(value) << ETH_MAN_PHYA_Pos)) /* Assigment of value for PHYA in the ETH_MAN register */
#define ETH_MAN_OP_Pos                        _UINT32_(28)                                         /* (ETH_MAN) Operation Position */
#define ETH_MAN_OP_Msk                        (_UINT32_(0x3) << ETH_MAN_OP_Pos)                    /* (ETH_MAN) Operation Mask */
#define ETH_MAN_OP(value)                     (ETH_MAN_OP_Msk & (_UINT32_(value) << ETH_MAN_OP_Pos)) /* Assigment of value for OP in the ETH_MAN register */
#define ETH_MAN_CLTTO_Pos                     _UINT32_(30)                                         /* (ETH_MAN) Clause 22 Operation Position */
#define ETH_MAN_CLTTO_Msk                     (_UINT32_(0x1) << ETH_MAN_CLTTO_Pos)                 /* (ETH_MAN) Clause 22 Operation Mask */
#define ETH_MAN_CLTTO(value)                  (ETH_MAN_CLTTO_Msk & (_UINT32_(value) << ETH_MAN_CLTTO_Pos)) /* Assigment of value for CLTTO in the ETH_MAN register */
#define ETH_MAN_WZO_Pos                       _UINT32_(31)                                         /* (ETH_MAN) Write ZERO Position */
#define ETH_MAN_WZO_Msk                       (_UINT32_(0x1) << ETH_MAN_WZO_Pos)                   /* (ETH_MAN) Write ZERO Mask */
#define ETH_MAN_WZO(value)                    (ETH_MAN_WZO_Msk & (_UINT32_(value) << ETH_MAN_WZO_Pos)) /* Assigment of value for WZO in the ETH_MAN register */
#define ETH_MAN_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (ETH_MAN) Register Mask  */


/* -------- ETH_RPQ : (ETH Offset: 0x1038) ( R/ 32) Received Pause Quantum Register -------- */
#define ETH_RPQ_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_RPQ) Received Pause Quantum Register  Reset Value */

#define ETH_RPQ_RPQ_Pos                       _UINT32_(0)                                          /* (ETH_RPQ) Received Pause Quantum Position */
#define ETH_RPQ_RPQ_Msk                       (_UINT32_(0xFFFF) << ETH_RPQ_RPQ_Pos)                /* (ETH_RPQ) Received Pause Quantum Mask */
#define ETH_RPQ_RPQ(value)                    (ETH_RPQ_RPQ_Msk & (_UINT32_(value) << ETH_RPQ_RPQ_Pos)) /* Assigment of value for RPQ in the ETH_RPQ register */
#define ETH_RPQ_Msk                           _UINT32_(0x0000FFFF)                                 /* (ETH_RPQ) Register Mask  */


/* -------- ETH_TPQ : (ETH Offset: 0x103C) (R/W 32) Transmit Pause Quantum Register -------- */
#define ETH_TPQ_RESETVALUE                    _UINT32_(0xFFFF)                                     /*  (ETH_TPQ) Transmit Pause Quantum Register  Reset Value */

#define ETH_TPQ_TPQ_Pos                       _UINT32_(0)                                          /* (ETH_TPQ) Transmit Pause Quantum Position */
#define ETH_TPQ_TPQ_Msk                       (_UINT32_(0xFFFF) << ETH_TPQ_TPQ_Pos)                /* (ETH_TPQ) Transmit Pause Quantum Mask */
#define ETH_TPQ_TPQ(value)                    (ETH_TPQ_TPQ_Msk & (_UINT32_(value) << ETH_TPQ_TPQ_Pos)) /* Assigment of value for TPQ in the ETH_TPQ register */
#define ETH_TPQ_Msk                           _UINT32_(0x0000FFFF)                                 /* (ETH_TPQ) Register Mask  */


/* -------- ETH_TPSF : (ETH Offset: 0x1040) (R/W 32) TX partial store and forward Register -------- */
#define ETH_TPSF_RESETVALUE                   _UINT32_(0x3FF)                                      /*  (ETH_TPSF) TX partial store and forward Register  Reset Value */

#define ETH_TPSF_TPB1ADR_Pos                  _UINT32_(0)                                          /* (ETH_TPSF) TX packet buffer address Position */
#define ETH_TPSF_TPB1ADR_Msk                  (_UINT32_(0x3FF) << ETH_TPSF_TPB1ADR_Pos)            /* (ETH_TPSF) TX packet buffer address Mask */
#define ETH_TPSF_TPB1ADR(value)               (ETH_TPSF_TPB1ADR_Msk & (_UINT32_(value) << ETH_TPSF_TPB1ADR_Pos)) /* Assigment of value for TPB1ADR in the ETH_TPSF register */
#define ETH_TPSF_ENTXP_Pos                    _UINT32_(31)                                         /* (ETH_TPSF) Enable TX partial store and forward operation Position */
#define ETH_TPSF_ENTXP_Msk                    (_UINT32_(0x1) << ETH_TPSF_ENTXP_Pos)                /* (ETH_TPSF) Enable TX partial store and forward operation Mask */
#define ETH_TPSF_ENTXP(value)                 (ETH_TPSF_ENTXP_Msk & (_UINT32_(value) << ETH_TPSF_ENTXP_Pos)) /* Assigment of value for ENTXP in the ETH_TPSF register */
#define ETH_TPSF_Msk                          _UINT32_(0x800003FF)                                 /* (ETH_TPSF) Register Mask  */


/* -------- ETH_RPSF : (ETH Offset: 0x1044) (R/W 32) RX partial store and forward Register -------- */
#define ETH_RPSF_RESETVALUE                   _UINT32_(0x3FF)                                      /*  (ETH_RPSF) RX partial store and forward Register  Reset Value */

#define ETH_RPSF_RPB1ADR_Pos                  _UINT32_(0)                                          /* (ETH_RPSF) RX packet buffer address Position */
#define ETH_RPSF_RPB1ADR_Msk                  (_UINT32_(0x3FF) << ETH_RPSF_RPB1ADR_Pos)            /* (ETH_RPSF) RX packet buffer address Mask */
#define ETH_RPSF_RPB1ADR(value)               (ETH_RPSF_RPB1ADR_Msk & (_UINT32_(value) << ETH_RPSF_RPB1ADR_Pos)) /* Assigment of value for RPB1ADR in the ETH_RPSF register */
#define ETH_RPSF_ENRXP_Pos                    _UINT32_(31)                                         /* (ETH_RPSF) Enable RX partial store and forward operation Position */
#define ETH_RPSF_ENRXP_Msk                    (_UINT32_(0x1) << ETH_RPSF_ENRXP_Pos)                /* (ETH_RPSF) Enable RX partial store and forward operation Mask */
#define ETH_RPSF_ENRXP(value)                 (ETH_RPSF_ENRXP_Msk & (_UINT32_(value) << ETH_RPSF_ENRXP_Pos)) /* Assigment of value for ENRXP in the ETH_RPSF register */
#define ETH_RPSF_Msk                          _UINT32_(0x800003FF)                                 /* (ETH_RPSF) Register Mask  */


/* -------- ETH_RJFML : (ETH Offset: 0x1048) (R/W 32) RX Jumbo Frame Max Length Register -------- */
#define ETH_RJFML_RESETVALUE                  _UINT32_(0x2800)                                     /*  (ETH_RJFML) RX Jumbo Frame Max Length Register  Reset Value */

#define ETH_RJFML_FML_Pos                     _UINT32_(0)                                          /* (ETH_RJFML) Frame Max Length Position */
#define ETH_RJFML_FML_Msk                     (_UINT32_(0x3FFF) << ETH_RJFML_FML_Pos)              /* (ETH_RJFML) Frame Max Length Mask */
#define ETH_RJFML_FML(value)                  (ETH_RJFML_FML_Msk & (_UINT32_(value) << ETH_RJFML_FML_Pos)) /* Assigment of value for FML in the ETH_RJFML register */
#define ETH_RJFML_Msk                         _UINT32_(0x00003FFF)                                 /* (ETH_RJFML) Register Mask  */


/* -------- ETH_HRB : (ETH Offset: 0x1080) (R/W 32) Hash Register Bottom [31:0] -------- */
#define ETH_HRB_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_HRB) Hash Register Bottom [31:0]  Reset Value */

#define ETH_HRB_ADDR_Pos                      _UINT32_(0)                                          /* (ETH_HRB) Hash Address Position */
#define ETH_HRB_ADDR_Msk                      (_UINT32_(0xFFFFFFFF) << ETH_HRB_ADDR_Pos)           /* (ETH_HRB) Hash Address Mask */
#define ETH_HRB_ADDR(value)                   (ETH_HRB_ADDR_Msk & (_UINT32_(value) << ETH_HRB_ADDR_Pos)) /* Assigment of value for ADDR in the ETH_HRB register */
#define ETH_HRB_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (ETH_HRB) Register Mask  */


/* -------- ETH_HRT : (ETH Offset: 0x1084) (R/W 32) Hash Register Top [63:32] -------- */
#define ETH_HRT_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_HRT) Hash Register Top [63:32]  Reset Value */

#define ETH_HRT_ADDR_Pos                      _UINT32_(0)                                          /* (ETH_HRT) Hash Address Position */
#define ETH_HRT_ADDR_Msk                      (_UINT32_(0xFFFFFFFF) << ETH_HRT_ADDR_Pos)           /* (ETH_HRT) Hash Address Mask */
#define ETH_HRT_ADDR(value)                   (ETH_HRT_ADDR_Msk & (_UINT32_(value) << ETH_HRT_ADDR_Pos)) /* Assigment of value for ADDR in the ETH_HRT register */
#define ETH_HRT_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (ETH_HRT) Register Mask  */


/* -------- ETH_TIDM : (ETH Offset: 0x10A8) (R/W 32) Type ID Match Register -------- */
#define ETH_TIDM_RESETVALUE                   _UINT32_(0x00)                                       /*  (ETH_TIDM) Type ID Match Register  Reset Value */

#define ETH_TIDM_TID_Pos                      _UINT32_(0)                                          /* (ETH_TIDM) Type ID Match 1 Position */
#define ETH_TIDM_TID_Msk                      (_UINT32_(0xFFFF) << ETH_TIDM_TID_Pos)               /* (ETH_TIDM) Type ID Match 1 Mask */
#define ETH_TIDM_TID(value)                   (ETH_TIDM_TID_Msk & (_UINT32_(value) << ETH_TIDM_TID_Pos)) /* Assigment of value for TID in the ETH_TIDM register */
#define ETH_TIDM_Msk                          _UINT32_(0x0000FFFF)                                 /* (ETH_TIDM) Register Mask  */


/* -------- ETH_WOL : (ETH Offset: 0x10B8) (R/W 32) Wake on LAN -------- */
#define ETH_WOL_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_WOL) Wake on LAN  Reset Value */

#define ETH_WOL_IP_Pos                        _UINT32_(0)                                          /* (ETH_WOL) IP address Position */
#define ETH_WOL_IP_Msk                        (_UINT32_(0xFFFF) << ETH_WOL_IP_Pos)                 /* (ETH_WOL) IP address Mask */
#define ETH_WOL_IP(value)                     (ETH_WOL_IP_Msk & (_UINT32_(value) << ETH_WOL_IP_Pos)) /* Assigment of value for IP in the ETH_WOL register */
#define ETH_WOL_MAG_Pos                       _UINT32_(16)                                         /* (ETH_WOL) Event enable Position */
#define ETH_WOL_MAG_Msk                       (_UINT32_(0x1) << ETH_WOL_MAG_Pos)                   /* (ETH_WOL) Event enable Mask */
#define ETH_WOL_MAG(value)                    (ETH_WOL_MAG_Msk & (_UINT32_(value) << ETH_WOL_MAG_Pos)) /* Assigment of value for MAG in the ETH_WOL register */
#define ETH_WOL_ARP_Pos                       _UINT32_(17)                                         /* (ETH_WOL) LAN ARP req Position */
#define ETH_WOL_ARP_Msk                       (_UINT32_(0x1) << ETH_WOL_ARP_Pos)                   /* (ETH_WOL) LAN ARP req Mask */
#define ETH_WOL_ARP(value)                    (ETH_WOL_ARP_Msk & (_UINT32_(value) << ETH_WOL_ARP_Pos)) /* Assigment of value for ARP in the ETH_WOL register */
#define ETH_WOL_SA1_Pos                       _UINT32_(18)                                         /* (ETH_WOL) WOL specific address reg 1 Position */
#define ETH_WOL_SA1_Msk                       (_UINT32_(0x1) << ETH_WOL_SA1_Pos)                   /* (ETH_WOL) WOL specific address reg 1 Mask */
#define ETH_WOL_SA1(value)                    (ETH_WOL_SA1_Msk & (_UINT32_(value) << ETH_WOL_SA1_Pos)) /* Assigment of value for SA1 in the ETH_WOL register */
#define ETH_WOL_MTI_Pos                       _UINT32_(19)                                         /* (ETH_WOL) WOL LAN multicast Position */
#define ETH_WOL_MTI_Msk                       (_UINT32_(0x1) << ETH_WOL_MTI_Pos)                   /* (ETH_WOL) WOL LAN multicast Mask */
#define ETH_WOL_MTI(value)                    (ETH_WOL_MTI_Msk & (_UINT32_(value) << ETH_WOL_MTI_Pos)) /* Assigment of value for MTI in the ETH_WOL register */
#define ETH_WOL_Msk                           _UINT32_(0x000FFFFF)                                 /* (ETH_WOL) Register Mask  */

#define ETH_WOL_SA_Pos                        _UINT32_(18)                                         /* (ETH_WOL Position) WOL specific address reg x */
#define ETH_WOL_SA_Msk                        (_UINT32_(0x1) << ETH_WOL_SA_Pos)                    /* (ETH_WOL Mask) SA */
#define ETH_WOL_SA(value)                     (ETH_WOL_SA_Msk & (_UINT32_(value) << ETH_WOL_SA_Pos)) 

/* -------- ETH_IPGS : (ETH Offset: 0x10BC) (R/W 32) IPG Stretch Register -------- */
#define ETH_IPGS_RESETVALUE                   _UINT32_(0x00)                                       /*  (ETH_IPGS) IPG Stretch Register  Reset Value */

#define ETH_IPGS_FL_Pos                       _UINT32_(0)                                          /* (ETH_IPGS) Frame Length Position */
#define ETH_IPGS_FL_Msk                       (_UINT32_(0xFFFF) << ETH_IPGS_FL_Pos)                /* (ETH_IPGS) Frame Length Mask */
#define ETH_IPGS_FL(value)                    (ETH_IPGS_FL_Msk & (_UINT32_(value) << ETH_IPGS_FL_Pos)) /* Assigment of value for FL in the ETH_IPGS register */
#define ETH_IPGS_Msk                          _UINT32_(0x0000FFFF)                                 /* (ETH_IPGS) Register Mask  */


/* -------- ETH_SVLAN : (ETH Offset: 0x10C0) (R/W 32) Stacked VLAN Register -------- */
#define ETH_SVLAN_RESETVALUE                  _UINT32_(0x00)                                       /*  (ETH_SVLAN) Stacked VLAN Register  Reset Value */

#define ETH_SVLAN_VLAN_TYPE_Pos               _UINT32_(0)                                          /* (ETH_SVLAN) User Defined VLAN_TYPE Field Position */
#define ETH_SVLAN_VLAN_TYPE_Msk               (_UINT32_(0xFFFF) << ETH_SVLAN_VLAN_TYPE_Pos)        /* (ETH_SVLAN) User Defined VLAN_TYPE Field Mask */
#define ETH_SVLAN_VLAN_TYPE(value)            (ETH_SVLAN_VLAN_TYPE_Msk & (_UINT32_(value) << ETH_SVLAN_VLAN_TYPE_Pos)) /* Assigment of value for VLAN_TYPE in the ETH_SVLAN register */
#define ETH_SVLAN_ESVLAN_Pos                  _UINT32_(31)                                         /* (ETH_SVLAN) Enable Stacked VLAN Processing Mode Position */
#define ETH_SVLAN_ESVLAN_Msk                  (_UINT32_(0x1) << ETH_SVLAN_ESVLAN_Pos)              /* (ETH_SVLAN) Enable Stacked VLAN Processing Mode Mask */
#define ETH_SVLAN_ESVLAN(value)               (ETH_SVLAN_ESVLAN_Msk & (_UINT32_(value) << ETH_SVLAN_ESVLAN_Pos)) /* Assigment of value for ESVLAN in the ETH_SVLAN register */
#define ETH_SVLAN_Msk                         _UINT32_(0x8000FFFF)                                 /* (ETH_SVLAN) Register Mask  */


/* -------- ETH_TPFCP : (ETH Offset: 0x10C4) (R/W 32) Transmit PFC Pause Register -------- */
#define ETH_TPFCP_RESETVALUE                  _UINT32_(0x00)                                       /*  (ETH_TPFCP) Transmit PFC Pause Register  Reset Value */

#define ETH_TPFCP_PEV_Pos                     _UINT32_(0)                                          /* (ETH_TPFCP) Priority Enable Vector Position */
#define ETH_TPFCP_PEV_Msk                     (_UINT32_(0xFF) << ETH_TPFCP_PEV_Pos)                /* (ETH_TPFCP) Priority Enable Vector Mask */
#define ETH_TPFCP_PEV(value)                  (ETH_TPFCP_PEV_Msk & (_UINT32_(value) << ETH_TPFCP_PEV_Pos)) /* Assigment of value for PEV in the ETH_TPFCP register */
#define ETH_TPFCP_PQ_Pos                      _UINT32_(8)                                          /* (ETH_TPFCP) Pause Quantum Position */
#define ETH_TPFCP_PQ_Msk                      (_UINT32_(0xFF) << ETH_TPFCP_PQ_Pos)                 /* (ETH_TPFCP) Pause Quantum Mask */
#define ETH_TPFCP_PQ(value)                   (ETH_TPFCP_PQ_Msk & (_UINT32_(value) << ETH_TPFCP_PQ_Pos)) /* Assigment of value for PQ in the ETH_TPFCP register */
#define ETH_TPFCP_Msk                         _UINT32_(0x0000FFFF)                                 /* (ETH_TPFCP) Register Mask  */


/* -------- ETH_SAMB1 : (ETH Offset: 0x10C8) (R/W 32) Specific Address 1 Mask Bottom [31:0] Register -------- */
#define ETH_SAMB1_RESETVALUE                  _UINT32_(0x00)                                       /*  (ETH_SAMB1) Specific Address 1 Mask Bottom [31:0] Register  Reset Value */

#define ETH_SAMB1_ADDR_Pos                    _UINT32_(0)                                          /* (ETH_SAMB1) Specific Address 1 Mask Position */
#define ETH_SAMB1_ADDR_Msk                    (_UINT32_(0xFFFFFFFF) << ETH_SAMB1_ADDR_Pos)         /* (ETH_SAMB1) Specific Address 1 Mask Mask */
#define ETH_SAMB1_ADDR(value)                 (ETH_SAMB1_ADDR_Msk & (_UINT32_(value) << ETH_SAMB1_ADDR_Pos)) /* Assigment of value for ADDR in the ETH_SAMB1 register */
#define ETH_SAMB1_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (ETH_SAMB1) Register Mask  */


/* -------- ETH_SAMT1 : (ETH Offset: 0x10CC) (R/W 32) Specific Address 1 Mask Top [47:32] Register -------- */
#define ETH_SAMT1_RESETVALUE                  _UINT32_(0x00)                                       /*  (ETH_SAMT1) Specific Address 1 Mask Top [47:32] Register  Reset Value */

#define ETH_SAMT1_ADDR_Pos                    _UINT32_(0)                                          /* (ETH_SAMT1) Specific Address 1 Mask Position */
#define ETH_SAMT1_ADDR_Msk                    (_UINT32_(0xFFFF) << ETH_SAMT1_ADDR_Pos)             /* (ETH_SAMT1) Specific Address 1 Mask Mask */
#define ETH_SAMT1_ADDR(value)                 (ETH_SAMT1_ADDR_Msk & (_UINT32_(value) << ETH_SAMT1_ADDR_Pos)) /* Assigment of value for ADDR in the ETH_SAMT1 register */
#define ETH_SAMT1_Msk                         _UINT32_(0x0000FFFF)                                 /* (ETH_SAMT1) Register Mask  */


/* -------- ETH_NSC : (ETH Offset: 0x10DC) (R/W 32) Tsu timer comparison nanoseconds Register -------- */
#define ETH_NSC_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_NSC) Tsu timer comparison nanoseconds Register  Reset Value */

#define ETH_NSC_NANOSEC_Pos                   _UINT32_(0)                                          /* (ETH_NSC) 1588 Timer Nanosecond comparison value Position */
#define ETH_NSC_NANOSEC_Msk                   (_UINT32_(0x1FFFFF) << ETH_NSC_NANOSEC_Pos)          /* (ETH_NSC) 1588 Timer Nanosecond comparison value Mask */
#define ETH_NSC_NANOSEC(value)                (ETH_NSC_NANOSEC_Msk & (_UINT32_(value) << ETH_NSC_NANOSEC_Pos)) /* Assigment of value for NANOSEC in the ETH_NSC register */
#define ETH_NSC_Msk                           _UINT32_(0x001FFFFF)                                 /* (ETH_NSC) Register Mask  */


/* -------- ETH_SCL : (ETH Offset: 0x10E0) (R/W 32) Tsu timer second comparison Register -------- */
#define ETH_SCL_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_SCL) Tsu timer second comparison Register  Reset Value */

#define ETH_SCL_SEC_Pos                       _UINT32_(0)                                          /* (ETH_SCL) 1588 Timer Second comparison value Position */
#define ETH_SCL_SEC_Msk                       (_UINT32_(0xFFFFFFFF) << ETH_SCL_SEC_Pos)            /* (ETH_SCL) 1588 Timer Second comparison value Mask */
#define ETH_SCL_SEC(value)                    (ETH_SCL_SEC_Msk & (_UINT32_(value) << ETH_SCL_SEC_Pos)) /* Assigment of value for SEC in the ETH_SCL register */
#define ETH_SCL_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (ETH_SCL) Register Mask  */


/* -------- ETH_SCH : (ETH Offset: 0x10E4) (R/W 32) Tsu timer second comparison Register -------- */
#define ETH_SCH_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_SCH) Tsu timer second comparison Register  Reset Value */

#define ETH_SCH_SEC_Pos                       _UINT32_(0)                                          /* (ETH_SCH) 1588 Timer Second comparison value Position */
#define ETH_SCH_SEC_Msk                       (_UINT32_(0xFFFF) << ETH_SCH_SEC_Pos)                /* (ETH_SCH) 1588 Timer Second comparison value Mask */
#define ETH_SCH_SEC(value)                    (ETH_SCH_SEC_Msk & (_UINT32_(value) << ETH_SCH_SEC_Pos)) /* Assigment of value for SEC in the ETH_SCH register */
#define ETH_SCH_Msk                           _UINT32_(0x0000FFFF)                                 /* (ETH_SCH) Register Mask  */


/* -------- ETH_EFTSH : (ETH Offset: 0x10E8) ( R/ 32) PTP Event Frame Transmitted Seconds High Register -------- */
#define ETH_EFTSH_RESETVALUE                  _UINT32_(0x00)                                       /*  (ETH_EFTSH) PTP Event Frame Transmitted Seconds High Register  Reset Value */

#define ETH_EFTSH_RUD_Pos                     _UINT32_(0)                                          /* (ETH_EFTSH) Register Update Position */
#define ETH_EFTSH_RUD_Msk                     (_UINT32_(0xFFFF) << ETH_EFTSH_RUD_Pos)              /* (ETH_EFTSH) Register Update Mask */
#define ETH_EFTSH_RUD(value)                  (ETH_EFTSH_RUD_Msk & (_UINT32_(value) << ETH_EFTSH_RUD_Pos)) /* Assigment of value for RUD in the ETH_EFTSH register */
#define ETH_EFTSH_Msk                         _UINT32_(0x0000FFFF)                                 /* (ETH_EFTSH) Register Mask  */


/* -------- ETH_EFRSH : (ETH Offset: 0x10EC) ( R/ 32) PTP Event Frame Received Seconds High Register -------- */
#define ETH_EFRSH_RESETVALUE                  _UINT32_(0x00)                                       /*  (ETH_EFRSH) PTP Event Frame Received Seconds High Register  Reset Value */

#define ETH_EFRSH_RUD_Pos                     _UINT32_(0)                                          /* (ETH_EFRSH) Register Update Position */
#define ETH_EFRSH_RUD_Msk                     (_UINT32_(0xFFFF) << ETH_EFRSH_RUD_Pos)              /* (ETH_EFRSH) Register Update Mask */
#define ETH_EFRSH_RUD(value)                  (ETH_EFRSH_RUD_Msk & (_UINT32_(value) << ETH_EFRSH_RUD_Pos)) /* Assigment of value for RUD in the ETH_EFRSH register */
#define ETH_EFRSH_Msk                         _UINT32_(0x0000FFFF)                                 /* (ETH_EFRSH) Register Mask  */


/* -------- ETH_PEFTSH : (ETH Offset: 0x10F0) ( R/ 32) PTP Peer Event Frame Transmitted Seconds High Register -------- */
#define ETH_PEFTSH_RESETVALUE                 _UINT32_(0x00)                                       /*  (ETH_PEFTSH) PTP Peer Event Frame Transmitted Seconds High Register  Reset Value */

#define ETH_PEFTSH_RUD_Pos                    _UINT32_(0)                                          /* (ETH_PEFTSH) Register Update Position */
#define ETH_PEFTSH_RUD_Msk                    (_UINT32_(0xFFFF) << ETH_PEFTSH_RUD_Pos)             /* (ETH_PEFTSH) Register Update Mask */
#define ETH_PEFTSH_RUD(value)                 (ETH_PEFTSH_RUD_Msk & (_UINT32_(value) << ETH_PEFTSH_RUD_Pos)) /* Assigment of value for RUD in the ETH_PEFTSH register */
#define ETH_PEFTSH_Msk                        _UINT32_(0x0000FFFF)                                 /* (ETH_PEFTSH) Register Mask  */


/* -------- ETH_PEFRSH : (ETH Offset: 0x10F4) ( R/ 32) PTP Peer Event Frame Received Seconds High Register -------- */
#define ETH_PEFRSH_RESETVALUE                 _UINT32_(0x00)                                       /*  (ETH_PEFRSH) PTP Peer Event Frame Received Seconds High Register  Reset Value */

#define ETH_PEFRSH_RUD_Pos                    _UINT32_(0)                                          /* (ETH_PEFRSH) Register Update Position */
#define ETH_PEFRSH_RUD_Msk                    (_UINT32_(0xFFFF) << ETH_PEFRSH_RUD_Pos)             /* (ETH_PEFRSH) Register Update Mask */
#define ETH_PEFRSH_RUD(value)                 (ETH_PEFRSH_RUD_Msk & (_UINT32_(value) << ETH_PEFRSH_RUD_Pos)) /* Assigment of value for RUD in the ETH_PEFRSH register */
#define ETH_PEFRSH_Msk                        _UINT32_(0x0000FFFF)                                 /* (ETH_PEFRSH) Register Mask  */


/* -------- ETH_OTLO : (ETH Offset: 0x1100) ( R/ 32) Octets Transmitted [31:0] Register -------- */
#define ETH_OTLO_RESETVALUE                   _UINT32_(0x00)                                       /*  (ETH_OTLO) Octets Transmitted [31:0] Register  Reset Value */

#define ETH_OTLO_TXO_Pos                      _UINT32_(0)                                          /* (ETH_OTLO) Transmitted Octets Position */
#define ETH_OTLO_TXO_Msk                      (_UINT32_(0xFFFFFFFF) << ETH_OTLO_TXO_Pos)           /* (ETH_OTLO) Transmitted Octets Mask */
#define ETH_OTLO_TXO(value)                   (ETH_OTLO_TXO_Msk & (_UINT32_(value) << ETH_OTLO_TXO_Pos)) /* Assigment of value for TXO in the ETH_OTLO register */
#define ETH_OTLO_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (ETH_OTLO) Register Mask  */


/* -------- ETH_OTHI : (ETH Offset: 0x1104) ( R/ 32) Octets Transmitted [47:32] Register -------- */
#define ETH_OTHI_RESETVALUE                   _UINT32_(0x00)                                       /*  (ETH_OTHI) Octets Transmitted [47:32] Register  Reset Value */

#define ETH_OTHI_TXO_Pos                      _UINT32_(0)                                          /* (ETH_OTHI) Transmitted Octets Position */
#define ETH_OTHI_TXO_Msk                      (_UINT32_(0xFFFF) << ETH_OTHI_TXO_Pos)               /* (ETH_OTHI) Transmitted Octets Mask */
#define ETH_OTHI_TXO(value)                   (ETH_OTHI_TXO_Msk & (_UINT32_(value) << ETH_OTHI_TXO_Pos)) /* Assigment of value for TXO in the ETH_OTHI register */
#define ETH_OTHI_Msk                          _UINT32_(0x0000FFFF)                                 /* (ETH_OTHI) Register Mask  */


/* -------- ETH_FT : (ETH Offset: 0x1108) ( R/ 32) Frames Transmitted Register -------- */
#define ETH_FT_RESETVALUE                     _UINT32_(0x00)                                       /*  (ETH_FT) Frames Transmitted Register  Reset Value */

#define ETH_FT_FTX_Pos                        _UINT32_(0)                                          /* (ETH_FT) Frames Transmitted without Error Position */
#define ETH_FT_FTX_Msk                        (_UINT32_(0xFFFFFFFF) << ETH_FT_FTX_Pos)             /* (ETH_FT) Frames Transmitted without Error Mask */
#define ETH_FT_FTX(value)                     (ETH_FT_FTX_Msk & (_UINT32_(value) << ETH_FT_FTX_Pos)) /* Assigment of value for FTX in the ETH_FT register */
#define ETH_FT_Msk                            _UINT32_(0xFFFFFFFF)                                 /* (ETH_FT) Register Mask  */


/* -------- ETH_BCFT : (ETH Offset: 0x110C) ( R/ 32) Broadcast Frames Transmitted Register -------- */
#define ETH_BCFT_RESETVALUE                   _UINT32_(0x00)                                       /*  (ETH_BCFT) Broadcast Frames Transmitted Register  Reset Value */

#define ETH_BCFT_BFTX_Pos                     _UINT32_(0)                                          /* (ETH_BCFT) Broadcast Frames Transmitted without Error Position */
#define ETH_BCFT_BFTX_Msk                     (_UINT32_(0xFFFFFFFF) << ETH_BCFT_BFTX_Pos)          /* (ETH_BCFT) Broadcast Frames Transmitted without Error Mask */
#define ETH_BCFT_BFTX(value)                  (ETH_BCFT_BFTX_Msk & (_UINT32_(value) << ETH_BCFT_BFTX_Pos)) /* Assigment of value for BFTX in the ETH_BCFT register */
#define ETH_BCFT_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (ETH_BCFT) Register Mask  */


/* -------- ETH_MFT : (ETH Offset: 0x1110) ( R/ 32) Multicast Frames Transmitted Register -------- */
#define ETH_MFT_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_MFT) Multicast Frames Transmitted Register  Reset Value */

#define ETH_MFT_MFTX_Pos                      _UINT32_(0)                                          /* (ETH_MFT) Multicast Frames Transmitted without Error Position */
#define ETH_MFT_MFTX_Msk                      (_UINT32_(0xFFFFFFFF) << ETH_MFT_MFTX_Pos)           /* (ETH_MFT) Multicast Frames Transmitted without Error Mask */
#define ETH_MFT_MFTX(value)                   (ETH_MFT_MFTX_Msk & (_UINT32_(value) << ETH_MFT_MFTX_Pos)) /* Assigment of value for MFTX in the ETH_MFT register */
#define ETH_MFT_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (ETH_MFT) Register Mask  */


/* -------- ETH_PFT : (ETH Offset: 0x1114) ( R/ 32) Pause Frames Transmitted Register -------- */
#define ETH_PFT_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_PFT) Pause Frames Transmitted Register  Reset Value */

#define ETH_PFT_PFTX_Pos                      _UINT32_(0)                                          /* (ETH_PFT) Pause Frames Transmitted Register Position */
#define ETH_PFT_PFTX_Msk                      (_UINT32_(0xFFFF) << ETH_PFT_PFTX_Pos)               /* (ETH_PFT) Pause Frames Transmitted Register Mask */
#define ETH_PFT_PFTX(value)                   (ETH_PFT_PFTX_Msk & (_UINT32_(value) << ETH_PFT_PFTX_Pos)) /* Assigment of value for PFTX in the ETH_PFT register */
#define ETH_PFT_Msk                           _UINT32_(0x0000FFFF)                                 /* (ETH_PFT) Register Mask  */


/* -------- ETH_BFT64 : (ETH Offset: 0x1118) ( R/ 32) 64 Byte Frames Transmitted Register -------- */
#define ETH_BFT64_RESETVALUE                  _UINT32_(0x00)                                       /*  (ETH_BFT64) 64 Byte Frames Transmitted Register  Reset Value */

#define ETH_BFT64_NFTX_Pos                    _UINT32_(0)                                          /* (ETH_BFT64) 64 Byte Frames Transmitted without Error Position */
#define ETH_BFT64_NFTX_Msk                    (_UINT32_(0xFFFFFFFF) << ETH_BFT64_NFTX_Pos)         /* (ETH_BFT64) 64 Byte Frames Transmitted without Error Mask */
#define ETH_BFT64_NFTX(value)                 (ETH_BFT64_NFTX_Msk & (_UINT32_(value) << ETH_BFT64_NFTX_Pos)) /* Assigment of value for NFTX in the ETH_BFT64 register */
#define ETH_BFT64_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (ETH_BFT64) Register Mask  */


/* -------- ETH_TBFT127 : (ETH Offset: 0x111C) ( R/ 32) 65 to 127 Byte Frames Transmitted Register -------- */
#define ETH_TBFT127_RESETVALUE                _UINT32_(0x00)                                       /*  (ETH_TBFT127) 65 to 127 Byte Frames Transmitted Register  Reset Value */

#define ETH_TBFT127_NFTX_Pos                  _UINT32_(0)                                          /* (ETH_TBFT127) 65 to 127 Byte Frames Transmitted without Error Position */
#define ETH_TBFT127_NFTX_Msk                  (_UINT32_(0xFFFFFFFF) << ETH_TBFT127_NFTX_Pos)       /* (ETH_TBFT127) 65 to 127 Byte Frames Transmitted without Error Mask */
#define ETH_TBFT127_NFTX(value)               (ETH_TBFT127_NFTX_Msk & (_UINT32_(value) << ETH_TBFT127_NFTX_Pos)) /* Assigment of value for NFTX in the ETH_TBFT127 register */
#define ETH_TBFT127_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (ETH_TBFT127) Register Mask  */


/* -------- ETH_TBFT255 : (ETH Offset: 0x1120) ( R/ 32) 128 to 255 Byte Frames Transmitted Register -------- */
#define ETH_TBFT255_RESETVALUE                _UINT32_(0x00)                                       /*  (ETH_TBFT255) 128 to 255 Byte Frames Transmitted Register  Reset Value */

#define ETH_TBFT255_NFTX_Pos                  _UINT32_(0)                                          /* (ETH_TBFT255) 128 to 255 Byte Frames Transmitted without Error Position */
#define ETH_TBFT255_NFTX_Msk                  (_UINT32_(0xFFFFFFFF) << ETH_TBFT255_NFTX_Pos)       /* (ETH_TBFT255) 128 to 255 Byte Frames Transmitted without Error Mask */
#define ETH_TBFT255_NFTX(value)               (ETH_TBFT255_NFTX_Msk & (_UINT32_(value) << ETH_TBFT255_NFTX_Pos)) /* Assigment of value for NFTX in the ETH_TBFT255 register */
#define ETH_TBFT255_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (ETH_TBFT255) Register Mask  */


/* -------- ETH_TBFT511 : (ETH Offset: 0x1124) ( R/ 32) 256 to 511 Byte Frames Transmitted Register -------- */
#define ETH_TBFT511_RESETVALUE                _UINT32_(0x00)                                       /*  (ETH_TBFT511) 256 to 511 Byte Frames Transmitted Register  Reset Value */

#define ETH_TBFT511_NFTX_Pos                  _UINT32_(0)                                          /* (ETH_TBFT511) 256 to 511 Byte Frames Transmitted without Error Position */
#define ETH_TBFT511_NFTX_Msk                  (_UINT32_(0xFFFFFFFF) << ETH_TBFT511_NFTX_Pos)       /* (ETH_TBFT511) 256 to 511 Byte Frames Transmitted without Error Mask */
#define ETH_TBFT511_NFTX(value)               (ETH_TBFT511_NFTX_Msk & (_UINT32_(value) << ETH_TBFT511_NFTX_Pos)) /* Assigment of value for NFTX in the ETH_TBFT511 register */
#define ETH_TBFT511_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (ETH_TBFT511) Register Mask  */


/* -------- ETH_TBFT1023 : (ETH Offset: 0x1128) ( R/ 32) 512 to 1023 Byte Frames Transmitted Register -------- */
#define ETH_TBFT1023_RESETVALUE               _UINT32_(0x00)                                       /*  (ETH_TBFT1023) 512 to 1023 Byte Frames Transmitted Register  Reset Value */

#define ETH_TBFT1023_NFTX_Pos                 _UINT32_(0)                                          /* (ETH_TBFT1023) 512 to 1023 Byte Frames Transmitted without Error Position */
#define ETH_TBFT1023_NFTX_Msk                 (_UINT32_(0xFFFFFFFF) << ETH_TBFT1023_NFTX_Pos)      /* (ETH_TBFT1023) 512 to 1023 Byte Frames Transmitted without Error Mask */
#define ETH_TBFT1023_NFTX(value)              (ETH_TBFT1023_NFTX_Msk & (_UINT32_(value) << ETH_TBFT1023_NFTX_Pos)) /* Assigment of value for NFTX in the ETH_TBFT1023 register */
#define ETH_TBFT1023_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (ETH_TBFT1023) Register Mask  */


/* -------- ETH_TBFT1518 : (ETH Offset: 0x112C) ( R/ 32) 1024 to 1518 Byte Frames Transmitted Register -------- */
#define ETH_TBFT1518_RESETVALUE               _UINT32_(0x00)                                       /*  (ETH_TBFT1518) 1024 to 1518 Byte Frames Transmitted Register  Reset Value */

#define ETH_TBFT1518_NFTX_Pos                 _UINT32_(0)                                          /* (ETH_TBFT1518) 1024 to 1518 Byte Frames Transmitted without Error Position */
#define ETH_TBFT1518_NFTX_Msk                 (_UINT32_(0xFFFFFFFF) << ETH_TBFT1518_NFTX_Pos)      /* (ETH_TBFT1518) 1024 to 1518 Byte Frames Transmitted without Error Mask */
#define ETH_TBFT1518_NFTX(value)              (ETH_TBFT1518_NFTX_Msk & (_UINT32_(value) << ETH_TBFT1518_NFTX_Pos)) /* Assigment of value for NFTX in the ETH_TBFT1518 register */
#define ETH_TBFT1518_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (ETH_TBFT1518) Register Mask  */


/* -------- ETH_GTBFT1518 : (ETH Offset: 0x1130) ( R/ 32) Greater Than 1518 Byte Frames Transmitted Register -------- */
#define ETH_GTBFT1518_RESETVALUE              _UINT32_(0x00)                                       /*  (ETH_GTBFT1518) Greater Than 1518 Byte Frames Transmitted Register  Reset Value */

#define ETH_GTBFT1518_NFTX_Pos                _UINT32_(0)                                          /* (ETH_GTBFT1518) Greater than 1518 Byte Frames Transmitted without Error Position */
#define ETH_GTBFT1518_NFTX_Msk                (_UINT32_(0xFFFFFFFF) << ETH_GTBFT1518_NFTX_Pos)     /* (ETH_GTBFT1518) Greater than 1518 Byte Frames Transmitted without Error Mask */
#define ETH_GTBFT1518_NFTX(value)             (ETH_GTBFT1518_NFTX_Msk & (_UINT32_(value) << ETH_GTBFT1518_NFTX_Pos)) /* Assigment of value for NFTX in the ETH_GTBFT1518 register */
#define ETH_GTBFT1518_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (ETH_GTBFT1518) Register Mask  */


/* -------- ETH_TUR : (ETH Offset: 0x1134) ( R/ 32) Transmit Underruns Register -------- */
#define ETH_TUR_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_TUR) Transmit Underruns Register  Reset Value */

#define ETH_TUR_TXUNR_Pos                     _UINT32_(0)                                          /* (ETH_TUR) Transmit Underruns Position */
#define ETH_TUR_TXUNR_Msk                     (_UINT32_(0x3FF) << ETH_TUR_TXUNR_Pos)               /* (ETH_TUR) Transmit Underruns Mask */
#define ETH_TUR_TXUNR(value)                  (ETH_TUR_TXUNR_Msk & (_UINT32_(value) << ETH_TUR_TXUNR_Pos)) /* Assigment of value for TXUNR in the ETH_TUR register */
#define ETH_TUR_Msk                           _UINT32_(0x000003FF)                                 /* (ETH_TUR) Register Mask  */


/* -------- ETH_SCF : (ETH Offset: 0x1138) ( R/ 32) Single Collision Frames Register -------- */
#define ETH_SCF_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_SCF) Single Collision Frames Register  Reset Value */

#define ETH_SCF_SCOL_Pos                      _UINT32_(0)                                          /* (ETH_SCF) Single Collision Position */
#define ETH_SCF_SCOL_Msk                      (_UINT32_(0x3FFFF) << ETH_SCF_SCOL_Pos)              /* (ETH_SCF) Single Collision Mask */
#define ETH_SCF_SCOL(value)                   (ETH_SCF_SCOL_Msk & (_UINT32_(value) << ETH_SCF_SCOL_Pos)) /* Assigment of value for SCOL in the ETH_SCF register */
#define ETH_SCF_Msk                           _UINT32_(0x0003FFFF)                                 /* (ETH_SCF) Register Mask  */


/* -------- ETH_MCF : (ETH Offset: 0x113C) ( R/ 32) Multiple Collision Frames Register -------- */
#define ETH_MCF_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_MCF) Multiple Collision Frames Register  Reset Value */

#define ETH_MCF_MCOL_Pos                      _UINT32_(0)                                          /* (ETH_MCF) Multiple Collision Position */
#define ETH_MCF_MCOL_Msk                      (_UINT32_(0x3FFFF) << ETH_MCF_MCOL_Pos)              /* (ETH_MCF) Multiple Collision Mask */
#define ETH_MCF_MCOL(value)                   (ETH_MCF_MCOL_Msk & (_UINT32_(value) << ETH_MCF_MCOL_Pos)) /* Assigment of value for MCOL in the ETH_MCF register */
#define ETH_MCF_Msk                           _UINT32_(0x0003FFFF)                                 /* (ETH_MCF) Register Mask  */


/* -------- ETH_EC : (ETH Offset: 0x1140) ( R/ 32) Excessive Collisions Register -------- */
#define ETH_EC_RESETVALUE                     _UINT32_(0x00)                                       /*  (ETH_EC) Excessive Collisions Register  Reset Value */

#define ETH_EC_XCOL_Pos                       _UINT32_(0)                                          /* (ETH_EC) Excessive Collisions Position */
#define ETH_EC_XCOL_Msk                       (_UINT32_(0x3FF) << ETH_EC_XCOL_Pos)                 /* (ETH_EC) Excessive Collisions Mask */
#define ETH_EC_XCOL(value)                    (ETH_EC_XCOL_Msk & (_UINT32_(value) << ETH_EC_XCOL_Pos)) /* Assigment of value for XCOL in the ETH_EC register */
#define ETH_EC_Msk                            _UINT32_(0x000003FF)                                 /* (ETH_EC) Register Mask  */


/* -------- ETH_LC : (ETH Offset: 0x1144) ( R/ 32) Late Collisions Register -------- */
#define ETH_LC_RESETVALUE                     _UINT32_(0x00)                                       /*  (ETH_LC) Late Collisions Register  Reset Value */

#define ETH_LC_LCOL_Pos                       _UINT32_(0)                                          /* (ETH_LC) Late Collisions Position */
#define ETH_LC_LCOL_Msk                       (_UINT32_(0x3FF) << ETH_LC_LCOL_Pos)                 /* (ETH_LC) Late Collisions Mask */
#define ETH_LC_LCOL(value)                    (ETH_LC_LCOL_Msk & (_UINT32_(value) << ETH_LC_LCOL_Pos)) /* Assigment of value for LCOL in the ETH_LC register */
#define ETH_LC_Msk                            _UINT32_(0x000003FF)                                 /* (ETH_LC) Register Mask  */


/* -------- ETH_DTF : (ETH Offset: 0x1148) ( R/ 32) Deferred Transmission Frames Register -------- */
#define ETH_DTF_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_DTF) Deferred Transmission Frames Register  Reset Value */

#define ETH_DTF_DEFT_Pos                      _UINT32_(0)                                          /* (ETH_DTF) Deferred Transmission Position */
#define ETH_DTF_DEFT_Msk                      (_UINT32_(0x3FFFF) << ETH_DTF_DEFT_Pos)              /* (ETH_DTF) Deferred Transmission Mask */
#define ETH_DTF_DEFT(value)                   (ETH_DTF_DEFT_Msk & (_UINT32_(value) << ETH_DTF_DEFT_Pos)) /* Assigment of value for DEFT in the ETH_DTF register */
#define ETH_DTF_Msk                           _UINT32_(0x0003FFFF)                                 /* (ETH_DTF) Register Mask  */


/* -------- ETH_CSE : (ETH Offset: 0x114C) ( R/ 32) Carrier Sense Errors Register -------- */
#define ETH_CSE_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_CSE) Carrier Sense Errors Register  Reset Value */

#define ETH_CSE_CSR_Pos                       _UINT32_(0)                                          /* (ETH_CSE) Carrier Sense Error Position */
#define ETH_CSE_CSR_Msk                       (_UINT32_(0x3FF) << ETH_CSE_CSR_Pos)                 /* (ETH_CSE) Carrier Sense Error Mask */
#define ETH_CSE_CSR(value)                    (ETH_CSE_CSR_Msk & (_UINT32_(value) << ETH_CSE_CSR_Pos)) /* Assigment of value for CSR in the ETH_CSE register */
#define ETH_CSE_Msk                           _UINT32_(0x000003FF)                                 /* (ETH_CSE) Register Mask  */


/* -------- ETH_ORLO : (ETH Offset: 0x1150) ( R/ 32) Octets Received [31:0] Received -------- */
#define ETH_ORLO_RESETVALUE                   _UINT32_(0x00)                                       /*  (ETH_ORLO) Octets Received [31:0] Received  Reset Value */

#define ETH_ORLO_RXO_Pos                      _UINT32_(0)                                          /* (ETH_ORLO) Received Octets Position */
#define ETH_ORLO_RXO_Msk                      (_UINT32_(0xFFFFFFFF) << ETH_ORLO_RXO_Pos)           /* (ETH_ORLO) Received Octets Mask */
#define ETH_ORLO_RXO(value)                   (ETH_ORLO_RXO_Msk & (_UINT32_(value) << ETH_ORLO_RXO_Pos)) /* Assigment of value for RXO in the ETH_ORLO register */
#define ETH_ORLO_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (ETH_ORLO) Register Mask  */


/* -------- ETH_ORHI : (ETH Offset: 0x1154) ( R/ 32) Octets Received [47:32] Received -------- */
#define ETH_ORHI_RESETVALUE                   _UINT32_(0x00)                                       /*  (ETH_ORHI) Octets Received [47:32] Received  Reset Value */

#define ETH_ORHI_RXO_Pos                      _UINT32_(0)                                          /* (ETH_ORHI) Received Octets Position */
#define ETH_ORHI_RXO_Msk                      (_UINT32_(0xFFFF) << ETH_ORHI_RXO_Pos)               /* (ETH_ORHI) Received Octets Mask */
#define ETH_ORHI_RXO(value)                   (ETH_ORHI_RXO_Msk & (_UINT32_(value) << ETH_ORHI_RXO_Pos)) /* Assigment of value for RXO in the ETH_ORHI register */
#define ETH_ORHI_Msk                          _UINT32_(0x0000FFFF)                                 /* (ETH_ORHI) Register Mask  */


/* -------- ETH_FR : (ETH Offset: 0x1158) ( R/ 32) Frames Received Register -------- */
#define ETH_FR_RESETVALUE                     _UINT32_(0x00)                                       /*  (ETH_FR) Frames Received Register  Reset Value */

#define ETH_FR_FRX_Pos                        _UINT32_(0)                                          /* (ETH_FR) Frames Received without Error Position */
#define ETH_FR_FRX_Msk                        (_UINT32_(0xFFFFFFFF) << ETH_FR_FRX_Pos)             /* (ETH_FR) Frames Received without Error Mask */
#define ETH_FR_FRX(value)                     (ETH_FR_FRX_Msk & (_UINT32_(value) << ETH_FR_FRX_Pos)) /* Assigment of value for FRX in the ETH_FR register */
#define ETH_FR_Msk                            _UINT32_(0xFFFFFFFF)                                 /* (ETH_FR) Register Mask  */


/* -------- ETH_BCFR : (ETH Offset: 0x115C) ( R/ 32) Broadcast Frames Received Register -------- */
#define ETH_BCFR_RESETVALUE                   _UINT32_(0x00)                                       /*  (ETH_BCFR) Broadcast Frames Received Register  Reset Value */

#define ETH_BCFR_BFRX_Pos                     _UINT32_(0)                                          /* (ETH_BCFR) Broadcast Frames Received without Error Position */
#define ETH_BCFR_BFRX_Msk                     (_UINT32_(0xFFFFFFFF) << ETH_BCFR_BFRX_Pos)          /* (ETH_BCFR) Broadcast Frames Received without Error Mask */
#define ETH_BCFR_BFRX(value)                  (ETH_BCFR_BFRX_Msk & (_UINT32_(value) << ETH_BCFR_BFRX_Pos)) /* Assigment of value for BFRX in the ETH_BCFR register */
#define ETH_BCFR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (ETH_BCFR) Register Mask  */


/* -------- ETH_MFR : (ETH Offset: 0x1160) ( R/ 32) Multicast Frames Received Register -------- */
#define ETH_MFR_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_MFR) Multicast Frames Received Register  Reset Value */

#define ETH_MFR_MFRX_Pos                      _UINT32_(0)                                          /* (ETH_MFR) Multicast Frames Received without Error Position */
#define ETH_MFR_MFRX_Msk                      (_UINT32_(0xFFFFFFFF) << ETH_MFR_MFRX_Pos)           /* (ETH_MFR) Multicast Frames Received without Error Mask */
#define ETH_MFR_MFRX(value)                   (ETH_MFR_MFRX_Msk & (_UINT32_(value) << ETH_MFR_MFRX_Pos)) /* Assigment of value for MFRX in the ETH_MFR register */
#define ETH_MFR_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (ETH_MFR) Register Mask  */


/* -------- ETH_PFR : (ETH Offset: 0x1164) ( R/ 32) Pause Frames Received Register -------- */
#define ETH_PFR_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_PFR) Pause Frames Received Register  Reset Value */

#define ETH_PFR_PFRX_Pos                      _UINT32_(0)                                          /* (ETH_PFR) Pause Frames Received Register Position */
#define ETH_PFR_PFRX_Msk                      (_UINT32_(0xFFFF) << ETH_PFR_PFRX_Pos)               /* (ETH_PFR) Pause Frames Received Register Mask */
#define ETH_PFR_PFRX(value)                   (ETH_PFR_PFRX_Msk & (_UINT32_(value) << ETH_PFR_PFRX_Pos)) /* Assigment of value for PFRX in the ETH_PFR register */
#define ETH_PFR_Msk                           _UINT32_(0x0000FFFF)                                 /* (ETH_PFR) Register Mask  */


/* -------- ETH_BFR64 : (ETH Offset: 0x1168) ( R/ 32) 64 Byte Frames Received Register -------- */
#define ETH_BFR64_RESETVALUE                  _UINT32_(0x00)                                       /*  (ETH_BFR64) 64 Byte Frames Received Register  Reset Value */

#define ETH_BFR64_NFRX_Pos                    _UINT32_(0)                                          /* (ETH_BFR64) 64 Byte Frames Received without Error Position */
#define ETH_BFR64_NFRX_Msk                    (_UINT32_(0xFFFFFFFF) << ETH_BFR64_NFRX_Pos)         /* (ETH_BFR64) 64 Byte Frames Received without Error Mask */
#define ETH_BFR64_NFRX(value)                 (ETH_BFR64_NFRX_Msk & (_UINT32_(value) << ETH_BFR64_NFRX_Pos)) /* Assigment of value for NFRX in the ETH_BFR64 register */
#define ETH_BFR64_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (ETH_BFR64) Register Mask  */


/* -------- ETH_TBFR127 : (ETH Offset: 0x116C) ( R/ 32) 65 to 127 Byte Frames Received Register -------- */
#define ETH_TBFR127_RESETVALUE                _UINT32_(0x00)                                       /*  (ETH_TBFR127) 65 to 127 Byte Frames Received Register  Reset Value */

#define ETH_TBFR127_NFRX_Pos                  _UINT32_(0)                                          /* (ETH_TBFR127) 65 to 127 Byte Frames Received without Error Position */
#define ETH_TBFR127_NFRX_Msk                  (_UINT32_(0xFFFFFFFF) << ETH_TBFR127_NFRX_Pos)       /* (ETH_TBFR127) 65 to 127 Byte Frames Received without Error Mask */
#define ETH_TBFR127_NFRX(value)               (ETH_TBFR127_NFRX_Msk & (_UINT32_(value) << ETH_TBFR127_NFRX_Pos)) /* Assigment of value for NFRX in the ETH_TBFR127 register */
#define ETH_TBFR127_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (ETH_TBFR127) Register Mask  */


/* -------- ETH_TBFR255 : (ETH Offset: 0x1170) ( R/ 32) 128 to 255 Byte Frames Received Register -------- */
#define ETH_TBFR255_RESETVALUE                _UINT32_(0x00)                                       /*  (ETH_TBFR255) 128 to 255 Byte Frames Received Register  Reset Value */

#define ETH_TBFR255_NFRX_Pos                  _UINT32_(0)                                          /* (ETH_TBFR255) 128 to 255 Byte Frames Received without Error Position */
#define ETH_TBFR255_NFRX_Msk                  (_UINT32_(0xFFFFFFFF) << ETH_TBFR255_NFRX_Pos)       /* (ETH_TBFR255) 128 to 255 Byte Frames Received without Error Mask */
#define ETH_TBFR255_NFRX(value)               (ETH_TBFR255_NFRX_Msk & (_UINT32_(value) << ETH_TBFR255_NFRX_Pos)) /* Assigment of value for NFRX in the ETH_TBFR255 register */
#define ETH_TBFR255_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (ETH_TBFR255) Register Mask  */


/* -------- ETH_TBFR511 : (ETH Offset: 0x1174) ( R/ 32) 256 to 511Byte Frames Received Register -------- */
#define ETH_TBFR511_RESETVALUE                _UINT32_(0x00)                                       /*  (ETH_TBFR511) 256 to 511Byte Frames Received Register  Reset Value */

#define ETH_TBFR511_NFRX_Pos                  _UINT32_(0)                                          /* (ETH_TBFR511) 256 to 511 Byte Frames Received without Error Position */
#define ETH_TBFR511_NFRX_Msk                  (_UINT32_(0xFFFFFFFF) << ETH_TBFR511_NFRX_Pos)       /* (ETH_TBFR511) 256 to 511 Byte Frames Received without Error Mask */
#define ETH_TBFR511_NFRX(value)               (ETH_TBFR511_NFRX_Msk & (_UINT32_(value) << ETH_TBFR511_NFRX_Pos)) /* Assigment of value for NFRX in the ETH_TBFR511 register */
#define ETH_TBFR511_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (ETH_TBFR511) Register Mask  */


/* -------- ETH_TBFR1023 : (ETH Offset: 0x1178) ( R/ 32) 512 to 1023 Byte Frames Received Register -------- */
#define ETH_TBFR1023_RESETVALUE               _UINT32_(0x00)                                       /*  (ETH_TBFR1023) 512 to 1023 Byte Frames Received Register  Reset Value */

#define ETH_TBFR1023_NFRX_Pos                 _UINT32_(0)                                          /* (ETH_TBFR1023) 512 to 1023 Byte Frames Received without Error Position */
#define ETH_TBFR1023_NFRX_Msk                 (_UINT32_(0xFFFFFFFF) << ETH_TBFR1023_NFRX_Pos)      /* (ETH_TBFR1023) 512 to 1023 Byte Frames Received without Error Mask */
#define ETH_TBFR1023_NFRX(value)              (ETH_TBFR1023_NFRX_Msk & (_UINT32_(value) << ETH_TBFR1023_NFRX_Pos)) /* Assigment of value for NFRX in the ETH_TBFR1023 register */
#define ETH_TBFR1023_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (ETH_TBFR1023) Register Mask  */


/* -------- ETH_TBFR1518 : (ETH Offset: 0x117C) ( R/ 32) 1024 to 1518 Byte Frames Received Register -------- */
#define ETH_TBFR1518_RESETVALUE               _UINT32_(0x00)                                       /*  (ETH_TBFR1518) 1024 to 1518 Byte Frames Received Register  Reset Value */

#define ETH_TBFR1518_NFRX_Pos                 _UINT32_(0)                                          /* (ETH_TBFR1518) 1024 to 1518 Byte Frames Received without Error Position */
#define ETH_TBFR1518_NFRX_Msk                 (_UINT32_(0xFFFFFFFF) << ETH_TBFR1518_NFRX_Pos)      /* (ETH_TBFR1518) 1024 to 1518 Byte Frames Received without Error Mask */
#define ETH_TBFR1518_NFRX(value)              (ETH_TBFR1518_NFRX_Msk & (_UINT32_(value) << ETH_TBFR1518_NFRX_Pos)) /* Assigment of value for NFRX in the ETH_TBFR1518 register */
#define ETH_TBFR1518_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (ETH_TBFR1518) Register Mask  */


/* -------- ETH_TMXBFR : (ETH Offset: 0x1180) ( R/ 32) 1519 to Maximum Byte Frames Received Register -------- */
#define ETH_TMXBFR_RESETVALUE                 _UINT32_(0x00)                                       /*  (ETH_TMXBFR) 1519 to Maximum Byte Frames Received Register  Reset Value */

#define ETH_TMXBFR_NFRX_Pos                   _UINT32_(0)                                          /* (ETH_TMXBFR) 1519 to Maximum Byte Frames Received without Error Position */
#define ETH_TMXBFR_NFRX_Msk                   (_UINT32_(0xFFFFFFFF) << ETH_TMXBFR_NFRX_Pos)        /* (ETH_TMXBFR) 1519 to Maximum Byte Frames Received without Error Mask */
#define ETH_TMXBFR_NFRX(value)                (ETH_TMXBFR_NFRX_Msk & (_UINT32_(value) << ETH_TMXBFR_NFRX_Pos)) /* Assigment of value for NFRX in the ETH_TMXBFR register */
#define ETH_TMXBFR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (ETH_TMXBFR) Register Mask  */


/* -------- ETH_UFR : (ETH Offset: 0x1184) ( R/ 32) Undersize Frames Received Register -------- */
#define ETH_UFR_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_UFR) Undersize Frames Received Register  Reset Value */

#define ETH_UFR_UFRX_Pos                      _UINT32_(0)                                          /* (ETH_UFR) Undersize Frames Received Position */
#define ETH_UFR_UFRX_Msk                      (_UINT32_(0x3FF) << ETH_UFR_UFRX_Pos)                /* (ETH_UFR) Undersize Frames Received Mask */
#define ETH_UFR_UFRX(value)                   (ETH_UFR_UFRX_Msk & (_UINT32_(value) << ETH_UFR_UFRX_Pos)) /* Assigment of value for UFRX in the ETH_UFR register */
#define ETH_UFR_Msk                           _UINT32_(0x000003FF)                                 /* (ETH_UFR) Register Mask  */


/* -------- ETH_OFR : (ETH Offset: 0x1188) ( R/ 32) Oversize Frames Received Register -------- */
#define ETH_OFR_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_OFR) Oversize Frames Received Register  Reset Value */

#define ETH_OFR_OFRX_Pos                      _UINT32_(0)                                          /* (ETH_OFR) Oversized Frames Received Position */
#define ETH_OFR_OFRX_Msk                      (_UINT32_(0x3FF) << ETH_OFR_OFRX_Pos)                /* (ETH_OFR) Oversized Frames Received Mask */
#define ETH_OFR_OFRX(value)                   (ETH_OFR_OFRX_Msk & (_UINT32_(value) << ETH_OFR_OFRX_Pos)) /* Assigment of value for OFRX in the ETH_OFR register */
#define ETH_OFR_Msk                           _UINT32_(0x000003FF)                                 /* (ETH_OFR) Register Mask  */


/* -------- ETH_JR : (ETH Offset: 0x118C) ( R/ 32) Jabbers Received Register -------- */
#define ETH_JR_RESETVALUE                     _UINT32_(0x00)                                       /*  (ETH_JR) Jabbers Received Register  Reset Value */

#define ETH_JR_JRX_Pos                        _UINT32_(0)                                          /* (ETH_JR) Jabbers Received Position */
#define ETH_JR_JRX_Msk                        (_UINT32_(0x3FF) << ETH_JR_JRX_Pos)                  /* (ETH_JR) Jabbers Received Mask */
#define ETH_JR_JRX(value)                     (ETH_JR_JRX_Msk & (_UINT32_(value) << ETH_JR_JRX_Pos)) /* Assigment of value for JRX in the ETH_JR register */
#define ETH_JR_Msk                            _UINT32_(0x000003FF)                                 /* (ETH_JR) Register Mask  */


/* -------- ETH_FCSE : (ETH Offset: 0x1190) ( R/ 32) Frame Check Sequence Errors Register -------- */
#define ETH_FCSE_RESETVALUE                   _UINT32_(0x00)                                       /*  (ETH_FCSE) Frame Check Sequence Errors Register  Reset Value */

#define ETH_FCSE_FCKR_Pos                     _UINT32_(0)                                          /* (ETH_FCSE) Frame Check Sequence Errors Position */
#define ETH_FCSE_FCKR_Msk                     (_UINT32_(0x3FF) << ETH_FCSE_FCKR_Pos)               /* (ETH_FCSE) Frame Check Sequence Errors Mask */
#define ETH_FCSE_FCKR(value)                  (ETH_FCSE_FCKR_Msk & (_UINT32_(value) << ETH_FCSE_FCKR_Pos)) /* Assigment of value for FCKR in the ETH_FCSE register */
#define ETH_FCSE_Msk                          _UINT32_(0x000003FF)                                 /* (ETH_FCSE) Register Mask  */


/* -------- ETH_LFFE : (ETH Offset: 0x1194) ( R/ 32) Length Field Frame Errors Register -------- */
#define ETH_LFFE_RESETVALUE                   _UINT32_(0x00)                                       /*  (ETH_LFFE) Length Field Frame Errors Register  Reset Value */

#define ETH_LFFE_LFER_Pos                     _UINT32_(0)                                          /* (ETH_LFFE) Length Field Frame Errors Position */
#define ETH_LFFE_LFER_Msk                     (_UINT32_(0x3FF) << ETH_LFFE_LFER_Pos)               /* (ETH_LFFE) Length Field Frame Errors Mask */
#define ETH_LFFE_LFER(value)                  (ETH_LFFE_LFER_Msk & (_UINT32_(value) << ETH_LFFE_LFER_Pos)) /* Assigment of value for LFER in the ETH_LFFE register */
#define ETH_LFFE_Msk                          _UINT32_(0x000003FF)                                 /* (ETH_LFFE) Register Mask  */


/* -------- ETH_RSE : (ETH Offset: 0x1198) ( R/ 32) Receive Symbol Errors Register -------- */
#define ETH_RSE_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_RSE) Receive Symbol Errors Register  Reset Value */

#define ETH_RSE_RXSE_Pos                      _UINT32_(0)                                          /* (ETH_RSE) Receive Symbol Errors Position */
#define ETH_RSE_RXSE_Msk                      (_UINT32_(0x3FF) << ETH_RSE_RXSE_Pos)                /* (ETH_RSE) Receive Symbol Errors Mask */
#define ETH_RSE_RXSE(value)                   (ETH_RSE_RXSE_Msk & (_UINT32_(value) << ETH_RSE_RXSE_Pos)) /* Assigment of value for RXSE in the ETH_RSE register */
#define ETH_RSE_Msk                           _UINT32_(0x000003FF)                                 /* (ETH_RSE) Register Mask  */


/* -------- ETH_AE : (ETH Offset: 0x119C) ( R/ 32) Alignment Errors Register -------- */
#define ETH_AE_RESETVALUE                     _UINT32_(0x00)                                       /*  (ETH_AE) Alignment Errors Register  Reset Value */

#define ETH_AE_AER_Pos                        _UINT32_(0)                                          /* (ETH_AE) Alignment Errors Position */
#define ETH_AE_AER_Msk                        (_UINT32_(0x3FF) << ETH_AE_AER_Pos)                  /* (ETH_AE) Alignment Errors Mask */
#define ETH_AE_AER(value)                     (ETH_AE_AER_Msk & (_UINT32_(value) << ETH_AE_AER_Pos)) /* Assigment of value for AER in the ETH_AE register */
#define ETH_AE_Msk                            _UINT32_(0x000003FF)                                 /* (ETH_AE) Register Mask  */


/* -------- ETH_RRE : (ETH Offset: 0x11A0) ( R/ 32) Receive Resource Errors Register -------- */
#define ETH_RRE_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_RRE) Receive Resource Errors Register  Reset Value */

#define ETH_RRE_RXRER_Pos                     _UINT32_(0)                                          /* (ETH_RRE) Receive Resource Errors Position */
#define ETH_RRE_RXRER_Msk                     (_UINT32_(0x3FFFF) << ETH_RRE_RXRER_Pos)             /* (ETH_RRE) Receive Resource Errors Mask */
#define ETH_RRE_RXRER(value)                  (ETH_RRE_RXRER_Msk & (_UINT32_(value) << ETH_RRE_RXRER_Pos)) /* Assigment of value for RXRER in the ETH_RRE register */
#define ETH_RRE_Msk                           _UINT32_(0x0003FFFF)                                 /* (ETH_RRE) Register Mask  */


/* -------- ETH_ROE : (ETH Offset: 0x11A4) ( R/ 32) Receive Overrun Register -------- */
#define ETH_ROE_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_ROE) Receive Overrun Register  Reset Value */

#define ETH_ROE_RXOVR_Pos                     _UINT32_(0)                                          /* (ETH_ROE) Receive Overruns Position */
#define ETH_ROE_RXOVR_Msk                     (_UINT32_(0x3FF) << ETH_ROE_RXOVR_Pos)               /* (ETH_ROE) Receive Overruns Mask */
#define ETH_ROE_RXOVR(value)                  (ETH_ROE_RXOVR_Msk & (_UINT32_(value) << ETH_ROE_RXOVR_Pos)) /* Assigment of value for RXOVR in the ETH_ROE register */
#define ETH_ROE_Msk                           _UINT32_(0x000003FF)                                 /* (ETH_ROE) Register Mask  */


/* -------- ETH_IHCE : (ETH Offset: 0x11A8) ( R/ 32) IP Header Checksum Errors Register -------- */
#define ETH_IHCE_RESETVALUE                   _UINT32_(0x00)                                       /*  (ETH_IHCE) IP Header Checksum Errors Register  Reset Value */

#define ETH_IHCE_HCKER_Pos                    _UINT32_(0)                                          /* (ETH_IHCE) IP Header Checksum Errors Position */
#define ETH_IHCE_HCKER_Msk                    (_UINT32_(0xFF) << ETH_IHCE_HCKER_Pos)               /* (ETH_IHCE) IP Header Checksum Errors Mask */
#define ETH_IHCE_HCKER(value)                 (ETH_IHCE_HCKER_Msk & (_UINT32_(value) << ETH_IHCE_HCKER_Pos)) /* Assigment of value for HCKER in the ETH_IHCE register */
#define ETH_IHCE_Msk                          _UINT32_(0x000000FF)                                 /* (ETH_IHCE) Register Mask  */


/* -------- ETH_TCE : (ETH Offset: 0x11AC) ( R/ 32) TCP Checksum Errors Register -------- */
#define ETH_TCE_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_TCE) TCP Checksum Errors Register  Reset Value */

#define ETH_TCE_TCKER_Pos                     _UINT32_(0)                                          /* (ETH_TCE) TCP Checksum Errors Position */
#define ETH_TCE_TCKER_Msk                     (_UINT32_(0xFF) << ETH_TCE_TCKER_Pos)                /* (ETH_TCE) TCP Checksum Errors Mask */
#define ETH_TCE_TCKER(value)                  (ETH_TCE_TCKER_Msk & (_UINT32_(value) << ETH_TCE_TCKER_Pos)) /* Assigment of value for TCKER in the ETH_TCE register */
#define ETH_TCE_Msk                           _UINT32_(0x000000FF)                                 /* (ETH_TCE) Register Mask  */


/* -------- ETH_UCE : (ETH Offset: 0x11B0) ( R/ 32) UDP Checksum Errors Register -------- */
#define ETH_UCE_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_UCE) UDP Checksum Errors Register  Reset Value */

#define ETH_UCE_UCKER_Pos                     _UINT32_(0)                                          /* (ETH_UCE) UDP Checksum Errors Position */
#define ETH_UCE_UCKER_Msk                     (_UINT32_(0xFF) << ETH_UCE_UCKER_Pos)                /* (ETH_UCE) UDP Checksum Errors Mask */
#define ETH_UCE_UCKER(value)                  (ETH_UCE_UCKER_Msk & (_UINT32_(value) << ETH_UCE_UCKER_Pos)) /* Assigment of value for UCKER in the ETH_UCE register */
#define ETH_UCE_Msk                           _UINT32_(0x000000FF)                                 /* (ETH_UCE) Register Mask  */


/* -------- ETH_TISUBN : (ETH Offset: 0x11BC) (R/W 32) 1588 Timer Increment [15:0] Sub-Nanoseconds Register -------- */
#define ETH_TISUBN_RESETVALUE                 _UINT32_(0x00)                                       /*  (ETH_TISUBN) 1588 Timer Increment [15:0] Sub-Nanoseconds Register  Reset Value */

#define ETH_TISUBN_LSBTIR_Pos                 _UINT32_(0)                                          /* (ETH_TISUBN) Lower Significant Bits of Timer Increment Position */
#define ETH_TISUBN_LSBTIR_Msk                 (_UINT32_(0xFFFF) << ETH_TISUBN_LSBTIR_Pos)          /* (ETH_TISUBN) Lower Significant Bits of Timer Increment Mask */
#define ETH_TISUBN_LSBTIR(value)              (ETH_TISUBN_LSBTIR_Msk & (_UINT32_(value) << ETH_TISUBN_LSBTIR_Pos)) /* Assigment of value for LSBTIR in the ETH_TISUBN register */
#define ETH_TISUBN_Msk                        _UINT32_(0x0000FFFF)                                 /* (ETH_TISUBN) Register Mask  */


/* -------- ETH_TSH : (ETH Offset: 0x11C0) (R/W 32) 1588 Timer Seconds High [15:0] Register -------- */
#define ETH_TSH_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_TSH) 1588 Timer Seconds High [15:0] Register  Reset Value */

#define ETH_TSH_TCS_Pos                       _UINT32_(0)                                          /* (ETH_TSH) Timer Count in Seconds Position */
#define ETH_TSH_TCS_Msk                       (_UINT32_(0xFFFF) << ETH_TSH_TCS_Pos)                /* (ETH_TSH) Timer Count in Seconds Mask */
#define ETH_TSH_TCS(value)                    (ETH_TSH_TCS_Msk & (_UINT32_(value) << ETH_TSH_TCS_Pos)) /* Assigment of value for TCS in the ETH_TSH register */
#define ETH_TSH_Msk                           _UINT32_(0x0000FFFF)                                 /* (ETH_TSH) Register Mask  */


/* -------- ETH_TSSSL : (ETH Offset: 0x11C8) (R/W 32) 1588 Timer Sync Strobe Seconds [31:0] Register -------- */
#define ETH_TSSSL_RESETVALUE                  _UINT32_(0x00)                                       /*  (ETH_TSSSL) 1588 Timer Sync Strobe Seconds [31:0] Register  Reset Value */

#define ETH_TSSSL_VTS_Pos                     _UINT32_(0)                                          /* (ETH_TSSSL) Value of Timer Seconds Register Capture Position */
#define ETH_TSSSL_VTS_Msk                     (_UINT32_(0xFFFFFFFF) << ETH_TSSSL_VTS_Pos)          /* (ETH_TSSSL) Value of Timer Seconds Register Capture Mask */
#define ETH_TSSSL_VTS(value)                  (ETH_TSSSL_VTS_Msk & (_UINT32_(value) << ETH_TSSSL_VTS_Pos)) /* Assigment of value for VTS in the ETH_TSSSL register */
#define ETH_TSSSL_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (ETH_TSSSL) Register Mask  */


/* -------- ETH_TSSN : (ETH Offset: 0x11CC) (R/W 32) 1588 Timer Sync Strobe Nanoseconds Register -------- */
#define ETH_TSSN_RESETVALUE                   _UINT32_(0x00)                                       /*  (ETH_TSSN) 1588 Timer Sync Strobe Nanoseconds Register  Reset Value */

#define ETH_TSSN_VTN_Pos                      _UINT32_(0)                                          /* (ETH_TSSN) Value Timer Nanoseconds Register Capture Position */
#define ETH_TSSN_VTN_Msk                      (_UINT32_(0x3FFFFFFF) << ETH_TSSN_VTN_Pos)           /* (ETH_TSSN) Value Timer Nanoseconds Register Capture Mask */
#define ETH_TSSN_VTN(value)                   (ETH_TSSN_VTN_Msk & (_UINT32_(value) << ETH_TSSN_VTN_Pos)) /* Assigment of value for VTN in the ETH_TSSN register */
#define ETH_TSSN_Msk                          _UINT32_(0x3FFFFFFF)                                 /* (ETH_TSSN) Register Mask  */


/* -------- ETH_TSL : (ETH Offset: 0x11D0) (R/W 32) 1588 Timer Seconds [31:0] Register -------- */
#define ETH_TSL_RESETVALUE                    _UINT32_(0x00)                                       /*  (ETH_TSL) 1588 Timer Seconds [31:0] Register  Reset Value */

#define ETH_TSL_TCS_Pos                       _UINT32_(0)                                          /* (ETH_TSL) Timer Count in Seconds Position */
#define ETH_TSL_TCS_Msk                       (_UINT32_(0xFFFFFFFF) << ETH_TSL_TCS_Pos)            /* (ETH_TSL) Timer Count in Seconds Mask */
#define ETH_TSL_TCS(value)                    (ETH_TSL_TCS_Msk & (_UINT32_(value) << ETH_TSL_TCS_Pos)) /* Assigment of value for TCS in the ETH_TSL register */
#define ETH_TSL_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (ETH_TSL) Register Mask  */


/* -------- ETH_TN : (ETH Offset: 0x11D4) (R/W 32) 1588 Timer Nanoseconds Register -------- */
#define ETH_TN_RESETVALUE                     _UINT32_(0x00)                                       /*  (ETH_TN) 1588 Timer Nanoseconds Register  Reset Value */

#define ETH_TN_TNS_Pos                        _UINT32_(0)                                          /* (ETH_TN) Timer Count in Nanoseconds Position */
#define ETH_TN_TNS_Msk                        (_UINT32_(0x3FFFFFFF) << ETH_TN_TNS_Pos)             /* (ETH_TN) Timer Count in Nanoseconds Mask */
#define ETH_TN_TNS(value)                     (ETH_TN_TNS_Msk & (_UINT32_(value) << ETH_TN_TNS_Pos)) /* Assigment of value for TNS in the ETH_TN register */
#define ETH_TN_Msk                            _UINT32_(0x3FFFFFFF)                                 /* (ETH_TN) Register Mask  */


/* -------- ETH_TA : (ETH Offset: 0x11D8) ( /W 32) 1588 Timer Adjust Register -------- */
#define ETH_TA_RESETVALUE                     _UINT32_(0x00)                                       /*  (ETH_TA) 1588 Timer Adjust Register  Reset Value */

#define ETH_TA_ITDT_Pos                       _UINT32_(0)                                          /* (ETH_TA) Increment/Decrement Position */
#define ETH_TA_ITDT_Msk                       (_UINT32_(0x3FFFFFFF) << ETH_TA_ITDT_Pos)            /* (ETH_TA) Increment/Decrement Mask */
#define ETH_TA_ITDT(value)                    (ETH_TA_ITDT_Msk & (_UINT32_(value) << ETH_TA_ITDT_Pos)) /* Assigment of value for ITDT in the ETH_TA register */
#define ETH_TA_ADJ_Pos                        _UINT32_(31)                                         /* (ETH_TA) Adjust 1588 Timer Position */
#define ETH_TA_ADJ_Msk                        (_UINT32_(0x1) << ETH_TA_ADJ_Pos)                    /* (ETH_TA) Adjust 1588 Timer Mask */
#define ETH_TA_ADJ(value)                     (ETH_TA_ADJ_Msk & (_UINT32_(value) << ETH_TA_ADJ_Pos)) /* Assigment of value for ADJ in the ETH_TA register */
#define ETH_TA_Msk                            _UINT32_(0xBFFFFFFF)                                 /* (ETH_TA) Register Mask  */


/* -------- ETH_TI : (ETH Offset: 0x11DC) (R/W 32) 1588 Timer Increment Register -------- */
#define ETH_TI_RESETVALUE                     _UINT32_(0x00)                                       /*  (ETH_TI) 1588 Timer Increment Register  Reset Value */

#define ETH_TI_CNS_Pos                        _UINT32_(0)                                          /* (ETH_TI) Count Nanoseconds Position */
#define ETH_TI_CNS_Msk                        (_UINT32_(0xFF) << ETH_TI_CNS_Pos)                   /* (ETH_TI) Count Nanoseconds Mask */
#define ETH_TI_CNS(value)                     (ETH_TI_CNS_Msk & (_UINT32_(value) << ETH_TI_CNS_Pos)) /* Assigment of value for CNS in the ETH_TI register */
#define ETH_TI_ACNS_Pos                       _UINT32_(8)                                          /* (ETH_TI) Alternative Count Nanoseconds Position */
#define ETH_TI_ACNS_Msk                       (_UINT32_(0xFF) << ETH_TI_ACNS_Pos)                  /* (ETH_TI) Alternative Count Nanoseconds Mask */
#define ETH_TI_ACNS(value)                    (ETH_TI_ACNS_Msk & (_UINT32_(value) << ETH_TI_ACNS_Pos)) /* Assigment of value for ACNS in the ETH_TI register */
#define ETH_TI_NIT_Pos                        _UINT32_(16)                                         /* (ETH_TI) Number of Increments Position */
#define ETH_TI_NIT_Msk                        (_UINT32_(0xFF) << ETH_TI_NIT_Pos)                   /* (ETH_TI) Number of Increments Mask */
#define ETH_TI_NIT(value)                     (ETH_TI_NIT_Msk & (_UINT32_(value) << ETH_TI_NIT_Pos)) /* Assigment of value for NIT in the ETH_TI register */
#define ETH_TI_Msk                            _UINT32_(0x00FFFFFF)                                 /* (ETH_TI) Register Mask  */


/* -------- ETH_EFTSL : (ETH Offset: 0x11E0) ( R/ 32) PTP Event Frame Transmitted Seconds Low Register -------- */
#define ETH_EFTSL_RESETVALUE                  _UINT32_(0x00)                                       /*  (ETH_EFTSL) PTP Event Frame Transmitted Seconds Low Register  Reset Value */

#define ETH_EFTSL_RUD_Pos                     _UINT32_(0)                                          /* (ETH_EFTSL) Register Update Position */
#define ETH_EFTSL_RUD_Msk                     (_UINT32_(0xFFFFFFFF) << ETH_EFTSL_RUD_Pos)          /* (ETH_EFTSL) Register Update Mask */
#define ETH_EFTSL_RUD(value)                  (ETH_EFTSL_RUD_Msk & (_UINT32_(value) << ETH_EFTSL_RUD_Pos)) /* Assigment of value for RUD in the ETH_EFTSL register */
#define ETH_EFTSL_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (ETH_EFTSL) Register Mask  */


/* -------- ETH_EFTN : (ETH Offset: 0x11E4) ( R/ 32) PTP Event Frame Transmitted Nanoseconds -------- */
#define ETH_EFTN_RESETVALUE                   _UINT32_(0x00)                                       /*  (ETH_EFTN) PTP Event Frame Transmitted Nanoseconds  Reset Value */

#define ETH_EFTN_RUD_Pos                      _UINT32_(0)                                          /* (ETH_EFTN) Register Update Position */
#define ETH_EFTN_RUD_Msk                      (_UINT32_(0x3FFFFFFF) << ETH_EFTN_RUD_Pos)           /* (ETH_EFTN) Register Update Mask */
#define ETH_EFTN_RUD(value)                   (ETH_EFTN_RUD_Msk & (_UINT32_(value) << ETH_EFTN_RUD_Pos)) /* Assigment of value for RUD in the ETH_EFTN register */
#define ETH_EFTN_Msk                          _UINT32_(0x3FFFFFFF)                                 /* (ETH_EFTN) Register Mask  */


/* -------- ETH_EFRSL : (ETH Offset: 0x11E8) ( R/ 32) PTP Event Frame Received Seconds Low Register -------- */
#define ETH_EFRSL_RESETVALUE                  _UINT32_(0x00)                                       /*  (ETH_EFRSL) PTP Event Frame Received Seconds Low Register  Reset Value */

#define ETH_EFRSL_RUD_Pos                     _UINT32_(0)                                          /* (ETH_EFRSL) Register Update Position */
#define ETH_EFRSL_RUD_Msk                     (_UINT32_(0xFFFFFFFF) << ETH_EFRSL_RUD_Pos)          /* (ETH_EFRSL) Register Update Mask */
#define ETH_EFRSL_RUD(value)                  (ETH_EFRSL_RUD_Msk & (_UINT32_(value) << ETH_EFRSL_RUD_Pos)) /* Assigment of value for RUD in the ETH_EFRSL register */
#define ETH_EFRSL_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (ETH_EFRSL) Register Mask  */


/* -------- ETH_EFRN : (ETH Offset: 0x11EC) ( R/ 32) PTP Event Frame Received Nanoseconds -------- */
#define ETH_EFRN_RESETVALUE                   _UINT32_(0x00)                                       /*  (ETH_EFRN) PTP Event Frame Received Nanoseconds  Reset Value */

#define ETH_EFRN_RUD_Pos                      _UINT32_(0)                                          /* (ETH_EFRN) Register Update Position */
#define ETH_EFRN_RUD_Msk                      (_UINT32_(0x3FFFFFFF) << ETH_EFRN_RUD_Pos)           /* (ETH_EFRN) Register Update Mask */
#define ETH_EFRN_RUD(value)                   (ETH_EFRN_RUD_Msk & (_UINT32_(value) << ETH_EFRN_RUD_Pos)) /* Assigment of value for RUD in the ETH_EFRN register */
#define ETH_EFRN_Msk                          _UINT32_(0x3FFFFFFF)                                 /* (ETH_EFRN) Register Mask  */


/* -------- ETH_PEFTSL : (ETH Offset: 0x11F0) ( R/ 32) PTP Peer Event Frame Transmitted Seconds Low Register -------- */
#define ETH_PEFTSL_RESETVALUE                 _UINT32_(0x00)                                       /*  (ETH_PEFTSL) PTP Peer Event Frame Transmitted Seconds Low Register  Reset Value */

#define ETH_PEFTSL_RUD_Pos                    _UINT32_(0)                                          /* (ETH_PEFTSL) Register Update Position */
#define ETH_PEFTSL_RUD_Msk                    (_UINT32_(0xFFFFFFFF) << ETH_PEFTSL_RUD_Pos)         /* (ETH_PEFTSL) Register Update Mask */
#define ETH_PEFTSL_RUD(value)                 (ETH_PEFTSL_RUD_Msk & (_UINT32_(value) << ETH_PEFTSL_RUD_Pos)) /* Assigment of value for RUD in the ETH_PEFTSL register */
#define ETH_PEFTSL_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (ETH_PEFTSL) Register Mask  */


/* -------- ETH_PEFTN : (ETH Offset: 0x11F4) ( R/ 32) PTP Peer Event Frame Transmitted Nanoseconds -------- */
#define ETH_PEFTN_RESETVALUE                  _UINT32_(0x00)                                       /*  (ETH_PEFTN) PTP Peer Event Frame Transmitted Nanoseconds  Reset Value */

#define ETH_PEFTN_RUD_Pos                     _UINT32_(0)                                          /* (ETH_PEFTN) Register Update Position */
#define ETH_PEFTN_RUD_Msk                     (_UINT32_(0x3FFFFFFF) << ETH_PEFTN_RUD_Pos)          /* (ETH_PEFTN) Register Update Mask */
#define ETH_PEFTN_RUD(value)                  (ETH_PEFTN_RUD_Msk & (_UINT32_(value) << ETH_PEFTN_RUD_Pos)) /* Assigment of value for RUD in the ETH_PEFTN register */
#define ETH_PEFTN_Msk                         _UINT32_(0x3FFFFFFF)                                 /* (ETH_PEFTN) Register Mask  */


/* -------- ETH_PEFRSL : (ETH Offset: 0x11F8) ( R/ 32) PTP Peer Event Frame Received Seconds Low Register -------- */
#define ETH_PEFRSL_RESETVALUE                 _UINT32_(0x00)                                       /*  (ETH_PEFRSL) PTP Peer Event Frame Received Seconds Low Register  Reset Value */

#define ETH_PEFRSL_RUD_Pos                    _UINT32_(0)                                          /* (ETH_PEFRSL) Register Update Position */
#define ETH_PEFRSL_RUD_Msk                    (_UINT32_(0xFFFFFFFF) << ETH_PEFRSL_RUD_Pos)         /* (ETH_PEFRSL) Register Update Mask */
#define ETH_PEFRSL_RUD(value)                 (ETH_PEFRSL_RUD_Msk & (_UINT32_(value) << ETH_PEFRSL_RUD_Pos)) /* Assigment of value for RUD in the ETH_PEFRSL register */
#define ETH_PEFRSL_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (ETH_PEFRSL) Register Mask  */


/* -------- ETH_PEFRN : (ETH Offset: 0x11FC) ( R/ 32) PTP Peer Event Frame Received Nanoseconds -------- */
#define ETH_PEFRN_RESETVALUE                  _UINT32_(0x00)                                       /*  (ETH_PEFRN) PTP Peer Event Frame Received Nanoseconds  Reset Value */

#define ETH_PEFRN_RUD_Pos                     _UINT32_(0)                                          /* (ETH_PEFRN) Register Update Position */
#define ETH_PEFRN_RUD_Msk                     (_UINT32_(0x3FFFFFFF) << ETH_PEFRN_RUD_Pos)          /* (ETH_PEFRN) Register Update Mask */
#define ETH_PEFRN_RUD(value)                  (ETH_PEFRN_RUD_Msk & (_UINT32_(value) << ETH_PEFRN_RUD_Pos)) /* Assigment of value for RUD in the ETH_PEFRN register */
#define ETH_PEFRN_Msk                         _UINT32_(0x3FFFFFFF)                                 /* (ETH_PEFRN) Register Mask  */


/* -------- ETH_RLPITR : (ETH Offset: 0x1270) ( R/ 32) Receive LPI transition Register -------- */
#define ETH_RLPITR_RESETVALUE                 _UINT32_(0x00)                                       /*  (ETH_RLPITR) Receive LPI transition Register  Reset Value */

#define ETH_RLPITR_RLPITR_Pos                 _UINT32_(0)                                          /* (ETH_RLPITR) Count number of times transition from rx normal idle to low power idle Position */
#define ETH_RLPITR_RLPITR_Msk                 (_UINT32_(0xFFFF) << ETH_RLPITR_RLPITR_Pos)          /* (ETH_RLPITR) Count number of times transition from rx normal idle to low power idle Mask */
#define ETH_RLPITR_RLPITR(value)              (ETH_RLPITR_RLPITR_Msk & (_UINT32_(value) << ETH_RLPITR_RLPITR_Pos)) /* Assigment of value for RLPITR in the ETH_RLPITR register */
#define ETH_RLPITR_Msk                        _UINT32_(0x0000FFFF)                                 /* (ETH_RLPITR) Register Mask  */


/* -------- ETH_RLPITI : (ETH Offset: 0x1274) ( R/ 32) Receive LPI Time Register -------- */
#define ETH_RLPITI_RESETVALUE                 _UINT32_(0x00)                                       /*  (ETH_RLPITI) Receive LPI Time Register  Reset Value */

#define ETH_RLPITI_RLPITI_Pos                 _UINT32_(0)                                          /* (ETH_RLPITI) Increment once over 16 ahb clock when LPI indication bit 20 is set in rx mode Position */
#define ETH_RLPITI_RLPITI_Msk                 (_UINT32_(0xFFFFFF) << ETH_RLPITI_RLPITI_Pos)        /* (ETH_RLPITI) Increment once over 16 ahb clock when LPI indication bit 20 is set in rx mode Mask */
#define ETH_RLPITI_RLPITI(value)              (ETH_RLPITI_RLPITI_Msk & (_UINT32_(value) << ETH_RLPITI_RLPITI_Pos)) /* Assigment of value for RLPITI in the ETH_RLPITI register */
#define ETH_RLPITI_Msk                        _UINT32_(0x00FFFFFF)                                 /* (ETH_RLPITI) Register Mask  */


/* -------- ETH_TLPITR : (ETH Offset: 0x1278) ( R/ 32) Receive LPI transition Register -------- */
#define ETH_TLPITR_RESETVALUE                 _UINT32_(0x00)                                       /*  (ETH_TLPITR) Receive LPI transition Register  Reset Value */

#define ETH_TLPITR_TLPITR_Pos                 _UINT32_(0)                                          /* (ETH_TLPITR) Count number of times enable LPI tx bit 20 goes from low to high Position */
#define ETH_TLPITR_TLPITR_Msk                 (_UINT32_(0xFFFF) << ETH_TLPITR_TLPITR_Pos)          /* (ETH_TLPITR) Count number of times enable LPI tx bit 20 goes from low to high Mask */
#define ETH_TLPITR_TLPITR(value)              (ETH_TLPITR_TLPITR_Msk & (_UINT32_(value) << ETH_TLPITR_TLPITR_Pos)) /* Assigment of value for TLPITR in the ETH_TLPITR register */
#define ETH_TLPITR_Msk                        _UINT32_(0x0000FFFF)                                 /* (ETH_TLPITR) Register Mask  */


/* -------- ETH_TLPITI : (ETH Offset: 0x127C) ( R/ 32) Receive LPI Time Register -------- */
#define ETH_TLPITI_RESETVALUE                 _UINT32_(0x00)                                       /*  (ETH_TLPITI) Receive LPI Time Register  Reset Value */

#define ETH_TLPITI_TLPITI_Pos                 _UINT32_(0)                                          /* (ETH_TLPITI) Increment once over 16 ahb clock when LPI indication bit 20 is set in tx mode Position */
#define ETH_TLPITI_TLPITI_Msk                 (_UINT32_(0xFFFFFF) << ETH_TLPITI_TLPITI_Pos)        /* (ETH_TLPITI) Increment once over 16 ahb clock when LPI indication bit 20 is set in tx mode Mask */
#define ETH_TLPITI_TLPITI(value)              (ETH_TLPITI_TLPITI_Msk & (_UINT32_(value) << ETH_TLPITI_TLPITI_Pos)) /* Assigment of value for TLPITI in the ETH_TLPITI register */
#define ETH_TLPITI_Msk                        _UINT32_(0x00FFFFFF)                                 /* (ETH_TLPITI) Register Mask  */


/* -------- ETH_ISRQ : (ETH Offset: 0x1400) (R/W 32) Interrupt Status Register Queues -------- */
#define ETH_ISRQ_RESETVALUE                   _UINT32_(0x00)                                       /*  (ETH_ISRQ) Interrupt Status Register Queues  Reset Value */

#define ETH_ISRQ_RCOMP_Pos                    _UINT32_(1)                                          /* (ETH_ISRQ) Receive Complete Position */
#define ETH_ISRQ_RCOMP_Msk                    (_UINT32_(0x1) << ETH_ISRQ_RCOMP_Pos)                /* (ETH_ISRQ) Receive Complete Mask */
#define ETH_ISRQ_RCOMP(value)                 (ETH_ISRQ_RCOMP_Msk & (_UINT32_(value) << ETH_ISRQ_RCOMP_Pos)) /* Assigment of value for RCOMP in the ETH_ISRQ register */
#define ETH_ISRQ_RXUBR_Pos                    _UINT32_(2)                                          /* (ETH_ISRQ) RX Used Bit Read Position */
#define ETH_ISRQ_RXUBR_Msk                    (_UINT32_(0x1) << ETH_ISRQ_RXUBR_Pos)                /* (ETH_ISRQ) RX Used Bit Read Mask */
#define ETH_ISRQ_RXUBR(value)                 (ETH_ISRQ_RXUBR_Msk & (_UINT32_(value) << ETH_ISRQ_RXUBR_Pos)) /* Assigment of value for RXUBR in the ETH_ISRQ register */
#define ETH_ISRQ_TXUBR_Pos                    _UINT32_(3)                                          /* (ETH_ISRQ) TX Used Bit Read Position */
#define ETH_ISRQ_TXUBR_Msk                    (_UINT32_(0x1) << ETH_ISRQ_TXUBR_Pos)                /* (ETH_ISRQ) TX Used Bit Read Mask */
#define ETH_ISRQ_TXUBR(value)                 (ETH_ISRQ_TXUBR_Msk & (_UINT32_(value) << ETH_ISRQ_TXUBR_Pos)) /* Assigment of value for TXUBR in the ETH_ISRQ register */
#define ETH_ISRQ_TUR_Pos                      _UINT32_(4)                                          /* (ETH_ISRQ) Transmit Underrun Position */
#define ETH_ISRQ_TUR_Msk                      (_UINT32_(0x1) << ETH_ISRQ_TUR_Pos)                  /* (ETH_ISRQ) Transmit Underrun Mask */
#define ETH_ISRQ_TUR(value)                   (ETH_ISRQ_TUR_Msk & (_UINT32_(value) << ETH_ISRQ_TUR_Pos)) /* Assigment of value for TUR in the ETH_ISRQ register */
#define ETH_ISRQ_RLEX_Pos                     _UINT32_(5)                                          /* (ETH_ISRQ) Retry Limit Exceeded Position */
#define ETH_ISRQ_RLEX_Msk                     (_UINT32_(0x1) << ETH_ISRQ_RLEX_Pos)                 /* (ETH_ISRQ) Retry Limit Exceeded Mask */
#define ETH_ISRQ_RLEX(value)                  (ETH_ISRQ_RLEX_Msk & (_UINT32_(value) << ETH_ISRQ_RLEX_Pos)) /* Assigment of value for RLEX in the ETH_ISRQ register */
#define ETH_ISRQ_TFC_Pos                      _UINT32_(6)                                          /* (ETH_ISRQ) Transmit Frame Corruption Due to AHB Error Position */
#define ETH_ISRQ_TFC_Msk                      (_UINT32_(0x1) << ETH_ISRQ_TFC_Pos)                  /* (ETH_ISRQ) Transmit Frame Corruption Due to AHB Error Mask */
#define ETH_ISRQ_TFC(value)                   (ETH_ISRQ_TFC_Msk & (_UINT32_(value) << ETH_ISRQ_TFC_Pos)) /* Assigment of value for TFC in the ETH_ISRQ register */
#define ETH_ISRQ_TCOMP_Pos                    _UINT32_(7)                                          /* (ETH_ISRQ) Transmit Complete Position */
#define ETH_ISRQ_TCOMP_Msk                    (_UINT32_(0x1) << ETH_ISRQ_TCOMP_Pos)                /* (ETH_ISRQ) Transmit Complete Mask */
#define ETH_ISRQ_TCOMP(value)                 (ETH_ISRQ_TCOMP_Msk & (_UINT32_(value) << ETH_ISRQ_TCOMP_Pos)) /* Assigment of value for TCOMP in the ETH_ISRQ register */
#define ETH_ISRQ_ROVR_Pos                     _UINT32_(10)                                         /* (ETH_ISRQ) Receive Overrun Position */
#define ETH_ISRQ_ROVR_Msk                     (_UINT32_(0x1) << ETH_ISRQ_ROVR_Pos)                 /* (ETH_ISRQ) Receive Overrun Mask */
#define ETH_ISRQ_ROVR(value)                  (ETH_ISRQ_ROVR_Msk & (_UINT32_(value) << ETH_ISRQ_ROVR_Pos)) /* Assigment of value for ROVR in the ETH_ISRQ register */
#define ETH_ISRQ_HRESP_Pos                    _UINT32_(11)                                         /* (ETH_ISRQ) HRESP Not OK Position */
#define ETH_ISRQ_HRESP_Msk                    (_UINT32_(0x1) << ETH_ISRQ_HRESP_Pos)                /* (ETH_ISRQ) HRESP Not OK Mask */
#define ETH_ISRQ_HRESP(value)                 (ETH_ISRQ_HRESP_Msk & (_UINT32_(value) << ETH_ISRQ_HRESP_Pos)) /* Assigment of value for HRESP in the ETH_ISRQ register */
#define ETH_ISRQ_Msk                          _UINT32_(0x00000CFE)                                 /* (ETH_ISRQ) Register Mask  */


/* -------- ETH_TBPQB : (ETH Offset: 0x1440) (R/W 32) Transmit Priority Queue Buffer Base Address -------- */
#define ETH_TBPQB_RESETVALUE                  _UINT32_(0x00)                                       /*  (ETH_TBPQB) Transmit Priority Queue Buffer Base Address  Reset Value */

#define ETH_TBPQB_Msk                         _UINT32_(0x00000000)                                 /* (ETH_TBPQB) Register Mask  */


/* -------- ETH_RBPQB : (ETH Offset: 0x1480) (R/W 32) Receive Priority Queue Buffer Base Address -------- */
#define ETH_RBPQB_RESETVALUE                  _UINT32_(0x00)                                       /*  (ETH_RBPQB) Receive Priority Queue Buffer Base Address  Reset Value */

#define ETH_RBPQB_Msk                         _UINT32_(0x00000000)                                 /* (ETH_RBPQB) Register Mask  */


/* -------- ETH_RBQSZ : (ETH Offset: 0x14A0) (R/W 32) Receive Priority Queue Buffer Size -------- */
#define ETH_RBQSZ_RESETVALUE                  _UINT32_(0x02)                                       /*  (ETH_RBQSZ) Receive Priority Queue Buffer Size  Reset Value */

#define ETH_RBQSZ_RXBUFSZ_Pos                 _UINT32_(0)                                          /* (ETH_RBQSZ) DMA Receive Buffer Size Position */
#define ETH_RBQSZ_RXBUFSZ_Msk                 (_UINT32_(0xFF) << ETH_RBQSZ_RXBUFSZ_Pos)            /* (ETH_RBQSZ) DMA Receive Buffer Size Mask */
#define ETH_RBQSZ_RXBUFSZ(value)              (ETH_RBQSZ_RXBUFSZ_Msk & (_UINT32_(value) << ETH_RBQSZ_RXBUFSZ_Pos)) /* Assigment of value for RXBUFSZ in the ETH_RBQSZ register */
#define ETH_RBQSZ_Msk                         _UINT32_(0x000000FF)                                 /* (ETH_RBQSZ) Register Mask  */


/* -------- ETH_SCRT1 : (ETH Offset: 0x1500) (R/W 32) Screening Type 1 Register 0 -------- */
#define ETH_SCRT1_RESETVALUE                  _UINT32_(0x00)                                       /*  (ETH_SCRT1) Screening Type 1 Register 0  Reset Value */

#define ETH_SCRT1_QNMBR_Pos                   _UINT32_(0)                                          /* (ETH_SCRT1) Queue Number Position */
#define ETH_SCRT1_QNMBR_Msk                   (_UINT32_(0xF) << ETH_SCRT1_QNMBR_Pos)               /* (ETH_SCRT1) Queue Number Mask */
#define ETH_SCRT1_QNMBR(value)                (ETH_SCRT1_QNMBR_Msk & (_UINT32_(value) << ETH_SCRT1_QNMBR_Pos)) /* Assigment of value for QNMBR in the ETH_SCRT1 register */
#define ETH_SCRT1_DSTCM_Pos                   _UINT32_(4)                                          /* (ETH_SCRT1) DS/TC Match Position */
#define ETH_SCRT1_DSTCM_Msk                   (_UINT32_(0xFF) << ETH_SCRT1_DSTCM_Pos)              /* (ETH_SCRT1) DS/TC Match Mask */
#define ETH_SCRT1_DSTCM(value)                (ETH_SCRT1_DSTCM_Msk & (_UINT32_(value) << ETH_SCRT1_DSTCM_Pos)) /* Assigment of value for DSTCM in the ETH_SCRT1 register */
#define ETH_SCRT1_UDPP_Pos                    _UINT32_(12)                                         /* (ETH_SCRT1) UDP Port Match Position */
#define ETH_SCRT1_UDPP_Msk                    (_UINT32_(0xFFFF) << ETH_SCRT1_UDPP_Pos)             /* (ETH_SCRT1) UDP Port Match Mask */
#define ETH_SCRT1_UDPP(value)                 (ETH_SCRT1_UDPP_Msk & (_UINT32_(value) << ETH_SCRT1_UDPP_Pos)) /* Assigment of value for UDPP in the ETH_SCRT1 register */
#define ETH_SCRT1_DSTCE_Pos                   _UINT32_(28)                                         /* (ETH_SCRT1) DS/TC Enable Position */
#define ETH_SCRT1_DSTCE_Msk                   (_UINT32_(0x1) << ETH_SCRT1_DSTCE_Pos)               /* (ETH_SCRT1) DS/TC Enable Mask */
#define ETH_SCRT1_DSTCE(value)                (ETH_SCRT1_DSTCE_Msk & (_UINT32_(value) << ETH_SCRT1_DSTCE_Pos)) /* Assigment of value for DSTCE in the ETH_SCRT1 register */
#define ETH_SCRT1_UDPE_Pos                    _UINT32_(29)                                         /* (ETH_SCRT1) UDP Port Match Enable Position */
#define ETH_SCRT1_UDPE_Msk                    (_UINT32_(0x1) << ETH_SCRT1_UDPE_Pos)                /* (ETH_SCRT1) UDP Port Match Enable Mask */
#define ETH_SCRT1_UDPE(value)                 (ETH_SCRT1_UDPE_Msk & (_UINT32_(value) << ETH_SCRT1_UDPE_Pos)) /* Assigment of value for UDPE in the ETH_SCRT1 register */
#define ETH_SCRT1_Msk                         _UINT32_(0x3FFFFFFF)                                 /* (ETH_SCRT1) Register Mask  */


/* -------- ETH_SCRT2 : (ETH Offset: 0x1540) (R/W 32) Screening Type 2 Register -------- */
#define ETH_SCRT2_RESETVALUE                  _UINT32_(0x00)                                       /*  (ETH_SCRT2) Screening Type 2 Register  Reset Value */

#define ETH_SCRT2_QNMBR_Pos                   _UINT32_(0)                                          /* (ETH_SCRT2) Queue Number Position */
#define ETH_SCRT2_QNMBR_Msk                   (_UINT32_(0xF) << ETH_SCRT2_QNMBR_Pos)               /* (ETH_SCRT2) Queue Number Mask */
#define ETH_SCRT2_QNMBR(value)                (ETH_SCRT2_QNMBR_Msk & (_UINT32_(value) << ETH_SCRT2_QNMBR_Pos)) /* Assigment of value for QNMBR in the ETH_SCRT2 register */
#define ETH_SCRT2_VLANPRI_Pos                 _UINT32_(4)                                          /* (ETH_SCRT2) VLAN Priority Position */
#define ETH_SCRT2_VLANPRI_Msk                 (_UINT32_(0x7) << ETH_SCRT2_VLANPRI_Pos)             /* (ETH_SCRT2) VLAN Priority Mask */
#define ETH_SCRT2_VLANPRI(value)              (ETH_SCRT2_VLANPRI_Msk & (_UINT32_(value) << ETH_SCRT2_VLANPRI_Pos)) /* Assigment of value for VLANPRI in the ETH_SCRT2 register */
#define ETH_SCRT2_VLANE_Pos                   _UINT32_(8)                                          /* (ETH_SCRT2) VLAN Enable Position */
#define ETH_SCRT2_VLANE_Msk                   (_UINT32_(0x1) << ETH_SCRT2_VLANE_Pos)               /* (ETH_SCRT2) VLAN Enable Mask */
#define ETH_SCRT2_VLANE(value)                (ETH_SCRT2_VLANE_Msk & (_UINT32_(value) << ETH_SCRT2_VLANE_Pos)) /* Assigment of value for VLANE in the ETH_SCRT2 register */
#define ETH_SCRT2_ETID_Pos                    _UINT32_(9)                                          /* (ETH_SCRT2) EtherType Index Position */
#define ETH_SCRT2_ETID_Msk                    (_UINT32_(0x7) << ETH_SCRT2_ETID_Pos)                /* (ETH_SCRT2) EtherType Index Mask */
#define ETH_SCRT2_ETID(value)                 (ETH_SCRT2_ETID_Msk & (_UINT32_(value) << ETH_SCRT2_ETID_Pos)) /* Assigment of value for ETID in the ETH_SCRT2 register */
#define ETH_SCRT2_ETE_Pos                     _UINT32_(12)                                         /* (ETH_SCRT2) EtherType Enable Position */
#define ETH_SCRT2_ETE_Msk                     (_UINT32_(0x1) << ETH_SCRT2_ETE_Pos)                 /* (ETH_SCRT2) EtherType Enable Mask */
#define ETH_SCRT2_ETE(value)                  (ETH_SCRT2_ETE_Msk & (_UINT32_(value) << ETH_SCRT2_ETE_Pos)) /* Assigment of value for ETE in the ETH_SCRT2 register */
#define ETH_SCRT2_CMPAID_Pos                  _UINT32_(13)                                         /* (ETH_SCRT2) Compare A Index Position */
#define ETH_SCRT2_CMPAID_Msk                  (_UINT32_(0x1F) << ETH_SCRT2_CMPAID_Pos)             /* (ETH_SCRT2) Compare A Index Mask */
#define ETH_SCRT2_CMPAID(value)               (ETH_SCRT2_CMPAID_Msk & (_UINT32_(value) << ETH_SCRT2_CMPAID_Pos)) /* Assigment of value for CMPAID in the ETH_SCRT2 register */
#define ETH_SCRT2_CMPAE_Pos                   _UINT32_(18)                                         /* (ETH_SCRT2) Compare A Enable Position */
#define ETH_SCRT2_CMPAE_Msk                   (_UINT32_(0x1) << ETH_SCRT2_CMPAE_Pos)               /* (ETH_SCRT2) Compare A Enable Mask */
#define ETH_SCRT2_CMPAE(value)                (ETH_SCRT2_CMPAE_Msk & (_UINT32_(value) << ETH_SCRT2_CMPAE_Pos)) /* Assigment of value for CMPAE in the ETH_SCRT2 register */
#define ETH_SCRT2_CMPBID_Pos                  _UINT32_(19)                                         /* (ETH_SCRT2) Compare B Index Position */
#define ETH_SCRT2_CMPBID_Msk                  (_UINT32_(0x1F) << ETH_SCRT2_CMPBID_Pos)             /* (ETH_SCRT2) Compare B Index Mask */
#define ETH_SCRT2_CMPBID(value)               (ETH_SCRT2_CMPBID_Msk & (_UINT32_(value) << ETH_SCRT2_CMPBID_Pos)) /* Assigment of value for CMPBID in the ETH_SCRT2 register */
#define ETH_SCRT2_CMPBE_Pos                   _UINT32_(24)                                         /* (ETH_SCRT2) Compare B Enable Position */
#define ETH_SCRT2_CMPBE_Msk                   (_UINT32_(0x1) << ETH_SCRT2_CMPBE_Pos)               /* (ETH_SCRT2) Compare B Enable Mask */
#define ETH_SCRT2_CMPBE(value)                (ETH_SCRT2_CMPBE_Msk & (_UINT32_(value) << ETH_SCRT2_CMPBE_Pos)) /* Assigment of value for CMPBE in the ETH_SCRT2 register */
#define ETH_SCRT2_CMPCID_Pos                  _UINT32_(25)                                         /* (ETH_SCRT2) Compare C Index Position */
#define ETH_SCRT2_CMPCID_Msk                  (_UINT32_(0x1F) << ETH_SCRT2_CMPCID_Pos)             /* (ETH_SCRT2) Compare C Index Mask */
#define ETH_SCRT2_CMPCID(value)               (ETH_SCRT2_CMPCID_Msk & (_UINT32_(value) << ETH_SCRT2_CMPCID_Pos)) /* Assigment of value for CMPCID in the ETH_SCRT2 register */
#define ETH_SCRT2_CMPCE_Pos                   _UINT32_(30)                                         /* (ETH_SCRT2) Compare C Enable Position */
#define ETH_SCRT2_CMPCE_Msk                   (_UINT32_(0x1) << ETH_SCRT2_CMPCE_Pos)               /* (ETH_SCRT2) Compare C Enable Mask */
#define ETH_SCRT2_CMPCE(value)                (ETH_SCRT2_CMPCE_Msk & (_UINT32_(value) << ETH_SCRT2_CMPCE_Pos)) /* Assigment of value for CMPCE in the ETH_SCRT2 register */
#define ETH_SCRT2_Msk                         _UINT32_(0x7FFFFF7F)                                 /* (ETH_SCRT2) Register Mask  */


/* -------- ETH_IERQ : (ETH Offset: 0x1600) (R/W 32) Interrupt Enable Queue 1 -------- */
#define ETH_IERQ_RESETVALUE                   _UINT32_(0x00)                                       /*  (ETH_IERQ) Interrupt Enable Queue 1  Reset Value */

#define ETH_IERQ_RCOMP_Pos                    _UINT32_(1)                                          /* (ETH_IERQ) Receive Complete Position */
#define ETH_IERQ_RCOMP_Msk                    (_UINT32_(0x1) << ETH_IERQ_RCOMP_Pos)                /* (ETH_IERQ) Receive Complete Mask */
#define ETH_IERQ_RCOMP(value)                 (ETH_IERQ_RCOMP_Msk & (_UINT32_(value) << ETH_IERQ_RCOMP_Pos)) /* Assigment of value for RCOMP in the ETH_IERQ register */
#define ETH_IERQ_RXUBR_Pos                    _UINT32_(2)                                          /* (ETH_IERQ) RX Used Bit Read Position */
#define ETH_IERQ_RXUBR_Msk                    (_UINT32_(0x1) << ETH_IERQ_RXUBR_Pos)                /* (ETH_IERQ) RX Used Bit Read Mask */
#define ETH_IERQ_RXUBR(value)                 (ETH_IERQ_RXUBR_Msk & (_UINT32_(value) << ETH_IERQ_RXUBR_Pos)) /* Assigment of value for RXUBR in the ETH_IERQ register */
#define ETH_IERQ_TXUBR_Pos                    _UINT32_(3)                                          /* (ETH_IERQ) TX Used Bit Read Position */
#define ETH_IERQ_TXUBR_Msk                    (_UINT32_(0x1) << ETH_IERQ_TXUBR_Pos)                /* (ETH_IERQ) TX Used Bit Read Mask */
#define ETH_IERQ_TXUBR(value)                 (ETH_IERQ_TXUBR_Msk & (_UINT32_(value) << ETH_IERQ_TXUBR_Pos)) /* Assigment of value for TXUBR in the ETH_IERQ register */
#define ETH_IERQ_TUR_Pos                      _UINT32_(4)                                          /* (ETH_IERQ) Transmit Underrun Position */
#define ETH_IERQ_TUR_Msk                      (_UINT32_(0x1) << ETH_IERQ_TUR_Pos)                  /* (ETH_IERQ) Transmit Underrun Mask */
#define ETH_IERQ_TUR(value)                   (ETH_IERQ_TUR_Msk & (_UINT32_(value) << ETH_IERQ_TUR_Pos)) /* Assigment of value for TUR in the ETH_IERQ register */
#define ETH_IERQ_RLEX_Pos                     _UINT32_(5)                                          /* (ETH_IERQ) Retry Limit Exceeded Position */
#define ETH_IERQ_RLEX_Msk                     (_UINT32_(0x1) << ETH_IERQ_RLEX_Pos)                 /* (ETH_IERQ) Retry Limit Exceeded Mask */
#define ETH_IERQ_RLEX(value)                  (ETH_IERQ_RLEX_Msk & (_UINT32_(value) << ETH_IERQ_RLEX_Pos)) /* Assigment of value for RLEX in the ETH_IERQ register */
#define ETH_IERQ_TFC_Pos                      _UINT32_(6)                                          /* (ETH_IERQ) Transmit Frame Corruption Due to AHB Error Position */
#define ETH_IERQ_TFC_Msk                      (_UINT32_(0x1) << ETH_IERQ_TFC_Pos)                  /* (ETH_IERQ) Transmit Frame Corruption Due to AHB Error Mask */
#define ETH_IERQ_TFC(value)                   (ETH_IERQ_TFC_Msk & (_UINT32_(value) << ETH_IERQ_TFC_Pos)) /* Assigment of value for TFC in the ETH_IERQ register */
#define ETH_IERQ_TCOMP_Pos                    _UINT32_(7)                                          /* (ETH_IERQ) Transmit Complete Position */
#define ETH_IERQ_TCOMP_Msk                    (_UINT32_(0x1) << ETH_IERQ_TCOMP_Pos)                /* (ETH_IERQ) Transmit Complete Mask */
#define ETH_IERQ_TCOMP(value)                 (ETH_IERQ_TCOMP_Msk & (_UINT32_(value) << ETH_IERQ_TCOMP_Pos)) /* Assigment of value for TCOMP in the ETH_IERQ register */
#define ETH_IERQ_ROVR_Pos                     _UINT32_(10)                                         /* (ETH_IERQ) Receive Overrun Position */
#define ETH_IERQ_ROVR_Msk                     (_UINT32_(0x1) << ETH_IERQ_ROVR_Pos)                 /* (ETH_IERQ) Receive Overrun Mask */
#define ETH_IERQ_ROVR(value)                  (ETH_IERQ_ROVR_Msk & (_UINT32_(value) << ETH_IERQ_ROVR_Pos)) /* Assigment of value for ROVR in the ETH_IERQ register */
#define ETH_IERQ_HRESP_Pos                    _UINT32_(11)                                         /* (ETH_IERQ) HRESP Not OK Position */
#define ETH_IERQ_HRESP_Msk                    (_UINT32_(0x1) << ETH_IERQ_HRESP_Pos)                /* (ETH_IERQ) HRESP Not OK Mask */
#define ETH_IERQ_HRESP(value)                 (ETH_IERQ_HRESP_Msk & (_UINT32_(value) << ETH_IERQ_HRESP_Pos)) /* Assigment of value for HRESP in the ETH_IERQ register */
#define ETH_IERQ_Msk                          _UINT32_(0x00000CFE)                                 /* (ETH_IERQ) Register Mask  */


/* -------- ETH_IDRQ : (ETH Offset: 0x1620) (R/W 32) Interrupt Disable Queue 1 -------- */
#define ETH_IDRQ_RESETVALUE                   _UINT32_(0x00)                                       /*  (ETH_IDRQ) Interrupt Disable Queue 1  Reset Value */

#define ETH_IDRQ_Msk                          _UINT32_(0x00000000)                                 /* (ETH_IDRQ) Register Mask  */


/* -------- ETH_IMRQ : (ETH Offset: 0x1640) (R/W 32) Interrupt Mask Register Queue 1 -------- */
#define ETH_IMRQ_RESETVALUE                   _UINT32_(0x876)                                      /*  (ETH_IMRQ) Interrupt Mask Register Queue 1  Reset Value */

#define ETH_IMRQ_RCOMP_Pos                    _UINT32_(1)                                          /* (ETH_IMRQ) Receive Complete Position */
#define ETH_IMRQ_RCOMP_Msk                    (_UINT32_(0x1) << ETH_IMRQ_RCOMP_Pos)                /* (ETH_IMRQ) Receive Complete Mask */
#define ETH_IMRQ_RCOMP(value)                 (ETH_IMRQ_RCOMP_Msk & (_UINT32_(value) << ETH_IMRQ_RCOMP_Pos)) /* Assigment of value for RCOMP in the ETH_IMRQ register */
#define ETH_IMRQ_RXUBR_Pos                    _UINT32_(2)                                          /* (ETH_IMRQ) RX Used Bit Read Position */
#define ETH_IMRQ_RXUBR_Msk                    (_UINT32_(0x1) << ETH_IMRQ_RXUBR_Pos)                /* (ETH_IMRQ) RX Used Bit Read Mask */
#define ETH_IMRQ_RXUBR(value)                 (ETH_IMRQ_RXUBR_Msk & (_UINT32_(value) << ETH_IMRQ_RXUBR_Pos)) /* Assigment of value for RXUBR in the ETH_IMRQ register */
#define ETH_IMRQ_TXUBR_Pos                    _UINT32_(3)                                          /* (ETH_IMRQ) TX Used Bit Read Position */
#define ETH_IMRQ_TXUBR_Msk                    (_UINT32_(0x1) << ETH_IMRQ_TXUBR_Pos)                /* (ETH_IMRQ) TX Used Bit Read Mask */
#define ETH_IMRQ_TXUBR(value)                 (ETH_IMRQ_TXUBR_Msk & (_UINT32_(value) << ETH_IMRQ_TXUBR_Pos)) /* Assigment of value for TXUBR in the ETH_IMRQ register */
#define ETH_IMRQ_TUR_Pos                      _UINT32_(4)                                          /* (ETH_IMRQ) Transmit Underrun Position */
#define ETH_IMRQ_TUR_Msk                      (_UINT32_(0x1) << ETH_IMRQ_TUR_Pos)                  /* (ETH_IMRQ) Transmit Underrun Mask */
#define ETH_IMRQ_TUR(value)                   (ETH_IMRQ_TUR_Msk & (_UINT32_(value) << ETH_IMRQ_TUR_Pos)) /* Assigment of value for TUR in the ETH_IMRQ register */
#define ETH_IMRQ_RLEX_Pos                     _UINT32_(5)                                          /* (ETH_IMRQ) Retry Limit Exceeded Position */
#define ETH_IMRQ_RLEX_Msk                     (_UINT32_(0x1) << ETH_IMRQ_RLEX_Pos)                 /* (ETH_IMRQ) Retry Limit Exceeded Mask */
#define ETH_IMRQ_RLEX(value)                  (ETH_IMRQ_RLEX_Msk & (_UINT32_(value) << ETH_IMRQ_RLEX_Pos)) /* Assigment of value for RLEX in the ETH_IMRQ register */
#define ETH_IMRQ_TFC_Pos                      _UINT32_(6)                                          /* (ETH_IMRQ) Transmit Frame Corruption Due to AHB Error Position */
#define ETH_IMRQ_TFC_Msk                      (_UINT32_(0x1) << ETH_IMRQ_TFC_Pos)                  /* (ETH_IMRQ) Transmit Frame Corruption Due to AHB Error Mask */
#define ETH_IMRQ_TFC(value)                   (ETH_IMRQ_TFC_Msk & (_UINT32_(value) << ETH_IMRQ_TFC_Pos)) /* Assigment of value for TFC in the ETH_IMRQ register */
#define ETH_IMRQ_TCOMP_Pos                    _UINT32_(7)                                          /* (ETH_IMRQ) Transmit Complete Position */
#define ETH_IMRQ_TCOMP_Msk                    (_UINT32_(0x1) << ETH_IMRQ_TCOMP_Pos)                /* (ETH_IMRQ) Transmit Complete Mask */
#define ETH_IMRQ_TCOMP(value)                 (ETH_IMRQ_TCOMP_Msk & (_UINT32_(value) << ETH_IMRQ_TCOMP_Pos)) /* Assigment of value for TCOMP in the ETH_IMRQ register */
#define ETH_IMRQ_ROVR_Pos                     _UINT32_(10)                                         /* (ETH_IMRQ) Receive Overrun Position */
#define ETH_IMRQ_ROVR_Msk                     (_UINT32_(0x1) << ETH_IMRQ_ROVR_Pos)                 /* (ETH_IMRQ) Receive Overrun Mask */
#define ETH_IMRQ_ROVR(value)                  (ETH_IMRQ_ROVR_Msk & (_UINT32_(value) << ETH_IMRQ_ROVR_Pos)) /* Assigment of value for ROVR in the ETH_IMRQ register */
#define ETH_IMRQ_HRESP_Pos                    _UINT32_(11)                                         /* (ETH_IMRQ) HRESP Not OK Position */
#define ETH_IMRQ_HRESP_Msk                    (_UINT32_(0x1) << ETH_IMRQ_HRESP_Pos)                /* (ETH_IMRQ) HRESP Not OK Mask */
#define ETH_IMRQ_HRESP(value)                 (ETH_IMRQ_HRESP_Msk & (_UINT32_(value) << ETH_IMRQ_HRESP_Pos)) /* Assigment of value for HRESP in the ETH_IMRQ register */
#define ETH_IMRQ_Msk                          _UINT32_(0x00000CFE)                                 /* (ETH_IMRQ) Register Mask  */


/* -------- ETH_SCRT2ET : (ETH Offset: 0x16E0) (R/W 32) Screening Type 2 EtherType Register 0 -------- */
#define ETH_SCRT2ET_RESETVALUE                _UINT32_(0x00)                                       /*  (ETH_SCRT2ET) Screening Type 2 EtherType Register 0  Reset Value */

#define ETH_SCRT2ET_CMPVAL_Pos                _UINT32_(0)                                          /* (ETH_SCRT2ET) Ethertype compare value Position */
#define ETH_SCRT2ET_CMPVAL_Msk                (_UINT32_(0xFFFF) << ETH_SCRT2ET_CMPVAL_Pos)         /* (ETH_SCRT2ET) Ethertype compare value Mask */
#define ETH_SCRT2ET_CMPVAL(value)             (ETH_SCRT2ET_CMPVAL_Msk & (_UINT32_(value) << ETH_SCRT2ET_CMPVAL_Pos)) /* Assigment of value for CMPVAL in the ETH_SCRT2ET register */
#define ETH_SCRT2ET_Msk                       _UINT32_(0x0000FFFF)                                 /* (ETH_SCRT2ET) Register Mask  */


/** \brief ETH register offsets definitions */
#define ETH_SAB_REG_OFST               _UINT32_(0x00)      /* (ETH_SAB) Specific Address Bottom [31:0] Register Offset */
#define ETH_SAT_REG_OFST               _UINT32_(0x04)      /* (ETH_SAT) Specific Address Top [47:32] Register Offset */
#define ETH_SCRT2CMP0_REG_OFST         _UINT32_(0x00)      /* (ETH_SCRT2CMP0) Screening Type 2 Compare Registers Word 0 Offset */
#define ETH_SCRT2CMP1_REG_OFST         _UINT32_(0x04)      /* (ETH_SCRT2CMP1) Screening Type 2 Compare Registers Word 1 Offset */
#define ETH_CTRLA_REG_OFST             _UINT32_(0x00)      /* (ETH_CTRLA) CTRLA Register Offset */
#define ETH_CTRLB_REG_OFST             _UINT32_(0x04)      /* (ETH_CTRLB) CTRLB Register Offset */
#define ETH_EVCTRL_REG_OFST            _UINT32_(0x0C)      /* (ETH_EVCTRL) Event Control Register Offset */
#define ETH_SYNCB_REG_OFST             _UINT32_(0x20)      /* (ETH_SYNCB) Sync Busy Register Offset */
#define ETH_NCR_REG_OFST               _UINT32_(0x1000)    /* (ETH_NCR) Network Control Register Offset */
#define ETH_NCFGR_REG_OFST             _UINT32_(0x1004)    /* (ETH_NCFGR) Network Configuration Register Offset */
#define ETH_NSR_REG_OFST               _UINT32_(0x1008)    /* (ETH_NSR) Network Status Register Offset */
#define ETH_UR_REG_OFST                _UINT32_(0x100C)    /* (ETH_UR) User Register Offset */
#define ETH_DCFGR_REG_OFST             _UINT32_(0x1010)    /* (ETH_DCFGR) DMA Configuration Register Offset */
#define ETH_TSR_REG_OFST               _UINT32_(0x1014)    /* (ETH_TSR) Transmit Status Register Offset */
#define ETH_RBQB_REG_OFST              _UINT32_(0x1018)    /* (ETH_RBQB) Receive Buffer Queue Base Address Offset */
#define ETH_TBQB_REG_OFST              _UINT32_(0x101C)    /* (ETH_TBQB) Transmit Buffer Queue Base Address Offset */
#define ETH_RSR_REG_OFST               _UINT32_(0x1020)    /* (ETH_RSR) Receive Status Register Offset */
#define ETH_ISR_REG_OFST               _UINT32_(0x1024)    /* (ETH_ISR) Interrupt Status Register Offset */
#define ETH_IER_REG_OFST               _UINT32_(0x1028)    /* (ETH_IER) Interrupt Enable Register Offset */
#define ETH_IDR_REG_OFST               _UINT32_(0x102C)    /* (ETH_IDR) Interrupt Disable Register Offset */
#define ETH_IMR_REG_OFST               _UINT32_(0x1030)    /* (ETH_IMR) Interrupt Mask Register Offset */
#define ETH_MAN_REG_OFST               _UINT32_(0x1034)    /* (ETH_MAN) PHY Maintenance Register Offset */
#define ETH_RPQ_REG_OFST               _UINT32_(0x1038)    /* (ETH_RPQ) Received Pause Quantum Register Offset */
#define ETH_TPQ_REG_OFST               _UINT32_(0x103C)    /* (ETH_TPQ) Transmit Pause Quantum Register Offset */
#define ETH_TPSF_REG_OFST              _UINT32_(0x1040)    /* (ETH_TPSF) TX partial store and forward Register Offset */
#define ETH_RPSF_REG_OFST              _UINT32_(0x1044)    /* (ETH_RPSF) RX partial store and forward Register Offset */
#define ETH_RJFML_REG_OFST             _UINT32_(0x1048)    /* (ETH_RJFML) RX Jumbo Frame Max Length Register Offset */
#define ETH_HRB_REG_OFST               _UINT32_(0x1080)    /* (ETH_HRB) Hash Register Bottom [31:0] Offset */
#define ETH_HRT_REG_OFST               _UINT32_(0x1084)    /* (ETH_HRT) Hash Register Top [63:32] Offset */
#define ETH_TIDM_REG_OFST              _UINT32_(0x10A8)    /* (ETH_TIDM) Type ID Match Register Offset */
#define ETH_TIDM0_REG_OFST             _UINT32_(0x10A8)    /* (ETH_TIDM0) Type ID Match Register Offset */
#define ETH_TIDM1_REG_OFST             _UINT32_(0x10AC)    /* (ETH_TIDM1) Type ID Match Register Offset */
#define ETH_TIDM2_REG_OFST             _UINT32_(0x10B0)    /* (ETH_TIDM2) Type ID Match Register Offset */
#define ETH_TIDM3_REG_OFST             _UINT32_(0x10B4)    /* (ETH_TIDM3) Type ID Match Register Offset */
#define ETH_WOL_REG_OFST               _UINT32_(0x10B8)    /* (ETH_WOL) Wake on LAN Offset */
#define ETH_IPGS_REG_OFST              _UINT32_(0x10BC)    /* (ETH_IPGS) IPG Stretch Register Offset */
#define ETH_SVLAN_REG_OFST             _UINT32_(0x10C0)    /* (ETH_SVLAN) Stacked VLAN Register Offset */
#define ETH_TPFCP_REG_OFST             _UINT32_(0x10C4)    /* (ETH_TPFCP) Transmit PFC Pause Register Offset */
#define ETH_SAMB1_REG_OFST             _UINT32_(0x10C8)    /* (ETH_SAMB1) Specific Address 1 Mask Bottom [31:0] Register Offset */
#define ETH_SAMT1_REG_OFST             _UINT32_(0x10CC)    /* (ETH_SAMT1) Specific Address 1 Mask Top [47:32] Register Offset */
#define ETH_NSC_REG_OFST               _UINT32_(0x10DC)    /* (ETH_NSC) Tsu timer comparison nanoseconds Register Offset */
#define ETH_SCL_REG_OFST               _UINT32_(0x10E0)    /* (ETH_SCL) Tsu timer second comparison Register Offset */
#define ETH_SCH_REG_OFST               _UINT32_(0x10E4)    /* (ETH_SCH) Tsu timer second comparison Register Offset */
#define ETH_EFTSH_REG_OFST             _UINT32_(0x10E8)    /* (ETH_EFTSH) PTP Event Frame Transmitted Seconds High Register Offset */
#define ETH_EFRSH_REG_OFST             _UINT32_(0x10EC)    /* (ETH_EFRSH) PTP Event Frame Received Seconds High Register Offset */
#define ETH_PEFTSH_REG_OFST            _UINT32_(0x10F0)    /* (ETH_PEFTSH) PTP Peer Event Frame Transmitted Seconds High Register Offset */
#define ETH_PEFRSH_REG_OFST            _UINT32_(0x10F4)    /* (ETH_PEFRSH) PTP Peer Event Frame Received Seconds High Register Offset */
#define ETH_OTLO_REG_OFST              _UINT32_(0x1100)    /* (ETH_OTLO) Octets Transmitted [31:0] Register Offset */
#define ETH_OTHI_REG_OFST              _UINT32_(0x1104)    /* (ETH_OTHI) Octets Transmitted [47:32] Register Offset */
#define ETH_FT_REG_OFST                _UINT32_(0x1108)    /* (ETH_FT) Frames Transmitted Register Offset */
#define ETH_BCFT_REG_OFST              _UINT32_(0x110C)    /* (ETH_BCFT) Broadcast Frames Transmitted Register Offset */
#define ETH_MFT_REG_OFST               _UINT32_(0x1110)    /* (ETH_MFT) Multicast Frames Transmitted Register Offset */
#define ETH_PFT_REG_OFST               _UINT32_(0x1114)    /* (ETH_PFT) Pause Frames Transmitted Register Offset */
#define ETH_BFT64_REG_OFST             _UINT32_(0x1118)    /* (ETH_BFT64) 64 Byte Frames Transmitted Register Offset */
#define ETH_TBFT127_REG_OFST           _UINT32_(0x111C)    /* (ETH_TBFT127) 65 to 127 Byte Frames Transmitted Register Offset */
#define ETH_TBFT255_REG_OFST           _UINT32_(0x1120)    /* (ETH_TBFT255) 128 to 255 Byte Frames Transmitted Register Offset */
#define ETH_TBFT511_REG_OFST           _UINT32_(0x1124)    /* (ETH_TBFT511) 256 to 511 Byte Frames Transmitted Register Offset */
#define ETH_TBFT1023_REG_OFST          _UINT32_(0x1128)    /* (ETH_TBFT1023) 512 to 1023 Byte Frames Transmitted Register Offset */
#define ETH_TBFT1518_REG_OFST          _UINT32_(0x112C)    /* (ETH_TBFT1518) 1024 to 1518 Byte Frames Transmitted Register Offset */
#define ETH_GTBFT1518_REG_OFST         _UINT32_(0x1130)    /* (ETH_GTBFT1518) Greater Than 1518 Byte Frames Transmitted Register Offset */
#define ETH_TUR_REG_OFST               _UINT32_(0x1134)    /* (ETH_TUR) Transmit Underruns Register Offset */
#define ETH_SCF_REG_OFST               _UINT32_(0x1138)    /* (ETH_SCF) Single Collision Frames Register Offset */
#define ETH_MCF_REG_OFST               _UINT32_(0x113C)    /* (ETH_MCF) Multiple Collision Frames Register Offset */
#define ETH_EC_REG_OFST                _UINT32_(0x1140)    /* (ETH_EC) Excessive Collisions Register Offset */
#define ETH_LC_REG_OFST                _UINT32_(0x1144)    /* (ETH_LC) Late Collisions Register Offset */
#define ETH_DTF_REG_OFST               _UINT32_(0x1148)    /* (ETH_DTF) Deferred Transmission Frames Register Offset */
#define ETH_CSE_REG_OFST               _UINT32_(0x114C)    /* (ETH_CSE) Carrier Sense Errors Register Offset */
#define ETH_ORLO_REG_OFST              _UINT32_(0x1150)    /* (ETH_ORLO) Octets Received [31:0] Received Offset */
#define ETH_ORHI_REG_OFST              _UINT32_(0x1154)    /* (ETH_ORHI) Octets Received [47:32] Received Offset */
#define ETH_FR_REG_OFST                _UINT32_(0x1158)    /* (ETH_FR) Frames Received Register Offset */
#define ETH_BCFR_REG_OFST              _UINT32_(0x115C)    /* (ETH_BCFR) Broadcast Frames Received Register Offset */
#define ETH_MFR_REG_OFST               _UINT32_(0x1160)    /* (ETH_MFR) Multicast Frames Received Register Offset */
#define ETH_PFR_REG_OFST               _UINT32_(0x1164)    /* (ETH_PFR) Pause Frames Received Register Offset */
#define ETH_BFR64_REG_OFST             _UINT32_(0x1168)    /* (ETH_BFR64) 64 Byte Frames Received Register Offset */
#define ETH_TBFR127_REG_OFST           _UINT32_(0x116C)    /* (ETH_TBFR127) 65 to 127 Byte Frames Received Register Offset */
#define ETH_TBFR255_REG_OFST           _UINT32_(0x1170)    /* (ETH_TBFR255) 128 to 255 Byte Frames Received Register Offset */
#define ETH_TBFR511_REG_OFST           _UINT32_(0x1174)    /* (ETH_TBFR511) 256 to 511Byte Frames Received Register Offset */
#define ETH_TBFR1023_REG_OFST          _UINT32_(0x1178)    /* (ETH_TBFR1023) 512 to 1023 Byte Frames Received Register Offset */
#define ETH_TBFR1518_REG_OFST          _UINT32_(0x117C)    /* (ETH_TBFR1518) 1024 to 1518 Byte Frames Received Register Offset */
#define ETH_TMXBFR_REG_OFST            _UINT32_(0x1180)    /* (ETH_TMXBFR) 1519 to Maximum Byte Frames Received Register Offset */
#define ETH_UFR_REG_OFST               _UINT32_(0x1184)    /* (ETH_UFR) Undersize Frames Received Register Offset */
#define ETH_OFR_REG_OFST               _UINT32_(0x1188)    /* (ETH_OFR) Oversize Frames Received Register Offset */
#define ETH_JR_REG_OFST                _UINT32_(0x118C)    /* (ETH_JR) Jabbers Received Register Offset */
#define ETH_FCSE_REG_OFST              _UINT32_(0x1190)    /* (ETH_FCSE) Frame Check Sequence Errors Register Offset */
#define ETH_LFFE_REG_OFST              _UINT32_(0x1194)    /* (ETH_LFFE) Length Field Frame Errors Register Offset */
#define ETH_RSE_REG_OFST               _UINT32_(0x1198)    /* (ETH_RSE) Receive Symbol Errors Register Offset */
#define ETH_AE_REG_OFST                _UINT32_(0x119C)    /* (ETH_AE) Alignment Errors Register Offset */
#define ETH_RRE_REG_OFST               _UINT32_(0x11A0)    /* (ETH_RRE) Receive Resource Errors Register Offset */
#define ETH_ROE_REG_OFST               _UINT32_(0x11A4)    /* (ETH_ROE) Receive Overrun Register Offset */
#define ETH_IHCE_REG_OFST              _UINT32_(0x11A8)    /* (ETH_IHCE) IP Header Checksum Errors Register Offset */
#define ETH_TCE_REG_OFST               _UINT32_(0x11AC)    /* (ETH_TCE) TCP Checksum Errors Register Offset */
#define ETH_UCE_REG_OFST               _UINT32_(0x11B0)    /* (ETH_UCE) UDP Checksum Errors Register Offset */
#define ETH_TISUBN_REG_OFST            _UINT32_(0x11BC)    /* (ETH_TISUBN) 1588 Timer Increment [15:0] Sub-Nanoseconds Register Offset */
#define ETH_TSH_REG_OFST               _UINT32_(0x11C0)    /* (ETH_TSH) 1588 Timer Seconds High [15:0] Register Offset */
#define ETH_TSSSL_REG_OFST             _UINT32_(0x11C8)    /* (ETH_TSSSL) 1588 Timer Sync Strobe Seconds [31:0] Register Offset */
#define ETH_TSSN_REG_OFST              _UINT32_(0x11CC)    /* (ETH_TSSN) 1588 Timer Sync Strobe Nanoseconds Register Offset */
#define ETH_TSL_REG_OFST               _UINT32_(0x11D0)    /* (ETH_TSL) 1588 Timer Seconds [31:0] Register Offset */
#define ETH_TN_REG_OFST                _UINT32_(0x11D4)    /* (ETH_TN) 1588 Timer Nanoseconds Register Offset */
#define ETH_TA_REG_OFST                _UINT32_(0x11D8)    /* (ETH_TA) 1588 Timer Adjust Register Offset */
#define ETH_TI_REG_OFST                _UINT32_(0x11DC)    /* (ETH_TI) 1588 Timer Increment Register Offset */
#define ETH_EFTSL_REG_OFST             _UINT32_(0x11E0)    /* (ETH_EFTSL) PTP Event Frame Transmitted Seconds Low Register Offset */
#define ETH_EFTN_REG_OFST              _UINT32_(0x11E4)    /* (ETH_EFTN) PTP Event Frame Transmitted Nanoseconds Offset */
#define ETH_EFRSL_REG_OFST             _UINT32_(0x11E8)    /* (ETH_EFRSL) PTP Event Frame Received Seconds Low Register Offset */
#define ETH_EFRN_REG_OFST              _UINT32_(0x11EC)    /* (ETH_EFRN) PTP Event Frame Received Nanoseconds Offset */
#define ETH_PEFTSL_REG_OFST            _UINT32_(0x11F0)    /* (ETH_PEFTSL) PTP Peer Event Frame Transmitted Seconds Low Register Offset */
#define ETH_PEFTN_REG_OFST             _UINT32_(0x11F4)    /* (ETH_PEFTN) PTP Peer Event Frame Transmitted Nanoseconds Offset */
#define ETH_PEFRSL_REG_OFST            _UINT32_(0x11F8)    /* (ETH_PEFRSL) PTP Peer Event Frame Received Seconds Low Register Offset */
#define ETH_PEFRN_REG_OFST             _UINT32_(0x11FC)    /* (ETH_PEFRN) PTP Peer Event Frame Received Nanoseconds Offset */
#define ETH_RLPITR_REG_OFST            _UINT32_(0x1270)    /* (ETH_RLPITR) Receive LPI transition Register Offset */
#define ETH_RLPITI_REG_OFST            _UINT32_(0x1274)    /* (ETH_RLPITI) Receive LPI Time Register Offset */
#define ETH_TLPITR_REG_OFST            _UINT32_(0x1278)    /* (ETH_TLPITR) Receive LPI transition Register Offset */
#define ETH_TLPITI_REG_OFST            _UINT32_(0x127C)    /* (ETH_TLPITI) Receive LPI Time Register Offset */
#define ETH_ISRQ_REG_OFST              _UINT32_(0x1400)    /* (ETH_ISRQ) Interrupt Status Register Queues Offset */
#define ETH_ISRQ0_REG_OFST             _UINT32_(0x1400)    /* (ETH_ISRQ0) Interrupt Status Register Queues Offset */
#define ETH_ISRQ1_REG_OFST             _UINT32_(0x1404)    /* (ETH_ISRQ1) Interrupt Status Register Queues Offset */
#define ETH_ISRQ2_REG_OFST             _UINT32_(0x1408)    /* (ETH_ISRQ2) Interrupt Status Register Queues Offset */
#define ETH_ISRQ3_REG_OFST             _UINT32_(0x140C)    /* (ETH_ISRQ3) Interrupt Status Register Queues Offset */
#define ETH_ISRQ4_REG_OFST             _UINT32_(0x1410)    /* (ETH_ISRQ4) Interrupt Status Register Queues Offset */
#define ETH_TBPQB_REG_OFST             _UINT32_(0x1440)    /* (ETH_TBPQB) Transmit Priority Queue Buffer Base Address Offset */
#define ETH_TBPQB0_REG_OFST            _UINT32_(0x1440)    /* (ETH_TBPQB0) Transmit Priority Queue Buffer Base Address Offset */
#define ETH_TBPQB1_REG_OFST            _UINT32_(0x1444)    /* (ETH_TBPQB1) Transmit Priority Queue Buffer Base Address Offset */
#define ETH_TBPQB2_REG_OFST            _UINT32_(0x1448)    /* (ETH_TBPQB2) Transmit Priority Queue Buffer Base Address Offset */
#define ETH_TBPQB3_REG_OFST            _UINT32_(0x144C)    /* (ETH_TBPQB3) Transmit Priority Queue Buffer Base Address Offset */
#define ETH_TBPQB4_REG_OFST            _UINT32_(0x1450)    /* (ETH_TBPQB4) Transmit Priority Queue Buffer Base Address Offset */
#define ETH_RBPQB_REG_OFST             _UINT32_(0x1480)    /* (ETH_RBPQB) Receive Priority Queue Buffer Base Address Offset */
#define ETH_RBPQB0_REG_OFST            _UINT32_(0x1480)    /* (ETH_RBPQB0) Receive Priority Queue Buffer Base Address Offset */
#define ETH_RBPQB1_REG_OFST            _UINT32_(0x1484)    /* (ETH_RBPQB1) Receive Priority Queue Buffer Base Address Offset */
#define ETH_RBPQB2_REG_OFST            _UINT32_(0x1488)    /* (ETH_RBPQB2) Receive Priority Queue Buffer Base Address Offset */
#define ETH_RBPQB3_REG_OFST            _UINT32_(0x148C)    /* (ETH_RBPQB3) Receive Priority Queue Buffer Base Address Offset */
#define ETH_RBPQB4_REG_OFST            _UINT32_(0x1490)    /* (ETH_RBPQB4) Receive Priority Queue Buffer Base Address Offset */
#define ETH_RBQSZ_REG_OFST             _UINT32_(0x14A0)    /* (ETH_RBQSZ) Receive Priority Queue Buffer Size Offset */
#define ETH_RBQSZ0_REG_OFST            _UINT32_(0x14A0)    /* (ETH_RBQSZ0) Receive Priority Queue Buffer Size Offset */
#define ETH_RBQSZ1_REG_OFST            _UINT32_(0x14A4)    /* (ETH_RBQSZ1) Receive Priority Queue Buffer Size Offset */
#define ETH_RBQSZ2_REG_OFST            _UINT32_(0x14A8)    /* (ETH_RBQSZ2) Receive Priority Queue Buffer Size Offset */
#define ETH_RBQSZ3_REG_OFST            _UINT32_(0x14AC)    /* (ETH_RBQSZ3) Receive Priority Queue Buffer Size Offset */
#define ETH_RBQSZ4_REG_OFST            _UINT32_(0x14B0)    /* (ETH_RBQSZ4) Receive Priority Queue Buffer Size Offset */
#define ETH_SCRT1_REG_OFST             _UINT32_(0x1500)    /* (ETH_SCRT1) Screening Type 1 Register 0 Offset */
#define ETH_SCRT1_0_REG_OFST           _UINT32_(0x1500)    /* (ETH_SCRT1_0) Screening Type 1 Register 0 Offset */
#define ETH_SCRT1_1_REG_OFST           _UINT32_(0x1504)    /* (ETH_SCRT1_1) Screening Type 1 Register 0 Offset */
#define ETH_SCRT1_2_REG_OFST           _UINT32_(0x1508)    /* (ETH_SCRT1_2) Screening Type 1 Register 0 Offset */
#define ETH_SCRT1_3_REG_OFST           _UINT32_(0x150C)    /* (ETH_SCRT1_3) Screening Type 1 Register 0 Offset */
#define ETH_SCRT2_REG_OFST             _UINT32_(0x1540)    /* (ETH_SCRT2) Screening Type 2 Register Offset */
#define ETH_SCRT2_0_REG_OFST           _UINT32_(0x1540)    /* (ETH_SCRT2_0) Screening Type 2 Register Offset */
#define ETH_SCRT2_1_REG_OFST           _UINT32_(0x1544)    /* (ETH_SCRT2_1) Screening Type 2 Register Offset */
#define ETH_SCRT2_2_REG_OFST           _UINT32_(0x1548)    /* (ETH_SCRT2_2) Screening Type 2 Register Offset */
#define ETH_SCRT2_3_REG_OFST           _UINT32_(0x154C)    /* (ETH_SCRT2_3) Screening Type 2 Register Offset */
#define ETH_SCRT2_4_REG_OFST           _UINT32_(0x1550)    /* (ETH_SCRT2_4) Screening Type 2 Register Offset */
#define ETH_SCRT2_5_REG_OFST           _UINT32_(0x1554)    /* (ETH_SCRT2_5) Screening Type 2 Register Offset */
#define ETH_SCRT2_6_REG_OFST           _UINT32_(0x1558)    /* (ETH_SCRT2_6) Screening Type 2 Register Offset */
#define ETH_SCRT2_7_REG_OFST           _UINT32_(0x155C)    /* (ETH_SCRT2_7) Screening Type 2 Register Offset */
#define ETH_IERQ_REG_OFST              _UINT32_(0x1600)    /* (ETH_IERQ) Interrupt Enable Queue 1 Offset */
#define ETH_IERQ0_REG_OFST             _UINT32_(0x1600)    /* (ETH_IERQ0) Interrupt Enable Queue 1 Offset */
#define ETH_IERQ1_REG_OFST             _UINT32_(0x1604)    /* (ETH_IERQ1) Interrupt Enable Queue 1 Offset */
#define ETH_IERQ2_REG_OFST             _UINT32_(0x1608)    /* (ETH_IERQ2) Interrupt Enable Queue 1 Offset */
#define ETH_IERQ3_REG_OFST             _UINT32_(0x160C)    /* (ETH_IERQ3) Interrupt Enable Queue 1 Offset */
#define ETH_IERQ4_REG_OFST             _UINT32_(0x1610)    /* (ETH_IERQ4) Interrupt Enable Queue 1 Offset */
#define ETH_IDRQ_REG_OFST              _UINT32_(0x1620)    /* (ETH_IDRQ) Interrupt Disable Queue 1 Offset */
#define ETH_IDRQ0_REG_OFST             _UINT32_(0x1620)    /* (ETH_IDRQ0) Interrupt Disable Queue 1 Offset */
#define ETH_IDRQ1_REG_OFST             _UINT32_(0x1624)    /* (ETH_IDRQ1) Interrupt Disable Queue 1 Offset */
#define ETH_IDRQ2_REG_OFST             _UINT32_(0x1628)    /* (ETH_IDRQ2) Interrupt Disable Queue 1 Offset */
#define ETH_IDRQ3_REG_OFST             _UINT32_(0x162C)    /* (ETH_IDRQ3) Interrupt Disable Queue 1 Offset */
#define ETH_IDRQ4_REG_OFST             _UINT32_(0x1630)    /* (ETH_IDRQ4) Interrupt Disable Queue 1 Offset */
#define ETH_IMRQ_REG_OFST              _UINT32_(0x1640)    /* (ETH_IMRQ) Interrupt Mask Register Queue 1 Offset */
#define ETH_IMRQ0_REG_OFST             _UINT32_(0x1640)    /* (ETH_IMRQ0) Interrupt Mask Register Queue 1 Offset */
#define ETH_IMRQ1_REG_OFST             _UINT32_(0x1644)    /* (ETH_IMRQ1) Interrupt Mask Register Queue 1 Offset */
#define ETH_IMRQ2_REG_OFST             _UINT32_(0x1648)    /* (ETH_IMRQ2) Interrupt Mask Register Queue 1 Offset */
#define ETH_IMRQ3_REG_OFST             _UINT32_(0x164C)    /* (ETH_IMRQ3) Interrupt Mask Register Queue 1 Offset */
#define ETH_IMRQ4_REG_OFST             _UINT32_(0x1650)    /* (ETH_IMRQ4) Interrupt Mask Register Queue 1 Offset */
#define ETH_SCRT2ET_REG_OFST           _UINT32_(0x16E0)    /* (ETH_SCRT2ET) Screening Type 2 EtherType Register 0 Offset */
#define ETH_SCRT2ET0_REG_OFST          _UINT32_(0x16E0)    /* (ETH_SCRT2ET0) Screening Type 2 EtherType Register 0 Offset */
#define ETH_SCRT2ET1_REG_OFST          _UINT32_(0x16E4)    /* (ETH_SCRT2ET1) Screening Type 2 EtherType Register 0 Offset */
#define ETH_SCRT2ET2_REG_OFST          _UINT32_(0x16E8)    /* (ETH_SCRT2ET2) Screening Type 2 EtherType Register 0 Offset */
#define ETH_SCRT2ET3_REG_OFST          _UINT32_(0x16EC)    /* (ETH_SCRT2ET3) Screening Type 2 EtherType Register 0 Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief SA register API structure */
typedef struct
{
  __IO  uint32_t                       ETH_SAB;            /**< Offset: 0x00 (R/W  32) Specific Address Bottom [31:0] Register */
  __IO  uint32_t                       ETH_SAT;            /**< Offset: 0x04 (R/W  32) Specific Address Top [47:32] Register */
} eth_sa_registers_t;

/** \brief SCRT2CMP register API structure */
typedef struct
{
  __IO  uint32_t                       ETH_SCRT2CMP0;      /**< Offset: 0x00 (R/W  32) Screening Type 2 Compare Registers Word 0 */
  __IO  uint32_t                       ETH_SCRT2CMP1;      /**< Offset: 0x04 (R/W  32) Screening Type 2 Compare Registers Word 1 */
} eth_scrt2cmp_registers_t;

#define ETH_SA_NUMBER 4

#define ETH_SCRT2CMP_NUMBER 24

/** \brief ETH register API structure */
typedef struct
{  /* Ethernet Controller */
  __IO  uint32_t                       ETH_CTRLA;          /**< Offset: 0x00 (R/W  32) CTRLA Register */
  __IO  uint32_t                       ETH_CTRLB;          /**< Offset: 0x04 (R/W  32) CTRLB Register */
  __I   uint8_t                        Reserved1[0x04];
  __IO  uint32_t                       ETH_EVCTRL;         /**< Offset: 0x0C (R/W  32) Event Control Register */
  __I   uint8_t                        Reserved2[0x10];
  __I   uint32_t                       ETH_SYNCB;          /**< Offset: 0x20 (R/   32) Sync Busy Register */
  __I   uint8_t                        Reserved3[0xFDC];
  __IO  uint32_t                       ETH_NCR;            /**< Offset: 0x1000 (R/W  32) Network Control Register */
  __IO  uint32_t                       ETH_NCFGR;          /**< Offset: 0x1004 (R/W  32) Network Configuration Register */
  __I   uint32_t                       ETH_NSR;            /**< Offset: 0x1008 (R/   32) Network Status Register */
  __IO  uint32_t                       ETH_UR;             /**< Offset: 0x100C (R/W  32) User Register */
  __IO  uint32_t                       ETH_DCFGR;          /**< Offset: 0x1010 (R/W  32) DMA Configuration Register */
  __IO  uint32_t                       ETH_TSR;            /**< Offset: 0x1014 (R/W  32) Transmit Status Register */
  __IO  uint32_t                       ETH_RBQB;           /**< Offset: 0x1018 (R/W  32) Receive Buffer Queue Base Address */
  __IO  uint32_t                       ETH_TBQB;           /**< Offset: 0x101C (R/W  32) Transmit Buffer Queue Base Address */
  __IO  uint32_t                       ETH_RSR;            /**< Offset: 0x1020 (R/W  32) Receive Status Register */
  __IO  uint32_t                       ETH_ISR;            /**< Offset: 0x1024 (R/W  32) Interrupt Status Register */
  __O   uint32_t                       ETH_IER;            /**< Offset: 0x1028 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       ETH_IDR;            /**< Offset: 0x102C ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       ETH_IMR;            /**< Offset: 0x1030 (R/   32) Interrupt Mask Register */
  __IO  uint32_t                       ETH_MAN;            /**< Offset: 0x1034 (R/W  32) PHY Maintenance Register */
  __I   uint32_t                       ETH_RPQ;            /**< Offset: 0x1038 (R/   32) Received Pause Quantum Register */
  __IO  uint32_t                       ETH_TPQ;            /**< Offset: 0x103C (R/W  32) Transmit Pause Quantum Register */
  __IO  uint32_t                       ETH_TPSF;           /**< Offset: 0x1040 (R/W  32) TX partial store and forward Register */
  __IO  uint32_t                       ETH_RPSF;           /**< Offset: 0x1044 (R/W  32) RX partial store and forward Register */
  __IO  uint32_t                       ETH_RJFML;          /**< Offset: 0x1048 (R/W  32) RX Jumbo Frame Max Length Register */
  __I   uint8_t                        Reserved4[0x34];
  __IO  uint32_t                       ETH_HRB;            /**< Offset: 0x1080 (R/W  32) Hash Register Bottom [31:0] */
  __IO  uint32_t                       ETH_HRT;            /**< Offset: 0x1084 (R/W  32) Hash Register Top [63:32] */
        eth_sa_registers_t             SA[ETH_SA_NUMBER]; /**< Offset: 0x1088  */
  __IO  uint32_t                       ETH_TIDM[4];        /**< Offset: 0x10A8 (R/W  32) Type ID Match Register */
  __IO  uint32_t                       ETH_WOL;            /**< Offset: 0x10B8 (R/W  32) Wake on LAN */
  __IO  uint32_t                       ETH_IPGS;           /**< Offset: 0x10BC (R/W  32) IPG Stretch Register */
  __IO  uint32_t                       ETH_SVLAN;          /**< Offset: 0x10C0 (R/W  32) Stacked VLAN Register */
  __IO  uint32_t                       ETH_TPFCP;          /**< Offset: 0x10C4 (R/W  32) Transmit PFC Pause Register */
  __IO  uint32_t                       ETH_SAMB1;          /**< Offset: 0x10C8 (R/W  32) Specific Address 1 Mask Bottom [31:0] Register */
  __IO  uint32_t                       ETH_SAMT1;          /**< Offset: 0x10CC (R/W  32) Specific Address 1 Mask Top [47:32] Register */
  __I   uint8_t                        Reserved5[0x0C];
  __IO  uint32_t                       ETH_NSC;            /**< Offset: 0x10DC (R/W  32) Tsu timer comparison nanoseconds Register */
  __IO  uint32_t                       ETH_SCL;            /**< Offset: 0x10E0 (R/W  32) Tsu timer second comparison Register */
  __IO  uint32_t                       ETH_SCH;            /**< Offset: 0x10E4 (R/W  32) Tsu timer second comparison Register */
  __I   uint32_t                       ETH_EFTSH;          /**< Offset: 0x10E8 (R/   32) PTP Event Frame Transmitted Seconds High Register */
  __I   uint32_t                       ETH_EFRSH;          /**< Offset: 0x10EC (R/   32) PTP Event Frame Received Seconds High Register */
  __I   uint32_t                       ETH_PEFTSH;         /**< Offset: 0x10F0 (R/   32) PTP Peer Event Frame Transmitted Seconds High Register */
  __I   uint32_t                       ETH_PEFRSH;         /**< Offset: 0x10F4 (R/   32) PTP Peer Event Frame Received Seconds High Register */
  __I   uint8_t                        Reserved6[0x08];
  __I   uint32_t                       ETH_OTLO;           /**< Offset: 0x1100 (R/   32) Octets Transmitted [31:0] Register */
  __I   uint32_t                       ETH_OTHI;           /**< Offset: 0x1104 (R/   32) Octets Transmitted [47:32] Register */
  __I   uint32_t                       ETH_FT;             /**< Offset: 0x1108 (R/   32) Frames Transmitted Register */
  __I   uint32_t                       ETH_BCFT;           /**< Offset: 0x110C (R/   32) Broadcast Frames Transmitted Register */
  __I   uint32_t                       ETH_MFT;            /**< Offset: 0x1110 (R/   32) Multicast Frames Transmitted Register */
  __I   uint32_t                       ETH_PFT;            /**< Offset: 0x1114 (R/   32) Pause Frames Transmitted Register */
  __I   uint32_t                       ETH_BFT64;          /**< Offset: 0x1118 (R/   32) 64 Byte Frames Transmitted Register */
  __I   uint32_t                       ETH_TBFT127;        /**< Offset: 0x111C (R/   32) 65 to 127 Byte Frames Transmitted Register */
  __I   uint32_t                       ETH_TBFT255;        /**< Offset: 0x1120 (R/   32) 128 to 255 Byte Frames Transmitted Register */
  __I   uint32_t                       ETH_TBFT511;        /**< Offset: 0x1124 (R/   32) 256 to 511 Byte Frames Transmitted Register */
  __I   uint32_t                       ETH_TBFT1023;       /**< Offset: 0x1128 (R/   32) 512 to 1023 Byte Frames Transmitted Register */
  __I   uint32_t                       ETH_TBFT1518;       /**< Offset: 0x112C (R/   32) 1024 to 1518 Byte Frames Transmitted Register */
  __I   uint32_t                       ETH_GTBFT1518;      /**< Offset: 0x1130 (R/   32) Greater Than 1518 Byte Frames Transmitted Register */
  __I   uint32_t                       ETH_TUR;            /**< Offset: 0x1134 (R/   32) Transmit Underruns Register */
  __I   uint32_t                       ETH_SCF;            /**< Offset: 0x1138 (R/   32) Single Collision Frames Register */
  __I   uint32_t                       ETH_MCF;            /**< Offset: 0x113C (R/   32) Multiple Collision Frames Register */
  __I   uint32_t                       ETH_EC;             /**< Offset: 0x1140 (R/   32) Excessive Collisions Register */
  __I   uint32_t                       ETH_LC;             /**< Offset: 0x1144 (R/   32) Late Collisions Register */
  __I   uint32_t                       ETH_DTF;            /**< Offset: 0x1148 (R/   32) Deferred Transmission Frames Register */
  __I   uint32_t                       ETH_CSE;            /**< Offset: 0x114C (R/   32) Carrier Sense Errors Register */
  __I   uint32_t                       ETH_ORLO;           /**< Offset: 0x1150 (R/   32) Octets Received [31:0] Received */
  __I   uint32_t                       ETH_ORHI;           /**< Offset: 0x1154 (R/   32) Octets Received [47:32] Received */
  __I   uint32_t                       ETH_FR;             /**< Offset: 0x1158 (R/   32) Frames Received Register */
  __I   uint32_t                       ETH_BCFR;           /**< Offset: 0x115C (R/   32) Broadcast Frames Received Register */
  __I   uint32_t                       ETH_MFR;            /**< Offset: 0x1160 (R/   32) Multicast Frames Received Register */
  __I   uint32_t                       ETH_PFR;            /**< Offset: 0x1164 (R/   32) Pause Frames Received Register */
  __I   uint32_t                       ETH_BFR64;          /**< Offset: 0x1168 (R/   32) 64 Byte Frames Received Register */
  __I   uint32_t                       ETH_TBFR127;        /**< Offset: 0x116C (R/   32) 65 to 127 Byte Frames Received Register */
  __I   uint32_t                       ETH_TBFR255;        /**< Offset: 0x1170 (R/   32) 128 to 255 Byte Frames Received Register */
  __I   uint32_t                       ETH_TBFR511;        /**< Offset: 0x1174 (R/   32) 256 to 511Byte Frames Received Register */
  __I   uint32_t                       ETH_TBFR1023;       /**< Offset: 0x1178 (R/   32) 512 to 1023 Byte Frames Received Register */
  __I   uint32_t                       ETH_TBFR1518;       /**< Offset: 0x117C (R/   32) 1024 to 1518 Byte Frames Received Register */
  __I   uint32_t                       ETH_TMXBFR;         /**< Offset: 0x1180 (R/   32) 1519 to Maximum Byte Frames Received Register */
  __I   uint32_t                       ETH_UFR;            /**< Offset: 0x1184 (R/   32) Undersize Frames Received Register */
  __I   uint32_t                       ETH_OFR;            /**< Offset: 0x1188 (R/   32) Oversize Frames Received Register */
  __I   uint32_t                       ETH_JR;             /**< Offset: 0x118C (R/   32) Jabbers Received Register */
  __I   uint32_t                       ETH_FCSE;           /**< Offset: 0x1190 (R/   32) Frame Check Sequence Errors Register */
  __I   uint32_t                       ETH_LFFE;           /**< Offset: 0x1194 (R/   32) Length Field Frame Errors Register */
  __I   uint32_t                       ETH_RSE;            /**< Offset: 0x1198 (R/   32) Receive Symbol Errors Register */
  __I   uint32_t                       ETH_AE;             /**< Offset: 0x119C (R/   32) Alignment Errors Register */
  __I   uint32_t                       ETH_RRE;            /**< Offset: 0x11A0 (R/   32) Receive Resource Errors Register */
  __I   uint32_t                       ETH_ROE;            /**< Offset: 0x11A4 (R/   32) Receive Overrun Register */
  __I   uint32_t                       ETH_IHCE;           /**< Offset: 0x11A8 (R/   32) IP Header Checksum Errors Register */
  __I   uint32_t                       ETH_TCE;            /**< Offset: 0x11AC (R/   32) TCP Checksum Errors Register */
  __I   uint32_t                       ETH_UCE;            /**< Offset: 0x11B0 (R/   32) UDP Checksum Errors Register */
  __I   uint8_t                        Reserved7[0x08];
  __IO  uint32_t                       ETH_TISUBN;         /**< Offset: 0x11BC (R/W  32) 1588 Timer Increment [15:0] Sub-Nanoseconds Register */
  __IO  uint32_t                       ETH_TSH;            /**< Offset: 0x11C0 (R/W  32) 1588 Timer Seconds High [15:0] Register */
  __I   uint8_t                        Reserved8[0x04];
  __IO  uint32_t                       ETH_TSSSL;          /**< Offset: 0x11C8 (R/W  32) 1588 Timer Sync Strobe Seconds [31:0] Register */
  __IO  uint32_t                       ETH_TSSN;           /**< Offset: 0x11CC (R/W  32) 1588 Timer Sync Strobe Nanoseconds Register */
  __IO  uint32_t                       ETH_TSL;            /**< Offset: 0x11D0 (R/W  32) 1588 Timer Seconds [31:0] Register */
  __IO  uint32_t                       ETH_TN;             /**< Offset: 0x11D4 (R/W  32) 1588 Timer Nanoseconds Register */
  __O   uint32_t                       ETH_TA;             /**< Offset: 0x11D8 ( /W  32) 1588 Timer Adjust Register */
  __IO  uint32_t                       ETH_TI;             /**< Offset: 0x11DC (R/W  32) 1588 Timer Increment Register */
  __I   uint32_t                       ETH_EFTSL;          /**< Offset: 0x11E0 (R/   32) PTP Event Frame Transmitted Seconds Low Register */
  __I   uint32_t                       ETH_EFTN;           /**< Offset: 0x11E4 (R/   32) PTP Event Frame Transmitted Nanoseconds */
  __I   uint32_t                       ETH_EFRSL;          /**< Offset: 0x11E8 (R/   32) PTP Event Frame Received Seconds Low Register */
  __I   uint32_t                       ETH_EFRN;           /**< Offset: 0x11EC (R/   32) PTP Event Frame Received Nanoseconds */
  __I   uint32_t                       ETH_PEFTSL;         /**< Offset: 0x11F0 (R/   32) PTP Peer Event Frame Transmitted Seconds Low Register */
  __I   uint32_t                       ETH_PEFTN;          /**< Offset: 0x11F4 (R/   32) PTP Peer Event Frame Transmitted Nanoseconds */
  __I   uint32_t                       ETH_PEFRSL;         /**< Offset: 0x11F8 (R/   32) PTP Peer Event Frame Received Seconds Low Register */
  __I   uint32_t                       ETH_PEFRN;          /**< Offset: 0x11FC (R/   32) PTP Peer Event Frame Received Nanoseconds */
  __I   uint8_t                        Reserved9[0x70];
  __I   uint32_t                       ETH_RLPITR;         /**< Offset: 0x1270 (R/   32) Receive LPI transition Register */
  __I   uint32_t                       ETH_RLPITI;         /**< Offset: 0x1274 (R/   32) Receive LPI Time Register */
  __I   uint32_t                       ETH_TLPITR;         /**< Offset: 0x1278 (R/   32) Receive LPI transition Register */
  __I   uint32_t                       ETH_TLPITI;         /**< Offset: 0x127C (R/   32) Receive LPI Time Register */
  __I   uint8_t                        Reserved10[0x180];
  __IO  uint32_t                       ETH_ISRQ[5];        /**< Offset: 0x1400 (R/W  32) Interrupt Status Register Queues */
  __I   uint8_t                        Reserved11[0x2C];
  __IO  uint32_t                       ETH_TBPQB[5];       /**< Offset: 0x1440 (R/W  32) Transmit Priority Queue Buffer Base Address */
  __I   uint8_t                        Reserved12[0x2C];
  __IO  uint32_t                       ETH_RBPQB[5];       /**< Offset: 0x1480 (R/W  32) Receive Priority Queue Buffer Base Address */
  __I   uint8_t                        Reserved13[0x0C];
  __IO  uint32_t                       ETH_RBQSZ[5];       /**< Offset: 0x14A0 (R/W  32) Receive Priority Queue Buffer Size */
  __I   uint8_t                        Reserved14[0x4C];
  __IO  uint32_t                       ETH_SCRT1[4];       /**< Offset: 0x1500 (R/W  32) Screening Type 1 Register 0 */
  __I   uint8_t                        Reserved15[0x30];
  __IO  uint32_t                       ETH_SCRT2[8];       /**< Offset: 0x1540 (R/W  32) Screening Type 2 Register */
  __I   uint8_t                        Reserved16[0xA0];
  __IO  uint32_t                       ETH_IERQ[5];        /**< Offset: 0x1600 (R/W  32) Interrupt Enable Queue 1 */
  __I   uint8_t                        Reserved17[0x0C];
  __IO  uint32_t                       ETH_IDRQ[5];        /**< Offset: 0x1620 (R/W  32) Interrupt Disable Queue 1 */
  __I   uint8_t                        Reserved18[0x0C];
  __IO  uint32_t                       ETH_IMRQ[5];        /**< Offset: 0x1640 (R/W  32) Interrupt Mask Register Queue 1 */
  __I   uint8_t                        Reserved19[0x8C];
  __IO  uint32_t                       ETH_SCRT2ET[4];     /**< Offset: 0x16E0 (R/W  32) Screening Type 2 EtherType Register 0 */
  __I   uint8_t                        Reserved20[0x10];
        eth_scrt2cmp_registers_t       SCRT2CMP[ETH_SCRT2CMP_NUMBER]; /**< Offset: 0x1700  */
} eth_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA80_ETH_COMPONENT_H_ */
