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

/* file generated from device description version 2023-02-02T10:07:15Z */
#ifndef _SAMA7G_CSI_COMPONENT_H_
#define _SAMA7G_CSI_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR CSI                                          */
/* ************************************************************************** */

/* -------- CSI_VERSION : (CSI Offset: 0x00) ( R/ 32) Read-only register   Contains the version of DWC_mipi_csi2_host coded in 32-bit ASCII code. -------- */
#define CSI_VERSION_VERSION_Pos               _UINT32_(0)                                          /* (CSI_VERSION) This field indicates the version of the DWC_mipi_csi2_host. Position */
#define CSI_VERSION_VERSION_Msk               (_UINT32_(0xFFFFFFFF) << CSI_VERSION_VERSION_Pos)    /* (CSI_VERSION) This field indicates the version of the DWC_mipi_csi2_host. Mask */
#define CSI_VERSION_VERSION(value)            (CSI_VERSION_VERSION_Msk & (_UINT32_(value) << CSI_VERSION_VERSION_Pos)) /* Assigment of value for VERSION in the CSI_VERSION register */
#define CSI_VERSION_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (CSI_VERSION) Register Mask  */


/* -------- CSI_N_LANES : (CSI Offset: 0x04) (R/W 32) Static read and write register   Configures the number of active lanes that the DWC_mipi_csi2_host uses to receive the camera device data. -------- */
#define CSI_N_LANES_N_LANES_Pos               _UINT32_(0)                                          /* (CSI_N_LANES) Number of active data lanes:   -000: 1 Data Lane  -001: 2 Data Lanes  -010: 3 Data Lanes  -011: 4 Data Lanes - Only on D-PHY  -100: 5 Data Lanes - Only on D-PHY  -101: 6 Data Lanes - Only on D-PHY  -110: 7 Data Lanes - Only on D-PHY  -111: 8 Data Lanes - Only on D-PHY  This can only be updated when the PHY lane is in stopstate. Position */
#define CSI_N_LANES_N_LANES_Msk               (_UINT32_(0x7) << CSI_N_LANES_N_LANES_Pos)           /* (CSI_N_LANES) Number of active data lanes:   -000: 1 Data Lane  -001: 2 Data Lanes  -010: 3 Data Lanes  -011: 4 Data Lanes - Only on D-PHY  -100: 5 Data Lanes - Only on D-PHY  -101: 6 Data Lanes - Only on D-PHY  -110: 7 Data Lanes - Only on D-PHY  -111: 8 Data Lanes - Only on D-PHY  This can only be updated when the PHY lane is in stopstate. Mask */
#define CSI_N_LANES_N_LANES(value)            (CSI_N_LANES_N_LANES_Msk & (_UINT32_(value) << CSI_N_LANES_N_LANES_Pos)) /* Assigment of value for N_LANES in the CSI_N_LANES register */
#define CSI_N_LANES_Msk                       _UINT32_(0x00000007)                                 /* (CSI_N_LANES) Register Mask  */


/* -------- CSI_CSI2_RESETN : (CSI Offset: 0x08) (R/W 32) Static read and write register   Controls the DWC_mipi_csi2_host logic reset state. When activated, the internal logic of the controller goes into the reset state. The configuration is not reset to default values with this register, instead, only the internal controller logic is affected. -------- */
#define CSI_CSI2_RESETN_CSI2_RESETN_Pos       _UINT32_(0)                                          /* (CSI_CSI2_RESETN) DWC_mipi_csi2_host reset output. Active Low. Position */
#define CSI_CSI2_RESETN_CSI2_RESETN_Msk       (_UINT32_(0x1) << CSI_CSI2_RESETN_CSI2_RESETN_Pos)   /* (CSI_CSI2_RESETN) DWC_mipi_csi2_host reset output. Active Low. Mask */
#define CSI_CSI2_RESETN_CSI2_RESETN(value)    (CSI_CSI2_RESETN_CSI2_RESETN_Msk & (_UINT32_(value) << CSI_CSI2_RESETN_CSI2_RESETN_Pos)) /* Assigment of value for CSI2_RESETN in the CSI_CSI2_RESETN register */
#define CSI_CSI2_RESETN_Msk                   _UINT32_(0x00000001)                                 /* (CSI_CSI2_RESETN) Register Mask  */


/* -------- CSI_INT_ST_MAIN : (CSI Offset: 0x0C) ( R/ 32) Clear on read register   Contains the status of individual interrupt sources, regardless of the contents of the associated interrupt mask registers, so it is possible to service the interrupt status registers by polling. Reading INT_ST_MAIN register clears the interrupt pin. -------- */
#define CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL_Pos _UINT32_(0)                                          /* (CSI_INT_ST_MAIN) Status of int_st_phy_fatal. Position */
#define CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL_Msk (_UINT32_(0x1) << CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL_Pos) /* (CSI_INT_ST_MAIN) Status of int_st_phy_fatal. Mask */
#define CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL(value) (CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL_Msk & (_UINT32_(value) << CSI_INT_ST_MAIN_STATUS_INT_PHY_FATAL_Pos)) /* Assigment of value for STATUS_INT_PHY_FATAL in the CSI_INT_ST_MAIN register */
#define CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL_Pos _UINT32_(1)                                          /* (CSI_INT_ST_MAIN) Status of int_st_pkt_fatal. Position */
#define CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL_Msk (_UINT32_(0x1) << CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL_Pos) /* (CSI_INT_ST_MAIN) Status of int_st_pkt_fatal. Mask */
#define CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL(value) (CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL_Msk & (_UINT32_(value) << CSI_INT_ST_MAIN_STATUS_INT_PKT_FATAL_Pos)) /* Assigment of value for STATUS_INT_PKT_FATAL in the CSI_INT_ST_MAIN register */
#define CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL_Pos _UINT32_(2)                                          /* (CSI_INT_ST_MAIN) Status of int_st_frame_fatal. Position */
#define CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL_Msk (_UINT32_(0x1) << CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL_Pos) /* (CSI_INT_ST_MAIN) Status of int_st_frame_fatal. Mask */
#define CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL(value) (CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL_Msk & (_UINT32_(value) << CSI_INT_ST_MAIN_STATUS_INT_FRAME_FATAL_Pos)) /* Assigment of value for STATUS_INT_FRAME_FATAL in the CSI_INT_ST_MAIN register */
#define CSI_INT_ST_MAIN_STATUS_INT_PHY_Pos    _UINT32_(16)                                         /* (CSI_INT_ST_MAIN) Status of int_st_phy. Position */
#define CSI_INT_ST_MAIN_STATUS_INT_PHY_Msk    (_UINT32_(0x1) << CSI_INT_ST_MAIN_STATUS_INT_PHY_Pos) /* (CSI_INT_ST_MAIN) Status of int_st_phy. Mask */
#define CSI_INT_ST_MAIN_STATUS_INT_PHY(value) (CSI_INT_ST_MAIN_STATUS_INT_PHY_Msk & (_UINT32_(value) << CSI_INT_ST_MAIN_STATUS_INT_PHY_Pos)) /* Assigment of value for STATUS_INT_PHY in the CSI_INT_ST_MAIN register */
#define CSI_INT_ST_MAIN_STATUS_INT_PKT_Pos    _UINT32_(17)                                         /* (CSI_INT_ST_MAIN) Status of int_st_pkt. Position */
#define CSI_INT_ST_MAIN_STATUS_INT_PKT_Msk    (_UINT32_(0x1) << CSI_INT_ST_MAIN_STATUS_INT_PKT_Pos) /* (CSI_INT_ST_MAIN) Status of int_st_pkt. Mask */
#define CSI_INT_ST_MAIN_STATUS_INT_PKT(value) (CSI_INT_ST_MAIN_STATUS_INT_PKT_Msk & (_UINT32_(value) << CSI_INT_ST_MAIN_STATUS_INT_PKT_Pos)) /* Assigment of value for STATUS_INT_PKT in the CSI_INT_ST_MAIN register */
#define CSI_INT_ST_MAIN_STATUS_INT_LINE_Pos   _UINT32_(18)                                         /* (CSI_INT_ST_MAIN) Status of int_st_line Position */
#define CSI_INT_ST_MAIN_STATUS_INT_LINE_Msk   (_UINT32_(0x1) << CSI_INT_ST_MAIN_STATUS_INT_LINE_Pos) /* (CSI_INT_ST_MAIN) Status of int_st_line Mask */
#define CSI_INT_ST_MAIN_STATUS_INT_LINE(value) (CSI_INT_ST_MAIN_STATUS_INT_LINE_Msk & (_UINT32_(value) << CSI_INT_ST_MAIN_STATUS_INT_LINE_Pos)) /* Assigment of value for STATUS_INT_LINE in the CSI_INT_ST_MAIN register */
#define CSI_INT_ST_MAIN_Msk                   _UINT32_(0x00070007)                                 /* (CSI_INT_ST_MAIN) Register Mask  */


/* -------- CSI_DATA_IDS_1 : (CSI Offset: 0x10) (R/W 32) Static read and write register   Programs the data Ids for matching line error reporting.   Enables up to eight different data Ids that can be identified simultaneously. -------- */
#define CSI_DATA_IDS_1_DI0_DT_Pos             _UINT32_(0)                                          /* (CSI_DATA_IDS_1) Data type for programmed data Id 0. Position */
#define CSI_DATA_IDS_1_DI0_DT_Msk             (_UINT32_(0x3F) << CSI_DATA_IDS_1_DI0_DT_Pos)        /* (CSI_DATA_IDS_1) Data type for programmed data Id 0. Mask */
#define CSI_DATA_IDS_1_DI0_DT(value)          (CSI_DATA_IDS_1_DI0_DT_Msk & (_UINT32_(value) << CSI_DATA_IDS_1_DI0_DT_Pos)) /* Assigment of value for DI0_DT in the CSI_DATA_IDS_1 register */
#define CSI_DATA_IDS_1_DI0_VC_Pos             _UINT32_(6)                                          /* (CSI_DATA_IDS_1) Virtual channel for programmed data Id 0. Position */
#define CSI_DATA_IDS_1_DI0_VC_Msk             (_UINT32_(0x3) << CSI_DATA_IDS_1_DI0_VC_Pos)         /* (CSI_DATA_IDS_1) Virtual channel for programmed data Id 0. Mask */
#define CSI_DATA_IDS_1_DI0_VC(value)          (CSI_DATA_IDS_1_DI0_VC_Msk & (_UINT32_(value) << CSI_DATA_IDS_1_DI0_VC_Pos)) /* Assigment of value for DI0_VC in the CSI_DATA_IDS_1 register */
#define CSI_DATA_IDS_1_DI1_DT_Pos             _UINT32_(8)                                          /* (CSI_DATA_IDS_1) Data type for programmed data Id 1. Position */
#define CSI_DATA_IDS_1_DI1_DT_Msk             (_UINT32_(0x3F) << CSI_DATA_IDS_1_DI1_DT_Pos)        /* (CSI_DATA_IDS_1) Data type for programmed data Id 1. Mask */
#define CSI_DATA_IDS_1_DI1_DT(value)          (CSI_DATA_IDS_1_DI1_DT_Msk & (_UINT32_(value) << CSI_DATA_IDS_1_DI1_DT_Pos)) /* Assigment of value for DI1_DT in the CSI_DATA_IDS_1 register */
#define CSI_DATA_IDS_1_DI1_VC_Pos             _UINT32_(14)                                         /* (CSI_DATA_IDS_1) Virtual channel for programmed data Id 1. Position */
#define CSI_DATA_IDS_1_DI1_VC_Msk             (_UINT32_(0x3) << CSI_DATA_IDS_1_DI1_VC_Pos)         /* (CSI_DATA_IDS_1) Virtual channel for programmed data Id 1. Mask */
#define CSI_DATA_IDS_1_DI1_VC(value)          (CSI_DATA_IDS_1_DI1_VC_Msk & (_UINT32_(value) << CSI_DATA_IDS_1_DI1_VC_Pos)) /* Assigment of value for DI1_VC in the CSI_DATA_IDS_1 register */
#define CSI_DATA_IDS_1_DI2_DT_Pos             _UINT32_(16)                                         /* (CSI_DATA_IDS_1) Data type for programmed Data ID 2. Position */
#define CSI_DATA_IDS_1_DI2_DT_Msk             (_UINT32_(0x3F) << CSI_DATA_IDS_1_DI2_DT_Pos)        /* (CSI_DATA_IDS_1) Data type for programmed Data ID 2. Mask */
#define CSI_DATA_IDS_1_DI2_DT(value)          (CSI_DATA_IDS_1_DI2_DT_Msk & (_UINT32_(value) << CSI_DATA_IDS_1_DI2_DT_Pos)) /* Assigment of value for DI2_DT in the CSI_DATA_IDS_1 register */
#define CSI_DATA_IDS_1_DI2_VC_Pos             _UINT32_(22)                                         /* (CSI_DATA_IDS_1) Virtual channel for programmed data Id 2. Position */
#define CSI_DATA_IDS_1_DI2_VC_Msk             (_UINT32_(0x3) << CSI_DATA_IDS_1_DI2_VC_Pos)         /* (CSI_DATA_IDS_1) Virtual channel for programmed data Id 2. Mask */
#define CSI_DATA_IDS_1_DI2_VC(value)          (CSI_DATA_IDS_1_DI2_VC_Msk & (_UINT32_(value) << CSI_DATA_IDS_1_DI2_VC_Pos)) /* Assigment of value for DI2_VC in the CSI_DATA_IDS_1 register */
#define CSI_DATA_IDS_1_DI3_DT_Pos             _UINT32_(24)                                         /* (CSI_DATA_IDS_1) Data type for programmed data Id 3. Position */
#define CSI_DATA_IDS_1_DI3_DT_Msk             (_UINT32_(0x3F) << CSI_DATA_IDS_1_DI3_DT_Pos)        /* (CSI_DATA_IDS_1) Data type for programmed data Id 3. Mask */
#define CSI_DATA_IDS_1_DI3_DT(value)          (CSI_DATA_IDS_1_DI3_DT_Msk & (_UINT32_(value) << CSI_DATA_IDS_1_DI3_DT_Pos)) /* Assigment of value for DI3_DT in the CSI_DATA_IDS_1 register */
#define CSI_DATA_IDS_1_DI3_VC_Pos             _UINT32_(30)                                         /* (CSI_DATA_IDS_1) Virtual channel for programmed data Id 3. Position */
#define CSI_DATA_IDS_1_DI3_VC_Msk             (_UINT32_(0x3) << CSI_DATA_IDS_1_DI3_VC_Pos)         /* (CSI_DATA_IDS_1) Virtual channel for programmed data Id 3. Mask */
#define CSI_DATA_IDS_1_DI3_VC(value)          (CSI_DATA_IDS_1_DI3_VC_Msk & (_UINT32_(value) << CSI_DATA_IDS_1_DI3_VC_Pos)) /* Assigment of value for DI3_VC in the CSI_DATA_IDS_1 register */
#define CSI_DATA_IDS_1_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (CSI_DATA_IDS_1) Register Mask  */


/* -------- CSI_DATA_IDS_2 : (CSI Offset: 0x14) (R/W 32) Static read and write register   Programs the data Ids for matching line error reporting.   Configures Data ID definition for four additional pairs of data types and virtual channel identifiers. -------- */
#define CSI_DATA_IDS_2_DI4_DT_Pos             _UINT32_(0)                                          /* (CSI_DATA_IDS_2) Data type for programmed data Id 4. Position */
#define CSI_DATA_IDS_2_DI4_DT_Msk             (_UINT32_(0x3F) << CSI_DATA_IDS_2_DI4_DT_Pos)        /* (CSI_DATA_IDS_2) Data type for programmed data Id 4. Mask */
#define CSI_DATA_IDS_2_DI4_DT(value)          (CSI_DATA_IDS_2_DI4_DT_Msk & (_UINT32_(value) << CSI_DATA_IDS_2_DI4_DT_Pos)) /* Assigment of value for DI4_DT in the CSI_DATA_IDS_2 register */
#define CSI_DATA_IDS_2_DI4_VC_Pos             _UINT32_(6)                                          /* (CSI_DATA_IDS_2) Virtual channel for programmed data Id 4. Position */
#define CSI_DATA_IDS_2_DI4_VC_Msk             (_UINT32_(0x3) << CSI_DATA_IDS_2_DI4_VC_Pos)         /* (CSI_DATA_IDS_2) Virtual channel for programmed data Id 4. Mask */
#define CSI_DATA_IDS_2_DI4_VC(value)          (CSI_DATA_IDS_2_DI4_VC_Msk & (_UINT32_(value) << CSI_DATA_IDS_2_DI4_VC_Pos)) /* Assigment of value for DI4_VC in the CSI_DATA_IDS_2 register */
#define CSI_DATA_IDS_2_DI5_DT_Pos             _UINT32_(8)                                          /* (CSI_DATA_IDS_2) Data type for programmed data Id 5. Position */
#define CSI_DATA_IDS_2_DI5_DT_Msk             (_UINT32_(0x3F) << CSI_DATA_IDS_2_DI5_DT_Pos)        /* (CSI_DATA_IDS_2) Data type for programmed data Id 5. Mask */
#define CSI_DATA_IDS_2_DI5_DT(value)          (CSI_DATA_IDS_2_DI5_DT_Msk & (_UINT32_(value) << CSI_DATA_IDS_2_DI5_DT_Pos)) /* Assigment of value for DI5_DT in the CSI_DATA_IDS_2 register */
#define CSI_DATA_IDS_2_DI5_VC_Pos             _UINT32_(14)                                         /* (CSI_DATA_IDS_2) Virtual channel for programmed data Id 5. Position */
#define CSI_DATA_IDS_2_DI5_VC_Msk             (_UINT32_(0x3) << CSI_DATA_IDS_2_DI5_VC_Pos)         /* (CSI_DATA_IDS_2) Virtual channel for programmed data Id 5. Mask */
#define CSI_DATA_IDS_2_DI5_VC(value)          (CSI_DATA_IDS_2_DI5_VC_Msk & (_UINT32_(value) << CSI_DATA_IDS_2_DI5_VC_Pos)) /* Assigment of value for DI5_VC in the CSI_DATA_IDS_2 register */
#define CSI_DATA_IDS_2_DI6_DT_Pos             _UINT32_(16)                                         /* (CSI_DATA_IDS_2) Data type for programmed data Id 6. Position */
#define CSI_DATA_IDS_2_DI6_DT_Msk             (_UINT32_(0x3F) << CSI_DATA_IDS_2_DI6_DT_Pos)        /* (CSI_DATA_IDS_2) Data type for programmed data Id 6. Mask */
#define CSI_DATA_IDS_2_DI6_DT(value)          (CSI_DATA_IDS_2_DI6_DT_Msk & (_UINT32_(value) << CSI_DATA_IDS_2_DI6_DT_Pos)) /* Assigment of value for DI6_DT in the CSI_DATA_IDS_2 register */
#define CSI_DATA_IDS_2_DI6_VC_Pos             _UINT32_(22)                                         /* (CSI_DATA_IDS_2) Virtual channel for programmed data Id 6. Position */
#define CSI_DATA_IDS_2_DI6_VC_Msk             (_UINT32_(0x3) << CSI_DATA_IDS_2_DI6_VC_Pos)         /* (CSI_DATA_IDS_2) Virtual channel for programmed data Id 6. Mask */
#define CSI_DATA_IDS_2_DI6_VC(value)          (CSI_DATA_IDS_2_DI6_VC_Msk & (_UINT32_(value) << CSI_DATA_IDS_2_DI6_VC_Pos)) /* Assigment of value for DI6_VC in the CSI_DATA_IDS_2 register */
#define CSI_DATA_IDS_2_DI7_DT_Pos             _UINT32_(24)                                         /* (CSI_DATA_IDS_2) Data type for programmed data Id 7. Position */
#define CSI_DATA_IDS_2_DI7_DT_Msk             (_UINT32_(0x3F) << CSI_DATA_IDS_2_DI7_DT_Pos)        /* (CSI_DATA_IDS_2) Data type for programmed data Id 7. Mask */
#define CSI_DATA_IDS_2_DI7_DT(value)          (CSI_DATA_IDS_2_DI7_DT_Msk & (_UINT32_(value) << CSI_DATA_IDS_2_DI7_DT_Pos)) /* Assigment of value for DI7_DT in the CSI_DATA_IDS_2 register */
#define CSI_DATA_IDS_2_DI7_VC_Pos             _UINT32_(30)                                         /* (CSI_DATA_IDS_2) Virtual channel for programmed data Id 7. Position */
#define CSI_DATA_IDS_2_DI7_VC_Msk             (_UINT32_(0x3) << CSI_DATA_IDS_2_DI7_VC_Pos)         /* (CSI_DATA_IDS_2) Virtual channel for programmed data Id 7. Mask */
#define CSI_DATA_IDS_2_DI7_VC(value)          (CSI_DATA_IDS_2_DI7_VC_Msk & (_UINT32_(value) << CSI_DATA_IDS_2_DI7_VC_Pos)) /* Assigment of value for DI7_VC in the CSI_DATA_IDS_2 register */
#define CSI_DATA_IDS_2_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (CSI_DATA_IDS_2) Register Mask  */


/* -------- CSI_PHY_SHUTDOWNZ : (CSI Offset: 0x40) (R/W 32) Active low   Controls the PHY Shutdown mode. In this state, the PHY sets the analog and digital circuitry in the Reset state. -------- */
#define CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ_Pos   _UINT32_(0)                                          /* (CSI_PHY_SHUTDOWNZ) Shutdown input. This line is used to place the complete macro in power down. All analog blocks are in power down mode and digital logic is cleared. Active Low. Position */
#define CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ_Msk   (_UINT32_(0x1) << CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ_Pos) /* (CSI_PHY_SHUTDOWNZ) Shutdown input. This line is used to place the complete macro in power down. All analog blocks are in power down mode and digital logic is cleared. Active Low. Mask */
#define CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ(value) (CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ_Msk & (_UINT32_(value) << CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ_Pos)) /* Assigment of value for PHY_SHUTDOWNZ in the CSI_PHY_SHUTDOWNZ register */
#define CSI_PHY_SHUTDOWNZ_Msk                 _UINT32_(0x00000001)                                 /* (CSI_PHY_SHUTDOWNZ) Register Mask  */


/* -------- CSI_DPHY_RSTZ : (CSI Offset: 0x44) (R/W 32) Active low   Controls the PHY Reset mode. in this state, the PHY sets the digital circuitry in the Reset State. -------- */
#define CSI_DPHY_RSTZ_DPHY_RSTZ_Pos           _UINT32_(0)                                          /* (CSI_DPHY_RSTZ) PHY reset output. Active Low. Position */
#define CSI_DPHY_RSTZ_DPHY_RSTZ_Msk           (_UINT32_(0x1) << CSI_DPHY_RSTZ_DPHY_RSTZ_Pos)       /* (CSI_DPHY_RSTZ) PHY reset output. Active Low. Mask */
#define CSI_DPHY_RSTZ_DPHY_RSTZ(value)        (CSI_DPHY_RSTZ_DPHY_RSTZ_Msk & (_UINT32_(value) << CSI_DPHY_RSTZ_DPHY_RSTZ_Pos)) /* Assigment of value for DPHY_RSTZ in the CSI_DPHY_RSTZ register */
#define CSI_DPHY_RSTZ_Msk                     _UINT32_(0x00000001)                                 /* (CSI_DPHY_RSTZ) Register Mask  */


