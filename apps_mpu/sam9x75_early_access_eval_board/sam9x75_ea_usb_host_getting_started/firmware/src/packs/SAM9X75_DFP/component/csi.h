/*
 * Component description for CSI
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
#ifndef _SAM9X7_CSI_COMPONENT_H_
#define _SAM9X7_CSI_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR CSI                                          */
/* ************************************************************************** */

/* -------- CSI_N_LANES : (CSI Offset: 0x04) (R/W 32) CSI Lane Configuration Register -------- */
#define CSI_N_LANES_RESETVALUE                _UINT32_(0x01)                                       /*  (CSI_N_LANES) CSI Lane Configuration Register  Reset Value */

#define CSI_N_LANES_N_LANES_Pos               _UINT32_(0)                                          /* (CSI_N_LANES) Number of active data lanes Position */
#define CSI_N_LANES_N_LANES_Msk               (_UINT32_(0x1) << CSI_N_LANES_N_LANES_Pos)           /* (CSI_N_LANES) Number of active data lanes Mask */
#define CSI_N_LANES_N_LANES(value)            (CSI_N_LANES_N_LANES_Msk & (_UINT32_(value) << CSI_N_LANES_N_LANES_Pos)) /* Assigment of value for N_LANES in the CSI_N_LANES register */
#define CSI_N_LANES_Msk                       _UINT32_(0x00000001)                                 /* (CSI_N_LANES) Register Mask  */


/* -------- CSI_CSI2_RESETN : (CSI Offset: 0x08) (R/W 32) CSI Reset Control Register -------- */
#define CSI_CSI2_RESETN_RESETVALUE            _UINT32_(0x00)                                       /*  (CSI_CSI2_RESETN) CSI Reset Control Register  Reset Value */

#define CSI_CSI2_RESETN_CSI2_RESETN_Pos       _UINT32_(0)                                          /* (CSI_CSI2_RESETN) Internal controller logic reset Position */
#define CSI_CSI2_RESETN_CSI2_RESETN_Msk       (_UINT32_(0x1) << CSI_CSI2_RESETN_CSI2_RESETN_Pos)   /* (CSI_CSI2_RESETN) Internal controller logic reset Mask */
#define CSI_CSI2_RESETN_CSI2_RESETN(value)    (CSI_CSI2_RESETN_CSI2_RESETN_Msk & (_UINT32_(value) << CSI_CSI2_RESETN_CSI2_RESETN_Pos)) /* Assigment of value for CSI2_RESETN in the CSI_CSI2_RESETN register */
#define   CSI_CSI2_RESETN_CSI2_RESETN_0_Val   _UINT32_(0x0)                                        /* (CSI_CSI2_RESETN) Resets the internal controller logic.  */
#define   CSI_CSI2_RESETN_CSI2_RESETN_1_Val   _UINT32_(0x1)                                        /* (CSI_CSI2_RESETN) CSI exits Reset state.  */
#define CSI_CSI2_RESETN_CSI2_RESETN_0         (CSI_CSI2_RESETN_CSI2_RESETN_0_Val << CSI_CSI2_RESETN_CSI2_RESETN_Pos) /* (CSI_CSI2_RESETN) Resets the internal controller logic. Position  */
#define CSI_CSI2_RESETN_CSI2_RESETN_1         (CSI_CSI2_RESETN_CSI2_RESETN_1_Val << CSI_CSI2_RESETN_CSI2_RESETN_Pos) /* (CSI_CSI2_RESETN) CSI exits Reset state. Position  */
#define CSI_CSI2_RESETN_Msk                   _UINT32_(0x00000001)                                 /* (CSI_CSI2_RESETN) Register Mask  */


/* -------- CSI_INT_ST_MAIN : (CSI Offset: 0x0C) ( R/ 32) CSI Main Interrupt Status Register -------- */
#define CSI_INT_ST_MAIN_RESETVALUE            _UINT32_(0x00)                                       /*  (CSI_INT_ST_MAIN) CSI Main Interrupt Status Register  Reset Value */

#define CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL_Pos _UINT32_(0)                                          /* (CSI_INT_ST_MAIN) CSI_INT_ST_PHY_FATAL Register Event (Cleared on Read) Position */
#define CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL_Msk (_UINT32_(0x1) << CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL_Pos) /* (CSI_INT_ST_MAIN) CSI_INT_ST_PHY_FATAL Register Event (Cleared on Read) Mask */
#define CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL(value) (CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL_Msk & (_UINT32_(value) << CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL_Pos)) /* Assigment of value for STATUS_INT_PHY_FATAL in the CSI_INT_ST_MAIN register */
#define   CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL_0_Val _UINT32_(0x0)                                        /* (CSI_INT_ST_MAIN) No event occurred in the CSI_INT_ST_PHY_FATAL register since the last CSI_INT_ST_MAIN read.  */
#define   CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL_1_Val _UINT32_(0x1)                                        /* (CSI_INT_ST_MAIN) Indicates if an event occurred in the CSI_INT_ST_PHY_FATAL register since the last CSI_INT_ST_MAIN read.  */
#define CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL_0 (CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL_0_Val << CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL_Pos) /* (CSI_INT_ST_MAIN) No event occurred in the CSI_INT_ST_PHY_FATAL register since the last CSI_INT_ST_MAIN read. Position  */
#define CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL_1 (CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL_1_Val << CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL_Pos) /* (CSI_INT_ST_MAIN) Indicates if an event occurred in the CSI_INT_ST_PHY_FATAL register since the last CSI_INT_ST_MAIN read. Position  */
#define CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL_Pos _UINT32_(1)                                          /* (CSI_INT_ST_MAIN) CSI_INT_ST_PKT_FATAL Register Event (Cleared on Read) Position */
#define CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL_Msk (_UINT32_(0x1) << CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL_Pos) /* (CSI_INT_ST_MAIN) CSI_INT_ST_PKT_FATAL Register Event (Cleared on Read) Mask */
#define CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL(value) (CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL_Msk & (_UINT32_(value) << CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL_Pos)) /* Assigment of value for STATUS_INT_PKT_FATAL in the CSI_INT_ST_MAIN register */
#define   CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL_0_Val _UINT32_(0x0)                                        /* (CSI_INT_ST_MAIN) No event occurred in the CSI_INT_ST_PKT_FATAL register since the last CSI_INT_ST_MAIN read.  */
#define   CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL_1_Val _UINT32_(0x1)                                        /* (CSI_INT_ST_MAIN) Indicates if an event occurred in the CSI_INT_ST_PKT_FATAL register since the last CSI_INT_ST_MAIN read.  */
#define CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL_0 (CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL_0_Val << CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL_Pos) /* (CSI_INT_ST_MAIN) No event occurred in the CSI_INT_ST_PKT_FATAL register since the last CSI_INT_ST_MAIN read. Position  */
#define CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL_1 (CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL_1_Val << CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL_Pos) /* (CSI_INT_ST_MAIN) Indicates if an event occurred in the CSI_INT_ST_PKT_FATAL register since the last CSI_INT_ST_MAIN read. Position  */
#define CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL_Pos _UINT32_(2)                                          /* (CSI_INT_ST_MAIN) CSI_INT_ST_FRAME_FATAL Register Event (Cleared on Read) Position */
#define CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL_Msk (_UINT32_(0x1) << CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL_Pos) /* (CSI_INT_ST_MAIN) CSI_INT_ST_FRAME_FATAL Register Event (Cleared on Read) Mask */
#define CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL(value) (CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL_Msk & (_UINT32_(value) << CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL_Pos)) /* Assigment of value for STATUS_INT_FRAME_FATAL in the CSI_INT_ST_MAIN register */
#define   CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL_0_Val _UINT32_(0x0)                                        /* (CSI_INT_ST_MAIN) No event occurred in the CSI_INT_ST_FRAME_FATAL register since the last CSI_INT_ST_MAIN read.  */
#define   CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL_1_Val _UINT32_(0x1)                                        /* (CSI_INT_ST_MAIN) Indicates if an event occurred in the CSI_INT_ST_FRAME_FATAL register since the last CSI_INT_ST_MAIN read.  */
#define CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL_0 (CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL_0_Val << CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL_Pos) /* (CSI_INT_ST_MAIN) No event occurred in the CSI_INT_ST_FRAME_FATAL register since the last CSI_INT_ST_MAIN read. Position  */
#define CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL_1 (CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL_1_Val << CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL_Pos) /* (CSI_INT_ST_MAIN) Indicates if an event occurred in the CSI_INT_ST_FRAME_FATAL register since the last CSI_INT_ST_MAIN read. Position  */
#define CSI_INT_ST_MAIN_STATUS_INT_DPHY_Pos   _UINT32_(16)                                         /* (CSI_INT_ST_MAIN) CSI_INT_ST_DPHY Register Event (Cleared on Read) Position */
#define CSI_INT_ST_MAIN_STATUS_INT_DPHY_Msk   (_UINT32_(0x1) << CSI_INT_ST_MAIN_STATUS_INT_DPHY_Pos) /* (CSI_INT_ST_MAIN) CSI_INT_ST_DPHY Register Event (Cleared on Read) Mask */
#define CSI_INT_ST_MAIN_STATUS_INT_DPHY(value) (CSI_INT_ST_MAIN_STATUS_INT_DPHY_Msk & (_UINT32_(value) << CSI_INT_ST_MAIN_STATUS_INT_DPHY_Pos)) /* Assigment of value for STATUS_INT_DPHY in the CSI_INT_ST_MAIN register */
#define   CSI_INT_ST_MAIN_STATUS_INT_DPHY_0_Val _UINT32_(0x0)                                        /* (CSI_INT_ST_MAIN) No event occurred in the CSI_INT_ST_DPHY register since the last CSI_INT_ST_MAIN read.  */
#define   CSI_INT_ST_MAIN_STATUS_INT_DPHY_1_Val _UINT32_(0x1)                                        /* (CSI_INT_ST_MAIN) Indicates if an event occurred in the CSI_INT_ST_DPHY register since the last CSI_INT_ST_MAIN read.  */
#define CSI_INT_ST_MAIN_STATUS_INT_DPHY_0     (CSI_INT_ST_MAIN_STATUS_INT_DPHY_0_Val << CSI_INT_ST_MAIN_STATUS_INT_DPHY_Pos) /* (CSI_INT_ST_MAIN) No event occurred in the CSI_INT_ST_DPHY register since the last CSI_INT_ST_MAIN read. Position  */
#define CSI_INT_ST_MAIN_STATUS_INT_DPHY_1     (CSI_INT_ST_MAIN_STATUS_INT_DPHY_1_Val << CSI_INT_ST_MAIN_STATUS_INT_DPHY_Pos) /* (CSI_INT_ST_MAIN) Indicates if an event occurred in the CSI_INT_ST_DPHY register since the last CSI_INT_ST_MAIN read. Position  */
#define CSI_INT_ST_MAIN_STATUS_INT_PKT_Pos    _UINT32_(17)                                         /* (CSI_INT_ST_MAIN) CSI_INT_ST_PKT Register Event (Cleared on Read) Position */
#define CSI_INT_ST_MAIN_STATUS_INT_PKT_Msk    (_UINT32_(0x1) << CSI_INT_ST_MAIN_STATUS_INT_PKT_Pos) /* (CSI_INT_ST_MAIN) CSI_INT_ST_PKT Register Event (Cleared on Read) Mask */
#define CSI_INT_ST_MAIN_STATUS_INT_PKT(value) (CSI_INT_ST_MAIN_STATUS_INT_PKT_Msk & (_UINT32_(value) << CSI_INT_ST_MAIN_STATUS_INT_PKT_Pos)) /* Assigment of value for STATUS_INT_PKT in the CSI_INT_ST_MAIN register */
#define   CSI_INT_ST_MAIN_STATUS_INT_PKT_0_Val _UINT32_(0x0)                                        /* (CSI_INT_ST_MAIN) No event occurred in the CSI_INT_ST_PKT register since the last CSI_INT_ST_MAIN read.  */
#define   CSI_INT_ST_MAIN_STATUS_INT_PKT_1_Val _UINT32_(0x1)                                        /* (CSI_INT_ST_MAIN) Indicates if an event occurred in the CSI_INT_ST_PKT register since the last CSI_INT_ST_MAIN read.  */
#define CSI_INT_ST_MAIN_STATUS_INT_PKT_0      (CSI_INT_ST_MAIN_STATUS_INT_PKT_0_Val << CSI_INT_ST_MAIN_STATUS_INT_PKT_Pos) /* (CSI_INT_ST_MAIN) No event occurred in the CSI_INT_ST_PKT register since the last CSI_INT_ST_MAIN read. Position  */
#define CSI_INT_ST_MAIN_STATUS_INT_PKT_1      (CSI_INT_ST_MAIN_STATUS_INT_PKT_1_Val << CSI_INT_ST_MAIN_STATUS_INT_PKT_Pos) /* (CSI_INT_ST_MAIN) Indicates if an event occurred in the CSI_INT_ST_PKT register since the last CSI_INT_ST_MAIN read. Position  */
#define CSI_INT_ST_MAIN_STATUS_INT_LINE_Pos   _UINT32_(18)                                         /* (CSI_INT_ST_MAIN) CSI_INT_LINE Register Event (Cleared on Read) Position */
#define CSI_INT_ST_MAIN_STATUS_INT_LINE_Msk   (_UINT32_(0x1) << CSI_INT_ST_MAIN_STATUS_INT_LINE_Pos) /* (CSI_INT_ST_MAIN) CSI_INT_LINE Register Event (Cleared on Read) Mask */
#define CSI_INT_ST_MAIN_STATUS_INT_LINE(value) (CSI_INT_ST_MAIN_STATUS_INT_LINE_Msk & (_UINT32_(value) << CSI_INT_ST_MAIN_STATUS_INT_LINE_Pos)) /* Assigment of value for STATUS_INT_LINE in the CSI_INT_ST_MAIN register */
#define   CSI_INT_ST_MAIN_STATUS_INT_LINE_0_Val _UINT32_(0x0)                                        /* (CSI_INT_ST_MAIN) No event occurred in the CSI_INT_ST_LINE register since the last CSI_INT_ST_MAIN read.  */
#define   CSI_INT_ST_MAIN_STATUS_INT_LINE_1_Val _UINT32_(0x1)                                        /* (CSI_INT_ST_MAIN) Indicates if an event occurred in the CSI_INT_ST_LINE register since the last CSI_INT_ST_MAIN read.  */
#define CSI_INT_ST_MAIN_STATUS_INT_LINE_0     (CSI_INT_ST_MAIN_STATUS_INT_LINE_0_Val << CSI_INT_ST_MAIN_STATUS_INT_LINE_Pos) /* (CSI_INT_ST_MAIN) No event occurred in the CSI_INT_ST_LINE register since the last CSI_INT_ST_MAIN read. Position  */
#define CSI_INT_ST_MAIN_STATUS_INT_LINE_1     (CSI_INT_ST_MAIN_STATUS_INT_LINE_1_Val << CSI_INT_ST_MAIN_STATUS_INT_LINE_Pos) /* (CSI_INT_ST_MAIN) Indicates if an event occurred in the CSI_INT_ST_LINE register since the last CSI_INT_ST_MAIN read. Position  */
#define CSI_INT_ST_MAIN_Msk                   _UINT32_(0x00070007)                                 /* (CSI_INT_ST_MAIN) Register Mask  */


/* -------- CSI_DATA_IDS_1 : (CSI Offset: 0x10) (R/W 32) CSI Data Identifier Register 1 -------- */
#define CSI_DATA_IDS_1_RESETVALUE             _UINT32_(0x00)                                       /*  (CSI_DATA_IDS_1) CSI Data Identifier Register 1  Reset Value */

#define CSI_DATA_IDS_1_DI0_DT_Pos             _UINT32_(0)                                          /* (CSI_DATA_IDS_1) Data Type for Programmed data ID 0 Position */
#define CSI_DATA_IDS_1_DI0_DT_Msk             (_UINT32_(0x3F) << CSI_DATA_IDS_1_DI0_DT_Pos)        /* (CSI_DATA_IDS_1) Data Type for Programmed data ID 0 Mask */
#define CSI_DATA_IDS_1_DI0_DT(value)          (CSI_DATA_IDS_1_DI0_DT_Msk & (_UINT32_(value) << CSI_DATA_IDS_1_DI0_DT_Pos)) /* Assigment of value for DI0_DT in the CSI_DATA_IDS_1 register */
#define CSI_DATA_IDS_1_DI0_VC_Pos             _UINT32_(6)                                          /* (CSI_DATA_IDS_1) Virtual Channel for Programmed data ID 0 Position */
#define CSI_DATA_IDS_1_DI0_VC_Msk             (_UINT32_(0x3) << CSI_DATA_IDS_1_DI0_VC_Pos)         /* (CSI_DATA_IDS_1) Virtual Channel for Programmed data ID 0 Mask */
#define CSI_DATA_IDS_1_DI0_VC(value)          (CSI_DATA_IDS_1_DI0_VC_Msk & (_UINT32_(value) << CSI_DATA_IDS_1_DI0_VC_Pos)) /* Assigment of value for DI0_VC in the CSI_DATA_IDS_1 register */
#define CSI_DATA_IDS_1_DI1_DT_Pos             _UINT32_(8)                                          /* (CSI_DATA_IDS_1) Data Type for Programmed data ID 1 Position */
#define CSI_DATA_IDS_1_DI1_DT_Msk             (_UINT32_(0x3F) << CSI_DATA_IDS_1_DI1_DT_Pos)        /* (CSI_DATA_IDS_1) Data Type for Programmed data ID 1 Mask */
#define CSI_DATA_IDS_1_DI1_DT(value)          (CSI_DATA_IDS_1_DI1_DT_Msk & (_UINT32_(value) << CSI_DATA_IDS_1_DI1_DT_Pos)) /* Assigment of value for DI1_DT in the CSI_DATA_IDS_1 register */
#define CSI_DATA_IDS_1_DI1_VC_Pos             _UINT32_(14)                                         /* (CSI_DATA_IDS_1) Virtual Channel for Programmed data ID 1 Position */
#define CSI_DATA_IDS_1_DI1_VC_Msk             (_UINT32_(0x3) << CSI_DATA_IDS_1_DI1_VC_Pos)         /* (CSI_DATA_IDS_1) Virtual Channel for Programmed data ID 1 Mask */
#define CSI_DATA_IDS_1_DI1_VC(value)          (CSI_DATA_IDS_1_DI1_VC_Msk & (_UINT32_(value) << CSI_DATA_IDS_1_DI1_VC_Pos)) /* Assigment of value for DI1_VC in the CSI_DATA_IDS_1 register */
#define CSI_DATA_IDS_1_DI2_DT_Pos             _UINT32_(16)                                         /* (CSI_DATA_IDS_1) Data Type for Programmed data ID 2 Position */
#define CSI_DATA_IDS_1_DI2_DT_Msk             (_UINT32_(0x3F) << CSI_DATA_IDS_1_DI2_DT_Pos)        /* (CSI_DATA_IDS_1) Data Type for Programmed data ID 2 Mask */
#define CSI_DATA_IDS_1_DI2_DT(value)          (CSI_DATA_IDS_1_DI2_DT_Msk & (_UINT32_(value) << CSI_DATA_IDS_1_DI2_DT_Pos)) /* Assigment of value for DI2_DT in the CSI_DATA_IDS_1 register */
#define CSI_DATA_IDS_1_DI2_VC_Pos             _UINT32_(22)                                         /* (CSI_DATA_IDS_1) Virtual Channel for Programmed data ID 2 Position */
#define CSI_DATA_IDS_1_DI2_VC_Msk             (_UINT32_(0x3) << CSI_DATA_IDS_1_DI2_VC_Pos)         /* (CSI_DATA_IDS_1) Virtual Channel for Programmed data ID 2 Mask */
#define CSI_DATA_IDS_1_DI2_VC(value)          (CSI_DATA_IDS_1_DI2_VC_Msk & (_UINT32_(value) << CSI_DATA_IDS_1_DI2_VC_Pos)) /* Assigment of value for DI2_VC in the CSI_DATA_IDS_1 register */
#define CSI_DATA_IDS_1_DI3_DT_Pos             _UINT32_(24)                                         /* (CSI_DATA_IDS_1) Data Type for Programmed data ID 3 Position */
#define CSI_DATA_IDS_1_DI3_DT_Msk             (_UINT32_(0x3F) << CSI_DATA_IDS_1_DI3_DT_Pos)        /* (CSI_DATA_IDS_1) Data Type for Programmed data ID 3 Mask */
#define CSI_DATA_IDS_1_DI3_DT(value)          (CSI_DATA_IDS_1_DI3_DT_Msk & (_UINT32_(value) << CSI_DATA_IDS_1_DI3_DT_Pos)) /* Assigment of value for DI3_DT in the CSI_DATA_IDS_1 register */
#define CSI_DATA_IDS_1_DI3_VC_Pos             _UINT32_(30)                                         /* (CSI_DATA_IDS_1) Virtual Channel for Programmed data ID 3 Position */
#define CSI_DATA_IDS_1_DI3_VC_Msk             (_UINT32_(0x3) << CSI_DATA_IDS_1_DI3_VC_Pos)         /* (CSI_DATA_IDS_1) Virtual Channel for Programmed data ID 3 Mask */
#define CSI_DATA_IDS_1_DI3_VC(value)          (CSI_DATA_IDS_1_DI3_VC_Msk & (_UINT32_(value) << CSI_DATA_IDS_1_DI3_VC_Pos)) /* Assigment of value for DI3_VC in the CSI_DATA_IDS_1 register */
#define CSI_DATA_IDS_1_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (CSI_DATA_IDS_1) Register Mask  */


/* -------- CSI_DATA_IDS_2 : (CSI Offset: 0x14) (R/W 32) CSI Data Identifier Register 2 -------- */
#define CSI_DATA_IDS_2_RESETVALUE             _UINT32_(0x00)                                       /*  (CSI_DATA_IDS_2) CSI Data Identifier Register 2  Reset Value */

#define CSI_DATA_IDS_2_DI4_DT_Pos             _UINT32_(0)                                          /* (CSI_DATA_IDS_2) Data Type for Programmed data ID 4 Position */
#define CSI_DATA_IDS_2_DI4_DT_Msk             (_UINT32_(0x3F) << CSI_DATA_IDS_2_DI4_DT_Pos)        /* (CSI_DATA_IDS_2) Data Type for Programmed data ID 4 Mask */
#define CSI_DATA_IDS_2_DI4_DT(value)          (CSI_DATA_IDS_2_DI4_DT_Msk & (_UINT32_(value) << CSI_DATA_IDS_2_DI4_DT_Pos)) /* Assigment of value for DI4_DT in the CSI_DATA_IDS_2 register */
#define CSI_DATA_IDS_2_DI4_VC_Pos             _UINT32_(6)                                          /* (CSI_DATA_IDS_2) Virtual Channel for Programmed data ID 4 Position */
#define CSI_DATA_IDS_2_DI4_VC_Msk             (_UINT32_(0x3) << CSI_DATA_IDS_2_DI4_VC_Pos)         /* (CSI_DATA_IDS_2) Virtual Channel for Programmed data ID 4 Mask */
#define CSI_DATA_IDS_2_DI4_VC(value)          (CSI_DATA_IDS_2_DI4_VC_Msk & (_UINT32_(value) << CSI_DATA_IDS_2_DI4_VC_Pos)) /* Assigment of value for DI4_VC in the CSI_DATA_IDS_2 register */
#define CSI_DATA_IDS_2_DI5_DT_Pos             _UINT32_(8)                                          /* (CSI_DATA_IDS_2) Data Type for Programmed data ID 5 Position */
#define CSI_DATA_IDS_2_DI5_DT_Msk             (_UINT32_(0x3F) << CSI_DATA_IDS_2_DI5_DT_Pos)        /* (CSI_DATA_IDS_2) Data Type for Programmed data ID 5 Mask */
#define CSI_DATA_IDS_2_DI5_DT(value)          (CSI_DATA_IDS_2_DI5_DT_Msk & (_UINT32_(value) << CSI_DATA_IDS_2_DI5_DT_Pos)) /* Assigment of value for DI5_DT in the CSI_DATA_IDS_2 register */
#define CSI_DATA_IDS_2_DI5_VC_Pos             _UINT32_(14)                                         /* (CSI_DATA_IDS_2) Virtual Channel for Programmed data ID 5 Position */
#define CSI_DATA_IDS_2_DI5_VC_Msk             (_UINT32_(0x3) << CSI_DATA_IDS_2_DI5_VC_Pos)         /* (CSI_DATA_IDS_2) Virtual Channel for Programmed data ID 5 Mask */
#define CSI_DATA_IDS_2_DI5_VC(value)          (CSI_DATA_IDS_2_DI5_VC_Msk & (_UINT32_(value) << CSI_DATA_IDS_2_DI5_VC_Pos)) /* Assigment of value for DI5_VC in the CSI_DATA_IDS_2 register */
#define CSI_DATA_IDS_2_DI6_DT_Pos             _UINT32_(16)                                         /* (CSI_DATA_IDS_2) Data Type for Programmed data ID 6 Position */
#define CSI_DATA_IDS_2_DI6_DT_Msk             (_UINT32_(0x3F) << CSI_DATA_IDS_2_DI6_DT_Pos)        /* (CSI_DATA_IDS_2) Data Type for Programmed data ID 6 Mask */
#define CSI_DATA_IDS_2_DI6_DT(value)          (CSI_DATA_IDS_2_DI6_DT_Msk & (_UINT32_(value) << CSI_DATA_IDS_2_DI6_DT_Pos)) /* Assigment of value for DI6_DT in the CSI_DATA_IDS_2 register */
#define CSI_DATA_IDS_2_DI6_VC_Pos             _UINT32_(22)                                         /* (CSI_DATA_IDS_2) Virtual Channel for Programmed data ID 6 Position */
#define CSI_DATA_IDS_2_DI6_VC_Msk             (_UINT32_(0x3) << CSI_DATA_IDS_2_DI6_VC_Pos)         /* (CSI_DATA_IDS_2) Virtual Channel for Programmed data ID 6 Mask */
#define CSI_DATA_IDS_2_DI6_VC(value)          (CSI_DATA_IDS_2_DI6_VC_Msk & (_UINT32_(value) << CSI_DATA_IDS_2_DI6_VC_Pos)) /* Assigment of value for DI6_VC in the CSI_DATA_IDS_2 register */
#define CSI_DATA_IDS_2_DI7_DT_Pos             _UINT32_(24)                                         /* (CSI_DATA_IDS_2) Data Type for Programmed data ID 7 Position */
#define CSI_DATA_IDS_2_DI7_DT_Msk             (_UINT32_(0x3F) << CSI_DATA_IDS_2_DI7_DT_Pos)        /* (CSI_DATA_IDS_2) Data Type for Programmed data ID 7 Mask */
#define CSI_DATA_IDS_2_DI7_DT(value)          (CSI_DATA_IDS_2_DI7_DT_Msk & (_UINT32_(value) << CSI_DATA_IDS_2_DI7_DT_Pos)) /* Assigment of value for DI7_DT in the CSI_DATA_IDS_2 register */
#define CSI_DATA_IDS_2_DI7_VC_Pos             _UINT32_(30)                                         /* (CSI_DATA_IDS_2) Virtual Channel for Programmed data ID 7 Position */
#define CSI_DATA_IDS_2_DI7_VC_Msk             (_UINT32_(0x3) << CSI_DATA_IDS_2_DI7_VC_Pos)         /* (CSI_DATA_IDS_2) Virtual Channel for Programmed data ID 7 Mask */
#define CSI_DATA_IDS_2_DI7_VC(value)          (CSI_DATA_IDS_2_DI7_VC_Msk & (_UINT32_(value) << CSI_DATA_IDS_2_DI7_VC_Pos)) /* Assigment of value for DI7_VC in the CSI_DATA_IDS_2 register */
#define CSI_DATA_IDS_2_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (CSI_DATA_IDS_2) Register Mask  */