/* -------- CSI_PHY_RX : (CSI Offset: 0x48) ( R/ 32) Read-only register Contains the status of RX-related signals from PHY:  RXULPSESC* RXCLKACTIVEHS (D-PHY)  It contains information such as, if the clock lane is receiving high-speed clock signal, or if the data and clock lanes are in Ultra Low Power Mode (ULPM). -------- */
#define CSI_PHY_RX_PHY_RXULPSESC_0_Pos        _UINT32_(0)                                          /* (CSI_PHY_RX) Lane module 0 has entered the Ultra Low Power mode. Position */
#define CSI_PHY_RX_PHY_RXULPSESC_0_Msk        (_UINT32_(0x1) << CSI_PHY_RX_PHY_RXULPSESC_0_Pos)    /* (CSI_PHY_RX) Lane module 0 has entered the Ultra Low Power mode. Mask */
#define CSI_PHY_RX_PHY_RXULPSESC_0(value)     (CSI_PHY_RX_PHY_RXULPSESC_0_Msk & (_UINT32_(value) << CSI_PHY_RX_PHY_RXULPSESC_0_Pos)) /* Assigment of value for PHY_RXULPSESC_0 in the CSI_PHY_RX register */
#define CSI_PHY_RX_PHY_RXULPSESC_1_Pos        _UINT32_(1)                                          /* (CSI_PHY_RX) Lane module 1 has entered the Ultra Low Power mode Position */
#define CSI_PHY_RX_PHY_RXULPSESC_1_Msk        (_UINT32_(0x1) << CSI_PHY_RX_PHY_RXULPSESC_1_Pos)    /* (CSI_PHY_RX) Lane module 1 has entered the Ultra Low Power mode Mask */
#define CSI_PHY_RX_PHY_RXULPSESC_1(value)     (CSI_PHY_RX_PHY_RXULPSESC_1_Msk & (_UINT32_(value) << CSI_PHY_RX_PHY_RXULPSESC_1_Pos)) /* Assigment of value for PHY_RXULPSESC_1 in the CSI_PHY_RX register */
#define CSI_PHY_RX_PHY_RXULPSCLKNOT_Pos       _UINT32_(16)                                         /* (CSI_PHY_RX) Active Low. This signal indicates that D-PHY Clock Lane module has entered the Ultra Low Power state Position */
#define CSI_PHY_RX_PHY_RXULPSCLKNOT_Msk       (_UINT32_(0x1) << CSI_PHY_RX_PHY_RXULPSCLKNOT_Pos)   /* (CSI_PHY_RX) Active Low. This signal indicates that D-PHY Clock Lane module has entered the Ultra Low Power state Mask */
#define CSI_PHY_RX_PHY_RXULPSCLKNOT(value)    (CSI_PHY_RX_PHY_RXULPSCLKNOT_Msk & (_UINT32_(value) << CSI_PHY_RX_PHY_RXULPSCLKNOT_Pos)) /* Assigment of value for PHY_RXULPSCLKNOT in the CSI_PHY_RX register */
#define CSI_PHY_RX_PHY_RXCLKACTIVEHS_Pos      _UINT32_(17)                                         /* (CSI_PHY_RX) Indicates that D-PHY clock lane is actively receiving a DDR clock Position */
#define CSI_PHY_RX_PHY_RXCLKACTIVEHS_Msk      (_UINT32_(0x1) << CSI_PHY_RX_PHY_RXCLKACTIVEHS_Pos)  /* (CSI_PHY_RX) Indicates that D-PHY clock lane is actively receiving a DDR clock Mask */
#define CSI_PHY_RX_PHY_RXCLKACTIVEHS(value)   (CSI_PHY_RX_PHY_RXCLKACTIVEHS_Msk & (_UINT32_(value) << CSI_PHY_RX_PHY_RXCLKACTIVEHS_Pos)) /* Assigment of value for PHY_RXCLKACTIVEHS in the CSI_PHY_RX register */
#define CSI_PHY_RX_Msk                        _UINT32_(0x00030003)                                 /* (CSI_PHY_RX) Register Mask  */

#define CSI_PHY_RX_PHY_RXULPSESC__Pos         _UINT32_(0)                                          /* (CSI_PHY_RX Position) Lane module x has entered the Ultra Low Power mode. */
#define CSI_PHY_RX_PHY_RXULPSESC__Msk         (_UINT32_(0x3) << CSI_PHY_RX_PHY_RXULPSESC__Pos)     /* (CSI_PHY_RX Mask) PHY_RXULPSESC_ */
#define CSI_PHY_RX_PHY_RXULPSESC_(value)      (CSI_PHY_RX_PHY_RXULPSESC__Msk & (_UINT32_(value) << CSI_PHY_RX_PHY_RXULPSESC__Pos)) 

/* -------- CSI_PHY_STOPSTATE : (CSI Offset: 0x4C) ( R/ 32) Read-only register   Contains the STOPSTATE signal status from PHY. -------- */
#define CSI_PHY_STOPSTATE_PHY_STOPSTATEDATA_0_Pos _UINT32_(0)                                          /* (CSI_PHY_STOPSTATE) Data lane 0 in Stop state. Position */
#define CSI_PHY_STOPSTATE_PHY_STOPSTATEDATA_0_Msk (_UINT32_(0x1) << CSI_PHY_STOPSTATE_PHY_STOPSTATEDATA_0_Pos) /* (CSI_PHY_STOPSTATE) Data lane 0 in Stop state. Mask */
#define CSI_PHY_STOPSTATE_PHY_STOPSTATEDATA_0(value) (CSI_PHY_STOPSTATE_PHY_STOPSTATEDATA_0_Msk & (_UINT32_(value) << CSI_PHY_STOPSTATE_PHY_STOPSTATEDATA_0_Pos)) /* Assigment of value for PHY_STOPSTATEDATA_0 in the CSI_PHY_STOPSTATE register */
#define CSI_PHY_STOPSTATE_PHY_STOPSTATEDATA_1_Pos _UINT32_(1)                                          /* (CSI_PHY_STOPSTATE) Data lane 1 in Stop state Position */
#define CSI_PHY_STOPSTATE_PHY_STOPSTATEDATA_1_Msk (_UINT32_(0x1) << CSI_PHY_STOPSTATE_PHY_STOPSTATEDATA_1_Pos) /* (CSI_PHY_STOPSTATE) Data lane 1 in Stop state Mask */
#define CSI_PHY_STOPSTATE_PHY_STOPSTATEDATA_1(value) (CSI_PHY_STOPSTATE_PHY_STOPSTATEDATA_1_Msk & (_UINT32_(value) << CSI_PHY_STOPSTATE_PHY_STOPSTATEDATA_1_Pos)) /* Assigment of value for PHY_STOPSTATEDATA_1 in the CSI_PHY_STOPSTATE register */
#define CSI_PHY_STOPSTATE_PHY_STOPSTATECLK_Pos _UINT32_(16)                                         /* (CSI_PHY_STOPSTATE) D-PHY Clock lane in Stop state Position */
#define CSI_PHY_STOPSTATE_PHY_STOPSTATECLK_Msk (_UINT32_(0x1) << CSI_PHY_STOPSTATE_PHY_STOPSTATECLK_Pos) /* (CSI_PHY_STOPSTATE) D-PHY Clock lane in Stop state Mask */
#define CSI_PHY_STOPSTATE_PHY_STOPSTATECLK(value) (CSI_PHY_STOPSTATE_PHY_STOPSTATECLK_Msk & (_UINT32_(value) << CSI_PHY_STOPSTATE_PHY_STOPSTATECLK_Pos)) /* Assigment of value for PHY_STOPSTATECLK in the CSI_PHY_STOPSTATE register */
#define CSI_PHY_STOPSTATE_Msk                 _UINT32_(0x00010003)                                 /* (CSI_PHY_STOPSTATE) Register Mask  */

#define CSI_PHY_STOPSTATE_PHY_STOPSTATEDATA__Pos _UINT32_(0)                                          /* (CSI_PHY_STOPSTATE Position) Data lane x in Stop state. */
#define CSI_PHY_STOPSTATE_PHY_STOPSTATEDATA__Msk (_UINT32_(0x3) << CSI_PHY_STOPSTATE_PHY_STOPSTATEDATA__Pos) /* (CSI_PHY_STOPSTATE Mask) PHY_STOPSTATEDATA_ */
#define CSI_PHY_STOPSTATE_PHY_STOPSTATEDATA_(value) (CSI_PHY_STOPSTATE_PHY_STOPSTATEDATA__Msk & (_UINT32_(value) << CSI_PHY_STOPSTATE_PHY_STOPSTATEDATA__Pos)) 

/* -------- CSI_PHY_TEST_CTRL0 : (CSI Offset: 0x50) (R/W 32) Dynamic register   Control for vendor specific interface in the PHY.   Controls the Synopsys D-PHY Test and Control interface. This register controls the TESTCLR and TESTCLK signals. -------- */
#define CSI_PHY_TEST_CTRL0_PHY_TESTCLR_Pos    _UINT32_(0)                                          /* (CSI_PHY_TEST_CTRL0) When active, performs vendor specific interface initialization. Active High.   Note: This line needs an initial high pulse after power up for analog programmability default values to be preset. Position */
#define CSI_PHY_TEST_CTRL0_PHY_TESTCLR_Msk    (_UINT32_(0x1) << CSI_PHY_TEST_CTRL0_PHY_TESTCLR_Pos) /* (CSI_PHY_TEST_CTRL0) When active, performs vendor specific interface initialization. Active High.   Note: This line needs an initial high pulse after power up for analog programmability default values to be preset. Mask */
#define CSI_PHY_TEST_CTRL0_PHY_TESTCLR(value) (CSI_PHY_TEST_CTRL0_PHY_TESTCLR_Msk & (_UINT32_(value) << CSI_PHY_TEST_CTRL0_PHY_TESTCLR_Pos)) /* Assigment of value for PHY_TESTCLR in the CSI_PHY_TEST_CTRL0 register */
#define CSI_PHY_TEST_CTRL0_PHY_TESTCLK_Pos    _UINT32_(1)                                          /* (CSI_PHY_TEST_CTRL0) Clock to capture testdin bus contents into the macro, with testen signal controlling the operation selection. Position */
#define CSI_PHY_TEST_CTRL0_PHY_TESTCLK_Msk    (_UINT32_(0x1) << CSI_PHY_TEST_CTRL0_PHY_TESTCLK_Pos) /* (CSI_PHY_TEST_CTRL0) Clock to capture testdin bus contents into the macro, with testen signal controlling the operation selection. Mask */
#define CSI_PHY_TEST_CTRL0_PHY_TESTCLK(value) (CSI_PHY_TEST_CTRL0_PHY_TESTCLK_Msk & (_UINT32_(value) << CSI_PHY_TEST_CTRL0_PHY_TESTCLK_Pos)) /* Assigment of value for PHY_TESTCLK in the CSI_PHY_TEST_CTRL0 register */
#define CSI_PHY_TEST_CTRL0_Msk                _UINT32_(0x00000003)                                 /* (CSI_PHY_TEST_CTRL0) Register Mask  */


/* -------- CSI_PHY_TEST_CTRL1 : (CSI Offset: 0x54) (R/W 32) Dynamic register   Control for vendor specific interface in the PHY.   Controls the Synopsys D-PHY Test and Control interface. This register controls the TESTENABLE signal and the TESTDIN bus. Reading from this register retrieves the value from TESTDOUT. -------- */
#define CSI_PHY_TEST_CTRL1_PHY_TESTDIN_Pos    _UINT32_(0)                                          /* (CSI_PHY_TEST_CTRL1) Test interface 8-bit data input for programming internal registers and accessing test functionalities. Position */
#define CSI_PHY_TEST_CTRL1_PHY_TESTDIN_Msk    (_UINT32_(0xFF) << CSI_PHY_TEST_CTRL1_PHY_TESTDIN_Pos) /* (CSI_PHY_TEST_CTRL1) Test interface 8-bit data input for programming internal registers and accessing test functionalities. Mask */
#define CSI_PHY_TEST_CTRL1_PHY_TESTDIN(value) (CSI_PHY_TEST_CTRL1_PHY_TESTDIN_Msk & (_UINT32_(value) << CSI_PHY_TEST_CTRL1_PHY_TESTDIN_Pos)) /* Assigment of value for PHY_TESTDIN in the CSI_PHY_TEST_CTRL1 register */
#define CSI_PHY_TEST_CTRL1_PHY_TESTDOUT_Pos   _UINT32_(8)                                          /* (CSI_PHY_TEST_CTRL1) Vendor-specific 8-bit data output for reading data and other probing functionalities. Position */
#define CSI_PHY_TEST_CTRL1_PHY_TESTDOUT_Msk   (_UINT32_(0xFF) << CSI_PHY_TEST_CTRL1_PHY_TESTDOUT_Pos) /* (CSI_PHY_TEST_CTRL1) Vendor-specific 8-bit data output for reading data and other probing functionalities. Mask */
#define CSI_PHY_TEST_CTRL1_PHY_TESTDOUT(value) (CSI_PHY_TEST_CTRL1_PHY_TESTDOUT_Msk & (_UINT32_(value) << CSI_PHY_TEST_CTRL1_PHY_TESTDOUT_Pos)) /* Assigment of value for PHY_TESTDOUT in the CSI_PHY_TEST_CTRL1 register */
#define CSI_PHY_TEST_CTRL1_PHY_TESTEN_Pos     _UINT32_(16)                                         /* (CSI_PHY_TEST_CTRL1) When asserted high, it configures an address write operation on the falling edge of testclk. When asserted low, it configures a data write operation on the rising edge of testclk. Position */
#define CSI_PHY_TEST_CTRL1_PHY_TESTEN_Msk     (_UINT32_(0x1) << CSI_PHY_TEST_CTRL1_PHY_TESTEN_Pos) /* (CSI_PHY_TEST_CTRL1) When asserted high, it configures an address write operation on the falling edge of testclk. When asserted low, it configures a data write operation on the rising edge of testclk. Mask */
#define CSI_PHY_TEST_CTRL1_PHY_TESTEN(value)  (CSI_PHY_TEST_CTRL1_PHY_TESTEN_Msk & (_UINT32_(value) << CSI_PHY_TEST_CTRL1_PHY_TESTEN_Pos)) /* Assigment of value for PHY_TESTEN in the CSI_PHY_TEST_CTRL1 register */
#define CSI_PHY_TEST_CTRL1_Msk                _UINT32_(0x0001FFFF)                                 /* (CSI_PHY_TEST_CTRL1) Register Mask  */


/* -------- CSI_IPI_MODE : (CSI Offset: 0x80) (R/W 32) This register selects how the IPI interface generates the video frame -------- */
#define CSI_IPI_MODE_IPI_MODE_Pos             _UINT32_(0)                                          /* (CSI_IPI_MODE) This field indicates the video mode transmission type as follows:  - 0: Camera timing - 1: Controller timing Position */
#define CSI_IPI_MODE_IPI_MODE_Msk             (_UINT32_(0x1) << CSI_IPI_MODE_IPI_MODE_Pos)         /* (CSI_IPI_MODE) This field indicates the video mode transmission type as follows:  - 0: Camera timing - 1: Controller timing Mask */
#define CSI_IPI_MODE_IPI_MODE(value)          (CSI_IPI_MODE_IPI_MODE_Msk & (_UINT32_(value) << CSI_IPI_MODE_IPI_MODE_Pos)) /* Assigment of value for IPI_MODE in the CSI_IPI_MODE register */
#define CSI_IPI_MODE_IPI_COLOR_COM_Pos        _UINT32_(8)                                          /* (CSI_IPI_MODE) This field indicates if color mode components are delivered as follows:  - 0: 48 bits interface - 1: 16 bits interface Position */
#define CSI_IPI_MODE_IPI_COLOR_COM_Msk        (_UINT32_(0x1) << CSI_IPI_MODE_IPI_COLOR_COM_Pos)    /* (CSI_IPI_MODE) This field indicates if color mode components are delivered as follows:  - 0: 48 bits interface - 1: 16 bits interface Mask */
#define CSI_IPI_MODE_IPI_COLOR_COM(value)     (CSI_IPI_MODE_IPI_COLOR_COM_Msk & (_UINT32_(value) << CSI_IPI_MODE_IPI_COLOR_COM_Pos)) /* Assigment of value for IPI_COLOR_COM in the CSI_IPI_MODE register */
#define CSI_IPI_MODE_Msk                      _UINT32_(0x00000101)                                 /* (CSI_IPI_MODE) Register Mask  */


/* -------- CSI_IPI_VCID : (CSI Offset: 0x84) (R/W 32) This register selects the virtual channel processed by IPI -------- */
#define CSI_IPI_VCID_IP_VCID_Pos              _UINT32_(0)                                          /* (CSI_IPI_VCID) Virtual channel of data to be processed by pixel interface Position */
#define CSI_IPI_VCID_IP_VCID_Msk              (_UINT32_(0x3) << CSI_IPI_VCID_IP_VCID_Pos)          /* (CSI_IPI_VCID) Virtual channel of data to be processed by pixel interface Mask */
#define CSI_IPI_VCID_IP_VCID(value)           (CSI_IPI_VCID_IP_VCID_Msk & (_UINT32_(value) << CSI_IPI_VCID_IP_VCID_Pos)) /* Assigment of value for IP_VCID in the CSI_IPI_VCID register */
#define CSI_IPI_VCID_Msk                      _UINT32_(0x00000003)                                 /* (CSI_IPI_VCID) Register Mask  */


/* -------- CSI_IPI_DATA_TYPE : (CSI Offset: 0x88) (R/W 32) This register selects the data type processed by IPI -------- */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos   _UINT32_(0)                                          /* (CSI_IPI_DATA_TYPE) Data type of data to be processed by pixel interface Position */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Msk   (_UINT32_(0x3F) << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) Data type of data to be processed by pixel interface Mask */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE(value) (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Msk & (_UINT32_(value) << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos)) /* Assigment of value for IPI_DATA_TYPE in the CSI_IPI_DATA_TYPE register */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_FS_Val _UINT32_(0x0)                                        /* (CSI_IPI_DATA_TYPE) Frame Start signaling  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_FE_Val _UINT32_(0x1)                                        /* (CSI_IPI_DATA_TYPE) Frame End signaling  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_LS_Val _UINT32_(0x2)                                        /* (CSI_IPI_DATA_TYPE) Line Start signaling  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_LE_Val _UINT32_(0x3)                                        /* (CSI_IPI_DATA_TYPE) Line End signaling  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_BLANK_Val _UINT32_(0x11)                                       /* (CSI_IPI_DATA_TYPE) Blanking packet  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV420_8_Val _UINT32_(0x18)                                       /* (CSI_IPI_DATA_TYPE) YUV420 8-bit data format  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV420_10_Val _UINT32_(0x19)                                       /* (CSI_IPI_DATA_TYPE) YUV420 10-bit data format  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV420_8L_Val _UINT32_(0x1A)                                       /* (CSI_IPI_DATA_TYPE) YUV420 8-bit Legacy data format  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV420_8C_Val _UINT32_(0x1C)                                       /* (CSI_IPI_DATA_TYPE) YUV420 8-bit (Chroma Shifted Pixel Sampling) data format  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV420_10C_Val _UINT32_(0x1D)                                       /* (CSI_IPI_DATA_TYPE) YUV420 10-bit (Chroma Shifted Pixel Sampling) data format  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV422_8_Val _UINT32_(0x1E)                                       /* (CSI_IPI_DATA_TYPE) YUV422 8-bit data format  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV422_10_Val _UINT32_(0x1F)                                       /* (CSI_IPI_DATA_TYPE) YUV422 10-bit data format  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RGB444_Val _UINT32_(0x20)                                       /* (CSI_IPI_DATA_TYPE) RGB444 data format  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RGB555_Val _UINT32_(0x21)                                       /* (CSI_IPI_DATA_TYPE) RGB555 data format  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RGB565_Val _UINT32_(0x22)                                       /* (CSI_IPI_DATA_TYPE) RGB565 data format  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RGB666_Val _UINT32_(0x23)                                       /* (CSI_IPI_DATA_TYPE) RGB666 data format  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RGB888_Val _UINT32_(0x24)                                       /* (CSI_IPI_DATA_TYPE) RGB888 data format  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RAW6_Val _UINT32_(0x28)                                       /* (CSI_IPI_DATA_TYPE) RAW6 data format  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RAW7_Val _UINT32_(0x29)                                       /* (CSI_IPI_DATA_TYPE) RAW7 data format  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RAW8_Val _UINT32_(0x2A)                                       /* (CSI_IPI_DATA_TYPE) RAW8 data format  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RAW10_Val _UINT32_(0x2B)                                       /* (CSI_IPI_DATA_TYPE) RAW10 data format  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RAW12_Val _UINT32_(0x2C)                                       /* (CSI_IPI_DATA_TYPE) RAW12 data format  */
#define   CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RAW14_Val _UINT32_(0x2D)                                       /* (CSI_IPI_DATA_TYPE) RAW14 data format  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_FS    (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_FS_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) Frame Start signaling Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_FE    (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_FE_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) Frame End signaling Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_LS    (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_LS_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) Line Start signaling Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_LE    (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_LE_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) Line End signaling Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_BLANK (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_BLANK_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) Blanking packet Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV420_8 (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV420_8_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) YUV420 8-bit data format Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV420_10 (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV420_10_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) YUV420 10-bit data format Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV420_8L (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV420_8L_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) YUV420 8-bit Legacy data format Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV420_8C (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV420_8C_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) YUV420 8-bit (Chroma Shifted Pixel Sampling) data format Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV420_10C (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV420_10C_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) YUV420 10-bit (Chroma Shifted Pixel Sampling) data format Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV422_8 (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV422_8_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) YUV422 8-bit data format Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV422_10 (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_YUV422_10_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) YUV422 10-bit data format Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RGB444 (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RGB444_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) RGB444 data format Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RGB555 (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RGB555_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) RGB555 data format Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RGB565 (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RGB565_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) RGB565 data format Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RGB666 (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RGB666_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) RGB666 data format Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RGB888 (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RGB888_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) RGB888 data format Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RAW6  (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RAW6_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) RAW6 data format Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RAW7  (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RAW7_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) RAW7 data format Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RAW8  (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RAW8_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) RAW8 data format Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RAW10 (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RAW10_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) RAW10 data format Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RAW12 (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RAW12_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) RAW12 data format Position  */
#define CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RAW14 (CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_RAW14_Val << CSI_IPI_DATA_TYPE_IPI_DATA_TYPE_Pos) /* (CSI_IPI_DATA_TYPE) RAW14 data format Position  */
#define CSI_IPI_DATA_TYPE_Msk                 _UINT32_(0x0000003F)                                 /* (CSI_IPI_DATA_TYPE) Register Mask  */


/* -------- CSI_IPI_MEM_FLUSH : (CSI Offset: 0x8C) (R/W 32) This register control the flush of IPI memory -------- */
#define CSI_IPI_MEM_FLUSH_IPI_FLUSH_Pos       _UINT32_(0)                                          /* (CSI_IPI_MEM_FLUSH) Flush IPI memory. This bit is auto clear Position */
#define CSI_IPI_MEM_FLUSH_IPI_FLUSH_Msk       (_UINT32_(0x1) << CSI_IPI_MEM_FLUSH_IPI_FLUSH_Pos)   /* (CSI_IPI_MEM_FLUSH) Flush IPI memory. This bit is auto clear Mask */
#define CSI_IPI_MEM_FLUSH_IPI_FLUSH(value)    (CSI_IPI_MEM_FLUSH_IPI_FLUSH_Msk & (_UINT32_(value) << CSI_IPI_MEM_FLUSH_IPI_FLUSH_Pos)) /* Assigment of value for IPI_FLUSH in the CSI_IPI_MEM_FLUSH register */
#define CSI_IPI_MEM_FLUSH_IPI_AUTO_FLUSH_Pos  _UINT32_(8)                                          /* (CSI_IPI_MEM_FLUSH) Memory is automatically flushed at each vsync Position */
#define CSI_IPI_MEM_FLUSH_IPI_AUTO_FLUSH_Msk  (_UINT32_(0x1) << CSI_IPI_MEM_FLUSH_IPI_AUTO_FLUSH_Pos) /* (CSI_IPI_MEM_FLUSH) Memory is automatically flushed at each vsync Mask */
#define CSI_IPI_MEM_FLUSH_IPI_AUTO_FLUSH(value) (CSI_IPI_MEM_FLUSH_IPI_AUTO_FLUSH_Msk & (_UINT32_(value) << CSI_IPI_MEM_FLUSH_IPI_AUTO_FLUSH_Pos)) /* Assigment of value for IPI_AUTO_FLUSH in the CSI_IPI_MEM_FLUSH register */
#define CSI_IPI_MEM_FLUSH_Msk                 _UINT32_(0x00000101)                                 /* (CSI_IPI_MEM_FLUSH) Register Mask  */


/* -------- CSI_IPI_HSA_TIME : (CSI Offset: 0x90) (R/W 32) This register configures the video Horizontal Synchronism Active (HSA) time -------- */
#define CSI_IPI_HSA_TIME_IPI_HSA_TIME_Pos     _UINT32_(0)                                          /* (CSI_IPI_HSA_TIME) This field configures the Horizontal Synchronism Active period in pixclk cycles Position */
#define CSI_IPI_HSA_TIME_IPI_HSA_TIME_Msk     (_UINT32_(0xFFF) << CSI_IPI_HSA_TIME_IPI_HSA_TIME_Pos) /* (CSI_IPI_HSA_TIME) This field configures the Horizontal Synchronism Active period in pixclk cycles Mask */
#define CSI_IPI_HSA_TIME_IPI_HSA_TIME(value)  (CSI_IPI_HSA_TIME_IPI_HSA_TIME_Msk & (_UINT32_(value) << CSI_IPI_HSA_TIME_IPI_HSA_TIME_Pos)) /* Assigment of value for IPI_HSA_TIME in the CSI_IPI_HSA_TIME register */
#define CSI_IPI_HSA_TIME_Msk                  _UINT32_(0x00000FFF)                                 /* (CSI_IPI_HSA_TIME) Register Mask  */