/* -------- CSI_PHY_SHUTDOWNZ : (CSI Offset: 0x40) (R/W 32) CSI D-PHY Shutdown Register -------- */
#define CSI_PHY_SHUTDOWNZ_RESETVALUE          _UINT32_(0x00)                                       /*  (CSI_PHY_SHUTDOWNZ) CSI D-PHY Shutdown Register  Reset Value */

#define CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ_Pos   _UINT32_(0)                                          /* (CSI_PHY_SHUTDOWNZ) Shutdown input buffer Position */
#define CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ_Msk   (_UINT32_(0x1) << CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ_Pos) /* (CSI_PHY_SHUTDOWNZ) Shutdown input buffer Mask */
#define CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ(value) (CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ_Msk & (_UINT32_(value) << CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ_Pos)) /* Assigment of value for PHY_SHUTDOWNZ in the CSI_PHY_SHUTDOWNZ register */
#define   CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ_0_Val _UINT32_(0x0)                                        /* (CSI_PHY_SHUTDOWNZ) Puts the D-PHY in Shutdown mode. All analog blocks are in Power-down mode and digital logic is cleared.  */
#define   CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ_1_Val _UINT32_(0x1)                                        /* (CSI_PHY_SHUTDOWNZ) D-PHY exits Shutdown mode.  */
#define CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ_0     (CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ_0_Val << CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ_Pos) /* (CSI_PHY_SHUTDOWNZ) Puts the D-PHY in Shutdown mode. All analog blocks are in Power-down mode and digital logic is cleared. Position  */
#define CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ_1     (CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ_1_Val << CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ_Pos) /* (CSI_PHY_SHUTDOWNZ) D-PHY exits Shutdown mode. Position  */
#define CSI_PHY_SHUTDOWNZ_Msk                 _UINT32_(0x00000001)                                 /* (CSI_PHY_SHUTDOWNZ) Register Mask  */


/* -------- CSI_DPHY_RSTZ : (CSI Offset: 0x44) (R/W 32) CSI D-PHY Reset Register -------- */
#define CSI_DPHY_RSTZ_RESETVALUE              _UINT32_(0x00)                                       /*  (CSI_DPHY_RSTZ) CSI D-PHY Reset Register  Reset Value */

#define CSI_DPHY_RSTZ_DPHY_RSTZ_Pos           _UINT32_(0)                                          /* (CSI_DPHY_RSTZ) D-PHY Reset Control Position */
#define CSI_DPHY_RSTZ_DPHY_RSTZ_Msk           (_UINT32_(0x1) << CSI_DPHY_RSTZ_DPHY_RSTZ_Pos)       /* (CSI_DPHY_RSTZ) D-PHY Reset Control Mask */
#define CSI_DPHY_RSTZ_DPHY_RSTZ(value)        (CSI_DPHY_RSTZ_DPHY_RSTZ_Msk & (_UINT32_(value) << CSI_DPHY_RSTZ_DPHY_RSTZ_Pos)) /* Assigment of value for DPHY_RSTZ in the CSI_DPHY_RSTZ register */
#define   CSI_DPHY_RSTZ_DPHY_RSTZ_0_Val       _UINT32_(0x0)                                        /* (CSI_DPHY_RSTZ) Resets the D-PHY.  */
#define   CSI_DPHY_RSTZ_DPHY_RSTZ_1_Val       _UINT32_(0x1)                                        /* (CSI_DPHY_RSTZ) D-PHY exits Reset state.  */
#define CSI_DPHY_RSTZ_DPHY_RSTZ_0             (CSI_DPHY_RSTZ_DPHY_RSTZ_0_Val << CSI_DPHY_RSTZ_DPHY_RSTZ_Pos) /* (CSI_DPHY_RSTZ) Resets the D-PHY. Position  */
#define CSI_DPHY_RSTZ_DPHY_RSTZ_1             (CSI_DPHY_RSTZ_DPHY_RSTZ_1_Val << CSI_DPHY_RSTZ_DPHY_RSTZ_Pos) /* (CSI_DPHY_RSTZ) D-PHY exits Reset state. Position  */
#define CSI_DPHY_RSTZ_Msk                     _UINT32_(0x00000001)                                 /* (CSI_DPHY_RSTZ) Register Mask  */


/* -------- CSI_PHY_RX : (CSI Offset: 0x48) ( R/ 32) CSI D-PHY Receive Status Register -------- */
#define CSI_PHY_RX_RESETVALUE                 _UINT32_(0x10000)                                    /*  (CSI_PHY_RX) CSI D-PHY Receive Status Register  Reset Value */

#define CSI_PHY_RX_PHY_RXULPSESC_0_Pos        _UINT32_(0)                                          /* (CSI_PHY_RX) Data Lane 0 Ultra-Low-Power Status Position */
#define CSI_PHY_RX_PHY_RXULPSESC_0_Msk        (_UINT32_(0x1) << CSI_PHY_RX_PHY_RXULPSESC_0_Pos)    /* (CSI_PHY_RX) Data Lane 0 Ultra-Low-Power Status Mask */
#define CSI_PHY_RX_PHY_RXULPSESC_0(value)     (CSI_PHY_RX_PHY_RXULPSESC_0_Msk & (_UINT32_(value) << CSI_PHY_RX_PHY_RXULPSESC_0_Pos)) /* Assigment of value for PHY_RXULPSESC_0 in the CSI_PHY_RX register */
#define   CSI_PHY_RX_PHY_RXULPSESC_0_0_Val    _UINT32_(0x0)                                        /* (CSI_PHY_RX) Data lane 0 module is not in Ultra-Low-Power (ULP) Mode.  */
#define   CSI_PHY_RX_PHY_RXULPSESC_0_1_Val    _UINT32_(0x1)                                        /* (CSI_PHY_RX) Data lane 0 module has entered ULP Mode.  */
#define CSI_PHY_RX_PHY_RXULPSESC_0_0          (CSI_PHY_RX_PHY_RXULPSESC_0_0_Val << CSI_PHY_RX_PHY_RXULPSESC_0_Pos) /* (CSI_PHY_RX) Data lane 0 module is not in Ultra-Low-Power (ULP) Mode. Position  */
#define CSI_PHY_RX_PHY_RXULPSESC_0_1          (CSI_PHY_RX_PHY_RXULPSESC_0_1_Val << CSI_PHY_RX_PHY_RXULPSESC_0_Pos) /* (CSI_PHY_RX) Data lane 0 module has entered ULP Mode. Position  */
#define CSI_PHY_RX_PHY_RXULPSESC_1_Pos        _UINT32_(1)                                          /* (CSI_PHY_RX) Data Lane 1 Ultra-Low-Power Status Position */
#define CSI_PHY_RX_PHY_RXULPSESC_1_Msk        (_UINT32_(0x1) << CSI_PHY_RX_PHY_RXULPSESC_1_Pos)    /* (CSI_PHY_RX) Data Lane 1 Ultra-Low-Power Status Mask */
#define CSI_PHY_RX_PHY_RXULPSESC_1(value)     (CSI_PHY_RX_PHY_RXULPSESC_1_Msk & (_UINT32_(value) << CSI_PHY_RX_PHY_RXULPSESC_1_Pos)) /* Assigment of value for PHY_RXULPSESC_1 in the CSI_PHY_RX register */
#define   CSI_PHY_RX_PHY_RXULPSESC_1_0_Val    _UINT32_(0x0)                                        /* (CSI_PHY_RX) Data lane 1 module is not in ULP Mode.  */
#define   CSI_PHY_RX_PHY_RXULPSESC_1_1_Val    _UINT32_(0x1)                                        /* (CSI_PHY_RX) Data lane 1 module has entered ULP Mode.  */
#define CSI_PHY_RX_PHY_RXULPSESC_1_0          (CSI_PHY_RX_PHY_RXULPSESC_1_0_Val << CSI_PHY_RX_PHY_RXULPSESC_1_Pos) /* (CSI_PHY_RX) Data lane 1 module is not in ULP Mode. Position  */
#define CSI_PHY_RX_PHY_RXULPSESC_1_1          (CSI_PHY_RX_PHY_RXULPSESC_1_1_Val << CSI_PHY_RX_PHY_RXULPSESC_1_Pos) /* (CSI_PHY_RX) Data lane 1 module has entered ULP Mode. Position  */
#define CSI_PHY_RX_PHY_RXULPSESC_2_Pos        _UINT32_(2)                                          /* (CSI_PHY_RX) Data Lane 2 Ultra-Low-Power Status Position */
#define CSI_PHY_RX_PHY_RXULPSESC_2_Msk        (_UINT32_(0x1) << CSI_PHY_RX_PHY_RXULPSESC_2_Pos)    /* (CSI_PHY_RX) Data Lane 2 Ultra-Low-Power Status Mask */
#define CSI_PHY_RX_PHY_RXULPSESC_2(value)     (CSI_PHY_RX_PHY_RXULPSESC_2_Msk & (_UINT32_(value) << CSI_PHY_RX_PHY_RXULPSESC_2_Pos)) /* Assigment of value for PHY_RXULPSESC_2 in the CSI_PHY_RX register */
#define   CSI_PHY_RX_PHY_RXULPSESC_2_0_Val    _UINT32_(0x0)                                        /* (CSI_PHY_RX) Data lane 2 module is not in ULP Mode.  */
#define   CSI_PHY_RX_PHY_RXULPSESC_2_1_Val    _UINT32_(0x1)                                        /* (CSI_PHY_RX) Data lane 2 module has entered ULP Mode.  */
#define CSI_PHY_RX_PHY_RXULPSESC_2_0          (CSI_PHY_RX_PHY_RXULPSESC_2_0_Val << CSI_PHY_RX_PHY_RXULPSESC_2_Pos) /* (CSI_PHY_RX) Data lane 2 module is not in ULP Mode. Position  */
#define CSI_PHY_RX_PHY_RXULPSESC_2_1          (CSI_PHY_RX_PHY_RXULPSESC_2_1_Val << CSI_PHY_RX_PHY_RXULPSESC_2_Pos) /* (CSI_PHY_RX) Data lane 2 module has entered ULP Mode. Position  */
#define CSI_PHY_RX_PHY_RXULPSESC_3_Pos        _UINT32_(3)                                          /* (CSI_PHY_RX) Lane 3 Ultra-Low-Power Status Position */
#define CSI_PHY_RX_PHY_RXULPSESC_3_Msk        (_UINT32_(0x1) << CSI_PHY_RX_PHY_RXULPSESC_3_Pos)    /* (CSI_PHY_RX) Lane 3 Ultra-Low-Power Status Mask */
#define CSI_PHY_RX_PHY_RXULPSESC_3(value)     (CSI_PHY_RX_PHY_RXULPSESC_3_Msk & (_UINT32_(value) << CSI_PHY_RX_PHY_RXULPSESC_3_Pos)) /* Assigment of value for PHY_RXULPSESC_3 in the CSI_PHY_RX register */
#define   CSI_PHY_RX_PHY_RXULPSESC_3_0_Val    _UINT32_(0x0)                                        /* (CSI_PHY_RX) Data lane 3 module is not in ULP Mode.  */
#define   CSI_PHY_RX_PHY_RXULPSESC_3_1_Val    _UINT32_(0x1)                                        /* (CSI_PHY_RX) Data lane 3 module has entered ULP Mode.  */
#define CSI_PHY_RX_PHY_RXULPSESC_3_0          (CSI_PHY_RX_PHY_RXULPSESC_3_0_Val << CSI_PHY_RX_PHY_RXULPSESC_3_Pos) /* (CSI_PHY_RX) Data lane 3 module is not in ULP Mode. Position  */
#define CSI_PHY_RX_PHY_RXULPSESC_3_1          (CSI_PHY_RX_PHY_RXULPSESC_3_1_Val << CSI_PHY_RX_PHY_RXULPSESC_3_Pos) /* (CSI_PHY_RX) Data lane 3 module has entered ULP Mode. Position  */
#define CSI_PHY_RX_PHY_RXULPSSCLKNOT_Pos      _UINT32_(16)                                         /* (CSI_PHY_RX) Clock Lane Power Status Position */
#define CSI_PHY_RX_PHY_RXULPSSCLKNOT_Msk      (_UINT32_(0x1) << CSI_PHY_RX_PHY_RXULPSSCLKNOT_Pos)  /* (CSI_PHY_RX) Clock Lane Power Status Mask */
#define CSI_PHY_RX_PHY_RXULPSSCLKNOT(value)   (CSI_PHY_RX_PHY_RXULPSSCLKNOT_Msk & (_UINT32_(value) << CSI_PHY_RX_PHY_RXULPSSCLKNOT_Pos)) /* Assigment of value for PHY_RXULPSSCLKNOT in the CSI_PHY_RX register */
#define   CSI_PHY_RX_PHY_RXULPSSCLKNOT_0_Val  _UINT32_(0x0)                                        /* (CSI_PHY_RX) Indicates that D-PHY Clock Lane module has entered the Ultra-Low-Power Mode.  */
#define   CSI_PHY_RX_PHY_RXULPSSCLKNOT_1_Val  _UINT32_(0x1)                                        /* (CSI_PHY_RX) Clock Lane is not ULP Mode.  */
#define CSI_PHY_RX_PHY_RXULPSSCLKNOT_0        (CSI_PHY_RX_PHY_RXULPSSCLKNOT_0_Val << CSI_PHY_RX_PHY_RXULPSSCLKNOT_Pos) /* (CSI_PHY_RX) Indicates that D-PHY Clock Lane module has entered the Ultra-Low-Power Mode. Position  */
#define CSI_PHY_RX_PHY_RXULPSSCLKNOT_1        (CSI_PHY_RX_PHY_RXULPSSCLKNOT_1_Val << CSI_PHY_RX_PHY_RXULPSSCLKNOT_Pos) /* (CSI_PHY_RX) Clock Lane is not ULP Mode. Position  */
#define CSI_PHY_RX_PHY_RXCLKACTIVEHS_Pos      _UINT32_(17)                                         /* (CSI_PHY_RX) D-PHY Receives a DDR clock Position */
#define CSI_PHY_RX_PHY_RXCLKACTIVEHS_Msk      (_UINT32_(0x1) << CSI_PHY_RX_PHY_RXCLKACTIVEHS_Pos)  /* (CSI_PHY_RX) D-PHY Receives a DDR clock Mask */
#define CSI_PHY_RX_PHY_RXCLKACTIVEHS(value)   (CSI_PHY_RX_PHY_RXCLKACTIVEHS_Msk & (_UINT32_(value) << CSI_PHY_RX_PHY_RXCLKACTIVEHS_Pos)) /* Assigment of value for PHY_RXCLKACTIVEHS in the CSI_PHY_RX register */
#define   CSI_PHY_RX_PHY_RXCLKACTIVEHS_0_Val  _UINT32_(0x0)                                        /* (CSI_PHY_RX) No DDR clock received.  */
#define   CSI_PHY_RX_PHY_RXCLKACTIVEHS_1_Val  _UINT32_(0x1)                                        /* (CSI_PHY_RX) Indicates that D-PHY clock lane is actively receiving a DDR clock.  */
#define CSI_PHY_RX_PHY_RXCLKACTIVEHS_0        (CSI_PHY_RX_PHY_RXCLKACTIVEHS_0_Val << CSI_PHY_RX_PHY_RXCLKACTIVEHS_Pos) /* (CSI_PHY_RX) No DDR clock received. Position  */
#define CSI_PHY_RX_PHY_RXCLKACTIVEHS_1        (CSI_PHY_RX_PHY_RXCLKACTIVEHS_1_Val << CSI_PHY_RX_PHY_RXCLKACTIVEHS_Pos) /* (CSI_PHY_RX) Indicates that D-PHY clock lane is actively receiving a DDR clock. Position  */
#define CSI_PHY_RX_Msk                        _UINT32_(0x0003000F)                                 /* (CSI_PHY_RX) Register Mask  */

#define CSI_PHY_RX_PHY_RXULPSESC__Pos         _UINT32_(0)                                          /* (CSI_PHY_RX Position) Data Lane x Ultra-Low-Power Status */
#define CSI_PHY_RX_PHY_RXULPSESC__Msk         (_UINT32_(0xF) << CSI_PHY_RX_PHY_RXULPSESC__Pos)     /* (CSI_PHY_RX Mask) PHY_RXULPSESC_ */
#define CSI_PHY_RX_PHY_RXULPSESC_(value)      (CSI_PHY_RX_PHY_RXULPSESC__Msk & (_UINT32_(value) << CSI_PHY_RX_PHY_RXULPSESC__Pos)) 

/* -------- CSI_PHY_STOPSTATE : (CSI Offset: 0x4C) ( R/ 32) CSI D-PHY Stop State Register -------- */
#define CSI_PHY_STOPSTATE_RESETVALUE          _UINT32_(0x00)                                       /*  (CSI_PHY_STOPSTATE) CSI D-PHY Stop State Register  Reset Value */

#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_0_Pos _UINT32_(0)                                          /* (CSI_PHY_STOPSTATE) Data Lane 0 Stop State Status Position */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_0_Msk (_UINT32_(0x1) << CSI_PHY_STOPSTATE_PHY_STOPSTADATA_0_Pos) /* (CSI_PHY_STOPSTATE) Data Lane 0 Stop State Status Mask */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_0(value) (CSI_PHY_STOPSTATE_PHY_STOPSTADATA_0_Msk & (_UINT32_(value) << CSI_PHY_STOPSTATE_PHY_STOPSTADATA_0_Pos)) /* Assigment of value for PHY_STOPSTADATA_0 in the CSI_PHY_STOPSTATE register */
#define   CSI_PHY_STOPSTATE_PHY_STOPSTADATA_0_0_Val _UINT32_(0x0)                                        /* (CSI_PHY_STOPSTATE) Data lane 0 module is not in Stop state.  */
#define   CSI_PHY_STOPSTATE_PHY_STOPSTADATA_0_1_Val _UINT32_(0x1)                                        /* (CSI_PHY_STOPSTATE) Lane 0 module has entered Stop state.  */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_0_0 (CSI_PHY_STOPSTATE_PHY_STOPSTADATA_0_0_Val << CSI_PHY_STOPSTATE_PHY_STOPSTADATA_0_Pos) /* (CSI_PHY_STOPSTATE) Data lane 0 module is not in Stop state. Position  */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_0_1 (CSI_PHY_STOPSTATE_PHY_STOPSTADATA_0_1_Val << CSI_PHY_STOPSTATE_PHY_STOPSTADATA_0_Pos) /* (CSI_PHY_STOPSTATE) Lane 0 module has entered Stop state. Position  */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_1_Pos _UINT32_(1)                                          /* (CSI_PHY_STOPSTATE) Data Lane 1 Stop State Status Position */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_1_Msk (_UINT32_(0x1) << CSI_PHY_STOPSTATE_PHY_STOPSTADATA_1_Pos) /* (CSI_PHY_STOPSTATE) Data Lane 1 Stop State Status Mask */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_1(value) (CSI_PHY_STOPSTATE_PHY_STOPSTADATA_1_Msk & (_UINT32_(value) << CSI_PHY_STOPSTATE_PHY_STOPSTADATA_1_Pos)) /* Assigment of value for PHY_STOPSTADATA_1 in the CSI_PHY_STOPSTATE register */
#define   CSI_PHY_STOPSTATE_PHY_STOPSTADATA_1_0_Val _UINT32_(0x0)                                        /* (CSI_PHY_STOPSTATE) Lane 1 module is not in Stop state.  */
#define   CSI_PHY_STOPSTATE_PHY_STOPSTADATA_1_1_Val _UINT32_(0x1)                                        /* (CSI_PHY_STOPSTATE) Lane 1 module has entered Stop state.  */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_1_0 (CSI_PHY_STOPSTATE_PHY_STOPSTADATA_1_0_Val << CSI_PHY_STOPSTATE_PHY_STOPSTADATA_1_Pos) /* (CSI_PHY_STOPSTATE) Lane 1 module is not in Stop state. Position  */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_1_1 (CSI_PHY_STOPSTATE_PHY_STOPSTADATA_1_1_Val << CSI_PHY_STOPSTATE_PHY_STOPSTADATA_1_Pos) /* (CSI_PHY_STOPSTATE) Lane 1 module has entered Stop state. Position  */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_2_Pos _UINT32_(2)                                          /* (CSI_PHY_STOPSTATE) Data Lane 2 Stop State Status Position */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_2_Msk (_UINT32_(0x1) << CSI_PHY_STOPSTATE_PHY_STOPSTADATA_2_Pos) /* (CSI_PHY_STOPSTATE) Data Lane 2 Stop State Status Mask */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_2(value) (CSI_PHY_STOPSTATE_PHY_STOPSTADATA_2_Msk & (_UINT32_(value) << CSI_PHY_STOPSTATE_PHY_STOPSTADATA_2_Pos)) /* Assigment of value for PHY_STOPSTADATA_2 in the CSI_PHY_STOPSTATE register */
#define   CSI_PHY_STOPSTATE_PHY_STOPSTADATA_2_0_Val _UINT32_(0x0)                                        /* (CSI_PHY_STOPSTATE) Data lane 2 module is not in Stop state.  */
#define   CSI_PHY_STOPSTATE_PHY_STOPSTADATA_2_1_Val _UINT32_(0x1)                                        /* (CSI_PHY_STOPSTATE) Data lane 2 module has entered Stop state.  */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_2_0 (CSI_PHY_STOPSTATE_PHY_STOPSTADATA_2_0_Val << CSI_PHY_STOPSTATE_PHY_STOPSTADATA_2_Pos) /* (CSI_PHY_STOPSTATE) Data lane 2 module is not in Stop state. Position  */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_2_1 (CSI_PHY_STOPSTATE_PHY_STOPSTADATA_2_1_Val << CSI_PHY_STOPSTATE_PHY_STOPSTADATA_2_Pos) /* (CSI_PHY_STOPSTATE) Data lane 2 module has entered Stop state. Position  */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_3_Pos _UINT32_(3)                                          /* (CSI_PHY_STOPSTATE) Data Lane 3 Stop State Status Position */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_3_Msk (_UINT32_(0x1) << CSI_PHY_STOPSTATE_PHY_STOPSTADATA_3_Pos) /* (CSI_PHY_STOPSTATE) Data Lane 3 Stop State Status Mask */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_3(value) (CSI_PHY_STOPSTATE_PHY_STOPSTADATA_3_Msk & (_UINT32_(value) << CSI_PHY_STOPSTATE_PHY_STOPSTADATA_3_Pos)) /* Assigment of value for PHY_STOPSTADATA_3 in the CSI_PHY_STOPSTATE register */
#define   CSI_PHY_STOPSTATE_PHY_STOPSTADATA_3_0_Val _UINT32_(0x0)                                        /* (CSI_PHY_STOPSTATE) Data lane 3 module is not in Stop state.  */
#define   CSI_PHY_STOPSTATE_PHY_STOPSTADATA_3_1_Val _UINT32_(0x1)                                        /* (CSI_PHY_STOPSTATE) Data lane 3 module has entered Stop state.  */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_3_0 (CSI_PHY_STOPSTATE_PHY_STOPSTADATA_3_0_Val << CSI_PHY_STOPSTATE_PHY_STOPSTADATA_3_Pos) /* (CSI_PHY_STOPSTATE) Data lane 3 module is not in Stop state. Position  */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_3_1 (CSI_PHY_STOPSTATE_PHY_STOPSTADATA_3_1_Val << CSI_PHY_STOPSTATE_PHY_STOPSTADATA_3_Pos) /* (CSI_PHY_STOPSTATE) Data lane 3 module has entered Stop state. Position  */
#define CSI_PHY_STOPSTATE_PHY_STOPSTATECLK_Pos _UINT32_(16)                                         /* (CSI_PHY_STOPSTATE) Clock Lane Stop State Status Position */
#define CSI_PHY_STOPSTATE_PHY_STOPSTATECLK_Msk (_UINT32_(0x1) << CSI_PHY_STOPSTATE_PHY_STOPSTATECLK_Pos) /* (CSI_PHY_STOPSTATE) Clock Lane Stop State Status Mask */
#define CSI_PHY_STOPSTATE_PHY_STOPSTATECLK(value) (CSI_PHY_STOPSTATE_PHY_STOPSTATECLK_Msk & (_UINT32_(value) << CSI_PHY_STOPSTATE_PHY_STOPSTATECLK_Pos)) /* Assigment of value for PHY_STOPSTATECLK in the CSI_PHY_STOPSTATE register */
#define   CSI_PHY_STOPSTATE_PHY_STOPSTATECLK_0_Val _UINT32_(0x0)                                        /* (CSI_PHY_STOPSTATE) Clock lane module is not in Stop state.  */
#define   CSI_PHY_STOPSTATE_PHY_STOPSTATECLK_1_Val _UINT32_(0x1)                                        /* (CSI_PHY_STOPSTATE) Clock lane module is in Stop state.  */
#define CSI_PHY_STOPSTATE_PHY_STOPSTATECLK_0  (CSI_PHY_STOPSTATE_PHY_STOPSTATECLK_0_Val << CSI_PHY_STOPSTATE_PHY_STOPSTATECLK_Pos) /* (CSI_PHY_STOPSTATE) Clock lane module is not in Stop state. Position  */
#define CSI_PHY_STOPSTATE_PHY_STOPSTATECLK_1  (CSI_PHY_STOPSTATE_PHY_STOPSTATECLK_1_Val << CSI_PHY_STOPSTATE_PHY_STOPSTATECLK_Pos) /* (CSI_PHY_STOPSTATE) Clock lane module is in Stop state. Position  */
#define CSI_PHY_STOPSTATE_Msk                 _UINT32_(0x0001000F)                                 /* (CSI_PHY_STOPSTATE) Register Mask  */

#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA__Pos _UINT32_(0)                                          /* (CSI_PHY_STOPSTATE Position) Data Lane x Stop State Status */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA__Msk (_UINT32_(0xF) << CSI_PHY_STOPSTATE_PHY_STOPSTADATA__Pos) /* (CSI_PHY_STOPSTATE Mask) PHY_STOPSTADATA_ */
#define CSI_PHY_STOPSTATE_PHY_STOPSTADATA_(value) (CSI_PHY_STOPSTATE_PHY_STOPSTADATA__Msk & (_UINT32_(value) << CSI_PHY_STOPSTATE_PHY_STOPSTADATA__Pos)) 

/* -------- CSI_PHY_TEST_CTRL0 : (CSI Offset: 0x50) (R/W 32) CSI D-PHY Analog Configuration Control Register -------- */
#define CSI_PHY_TEST_CTRL0_RESETVALUE         _UINT32_(0x01)                                       /*  (CSI_PHY_TEST_CTRL0) CSI D-PHY Analog Configuration Control Register  Reset Value */

#define CSI_PHY_TEST_CTRL0_PHY_TESTCLR_Pos    _UINT32_(0)                                          /* (CSI_PHY_TEST_CTRL0) Analog Configuration Clear Position */
#define CSI_PHY_TEST_CTRL0_PHY_TESTCLR_Msk    (_UINT32_(0x1) << CSI_PHY_TEST_CTRL0_PHY_TESTCLR_Pos) /* (CSI_PHY_TEST_CTRL0) Analog Configuration Clear Mask */
#define CSI_PHY_TEST_CTRL0_PHY_TESTCLR(value) (CSI_PHY_TEST_CTRL0_PHY_TESTCLR_Msk & (_UINT32_(value) << CSI_PHY_TEST_CTRL0_PHY_TESTCLR_Pos)) /* Assigment of value for PHY_TESTCLR in the CSI_PHY_TEST_CTRL0 register */
#define   CSI_PHY_TEST_CTRL0_PHY_TESTCLR_0_Val _UINT32_(0x0)                                        /* (CSI_PHY_TEST_CTRL0) No effect.  */
#define   CSI_PHY_TEST_CTRL0_PHY_TESTCLR_1_Val _UINT32_(0x1)                                        /* (CSI_PHY_TEST_CTRL0) Resets the analog configuration.  */
#define CSI_PHY_TEST_CTRL0_PHY_TESTCLR_0      (CSI_PHY_TEST_CTRL0_PHY_TESTCLR_0_Val << CSI_PHY_TEST_CTRL0_PHY_TESTCLR_Pos) /* (CSI_PHY_TEST_CTRL0) No effect. Position  */
#define CSI_PHY_TEST_CTRL0_PHY_TESTCLR_1      (CSI_PHY_TEST_CTRL0_PHY_TESTCLR_1_Val << CSI_PHY_TEST_CTRL0_PHY_TESTCLR_Pos) /* (CSI_PHY_TEST_CTRL0) Resets the analog configuration. Position  */
#define CSI_PHY_TEST_CTRL0_PHY_TESTCLK_Pos    _UINT32_(1)                                          /* (CSI_PHY_TEST_CTRL0) Analog Configuration Control Clock Position */
#define CSI_PHY_TEST_CTRL0_PHY_TESTCLK_Msk    (_UINT32_(0x1) << CSI_PHY_TEST_CTRL0_PHY_TESTCLK_Pos) /* (CSI_PHY_TEST_CTRL0) Analog Configuration Control Clock Mask */
#define CSI_PHY_TEST_CTRL0_PHY_TESTCLK(value) (CSI_PHY_TEST_CTRL0_PHY_TESTCLK_Msk & (_UINT32_(value) << CSI_PHY_TEST_CTRL0_PHY_TESTCLK_Pos)) /* Assigment of value for PHY_TESTCLK in the CSI_PHY_TEST_CTRL0 register */
#define   CSI_PHY_TEST_CTRL0_PHY_TESTCLK_0_Val _UINT32_(0x0)                                        /* (CSI_PHY_TEST_CTRL0) No effect.  */
#define   CSI_PHY_TEST_CTRL0_PHY_TESTCLK_1_Val _UINT32_(0x1)                                        /* (CSI_PHY_TEST_CTRL0) Captures the PHY_TEST_CTRL1.PHY_TESTDIN value.  */
#define CSI_PHY_TEST_CTRL0_PHY_TESTCLK_0      (CSI_PHY_TEST_CTRL0_PHY_TESTCLK_0_Val << CSI_PHY_TEST_CTRL0_PHY_TESTCLK_Pos) /* (CSI_PHY_TEST_CTRL0) No effect. Position  */
#define CSI_PHY_TEST_CTRL0_PHY_TESTCLK_1      (CSI_PHY_TEST_CTRL0_PHY_TESTCLK_1_Val << CSI_PHY_TEST_CTRL0_PHY_TESTCLK_Pos) /* (CSI_PHY_TEST_CTRL0) Captures the PHY_TEST_CTRL1.PHY_TESTDIN value. Position  */
#define CSI_PHY_TEST_CTRL0_Msk                _UINT32_(0x00000003)                                 /* (CSI_PHY_TEST_CTRL0) Register Mask  */


/* -------- CSI_PHY_TEST_CTRL1 : (CSI Offset: 0x54) (R/W 32) CSI D-PHY Analog Configuration Data Register -------- */
#define CSI_PHY_TEST_CTRL1_RESETVALUE         _UINT32_(0x00)                                       /*  (CSI_PHY_TEST_CTRL1) CSI D-PHY Analog Configuration Data Register  Reset Value */

#define CSI_PHY_TEST_CTRL1_PHY_TESTDIN_Pos    _UINT32_(0)                                          /* (CSI_PHY_TEST_CTRL1) Analog Configuration Value or High-Speed Bit Rate Code Position */
#define CSI_PHY_TEST_CTRL1_PHY_TESTDIN_Msk    (_UINT32_(0xFF) << CSI_PHY_TEST_CTRL1_PHY_TESTDIN_Pos) /* (CSI_PHY_TEST_CTRL1) Analog Configuration Value or High-Speed Bit Rate Code Mask */
#define CSI_PHY_TEST_CTRL1_PHY_TESTDIN(value) (CSI_PHY_TEST_CTRL1_PHY_TESTDIN_Msk & (_UINT32_(value) << CSI_PHY_TEST_CTRL1_PHY_TESTDIN_Pos)) /* Assigment of value for PHY_TESTDIN in the CSI_PHY_TEST_CTRL1 register */
#define CSI_PHY_TEST_CTRL1_PHY_TESTDOUT_Pos   _UINT32_(8)                                          /* (CSI_PHY_TEST_CTRL1) Read Data Output for Test Position */
#define CSI_PHY_TEST_CTRL1_PHY_TESTDOUT_Msk   (_UINT32_(0xFF) << CSI_PHY_TEST_CTRL1_PHY_TESTDOUT_Pos) /* (CSI_PHY_TEST_CTRL1) Read Data Output for Test Mask */
#define CSI_PHY_TEST_CTRL1_PHY_TESTDOUT(value) (CSI_PHY_TEST_CTRL1_PHY_TESTDOUT_Msk & (_UINT32_(value) << CSI_PHY_TEST_CTRL1_PHY_TESTDOUT_Pos)) /* Assigment of value for PHY_TESTDOUT in the CSI_PHY_TEST_CTRL1 register */
#define CSI_PHY_TEST_CTRL1_PHY_TESTEN_Pos     _UINT32_(16)                                         /* (CSI_PHY_TEST_CTRL1) Analog Configuration Code Selection Position */
#define CSI_PHY_TEST_CTRL1_PHY_TESTEN_Msk     (_UINT32_(0x1) << CSI_PHY_TEST_CTRL1_PHY_TESTEN_Pos) /* (CSI_PHY_TEST_CTRL1) Analog Configuration Code Selection Mask */
#define CSI_PHY_TEST_CTRL1_PHY_TESTEN(value)  (CSI_PHY_TEST_CTRL1_PHY_TESTEN_Msk & (_UINT32_(value) << CSI_PHY_TEST_CTRL1_PHY_TESTEN_Pos)) /* Assigment of value for PHY_TESTEN in the CSI_PHY_TEST_CTRL1 register */
#define   CSI_PHY_TEST_CTRL1_PHY_TESTEN_0_Val _UINT32_(0x0)                                        /* (CSI_PHY_TEST_CTRL1) Transmits the high-speed bit rate code on the rising edge of CSI_PHY_TEST_CTRL0.PHY_TESTCLK.  */
#define   CSI_PHY_TEST_CTRL1_PHY_TESTEN_1_Val _UINT32_(0x1)                                        /* (CSI_PHY_TEST_CTRL1) Transmits the address (0x44) of the high-speed bit rate code on the falling edge of CSI_PHY_TEST_CTRL0.PHY_TESTCLK  */
#define CSI_PHY_TEST_CTRL1_PHY_TESTEN_0       (CSI_PHY_TEST_CTRL1_PHY_TESTEN_0_Val << CSI_PHY_TEST_CTRL1_PHY_TESTEN_Pos) /* (CSI_PHY_TEST_CTRL1) Transmits the high-speed bit rate code on the rising edge of CSI_PHY_TEST_CTRL0.PHY_TESTCLK. Position  */
#define CSI_PHY_TEST_CTRL1_PHY_TESTEN_1       (CSI_PHY_TEST_CTRL1_PHY_TESTEN_1_Val << CSI_PHY_TEST_CTRL1_PHY_TESTEN_Pos) /* (CSI_PHY_TEST_CTRL1) Transmits the address (0x44) of the high-speed bit rate code on the falling edge of CSI_PHY_TEST_CTRL0.PHY_TESTCLK Position  */
#define CSI_PHY_TEST_CTRL1_Msk                _UINT32_(0x0001FFFF)                                 /* (CSI_PHY_TEST_CTRL1) Register Mask  */


/* -------- CSI_PHY_CAL : (CSI Offset: 0xCC) ( R/ 32) CSI D-PHY Calibration Status Register -------- */
#define CSI_PHY_CAL_RESETVALUE                _UINT32_(0x00)                                       /*  (CSI_PHY_CAL) CSI D-PHY Calibration Status Register  Reset Value */

#define CSI_PHY_CAL_RXSKEWCALHS_Pos           _UINT32_(0)                                          /* (CSI_PHY_CAL) Calibration Status (cleared on read) Position */
#define CSI_PHY_CAL_RXSKEWCALHS_Msk           (_UINT32_(0x1) << CSI_PHY_CAL_RXSKEWCALHS_Pos)       /* (CSI_PHY_CAL) Calibration Status (cleared on read) Mask */
#define CSI_PHY_CAL_RXSKEWCALHS(value)        (CSI_PHY_CAL_RXSKEWCALHS_Msk & (_UINT32_(value) << CSI_PHY_CAL_RXSKEWCALHS_Pos)) /* Assigment of value for RXSKEWCALHS in the CSI_PHY_CAL register */
#define   CSI_PHY_CAL_RXSKEWCALHS_0_Val       _UINT32_(0x0)                                        /* (CSI_PHY_CAL) No calibration initiated since the last CSI_PHY_CAL read.  */
#define   CSI_PHY_CAL_RXSKEWCALHS_1_Val       _UINT32_(0x1)                                        /* (CSI_PHY_CAL) A calibration has been initiated since the last CSI_PHY_CAL read.  */
#define CSI_PHY_CAL_RXSKEWCALHS_0             (CSI_PHY_CAL_RXSKEWCALHS_0_Val << CSI_PHY_CAL_RXSKEWCALHS_Pos) /* (CSI_PHY_CAL) No calibration initiated since the last CSI_PHY_CAL read. Position  */
#define CSI_PHY_CAL_RXSKEWCALHS_1             (CSI_PHY_CAL_RXSKEWCALHS_1_Val << CSI_PHY_CAL_RXSKEWCALHS_Pos) /* (CSI_PHY_CAL) A calibration has been initiated since the last CSI_PHY_CAL read. Position  */
#define CSI_PHY_CAL_Msk                       _UINT32_(0x00000001)                                 /* (CSI_PHY_CAL) Register Mask  */


/* -------- CSI_INT_ST_PHY_FATAL : (CSI Offset: 0xE0) ( R/ 32) CSI D-PHY Fatal Error Interrupt Status Register -------- */
#define CSI_INT_ST_PHY_FATAL_RESETVALUE       _UINT32_(0x01)                                       /*  (CSI_INT_ST_PHY_FATAL) CSI D-PHY Fatal Error Interrupt Status Register  Reset Value */

#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0_Pos _UINT32_(0)                                          /* (CSI_INT_ST_PHY_FATAL) Data Lane 0 Start Of Transmission Error Status (cleared on read) Position */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0_Msk (_UINT32_(0x1) << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0_Pos) /* (CSI_INT_ST_PHY_FATAL) Data Lane 0 Start Of Transmission Error Status (cleared on read) Mask */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0(value) (CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0_Msk & (_UINT32_(value) << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0_Pos)) /* Assigment of value for PHY_ERRSOTSYNCHS_0 in the CSI_INT_ST_PHY_FATAL register */
#define   CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0_0_Val _UINT32_(0x0)                                        /* (CSI_INT_ST_PHY_FATAL) No transmission error has occurred on data lane 0 since the last read of CSI_INT_ST_PHY_FATAL.  */
#define   CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0_1_Val _UINT32_(0x1)                                        /* (CSI_INT_ST_PHY_FATAL) Transmission error has occurred on data lane 0 since the last read of CSI_INT_ST_PHY_FATAL.  */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0_0 (CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0_0_Val << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0_Pos) /* (CSI_INT_ST_PHY_FATAL) No transmission error has occurred on data lane 0 since the last read of CSI_INT_ST_PHY_FATAL. Position  */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0_1 (CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0_1_Val << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0_Pos) /* (CSI_INT_ST_PHY_FATAL) Transmission error has occurred on data lane 0 since the last read of CSI_INT_ST_PHY_FATAL. Position  */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1_Pos _UINT32_(1)                                          /* (CSI_INT_ST_PHY_FATAL) Data Lane 1 Start Of Transmission Error Status (cleared on read) Position */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1_Msk (_UINT32_(0x1) << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1_Pos) /* (CSI_INT_ST_PHY_FATAL) Data Lane 1 Start Of Transmission Error Status (cleared on read) Mask */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1(value) (CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1_Msk & (_UINT32_(value) << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1_Pos)) /* Assigment of value for PHY_ERRSOTSYNCHS_1 in the CSI_INT_ST_PHY_FATAL register */
#define   CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1_0_Val _UINT32_(0x0)                                        /* (CSI_INT_ST_PHY_FATAL) No transmission error has occurred on data lane 1 since the last read of CSI_INT_ST_PHY_FATAL.  */
#define   CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1_1_Val _UINT32_(0x1)                                        /* (CSI_INT_ST_PHY_FATAL) Transmission error has occurred on data lane 1 since the last read of CSI_INT_ST_PHY_FATAL.  */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1_0 (CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1_0_Val << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1_Pos) /* (CSI_INT_ST_PHY_FATAL) No transmission error has occurred on data lane 1 since the last read of CSI_INT_ST_PHY_FATAL. Position  */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1_1 (CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1_1_Val << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1_Pos) /* (CSI_INT_ST_PHY_FATAL) Transmission error has occurred on data lane 1 since the last read of CSI_INT_ST_PHY_FATAL. Position  */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_2_Pos _UINT32_(2)                                          /* (CSI_INT_ST_PHY_FATAL) Data Lane 2 Start Of Transmission Error Status (cleared on read) Position */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_2_Msk (_UINT32_(0x1) << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_2_Pos) /* (CSI_INT_ST_PHY_FATAL) Data Lane 2 Start Of Transmission Error Status (cleared on read) Mask */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_2(value) (CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_2_Msk & (_UINT32_(value) << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_2_Pos)) /* Assigment of value for PHY_ERRSOTSYNCHS_2 in the CSI_INT_ST_PHY_FATAL register */
#define   CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_2_0_Val _UINT32_(0x0)                                        /* (CSI_INT_ST_PHY_FATAL) No transmission error has occurred on data lane 2 since the last read of CSI_INT_ST_PHY_FATAL.  */
#define   CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_2_1_Val _UINT32_(0x1)                                        /* (CSI_INT_ST_PHY_FATAL) Transmission error has occurred on data lane 2 since the last read of CSI_INT_ST_PHY_FATAL.  */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_2_0 (CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_2_0_Val << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_2_Pos) /* (CSI_INT_ST_PHY_FATAL) No transmission error has occurred on data lane 2 since the last read of CSI_INT_ST_PHY_FATAL. Position  */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_2_1 (CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_2_1_Val << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_2_Pos) /* (CSI_INT_ST_PHY_FATAL) Transmission error has occurred on data lane 2 since the last read of CSI_INT_ST_PHY_FATAL. Position  */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_3_Pos _UINT32_(3)                                          /* (CSI_INT_ST_PHY_FATAL) Lane 3 Start Of Transmission Error Status (cleared on read) Position */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_3_Msk (_UINT32_(0x1) << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_3_Pos) /* (CSI_INT_ST_PHY_FATAL) Lane 3 Start Of Transmission Error Status (cleared on read) Mask */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_3(value) (CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_3_Msk & (_UINT32_(value) << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_3_Pos)) /* Assigment of value for PHY_ERRSOTSYNCHS_3 in the CSI_INT_ST_PHY_FATAL register */
#define   CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_3_0_Val _UINT32_(0x0)                                        /* (CSI_INT_ST_PHY_FATAL) No transmission error has occurred on data lane 3 since the last read of CSI_INT_ST_PHY_FATAL.  */
#define   CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_3_1_Val _UINT32_(0x1)                                        /* (CSI_INT_ST_PHY_FATAL) Transmission error has occurred on data lane 3 since the last read of CSI_INT_ST_PHY_FATAL.  */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_3_0 (CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_3_0_Val << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_3_Pos) /* (CSI_INT_ST_PHY_FATAL) No transmission error has occurred on data lane 3 since the last read of CSI_INT_ST_PHY_FATAL. Position  */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_3_1 (CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_3_1_Val << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_3_Pos) /* (CSI_INT_ST_PHY_FATAL) Transmission error has occurred on data lane 3 since the last read of CSI_INT_ST_PHY_FATAL. Position  */
#define CSI_INT_ST_PHY_FATAL_Msk              _UINT32_(0x0000000F)                                 /* (CSI_INT_ST_PHY_FATAL) Register Mask  */

#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS__Pos _UINT32_(0)                                          /* (CSI_INT_ST_PHY_FATAL Position) Lane 3 Start Of Transmission Error Status (cleared on read) */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS__Msk (_UINT32_(0xF) << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS__Pos) /* (CSI_INT_ST_PHY_FATAL Mask) PHY_ERRSOTSYNCHS_ */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_(value) (CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS__Msk & (_UINT32_(value) << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS__Pos)) 

/* -------- CSI_INT_MSK_PHY_FATAL : (CSI Offset: 0xE4) (R/W 32) CSI D-PHY Fatal Error Interrupt Mask Register -------- */
#define CSI_INT_MSK_PHY_FATAL_RESETVALUE      _UINT32_(0x00)                                       /*  (CSI_INT_MSK_PHY_FATAL) CSI D-PHY Fatal Error Interrupt Mask Register  Reset Value */

#define CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_0_Pos _UINT32_(0)                                          /* (CSI_INT_MSK_PHY_FATAL) Data Lane 0 Start Of Transmission Error Interrupt Mask Position */
#define CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_0_Msk (_UINT32_(0x1) << CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_0_Pos) /* (CSI_INT_MSK_PHY_FATAL) Data Lane 0 Start Of Transmission Error Interrupt Mask Mask */
#define CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_0(value) (CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_0_Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_0_Pos)) /* Assigment of value for MASK_ERRSOTSYNCHS_0 in the CSI_INT_MSK_PHY_FATAL register */
#define CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_1_Pos _UINT32_(1)                                          /* (CSI_INT_MSK_PHY_FATAL) Data Lane 1 Start Of Transmission Error Interrupt Mask Position */
#define CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_1_Msk (_UINT32_(0x1) << CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_1_Pos) /* (CSI_INT_MSK_PHY_FATAL) Data Lane 1 Start Of Transmission Error Interrupt Mask Mask */
#define CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_1(value) (CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_1_Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_1_Pos)) /* Assigment of value for MASK_ERRSOTSYNCHS_1 in the CSI_INT_MSK_PHY_FATAL register */
#define CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_2_Pos _UINT32_(2)                                          /* (CSI_INT_MSK_PHY_FATAL) Data Lane 2 Start Of Transmission Error Interrupt Mask Position */
#define CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_2_Msk (_UINT32_(0x1) << CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_2_Pos) /* (CSI_INT_MSK_PHY_FATAL) Data Lane 2 Start Of Transmission Error Interrupt Mask Mask */
#define CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_2(value) (CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_2_Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_2_Pos)) /* Assigment of value for MASK_ERRSOTSYNCHS_2 in the CSI_INT_MSK_PHY_FATAL register */
#define CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_3_Pos _UINT32_(3)                                          /* (CSI_INT_MSK_PHY_FATAL) Lane 3 Start Of Transmission Error Error Interrupt Mask Position */
#define CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_3_Msk (_UINT32_(0x1) << CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_3_Pos) /* (CSI_INT_MSK_PHY_FATAL) Lane 3 Start Of Transmission Error Error Interrupt Mask Mask */
#define CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_3(value) (CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_3_Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_3_Pos)) /* Assigment of value for MASK_ERRSOTSYNCHS_3 in the CSI_INT_MSK_PHY_FATAL register */
#define CSI_INT_MSK_PHY_FATAL_Msk             _UINT32_(0x0000000F)                                 /* (CSI_INT_MSK_PHY_FATAL) Register Mask  */