/* -------- CSI_IPI_HBP_TIME : (CSI Offset: 0x94) (R/W 32) This register configures the video Horizontal Back Porch (HBP) time -------- */
#define CSI_IPI_HBP_TIME_IPI_HBP_TIME_Pos     _UINT32_(0)                                          /* (CSI_IPI_HBP_TIME) This field configures the Horizontal Back Porch period in pixclk cycles Position */
#define CSI_IPI_HBP_TIME_IPI_HBP_TIME_Msk     (_UINT32_(0xFFF) << CSI_IPI_HBP_TIME_IPI_HBP_TIME_Pos) /* (CSI_IPI_HBP_TIME) This field configures the Horizontal Back Porch period in pixclk cycles Mask */
#define CSI_IPI_HBP_TIME_IPI_HBP_TIME(value)  (CSI_IPI_HBP_TIME_IPI_HBP_TIME_Msk & (_UINT32_(value) << CSI_IPI_HBP_TIME_IPI_HBP_TIME_Pos)) /* Assigment of value for IPI_HBP_TIME in the CSI_IPI_HBP_TIME register */
#define CSI_IPI_HBP_TIME_Msk                  _UINT32_(0x00000FFF)                                 /* (CSI_IPI_HBP_TIME) Register Mask  */


/* -------- CSI_IPI_HSD_TIME : (CSI Offset: 0x98) (R/W 32) This register configures the video Horizontal Sync Delay (HSD) time -------- */
#define CSI_IPI_HSD_TIME_IPI_HSD_TIME_Pos     _UINT32_(0)                                          /* (CSI_IPI_HSD_TIME) This field configures the Horizontal Sync Porch delay period in pixclk cycles Position */
#define CSI_IPI_HSD_TIME_IPI_HSD_TIME_Msk     (_UINT32_(0xFFF) << CSI_IPI_HSD_TIME_IPI_HSD_TIME_Pos) /* (CSI_IPI_HSD_TIME) This field configures the Horizontal Sync Porch delay period in pixclk cycles Mask */
#define CSI_IPI_HSD_TIME_IPI_HSD_TIME(value)  (CSI_IPI_HSD_TIME_IPI_HSD_TIME_Msk & (_UINT32_(value) << CSI_IPI_HSD_TIME_IPI_HSD_TIME_Pos)) /* Assigment of value for IPI_HSD_TIME in the CSI_IPI_HSD_TIME register */
#define CSI_IPI_HSD_TIME_Msk                  _UINT32_(0x00000FFF)                                 /* (CSI_IPI_HSD_TIME) Register Mask  */


/* -------- CSI_IPI_HLINE_TIME : (CSI Offset: 0x9C) (R/W 32) This register configures the overall time for each video line -------- */
#define CSI_IPI_HLINE_TIME_IPI_HLINE_TIME_Pos _UINT32_(0)                                          /* (CSI_IPI_HLINE_TIME) This field configures the size of the line time counted in pixclk cycles Position */
#define CSI_IPI_HLINE_TIME_IPI_HLINE_TIME_Msk (_UINT32_(0x7FFF) << CSI_IPI_HLINE_TIME_IPI_HLINE_TIME_Pos) /* (CSI_IPI_HLINE_TIME) This field configures the size of the line time counted in pixclk cycles Mask */
#define CSI_IPI_HLINE_TIME_IPI_HLINE_TIME(value) (CSI_IPI_HLINE_TIME_IPI_HLINE_TIME_Msk & (_UINT32_(value) << CSI_IPI_HLINE_TIME_IPI_HLINE_TIME_Pos)) /* Assigment of value for IPI_HLINE_TIME in the CSI_IPI_HLINE_TIME register */
#define CSI_IPI_HLINE_TIME_Msk                _UINT32_(0x00007FFF)                                 /* (CSI_IPI_HLINE_TIME) Register Mask  */


/* -------- CSI_IPI_VSA_LINES : (CSI Offset: 0xB0) (R/W 32) This register configures the Vertical Synchronism Active (VSA) period -------- */
#define CSI_IPI_VSA_LINES_IPI_VSA_LINES_Pos   _UINT32_(0)                                          /* (CSI_IPI_VSA_LINES) This field configures the Vertical Synchronism Active period measured in number of horizontal lines Position */
#define CSI_IPI_VSA_LINES_IPI_VSA_LINES_Msk   (_UINT32_(0x3FF) << CSI_IPI_VSA_LINES_IPI_VSA_LINES_Pos) /* (CSI_IPI_VSA_LINES) This field configures the Vertical Synchronism Active period measured in number of horizontal lines Mask */
#define CSI_IPI_VSA_LINES_IPI_VSA_LINES(value) (CSI_IPI_VSA_LINES_IPI_VSA_LINES_Msk & (_UINT32_(value) << CSI_IPI_VSA_LINES_IPI_VSA_LINES_Pos)) /* Assigment of value for IPI_VSA_LINES in the CSI_IPI_VSA_LINES register */
#define CSI_IPI_VSA_LINES_Msk                 _UINT32_(0x000003FF)                                 /* (CSI_IPI_VSA_LINES) Register Mask  */


/* -------- CSI_IPI_VBP_LINES : (CSI Offset: 0xB4) (R/W 32) This register configures the Vertical Back Porch (VBP) period -------- */
#define CSI_IPI_VBP_LINES_IPI_VBP_LINES_Pos   _UINT32_(0)                                          /* (CSI_IPI_VBP_LINES) This field configures the Vertical Back Porch period measured in number of horizontal lines Position */
#define CSI_IPI_VBP_LINES_IPI_VBP_LINES_Msk   (_UINT32_(0x3FF) << CSI_IPI_VBP_LINES_IPI_VBP_LINES_Pos) /* (CSI_IPI_VBP_LINES) This field configures the Vertical Back Porch period measured in number of horizontal lines Mask */
#define CSI_IPI_VBP_LINES_IPI_VBP_LINES(value) (CSI_IPI_VBP_LINES_IPI_VBP_LINES_Msk & (_UINT32_(value) << CSI_IPI_VBP_LINES_IPI_VBP_LINES_Pos)) /* Assigment of value for IPI_VBP_LINES in the CSI_IPI_VBP_LINES register */
#define CSI_IPI_VBP_LINES_Msk                 _UINT32_(0x000003FF)                                 /* (CSI_IPI_VBP_LINES) Register Mask  */


/* -------- CSI_IPI_VFP_LINES : (CSI Offset: 0xB8) (R/W 32) This register configures the Vertical Front Porch (VFP) period -------- */
#define CSI_IPI_VFP_LINES_IPI_VFP_LINES_Pos   _UINT32_(0)                                          /* (CSI_IPI_VFP_LINES) This field configures the Vertical Front Porch period measured in number of horizontal lines Position */
#define CSI_IPI_VFP_LINES_IPI_VFP_LINES_Msk   (_UINT32_(0x3FF) << CSI_IPI_VFP_LINES_IPI_VFP_LINES_Pos) /* (CSI_IPI_VFP_LINES) This field configures the Vertical Front Porch period measured in number of horizontal lines Mask */
#define CSI_IPI_VFP_LINES_IPI_VFP_LINES(value) (CSI_IPI_VFP_LINES_IPI_VFP_LINES_Msk & (_UINT32_(value) << CSI_IPI_VFP_LINES_IPI_VFP_LINES_Pos)) /* Assigment of value for IPI_VFP_LINES in the CSI_IPI_VFP_LINES register */
#define CSI_IPI_VFP_LINES_Msk                 _UINT32_(0x000003FF)                                 /* (CSI_IPI_VFP_LINES) Register Mask  */


/* -------- CSI_IPI_VACTIVE_LINES : (CSI Offset: 0xBC) (R/W 32) This register configures the vertical resolution of the video -------- */
#define CSI_IPI_VACTIVE_LINES_IPI_VACTIVE_LINES_Pos _UINT32_(0)                                          /* (CSI_IPI_VACTIVE_LINES) This field configures the Vertical Active period measured in number of horizontal lines Position */
#define CSI_IPI_VACTIVE_LINES_IPI_VACTIVE_LINES_Msk (_UINT32_(0x3FFF) << CSI_IPI_VACTIVE_LINES_IPI_VACTIVE_LINES_Pos) /* (CSI_IPI_VACTIVE_LINES) This field configures the Vertical Active period measured in number of horizontal lines Mask */
#define CSI_IPI_VACTIVE_LINES_IPI_VACTIVE_LINES(value) (CSI_IPI_VACTIVE_LINES_IPI_VACTIVE_LINES_Msk & (_UINT32_(value) << CSI_IPI_VACTIVE_LINES_IPI_VACTIVE_LINES_Pos)) /* Assigment of value for IPI_VACTIVE_LINES in the CSI_IPI_VACTIVE_LINES register */
#define CSI_IPI_VACTIVE_LINES_Msk             _UINT32_(0x00003FFF)                                 /* (CSI_IPI_VACTIVE_LINES) Register Mask  */


/* -------- CSI_PHY_CAL : (CSI Offset: 0xCC) ( R/ 32) Clear on read register    Contains the CALIBRATION signal status from Synopsys D-PHY. -------- */
#define CSI_PHY_CAL_RXSKEWCALHS_Pos           _UINT32_(0)                                          /* (CSI_PHY_CAL) A low-to-high transition on rxskewcalhs signal means that the PHY has initiated the de-skew calibration.. Position */
#define CSI_PHY_CAL_RXSKEWCALHS_Msk           (_UINT32_(0x1) << CSI_PHY_CAL_RXSKEWCALHS_Pos)       /* (CSI_PHY_CAL) A low-to-high transition on rxskewcalhs signal means that the PHY has initiated the de-skew calibration.. Mask */
#define CSI_PHY_CAL_RXSKEWCALHS(value)        (CSI_PHY_CAL_RXSKEWCALHS_Msk & (_UINT32_(value) << CSI_PHY_CAL_RXSKEWCALHS_Pos)) /* Assigment of value for RXSKEWCALHS in the CSI_PHY_CAL register */
#define CSI_PHY_CAL_Msk                       _UINT32_(0x00000001)                                 /* (CSI_PHY_CAL) Register Mask  */


/* -------- CSI_INT_ST_PHY_FATAL : (CSI Offset: 0xE0) ( R/ 32) Clear on read register   Groups the fatal interruptions caused by PHY Packet discarded.   Stores the source of the error.   Reading INT_ST_PHY_FATAL register does not clear the interrupt pin. -------- */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0_Pos _UINT32_(0)                                          /* (CSI_INT_ST_PHY_FATAL) Start of transmission error on data lane 0 (no synchronization achieved). Position */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0_Msk (_UINT32_(0x1) << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0_Pos) /* (CSI_INT_ST_PHY_FATAL) Start of transmission error on data lane 0 (no synchronization achieved). Mask */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0(value) (CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0_Msk & (_UINT32_(value) << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_0_Pos)) /* Assigment of value for PHY_ERRSOTSYNCHS_0 in the CSI_INT_ST_PHY_FATAL register */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1_Pos _UINT32_(1)                                          /* (CSI_INT_ST_PHY_FATAL) Start of transmission error on data lane 1 (no synchronization achieved) Position */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1_Msk (_UINT32_(0x1) << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1_Pos) /* (CSI_INT_ST_PHY_FATAL) Start of transmission error on data lane 1 (no synchronization achieved) Mask */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1(value) (CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1_Msk & (_UINT32_(value) << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_1_Pos)) /* Assigment of value for PHY_ERRSOTSYNCHS_1 in the CSI_INT_ST_PHY_FATAL register */
#define CSI_INT_ST_PHY_FATAL_Msk              _UINT32_(0x00000003)                                 /* (CSI_INT_ST_PHY_FATAL) Register Mask  */

#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS__Pos _UINT32_(0)                                          /* (CSI_INT_ST_PHY_FATAL Position) Start of transmission error on data lane x (no synchronization achieved) */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS__Msk (_UINT32_(0x3) << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS__Pos) /* (CSI_INT_ST_PHY_FATAL Mask) PHY_ERRSOTSYNCHS_ */
#define CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS_(value) (CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS__Msk & (_UINT32_(value) << CSI_INT_ST_PHY_FATAL_PHY_ERRSOTSYNCHS__Pos)) 

/* -------- CSI_INT_MSK_PHY_FATAL : (CSI Offset: 0xE4) (R/W 32) Static read and write register    Interrupt mask for INT_ST_PHY_FATAL controls which interrupt status bits will trigger the interrupt pin. Bit at 1 - Enable the interrupt source. Bit at 0 - Interrupt source is masked. -------- */
#define CSI_INT_MSK_PHY_FATAL_MASK_PHY_ERRSOTSYNCHS_0_Pos _UINT32_(0)                                          /* (CSI_INT_MSK_PHY_FATAL) Mask for phy_errsotsynchs_0. Position */
#define CSI_INT_MSK_PHY_FATAL_MASK_PHY_ERRSOTSYNCHS_0_Msk (_UINT32_(0x1) << CSI_INT_MSK_PHY_FATAL_MASK_PHY_ERRSOTSYNCHS_0_Pos) /* (CSI_INT_MSK_PHY_FATAL) Mask for phy_errsotsynchs_0. Mask */
#define CSI_INT_MSK_PHY_FATAL_MASK_PHY_ERRSOTSYNCHS_0(value) (CSI_INT_MSK_PHY_FATAL_MASK_PHY_ERRSOTSYNCHS_0_Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_FATAL_MASK_PHY_ERRSOTSYNCHS_0_Pos)) /* Assigment of value for MASK_PHY_ERRSOTSYNCHS_0 in the CSI_INT_MSK_PHY_FATAL register */
#define CSI_INT_MSK_PHY_FATAL_MASK_PHY_ERRSOTSYNCHS_1_Pos _UINT32_(1)                                          /* (CSI_INT_MSK_PHY_FATAL) Mask for phy_errsotsynchs_1 Position */
#define CSI_INT_MSK_PHY_FATAL_MASK_PHY_ERRSOTSYNCHS_1_Msk (_UINT32_(0x1) << CSI_INT_MSK_PHY_FATAL_MASK_PHY_ERRSOTSYNCHS_1_Pos) /* (CSI_INT_MSK_PHY_FATAL) Mask for phy_errsotsynchs_1 Mask */
#define CSI_INT_MSK_PHY_FATAL_MASK_PHY_ERRSOTSYNCHS_1(value) (CSI_INT_MSK_PHY_FATAL_MASK_PHY_ERRSOTSYNCHS_1_Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_FATAL_MASK_PHY_ERRSOTSYNCHS_1_Pos)) /* Assigment of value for MASK_PHY_ERRSOTSYNCHS_1 in the CSI_INT_MSK_PHY_FATAL register */
#define CSI_INT_MSK_PHY_FATAL_Msk             _UINT32_(0x00000003)                                 /* (CSI_INT_MSK_PHY_FATAL) Register Mask  */

#define CSI_INT_MSK_PHY_FATAL_MASK_PHY_ERRSOTSYNCHS__Pos _UINT32_(0)                                          /* (CSI_INT_MSK_PHY_FATAL Position) Mask for phy_errsotsynchs_x */
#define CSI_INT_MSK_PHY_FATAL_MASK_PHY_ERRSOTSYNCHS__Msk (_UINT32_(0x3) << CSI_INT_MSK_PHY_FATAL_MASK_PHY_ERRSOTSYNCHS__Pos) /* (CSI_INT_MSK_PHY_FATAL Mask) MASK_PHY_ERRSOTSYNCHS_ */
#define CSI_INT_MSK_PHY_FATAL_MASK_PHY_ERRSOTSYNCHS_(value) (CSI_INT_MSK_PHY_FATAL_MASK_PHY_ERRSOTSYNCHS__Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_FATAL_MASK_PHY_ERRSOTSYNCHS__Pos)) 

/* -------- CSI_INT_FORCE_PHY_FATAL : (CSI Offset: 0xE8) (R/W 32) Static read and write register    Interrupt Force register is used for test purposes, and allows triggering INT_ST_PHY_FATAL interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, since it may be extremely complex to generate stimuli for that purpose. -------- */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_PHY_ERRSOTSYNCHS_0_Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_PHY_FATAL) Force phy_errsotsynchs_0. Position */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_PHY_ERRSOTSYNCHS_0_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PHY_FATAL_FORCE_PHY_ERRSOTSYNCHS_0_Pos) /* (CSI_INT_FORCE_PHY_FATAL) Force phy_errsotsynchs_0. Mask */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_PHY_ERRSOTSYNCHS_0(value) (CSI_INT_FORCE_PHY_FATAL_FORCE_PHY_ERRSOTSYNCHS_0_Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FATAL_FORCE_PHY_ERRSOTSYNCHS_0_Pos)) /* Assigment of value for FORCE_PHY_ERRSOTSYNCHS_0 in the CSI_INT_FORCE_PHY_FATAL register */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_PHY_ERRSOTSYNCHS_1_Pos _UINT32_(1)                                          /* (CSI_INT_FORCE_PHY_FATAL) Force phy_errsotsynchs_1 Position */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_PHY_ERRSOTSYNCHS_1_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PHY_FATAL_FORCE_PHY_ERRSOTSYNCHS_1_Pos) /* (CSI_INT_FORCE_PHY_FATAL) Force phy_errsotsynchs_1 Mask */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_PHY_ERRSOTSYNCHS_1(value) (CSI_INT_FORCE_PHY_FATAL_FORCE_PHY_ERRSOTSYNCHS_1_Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FATAL_FORCE_PHY_ERRSOTSYNCHS_1_Pos)) /* Assigment of value for FORCE_PHY_ERRSOTSYNCHS_1 in the CSI_INT_FORCE_PHY_FATAL register */
#define CSI_INT_FORCE_PHY_FATAL_Msk           _UINT32_(0x00000003)                                 /* (CSI_INT_FORCE_PHY_FATAL) Register Mask  */

#define CSI_INT_FORCE_PHY_FATAL_FORCE_PHY_ERRSOTSYNCHS__Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_PHY_FATAL Position) Force phy_errsotsynchs_x */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_PHY_ERRSOTSYNCHS__Msk (_UINT32_(0x3) << CSI_INT_FORCE_PHY_FATAL_FORCE_PHY_ERRSOTSYNCHS__Pos) /* (CSI_INT_FORCE_PHY_FATAL Mask) FORCE_PHY_ERRSOTSYNCHS_ */
#define CSI_INT_FORCE_PHY_FATAL_FORCE_PHY_ERRSOTSYNCHS_(value) (CSI_INT_FORCE_PHY_FATAL_FORCE_PHY_ERRSOTSYNCHS__Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FATAL_FORCE_PHY_ERRSOTSYNCHS__Pos)) 

/* -------- CSI_INT_ST_PKT_FATAL : (CSI Offset: 0xF0) ( R/ 32) Clear on read register    Groups the fatal interruption related with Packet construction. Packet discarded.   Notifies which interruption bit has caused the interruption.   Stores the source of the error.   Reading INT_ST_PKT_FATAL register does not clear the interrupt pin. -------- */
#define CSI_INT_ST_PKT_FATAL_VC0_ERR_CRC_Pos  _UINT32_(0)                                          /* (CSI_INT_ST_PKT_FATAL) Payload Checksum error detected on virtual channel 0. Position */
#define CSI_INT_ST_PKT_FATAL_VC0_ERR_CRC_Msk  (_UINT32_(0x1) << CSI_INT_ST_PKT_FATAL_VC0_ERR_CRC_Pos) /* (CSI_INT_ST_PKT_FATAL) Payload Checksum error detected on virtual channel 0. Mask */
#define CSI_INT_ST_PKT_FATAL_VC0_ERR_CRC(value) (CSI_INT_ST_PKT_FATAL_VC0_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_FATAL_VC0_ERR_CRC_Pos)) /* Assigment of value for VC0_ERR_CRC in the CSI_INT_ST_PKT_FATAL register */
#define CSI_INT_ST_PKT_FATAL_VC1_ERR_CRC_Pos  _UINT32_(1)                                          /* (CSI_INT_ST_PKT_FATAL) Payload Checksum error detected on virtual channel 1. Position */
#define CSI_INT_ST_PKT_FATAL_VC1_ERR_CRC_Msk  (_UINT32_(0x1) << CSI_INT_ST_PKT_FATAL_VC1_ERR_CRC_Pos) /* (CSI_INT_ST_PKT_FATAL) Payload Checksum error detected on virtual channel 1. Mask */
#define CSI_INT_ST_PKT_FATAL_VC1_ERR_CRC(value) (CSI_INT_ST_PKT_FATAL_VC1_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_FATAL_VC1_ERR_CRC_Pos)) /* Assigment of value for VC1_ERR_CRC in the CSI_INT_ST_PKT_FATAL register */
#define CSI_INT_ST_PKT_FATAL_VC2_ERR_CRC_Pos  _UINT32_(2)                                          /* (CSI_INT_ST_PKT_FATAL) Payload Checksum error detected on virtual channel 2. Position */
#define CSI_INT_ST_PKT_FATAL_VC2_ERR_CRC_Msk  (_UINT32_(0x1) << CSI_INT_ST_PKT_FATAL_VC2_ERR_CRC_Pos) /* (CSI_INT_ST_PKT_FATAL) Payload Checksum error detected on virtual channel 2. Mask */
#define CSI_INT_ST_PKT_FATAL_VC2_ERR_CRC(value) (CSI_INT_ST_PKT_FATAL_VC2_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_FATAL_VC2_ERR_CRC_Pos)) /* Assigment of value for VC2_ERR_CRC in the CSI_INT_ST_PKT_FATAL register */
#define CSI_INT_ST_PKT_FATAL_VC3_ERR_CRC_Pos  _UINT32_(3)                                          /* (CSI_INT_ST_PKT_FATAL) Payload Checksum error detected on virtual channel 3. Position */
#define CSI_INT_ST_PKT_FATAL_VC3_ERR_CRC_Msk  (_UINT32_(0x1) << CSI_INT_ST_PKT_FATAL_VC3_ERR_CRC_Pos) /* (CSI_INT_ST_PKT_FATAL) Payload Checksum error detected on virtual channel 3. Mask */
#define CSI_INT_ST_PKT_FATAL_VC3_ERR_CRC(value) (CSI_INT_ST_PKT_FATAL_VC3_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_FATAL_VC3_ERR_CRC_Pos)) /* Assigment of value for VC3_ERR_CRC in the CSI_INT_ST_PKT_FATAL register */
#define CSI_INT_ST_PKT_FATAL_ERR_ECC_DOUBLE_Pos _UINT32_(16)                                         /* (CSI_INT_ST_PKT_FATAL) D-PHY mode : Header ECC contains at least 2 errors, unrecoverable.   C-PHY mode : Header CRC unrecoverable. Position */
#define CSI_INT_ST_PKT_FATAL_ERR_ECC_DOUBLE_Msk (_UINT32_(0x1) << CSI_INT_ST_PKT_FATAL_ERR_ECC_DOUBLE_Pos) /* (CSI_INT_ST_PKT_FATAL) D-PHY mode : Header ECC contains at least 2 errors, unrecoverable.   C-PHY mode : Header CRC unrecoverable. Mask */
#define CSI_INT_ST_PKT_FATAL_ERR_ECC_DOUBLE(value) (CSI_INT_ST_PKT_FATAL_ERR_ECC_DOUBLE_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_FATAL_ERR_ECC_DOUBLE_Pos)) /* Assigment of value for ERR_ECC_DOUBLE in the CSI_INT_ST_PKT_FATAL register */
#define CSI_INT_ST_PKT_FATAL_Msk              _UINT32_(0x0001000F)                                 /* (CSI_INT_ST_PKT_FATAL) Register Mask  */


/* -------- CSI_INT_MSK_PKT_FATAL : (CSI Offset: 0xF4) (R/W 32) Static read and write register    Interrupt mask for INT_ST_PKT_FATAL controls which interrupt status bits will trigger the interrupt pin. Bit at 1 - Enable the interrupt source. Bit at 0 - Interrupt source is masked. -------- */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC0_ERR_CRC_Pos _UINT32_(0)                                          /* (CSI_INT_MSK_PKT_FATAL) Mask for vc0_err_crc. Position */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC0_ERR_CRC_Msk (_UINT32_(0x1) << CSI_INT_MSK_PKT_FATAL_MASK_VC0_ERR_CRC_Pos) /* (CSI_INT_MSK_PKT_FATAL) Mask for vc0_err_crc. Mask */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC0_ERR_CRC(value) (CSI_INT_MSK_PKT_FATAL_MASK_VC0_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_FATAL_MASK_VC0_ERR_CRC_Pos)) /* Assigment of value for MASK_VC0_ERR_CRC in the CSI_INT_MSK_PKT_FATAL register */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC1_ERR_CRC_Pos _UINT32_(1)                                          /* (CSI_INT_MSK_PKT_FATAL) Mask for vc1_err_crc. Position */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC1_ERR_CRC_Msk (_UINT32_(0x1) << CSI_INT_MSK_PKT_FATAL_MASK_VC1_ERR_CRC_Pos) /* (CSI_INT_MSK_PKT_FATAL) Mask for vc1_err_crc. Mask */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC1_ERR_CRC(value) (CSI_INT_MSK_PKT_FATAL_MASK_VC1_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_FATAL_MASK_VC1_ERR_CRC_Pos)) /* Assigment of value for MASK_VC1_ERR_CRC in the CSI_INT_MSK_PKT_FATAL register */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC2_ERR_CRC_Pos _UINT32_(2)                                          /* (CSI_INT_MSK_PKT_FATAL) Mask for vc2_err_crc. Position */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC2_ERR_CRC_Msk (_UINT32_(0x1) << CSI_INT_MSK_PKT_FATAL_MASK_VC2_ERR_CRC_Pos) /* (CSI_INT_MSK_PKT_FATAL) Mask for vc2_err_crc. Mask */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC2_ERR_CRC(value) (CSI_INT_MSK_PKT_FATAL_MASK_VC2_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_FATAL_MASK_VC2_ERR_CRC_Pos)) /* Assigment of value for MASK_VC2_ERR_CRC in the CSI_INT_MSK_PKT_FATAL register */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC3_ERR_CRC_Pos _UINT32_(3)                                          /* (CSI_INT_MSK_PKT_FATAL) Mask for vc3_err_crc. Position */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC3_ERR_CRC_Msk (_UINT32_(0x1) << CSI_INT_MSK_PKT_FATAL_MASK_VC3_ERR_CRC_Pos) /* (CSI_INT_MSK_PKT_FATAL) Mask for vc3_err_crc. Mask */
#define CSI_INT_MSK_PKT_FATAL_MASK_VC3_ERR_CRC(value) (CSI_INT_MSK_PKT_FATAL_MASK_VC3_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_FATAL_MASK_VC3_ERR_CRC_Pos)) /* Assigment of value for MASK_VC3_ERR_CRC in the CSI_INT_MSK_PKT_FATAL register */
#define CSI_INT_MSK_PKT_FATAL_MASK_ERR_ECC_DOUBLE_Pos _UINT32_(16)                                         /* (CSI_INT_MSK_PKT_FATAL) Mask for err_ecc_double. Position */
#define CSI_INT_MSK_PKT_FATAL_MASK_ERR_ECC_DOUBLE_Msk (_UINT32_(0x1) << CSI_INT_MSK_PKT_FATAL_MASK_ERR_ECC_DOUBLE_Pos) /* (CSI_INT_MSK_PKT_FATAL) Mask for err_ecc_double. Mask */
#define CSI_INT_MSK_PKT_FATAL_MASK_ERR_ECC_DOUBLE(value) (CSI_INT_MSK_PKT_FATAL_MASK_ERR_ECC_DOUBLE_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_FATAL_MASK_ERR_ECC_DOUBLE_Pos)) /* Assigment of value for MASK_ERR_ECC_DOUBLE in the CSI_INT_MSK_PKT_FATAL register */
#define CSI_INT_MSK_PKT_FATAL_Msk             _UINT32_(0x0001000F)                                 /* (CSI_INT_MSK_PKT_FATAL) Register Mask  */


/* -------- CSI_INT_FORCE_PKT_FATAL : (CSI Offset: 0xF8) (R/W 32) Static read and write register   Interrupt force register is used for test purposes, and allows triggering INT_ST_PKT_FATAL interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, since it may be extremely complex to generate stimuli for that purpose. -------- */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC0_ERR_CRC_Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_PKT_FATAL) Force vc0_err_crc. Position */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC0_ERR_CRC_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FATAL_FORCE_VC0_ERR_CRC_Pos) /* (CSI_INT_FORCE_PKT_FATAL) Force vc0_err_crc. Mask */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC0_ERR_CRC(value) (CSI_INT_FORCE_PKT_FATAL_FORCE_VC0_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FATAL_FORCE_VC0_ERR_CRC_Pos)) /* Assigment of value for FORCE_VC0_ERR_CRC in the CSI_INT_FORCE_PKT_FATAL register */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC1_ERR_CRC_Pos _UINT32_(1)                                          /* (CSI_INT_FORCE_PKT_FATAL) Force vc1_err_crc. Position */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC1_ERR_CRC_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FATAL_FORCE_VC1_ERR_CRC_Pos) /* (CSI_INT_FORCE_PKT_FATAL) Force vc1_err_crc. Mask */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC1_ERR_CRC(value) (CSI_INT_FORCE_PKT_FATAL_FORCE_VC1_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FATAL_FORCE_VC1_ERR_CRC_Pos)) /* Assigment of value for FORCE_VC1_ERR_CRC in the CSI_INT_FORCE_PKT_FATAL register */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC2_ERR_CRC_Pos _UINT32_(2)                                          /* (CSI_INT_FORCE_PKT_FATAL) Force vc2_err_crc. Position */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC2_ERR_CRC_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FATAL_FORCE_VC2_ERR_CRC_Pos) /* (CSI_INT_FORCE_PKT_FATAL) Force vc2_err_crc. Mask */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC2_ERR_CRC(value) (CSI_INT_FORCE_PKT_FATAL_FORCE_VC2_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FATAL_FORCE_VC2_ERR_CRC_Pos)) /* Assigment of value for FORCE_VC2_ERR_CRC in the CSI_INT_FORCE_PKT_FATAL register */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC3_ERR_CRC_Pos _UINT32_(3)                                          /* (CSI_INT_FORCE_PKT_FATAL) Force vc3_err_crc. Position */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC3_ERR_CRC_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FATAL_FORCE_VC3_ERR_CRC_Pos) /* (CSI_INT_FORCE_PKT_FATAL) Force vc3_err_crc. Mask */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_VC3_ERR_CRC(value) (CSI_INT_FORCE_PKT_FATAL_FORCE_VC3_ERR_CRC_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FATAL_FORCE_VC3_ERR_CRC_Pos)) /* Assigment of value for FORCE_VC3_ERR_CRC in the CSI_INT_FORCE_PKT_FATAL register */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_ERR_ECC_DOUBLE_Pos _UINT32_(16)                                         /* (CSI_INT_FORCE_PKT_FATAL) Force err_ecc_double. Position */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_ERR_ECC_DOUBLE_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FATAL_FORCE_ERR_ECC_DOUBLE_Pos) /* (CSI_INT_FORCE_PKT_FATAL) Force err_ecc_double. Mask */
#define CSI_INT_FORCE_PKT_FATAL_FORCE_ERR_ECC_DOUBLE(value) (CSI_INT_FORCE_PKT_FATAL_FORCE_ERR_ECC_DOUBLE_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FATAL_FORCE_ERR_ECC_DOUBLE_Pos)) /* Assigment of value for FORCE_ERR_ECC_DOUBLE in the CSI_INT_FORCE_PKT_FATAL register */
#define CSI_INT_FORCE_PKT_FATAL_Msk           _UINT32_(0x0001000F)                                 /* (CSI_INT_FORCE_PKT_FATAL) Register Mask  */


/* -------- CSI_INT_ST_FRAME_FATAL : (CSI Offset: 0x100) ( R/ 32) Clear on read register    Fatal interruption related with Frame construction. Packet discarded.   Groups and notifies which interruption bits caused the interruption.   Stores the source of the error.   Reading INT_ST_FRAME_FATAL register does not clear the interrupt pin. -------- */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC0_Pos _UINT32_(0)                                          /* (CSI_INT_ST_FRAME_FATAL) Error matching Frame Start with Frame End for virtual channel 0. Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC0_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC0_Pos) /* (CSI_INT_ST_FRAME_FATAL) Error matching Frame Start with Frame End for virtual channel 0. Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC0(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC0_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC0_Pos)) /* Assigment of value for ERR_F_BNDRY_MATCH_VC0 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC1_Pos _UINT32_(1)                                          /* (CSI_INT_ST_FRAME_FATAL) Error matching Frame Start with Frame End for virtual channel 1. Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC1_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC1_Pos) /* (CSI_INT_ST_FRAME_FATAL) Error matching Frame Start with Frame End for virtual channel 1. Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC1(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC1_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC1_Pos)) /* Assigment of value for ERR_F_BNDRY_MATCH_VC1 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC2_Pos _UINT32_(2)                                          /* (CSI_INT_ST_FRAME_FATAL) Error matching Frame Start with Frame End for virtual channel 2. Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC2_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC2_Pos) /* (CSI_INT_ST_FRAME_FATAL) Error matching Frame Start with Frame End for virtual channel 2. Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC2(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC2_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC2_Pos)) /* Assigment of value for ERR_F_BNDRY_MATCH_VC2 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC3_Pos _UINT32_(3)                                          /* (CSI_INT_ST_FRAME_FATAL) Error matching Frame Start with Frame End for virtual channel 3. Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC3_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC3_Pos) /* (CSI_INT_ST_FRAME_FATAL) Error matching Frame Start with Frame End for virtual channel 3. Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC3(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC3_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC3_Pos)) /* Assigment of value for ERR_F_BNDRY_MATCH_VC3 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC0_Pos _UINT32_(8)                                          /* (CSI_INT_ST_FRAME_FATAL) Incorrect Frame sequence detected in Virtual Channel 0. Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC0_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC0_Pos) /* (CSI_INT_ST_FRAME_FATAL) Incorrect Frame sequence detected in Virtual Channel 0. Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC0(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC0_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC0_Pos)) /* Assigment of value for ERR_F_SEQ_VC0 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC1_Pos _UINT32_(9)                                          /* (CSI_INT_ST_FRAME_FATAL) Incorrect Frame sequence detected in Virtual Channel 1. Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC1_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC1_Pos) /* (CSI_INT_ST_FRAME_FATAL) Incorrect Frame sequence detected in Virtual Channel 1. Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC1(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC1_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC1_Pos)) /* Assigment of value for ERR_F_SEQ_VC1 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC2_Pos _UINT32_(10)                                         /* (CSI_INT_ST_FRAME_FATAL) Incorrect Frame sequence detected in Virtual Channel 2. Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC2_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC2_Pos) /* (CSI_INT_ST_FRAME_FATAL) Incorrect Frame sequence detected in Virtual Channel 2. Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC2(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC2_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC2_Pos)) /* Assigment of value for ERR_F_SEQ_VC2 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC3_Pos _UINT32_(11)                                         /* (CSI_INT_ST_FRAME_FATAL) Incorrect Frame sequence detected in Virtual Channel 3. Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC3_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC3_Pos) /* (CSI_INT_ST_FRAME_FATAL) Incorrect Frame sequence detected in Virtual Channel 3. Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC3(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC3_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC3_Pos)) /* Assigment of value for ERR_F_SEQ_VC3 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC0_Pos _UINT32_(16)                                         /* (CSI_INT_ST_FRAME_FATAL) Last received Frame in virtual channel 0, had at least one CRC error. Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC0_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC0_Pos) /* (CSI_INT_ST_FRAME_FATAL) Last received Frame in virtual channel 0, had at least one CRC error. Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC0(value) (CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC0_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC0_Pos)) /* Assigment of value for ERR_FRAME_DATA_VC0 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC1_Pos _UINT32_(17)                                         /* (CSI_INT_ST_FRAME_FATAL) Last received Frame in virtual channel 1, had at least one CRC error. Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC1_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC1_Pos) /* (CSI_INT_ST_FRAME_FATAL) Last received Frame in virtual channel 1, had at least one CRC error. Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC1(value) (CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC1_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC1_Pos)) /* Assigment of value for ERR_FRAME_DATA_VC1 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC2_Pos _UINT32_(18)                                         /* (CSI_INT_ST_FRAME_FATAL) Last received Frame in virtual channel 2, had at least one CRC error. Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC2_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC2_Pos) /* (CSI_INT_ST_FRAME_FATAL) Last received Frame in virtual channel 2, had at least one CRC error. Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC2(value) (CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC2_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC2_Pos)) /* Assigment of value for ERR_FRAME_DATA_VC2 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC3_Pos _UINT32_(19)                                         /* (CSI_INT_ST_FRAME_FATAL) Last received Frame in virtual channel 3, had at least one CRC error. Position */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC3_Msk (_UINT32_(0x1) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC3_Pos) /* (CSI_INT_ST_FRAME_FATAL) Last received Frame in virtual channel 3, had at least one CRC error. Mask */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC3(value) (CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC3_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC3_Pos)) /* Assigment of value for ERR_FRAME_DATA_VC3 in the CSI_INT_ST_FRAME_FATAL register */
#define CSI_INT_ST_FRAME_FATAL_Msk            _UINT32_(0x000F0F0F)                                 /* (CSI_INT_ST_FRAME_FATAL) Register Mask  */

#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC_Pos _UINT32_(0)                                          /* (CSI_INT_ST_FRAME_FATAL Position) Error matching Frame Start with Frame End for virtual channel x. */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC_Msk (_UINT32_(0xF) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC_Pos) /* (CSI_INT_ST_FRAME_FATAL Mask) ERR_F_BNDRY_MATCH_VC */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_BNDRY_MATCH_VC_Pos)) 
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC_Pos _UINT32_(8)                                          /* (CSI_INT_ST_FRAME_FATAL Position) Incorrect Frame sequence detected in Virtual Channel x. */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC_Msk (_UINT32_(0xF) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC_Pos) /* (CSI_INT_ST_FRAME_FATAL Mask) ERR_F_SEQ_VC */
#define CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC(value) (CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_F_SEQ_VC_Pos)) 
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC_Pos _UINT32_(16)                                         /* (CSI_INT_ST_FRAME_FATAL Position) Last received Frame in virtual channel 3, had at least one CRC error. */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC_Msk (_UINT32_(0xF) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC_Pos) /* (CSI_INT_ST_FRAME_FATAL Mask) ERR_FRAME_DATA_VC */
#define CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC(value) (CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC_Msk & (_UINT32_(value) << CSI_INT_ST_FRAME_FATAL_ERR_FRAME_DATA_VC_Pos)) 

/* -------- CSI_INT_MSK_FRAME_FATAL : (CSI Offset: 0x104) (R/W 32) Static read and write register    Interrupt mask for INT_ST_FRAME_FATAL controls which interrupt status bits will trigger the interrupt pin. Bit at 1 - Enable the interrupt source. Bit at 0 - Interrupt source is masked. -------- */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC0_Pos _UINT32_(0)                                          /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_f_bndry_match_vc0. Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC0_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC0_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_f_bndry_match_vc0. Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC0(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC0_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC0_Pos)) /* Assigment of value for MASK_ERR_F_BNDRY_MATCH_VC0 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC1_Pos _UINT32_(1)                                          /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_f_bndry_match_vc1. Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC1_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC1_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_f_bndry_match_vc1. Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC1(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC1_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC1_Pos)) /* Assigment of value for MASK_ERR_F_BNDRY_MATCH_VC1 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC2_Pos _UINT32_(2)                                          /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_f_bndry_match_vc2. Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC2_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC2_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_f_bndry_match_vc2. Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC2(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC2_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC2_Pos)) /* Assigment of value for MASK_ERR_F_BNDRY_MATCH_VC2 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC3_Pos _UINT32_(3)                                          /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_f_bndry_match_vc3. Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC3_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC3_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_f_bndry_match_vc3. Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC3(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC3_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC3_Pos)) /* Assigment of value for MASK_ERR_F_BNDRY_MATCH_VC3 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC0_Pos _UINT32_(8)                                          /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_f_seq_vc0. Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC0_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC0_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_f_seq_vc0. Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC0(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC0_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC0_Pos)) /* Assigment of value for MASK_ERR_F_SEQ_VC0 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC1_Pos _UINT32_(9)                                          /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_f_seq_vc1. Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC1_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC1_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_f_seq_vc1. Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC1(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC1_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC1_Pos)) /* Assigment of value for MASK_ERR_F_SEQ_VC1 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC2_Pos _UINT32_(10)                                         /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_f_seq_vc2. Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC2_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC2_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_f_seq_vc2. Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC2(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC2_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC2_Pos)) /* Assigment of value for MASK_ERR_F_SEQ_VC2 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC3_Pos _UINT32_(11)                                         /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_f_seq_vc3. Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC3_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC3_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_f_seq_vc3. Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC3(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC3_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC3_Pos)) /* Assigment of value for MASK_ERR_F_SEQ_VC3 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC0_Pos _UINT32_(16)                                         /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_frame_data_vc0. Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC0_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC0_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_frame_data_vc0. Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC0(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC0_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC0_Pos)) /* Assigment of value for MASK_ERR_FRAME_DATA_VC0 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC1_Pos _UINT32_(17)                                         /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_frame_data_vc1. Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC1_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC1_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_frame_data_vc1. Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC1(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC1_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC1_Pos)) /* Assigment of value for MASK_ERR_FRAME_DATA_VC1 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC2_Pos _UINT32_(18)                                         /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_frame_data_vc2. Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC2_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC2_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_frame_data_vc2. Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC2(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC2_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC2_Pos)) /* Assigment of value for MASK_ERR_FRAME_DATA_VC2 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC3_Pos _UINT32_(19)                                         /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_frame_data_vc3. Position */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC3_Msk (_UINT32_(0x1) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC3_Pos) /* (CSI_INT_MSK_FRAME_FATAL) Mask for err_frame_data_vc3. Mask */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC3(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC3_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC3_Pos)) /* Assigment of value for MASK_ERR_FRAME_DATA_VC3 in the CSI_INT_MSK_FRAME_FATAL register */
#define CSI_INT_MSK_FRAME_FATAL_Msk           _UINT32_(0x000F0F0F)                                 /* (CSI_INT_MSK_FRAME_FATAL) Register Mask  */

#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC_Pos _UINT32_(0)                                          /* (CSI_INT_MSK_FRAME_FATAL Position) Mask for err_f_bndry_match_vcx. */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC_Msk (_UINT32_(0xF) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC_Pos) /* (CSI_INT_MSK_FRAME_FATAL Mask) MASK_ERR_F_BNDRY_MATCH_VC */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_BNDRY_MATCH_VC_Pos)) 
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC_Pos _UINT32_(8)                                          /* (CSI_INT_MSK_FRAME_FATAL Position) Mask for err_f_seq_vcx. */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC_Msk (_UINT32_(0xF) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC_Pos) /* (CSI_INT_MSK_FRAME_FATAL Mask) MASK_ERR_F_SEQ_VC */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_F_SEQ_VC_Pos)) 
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC_Pos _UINT32_(16)                                         /* (CSI_INT_MSK_FRAME_FATAL Position) Mask for err_frame_data_vc3. */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC_Msk (_UINT32_(0xF) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC_Pos) /* (CSI_INT_MSK_FRAME_FATAL Mask) MASK_ERR_FRAME_DATA_VC */
#define CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC(value) (CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC_Msk & (_UINT32_(value) << CSI_INT_MSK_FRAME_FATAL_MASK_ERR_FRAME_DATA_VC_Pos)) 

/* -------- CSI_INT_FORCE_FRAME_FATAL : (CSI Offset: 0x108) (R/W 32) Static read and write register    Interrupt force register is used for test purposes, and allows triggering INT_ST_FRAME_FATAL interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, because it may be extremely complex to generate stimuli for that purpose. -------- */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC0_Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_FRAME_FATAL) Force err_f_bndry_match_vc0. Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC0_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC0_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force err_f_bndry_match_vc0. Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC0(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC0_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC0_Pos)) /* Assigment of value for FORCE_ERR_F_BNDRY_MATCH_VC0 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC1_Pos _UINT32_(1)                                          /* (CSI_INT_FORCE_FRAME_FATAL) Force err_f_bndry_match_vc1. Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC1_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC1_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force err_f_bndry_match_vc1. Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC1(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC1_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC1_Pos)) /* Assigment of value for FORCE_ERR_F_BNDRY_MATCH_VC1 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC2_Pos _UINT32_(2)                                          /* (CSI_INT_FORCE_FRAME_FATAL) Force err_f_bndry_match_vc2. Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC2_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC2_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force err_f_bndry_match_vc2. Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC2(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC2_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC2_Pos)) /* Assigment of value for FORCE_ERR_F_BNDRY_MATCH_VC2 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC3_Pos _UINT32_(3)                                          /* (CSI_INT_FORCE_FRAME_FATAL) Force err_f_bndry_match_vc3. Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC3_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC3_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force err_f_bndry_match_vc3. Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC3(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC3_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC3_Pos)) /* Assigment of value for FORCE_ERR_F_BNDRY_MATCH_VC3 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC0_Pos _UINT32_(8)                                          /* (CSI_INT_FORCE_FRAME_FATAL) Force err_f_seq_vc0. Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC0_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC0_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force err_f_seq_vc0. Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC0(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC0_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC0_Pos)) /* Assigment of value for FORCE_ERR_F_SEQ_VC0 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC1_Pos _UINT32_(9)                                          /* (CSI_INT_FORCE_FRAME_FATAL) Force err_f_seq_vc1. Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC1_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC1_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force err_f_seq_vc1. Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC1(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC1_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC1_Pos)) /* Assigment of value for FORCE_ERR_F_SEQ_VC1 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC2_Pos _UINT32_(10)                                         /* (CSI_INT_FORCE_FRAME_FATAL) Force err_f_seq_vc2. Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC2_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC2_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force err_f_seq_vc2. Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC2(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC2_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC2_Pos)) /* Assigment of value for FORCE_ERR_F_SEQ_VC2 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC3_Pos _UINT32_(11)                                         /* (CSI_INT_FORCE_FRAME_FATAL) Force err_f_seq_vc3. Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC3_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC3_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force err_f_seq_vc3. Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC3(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC3_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC3_Pos)) /* Assigment of value for FORCE_ERR_F_SEQ_VC3 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC0_Pos _UINT32_(16)                                         /* (CSI_INT_FORCE_FRAME_FATAL) Force err_frame_data_vc0. Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC0_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC0_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force err_frame_data_vc0. Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC0(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC0_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC0_Pos)) /* Assigment of value for FORCE_ERR_FRAME_DATA_VC0 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC1_Pos _UINT32_(17)                                         /* (CSI_INT_FORCE_FRAME_FATAL) Force err_frame_data_vc1. Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC1_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC1_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force err_frame_data_vc1. Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC1(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC1_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC1_Pos)) /* Assigment of value for FORCE_ERR_FRAME_DATA_VC1 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC2_Pos _UINT32_(18)                                         /* (CSI_INT_FORCE_FRAME_FATAL) Force err_frame_data_vc2. Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC2_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC2_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force err_frame_data_vc2. Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC2(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC2_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC2_Pos)) /* Assigment of value for FORCE_ERR_FRAME_DATA_VC2 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC3_Pos _UINT32_(19)                                         /* (CSI_INT_FORCE_FRAME_FATAL) Force err_frame_data_vc3. Position */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC3_Msk (_UINT32_(0x1) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC3_Pos) /* (CSI_INT_FORCE_FRAME_FATAL) Force err_frame_data_vc3. Mask */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC3(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC3_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC3_Pos)) /* Assigment of value for FORCE_ERR_FRAME_DATA_VC3 in the CSI_INT_FORCE_FRAME_FATAL register */
#define CSI_INT_FORCE_FRAME_FATAL_Msk         _UINT32_(0x000F0F0F)                                 /* (CSI_INT_FORCE_FRAME_FATAL) Register Mask  */

#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC_Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_FRAME_FATAL Position) Force err_f_bndry_match_vcx. */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC_Msk (_UINT32_(0xF) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC_Pos) /* (CSI_INT_FORCE_FRAME_FATAL Mask) FORCE_ERR_F_BNDRY_MATCH_VC */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_BNDRY_MATCH_VC_Pos)) 
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC_Pos _UINT32_(8)                                          /* (CSI_INT_FORCE_FRAME_FATAL Position) Force err_f_seq_vcx. */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC_Msk (_UINT32_(0xF) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC_Pos) /* (CSI_INT_FORCE_FRAME_FATAL Mask) FORCE_ERR_F_SEQ_VC */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_F_SEQ_VC_Pos)) 
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC_Pos _UINT32_(16)                                         /* (CSI_INT_FORCE_FRAME_FATAL Position) Force err_frame_data_vc3. */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC_Msk (_UINT32_(0xF) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC_Pos) /* (CSI_INT_FORCE_FRAME_FATAL Mask) FORCE_ERR_FRAME_DATA_VC */
#define CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC(value) (CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC_Msk & (_UINT32_(value) << CSI_INT_FORCE_FRAME_FATAL_FORCE_ERR_FRAME_DATA_VC_Pos)) 