#define CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS__Pos _UINT32_(0)                                          /* (CSI_INT_MSK_PHY_FATAL Position) Lane 3 Start Of Transmission Error Error Interrupt Mask */
#define CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS__Msk (_UINT32_(0xF) << CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS__Pos) /* (CSI_INT_MSK_PHY_FATAL Mask) MASK_ERRSOTSYNCHS_ */
#define CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS_(value) (CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS__Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_FATAL_MASK_ERRSOTSYNCHS__Pos)) 

/* -------- CSI_INT_FORCE_PHY_FATAL : (CSI Offset: 0xE8) (R/W 32) CSI D-PHY Fatal Error Interrupt Force Register -------- */
#define CSI_INT_FORCE_PHY_FATAL_RESETVALUE    _UINT32_(0x00)                                       /*  (CSI_INT_FORCE_PHY_FATAL) CSI D-PHY Fatal Error Interrupt Force Register  Reset Value */

#define CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_0_Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_PHY_FATAL) Force Start Of Transmission Interrupt Error on Data Lane 0 Position */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_0_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_0_Pos) /* (CSI_INT_FORCE_PHY_FATAL) Force Start Of Transmission Interrupt Error on Data Lane 0 Mask */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_0(value) (CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_0_Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_0_Pos)) /* Assigment of value for FORCE_ERRSOTSYNCHS_0 in the CSI_INT_FORCE_PHY_FATAL register */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_1_Pos _UINT32_(1)                                          /* (CSI_INT_FORCE_PHY_FATAL) Force Start Of Transmission Interrupt Error on Data Lane 1 Position */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_1_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_1_Pos) /* (CSI_INT_FORCE_PHY_FATAL) Force Start Of Transmission Interrupt Error on Data Lane 1 Mask */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_1(value) (CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_1_Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_1_Pos)) /* Assigment of value for FORCE_ERRSOTSYNCHS_1 in the CSI_INT_FORCE_PHY_FATAL register */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_2_Pos _UINT32_(2)                                          /* (CSI_INT_FORCE_PHY_FATAL) Force Start Of Transmission Interrupt Error on Data Lane 2 Position */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_2_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_2_Pos) /* (CSI_INT_FORCE_PHY_FATAL) Force Start Of Transmission Interrupt Error on Data Lane 2 Mask */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_2(value) (CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_2_Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_2_Pos)) /* Assigment of value for FORCE_ERRSOTSYNCHS_2 in the CSI_INT_FORCE_PHY_FATAL register */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_3_Pos _UINT32_(3)                                          /* (CSI_INT_FORCE_PHY_FATAL) Force Start Of Transmission Interrupt Error on Data Lane 3 Position */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_3_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_3_Pos) /* (CSI_INT_FORCE_PHY_FATAL) Force Start Of Transmission Interrupt Error on Data Lane 3 Mask */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_3(value) (CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_3_Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_3_Pos)) /* Assigment of value for FORCE_ERRSOTSYNCHS_3 in the CSI_INT_FORCE_PHY_FATAL register */
#define CSI_INT_FORCE_PHY_FATAL_Msk           _UINT32_(0x0000000F)                                 /* (CSI_INT_FORCE_PHY_FATAL) Register Mask  */

#define CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS__Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_PHY_FATAL Position) Force Start Of Transmission Interrupt Error on Data Lane 3 */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS__Msk (_UINT32_(0xF) << CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS__Pos) /* (CSI_INT_FORCE_PHY_FATAL Mask) FORCE_ERRSOTSYNCHS_ */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS_(value) (CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS__Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FATAL_FORCE_ERRSOTSYNCHS__Pos)) 

/* -------- CSI_INT_ST_PKT_FATAL : (CSI Offset: 0xF0) ( R/ 32) CSI Packet Fatal Error Interrupt Force Register -------- */
#define CSI_INT_ST_PKT_FATAL_RESETVALUE       _UINT32_(0x00)                                       /*  (CSI_INT_ST_PKT_FATAL) CSI Packet Fatal Error Interrupt Force Register  Reset Value */

#define CSI_INT_ST_PKT_FATAL_VC0_ERR_CRC_Pos  _UINT32_(0)                                          /* (CSI_INT_ST_PKT_FATAL) Virtual Channel 0 Payload Checksum Error (cleared on read) Position */
#define CSI_INT_ST_PKT_FATAL_VC0_ERR_CRC_Msk  (_UINT32_(0x1) << CSI_INT_ST_PKT_FATAL_VC0_ERR_CRC_Pos) /* (CSI_INT_ST_PKT_FATAL) Virtual Channel 0 Payload Checksum Error (cleared on read) Mask */
#define CSI_INT_ST_PKT_FATAL_VC0_ERR_CRC(value) (CSI_INT_ST_PKT_FATAL_VC0_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_FATAL_VC0_ERR_CRC_Pos)) /* Assigment of value for VC0_ERR_CRC in the CSI_INT_ST_PKT_FATAL register */
#define CSI_INT_ST_PKT_FATAL_VC1_ERR_CRC_Pos  _UINT32_(1)                                          /* (CSI_INT_ST_PKT_FATAL) Virtual Channel 1 Payload Checksum Error (cleared on read) Position */
#define CSI_INT_ST_PKT_FATAL_VC1_ERR_CRC_Msk  (_UINT32_(0x1) << CSI_INT_ST_PKT_FATAL_VC1_ERR_CRC_Pos) /* (CSI_INT_ST_PKT_FATAL) Virtual Channel 1 Payload Checksum Error (cleared on read) Mask */
#define CSI_INT_ST_PKT_FATAL_VC1_ERR_CRC(value) (CSI_INT_ST_PKT_FATAL_VC1_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_FATAL_VC1_ERR_CRC_Pos)) /* Assigment of value for VC1_ERR_CRC in the CSI_INT_ST_PKT_FATAL register */
#define CSI_INT_ST_PKT_FATAL_VC2_ERR_CRC_Pos  _UINT32_(2)                                          /* (CSI_INT_ST_PKT_FATAL) Virtual Channel 2 Payload Checksum Error (cleared on read) Position */
#define CSI_INT_ST_PKT_FATAL_VC2_ERR_CRC_Msk  (_UINT32_(0x1) << CSI_INT_ST_PKT_FATAL_VC2_ERR_CRC_Pos) /* (CSI_INT_ST_PKT_FATAL) Virtual Channel 2 Payload Checksum Error (cleared on read) Mask */
#define CSI_INT_ST_PKT_FATAL_VC2_ERR_CRC(value) (CSI_INT_ST_PKT_FATAL_VC2_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_FATAL_VC2_ERR_CRC_Pos)) /* Assigment of value for VC2_ERR_CRC in the CSI_INT_ST_PKT_FATAL register */
#define CSI_INT_ST_PKT_FATAL_VC3_ERR_CRC_Pos  _UINT32_(3)                                          /* (CSI_INT_ST_PKT_FATAL) Virtual Channel 3 Payload Checksum Error (cleared on read) Position */
#define CSI_INT_ST_PKT_FATAL_VC3_ERR_CRC_Msk  (_UINT32_(0x1) << CSI_INT_ST_PKT_FATAL_VC3_ERR_CRC_Pos) /* (CSI_INT_ST_PKT_FATAL) Virtual Channel 3 Payload Checksum Error (cleared on read) Mask */
#define CSI_INT_ST_PKT_FATAL_VC3_ERR_CRC(value) (CSI_INT_ST_PKT_FATAL_VC3_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_FATAL_VC3_ERR_CRC_Pos)) /* Assigment of value for VC3_ERR_CRC in the CSI_INT_ST_PKT_FATAL register */
#define CSI_INT_ST_PKT_FATAL_ERR_ECC_DOUBLE_Pos _UINT32_(16)                                         /* (CSI_INT_ST_PKT_FATAL) Unrecoverable Header Error, Two Errors ECC, (cleared on read). Position */
#define CSI_INT_ST_PKT_FATAL_ERR_ECC_DOUBLE_Msk (_UINT32_(0x1) << CSI_INT_ST_PKT_FATAL_ERR_ECC_DOUBLE_Pos) /* (CSI_INT_ST_PKT_FATAL) Unrecoverable Header Error, Two Errors ECC, (cleared on read). Mask */
#define CSI_INT_ST_PKT_FATAL_ERR_ECC_DOUBLE(value) (CSI_INT_ST_PKT_FATAL_ERR_ECC_DOUBLE_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_FATAL_ERR_ECC_DOUBLE_Pos)) /* Assigment of value for ERR_ECC_DOUBLE in the CSI_INT_ST_PKT_FATAL register */
#define CSI_INT_ST_PKT_FATAL_Msk              _UINT32_(0x0001000F)                                 /* (CSI_INT_ST_PKT_FATAL) Register Mask  */


/* -------- CSI_INT_MSK_PKT_FATAL : (CSI Offset: 0xF4) (R/W 32) CSI Packet Fatal Error Interrupt Force Register -------- */
#define CSI_INT_MSK_PKT_FATAL_RESETVALUE      _UINT32_(0x00)                                       /*  (CSI_INT_MSK_PKT_FATAL) CSI Packet Fatal Error Interrupt Force Register  Reset Value */

#define CSI_INT_MSK_PKT_FATAL_MASK_VC0_ERR_CRC_Pos _UINT32_(0)                                          /* (CSI_INT_MSK_PKT_FATAL) Virtual Channel 0 Payload Checksum Error Interrupt Mask Position */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC0_ERR_CRC_Msk (_UINT32_(0x1) << CSI_INT_MSK_PKT_FATAL_MASK_VC0_ERR_CRC_Pos) /* (CSI_INT_MSK_PKT_FATAL) Virtual Channel 0 Payload Checksum Error Interrupt Mask Mask */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC0_ERR_CRC(value) (CSI_INT_MSK_PKT_FATAL_MASK_VC0_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_FATAL_MASK_VC0_ERR_CRC_Pos)) /* Assigment of value for MASK_VC0_ERR_CRC in the CSI_INT_MSK_PKT_FATAL register */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC1_ERR_CRC_Pos _UINT32_(1)                                          /* (CSI_INT_MSK_PKT_FATAL) Virtual Channel 1 Payload Checksum Error Interrupt Mask Position */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC1_ERR_CRC_Msk (_UINT32_(0x1) << CSI_INT_MSK_PKT_FATAL_MASK_VC1_ERR_CRC_Pos) /* (CSI_INT_MSK_PKT_FATAL) Virtual Channel 1 Payload Checksum Error Interrupt Mask Mask */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC1_ERR_CRC(value) (CSI_INT_MSK_PKT_FATAL_MASK_VC1_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_FATAL_MASK_VC1_ERR_CRC_Pos)) /* Assigment of value for MASK_VC1_ERR_CRC in the CSI_INT_MSK_PKT_FATAL register */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC2_ERR_CRC_Pos _UINT32_(2)                                          /* (CSI_INT_MSK_PKT_FATAL) Virtual Channel 2 Payload Checksum Error Interrupt Mask Position */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC2_ERR_CRC_Msk (_UINT32_(0x1) << CSI_INT_MSK_PKT_FATAL_MASK_VC2_ERR_CRC_Pos) /* (CSI_INT_MSK_PKT_FATAL) Virtual Channel 2 Payload Checksum Error Interrupt Mask Mask */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC2_ERR_CRC(value) (CSI_INT_MSK_PKT_FATAL_MASK_VC2_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_FATAL_MASK_VC2_ERR_CRC_Pos)) /* Assigment of value for MASK_VC2_ERR_CRC in the CSI_INT_MSK_PKT_FATAL register */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC3_ERR_CRC_Pos _UINT32_(3)                                          /* (CSI_INT_MSK_PKT_FATAL) Virtual Channel 3 Payload Checksum Error Interrupt Mask Position */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC3_ERR_CRC_Msk (_UINT32_(0x1) << CSI_INT_MSK_PKT_FATAL_MASK_VC3_ERR_CRC_Pos) /* (CSI_INT_MSK_PKT_FATAL) Virtual Channel 3 Payload Checksum Error Interrupt Mask Mask */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC3_ERR_CRC(value) (CSI_INT_MSK_PKT_FATAL_MASK_VC3_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_FATAL_MASK_VC3_ERR_CRC_Pos)) /* Assigment of value for MASK_VC3_ERR_CRC in the CSI_INT_MSK_PKT_FATAL register */
#define CSI_INT_MSK_PKT_FATAL_MASK_ERR_ECC_DOUBLE_Pos _UINT32_(16)                                         /* (CSI_INT_MSK_PKT_FATAL) Unrecoverable Header Error (ECC Two Errors) Interrupt Mask Position */
#define CSI_INT_MSK_PKT_FATAL_MASK_ERR_ECC_DOUBLE_Msk (_UINT32_(0x1) << CSI_INT_MSK_PKT_FATAL_MASK_ERR_ECC_DOUBLE_Pos) /* (CSI_INT_MSK_PKT_FATAL) Unrecoverable Header Error (ECC Two Errors) Interrupt Mask Mask */
#define CSI_INT_MSK_PKT_FATAL_MASK_ERR_ECC_DOUBLE(value) (CSI_INT_MSK_PKT_FATAL_MASK_ERR_ECC_DOUBLE_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_FATAL_MASK_ERR_ECC_DOUBLE_Pos)) /* Assigment of value for MASK_ERR_ECC_DOUBLE in the CSI_INT_MSK_PKT_FATAL register */
#define CSI_INT_MSK_PKT_FATAL_Msk             _UINT32_(0x0001000F)                                 /* (CSI_INT_MSK_PKT_FATAL) Register Mask  */


/* -------- CSI_INT_FORCE_PKT_FATAL : (CSI Offset: 0xF8) (R/W 32) CSI Packet Fatal Error Interrupt Force Register -------- */
#define CSI_INT_FORCE_PKT_FATAL_RESETVALUE    _UINT32_(0x00)                                       /*  (CSI_INT_FORCE_PKT_FATAL) CSI Packet Fatal Error Interrupt Force Register  Reset Value */

#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC0_ERR_CRC_Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_PKT_FATAL) Force Virtual Channel 0 Payload Checksum Error Interrupt Position */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC0_ERR_CRC_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FATAL_FORCE_VC0_ERR_CRC_Pos) /* (CSI_INT_FORCE_PKT_FATAL) Force Virtual Channel 0 Payload Checksum Error Interrupt Mask */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC0_ERR_CRC(value) (CSI_INT_FORCE_PKT_FATAL_FORCE_VC0_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FATAL_FORCE_VC0_ERR_CRC_Pos)) /* Assigment of value for FORCE_VC0_ERR_CRC in the CSI_INT_FORCE_PKT_FATAL register */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC1_ERR_CRC_Pos _UINT32_(1)                                          /* (CSI_INT_FORCE_PKT_FATAL) Force Virtual Channel 1 Payload Checksum Error Interrupt Position */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC1_ERR_CRC_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FATAL_FORCE_VC1_ERR_CRC_Pos) /* (CSI_INT_FORCE_PKT_FATAL) Force Virtual Channel 1 Payload Checksum Error Interrupt Mask */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC1_ERR_CRC(value) (CSI_INT_FORCE_PKT_FATAL_FORCE_VC1_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FATAL_FORCE_VC1_ERR_CRC_Pos)) /* Assigment of value for FORCE_VC1_ERR_CRC in the CSI_INT_FORCE_PKT_FATAL register */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC2_ERR_CRC_Pos _UINT32_(2)                                          /* (CSI_INT_FORCE_PKT_FATAL) Force Virtual Channel 2 Payload Checksum Error Interrupt Position */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC2_ERR_CRC_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FATAL_FORCE_VC2_ERR_CRC_Pos) /* (CSI_INT_FORCE_PKT_FATAL) Force Virtual Channel 2 Payload Checksum Error Interrupt Mask */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC2_ERR_CRC(value) (CSI_INT_FORCE_PKT_FATAL_FORCE_VC2_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FATAL_FORCE_VC2_ERR_CRC_Pos)) /* Assigment of value for FORCE_VC2_ERR_CRC in the CSI_INT_FORCE_PKT_FATAL register */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC3_ERR_CRC_Pos _UINT32_(3)                                          /* (CSI_INT_FORCE_PKT_FATAL) Force Virtual Channel 3 Payload Checksum Error Interrupt Position */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC3_ERR_CRC_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FATAL_FORCE_VC3_ERR_CRC_Pos) /* (CSI_INT_FORCE_PKT_FATAL) Force Virtual Channel 3 Payload Checksum Error Interrupt Mask */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC3_ERR_CRC(value) (CSI_INT_FORCE_PKT_FATAL_FORCE_VC3_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FATAL_FORCE_VC3_ERR_CRC_Pos)) /* Assigment of value for FORCE_VC3_ERR_CRC in the CSI_INT_FORCE_PKT_FATAL register */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_ERR_ECC_DOUBLE_Pos _UINT32_(16)                                         /* (CSI_INT_FORCE_PKT_FATAL) Force Header ECC Double Error Interrupt Position */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_ERR_ECC_DOUBLE_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FATAL_FORCE_ERR_ECC_DOUBLE_Pos) /* (CSI_INT_FORCE_PKT_FATAL) Force Header ECC Double Error Interrupt Mask */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_ERR_ECC_DOUBLE(value) (CSI_INT_FORCE_PKT_FATAL_FORCE_ERR_ECC_DOUBLE_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FATAL_FORCE_ERR_ECC_DOUBLE_Pos)) /* Assigment of value for FORCE_ERR_ECC_DOUBLE in the CSI_INT_FORCE_PKT_FATAL register */
#define CSI_INT_FORCE_PKT_FATAL_Msk           _UINT32_(0x0001000F)                                 /* (CSI_INT_FORCE_PKT_FATAL) Register Mask  */


/* -------- CSI_INT_ST_FRAME_FATAL : (CSI Offset: 0x100) ( R/ 32) CSI Frame Fatal Error Interrupt Force Register -------- */
#define CSI_INT_ST_FRAME_FATAL_RESETVALUE     _UINT32_(0x00)                                       /*  (CSI_INT_ST_FRAME_FATAL) CSI Frame Fatal Error Interrupt Force Register  Reset Value */

#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC0_Pos _UINT32_(0)                                          /* (CSI_INT_ST_FRAME_FATAL) Error Matching Frame Start with Frame End for Virtual Channel 0 (cleared on read) Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC0_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC0_Pos) /* (CSI_INT_ST_FRAME_FATAL) Error Matching Frame Start with Frame End for Virtual Channel 0 (cleared on read) Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC0(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC0_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC0_Pos)) /* Assigment of value for ERR_F_BNDRY_MATCH_VC0 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC1_Pos _UINT32_(1)                                          /* (CSI_INT_ST_FRAME_FATAL) Error Matching Frame Start with Frame End for Virtual Channel 1 (cleared on read) Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC1_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC1_Pos) /* (CSI_INT_ST_FRAME_FATAL) Error Matching Frame Start with Frame End for Virtual Channel 1 (cleared on read) Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC1(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC1_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC1_Pos)) /* Assigment of value for ERR_F_BNDRY_MATCH_VC1 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC2_Pos _UINT32_(2)                                          /* (CSI_INT_ST_FRAME_FATAL) Error Matching Frame Start with Frame End for Virtual Channel 2 (cleared on read) Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC2_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC2_Pos) /* (CSI_INT_ST_FRAME_FATAL) Error Matching Frame Start with Frame End for Virtual Channel 2 (cleared on read) Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC2(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC2_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC2_Pos)) /* Assigment of value for ERR_F_BNDRY_MATCH_VC2 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC3_Pos _UINT32_(3)                                          /* (CSI_INT_ST_FRAME_FATAL) Error Matching Frame Start with Frame End for Virtual Channel 3 (cleared on read) Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC3_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC3_Pos) /* (CSI_INT_ST_FRAME_FATAL) Error Matching Frame Start with Frame End for Virtual Channel 3 (cleared on read) Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC3(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC3_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC3_Pos)) /* Assigment of value for ERR_F_BNDRY_MATCH_VC3 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC0_Pos _UINT32_(8)                                          /* (CSI_INT_ST_FRAME_FATAL) Incorrect Frame Sequence in Virtual Channel 0 (cleared on read) Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC0_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC0_Pos) /* (CSI_INT_ST_FRAME_FATAL) Incorrect Frame Sequence in Virtual Channel 0 (cleared on read) Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC0(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC0_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC0_Pos)) /* Assigment of value for ERR_F_SEQ_VC0 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC1_Pos _UINT32_(9)                                          /* (CSI_INT_ST_FRAME_FATAL) Incorrect Frame Sequence in Virtual Channel 1 (cleared on read) Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC1_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC1_Pos) /* (CSI_INT_ST_FRAME_FATAL) Incorrect Frame Sequence in Virtual Channel 1 (cleared on read) Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC1(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC1_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC1_Pos)) /* Assigment of value for ERR_F_SEQ_VC1 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC2_Pos _UINT32_(10)                                         /* (CSI_INT_ST_FRAME_FATAL) Incorrect Frame Sequence in Virtual Channel 2 (cleared on read) Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC2_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC2_Pos) /* (CSI_INT_ST_FRAME_FATAL) Incorrect Frame Sequence in Virtual Channel 2 (cleared on read) Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC2(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC2_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC2_Pos)) /* Assigment of value for ERR_F_SEQ_VC2 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC3_Pos _UINT32_(11)                                         /* (CSI_INT_ST_FRAME_FATAL) Incorrect Frame Sequence in Virtual Channel 3(cleared on read) Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC3_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC3_Pos) /* (CSI_INT_ST_FRAME_FATAL) Incorrect Frame Sequence in Virtual Channel 3(cleared on read) Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC3(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC3_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC3_Pos)) /* Assigment of value for ERR_F_SEQ_VC3 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC0_Pos _UINT32_(16)                                         /* (CSI_INT_ST_FRAME_FATAL) At Least One CRC Error in Last Received Frame of Virtual Channel 0 (cleared on read) Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC0_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC0_Pos) /* (CSI_INT_ST_FRAME_FATAL) At Least One CRC Error in Last Received Frame of Virtual Channel 0 (cleared on read) Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC0(value) (CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC0_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC0_Pos)) /* Assigment of value for ERR_FRAME_DATA_VC0 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC1_Pos _UINT32_(17)                                         /* (CSI_INT_ST_FRAME_FATAL) At Least One CRC Error in Last Received Frame of Virtual Channel 1 (cleared on read) Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC1_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC1_Pos) /* (CSI_INT_ST_FRAME_FATAL) At Least One CRC Error in Last Received Frame of Virtual Channel 1 (cleared on read) Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC1(value) (CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC1_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC1_Pos)) /* Assigment of value for ERR_FRAME_DATA_VC1 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC2_Pos _UINT32_(18)                                         /* (CSI_INT_ST_FRAME_FATAL) At Least One CRC Error in Last Received Frame of Virtual Channel 2 (cleared on read) Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC2_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC2_Pos) /* (CSI_INT_ST_FRAME_FATAL) At Least One CRC Error in Last Received Frame of Virtual Channel 2 (cleared on read) Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC2(value) (CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC2_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC2_Pos)) /* Assigment of value for ERR_FRAME_DATA_VC2 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC3_Pos _UINT32_(19)                                         /* (CSI_INT_ST_FRAME_FATAL) At Least One CRC Error in Last Received Frame of Virtual Channel 3 (cleared on read) Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC3_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC3_Pos) /* (CSI_INT_ST_FRAME_FATAL) At Least One CRC Error in Last Received Frame of Virtual Channel 3 (cleared on read) Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC3(value) (CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC3_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC3_Pos)) /* Assigment of value for ERR_FRAME_DATA_VC3 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_Msk            _UINT32_(0x000F0F0F)                                 /* (CSI_INT_ST_FRAME_FATAL) Register Mask  */

#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC_Pos _UINT32_(0)                                          /* (CSI_INT_ST_FRAME_FATAL Position) Error Matching Frame Start with Frame End for Virtual Channel x (cleared on read) */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC_Msk (_UINT32_(0xF) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC_Pos) /* (CSI_INT_ST_FRAME_FATAL Mask) ERR_F_BNDRY_MATCH_VC */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC_Pos)) 
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC_Pos _UINT32_(8)                                          /* (CSI_INT_ST_FRAME_FATAL Position) Incorrect Frame Sequence in Virtual Channel x (cleared on read) */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC_Msk (_UINT32_(0xF) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC_Pos) /* (CSI_INT_ST_FRAME_FATAL Mask) ERR_F_SEQ_VC */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC_Pos)) 
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC_Pos _UINT32_(16)                                         /* (CSI_INT_ST_FRAME_FATAL Position) At Least One CRC Error in Last Received Frame of Virtual Channel 3 (cleared on read) */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC_Msk (_UINT32_(0xF) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC_Pos) /* (CSI_INT_ST_FRAME_FATAL Mask) ERR_FRAME_DATA_VC */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC(value) (CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC_Pos)) 

/* -------- CSI_INT_MSK_FRAME_FATAL : (CSI Offset: 0x104) (R/W 32) CSI Frame Fatal Error Interrupt Force Register -------- */
#define CSI_INT_MSK_FRAME_FATAL_RESETVALUE    _UINT32_(0x00)                                       /*  (CSI_INT_MSK_FRAME_FATAL) CSI Frame Fatal Error Interrupt Force Register  Reset Value */