/* -------- CSI_INT_ST_PHY : (CSI Offset: 0x110) ( R/ 32) Clear on read register    Interruption caused by PHY.   Groups and notifies which interruption bits caused the interruption.   Stores the source of the error.   Reading INT_ST_PHY register does not clear the interrupt pin. -------- */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS_0_Pos     _UINT32_(0)                                          /* (CSI_INT_ST_PHY) Start of transmission error on data lane 0 (synchronization can still be achieved). Position */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS_0_Msk     (_UINT32_(0x1) << CSI_INT_ST_PHY_PHY_ERRSOTHS_0_Pos) /* (CSI_INT_ST_PHY) Start of transmission error on data lane 0 (synchronization can still be achieved). Mask */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS_0(value)  (CSI_INT_ST_PHY_PHY_ERRSOTHS_0_Msk & (_UINT32_(value) << CSI_INT_ST_PHY_PHY_ERRSOTHS_0_Pos)) /* Assigment of value for PHY_ERRSOTHS_0 in the CSI_INT_ST_PHY register */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS_1_Pos     _UINT32_(1)                                          /* (CSI_INT_ST_PHY) Start of transmission error on data lane 1 (synchronization can still be achieved) Position */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS_1_Msk     (_UINT32_(0x1) << CSI_INT_ST_PHY_PHY_ERRSOTHS_1_Pos) /* (CSI_INT_ST_PHY) Start of transmission error on data lane 1 (synchronization can still be achieved) Mask */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS_1(value)  (CSI_INT_ST_PHY_PHY_ERRSOTHS_1_Msk & (_UINT32_(value) << CSI_INT_ST_PHY_PHY_ERRSOTHS_1_Pos)) /* Assigment of value for PHY_ERRSOTHS_1 in the CSI_INT_ST_PHY register */
#define CSI_INT_ST_PHY_PHY_ERRESC_0_Pos       _UINT32_(16)                                         /* (CSI_INT_ST_PHY) Start of Transmission Error on data lane 0 (no synchronization achieved). Position */
#define CSI_INT_ST_PHY_PHY_ERRESC_0_Msk       (_UINT32_(0x1) << CSI_INT_ST_PHY_PHY_ERRESC_0_Pos)   /* (CSI_INT_ST_PHY) Start of Transmission Error on data lane 0 (no synchronization achieved). Mask */
#define CSI_INT_ST_PHY_PHY_ERRESC_0(value)    (CSI_INT_ST_PHY_PHY_ERRESC_0_Msk & (_UINT32_(value) << CSI_INT_ST_PHY_PHY_ERRESC_0_Pos)) /* Assigment of value for PHY_ERRESC_0 in the CSI_INT_ST_PHY register */
#define CSI_INT_ST_PHY_PHY_ERRESC_1_Pos       _UINT32_(17)                                         /* (CSI_INT_ST_PHY) Start of Transmission Error on data lane 1 (no synchronization achieved) Position */
#define CSI_INT_ST_PHY_PHY_ERRESC_1_Msk       (_UINT32_(0x1) << CSI_INT_ST_PHY_PHY_ERRESC_1_Pos)   /* (CSI_INT_ST_PHY) Start of Transmission Error on data lane 1 (no synchronization achieved) Mask */
#define CSI_INT_ST_PHY_PHY_ERRESC_1(value)    (CSI_INT_ST_PHY_PHY_ERRESC_1_Msk & (_UINT32_(value) << CSI_INT_ST_PHY_PHY_ERRESC_1_Pos)) /* Assigment of value for PHY_ERRESC_1 in the CSI_INT_ST_PHY register */
#define CSI_INT_ST_PHY_Msk                    _UINT32_(0x00030003)                                 /* (CSI_INT_ST_PHY) Register Mask  */

#define CSI_INT_ST_PHY_PHY_ERRSOTHS__Pos      _UINT32_(0)                                          /* (CSI_INT_ST_PHY Position) Start of transmission error on data lane x (synchronization can still be achieved). */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS__Msk      (_UINT32_(0x3) << CSI_INT_ST_PHY_PHY_ERRSOTHS__Pos)  /* (CSI_INT_ST_PHY Mask) PHY_ERRSOTHS_ */
#define CSI_INT_ST_PHY_PHY_ERRSOTHS_(value)   (CSI_INT_ST_PHY_PHY_ERRSOTHS__Msk & (_UINT32_(value) << CSI_INT_ST_PHY_PHY_ERRSOTHS__Pos)) 
#define CSI_INT_ST_PHY_PHY_ERRESC__Pos        _UINT32_(16)                                         /* (CSI_INT_ST_PHY Position) Start of Transmission Error on data lane x (no synchronization achieved) */
#define CSI_INT_ST_PHY_PHY_ERRESC__Msk        (_UINT32_(0x3) << CSI_INT_ST_PHY_PHY_ERRESC__Pos)    /* (CSI_INT_ST_PHY Mask) PHY_ERRESC_ */
#define CSI_INT_ST_PHY_PHY_ERRESC_(value)     (CSI_INT_ST_PHY_PHY_ERRESC__Msk & (_UINT32_(value) << CSI_INT_ST_PHY_PHY_ERRESC__Pos)) 

/* -------- CSI_INT_MSK_PHY : (CSI Offset: 0x114) (R/W 32) Static read and write register    Interrupt mask for INT_ST_PHY controls which interrupt status bits will trigger the interrupt pin. Bit at 1 - Enable the interrupt source. Bit at 0 - Interrupt source is masked. -------- */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_0_Pos _UINT32_(0)                                          /* (CSI_INT_MSK_PHY) Mask for phy_errsoths_0. Position */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_0_Msk (_UINT32_(0x1) << CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_0_Pos) /* (CSI_INT_MSK_PHY) Mask for phy_errsoths_0. Mask */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_0(value) (CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_0_Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_0_Pos)) /* Assigment of value for MASK_PHY_ERRSOTHS_0 in the CSI_INT_MSK_PHY register */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_1_Pos _UINT32_(1)                                          /* (CSI_INT_MSK_PHY) Mask for phy_errsoths_1 Position */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_1_Msk (_UINT32_(0x1) << CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_1_Pos) /* (CSI_INT_MSK_PHY) Mask for phy_errsoths_1 Mask */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_1(value) (CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_1_Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_1_Pos)) /* Assigment of value for MASK_PHY_ERRSOTHS_1 in the CSI_INT_MSK_PHY register */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_0_Pos _UINT32_(16)                                         /* (CSI_INT_MSK_PHY) Mask for phy_erresc_0. Position */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_0_Msk (_UINT32_(0x1) << CSI_INT_MSK_PHY_MASK_PHY_ERRESC_0_Pos) /* (CSI_INT_MSK_PHY) Mask for phy_erresc_0. Mask */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_0(value) (CSI_INT_MSK_PHY_MASK_PHY_ERRESC_0_Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_MASK_PHY_ERRESC_0_Pos)) /* Assigment of value for MASK_PHY_ERRESC_0 in the CSI_INT_MSK_PHY register */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_1_Pos _UINT32_(17)                                         /* (CSI_INT_MSK_PHY) Mask for phy_erresc_1 Position */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_1_Msk (_UINT32_(0x1) << CSI_INT_MSK_PHY_MASK_PHY_ERRESC_1_Pos) /* (CSI_INT_MSK_PHY) Mask for phy_erresc_1 Mask */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_1(value) (CSI_INT_MSK_PHY_MASK_PHY_ERRESC_1_Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_MASK_PHY_ERRESC_1_Pos)) /* Assigment of value for MASK_PHY_ERRESC_1 in the CSI_INT_MSK_PHY register */
#define CSI_INT_MSK_PHY_Msk                   _UINT32_(0x00030003)                                 /* (CSI_INT_MSK_PHY) Register Mask  */

#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS__Pos _UINT32_(0)                                          /* (CSI_INT_MSK_PHY Position) Mask for phy_errsoths_x. */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS__Msk (_UINT32_(0x3) << CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS__Pos) /* (CSI_INT_MSK_PHY Mask) MASK_PHY_ERRSOTHS_ */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS_(value) (CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS__Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_MASK_PHY_ERRSOTHS__Pos)) 
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC__Pos  _UINT32_(16)                                         /* (CSI_INT_MSK_PHY Position) Mask for phy_erresc_x */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC__Msk  (_UINT32_(0x3) << CSI_INT_MSK_PHY_MASK_PHY_ERRESC__Pos) /* (CSI_INT_MSK_PHY Mask) MASK_PHY_ERRESC_ */
#define CSI_INT_MSK_PHY_MASK_PHY_ERRESC_(value) (CSI_INT_MSK_PHY_MASK_PHY_ERRESC__Msk & (_UINT32_(value) << CSI_INT_MSK_PHY_MASK_PHY_ERRESC__Pos)) 

/* -------- CSI_INT_FORCE_PHY : (CSI Offset: 0x118) (R/W 32) Static read and write register    Interrupt force register is used for test purposes, and allows triggering INT_ST_PHY interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, because it may be extremely complex to generate stimuli for that purpose. -------- */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_0_Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_PHY) Force phy_errsoths_0. Position */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_0_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_0_Pos) /* (CSI_INT_FORCE_PHY) Force phy_errsoths_0. Mask */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_0(value) (CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_0_Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_0_Pos)) /* Assigment of value for FORCE_PHY_ERRSOTHS_0 in the CSI_INT_FORCE_PHY register */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_1_Pos _UINT32_(1)                                          /* (CSI_INT_FORCE_PHY) Force phy_errsoths_1 Position */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_1_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_1_Pos) /* (CSI_INT_FORCE_PHY) Force phy_errsoths_1 Mask */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_1(value) (CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_1_Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_1_Pos)) /* Assigment of value for FORCE_PHY_ERRSOTHS_1 in the CSI_INT_FORCE_PHY register */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_0_Pos _UINT32_(16)                                         /* (CSI_INT_FORCE_PHY) Force phy_erresc_0 Position */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_0_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_0_Pos) /* (CSI_INT_FORCE_PHY) Force phy_erresc_0 Mask */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_0(value) (CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_0_Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_0_Pos)) /* Assigment of value for FORCE_PHY_ERRESC_0 in the CSI_INT_FORCE_PHY register */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_1_Pos _UINT32_(17)                                         /* (CSI_INT_FORCE_PHY) Force phy_erresc_1 Position */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_1_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_1_Pos) /* (CSI_INT_FORCE_PHY) Force phy_erresc_1 Mask */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_1(value) (CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_1_Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_1_Pos)) /* Assigment of value for FORCE_PHY_ERRESC_1 in the CSI_INT_FORCE_PHY register */
#define CSI_INT_FORCE_PHY_Msk                 _UINT32_(0x00030003)                                 /* (CSI_INT_FORCE_PHY) Register Mask  */

#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS__Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_PHY Position) Force phy_errsoths_x. */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS__Msk (_UINT32_(0x3) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS__Pos) /* (CSI_INT_FORCE_PHY Mask) FORCE_PHY_ERRSOTHS_ */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS_(value) (CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS__Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRSOTHS__Pos)) 
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC__Pos _UINT32_(16)                                         /* (CSI_INT_FORCE_PHY Position) Force phy_erresc_x */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC__Msk (_UINT32_(0x3) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC__Pos) /* (CSI_INT_FORCE_PHY Mask) FORCE_PHY_ERRESC_ */
#define CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC_(value) (CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC__Msk & (_UINT32_(value) << CSI_INT_FORCE_PHY_FORCE_PHY_ERRESC__Pos)) 

/* -------- CSI_INT_ST_PKT : (CSI Offset: 0x120) ( R/ 32) Clear on read register    Interruption related with Packet construction. Packet discarded.   Groups and notifies which interruption bits caused the interruption.   Stores the source of the error.   Reading INT_ST_PKT register does not clear the interrupt pin. -------- */
#define CSI_INT_ST_PKT_ERR_ID_VC0_Pos         _UINT32_(0)                                          /* (CSI_INT_ST_PKT) Unrecognized or unimplemented data type detected in virtual channel 0. Position */
#define CSI_INT_ST_PKT_ERR_ID_VC0_Msk         (_UINT32_(0x1) << CSI_INT_ST_PKT_ERR_ID_VC0_Pos)     /* (CSI_INT_ST_PKT) Unrecognized or unimplemented data type detected in virtual channel 0. Mask */
#define CSI_INT_ST_PKT_ERR_ID_VC0(value)      (CSI_INT_ST_PKT_ERR_ID_VC0_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_ERR_ID_VC0_Pos)) /* Assigment of value for ERR_ID_VC0 in the CSI_INT_ST_PKT register */
#define CSI_INT_ST_PKT_ERR_ID_VC1_Pos         _UINT32_(1)                                          /* (CSI_INT_ST_PKT) Unrecognized or unimplemented data type detected in virtual channel 1. Position */
#define CSI_INT_ST_PKT_ERR_ID_VC1_Msk         (_UINT32_(0x1) << CSI_INT_ST_PKT_ERR_ID_VC1_Pos)     /* (CSI_INT_ST_PKT) Unrecognized or unimplemented data type detected in virtual channel 1. Mask */
#define CSI_INT_ST_PKT_ERR_ID_VC1(value)      (CSI_INT_ST_PKT_ERR_ID_VC1_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_ERR_ID_VC1_Pos)) /* Assigment of value for ERR_ID_VC1 in the CSI_INT_ST_PKT register */
#define CSI_INT_ST_PKT_ERR_ID_VC2_Pos         _UINT32_(2)                                          /* (CSI_INT_ST_PKT) Unrecognized or unimplemented data type detected in virtual channel 2. Position */
#define CSI_INT_ST_PKT_ERR_ID_VC2_Msk         (_UINT32_(0x1) << CSI_INT_ST_PKT_ERR_ID_VC2_Pos)     /* (CSI_INT_ST_PKT) Unrecognized or unimplemented data type detected in virtual channel 2. Mask */
#define CSI_INT_ST_PKT_ERR_ID_VC2(value)      (CSI_INT_ST_PKT_ERR_ID_VC2_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_ERR_ID_VC2_Pos)) /* Assigment of value for ERR_ID_VC2 in the CSI_INT_ST_PKT register */
#define CSI_INT_ST_PKT_ERR_ID_VC3_Pos         _UINT32_(3)                                          /* (CSI_INT_ST_PKT) Unrecognized or unimplemented data type detected in virtual channel 3. Position */
#define CSI_INT_ST_PKT_ERR_ID_VC3_Msk         (_UINT32_(0x1) << CSI_INT_ST_PKT_ERR_ID_VC3_Pos)     /* (CSI_INT_ST_PKT) Unrecognized or unimplemented data type detected in virtual channel 3. Mask */
#define CSI_INT_ST_PKT_ERR_ID_VC3(value)      (CSI_INT_ST_PKT_ERR_ID_VC3_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_ERR_ID_VC3_Pos)) /* Assigment of value for ERR_ID_VC3 in the CSI_INT_ST_PKT register */
#define CSI_INT_ST_PKT_VC0_ERR_ECC_CORRECTED_Pos _UINT32_(16)                                         /* (CSI_INT_ST_PKT) D-PHY mode : Header error detected and corrected on virtual channel 0.   C-PHY mode : Header CRC recoverable on virtual channel 0. Position */
#define CSI_INT_ST_PKT_VC0_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_ST_PKT_VC0_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_ST_PKT) D-PHY mode : Header error detected and corrected on virtual channel 0.   C-PHY mode : Header CRC recoverable on virtual channel 0. Mask */
#define CSI_INT_ST_PKT_VC0_ERR_ECC_CORRECTED(value) (CSI_INT_ST_PKT_VC0_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_VC0_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for VC0_ERR_ECC_CORRECTED in the CSI_INT_ST_PKT register */
#define CSI_INT_ST_PKT_VC1_ERR_ECC_CORRECTED_Pos _UINT32_(17)                                         /* (CSI_INT_ST_PKT) D-PHY mode : Header error detected and corrected on virtual channel 1.   C-PHY mode : Header CRC recoverable on virtual channel 1. Position */
#define CSI_INT_ST_PKT_VC1_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_ST_PKT_VC1_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_ST_PKT) D-PHY mode : Header error detected and corrected on virtual channel 1.   C-PHY mode : Header CRC recoverable on virtual channel 1. Mask */
#define CSI_INT_ST_PKT_VC1_ERR_ECC_CORRECTED(value) (CSI_INT_ST_PKT_VC1_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_VC1_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for VC1_ERR_ECC_CORRECTED in the CSI_INT_ST_PKT register */
#define CSI_INT_ST_PKT_VC2_ERR_ECC_CORRECTED_Pos _UINT32_(18)                                         /* (CSI_INT_ST_PKT) D-PHY mode : Header error detected and corrected on virtual channel 2.  C-PHY mode : Header CRC recoverable on virtual channel 2. Position */
#define CSI_INT_ST_PKT_VC2_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_ST_PKT_VC2_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_ST_PKT) D-PHY mode : Header error detected and corrected on virtual channel 2.  C-PHY mode : Header CRC recoverable on virtual channel 2. Mask */
#define CSI_INT_ST_PKT_VC2_ERR_ECC_CORRECTED(value) (CSI_INT_ST_PKT_VC2_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_VC2_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for VC2_ERR_ECC_CORRECTED in the CSI_INT_ST_PKT register */
#define CSI_INT_ST_PKT_VC3_ERR_ECC_CORRECTED_Pos _UINT32_(19)                                         /* (CSI_INT_ST_PKT) D-PHY mode : Header error detected and corrected on virtual channel 3.  C-PHY mode : Header CRC recoverable on virtual channel 3. Position */
#define CSI_INT_ST_PKT_VC3_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_ST_PKT_VC3_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_ST_PKT) D-PHY mode : Header error detected and corrected on virtual channel 3.  C-PHY mode : Header CRC recoverable on virtual channel 3. Mask */
#define CSI_INT_ST_PKT_VC3_ERR_ECC_CORRECTED(value) (CSI_INT_ST_PKT_VC3_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_VC3_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for VC3_ERR_ECC_CORRECTED in the CSI_INT_ST_PKT register */
#define CSI_INT_ST_PKT_Msk                    _UINT32_(0x000F000F)                                 /* (CSI_INT_ST_PKT) Register Mask  */

#define CSI_INT_ST_PKT_ERR_ID_VC_Pos          _UINT32_(0)                                          /* (CSI_INT_ST_PKT Position) Unrecognized or unimplemented data type detected in virtual channel x. */
#define CSI_INT_ST_PKT_ERR_ID_VC_Msk          (_UINT32_(0xF) << CSI_INT_ST_PKT_ERR_ID_VC_Pos)      /* (CSI_INT_ST_PKT Mask) ERR_ID_VC */
#define CSI_INT_ST_PKT_ERR_ID_VC(value)       (CSI_INT_ST_PKT_ERR_ID_VC_Msk & (_UINT32_(value) << CSI_INT_ST_PKT_ERR_ID_VC_Pos)) 

/* -------- CSI_INT_MSK_PKT : (CSI Offset: 0x124) (R/W 32) Static read and write register    Interrupt mask for INT_ST_PKT controls which interrupt status bits will trigger the interrupt pin. Bit at 1 - Enable the interrupt source. Bit at 0 - Interrupt source is masked. -------- */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC0_Pos   _UINT32_(0)                                          /* (CSI_INT_MSK_PKT) Mask for err_id_vc0. Position */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC0_Msk   (_UINT32_(0x1) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC0_Pos) /* (CSI_INT_MSK_PKT) Mask for err_id_vc0. Mask */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC0(value) (CSI_INT_MSK_PKT_MASK_ERR_ID_VC0_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC0_Pos)) /* Assigment of value for MASK_ERR_ID_VC0 in the CSI_INT_MSK_PKT register */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC1_Pos   _UINT32_(1)                                          /* (CSI_INT_MSK_PKT) Mask for err_id_vc1. Position */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC1_Msk   (_UINT32_(0x1) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC1_Pos) /* (CSI_INT_MSK_PKT) Mask for err_id_vc1. Mask */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC1(value) (CSI_INT_MSK_PKT_MASK_ERR_ID_VC1_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC1_Pos)) /* Assigment of value for MASK_ERR_ID_VC1 in the CSI_INT_MSK_PKT register */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC2_Pos   _UINT32_(2)                                          /* (CSI_INT_MSK_PKT) Mask for err_id_vc2. Position */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC2_Msk   (_UINT32_(0x1) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC2_Pos) /* (CSI_INT_MSK_PKT) Mask for err_id_vc2. Mask */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC2(value) (CSI_INT_MSK_PKT_MASK_ERR_ID_VC2_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC2_Pos)) /* Assigment of value for MASK_ERR_ID_VC2 in the CSI_INT_MSK_PKT register */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC3_Pos   _UINT32_(3)                                          /* (CSI_INT_MSK_PKT) Mask for err_id_vc3. Position */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC3_Msk   (_UINT32_(0x1) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC3_Pos) /* (CSI_INT_MSK_PKT) Mask for err_id_vc3. Mask */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC3(value) (CSI_INT_MSK_PKT_MASK_ERR_ID_VC3_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC3_Pos)) /* Assigment of value for MASK_ERR_ID_VC3 in the CSI_INT_MSK_PKT register */
#define CSI_INT_MSK_PKT_MASK_VC0_ERR_ECC_CORRECTED_Pos _UINT32_(16)                                         /* (CSI_INT_MSK_PKT) Mask for vc0_err_ecc_corrected. Position */
#define CSI_INT_MSK_PKT_MASK_VC0_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_MSK_PKT_MASK_VC0_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_MSK_PKT) Mask for vc0_err_ecc_corrected. Mask */
#define CSI_INT_MSK_PKT_MASK_VC0_ERR_ECC_CORRECTED(value) (CSI_INT_MSK_PKT_MASK_VC0_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_MASK_VC0_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for MASK_VC0_ERR_ECC_CORRECTED in the CSI_INT_MSK_PKT register */
#define CSI_INT_MSK_PKT_MASK_VC1_ERR_ECC_CORRECTED_Pos _UINT32_(17)                                         /* (CSI_INT_MSK_PKT) Mask for vc1_err_ecc_corrected. Position */
#define CSI_INT_MSK_PKT_MASK_VC1_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_MSK_PKT_MASK_VC1_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_MSK_PKT) Mask for vc1_err_ecc_corrected. Mask */
#define CSI_INT_MSK_PKT_MASK_VC1_ERR_ECC_CORRECTED(value) (CSI_INT_MSK_PKT_MASK_VC1_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_MASK_VC1_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for MASK_VC1_ERR_ECC_CORRECTED in the CSI_INT_MSK_PKT register */
#define CSI_INT_MSK_PKT_MASK_VC2_ERR_ECC_CORRECTED_Pos _UINT32_(18)                                         /* (CSI_INT_MSK_PKT) Mask for vc2_err_ecc_corrected. Position */
#define CSI_INT_MSK_PKT_MASK_VC2_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_MSK_PKT_MASK_VC2_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_MSK_PKT) Mask for vc2_err_ecc_corrected. Mask */
#define CSI_INT_MSK_PKT_MASK_VC2_ERR_ECC_CORRECTED(value) (CSI_INT_MSK_PKT_MASK_VC2_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_MASK_VC2_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for MASK_VC2_ERR_ECC_CORRECTED in the CSI_INT_MSK_PKT register */
#define CSI_INT_MSK_PKT_MASK_VC3_ERR_ECC_CORRECTED_Pos _UINT32_(19)                                         /* (CSI_INT_MSK_PKT) Mask for vc3_err_ecc_corrected. Position */
#define CSI_INT_MSK_PKT_MASK_VC3_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_MSK_PKT_MASK_VC3_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_MSK_PKT) Mask for vc3_err_ecc_corrected. Mask */
#define CSI_INT_MSK_PKT_MASK_VC3_ERR_ECC_CORRECTED(value) (CSI_INT_MSK_PKT_MASK_VC3_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_MASK_VC3_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for MASK_VC3_ERR_ECC_CORRECTED in the CSI_INT_MSK_PKT register */
#define CSI_INT_MSK_PKT_Msk                   _UINT32_(0x000F000F)                                 /* (CSI_INT_MSK_PKT) Register Mask  */

#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC_Pos    _UINT32_(0)                                          /* (CSI_INT_MSK_PKT Position) Mask for err_id_vcx. */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC_Msk    (_UINT32_(0xF) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC_Pos) /* (CSI_INT_MSK_PKT Mask) MASK_ERR_ID_VC */
#define CSI_INT_MSK_PKT_MASK_ERR_ID_VC(value) (CSI_INT_MSK_PKT_MASK_ERR_ID_VC_Msk & (_UINT32_(value) << CSI_INT_MSK_PKT_MASK_ERR_ID_VC_Pos)) 

/* -------- CSI_INT_FORCE_PKT : (CSI Offset: 0x128) (R/W 32) Static read and write register    Interrupt force register is used for test purposes, and allows triggering INT_ST_PKT interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, because it may be extremely complex to generate stimuli for that purpose. -------- */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC0_Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_PKT) Force err_id_vc0. Position */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC0_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC0_Pos) /* (CSI_INT_FORCE_PKT) Force err_id_vc0. Mask */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC0(value) (CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC0_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC0_Pos)) /* Assigment of value for FORCE_ERR_ID_VC0 in the CSI_INT_FORCE_PKT register */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC1_Pos _UINT32_(1)                                          /* (CSI_INT_FORCE_PKT) Force err_id_vc1. Position */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC1_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC1_Pos) /* (CSI_INT_FORCE_PKT) Force err_id_vc1. Mask */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC1(value) (CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC1_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC1_Pos)) /* Assigment of value for FORCE_ERR_ID_VC1 in the CSI_INT_FORCE_PKT register */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC2_Pos _UINT32_(2)                                          /* (CSI_INT_FORCE_PKT) Force err_id_vc2. Position */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC2_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC2_Pos) /* (CSI_INT_FORCE_PKT) Force err_id_vc2. Mask */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC2(value) (CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC2_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC2_Pos)) /* Assigment of value for FORCE_ERR_ID_VC2 in the CSI_INT_FORCE_PKT register */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC3_Pos _UINT32_(3)                                          /* (CSI_INT_FORCE_PKT) Force err_id_vc3. Position */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC3_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC3_Pos) /* (CSI_INT_FORCE_PKT) Force err_id_vc3. Mask */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC3(value) (CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC3_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC3_Pos)) /* Assigment of value for FORCE_ERR_ID_VC3 in the CSI_INT_FORCE_PKT register */
#define CSI_INT_FORCE_PKT_FORCE_VC0_ERR_ECC_CORRECTED_Pos _UINT32_(16)                                         /* (CSI_INT_FORCE_PKT) Force vc0_err_ecc_corrected. Position */
#define CSI_INT_FORCE_PKT_FORCE_VC0_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FORCE_VC0_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_FORCE_PKT) Force vc0_err_ecc_corrected. Mask */
#define CSI_INT_FORCE_PKT_FORCE_VC0_ERR_ECC_CORRECTED(value) (CSI_INT_FORCE_PKT_FORCE_VC0_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FORCE_VC0_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for FORCE_VC0_ERR_ECC_CORRECTED in the CSI_INT_FORCE_PKT register */
#define CSI_INT_FORCE_PKT_FORCE_VC1_ERR_ECC_CORRECTED_Pos _UINT32_(17)                                         /* (CSI_INT_FORCE_PKT) Force vc1_err_ecc_corrected. Position */
#define CSI_INT_FORCE_PKT_FORCE_VC1_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FORCE_VC1_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_FORCE_PKT) Force vc1_err_ecc_corrected. Mask */
#define CSI_INT_FORCE_PKT_FORCE_VC1_ERR_ECC_CORRECTED(value) (CSI_INT_FORCE_PKT_FORCE_VC1_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FORCE_VC1_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for FORCE_VC1_ERR_ECC_CORRECTED in the CSI_INT_FORCE_PKT register */
#define CSI_INT_FORCE_PKT_FORCE_VC2_ERR_ECC_CORRECTED_Pos _UINT32_(18)                                         /* (CSI_INT_FORCE_PKT) Force vc2_err_ecc_corrected. Position */
#define CSI_INT_FORCE_PKT_FORCE_VC2_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FORCE_VC2_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_FORCE_PKT) Force vc2_err_ecc_corrected. Mask */
#define CSI_INT_FORCE_PKT_FORCE_VC2_ERR_ECC_CORRECTED(value) (CSI_INT_FORCE_PKT_FORCE_VC2_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FORCE_VC2_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for FORCE_VC2_ERR_ECC_CORRECTED in the CSI_INT_FORCE_PKT register */
#define CSI_INT_FORCE_PKT_FORCE_VC3_ERR_ECC_CORRECTED_Pos _UINT32_(19)                                         /* (CSI_INT_FORCE_PKT) Force vc3_err_ecc_corrected. Position */
#define CSI_INT_FORCE_PKT_FORCE_VC3_ERR_ECC_CORRECTED_Msk (_UINT32_(0x1) << CSI_INT_FORCE_PKT_FORCE_VC3_ERR_ECC_CORRECTED_Pos) /* (CSI_INT_FORCE_PKT) Force vc3_err_ecc_corrected. Mask */
#define CSI_INT_FORCE_PKT_FORCE_VC3_ERR_ECC_CORRECTED(value) (CSI_INT_FORCE_PKT_FORCE_VC3_ERR_ECC_CORRECTED_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FORCE_VC3_ERR_ECC_CORRECTED_Pos)) /* Assigment of value for FORCE_VC3_ERR_ECC_CORRECTED in the CSI_INT_FORCE_PKT register */
#define CSI_INT_FORCE_PKT_Msk                 _UINT32_(0x000F000F)                                 /* (CSI_INT_FORCE_PKT) Register Mask  */

#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC_Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_PKT Position) Force err_id_vcx. */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC_Msk (_UINT32_(0xF) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC_Pos) /* (CSI_INT_FORCE_PKT Mask) FORCE_ERR_ID_VC */
#define CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC(value) (CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC_Msk & (_UINT32_(value) << CSI_INT_FORCE_PKT_FORCE_ERR_ID_VC_Pos)) 

/* -------- CSI_INT_ST_LINE : (CSI Offset: 0x130) ( R/ 32) Clear on read register    Interruption related with Line construction.    Groups and notifies which interruption bits caused the interruption.  Stores the source of the error.   Reading INT_ST_LINE register does not clear the interrupt pin. -------- */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI0_Pos _UINT32_(0)                                          /* (CSI_INT_ST_LINE) Error matching line start with line end for vc0 and dt0 Position */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI0_Msk (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI0_Pos) /* (CSI_INT_ST_LINE) Error matching line start with line end for vc0 and dt0 Mask */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI0(value) (CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI0_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI0_Pos)) /* Assigment of value for ERR_L_BNDRY_MATCH_DI0 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI1_Pos _UINT32_(1)                                          /* (CSI_INT_ST_LINE) Error matching line start with line end for vc1 and dt1 Position */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI1_Msk (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI1_Pos) /* (CSI_INT_ST_LINE) Error matching line start with line end for vc1 and dt1 Mask */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI1(value) (CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI1_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI1_Pos)) /* Assigment of value for ERR_L_BNDRY_MATCH_DI1 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI2_Pos _UINT32_(2)                                          /* (CSI_INT_ST_LINE) Error matching line start with line end for vc2 and dt2 Position */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI2_Msk (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI2_Pos) /* (CSI_INT_ST_LINE) Error matching line start with line end for vc2 and dt2 Mask */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI2(value) (CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI2_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI2_Pos)) /* Assigment of value for ERR_L_BNDRY_MATCH_DI2 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI3_Pos _UINT32_(3)                                          /* (CSI_INT_ST_LINE) Error matching line start with line end for vc3 and dt3 Position */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI3_Msk (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI3_Pos) /* (CSI_INT_ST_LINE) Error matching line start with line end for vc3 and dt3 Mask */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI3(value) (CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI3_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI3_Pos)) /* Assigment of value for ERR_L_BNDRY_MATCH_DI3 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI4_Pos _UINT32_(4)                                          /* (CSI_INT_ST_LINE) Error matching line start with line end for vc4 and dt4 Position */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI4_Msk (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI4_Pos) /* (CSI_INT_ST_LINE) Error matching line start with line end for vc4 and dt4 Mask */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI4(value) (CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI4_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI4_Pos)) /* Assigment of value for ERR_L_BNDRY_MATCH_DI4 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI5_Pos _UINT32_(5)                                          /* (CSI_INT_ST_LINE) Error matching line start with line end for vc5 and dt5 Position */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI5_Msk (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI5_Pos) /* (CSI_INT_ST_LINE) Error matching line start with line end for vc5 and dt5 Mask */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI5(value) (CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI5_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI5_Pos)) /* Assigment of value for ERR_L_BNDRY_MATCH_DI5 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI6_Pos _UINT32_(6)                                          /* (CSI_INT_ST_LINE) Error matching line start with line end for vc6 and dt6 Position */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI6_Msk (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI6_Pos) /* (CSI_INT_ST_LINE) Error matching line start with line end for vc6 and dt6 Mask */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI6(value) (CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI6_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI6_Pos)) /* Assigment of value for ERR_L_BNDRY_MATCH_DI6 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI7_Pos _UINT32_(7)                                          /* (CSI_INT_ST_LINE) Error matching line start with line end for vc7 and dt7 Position */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI7_Msk (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI7_Pos) /* (CSI_INT_ST_LINE) Error matching line start with line end for vc7 and dt7 Mask */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI7(value) (CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI7_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI7_Pos)) /* Assigment of value for ERR_L_BNDRY_MATCH_DI7 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI0_Pos     _UINT32_(16)                                         /* (CSI_INT_ST_LINE) Error in the sequence of lines for vc0 and dt0 Position */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI0_Msk     (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_SEQ_DI0_Pos) /* (CSI_INT_ST_LINE) Error in the sequence of lines for vc0 and dt0 Mask */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI0(value)  (CSI_INT_ST_LINE_ERR_L_SEQ_DI0_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_SEQ_DI0_Pos)) /* Assigment of value for ERR_L_SEQ_DI0 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI1_Pos     _UINT32_(17)                                         /* (CSI_INT_ST_LINE) Error in the sequence of lines for vc1 and dt1 Position */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI1_Msk     (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_SEQ_DI1_Pos) /* (CSI_INT_ST_LINE) Error in the sequence of lines for vc1 and dt1 Mask */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI1(value)  (CSI_INT_ST_LINE_ERR_L_SEQ_DI1_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_SEQ_DI1_Pos)) /* Assigment of value for ERR_L_SEQ_DI1 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI2_Pos     _UINT32_(18)                                         /* (CSI_INT_ST_LINE) Error in the sequence of lines for vc2 and dt2 Position */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI2_Msk     (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_SEQ_DI2_Pos) /* (CSI_INT_ST_LINE) Error in the sequence of lines for vc2 and dt2 Mask */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI2(value)  (CSI_INT_ST_LINE_ERR_L_SEQ_DI2_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_SEQ_DI2_Pos)) /* Assigment of value for ERR_L_SEQ_DI2 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI3_Pos     _UINT32_(19)                                         /* (CSI_INT_ST_LINE) Error in the sequence of lines for vc3 and dt3 Position */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI3_Msk     (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_SEQ_DI3_Pos) /* (CSI_INT_ST_LINE) Error in the sequence of lines for vc3 and dt3 Mask */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI3(value)  (CSI_INT_ST_LINE_ERR_L_SEQ_DI3_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_SEQ_DI3_Pos)) /* Assigment of value for ERR_L_SEQ_DI3 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI4_Pos     _UINT32_(20)                                         /* (CSI_INT_ST_LINE) Error in the sequence of lines for vc4 and dt4 Position */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI4_Msk     (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_SEQ_DI4_Pos) /* (CSI_INT_ST_LINE) Error in the sequence of lines for vc4 and dt4 Mask */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI4(value)  (CSI_INT_ST_LINE_ERR_L_SEQ_DI4_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_SEQ_DI4_Pos)) /* Assigment of value for ERR_L_SEQ_DI4 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI5_Pos     _UINT32_(21)                                         /* (CSI_INT_ST_LINE) Error in the sequence of lines for vc5 and dt5 Position */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI5_Msk     (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_SEQ_DI5_Pos) /* (CSI_INT_ST_LINE) Error in the sequence of lines for vc5 and dt5 Mask */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI5(value)  (CSI_INT_ST_LINE_ERR_L_SEQ_DI5_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_SEQ_DI5_Pos)) /* Assigment of value for ERR_L_SEQ_DI5 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI6_Pos     _UINT32_(22)                                         /* (CSI_INT_ST_LINE) Error in the sequence of lines for vc6 and dt6 Position */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI6_Msk     (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_SEQ_DI6_Pos) /* (CSI_INT_ST_LINE) Error in the sequence of lines for vc6 and dt6 Mask */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI6(value)  (CSI_INT_ST_LINE_ERR_L_SEQ_DI6_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_SEQ_DI6_Pos)) /* Assigment of value for ERR_L_SEQ_DI6 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI7_Pos     _UINT32_(23)                                         /* (CSI_INT_ST_LINE) Error in the sequence of lines for vc7 and dt7 Position */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI7_Msk     (_UINT32_(0x1) << CSI_INT_ST_LINE_ERR_L_SEQ_DI7_Pos) /* (CSI_INT_ST_LINE) Error in the sequence of lines for vc7 and dt7 Mask */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI7(value)  (CSI_INT_ST_LINE_ERR_L_SEQ_DI7_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_SEQ_DI7_Pos)) /* Assigment of value for ERR_L_SEQ_DI7 in the CSI_INT_ST_LINE register */
#define CSI_INT_ST_LINE_Msk                   _UINT32_(0x00FF00FF)                                 /* (CSI_INT_ST_LINE) Register Mask  */

#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI_Pos _UINT32_(0)                                          /* (CSI_INT_ST_LINE Position) Error matching line start with line end for vcx and dtx */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI_Msk (_UINT32_(0xFF) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI_Pos) /* (CSI_INT_ST_LINE Mask) ERR_L_BNDRY_MATCH_DI */
#define CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI(value) (CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_BNDRY_MATCH_DI_Pos)) 
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI_Pos      _UINT32_(16)                                         /* (CSI_INT_ST_LINE Position) Error in the sequence of lines for vc7 and dt7 */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI_Msk      (_UINT32_(0xFF) << CSI_INT_ST_LINE_ERR_L_SEQ_DI_Pos) /* (CSI_INT_ST_LINE Mask) ERR_L_SEQ_DI */
#define CSI_INT_ST_LINE_ERR_L_SEQ_DI(value)   (CSI_INT_ST_LINE_ERR_L_SEQ_DI_Msk & (_UINT32_(value) << CSI_INT_ST_LINE_ERR_L_SEQ_DI_Pos)) 

/* -------- CSI_INT_MSK_LINE : (CSI Offset: 0x134) (R/W 32) Static read and write register    Interrupt mask for INT_ST_LINE controls which interrupt status bits will trigger the interrupt pin. Bit at 1 - Enable the interrupt source. Bit at 0 - Interrupt source is masked. -------- */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI0_Pos _UINT32_(0)                                          /* (CSI_INT_MSK_LINE) Mask for err_l_bndry_match_di0 Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI0_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI0_Pos) /* (CSI_INT_MSK_LINE) Mask for err_l_bndry_match_di0 Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI0(value) (CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI0_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI0_Pos)) /* Assigment of value for MASK_ERR_L_BNDRY_MATCH_DI0 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI1_Pos _UINT32_(1)                                          /* (CSI_INT_MSK_LINE) Mask for err_l_bndry_match_di1 Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI1_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI1_Pos) /* (CSI_INT_MSK_LINE) Mask for err_l_bndry_match_di1 Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI1(value) (CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI1_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI1_Pos)) /* Assigment of value for MASK_ERR_L_BNDRY_MATCH_DI1 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI2_Pos _UINT32_(2)                                          /* (CSI_INT_MSK_LINE) Mask for err_l_bndry_match_di2 Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI2_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI2_Pos) /* (CSI_INT_MSK_LINE) Mask for err_l_bndry_match_di2 Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI2(value) (CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI2_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI2_Pos)) /* Assigment of value for MASK_ERR_L_BNDRY_MATCH_DI2 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI3_Pos _UINT32_(3)                                          /* (CSI_INT_MSK_LINE) Mask for err_l_bndry_match_di3 Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI3_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI3_Pos) /* (CSI_INT_MSK_LINE) Mask for err_l_bndry_match_di3 Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI3(value) (CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI3_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI3_Pos)) /* Assigment of value for MASK_ERR_L_BNDRY_MATCH_DI3 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI4_Pos _UINT32_(4)                                          /* (CSI_INT_MSK_LINE) Mask for err_l_bndry_match_di4 Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI4_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI4_Pos) /* (CSI_INT_MSK_LINE) Mask for err_l_bndry_match_di4 Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI4(value) (CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI4_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI4_Pos)) /* Assigment of value for MASK_ERR_L_BNDRY_MATCH_DI4 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI5_Pos _UINT32_(5)                                          /* (CSI_INT_MSK_LINE) Mask for err_l_bndry_match_di5 Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI5_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI5_Pos) /* (CSI_INT_MSK_LINE) Mask for err_l_bndry_match_di5 Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI5(value) (CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI5_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI5_Pos)) /* Assigment of value for MASK_ERR_L_BNDRY_MATCH_DI5 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI6_Pos _UINT32_(6)                                          /* (CSI_INT_MSK_LINE) Mask for err_l_bndry_match_di6 Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI6_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI6_Pos) /* (CSI_INT_MSK_LINE) Mask for err_l_bndry_match_di6 Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI6(value) (CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI6_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI6_Pos)) /* Assigment of value for MASK_ERR_L_BNDRY_MATCH_DI6 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI7_Pos _UINT32_(7)                                          /* (CSI_INT_MSK_LINE) Mask for err_l_bndry_match_di7 Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI7_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI7_Pos) /* (CSI_INT_MSK_LINE) Mask for err_l_bndry_match_di7 Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI7(value) (CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI7_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI7_Pos)) /* Assigment of value for MASK_ERR_L_BNDRY_MATCH_DI7 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI0_Pos _UINT32_(16)                                         /* (CSI_INT_MSK_LINE) Mask for err_l_seq_di0 Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI0_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI0_Pos) /* (CSI_INT_MSK_LINE) Mask for err_l_seq_di0 Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI0(value) (CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI0_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI0_Pos)) /* Assigment of value for MASK_ERR_L_SEQ_DI0 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI1_Pos _UINT32_(17)                                         /* (CSI_INT_MSK_LINE) Mask for err_l_seq_di1 Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI1_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI1_Pos) /* (CSI_INT_MSK_LINE) Mask for err_l_seq_di1 Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI1(value) (CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI1_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI1_Pos)) /* Assigment of value for MASK_ERR_L_SEQ_DI1 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI2_Pos _UINT32_(18)                                         /* (CSI_INT_MSK_LINE) Mask for err_l_seq_di2 Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI2_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI2_Pos) /* (CSI_INT_MSK_LINE) Mask for err_l_seq_di2 Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI2(value) (CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI2_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI2_Pos)) /* Assigment of value for MASK_ERR_L_SEQ_DI2 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI3_Pos _UINT32_(19)                                         /* (CSI_INT_MSK_LINE) Mask for err_l_seq_di3 Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI3_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI3_Pos) /* (CSI_INT_MSK_LINE) Mask for err_l_seq_di3 Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI3(value) (CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI3_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI3_Pos)) /* Assigment of value for MASK_ERR_L_SEQ_DI3 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI4_Pos _UINT32_(20)                                         /* (CSI_INT_MSK_LINE) Mask for err_l_seq_di4 Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI4_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI4_Pos) /* (CSI_INT_MSK_LINE) Mask for err_l_seq_di4 Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI4(value) (CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI4_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI4_Pos)) /* Assigment of value for MASK_ERR_L_SEQ_DI4 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI5_Pos _UINT32_(21)                                         /* (CSI_INT_MSK_LINE) Mask for err_l_seq_di5 Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI5_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI5_Pos) /* (CSI_INT_MSK_LINE) Mask for err_l_seq_di5 Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI5(value) (CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI5_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI5_Pos)) /* Assigment of value for MASK_ERR_L_SEQ_DI5 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI6_Pos _UINT32_(22)                                         /* (CSI_INT_MSK_LINE) Mask for err_l_seq_di6 Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI6_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI6_Pos) /* (CSI_INT_MSK_LINE) Mask for err_l_seq_di6 Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI6(value) (CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI6_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI6_Pos)) /* Assigment of value for MASK_ERR_L_SEQ_DI6 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI7_Pos _UINT32_(23)                                         /* (CSI_INT_MSK_LINE) Mask for err_l_seq_di7 Position */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI7_Msk (_UINT32_(0x1) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI7_Pos) /* (CSI_INT_MSK_LINE) Mask for err_l_seq_di7 Mask */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI7(value) (CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI7_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI7_Pos)) /* Assigment of value for MASK_ERR_L_SEQ_DI7 in the CSI_INT_MSK_LINE register */
#define CSI_INT_MSK_LINE_Msk                  _UINT32_(0x00FF00FF)                                 /* (CSI_INT_MSK_LINE) Register Mask  */

#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI_Pos _UINT32_(0)                                          /* (CSI_INT_MSK_LINE Position) Mask for err_l_bndry_match_dix */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI_Msk (_UINT32_(0xFF) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI_Pos) /* (CSI_INT_MSK_LINE Mask) MASK_ERR_L_BNDRY_MATCH_DI */
#define CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI(value) (CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_BNDRY_MATCH_DI_Pos)) 
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI_Pos _UINT32_(16)                                         /* (CSI_INT_MSK_LINE Position) Mask for err_l_seq_di7 */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI_Msk (_UINT32_(0xFF) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI_Pos) /* (CSI_INT_MSK_LINE Mask) MASK_ERR_L_SEQ_DI */
#define CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI(value) (CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI_Msk & (_UINT32_(value) << CSI_INT_MSK_LINE_MASK_ERR_L_SEQ_DI_Pos)) 

/* -------- CSI_INT_FORCE_LINE : (CSI Offset: 0x138) (R/W 32) Static read and write register    Interrupt force register is used for test purposes, and allows triggering INT_ST_LINE interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, because it may be extremely complex to generate stimuli for that purpose. -------- */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI0_Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_LINE) Force err_l_bndry_match_di0 Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI0_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI0_Pos) /* (CSI_INT_FORCE_LINE) Force err_l_bndry_match_di0 Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI0(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI0_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI0_Pos)) /* Assigment of value for FORCE_ERR_L_BNDRY_MATCH_DI0 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI1_Pos _UINT32_(1)                                          /* (CSI_INT_FORCE_LINE) Force err_l_bndry_match_di1 Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI1_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI1_Pos) /* (CSI_INT_FORCE_LINE) Force err_l_bndry_match_di1 Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI1(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI1_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI1_Pos)) /* Assigment of value for FORCE_ERR_L_BNDRY_MATCH_DI1 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI2_Pos _UINT32_(2)                                          /* (CSI_INT_FORCE_LINE) Force err_l_bndry_match_di2 Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI2_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI2_Pos) /* (CSI_INT_FORCE_LINE) Force err_l_bndry_match_di2 Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI2(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI2_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI2_Pos)) /* Assigment of value for FORCE_ERR_L_BNDRY_MATCH_DI2 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI3_Pos _UINT32_(3)                                          /* (CSI_INT_FORCE_LINE) Force err_l_bndry_match_di3 Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI3_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI3_Pos) /* (CSI_INT_FORCE_LINE) Force err_l_bndry_match_di3 Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI3(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI3_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI3_Pos)) /* Assigment of value for FORCE_ERR_L_BNDRY_MATCH_DI3 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI4_Pos _UINT32_(4)                                          /* (CSI_INT_FORCE_LINE) Force err_l_bndry_match_di4 Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI4_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI4_Pos) /* (CSI_INT_FORCE_LINE) Force err_l_bndry_match_di4 Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI4(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI4_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI4_Pos)) /* Assigment of value for FORCE_ERR_L_BNDRY_MATCH_DI4 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI5_Pos _UINT32_(5)                                          /* (CSI_INT_FORCE_LINE) Force err_l_bndry_match_di5 Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI5_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI5_Pos) /* (CSI_INT_FORCE_LINE) Force err_l_bndry_match_di5 Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI5(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI5_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI5_Pos)) /* Assigment of value for FORCE_ERR_L_BNDRY_MATCH_DI5 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI6_Pos _UINT32_(6)                                          /* (CSI_INT_FORCE_LINE) Force err_l_bndry_match_di6 Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI6_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI6_Pos) /* (CSI_INT_FORCE_LINE) Force err_l_bndry_match_di6 Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI6(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI6_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI6_Pos)) /* Assigment of value for FORCE_ERR_L_BNDRY_MATCH_DI6 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI7_Pos _UINT32_(7)                                          /* (CSI_INT_FORCE_LINE) Force err_l_bndry_match_di7 Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI7_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI7_Pos) /* (CSI_INT_FORCE_LINE) Force err_l_bndry_match_di7 Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI7(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI7_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI7_Pos)) /* Assigment of value for FORCE_ERR_L_BNDRY_MATCH_DI7 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI0_Pos _UINT32_(16)                                         /* (CSI_INT_FORCE_LINE) Force err_l_seq_di0 Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI0_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI0_Pos) /* (CSI_INT_FORCE_LINE) Force err_l_seq_di0 Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI0(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI0_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI0_Pos)) /* Assigment of value for FORCE_ERR_L_SEQ_DI0 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI1_Pos _UINT32_(17)                                         /* (CSI_INT_FORCE_LINE) Force err_l_seq_di1 Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI1_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI1_Pos) /* (CSI_INT_FORCE_LINE) Force err_l_seq_di1 Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI1(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI1_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI1_Pos)) /* Assigment of value for FORCE_ERR_L_SEQ_DI1 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI2_Pos _UINT32_(18)                                         /* (CSI_INT_FORCE_LINE) Force err_l_seq_di2 Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI2_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI2_Pos) /* (CSI_INT_FORCE_LINE) Force err_l_seq_di2 Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI2(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI2_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI2_Pos)) /* Assigment of value for FORCE_ERR_L_SEQ_DI2 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI3_Pos _UINT32_(19)                                         /* (CSI_INT_FORCE_LINE) Force err_l_seq_di3 Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI3_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI3_Pos) /* (CSI_INT_FORCE_LINE) Force err_l_seq_di3 Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI3(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI3_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI3_Pos)) /* Assigment of value for FORCE_ERR_L_SEQ_DI3 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI4_Pos _UINT32_(20)                                         /* (CSI_INT_FORCE_LINE) Force err_l_seq_di4 Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI4_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI4_Pos) /* (CSI_INT_FORCE_LINE) Force err_l_seq_di4 Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI4(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI4_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI4_Pos)) /* Assigment of value for FORCE_ERR_L_SEQ_DI4 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI5_Pos _UINT32_(21)                                         /* (CSI_INT_FORCE_LINE) Force err_l_seq_di5 Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI5_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI5_Pos) /* (CSI_INT_FORCE_LINE) Force err_l_seq_di5 Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI5(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI5_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI5_Pos)) /* Assigment of value for FORCE_ERR_L_SEQ_DI5 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI6_Pos _UINT32_(22)                                         /* (CSI_INT_FORCE_LINE) Force err_l_seq_di6 Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI6_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI6_Pos) /* (CSI_INT_FORCE_LINE) Force err_l_seq_di6 Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI6(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI6_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI6_Pos)) /* Assigment of value for FORCE_ERR_L_SEQ_DI6 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI7_Pos _UINT32_(23)                                         /* (CSI_INT_FORCE_LINE) Force err_l_seq_di7 Position */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI7_Msk (_UINT32_(0x1) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI7_Pos) /* (CSI_INT_FORCE_LINE) Force err_l_seq_di7 Mask */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI7(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI7_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI7_Pos)) /* Assigment of value for FORCE_ERR_L_SEQ_DI7 in the CSI_INT_FORCE_LINE register */
#define CSI_INT_FORCE_LINE_Msk                _UINT32_(0x00FF00FF)                                 /* (CSI_INT_FORCE_LINE) Register Mask  */