#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC0_Pos _UINT32_(0)                                          /* (CSI_INT_MSK_FRAME_FATAL) Virtual Channel 0 Error Matching Frame Start with Frame End Interrupt Mask Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC0_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC0_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Virtual Channel 0 Error Matching Frame Start with Frame End Interrupt Mask Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC0(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC0_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC0_Pos)) /* Assigment of value for MASK_ERR_F_BNDRY_MATCH_VC0 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC1_Pos _UINT32_(1)                                          /* (CSI_INT_MSK_FRAME_FATAL) Virtual Channel 1 Error Matching Frame Start with Frame End Interrupt Mask Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC1_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC1_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Virtual Channel 1 Error Matching Frame Start with Frame End Interrupt Mask Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC1(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC1_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC1_Pos)) /* Assigment of value for MASK_ERR_F_BNDRY_MATCH_VC1 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC2_Pos _UINT32_(2)                                          /* (CSI_INT_MSK_FRAME_FATAL) Virtual Channel 2 Error Matching Frame Start with Frame End Interrupt Mask Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC2_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC2_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Virtual Channel 2 Error Matching Frame Start with Frame End Interrupt Mask Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC2(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC2_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC2_Pos)) /* Assigment of value for MASK_ERR_F_BNDRY_MATCH_VC2 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC3_Pos _UINT32_(3)                                          /* (CSI_INT_MSK_FRAME_FATAL) Virtual Channel 3 Error Matching Frame Start with Frame End Interrupt Mask Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC3_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC3_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Virtual Channel 3 Error Matching Frame Start with Frame End Interrupt Mask Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC3(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC3_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC3_Pos)) /* Assigment of value for MASK_ERR_F_BNDRY_MATCH_VC3 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC0_Pos _UINT32_(8)                                          /* (CSI_INT_MSK_FRAME_FATAL) Incorrect Frame Sequence in Virtual Channel 0 Interrupt Mask Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC0_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC0_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Incorrect Frame Sequence in Virtual Channel 0 Interrupt Mask Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC0(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC0_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC0_Pos)) /* Assigment of value for MASK_ERR_F_SEQ_VC0 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC1_Pos _UINT32_(9)                                          /* (CSI_INT_MSK_FRAME_FATAL) Incorrect Frame Sequence in Virtual Channel 1 Interrupt Mask Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC1_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC1_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Incorrect Frame Sequence in Virtual Channel 1 Interrupt Mask Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC1(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC1_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC1_Pos)) /* Assigment of value for MASK_ERR_F_SEQ_VC1 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC2_Pos _UINT32_(10)                                         /* (CSI_INT_MSK_FRAME_FATAL) Incorrect Frame Sequence in Virtual Channel 2 Interrupt Mask Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC2_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC2_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Incorrect Frame Sequence in Virtual Channel 2 Interrupt Mask Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC2(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC2_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC2_Pos)) /* Assigment of value for MASK_ERR_F_SEQ_VC2 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC3_Pos _UINT32_(11)                                         /* (CSI_INT_MSK_FRAME_FATAL) Incorrect Frame Sequence in Virtual Channel 3 Interrupt Mask Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC3_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC3_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Incorrect Frame Sequence in Virtual Channel 3 Interrupt Mask Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC3(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC3_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC3_Pos)) /* Assigment of value for MASK_ERR_F_SEQ_VC3 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC0_Pos _UINT32_(16)                                         /* (CSI_INT_MSK_FRAME_FATAL) CRC Error in Last Received Frame of Virtual Channel 0 Interrupt Mask Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC0_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC0_Pos) /* (CSI_INT_MSK_FRAME_FATAL) CRC Error in Last Received Frame of Virtual Channel 0 Interrupt Mask Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC0(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC0_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC0_Pos)) /* Assigment of value for MASK_ERR_FRAME_DATA_VC0 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC1_Pos _UINT32_(17)                                         /* (CSI_INT_MSK_FRAME_FATAL) CRC Error in Last Received Frame of Virtual Channel 1 Interrupt Mask Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC1_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC1_Pos) /* (CSI_INT_MSK_FRAME_FATAL) CRC Error in Last Received Frame of Virtual Channel 1 Interrupt Mask Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC1(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC1_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC1_Pos)) /* Assigment of value for MASK_ERR_FRAME_DATA_VC1 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC2_Pos _UINT32_(18)                                         /* (CSI_INT_MSK_FRAME_FATAL) CRC Error in Last Received Frame of Virtual Channel 2 Interrupt Mask Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC2_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC2_Pos) /* (CSI_INT_MSK_FRAME_FATAL) CRC Error in Last Received Frame of Virtual Channel 2 Interrupt Mask Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC2(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC2_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC2_Pos)) /* Assigment of value for MASK_ERR_FRAME_DATA_VC2 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC3_Pos _UINT32_(19)                                         /* (CSI_INT_MSK_FRAME_FATAL) CRC Error in Last Received Frame of Virtual Channel 3 Interrupt Mask Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC3_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC3_Pos) /* (CSI_INT_MSK_FRAME_FATAL) CRC Error in Last Received Frame of Virtual Channel 3 Interrupt Mask Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC3(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC3_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC3_Pos)) /* Assigment of value for MASK_ERR_FRAME_DATA_VC3 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_Msk           _UINT32_(0x000F0F0F)                                 /* (CSI_INT_MSK_FRAME_FATAL) Register Mask  */

#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC_Pos _UINT32_(0)                                          /* (CSI_INT_MSK_FRAME_FATAL Position) Virtual Channel x Error Matching Frame Start with Frame End Interrupt Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC_Msk (_UINT32_(0xF) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC_Pos) /* (CSI_INT_MSK_FRAME_FATAL Mask) MASK_ERR_F_BNDRY_MATCH_VC */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC_Pos)) 
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC_Pos _UINT32_(8)                                          /* (CSI_INT_MSK_FRAME_FATAL Position) Incorrect Frame Sequence in Virtual Channel x Interrupt Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC_Msk (_UINT32_(0xF) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC_Pos) /* (CSI_INT_MSK_FRAME_FATAL Mask) MASK_ERR_F_SEQ_VC */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC_Pos)) 
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC_Pos _UINT32_(16)                                         /* (CSI_INT_MSK_FRAME_FATAL Position) CRC Error in Last Received Frame of Virtual Channel 3 Interrupt Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC_Msk (_UINT32_(0xF) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC_Pos) /* (CSI_INT_MSK_FRAME_FATAL Mask) MASK_ERR_FRAME_DATA_VC */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC_Pos)) 

/* -------- CSI_INT_FORCE_FRAME_FATAL : (CSI Offset: 0x108) (R/W 32) CSI Frame Fatal Error Interrupt Force Register -------- */
#define CSI_INT_FORCE_FRAME_FATAL_RESETVALUE  _UINT32_(0x00)                                       /*  (CSI_INT_FORCE_FRAME_FATAL) CSI Frame Fatal Error Interrupt Force Register  Reset Value */

#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC0_Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_FRAME_FATAL) Force Virtual Channel 0 Error Matching Frame Start with Frame End Interrupt Error Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC0_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC0_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force Virtual Channel 0 Error Matching Frame Start with Frame End Interrupt Error Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC0(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC0_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC0_Pos)) /* Assigment of value for FORCE_ERR_F_BNDRY_MATCH_VC0 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC1_Pos _UINT32_(1)                                          /* (CSI_INT_FORCE_FRAME_FATAL) Force Virtual Channel 1 Error Matching Frame Start with Frame End Interrupt Error Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC1_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC1_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force Virtual Channel 1 Error Matching Frame Start with Frame End Interrupt Error Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC1(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC1_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC1_Pos)) /* Assigment of value for FORCE_ERR_F_BNDRY_MATCH_VC1 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC2_Pos _UINT32_(2)                                          /* (CSI_INT_FORCE_FRAME_FATAL) Force Virtual Channel 2 Error Matching Frame Start with Frame End Interrupt Error Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC2_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC2_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force Virtual Channel 2 Error Matching Frame Start with Frame End Interrupt Error Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC2(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC2_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC2_Pos)) /* Assigment of value for FORCE_ERR_F_BNDRY_MATCH_VC2 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC3_Pos _UINT32_(3)                                          /* (CSI_INT_FORCE_FRAME_FATAL) Force Virtual Channel 3 Error Matching Frame Start with Frame End Interrupt Error Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC3_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC3_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force Virtual Channel 3 Error Matching Frame Start with Frame End Interrupt Error Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC3(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC3_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC3_Pos)) /* Assigment of value for FORCE_ERR_F_BNDRY_MATCH_VC3 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC0_Pos _UINT32_(8)                                          /* (CSI_INT_FORCE_FRAME_FATAL) Force Incorrect Frame Sequence in Virtual Channel 0 Interrupt Error Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC0_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC0_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force Incorrect Frame Sequence in Virtual Channel 0 Interrupt Error Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC0(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC0_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC0_Pos)) /* Assigment of value for FORCE_ERR_F_SEQ_VC0 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC1_Pos _UINT32_(9)                                          /* (CSI_INT_FORCE_FRAME_FATAL) Force Incorrect Frame Sequence in Virtual Channel 1 Interrupt Error Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC1_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC1_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force Incorrect Frame Sequence in Virtual Channel 1 Interrupt Error Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC1(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC1_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC1_Pos)) /* Assigment of value for FORCE_ERR_F_SEQ_VC1 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC2_Pos _UINT32_(10)                                         /* (CSI_INT_FORCE_FRAME_FATAL) Force Incorrect Frame Sequence in Virtual Channel 2 Interrupt Error Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC2_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC2_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force Incorrect Frame Sequence in Virtual Channel 2 Interrupt Error Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC2(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC2_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC2_Pos)) /* Assigment of value for FORCE_ERR_F_SEQ_VC2 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC3_Pos _UINT32_(11)                                         /* (CSI_INT_FORCE_FRAME_FATAL) Force Incorrect Frame Sequence in Virtual Channel 3 Interrupt Error Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC3_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC3_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force Incorrect Frame Sequence in Virtual Channel 3 Interrupt Error Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC3(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC3_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC3_Pos)) /* Assigment of value for FORCE_ERR_F_SEQ_VC3 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC0_Pos _UINT32_(16)                                         /* (CSI_INT_FORCE_FRAME_FATAL) Force CRC Error in Last Received Frame of Virtual Channel 0 Interrupt Error Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC0_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC0_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force CRC Error in Last Received Frame of Virtual Channel 0 Interrupt Error Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC0(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC0_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC0_Pos)) /* Assigment of value for FORCE_ERR_FRAME_DATA_VC0 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC1_Pos _UINT32_(17)                                         /* (CSI_INT_FORCE_FRAME_FATAL) Force CRC Error in Last Received Frame of Virtual Channel 1 Interrupt Error Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC1_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC1_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force CRC Error in Last Received Frame of Virtual Channel 1 Interrupt Error Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC1(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC1_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC1_Pos)) /* Assigment of value for FORCE_ERR_FRAME_DATA_VC1 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC2_Pos _UINT32_(18)                                         /* (CSI_INT_FORCE_FRAME_FATAL) Force CRC Error in Last Received Frame of Virtual Channel 2 Interrupt Error Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC2_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC2_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force CRC Error in Last Received Frame of Virtual Channel 2 Interrupt Error Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC2(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC2_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC2_Pos)) /* Assigment of value for FORCE_ERR_FRAME_DATA_VC2 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC3_Pos _UINT32_(19)                                         /* (CSI_INT_FORCE_FRAME_FATAL) Force CRC Error in Last Received Frame of Virtual Channel 3 Interrupt Error Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC3_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC3_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force CRC Error in Last Received Frame of Virtual Channel 3 Interrupt Error Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC3(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC3_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC3_Pos)) /* Assigment of value for FORCE_ERR_FRAME_DATA_VC3 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_Msk         _UINT32_(0x000F0F0F)                                 /* (CSI_INT_FORCE_FRAME_FATAL) Register Mask  */

#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC_Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_FRAME_FATAL Position) Force Virtual Channel x Error Matching Frame Start with Frame End Interrupt Error */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC_Msk (_UINT32_(0xF) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC_Pos) /* (CSI_INT_FORCE_FRAME_FATAL Mask) FORCE_ERR_F_BNDRY_MATCH_VC */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC_Pos)) 
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC_Pos _UINT32_(8)                                          /* (CSI_INT_FORCE_FRAME_FATAL Position) Force Incorrect Frame Sequence in Virtual Channel x Interrupt Error */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC_Msk (_UINT32_(0xF) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC_Pos) /* (CSI_INT_FORCE_FRAME_FATAL Mask) FORCE_ERR_F_SEQ_VC */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC_Pos)) 
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC_Pos _UINT32_(16)                                         /* (CSI_INT_FORCE_FRAME_FATAL Position) Force CRC Error in Last Received Frame of Virtual Channel 3 Interrupt Error */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC_Msk (_UINT32_(0xF) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC_Pos) /* (CSI_INT_FORCE_FRAME_FATAL Mask) FORCE_ERR_FRAME_DATA_VC */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC_Pos)) 

/* -------- CSI_INT_ST_PHY : (CSI Offset: 0x110) ( R/ 32) CSI D-PHY Interrupt Status Register -------- */
#define CSI_INT_ST_PHY_RESETVALUE             _UINT32_(0x00)                                       /*  (CSI_INT_ST_PHY) CSI D-PHY Interrupt Status Register  Reset Value */

#define CSI_INT_ST_PHY_PHY_ERRSOTHS_0_Pos     _UINT32_(0)                                          /* (CSI_INT_ST_PHY) Start of Transmission Error on Data Lane 0 (no synchronization achieved) (cleared on read) Position */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS_0_Msk     (_UINT32_(0x1) << CSI_INT_ST_PHY_PHY_ERRSOTHS_0_Pos) /* (CSI_INT_ST_PHY) Start of Transmission Error on Data Lane 0 (no synchronization achieved) (cleared on read) Mask */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS_0(value)  (CSI_INT_ST_PHY_PHY_ERRSOTHS_0_Msk & (_UINT32_(value) << CSI_INT_ST_PHY_PHY_ERRSOTHS_0_Pos)) /* Assigment of value for PHY_ERRSOTHS_0 in the CSI_INT_ST_PHY register */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS_1_Pos     _UINT32_(1)                                          /* (CSI_INT_ST_PHY) Start of Transmission Error on Data Lane 1 (no synchronization achieved) (cleared on read) Position */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS_1_Msk     (_UINT32_(0x1) << CSI_INT_ST_PHY_PHY_ERRSOTHS_1_Pos) /* (CSI_INT_ST_PHY) Start of Transmission Error on Data Lane 1 (no synchronization achieved) (cleared on read) Mask */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS_1(value)  (CSI_INT_ST_PHY_PHY_ERRSOTHS_1_Msk & (_UINT32_(value) << CSI_INT_ST_PHY_PHY_ERRSOTHS_1_Pos)) /* Assigment of value for PHY_ERRSOTHS_1 in the CSI_INT_ST_PHY register */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS_2_Pos     _UINT32_(2)                                          /* (CSI_INT_ST_PHY) Start of Transmission Error on Data Lane 2 (no synchronization achieved) (cleared on read) Position */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS_2_Msk     (_UINT32_(0x1) << CSI_INT_ST_PHY_PHY_ERRSOTHS_2_Pos) /* (CSI_INT_ST_PHY) Start of Transmission Error on Data Lane 2 (no synchronization achieved) (cleared on read) Mask */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS_2(value)  (CSI_INT_ST_PHY_PHY_ERRSOTHS_2_Msk & (_UINT32_(value) << CSI_INT_ST_PHY_PHY_ERRSOTHS_2_Pos)) /* Assigment of value for PHY_ERRSOTHS_2 in the CSI_INT_ST_PHY register */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS_3_Pos     _UINT32_(3)                                          /* (CSI_INT_ST_PHY) Start of Transmission Error on Data Lane 3 (no synchronization achieved) (cleared on read) Position */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS_3_Msk     (_UINT32_(0x1) << CSI_INT_ST_PHY_PHY_ERRSOTHS_3_Pos) /* (CSI_INT_ST_PHY) Start of Transmission Error on Data Lane 3 (no synchronization achieved) (cleared on read) Mask */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS_3(value)  (CSI_INT_ST_PHY_PHY_ERRSOTHS_3_Msk & (_UINT32_(value) << CSI_INT_ST_PHY_PHY_ERRSOTHS_3_Pos)) /* Assigment of value for PHY_ERRSOTHS_3 in the CSI_INT_ST_PHY register */
#define CSI_INT_ST_PHY_PHY_ERRESC_0_Pos       _UINT32_(16)                                         /* (CSI_INT_ST_PHY) Start of Transmission Error on Data Lane 0 (synchronization can still be achieved) (cleared on read) Position */
#define CSI_INT_ST_PHY_PHY_ERRESC_0_Msk       (_UINT32_(0x1) << CSI_INT_ST_PHY_PHY_ERRESC_0_Pos)   /* (CSI_INT_ST_PHY) Start of Transmission Error on Data Lane 0 (synchronization can still be achieved) (cleared on read) Mask */
#define CSI_INT_ST_PHY_PHY_ERRESC_0(value)    (CSI_INT_ST_PHY_PHY_ERRESC_0_Msk & (_UINT32_(value) << CSI_INT_ST_PHY_PHY_ERRESC_0_Pos)) /* Assigment of value for PHY_ERRESC_0 in the CSI_INT_ST_PHY register */
#define CSI_INT_ST_PHY_PHY_ERRESC_1_Pos       _UINT32_(17)                                         /* (CSI_INT_ST_PHY) Start of Transmission Error on Data Lane 1 (synchronization can still be achieved) (cleared on read) Position */
#define CSI_INT_ST_PHY_PHY_ERRESC_1_Msk       (_UINT32_(0x1) << CSI_INT_ST_PHY_PHY_ERRESC_1_Pos)   /* (CSI_INT_ST_PHY) Start of Transmission Error on Data Lane 1 (synchronization can still be achieved) (cleared on read) Mask */
#define CSI_INT_ST_PHY_PHY_ERRESC_1(value)    (CSI_INT_ST_PHY_PHY_ERRESC_1_Msk & (_UINT32_(value) << CSI_INT_ST_PHY_PHY_ERRESC_1_Pos)) /* Assigment of value for PHY_ERRESC_1 in the CSI_INT_ST_PHY register */
#define CSI_INT_ST_PHY_PHY_ERRESC_2_Pos       _UINT32_(18)                                         /* (CSI_INT_ST_PHY) Start of Transmission Error on Data Lane 2 (synchronization can still be achieved) (cleared on read) Position */
#define CSI_INT_ST_PHY_PHY_ERRESC_2_Msk       (_UINT32_(0x1) << CSI_INT_ST_PHY_PHY_ERRESC_2_Pos)   /* (CSI_INT_ST_PHY) Start of Transmission Error on Data Lane 2 (synchronization can still be achieved) (cleared on read) Mask */
#define CSI_INT_ST_PHY_PHY_ERRESC_2(value)    (CSI_INT_ST_PHY_PHY_ERRESC_2_Msk & (_UINT32_(value) << CSI_INT_ST_PHY_PHY_ERRESC_2_Pos)) /* Assigment of value for PHY_ERRESC_2 in the CSI_INT_ST_PHY register */
#define CSI_INT_ST_PHY_PHY_ERRESC_3_Pos       _UINT32_(19)                                         /* (CSI_INT_ST_PHY) Start of Transmission Error on Data Lane 3 (synchronization can still be achieved) (cleared on read) Position */
#define CSI_INT_ST_PHY_PHY_ERRESC_3_Msk       (_UINT32_(0x1) << CSI_INT_ST_PHY_PHY_ERRESC_3_Pos)   /* (CSI_INT_ST_PHY) Start of Transmission Error on Data Lane 3 (synchronization can still be achieved) (cleared on read) Mask */
#define CSI_INT_ST_PHY_PHY_ERRESC_3(value)    (CSI_INT_ST_PHY_PHY_ERRESC_3_Msk & (_UINT32_(value) << CSI_INT_ST_PHY_PHY_ERRESC_3_Pos)) /* Assigment of value for PHY_ERRESC_3 in the CSI_INT_ST_PHY register */
#define CSI_INT_ST_PHY_Msk                    _UINT32_(0x000F000F)                                 /* (CSI_INT_ST_PHY) Register Mask  */

#define CSI_INT_ST_PHY_PHY_ERRSOTHS__Pos      _UINT32_(0)                                          /* (CSI_INT_ST_PHY Position) Start of Transmission Error on Data Lane x (no synchronization achieved) (cleared on read) */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS__Msk      (_UINT32_(0xF) << CSI_INT_ST_PHY_PHY_ERRSOTHS__Pos)  /* (CSI_INT_ST_PHY Mask) PHY_ERRSOTHS_ */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS_(value)   (CSI_INT_ST_PHY_PHY_ERRSOTHS__Msk & (_UINT32_(value) << CSI_INT_ST_PHY_PHY_ERRSOTHS__Pos)) 
#define CSI_INT_ST_PHY_PHY_ERRESC__Pos        _UINT32_(16)                                         /* (CSI_INT_ST_PHY Position) Start of Transmission Error on Data Lane 3 (synchronization can still be achieved) (cleared on read) */
#define CSI_INT_ST_PHY_PHY_ERRESC__Msk        (_UINT32_(0xF) << CSI_INT_ST_PHY_PHY_ERRESC__Pos)    /* (CSI_INT_ST_PHY Mask) PHY_ERRESC_ */
#define CSI_INT_ST_PHY_PHY_ERRESC_(value)     (CSI_INT_ST_PHY_PHY_ERRESC__Msk & (_UINT32_(value) << CSI_INT_ST_PHY_PHY_ERRESC__Pos)) 

/* -------- CSI_INT_MSK_PHY : (CSI Offset: 0x114) (R/W 32) CSI D-PHY Interrupt Mask Register -------- */
#define CSI_INT_MSK_PHY_RESETVALUE            _UINT32_(0x00)                                       /*  (CSI_INT_MSK_PHY) CSI D-PHY Interrupt Mask Register  Reset Value */

#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_0_Pos _UINT32_(0)                                          /* (CSI_INT_MSK_PHY) Start of Transmission Error on Data Lane 0 (no synchronization achieved) Interrupt Mask Position */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_0_Msk (_UINT32_(0x1) << CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_0_Pos) /* (CSI_INT_MSK_PHY) Start of Transmission Error on Data Lane 0 (no synchronization achieved) Interrupt Mask Mask */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_0(value) (CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_0_Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_0_Pos)) /* Assigment of value for MASK_PHY_ERRSOTHS_0 in the CSI_INT_MSK_PHY register */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_1_Pos _UINT32_(1)                                          /* (CSI_INT_MSK_PHY) Start of Transmission Error on Data Lane 1 (no synchronization achieved) Interrupt Mask Position */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_1_Msk (_UINT32_(0x1) << CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_1_Pos) /* (CSI_INT_MSK_PHY) Start of Transmission Error on Data Lane 1 (no synchronization achieved) Interrupt Mask Mask */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_1(value) (CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_1_Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_1_Pos)) /* Assigment of value for MASK_PHY_ERRSOTHS_1 in the CSI_INT_MSK_PHY register */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_2_Pos _UINT32_(2)                                          /* (CSI_INT_MSK_PHY) Start of Transmission Error on Data Lane 2 (no synchronization achieved)Interrupt Mask Position */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_2_Msk (_UINT32_(0x1) << CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_2_Pos) /* (CSI_INT_MSK_PHY) Start of Transmission Error on Data Lane 2 (no synchronization achieved)Interrupt Mask Mask */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_2(value) (CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_2_Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_2_Pos)) /* Assigment of value for MASK_PHY_ERRSOTHS_2 in the CSI_INT_MSK_PHY register */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_3_Pos _UINT32_(3)                                          /* (CSI_INT_MSK_PHY) Start of Transmission Error on Data Lane 3 (no synchronization achieved) Interrupt Mask Position */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_3_Msk (_UINT32_(0x1) << CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_3_Pos) /* (CSI_INT_MSK_PHY) Start of Transmission Error on Data Lane 3 (no synchronization achieved) Interrupt Mask Mask */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_3(value) (CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_3_Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_3_Pos)) /* Assigment of value for MASK_PHY_ERRSOTHS_3 in the CSI_INT_MSK_PHY register */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_0_Pos _UINT32_(16)                                         /* (CSI_INT_MSK_PHY) Start of Transmission Error on Data Lane 0 (synchronization can still be achieved) Interrupt Mask Position */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_0_Msk (_UINT32_(0x1) << CSI_INT_MSK_PHY_MASK_PHY_ERRESC_0_Pos) /* (CSI_INT_MSK_PHY) Start of Transmission Error on Data Lane 0 (synchronization can still be achieved) Interrupt Mask Mask */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_0(value) (CSI_INT_MSK_PHY_MASK_PHY_ERRESC_0_Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_MASK_PHY_ERRESC_0_Pos)) /* Assigment of value for MASK_PHY_ERRESC_0 in the CSI_INT_MSK_PHY register */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_1_Pos _UINT32_(17)                                         /* (CSI_INT_MSK_PHY) Start of Transmission Error on Data Lane 1 (synchronization can still be achieved) Interrupt Mask Position */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_1_Msk (_UINT32_(0x1) << CSI_INT_MSK_PHY_MASK_PHY_ERRESC_1_Pos) /* (CSI_INT_MSK_PHY) Start of Transmission Error on Data Lane 1 (synchronization can still be achieved) Interrupt Mask Mask */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_1(value) (CSI_INT_MSK_PHY_MASK_PHY_ERRESC_1_Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_MASK_PHY_ERRESC_1_Pos)) /* Assigment of value for MASK_PHY_ERRESC_1 in the CSI_INT_MSK_PHY register */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_2_Pos _UINT32_(18)                                         /* (CSI_INT_MSK_PHY) Start of Transmission Error on Data Lane 2 (synchronization can still be achieved) Interrupt Mask Position */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_2_Msk (_UINT32_(0x1) << CSI_INT_MSK_PHY_MASK_PHY_ERRESC_2_Pos) /* (CSI_INT_MSK_PHY) Start of Transmission Error on Data Lane 2 (synchronization can still be achieved) Interrupt Mask Mask */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_2(value) (CSI_INT_MSK_PHY_MASK_PHY_ERRESC_2_Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_MASK_PHY_ERRESC_2_Pos)) /* Assigment of value for MASK_PHY_ERRESC_2 in the CSI_INT_MSK_PHY register */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_3_Pos _UINT32_(19)                                         /* (CSI_INT_MSK_PHY) Start of Transmission Error on Data Lane 3 (synchronization can still be achieved) Interrupt Mask Position */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_3_Msk (_UINT32_(0x1) << CSI_INT_MSK_PHY_MASK_PHY_ERRESC_3_Pos) /* (CSI_INT_MSK_PHY) Start of Transmission Error on Data Lane 3 (synchronization can still be achieved) Interrupt Mask Mask */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_3(value) (CSI_INT_MSK_PHY_MASK_PHY_ERRESC_3_Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_MASK_PHY_ERRESC_3_Pos)) /* Assigment of value for MASK_PHY_ERRESC_3 in the CSI_INT_MSK_PHY register */
#define CSI_INT_MSK_PHY_Msk                   _UINT32_(0x000F000F)                                 /* (CSI_INT_MSK_PHY) Register Mask  */