#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI_Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_LINE Position) Force err_l_bndry_match_dix */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI_Msk (_UINT32_(0xFF) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI_Pos) /* (CSI_INT_FORCE_LINE Mask) FORCE_ERR_L_BNDRY_MATCH_DI */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_BNDRY_MATCH_DI_Pos)) 
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI_Pos _UINT32_(16)                                         /* (CSI_INT_FORCE_LINE Position) Force err_l_seq_di7 */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI_Msk (_UINT32_(0xFF) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI_Pos) /* (CSI_INT_FORCE_LINE Mask) FORCE_ERR_L_SEQ_DI */
#define CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI(value) (CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI_Msk & (_UINT32_(value) << CSI_INT_FORCE_LINE_FORCE_ERR_L_SEQ_DI_Pos)) 

/* -------- CSI_INT_ST_IPI : (CSI Offset: 0x140) ( R/ 32) Clear on read register Fatal Interruption caused by IPI interface. Groups and notifies which interruption bits caused the interruption. Stores the source of the error. Reading INT_ST_IPI register does not clear the interrupt pin -------- */
#define CSI_INT_ST_IPI_PIXEL_IF_FIFO_UNDERFLOW_Pos _UINT32_(0)                                          /* (CSI_INT_ST_IPI) The FIFO has become empty before the expected number of pixels (calculated from the packet's header) could be extracted to the pixel interface Position */
#define CSI_INT_ST_IPI_PIXEL_IF_FIFO_UNDERFLOW_Msk (_UINT32_(0x1) << CSI_INT_ST_IPI_PIXEL_IF_FIFO_UNDERFLOW_Pos) /* (CSI_INT_ST_IPI) The FIFO has become empty before the expected number of pixels (calculated from the packet's header) could be extracted to the pixel interface Mask */
#define CSI_INT_ST_IPI_PIXEL_IF_FIFO_UNDERFLOW(value) (CSI_INT_ST_IPI_PIXEL_IF_FIFO_UNDERFLOW_Msk & (_UINT32_(value) << CSI_INT_ST_IPI_PIXEL_IF_FIFO_UNDERFLOW_Pos)) /* Assigment of value for PIXEL_IF_FIFO_UNDERFLOW in the CSI_INT_ST_IPI register */
#define CSI_INT_ST_IPI_PIXEL_IF_FIFO_OVERFLOW_Pos _UINT32_(1)                                          /* (CSI_INT_ST_IPI) The FIFO of pixel interface has lost information because some more data arrived when it was full Position */
#define CSI_INT_ST_IPI_PIXEL_IF_FIFO_OVERFLOW_Msk (_UINT32_(0x1) << CSI_INT_ST_IPI_PIXEL_IF_FIFO_OVERFLOW_Pos) /* (CSI_INT_ST_IPI) The FIFO of pixel interface has lost information because some more data arrived when it was full Mask */
#define CSI_INT_ST_IPI_PIXEL_IF_FIFO_OVERFLOW(value) (CSI_INT_ST_IPI_PIXEL_IF_FIFO_OVERFLOW_Msk & (_UINT32_(value) << CSI_INT_ST_IPI_PIXEL_IF_FIFO_OVERFLOW_Pos)) /* Assigment of value for PIXEL_IF_FIFO_OVERFLOW in the CSI_INT_ST_IPI register */
#define CSI_INT_ST_IPI_PIXEL_IF_FRAME_SYNC_ERR_Pos _UINT32_(2)                                          /* (CSI_INT_ST_IPI) New frame is received but previous has not been completed Position */
#define CSI_INT_ST_IPI_PIXEL_IF_FRAME_SYNC_ERR_Msk (_UINT32_(0x1) << CSI_INT_ST_IPI_PIXEL_IF_FRAME_SYNC_ERR_Pos) /* (CSI_INT_ST_IPI) New frame is received but previous has not been completed Mask */
#define CSI_INT_ST_IPI_PIXEL_IF_FRAME_SYNC_ERR(value) (CSI_INT_ST_IPI_PIXEL_IF_FRAME_SYNC_ERR_Msk & (_UINT32_(value) << CSI_INT_ST_IPI_PIXEL_IF_FRAME_SYNC_ERR_Pos)) /* Assigment of value for PIXEL_IF_FRAME_SYNC_ERR in the CSI_INT_ST_IPI register */
#define CSI_INT_ST_IPI_PIXEL_IF_FIFO_NEMPTY_FS_Pos _UINT32_(3)                                          /* (CSI_INT_ST_IPI) The FIFO of pixel interface is not empty at the start of a new frame. If this is expected this interrupt should be masked Position */
#define CSI_INT_ST_IPI_PIXEL_IF_FIFO_NEMPTY_FS_Msk (_UINT32_(0x1) << CSI_INT_ST_IPI_PIXEL_IF_FIFO_NEMPTY_FS_Pos) /* (CSI_INT_ST_IPI) The FIFO of pixel interface is not empty at the start of a new frame. If this is expected this interrupt should be masked Mask */
#define CSI_INT_ST_IPI_PIXEL_IF_FIFO_NEMPTY_FS(value) (CSI_INT_ST_IPI_PIXEL_IF_FIFO_NEMPTY_FS_Msk & (_UINT32_(value) << CSI_INT_ST_IPI_PIXEL_IF_FIFO_NEMPTY_FS_Pos)) /* Assigment of value for PIXEL_IF_FIFO_NEMPTY_FS in the CSI_INT_ST_IPI register */
#define CSI_INT_ST_IPI_PIXEL_IF_HLINE_ERR_Pos _UINT32_(4)                                          /* (CSI_INT_ST_IPI) Horizontal line time error (only available in controller mode) Position */
#define CSI_INT_ST_IPI_PIXEL_IF_HLINE_ERR_Msk (_UINT32_(0x1) << CSI_INT_ST_IPI_PIXEL_IF_HLINE_ERR_Pos) /* (CSI_INT_ST_IPI) Horizontal line time error (only available in controller mode) Mask */
#define CSI_INT_ST_IPI_PIXEL_IF_HLINE_ERR(value) (CSI_INT_ST_IPI_PIXEL_IF_HLINE_ERR_Msk & (_UINT32_(value) << CSI_INT_ST_IPI_PIXEL_IF_HLINE_ERR_Pos)) /* Assigment of value for PIXEL_IF_HLINE_ERR in the CSI_INT_ST_IPI register */
#define CSI_INT_ST_IPI_Msk                    _UINT32_(0x0000001F)                                 /* (CSI_INT_ST_IPI) Register Mask  */


/* -------- CSI_INT_MSK_IPI : (CSI Offset: 0x144) (R/W 32) Static read and write register Each bit of this register masks the interruption from INT_ST_IPI from generating an interruption event. Once a bit of the mask is active, the respective error of the INT_ST_ IPI register is masked preventing the error signal from signaling an interruption through the interrupt pin -------- */
#define CSI_INT_MSK_IPI_MSK_PIXEL_IF_FIFO_UNDERFLOW_Pos _UINT32_(0)                                          /* (CSI_INT_MSK_IPI) Mask for pixel_if_fifo_underflow Position */
#define CSI_INT_MSK_IPI_MSK_PIXEL_IF_FIFO_UNDERFLOW_Msk (_UINT32_(0x1) << CSI_INT_MSK_IPI_MSK_PIXEL_IF_FIFO_UNDERFLOW_Pos) /* (CSI_INT_MSK_IPI) Mask for pixel_if_fifo_underflow Mask */
#define CSI_INT_MSK_IPI_MSK_PIXEL_IF_FIFO_UNDERFLOW(value) (CSI_INT_MSK_IPI_MSK_PIXEL_IF_FIFO_UNDERFLOW_Msk & (_UINT32_(value) << CSI_INT_MSK_IPI_MSK_PIXEL_IF_FIFO_UNDERFLOW_Pos)) /* Assigment of value for MSK_PIXEL_IF_FIFO_UNDERFLOW in the CSI_INT_MSK_IPI register */
#define CSI_INT_MSK_IPI_MSK_PIXEL_IF_FIFO_OVERFLOW_Pos _UINT32_(1)                                          /* (CSI_INT_MSK_IPI) Mask for pixel_if_fifo_overflow Position */
#define CSI_INT_MSK_IPI_MSK_PIXEL_IF_FIFO_OVERFLOW_Msk (_UINT32_(0x1) << CSI_INT_MSK_IPI_MSK_PIXEL_IF_FIFO_OVERFLOW_Pos) /* (CSI_INT_MSK_IPI) Mask for pixel_if_fifo_overflow Mask */
#define CSI_INT_MSK_IPI_MSK_PIXEL_IF_FIFO_OVERFLOW(value) (CSI_INT_MSK_IPI_MSK_PIXEL_IF_FIFO_OVERFLOW_Msk & (_UINT32_(value) << CSI_INT_MSK_IPI_MSK_PIXEL_IF_FIFO_OVERFLOW_Pos)) /* Assigment of value for MSK_PIXEL_IF_FIFO_OVERFLOW in the CSI_INT_MSK_IPI register */
#define CSI_INT_MSK_IPI_MSK_FRAME_SYNC_ERR_Pos _UINT32_(2)                                          /* (CSI_INT_MSK_IPI) Mask for pixel_if_frame_sync_err Position */
#define CSI_INT_MSK_IPI_MSK_FRAME_SYNC_ERR_Msk (_UINT32_(0x1) << CSI_INT_MSK_IPI_MSK_FRAME_SYNC_ERR_Pos) /* (CSI_INT_MSK_IPI) Mask for pixel_if_frame_sync_err Mask */
#define CSI_INT_MSK_IPI_MSK_FRAME_SYNC_ERR(value) (CSI_INT_MSK_IPI_MSK_FRAME_SYNC_ERR_Msk & (_UINT32_(value) << CSI_INT_MSK_IPI_MSK_FRAME_SYNC_ERR_Pos)) /* Assigment of value for MSK_FRAME_SYNC_ERR in the CSI_INT_MSK_IPI register */
#define CSI_INT_MSK_IPI_MSK_PIXEL_IF_FIFO_NEMPTY_FS_Pos _UINT32_(3)                                          /* (CSI_INT_MSK_IPI) Mask pixel_if_fifo_nempty_fs Position */
#define CSI_INT_MSK_IPI_MSK_PIXEL_IF_FIFO_NEMPTY_FS_Msk (_UINT32_(0x1) << CSI_INT_MSK_IPI_MSK_PIXEL_IF_FIFO_NEMPTY_FS_Pos) /* (CSI_INT_MSK_IPI) Mask pixel_if_fifo_nempty_fs Mask */
#define CSI_INT_MSK_IPI_MSK_PIXEL_IF_FIFO_NEMPTY_FS(value) (CSI_INT_MSK_IPI_MSK_PIXEL_IF_FIFO_NEMPTY_FS_Msk & (_UINT32_(value) << CSI_INT_MSK_IPI_MSK_PIXEL_IF_FIFO_NEMPTY_FS_Pos)) /* Assigment of value for MSK_PIXEL_IF_FIFO_NEMPTY_FS in the CSI_INT_MSK_IPI register */
#define CSI_INT_MSK_IPI_MSK_PIXEL_IF_HLINE_ERR_Pos _UINT32_(4)                                          /* (CSI_INT_MSK_IPI) Mask pixel_if_hline_err Position */
#define CSI_INT_MSK_IPI_MSK_PIXEL_IF_HLINE_ERR_Msk (_UINT32_(0x1) << CSI_INT_MSK_IPI_MSK_PIXEL_IF_HLINE_ERR_Pos) /* (CSI_INT_MSK_IPI) Mask pixel_if_hline_err Mask */
#define CSI_INT_MSK_IPI_MSK_PIXEL_IF_HLINE_ERR(value) (CSI_INT_MSK_IPI_MSK_PIXEL_IF_HLINE_ERR_Msk & (_UINT32_(value) << CSI_INT_MSK_IPI_MSK_PIXEL_IF_HLINE_ERR_Pos)) /* Assigment of value for MSK_PIXEL_IF_HLINE_ERR in the CSI_INT_MSK_IPI register */
#define CSI_INT_MSK_IPI_Msk                   _UINT32_(0x0000001F)                                 /* (CSI_INT_MSK_IPI) Register Mask  */


/* -------- CSI_INT_FORCE_IPI : (CSI Offset: 0x148) (R/W 32) Static read and write register Interrupt force register is used for test purposes, and allows triggering INT_ST_IPI interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, because it may be extremely complex to generate stimuli for that purpose -------- */
#define CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_FIFO_UNDERFLOW_Pos _UINT32_(0)                                          /* (CSI_INT_FORCE_IPI) Force for pixel_if_fifo_underflow Position */
#define CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_FIFO_UNDERFLOW_Msk (_UINT32_(0x1) << CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_FIFO_UNDERFLOW_Pos) /* (CSI_INT_FORCE_IPI) Force for pixel_if_fifo_underflow Mask */
#define CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_FIFO_UNDERFLOW(value) (CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_FIFO_UNDERFLOW_Msk & (_UINT32_(value) << CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_FIFO_UNDERFLOW_Pos)) /* Assigment of value for FORCE_PIXEL_IF_FIFO_UNDERFLOW in the CSI_INT_FORCE_IPI register */
#define CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_FIFO_OVERFLOW_Pos _UINT32_(1)                                          /* (CSI_INT_FORCE_IPI) Force for pixel_if_fifo_overflow Position */
#define CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_FIFO_OVERFLOW_Msk (_UINT32_(0x1) << CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_FIFO_OVERFLOW_Pos) /* (CSI_INT_FORCE_IPI) Force for pixel_if_fifo_overflow Mask */
#define CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_FIFO_OVERFLOW(value) (CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_FIFO_OVERFLOW_Msk & (_UINT32_(value) << CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_FIFO_OVERFLOW_Pos)) /* Assigment of value for FORCE_PIXEL_IF_FIFO_OVERFLOW in the CSI_INT_FORCE_IPI register */
#define CSI_INT_FORCE_IPI_FORCE_FRAME_SYNC_ERR_Pos _UINT32_(2)                                          /* (CSI_INT_FORCE_IPI) Force for frame_sync_err Position */
#define CSI_INT_FORCE_IPI_FORCE_FRAME_SYNC_ERR_Msk (_UINT32_(0x1) << CSI_INT_FORCE_IPI_FORCE_FRAME_SYNC_ERR_Pos) /* (CSI_INT_FORCE_IPI) Force for frame_sync_err Mask */
#define CSI_INT_FORCE_IPI_FORCE_FRAME_SYNC_ERR(value) (CSI_INT_FORCE_IPI_FORCE_FRAME_SYNC_ERR_Msk & (_UINT32_(value) << CSI_INT_FORCE_IPI_FORCE_FRAME_SYNC_ERR_Pos)) /* Assigment of value for FORCE_FRAME_SYNC_ERR in the CSI_INT_FORCE_IPI register */
#define CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_FIFO_NEMPTY_FS_Pos _UINT32_(3)                                          /* (CSI_INT_FORCE_IPI) Force pixel_if_fifo_nempty_fs Position */
#define CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_FIFO_NEMPTY_FS_Msk (_UINT32_(0x1) << CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_FIFO_NEMPTY_FS_Pos) /* (CSI_INT_FORCE_IPI) Force pixel_if_fifo_nempty_fs Mask */
#define CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_FIFO_NEMPTY_FS(value) (CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_FIFO_NEMPTY_FS_Msk & (_UINT32_(value) << CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_FIFO_NEMPTY_FS_Pos)) /* Assigment of value for FORCE_PIXEL_IF_FIFO_NEMPTY_FS in the CSI_INT_FORCE_IPI register */
#define CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_HLINE_ERR_Pos _UINT32_(4)                                          /* (CSI_INT_FORCE_IPI) Force pixel_if_hline_err Position */
#define CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_HLINE_ERR_Msk (_UINT32_(0x1) << CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_HLINE_ERR_Pos) /* (CSI_INT_FORCE_IPI) Force pixel_if_hline_err Mask */
#define CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_HLINE_ERR(value) (CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_HLINE_ERR_Msk & (_UINT32_(value) << CSI_INT_FORCE_IPI_FORCE_PIXEL_IF_HLINE_ERR_Pos)) /* Assigment of value for FORCE_PIXEL_IF_HLINE_ERR in the CSI_INT_FORCE_IPI register */
#define CSI_INT_FORCE_IPI_Msk                 _UINT32_(0x0000001F)                                 /* (CSI_INT_FORCE_IPI) Register Mask  */


/* -------- CSI_SCRAMBLING : (CSI Offset: 0x300) (R/W 32) This register configures the De-scrambler block. -------- */
#define CSI_SCRAMBLING_SCRAMBLE_ENABLE_Pos    _UINT32_(0)                                          /* (CSI_SCRAMBLING) Enables data de-scrambling on the controller side. Position */
#define CSI_SCRAMBLING_SCRAMBLE_ENABLE_Msk    (_UINT32_(0x1) << CSI_SCRAMBLING_SCRAMBLE_ENABLE_Pos) /* (CSI_SCRAMBLING) Enables data de-scrambling on the controller side. Mask */
#define CSI_SCRAMBLING_SCRAMBLE_ENABLE(value) (CSI_SCRAMBLING_SCRAMBLE_ENABLE_Msk & (_UINT32_(value) << CSI_SCRAMBLING_SCRAMBLE_ENABLE_Pos)) /* Assigment of value for SCRAMBLE_ENABLE in the CSI_SCRAMBLING register */
#define CSI_SCRAMBLING_Msk                    _UINT32_(0x00000001)                                 /* (CSI_SCRAMBLING) Register Mask  */


/* -------- CSI_SCRAMBLING_SEED1 : (CSI Offset: 0x304) (R/W 32) This register configures the seed used by De-scrambler block for lane 1 -------- */
#define CSI_SCRAMBLING_SEED1_SCRAMBLE_SEED_LANE1_Pos _UINT32_(0)                                          /* (CSI_SCRAMBLING_SEED1) Seed used by De-scrambler block for lane 1 Position */
#define CSI_SCRAMBLING_SEED1_SCRAMBLE_SEED_LANE1_Msk (_UINT32_(0xFFFF) << CSI_SCRAMBLING_SEED1_SCRAMBLE_SEED_LANE1_Pos) /* (CSI_SCRAMBLING_SEED1) Seed used by De-scrambler block for lane 1 Mask */
#define CSI_SCRAMBLING_SEED1_SCRAMBLE_SEED_LANE1(value) (CSI_SCRAMBLING_SEED1_SCRAMBLE_SEED_LANE1_Msk & (_UINT32_(value) << CSI_SCRAMBLING_SEED1_SCRAMBLE_SEED_LANE1_Pos)) /* Assigment of value for SCRAMBLE_SEED_LANE1 in the CSI_SCRAMBLING_SEED1 register */
#define CSI_SCRAMBLING_SEED1_Msk              _UINT32_(0x0000FFFF)                                 /* (CSI_SCRAMBLING_SEED1) Register Mask  */


/* -------- CSI_SCRAMBLING_SEED2 : (CSI Offset: 0x308) (R/W 32) This register configures the seed used by De-scrambler block for lane 2 -------- */
#define CSI_SCRAMBLING_SEED2_SCRAMBLE_SEED_LANE2_Pos _UINT32_(0)                                          /* (CSI_SCRAMBLING_SEED2) Seed used by De-scrambler block for lane 2 Position */
#define CSI_SCRAMBLING_SEED2_SCRAMBLE_SEED_LANE2_Msk (_UINT32_(0xFFFF) << CSI_SCRAMBLING_SEED2_SCRAMBLE_SEED_LANE2_Pos) /* (CSI_SCRAMBLING_SEED2) Seed used by De-scrambler block for lane 2 Mask */
#define CSI_SCRAMBLING_SEED2_SCRAMBLE_SEED_LANE2(value) (CSI_SCRAMBLING_SEED2_SCRAMBLE_SEED_LANE2_Msk & (_UINT32_(value) << CSI_SCRAMBLING_SEED2_SCRAMBLE_SEED_LANE2_Pos)) /* Assigment of value for SCRAMBLE_SEED_LANE2 in the CSI_SCRAMBLING_SEED2 register */
#define CSI_SCRAMBLING_SEED2_Msk              _UINT32_(0x0000FFFF)                                 /* (CSI_SCRAMBLING_SEED2) Register Mask  */