#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS__Pos _UINT32_(0)                                          /* (CSI_INT_MSK_PHY Position) Start of Transmission Error on Data Lane x (no synchronization achieved) Interrupt Mask */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS__Msk (_UINT32_(0xF) << CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS__Pos) /* (CSI_INT_MSK_PHY Mask) MASK_PHY_ERRSOTHS_ */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_(value) (CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS__Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS__Pos)) 
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC__Pos  _UINT32_(16)                                         /* (CSI_INT_MSK_PHY Position) Start of Transmission Error on Data Lane 3 (synchronization can still be achieved) Interrupt Mask */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC__Msk  (_UINT32_(0xF) << CSI_INT_MSK_PHY_MASK_PHY_ERRESC__Pos) /* (CSI_INT_MSK_PHY Mask) MASK_PHY_ERRESC_ */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_(value) (CSI_INT_MSK_PHY_MASK_PHY_ERRESC__Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_MASK_PHY_ERRESC__Pos)) 

/* -------- CSI_INT_FORCE_PHY : (CSI Offset: 0x118) (R/W 32) CSI D-PHY Interrupt Force Register -------- */
#define CSI_INT_FORCE_PHY_RESETVALUE          _UINT32_(0x00)                                       /*  (CSI_INT_FORCE_PHY) CSI D-PHY Interrupt Force Register  Reset Value */

#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_0_Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_PHY) Force Start of Transmission Error on Data Lane 0 (no synchronization achieved) Interrupt Position */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_0_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_0_Pos) /* (CSI_INT_FORCE_PHY) Force Start of Transmission Error on Data Lane 0 (no synchronization achieved) Interrupt Mask */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_0(value) (CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_0_Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_0_Pos)) /* Assigment of value for FORCE_PHY_ERRSOTHS_0 in the CSI_INT_FORCE_PHY register */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_1_Pos _UINT32_(1)                                          /* (CSI_INT_FORCE_PHY) Force Start of Transmission Error on Data Lane 1 (no synchronization achieved) Interrupt Position */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_1_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_1_Pos) /* (CSI_INT_FORCE_PHY) Force Start of Transmission Error on Data Lane 1 (no synchronization achieved) Interrupt Mask */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_1(value) (CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_1_Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_1_Pos)) /* Assigment of value for FORCE_PHY_ERRSOTHS_1 in the CSI_INT_FORCE_PHY register */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_2_Pos _UINT32_(2)                                          /* (CSI_INT_FORCE_PHY) Force Start of Transmission Error on Data Lane 2 (no synchronization achieved) Interrupt Position */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_2_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_2_Pos) /* (CSI_INT_FORCE_PHY) Force Start of Transmission Error on Data Lane 2 (no synchronization achieved) Interrupt Mask */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_2(value) (CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_2_Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_2_Pos)) /* Assigment of value for FORCE_PHY_ERRSOTHS_2 in the CSI_INT_FORCE_PHY register */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_3_Pos _UINT32_(3)                                          /* (CSI_INT_FORCE_PHY) Force Start of Transmission Error on Data Lane 3 (no synchronization achieved) Interrupt Mask Position */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_3_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_3_Pos) /* (CSI_INT_FORCE_PHY) Force Start of Transmission Error on Data Lane 3 (no synchronization achieved) Interrupt Mask Mask */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_3(value) (CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_3_Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_3_Pos)) /* Assigment of value for FORCE_PHY_ERRSOTHS_3 in the CSI_INT_FORCE_PHY register */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_0_Pos _UINT32_(16)                                         /* (CSI_INT_FORCE_PHY) Force Start of Transmission Error on Data Lane 0 (synchronization can still be achieved) Interrupt Position */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_0_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_0_Pos) /* (CSI_INT_FORCE_PHY) Force Start of Transmission Error on Data Lane 0 (synchronization can still be achieved) Interrupt Mask */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_0(value) (CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_0_Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_0_Pos)) /* Assigment of value for FORCE_PHY_ERRESC_0 in the CSI_INT_FORCE_PHY register */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_1_Pos _UINT32_(17)                                         /* (CSI_INT_FORCE_PHY) Force Start of Transmission Error on Data Lane 1 (synchronization can still be achieved) Interrupt Position */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_1_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_1_Pos) /* (CSI_INT_FORCE_PHY) Force Start of Transmission Error on Data Lane 1 (synchronization can still be achieved) Interrupt Mask */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_1(value) (CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_1_Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_1_Pos)) /* Assigment of value for FORCE_PHY_ERRESC_1 in the CSI_INT_FORCE_PHY register */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_2_Pos _UINT32_(18)                                         /* (CSI_INT_FORCE_PHY) Force Start of Transmission Error on Data Lane 2 (synchronization can still be achieved) Interrupt Position */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_2_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_2_Pos) /* (CSI_INT_FORCE_PHY) Force Start of Transmission Error on Data Lane 2 (synchronization can still be achieved) Interrupt Mask */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_2(value) (CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_2_Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_2_Pos)) /* Assigment of value for FORCE_PHY_ERRESC_2 in the CSI_INT_FORCE_PHY register */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_3_Pos _UINT32_(19)                                         /* (CSI_INT_FORCE_PHY) Force Start of Transmission Error on Data Lane 3 (synchronization can still be achieved) Interrupt Position */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_3_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_3_Pos) /* (CSI_INT_FORCE_PHY) Force Start of Transmission Error on Data Lane 3 (synchronization can still be achieved) Interrupt Mask */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_3(value) (CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_3_Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_3_Pos)) /* Assigment of value for FORCE_PHY_ERRESC_3 in the CSI_INT_FORCE_PHY register */
#define CSI_INT_FORCE_PHY_Msk                 _UINT32_(0x000F000F)                                 /* (CSI_INT_FORCE_PHY) Register Mask  */

#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS__Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_PHY Position) Force Start of Transmission Error on Data Lane x (no synchronization achieved) Interrupt */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS__Msk (_UINT32_(0xF) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS__Pos) /* (CSI_INT_FORCE_PHY Mask) FORCE_PHY_ERRSOTHS_ */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_(value) (CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS__Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS__Pos)) 
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC__Pos _UINT32_(16)                                         /* (CSI_INT_FORCE_PHY Position) Force Start of Transmission Error on Data Lane 3 (synchronization can still be achieved) Interrupt */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC__Msk (_UINT32_(0xF) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC__Pos) /* (CSI_INT_FORCE_PHY Mask) FORCE_PHY_ERRESC_ */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_(value) (CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC__Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC__Pos)) 

/* -------- CSI_INT_ST_PKT : (CSI Offset: 0x120) ( R/ 32) CSI Packet Interrupt Status Register -------- */
#define CSI_INT_ST_PKT_RESETVALUE             _UINT32_(0x00)                                       /*  (CSI_INT_ST_PKT) CSI Packet Interrupt Status Register  Reset Value */

#define CSI_INT_ST_PKT_ERR_ID_VC0_Pos         _UINT32_(0)                                          /* (CSI_INT_ST_PKT) Unrecognized or Unimplemented Data Type Detected in Virtual Channel 0 (cleared on read) Position */
#define CSI_INT_ST_PKT_ERR_ID_VC0_Msk         (_UINT32_(0x1) << CSI_INT_ST_PKT_ERR_ID_VC0_Pos)     /* (CSI_INT_ST_PKT) Unrecognized or Unimplemented Data Type Detected in Virtual Channel 0 (cleared on read) Mask */
#define CSI_INT_ST_PKT_ERR_ID_VC0(value)      (CSI_INT_ST_PKT_ERR_ID_VC0_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_ERR_ID_VC0_Pos)) /* Assigment of value for ERR_ID_VC0 in the CSI_INT_ST_PKT register */
#define CSI_INT_ST_PKT_ERR_ID_VC1_Pos         _UINT32_(1)                                          /* (CSI_INT_ST_PKT) Unrecognized or Unimplemented Data Type Detected in Virtual Channel 1 (cleared on read) Position */
#define CSI_INT_ST_PKT_ERR_ID_VC1_Msk         (_UINT32_(0x1) << CSI_INT_ST_PKT_ERR_ID_VC1_Pos)     /* (CSI_INT_ST_PKT) Unrecognized or Unimplemented Data Type Detected in Virtual Channel 1 (cleared on read) Mask */
#define CSI_INT_ST_PKT_ERR_ID_VC1(value)      (CSI_INT_ST_PKT_ERR_ID_VC1_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_ERR_ID_VC1_Pos)) /* Assigment of value for ERR_ID_VC1 in the CSI_INT_ST_PKT register */
#define CSI_INT_ST_PKT_ERR_ID_VC2_Pos         _UINT32_(2)                                          /* (CSI_INT_ST_PKT) Unrecognized or Unimplemented Data Type Detected in Virtual Channel 2 (cleared on read) Position */
#define CSI_INT_ST_PKT_ERR_ID_VC2_Msk         (_UINT32_(0x1) << CSI_INT_ST_PKT_ERR_ID_VC2_Pos)     /* (CSI_INT_ST_PKT) Unrecognized or Unimplemented Data Type Detected in Virtual Channel 2 (cleared on read) Mask */
#define CSI_INT_ST_PKT_ERR_ID_VC2(value)      (CSI_INT_ST_PKT_ERR_ID_VC2_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_ERR_ID_VC2_Pos)) /* Assigment of value for ERR_ID_VC2 in the CSI_INT_ST_PKT register */
#define CSI_INT_ST_PKT_ERR_ID_VC3_Pos         _UINT32_(3)                                          /* (CSI_INT_ST_PKT) Unrecognized or Unimplemented Data Type Detected in Virtual Channel 3 (cleared on read) Position */
#define CSI_INT_ST_PKT_ERR_ID_VC3_Msk         (_UINT32_(0x1) << CSI_INT_ST_PKT_ERR_ID_VC3_Pos)     /* (CSI_INT_ST_PKT) Unrecognized or Unimplemented Data Type Detected in Virtual Channel 3 (cleared on read) Mask */
#define CSI_INT_ST_PKT_ERR_ID_VC3(value)      (CSI_INT_ST_PKT_ERR_ID_VC3_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_ERR_ID_VC3_Pos)) /* Assigment of value for ERR_ID_VC3 in the CSI_INT_ST_PKT register */
#define CSI_INT_ST_PKT_VC0_ERR_ECC_CORRECTED_Pos _UINT32_(16)                                         /* (CSI_INT_ST_PKT) Header Error Detected and Corrected on Virtual Channel 0 (cleared on read) Position */
#define CSI_INT_ST_PKT_VC0_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_ST_PKT_VC0_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_ST_PKT) Header Error Detected and Corrected on Virtual Channel 0 (cleared on read) Mask */
#define CSI_INT_ST_PKT_VC0_ERR_ECC_CORRECTED(value) (CSI_INT_ST_PKT_VC0_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_VC0_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for VC0_ERR_ECC_CORRECTED in the CSI_INT_ST_PKT register */
#define CSI_INT_ST_PKT_VC1_ERR_ECC_CORRECTED_Pos _UINT32_(17)                                         /* (CSI_INT_ST_PKT) Header Error Detected and Corrected on Virtual Channel 1 (cleared on read) Position */
#define CSI_INT_ST_PKT_VC1_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_ST_PKT_VC1_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_ST_PKT) Header Error Detected and Corrected on Virtual Channel 1 (cleared on read) Mask */
#define CSI_INT_ST_PKT_VC1_ERR_ECC_CORRECTED(value) (CSI_INT_ST_PKT_VC1_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_VC1_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for VC1_ERR_ECC_CORRECTED in the CSI_INT_ST_PKT register */
#define CSI_INT_ST_PKT_VC2_ERR_ECC_CORRECTED_Pos _UINT32_(18)                                         /* (CSI_INT_ST_PKT) Header Error Detected and Corrected on Virtual Channel 2 (cleared on read) Position */
#define CSI_INT_ST_PKT_VC2_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_ST_PKT_VC2_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_ST_PKT) Header Error Detected and Corrected on Virtual Channel 2 (cleared on read) Mask */
#define CSI_INT_ST_PKT_VC2_ERR_ECC_CORRECTED(value) (CSI_INT_ST_PKT_VC2_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_VC2_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for VC2_ERR_ECC_CORRECTED in the CSI_INT_ST_PKT register */
#define CSI_INT_ST_PKT_VC3_ERR_ECC_CORRECTED_Pos _UINT32_(19)                                         /* (CSI_INT_ST_PKT) Header Error Detected and Corrected on Virtual Channel 3 (cleared on read) Position */
#define CSI_INT_ST_PKT_VC3_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_ST_PKT_VC3_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_ST_PKT) Header Error Detected and Corrected on Virtual Channel 3 (cleared on read) Mask */
#define CSI_INT_ST_PKT_VC3_ERR_ECC_CORRECTED(value) (CSI_INT_ST_PKT_VC3_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_VC3_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for VC3_ERR_ECC_CORRECTED in the CSI_INT_ST_PKT register */
#define CSI_INT_ST_PKT_Msk                    _UINT32_(0x000F000F)                                 /* (CSI_INT_ST_PKT) Register Mask  */

#define CSI_INT_ST_PKT_ERR_ID_VC_Pos          _UINT32_(0)                                          /* (CSI_INT_ST_PKT Position) Unrecognized or Unimplemented Data Type Detected in Virtual Channel x (cleared on read) */
#define CSI_INT_ST_PKT_ERR_ID_VC_Msk          (_UINT32_(0xF) << CSI_INT_ST_PKT_ERR_ID_VC_Pos)      /* (CSI_INT_ST_PKT Mask) ERR_ID_VC */
#define CSI_INT_ST_PKT_ERR_ID_VC(value)       (CSI_INT_ST_PKT_ERR_ID_VC_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_ERR_ID_VC_Pos)) 

/* -------- CSI_INT_MSK_PKT : (CSI Offset: 0x124) (R/W 32) CSI Packet Interrupt Mask Register -------- */
#define CSI_INT_MSK_PKT_RESETVALUE            _UINT32_(0x00)                                       /*  (CSI_INT_MSK_PKT) CSI Packet Interrupt Mask Register  Reset Value */

#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC0_Pos   _UINT32_(0)                                          /* (CSI_INT_MSK_PKT) Unrecognized or Unimplemented Data Type Detected in Virtual Channel 0 Interrupt Mask Position */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC0_Msk   (_UINT32_(0x1) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC0_Pos) /* (CSI_INT_MSK_PKT) Unrecognized or Unimplemented Data Type Detected in Virtual Channel 0 Interrupt Mask Mask */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC0(value) (CSI_INT_MSK_PKT_MASK_ERR_ID_VC0_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC0_Pos)) /* Assigment of value for MASK_ERR_ID_VC0 in the CSI_INT_MSK_PKT register */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC1_Pos   _UINT32_(1)                                          /* (CSI_INT_MSK_PKT) Unrecognized or Unimplemented Data Type Detected in Virtual Channel 1 Interrupt Mask Position */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC1_Msk   (_UINT32_(0x1) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC1_Pos) /* (CSI_INT_MSK_PKT) Unrecognized or Unimplemented Data Type Detected in Virtual Channel 1 Interrupt Mask Mask */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC1(value) (CSI_INT_MSK_PKT_MASK_ERR_ID_VC1_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC1_Pos)) /* Assigment of value for MASK_ERR_ID_VC1 in the CSI_INT_MSK_PKT register */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC2_Pos   _UINT32_(2)                                          /* (CSI_INT_MSK_PKT) Unrecognized or Unimplemented Data Type Detected in Virtual Channel 2 Interrupt Mask Position */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC2_Msk   (_UINT32_(0x1) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC2_Pos) /* (CSI_INT_MSK_PKT) Unrecognized or Unimplemented Data Type Detected in Virtual Channel 2 Interrupt Mask Mask */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC2(value) (CSI_INT_MSK_PKT_MASK_ERR_ID_VC2_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC2_Pos)) /* Assigment of value for MASK_ERR_ID_VC2 in the CSI_INT_MSK_PKT register */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC3_Pos   _UINT32_(3)                                          /* (CSI_INT_MSK_PKT) Unrecognized or Unimplemented Data Type Detected in Virtual Channel 3 Interrupt Mask Position */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC3_Msk   (_UINT32_(0x1) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC3_Pos) /* (CSI_INT_MSK_PKT) Unrecognized or Unimplemented Data Type Detected in Virtual Channel 3 Interrupt Mask Mask */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC3(value) (CSI_INT_MSK_PKT_MASK_ERR_ID_VC3_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC3_Pos)) /* Assigment of value for MASK_ERR_ID_VC3 in the CSI_INT_MSK_PKT register */
#define CSI_INT_MSK_PKT_MASK_VC0_ERR_ECC_CORRECTED_Pos _UINT32_(16)                                         /* (CSI_INT_MSK_PKT) Header Error Detected and Corrected on Virtual Channel 0 Interrupt Mask Position */
#define CSI_INT_MSK_PKT_MASK_VC0_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_MSK_PKT_MASK_VC0_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_MSK_PKT) Header Error Detected and Corrected on Virtual Channel 0 Interrupt Mask Mask */
#define CSI_INT_MSK_PKT_MASK_VC0_ERR_ECC_CORRECTED(value) (CSI_INT_MSK_PKT_MASK_VC0_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_MASK_VC0_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for MASK_VC0_ERR_ECC_CORRECTED in the CSI_INT_MSK_PKT register */
#define CSI_INT_MSK_PKT_MASK_VC1_ERR_ECC_CORRECTED_Pos _UINT32_(17)                                         /* (CSI_INT_MSK_PKT) Header Error Detected and Corrected on Virtual Channel 1 Interrupt Mask Position */
#define CSI_INT_MSK_PKT_MASK_VC1_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_MSK_PKT_MASK_VC1_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_MSK_PKT) Header Error Detected and Corrected on Virtual Channel 1 Interrupt Mask Mask */
#define CSI_INT_MSK_PKT_MASK_VC1_ERR_ECC_CORRECTED(value) (CSI_INT_MSK_PKT_MASK_VC1_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_MASK_VC1_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for MASK_VC1_ERR_ECC_CORRECTED in the CSI_INT_MSK_PKT register */
#define CSI_INT_MSK_PKT_MASK_VC2_ERR_ECC_CORRECTED_Pos _UINT32_(18)                                         /* (CSI_INT_MSK_PKT) Header Error Detected and Corrected on Virtual Channel 2 Interrupt Mask Position */
#define CSI_INT_MSK_PKT_MASK_VC2_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_MSK_PKT_MASK_VC2_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_MSK_PKT) Header Error Detected and Corrected on Virtual Channel 2 Interrupt Mask Mask */
#define CSI_INT_MSK_PKT_MASK_VC2_ERR_ECC_CORRECTED(value) (CSI_INT_MSK_PKT_MASK_VC2_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_MASK_VC2_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for MASK_VC2_ERR_ECC_CORRECTED in the CSI_INT_MSK_PKT register */
#define CSI_INT_MSK_PKT_MASK_VC3_ERR_ECC_CORRECTED_Pos _UINT32_(19)                                         /* (CSI_INT_MSK_PKT) Header Error Detected and Corrected on Virtual Channel 3 Interrupt Mask Position */
#define CSI_INT_MSK_PKT_MASK_VC3_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_MSK_PKT_MASK_VC3_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_MSK_PKT) Header Error Detected and Corrected on Virtual Channel 3 Interrupt Mask Mask */
#define CSI_INT_MSK_PKT_MASK_VC3_ERR_ECC_CORRECTED(value) (CSI_INT_MSK_PKT_MASK_VC3_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_MASK_VC3_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for MASK_VC3_ERR_ECC_CORRECTED in the CSI_INT_MSK_PKT register */
#define CSI_INT_MSK_PKT_Msk                   _UINT32_(0x000F000F)                                 /* (CSI_INT_MSK_PKT) Register Mask  */

#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC_Pos    _UINT32_(0)                                          /* (CSI_INT_MSK_PKT Position) Unrecognized or Unimplemented Data Type Detected in Virtual Channel x Interrupt Mask */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC_Msk    (_UINT32_(0xF) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC_Pos) /* (CSI_INT_MSK_PKT Mask) MASK_ERR_ID_VC */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC(value) (CSI_INT_MSK_PKT_MASK_ERR_ID_VC_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC_Pos)) 

/* -------- CSI_INT_FORCE_PKT : (CSI Offset: 0x128) (R/W 32) CSI Packet Interrupt Force Register -------- */
#define CSI_INT_FORCE_PKT_RESETVALUE          _UINT32_(0x00)                                       /*  (CSI_INT_FORCE_PKT) CSI Packet Interrupt Force Register  Reset Value */

#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC0_Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_PKT) Force Start of Transmission Error on Data Lane 0 (no synchronization achieved) Interrupt Position */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC0_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC0_Pos) /* (CSI_INT_FORCE_PKT) Force Start of Transmission Error on Data Lane 0 (no synchronization achieved) Interrupt Mask */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC0(value) (CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC0_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC0_Pos)) /* Assigment of value for FORCE_ERR_ID_VC0 in the CSI_INT_FORCE_PKT register */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC1_Pos _UINT32_(1)                                          /* (CSI_INT_FORCE_PKT) Force Start of Transmission Error on Data Lane 1 (no synchronization achieved) Interrupt Position */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC1_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC1_Pos) /* (CSI_INT_FORCE_PKT) Force Start of Transmission Error on Data Lane 1 (no synchronization achieved) Interrupt Mask */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC1(value) (CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC1_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC1_Pos)) /* Assigment of value for FORCE_ERR_ID_VC1 in the CSI_INT_FORCE_PKT register */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC2_Pos _UINT32_(2)                                          /* (CSI_INT_FORCE_PKT) Force Start of Transmission Error on Data Lane 2 (no synchronization achieved) Interrupt Position */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC2_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC2_Pos) /* (CSI_INT_FORCE_PKT) Force Start of Transmission Error on Data Lane 2 (no synchronization achieved) Interrupt Mask */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC2(value) (CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC2_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC2_Pos)) /* Assigment of value for FORCE_ERR_ID_VC2 in the CSI_INT_FORCE_PKT register */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC3_Pos _UINT32_(3)                                          /* (CSI_INT_FORCE_PKT) Force Start of Transmission Error on Data Lane 3 (no synchronization achieved) Interrupt Mask Position */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC3_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC3_Pos) /* (CSI_INT_FORCE_PKT) Force Start of Transmission Error on Data Lane 3 (no synchronization achieved) Interrupt Mask Mask */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC3(value) (CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC3_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC3_Pos)) /* Assigment of value for FORCE_ERR_ID_VC3 in the CSI_INT_FORCE_PKT register */
#define CSI_INT_FORCE_PKT_FORCE_VC0_ERR_ECC_CORRECTED_Pos _UINT32_(16)                                         /* (CSI_INT_FORCE_PKT) Force Start of Transmission Error on Data Lane 0 (synchronization can still be achieved) Interrupt Position */
#define CSI_INT_FORCE_PKT_FORCE_VC0_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FORCE_VC0_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_FORCE_PKT) Force Start of Transmission Error on Data Lane 0 (synchronization can still be achieved) Interrupt Mask */
#define CSI_INT_FORCE_PKT_FORCE_VC0_ERR_ECC_CORRECTED(value) (CSI_INT_FORCE_PKT_FORCE_VC0_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FORCE_VC0_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for FORCE_VC0_ERR_ECC_CORRECTED in the CSI_INT_FORCE_PKT register */
#define CSI_INT_FORCE_PKT_FORCE_VC1_ERR_ECC_CORRECTED_Pos _UINT32_(17)                                         /* (CSI_INT_FORCE_PKT) Force Start of Transmission Error on Data Lane 1 (synchronization can still be achieved) Interrupt Position */
#define CSI_INT_FORCE_PKT_FORCE_VC1_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FORCE_VC1_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_FORCE_PKT) Force Start of Transmission Error on Data Lane 1 (synchronization can still be achieved) Interrupt Mask */
#define CSI_INT_FORCE_PKT_FORCE_VC1_ERR_ECC_CORRECTED(value) (CSI_INT_FORCE_PKT_FORCE_VC1_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FORCE_VC1_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for FORCE_VC1_ERR_ECC_CORRECTED in the CSI_INT_FORCE_PKT register */
#define CSI_INT_FORCE_PKT_FORCE_VC2_ERR_ECC_CORRECTED_Pos _UINT32_(18)                                         /* (CSI_INT_FORCE_PKT) Force Start of Transmission Error on Data Lane 2 (synchronization can still be achieved) Interrupt Position */
#define CSI_INT_FORCE_PKT_FORCE_VC2_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FORCE_VC2_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_FORCE_PKT) Force Start of Transmission Error on Data Lane 2 (synchronization can still be achieved) Interrupt Mask */
#define CSI_INT_FORCE_PKT_FORCE_VC2_ERR_ECC_CORRECTED(value) (CSI_INT_FORCE_PKT_FORCE_VC2_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FORCE_VC2_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for FORCE_VC2_ERR_ECC_CORRECTED in the CSI_INT_FORCE_PKT register */
#define CSI_INT_FORCE_PKT_FORCE_VC3_ERR_ECC_CORRECTED_Pos _UINT32_(19)                                         /* (CSI_INT_FORCE_PKT) Force Start of Transmission Error on Data Lane 3 (synchronization can still be achieved) Interrupt Position */
#define CSI_INT_FORCE_PKT_FORCE_VC3_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FORCE_VC3_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_FORCE_PKT) Force Start of Transmission Error on Data Lane 3 (synchronization can still be achieved) Interrupt Mask */
#define CSI_INT_FORCE_PKT_FORCE_VC3_ERR_ECC_CORRECTED(value) (CSI_INT_FORCE_PKT_FORCE_VC3_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FORCE_VC3_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for FORCE_VC3_ERR_ECC_CORRECTED in the CSI_INT_FORCE_PKT register */
#define CSI_INT_FORCE_PKT_Msk                 _UINT32_(0x000F000F)                                 /* (CSI_INT_FORCE_PKT) Register Mask  */

#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC_Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_PKT Position) Force Start of Transmission Error on Data Lane x (no synchronization achieved) Interrupt */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC_Msk (_UINT32_(0xF) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC_Pos) /* (CSI_INT_FORCE_PKT Mask) FORCE_ERR_ID_VC */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC(value) (CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC_Pos)) 

/* -------- CSI_INT_ST_LINE : (CSI Offset: 0x130) ( R/ 32) CSI Line Error Interrupt Status Register -------- */
#define CSI_INT_ST_LINE_RESETVALUE            _UINT32_(0x00)                                       /*  (CSI_INT_ST_LINE) CSI Line Error Interrupt Status Register  Reset Value */

#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI0_Pos _UINT32_(0)                                          /* (CSI_INT_ST_LINE) Error Matching Line Start with Line End for VC0 and DT0 (cleared on read) Position */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI0_Msk (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI0_Pos) /* (CSI_INT_ST_LINE) Error Matching Line Start with Line End for VC0 and DT0 (cleared on read) Mask */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI0(value) (CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI0_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI0_Pos)) /* Assigment of value for ERR_L_BNDRY_MATCH_DI0 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI1_Pos _UINT32_(1)                                          /* (CSI_INT_ST_LINE) Error Matching Line Start with Line End for VC1 and DT1 (cleared on read) Position */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI1_Msk (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI1_Pos) /* (CSI_INT_ST_LINE) Error Matching Line Start with Line End for VC1 and DT1 (cleared on read) Mask */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI1(value) (CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI1_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI1_Pos)) /* Assigment of value for ERR_L_BNDRY_MATCH_DI1 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI2_Pos _UINT32_(2)                                          /* (CSI_INT_ST_LINE) Error Matching Line Start with Line End for VC2 and DT2 (cleared on read) Position */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI2_Msk (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI2_Pos) /* (CSI_INT_ST_LINE) Error Matching Line Start with Line End for VC2 and DT2 (cleared on read) Mask */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI2(value) (CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI2_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI2_Pos)) /* Assigment of value for ERR_L_BNDRY_MATCH_DI2 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI3_Pos _UINT32_(3)                                          /* (CSI_INT_ST_LINE) Error Matching Line Start with Line End for VC3 and DT3 (cleared on read) Position */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI3_Msk (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI3_Pos) /* (CSI_INT_ST_LINE) Error Matching Line Start with Line End for VC3 and DT3 (cleared on read) Mask */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI3(value) (CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI3_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI3_Pos)) /* Assigment of value for ERR_L_BNDRY_MATCH_DI3 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI4_Pos _UINT32_(4)                                          /* (CSI_INT_ST_LINE) Error Matching Line Start with Line End for VC4 and DT4 (cleared on read) Position */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI4_Msk (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI4_Pos) /* (CSI_INT_ST_LINE) Error Matching Line Start with Line End for VC4 and DT4 (cleared on read) Mask */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI4(value) (CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI4_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI4_Pos)) /* Assigment of value for ERR_L_BNDRY_MATCH_DI4 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI5_Pos _UINT32_(5)                                          /* (CSI_INT_ST_LINE) Error Matching Line Start with Line End for VC5 and DT5 (cleared on read) Position */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI5_Msk (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI5_Pos) /* (CSI_INT_ST_LINE) Error Matching Line Start with Line End for VC5 and DT5 (cleared on read) Mask */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI5(value) (CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI5_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI5_Pos)) /* Assigment of value for ERR_L_BNDRY_MATCH_DI5 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI6_Pos _UINT32_(6)                                          /* (CSI_INT_ST_LINE) Error Matching Line Start with Line End for VC6 and DT6 (cleared on read) Position */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI6_Msk (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI6_Pos) /* (CSI_INT_ST_LINE) Error Matching Line Start with Line End for VC6 and DT6 (cleared on read) Mask */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI6(value) (CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI6_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI6_Pos)) /* Assigment of value for ERR_L_BNDRY_MATCH_DI6 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI7_Pos _UINT32_(7)                                          /* (CSI_INT_ST_LINE) Error Matching Line Start with Line End for VC7 and DT7 (cleared on read) Position */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI7_Msk (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI7_Pos) /* (CSI_INT_ST_LINE) Error Matching Line Start with Line End for VC7 and DT7 (cleared on read) Mask */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI7(value) (CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI7_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI7_Pos)) /* Assigment of value for ERR_L_BNDRY_MATCH_DI7 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI0_Pos     _UINT32_(16)                                         /* (CSI_INT_ST_LINE) Error in the Sequence of Lines for VC0 and DT0 (cleared on read) Position */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI0_Msk     (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_SEQ_DI0_Pos) /* (CSI_INT_ST_LINE) Error in the Sequence of Lines for VC0 and DT0 (cleared on read) Mask */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI0(value)  (CSI_INT_ST_LINE_ERR_L_SEQ_DI0_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_SEQ_DI0_Pos)) /* Assigment of value for ERR_L_SEQ_DI0 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI1_Pos     _UINT32_(17)                                         /* (CSI_INT_ST_LINE) Error in the Sequence of Lines for VC1 and DT1 (cleared on read) Position */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI1_Msk     (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_SEQ_DI1_Pos) /* (CSI_INT_ST_LINE) Error in the Sequence of Lines for VC1 and DT1 (cleared on read) Mask */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI1(value)  (CSI_INT_ST_LINE_ERR_L_SEQ_DI1_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_SEQ_DI1_Pos)) /* Assigment of value for ERR_L_SEQ_DI1 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI2_Pos     _UINT32_(18)                                         /* (CSI_INT_ST_LINE) Error in the Sequence of Lines for VC2 and DT2 (cleared on read) Position */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI2_Msk     (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_SEQ_DI2_Pos) /* (CSI_INT_ST_LINE) Error in the Sequence of Lines for VC2 and DT2 (cleared on read) Mask */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI2(value)  (CSI_INT_ST_LINE_ERR_L_SEQ_DI2_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_SEQ_DI2_Pos)) /* Assigment of value for ERR_L_SEQ_DI2 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI3_Pos     _UINT32_(19)                                         /* (CSI_INT_ST_LINE) Error in the Sequence of Lines for VC3 and DT3 (cleared on read) Position */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI3_Msk     (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_SEQ_DI3_Pos) /* (CSI_INT_ST_LINE) Error in the Sequence of Lines for VC3 and DT3 (cleared on read) Mask */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI3(value)  (CSI_INT_ST_LINE_ERR_L_SEQ_DI3_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_SEQ_DI3_Pos)) /* Assigment of value for ERR_L_SEQ_DI3 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI4_Pos     _UINT32_(20)                                         /* (CSI_INT_ST_LINE) Error in the Sequence of Lines for VC4 and DT4 (cleared on read) Position */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI4_Msk     (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_SEQ_DI4_Pos) /* (CSI_INT_ST_LINE) Error in the Sequence of Lines for VC4 and DT4 (cleared on read) Mask */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI4(value)  (CSI_INT_ST_LINE_ERR_L_SEQ_DI4_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_SEQ_DI4_Pos)) /* Assigment of value for ERR_L_SEQ_DI4 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI5_Pos     _UINT32_(21)                                         /* (CSI_INT_ST_LINE) Error in the Sequence of Lines for VC5 and DT5 (cleared on read) Position */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI5_Msk     (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_SEQ_DI5_Pos) /* (CSI_INT_ST_LINE) Error in the Sequence of Lines for VC5 and DT5 (cleared on read) Mask */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI5(value)  (CSI_INT_ST_LINE_ERR_L_SEQ_DI5_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_SEQ_DI5_Pos)) /* Assigment of value for ERR_L_SEQ_DI5 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI6_Pos     _UINT32_(22)                                         /* (CSI_INT_ST_LINE) Error in the Sequence of Lines for VC6 and DT6 (cleared on read) Position */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI6_Msk     (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_SEQ_DI6_Pos) /* (CSI_INT_ST_LINE) Error in the Sequence of Lines for VC6 and DT6 (cleared on read) Mask */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI6(value)  (CSI_INT_ST_LINE_ERR_L_SEQ_DI6_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_SEQ_DI6_Pos)) /* Assigment of value for ERR_L_SEQ_DI6 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI7_Pos     _UINT32_(23)                                         /* (CSI_INT_ST_LINE) Error in the Sequence of Lines for VC7 and DT7 (cleared on read) Position */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI7_Msk     (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_SEQ_DI7_Pos) /* (CSI_INT_ST_LINE) Error in the Sequence of Lines for VC7 and DT7 (cleared on read) Mask */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI7(value)  (CSI_INT_ST_LINE_ERR_L_SEQ_DI7_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_SEQ_DI7_Pos)) /* Assigment of value for ERR_L_SEQ_DI7 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_Msk                   _UINT32_(0x00FF00FF)                                 /* (CSI_INT_ST_LINE) Register Mask  */

#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI_Pos _UINT32_(0)                                          /* (CSI_INT_ST_LINE Position) Error Matching Line Start with Line End for VCx and DTx (cleared on read) */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI_Msk (_UINT32_(0xFF) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI_Pos) /* (CSI_INT_ST_LINE Mask) ERR_L_BNDRY_MATCH_DI */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI(value) (CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI_Pos)) 
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI_Pos      _UINT32_(16)                                         /* (CSI_INT_ST_LINE Position) Error in the Sequence of Lines for VC7 and DT7 (cleared on read) */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI_Msk      (_UINT32_(0xFF) << CSI_INT_ST_LINE_ERR_L_SEQ_DI_Pos) /* (CSI_INT_ST_LINE Mask) ERR_L_SEQ_DI */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI(value)   (CSI_INT_ST_LINE_ERR_L_SEQ_DI_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_SEQ_DI_Pos)) 

/* -------- CSI_INT_MSK_LINE : (CSI Offset: 0x134) (R/W 32) CSI Line Error Interrupt Mask Register -------- */
#define CSI_INT_MSK_LINE_RESETVALUE           _UINT32_(0x00)                                       /*  (CSI_INT_MSK_LINE) CSI Line Error Interrupt Mask Register  Reset Value */

#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI0_Pos _UINT32_(0)                                          /* (CSI_INT_MSK_LINE) Error Matching Line Start with Line End for VC0 and DT0 Interrupt Mask Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI0_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI0_Pos) /* (CSI_INT_MSK_LINE) Error Matching Line Start with Line End for VC0 and DT0 Interrupt Mask Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI0(value) (CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI0_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI0_Pos)) /* Assigment of value for MASK_ERR_L_BNDRY_MATCH_DI0 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI1_Pos _UINT32_(1)                                          /* (CSI_INT_MSK_LINE) Error Matching Line Start with Line End for VC1 and DT1 Interrupt Mask Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI1_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI1_Pos) /* (CSI_INT_MSK_LINE) Error Matching Line Start with Line End for VC1 and DT1 Interrupt Mask Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI1(value) (CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI1_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI1_Pos)) /* Assigment of value for MASK_ERR_L_BNDRY_MATCH_DI1 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI2_Pos _UINT32_(2)                                          /* (CSI_INT_MSK_LINE) Error Matching Line Start with Line End for VC2 and DT2 Interrupt Mask Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI2_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI2_Pos) /* (CSI_INT_MSK_LINE) Error Matching Line Start with Line End for VC2 and DT2 Interrupt Mask Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI2(value) (CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI2_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI2_Pos)) /* Assigment of value for MASK_ERR_L_BNDRY_MATCH_DI2 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI3_Pos _UINT32_(3)                                          /* (CSI_INT_MSK_LINE) Error Matching Line Start with Line End for VC3 and DT3 Interrupt Mask Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI3_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI3_Pos) /* (CSI_INT_MSK_LINE) Error Matching Line Start with Line End for VC3 and DT3 Interrupt Mask Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI3(value) (CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI3_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI3_Pos)) /* Assigment of value for MASK_ERR_L_BNDRY_MATCH_DI3 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI4_Pos _UINT32_(4)                                          /* (CSI_INT_MSK_LINE) Error Matching Line Start with Line End for VC4 and DT4 Interrupt Mask Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI4_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI4_Pos) /* (CSI_INT_MSK_LINE) Error Matching Line Start with Line End for VC4 and DT4 Interrupt Mask Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI4(value) (CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI4_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI4_Pos)) /* Assigment of value for MASK_ERR_L_BNDRY_MATCH_DI4 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI5_Pos _UINT32_(5)                                          /* (CSI_INT_MSK_LINE) Error Matching Line Start with Line End for VC5 and DT5 Interrupt Mask Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI5_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI5_Pos) /* (CSI_INT_MSK_LINE) Error Matching Line Start with Line End for VC5 and DT5 Interrupt Mask Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI5(value) (CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI5_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI5_Pos)) /* Assigment of value for MASK_ERR_L_BNDRY_MATCH_DI5 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI6_Pos _UINT32_(6)                                          /* (CSI_INT_MSK_LINE) Error Matching Line Start with Line End for VC6 and DT6 Interrupt Mask Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI6_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI6_Pos) /* (CSI_INT_MSK_LINE) Error Matching Line Start with Line End for VC6 and DT6 Interrupt Mask Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI6(value) (CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI6_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI6_Pos)) /* Assigment of value for MASK_ERR_L_BNDRY_MATCH_DI6 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI7_Pos _UINT32_(7)                                          /* (CSI_INT_MSK_LINE) Error Matching Line Start with Line End for VC7 and DT7 Interrupt Mask Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI7_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI7_Pos) /* (CSI_INT_MSK_LINE) Error Matching Line Start with Line End for VC7 and DT7 Interrupt Mask Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI7(value) (CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI7_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI7_Pos)) /* Assigment of value for MASK_ERR_L_BNDRY_MATCH_DI7 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI0_Pos _UINT32_(16)                                         /* (CSI_INT_MSK_LINE) Error in the Sequence of Lines for VC0 and DT0 Interrupt Mask Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI0_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI0_Pos) /* (CSI_INT_MSK_LINE) Error in the Sequence of Lines for VC0 and DT0 Interrupt Mask Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI0(value) (CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI0_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI0_Pos)) /* Assigment of value for MASK_ERR_L_SEQ_DI0 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI1_Pos _UINT32_(17)                                         /* (CSI_INT_MSK_LINE) Error in the Sequence of Lines for VC1 and DT1 Interrupt Mask Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI1_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI1_Pos) /* (CSI_INT_MSK_LINE) Error in the Sequence of Lines for VC1 and DT1 Interrupt Mask Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI1(value) (CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI1_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI1_Pos)) /* Assigment of value for MASK_ERR_L_SEQ_DI1 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI2_Pos _UINT32_(18)                                         /* (CSI_INT_MSK_LINE) Error in the Sequence of Lines for VC2 and DT2 Interrupt Mask Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI2_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI2_Pos) /* (CSI_INT_MSK_LINE) Error in the Sequence of Lines for VC2 and DT2 Interrupt Mask Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI2(value) (CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI2_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI2_Pos)) /* Assigment of value for MASK_ERR_L_SEQ_DI2 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI3_Pos _UINT32_(19)                                         /* (CSI_INT_MSK_LINE) Error in the Sequence of Lines for VC3 and DT3 Interrupt Mask Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI3_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI3_Pos) /* (CSI_INT_MSK_LINE) Error in the Sequence of Lines for VC3 and DT3 Interrupt Mask Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI3(value) (CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI3_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI3_Pos)) /* Assigment of value for MASK_ERR_L_SEQ_DI3 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI4_Pos _UINT32_(20)                                         /* (CSI_INT_MSK_LINE) Error in the Sequence of Lines for VC4 and DT4 Interrupt Mask Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI4_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI4_Pos) /* (CSI_INT_MSK_LINE) Error in the Sequence of Lines for VC4 and DT4 Interrupt Mask Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI4(value) (CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI4_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI4_Pos)) /* Assigment of value for MASK_ERR_L_SEQ_DI4 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI5_Pos _UINT32_(21)                                         /* (CSI_INT_MSK_LINE) Error in the Sequence of Lines for VC5 and DT5 Interrupt Mask Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI5_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI5_Pos) /* (CSI_INT_MSK_LINE) Error in the Sequence of Lines for VC5 and DT5 Interrupt Mask Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI5(value) (CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI5_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI5_Pos)) /* Assigment of value for MASK_ERR_L_SEQ_DI5 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI6_Pos _UINT32_(22)                                         /* (CSI_INT_MSK_LINE) Error in the Sequence of Lines for VC6 and DT6 Interrupt Mask Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI6_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI6_Pos) /* (CSI_INT_MSK_LINE) Error in the Sequence of Lines for VC6 and DT6 Interrupt Mask Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI6(value) (CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI6_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI6_Pos)) /* Assigment of value for MASK_ERR_L_SEQ_DI6 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI7_Pos _UINT32_(23)                                         /* (CSI_INT_MSK_LINE) Error in the Sequence of Lines for VC7 and DT7 Interrupt Mask Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI7_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI7_Pos) /* (CSI_INT_MSK_LINE) Error in the Sequence of Lines for VC7 and DT7 Interrupt Mask Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI7(value) (CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI7_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI7_Pos)) /* Assigment of value for MASK_ERR_L_SEQ_DI7 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_Msk                  _UINT32_(0x00FF00FF)                                 /* (CSI_INT_MSK_LINE) Register Mask  */

#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI_Pos _UINT32_(0)                                          /* (CSI_INT_MSK_LINE Position) Error Matching Line Start with Line End for VCx and DTx Interrupt Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI_Msk (_UINT32_(0xFF) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI_Pos) /* (CSI_INT_MSK_LINE Mask) MASK_ERR_L_BNDRY_MATCH_DI */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI(value) (CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI_Pos)) 
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI_Pos _UINT32_(16)                                         /* (CSI_INT_MSK_LINE Position) Error in the Sequence of Lines for VC7 and DT7 Interrupt Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI_Msk (_UINT32_(0xFF) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI_Pos) /* (CSI_INT_MSK_LINE Mask) MASK_ERR_L_SEQ_DI */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI(value) (CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI_Pos)) 

/* -------- CSI_INT_FORCE_LINE : (CSI Offset: 0x138) (R/W 32) CSI Line Error Interrupt Force Register -------- */
#define CSI_INT_FORCE_LINE_RESETVALUE         _UINT32_(0x00)                                       /*  (CSI_INT_FORCE_LINE) CSI Line Error Interrupt Force Register  Reset Value */

#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI0_Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_LINE) Force Error Matching Line Start with Line End for VC0 and DT0 Interrupt Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI0_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI0_Pos) /* (CSI_INT_FORCE_LINE) Force Error Matching Line Start with Line End for VC0 and DT0 Interrupt Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI0(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI0_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI0_Pos)) /* Assigment of value for FORCE_ERR_L_BNDRY_MATCH_DI0 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI1_Pos _UINT32_(1)                                          /* (CSI_INT_FORCE_LINE) Force Error Matching Line Start with Line End for VC1 and DT1 Interrupt Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI1_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI1_Pos) /* (CSI_INT_FORCE_LINE) Force Error Matching Line Start with Line End for VC1 and DT1 Interrupt Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI1(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI1_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI1_Pos)) /* Assigment of value for FORCE_ERR_L_BNDRY_MATCH_DI1 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI2_Pos _UINT32_(2)                                          /* (CSI_INT_FORCE_LINE) Force Error Matching Line Start with Line End for VC2 and DT2 Interrupt Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI2_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI2_Pos) /* (CSI_INT_FORCE_LINE) Force Error Matching Line Start with Line End for VC2 and DT2 Interrupt Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI2(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI2_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI2_Pos)) /* Assigment of value for FORCE_ERR_L_BNDRY_MATCH_DI2 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI3_Pos _UINT32_(3)                                          /* (CSI_INT_FORCE_LINE) Force Error Matching Line Start with Line End for VC3 and DT3 Interrupt Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI3_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI3_Pos) /* (CSI_INT_FORCE_LINE) Force Error Matching Line Start with Line End for VC3 and DT3 Interrupt Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI3(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI3_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI3_Pos)) /* Assigment of value for FORCE_ERR_L_BNDRY_MATCH_DI3 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI4_Pos _UINT32_(4)                                          /* (CSI_INT_FORCE_LINE) Force Error Matching Line Start with Line End for VC4 and DT4 Interrupt Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI4_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI4_Pos) /* (CSI_INT_FORCE_LINE) Force Error Matching Line Start with Line End for VC4 and DT4 Interrupt Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI4(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI4_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI4_Pos)) /* Assigment of value for FORCE_ERR_L_BNDRY_MATCH_DI4 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI5_Pos _UINT32_(5)                                          /* (CSI_INT_FORCE_LINE) Force Error Matching Line Start with Line End for VC5 and DT5 Interrupt Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI5_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI5_Pos) /* (CSI_INT_FORCE_LINE) Force Error Matching Line Start with Line End for VC5 and DT5 Interrupt Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI5(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI5_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI5_Pos)) /* Assigment of value for FORCE_ERR_L_BNDRY_MATCH_DI5 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI6_Pos _UINT32_(6)                                          /* (CSI_INT_FORCE_LINE) Force Error Matching Line Start with Line End for VC6 and DT6 Interrupt Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI6_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI6_Pos) /* (CSI_INT_FORCE_LINE) Force Error Matching Line Start with Line End for VC6 and DT6 Interrupt Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI6(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI6_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI6_Pos)) /* Assigment of value for FORCE_ERR_L_BNDRY_MATCH_DI6 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI7_Pos _UINT32_(7)                                          /* (CSI_INT_FORCE_LINE) Force Error Matching Line Start with Line End for VC7 and DT7 Interrupt Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI7_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI7_Pos) /* (CSI_INT_FORCE_LINE) Force Error Matching Line Start with Line End for VC7 and DT7 Interrupt Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI7(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI7_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI7_Pos)) /* Assigment of value for FORCE_ERR_L_BNDRY_MATCH_DI7 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI0_Pos _UINT32_(16)                                         /* (CSI_INT_FORCE_LINE) Force Error in the Sequence of Lines for VC0 and DT0 Interrupt Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI0_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI0_Pos) /* (CSI_INT_FORCE_LINE) Force Error in the Sequence of Lines for VC0 and DT0 Interrupt Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI0(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI0_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI0_Pos)) /* Assigment of value for FORCE_ERR_L_SEQ_DI0 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI1_Pos _UINT32_(17)                                         /* (CSI_INT_FORCE_LINE) Force Error in the Sequence of Lines for VC1 and DT1 Interrupt Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI1_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI1_Pos) /* (CSI_INT_FORCE_LINE) Force Error in the Sequence of Lines for VC1 and DT1 Interrupt Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI1(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI1_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI1_Pos)) /* Assigment of value for FORCE_ERR_L_SEQ_DI1 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI2_Pos _UINT32_(18)                                         /* (CSI_INT_FORCE_LINE) Force Error in the Sequence of Lines for VC2 and DT2 Interrupt Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI2_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI2_Pos) /* (CSI_INT_FORCE_LINE) Force Error in the Sequence of Lines for VC2 and DT2 Interrupt Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI2(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI2_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI2_Pos)) /* Assigment of value for FORCE_ERR_L_SEQ_DI2 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI3_Pos _UINT32_(19)                                         /* (CSI_INT_FORCE_LINE) Force Error in the Sequence of Lines for VC3 and DT3 Interrupt Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI3_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI3_Pos) /* (CSI_INT_FORCE_LINE) Force Error in the Sequence of Lines for VC3 and DT3 Interrupt Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI3(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI3_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI3_Pos)) /* Assigment of value for FORCE_ERR_L_SEQ_DI3 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI4_Pos _UINT32_(20)                                         /* (CSI_INT_FORCE_LINE) Force Error in the Sequence of Lines for VC4 and DT4 Interrupt Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI4_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI4_Pos) /* (CSI_INT_FORCE_LINE) Force Error in the Sequence of Lines for VC4 and DT4 Interrupt Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI4(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI4_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI4_Pos)) /* Assigment of value for FORCE_ERR_L_SEQ_DI4 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI5_Pos _UINT32_(21)                                         /* (CSI_INT_FORCE_LINE) Force Error in the Sequence of Lines for VC5 and DT5 Interrupt Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI5_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI5_Pos) /* (CSI_INT_FORCE_LINE) Force Error in the Sequence of Lines for VC5 and DT5 Interrupt Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI5(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI5_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI5_Pos)) /* Assigment of value for FORCE_ERR_L_SEQ_DI5 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI6_Pos _UINT32_(22)                                         /* (CSI_INT_FORCE_LINE) Force Error in the Sequence of Lines for VC6 and DT6 Interrupt Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI6_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI6_Pos) /* (CSI_INT_FORCE_LINE) Force Error in the Sequence of Lines for VC6 and DT6 Interrupt Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI6(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI6_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI6_Pos)) /* Assigment of value for FORCE_ERR_L_SEQ_DI6 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI7_Pos _UINT32_(23)                                         /* (CSI_INT_FORCE_LINE) Force Error in the Sequence of Lines for VC7 and DT7 Interrupt Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI7_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI7_Pos) /* (CSI_INT_FORCE_LINE) Force Error in the Sequence of Lines for VC7 and DT7 Interrupt Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI7(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI7_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI7_Pos)) /* Assigment of value for FORCE_ERR_L_SEQ_DI7 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_Msk                _UINT32_(0x00FF00FF)                                 /* (CSI_INT_FORCE_LINE) Register Mask  */