/** \brief CSI register offsets definitions */
#define CSI_VERSION_REG_OFST           _UINT32_(0x00)      /* (CSI_VERSION) Read-only register   Contains the version of DWC_mipi_csi2_host coded in 32-bit ASCII code. Offset */
#define CSI_N_LANES_REG_OFST           _UINT32_(0x04)      /* (CSI_N_LANES) Static read and write register   Configures the number of active lanes that the DWC_mipi_csi2_host uses to receive the camera device data. Offset */
#define CSI_CSI2_RESETN_REG_OFST       _UINT32_(0x08)      /* (CSI_CSI2_RESETN) Static read and write register   Controls the DWC_mipi_csi2_host logic reset state. When activated, the internal logic of the controller goes into the reset state. The configuration is not reset to default values with this register, instead, only the internal controller logic is affected. Offset */
#define CSI_INT_ST_MAIN_REG_OFST       _UINT32_(0x0C)      /* (CSI_INT_ST_MAIN) Clear on read register   Contains the status of individual interrupt sources, regardless of the contents of the associated interrupt mask registers, so it is possible to service the interrupt status registers by polling. Reading INT_ST_MAIN register clears the interrupt pin. Offset */
#define CSI_DATA_IDS_1_REG_OFST        _UINT32_(0x10)      /* (CSI_DATA_IDS_1) Static read and write register   Programs the data Ids for matching line error reporting.   Enables up to eight different data Ids that can be identified simultaneously. Offset */
#define CSI_DATA_IDS_2_REG_OFST        _UINT32_(0x14)      /* (CSI_DATA_IDS_2) Static read and write register   Programs the data Ids for matching line error reporting.   Configures Data ID definition for four additional pairs of data types and virtual channel identifiers. Offset */
#define CSI_PHY_SHUTDOWNZ_REG_OFST     _UINT32_(0x40)      /* (CSI_PHY_SHUTDOWNZ) Active low   Controls the PHY Shutdown mode. In this state, the PHY sets the analog and digital circuitry in the Reset state. Offset */
#define CSI_DPHY_RSTZ_REG_OFST         _UINT32_(0x44)      /* (CSI_DPHY_RSTZ) Active low   Controls the PHY Reset mode. in this state, the PHY sets the digital circuitry in the Reset State. Offset */
#define CSI_PHY_RX_REG_OFST            _UINT32_(0x48)      /* (CSI_PHY_RX) Read-only register Contains the status of RX-related signals from PHY:  RXULPSESC* RXCLKACTIVEHS (D-PHY)  It contains information such as, if the clock lane is receiving high-speed clock signal, or if the data and clock lanes are in Ultra Low Power Mode (ULPM). Offset */
#define CSI_PHY_STOPSTATE_REG_OFST     _UINT32_(0x4C)      /* (CSI_PHY_STOPSTATE) Read-only register   Contains the STOPSTATE signal status from PHY. Offset */
#define CSI_PHY_TEST_CTRL0_REG_OFST    _UINT32_(0x50)      /* (CSI_PHY_TEST_CTRL0) Dynamic register   Control for vendor specific interface in the PHY.   Controls the Synopsys D-PHY Test and Control interface. This register controls the TESTCLR and TESTCLK signals. Offset */
#define CSI_PHY_TEST_CTRL1_REG_OFST    _UINT32_(0x54)      /* (CSI_PHY_TEST_CTRL1) Dynamic register   Control for vendor specific interface in the PHY.   Controls the Synopsys D-PHY Test and Control interface. This register controls the TESTENABLE signal and the TESTDIN bus. Reading from this register retrieves the value from TESTDOUT. Offset */
#define CSI_IPI_MODE_REG_OFST          _UINT32_(0x80)      /* (CSI_IPI_MODE) This register selects how the IPI interface generates the video frame Offset */
#define CSI_IPI_VCID_REG_OFST          _UINT32_(0x84)      /* (CSI_IPI_VCID) This register selects the virtual channel processed by IPI Offset */
#define CSI_IPI_DATA_TYPE_REG_OFST     _UINT32_(0x88)      /* (CSI_IPI_DATA_TYPE) This register selects the data type processed by IPI Offset */
#define CSI_IPI_MEM_FLUSH_REG_OFST     _UINT32_(0x8C)      /* (CSI_IPI_MEM_FLUSH) This register control the flush of IPI memory Offset */
#define CSI_IPI_HSA_TIME_REG_OFST      _UINT32_(0x90)      /* (CSI_IPI_HSA_TIME) This register configures the video Horizontal Synchronism Active (HSA) time Offset */
#define CSI_IPI_HBP_TIME_REG_OFST      _UINT32_(0x94)      /* (CSI_IPI_HBP_TIME) This register configures the video Horizontal Back Porch (HBP) time Offset */
#define CSI_IPI_HSD_TIME_REG_OFST      _UINT32_(0x98)      /* (CSI_IPI_HSD_TIME) This register configures the video Horizontal Sync Delay (HSD) time Offset */
#define CSI_IPI_HLINE_TIME_REG_OFST    _UINT32_(0x9C)      /* (CSI_IPI_HLINE_TIME) This register configures the overall time for each video line Offset */
#define CSI_IPI_VSA_LINES_REG_OFST     _UINT32_(0xB0)      /* (CSI_IPI_VSA_LINES) This register configures the Vertical Synchronism Active (VSA) period Offset */
#define CSI_IPI_VBP_LINES_REG_OFST     _UINT32_(0xB4)      /* (CSI_IPI_VBP_LINES) This register configures the Vertical Back Porch (VBP) period Offset */
#define CSI_IPI_VFP_LINES_REG_OFST     _UINT32_(0xB8)      /* (CSI_IPI_VFP_LINES) This register configures the Vertical Front Porch (VFP) period Offset */
#define CSI_IPI_VACTIVE_LINES_REG_OFST _UINT32_(0xBC)      /* (CSI_IPI_VACTIVE_LINES) This register configures the vertical resolution of the video Offset */
#define CSI_PHY_CAL_REG_OFST           _UINT32_(0xCC)      /* (CSI_PHY_CAL) Clear on read register    Contains the CALIBRATION signal status from Synopsys D-PHY. Offset */
#define CSI_INT_ST_PHY_FATAL_REG_OFST  _UINT32_(0xE0)      /* (CSI_INT_ST_PHY_FATAL) Clear on read register   Groups the fatal interruptions caused by PHY Packet discarded.   Stores the source of the error.   Reading INT_ST_PHY_FATAL register does not clear the interrupt pin. Offset */
#define CSI_INT_MSK_PHY_FATAL_REG_OFST _UINT32_(0xE4)      /* (CSI_INT_MSK_PHY_FATAL) Static read and write register    Interrupt mask for INT_ST_PHY_FATAL controls which interrupt status bits will trigger the interrupt pin. Bit at 1 - Enable the interrupt source. Bit at 0 - Interrupt source is masked. Offset */
#define CSI_INT_FORCE_PHY_FATAL_REG_OFST _UINT32_(0xE8)      /* (CSI_INT_FORCE_PHY_FATAL) Static read and write register    Interrupt Force register is used for test purposes, and allows triggering INT_ST_PHY_FATAL interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, since it may be extremely complex to generate stimuli for that purpose. Offset */
#define CSI_INT_ST_PKT_FATAL_REG_OFST  _UINT32_(0xF0)      /* (CSI_INT_ST_PKT_FATAL) Clear on read register    Groups the fatal interruption related with Packet construction. Packet discarded.   Notifies which interruption bit has caused the interruption.   Stores the source of the error.   Reading INT_ST_PKT_FATAL register does not clear the interrupt pin. Offset */
#define CSI_INT_MSK_PKT_FATAL_REG_OFST _UINT32_(0xF4)      /* (CSI_INT_MSK_PKT_FATAL) Static read and write register    Interrupt mask for INT_ST_PKT_FATAL controls which interrupt status bits will trigger the interrupt pin. Bit at 1 - Enable the interrupt source. Bit at 0 - Interrupt source is masked. Offset */
#define CSI_INT_FORCE_PKT_FATAL_REG_OFST _UINT32_(0xF8)      /* (CSI_INT_FORCE_PKT_FATAL) Static read and write register   Interrupt force register is used for test purposes, and allows triggering INT_ST_PKT_FATAL interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, since it may be extremely complex to generate stimuli for that purpose. Offset */
#define CSI_INT_ST_FRAME_FATAL_REG_OFST _UINT32_(0x100)     /* (CSI_INT_ST_FRAME_FATAL) Clear on read register    Fatal interruption related with Frame construction. Packet discarded.   Groups and notifies which interruption bits caused the interruption.   Stores the source of the error.   Reading INT_ST_FRAME_FATAL register does not clear the interrupt pin. Offset */
#define CSI_INT_MSK_FRAME_FATAL_REG_OFST _UINT32_(0x104)     /* (CSI_INT_MSK_FRAME_FATAL) Static read and write register    Interrupt mask for INT_ST_FRAME_FATAL controls which interrupt status bits will trigger the interrupt pin. Bit at 1 - Enable the interrupt source. Bit at 0 - Interrupt source is masked. Offset */
#define CSI_INT_FORCE_FRAME_FATAL_REG_OFST _UINT32_(0x108)     /* (CSI_INT_FORCE_FRAME_FATAL) Static read and write register    Interrupt force register is used for test purposes, and allows triggering INT_ST_FRAME_FATAL interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, because it may be extremely complex to generate stimuli for that purpose. Offset */
#define CSI_INT_ST_PHY_REG_OFST        _UINT32_(0x110)     /* (CSI_INT_ST_PHY) Clear on read register    Interruption caused by PHY.   Groups and notifies which interruption bits caused the interruption.   Stores the source of the error.   Reading INT_ST_PHY register does not clear the interrupt pin. Offset */
#define CSI_INT_MSK_PHY_REG_OFST       _UINT32_(0x114)     /* (CSI_INT_MSK_PHY) Static read and write register    Interrupt mask for INT_ST_PHY controls which interrupt status bits will trigger the interrupt pin. Bit at 1 - Enable the interrupt source. Bit at 0 - Interrupt source is masked. Offset */
#define CSI_INT_FORCE_PHY_REG_OFST     _UINT32_(0x118)     /* (CSI_INT_FORCE_PHY) Static read and write register    Interrupt force register is used for test purposes, and allows triggering INT_ST_PHY interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, because it may be extremely complex to generate stimuli for that purpose. Offset */
#define CSI_INT_ST_PKT_REG_OFST        _UINT32_(0x120)     /* (CSI_INT_ST_PKT) Clear on read register    Interruption related with Packet construction. Packet discarded.   Groups and notifies which interruption bits caused the interruption.   Stores the source of the error.   Reading INT_ST_PKT register does not clear the interrupt pin. Offset */
#define CSI_INT_MSK_PKT_REG_OFST       _UINT32_(0x124)     /* (CSI_INT_MSK_PKT) Static read and write register    Interrupt mask for INT_ST_PKT controls which interrupt status bits will trigger the interrupt pin. Bit at 1 - Enable the interrupt source. Bit at 0 - Interrupt source is masked. Offset */
#define CSI_INT_FORCE_PKT_REG_OFST     _UINT32_(0x128)     /* (CSI_INT_FORCE_PKT) Static read and write register    Interrupt force register is used for test purposes, and allows triggering INT_ST_PKT interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, because it may be extremely complex to generate stimuli for that purpose. Offset */
#define CSI_INT_ST_LINE_REG_OFST       _UINT32_(0x130)     /* (CSI_INT_ST_LINE) Clear on read register    Interruption related with Line construction.    Groups and notifies which interruption bits caused the interruption.  Stores the source of the error.   Reading INT_ST_LINE register does not clear the interrupt pin. Offset */
#define CSI_INT_MSK_LINE_REG_OFST      _UINT32_(0x134)     /* (CSI_INT_MSK_LINE) Static read and write register    Interrupt mask for INT_ST_LINE controls which interrupt status bits will trigger the interrupt pin. Bit at 1 - Enable the interrupt source. Bit at 0 - Interrupt source is masked. Offset */
#define CSI_INT_FORCE_LINE_REG_OFST    _UINT32_(0x138)     /* (CSI_INT_FORCE_LINE) Static read and write register    Interrupt force register is used for test purposes, and allows triggering INT_ST_LINE interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, because it may be extremely complex to generate stimuli for that purpose. Offset */
#define CSI_INT_ST_IPI_REG_OFST        _UINT32_(0x140)     /* (CSI_INT_ST_IPI) Clear on read register Fatal Interruption caused by IPI interface. Groups and notifies which interruption bits caused the interruption. Stores the source of the error. Reading INT_ST_IPI register does not clear the interrupt pin Offset */
#define CSI_INT_MSK_IPI_REG_OFST       _UINT32_(0x144)     /* (CSI_INT_MSK_IPI) Static read and write register Each bit of this register masks the interruption from INT_ST_IPI from generating an interruption event. Once a bit of the mask is active, the respective error of the INT_ST_ IPI register is masked preventing the error signal from signaling an interruption through the interrupt pin Offset */
#define CSI_INT_FORCE_IPI_REG_OFST     _UINT32_(0x148)     /* (CSI_INT_FORCE_IPI) Static read and write register Interrupt force register is used for test purposes, and allows triggering INT_ST_IPI interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, because it may be extremely complex to generate stimuli for that purpose Offset */
#define CSI_SCRAMBLING_REG_OFST        _UINT32_(0x300)     /* (CSI_SCRAMBLING) This register configures the De-scrambler block. Offset */
#define CSI_SCRAMBLING_SEED1_REG_OFST  _UINT32_(0x304)     /* (CSI_SCRAMBLING_SEED1) This register configures the seed used by De-scrambler block for lane 1 Offset */
#define CSI_SCRAMBLING_SEED2_REG_OFST  _UINT32_(0x308)     /* (CSI_SCRAMBLING_SEED2) This register configures the seed used by De-scrambler block for lane 2 Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief CSI register API structure */
typedef struct
{  /* Camera Serial Interface */
  __I   uint32_t                       CSI_VERSION;        /**< Offset: 0x00 (R/   32) Read-only register   Contains the version of DWC_mipi_csi2_host coded in 32-bit ASCII code. */
  __IO  uint32_t                       CSI_N_LANES;        /**< Offset: 0x04 (R/W  32) Static read and write register   Configures the number of active lanes that the DWC_mipi_csi2_host uses to receive the camera device data. */
  __IO  uint32_t                       CSI_CSI2_RESETN;    /**< Offset: 0x08 (R/W  32) Static read and write register   Controls the DWC_mipi_csi2_host logic reset state. When activated, the internal logic of the controller goes into the reset state. The configuration is not reset to default values with this register, instead, only the internal controller logic is affected. */
  __I   uint32_t                       CSI_INT_ST_MAIN;    /**< Offset: 0x0C (R/   32) Clear on read register   Contains the status of individual interrupt sources, regardless of the contents of the associated interrupt mask registers, so it is possible to service the interrupt status registers by polling. Reading INT_ST_MAIN register clears the interrupt pin. */
  __IO  uint32_t                       CSI_DATA_IDS_1;     /**< Offset: 0x10 (R/W  32) Static read and write register   Programs the data Ids for matching line error reporting.   Enables up to eight different data Ids that can be identified simultaneously. */
  __IO  uint32_t                       CSI_DATA_IDS_2;     /**< Offset: 0x14 (R/W  32) Static read and write register   Programs the data Ids for matching line error reporting.   Configures Data ID definition for four additional pairs of data types and virtual channel identifiers. */
  __I   uint8_t                        Reserved1[0x28];
  __IO  uint32_t                       CSI_PHY_SHUTDOWNZ;  /**< Offset: 0x40 (R/W  32) Active low   Controls the PHY Shutdown mode. In this state, the PHY sets the analog and digital circuitry in the Reset state. */
  __IO  uint32_t                       CSI_DPHY_RSTZ;      /**< Offset: 0x44 (R/W  32) Active low   Controls the PHY Reset mode. in this state, the PHY sets the digital circuitry in the Reset State. */
  __I   uint32_t                       CSI_PHY_RX;         /**< Offset: 0x48 (R/   32) Read-only register Contains the status of RX-related signals from PHY:  RXULPSESC* RXCLKACTIVEHS (D-PHY)  It contains information such as, if the clock lane is receiving high-speed clock signal, or if the data and clock lanes are in Ultra Low Power Mode (ULPM). */
  __I   uint32_t                       CSI_PHY_STOPSTATE;  /**< Offset: 0x4C (R/   32) Read-only register   Contains the STOPSTATE signal status from PHY. */
  __IO  uint32_t                       CSI_PHY_TEST_CTRL0; /**< Offset: 0x50 (R/W  32) Dynamic register   Control for vendor specific interface in the PHY.   Controls the Synopsys D-PHY Test and Control interface. This register controls the TESTCLR and TESTCLK signals. */
  __IO  uint32_t                       CSI_PHY_TEST_CTRL1; /**< Offset: 0x54 (R/W  32) Dynamic register   Control for vendor specific interface in the PHY.   Controls the Synopsys D-PHY Test and Control interface. This register controls the TESTENABLE signal and the TESTDIN bus. Reading from this register retrieves the value from TESTDOUT. */
  __I   uint8_t                        Reserved2[0x28];
  __IO  uint32_t                       CSI_IPI_MODE;       /**< Offset: 0x80 (R/W  32) This register selects how the IPI interface generates the video frame */
  __IO  uint32_t                       CSI_IPI_VCID;       /**< Offset: 0x84 (R/W  32) This register selects the virtual channel processed by IPI */
  __IO  uint32_t                       CSI_IPI_DATA_TYPE;  /**< Offset: 0x88 (R/W  32) This register selects the data type processed by IPI */
  __IO  uint32_t                       CSI_IPI_MEM_FLUSH;  /**< Offset: 0x8C (R/W  32) This register control the flush of IPI memory */
  __IO  uint32_t                       CSI_IPI_HSA_TIME;   /**< Offset: 0x90 (R/W  32) This register configures the video Horizontal Synchronism Active (HSA) time */
  __IO  uint32_t                       CSI_IPI_HBP_TIME;   /**< Offset: 0x94 (R/W  32) This register configures the video Horizontal Back Porch (HBP) time */
  __IO  uint32_t                       CSI_IPI_HSD_TIME;   /**< Offset: 0x98 (R/W  32) This register configures the video Horizontal Sync Delay (HSD) time */
  __IO  uint32_t                       CSI_IPI_HLINE_TIME; /**< Offset: 0x9C (R/W  32) This register configures the overall time for each video line */
  __I   uint8_t                        Reserved3[0x10];
  __IO  uint32_t                       CSI_IPI_VSA_LINES;  /**< Offset: 0xB0 (R/W  32) This register configures the Vertical Synchronism Active (VSA) period */
  __IO  uint32_t                       CSI_IPI_VBP_LINES;  /**< Offset: 0xB4 (R/W  32) This register configures the Vertical Back Porch (VBP) period */
  __IO  uint32_t                       CSI_IPI_VFP_LINES;  /**< Offset: 0xB8 (R/W  32) This register configures the Vertical Front Porch (VFP) period */
  __IO  uint32_t                       CSI_IPI_VACTIVE_LINES; /**< Offset: 0xBC (R/W  32) This register configures the vertical resolution of the video */
  __I   uint8_t                        Reserved4[0x0C];
  __I   uint32_t                       CSI_PHY_CAL;        /**< Offset: 0xCC (R/   32) Clear on read register    Contains the CALIBRATION signal status from Synopsys D-PHY. */
  __I   uint8_t                        Reserved5[0x10];
  __I   uint32_t                       CSI_INT_ST_PHY_FATAL; /**< Offset: 0xE0 (R/   32) Clear on read register   Groups the fatal interruptions caused by PHY Packet discarded.   Stores the source of the error.   Reading INT_ST_PHY_FATAL register does not clear the interrupt pin. */
  __IO  uint32_t                       CSI_INT_MSK_PHY_FATAL; /**< Offset: 0xE4 (R/W  32) Static read and write register    Interrupt mask for INT_ST_PHY_FATAL controls which interrupt status bits will trigger the interrupt pin. Bit at 1 - Enable the interrupt source. Bit at 0 - Interrupt source is masked. */
  __IO  uint32_t                       CSI_INT_FORCE_PHY_FATAL; /**< Offset: 0xE8 (R/W  32) Static read and write register    Interrupt Force register is used for test purposes, and allows triggering INT_ST_PHY_FATAL interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, since it may be extremely complex to generate stimuli for that purpose. */
  __I   uint8_t                        Reserved6[0x04];
  __I   uint32_t                       CSI_INT_ST_PKT_FATAL; /**< Offset: 0xF0 (R/   32) Clear on read register    Groups the fatal interruption related with Packet construction. Packet discarded.   Notifies which interruption bit has caused the interruption.   Stores the source of the error.   Reading INT_ST_PKT_FATAL register does not clear the interrupt pin. */
  __IO  uint32_t                       CSI_INT_MSK_PKT_FATAL; /**< Offset: 0xF4 (R/W  32) Static read and write register    Interrupt mask for INT_ST_PKT_FATAL controls which interrupt status bits will trigger the interrupt pin. Bit at 1 - Enable the interrupt source. Bit at 0 - Interrupt source is masked. */
  __IO  uint32_t                       CSI_INT_FORCE_PKT_FATAL; /**< Offset: 0xF8 (R/W  32) Static read and write register   Interrupt force register is used for test purposes, and allows triggering INT_ST_PKT_FATAL interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, since it may be extremely complex to generate stimuli for that purpose. */
  __I   uint8_t                        Reserved7[0x04];
  __I   uint32_t                       CSI_INT_ST_FRAME_FATAL; /**< Offset: 0x100 (R/   32) Clear on read register    Fatal interruption related with Frame construction. Packet discarded.   Groups and notifies which interruption bits caused the interruption.   Stores the source of the error.   Reading INT_ST_FRAME_FATAL register does not clear the interrupt pin. */
  __IO  uint32_t                       CSI_INT_MSK_FRAME_FATAL; /**< Offset: 0x104 (R/W  32) Static read and write register    Interrupt mask for INT_ST_FRAME_FATAL controls which interrupt status bits will trigger the interrupt pin. Bit at 1 - Enable the interrupt source. Bit at 0 - Interrupt source is masked. */
  __IO  uint32_t                       CSI_INT_FORCE_FRAME_FATAL; /**< Offset: 0x108 (R/W  32) Static read and write register    Interrupt force register is used for test purposes, and allows triggering INT_ST_FRAME_FATAL interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, because it may be extremely complex to generate stimuli for that purpose. */
  __I   uint8_t                        Reserved8[0x04];
  __I   uint32_t                       CSI_INT_ST_PHY;     /**< Offset: 0x110 (R/   32) Clear on read register    Interruption caused by PHY.   Groups and notifies which interruption bits caused the interruption.   Stores the source of the error.   Reading INT_ST_PHY register does not clear the interrupt pin. */
  __IO  uint32_t                       CSI_INT_MSK_PHY;    /**< Offset: 0x114 (R/W  32) Static read and write register    Interrupt mask for INT_ST_PHY controls which interrupt status bits will trigger the interrupt pin. Bit at 1 - Enable the interrupt source. Bit at 0 - Interrupt source is masked. */
  __IO  uint32_t                       CSI_INT_FORCE_PHY;  /**< Offset: 0x118 (R/W  32) Static read and write register    Interrupt force register is used for test purposes, and allows triggering INT_ST_PHY interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, because it may be extremely complex to generate stimuli for that purpose. */
  __I   uint8_t                        Reserved9[0x04];
  __I   uint32_t                       CSI_INT_ST_PKT;     /**< Offset: 0x120 (R/   32) Clear on read register    Interruption related with Packet construction. Packet discarded.   Groups and notifies which interruption bits caused the interruption.   Stores the source of the error.   Reading INT_ST_PKT register does not clear the interrupt pin. */
  __IO  uint32_t                       CSI_INT_MSK_PKT;    /**< Offset: 0x124 (R/W  32) Static read and write register    Interrupt mask for INT_ST_PKT controls which interrupt status bits will trigger the interrupt pin. Bit at 1 - Enable the interrupt source. Bit at 0 - Interrupt source is masked. */
  __IO  uint32_t                       CSI_INT_FORCE_PKT;  /**< Offset: 0x128 (R/W  32) Static read and write register    Interrupt force register is used for test purposes, and allows triggering INT_ST_PKT interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, because it may be extremely complex to generate stimuli for that purpose. */
  __I   uint8_t                        Reserved10[0x04];
  __I   uint32_t                       CSI_INT_ST_LINE;    /**< Offset: 0x130 (R/   32) Clear on read register    Interruption related with Line construction.    Groups and notifies which interruption bits caused the interruption.  Stores the source of the error.   Reading INT_ST_LINE register does not clear the interrupt pin. */
  __IO  uint32_t                       CSI_INT_MSK_LINE;   /**< Offset: 0x134 (R/W  32) Static read and write register    Interrupt mask for INT_ST_LINE controls which interrupt status bits will trigger the interrupt pin. Bit at 1 - Enable the interrupt source. Bit at 0 - Interrupt source is masked. */
  __IO  uint32_t                       CSI_INT_FORCE_LINE; /**< Offset: 0x138 (R/W  32) Static read and write register    Interrupt force register is used for test purposes, and allows triggering INT_ST_LINE interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, because it may be extremely complex to generate stimuli for that purpose. */
  __I   uint8_t                        Reserved11[0x04];
  __I   uint32_t                       CSI_INT_ST_IPI;     /**< Offset: 0x140 (R/   32) Clear on read register Fatal Interruption caused by IPI interface. Groups and notifies which interruption bits caused the interruption. Stores the source of the error. Reading INT_ST_IPI register does not clear the interrupt pin */
  __IO  uint32_t                       CSI_INT_MSK_IPI;    /**< Offset: 0x144 (R/W  32) Static read and write register Each bit of this register masks the interruption from INT_ST_IPI from generating an interruption event. Once a bit of the mask is active, the respective error of the INT_ST_ IPI register is masked preventing the error signal from signaling an interruption through the interrupt pin */
  __IO  uint32_t                       CSI_INT_FORCE_IPI;  /**< Offset: 0x148 (R/W  32) Static read and write register Interrupt force register is used for test purposes, and allows triggering INT_ST_IPI interrupt events individually, without the need to activate the conditions that trigger the interrupt sources, because it may be extremely complex to generate stimuli for that purpose */
  __I   uint8_t                        Reserved12[0x1B4];
  __IO  uint32_t                       CSI_SCRAMBLING;     /**< Offset: 0x300 (R/W  32) This register configures the De-scrambler block. */
  __IO  uint32_t                       CSI_SCRAMBLING_SEED1; /**< Offset: 0x304 (R/W  32) This register configures the seed used by De-scrambler block for lane 1 */
  __IO  uint32_t                       CSI_SCRAMBLING_SEED2; /**< Offset: 0x308 (R/W  32) This register configures the seed used by De-scrambler block for lane 2 */
} csi_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMA7G_CSI_COMPONENT_H_ */