#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI_Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_LINE Position) Force Error Matching Line Start with Line End for VCx and DTx Interrupt */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI_Msk (_UINT32_(0xFF) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI_Pos) /* (CSI_INT_FORCE_LINE Mask) FORCE_ERR_L_BNDRY_MATCH_DI */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI_Pos)) 
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI_Pos _UINT32_(16)                                         /* (CSI_INT_FORCE_LINE Position) Force Error in the Sequence of Lines for VC7 and DT7 Interrupt */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI_Msk (_UINT32_(0xFF) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI_Pos) /* (CSI_INT_FORCE_LINE Mask) FORCE_ERR_L_SEQ_DI */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI_Pos)) 

/* -------- CSI_SCRAMBLING : (CSI Offset: 0x300) ( R/ 32) CSI Descrambler Configuration Register -------- */
#define CSI_SCRAMBLING_RESETVALUE             _UINT32_(0x00)                                       /*  (CSI_SCRAMBLING) CSI Descrambler Configuration Register  Reset Value */

#define CSI_SCRAMBLING_SCRAMBLE_ENABLE_Pos    _UINT32_(0)                                          /* (CSI_SCRAMBLING) Data De-scrambling Enable Position */
#define CSI_SCRAMBLING_SCRAMBLE_ENABLE_Msk    (_UINT32_(0x1) << CSI_SCRAMBLING_SCRAMBLE_ENABLE_Pos) /* (CSI_SCRAMBLING) Data De-scrambling Enable Mask */
#define CSI_SCRAMBLING_SCRAMBLE_ENABLE(value) (CSI_SCRAMBLING_SCRAMBLE_ENABLE_Msk & (_UINT32_(value) << CSI_SCRAMBLING_SCRAMBLE_ENABLE_Pos)) /* Assigment of value for SCRAMBLE_ENABLE in the CSI_SCRAMBLING register */
#define   CSI_SCRAMBLING_SCRAMBLE_ENABLE_0_Val _UINT32_(0x0)                                        /* (CSI_SCRAMBLING) No data de-scrambling.  */
#define   CSI_SCRAMBLING_SCRAMBLE_ENABLE_1_Val _UINT32_(0x1)                                        /* (CSI_SCRAMBLING) Activates the data de-scrambling.  */
#define CSI_SCRAMBLING_SCRAMBLE_ENABLE_0      (CSI_SCRAMBLING_SCRAMBLE_ENABLE_0_Val << CSI_SCRAMBLING_SCRAMBLE_ENABLE_Pos) /* (CSI_SCRAMBLING) No data de-scrambling. Position  */
#define CSI_SCRAMBLING_SCRAMBLE_ENABLE_1      (CSI_SCRAMBLING_SCRAMBLE_ENABLE_1_Val << CSI_SCRAMBLING_SCRAMBLE_ENABLE_Pos) /* (CSI_SCRAMBLING) Activates the data de-scrambling. Position  */
#define CSI_SCRAMBLING_Msk                    _UINT32_(0x00000001)                                 /* (CSI_SCRAMBLING) Register Mask  */


/* -------- CSI_SCRAMBLING_SEED0 : (CSI Offset: 0x304) (R/W 32) CSI Lane 0 Scrambling Seed Register -------- */
#define CSI_SCRAMBLING_SEED0_RESETVALUE       _UINT32_(0x00)                                       /*  (CSI_SCRAMBLING_SEED0) CSI Lane 0 Scrambling Seed Register  Reset Value */

#define CSI_SCRAMBLING_SEED0_SCRAMBLE_SEED_LANE0_Pos _UINT32_(0)                                          /* (CSI_SCRAMBLING_SEED0) Data Lane 0 Descrambler Seed Position */
#define CSI_SCRAMBLING_SEED0_SCRAMBLE_SEED_LANE0_Msk (_UINT32_(0xFFFF) << CSI_SCRAMBLING_SEED0_SCRAMBLE_SEED_LANE0_Pos) /* (CSI_SCRAMBLING_SEED0) Data Lane 0 Descrambler Seed Mask */
#define CSI_SCRAMBLING_SEED0_SCRAMBLE_SEED_LANE0(value) (CSI_SCRAMBLING_SEED0_SCRAMBLE_SEED_LANE0_Msk & (_UINT32_(value) << CSI_SCRAMBLING_SEED0_SCRAMBLE_SEED_LANE0_Pos)) /* Assigment of value for SCRAMBLE_SEED_LANE0 in the CSI_SCRAMBLING_SEED0 register */
#define CSI_SCRAMBLING_SEED0_Msk              _UINT32_(0x0000FFFF)                                 /* (CSI_SCRAMBLING_SEED0) Register Mask  */


/* -------- CSI_SCRAMBLING_SEED1 : (CSI Offset: 0x308) (R/W 32) CSI Lane 1 Scrambling Seed Register -------- */
#define CSI_SCRAMBLING_SEED1_RESETVALUE       _UINT32_(0x00)                                       /*  (CSI_SCRAMBLING_SEED1) CSI Lane 1 Scrambling Seed Register  Reset Value */

#define CSI_SCRAMBLING_SEED1_SCRAMBLE_SEED_LANE1_Pos _UINT32_(0)                                          /* (CSI_SCRAMBLING_SEED1) Data Lane 1 Descrambler Seed Position */
#define CSI_SCRAMBLING_SEED1_SCRAMBLE_SEED_LANE1_Msk (_UINT32_(0xFFFF) << CSI_SCRAMBLING_SEED1_SCRAMBLE_SEED_LANE1_Pos) /* (CSI_SCRAMBLING_SEED1) Data Lane 1 Descrambler Seed Mask */
#define CSI_SCRAMBLING_SEED1_SCRAMBLE_SEED_LANE1(value) (CSI_SCRAMBLING_SEED1_SCRAMBLE_SEED_LANE1_Msk & (_UINT32_(value) << CSI_SCRAMBLING_SEED1_SCRAMBLE_SEED_LANE1_Pos)) /* Assigment of value for SCRAMBLE_SEED_LANE1 in the CSI_SCRAMBLING_SEED1 register */
#define CSI_SCRAMBLING_SEED1_Msk              _UINT32_(0x0000FFFF)                                 /* (CSI_SCRAMBLING_SEED1) Register Mask  */


/* -------- CSI_SCRAMBLING_SEED2 : (CSI Offset: 0x30C) (R/W 32) CSI Lane 2 Scrambling Seed Register -------- */
#define CSI_SCRAMBLING_SEED2_RESETVALUE       _UINT32_(0x00)                                       /*  (CSI_SCRAMBLING_SEED2) CSI Lane 2 Scrambling Seed Register  Reset Value */

#define CSI_SCRAMBLING_SEED2_SCRAMBLE_SEED_LANE2_Pos _UINT32_(0)                                          /* (CSI_SCRAMBLING_SEED2) Data Lane 2 Descrambler Seed Position */
#define CSI_SCRAMBLING_SEED2_SCRAMBLE_SEED_LANE2_Msk (_UINT32_(0xFFFF) << CSI_SCRAMBLING_SEED2_SCRAMBLE_SEED_LANE2_Pos) /* (CSI_SCRAMBLING_SEED2) Data Lane 2 Descrambler Seed Mask */
#define CSI_SCRAMBLING_SEED2_SCRAMBLE_SEED_LANE2(value) (CSI_SCRAMBLING_SEED2_SCRAMBLE_SEED_LANE2_Msk & (_UINT32_(value) << CSI_SCRAMBLING_SEED2_SCRAMBLE_SEED_LANE2_Pos)) /* Assigment of value for SCRAMBLE_SEED_LANE2 in the CSI_SCRAMBLING_SEED2 register */
#define CSI_SCRAMBLING_SEED2_Msk              _UINT32_(0x0000FFFF)                                 /* (CSI_SCRAMBLING_SEED2) Register Mask  */


/* -------- CSI_SCRAMBLING_SEED3 : (CSI Offset: 0x310) (R/W 32) CSI Lane 3 Scrambling Seed Register -------- */
#define CSI_SCRAMBLING_SEED3_RESETVALUE       _UINT32_(0x00)                                       /*  (CSI_SCRAMBLING_SEED3) CSI Lane 3 Scrambling Seed Register  Reset Value */

#define CSI_SCRAMBLING_SEED3_SCRAMBLE_SEED_LANE3_Pos _UINT32_(0)                                          /* (CSI_SCRAMBLING_SEED3) Data Lane 3 Descrambler Seed Position */
#define CSI_SCRAMBLING_SEED3_SCRAMBLE_SEED_LANE3_Msk (_UINT32_(0xFFFF) << CSI_SCRAMBLING_SEED3_SCRAMBLE_SEED_LANE3_Pos) /* (CSI_SCRAMBLING_SEED3) Data Lane 3 Descrambler Seed Mask */
#define CSI_SCRAMBLING_SEED3_SCRAMBLE_SEED_LANE3(value) (CSI_SCRAMBLING_SEED3_SCRAMBLE_SEED_LANE3_Msk & (_UINT32_(value) << CSI_SCRAMBLING_SEED3_SCRAMBLE_SEED_LANE3_Pos)) /* Assigment of value for SCRAMBLE_SEED_LANE3 in the CSI_SCRAMBLING_SEED3 register */
#define CSI_SCRAMBLING_SEED3_Msk              _UINT32_(0x0000FFFF)                                 /* (CSI_SCRAMBLING_SEED3) Register Mask  */


/** \brief CSI register offsets definitions */
#define CSI_N_LANES_REG_OFST           _UINT32_(0x04)      /* (CSI_N_LANES) CSI Lane Configuration Register Offset */
#define CSI_CSI2_RESETN_REG_OFST       _UINT32_(0x08)      /* (CSI_CSI2_RESETN) CSI Reset Control Register Offset */
#define CSI_INT_ST_MAIN_REG_OFST       _UINT32_(0x0C)      /* (CSI_INT_ST_MAIN) CSI Main Interrupt Status Register Offset */
#define CSI_DATA_IDS_1_REG_OFST        _UINT32_(0x10)      /* (CSI_DATA_IDS_1) CSI Data Identifier Register 1 Offset */
#define CSI_DATA_IDS_2_REG_OFST        _UINT32_(0x14)      /* (CSI_DATA_IDS_2) CSI Data Identifier Register 2 Offset */
#define CSI_PHY_SHUTDOWNZ_REG_OFST     _UINT32_(0x40)      /* (CSI_PHY_SHUTDOWNZ) CSI D-PHY Shutdown Register Offset */
#define CSI_DPHY_RSTZ_REG_OFST         _UINT32_(0x44)      /* (CSI_DPHY_RSTZ) CSI D-PHY Reset Register Offset */
#define CSI_PHY_RX_REG_OFST            _UINT32_(0x48)      /* (CSI_PHY_RX) CSI D-PHY Receive Status Register Offset */
#define CSI_PHY_STOPSTATE_REG_OFST     _UINT32_(0x4C)      /* (CSI_PHY_STOPSTATE) CSI D-PHY Stop State Register Offset */
#define CSI_PHY_TEST_CTRL0_REG_OFST    _UINT32_(0x50)      /* (CSI_PHY_TEST_CTRL0) CSI D-PHY Analog Configuration Control Register Offset */
#define CSI_PHY_TEST_CTRL1_REG_OFST    _UINT32_(0x54)      /* (CSI_PHY_TEST_CTRL1) CSI D-PHY Analog Configuration Data Register Offset */
#define CSI_PHY_CAL_REG_OFST           _UINT32_(0xCC)      /* (CSI_PHY_CAL) CSI D-PHY Calibration Status Register Offset */
#define CSI_INT_ST_PHY_FATAL_REG_OFST  _UINT32_(0xE0)      /* (CSI_INT_ST_PHY_FATAL) CSI D-PHY Fatal Error Interrupt Status Register Offset */
#define CSI_INT_MSK_PHY_FATAL_REG_OFST _UINT32_(0xE4)      /* (CSI_INT_MSK_PHY_FATAL) CSI D-PHY Fatal Error Interrupt Mask Register Offset */
#define CSI_INT_FORCE_PHY_FATAL_REG_OFST _UINT32_(0xE8)      /* (CSI_INT_FORCE_PHY_FATAL) CSI D-PHY Fatal Error Interrupt Force Register Offset */
#define CSI_INT_ST_PKT_FATAL_REG_OFST  _UINT32_(0xF0)      /* (CSI_INT_ST_PKT_FATAL) CSI Packet Fatal Error Interrupt Force Register Offset */
#define CSI_INT_MSK_PKT_FATAL_REG_OFST _UINT32_(0xF4)      /* (CSI_INT_MSK_PKT_FATAL) CSI Packet Fatal Error Interrupt Force Register Offset */
#define CSI_INT_FORCE_PKT_FATAL_REG_OFST _UINT32_(0xF8)      /* (CSI_INT_FORCE_PKT_FATAL) CSI Packet Fatal Error Interrupt Force Register Offset */
#define CSI_INT_ST_FRAME_FATAL_REG_OFST _UINT32_(0x100)     /* (CSI_INT_ST_FRAME_FATAL) CSI Frame Fatal Error Interrupt Force Register Offset */
#define CSI_INT_MSK_FRAME_FATAL_REG_OFST _UINT32_(0x104)     /* (CSI_INT_MSK_FRAME_FATAL) CSI Frame Fatal Error Interrupt Force Register Offset */
#define CSI_INT_FORCE_FRAME_FATAL_REG_OFST _UINT32_(0x108)     /* (CSI_INT_FORCE_FRAME_FATAL) CSI Frame Fatal Error Interrupt Force Register Offset */
#define CSI_INT_ST_PHY_REG_OFST        _UINT32_(0x110)     /* (CSI_INT_ST_PHY) CSI D-PHY Interrupt Status Register Offset */
#define CSI_INT_MSK_PHY_REG_OFST       _UINT32_(0x114)     /* (CSI_INT_MSK_PHY) CSI D-PHY Interrupt Mask Register Offset */
#define CSI_INT_FORCE_PHY_REG_OFST     _UINT32_(0x118)     /* (CSI_INT_FORCE_PHY) CSI D-PHY Interrupt Force Register Offset */
#define CSI_INT_ST_PKT_REG_OFST        _UINT32_(0x120)     /* (CSI_INT_ST_PKT) CSI Packet Interrupt Status Register Offset */
#define CSI_INT_MSK_PKT_REG_OFST       _UINT32_(0x124)     /* (CSI_INT_MSK_PKT) CSI Packet Interrupt Mask Register Offset */
#define CSI_INT_FORCE_PKT_REG_OFST     _UINT32_(0x128)     /* (CSI_INT_FORCE_PKT) CSI Packet Interrupt Force Register Offset */
#define CSI_INT_ST_LINE_REG_OFST       _UINT32_(0x130)     /* (CSI_INT_ST_LINE) CSI Line Error Interrupt Status Register Offset */
#define CSI_INT_MSK_LINE_REG_OFST      _UINT32_(0x134)     /* (CSI_INT_MSK_LINE) CSI Line Error Interrupt Mask Register Offset */
#define CSI_INT_FORCE_LINE_REG_OFST    _UINT32_(0x138)     /* (CSI_INT_FORCE_LINE) CSI Line Error Interrupt Force Register Offset */
#define CSI_SCRAMBLING_REG_OFST        _UINT32_(0x300)     /* (CSI_SCRAMBLING) CSI Descrambler Configuration Register Offset */
#define CSI_SCRAMBLING_SEED0_REG_OFST  _UINT32_(0x304)     /* (CSI_SCRAMBLING_SEED0) CSI Lane 0 Scrambling Seed Register Offset */
#define CSI_SCRAMBLING_SEED1_REG_OFST  _UINT32_(0x308)     /* (CSI_SCRAMBLING_SEED1) CSI Lane 1 Scrambling Seed Register Offset */
#define CSI_SCRAMBLING_SEED2_REG_OFST  _UINT32_(0x30C)     /* (CSI_SCRAMBLING_SEED2) CSI Lane 2 Scrambling Seed Register Offset */
#define CSI_SCRAMBLING_SEED3_REG_OFST  _UINT32_(0x310)     /* (CSI_SCRAMBLING_SEED3) CSI Lane 3 Scrambling Seed Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief CSI register API structure */
typedef struct
{  /* CSI Host Controller */
  __I   uint8_t                        Reserved1[0x04];
  __IO  uint32_t                       CSI_N_LANES;        /**< Offset: 0x04 (R/W  32) CSI Lane Configuration Register */
  __IO  uint32_t                       CSI_CSI2_RESETN;    /**< Offset: 0x08 (R/W  32) CSI Reset Control Register */
  __I   uint32_t                       CSI_INT_ST_MAIN;    /**< Offset: 0x0C (R/   32) CSI Main Interrupt Status Register */
  __IO  uint32_t                       CSI_DATA_IDS_1;     /**< Offset: 0x10 (R/W  32) CSI Data Identifier Register 1 */
  __IO  uint32_t                       CSI_DATA_IDS_2;     /**< Offset: 0x14 (R/W  32) CSI Data Identifier Register 2 */
  __I   uint8_t                        Reserved2[0x28];
  __IO  uint32_t                       CSI_PHY_SHUTDOWNZ;  /**< Offset: 0x40 (R/W  32) CSI D-PHY Shutdown Register */
  __IO  uint32_t                       CSI_DPHY_RSTZ;      /**< Offset: 0x44 (R/W  32) CSI D-PHY Reset Register */
  __I   uint32_t                       CSI_PHY_RX;         /**< Offset: 0x48 (R/   32) CSI D-PHY Receive Status Register */
  __I   uint32_t                       CSI_PHY_STOPSTATE;  /**< Offset: 0x4C (R/   32) CSI D-PHY Stop State Register */
  __IO  uint32_t                       CSI_PHY_TEST_CTRL0; /**< Offset: 0x50 (R/W  32) CSI D-PHY Analog Configuration Control Register */
  __IO  uint32_t                       CSI_PHY_TEST_CTRL1; /**< Offset: 0x54 (R/W  32) CSI D-PHY Analog Configuration Data Register */
  __I   uint8_t                        Reserved3[0x74];
  __I   uint32_t                       CSI_PHY_CAL;        /**< Offset: 0xCC (R/   32) CSI D-PHY Calibration Status Register */
  __I   uint8_t                        Reserved4[0x10];
  __I   uint32_t                       CSI_INT_ST_PHY_FATAL; /**< Offset: 0xE0 (R/   32) CSI D-PHY Fatal Error Interrupt Status Register */
  __IO  uint32_t                       CSI_INT_MSK_PHY_FATAL; /**< Offset: 0xE4 (R/W  32) CSI D-PHY Fatal Error Interrupt Mask Register */
  __IO  uint32_t                       CSI_INT_FORCE_PHY_FATAL; /**< Offset: 0xE8 (R/W  32) CSI D-PHY Fatal Error Interrupt Force Register */
  __I   uint8_t                        Reserved5[0x04];
  __I   uint32_t                       CSI_INT_ST_PKT_FATAL; /**< Offset: 0xF0 (R/   32) CSI Packet Fatal Error Interrupt Force Register */
  __IO  uint32_t                       CSI_INT_MSK_PKT_FATAL; /**< Offset: 0xF4 (R/W  32) CSI Packet Fatal Error Interrupt Force Register */
  __IO  uint32_t                       CSI_INT_FORCE_PKT_FATAL; /**< Offset: 0xF8 (R/W  32) CSI Packet Fatal Error Interrupt Force Register */
  __I   uint8_t                        Reserved6[0x04];
  __I   uint32_t                       CSI_INT_ST_FRAME_FATAL; /**< Offset: 0x100 (R/   32) CSI Frame Fatal Error Interrupt Force Register */
  __IO  uint32_t                       CSI_INT_MSK_FRAME_FATAL; /**< Offset: 0x104 (R/W  32) CSI Frame Fatal Error Interrupt Force Register */
  __IO  uint32_t                       CSI_INT_FORCE_FRAME_FATAL; /**< Offset: 0x108 (R/W  32) CSI Frame Fatal Error Interrupt Force Register */
  __I   uint8_t                        Reserved7[0x04];
  __I   uint32_t                       CSI_INT_ST_PHY;     /**< Offset: 0x110 (R/   32) CSI D-PHY Interrupt Status Register */
  __IO  uint32_t                       CSI_INT_MSK_PHY;    /**< Offset: 0x114 (R/W  32) CSI D-PHY Interrupt Mask Register */
  __IO  uint32_t                       CSI_INT_FORCE_PHY;  /**< Offset: 0x118 (R/W  32) CSI D-PHY Interrupt Force Register */
  __I   uint8_t                        Reserved8[0x04];
  __I   uint32_t                       CSI_INT_ST_PKT;     /**< Offset: 0x120 (R/   32) CSI Packet Interrupt Status Register */
  __IO  uint32_t                       CSI_INT_MSK_PKT;    /**< Offset: 0x124 (R/W  32) CSI Packet Interrupt Mask Register */
  __IO  uint32_t                       CSI_INT_FORCE_PKT;  /**< Offset: 0x128 (R/W  32) CSI Packet Interrupt Force Register */
  __I   uint8_t                        Reserved9[0x04];
  __I   uint32_t                       CSI_INT_ST_LINE;    /**< Offset: 0x130 (R/   32) CSI Line Error Interrupt Status Register */
  __IO  uint32_t                       CSI_INT_MSK_LINE;   /**< Offset: 0x134 (R/W  32) CSI Line Error Interrupt Mask Register */
  __IO  uint32_t                       CSI_INT_FORCE_LINE; /**< Offset: 0x138 (R/W  32) CSI Line Error Interrupt Force Register */
  __I   uint8_t                        Reserved10[0x1C4];
  __I   uint32_t                       CSI_SCRAMBLING;     /**< Offset: 0x300 (R/   32) CSI Descrambler Configuration Register */
  __IO  uint32_t                       CSI_SCRAMBLING_SEED0; /**< Offset: 0x304 (R/W  32) CSI Lane 0 Scrambling Seed Register */
  __IO  uint32_t                       CSI_SCRAMBLING_SEED1; /**< Offset: 0x308 (R/W  32) CSI Lane 1 Scrambling Seed Register */
  __IO  uint32_t                       CSI_SCRAMBLING_SEED2; /**< Offset: 0x30C (R/W  32) CSI Lane 2 Scrambling Seed Register */
  __IO  uint32_t                       CSI_SCRAMBLING_SEED3; /**< Offset: 0x310 (R/W  32) CSI Lane 3 Scrambling Seed Register */
} csi_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X7_CSI_COMPONENT_H_ */
