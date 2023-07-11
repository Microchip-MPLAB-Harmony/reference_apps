/*
 * Component description for DSI
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
#ifndef _SAM9X7_DSI_COMPONENT_H_
#define _SAM9X7_DSI_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR DSI                                          */
/* ************************************************************************** */

/* -------- DSI_PWR_UP : (DSI Offset: 0x04) (R/W 32) Power-Up Control Register -------- */
#define DSI_PWR_UP_RESETVALUE                 _UINT32_(0x00)                                       /*  (DSI_PWR_UP) Power-Up Control Register  Reset Value */

#define DSI_PWR_UP_SHUTDOWNZ_Pos              _UINT32_(0)                                          /* (DSI_PWR_UP) Shutdown Position */
#define DSI_PWR_UP_SHUTDOWNZ_Msk              (_UINT32_(0x1) << DSI_PWR_UP_SHUTDOWNZ_Pos)          /* (DSI_PWR_UP) Shutdown Mask */
#define DSI_PWR_UP_SHUTDOWNZ(value)           (DSI_PWR_UP_SHUTDOWNZ_Msk & (_UINT32_(value) << DSI_PWR_UP_SHUTDOWNZ_Pos)) /* Assigment of value for SHUTDOWNZ in the DSI_PWR_UP register */
#define   DSI_PWR_UP_SHUTDOWNZ_0_Val          _UINT32_(0x0)                                        /* (DSI_PWR_UP) DSI host is reset.  */
#define   DSI_PWR_UP_SHUTDOWNZ_1_Val          _UINT32_(0x1)                                        /* (DSI_PWR_UP) DSI host is powered up.  */
#define DSI_PWR_UP_SHUTDOWNZ_0                (DSI_PWR_UP_SHUTDOWNZ_0_Val << DSI_PWR_UP_SHUTDOWNZ_Pos) /* (DSI_PWR_UP) DSI host is reset. Position  */
#define DSI_PWR_UP_SHUTDOWNZ_1                (DSI_PWR_UP_SHUTDOWNZ_1_Val << DSI_PWR_UP_SHUTDOWNZ_Pos) /* (DSI_PWR_UP) DSI host is powered up. Position  */
#define DSI_PWR_UP_Msk                        _UINT32_(0x00000001)                                 /* (DSI_PWR_UP) Register Mask  */


/* -------- DSI_CLKMGR_CFG : (DSI Offset: 0x08) (R/W 32) Clock Management Configuration Register -------- */
#define DSI_CLKMGR_CFG_RESETVALUE             _UINT32_(0x00)                                       /*  (DSI_CLKMGR_CFG) Clock Management Configuration Register  Reset Value */

#define DSI_CLKMGR_CFG_TX_ESC_CLK_DIVISION_Pos _UINT32_(0)                                          /* (DSI_CLKMGR_CFG) Transmission Escape Clock Division Position */
#define DSI_CLKMGR_CFG_TX_ESC_CLK_DIVISION_Msk (_UINT32_(0xFF) << DSI_CLKMGR_CFG_TX_ESC_CLK_DIVISION_Pos) /* (DSI_CLKMGR_CFG) Transmission Escape Clock Division Mask */
#define DSI_CLKMGR_CFG_TX_ESC_CLK_DIVISION(value) (DSI_CLKMGR_CFG_TX_ESC_CLK_DIVISION_Msk & (_UINT32_(value) << DSI_CLKMGR_CFG_TX_ESC_CLK_DIVISION_Pos)) /* Assigment of value for TX_ESC_CLK_DIVISION in the DSI_CLKMGR_CFG register */
#define DSI_CLKMGR_CFG_TO_CLK_DIVISION_Pos    _UINT32_(8)                                          /* (DSI_CLKMGR_CFG) Timeout Clock Division Position */
#define DSI_CLKMGR_CFG_TO_CLK_DIVISION_Msk    (_UINT32_(0xFF) << DSI_CLKMGR_CFG_TO_CLK_DIVISION_Pos) /* (DSI_CLKMGR_CFG) Timeout Clock Division Mask */
#define DSI_CLKMGR_CFG_TO_CLK_DIVISION(value) (DSI_CLKMGR_CFG_TO_CLK_DIVISION_Msk & (_UINT32_(value) << DSI_CLKMGR_CFG_TO_CLK_DIVISION_Pos)) /* Assigment of value for TO_CLK_DIVISION in the DSI_CLKMGR_CFG register */
#define DSI_CLKMGR_CFG_Msk                    _UINT32_(0x0000FFFF)                                 /* (DSI_CLKMGR_CFG) Register Mask  */


/* -------- DSI_DPI_VCID : (DSI Offset: 0x0C) (R/W 32) Input Video Virtual Channel ID Configuration Register -------- */
#define DSI_DPI_VCID_RESETVALUE               _UINT32_(0x00)                                       /*  (DSI_DPI_VCID) Input Video Virtual Channel ID Configuration Register  Reset Value */

#define DSI_DPI_VCID_DPI_VCID_Pos             _UINT32_(0)                                          /* (DSI_DPI_VCID) Input Video Virtual Channel Identifier Position */
#define DSI_DPI_VCID_DPI_VCID_Msk             (_UINT32_(0x3) << DSI_DPI_VCID_DPI_VCID_Pos)         /* (DSI_DPI_VCID) Input Video Virtual Channel Identifier Mask */
#define DSI_DPI_VCID_DPI_VCID(value)          (DSI_DPI_VCID_DPI_VCID_Msk & (_UINT32_(value) << DSI_DPI_VCID_DPI_VCID_Pos)) /* Assigment of value for DPI_VCID in the DSI_DPI_VCID register */
#define DSI_DPI_VCID_Msk                      _UINT32_(0x00000003)                                 /* (DSI_DPI_VCID) Register Mask  */


/* -------- DSI_DPI_COLOR_CODING : (DSI Offset: 0x10) (R/W 32) Input Video Color Coding Configuration Register -------- */
#define DSI_DPI_COLOR_CODING_RESETVALUE       _UINT32_(0x00)                                       /*  (DSI_DPI_COLOR_CODING) Input Video Color Coding Configuration Register  Reset Value */

#define DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_Pos _UINT32_(0)                                          /* (DSI_DPI_COLOR_CODING) Input Video Color Coding Position */
#define DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_Msk (_UINT32_(0xF) << DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_Pos) /* (DSI_DPI_COLOR_CODING) Input Video Color Coding Mask */
#define DSI_DPI_COLOR_CODING_DPI_COLOR_CODING(value) (DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_Msk & (_UINT32_(value) << DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_Pos)) /* Assigment of value for DPI_COLOR_CODING in the DSI_DPI_COLOR_CODING register */
#define   DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_16BIT_CFG1_Val _UINT32_(0x0)                                        /* (DSI_DPI_COLOR_CODING) 16-bit configuration 1  */
#define   DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_16BIT_CFG2_Val _UINT32_(0x1)                                        /* (DSI_DPI_COLOR_CODING) 16-bit configuration 2  */
#define   DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_16BIT_CFG3_Val _UINT32_(0x2)                                        /* (DSI_DPI_COLOR_CODING) 16-bit configuration 3  */
#define   DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_18BIT_CFG1_Val _UINT32_(0x3)                                        /* (DSI_DPI_COLOR_CODING) 18-bit configuration 1  */
#define   DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_18BIT_CFG2_Val _UINT32_(0x4)                                        /* (DSI_DPI_COLOR_CODING) 18-bit configuration 2  */
#define   DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_24BIT_Val _UINT32_(0x5)                                        /* (DSI_DPI_COLOR_CODING) 24-bit  */
#define DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_16BIT_CFG1 (DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_16BIT_CFG1_Val << DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_Pos) /* (DSI_DPI_COLOR_CODING) 16-bit configuration 1 Position  */
#define DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_16BIT_CFG2 (DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_16BIT_CFG2_Val << DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_Pos) /* (DSI_DPI_COLOR_CODING) 16-bit configuration 2 Position  */
#define DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_16BIT_CFG3 (DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_16BIT_CFG3_Val << DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_Pos) /* (DSI_DPI_COLOR_CODING) 16-bit configuration 3 Position  */
#define DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_18BIT_CFG1 (DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_18BIT_CFG1_Val << DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_Pos) /* (DSI_DPI_COLOR_CODING) 18-bit configuration 1 Position  */
#define DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_18BIT_CFG2 (DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_18BIT_CFG2_Val << DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_Pos) /* (DSI_DPI_COLOR_CODING) 18-bit configuration 2 Position  */
#define DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_24BIT (DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_24BIT_Val << DSI_DPI_COLOR_CODING_DPI_COLOR_CODING_Pos) /* (DSI_DPI_COLOR_CODING) 24-bit Position  */
#define DSI_DPI_COLOR_CODING_Msk              _UINT32_(0x0000000F)                                 /* (DSI_DPI_COLOR_CODING) Register Mask  */


/* -------- DSI_DPI_CFG_POL : (DSI Offset: 0x14) (R/W 32) Input Video Polarity Configuration Register -------- */
#define DSI_DPI_CFG_POL_RESETVALUE            _UINT32_(0x00)                                       /*  (DSI_DPI_CFG_POL) Input Video Polarity Configuration Register  Reset Value */

#define DSI_DPI_CFG_POL_DATAEN_ACTIVE_LOW_Pos _UINT32_(0)                                          /* (DSI_DPI_CFG_POL) Data Enable Signal Active Low Position */
#define DSI_DPI_CFG_POL_DATAEN_ACTIVE_LOW_Msk (_UINT32_(0x1) << DSI_DPI_CFG_POL_DATAEN_ACTIVE_LOW_Pos) /* (DSI_DPI_CFG_POL) Data Enable Signal Active Low Mask */
#define DSI_DPI_CFG_POL_DATAEN_ACTIVE_LOW(value) (DSI_DPI_CFG_POL_DATAEN_ACTIVE_LOW_Msk & (_UINT32_(value) << DSI_DPI_CFG_POL_DATAEN_ACTIVE_LOW_Pos)) /* Assigment of value for DATAEN_ACTIVE_LOW in the DSI_DPI_CFG_POL register */
#define   DSI_DPI_CFG_POL_DATAEN_ACTIVE_LOW_0_Val _UINT32_(0x0)                                        /* (DSI_DPI_CFG_POL) Input video interface  DATAEN is active high.  */
#define   DSI_DPI_CFG_POL_DATAEN_ACTIVE_LOW_1_Val _UINT32_(0x1)                                        /* (DSI_DPI_CFG_POL) Input video interface  DATAEN is active low.  */
#define DSI_DPI_CFG_POL_DATAEN_ACTIVE_LOW_0   (DSI_DPI_CFG_POL_DATAEN_ACTIVE_LOW_0_Val << DSI_DPI_CFG_POL_DATAEN_ACTIVE_LOW_Pos) /* (DSI_DPI_CFG_POL) Input video interface  DATAEN is active high. Position  */
#define DSI_DPI_CFG_POL_DATAEN_ACTIVE_LOW_1   (DSI_DPI_CFG_POL_DATAEN_ACTIVE_LOW_1_Val << DSI_DPI_CFG_POL_DATAEN_ACTIVE_LOW_Pos) /* (DSI_DPI_CFG_POL) Input video interface  DATAEN is active low. Position  */
#define DSI_DPI_CFG_POL_VSYNC_ACTIVE_LOW_Pos  _UINT32_(1)                                          /* (DSI_DPI_CFG_POL) Vertical Synchronisation Signal Active Low Position */
#define DSI_DPI_CFG_POL_VSYNC_ACTIVE_LOW_Msk  (_UINT32_(0x1) << DSI_DPI_CFG_POL_VSYNC_ACTIVE_LOW_Pos) /* (DSI_DPI_CFG_POL) Vertical Synchronisation Signal Active Low Mask */
#define DSI_DPI_CFG_POL_VSYNC_ACTIVE_LOW(value) (DSI_DPI_CFG_POL_VSYNC_ACTIVE_LOW_Msk & (_UINT32_(value) << DSI_DPI_CFG_POL_VSYNC_ACTIVE_LOW_Pos)) /* Assigment of value for VSYNC_ACTIVE_LOW in the DSI_DPI_CFG_POL register */
#define   DSI_DPI_CFG_POL_VSYNC_ACTIVE_LOW_0_Val _UINT32_(0x0)                                        /* (DSI_DPI_CFG_POL) Input video interface  VSYNC is active high.  */
#define   DSI_DPI_CFG_POL_VSYNC_ACTIVE_LOW_1_Val _UINT32_(0x1)                                        /* (DSI_DPI_CFG_POL) Input video interface  VSYNC is active low.  */
#define DSI_DPI_CFG_POL_VSYNC_ACTIVE_LOW_0    (DSI_DPI_CFG_POL_VSYNC_ACTIVE_LOW_0_Val << DSI_DPI_CFG_POL_VSYNC_ACTIVE_LOW_Pos) /* (DSI_DPI_CFG_POL) Input video interface  VSYNC is active high. Position  */
#define DSI_DPI_CFG_POL_VSYNC_ACTIVE_LOW_1    (DSI_DPI_CFG_POL_VSYNC_ACTIVE_LOW_1_Val << DSI_DPI_CFG_POL_VSYNC_ACTIVE_LOW_Pos) /* (DSI_DPI_CFG_POL) Input video interface  VSYNC is active low. Position  */
#define DSI_DPI_CFG_POL_HSYNC_ACTIVE_LOW_Pos  _UINT32_(2)                                          /* (DSI_DPI_CFG_POL) Horizontal Synchronisation Signal Active Low Position */
#define DSI_DPI_CFG_POL_HSYNC_ACTIVE_LOW_Msk  (_UINT32_(0x1) << DSI_DPI_CFG_POL_HSYNC_ACTIVE_LOW_Pos) /* (DSI_DPI_CFG_POL) Horizontal Synchronisation Signal Active Low Mask */
#define DSI_DPI_CFG_POL_HSYNC_ACTIVE_LOW(value) (DSI_DPI_CFG_POL_HSYNC_ACTIVE_LOW_Msk & (_UINT32_(value) << DSI_DPI_CFG_POL_HSYNC_ACTIVE_LOW_Pos)) /* Assigment of value for HSYNC_ACTIVE_LOW in the DSI_DPI_CFG_POL register */
#define   DSI_DPI_CFG_POL_HSYNC_ACTIVE_LOW_0_Val _UINT32_(0x0)                                        /* (DSI_DPI_CFG_POL) Input video interface  VSYNC is active high.  */
#define   DSI_DPI_CFG_POL_HSYNC_ACTIVE_LOW_1_Val _UINT32_(0x1)                                        /* (DSI_DPI_CFG_POL) Input video interface  VSYNC is active low.  */
#define DSI_DPI_CFG_POL_HSYNC_ACTIVE_LOW_0    (DSI_DPI_CFG_POL_HSYNC_ACTIVE_LOW_0_Val << DSI_DPI_CFG_POL_HSYNC_ACTIVE_LOW_Pos) /* (DSI_DPI_CFG_POL) Input video interface  VSYNC is active high. Position  */
#define DSI_DPI_CFG_POL_HSYNC_ACTIVE_LOW_1    (DSI_DPI_CFG_POL_HSYNC_ACTIVE_LOW_1_Val << DSI_DPI_CFG_POL_HSYNC_ACTIVE_LOW_Pos) /* (DSI_DPI_CFG_POL) Input video interface  VSYNC is active low. Position  */
#define DSI_DPI_CFG_POL_SHUTD_ACTIVE_LOW_Pos  _UINT32_(3)                                          /* (DSI_DPI_CFG_POL) Shutdown Signal Active Low Position */
#define DSI_DPI_CFG_POL_SHUTD_ACTIVE_LOW_Msk  (_UINT32_(0x1) << DSI_DPI_CFG_POL_SHUTD_ACTIVE_LOW_Pos) /* (DSI_DPI_CFG_POL) Shutdown Signal Active Low Mask */
#define DSI_DPI_CFG_POL_SHUTD_ACTIVE_LOW(value) (DSI_DPI_CFG_POL_SHUTD_ACTIVE_LOW_Msk & (_UINT32_(value) << DSI_DPI_CFG_POL_SHUTD_ACTIVE_LOW_Pos)) /* Assigment of value for SHUTD_ACTIVE_LOW in the DSI_DPI_CFG_POL register */
#define   DSI_DPI_CFG_POL_SHUTD_ACTIVE_LOW_0_Val _UINT32_(0x0)                                        /* (DSI_DPI_CFG_POL) Input interface Shutdown signal is active high.  */
#define   DSI_DPI_CFG_POL_SHUTD_ACTIVE_LOW_1_Val _UINT32_(0x1)                                        /* (DSI_DPI_CFG_POL) Input interface Shutdown signal is active low.  */
#define DSI_DPI_CFG_POL_SHUTD_ACTIVE_LOW_0    (DSI_DPI_CFG_POL_SHUTD_ACTIVE_LOW_0_Val << DSI_DPI_CFG_POL_SHUTD_ACTIVE_LOW_Pos) /* (DSI_DPI_CFG_POL) Input interface Shutdown signal is active high. Position  */
#define DSI_DPI_CFG_POL_SHUTD_ACTIVE_LOW_1    (DSI_DPI_CFG_POL_SHUTD_ACTIVE_LOW_1_Val << DSI_DPI_CFG_POL_SHUTD_ACTIVE_LOW_Pos) /* (DSI_DPI_CFG_POL) Input interface Shutdown signal is active low. Position  */
#define DSI_DPI_CFG_POL_COLORM_ACTIVE_LOW_Pos _UINT32_(4)                                          /* (DSI_DPI_CFG_POL) Color Mode Signal Active Low Position */
#define DSI_DPI_CFG_POL_COLORM_ACTIVE_LOW_Msk (_UINT32_(0x1) << DSI_DPI_CFG_POL_COLORM_ACTIVE_LOW_Pos) /* (DSI_DPI_CFG_POL) Color Mode Signal Active Low Mask */
#define DSI_DPI_CFG_POL_COLORM_ACTIVE_LOW(value) (DSI_DPI_CFG_POL_COLORM_ACTIVE_LOW_Msk & (_UINT32_(value) << DSI_DPI_CFG_POL_COLORM_ACTIVE_LOW_Pos)) /* Assigment of value for COLORM_ACTIVE_LOW in the DSI_DPI_CFG_POL register */
#define   DSI_DPI_CFG_POL_COLORM_ACTIVE_LOW_0_Val _UINT32_(0x0)                                        /* (DSI_DPI_CFG_POL) Input interface Color Mode signal is active high.  */
#define   DSI_DPI_CFG_POL_COLORM_ACTIVE_LOW_1_Val _UINT32_(0x1)                                        /* (DSI_DPI_CFG_POL) Input interface Color Mode signal is active low.  */
#define DSI_DPI_CFG_POL_COLORM_ACTIVE_LOW_0   (DSI_DPI_CFG_POL_COLORM_ACTIVE_LOW_0_Val << DSI_DPI_CFG_POL_COLORM_ACTIVE_LOW_Pos) /* (DSI_DPI_CFG_POL) Input interface Color Mode signal is active high. Position  */
#define DSI_DPI_CFG_POL_COLORM_ACTIVE_LOW_1   (DSI_DPI_CFG_POL_COLORM_ACTIVE_LOW_1_Val << DSI_DPI_CFG_POL_COLORM_ACTIVE_LOW_Pos) /* (DSI_DPI_CFG_POL) Input interface Color Mode signal is active low. Position  */
#define DSI_DPI_CFG_POL_Msk                   _UINT32_(0x0000001F)                                 /* (DSI_DPI_CFG_POL) Register Mask  */


/* -------- DSI_DPI_LP_CMD_TIM : (DSI Offset: 0x18) (R/W 32) Input Video Timing for Low-Power Commands Configuration Register -------- */
#define DSI_DPI_LP_CMD_TIM_RESETVALUE         _UINT32_(0x00)                                       /*  (DSI_DPI_LP_CMD_TIM) Input Video Timing for Low-Power Commands Configuration Register  Reset Value */

#define DSI_DPI_LP_CMD_TIM_INVACT_LPCMD_TIME_Pos _UINT32_(0)                                          /* (DSI_DPI_LP_CMD_TIM) Input Vertical Active Low-Power Command Time Position */
#define DSI_DPI_LP_CMD_TIM_INVACT_LPCMD_TIME_Msk (_UINT32_(0xFF) << DSI_DPI_LP_CMD_TIM_INVACT_LPCMD_TIME_Pos) /* (DSI_DPI_LP_CMD_TIM) Input Vertical Active Low-Power Command Time Mask */
#define DSI_DPI_LP_CMD_TIM_INVACT_LPCMD_TIME(value) (DSI_DPI_LP_CMD_TIM_INVACT_LPCMD_TIME_Msk & (_UINT32_(value) << DSI_DPI_LP_CMD_TIM_INVACT_LPCMD_TIME_Pos)) /* Assigment of value for INVACT_LPCMD_TIME in the DSI_DPI_LP_CMD_TIM register */
#define DSI_DPI_LP_CMD_TIM_OUTVACT_LPCMD_TIME_Pos _UINT32_(16)                                         /* (DSI_DPI_LP_CMD_TIM) Output Vertical Active Low-Power Command Position */
#define DSI_DPI_LP_CMD_TIM_OUTVACT_LPCMD_TIME_Msk (_UINT32_(0xFF) << DSI_DPI_LP_CMD_TIM_OUTVACT_LPCMD_TIME_Pos) /* (DSI_DPI_LP_CMD_TIM) Output Vertical Active Low-Power Command Mask */
#define DSI_DPI_LP_CMD_TIM_OUTVACT_LPCMD_TIME(value) (DSI_DPI_LP_CMD_TIM_OUTVACT_LPCMD_TIME_Msk & (_UINT32_(value) << DSI_DPI_LP_CMD_TIM_OUTVACT_LPCMD_TIME_Pos)) /* Assigment of value for OUTVACT_LPCMD_TIME in the DSI_DPI_LP_CMD_TIM register */
#define DSI_DPI_LP_CMD_TIM_Msk                _UINT32_(0x00FF00FF)                                 /* (DSI_DPI_LP_CMD_TIM) Register Mask  */


/* -------- DSI_PCKHDL_CFG : (DSI Offset: 0x2C) (R/W 32) DSI Protocol Configuration Register -------- */
#define DSI_PCKHDL_CFG_RESETVALUE             _UINT32_(0x00)                                       /*  (DSI_PCKHDL_CFG) DSI Protocol Configuration Register  Reset Value */

#define DSI_PCKHDL_CFG_EOTP_TX_EN_Pos         _UINT32_(0)                                          /* (DSI_PCKHDL_CFG) End Of Transmission Packet Enable Position */
#define DSI_PCKHDL_CFG_EOTP_TX_EN_Msk         (_UINT32_(0x1) << DSI_PCKHDL_CFG_EOTP_TX_EN_Pos)     /* (DSI_PCKHDL_CFG) End Of Transmission Packet Enable Mask */
#define DSI_PCKHDL_CFG_EOTP_TX_EN(value)      (DSI_PCKHDL_CFG_EOTP_TX_EN_Msk & (_UINT32_(value) << DSI_PCKHDL_CFG_EOTP_TX_EN_Pos)) /* Assigment of value for EOTP_TX_EN in the DSI_PCKHDL_CFG register */
#define   DSI_PCKHDL_CFG_EOTP_TX_EN_0_Val     _UINT32_(0x0)                                        /* (DSI_PCKHDL_CFG) Disables the EoTp transmission.  */
#define   DSI_PCKHDL_CFG_EOTP_TX_EN_1_Val     _UINT32_(0x1)                                        /* (DSI_PCKHDL_CFG) Enables the EoTp transmission.  */
#define DSI_PCKHDL_CFG_EOTP_TX_EN_0           (DSI_PCKHDL_CFG_EOTP_TX_EN_0_Val << DSI_PCKHDL_CFG_EOTP_TX_EN_Pos) /* (DSI_PCKHDL_CFG) Disables the EoTp transmission. Position  */
#define DSI_PCKHDL_CFG_EOTP_TX_EN_1           (DSI_PCKHDL_CFG_EOTP_TX_EN_1_Val << DSI_PCKHDL_CFG_EOTP_TX_EN_Pos) /* (DSI_PCKHDL_CFG) Enables the EoTp transmission. Position  */
#define DSI_PCKHDL_CFG_EOTP_RX_EN_Pos         _UINT32_(1)                                          /* (DSI_PCKHDL_CFG) End Of Reception Packet Enable Position */
#define DSI_PCKHDL_CFG_EOTP_RX_EN_Msk         (_UINT32_(0x1) << DSI_PCKHDL_CFG_EOTP_RX_EN_Pos)     /* (DSI_PCKHDL_CFG) End Of Reception Packet Enable Mask */
#define DSI_PCKHDL_CFG_EOTP_RX_EN(value)      (DSI_PCKHDL_CFG_EOTP_RX_EN_Msk & (_UINT32_(value) << DSI_PCKHDL_CFG_EOTP_RX_EN_Pos)) /* Assigment of value for EOTP_RX_EN in the DSI_PCKHDL_CFG register */
#define   DSI_PCKHDL_CFG_EOTP_RX_EN_0_Val     _UINT32_(0x0)                                        /* (DSI_PCKHDL_CFG) Disables the EoTp reception.  */
#define   DSI_PCKHDL_CFG_EOTP_RX_EN_1_Val     _UINT32_(0x1)                                        /* (DSI_PCKHDL_CFG) Enables the EoTp reception.  */
#define DSI_PCKHDL_CFG_EOTP_RX_EN_0           (DSI_PCKHDL_CFG_EOTP_RX_EN_0_Val << DSI_PCKHDL_CFG_EOTP_RX_EN_Pos) /* (DSI_PCKHDL_CFG) Disables the EoTp reception. Position  */
#define DSI_PCKHDL_CFG_EOTP_RX_EN_1           (DSI_PCKHDL_CFG_EOTP_RX_EN_1_Val << DSI_PCKHDL_CFG_EOTP_RX_EN_Pos) /* (DSI_PCKHDL_CFG) Enables the EoTp reception. Position  */
#define DSI_PCKHDL_CFG_BTA_EN_Pos             _UINT32_(2)                                          /* (DSI_PCKHDL_CFG) Bus Turn-Around Enable Position */
#define DSI_PCKHDL_CFG_BTA_EN_Msk             (_UINT32_(0x1) << DSI_PCKHDL_CFG_BTA_EN_Pos)         /* (DSI_PCKHDL_CFG) Bus Turn-Around Enable Mask */
#define DSI_PCKHDL_CFG_BTA_EN(value)          (DSI_PCKHDL_CFG_BTA_EN_Msk & (_UINT32_(value) << DSI_PCKHDL_CFG_BTA_EN_Pos)) /* Assigment of value for BTA_EN in the DSI_PCKHDL_CFG register */
#define   DSI_PCKHDL_CFG_BTA_EN_0_Val         _UINT32_(0x0)                                        /* (DSI_PCKHDL_CFG) Disables the Bus Turnaround (BTA) request.  */
#define   DSI_PCKHDL_CFG_BTA_EN_1_Val         _UINT32_(0x1)                                        /* (DSI_PCKHDL_CFG) Enables the Bus Turnaround (BTA) request.  */
#define DSI_PCKHDL_CFG_BTA_EN_0               (DSI_PCKHDL_CFG_BTA_EN_0_Val << DSI_PCKHDL_CFG_BTA_EN_Pos) /* (DSI_PCKHDL_CFG) Disables the Bus Turnaround (BTA) request. Position  */
#define DSI_PCKHDL_CFG_BTA_EN_1               (DSI_PCKHDL_CFG_BTA_EN_1_Val << DSI_PCKHDL_CFG_BTA_EN_Pos) /* (DSI_PCKHDL_CFG) Enables the Bus Turnaround (BTA) request. Position  */
#define DSI_PCKHDL_CFG_ECC_RX_EN_Pos          _UINT32_(3)                                          /* (DSI_PCKHDL_CFG) ECC Reception Enable Position */
#define DSI_PCKHDL_CFG_ECC_RX_EN_Msk          (_UINT32_(0x1) << DSI_PCKHDL_CFG_ECC_RX_EN_Pos)      /* (DSI_PCKHDL_CFG) ECC Reception Enable Mask */
#define DSI_PCKHDL_CFG_ECC_RX_EN(value)       (DSI_PCKHDL_CFG_ECC_RX_EN_Msk & (_UINT32_(value) << DSI_PCKHDL_CFG_ECC_RX_EN_Pos)) /* Assigment of value for ECC_RX_EN in the DSI_PCKHDL_CFG register */
#define   DSI_PCKHDL_CFG_ECC_RX_EN_0_Val      _UINT32_(0x0)                                        /* (DSI_PCKHDL_CFG) Disables the ECC reception, error correction, and reporting.  */
#define   DSI_PCKHDL_CFG_ECC_RX_EN_1_Val      _UINT32_(0x1)                                        /* (DSI_PCKHDL_CFG) Enables the ECC reception, error correction, and reporting.  */
#define DSI_PCKHDL_CFG_ECC_RX_EN_0            (DSI_PCKHDL_CFG_ECC_RX_EN_0_Val << DSI_PCKHDL_CFG_ECC_RX_EN_Pos) /* (DSI_PCKHDL_CFG) Disables the ECC reception, error correction, and reporting. Position  */
#define DSI_PCKHDL_CFG_ECC_RX_EN_1            (DSI_PCKHDL_CFG_ECC_RX_EN_1_Val << DSI_PCKHDL_CFG_ECC_RX_EN_Pos) /* (DSI_PCKHDL_CFG) Enables the ECC reception, error correction, and reporting. Position  */
#define DSI_PCKHDL_CFG_CRC_RX_EN_Pos          _UINT32_(4)                                          /* (DSI_PCKHDL_CFG) CRC Reception Enable Position */
#define DSI_PCKHDL_CFG_CRC_RX_EN_Msk          (_UINT32_(0x1) << DSI_PCKHDL_CFG_CRC_RX_EN_Pos)      /* (DSI_PCKHDL_CFG) CRC Reception Enable Mask */
#define DSI_PCKHDL_CFG_CRC_RX_EN(value)       (DSI_PCKHDL_CFG_CRC_RX_EN_Msk & (_UINT32_(value) << DSI_PCKHDL_CFG_CRC_RX_EN_Pos)) /* Assigment of value for CRC_RX_EN in the DSI_PCKHDL_CFG register */
#define   DSI_PCKHDL_CFG_CRC_RX_EN_0_Val      _UINT32_(0x0)                                        /* (DSI_PCKHDL_CFG) Disables the CRC reception and error reporting.  */
#define   DSI_PCKHDL_CFG_CRC_RX_EN_1_Val      _UINT32_(0x1)                                        /* (DSI_PCKHDL_CFG) Enables the CRC reception and error reporting.  */
#define DSI_PCKHDL_CFG_CRC_RX_EN_0            (DSI_PCKHDL_CFG_CRC_RX_EN_0_Val << DSI_PCKHDL_CFG_CRC_RX_EN_Pos) /* (DSI_PCKHDL_CFG) Disables the CRC reception and error reporting. Position  */
#define DSI_PCKHDL_CFG_CRC_RX_EN_1            (DSI_PCKHDL_CFG_CRC_RX_EN_1_Val << DSI_PCKHDL_CFG_CRC_RX_EN_Pos) /* (DSI_PCKHDL_CFG) Enables the CRC reception and error reporting. Position  */
#define DSI_PCKHDL_CFG_Msk                    _UINT32_(0x0000001F)                                 /* (DSI_PCKHDL_CFG) Register Mask  */


/* -------- DSI_GEN_VCID : (DSI Offset: 0x30) (R/W 32) Read Generic Virtual Channel ID Configuration Register -------- */
#define DSI_GEN_VCID_RESETVALUE               _UINT32_(0x00)                                       /*  (DSI_GEN_VCID) Read Generic Virtual Channel ID Configuration Register  Reset Value */

#define DSI_GEN_VCID_GEN_VCID_RX_Pos          _UINT32_(0)                                          /* (DSI_GEN_VCID) Generic Reception Virtual Channel Identifier Position */
#define DSI_GEN_VCID_GEN_VCID_RX_Msk          (_UINT32_(0x3) << DSI_GEN_VCID_GEN_VCID_RX_Pos)      /* (DSI_GEN_VCID) Generic Reception Virtual Channel Identifier Mask */
#define DSI_GEN_VCID_GEN_VCID_RX(value)       (DSI_GEN_VCID_GEN_VCID_RX_Msk & (_UINT32_(value) << DSI_GEN_VCID_GEN_VCID_RX_Pos)) /* Assigment of value for GEN_VCID_RX in the DSI_GEN_VCID register */
#define DSI_GEN_VCID_Msk                      _UINT32_(0x00000003)                                 /* (DSI_GEN_VCID) Register Mask  */


/* -------- DSI_MODE_CFG : (DSI Offset: 0x34) (R/W 32) Mode of Operation Configuration Register -------- */
#define DSI_MODE_CFG_RESETVALUE               _UINT32_(0x00)                                       /*  (DSI_MODE_CFG) Mode of Operation Configuration Register  Reset Value */

#define DSI_MODE_CFG_CMD_VIDEO_MODE_Pos       _UINT32_(0)                                          /* (DSI_MODE_CFG) Command/Video Mode Position */
#define DSI_MODE_CFG_CMD_VIDEO_MODE_Msk       (_UINT32_(0x1) << DSI_MODE_CFG_CMD_VIDEO_MODE_Pos)   /* (DSI_MODE_CFG) Command/Video Mode Mask */
#define DSI_MODE_CFG_CMD_VIDEO_MODE(value)    (DSI_MODE_CFG_CMD_VIDEO_MODE_Msk & (_UINT32_(value) << DSI_MODE_CFG_CMD_VIDEO_MODE_Pos)) /* Assigment of value for CMD_VIDEO_MODE in the DSI_MODE_CFG register */
#define   DSI_MODE_CFG_CMD_VIDEO_MODE_0_Val   _UINT32_(0x0)                                        /* (DSI_MODE_CFG) Video mode.  */
#define   DSI_MODE_CFG_CMD_VIDEO_MODE_1_Val   _UINT32_(0x1)                                        /* (DSI_MODE_CFG) Command mode.  */
#define DSI_MODE_CFG_CMD_VIDEO_MODE_0         (DSI_MODE_CFG_CMD_VIDEO_MODE_0_Val << DSI_MODE_CFG_CMD_VIDEO_MODE_Pos) /* (DSI_MODE_CFG) Video mode. Position  */
#define DSI_MODE_CFG_CMD_VIDEO_MODE_1         (DSI_MODE_CFG_CMD_VIDEO_MODE_1_Val << DSI_MODE_CFG_CMD_VIDEO_MODE_Pos) /* (DSI_MODE_CFG) Command mode. Position  */
#define DSI_MODE_CFG_Msk                      _UINT32_(0x00000001)                                 /* (DSI_MODE_CFG) Register Mask  */


/* -------- DSI_VID_MODE_CFG : (DSI Offset: 0x38) (R/W 32) Video Mode Configuration Register -------- */
#define DSI_VID_MODE_CFG_RESETVALUE           _UINT32_(0x00)                                       /*  (DSI_VID_MODE_CFG) Video Mode Configuration Register  Reset Value */

#define DSI_VID_MODE_CFG_VID_MODE_TYPE_Pos    _UINT32_(0)                                          /* (DSI_VID_MODE_CFG) Video Mode Transmission Type Position */
#define DSI_VID_MODE_CFG_VID_MODE_TYPE_Msk    (_UINT32_(0x3) << DSI_VID_MODE_CFG_VID_MODE_TYPE_Pos) /* (DSI_VID_MODE_CFG) Video Mode Transmission Type Mask */
#define DSI_VID_MODE_CFG_VID_MODE_TYPE(value) (DSI_VID_MODE_CFG_VID_MODE_TYPE_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_VID_MODE_TYPE_Pos)) /* Assigment of value for VID_MODE_TYPE in the DSI_VID_MODE_CFG register */
#define   DSI_VID_MODE_CFG_VID_MODE_TYPE_0_Val _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG) Non-burst with sync pulses  */
#define   DSI_VID_MODE_CFG_VID_MODE_TYPE_1_Val _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG) Non-burst with sync events  */
#define   DSI_VID_MODE_CFG_VID_MODE_TYPE_2_Val _UINT32_(0x2)                                        /* (DSI_VID_MODE_CFG) Burst mode  */
#define   DSI_VID_MODE_CFG_VID_MODE_TYPE_3_Val _UINT32_(0x3)                                        /* (DSI_VID_MODE_CFG) Burst mode  */
#define DSI_VID_MODE_CFG_VID_MODE_TYPE_0      (DSI_VID_MODE_CFG_VID_MODE_TYPE_0_Val << DSI_VID_MODE_CFG_VID_MODE_TYPE_Pos) /* (DSI_VID_MODE_CFG) Non-burst with sync pulses Position  */
#define DSI_VID_MODE_CFG_VID_MODE_TYPE_1      (DSI_VID_MODE_CFG_VID_MODE_TYPE_1_Val << DSI_VID_MODE_CFG_VID_MODE_TYPE_Pos) /* (DSI_VID_MODE_CFG) Non-burst with sync events Position  */
#define DSI_VID_MODE_CFG_VID_MODE_TYPE_2      (DSI_VID_MODE_CFG_VID_MODE_TYPE_2_Val << DSI_VID_MODE_CFG_VID_MODE_TYPE_Pos) /* (DSI_VID_MODE_CFG) Burst mode Position  */
#define DSI_VID_MODE_CFG_VID_MODE_TYPE_3      (DSI_VID_MODE_CFG_VID_MODE_TYPE_3_Val << DSI_VID_MODE_CFG_VID_MODE_TYPE_Pos) /* (DSI_VID_MODE_CFG) Burst mode Position  */
#define DSI_VID_MODE_CFG_LP_VSA_EN_Pos        _UINT32_(8)                                          /* (DSI_VID_MODE_CFG) Low-Power Vertical Sync Active Enable Position */
#define DSI_VID_MODE_CFG_LP_VSA_EN_Msk        (_UINT32_(0x1) << DSI_VID_MODE_CFG_LP_VSA_EN_Pos)    /* (DSI_VID_MODE_CFG) Low-Power Vertical Sync Active Enable Mask */
#define DSI_VID_MODE_CFG_LP_VSA_EN(value)     (DSI_VID_MODE_CFG_LP_VSA_EN_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_LP_VSA_EN_Pos)) /* Assigment of value for LP_VSA_EN in the DSI_VID_MODE_CFG register */
#define   DSI_VID_MODE_CFG_LP_VSA_EN_0_Val    _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG) Disables the return to low-power inside the VSA period when timing allows.  */
#define   DSI_VID_MODE_CFG_LP_VSA_EN_1_Val    _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG) Enables the return to low-power inside the VSA period when timing allows.  */
#define DSI_VID_MODE_CFG_LP_VSA_EN_0          (DSI_VID_MODE_CFG_LP_VSA_EN_0_Val << DSI_VID_MODE_CFG_LP_VSA_EN_Pos) /* (DSI_VID_MODE_CFG) Disables the return to low-power inside the VSA period when timing allows. Position  */
#define DSI_VID_MODE_CFG_LP_VSA_EN_1          (DSI_VID_MODE_CFG_LP_VSA_EN_1_Val << DSI_VID_MODE_CFG_LP_VSA_EN_Pos) /* (DSI_VID_MODE_CFG) Enables the return to low-power inside the VSA period when timing allows. Position  */
#define DSI_VID_MODE_CFG_LP_VBP_EN_Pos        _UINT32_(9)                                          /* (DSI_VID_MODE_CFG) Low-Power Vertical Back Porch Enable Position */
#define DSI_VID_MODE_CFG_LP_VBP_EN_Msk        (_UINT32_(0x1) << DSI_VID_MODE_CFG_LP_VBP_EN_Pos)    /* (DSI_VID_MODE_CFG) Low-Power Vertical Back Porch Enable Mask */
#define DSI_VID_MODE_CFG_LP_VBP_EN(value)     (DSI_VID_MODE_CFG_LP_VBP_EN_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_LP_VBP_EN_Pos)) /* Assigment of value for LP_VBP_EN in the DSI_VID_MODE_CFG register */
#define   DSI_VID_MODE_CFG_LP_VBP_EN_0_Val    _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG) Disables the return to low-power inside the VBP period when timing allows.  */
#define   DSI_VID_MODE_CFG_LP_VBP_EN_1_Val    _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG) Enables the return to low-power inside the VBP period when timing allows.  */
#define DSI_VID_MODE_CFG_LP_VBP_EN_0          (DSI_VID_MODE_CFG_LP_VBP_EN_0_Val << DSI_VID_MODE_CFG_LP_VBP_EN_Pos) /* (DSI_VID_MODE_CFG) Disables the return to low-power inside the VBP period when timing allows. Position  */
#define DSI_VID_MODE_CFG_LP_VBP_EN_1          (DSI_VID_MODE_CFG_LP_VBP_EN_1_Val << DSI_VID_MODE_CFG_LP_VBP_EN_Pos) /* (DSI_VID_MODE_CFG) Enables the return to low-power inside the VBP period when timing allows. Position  */
#define DSI_VID_MODE_CFG_LP_VFP_EN_Pos        _UINT32_(10)                                         /* (DSI_VID_MODE_CFG) Low-Power Vertical Front Porch Enable Position */
#define DSI_VID_MODE_CFG_LP_VFP_EN_Msk        (_UINT32_(0x1) << DSI_VID_MODE_CFG_LP_VFP_EN_Pos)    /* (DSI_VID_MODE_CFG) Low-Power Vertical Front Porch Enable Mask */
#define DSI_VID_MODE_CFG_LP_VFP_EN(value)     (DSI_VID_MODE_CFG_LP_VFP_EN_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_LP_VFP_EN_Pos)) /* Assigment of value for LP_VFP_EN in the DSI_VID_MODE_CFG register */
#define   DSI_VID_MODE_CFG_LP_VFP_EN_0_Val    _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG) Disables the return to low-power inside the VFP period when timing allows.  */
#define   DSI_VID_MODE_CFG_LP_VFP_EN_1_Val    _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG) Enables the return to low-power inside the VFP period when timing allows.  */
#define DSI_VID_MODE_CFG_LP_VFP_EN_0          (DSI_VID_MODE_CFG_LP_VFP_EN_0_Val << DSI_VID_MODE_CFG_LP_VFP_EN_Pos) /* (DSI_VID_MODE_CFG) Disables the return to low-power inside the VFP period when timing allows. Position  */
#define DSI_VID_MODE_CFG_LP_VFP_EN_1          (DSI_VID_MODE_CFG_LP_VFP_EN_1_Val << DSI_VID_MODE_CFG_LP_VFP_EN_Pos) /* (DSI_VID_MODE_CFG) Enables the return to low-power inside the VFP period when timing allows. Position  */
#define DSI_VID_MODE_CFG_LP_VACT_EN_Pos       _UINT32_(11)                                         /* (DSI_VID_MODE_CFG) Low-Power Vertical Active Enable Position */
#define DSI_VID_MODE_CFG_LP_VACT_EN_Msk       (_UINT32_(0x1) << DSI_VID_MODE_CFG_LP_VACT_EN_Pos)   /* (DSI_VID_MODE_CFG) Low-Power Vertical Active Enable Mask */
#define DSI_VID_MODE_CFG_LP_VACT_EN(value)    (DSI_VID_MODE_CFG_LP_VACT_EN_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_LP_VACT_EN_Pos)) /* Assigment of value for LP_VACT_EN in the DSI_VID_MODE_CFG register */
#define   DSI_VID_MODE_CFG_LP_VACT_EN_0_Val   _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG) Disables the return to low-power inside the VACT period when timing allows.  */
#define   DSI_VID_MODE_CFG_LP_VACT_EN_1_Val   _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG) Enables the return to low-power inside the VACT period when timing allows.  */
#define DSI_VID_MODE_CFG_LP_VACT_EN_0         (DSI_VID_MODE_CFG_LP_VACT_EN_0_Val << DSI_VID_MODE_CFG_LP_VACT_EN_Pos) /* (DSI_VID_MODE_CFG) Disables the return to low-power inside the VACT period when timing allows. Position  */
#define DSI_VID_MODE_CFG_LP_VACT_EN_1         (DSI_VID_MODE_CFG_LP_VACT_EN_1_Val << DSI_VID_MODE_CFG_LP_VACT_EN_Pos) /* (DSI_VID_MODE_CFG) Enables the return to low-power inside the VACT period when timing allows. Position  */
#define DSI_VID_MODE_CFG_LP_HBP_EN_Pos        _UINT32_(12)                                         /* (DSI_VID_MODE_CFG) Low-Power Horizontal Back Porch Enable Position */
#define DSI_VID_MODE_CFG_LP_HBP_EN_Msk        (_UINT32_(0x1) << DSI_VID_MODE_CFG_LP_HBP_EN_Pos)    /* (DSI_VID_MODE_CFG) Low-Power Horizontal Back Porch Enable Mask */
#define DSI_VID_MODE_CFG_LP_HBP_EN(value)     (DSI_VID_MODE_CFG_LP_HBP_EN_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_LP_HBP_EN_Pos)) /* Assigment of value for LP_HBP_EN in the DSI_VID_MODE_CFG register */
#define   DSI_VID_MODE_CFG_LP_HBP_EN_0_Val    _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG) Disables the return to low-power inside the HBP period when timing allows.  */
#define   DSI_VID_MODE_CFG_LP_HBP_EN_1_Val    _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG) Enables the return to low-power inside the HBP period when timing allows.  */
#define DSI_VID_MODE_CFG_LP_HBP_EN_0          (DSI_VID_MODE_CFG_LP_HBP_EN_0_Val << DSI_VID_MODE_CFG_LP_HBP_EN_Pos) /* (DSI_VID_MODE_CFG) Disables the return to low-power inside the HBP period when timing allows. Position  */
#define DSI_VID_MODE_CFG_LP_HBP_EN_1          (DSI_VID_MODE_CFG_LP_HBP_EN_1_Val << DSI_VID_MODE_CFG_LP_HBP_EN_Pos) /* (DSI_VID_MODE_CFG) Enables the return to low-power inside the HBP period when timing allows. Position  */
#define DSI_VID_MODE_CFG_LP_HFP_EN_Pos        _UINT32_(13)                                         /* (DSI_VID_MODE_CFG) Low-Power Horizontal Front Porch Enable Position */
#define DSI_VID_MODE_CFG_LP_HFP_EN_Msk        (_UINT32_(0x1) << DSI_VID_MODE_CFG_LP_HFP_EN_Pos)    /* (DSI_VID_MODE_CFG) Low-Power Horizontal Front Porch Enable Mask */
#define DSI_VID_MODE_CFG_LP_HFP_EN(value)     (DSI_VID_MODE_CFG_LP_HFP_EN_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_LP_HFP_EN_Pos)) /* Assigment of value for LP_HFP_EN in the DSI_VID_MODE_CFG register */
#define   DSI_VID_MODE_CFG_LP_HFP_EN_0_Val    _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG) Disables the return to low-power inside the HFP period when timing allows.  */
#define   DSI_VID_MODE_CFG_LP_HFP_EN_1_Val    _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG) Enables the return to low-power inside the HFP period when timing allows.  */
#define DSI_VID_MODE_CFG_LP_HFP_EN_0          (DSI_VID_MODE_CFG_LP_HFP_EN_0_Val << DSI_VID_MODE_CFG_LP_HFP_EN_Pos) /* (DSI_VID_MODE_CFG) Disables the return to low-power inside the HFP period when timing allows. Position  */
#define DSI_VID_MODE_CFG_LP_HFP_EN_1          (DSI_VID_MODE_CFG_LP_HFP_EN_1_Val << DSI_VID_MODE_CFG_LP_HFP_EN_Pos) /* (DSI_VID_MODE_CFG) Enables the return to low-power inside the HFP period when timing allows. Position  */
#define DSI_VID_MODE_CFG_FRAME_BTA_ACK_EN_Pos _UINT32_(14)                                         /* (DSI_VID_MODE_CFG) Frame Bus Turn Around Acknowledge Enable Position */
#define DSI_VID_MODE_CFG_FRAME_BTA_ACK_EN_Msk (_UINT32_(0x1) << DSI_VID_MODE_CFG_FRAME_BTA_ACK_EN_Pos) /* (DSI_VID_MODE_CFG) Frame Bus Turn Around Acknowledge Enable Mask */
#define DSI_VID_MODE_CFG_FRAME_BTA_ACK_EN(value) (DSI_VID_MODE_CFG_FRAME_BTA_ACK_EN_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_FRAME_BTA_ACK_EN_Pos)) /* Assigment of value for FRAME_BTA_ACK_EN in the DSI_VID_MODE_CFG register */
#define   DSI_VID_MODE_CFG_FRAME_BTA_ACK_EN_0_Val _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG) Disables the request for an acknowledge response at the end of a frame.  */
#define   DSI_VID_MODE_CFG_FRAME_BTA_ACK_EN_1_Val _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG) Enables the request for an acknowledge response at the end of a frame.  */
#define DSI_VID_MODE_CFG_FRAME_BTA_ACK_EN_0   (DSI_VID_MODE_CFG_FRAME_BTA_ACK_EN_0_Val << DSI_VID_MODE_CFG_FRAME_BTA_ACK_EN_Pos) /* (DSI_VID_MODE_CFG) Disables the request for an acknowledge response at the end of a frame. Position  */
#define DSI_VID_MODE_CFG_FRAME_BTA_ACK_EN_1   (DSI_VID_MODE_CFG_FRAME_BTA_ACK_EN_1_Val << DSI_VID_MODE_CFG_FRAME_BTA_ACK_EN_Pos) /* (DSI_VID_MODE_CFG) Enables the request for an acknowledge response at the end of a frame. Position  */
#define DSI_VID_MODE_CFG_LP_CMD_EN_Pos        _UINT32_(15)                                         /* (DSI_VID_MODE_CFG) Low Power Command Transmission Enable Position */
#define DSI_VID_MODE_CFG_LP_CMD_EN_Msk        (_UINT32_(0x1) << DSI_VID_MODE_CFG_LP_CMD_EN_Pos)    /* (DSI_VID_MODE_CFG) Low Power Command Transmission Enable Mask */
#define DSI_VID_MODE_CFG_LP_CMD_EN(value)     (DSI_VID_MODE_CFG_LP_CMD_EN_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_LP_CMD_EN_Pos)) /* Assigment of value for LP_CMD_EN in the DSI_VID_MODE_CFG register */
#define   DSI_VID_MODE_CFG_LP_CMD_EN_0_Val    _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG) Disables the command transmission only in Low-Power mode.  */
#define   DSI_VID_MODE_CFG_LP_CMD_EN_1_Val    _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG) Enables the command transmission only in Low-Power mode.  */
#define DSI_VID_MODE_CFG_LP_CMD_EN_0          (DSI_VID_MODE_CFG_LP_CMD_EN_0_Val << DSI_VID_MODE_CFG_LP_CMD_EN_Pos) /* (DSI_VID_MODE_CFG) Disables the command transmission only in Low-Power mode. Position  */
#define DSI_VID_MODE_CFG_LP_CMD_EN_1          (DSI_VID_MODE_CFG_LP_CMD_EN_1_Val << DSI_VID_MODE_CFG_LP_CMD_EN_Pos) /* (DSI_VID_MODE_CFG) Enables the command transmission only in Low-Power mode. Position  */
#define DSI_VID_MODE_CFG_VPG_EN_Pos           _UINT32_(16)                                         /* (DSI_VID_MODE_CFG) Video Pattern Generator Enable Position */
#define DSI_VID_MODE_CFG_VPG_EN_Msk           (_UINT32_(0x1) << DSI_VID_MODE_CFG_VPG_EN_Pos)       /* (DSI_VID_MODE_CFG) Video Pattern Generator Enable Mask */
#define DSI_VID_MODE_CFG_VPG_EN(value)        (DSI_VID_MODE_CFG_VPG_EN_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_VPG_EN_Pos)) /* Assigment of value for VPG_EN in the DSI_VID_MODE_CFG register */
#define   DSI_VID_MODE_CFG_VPG_EN_0_Val       _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG) Disables the video mode pattern generator.  */
#define   DSI_VID_MODE_CFG_VPG_EN_1_Val       _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG) Enables the video mode pattern generator.  */
#define DSI_VID_MODE_CFG_VPG_EN_0             (DSI_VID_MODE_CFG_VPG_EN_0_Val << DSI_VID_MODE_CFG_VPG_EN_Pos) /* (DSI_VID_MODE_CFG) Disables the video mode pattern generator. Position  */
#define DSI_VID_MODE_CFG_VPG_EN_1             (DSI_VID_MODE_CFG_VPG_EN_1_Val << DSI_VID_MODE_CFG_VPG_EN_Pos) /* (DSI_VID_MODE_CFG) Enables the video mode pattern generator. Position  */
#define DSI_VID_MODE_CFG_VPG_MODE_Pos         _UINT32_(20)                                         /* (DSI_VID_MODE_CFG) Video Pattern Generator Mode Position */
#define DSI_VID_MODE_CFG_VPG_MODE_Msk         (_UINT32_(0x1) << DSI_VID_MODE_CFG_VPG_MODE_Pos)     /* (DSI_VID_MODE_CFG) Video Pattern Generator Mode Mask */
#define DSI_VID_MODE_CFG_VPG_MODE(value)      (DSI_VID_MODE_CFG_VPG_MODE_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_VPG_MODE_Pos)) /* Assigment of value for VPG_MODE in the DSI_VID_MODE_CFG register */
#define   DSI_VID_MODE_CFG_VPG_MODE_0_Val     _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG) Color bar (horizontal or vertical) pattern is selected.  */
#define   DSI_VID_MODE_CFG_VPG_MODE_1_Val     _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG) BER pattern (vertical only) is selected.  */
#define DSI_VID_MODE_CFG_VPG_MODE_0           (DSI_VID_MODE_CFG_VPG_MODE_0_Val << DSI_VID_MODE_CFG_VPG_MODE_Pos) /* (DSI_VID_MODE_CFG) Color bar (horizontal or vertical) pattern is selected. Position  */
#define DSI_VID_MODE_CFG_VPG_MODE_1           (DSI_VID_MODE_CFG_VPG_MODE_1_Val << DSI_VID_MODE_CFG_VPG_MODE_Pos) /* (DSI_VID_MODE_CFG) BER pattern (vertical only) is selected. Position  */
#define DSI_VID_MODE_CFG_VPG_ORIENTATION_Pos  _UINT32_(24)                                         /* (DSI_VID_MODE_CFG) Video Pattern Generator Orientation Position */
#define DSI_VID_MODE_CFG_VPG_ORIENTATION_Msk  (_UINT32_(0x1) << DSI_VID_MODE_CFG_VPG_ORIENTATION_Pos) /* (DSI_VID_MODE_CFG) Video Pattern Generator Orientation Mask */
#define DSI_VID_MODE_CFG_VPG_ORIENTATION(value) (DSI_VID_MODE_CFG_VPG_ORIENTATION_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_VPG_ORIENTATION_Pos)) /* Assigment of value for VPG_ORIENTATION in the DSI_VID_MODE_CFG register */
#define   DSI_VID_MODE_CFG_VPG_ORIENTATION_0_Val _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG) Vertical color bar orientation.  */
#define   DSI_VID_MODE_CFG_VPG_ORIENTATION_1_Val _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG) Horizontal color bar orientation.  */
#define DSI_VID_MODE_CFG_VPG_ORIENTATION_0    (DSI_VID_MODE_CFG_VPG_ORIENTATION_0_Val << DSI_VID_MODE_CFG_VPG_ORIENTATION_Pos) /* (DSI_VID_MODE_CFG) Vertical color bar orientation. Position  */
#define DSI_VID_MODE_CFG_VPG_ORIENTATION_1    (DSI_VID_MODE_CFG_VPG_ORIENTATION_1_Val << DSI_VID_MODE_CFG_VPG_ORIENTATION_Pos) /* (DSI_VID_MODE_CFG) Horizontal color bar orientation. Position  */
#define DSI_VID_MODE_CFG_Msk                  _UINT32_(0x0111FF03)                                 /* (DSI_VID_MODE_CFG) Register Mask  */


/* -------- DSI_VID_PKT_SIZE : (DSI Offset: 0x3C) (R/W 32) Video Mode packet size Configuration Register -------- */
#define DSI_VID_PKT_SIZE_RESETVALUE           _UINT32_(0x00)                                       /*  (DSI_VID_PKT_SIZE) Video Mode packet size Configuration Register  Reset Value */

#define DSI_VID_PKT_SIZE_VID_PKT_SIZE_Pos     _UINT32_(0)                                          /* (DSI_VID_PKT_SIZE) Video Mode Packet Size Position */
#define DSI_VID_PKT_SIZE_VID_PKT_SIZE_Msk     (_UINT32_(0x3FFF) << DSI_VID_PKT_SIZE_VID_PKT_SIZE_Pos) /* (DSI_VID_PKT_SIZE) Video Mode Packet Size Mask */
#define DSI_VID_PKT_SIZE_VID_PKT_SIZE(value)  (DSI_VID_PKT_SIZE_VID_PKT_SIZE_Msk & (_UINT32_(value) << DSI_VID_PKT_SIZE_VID_PKT_SIZE_Pos)) /* Assigment of value for VID_PKT_SIZE in the DSI_VID_PKT_SIZE register */
#define DSI_VID_PKT_SIZE_Msk                  _UINT32_(0x00003FFF)                                 /* (DSI_VID_PKT_SIZE) Register Mask  */


/* -------- DSI_VID_NUM_CHUNKS : (DSI Offset: 0x40) (R/W 32) Video Mode Number of Chunks Configuration Register -------- */
#define DSI_VID_NUM_CHUNKS_RESETVALUE         _UINT32_(0x00)                                       /*  (DSI_VID_NUM_CHUNKS) Video Mode Number of Chunks Configuration Register  Reset Value */

#define DSI_VID_NUM_CHUNKS_VID_NUM_CHUNKS_Pos _UINT32_(0)                                          /* (DSI_VID_NUM_CHUNKS) Video Mode Number of Chunks Position */
#define DSI_VID_NUM_CHUNKS_VID_NUM_CHUNKS_Msk (_UINT32_(0x1FFF) << DSI_VID_NUM_CHUNKS_VID_NUM_CHUNKS_Pos) /* (DSI_VID_NUM_CHUNKS) Video Mode Number of Chunks Mask */
#define DSI_VID_NUM_CHUNKS_VID_NUM_CHUNKS(value) (DSI_VID_NUM_CHUNKS_VID_NUM_CHUNKS_Msk & (_UINT32_(value) << DSI_VID_NUM_CHUNKS_VID_NUM_CHUNKS_Pos)) /* Assigment of value for VID_NUM_CHUNKS in the DSI_VID_NUM_CHUNKS register */
#define DSI_VID_NUM_CHUNKS_Msk                _UINT32_(0x00001FFF)                                 /* (DSI_VID_NUM_CHUNKS) Register Mask  */


/* -------- DSI_VID_NULL_SIZE : (DSI Offset: 0x44) (R/W 32) Video Mode Null Packets Size Configuration Register -------- */
#define DSI_VID_NULL_SIZE_RESETVALUE          _UINT32_(0x00)                                       /*  (DSI_VID_NULL_SIZE) Video Mode Null Packets Size Configuration Register  Reset Value */

#define DSI_VID_NULL_SIZE_VID_NULL_SIZE_Pos   _UINT32_(0)                                          /* (DSI_VID_NULL_SIZE) Video Mode Null Packet Size Position */
#define DSI_VID_NULL_SIZE_VID_NULL_SIZE_Msk   (_UINT32_(0x1FFF) << DSI_VID_NULL_SIZE_VID_NULL_SIZE_Pos) /* (DSI_VID_NULL_SIZE) Video Mode Null Packet Size Mask */
#define DSI_VID_NULL_SIZE_VID_NULL_SIZE(value) (DSI_VID_NULL_SIZE_VID_NULL_SIZE_Msk & (_UINT32_(value) << DSI_VID_NULL_SIZE_VID_NULL_SIZE_Pos)) /* Assigment of value for VID_NULL_SIZE in the DSI_VID_NULL_SIZE register */
#define DSI_VID_NULL_SIZE_Msk                 _UINT32_(0x00001FFF)                                 /* (DSI_VID_NULL_SIZE) Register Mask  */


/* -------- DSI_VID_HSA_TIME : (DSI Offset: 0x48) (R/W 32) Video Mode HSA Time Configuration Register -------- */
#define DSI_VID_HSA_TIME_RESETVALUE           _UINT32_(0x00)                                       /*  (DSI_VID_HSA_TIME) Video Mode HSA Time Configuration Register  Reset Value */

#define DSI_VID_HSA_TIME_VID_HSA_TIME_Pos     _UINT32_(0)                                          /* (DSI_VID_HSA_TIME) Video Mode Horizontal Sync Active Time Position */
#define DSI_VID_HSA_TIME_VID_HSA_TIME_Msk     (_UINT32_(0xFFF) << DSI_VID_HSA_TIME_VID_HSA_TIME_Pos) /* (DSI_VID_HSA_TIME) Video Mode Horizontal Sync Active Time Mask */
#define DSI_VID_HSA_TIME_VID_HSA_TIME(value)  (DSI_VID_HSA_TIME_VID_HSA_TIME_Msk & (_UINT32_(value) << DSI_VID_HSA_TIME_VID_HSA_TIME_Pos)) /* Assigment of value for VID_HSA_TIME in the DSI_VID_HSA_TIME register */
#define DSI_VID_HSA_TIME_Msk                  _UINT32_(0x00000FFF)                                 /* (DSI_VID_HSA_TIME) Register Mask  */


/* -------- DSI_VID_HBP_TIME : (DSI Offset: 0x4C) (R/W 32) Video Mode HBP Time Configuration Register -------- */
#define DSI_VID_HBP_TIME_RESETVALUE           _UINT32_(0x00)                                       /*  (DSI_VID_HBP_TIME) Video Mode HBP Time Configuration Register  Reset Value */

#define DSI_VID_HBP_TIME_VID_HBP_TIME_Pos     _UINT32_(0)                                          /* (DSI_VID_HBP_TIME) Video Mode Horizontal Back Porch Time Position */
#define DSI_VID_HBP_TIME_VID_HBP_TIME_Msk     (_UINT32_(0xFFF) << DSI_VID_HBP_TIME_VID_HBP_TIME_Pos) /* (DSI_VID_HBP_TIME) Video Mode Horizontal Back Porch Time Mask */
#define DSI_VID_HBP_TIME_VID_HBP_TIME(value)  (DSI_VID_HBP_TIME_VID_HBP_TIME_Msk & (_UINT32_(value) << DSI_VID_HBP_TIME_VID_HBP_TIME_Pos)) /* Assigment of value for VID_HBP_TIME in the DSI_VID_HBP_TIME register */
#define DSI_VID_HBP_TIME_Msk                  _UINT32_(0x00000FFF)                                 /* (DSI_VID_HBP_TIME) Register Mask  */


/* -------- DSI_VID_HLINE_TIME : (DSI Offset: 0x50) (R/W 32) Video Mode HLINE Time Configuration Register -------- */
#define DSI_VID_HLINE_TIME_RESETVALUE         _UINT32_(0x00)                                       /*  (DSI_VID_HLINE_TIME) Video Mode HLINE Time Configuration Register  Reset Value */

#define DSI_VID_HLINE_TIME_VID_HLINE_TIME_Pos _UINT32_(0)                                          /* (DSI_VID_HLINE_TIME) Video Mode Horizontal Line Time Position */
#define DSI_VID_HLINE_TIME_VID_HLINE_TIME_Msk (_UINT32_(0x7FFF) << DSI_VID_HLINE_TIME_VID_HLINE_TIME_Pos) /* (DSI_VID_HLINE_TIME) Video Mode Horizontal Line Time Mask */
#define DSI_VID_HLINE_TIME_VID_HLINE_TIME(value) (DSI_VID_HLINE_TIME_VID_HLINE_TIME_Msk & (_UINT32_(value) << DSI_VID_HLINE_TIME_VID_HLINE_TIME_Pos)) /* Assigment of value for VID_HLINE_TIME in the DSI_VID_HLINE_TIME register */
#define DSI_VID_HLINE_TIME_Msk                _UINT32_(0x00007FFF)                                 /* (DSI_VID_HLINE_TIME) Register Mask  */


/* -------- DSI_VID_VSA_LINES : (DSI Offset: 0x54) (R/W 32) Video Mode VSA Lines Configuration Register -------- */
#define DSI_VID_VSA_LINES_RESETVALUE          _UINT32_(0x00)                                       /*  (DSI_VID_VSA_LINES) Video Mode VSA Lines Configuration Register  Reset Value */

#define DSI_VID_VSA_LINES_VSA_LINES_Pos       _UINT32_(0)                                          /* (DSI_VID_VSA_LINES) Vertical Sync Active Lines Position */
#define DSI_VID_VSA_LINES_VSA_LINES_Msk       (_UINT32_(0x3FF) << DSI_VID_VSA_LINES_VSA_LINES_Pos) /* (DSI_VID_VSA_LINES) Vertical Sync Active Lines Mask */
#define DSI_VID_VSA_LINES_VSA_LINES(value)    (DSI_VID_VSA_LINES_VSA_LINES_Msk & (_UINT32_(value) << DSI_VID_VSA_LINES_VSA_LINES_Pos)) /* Assigment of value for VSA_LINES in the DSI_VID_VSA_LINES register */
#define DSI_VID_VSA_LINES_Msk                 _UINT32_(0x000003FF)                                 /* (DSI_VID_VSA_LINES) Register Mask  */


/* -------- DSI_VID_VBP_LINES : (DSI Offset: 0x58) (R/W 32) Video Mode VBP Lines Configuration Register -------- */
#define DSI_VID_VBP_LINES_RESETVALUE          _UINT32_(0x00)                                       /*  (DSI_VID_VBP_LINES) Video Mode VBP Lines Configuration Register  Reset Value */

#define DSI_VID_VBP_LINES_VBP_LINES_Pos       _UINT32_(0)                                          /* (DSI_VID_VBP_LINES) Vertical Back Porch Lines Position */
#define DSI_VID_VBP_LINES_VBP_LINES_Msk       (_UINT32_(0x3FF) << DSI_VID_VBP_LINES_VBP_LINES_Pos) /* (DSI_VID_VBP_LINES) Vertical Back Porch Lines Mask */
#define DSI_VID_VBP_LINES_VBP_LINES(value)    (DSI_VID_VBP_LINES_VBP_LINES_Msk & (_UINT32_(value) << DSI_VID_VBP_LINES_VBP_LINES_Pos)) /* Assigment of value for VBP_LINES in the DSI_VID_VBP_LINES register */
#define DSI_VID_VBP_LINES_Msk                 _UINT32_(0x000003FF)                                 /* (DSI_VID_VBP_LINES) Register Mask  */


/* -------- DSI_VID_VFP_LINES : (DSI Offset: 0x5C) (R/W 32) Video Mode VFP Lines Configuration Register -------- */
#define DSI_VID_VFP_LINES_RESETVALUE          _UINT32_(0x00)                                       /*  (DSI_VID_VFP_LINES) Video Mode VFP Lines Configuration Register  Reset Value */

#define DSI_VID_VFP_LINES_VFP_LINES_Pos       _UINT32_(0)                                          /* (DSI_VID_VFP_LINES) Video Mode Vertical Front Porch Lines Position */
#define DSI_VID_VFP_LINES_VFP_LINES_Msk       (_UINT32_(0x3FF) << DSI_VID_VFP_LINES_VFP_LINES_Pos) /* (DSI_VID_VFP_LINES) Video Mode Vertical Front Porch Lines Mask */
#define DSI_VID_VFP_LINES_VFP_LINES(value)    (DSI_VID_VFP_LINES_VFP_LINES_Msk & (_UINT32_(value) << DSI_VID_VFP_LINES_VFP_LINES_Pos)) /* Assigment of value for VFP_LINES in the DSI_VID_VFP_LINES register */
#define DSI_VID_VFP_LINES_Msk                 _UINT32_(0x000003FF)                                 /* (DSI_VID_VFP_LINES) Register Mask  */


/* -------- DSI_VID_VACTIVE_LINES : (DSI Offset: 0x60) (R/W 32) Video Mode VACTIVE Lines Configuration Register -------- */
#define DSI_VID_VACTIVE_LINES_RESETVALUE      _UINT32_(0x00)                                       /*  (DSI_VID_VACTIVE_LINES) Video Mode VACTIVE Lines Configuration Register  Reset Value */

#define DSI_VID_VACTIVE_LINES_V_ACTIVE_LINES_Pos _UINT32_(0)                                          /* (DSI_VID_VACTIVE_LINES) Video Mode Active Lines Position */
#define DSI_VID_VACTIVE_LINES_V_ACTIVE_LINES_Msk (_UINT32_(0x3FFF) << DSI_VID_VACTIVE_LINES_V_ACTIVE_LINES_Pos) /* (DSI_VID_VACTIVE_LINES) Video Mode Active Lines Mask */
#define DSI_VID_VACTIVE_LINES_V_ACTIVE_LINES(value) (DSI_VID_VACTIVE_LINES_V_ACTIVE_LINES_Msk & (_UINT32_(value) << DSI_VID_VACTIVE_LINES_V_ACTIVE_LINES_Pos)) /* Assigment of value for V_ACTIVE_LINES in the DSI_VID_VACTIVE_LINES register */
#define DSI_VID_VACTIVE_LINES_Msk             _UINT32_(0x00003FFF)                                 /* (DSI_VID_VACTIVE_LINES) Register Mask  */


/* -------- DSI_CMD_MODE_CFG : (DSI Offset: 0x68) (R/W 32) Command Mode Configuration Register -------- */
#define DSI_CMD_MODE_CFG_RESETVALUE           _UINT32_(0x00)                                       /*  (DSI_CMD_MODE_CFG) Command Mode Configuration Register  Reset Value */

#define DSI_CMD_MODE_CFG_TEAR_FX_EN_Pos       _UINT32_(0)                                          /* (DSI_CMD_MODE_CFG) Tearing Effect Enable Position */
#define DSI_CMD_MODE_CFG_TEAR_FX_EN_Msk       (_UINT32_(0x1) << DSI_CMD_MODE_CFG_TEAR_FX_EN_Pos)   /* (DSI_CMD_MODE_CFG) Tearing Effect Enable Mask */
#define DSI_CMD_MODE_CFG_TEAR_FX_EN(value)    (DSI_CMD_MODE_CFG_TEAR_FX_EN_Msk & (_UINT32_(value) << DSI_CMD_MODE_CFG_TEAR_FX_EN_Pos)) /* Assigment of value for TEAR_FX_EN in the DSI_CMD_MODE_CFG register */
#define   DSI_CMD_MODE_CFG_TEAR_FX_EN_0_Val   _UINT32_(0x0)                                        /* (DSI_CMD_MODE_CFG) Disables the tearing effect acknowledge request.  */
#define   DSI_CMD_MODE_CFG_TEAR_FX_EN_1_Val   _UINT32_(0x1)                                        /* (DSI_CMD_MODE_CFG) Enables the tearing effect acknowledge request.  */
#define DSI_CMD_MODE_CFG_TEAR_FX_EN_0         (DSI_CMD_MODE_CFG_TEAR_FX_EN_0_Val << DSI_CMD_MODE_CFG_TEAR_FX_EN_Pos) /* (DSI_CMD_MODE_CFG) Disables the tearing effect acknowledge request. Position  */
#define DSI_CMD_MODE_CFG_TEAR_FX_EN_1         (DSI_CMD_MODE_CFG_TEAR_FX_EN_1_Val << DSI_CMD_MODE_CFG_TEAR_FX_EN_Pos) /* (DSI_CMD_MODE_CFG) Enables the tearing effect acknowledge request. Position  */
#define DSI_CMD_MODE_CFG_ACK_RQST_EN_Pos      _UINT32_(1)                                          /* (DSI_CMD_MODE_CFG) Acknowledge Request Enable Position */
#define DSI_CMD_MODE_CFG_ACK_RQST_EN_Msk      (_UINT32_(0x1) << DSI_CMD_MODE_CFG_ACK_RQST_EN_Pos)  /* (DSI_CMD_MODE_CFG) Acknowledge Request Enable Mask */
#define DSI_CMD_MODE_CFG_ACK_RQST_EN(value)   (DSI_CMD_MODE_CFG_ACK_RQST_EN_Msk & (_UINT32_(value) << DSI_CMD_MODE_CFG_ACK_RQST_EN_Pos)) /* Assigment of value for ACK_RQST_EN in the DSI_CMD_MODE_CFG register */
#define   DSI_CMD_MODE_CFG_ACK_RQST_EN_0_Val  _UINT32_(0x0)                                        /* (DSI_CMD_MODE_CFG) Disables the acknowledge request after each packet transmission.  */
#define   DSI_CMD_MODE_CFG_ACK_RQST_EN_1_Val  _UINT32_(0x1)                                        /* (DSI_CMD_MODE_CFG) Enables the acknowledge request after each packet transmission.  */
#define DSI_CMD_MODE_CFG_ACK_RQST_EN_0        (DSI_CMD_MODE_CFG_ACK_RQST_EN_0_Val << DSI_CMD_MODE_CFG_ACK_RQST_EN_Pos) /* (DSI_CMD_MODE_CFG) Disables the acknowledge request after each packet transmission. Position  */
#define DSI_CMD_MODE_CFG_ACK_RQST_EN_1        (DSI_CMD_MODE_CFG_ACK_RQST_EN_1_Val << DSI_CMD_MODE_CFG_ACK_RQST_EN_Pos) /* (DSI_CMD_MODE_CFG) Enables the acknowledge request after each packet transmission. Position  */
#define DSI_CMD_MODE_CFG_GEN_SW_0P_TX_Pos     _UINT32_(8)                                          /* (DSI_CMD_MODE_CFG) Generic Short Write Packet 0 Transmission Type Position */
#define DSI_CMD_MODE_CFG_GEN_SW_0P_TX_Msk     (_UINT32_(0x1) << DSI_CMD_MODE_CFG_GEN_SW_0P_TX_Pos) /* (DSI_CMD_MODE_CFG) Generic Short Write Packet 0 Transmission Type Mask */
#define DSI_CMD_MODE_CFG_GEN_SW_0P_TX(value)  (DSI_CMD_MODE_CFG_GEN_SW_0P_TX_Msk & (_UINT32_(value) << DSI_CMD_MODE_CFG_GEN_SW_0P_TX_Pos)) /* Assigment of value for GEN_SW_0P_TX in the DSI_CMD_MODE_CFG register */
#define   DSI_CMD_MODE_CFG_GEN_SW_0P_TX_0_Val _UINT32_(0x0)                                        /* (DSI_CMD_MODE_CFG) High-speed.  */
#define   DSI_CMD_MODE_CFG_GEN_SW_0P_TX_1_Val _UINT32_(0x1)                                        /* (DSI_CMD_MODE_CFG) Low-power.  */
#define DSI_CMD_MODE_CFG_GEN_SW_0P_TX_0       (DSI_CMD_MODE_CFG_GEN_SW_0P_TX_0_Val << DSI_CMD_MODE_CFG_GEN_SW_0P_TX_Pos) /* (DSI_CMD_MODE_CFG) High-speed. Position  */
#define DSI_CMD_MODE_CFG_GEN_SW_0P_TX_1       (DSI_CMD_MODE_CFG_GEN_SW_0P_TX_1_Val << DSI_CMD_MODE_CFG_GEN_SW_0P_TX_Pos) /* (DSI_CMD_MODE_CFG) Low-power. Position  */
#define DSI_CMD_MODE_CFG_GEN_SW_1P_TX_Pos     _UINT32_(9)                                          /* (DSI_CMD_MODE_CFG) Generic Short Write Packet 1 Transmission Type Position */
#define DSI_CMD_MODE_CFG_GEN_SW_1P_TX_Msk     (_UINT32_(0x1) << DSI_CMD_MODE_CFG_GEN_SW_1P_TX_Pos) /* (DSI_CMD_MODE_CFG) Generic Short Write Packet 1 Transmission Type Mask */
#define DSI_CMD_MODE_CFG_GEN_SW_1P_TX(value)  (DSI_CMD_MODE_CFG_GEN_SW_1P_TX_Msk & (_UINT32_(value) << DSI_CMD_MODE_CFG_GEN_SW_1P_TX_Pos)) /* Assigment of value for GEN_SW_1P_TX in the DSI_CMD_MODE_CFG register */
#define   DSI_CMD_MODE_CFG_GEN_SW_1P_TX_0_Val _UINT32_(0x0)                                        /* (DSI_CMD_MODE_CFG) High-speed.  */
#define   DSI_CMD_MODE_CFG_GEN_SW_1P_TX_1_Val _UINT32_(0x1)                                        /* (DSI_CMD_MODE_CFG) Low-power.  */
#define DSI_CMD_MODE_CFG_GEN_SW_1P_TX_0       (DSI_CMD_MODE_CFG_GEN_SW_1P_TX_0_Val << DSI_CMD_MODE_CFG_GEN_SW_1P_TX_Pos) /* (DSI_CMD_MODE_CFG) High-speed. Position  */
#define DSI_CMD_MODE_CFG_GEN_SW_1P_TX_1       (DSI_CMD_MODE_CFG_GEN_SW_1P_TX_1_Val << DSI_CMD_MODE_CFG_GEN_SW_1P_TX_Pos) /* (DSI_CMD_MODE_CFG) Low-power. Position  */
#define DSI_CMD_MODE_CFG_GEN_SW_2P_TX_Pos     _UINT32_(10)                                         /* (DSI_CMD_MODE_CFG) Generic Short Write Packet 2 Transmission Type Position */
#define DSI_CMD_MODE_CFG_GEN_SW_2P_TX_Msk     (_UINT32_(0x1) << DSI_CMD_MODE_CFG_GEN_SW_2P_TX_Pos) /* (DSI_CMD_MODE_CFG) Generic Short Write Packet 2 Transmission Type Mask */
#define DSI_CMD_MODE_CFG_GEN_SW_2P_TX(value)  (DSI_CMD_MODE_CFG_GEN_SW_2P_TX_Msk & (_UINT32_(value) << DSI_CMD_MODE_CFG_GEN_SW_2P_TX_Pos)) /* Assigment of value for GEN_SW_2P_TX in the DSI_CMD_MODE_CFG register */
#define   DSI_CMD_MODE_CFG_GEN_SW_2P_TX_0_Val _UINT32_(0x0)                                        /* (DSI_CMD_MODE_CFG) High-speed.  */
#define   DSI_CMD_MODE_CFG_GEN_SW_2P_TX_1_Val _UINT32_(0x1)                                        /* (DSI_CMD_MODE_CFG) Low-power.  */
#define DSI_CMD_MODE_CFG_GEN_SW_2P_TX_0       (DSI_CMD_MODE_CFG_GEN_SW_2P_TX_0_Val << DSI_CMD_MODE_CFG_GEN_SW_2P_TX_Pos) /* (DSI_CMD_MODE_CFG) High-speed. Position  */
#define DSI_CMD_MODE_CFG_GEN_SW_2P_TX_1       (DSI_CMD_MODE_CFG_GEN_SW_2P_TX_1_Val << DSI_CMD_MODE_CFG_GEN_SW_2P_TX_Pos) /* (DSI_CMD_MODE_CFG) Low-power. Position  */
#define DSI_CMD_MODE_CFG_GEN_SR_0P_TX_Pos     _UINT32_(11)                                         /* (DSI_CMD_MODE_CFG) Generic Short Read Packet 0 Transmission Type Position */
#define DSI_CMD_MODE_CFG_GEN_SR_0P_TX_Msk     (_UINT32_(0x1) << DSI_CMD_MODE_CFG_GEN_SR_0P_TX_Pos) /* (DSI_CMD_MODE_CFG) Generic Short Read Packet 0 Transmission Type Mask */
#define DSI_CMD_MODE_CFG_GEN_SR_0P_TX(value)  (DSI_CMD_MODE_CFG_GEN_SR_0P_TX_Msk & (_UINT32_(value) << DSI_CMD_MODE_CFG_GEN_SR_0P_TX_Pos)) /* Assigment of value for GEN_SR_0P_TX in the DSI_CMD_MODE_CFG register */
#define   DSI_CMD_MODE_CFG_GEN_SR_0P_TX_0_Val _UINT32_(0x0)                                        /* (DSI_CMD_MODE_CFG) High-speed.  */
#define   DSI_CMD_MODE_CFG_GEN_SR_0P_TX_1_Val _UINT32_(0x1)                                        /* (DSI_CMD_MODE_CFG) Low-power.  */
#define DSI_CMD_MODE_CFG_GEN_SR_0P_TX_0       (DSI_CMD_MODE_CFG_GEN_SR_0P_TX_0_Val << DSI_CMD_MODE_CFG_GEN_SR_0P_TX_Pos) /* (DSI_CMD_MODE_CFG) High-speed. Position  */
#define DSI_CMD_MODE_CFG_GEN_SR_0P_TX_1       (DSI_CMD_MODE_CFG_GEN_SR_0P_TX_1_Val << DSI_CMD_MODE_CFG_GEN_SR_0P_TX_Pos) /* (DSI_CMD_MODE_CFG) Low-power. Position  */
#define DSI_CMD_MODE_CFG_GEN_SR_1P_TX_Pos     _UINT32_(12)                                         /* (DSI_CMD_MODE_CFG) Generic Short Read Packet 1 Transmission Type Position */
#define DSI_CMD_MODE_CFG_GEN_SR_1P_TX_Msk     (_UINT32_(0x1) << DSI_CMD_MODE_CFG_GEN_SR_1P_TX_Pos) /* (DSI_CMD_MODE_CFG) Generic Short Read Packet 1 Transmission Type Mask */
#define DSI_CMD_MODE_CFG_GEN_SR_1P_TX(value)  (DSI_CMD_MODE_CFG_GEN_SR_1P_TX_Msk & (_UINT32_(value) << DSI_CMD_MODE_CFG_GEN_SR_1P_TX_Pos)) /* Assigment of value for GEN_SR_1P_TX in the DSI_CMD_MODE_CFG register */
#define   DSI_CMD_MODE_CFG_GEN_SR_1P_TX_0_Val _UINT32_(0x0)                                        /* (DSI_CMD_MODE_CFG) High-speed.  */
#define   DSI_CMD_MODE_CFG_GEN_SR_1P_TX_1_Val _UINT32_(0x1)                                        /* (DSI_CMD_MODE_CFG) Low-power.  */
#define DSI_CMD_MODE_CFG_GEN_SR_1P_TX_0       (DSI_CMD_MODE_CFG_GEN_SR_1P_TX_0_Val << DSI_CMD_MODE_CFG_GEN_SR_1P_TX_Pos) /* (DSI_CMD_MODE_CFG) High-speed. Position  */
#define DSI_CMD_MODE_CFG_GEN_SR_1P_TX_1       (DSI_CMD_MODE_CFG_GEN_SR_1P_TX_1_Val << DSI_CMD_MODE_CFG_GEN_SR_1P_TX_Pos) /* (DSI_CMD_MODE_CFG) Low-power. Position  */
#define DSI_CMD_MODE_CFG_GEN_SR_2P_TX_Pos     _UINT32_(13)                                         /* (DSI_CMD_MODE_CFG) Generic Short Read Packet 2 Transmission Type Position */
#define DSI_CMD_MODE_CFG_GEN_SR_2P_TX_Msk     (_UINT32_(0x1) << DSI_CMD_MODE_CFG_GEN_SR_2P_TX_Pos) /* (DSI_CMD_MODE_CFG) Generic Short Read Packet 2 Transmission Type Mask */
#define DSI_CMD_MODE_CFG_GEN_SR_2P_TX(value)  (DSI_CMD_MODE_CFG_GEN_SR_2P_TX_Msk & (_UINT32_(value) << DSI_CMD_MODE_CFG_GEN_SR_2P_TX_Pos)) /* Assigment of value for GEN_SR_2P_TX in the DSI_CMD_MODE_CFG register */
#define   DSI_CMD_MODE_CFG_GEN_SR_2P_TX_0_Val _UINT32_(0x0)                                        /* (DSI_CMD_MODE_CFG) High-speed.  */
#define   DSI_CMD_MODE_CFG_GEN_SR_2P_TX_1_Val _UINT32_(0x1)                                        /* (DSI_CMD_MODE_CFG) Low-power.  */
#define DSI_CMD_MODE_CFG_GEN_SR_2P_TX_0       (DSI_CMD_MODE_CFG_GEN_SR_2P_TX_0_Val << DSI_CMD_MODE_CFG_GEN_SR_2P_TX_Pos) /* (DSI_CMD_MODE_CFG) High-speed. Position  */
#define DSI_CMD_MODE_CFG_GEN_SR_2P_TX_1       (DSI_CMD_MODE_CFG_GEN_SR_2P_TX_1_Val << DSI_CMD_MODE_CFG_GEN_SR_2P_TX_Pos) /* (DSI_CMD_MODE_CFG) Low-power. Position  */
#define DSI_CMD_MODE_CFG_GEN_LW_TX_Pos        _UINT32_(14)                                         /* (DSI_CMD_MODE_CFG) Generic Long Write Packet Transmission Type Position */
#define DSI_CMD_MODE_CFG_GEN_LW_TX_Msk        (_UINT32_(0x1) << DSI_CMD_MODE_CFG_GEN_LW_TX_Pos)    /* (DSI_CMD_MODE_CFG) Generic Long Write Packet Transmission Type Mask */
#define DSI_CMD_MODE_CFG_GEN_LW_TX(value)     (DSI_CMD_MODE_CFG_GEN_LW_TX_Msk & (_UINT32_(value) << DSI_CMD_MODE_CFG_GEN_LW_TX_Pos)) /* Assigment of value for GEN_LW_TX in the DSI_CMD_MODE_CFG register */
#define   DSI_CMD_MODE_CFG_GEN_LW_TX_0_Val    _UINT32_(0x0)                                        /* (DSI_CMD_MODE_CFG) High-speed.  */
#define   DSI_CMD_MODE_CFG_GEN_LW_TX_1_Val    _UINT32_(0x1)                                        /* (DSI_CMD_MODE_CFG) Low-power.  */
#define DSI_CMD_MODE_CFG_GEN_LW_TX_0          (DSI_CMD_MODE_CFG_GEN_LW_TX_0_Val << DSI_CMD_MODE_CFG_GEN_LW_TX_Pos) /* (DSI_CMD_MODE_CFG) High-speed. Position  */
#define DSI_CMD_MODE_CFG_GEN_LW_TX_1          (DSI_CMD_MODE_CFG_GEN_LW_TX_1_Val << DSI_CMD_MODE_CFG_GEN_LW_TX_Pos) /* (DSI_CMD_MODE_CFG) Low-power. Position  */
#define DSI_CMD_MODE_CFG_DCS_SW_0P_TX_Pos     _UINT32_(16)                                         /* (DSI_CMD_MODE_CFG) DCS Short Write Packet 0 Transmission Type Position */
#define DSI_CMD_MODE_CFG_DCS_SW_0P_TX_Msk     (_UINT32_(0x1) << DSI_CMD_MODE_CFG_DCS_SW_0P_TX_Pos) /* (DSI_CMD_MODE_CFG) DCS Short Write Packet 0 Transmission Type Mask */
#define DSI_CMD_MODE_CFG_DCS_SW_0P_TX(value)  (DSI_CMD_MODE_CFG_DCS_SW_0P_TX_Msk & (_UINT32_(value) << DSI_CMD_MODE_CFG_DCS_SW_0P_TX_Pos)) /* Assigment of value for DCS_SW_0P_TX in the DSI_CMD_MODE_CFG register */
#define   DSI_CMD_MODE_CFG_DCS_SW_0P_TX_0_Val _UINT32_(0x0)                                        /* (DSI_CMD_MODE_CFG) High-speed.  */
#define   DSI_CMD_MODE_CFG_DCS_SW_0P_TX_1_Val _UINT32_(0x1)                                        /* (DSI_CMD_MODE_CFG) Low-power.  */
#define DSI_CMD_MODE_CFG_DCS_SW_0P_TX_0       (DSI_CMD_MODE_CFG_DCS_SW_0P_TX_0_Val << DSI_CMD_MODE_CFG_DCS_SW_0P_TX_Pos) /* (DSI_CMD_MODE_CFG) High-speed. Position  */
#define DSI_CMD_MODE_CFG_DCS_SW_0P_TX_1       (DSI_CMD_MODE_CFG_DCS_SW_0P_TX_1_Val << DSI_CMD_MODE_CFG_DCS_SW_0P_TX_Pos) /* (DSI_CMD_MODE_CFG) Low-power. Position  */
#define DSI_CMD_MODE_CFG_DCS_SW_1P_TX_Pos     _UINT32_(17)                                         /* (DSI_CMD_MODE_CFG) DCS Short Write Packet 1 Transmission Type Position */
#define DSI_CMD_MODE_CFG_DCS_SW_1P_TX_Msk     (_UINT32_(0x1) << DSI_CMD_MODE_CFG_DCS_SW_1P_TX_Pos) /* (DSI_CMD_MODE_CFG) DCS Short Write Packet 1 Transmission Type Mask */
#define DSI_CMD_MODE_CFG_DCS_SW_1P_TX(value)  (DSI_CMD_MODE_CFG_DCS_SW_1P_TX_Msk & (_UINT32_(value) << DSI_CMD_MODE_CFG_DCS_SW_1P_TX_Pos)) /* Assigment of value for DCS_SW_1P_TX in the DSI_CMD_MODE_CFG register */
#define   DSI_CMD_MODE_CFG_DCS_SW_1P_TX_0_Val _UINT32_(0x0)                                        /* (DSI_CMD_MODE_CFG) High-speed.  */
#define   DSI_CMD_MODE_CFG_DCS_SW_1P_TX_1_Val _UINT32_(0x1)                                        /* (DSI_CMD_MODE_CFG) Low-power.  */
#define DSI_CMD_MODE_CFG_DCS_SW_1P_TX_0       (DSI_CMD_MODE_CFG_DCS_SW_1P_TX_0_Val << DSI_CMD_MODE_CFG_DCS_SW_1P_TX_Pos) /* (DSI_CMD_MODE_CFG) High-speed. Position  */
#define DSI_CMD_MODE_CFG_DCS_SW_1P_TX_1       (DSI_CMD_MODE_CFG_DCS_SW_1P_TX_1_Val << DSI_CMD_MODE_CFG_DCS_SW_1P_TX_Pos) /* (DSI_CMD_MODE_CFG) Low-power. Position  */
#define DSI_CMD_MODE_CFG_DCS_SR_0P_TX_Pos     _UINT32_(18)                                         /* (DSI_CMD_MODE_CFG) DCS Short Read Packet 0 Transmission Type Position */
#define DSI_CMD_MODE_CFG_DCS_SR_0P_TX_Msk     (_UINT32_(0x1) << DSI_CMD_MODE_CFG_DCS_SR_0P_TX_Pos) /* (DSI_CMD_MODE_CFG) DCS Short Read Packet 0 Transmission Type Mask */
#define DSI_CMD_MODE_CFG_DCS_SR_0P_TX(value)  (DSI_CMD_MODE_CFG_DCS_SR_0P_TX_Msk & (_UINT32_(value) << DSI_CMD_MODE_CFG_DCS_SR_0P_TX_Pos)) /* Assigment of value for DCS_SR_0P_TX in the DSI_CMD_MODE_CFG register */
#define   DSI_CMD_MODE_CFG_DCS_SR_0P_TX_0_Val _UINT32_(0x0)                                        /* (DSI_CMD_MODE_CFG) High-speed.  */
#define   DSI_CMD_MODE_CFG_DCS_SR_0P_TX_1_Val _UINT32_(0x1)                                        /* (DSI_CMD_MODE_CFG) Low-power.  */
#define DSI_CMD_MODE_CFG_DCS_SR_0P_TX_0       (DSI_CMD_MODE_CFG_DCS_SR_0P_TX_0_Val << DSI_CMD_MODE_CFG_DCS_SR_0P_TX_Pos) /* (DSI_CMD_MODE_CFG) High-speed. Position  */
#define DSI_CMD_MODE_CFG_DCS_SR_0P_TX_1       (DSI_CMD_MODE_CFG_DCS_SR_0P_TX_1_Val << DSI_CMD_MODE_CFG_DCS_SR_0P_TX_Pos) /* (DSI_CMD_MODE_CFG) Low-power. Position  */
#define DSI_CMD_MODE_CFG_DCS_LW_TX_Pos        _UINT32_(19)                                         /* (DSI_CMD_MODE_CFG) DCS Long Write Packet Transmission Type Position */
#define DSI_CMD_MODE_CFG_DCS_LW_TX_Msk        (_UINT32_(0x1) << DSI_CMD_MODE_CFG_DCS_LW_TX_Pos)    /* (DSI_CMD_MODE_CFG) DCS Long Write Packet Transmission Type Mask */
#define DSI_CMD_MODE_CFG_DCS_LW_TX(value)     (DSI_CMD_MODE_CFG_DCS_LW_TX_Msk & (_UINT32_(value) << DSI_CMD_MODE_CFG_DCS_LW_TX_Pos)) /* Assigment of value for DCS_LW_TX in the DSI_CMD_MODE_CFG register */
#define   DSI_CMD_MODE_CFG_DCS_LW_TX_0_Val    _UINT32_(0x0)                                        /* (DSI_CMD_MODE_CFG) High-speed.  */
#define   DSI_CMD_MODE_CFG_DCS_LW_TX_1_Val    _UINT32_(0x1)                                        /* (DSI_CMD_MODE_CFG) Low-power.  */
#define DSI_CMD_MODE_CFG_DCS_LW_TX_0          (DSI_CMD_MODE_CFG_DCS_LW_TX_0_Val << DSI_CMD_MODE_CFG_DCS_LW_TX_Pos) /* (DSI_CMD_MODE_CFG) High-speed. Position  */
#define DSI_CMD_MODE_CFG_DCS_LW_TX_1          (DSI_CMD_MODE_CFG_DCS_LW_TX_1_Val << DSI_CMD_MODE_CFG_DCS_LW_TX_Pos) /* (DSI_CMD_MODE_CFG) Low-power. Position  */
#define DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE_Pos  _UINT32_(24)                                         /* (DSI_CMD_MODE_CFG) Maximum Read Packet Size Position */
#define DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE_Msk  (_UINT32_(0x1) << DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE_Pos) /* (DSI_CMD_MODE_CFG) Maximum Read Packet Size Mask */
#define DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE(value) (DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE_Msk & (_UINT32_(value) << DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE_Pos)) /* Assigment of value for MAX_RD_PKT_SIZE in the DSI_CMD_MODE_CFG register */
#define   DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE_0_Val _UINT32_(0x0)                                        /* (DSI_CMD_MODE_CFG) High-speed.  */
#define   DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE_1_Val _UINT32_(0x1)                                        /* (DSI_CMD_MODE_CFG) Low-power.  */
#define DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE_0    (DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE_0_Val << DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE_Pos) /* (DSI_CMD_MODE_CFG) High-speed. Position  */
#define DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE_1    (DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE_1_Val << DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE_Pos) /* (DSI_CMD_MODE_CFG) Low-power. Position  */
#define DSI_CMD_MODE_CFG_Msk                  _UINT32_(0x010F7F03)                                 /* (DSI_CMD_MODE_CFG) Register Mask  */


/* -------- DSI_GEN_HDR : (DSI Offset: 0x6C) (R/W 32) Generic Interface Header Register -------- */
#define DSI_GEN_HDR_RESETVALUE                _UINT32_(0x00)                                       /*  (DSI_GEN_HDR) Generic Interface Header Register  Reset Value */

#define DSI_GEN_HDR_GEN_DT_Pos                _UINT32_(0)                                          /* (DSI_GEN_HDR) Generic Interface Data Type Position */
#define DSI_GEN_HDR_GEN_DT_Msk                (_UINT32_(0x3F) << DSI_GEN_HDR_GEN_DT_Pos)           /* (DSI_GEN_HDR) Generic Interface Data Type Mask */
#define DSI_GEN_HDR_GEN_DT(value)             (DSI_GEN_HDR_GEN_DT_Msk & (_UINT32_(value) << DSI_GEN_HDR_GEN_DT_Pos)) /* Assigment of value for GEN_DT in the DSI_GEN_HDR register */
#define DSI_GEN_HDR_GEN_VC_Pos                _UINT32_(6)                                          /* (DSI_GEN_HDR) Generic Interface Virtual Channel Position */
#define DSI_GEN_HDR_GEN_VC_Msk                (_UINT32_(0x3) << DSI_GEN_HDR_GEN_VC_Pos)            /* (DSI_GEN_HDR) Generic Interface Virtual Channel Mask */
#define DSI_GEN_HDR_GEN_VC(value)             (DSI_GEN_HDR_GEN_VC_Msk & (_UINT32_(value) << DSI_GEN_HDR_GEN_VC_Pos)) /* Assigment of value for GEN_VC in the DSI_GEN_HDR register */
#define DSI_GEN_HDR_GEN_WC_LSBYTE_Pos         _UINT32_(8)                                          /* (DSI_GEN_HDR) Generic Interface Word Count Least Significant Byte Position */
#define DSI_GEN_HDR_GEN_WC_LSBYTE_Msk         (_UINT32_(0xFF) << DSI_GEN_HDR_GEN_WC_LSBYTE_Pos)    /* (DSI_GEN_HDR) Generic Interface Word Count Least Significant Byte Mask */
#define DSI_GEN_HDR_GEN_WC_LSBYTE(value)      (DSI_GEN_HDR_GEN_WC_LSBYTE_Msk & (_UINT32_(value) << DSI_GEN_HDR_GEN_WC_LSBYTE_Pos)) /* Assigment of value for GEN_WC_LSBYTE in the DSI_GEN_HDR register */
#define DSI_GEN_HDR_GEN_WC_MSBYTE_Pos         _UINT32_(16)                                         /* (DSI_GEN_HDR) Generic Interface Word Count Most Significant Byte Position */
#define DSI_GEN_HDR_GEN_WC_MSBYTE_Msk         (_UINT32_(0xFF) << DSI_GEN_HDR_GEN_WC_MSBYTE_Pos)    /* (DSI_GEN_HDR) Generic Interface Word Count Most Significant Byte Mask */
#define DSI_GEN_HDR_GEN_WC_MSBYTE(value)      (DSI_GEN_HDR_GEN_WC_MSBYTE_Msk & (_UINT32_(value) << DSI_GEN_HDR_GEN_WC_MSBYTE_Pos)) /* Assigment of value for GEN_WC_MSBYTE in the DSI_GEN_HDR register */
#define DSI_GEN_HDR_Msk                       _UINT32_(0x00FFFFFF)                                 /* (DSI_GEN_HDR) Register Mask  */


/* -------- DSI_GEN_PLD_DATA : (DSI Offset: 0x70) (R/W 32) Generic Interface Payload Register -------- */
#define DSI_GEN_PLD_DATA_RESETVALUE           _UINT32_(0x00)                                       /*  (DSI_GEN_PLD_DATA) Generic Interface Payload Register  Reset Value */

#define DSI_GEN_PLD_DATA_GEN_PLD_B1_Pos       _UINT32_(0)                                          /* (DSI_GEN_PLD_DATA) Generic Interface Payload Byte 1 Position */
#define DSI_GEN_PLD_DATA_GEN_PLD_B1_Msk       (_UINT32_(0xFF) << DSI_GEN_PLD_DATA_GEN_PLD_B1_Pos)  /* (DSI_GEN_PLD_DATA) Generic Interface Payload Byte 1 Mask */
#define DSI_GEN_PLD_DATA_GEN_PLD_B1(value)    (DSI_GEN_PLD_DATA_GEN_PLD_B1_Msk & (_UINT32_(value) << DSI_GEN_PLD_DATA_GEN_PLD_B1_Pos)) /* Assigment of value for GEN_PLD_B1 in the DSI_GEN_PLD_DATA register */
#define DSI_GEN_PLD_DATA_GEN_PLD_B2_Pos       _UINT32_(8)                                          /* (DSI_GEN_PLD_DATA) Generic Interface Payload Byte 2 Position */
#define DSI_GEN_PLD_DATA_GEN_PLD_B2_Msk       (_UINT32_(0xFF) << DSI_GEN_PLD_DATA_GEN_PLD_B2_Pos)  /* (DSI_GEN_PLD_DATA) Generic Interface Payload Byte 2 Mask */
#define DSI_GEN_PLD_DATA_GEN_PLD_B2(value)    (DSI_GEN_PLD_DATA_GEN_PLD_B2_Msk & (_UINT32_(value) << DSI_GEN_PLD_DATA_GEN_PLD_B2_Pos)) /* Assigment of value for GEN_PLD_B2 in the DSI_GEN_PLD_DATA register */
#define DSI_GEN_PLD_DATA_GEN_PLD_B3_Pos       _UINT32_(16)                                         /* (DSI_GEN_PLD_DATA) Generic Interface Payload Byte 3 Position */
#define DSI_GEN_PLD_DATA_GEN_PLD_B3_Msk       (_UINT32_(0xFF) << DSI_GEN_PLD_DATA_GEN_PLD_B3_Pos)  /* (DSI_GEN_PLD_DATA) Generic Interface Payload Byte 3 Mask */
#define DSI_GEN_PLD_DATA_GEN_PLD_B3(value)    (DSI_GEN_PLD_DATA_GEN_PLD_B3_Msk & (_UINT32_(value) << DSI_GEN_PLD_DATA_GEN_PLD_B3_Pos)) /* Assigment of value for GEN_PLD_B3 in the DSI_GEN_PLD_DATA register */
#define DSI_GEN_PLD_DATA_GEN_PLD_B4_Pos       _UINT32_(24)                                         /* (DSI_GEN_PLD_DATA) Generic Interface Payload Byte 4 Position */
#define DSI_GEN_PLD_DATA_GEN_PLD_B4_Msk       (_UINT32_(0xFF) << DSI_GEN_PLD_DATA_GEN_PLD_B4_Pos)  /* (DSI_GEN_PLD_DATA) Generic Interface Payload Byte 4 Mask */
#define DSI_GEN_PLD_DATA_GEN_PLD_B4(value)    (DSI_GEN_PLD_DATA_GEN_PLD_B4_Msk & (_UINT32_(value) << DSI_GEN_PLD_DATA_GEN_PLD_B4_Pos)) /* Assigment of value for GEN_PLD_B4 in the DSI_GEN_PLD_DATA register */
#define DSI_GEN_PLD_DATA_Msk                  _UINT32_(0xFFFFFFFF)                                 /* (DSI_GEN_PLD_DATA) Register Mask  */


/* -------- DSI_CMD_PKT_STATUS : (DSI Offset: 0x74) ( R/ 32) Command Packet Status Register -------- */
#define DSI_CMD_PKT_STATUS_RESETVALUE         _UINT32_(0x00)                                       /*  (DSI_CMD_PKT_STATUS) Command Packet Status Register  Reset Value */

#define DSI_CMD_PKT_STATUS_GEN_CMD_EMPTY_Pos  _UINT32_(0)                                          /* (DSI_CMD_PKT_STATUS) Generic Interface Command FIFO Empty Position */
#define DSI_CMD_PKT_STATUS_GEN_CMD_EMPTY_Msk  (_UINT32_(0x1) << DSI_CMD_PKT_STATUS_GEN_CMD_EMPTY_Pos) /* (DSI_CMD_PKT_STATUS) Generic Interface Command FIFO Empty Mask */
#define DSI_CMD_PKT_STATUS_GEN_CMD_EMPTY(value) (DSI_CMD_PKT_STATUS_GEN_CMD_EMPTY_Msk & (_UINT32_(value) << DSI_CMD_PKT_STATUS_GEN_CMD_EMPTY_Pos)) /* Assigment of value for GEN_CMD_EMPTY in the DSI_CMD_PKT_STATUS register */
#define DSI_CMD_PKT_STATUS_GEN_CMD_FULL_Pos   _UINT32_(1)                                          /* (DSI_CMD_PKT_STATUS) Generic Interface Command FIFO Full Position */
#define DSI_CMD_PKT_STATUS_GEN_CMD_FULL_Msk   (_UINT32_(0x1) << DSI_CMD_PKT_STATUS_GEN_CMD_FULL_Pos) /* (DSI_CMD_PKT_STATUS) Generic Interface Command FIFO Full Mask */
#define DSI_CMD_PKT_STATUS_GEN_CMD_FULL(value) (DSI_CMD_PKT_STATUS_GEN_CMD_FULL_Msk & (_UINT32_(value) << DSI_CMD_PKT_STATUS_GEN_CMD_FULL_Pos)) /* Assigment of value for GEN_CMD_FULL in the DSI_CMD_PKT_STATUS register */
#define DSI_CMD_PKT_STATUS_GEN_PLD_W_EMPTY_Pos _UINT32_(2)                                          /* (DSI_CMD_PKT_STATUS) Generic Interface Write Payload FIFO Empty Position */
#define DSI_CMD_PKT_STATUS_GEN_PLD_W_EMPTY_Msk (_UINT32_(0x1) << DSI_CMD_PKT_STATUS_GEN_PLD_W_EMPTY_Pos) /* (DSI_CMD_PKT_STATUS) Generic Interface Write Payload FIFO Empty Mask */
#define DSI_CMD_PKT_STATUS_GEN_PLD_W_EMPTY(value) (DSI_CMD_PKT_STATUS_GEN_PLD_W_EMPTY_Msk & (_UINT32_(value) << DSI_CMD_PKT_STATUS_GEN_PLD_W_EMPTY_Pos)) /* Assigment of value for GEN_PLD_W_EMPTY in the DSI_CMD_PKT_STATUS register */
#define DSI_CMD_PKT_STATUS_GEN_PLD_W_FULL_Pos _UINT32_(3)                                          /* (DSI_CMD_PKT_STATUS) Generic Interface Write Payload FIFO Full Position */
#define DSI_CMD_PKT_STATUS_GEN_PLD_W_FULL_Msk (_UINT32_(0x1) << DSI_CMD_PKT_STATUS_GEN_PLD_W_FULL_Pos) /* (DSI_CMD_PKT_STATUS) Generic Interface Write Payload FIFO Full Mask */
#define DSI_CMD_PKT_STATUS_GEN_PLD_W_FULL(value) (DSI_CMD_PKT_STATUS_GEN_PLD_W_FULL_Msk & (_UINT32_(value) << DSI_CMD_PKT_STATUS_GEN_PLD_W_FULL_Pos)) /* Assigment of value for GEN_PLD_W_FULL in the DSI_CMD_PKT_STATUS register */
#define DSI_CMD_PKT_STATUS_GEN_PLD_R_EMPTY_Pos _UINT32_(4)                                          /* (DSI_CMD_PKT_STATUS) Generic Interface Read Payload FIFO Empty Position */
#define DSI_CMD_PKT_STATUS_GEN_PLD_R_EMPTY_Msk (_UINT32_(0x1) << DSI_CMD_PKT_STATUS_GEN_PLD_R_EMPTY_Pos) /* (DSI_CMD_PKT_STATUS) Generic Interface Read Payload FIFO Empty Mask */
#define DSI_CMD_PKT_STATUS_GEN_PLD_R_EMPTY(value) (DSI_CMD_PKT_STATUS_GEN_PLD_R_EMPTY_Msk & (_UINT32_(value) << DSI_CMD_PKT_STATUS_GEN_PLD_R_EMPTY_Pos)) /* Assigment of value for GEN_PLD_R_EMPTY in the DSI_CMD_PKT_STATUS register */
#define DSI_CMD_PKT_STATUS_GEN_PLD_R_FULL_Pos _UINT32_(5)                                          /* (DSI_CMD_PKT_STATUS) Generic Interface Read Payload FIFO Full Position */
#define DSI_CMD_PKT_STATUS_GEN_PLD_R_FULL_Msk (_UINT32_(0x1) << DSI_CMD_PKT_STATUS_GEN_PLD_R_FULL_Pos) /* (DSI_CMD_PKT_STATUS) Generic Interface Read Payload FIFO Full Mask */
#define DSI_CMD_PKT_STATUS_GEN_PLD_R_FULL(value) (DSI_CMD_PKT_STATUS_GEN_PLD_R_FULL_Msk & (_UINT32_(value) << DSI_CMD_PKT_STATUS_GEN_PLD_R_FULL_Pos)) /* Assigment of value for GEN_PLD_R_FULL in the DSI_CMD_PKT_STATUS register */
#define DSI_CMD_PKT_STATUS_GEN_RD_CMD_BUSY_Pos _UINT32_(6)                                          /* (DSI_CMD_PKT_STATUS) Generic Interface Read Command FIFO Busy Position */
#define DSI_CMD_PKT_STATUS_GEN_RD_CMD_BUSY_Msk (_UINT32_(0x1) << DSI_CMD_PKT_STATUS_GEN_RD_CMD_BUSY_Pos) /* (DSI_CMD_PKT_STATUS) Generic Interface Read Command FIFO Busy Mask */
#define DSI_CMD_PKT_STATUS_GEN_RD_CMD_BUSY(value) (DSI_CMD_PKT_STATUS_GEN_RD_CMD_BUSY_Msk & (_UINT32_(value) << DSI_CMD_PKT_STATUS_GEN_RD_CMD_BUSY_Pos)) /* Assigment of value for GEN_RD_CMD_BUSY in the DSI_CMD_PKT_STATUS register */
#define DSI_CMD_PKT_STATUS_GEN_BUFF_CMD_EMPTY_Pos _UINT32_(16)                                         /* (DSI_CMD_PKT_STATUS) Generic Command Internal Buffer Empty Position */
#define DSI_CMD_PKT_STATUS_GEN_BUFF_CMD_EMPTY_Msk (_UINT32_(0x1) << DSI_CMD_PKT_STATUS_GEN_BUFF_CMD_EMPTY_Pos) /* (DSI_CMD_PKT_STATUS) Generic Command Internal Buffer Empty Mask */
#define DSI_CMD_PKT_STATUS_GEN_BUFF_CMD_EMPTY(value) (DSI_CMD_PKT_STATUS_GEN_BUFF_CMD_EMPTY_Msk & (_UINT32_(value) << DSI_CMD_PKT_STATUS_GEN_BUFF_CMD_EMPTY_Pos)) /* Assigment of value for GEN_BUFF_CMD_EMPTY in the DSI_CMD_PKT_STATUS register */
#define DSI_CMD_PKT_STATUS_GEN_BUFF_CMD_FULL_Pos _UINT32_(17)                                         /* (DSI_CMD_PKT_STATUS) Generic Command Internal Buffer Full Position */
#define DSI_CMD_PKT_STATUS_GEN_BUFF_CMD_FULL_Msk (_UINT32_(0x1) << DSI_CMD_PKT_STATUS_GEN_BUFF_CMD_FULL_Pos) /* (DSI_CMD_PKT_STATUS) Generic Command Internal Buffer Full Mask */
#define DSI_CMD_PKT_STATUS_GEN_BUFF_CMD_FULL(value) (DSI_CMD_PKT_STATUS_GEN_BUFF_CMD_FULL_Msk & (_UINT32_(value) << DSI_CMD_PKT_STATUS_GEN_BUFF_CMD_FULL_Pos)) /* Assigment of value for GEN_BUFF_CMD_FULL in the DSI_CMD_PKT_STATUS register */
#define DSI_CMD_PKT_STATUS_GEN_BUFF_PLD_EMPTY_Pos _UINT32_(18)                                         /* (DSI_CMD_PKT_STATUS) Generic Payload Internal Buffer Empty Position */
#define DSI_CMD_PKT_STATUS_GEN_BUFF_PLD_EMPTY_Msk (_UINT32_(0x1) << DSI_CMD_PKT_STATUS_GEN_BUFF_PLD_EMPTY_Pos) /* (DSI_CMD_PKT_STATUS) Generic Payload Internal Buffer Empty Mask */
#define DSI_CMD_PKT_STATUS_GEN_BUFF_PLD_EMPTY(value) (DSI_CMD_PKT_STATUS_GEN_BUFF_PLD_EMPTY_Msk & (_UINT32_(value) << DSI_CMD_PKT_STATUS_GEN_BUFF_PLD_EMPTY_Pos)) /* Assigment of value for GEN_BUFF_PLD_EMPTY in the DSI_CMD_PKT_STATUS register */
#define DSI_CMD_PKT_STATUS_GEN_BUFF_PLD_FULL_Pos _UINT32_(19)                                         /* (DSI_CMD_PKT_STATUS) Generic Payload Internal Buffer Full Position */
#define DSI_CMD_PKT_STATUS_GEN_BUFF_PLD_FULL_Msk (_UINT32_(0x1) << DSI_CMD_PKT_STATUS_GEN_BUFF_PLD_FULL_Pos) /* (DSI_CMD_PKT_STATUS) Generic Payload Internal Buffer Full Mask */
#define DSI_CMD_PKT_STATUS_GEN_BUFF_PLD_FULL(value) (DSI_CMD_PKT_STATUS_GEN_BUFF_PLD_FULL_Msk & (_UINT32_(value) << DSI_CMD_PKT_STATUS_GEN_BUFF_PLD_FULL_Pos)) /* Assigment of value for GEN_BUFF_PLD_FULL in the DSI_CMD_PKT_STATUS register */
#define DSI_CMD_PKT_STATUS_Msk                _UINT32_(0x000F007F)                                 /* (DSI_CMD_PKT_STATUS) Register Mask  */


/* -------- DSI_TO_CNT_CFG : (DSI Offset: 0x78) (R/W 32) Timeout Counters Configuration Register -------- */
#define DSI_TO_CNT_CFG_RESETVALUE             _UINT32_(0x00)                                       /*  (DSI_TO_CNT_CFG) Timeout Counters Configuration Register  Reset Value */

#define DSI_TO_CNT_CFG_LPRX_TO_CNT_Pos        _UINT32_(0)                                          /* (DSI_TO_CNT_CFG) Low-Power Reception Timeout Counter Position */
#define DSI_TO_CNT_CFG_LPRX_TO_CNT_Msk        (_UINT32_(0xFFFF) << DSI_TO_CNT_CFG_LPRX_TO_CNT_Pos) /* (DSI_TO_CNT_CFG) Low-Power Reception Timeout Counter Mask */
#define DSI_TO_CNT_CFG_LPRX_TO_CNT(value)     (DSI_TO_CNT_CFG_LPRX_TO_CNT_Msk & (_UINT32_(value) << DSI_TO_CNT_CFG_LPRX_TO_CNT_Pos)) /* Assigment of value for LPRX_TO_CNT in the DSI_TO_CNT_CFG register */
#define DSI_TO_CNT_CFG_HSTX_TO_CNT_Pos        _UINT32_(16)                                         /* (DSI_TO_CNT_CFG) High-Speed Transmission Timeout Counter Position */
#define DSI_TO_CNT_CFG_HSTX_TO_CNT_Msk        (_UINT32_(0xFFFF) << DSI_TO_CNT_CFG_HSTX_TO_CNT_Pos) /* (DSI_TO_CNT_CFG) High-Speed Transmission Timeout Counter Mask */
#define DSI_TO_CNT_CFG_HSTX_TO_CNT(value)     (DSI_TO_CNT_CFG_HSTX_TO_CNT_Msk & (_UINT32_(value) << DSI_TO_CNT_CFG_HSTX_TO_CNT_Pos)) /* Assigment of value for HSTX_TO_CNT in the DSI_TO_CNT_CFG register */
#define DSI_TO_CNT_CFG_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (DSI_TO_CNT_CFG) Register Mask  */


/* -------- DSI_HS_RD_TO_CNT : (DSI Offset: 0x7C) (R/W 32) HS Read Response Timeout Counter Configuration Register -------- */
#define DSI_HS_RD_TO_CNT_RESETVALUE           _UINT32_(0x00)                                       /*  (DSI_HS_RD_TO_CNT) HS Read Response Timeout Counter Configuration Register  Reset Value */

#define DSI_HS_RD_TO_CNT_HS_RD_TO_CNT_Pos     _UINT32_(0)                                          /* (DSI_HS_RD_TO_CNT) High-Speed Read Operation Timeout Counter Position */
#define DSI_HS_RD_TO_CNT_HS_RD_TO_CNT_Msk     (_UINT32_(0xFFFF) << DSI_HS_RD_TO_CNT_HS_RD_TO_CNT_Pos) /* (DSI_HS_RD_TO_CNT) High-Speed Read Operation Timeout Counter Mask */
#define DSI_HS_RD_TO_CNT_HS_RD_TO_CNT(value)  (DSI_HS_RD_TO_CNT_HS_RD_TO_CNT_Msk & (_UINT32_(value) << DSI_HS_RD_TO_CNT_HS_RD_TO_CNT_Pos)) /* Assigment of value for HS_RD_TO_CNT in the DSI_HS_RD_TO_CNT register */
#define DSI_HS_RD_TO_CNT_Msk                  _UINT32_(0x0000FFFF)                                 /* (DSI_HS_RD_TO_CNT) Register Mask  */


/* -------- DSI_LP_RD_TO_CNT : (DSI Offset: 0x80) (R/W 32) LP Read Response Timeout Counter Configuration Register -------- */
#define DSI_LP_RD_TO_CNT_RESETVALUE           _UINT32_(0x00)                                       /*  (DSI_LP_RD_TO_CNT) LP Read Response Timeout Counter Configuration Register  Reset Value */

#define DSI_LP_RD_TO_CNT_LP_RD_TO_CNT_Pos     _UINT32_(0)                                          /* (DSI_LP_RD_TO_CNT) Low-Power Read Operation Timeout Counter Position */
#define DSI_LP_RD_TO_CNT_LP_RD_TO_CNT_Msk     (_UINT32_(0xFFFF) << DSI_LP_RD_TO_CNT_LP_RD_TO_CNT_Pos) /* (DSI_LP_RD_TO_CNT) Low-Power Read Operation Timeout Counter Mask */
#define DSI_LP_RD_TO_CNT_LP_RD_TO_CNT(value)  (DSI_LP_RD_TO_CNT_LP_RD_TO_CNT_Msk & (_UINT32_(value) << DSI_LP_RD_TO_CNT_LP_RD_TO_CNT_Pos)) /* Assigment of value for LP_RD_TO_CNT in the DSI_LP_RD_TO_CNT register */
#define DSI_LP_RD_TO_CNT_Msk                  _UINT32_(0x0000FFFF)                                 /* (DSI_LP_RD_TO_CNT) Register Mask  */


/* -------- DSI_HS_WR_TO_CNT : (DSI Offset: 0x84) (R/W 32) HS Write Response Timeout Counter Configuration Register -------- */
#define DSI_HS_WR_TO_CNT_RESETVALUE           _UINT32_(0x00)                                       /*  (DSI_HS_WR_TO_CNT) HS Write Response Timeout Counter Configuration Register  Reset Value */

#define DSI_HS_WR_TO_CNT_HS_WR_TO_CNT_Pos     _UINT32_(0)                                          /* (DSI_HS_WR_TO_CNT) High-Speed Write Operation Timeout Counter Position */
#define DSI_HS_WR_TO_CNT_HS_WR_TO_CNT_Msk     (_UINT32_(0xFFFF) << DSI_HS_WR_TO_CNT_HS_WR_TO_CNT_Pos) /* (DSI_HS_WR_TO_CNT) High-Speed Write Operation Timeout Counter Mask */
#define DSI_HS_WR_TO_CNT_HS_WR_TO_CNT(value)  (DSI_HS_WR_TO_CNT_HS_WR_TO_CNT_Msk & (_UINT32_(value) << DSI_HS_WR_TO_CNT_HS_WR_TO_CNT_Pos)) /* Assigment of value for HS_WR_TO_CNT in the DSI_HS_WR_TO_CNT register */
#define DSI_HS_WR_TO_CNT_Msk                  _UINT32_(0x0000FFFF)                                 /* (DSI_HS_WR_TO_CNT) Register Mask  */


/* -------- DSI_LP_WR_TO_CNT : (DSI Offset: 0x88) (R/W 32) LP Write Response Timeout Counter Configuration Register -------- */
#define DSI_LP_WR_TO_CNT_RESETVALUE           _UINT32_(0x00)                                       /*  (DSI_LP_WR_TO_CNT) LP Write Response Timeout Counter Configuration Register  Reset Value */

#define DSI_LP_WR_TO_CNT_LP_WR_TO_CNT_Pos     _UINT32_(0)                                          /* (DSI_LP_WR_TO_CNT) Low-Power Write Operation Timeout Counter Position */
#define DSI_LP_WR_TO_CNT_LP_WR_TO_CNT_Msk     (_UINT32_(0xFFFF) << DSI_LP_WR_TO_CNT_LP_WR_TO_CNT_Pos) /* (DSI_LP_WR_TO_CNT) Low-Power Write Operation Timeout Counter Mask */
#define DSI_LP_WR_TO_CNT_LP_WR_TO_CNT(value)  (DSI_LP_WR_TO_CNT_LP_WR_TO_CNT_Msk & (_UINT32_(value) << DSI_LP_WR_TO_CNT_LP_WR_TO_CNT_Pos)) /* Assigment of value for LP_WR_TO_CNT in the DSI_LP_WR_TO_CNT register */
#define DSI_LP_WR_TO_CNT_Msk                  _UINT32_(0x0000FFFF)                                 /* (DSI_LP_WR_TO_CNT) Register Mask  */


/* -------- DSI_BTA_TO_CNT : (DSI Offset: 0x8C) (R/W 32) BTA Response Timeout Counter Configuration Register -------- */
#define DSI_BTA_TO_CNT_RESETVALUE             _UINT32_(0x00)                                       /*  (DSI_BTA_TO_CNT) BTA Response Timeout Counter Configuration Register  Reset Value */

#define DSI_BTA_TO_CNT_BTA_TO_CNT_Pos         _UINT32_(0)                                          /* (DSI_BTA_TO_CNT) Bus Turn Around Timeout Counter Position */
#define DSI_BTA_TO_CNT_BTA_TO_CNT_Msk         (_UINT32_(0xFFFF) << DSI_BTA_TO_CNT_BTA_TO_CNT_Pos)  /* (DSI_BTA_TO_CNT) Bus Turn Around Timeout Counter Mask */
#define DSI_BTA_TO_CNT_BTA_TO_CNT(value)      (DSI_BTA_TO_CNT_BTA_TO_CNT_Msk & (_UINT32_(value) << DSI_BTA_TO_CNT_BTA_TO_CNT_Pos)) /* Assigment of value for BTA_TO_CNT in the DSI_BTA_TO_CNT register */
#define DSI_BTA_TO_CNT_Msk                    _UINT32_(0x0000FFFF)                                 /* (DSI_BTA_TO_CNT) Register Mask  */


/* -------- DSI_SDF_3D : (DSI Offset: 0x90) (R/W 32) VSS Packet 3D Control Register -------- */
#define DSI_SDF_3D_RESETVALUE                 _UINT32_(0x00)                                       /*  (DSI_SDF_3D) VSS Packet 3D Control Register  Reset Value */

#define DSI_SDF_3D_MODE_3D_Pos                _UINT32_(0)                                          /* (DSI_SDF_3D) 3D Mode Position */
#define DSI_SDF_3D_MODE_3D_Msk                (_UINT32_(0x3) << DSI_SDF_3D_MODE_3D_Pos)            /* (DSI_SDF_3D) 3D Mode Mask */
#define DSI_SDF_3D_MODE_3D(value)             (DSI_SDF_3D_MODE_3D_Msk & (_UINT32_(value) << DSI_SDF_3D_MODE_3D_Pos)) /* Assigment of value for MODE_3D in the DSI_SDF_3D register */
#define   DSI_SDF_3D_MODE_3D_0_Val            _UINT32_(0x0)                                        /* (DSI_SDF_3D) 3D mode off (2D mode on).  */
#define   DSI_SDF_3D_MODE_3D_1_Val            _UINT32_(0x1)                                        /* (DSI_SDF_3D) 3D mode on, portrait orientation.  */
#define   DSI_SDF_3D_MODE_3D_2_Val            _UINT32_(0x2)                                        /* (DSI_SDF_3D) 3D mode on, landscape orientation.  */
#define   DSI_SDF_3D_MODE_3D_3_Val            _UINT32_(0x3)                                        /* (DSI_SDF_3D) Reserved.  */
#define DSI_SDF_3D_MODE_3D_0                  (DSI_SDF_3D_MODE_3D_0_Val << DSI_SDF_3D_MODE_3D_Pos) /* (DSI_SDF_3D) 3D mode off (2D mode on). Position  */
#define DSI_SDF_3D_MODE_3D_1                  (DSI_SDF_3D_MODE_3D_1_Val << DSI_SDF_3D_MODE_3D_Pos) /* (DSI_SDF_3D) 3D mode on, portrait orientation. Position  */
#define DSI_SDF_3D_MODE_3D_2                  (DSI_SDF_3D_MODE_3D_2_Val << DSI_SDF_3D_MODE_3D_Pos) /* (DSI_SDF_3D) 3D mode on, landscape orientation. Position  */
#define DSI_SDF_3D_MODE_3D_3                  (DSI_SDF_3D_MODE_3D_3_Val << DSI_SDF_3D_MODE_3D_Pos) /* (DSI_SDF_3D) Reserved. Position  */
#define DSI_SDF_3D_FORMAT_3D_Pos              _UINT32_(2)                                          /* (DSI_SDF_3D) 3D Format Position */
#define DSI_SDF_3D_FORMAT_3D_Msk              (_UINT32_(0x3) << DSI_SDF_3D_FORMAT_3D_Pos)          /* (DSI_SDF_3D) 3D Format Mask */
#define DSI_SDF_3D_FORMAT_3D(value)           (DSI_SDF_3D_FORMAT_3D_Msk & (_UINT32_(value) << DSI_SDF_3D_FORMAT_3D_Pos)) /* Assigment of value for FORMAT_3D in the DSI_SDF_3D register */
#define   DSI_SDF_3D_FORMAT_3D_0_Val          _UINT32_(0x0)                                        /* (DSI_SDF_3D) Line (alternating lines of left and right data).  */
#define   DSI_SDF_3D_FORMAT_3D_1_Val          _UINT32_(0x1)                                        /* (DSI_SDF_3D) Frame (alternating frames of left and right data).  */
#define   DSI_SDF_3D_FORMAT_3D_2_Val          _UINT32_(0x2)                                        /* (DSI_SDF_3D) Pixel (alternating pixels of left and right data).  */
#define DSI_SDF_3D_FORMAT_3D_0                (DSI_SDF_3D_FORMAT_3D_0_Val << DSI_SDF_3D_FORMAT_3D_Pos) /* (DSI_SDF_3D) Line (alternating lines of left and right data). Position  */
#define DSI_SDF_3D_FORMAT_3D_1                (DSI_SDF_3D_FORMAT_3D_1_Val << DSI_SDF_3D_FORMAT_3D_Pos) /* (DSI_SDF_3D) Frame (alternating frames of left and right data). Position  */
#define DSI_SDF_3D_FORMAT_3D_2                (DSI_SDF_3D_FORMAT_3D_2_Val << DSI_SDF_3D_FORMAT_3D_Pos) /* (DSI_SDF_3D) Pixel (alternating pixels of left and right data). Position  */
#define DSI_SDF_3D_SECOND_VSYNC_Pos           _UINT32_(4)                                          /* (DSI_SDF_3D) Second Vertical Sync Enable Position */
#define DSI_SDF_3D_SECOND_VSYNC_Msk           (_UINT32_(0x1) << DSI_SDF_3D_SECOND_VSYNC_Pos)       /* (DSI_SDF_3D) Second Vertical Sync Enable Mask */
#define DSI_SDF_3D_SECOND_VSYNC(value)        (DSI_SDF_3D_SECOND_VSYNC_Msk & (_UINT32_(value) << DSI_SDF_3D_SECOND_VSYNC_Pos)) /* Assigment of value for SECOND_VSYNC in the DSI_SDF_3D register */
#define   DSI_SDF_3D_SECOND_VSYNC_0_Val       _UINT32_(0x0)                                        /* (DSI_SDF_3D) No sync pulses between left and right data.  */
#define   DSI_SDF_3D_SECOND_VSYNC_1_Val       _UINT32_(0x1)                                        /* (DSI_SDF_3D) Sync pulse (HSYNC, VSYNC, blanking) between left and right data.  */
#define DSI_SDF_3D_SECOND_VSYNC_0             (DSI_SDF_3D_SECOND_VSYNC_0_Val << DSI_SDF_3D_SECOND_VSYNC_Pos) /* (DSI_SDF_3D) No sync pulses between left and right data. Position  */
#define DSI_SDF_3D_SECOND_VSYNC_1             (DSI_SDF_3D_SECOND_VSYNC_1_Val << DSI_SDF_3D_SECOND_VSYNC_Pos) /* (DSI_SDF_3D) Sync pulse (HSYNC, VSYNC, blanking) between left and right data. Position  */
#define DSI_SDF_3D_RIGHT_FIRST_Pos            _UINT32_(5)                                          /* (DSI_SDF_3D) Right First Position */
#define DSI_SDF_3D_RIGHT_FIRST_Msk            (_UINT32_(0x1) << DSI_SDF_3D_RIGHT_FIRST_Pos)        /* (DSI_SDF_3D) Right First Mask */
#define DSI_SDF_3D_RIGHT_FIRST(value)         (DSI_SDF_3D_RIGHT_FIRST_Msk & (_UINT32_(value) << DSI_SDF_3D_RIGHT_FIRST_Pos)) /* Assigment of value for RIGHT_FIRST in the DSI_SDF_3D register */
#define   DSI_SDF_3D_RIGHT_FIRST_0_Val        _UINT32_(0x0)                                        /* (DSI_SDF_3D) Left eye is sent first, then right eye.  */
#define   DSI_SDF_3D_RIGHT_FIRST_1_Val        _UINT32_(0x1)                                        /* (DSI_SDF_3D) Right eye data is sent first, then left eye.  */
#define DSI_SDF_3D_RIGHT_FIRST_0              (DSI_SDF_3D_RIGHT_FIRST_0_Val << DSI_SDF_3D_RIGHT_FIRST_Pos) /* (DSI_SDF_3D) Left eye is sent first, then right eye. Position  */
#define DSI_SDF_3D_RIGHT_FIRST_1              (DSI_SDF_3D_RIGHT_FIRST_1_Val << DSI_SDF_3D_RIGHT_FIRST_Pos) /* (DSI_SDF_3D) Right eye data is sent first, then left eye. Position  */
#define DSI_SDF_3D_SEND_3D_CFG_Pos            _UINT32_(16)                                         /* (DSI_SDF_3D) Send 3D Configuration Enable Position */
#define DSI_SDF_3D_SEND_3D_CFG_Msk            (_UINT32_(0x1) << DSI_SDF_3D_SEND_3D_CFG_Pos)        /* (DSI_SDF_3D) Send 3D Configuration Enable Mask */
#define DSI_SDF_3D_SEND_3D_CFG(value)         (DSI_SDF_3D_SEND_3D_CFG_Msk & (_UINT32_(value) << DSI_SDF_3D_SEND_3D_CFG_Pos)) /* Assigment of value for SEND_3D_CFG in the DSI_SDF_3D register */
#define DSI_SDF_3D_Msk                        _UINT32_(0x0001003F)                                 /* (DSI_SDF_3D) Register Mask  */


/* -------- DSI_LPCLK_CTRL : (DSI Offset: 0x94) (R/W 32) Clock Lane Control Register -------- */
#define DSI_LPCLK_CTRL_RESETVALUE             _UINT32_(0x00)                                       /*  (DSI_LPCLK_CTRL) Clock Lane Control Register  Reset Value */

#define DSI_LPCLK_CTRL_PHY_TXREQUESTCLKHS_Pos _UINT32_(0)                                          /* (DSI_LPCLK_CTRL) D-PHY High-Speed Transmission Request Position */
#define DSI_LPCLK_CTRL_PHY_TXREQUESTCLKHS_Msk (_UINT32_(0x1) << DSI_LPCLK_CTRL_PHY_TXREQUESTCLKHS_Pos) /* (DSI_LPCLK_CTRL) D-PHY High-Speed Transmission Request Mask */
#define DSI_LPCLK_CTRL_PHY_TXREQUESTCLKHS(value) (DSI_LPCLK_CTRL_PHY_TXREQUESTCLKHS_Msk & (_UINT32_(value) << DSI_LPCLK_CTRL_PHY_TXREQUESTCLKHS_Pos)) /* Assigment of value for PHY_TXREQUESTCLKHS in the DSI_LPCLK_CTRL register */
#define   DSI_LPCLK_CTRL_PHY_TXREQUESTCLKHS_0_Val _UINT32_(0x0)                                        /* (DSI_LPCLK_CTRL) Disables High-Speed mode transmission request on clock lane.  */
#define   DSI_LPCLK_CTRL_PHY_TXREQUESTCLKHS_1_Val _UINT32_(0x1)                                        /* (DSI_LPCLK_CTRL) Enables High-Speed mode transmission request on clock lane.  */
#define DSI_LPCLK_CTRL_PHY_TXREQUESTCLKHS_0   (DSI_LPCLK_CTRL_PHY_TXREQUESTCLKHS_0_Val << DSI_LPCLK_CTRL_PHY_TXREQUESTCLKHS_Pos) /* (DSI_LPCLK_CTRL) Disables High-Speed mode transmission request on clock lane. Position  */
#define DSI_LPCLK_CTRL_PHY_TXREQUESTCLKHS_1   (DSI_LPCLK_CTRL_PHY_TXREQUESTCLKHS_1_Val << DSI_LPCLK_CTRL_PHY_TXREQUESTCLKHS_Pos) /* (DSI_LPCLK_CTRL) Enables High-Speed mode transmission request on clock lane. Position  */
#define DSI_LPCLK_CTRL_AUTO_CLKLANE_CTRL_Pos  _UINT32_(1)                                          /* (DSI_LPCLK_CTRL) Automatic Clock Lane Control Position */
#define DSI_LPCLK_CTRL_AUTO_CLKLANE_CTRL_Msk  (_UINT32_(0x1) << DSI_LPCLK_CTRL_AUTO_CLKLANE_CTRL_Pos) /* (DSI_LPCLK_CTRL) Automatic Clock Lane Control Mask */
#define DSI_LPCLK_CTRL_AUTO_CLKLANE_CTRL(value) (DSI_LPCLK_CTRL_AUTO_CLKLANE_CTRL_Msk & (_UINT32_(value) << DSI_LPCLK_CTRL_AUTO_CLKLANE_CTRL_Pos)) /* Assigment of value for AUTO_CLKLANE_CTRL in the DSI_LPCLK_CTRL register */
#define   DSI_LPCLK_CTRL_AUTO_CLKLANE_CTRL_0_Val _UINT32_(0x0)                                        /* (DSI_LPCLK_CTRL) Disables the automatic mechanism to stop providing the clock in the clock lane when time allows.  */
#define   DSI_LPCLK_CTRL_AUTO_CLKLANE_CTRL_1_Val _UINT32_(0x1)                                        /* (DSI_LPCLK_CTRL) Enables the automatic mechanism to stop providing clock in the clock lane when time allows.  */
#define DSI_LPCLK_CTRL_AUTO_CLKLANE_CTRL_0    (DSI_LPCLK_CTRL_AUTO_CLKLANE_CTRL_0_Val << DSI_LPCLK_CTRL_AUTO_CLKLANE_CTRL_Pos) /* (DSI_LPCLK_CTRL) Disables the automatic mechanism to stop providing the clock in the clock lane when time allows. Position  */
#define DSI_LPCLK_CTRL_AUTO_CLKLANE_CTRL_1    (DSI_LPCLK_CTRL_AUTO_CLKLANE_CTRL_1_Val << DSI_LPCLK_CTRL_AUTO_CLKLANE_CTRL_Pos) /* (DSI_LPCLK_CTRL) Enables the automatic mechanism to stop providing clock in the clock lane when time allows. Position  */
#define DSI_LPCLK_CTRL_Msk                    _UINT32_(0x00000003)                                 /* (DSI_LPCLK_CTRL) Register Mask  */


/* -------- DSI_DPHY_TMR_LPCLK_CFG : (DSI Offset: 0x98) (R/W 32) Clock Lane Switch Mode Timing Configuration Register -------- */
#define DSI_DPHY_TMR_LPCLK_CFG_RESETVALUE     _UINT32_(0x00)                                       /*  (DSI_DPHY_TMR_LPCLK_CFG) Clock Lane Switch Mode Timing Configuration Register  Reset Value */

#define DSI_DPHY_TMR_LPCLK_CFG_PHY_CLKLP2HS_TIME_Pos _UINT32_(0)                                          /* (DSI_DPHY_TMR_LPCLK_CFG) D-PHY Clock Low-Power to High-Speed Time Position */
#define DSI_DPHY_TMR_LPCLK_CFG_PHY_CLKLP2HS_TIME_Msk (_UINT32_(0x3FF) << DSI_DPHY_TMR_LPCLK_CFG_PHY_CLKLP2HS_TIME_Pos) /* (DSI_DPHY_TMR_LPCLK_CFG) D-PHY Clock Low-Power to High-Speed Time Mask */
#define DSI_DPHY_TMR_LPCLK_CFG_PHY_CLKLP2HS_TIME(value) (DSI_DPHY_TMR_LPCLK_CFG_PHY_CLKLP2HS_TIME_Msk & (_UINT32_(value) << DSI_DPHY_TMR_LPCLK_CFG_PHY_CLKLP2HS_TIME_Pos)) /* Assigment of value for PHY_CLKLP2HS_TIME in the DSI_DPHY_TMR_LPCLK_CFG register */
#define DSI_DPHY_TMR_LPCLK_CFG_PHY_CLKHS2LP_TIME_Pos _UINT32_(16)                                         /* (DSI_DPHY_TMR_LPCLK_CFG) D-PHY Clock High-Speed to Low-Power Time Position */
#define DSI_DPHY_TMR_LPCLK_CFG_PHY_CLKHS2LP_TIME_Msk (_UINT32_(0x3FF) << DSI_DPHY_TMR_LPCLK_CFG_PHY_CLKHS2LP_TIME_Pos) /* (DSI_DPHY_TMR_LPCLK_CFG) D-PHY Clock High-Speed to Low-Power Time Mask */
#define DSI_DPHY_TMR_LPCLK_CFG_PHY_CLKHS2LP_TIME(value) (DSI_DPHY_TMR_LPCLK_CFG_PHY_CLKHS2LP_TIME_Msk & (_UINT32_(value) << DSI_DPHY_TMR_LPCLK_CFG_PHY_CLKHS2LP_TIME_Pos)) /* Assigment of value for PHY_CLKHS2LP_TIME in the DSI_DPHY_TMR_LPCLK_CFG register */
#define DSI_DPHY_TMR_LPCLK_CFG_Msk            _UINT32_(0x03FF03FF)                                 /* (DSI_DPHY_TMR_LPCLK_CFG) Register Mask  */


/* -------- DSI_DPHY_TMR_CFG : (DSI Offset: 0x9C) (R/W 32) Data Lane Switch Mode Timing Configuration Register -------- */
#define DSI_DPHY_TMR_CFG_RESETVALUE           _UINT32_(0x00)                                       /*  (DSI_DPHY_TMR_CFG) Data Lane Switch Mode Timing Configuration Register  Reset Value */

#define DSI_DPHY_TMR_CFG_PHY_LP2HS_TIME_Pos   _UINT32_(0)                                          /* (DSI_DPHY_TMR_CFG) D-PHY Data Low-Power to High-Speed Time Position */
#define DSI_DPHY_TMR_CFG_PHY_LP2HS_TIME_Msk   (_UINT32_(0x3FF) << DSI_DPHY_TMR_CFG_PHY_LP2HS_TIME_Pos) /* (DSI_DPHY_TMR_CFG) D-PHY Data Low-Power to High-Speed Time Mask */
#define DSI_DPHY_TMR_CFG_PHY_LP2HS_TIME(value) (DSI_DPHY_TMR_CFG_PHY_LP2HS_TIME_Msk & (_UINT32_(value) << DSI_DPHY_TMR_CFG_PHY_LP2HS_TIME_Pos)) /* Assigment of value for PHY_LP2HS_TIME in the DSI_DPHY_TMR_CFG register */
#define DSI_DPHY_TMR_CFG_PHY_HS2LP_TIME_Pos   _UINT32_(16)                                         /* (DSI_DPHY_TMR_CFG) D-PHY Data High-Speed to Low-Power Time Position */
#define DSI_DPHY_TMR_CFG_PHY_HS2LP_TIME_Msk   (_UINT32_(0x3FF) << DSI_DPHY_TMR_CFG_PHY_HS2LP_TIME_Pos) /* (DSI_DPHY_TMR_CFG) D-PHY Data High-Speed to Low-Power Time Mask */
#define DSI_DPHY_TMR_CFG_PHY_HS2LP_TIME(value) (DSI_DPHY_TMR_CFG_PHY_HS2LP_TIME_Msk & (_UINT32_(value) << DSI_DPHY_TMR_CFG_PHY_HS2LP_TIME_Pos)) /* Assigment of value for PHY_HS2LP_TIME in the DSI_DPHY_TMR_CFG register */
#define DSI_DPHY_TMR_CFG_Msk                  _UINT32_(0x03FF03FF)                                 /* (DSI_DPHY_TMR_CFG) Register Mask  */


/* -------- DSI_DPHY_RSTZ : (DSI Offset: 0xA0) (R/W 32) Reset and PLL Control Register -------- */
#define DSI_DPHY_RSTZ_RESETVALUE              _UINT32_(0x00)                                       /*  (DSI_DPHY_RSTZ) Reset and PLL Control Register  Reset Value */

#define DSI_DPHY_RSTZ_DPHY_SHUTDOWNZ_Pos      _UINT32_(0)                                          /* (DSI_DPHY_RSTZ) D-PHY Shutdown Disable Position */
#define DSI_DPHY_RSTZ_DPHY_SHUTDOWNZ_Msk      (_UINT32_(0x1) << DSI_DPHY_RSTZ_DPHY_SHUTDOWNZ_Pos)  /* (DSI_DPHY_RSTZ) D-PHY Shutdown Disable Mask */
#define DSI_DPHY_RSTZ_DPHY_SHUTDOWNZ(value)   (DSI_DPHY_RSTZ_DPHY_SHUTDOWNZ_Msk & (_UINT32_(value) << DSI_DPHY_RSTZ_DPHY_SHUTDOWNZ_Pos)) /* Assigment of value for DPHY_SHUTDOWNZ in the DSI_DPHY_RSTZ register */
#define   DSI_DPHY_RSTZ_DPHY_SHUTDOWNZ_0_Val  _UINT32_(0x0)                                        /* (DSI_DPHY_RSTZ) Places the complete D-PHY macro in power-down state.  */
#define   DSI_DPHY_RSTZ_DPHY_SHUTDOWNZ_1_Val  _UINT32_(0x1)                                        /* (DSI_DPHY_RSTZ) Allow the complete D-PHY macro to leave power-down state.  */
#define DSI_DPHY_RSTZ_DPHY_SHUTDOWNZ_0        (DSI_DPHY_RSTZ_DPHY_SHUTDOWNZ_0_Val << DSI_DPHY_RSTZ_DPHY_SHUTDOWNZ_Pos) /* (DSI_DPHY_RSTZ) Places the complete D-PHY macro in power-down state. Position  */
#define DSI_DPHY_RSTZ_DPHY_SHUTDOWNZ_1        (DSI_DPHY_RSTZ_DPHY_SHUTDOWNZ_1_Val << DSI_DPHY_RSTZ_DPHY_SHUTDOWNZ_Pos) /* (DSI_DPHY_RSTZ) Allow the complete D-PHY macro to leave power-down state. Position  */
#define DSI_DPHY_RSTZ_DPHY_RSTZ_Pos           _UINT32_(1)                                          /* (DSI_DPHY_RSTZ) D-PHY Reset Disable Position */
#define DSI_DPHY_RSTZ_DPHY_RSTZ_Msk           (_UINT32_(0x1) << DSI_DPHY_RSTZ_DPHY_RSTZ_Pos)       /* (DSI_DPHY_RSTZ) D-PHY Reset Disable Mask */
#define DSI_DPHY_RSTZ_DPHY_RSTZ(value)        (DSI_DPHY_RSTZ_DPHY_RSTZ_Msk & (_UINT32_(value) << DSI_DPHY_RSTZ_DPHY_RSTZ_Pos)) /* Assigment of value for DPHY_RSTZ in the DSI_DPHY_RSTZ register */
#define   DSI_DPHY_RSTZ_DPHY_RSTZ_0_Val       _UINT32_(0x0)                                        /* (DSI_DPHY_RSTZ) Places the digital section of the D-PHY in the reset state.  */
#define   DSI_DPHY_RSTZ_DPHY_RSTZ_1_Val       _UINT32_(0x1)                                        /* (DSI_DPHY_RSTZ) Allows the digital section of the D-PHY to leave the reset state.  */
#define DSI_DPHY_RSTZ_DPHY_RSTZ_0             (DSI_DPHY_RSTZ_DPHY_RSTZ_0_Val << DSI_DPHY_RSTZ_DPHY_RSTZ_Pos) /* (DSI_DPHY_RSTZ) Places the digital section of the D-PHY in the reset state. Position  */
#define DSI_DPHY_RSTZ_DPHY_RSTZ_1             (DSI_DPHY_RSTZ_DPHY_RSTZ_1_Val << DSI_DPHY_RSTZ_DPHY_RSTZ_Pos) /* (DSI_DPHY_RSTZ) Allows the digital section of the D-PHY to leave the reset state. Position  */
#define DSI_DPHY_RSTZ_DPHY_ENABLECLK_Pos      _UINT32_(2)                                          /* (DSI_DPHY_RSTZ) D-PHY Enable Clock Lane Position */
#define DSI_DPHY_RSTZ_DPHY_ENABLECLK_Msk      (_UINT32_(0x1) << DSI_DPHY_RSTZ_DPHY_ENABLECLK_Pos)  /* (DSI_DPHY_RSTZ) D-PHY Enable Clock Lane Mask */
#define DSI_DPHY_RSTZ_DPHY_ENABLECLK(value)   (DSI_DPHY_RSTZ_DPHY_ENABLECLK_Msk & (_UINT32_(value) << DSI_DPHY_RSTZ_DPHY_ENABLECLK_Pos)) /* Assigment of value for DPHY_ENABLECLK in the DSI_DPHY_RSTZ register */
#define   DSI_DPHY_RSTZ_DPHY_ENABLECLK_0_Val  _UINT32_(0x0)                                        /* (DSI_DPHY_RSTZ) Disables the D-PHY clock lane module.  */
#define   DSI_DPHY_RSTZ_DPHY_ENABLECLK_1_Val  _UINT32_(0x1)                                        /* (DSI_DPHY_RSTZ) Enables the D-PHY clock lane module.  */
#define DSI_DPHY_RSTZ_DPHY_ENABLECLK_0        (DSI_DPHY_RSTZ_DPHY_ENABLECLK_0_Val << DSI_DPHY_RSTZ_DPHY_ENABLECLK_Pos) /* (DSI_DPHY_RSTZ) Disables the D-PHY clock lane module. Position  */
#define DSI_DPHY_RSTZ_DPHY_ENABLECLK_1        (DSI_DPHY_RSTZ_DPHY_ENABLECLK_1_Val << DSI_DPHY_RSTZ_DPHY_ENABLECLK_Pos) /* (DSI_DPHY_RSTZ) Enables the D-PHY clock lane module. Position  */
#define DSI_DPHY_RSTZ_DPHY_FORCEPLL_Pos       _UINT32_(3)                                          /* (DSI_DPHY_RSTZ) D-PHY Force PLL Enable Position */
#define DSI_DPHY_RSTZ_DPHY_FORCEPLL_Msk       (_UINT32_(0x1) << DSI_DPHY_RSTZ_DPHY_FORCEPLL_Pos)   /* (DSI_DPHY_RSTZ) D-PHY Force PLL Enable Mask */
#define DSI_DPHY_RSTZ_DPHY_FORCEPLL(value)    (DSI_DPHY_RSTZ_DPHY_FORCEPLL_Msk & (_UINT32_(value) << DSI_DPHY_RSTZ_DPHY_FORCEPLL_Pos)) /* Assigment of value for DPHY_FORCEPLL in the DSI_DPHY_RSTZ register */
#define   DSI_DPHY_RSTZ_DPHY_FORCEPLL_0_Val   _UINT32_(0x0)                                        /* (DSI_DPHY_RSTZ) Disables the D-PHY PLL when the D-PHY is in ULPS.  */
#define   DSI_DPHY_RSTZ_DPHY_FORCEPLL_1_Val   _UINT32_(0x1)                                        /* (DSI_DPHY_RSTZ) Enables the D-PHY PLL when the D-PHY is in ULPS.  */
#define DSI_DPHY_RSTZ_DPHY_FORCEPLL_0         (DSI_DPHY_RSTZ_DPHY_FORCEPLL_0_Val << DSI_DPHY_RSTZ_DPHY_FORCEPLL_Pos) /* (DSI_DPHY_RSTZ) Disables the D-PHY PLL when the D-PHY is in ULPS. Position  */
#define DSI_DPHY_RSTZ_DPHY_FORCEPLL_1         (DSI_DPHY_RSTZ_DPHY_FORCEPLL_1_Val << DSI_DPHY_RSTZ_DPHY_FORCEPLL_Pos) /* (DSI_DPHY_RSTZ) Enables the D-PHY PLL when the D-PHY is in ULPS. Position  */
#define DSI_DPHY_RSTZ_Msk                     _UINT32_(0x0000000F)                                 /* (DSI_DPHY_RSTZ) Register Mask  */


/* -------- DSI_DPHY_IF_CFG : (DSI Offset: 0xA4) (R/W 32) D-PHY Interface Configuration Register -------- */
#define DSI_DPHY_IF_CFG_RESETVALUE            _UINT32_(0x00)                                       /*  (DSI_DPHY_IF_CFG) D-PHY Interface Configuration Register  Reset Value */

#define DSI_DPHY_IF_CFG_N_LANES_Pos           _UINT32_(0)                                          /* (DSI_DPHY_IF_CFG) Number of Active Data Lanes Position */
#define DSI_DPHY_IF_CFG_N_LANES_Msk           (_UINT32_(0x3) << DSI_DPHY_IF_CFG_N_LANES_Pos)       /* (DSI_DPHY_IF_CFG) Number of Active Data Lanes Mask */
#define DSI_DPHY_IF_CFG_N_LANES(value)        (DSI_DPHY_IF_CFG_N_LANES_Msk & (_UINT32_(value) << DSI_DPHY_IF_CFG_N_LANES_Pos)) /* Assigment of value for N_LANES in the DSI_DPHY_IF_CFG register */
#define   DSI_DPHY_IF_CFG_N_LANES_0_Val       _UINT32_(0x0)                                        /* (DSI_DPHY_IF_CFG) One data lane (lane 0)  */
#define   DSI_DPHY_IF_CFG_N_LANES_1_Val       _UINT32_(0x1)                                        /* (DSI_DPHY_IF_CFG) Two data lanes (lanes 0 and 1)  */
#define   DSI_DPHY_IF_CFG_N_LANES_2_Val       _UINT32_(0x2)                                        /* (DSI_DPHY_IF_CFG) Three data lanes (lanes 0, 1, and 2)  */
#define   DSI_DPHY_IF_CFG_N_LANES_3_Val       _UINT32_(0x3)                                        /* (DSI_DPHY_IF_CFG) Four data lanes (lanes 0, 1, 2, and 3)  */
#define DSI_DPHY_IF_CFG_N_LANES_0             (DSI_DPHY_IF_CFG_N_LANES_0_Val << DSI_DPHY_IF_CFG_N_LANES_Pos) /* (DSI_DPHY_IF_CFG) One data lane (lane 0) Position  */
#define DSI_DPHY_IF_CFG_N_LANES_1             (DSI_DPHY_IF_CFG_N_LANES_1_Val << DSI_DPHY_IF_CFG_N_LANES_Pos) /* (DSI_DPHY_IF_CFG) Two data lanes (lanes 0 and 1) Position  */
#define DSI_DPHY_IF_CFG_N_LANES_2             (DSI_DPHY_IF_CFG_N_LANES_2_Val << DSI_DPHY_IF_CFG_N_LANES_Pos) /* (DSI_DPHY_IF_CFG) Three data lanes (lanes 0, 1, and 2) Position  */
#define DSI_DPHY_IF_CFG_N_LANES_3             (DSI_DPHY_IF_CFG_N_LANES_3_Val << DSI_DPHY_IF_CFG_N_LANES_Pos) /* (DSI_DPHY_IF_CFG) Four data lanes (lanes 0, 1, 2, and 3) Position  */
#define DSI_DPHY_IF_CFG_PHY_STOP_WAIT_TIME_Pos _UINT32_(8)                                          /* (DSI_DPHY_IF_CFG) D-PHY Stop State Wait Time Position */
#define DSI_DPHY_IF_CFG_PHY_STOP_WAIT_TIME_Msk (_UINT32_(0xFF) << DSI_DPHY_IF_CFG_PHY_STOP_WAIT_TIME_Pos) /* (DSI_DPHY_IF_CFG) D-PHY Stop State Wait Time Mask */
#define DSI_DPHY_IF_CFG_PHY_STOP_WAIT_TIME(value) (DSI_DPHY_IF_CFG_PHY_STOP_WAIT_TIME_Msk & (_UINT32_(value) << DSI_DPHY_IF_CFG_PHY_STOP_WAIT_TIME_Pos)) /* Assigment of value for PHY_STOP_WAIT_TIME in the DSI_DPHY_IF_CFG register */
#define DSI_DPHY_IF_CFG_Msk                   _UINT32_(0x0000FF03)                                 /* (DSI_DPHY_IF_CFG) Register Mask  */


/* -------- DSI_DPHY_ULPS_CTRL : (DSI Offset: 0xA8) (R/W 32) D-PHY ULPS Control Register -------- */
#define DSI_DPHY_ULPS_CTRL_RESETVALUE         _UINT32_(0x00)                                       /*  (DSI_DPHY_ULPS_CTRL) D-PHY ULPS Control Register  Reset Value */

#define DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSCLK_Pos _UINT32_(0)                                          /* (DSI_DPHY_ULPS_CTRL) D-PHY Ultra-Low-Power Request Transmission on Clock Lane Position */
#define DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSCLK_Msk (_UINT32_(0x1) << DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSCLK_Pos) /* (DSI_DPHY_ULPS_CTRL) D-PHY Ultra-Low-Power Request Transmission on Clock Lane Mask */
#define DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSCLK(value) (DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSCLK_Msk & (_UINT32_(value) << DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSCLK_Pos)) /* Assigment of value for PHY_TXREQULPSCLK in the DSI_DPHY_ULPS_CTRL register */
#define   DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSCLK_0_Val _UINT32_(0x0)                                        /* (DSI_DPHY_ULPS_CTRL) No effect.  */
#define   DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSCLK_1_Val _UINT32_(0x1)                                        /* (DSI_DPHY_ULPS_CTRL) ULPS mode request on clock lane.  */
#define DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSCLK_0 (DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSCLK_0_Val << DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSCLK_Pos) /* (DSI_DPHY_ULPS_CTRL) No effect. Position  */
#define DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSCLK_1 (DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSCLK_1_Val << DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSCLK_Pos) /* (DSI_DPHY_ULPS_CTRL) ULPS mode request on clock lane. Position  */
#define DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSCLK_Pos _UINT32_(1)                                          /* (DSI_DPHY_ULPS_CTRL) D-PHY Ultra-Low-Power Exit Transmission on Clock Lane Position */
#define DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSCLK_Msk (_UINT32_(0x1) << DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSCLK_Pos) /* (DSI_DPHY_ULPS_CTRL) D-PHY Ultra-Low-Power Exit Transmission on Clock Lane Mask */
#define DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSCLK(value) (DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSCLK_Msk & (_UINT32_(value) << DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSCLK_Pos)) /* Assigment of value for PHY_TXEXITULPSCLK in the DSI_DPHY_ULPS_CTRL register */
#define   DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSCLK_0_Val _UINT32_(0x0)                                        /* (DSI_DPHY_ULPS_CTRL) No effect.  */
#define   DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSCLK_1_Val _UINT32_(0x1)                                        /* (DSI_DPHY_ULPS_CTRL) ULPS mode exit on clock lane.  */
#define DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSCLK_0 (DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSCLK_0_Val << DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSCLK_Pos) /* (DSI_DPHY_ULPS_CTRL) No effect. Position  */
#define DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSCLK_1 (DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSCLK_1_Val << DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSCLK_Pos) /* (DSI_DPHY_ULPS_CTRL) ULPS mode exit on clock lane. Position  */
#define DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSLAN_Pos _UINT32_(2)                                          /* (DSI_DPHY_ULPS_CTRL) D-PHY Ultra-Low-Power Request Transmission on Data Lane Position */
#define DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSLAN_Msk (_UINT32_(0x1) << DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSLAN_Pos) /* (DSI_DPHY_ULPS_CTRL) D-PHY Ultra-Low-Power Request Transmission on Data Lane Mask */
#define DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSLAN(value) (DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSLAN_Msk & (_UINT32_(value) << DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSLAN_Pos)) /* Assigment of value for PHY_TXREQULPSLAN in the DSI_DPHY_ULPS_CTRL register */
#define   DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSLAN_0_Val _UINT32_(0x0)                                        /* (DSI_DPHY_ULPS_CTRL) No effect.  */
#define   DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSLAN_1_Val _UINT32_(0x1)                                        /* (DSI_DPHY_ULPS_CTRL) ULPS mode request on data lane.  */
#define DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSLAN_0 (DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSLAN_0_Val << DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSLAN_Pos) /* (DSI_DPHY_ULPS_CTRL) No effect. Position  */
#define DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSLAN_1 (DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSLAN_1_Val << DSI_DPHY_ULPS_CTRL_PHY_TXREQULPSLAN_Pos) /* (DSI_DPHY_ULPS_CTRL) ULPS mode request on data lane. Position  */
#define DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSLAN_Pos _UINT32_(3)                                          /* (DSI_DPHY_ULPS_CTRL) D-PHY Ultra-Low-Power Exit Transmission on Data Lane Position */
#define DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSLAN_Msk (_UINT32_(0x1) << DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSLAN_Pos) /* (DSI_DPHY_ULPS_CTRL) D-PHY Ultra-Low-Power Exit Transmission on Data Lane Mask */
#define DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSLAN(value) (DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSLAN_Msk & (_UINT32_(value) << DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSLAN_Pos)) /* Assigment of value for PHY_TXEXITULPSLAN in the DSI_DPHY_ULPS_CTRL register */
#define   DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSLAN_0_Val _UINT32_(0x0)                                        /* (DSI_DPHY_ULPS_CTRL) No effect.  */
#define   DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSLAN_1_Val _UINT32_(0x1)                                        /* (DSI_DPHY_ULPS_CTRL) ULPS mode exit on clock lane.  */
#define DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSLAN_0 (DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSLAN_0_Val << DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSLAN_Pos) /* (DSI_DPHY_ULPS_CTRL) No effect. Position  */
#define DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSLAN_1 (DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSLAN_1_Val << DSI_DPHY_ULPS_CTRL_PHY_TXEXITULPSLAN_Pos) /* (DSI_DPHY_ULPS_CTRL) ULPS mode exit on clock lane. Position  */
#define DSI_DPHY_ULPS_CTRL_Msk                _UINT32_(0x0000000F)                                 /* (DSI_DPHY_ULPS_CTRL) Register Mask  */


/* -------- DSI_DPHY_TX_TRIGGERS : (DSI Offset: 0xAC) (R/W 32) D-PHY Tx Trigger Control Register -------- */
#define DSI_DPHY_TX_TRIGGERS_RESETVALUE       _UINT32_(0x00)                                       /*  (DSI_DPHY_TX_TRIGGERS) D-PHY Tx Trigger Control Register  Reset Value */

#define DSI_DPHY_TX_TRIGGERS_PHY_TX_TRIGGERS_Pos _UINT32_(0)                                          /* (DSI_DPHY_TX_TRIGGERS) D-PHY Trigger Transmission Position */
#define DSI_DPHY_TX_TRIGGERS_PHY_TX_TRIGGERS_Msk (_UINT32_(0xF) << DSI_DPHY_TX_TRIGGERS_PHY_TX_TRIGGERS_Pos) /* (DSI_DPHY_TX_TRIGGERS) D-PHY Trigger Transmission Mask */
#define DSI_DPHY_TX_TRIGGERS_PHY_TX_TRIGGERS(value) (DSI_DPHY_TX_TRIGGERS_PHY_TX_TRIGGERS_Msk & (_UINT32_(value) << DSI_DPHY_TX_TRIGGERS_PHY_TX_TRIGGERS_Pos)) /* Assigment of value for PHY_TX_TRIGGERS in the DSI_DPHY_TX_TRIGGERS register */
#define DSI_DPHY_TX_TRIGGERS_Msk              _UINT32_(0x0000000F)                                 /* (DSI_DPHY_TX_TRIGGERS) Register Mask  */


/* -------- DSI_DPHY_STATUS : (DSI Offset: 0xB0) ( R/ 32) D-PHY Status Register -------- */
#define DSI_DPHY_STATUS_RESETVALUE            _UINT32_(0x00)                                       /*  (DSI_DPHY_STATUS) D-PHY Status Register  Reset Value */

#define DSI_DPHY_STATUS_PHY_LOCK_Pos          _UINT32_(0)                                          /* (DSI_DPHY_STATUS) D-PHY Lock Status Position */
#define DSI_DPHY_STATUS_PHY_LOCK_Msk          (_UINT32_(0x1) << DSI_DPHY_STATUS_PHY_LOCK_Pos)      /* (DSI_DPHY_STATUS) D-PHY Lock Status Mask */
#define DSI_DPHY_STATUS_PHY_LOCK(value)       (DSI_DPHY_STATUS_PHY_LOCK_Msk & (_UINT32_(value) << DSI_DPHY_STATUS_PHY_LOCK_Pos)) /* Assigment of value for PHY_LOCK in the DSI_DPHY_STATUS register */
#define DSI_DPHY_STATUS_PHY_DIRECTION_Pos     _UINT32_(1)                                          /* (DSI_DPHY_STATUS) D-PHY Direction Status Position */
#define DSI_DPHY_STATUS_PHY_DIRECTION_Msk     (_UINT32_(0x1) << DSI_DPHY_STATUS_PHY_DIRECTION_Pos) /* (DSI_DPHY_STATUS) D-PHY Direction Status Mask */
#define DSI_DPHY_STATUS_PHY_DIRECTION(value)  (DSI_DPHY_STATUS_PHY_DIRECTION_Msk & (_UINT32_(value) << DSI_DPHY_STATUS_PHY_DIRECTION_Pos)) /* Assigment of value for PHY_DIRECTION in the DSI_DPHY_STATUS register */
#define   DSI_DPHY_STATUS_PHY_DIRECTION_0_Val _UINT32_(0x0)                                        /* (DSI_DPHY_STATUS) The lane interconnect is in Transmit mode.  */
#define   DSI_DPHY_STATUS_PHY_DIRECTION_1_Val _UINT32_(0x1)                                        /* (DSI_DPHY_STATUS) The lane interconnect is in Receive mode.  */
#define DSI_DPHY_STATUS_PHY_DIRECTION_0       (DSI_DPHY_STATUS_PHY_DIRECTION_0_Val << DSI_DPHY_STATUS_PHY_DIRECTION_Pos) /* (DSI_DPHY_STATUS) The lane interconnect is in Transmit mode. Position  */
#define DSI_DPHY_STATUS_PHY_DIRECTION_1       (DSI_DPHY_STATUS_PHY_DIRECTION_1_Val << DSI_DPHY_STATUS_PHY_DIRECTION_Pos) /* (DSI_DPHY_STATUS) The lane interconnect is in Receive mode. Position  */
#define DSI_DPHY_STATUS_PHY_STOPSTATECLKLANE_Pos _UINT32_(2)                                          /* (DSI_DPHY_STATUS) D-PHY Stop State Clock Lane Status Position */
#define DSI_DPHY_STATUS_PHY_STOPSTATECLKLANE_Msk (_UINT32_(0x1) << DSI_DPHY_STATUS_PHY_STOPSTATECLKLANE_Pos) /* (DSI_DPHY_STATUS) D-PHY Stop State Clock Lane Status Mask */
#define DSI_DPHY_STATUS_PHY_STOPSTATECLKLANE(value) (DSI_DPHY_STATUS_PHY_STOPSTATECLKLANE_Msk & (_UINT32_(value) << DSI_DPHY_STATUS_PHY_STOPSTATECLKLANE_Pos)) /* Assigment of value for PHY_STOPSTATECLKLANE in the DSI_DPHY_STATUS register */
#define   DSI_DPHY_STATUS_PHY_STOPSTATECLKLANE_0_Val _UINT32_(0x0)                                        /* (DSI_DPHY_STATUS) The clock lane module is not in Stop state.  */
#define   DSI_DPHY_STATUS_PHY_STOPSTATECLKLANE_1_Val _UINT32_(0x1)                                        /* (DSI_DPHY_STATUS) The clock lane module is in Stop state.  */
#define DSI_DPHY_STATUS_PHY_STOPSTATECLKLANE_0 (DSI_DPHY_STATUS_PHY_STOPSTATECLKLANE_0_Val << DSI_DPHY_STATUS_PHY_STOPSTATECLKLANE_Pos) /* (DSI_DPHY_STATUS) The clock lane module is not in Stop state. Position  */
#define DSI_DPHY_STATUS_PHY_STOPSTATECLKLANE_1 (DSI_DPHY_STATUS_PHY_STOPSTATECLKLANE_1_Val << DSI_DPHY_STATUS_PHY_STOPSTATECLKLANE_Pos) /* (DSI_DPHY_STATUS) The clock lane module is in Stop state. Position  */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOTCLK_Pos _UINT32_(3)                                          /* (DSI_DPHY_STATUS) D-PHY Ultra-Low-Power State Active on Clock Lane Status Position */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOTCLK_Msk (_UINT32_(0x1) << DSI_DPHY_STATUS_PHY_ULPSACTIVENOTCLK_Pos) /* (DSI_DPHY_STATUS) D-PHY Ultra-Low-Power State Active on Clock Lane Status Mask */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOTCLK(value) (DSI_DPHY_STATUS_PHY_ULPSACTIVENOTCLK_Msk & (_UINT32_(value) << DSI_DPHY_STATUS_PHY_ULPSACTIVENOTCLK_Pos)) /* Assigment of value for PHY_ULPSACTIVENOTCLK in the DSI_DPHY_STATUS register */
#define   DSI_DPHY_STATUS_PHY_ULPSACTIVENOTCLK_0_Val _UINT32_(0x0)                                        /* (DSI_DPHY_STATUS) The clock lane is in Ultra-Low-Power state.  */
#define   DSI_DPHY_STATUS_PHY_ULPSACTIVENOTCLK_1_Val _UINT32_(0x1)                                        /* (DSI_DPHY_STATUS) The clock lane is not in Ultra-Low-Power (ULP) state.  */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOTCLK_0 (DSI_DPHY_STATUS_PHY_ULPSACTIVENOTCLK_0_Val << DSI_DPHY_STATUS_PHY_ULPSACTIVENOTCLK_Pos) /* (DSI_DPHY_STATUS) The clock lane is in Ultra-Low-Power state. Position  */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOTCLK_1 (DSI_DPHY_STATUS_PHY_ULPSACTIVENOTCLK_1_Val << DSI_DPHY_STATUS_PHY_ULPSACTIVENOTCLK_Pos) /* (DSI_DPHY_STATUS) The clock lane is not in Ultra-Low-Power (ULP) state. Position  */
#define DSI_DPHY_STATUS_PHY_STOPSTATE0LANE_Pos _UINT32_(4)                                          /* (DSI_DPHY_STATUS) D-PHY Stop State on Data Lane 0 Status Position */
#define DSI_DPHY_STATUS_PHY_STOPSTATE0LANE_Msk (_UINT32_(0x1) << DSI_DPHY_STATUS_PHY_STOPSTATE0LANE_Pos) /* (DSI_DPHY_STATUS) D-PHY Stop State on Data Lane 0 Status Mask */
#define DSI_DPHY_STATUS_PHY_STOPSTATE0LANE(value) (DSI_DPHY_STATUS_PHY_STOPSTATE0LANE_Msk & (_UINT32_(value) << DSI_DPHY_STATUS_PHY_STOPSTATE0LANE_Pos)) /* Assigment of value for PHY_STOPSTATE0LANE in the DSI_DPHY_STATUS register */
#define   DSI_DPHY_STATUS_PHY_STOPSTATE0LANE_0_Val _UINT32_(0x0)                                        /* (DSI_DPHY_STATUS) Data lane 0 module is not in Stop state.  */
#define   DSI_DPHY_STATUS_PHY_STOPSTATE0LANE_1_Val _UINT32_(0x1)                                        /* (DSI_DPHY_STATUS) Data lane 0 module is in Stop state.  */
#define DSI_DPHY_STATUS_PHY_STOPSTATE0LANE_0  (DSI_DPHY_STATUS_PHY_STOPSTATE0LANE_0_Val << DSI_DPHY_STATUS_PHY_STOPSTATE0LANE_Pos) /* (DSI_DPHY_STATUS) Data lane 0 module is not in Stop state. Position  */
#define DSI_DPHY_STATUS_PHY_STOPSTATE0LANE_1  (DSI_DPHY_STATUS_PHY_STOPSTATE0LANE_1_Val << DSI_DPHY_STATUS_PHY_STOPSTATE0LANE_Pos) /* (DSI_DPHY_STATUS) Data lane 0 module is in Stop state. Position  */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT0LANE_Pos _UINT32_(5)                                          /* (DSI_DPHY_STATUS) D-PHY Ultra-Low-Power State Active on Data Lane 0 Status Position */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT0LANE_Msk (_UINT32_(0x1) << DSI_DPHY_STATUS_PHY_ULPSACTIVENOT0LANE_Pos) /* (DSI_DPHY_STATUS) D-PHY Ultra-Low-Power State Active on Data Lane 0 Status Mask */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT0LANE(value) (DSI_DPHY_STATUS_PHY_ULPSACTIVENOT0LANE_Msk & (_UINT32_(value) << DSI_DPHY_STATUS_PHY_ULPSACTIVENOT0LANE_Pos)) /* Assigment of value for PHY_ULPSACTIVENOT0LANE in the DSI_DPHY_STATUS register */
#define   DSI_DPHY_STATUS_PHY_ULPSACTIVENOT0LANE_0_Val _UINT32_(0x0)                                        /* (DSI_DPHY_STATUS) Data lane 0 is in Ultra-Low-Power state.  */
#define   DSI_DPHY_STATUS_PHY_ULPSACTIVENOT0LANE_1_Val _UINT32_(0x1)                                        /* (DSI_DPHY_STATUS) Data lane 0 is not in Ultra-Low-Power (ULP) state.  */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT0LANE_0 (DSI_DPHY_STATUS_PHY_ULPSACTIVENOT0LANE_0_Val << DSI_DPHY_STATUS_PHY_ULPSACTIVENOT0LANE_Pos) /* (DSI_DPHY_STATUS) Data lane 0 is in Ultra-Low-Power state. Position  */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT0LANE_1 (DSI_DPHY_STATUS_PHY_ULPSACTIVENOT0LANE_1_Val << DSI_DPHY_STATUS_PHY_ULPSACTIVENOT0LANE_Pos) /* (DSI_DPHY_STATUS) Data lane 0 is not in Ultra-Low-Power (ULP) state. Position  */
#define DSI_DPHY_STATUS_PHY_RXULPSESC0LANE_Pos _UINT32_(6)                                          /* (DSI_DPHY_STATUS) Ultra-Low-Power State Escape Code Reception Position */
#define DSI_DPHY_STATUS_PHY_RXULPSESC0LANE_Msk (_UINT32_(0x1) << DSI_DPHY_STATUS_PHY_RXULPSESC0LANE_Pos) /* (DSI_DPHY_STATUS) Ultra-Low-Power State Escape Code Reception Mask */
#define DSI_DPHY_STATUS_PHY_RXULPSESC0LANE(value) (DSI_DPHY_STATUS_PHY_RXULPSESC0LANE_Msk & (_UINT32_(value) << DSI_DPHY_STATUS_PHY_RXULPSESC0LANE_Pos)) /* Assigment of value for PHY_RXULPSESC0LANE in the DSI_DPHY_STATUS register */
#define   DSI_DPHY_STATUS_PHY_RXULPSESC0LANE_0_Val _UINT32_(0x0)                                        /* (DSI_DPHY_STATUS) Data lane 0 is not in Ultra Low-Power state after reception of the Ultra Low-Power state Escape code.  */
#define   DSI_DPHY_STATUS_PHY_RXULPSESC0LANE_1_Val _UINT32_(0x1)                                        /* (DSI_DPHY_STATUS) Data lane 0 is in Ultra Low-Power state after reception of the Ultra Low-Power state Escape code.  */
#define DSI_DPHY_STATUS_PHY_RXULPSESC0LANE_0  (DSI_DPHY_STATUS_PHY_RXULPSESC0LANE_0_Val << DSI_DPHY_STATUS_PHY_RXULPSESC0LANE_Pos) /* (DSI_DPHY_STATUS) Data lane 0 is not in Ultra Low-Power state after reception of the Ultra Low-Power state Escape code. Position  */
#define DSI_DPHY_STATUS_PHY_RXULPSESC0LANE_1  (DSI_DPHY_STATUS_PHY_RXULPSESC0LANE_1_Val << DSI_DPHY_STATUS_PHY_RXULPSESC0LANE_Pos) /* (DSI_DPHY_STATUS) Data lane 0 is in Ultra Low-Power state after reception of the Ultra Low-Power state Escape code. Position  */
#define DSI_DPHY_STATUS_PHY_STOPSTATE1LANE_Pos _UINT32_(7)                                          /* (DSI_DPHY_STATUS) D-PHY Stop State on Data Lane 1 Statu Position */
#define DSI_DPHY_STATUS_PHY_STOPSTATE1LANE_Msk (_UINT32_(0x1) << DSI_DPHY_STATUS_PHY_STOPSTATE1LANE_Pos) /* (DSI_DPHY_STATUS) D-PHY Stop State on Data Lane 1 Statu Mask */
#define DSI_DPHY_STATUS_PHY_STOPSTATE1LANE(value) (DSI_DPHY_STATUS_PHY_STOPSTATE1LANE_Msk & (_UINT32_(value) << DSI_DPHY_STATUS_PHY_STOPSTATE1LANE_Pos)) /* Assigment of value for PHY_STOPSTATE1LANE in the DSI_DPHY_STATUS register */
#define   DSI_DPHY_STATUS_PHY_STOPSTATE1LANE_0_Val _UINT32_(0x0)                                        /* (DSI_DPHY_STATUS) Data lane 1 module is not in Stop state.  */
#define   DSI_DPHY_STATUS_PHY_STOPSTATE1LANE_1_Val _UINT32_(0x1)                                        /* (DSI_DPHY_STATUS) Data lane 1 module is in Stop state.  */
#define DSI_DPHY_STATUS_PHY_STOPSTATE1LANE_0  (DSI_DPHY_STATUS_PHY_STOPSTATE1LANE_0_Val << DSI_DPHY_STATUS_PHY_STOPSTATE1LANE_Pos) /* (DSI_DPHY_STATUS) Data lane 1 module is not in Stop state. Position  */
#define DSI_DPHY_STATUS_PHY_STOPSTATE1LANE_1  (DSI_DPHY_STATUS_PHY_STOPSTATE1LANE_1_Val << DSI_DPHY_STATUS_PHY_STOPSTATE1LANE_Pos) /* (DSI_DPHY_STATUS) Data lane 1 module is in Stop state. Position  */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT1LANE_Pos _UINT32_(8)                                          /* (DSI_DPHY_STATUS) D-PHY Ultra-Low-Power State Active on Data Lane 1 Status Position */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT1LANE_Msk (_UINT32_(0x1) << DSI_DPHY_STATUS_PHY_ULPSACTIVENOT1LANE_Pos) /* (DSI_DPHY_STATUS) D-PHY Ultra-Low-Power State Active on Data Lane 1 Status Mask */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT1LANE(value) (DSI_DPHY_STATUS_PHY_ULPSACTIVENOT1LANE_Msk & (_UINT32_(value) << DSI_DPHY_STATUS_PHY_ULPSACTIVENOT1LANE_Pos)) /* Assigment of value for PHY_ULPSACTIVENOT1LANE in the DSI_DPHY_STATUS register */
#define   DSI_DPHY_STATUS_PHY_ULPSACTIVENOT1LANE_0_Val _UINT32_(0x0)                                        /* (DSI_DPHY_STATUS) Data lane 1 is in Ultra-Low-Power state.  */
#define   DSI_DPHY_STATUS_PHY_ULPSACTIVENOT1LANE_1_Val _UINT32_(0x1)                                        /* (DSI_DPHY_STATUS) Data lane 1 is not in Ultra-Low-Power (ULP) state.  */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT1LANE_0 (DSI_DPHY_STATUS_PHY_ULPSACTIVENOT1LANE_0_Val << DSI_DPHY_STATUS_PHY_ULPSACTIVENOT1LANE_Pos) /* (DSI_DPHY_STATUS) Data lane 1 is in Ultra-Low-Power state. Position  */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT1LANE_1 (DSI_DPHY_STATUS_PHY_ULPSACTIVENOT1LANE_1_Val << DSI_DPHY_STATUS_PHY_ULPSACTIVENOT1LANE_Pos) /* (DSI_DPHY_STATUS) Data lane 1 is not in Ultra-Low-Power (ULP) state. Position  */
#define DSI_DPHY_STATUS_PHY_STOPSTATE2LANE_Pos _UINT32_(9)                                          /* (DSI_DPHY_STATUS) D-PHY Stop State on Data Lane 2 Status Position */
#define DSI_DPHY_STATUS_PHY_STOPSTATE2LANE_Msk (_UINT32_(0x1) << DSI_DPHY_STATUS_PHY_STOPSTATE2LANE_Pos) /* (DSI_DPHY_STATUS) D-PHY Stop State on Data Lane 2 Status Mask */
#define DSI_DPHY_STATUS_PHY_STOPSTATE2LANE(value) (DSI_DPHY_STATUS_PHY_STOPSTATE2LANE_Msk & (_UINT32_(value) << DSI_DPHY_STATUS_PHY_STOPSTATE2LANE_Pos)) /* Assigment of value for PHY_STOPSTATE2LANE in the DSI_DPHY_STATUS register */
#define   DSI_DPHY_STATUS_PHY_STOPSTATE2LANE_0_Val _UINT32_(0x0)                                        /* (DSI_DPHY_STATUS) Data lane 2 module is not in Stop state.  */
#define   DSI_DPHY_STATUS_PHY_STOPSTATE2LANE_1_Val _UINT32_(0x1)                                        /* (DSI_DPHY_STATUS) Data lane 2 module is in Stop state.  */
#define DSI_DPHY_STATUS_PHY_STOPSTATE2LANE_0  (DSI_DPHY_STATUS_PHY_STOPSTATE2LANE_0_Val << DSI_DPHY_STATUS_PHY_STOPSTATE2LANE_Pos) /* (DSI_DPHY_STATUS) Data lane 2 module is not in Stop state. Position  */
#define DSI_DPHY_STATUS_PHY_STOPSTATE2LANE_1  (DSI_DPHY_STATUS_PHY_STOPSTATE2LANE_1_Val << DSI_DPHY_STATUS_PHY_STOPSTATE2LANE_Pos) /* (DSI_DPHY_STATUS) Data lane 2 module is in Stop state. Position  */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT2LANE_Pos _UINT32_(10)                                         /* (DSI_DPHY_STATUS) D-PHY Ultra-Low-Power State Active on Data Lane 2 Status Position */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT2LANE_Msk (_UINT32_(0x1) << DSI_DPHY_STATUS_PHY_ULPSACTIVENOT2LANE_Pos) /* (DSI_DPHY_STATUS) D-PHY Ultra-Low-Power State Active on Data Lane 2 Status Mask */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT2LANE(value) (DSI_DPHY_STATUS_PHY_ULPSACTIVENOT2LANE_Msk & (_UINT32_(value) << DSI_DPHY_STATUS_PHY_ULPSACTIVENOT2LANE_Pos)) /* Assigment of value for PHY_ULPSACTIVENOT2LANE in the DSI_DPHY_STATUS register */
#define   DSI_DPHY_STATUS_PHY_ULPSACTIVENOT2LANE_0_Val _UINT32_(0x0)                                        /* (DSI_DPHY_STATUS) Data lane 2 is in Ultra-Low-Power state.  */
#define   DSI_DPHY_STATUS_PHY_ULPSACTIVENOT2LANE_1_Val _UINT32_(0x1)                                        /* (DSI_DPHY_STATUS) Data lane 2 is not in Ultra-Low-Power (ULP) state.  */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT2LANE_0 (DSI_DPHY_STATUS_PHY_ULPSACTIVENOT2LANE_0_Val << DSI_DPHY_STATUS_PHY_ULPSACTIVENOT2LANE_Pos) /* (DSI_DPHY_STATUS) Data lane 2 is in Ultra-Low-Power state. Position  */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT2LANE_1 (DSI_DPHY_STATUS_PHY_ULPSACTIVENOT2LANE_1_Val << DSI_DPHY_STATUS_PHY_ULPSACTIVENOT2LANE_Pos) /* (DSI_DPHY_STATUS) Data lane 2 is not in Ultra-Low-Power (ULP) state. Position  */
#define DSI_DPHY_STATUS_PHY_STOPSTATE3LANE_Pos _UINT32_(11)                                         /* (DSI_DPHY_STATUS) D-PHY Stop State on Data Lane 3 Status Position */
#define DSI_DPHY_STATUS_PHY_STOPSTATE3LANE_Msk (_UINT32_(0x1) << DSI_DPHY_STATUS_PHY_STOPSTATE3LANE_Pos) /* (DSI_DPHY_STATUS) D-PHY Stop State on Data Lane 3 Status Mask */
#define DSI_DPHY_STATUS_PHY_STOPSTATE3LANE(value) (DSI_DPHY_STATUS_PHY_STOPSTATE3LANE_Msk & (_UINT32_(value) << DSI_DPHY_STATUS_PHY_STOPSTATE3LANE_Pos)) /* Assigment of value for PHY_STOPSTATE3LANE in the DSI_DPHY_STATUS register */
#define   DSI_DPHY_STATUS_PHY_STOPSTATE3LANE_0_Val _UINT32_(0x0)                                        /* (DSI_DPHY_STATUS) Data lane 3 module is not in Stop state.  */
#define   DSI_DPHY_STATUS_PHY_STOPSTATE3LANE_1_Val _UINT32_(0x1)                                        /* (DSI_DPHY_STATUS) Data lane 3 module is in Stop state.  */
#define DSI_DPHY_STATUS_PHY_STOPSTATE3LANE_0  (DSI_DPHY_STATUS_PHY_STOPSTATE3LANE_0_Val << DSI_DPHY_STATUS_PHY_STOPSTATE3LANE_Pos) /* (DSI_DPHY_STATUS) Data lane 3 module is not in Stop state. Position  */
#define DSI_DPHY_STATUS_PHY_STOPSTATE3LANE_1  (DSI_DPHY_STATUS_PHY_STOPSTATE3LANE_1_Val << DSI_DPHY_STATUS_PHY_STOPSTATE3LANE_Pos) /* (DSI_DPHY_STATUS) Data lane 3 module is in Stop state. Position  */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT3LANE_Pos _UINT32_(12)                                         /* (DSI_DPHY_STATUS) D-PHY Ultra-Low-Power State Active on Data Lane 3 Status Position */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT3LANE_Msk (_UINT32_(0x1) << DSI_DPHY_STATUS_PHY_ULPSACTIVENOT3LANE_Pos) /* (DSI_DPHY_STATUS) D-PHY Ultra-Low-Power State Active on Data Lane 3 Status Mask */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT3LANE(value) (DSI_DPHY_STATUS_PHY_ULPSACTIVENOT3LANE_Msk & (_UINT32_(value) << DSI_DPHY_STATUS_PHY_ULPSACTIVENOT3LANE_Pos)) /* Assigment of value for PHY_ULPSACTIVENOT3LANE in the DSI_DPHY_STATUS register */
#define   DSI_DPHY_STATUS_PHY_ULPSACTIVENOT3LANE_0_Val _UINT32_(0x0)                                        /* (DSI_DPHY_STATUS) Data lane 3 is in Ultra-Low-Power state.  */
#define   DSI_DPHY_STATUS_PHY_ULPSACTIVENOT3LANE_1_Val _UINT32_(0x1)                                        /* (DSI_DPHY_STATUS) Data lane 3 is not in Ultra-Low-Power (ULP) state.  */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT3LANE_0 (DSI_DPHY_STATUS_PHY_ULPSACTIVENOT3LANE_0_Val << DSI_DPHY_STATUS_PHY_ULPSACTIVENOT3LANE_Pos) /* (DSI_DPHY_STATUS) Data lane 3 is in Ultra-Low-Power state. Position  */
#define DSI_DPHY_STATUS_PHY_ULPSACTIVENOT3LANE_1 (DSI_DPHY_STATUS_PHY_ULPSACTIVENOT3LANE_1_Val << DSI_DPHY_STATUS_PHY_ULPSACTIVENOT3LANE_Pos) /* (DSI_DPHY_STATUS) Data lane 3 is not in Ultra-Low-Power (ULP) state. Position  */
#define DSI_DPHY_STATUS_Msk                   _UINT32_(0x00001FFF)                                 /* (DSI_DPHY_STATUS) Register Mask  */


/* -------- DSI_DPHY_TST_CTRL0 : (DSI Offset: 0xB4) (R/W 32) D-PHY Control Register 0 -------- */
#define DSI_DPHY_TST_CTRL0_RESETVALUE         _UINT32_(0x00)                                       /*  (DSI_DPHY_TST_CTRL0) D-PHY Control Register 0  Reset Value */

#define DSI_DPHY_TST_CTRL0_PHY_TESTCLR_Pos    _UINT32_(0)                                          /* (DSI_DPHY_TST_CTRL0) D-PHY Test Interface Clear Position */
#define DSI_DPHY_TST_CTRL0_PHY_TESTCLR_Msk    (_UINT32_(0x1) << DSI_DPHY_TST_CTRL0_PHY_TESTCLR_Pos) /* (DSI_DPHY_TST_CTRL0) D-PHY Test Interface Clear Mask */
#define DSI_DPHY_TST_CTRL0_PHY_TESTCLR(value) (DSI_DPHY_TST_CTRL0_PHY_TESTCLR_Msk & (_UINT32_(value) << DSI_DPHY_TST_CTRL0_PHY_TESTCLR_Pos)) /* Assigment of value for PHY_TESTCLR in the DSI_DPHY_TST_CTRL0 register */
#define   DSI_DPHY_TST_CTRL0_PHY_TESTCLR_0_Val _UINT32_(0x0)                                        /* (DSI_DPHY_TST_CTRL0) No effect.  */
#define   DSI_DPHY_TST_CTRL0_PHY_TESTCLR_1_Val _UINT32_(0x1)                                        /* (DSI_DPHY_TST_CTRL0) Clears the PHY test interface.  */
#define DSI_DPHY_TST_CTRL0_PHY_TESTCLR_0      (DSI_DPHY_TST_CTRL0_PHY_TESTCLR_0_Val << DSI_DPHY_TST_CTRL0_PHY_TESTCLR_Pos) /* (DSI_DPHY_TST_CTRL0) No effect. Position  */
#define DSI_DPHY_TST_CTRL0_PHY_TESTCLR_1      (DSI_DPHY_TST_CTRL0_PHY_TESTCLR_1_Val << DSI_DPHY_TST_CTRL0_PHY_TESTCLR_Pos) /* (DSI_DPHY_TST_CTRL0) Clears the PHY test interface. Position  */
#define DSI_DPHY_TST_CTRL0_PHY_TESTCLK_Pos    _UINT32_(1)                                          /* (DSI_DPHY_TST_CTRL0) D-PHY Test Interface Clock Position */
#define DSI_DPHY_TST_CTRL0_PHY_TESTCLK_Msk    (_UINT32_(0x1) << DSI_DPHY_TST_CTRL0_PHY_TESTCLK_Pos) /* (DSI_DPHY_TST_CTRL0) D-PHY Test Interface Clock Mask */
#define DSI_DPHY_TST_CTRL0_PHY_TESTCLK(value) (DSI_DPHY_TST_CTRL0_PHY_TESTCLK_Msk & (_UINT32_(value) << DSI_DPHY_TST_CTRL0_PHY_TESTCLK_Pos)) /* Assigment of value for PHY_TESTCLK in the DSI_DPHY_TST_CTRL0 register */
#define DSI_DPHY_TST_CTRL0_Msk                _UINT32_(0x00000003)                                 /* (DSI_DPHY_TST_CTRL0) Register Mask  */


/* -------- DSI_DPHY_TST_CTRL1 : (DSI Offset: 0xB8) (R/W 32) D-PHY Control Register 1 -------- */
#define DSI_DPHY_TST_CTRL1_RESETVALUE         _UINT32_(0x00)                                       /*  (DSI_DPHY_TST_CTRL1) D-PHY Control Register 1  Reset Value */

#define DSI_DPHY_TST_CTRL1_PHY_TESTDIN_Pos    _UINT32_(0)                                          /* (DSI_DPHY_TST_CTRL1) D-PHY Test Interface Data In Position */
#define DSI_DPHY_TST_CTRL1_PHY_TESTDIN_Msk    (_UINT32_(0xFF) << DSI_DPHY_TST_CTRL1_PHY_TESTDIN_Pos) /* (DSI_DPHY_TST_CTRL1) D-PHY Test Interface Data In Mask */
#define DSI_DPHY_TST_CTRL1_PHY_TESTDIN(value) (DSI_DPHY_TST_CTRL1_PHY_TESTDIN_Msk & (_UINT32_(value) << DSI_DPHY_TST_CTRL1_PHY_TESTDIN_Pos)) /* Assigment of value for PHY_TESTDIN in the DSI_DPHY_TST_CTRL1 register */
#define DSI_DPHY_TST_CTRL1_PHY_TESTDOUT_Pos   _UINT32_(8)                                          /* (DSI_DPHY_TST_CTRL1) D-PHY Test Interface Data Out Position */
#define DSI_DPHY_TST_CTRL1_PHY_TESTDOUT_Msk   (_UINT32_(0xFF) << DSI_DPHY_TST_CTRL1_PHY_TESTDOUT_Pos) /* (DSI_DPHY_TST_CTRL1) D-PHY Test Interface Data Out Mask */
#define DSI_DPHY_TST_CTRL1_PHY_TESTDOUT(value) (DSI_DPHY_TST_CTRL1_PHY_TESTDOUT_Msk & (_UINT32_(value) << DSI_DPHY_TST_CTRL1_PHY_TESTDOUT_Pos)) /* Assigment of value for PHY_TESTDOUT in the DSI_DPHY_TST_CTRL1 register */
#define DSI_DPHY_TST_CTRL1_PHY_TESTEN_Pos     _UINT32_(16)                                         /* (DSI_DPHY_TST_CTRL1) D-PHY Test Interface Operation Type Position */
#define DSI_DPHY_TST_CTRL1_PHY_TESTEN_Msk     (_UINT32_(0x1) << DSI_DPHY_TST_CTRL1_PHY_TESTEN_Pos) /* (DSI_DPHY_TST_CTRL1) D-PHY Test Interface Operation Type Mask */
#define DSI_DPHY_TST_CTRL1_PHY_TESTEN(value)  (DSI_DPHY_TST_CTRL1_PHY_TESTEN_Msk & (_UINT32_(value) << DSI_DPHY_TST_CTRL1_PHY_TESTEN_Pos)) /* Assigment of value for PHY_TESTEN in the DSI_DPHY_TST_CTRL1 register */
#define   DSI_DPHY_TST_CTRL1_PHY_TESTEN_WRITEADDR_Val _UINT32_(0x0)                                        /* (DSI_DPHY_TST_CTRL1) The data write operation is set on the rising edge of DSI_DPHY_TST_CTRL0.PHY_TESTCLK.  */
#define   DSI_DPHY_TST_CTRL1_PHY_TESTEN_WRITEDATA_Val _UINT32_(0x1)                                        /* (DSI_DPHY_TST_CTRL1) The address write operation is set on the falling edge of DSI_DPHY_TST_CTRL0.PHY_TESTCLK.  */
#define DSI_DPHY_TST_CTRL1_PHY_TESTEN_WRITEADDR (DSI_DPHY_TST_CTRL1_PHY_TESTEN_WRITEADDR_Val << DSI_DPHY_TST_CTRL1_PHY_TESTEN_Pos) /* (DSI_DPHY_TST_CTRL1) The data write operation is set on the rising edge of DSI_DPHY_TST_CTRL0.PHY_TESTCLK. Position  */
#define DSI_DPHY_TST_CTRL1_PHY_TESTEN_WRITEDATA (DSI_DPHY_TST_CTRL1_PHY_TESTEN_WRITEDATA_Val << DSI_DPHY_TST_CTRL1_PHY_TESTEN_Pos) /* (DSI_DPHY_TST_CTRL1) The address write operation is set on the falling edge of DSI_DPHY_TST_CTRL0.PHY_TESTCLK. Position  */
#define DSI_DPHY_TST_CTRL1_Msk                _UINT32_(0x0001FFFF)                                 /* (DSI_DPHY_TST_CTRL1) Register Mask  */


/* -------- DSI_INT_ST0 : (DSI Offset: 0xBC) ( R/ 32) Interrupt Status Register 0 -------- */
#define DSI_INT_ST0_RESETVALUE                _UINT32_(0x00)                                       /*  (DSI_INT_ST0) Interrupt Status Register 0  Reset Value */

#define DSI_INT_ST0_ACK_WITH_ERR_0_Pos        _UINT32_(0)                                          /* (DSI_INT_ST0) Acknowledge With Error 0 Position */
#define DSI_INT_ST0_ACK_WITH_ERR_0_Msk        (_UINT32_(0x1) << DSI_INT_ST0_ACK_WITH_ERR_0_Pos)    /* (DSI_INT_ST0) Acknowledge With Error 0 Mask */
#define DSI_INT_ST0_ACK_WITH_ERR_0(value)     (DSI_INT_ST0_ACK_WITH_ERR_0_Msk & (_UINT32_(value) << DSI_INT_ST0_ACK_WITH_ERR_0_Pos)) /* Assigment of value for ACK_WITH_ERR_0 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_ACK_WITH_ERR_1_Pos        _UINT32_(1)                                          /* (DSI_INT_ST0) Acknowledge With Error 1 Position */
#define DSI_INT_ST0_ACK_WITH_ERR_1_Msk        (_UINT32_(0x1) << DSI_INT_ST0_ACK_WITH_ERR_1_Pos)    /* (DSI_INT_ST0) Acknowledge With Error 1 Mask */
#define DSI_INT_ST0_ACK_WITH_ERR_1(value)     (DSI_INT_ST0_ACK_WITH_ERR_1_Msk & (_UINT32_(value) << DSI_INT_ST0_ACK_WITH_ERR_1_Pos)) /* Assigment of value for ACK_WITH_ERR_1 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_ACK_WITH_ERR_2_Pos        _UINT32_(2)                                          /* (DSI_INT_ST0) Acknowledge With Error 2 Position */
#define DSI_INT_ST0_ACK_WITH_ERR_2_Msk        (_UINT32_(0x1) << DSI_INT_ST0_ACK_WITH_ERR_2_Pos)    /* (DSI_INT_ST0) Acknowledge With Error 2 Mask */
#define DSI_INT_ST0_ACK_WITH_ERR_2(value)     (DSI_INT_ST0_ACK_WITH_ERR_2_Msk & (_UINT32_(value) << DSI_INT_ST0_ACK_WITH_ERR_2_Pos)) /* Assigment of value for ACK_WITH_ERR_2 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_ACK_WITH_ERR_3_Pos        _UINT32_(3)                                          /* (DSI_INT_ST0) Acknowledge With Error 3 Position */
#define DSI_INT_ST0_ACK_WITH_ERR_3_Msk        (_UINT32_(0x1) << DSI_INT_ST0_ACK_WITH_ERR_3_Pos)    /* (DSI_INT_ST0) Acknowledge With Error 3 Mask */
#define DSI_INT_ST0_ACK_WITH_ERR_3(value)     (DSI_INT_ST0_ACK_WITH_ERR_3_Msk & (_UINT32_(value) << DSI_INT_ST0_ACK_WITH_ERR_3_Pos)) /* Assigment of value for ACK_WITH_ERR_3 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_ACK_WITH_ERR_4_Pos        _UINT32_(4)                                          /* (DSI_INT_ST0) Acknowledge With Error 4 Position */
#define DSI_INT_ST0_ACK_WITH_ERR_4_Msk        (_UINT32_(0x1) << DSI_INT_ST0_ACK_WITH_ERR_4_Pos)    /* (DSI_INT_ST0) Acknowledge With Error 4 Mask */
#define DSI_INT_ST0_ACK_WITH_ERR_4(value)     (DSI_INT_ST0_ACK_WITH_ERR_4_Msk & (_UINT32_(value) << DSI_INT_ST0_ACK_WITH_ERR_4_Pos)) /* Assigment of value for ACK_WITH_ERR_4 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_ACK_WITH_ERR_5_Pos        _UINT32_(5)                                          /* (DSI_INT_ST0) Acknowledge With Error 5 Position */
#define DSI_INT_ST0_ACK_WITH_ERR_5_Msk        (_UINT32_(0x1) << DSI_INT_ST0_ACK_WITH_ERR_5_Pos)    /* (DSI_INT_ST0) Acknowledge With Error 5 Mask */
#define DSI_INT_ST0_ACK_WITH_ERR_5(value)     (DSI_INT_ST0_ACK_WITH_ERR_5_Msk & (_UINT32_(value) << DSI_INT_ST0_ACK_WITH_ERR_5_Pos)) /* Assigment of value for ACK_WITH_ERR_5 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_ACK_WITH_ERR_6_Pos        _UINT32_(6)                                          /* (DSI_INT_ST0) Acknowledge With Error 6 Position */
#define DSI_INT_ST0_ACK_WITH_ERR_6_Msk        (_UINT32_(0x1) << DSI_INT_ST0_ACK_WITH_ERR_6_Pos)    /* (DSI_INT_ST0) Acknowledge With Error 6 Mask */
#define DSI_INT_ST0_ACK_WITH_ERR_6(value)     (DSI_INT_ST0_ACK_WITH_ERR_6_Msk & (_UINT32_(value) << DSI_INT_ST0_ACK_WITH_ERR_6_Pos)) /* Assigment of value for ACK_WITH_ERR_6 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_ACK_WITH_ERR_7_Pos        _UINT32_(7)                                          /* (DSI_INT_ST0) Acknowledge With Error 7 Position */
#define DSI_INT_ST0_ACK_WITH_ERR_7_Msk        (_UINT32_(0x1) << DSI_INT_ST0_ACK_WITH_ERR_7_Pos)    /* (DSI_INT_ST0) Acknowledge With Error 7 Mask */
#define DSI_INT_ST0_ACK_WITH_ERR_7(value)     (DSI_INT_ST0_ACK_WITH_ERR_7_Msk & (_UINT32_(value) << DSI_INT_ST0_ACK_WITH_ERR_7_Pos)) /* Assigment of value for ACK_WITH_ERR_7 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_ACK_WITH_ERR_8_Pos        _UINT32_(8)                                          /* (DSI_INT_ST0) Acknowledge With Error 8 Position */
#define DSI_INT_ST0_ACK_WITH_ERR_8_Msk        (_UINT32_(0x1) << DSI_INT_ST0_ACK_WITH_ERR_8_Pos)    /* (DSI_INT_ST0) Acknowledge With Error 8 Mask */
#define DSI_INT_ST0_ACK_WITH_ERR_8(value)     (DSI_INT_ST0_ACK_WITH_ERR_8_Msk & (_UINT32_(value) << DSI_INT_ST0_ACK_WITH_ERR_8_Pos)) /* Assigment of value for ACK_WITH_ERR_8 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_ACK_WITH_ERR_9_Pos        _UINT32_(9)                                          /* (DSI_INT_ST0) Acknowledge With Error 9 Position */
#define DSI_INT_ST0_ACK_WITH_ERR_9_Msk        (_UINT32_(0x1) << DSI_INT_ST0_ACK_WITH_ERR_9_Pos)    /* (DSI_INT_ST0) Acknowledge With Error 9 Mask */
#define DSI_INT_ST0_ACK_WITH_ERR_9(value)     (DSI_INT_ST0_ACK_WITH_ERR_9_Msk & (_UINT32_(value) << DSI_INT_ST0_ACK_WITH_ERR_9_Pos)) /* Assigment of value for ACK_WITH_ERR_9 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_ACK_WITH_ERR_10_Pos       _UINT32_(10)                                         /* (DSI_INT_ST0) Acknowledge With Error 10 Position */
#define DSI_INT_ST0_ACK_WITH_ERR_10_Msk       (_UINT32_(0x1) << DSI_INT_ST0_ACK_WITH_ERR_10_Pos)   /* (DSI_INT_ST0) Acknowledge With Error 10 Mask */
#define DSI_INT_ST0_ACK_WITH_ERR_10(value)    (DSI_INT_ST0_ACK_WITH_ERR_10_Msk & (_UINT32_(value) << DSI_INT_ST0_ACK_WITH_ERR_10_Pos)) /* Assigment of value for ACK_WITH_ERR_10 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_ACK_WITH_ERR_11_Pos       _UINT32_(11)                                         /* (DSI_INT_ST0) Acknowledge With Error 11 Position */
#define DSI_INT_ST0_ACK_WITH_ERR_11_Msk       (_UINT32_(0x1) << DSI_INT_ST0_ACK_WITH_ERR_11_Pos)   /* (DSI_INT_ST0) Acknowledge With Error 11 Mask */
#define DSI_INT_ST0_ACK_WITH_ERR_11(value)    (DSI_INT_ST0_ACK_WITH_ERR_11_Msk & (_UINT32_(value) << DSI_INT_ST0_ACK_WITH_ERR_11_Pos)) /* Assigment of value for ACK_WITH_ERR_11 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_ACK_WITH_ERR_12_Pos       _UINT32_(12)                                         /* (DSI_INT_ST0) Acknowledge With Error 12 Position */
#define DSI_INT_ST0_ACK_WITH_ERR_12_Msk       (_UINT32_(0x1) << DSI_INT_ST0_ACK_WITH_ERR_12_Pos)   /* (DSI_INT_ST0) Acknowledge With Error 12 Mask */
#define DSI_INT_ST0_ACK_WITH_ERR_12(value)    (DSI_INT_ST0_ACK_WITH_ERR_12_Msk & (_UINT32_(value) << DSI_INT_ST0_ACK_WITH_ERR_12_Pos)) /* Assigment of value for ACK_WITH_ERR_12 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_ACK_WITH_ERR_13_Pos       _UINT32_(13)                                         /* (DSI_INT_ST0) Acknowledge With Error 13 Position */
#define DSI_INT_ST0_ACK_WITH_ERR_13_Msk       (_UINT32_(0x1) << DSI_INT_ST0_ACK_WITH_ERR_13_Pos)   /* (DSI_INT_ST0) Acknowledge With Error 13 Mask */
#define DSI_INT_ST0_ACK_WITH_ERR_13(value)    (DSI_INT_ST0_ACK_WITH_ERR_13_Msk & (_UINT32_(value) << DSI_INT_ST0_ACK_WITH_ERR_13_Pos)) /* Assigment of value for ACK_WITH_ERR_13 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_ACK_WITH_ERR_14_Pos       _UINT32_(14)                                         /* (DSI_INT_ST0) Acknowledge With Error 14 Position */
#define DSI_INT_ST0_ACK_WITH_ERR_14_Msk       (_UINT32_(0x1) << DSI_INT_ST0_ACK_WITH_ERR_14_Pos)   /* (DSI_INT_ST0) Acknowledge With Error 14 Mask */
#define DSI_INT_ST0_ACK_WITH_ERR_14(value)    (DSI_INT_ST0_ACK_WITH_ERR_14_Msk & (_UINT32_(value) << DSI_INT_ST0_ACK_WITH_ERR_14_Pos)) /* Assigment of value for ACK_WITH_ERR_14 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_ACK_WITH_ERR_15_Pos       _UINT32_(15)                                         /* (DSI_INT_ST0) Acknowledge With Error 15 Position */
#define DSI_INT_ST0_ACK_WITH_ERR_15_Msk       (_UINT32_(0x1) << DSI_INT_ST0_ACK_WITH_ERR_15_Pos)   /* (DSI_INT_ST0) Acknowledge With Error 15 Mask */
#define DSI_INT_ST0_ACK_WITH_ERR_15(value)    (DSI_INT_ST0_ACK_WITH_ERR_15_Msk & (_UINT32_(value) << DSI_INT_ST0_ACK_WITH_ERR_15_Pos)) /* Assigment of value for ACK_WITH_ERR_15 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_DPHY_ERRORS_0_Pos         _UINT32_(16)                                         /* (DSI_INT_ST0) D-PHY Errors 0 Position */
#define DSI_INT_ST0_DPHY_ERRORS_0_Msk         (_UINT32_(0x1) << DSI_INT_ST0_DPHY_ERRORS_0_Pos)     /* (DSI_INT_ST0) D-PHY Errors 0 Mask */
#define DSI_INT_ST0_DPHY_ERRORS_0(value)      (DSI_INT_ST0_DPHY_ERRORS_0_Msk & (_UINT32_(value) << DSI_INT_ST0_DPHY_ERRORS_0_Pos)) /* Assigment of value for DPHY_ERRORS_0 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_DPHY_ERRORS_1_Pos         _UINT32_(17)                                         /* (DSI_INT_ST0) D-PHY Errors 1 Position */
#define DSI_INT_ST0_DPHY_ERRORS_1_Msk         (_UINT32_(0x1) << DSI_INT_ST0_DPHY_ERRORS_1_Pos)     /* (DSI_INT_ST0) D-PHY Errors 1 Mask */
#define DSI_INT_ST0_DPHY_ERRORS_1(value)      (DSI_INT_ST0_DPHY_ERRORS_1_Msk & (_UINT32_(value) << DSI_INT_ST0_DPHY_ERRORS_1_Pos)) /* Assigment of value for DPHY_ERRORS_1 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_DPHY_ERRORS_2_Pos         _UINT32_(18)                                         /* (DSI_INT_ST0) D-PHY Errors 2 Position */
#define DSI_INT_ST0_DPHY_ERRORS_2_Msk         (_UINT32_(0x1) << DSI_INT_ST0_DPHY_ERRORS_2_Pos)     /* (DSI_INT_ST0) D-PHY Errors 2 Mask */
#define DSI_INT_ST0_DPHY_ERRORS_2(value)      (DSI_INT_ST0_DPHY_ERRORS_2_Msk & (_UINT32_(value) << DSI_INT_ST0_DPHY_ERRORS_2_Pos)) /* Assigment of value for DPHY_ERRORS_2 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_DPHY_ERRORS_3_Pos         _UINT32_(19)                                         /* (DSI_INT_ST0) D-PHY Errors 3 Position */
#define DSI_INT_ST0_DPHY_ERRORS_3_Msk         (_UINT32_(0x1) << DSI_INT_ST0_DPHY_ERRORS_3_Pos)     /* (DSI_INT_ST0) D-PHY Errors 3 Mask */
#define DSI_INT_ST0_DPHY_ERRORS_3(value)      (DSI_INT_ST0_DPHY_ERRORS_3_Msk & (_UINT32_(value) << DSI_INT_ST0_DPHY_ERRORS_3_Pos)) /* Assigment of value for DPHY_ERRORS_3 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_DPHY_ERRORS_4_Pos         _UINT32_(20)                                         /* (DSI_INT_ST0) D-PHY Errors 4 Position */
#define DSI_INT_ST0_DPHY_ERRORS_4_Msk         (_UINT32_(0x1) << DSI_INT_ST0_DPHY_ERRORS_4_Pos)     /* (DSI_INT_ST0) D-PHY Errors 4 Mask */
#define DSI_INT_ST0_DPHY_ERRORS_4(value)      (DSI_INT_ST0_DPHY_ERRORS_4_Msk & (_UINT32_(value) << DSI_INT_ST0_DPHY_ERRORS_4_Pos)) /* Assigment of value for DPHY_ERRORS_4 in the DSI_INT_ST0 register */
#define DSI_INT_ST0_Msk                       _UINT32_(0x001FFFFF)                                 /* (DSI_INT_ST0) Register Mask  */

#define DSI_INT_ST0_ACK_WITH_ERR__Pos         _UINT32_(0)                                          /* (DSI_INT_ST0 Position) Acknowledge With Error x */
#define DSI_INT_ST0_ACK_WITH_ERR__Msk         (_UINT32_(0xFFFF) << DSI_INT_ST0_ACK_WITH_ERR__Pos)  /* (DSI_INT_ST0 Mask) ACK_WITH_ERR_ */
#define DSI_INT_ST0_ACK_WITH_ERR_(value)      (DSI_INT_ST0_ACK_WITH_ERR__Msk & (_UINT32_(value) << DSI_INT_ST0_ACK_WITH_ERR__Pos)) 
#define DSI_INT_ST0_DPHY_ERRORS__Pos          _UINT32_(16)                                         /* (DSI_INT_ST0 Position) D-PHY Errors 4 */
#define DSI_INT_ST0_DPHY_ERRORS__Msk          (_UINT32_(0x1F) << DSI_INT_ST0_DPHY_ERRORS__Pos)     /* (DSI_INT_ST0 Mask) DPHY_ERRORS_ */
#define DSI_INT_ST0_DPHY_ERRORS_(value)       (DSI_INT_ST0_DPHY_ERRORS__Msk & (_UINT32_(value) << DSI_INT_ST0_DPHY_ERRORS__Pos)) 

/* -------- DSI_INT_ST1 : (DSI Offset: 0xC0) ( R/ 32) Interrupt Status Register 1 -------- */
#define DSI_INT_ST1_RESETVALUE                _UINT32_(0x00)                                       /*  (DSI_INT_ST1) Interrupt Status Register 1  Reset Value */

#define DSI_INT_ST1_TO_HS_TX_Pos              _UINT32_(0)                                          /* (DSI_INT_ST1) High-Speed Transmission Timeout Status Position */
#define DSI_INT_ST1_TO_HS_TX_Msk              (_UINT32_(0x1) << DSI_INT_ST1_TO_HS_TX_Pos)          /* (DSI_INT_ST1) High-Speed Transmission Timeout Status Mask */
#define DSI_INT_ST1_TO_HS_TX(value)           (DSI_INT_ST1_TO_HS_TX_Msk & (_UINT32_(value) << DSI_INT_ST1_TO_HS_TX_Pos)) /* Assigment of value for TO_HS_TX in the DSI_INT_ST1 register */
#define DSI_INT_ST1_TO_LP_RX_Pos              _UINT32_(1)                                          /* (DSI_INT_ST1) Low-Power Reception Timeout Status Position */
#define DSI_INT_ST1_TO_LP_RX_Msk              (_UINT32_(0x1) << DSI_INT_ST1_TO_LP_RX_Pos)          /* (DSI_INT_ST1) Low-Power Reception Timeout Status Mask */
#define DSI_INT_ST1_TO_LP_RX(value)           (DSI_INT_ST1_TO_LP_RX_Msk & (_UINT32_(value) << DSI_INT_ST1_TO_LP_RX_Pos)) /* Assigment of value for TO_LP_RX in the DSI_INT_ST1 register */
#define DSI_INT_ST1_ECC_SINGLE_ERR_Pos        _UINT32_(2)                                          /* (DSI_INT_ST1) ECC Single Error Status Position */
#define DSI_INT_ST1_ECC_SINGLE_ERR_Msk        (_UINT32_(0x1) << DSI_INT_ST1_ECC_SINGLE_ERR_Pos)    /* (DSI_INT_ST1) ECC Single Error Status Mask */
#define DSI_INT_ST1_ECC_SINGLE_ERR(value)     (DSI_INT_ST1_ECC_SINGLE_ERR_Msk & (_UINT32_(value) << DSI_INT_ST1_ECC_SINGLE_ERR_Pos)) /* Assigment of value for ECC_SINGLE_ERR in the DSI_INT_ST1 register */
#define DSI_INT_ST1_ECC_MULTI_ERR_Pos         _UINT32_(3)                                          /* (DSI_INT_ST1) ECC Multiple Error Status Position */
#define DSI_INT_ST1_ECC_MULTI_ERR_Msk         (_UINT32_(0x1) << DSI_INT_ST1_ECC_MULTI_ERR_Pos)     /* (DSI_INT_ST1) ECC Multiple Error Status Mask */
#define DSI_INT_ST1_ECC_MULTI_ERR(value)      (DSI_INT_ST1_ECC_MULTI_ERR_Msk & (_UINT32_(value) << DSI_INT_ST1_ECC_MULTI_ERR_Pos)) /* Assigment of value for ECC_MULTI_ERR in the DSI_INT_ST1 register */
#define DSI_INT_ST1_CRC_ERR_Pos               _UINT32_(4)                                          /* (DSI_INT_ST1) CRC Error Status Position */
#define DSI_INT_ST1_CRC_ERR_Msk               (_UINT32_(0x1) << DSI_INT_ST1_CRC_ERR_Pos)           /* (DSI_INT_ST1) CRC Error Status Mask */
#define DSI_INT_ST1_CRC_ERR(value)            (DSI_INT_ST1_CRC_ERR_Msk & (_UINT32_(value) << DSI_INT_ST1_CRC_ERR_Pos)) /* Assigment of value for CRC_ERR in the DSI_INT_ST1 register */
#define DSI_INT_ST1_PKT_SIZE_ERR_Pos          _UINT32_(5)                                          /* (DSI_INT_ST1) Packet Size Error Status Position */
#define DSI_INT_ST1_PKT_SIZE_ERR_Msk          (_UINT32_(0x1) << DSI_INT_ST1_PKT_SIZE_ERR_Pos)      /* (DSI_INT_ST1) Packet Size Error Status Mask */
#define DSI_INT_ST1_PKT_SIZE_ERR(value)       (DSI_INT_ST1_PKT_SIZE_ERR_Msk & (_UINT32_(value) << DSI_INT_ST1_PKT_SIZE_ERR_Pos)) /* Assigment of value for PKT_SIZE_ERR in the DSI_INT_ST1 register */
#define DSI_INT_ST1_EOTP_ERR_Pos              _UINT32_(6)                                          /* (DSI_INT_ST1) End Of Transmission Packet Error Status Position */
#define DSI_INT_ST1_EOTP_ERR_Msk              (_UINT32_(0x1) << DSI_INT_ST1_EOTP_ERR_Pos)          /* (DSI_INT_ST1) End Of Transmission Packet Error Status Mask */
#define DSI_INT_ST1_EOTP_ERR(value)           (DSI_INT_ST1_EOTP_ERR_Msk & (_UINT32_(value) << DSI_INT_ST1_EOTP_ERR_Pos)) /* Assigment of value for EOTP_ERR in the DSI_INT_ST1 register */
#define DSI_INT_ST1_DPI_PLD_WR_ERR_Pos        _UINT32_(7)                                          /* (DSI_INT_ST1) Input Video Payload Write Error Status Position */
#define DSI_INT_ST1_DPI_PLD_WR_ERR_Msk        (_UINT32_(0x1) << DSI_INT_ST1_DPI_PLD_WR_ERR_Pos)    /* (DSI_INT_ST1) Input Video Payload Write Error Status Mask */
#define DSI_INT_ST1_DPI_PLD_WR_ERR(value)     (DSI_INT_ST1_DPI_PLD_WR_ERR_Msk & (_UINT32_(value) << DSI_INT_ST1_DPI_PLD_WR_ERR_Pos)) /* Assigment of value for DPI_PLD_WR_ERR in the DSI_INT_ST1 register */
#define DSI_INT_ST1_GEN_CMD_WR_ERR_Pos        _UINT32_(8)                                          /* (DSI_INT_ST1) Generic Interface Command Write Error Status Position */
#define DSI_INT_ST1_GEN_CMD_WR_ERR_Msk        (_UINT32_(0x1) << DSI_INT_ST1_GEN_CMD_WR_ERR_Pos)    /* (DSI_INT_ST1) Generic Interface Command Write Error Status Mask */
#define DSI_INT_ST1_GEN_CMD_WR_ERR(value)     (DSI_INT_ST1_GEN_CMD_WR_ERR_Msk & (_UINT32_(value) << DSI_INT_ST1_GEN_CMD_WR_ERR_Pos)) /* Assigment of value for GEN_CMD_WR_ERR in the DSI_INT_ST1 register */
#define DSI_INT_ST1_GEN_PLD_WR_ERR_Pos        _UINT32_(9)                                          /* (DSI_INT_ST1) Generic Interface Payload Write Error Status Position */
#define DSI_INT_ST1_GEN_PLD_WR_ERR_Msk        (_UINT32_(0x1) << DSI_INT_ST1_GEN_PLD_WR_ERR_Pos)    /* (DSI_INT_ST1) Generic Interface Payload Write Error Status Mask */
#define DSI_INT_ST1_GEN_PLD_WR_ERR(value)     (DSI_INT_ST1_GEN_PLD_WR_ERR_Msk & (_UINT32_(value) << DSI_INT_ST1_GEN_PLD_WR_ERR_Pos)) /* Assigment of value for GEN_PLD_WR_ERR in the DSI_INT_ST1 register */
#define DSI_INT_ST1_GEN_PLD_SEND_ERR_Pos      _UINT32_(10)                                         /* (DSI_INT_ST1) Generic Interface Payload Send Error Status Position */
#define DSI_INT_ST1_GEN_PLD_SEND_ERR_Msk      (_UINT32_(0x1) << DSI_INT_ST1_GEN_PLD_SEND_ERR_Pos)  /* (DSI_INT_ST1) Generic Interface Payload Send Error Status Mask */
#define DSI_INT_ST1_GEN_PLD_SEND_ERR(value)   (DSI_INT_ST1_GEN_PLD_SEND_ERR_Msk & (_UINT32_(value) << DSI_INT_ST1_GEN_PLD_SEND_ERR_Pos)) /* Assigment of value for GEN_PLD_SEND_ERR in the DSI_INT_ST1 register */
#define DSI_INT_ST1_GEN_PLD_RD_ERR_Pos        _UINT32_(11)                                         /* (DSI_INT_ST1) Generic Interface DCS Payload Read Error Status Position */
#define DSI_INT_ST1_GEN_PLD_RD_ERR_Msk        (_UINT32_(0x1) << DSI_INT_ST1_GEN_PLD_RD_ERR_Pos)    /* (DSI_INT_ST1) Generic Interface DCS Payload Read Error Status Mask */
#define DSI_INT_ST1_GEN_PLD_RD_ERR(value)     (DSI_INT_ST1_GEN_PLD_RD_ERR_Msk & (_UINT32_(value) << DSI_INT_ST1_GEN_PLD_RD_ERR_Pos)) /* Assigment of value for GEN_PLD_RD_ERR in the DSI_INT_ST1 register */
#define DSI_INT_ST1_GEN_PLD_RECEV_ERR_Pos     _UINT32_(12)                                         /* (DSI_INT_ST1) Generic Interface Payload Receive Error Status Position */
#define DSI_INT_ST1_GEN_PLD_RECEV_ERR_Msk     (_UINT32_(0x1) << DSI_INT_ST1_GEN_PLD_RECEV_ERR_Pos) /* (DSI_INT_ST1) Generic Interface Payload Receive Error Status Mask */
#define DSI_INT_ST1_GEN_PLD_RECEV_ERR(value)  (DSI_INT_ST1_GEN_PLD_RECEV_ERR_Msk & (_UINT32_(value) << DSI_INT_ST1_GEN_PLD_RECEV_ERR_Pos)) /* Assigment of value for GEN_PLD_RECEV_ERR in the DSI_INT_ST1 register */
#define DSI_INT_ST1_Msk                       _UINT32_(0x00001FFF)                                 /* (DSI_INT_ST1) Register Mask  */


/* -------- DSI_INT_MSK0 : (DSI Offset: 0xC4) (R/W 32) Interrupt Mask Configuration Register 0 -------- */
#define DSI_INT_MSK0_RESETVALUE               _UINT32_(0x00)                                       /*  (DSI_INT_MSK0) Interrupt Mask Configuration Register 0  Reset Value */

#define DSI_INT_MSK0_ACK_WITH_ERR_0_Pos       _UINT32_(0)                                          /* (DSI_INT_MSK0) Acknowledge With Error 0 Mask Position */
#define DSI_INT_MSK0_ACK_WITH_ERR_0_Msk       (_UINT32_(0x1) << DSI_INT_MSK0_ACK_WITH_ERR_0_Pos)   /* (DSI_INT_MSK0) Acknowledge With Error 0 Mask Mask */
#define DSI_INT_MSK0_ACK_WITH_ERR_0(value)    (DSI_INT_MSK0_ACK_WITH_ERR_0_Msk & (_UINT32_(value) << DSI_INT_MSK0_ACK_WITH_ERR_0_Pos)) /* Assigment of value for ACK_WITH_ERR_0 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_ACK_WITH_ERR_1_Pos       _UINT32_(1)                                          /* (DSI_INT_MSK0) Acknowledge With Error 1 Mask Position */
#define DSI_INT_MSK0_ACK_WITH_ERR_1_Msk       (_UINT32_(0x1) << DSI_INT_MSK0_ACK_WITH_ERR_1_Pos)   /* (DSI_INT_MSK0) Acknowledge With Error 1 Mask Mask */
#define DSI_INT_MSK0_ACK_WITH_ERR_1(value)    (DSI_INT_MSK0_ACK_WITH_ERR_1_Msk & (_UINT32_(value) << DSI_INT_MSK0_ACK_WITH_ERR_1_Pos)) /* Assigment of value for ACK_WITH_ERR_1 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_ACK_WITH_ERR_2_Pos       _UINT32_(2)                                          /* (DSI_INT_MSK0) Acknowledge With Error 2 Mask Position */
#define DSI_INT_MSK0_ACK_WITH_ERR_2_Msk       (_UINT32_(0x1) << DSI_INT_MSK0_ACK_WITH_ERR_2_Pos)   /* (DSI_INT_MSK0) Acknowledge With Error 2 Mask Mask */
#define DSI_INT_MSK0_ACK_WITH_ERR_2(value)    (DSI_INT_MSK0_ACK_WITH_ERR_2_Msk & (_UINT32_(value) << DSI_INT_MSK0_ACK_WITH_ERR_2_Pos)) /* Assigment of value for ACK_WITH_ERR_2 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_ACK_WITH_ERR_3_Pos       _UINT32_(3)                                          /* (DSI_INT_MSK0) Acknowledge With Error 3 Mask Position */
#define DSI_INT_MSK0_ACK_WITH_ERR_3_Msk       (_UINT32_(0x1) << DSI_INT_MSK0_ACK_WITH_ERR_3_Pos)   /* (DSI_INT_MSK0) Acknowledge With Error 3 Mask Mask */
#define DSI_INT_MSK0_ACK_WITH_ERR_3(value)    (DSI_INT_MSK0_ACK_WITH_ERR_3_Msk & (_UINT32_(value) << DSI_INT_MSK0_ACK_WITH_ERR_3_Pos)) /* Assigment of value for ACK_WITH_ERR_3 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_ACK_WITH_ERR_4_Pos       _UINT32_(4)                                          /* (DSI_INT_MSK0) Acknowledge With Error 4 Mask Position */
#define DSI_INT_MSK0_ACK_WITH_ERR_4_Msk       (_UINT32_(0x1) << DSI_INT_MSK0_ACK_WITH_ERR_4_Pos)   /* (DSI_INT_MSK0) Acknowledge With Error 4 Mask Mask */
#define DSI_INT_MSK0_ACK_WITH_ERR_4(value)    (DSI_INT_MSK0_ACK_WITH_ERR_4_Msk & (_UINT32_(value) << DSI_INT_MSK0_ACK_WITH_ERR_4_Pos)) /* Assigment of value for ACK_WITH_ERR_4 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_ACK_WITH_ERR_5_Pos       _UINT32_(5)                                          /* (DSI_INT_MSK0) Acknowledge With Error 5 Mask Position */
#define DSI_INT_MSK0_ACK_WITH_ERR_5_Msk       (_UINT32_(0x1) << DSI_INT_MSK0_ACK_WITH_ERR_5_Pos)   /* (DSI_INT_MSK0) Acknowledge With Error 5 Mask Mask */
#define DSI_INT_MSK0_ACK_WITH_ERR_5(value)    (DSI_INT_MSK0_ACK_WITH_ERR_5_Msk & (_UINT32_(value) << DSI_INT_MSK0_ACK_WITH_ERR_5_Pos)) /* Assigment of value for ACK_WITH_ERR_5 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_ACK_WITH_ERR_6_Pos       _UINT32_(6)                                          /* (DSI_INT_MSK0) Acknowledge With Error 6 Mask Position */
#define DSI_INT_MSK0_ACK_WITH_ERR_6_Msk       (_UINT32_(0x1) << DSI_INT_MSK0_ACK_WITH_ERR_6_Pos)   /* (DSI_INT_MSK0) Acknowledge With Error 6 Mask Mask */
#define DSI_INT_MSK0_ACK_WITH_ERR_6(value)    (DSI_INT_MSK0_ACK_WITH_ERR_6_Msk & (_UINT32_(value) << DSI_INT_MSK0_ACK_WITH_ERR_6_Pos)) /* Assigment of value for ACK_WITH_ERR_6 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_ACK_WITH_ERR_7_Pos       _UINT32_(7)                                          /* (DSI_INT_MSK0) Acknowledge With Error 7 Mask Position */
#define DSI_INT_MSK0_ACK_WITH_ERR_7_Msk       (_UINT32_(0x1) << DSI_INT_MSK0_ACK_WITH_ERR_7_Pos)   /* (DSI_INT_MSK0) Acknowledge With Error 7 Mask Mask */
#define DSI_INT_MSK0_ACK_WITH_ERR_7(value)    (DSI_INT_MSK0_ACK_WITH_ERR_7_Msk & (_UINT32_(value) << DSI_INT_MSK0_ACK_WITH_ERR_7_Pos)) /* Assigment of value for ACK_WITH_ERR_7 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_ACK_WITH_ERR_8_Pos       _UINT32_(8)                                          /* (DSI_INT_MSK0) Acknowledge With Error 8 Mask Position */
#define DSI_INT_MSK0_ACK_WITH_ERR_8_Msk       (_UINT32_(0x1) << DSI_INT_MSK0_ACK_WITH_ERR_8_Pos)   /* (DSI_INT_MSK0) Acknowledge With Error 8 Mask Mask */
#define DSI_INT_MSK0_ACK_WITH_ERR_8(value)    (DSI_INT_MSK0_ACK_WITH_ERR_8_Msk & (_UINT32_(value) << DSI_INT_MSK0_ACK_WITH_ERR_8_Pos)) /* Assigment of value for ACK_WITH_ERR_8 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_ACK_WITH_ERR_9_Pos       _UINT32_(9)                                          /* (DSI_INT_MSK0) Acknowledge With Error 9 Mask Position */
#define DSI_INT_MSK0_ACK_WITH_ERR_9_Msk       (_UINT32_(0x1) << DSI_INT_MSK0_ACK_WITH_ERR_9_Pos)   /* (DSI_INT_MSK0) Acknowledge With Error 9 Mask Mask */
#define DSI_INT_MSK0_ACK_WITH_ERR_9(value)    (DSI_INT_MSK0_ACK_WITH_ERR_9_Msk & (_UINT32_(value) << DSI_INT_MSK0_ACK_WITH_ERR_9_Pos)) /* Assigment of value for ACK_WITH_ERR_9 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_ACK_WITH_ERR_10_Pos      _UINT32_(10)                                         /* (DSI_INT_MSK0) Acknowledge With Error 10 Mask Position */
#define DSI_INT_MSK0_ACK_WITH_ERR_10_Msk      (_UINT32_(0x1) << DSI_INT_MSK0_ACK_WITH_ERR_10_Pos)  /* (DSI_INT_MSK0) Acknowledge With Error 10 Mask Mask */
#define DSI_INT_MSK0_ACK_WITH_ERR_10(value)   (DSI_INT_MSK0_ACK_WITH_ERR_10_Msk & (_UINT32_(value) << DSI_INT_MSK0_ACK_WITH_ERR_10_Pos)) /* Assigment of value for ACK_WITH_ERR_10 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_ACK_WITH_ERR_11_Pos      _UINT32_(11)                                         /* (DSI_INT_MSK0) Acknowledge With Error 11 Mask Position */
#define DSI_INT_MSK0_ACK_WITH_ERR_11_Msk      (_UINT32_(0x1) << DSI_INT_MSK0_ACK_WITH_ERR_11_Pos)  /* (DSI_INT_MSK0) Acknowledge With Error 11 Mask Mask */
#define DSI_INT_MSK0_ACK_WITH_ERR_11(value)   (DSI_INT_MSK0_ACK_WITH_ERR_11_Msk & (_UINT32_(value) << DSI_INT_MSK0_ACK_WITH_ERR_11_Pos)) /* Assigment of value for ACK_WITH_ERR_11 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_ACK_WITH_ERR_12_Pos      _UINT32_(12)                                         /* (DSI_INT_MSK0) Acknowledge With Error 12 Mask Position */
#define DSI_INT_MSK0_ACK_WITH_ERR_12_Msk      (_UINT32_(0x1) << DSI_INT_MSK0_ACK_WITH_ERR_12_Pos)  /* (DSI_INT_MSK0) Acknowledge With Error 12 Mask Mask */
#define DSI_INT_MSK0_ACK_WITH_ERR_12(value)   (DSI_INT_MSK0_ACK_WITH_ERR_12_Msk & (_UINT32_(value) << DSI_INT_MSK0_ACK_WITH_ERR_12_Pos)) /* Assigment of value for ACK_WITH_ERR_12 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_ACK_WITH_ERR_13_Pos      _UINT32_(13)                                         /* (DSI_INT_MSK0) Acknowledge With Error 13 Mask Position */
#define DSI_INT_MSK0_ACK_WITH_ERR_13_Msk      (_UINT32_(0x1) << DSI_INT_MSK0_ACK_WITH_ERR_13_Pos)  /* (DSI_INT_MSK0) Acknowledge With Error 13 Mask Mask */
#define DSI_INT_MSK0_ACK_WITH_ERR_13(value)   (DSI_INT_MSK0_ACK_WITH_ERR_13_Msk & (_UINT32_(value) << DSI_INT_MSK0_ACK_WITH_ERR_13_Pos)) /* Assigment of value for ACK_WITH_ERR_13 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_ACK_WITH_ERR_14_Pos      _UINT32_(14)                                         /* (DSI_INT_MSK0) Acknowledge With Error 14 Mask Position */
#define DSI_INT_MSK0_ACK_WITH_ERR_14_Msk      (_UINT32_(0x1) << DSI_INT_MSK0_ACK_WITH_ERR_14_Pos)  /* (DSI_INT_MSK0) Acknowledge With Error 14 Mask Mask */
#define DSI_INT_MSK0_ACK_WITH_ERR_14(value)   (DSI_INT_MSK0_ACK_WITH_ERR_14_Msk & (_UINT32_(value) << DSI_INT_MSK0_ACK_WITH_ERR_14_Pos)) /* Assigment of value for ACK_WITH_ERR_14 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_ACK_WITH_ERR_15_Pos      _UINT32_(15)                                         /* (DSI_INT_MSK0) Acknowledge With Error 15 Mask Position */
#define DSI_INT_MSK0_ACK_WITH_ERR_15_Msk      (_UINT32_(0x1) << DSI_INT_MSK0_ACK_WITH_ERR_15_Pos)  /* (DSI_INT_MSK0) Acknowledge With Error 15 Mask Mask */
#define DSI_INT_MSK0_ACK_WITH_ERR_15(value)   (DSI_INT_MSK0_ACK_WITH_ERR_15_Msk & (_UINT32_(value) << DSI_INT_MSK0_ACK_WITH_ERR_15_Pos)) /* Assigment of value for ACK_WITH_ERR_15 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_DPHY_ERRORS_0_Pos        _UINT32_(16)                                         /* (DSI_INT_MSK0) D-PHY Errors Lane 0 Mask Position */
#define DSI_INT_MSK0_DPHY_ERRORS_0_Msk        (_UINT32_(0x1) << DSI_INT_MSK0_DPHY_ERRORS_0_Pos)    /* (DSI_INT_MSK0) D-PHY Errors Lane 0 Mask Mask */
#define DSI_INT_MSK0_DPHY_ERRORS_0(value)     (DSI_INT_MSK0_DPHY_ERRORS_0_Msk & (_UINT32_(value) << DSI_INT_MSK0_DPHY_ERRORS_0_Pos)) /* Assigment of value for DPHY_ERRORS_0 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_DPHY_ERRORS_1_Pos        _UINT32_(17)                                         /* (DSI_INT_MSK0) D-PHY Errors Lane 1 Mask Position */
#define DSI_INT_MSK0_DPHY_ERRORS_1_Msk        (_UINT32_(0x1) << DSI_INT_MSK0_DPHY_ERRORS_1_Pos)    /* (DSI_INT_MSK0) D-PHY Errors Lane 1 Mask Mask */
#define DSI_INT_MSK0_DPHY_ERRORS_1(value)     (DSI_INT_MSK0_DPHY_ERRORS_1_Msk & (_UINT32_(value) << DSI_INT_MSK0_DPHY_ERRORS_1_Pos)) /* Assigment of value for DPHY_ERRORS_1 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_DPHY_ERRORS_2_Pos        _UINT32_(18)                                         /* (DSI_INT_MSK0) D-PHY Errors Lane 2 Mask Position */
#define DSI_INT_MSK0_DPHY_ERRORS_2_Msk        (_UINT32_(0x1) << DSI_INT_MSK0_DPHY_ERRORS_2_Pos)    /* (DSI_INT_MSK0) D-PHY Errors Lane 2 Mask Mask */
#define DSI_INT_MSK0_DPHY_ERRORS_2(value)     (DSI_INT_MSK0_DPHY_ERRORS_2_Msk & (_UINT32_(value) << DSI_INT_MSK0_DPHY_ERRORS_2_Pos)) /* Assigment of value for DPHY_ERRORS_2 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_DPHY_ERRORS_3_Pos        _UINT32_(19)                                         /* (DSI_INT_MSK0) D-PHY Errors Lane 3 Mask Position */
#define DSI_INT_MSK0_DPHY_ERRORS_3_Msk        (_UINT32_(0x1) << DSI_INT_MSK0_DPHY_ERRORS_3_Pos)    /* (DSI_INT_MSK0) D-PHY Errors Lane 3 Mask Mask */
#define DSI_INT_MSK0_DPHY_ERRORS_3(value)     (DSI_INT_MSK0_DPHY_ERRORS_3_Msk & (_UINT32_(value) << DSI_INT_MSK0_DPHY_ERRORS_3_Pos)) /* Assigment of value for DPHY_ERRORS_3 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_DPHY_ERRORS_4_Pos        _UINT32_(20)                                         /* (DSI_INT_MSK0) D-PHY Errors Lane 4 Mask Position */
#define DSI_INT_MSK0_DPHY_ERRORS_4_Msk        (_UINT32_(0x1) << DSI_INT_MSK0_DPHY_ERRORS_4_Pos)    /* (DSI_INT_MSK0) D-PHY Errors Lane 4 Mask Mask */
#define DSI_INT_MSK0_DPHY_ERRORS_4(value)     (DSI_INT_MSK0_DPHY_ERRORS_4_Msk & (_UINT32_(value) << DSI_INT_MSK0_DPHY_ERRORS_4_Pos)) /* Assigment of value for DPHY_ERRORS_4 in the DSI_INT_MSK0 register */
#define DSI_INT_MSK0_Msk                      _UINT32_(0x001FFFFF)                                 /* (DSI_INT_MSK0) Register Mask  */

#define DSI_INT_MSK0_ACK_WITH_ERR__Pos        _UINT32_(0)                                          /* (DSI_INT_MSK0 Position) Acknowledge With Error x Mask */
#define DSI_INT_MSK0_ACK_WITH_ERR__Msk        (_UINT32_(0xFFFF) << DSI_INT_MSK0_ACK_WITH_ERR__Pos) /* (DSI_INT_MSK0 Mask) ACK_WITH_ERR_ */
#define DSI_INT_MSK0_ACK_WITH_ERR_(value)     (DSI_INT_MSK0_ACK_WITH_ERR__Msk & (_UINT32_(value) << DSI_INT_MSK0_ACK_WITH_ERR__Pos)) 
#define DSI_INT_MSK0_DPHY_ERRORS__Pos         _UINT32_(16)                                         /* (DSI_INT_MSK0 Position) D-PHY Errors Lane 4 Mask */
#define DSI_INT_MSK0_DPHY_ERRORS__Msk         (_UINT32_(0x1F) << DSI_INT_MSK0_DPHY_ERRORS__Pos)    /* (DSI_INT_MSK0 Mask) DPHY_ERRORS_ */
#define DSI_INT_MSK0_DPHY_ERRORS_(value)      (DSI_INT_MSK0_DPHY_ERRORS__Msk & (_UINT32_(value) << DSI_INT_MSK0_DPHY_ERRORS__Pos)) 

/* -------- DSI_INT_MSK1 : (DSI Offset: 0xC8) (R/W 32) Interrupt Mask Configuration Register 1 -------- */
#define DSI_INT_MSK1_RESETVALUE               _UINT32_(0x00)                                       /*  (DSI_INT_MSK1) Interrupt Mask Configuration Register 1  Reset Value */

#define DSI_INT_MSK1_TO_HS_TX_Pos             _UINT32_(0)                                          /* (DSI_INT_MSK1) Timeout High-Speed Transmission Mask Position */
#define DSI_INT_MSK1_TO_HS_TX_Msk             (_UINT32_(0x1) << DSI_INT_MSK1_TO_HS_TX_Pos)         /* (DSI_INT_MSK1) Timeout High-Speed Transmission Mask Mask */
#define DSI_INT_MSK1_TO_HS_TX(value)          (DSI_INT_MSK1_TO_HS_TX_Msk & (_UINT32_(value) << DSI_INT_MSK1_TO_HS_TX_Pos)) /* Assigment of value for TO_HS_TX in the DSI_INT_MSK1 register */
#define DSI_INT_MSK1_TO_LP_RX_Pos             _UINT32_(1)                                          /* (DSI_INT_MSK1) Timeout Low-Power Reception Mask Position */
#define DSI_INT_MSK1_TO_LP_RX_Msk             (_UINT32_(0x1) << DSI_INT_MSK1_TO_LP_RX_Pos)         /* (DSI_INT_MSK1) Timeout Low-Power Reception Mask Mask */
#define DSI_INT_MSK1_TO_LP_RX(value)          (DSI_INT_MSK1_TO_LP_RX_Msk & (_UINT32_(value) << DSI_INT_MSK1_TO_LP_RX_Pos)) /* Assigment of value for TO_LP_RX in the DSI_INT_MSK1 register */
#define DSI_INT_MSK1_ECC_SINGLE_ERR_Pos       _UINT32_(2)                                          /* (DSI_INT_MSK1) ECC Single Error Mask Position */
#define DSI_INT_MSK1_ECC_SINGLE_ERR_Msk       (_UINT32_(0x1) << DSI_INT_MSK1_ECC_SINGLE_ERR_Pos)   /* (DSI_INT_MSK1) ECC Single Error Mask Mask */
#define DSI_INT_MSK1_ECC_SINGLE_ERR(value)    (DSI_INT_MSK1_ECC_SINGLE_ERR_Msk & (_UINT32_(value) << DSI_INT_MSK1_ECC_SINGLE_ERR_Pos)) /* Assigment of value for ECC_SINGLE_ERR in the DSI_INT_MSK1 register */
#define DSI_INT_MSK1_ECC_MULTI_ERR_Pos        _UINT32_(3)                                          /* (DSI_INT_MSK1) ECC Multiple Error Mask Position */
#define DSI_INT_MSK1_ECC_MULTI_ERR_Msk        (_UINT32_(0x1) << DSI_INT_MSK1_ECC_MULTI_ERR_Pos)    /* (DSI_INT_MSK1) ECC Multiple Error Mask Mask */
#define DSI_INT_MSK1_ECC_MULTI_ERR(value)     (DSI_INT_MSK1_ECC_MULTI_ERR_Msk & (_UINT32_(value) << DSI_INT_MSK1_ECC_MULTI_ERR_Pos)) /* Assigment of value for ECC_MULTI_ERR in the DSI_INT_MSK1 register */
#define DSI_INT_MSK1_CRC_ERR_Pos              _UINT32_(4)                                          /* (DSI_INT_MSK1) CRC Error Mask Position */
#define DSI_INT_MSK1_CRC_ERR_Msk              (_UINT32_(0x1) << DSI_INT_MSK1_CRC_ERR_Pos)          /* (DSI_INT_MSK1) CRC Error Mask Mask */
#define DSI_INT_MSK1_CRC_ERR(value)           (DSI_INT_MSK1_CRC_ERR_Msk & (_UINT32_(value) << DSI_INT_MSK1_CRC_ERR_Pos)) /* Assigment of value for CRC_ERR in the DSI_INT_MSK1 register */
#define DSI_INT_MSK1_PKT_SIZE_ERR_Pos         _UINT32_(5)                                          /* (DSI_INT_MSK1) Packet Size Error Mask Position */
#define DSI_INT_MSK1_PKT_SIZE_ERR_Msk         (_UINT32_(0x1) << DSI_INT_MSK1_PKT_SIZE_ERR_Pos)     /* (DSI_INT_MSK1) Packet Size Error Mask Mask */
#define DSI_INT_MSK1_PKT_SIZE_ERR(value)      (DSI_INT_MSK1_PKT_SIZE_ERR_Msk & (_UINT32_(value) << DSI_INT_MSK1_PKT_SIZE_ERR_Pos)) /* Assigment of value for PKT_SIZE_ERR in the DSI_INT_MSK1 register */
#define DSI_INT_MSK1_EOTP_ERR_Pos             _UINT32_(6)                                          /* (DSI_INT_MSK1) End Of Transmission Packet Error Mask Position */
#define DSI_INT_MSK1_EOTP_ERR_Msk             (_UINT32_(0x1) << DSI_INT_MSK1_EOTP_ERR_Pos)         /* (DSI_INT_MSK1) End Of Transmission Packet Error Mask Mask */
#define DSI_INT_MSK1_EOTP_ERR(value)          (DSI_INT_MSK1_EOTP_ERR_Msk & (_UINT32_(value) << DSI_INT_MSK1_EOTP_ERR_Pos)) /* Assigment of value for EOTP_ERR in the DSI_INT_MSK1 register */
#define DSI_INT_MSK1_DPI_PLD_WR_ERR_Pos       _UINT32_(7)                                          /* (DSI_INT_MSK1) Input Video Payload Write Error Mask Position */
#define DSI_INT_MSK1_DPI_PLD_WR_ERR_Msk       (_UINT32_(0x1) << DSI_INT_MSK1_DPI_PLD_WR_ERR_Pos)   /* (DSI_INT_MSK1) Input Video Payload Write Error Mask Mask */
#define DSI_INT_MSK1_DPI_PLD_WR_ERR(value)    (DSI_INT_MSK1_DPI_PLD_WR_ERR_Msk & (_UINT32_(value) << DSI_INT_MSK1_DPI_PLD_WR_ERR_Pos)) /* Assigment of value for DPI_PLD_WR_ERR in the DSI_INT_MSK1 register */
#define DSI_INT_MSK1_GEN_CMD_WR_ERR_Pos       _UINT32_(8)                                          /* (DSI_INT_MSK1) Generic Interface Command Write Error Mask Position */
#define DSI_INT_MSK1_GEN_CMD_WR_ERR_Msk       (_UINT32_(0x1) << DSI_INT_MSK1_GEN_CMD_WR_ERR_Pos)   /* (DSI_INT_MSK1) Generic Interface Command Write Error Mask Mask */
#define DSI_INT_MSK1_GEN_CMD_WR_ERR(value)    (DSI_INT_MSK1_GEN_CMD_WR_ERR_Msk & (_UINT32_(value) << DSI_INT_MSK1_GEN_CMD_WR_ERR_Pos)) /* Assigment of value for GEN_CMD_WR_ERR in the DSI_INT_MSK1 register */
#define DSI_INT_MSK1_GEN_PLD_WR_ERR_Pos       _UINT32_(9)                                          /* (DSI_INT_MSK1) Generic Interface Payload Write Error Mask Position */
#define DSI_INT_MSK1_GEN_PLD_WR_ERR_Msk       (_UINT32_(0x1) << DSI_INT_MSK1_GEN_PLD_WR_ERR_Pos)   /* (DSI_INT_MSK1) Generic Interface Payload Write Error Mask Mask */
#define DSI_INT_MSK1_GEN_PLD_WR_ERR(value)    (DSI_INT_MSK1_GEN_PLD_WR_ERR_Msk & (_UINT32_(value) << DSI_INT_MSK1_GEN_PLD_WR_ERR_Pos)) /* Assigment of value for GEN_PLD_WR_ERR in the DSI_INT_MSK1 register */
#define DSI_INT_MSK1_GEN_PLD_SEND_ERR_Pos     _UINT32_(10)                                         /* (DSI_INT_MSK1) Generic Interface Payload Send Error Mask Position */
#define DSI_INT_MSK1_GEN_PLD_SEND_ERR_Msk     (_UINT32_(0x1) << DSI_INT_MSK1_GEN_PLD_SEND_ERR_Pos) /* (DSI_INT_MSK1) Generic Interface Payload Send Error Mask Mask */
#define DSI_INT_MSK1_GEN_PLD_SEND_ERR(value)  (DSI_INT_MSK1_GEN_PLD_SEND_ERR_Msk & (_UINT32_(value) << DSI_INT_MSK1_GEN_PLD_SEND_ERR_Pos)) /* Assigment of value for GEN_PLD_SEND_ERR in the DSI_INT_MSK1 register */
#define DSI_INT_MSK1_GEN_PLD_RD_ERR_Pos       _UINT32_(11)                                         /* (DSI_INT_MSK1) Generic Interface Payload Read Error Mask Position */
#define DSI_INT_MSK1_GEN_PLD_RD_ERR_Msk       (_UINT32_(0x1) << DSI_INT_MSK1_GEN_PLD_RD_ERR_Pos)   /* (DSI_INT_MSK1) Generic Interface Payload Read Error Mask Mask */
#define DSI_INT_MSK1_GEN_PLD_RD_ERR(value)    (DSI_INT_MSK1_GEN_PLD_RD_ERR_Msk & (_UINT32_(value) << DSI_INT_MSK1_GEN_PLD_RD_ERR_Pos)) /* Assigment of value for GEN_PLD_RD_ERR in the DSI_INT_MSK1 register */
#define DSI_INT_MSK1_GEN_PLD_RECEV_ERR_Pos    _UINT32_(12)                                         /* (DSI_INT_MSK1) Generic Interface Payload Receive Error Mask Position */
#define DSI_INT_MSK1_GEN_PLD_RECEV_ERR_Msk    (_UINT32_(0x1) << DSI_INT_MSK1_GEN_PLD_RECEV_ERR_Pos) /* (DSI_INT_MSK1) Generic Interface Payload Receive Error Mask Mask */
#define DSI_INT_MSK1_GEN_PLD_RECEV_ERR(value) (DSI_INT_MSK1_GEN_PLD_RECEV_ERR_Msk & (_UINT32_(value) << DSI_INT_MSK1_GEN_PLD_RECEV_ERR_Pos)) /* Assigment of value for GEN_PLD_RECEV_ERR in the DSI_INT_MSK1 register */
#define DSI_INT_MSK1_Msk                      _UINT32_(0x00001FFF)                                 /* (DSI_INT_MSK1) Register Mask  */


/* -------- DSI_DPHY_CAL : (DSI Offset: 0xCC) (R/W 32) D-PHY Calibration Control Register -------- */
#define DSI_DPHY_CAL_RESETVALUE               _UINT32_(0x00)                                       /*  (DSI_DPHY_CAL) D-PHY Calibration Control Register  Reset Value */

#define DSI_DPHY_CAL_TXSKEWCALHS_Pos          _UINT32_(0)                                          /* (DSI_DPHY_CAL) Transmission Skew Calibration High-Speed Position */
#define DSI_DPHY_CAL_TXSKEWCALHS_Msk          (_UINT32_(0x1) << DSI_DPHY_CAL_TXSKEWCALHS_Pos)      /* (DSI_DPHY_CAL) Transmission Skew Calibration High-Speed Mask */
#define DSI_DPHY_CAL_TXSKEWCALHS(value)       (DSI_DPHY_CAL_TXSKEWCALHS_Msk & (_UINT32_(value) << DSI_DPHY_CAL_TXSKEWCALHS_Pos)) /* Assigment of value for TXSKEWCALHS in the DSI_DPHY_CAL register */
#define DSI_DPHY_CAL_Msk                      _UINT32_(0x00000001)                                 /* (DSI_DPHY_CAL) Register Mask  */


/* -------- DSI_INT_FORCE0 : (DSI Offset: 0xD8) (R/W 32) Interrupt Force Control Register 0 -------- */
#define DSI_INT_FORCE0_RESETVALUE             _UINT32_(0x00)                                       /*  (DSI_INT_FORCE0) Interrupt Force Control Register 0  Reset Value */

#define DSI_INT_FORCE0_ACK_WITH_ERR_0_Pos     _UINT32_(0)                                          /* (DSI_INT_FORCE0) Acknowledge With Error 0 Force Position */
#define DSI_INT_FORCE0_ACK_WITH_ERR_0_Msk     (_UINT32_(0x1) << DSI_INT_FORCE0_ACK_WITH_ERR_0_Pos) /* (DSI_INT_FORCE0) Acknowledge With Error 0 Force Mask */
#define DSI_INT_FORCE0_ACK_WITH_ERR_0(value)  (DSI_INT_FORCE0_ACK_WITH_ERR_0_Msk & (_UINT32_(value) << DSI_INT_FORCE0_ACK_WITH_ERR_0_Pos)) /* Assigment of value for ACK_WITH_ERR_0 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_ACK_WITH_ERR_1_Pos     _UINT32_(1)                                          /* (DSI_INT_FORCE0) Acknowledge With Error 1 Force Position */
#define DSI_INT_FORCE0_ACK_WITH_ERR_1_Msk     (_UINT32_(0x1) << DSI_INT_FORCE0_ACK_WITH_ERR_1_Pos) /* (DSI_INT_FORCE0) Acknowledge With Error 1 Force Mask */
#define DSI_INT_FORCE0_ACK_WITH_ERR_1(value)  (DSI_INT_FORCE0_ACK_WITH_ERR_1_Msk & (_UINT32_(value) << DSI_INT_FORCE0_ACK_WITH_ERR_1_Pos)) /* Assigment of value for ACK_WITH_ERR_1 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_ACK_WITH_ERR_2_Pos     _UINT32_(2)                                          /* (DSI_INT_FORCE0) Acknowledge With Error 2 Force Position */
#define DSI_INT_FORCE0_ACK_WITH_ERR_2_Msk     (_UINT32_(0x1) << DSI_INT_FORCE0_ACK_WITH_ERR_2_Pos) /* (DSI_INT_FORCE0) Acknowledge With Error 2 Force Mask */
#define DSI_INT_FORCE0_ACK_WITH_ERR_2(value)  (DSI_INT_FORCE0_ACK_WITH_ERR_2_Msk & (_UINT32_(value) << DSI_INT_FORCE0_ACK_WITH_ERR_2_Pos)) /* Assigment of value for ACK_WITH_ERR_2 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_ACK_WITH_ERR_3_Pos     _UINT32_(3)                                          /* (DSI_INT_FORCE0) Acknowledge With Error 3 Force Position */
#define DSI_INT_FORCE0_ACK_WITH_ERR_3_Msk     (_UINT32_(0x1) << DSI_INT_FORCE0_ACK_WITH_ERR_3_Pos) /* (DSI_INT_FORCE0) Acknowledge With Error 3 Force Mask */
#define DSI_INT_FORCE0_ACK_WITH_ERR_3(value)  (DSI_INT_FORCE0_ACK_WITH_ERR_3_Msk & (_UINT32_(value) << DSI_INT_FORCE0_ACK_WITH_ERR_3_Pos)) /* Assigment of value for ACK_WITH_ERR_3 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_ACK_WITH_ERR_4_Pos     _UINT32_(4)                                          /* (DSI_INT_FORCE0) Acknowledge With Error 4 Force Position */
#define DSI_INT_FORCE0_ACK_WITH_ERR_4_Msk     (_UINT32_(0x1) << DSI_INT_FORCE0_ACK_WITH_ERR_4_Pos) /* (DSI_INT_FORCE0) Acknowledge With Error 4 Force Mask */
#define DSI_INT_FORCE0_ACK_WITH_ERR_4(value)  (DSI_INT_FORCE0_ACK_WITH_ERR_4_Msk & (_UINT32_(value) << DSI_INT_FORCE0_ACK_WITH_ERR_4_Pos)) /* Assigment of value for ACK_WITH_ERR_4 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_ACK_WITH_ERR_5_Pos     _UINT32_(5)                                          /* (DSI_INT_FORCE0) Acknowledge With Error 5 Force Position */
#define DSI_INT_FORCE0_ACK_WITH_ERR_5_Msk     (_UINT32_(0x1) << DSI_INT_FORCE0_ACK_WITH_ERR_5_Pos) /* (DSI_INT_FORCE0) Acknowledge With Error 5 Force Mask */
#define DSI_INT_FORCE0_ACK_WITH_ERR_5(value)  (DSI_INT_FORCE0_ACK_WITH_ERR_5_Msk & (_UINT32_(value) << DSI_INT_FORCE0_ACK_WITH_ERR_5_Pos)) /* Assigment of value for ACK_WITH_ERR_5 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_ACK_WITH_ERR_6_Pos     _UINT32_(6)                                          /* (DSI_INT_FORCE0) Acknowledge With Error 6 Force Position */
#define DSI_INT_FORCE0_ACK_WITH_ERR_6_Msk     (_UINT32_(0x1) << DSI_INT_FORCE0_ACK_WITH_ERR_6_Pos) /* (DSI_INT_FORCE0) Acknowledge With Error 6 Force Mask */
#define DSI_INT_FORCE0_ACK_WITH_ERR_6(value)  (DSI_INT_FORCE0_ACK_WITH_ERR_6_Msk & (_UINT32_(value) << DSI_INT_FORCE0_ACK_WITH_ERR_6_Pos)) /* Assigment of value for ACK_WITH_ERR_6 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_ACK_WITH_ERR_7_Pos     _UINT32_(7)                                          /* (DSI_INT_FORCE0) Acknowledge With Error 7 Force Position */
#define DSI_INT_FORCE0_ACK_WITH_ERR_7_Msk     (_UINT32_(0x1) << DSI_INT_FORCE0_ACK_WITH_ERR_7_Pos) /* (DSI_INT_FORCE0) Acknowledge With Error 7 Force Mask */
#define DSI_INT_FORCE0_ACK_WITH_ERR_7(value)  (DSI_INT_FORCE0_ACK_WITH_ERR_7_Msk & (_UINT32_(value) << DSI_INT_FORCE0_ACK_WITH_ERR_7_Pos)) /* Assigment of value for ACK_WITH_ERR_7 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_ACK_WITH_ERR_8_Pos     _UINT32_(8)                                          /* (DSI_INT_FORCE0) Acknowledge With Error 8 Force Position */
#define DSI_INT_FORCE0_ACK_WITH_ERR_8_Msk     (_UINT32_(0x1) << DSI_INT_FORCE0_ACK_WITH_ERR_8_Pos) /* (DSI_INT_FORCE0) Acknowledge With Error 8 Force Mask */
#define DSI_INT_FORCE0_ACK_WITH_ERR_8(value)  (DSI_INT_FORCE0_ACK_WITH_ERR_8_Msk & (_UINT32_(value) << DSI_INT_FORCE0_ACK_WITH_ERR_8_Pos)) /* Assigment of value for ACK_WITH_ERR_8 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_ACK_WITH_ERR_9_Pos     _UINT32_(9)                                          /* (DSI_INT_FORCE0) Acknowledge With Error 9 Force Position */
#define DSI_INT_FORCE0_ACK_WITH_ERR_9_Msk     (_UINT32_(0x1) << DSI_INT_FORCE0_ACK_WITH_ERR_9_Pos) /* (DSI_INT_FORCE0) Acknowledge With Error 9 Force Mask */
#define DSI_INT_FORCE0_ACK_WITH_ERR_9(value)  (DSI_INT_FORCE0_ACK_WITH_ERR_9_Msk & (_UINT32_(value) << DSI_INT_FORCE0_ACK_WITH_ERR_9_Pos)) /* Assigment of value for ACK_WITH_ERR_9 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_ACK_WITH_ERR_10_Pos    _UINT32_(10)                                         /* (DSI_INT_FORCE0) Acknowledge With Error 10 Force Position */
#define DSI_INT_FORCE0_ACK_WITH_ERR_10_Msk    (_UINT32_(0x1) << DSI_INT_FORCE0_ACK_WITH_ERR_10_Pos) /* (DSI_INT_FORCE0) Acknowledge With Error 10 Force Mask */
#define DSI_INT_FORCE0_ACK_WITH_ERR_10(value) (DSI_INT_FORCE0_ACK_WITH_ERR_10_Msk & (_UINT32_(value) << DSI_INT_FORCE0_ACK_WITH_ERR_10_Pos)) /* Assigment of value for ACK_WITH_ERR_10 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_ACK_WITH_ERR_11_Pos    _UINT32_(11)                                         /* (DSI_INT_FORCE0) Acknowledge With Error 11 Force Position */
#define DSI_INT_FORCE0_ACK_WITH_ERR_11_Msk    (_UINT32_(0x1) << DSI_INT_FORCE0_ACK_WITH_ERR_11_Pos) /* (DSI_INT_FORCE0) Acknowledge With Error 11 Force Mask */
#define DSI_INT_FORCE0_ACK_WITH_ERR_11(value) (DSI_INT_FORCE0_ACK_WITH_ERR_11_Msk & (_UINT32_(value) << DSI_INT_FORCE0_ACK_WITH_ERR_11_Pos)) /* Assigment of value for ACK_WITH_ERR_11 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_ACK_WITH_ERR_12_Pos    _UINT32_(12)                                         /* (DSI_INT_FORCE0) Acknowledge With Error 12 Force Position */
#define DSI_INT_FORCE0_ACK_WITH_ERR_12_Msk    (_UINT32_(0x1) << DSI_INT_FORCE0_ACK_WITH_ERR_12_Pos) /* (DSI_INT_FORCE0) Acknowledge With Error 12 Force Mask */
#define DSI_INT_FORCE0_ACK_WITH_ERR_12(value) (DSI_INT_FORCE0_ACK_WITH_ERR_12_Msk & (_UINT32_(value) << DSI_INT_FORCE0_ACK_WITH_ERR_12_Pos)) /* Assigment of value for ACK_WITH_ERR_12 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_ACK_WITH_ERR_13_Pos    _UINT32_(13)                                         /* (DSI_INT_FORCE0) Acknowledge With Error 13 Force Position */
#define DSI_INT_FORCE0_ACK_WITH_ERR_13_Msk    (_UINT32_(0x1) << DSI_INT_FORCE0_ACK_WITH_ERR_13_Pos) /* (DSI_INT_FORCE0) Acknowledge With Error 13 Force Mask */
#define DSI_INT_FORCE0_ACK_WITH_ERR_13(value) (DSI_INT_FORCE0_ACK_WITH_ERR_13_Msk & (_UINT32_(value) << DSI_INT_FORCE0_ACK_WITH_ERR_13_Pos)) /* Assigment of value for ACK_WITH_ERR_13 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_ACK_WITH_ERR_14_Pos    _UINT32_(14)                                         /* (DSI_INT_FORCE0) Acknowledge With Error 14 Force Position */
#define DSI_INT_FORCE0_ACK_WITH_ERR_14_Msk    (_UINT32_(0x1) << DSI_INT_FORCE0_ACK_WITH_ERR_14_Pos) /* (DSI_INT_FORCE0) Acknowledge With Error 14 Force Mask */
#define DSI_INT_FORCE0_ACK_WITH_ERR_14(value) (DSI_INT_FORCE0_ACK_WITH_ERR_14_Msk & (_UINT32_(value) << DSI_INT_FORCE0_ACK_WITH_ERR_14_Pos)) /* Assigment of value for ACK_WITH_ERR_14 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_ACK_WITH_ERR_15_Pos    _UINT32_(15)                                         /* (DSI_INT_FORCE0) Acknowledge With Error 15 Force Position */
#define DSI_INT_FORCE0_ACK_WITH_ERR_15_Msk    (_UINT32_(0x1) << DSI_INT_FORCE0_ACK_WITH_ERR_15_Pos) /* (DSI_INT_FORCE0) Acknowledge With Error 15 Force Mask */
#define DSI_INT_FORCE0_ACK_WITH_ERR_15(value) (DSI_INT_FORCE0_ACK_WITH_ERR_15_Msk & (_UINT32_(value) << DSI_INT_FORCE0_ACK_WITH_ERR_15_Pos)) /* Assigment of value for ACK_WITH_ERR_15 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_DPHY_ERRORS_0_Pos      _UINT32_(16)                                         /* (DSI_INT_FORCE0) D-PHY Errors 0 Force Position */
#define DSI_INT_FORCE0_DPHY_ERRORS_0_Msk      (_UINT32_(0x1) << DSI_INT_FORCE0_DPHY_ERRORS_0_Pos)  /* (DSI_INT_FORCE0) D-PHY Errors 0 Force Mask */
#define DSI_INT_FORCE0_DPHY_ERRORS_0(value)   (DSI_INT_FORCE0_DPHY_ERRORS_0_Msk & (_UINT32_(value) << DSI_INT_FORCE0_DPHY_ERRORS_0_Pos)) /* Assigment of value for DPHY_ERRORS_0 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_DPHY_ERRORS_1_Pos      _UINT32_(17)                                         /* (DSI_INT_FORCE0) D-PHY Errors 1 Force Position */
#define DSI_INT_FORCE0_DPHY_ERRORS_1_Msk      (_UINT32_(0x1) << DSI_INT_FORCE0_DPHY_ERRORS_1_Pos)  /* (DSI_INT_FORCE0) D-PHY Errors 1 Force Mask */
#define DSI_INT_FORCE0_DPHY_ERRORS_1(value)   (DSI_INT_FORCE0_DPHY_ERRORS_1_Msk & (_UINT32_(value) << DSI_INT_FORCE0_DPHY_ERRORS_1_Pos)) /* Assigment of value for DPHY_ERRORS_1 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_DPHY_ERRORS_2_Pos      _UINT32_(18)                                         /* (DSI_INT_FORCE0) D-PHY Errors 2 Force Position */
#define DSI_INT_FORCE0_DPHY_ERRORS_2_Msk      (_UINT32_(0x1) << DSI_INT_FORCE0_DPHY_ERRORS_2_Pos)  /* (DSI_INT_FORCE0) D-PHY Errors 2 Force Mask */
#define DSI_INT_FORCE0_DPHY_ERRORS_2(value)   (DSI_INT_FORCE0_DPHY_ERRORS_2_Msk & (_UINT32_(value) << DSI_INT_FORCE0_DPHY_ERRORS_2_Pos)) /* Assigment of value for DPHY_ERRORS_2 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_DPHY_ERRORS_3_Pos      _UINT32_(19)                                         /* (DSI_INT_FORCE0) D-PHY Errors 3 Force Position */
#define DSI_INT_FORCE0_DPHY_ERRORS_3_Msk      (_UINT32_(0x1) << DSI_INT_FORCE0_DPHY_ERRORS_3_Pos)  /* (DSI_INT_FORCE0) D-PHY Errors 3 Force Mask */
#define DSI_INT_FORCE0_DPHY_ERRORS_3(value)   (DSI_INT_FORCE0_DPHY_ERRORS_3_Msk & (_UINT32_(value) << DSI_INT_FORCE0_DPHY_ERRORS_3_Pos)) /* Assigment of value for DPHY_ERRORS_3 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_DPHY_ERRORS_4_Pos      _UINT32_(20)                                         /* (DSI_INT_FORCE0) D-PHY Errors 4 Force Position */
#define DSI_INT_FORCE0_DPHY_ERRORS_4_Msk      (_UINT32_(0x1) << DSI_INT_FORCE0_DPHY_ERRORS_4_Pos)  /* (DSI_INT_FORCE0) D-PHY Errors 4 Force Mask */
#define DSI_INT_FORCE0_DPHY_ERRORS_4(value)   (DSI_INT_FORCE0_DPHY_ERRORS_4_Msk & (_UINT32_(value) << DSI_INT_FORCE0_DPHY_ERRORS_4_Pos)) /* Assigment of value for DPHY_ERRORS_4 in the DSI_INT_FORCE0 register */
#define DSI_INT_FORCE0_Msk                    _UINT32_(0x001FFFFF)                                 /* (DSI_INT_FORCE0) Register Mask  */

#define DSI_INT_FORCE0_ACK_WITH_ERR__Pos      _UINT32_(0)                                          /* (DSI_INT_FORCE0 Position) Acknowledge With Error x Force */
#define DSI_INT_FORCE0_ACK_WITH_ERR__Msk      (_UINT32_(0xFFFF) << DSI_INT_FORCE0_ACK_WITH_ERR__Pos) /* (DSI_INT_FORCE0 Mask) ACK_WITH_ERR_ */
#define DSI_INT_FORCE0_ACK_WITH_ERR_(value)   (DSI_INT_FORCE0_ACK_WITH_ERR__Msk & (_UINT32_(value) << DSI_INT_FORCE0_ACK_WITH_ERR__Pos)) 
#define DSI_INT_FORCE0_DPHY_ERRORS__Pos       _UINT32_(16)                                         /* (DSI_INT_FORCE0 Position) D-PHY Errors 4 Force */
#define DSI_INT_FORCE0_DPHY_ERRORS__Msk       (_UINT32_(0x1F) << DSI_INT_FORCE0_DPHY_ERRORS__Pos)  /* (DSI_INT_FORCE0 Mask) DPHY_ERRORS_ */
#define DSI_INT_FORCE0_DPHY_ERRORS_(value)    (DSI_INT_FORCE0_DPHY_ERRORS__Msk & (_UINT32_(value) << DSI_INT_FORCE0_DPHY_ERRORS__Pos)) 

/* -------- DSI_INT_FORCE1 : (DSI Offset: 0xDC) (R/W 32) Interrupt Force Control Register 1 -------- */
#define DSI_INT_FORCE1_RESETVALUE             _UINT32_(0x00)                                       /*  (DSI_INT_FORCE1) Interrupt Force Control Register 1  Reset Value */

#define DSI_INT_FORCE1_TO_HS_TX_Pos           _UINT32_(0)                                          /* (DSI_INT_FORCE1) Timeout High-Speed Transmission Force Position */
#define DSI_INT_FORCE1_TO_HS_TX_Msk           (_UINT32_(0x1) << DSI_INT_FORCE1_TO_HS_TX_Pos)       /* (DSI_INT_FORCE1) Timeout High-Speed Transmission Force Mask */
#define DSI_INT_FORCE1_TO_HS_TX(value)        (DSI_INT_FORCE1_TO_HS_TX_Msk & (_UINT32_(value) << DSI_INT_FORCE1_TO_HS_TX_Pos)) /* Assigment of value for TO_HS_TX in the DSI_INT_FORCE1 register */
#define DSI_INT_FORCE1_TO_LP_RX_Pos           _UINT32_(1)                                          /* (DSI_INT_FORCE1) Timeout Low-Power Reception Force Position */
#define DSI_INT_FORCE1_TO_LP_RX_Msk           (_UINT32_(0x1) << DSI_INT_FORCE1_TO_LP_RX_Pos)       /* (DSI_INT_FORCE1) Timeout Low-Power Reception Force Mask */
#define DSI_INT_FORCE1_TO_LP_RX(value)        (DSI_INT_FORCE1_TO_LP_RX_Msk & (_UINT32_(value) << DSI_INT_FORCE1_TO_LP_RX_Pos)) /* Assigment of value for TO_LP_RX in the DSI_INT_FORCE1 register */
#define DSI_INT_FORCE1_ECC_SINGLE_ERR_Pos     _UINT32_(2)                                          /* (DSI_INT_FORCE1) ECC Single Error Force Position */
#define DSI_INT_FORCE1_ECC_SINGLE_ERR_Msk     (_UINT32_(0x1) << DSI_INT_FORCE1_ECC_SINGLE_ERR_Pos) /* (DSI_INT_FORCE1) ECC Single Error Force Mask */
#define DSI_INT_FORCE1_ECC_SINGLE_ERR(value)  (DSI_INT_FORCE1_ECC_SINGLE_ERR_Msk & (_UINT32_(value) << DSI_INT_FORCE1_ECC_SINGLE_ERR_Pos)) /* Assigment of value for ECC_SINGLE_ERR in the DSI_INT_FORCE1 register */
#define DSI_INT_FORCE1_ECC_MULTI_ERR_Pos      _UINT32_(3)                                          /* (DSI_INT_FORCE1) ECC Multiple Error Force Position */
#define DSI_INT_FORCE1_ECC_MULTI_ERR_Msk      (_UINT32_(0x1) << DSI_INT_FORCE1_ECC_MULTI_ERR_Pos)  /* (DSI_INT_FORCE1) ECC Multiple Error Force Mask */
#define DSI_INT_FORCE1_ECC_MULTI_ERR(value)   (DSI_INT_FORCE1_ECC_MULTI_ERR_Msk & (_UINT32_(value) << DSI_INT_FORCE1_ECC_MULTI_ERR_Pos)) /* Assigment of value for ECC_MULTI_ERR in the DSI_INT_FORCE1 register */
#define DSI_INT_FORCE1_CRC_ERR_Pos            _UINT32_(4)                                          /* (DSI_INT_FORCE1) CRC Error Force Position */
#define DSI_INT_FORCE1_CRC_ERR_Msk            (_UINT32_(0x1) << DSI_INT_FORCE1_CRC_ERR_Pos)        /* (DSI_INT_FORCE1) CRC Error Force Mask */
#define DSI_INT_FORCE1_CRC_ERR(value)         (DSI_INT_FORCE1_CRC_ERR_Msk & (_UINT32_(value) << DSI_INT_FORCE1_CRC_ERR_Pos)) /* Assigment of value for CRC_ERR in the DSI_INT_FORCE1 register */
#define DSI_INT_FORCE1_PKT_SIZE_ERR_Pos       _UINT32_(5)                                          /* (DSI_INT_FORCE1) Packet Size error Force Position */
#define DSI_INT_FORCE1_PKT_SIZE_ERR_Msk       (_UINT32_(0x1) << DSI_INT_FORCE1_PKT_SIZE_ERR_Pos)   /* (DSI_INT_FORCE1) Packet Size error Force Mask */
#define DSI_INT_FORCE1_PKT_SIZE_ERR(value)    (DSI_INT_FORCE1_PKT_SIZE_ERR_Msk & (_UINT32_(value) << DSI_INT_FORCE1_PKT_SIZE_ERR_Pos)) /* Assigment of value for PKT_SIZE_ERR in the DSI_INT_FORCE1 register */
#define DSI_INT_FORCE1_EOTP_ERR_Pos           _UINT32_(6)                                          /* (DSI_INT_FORCE1) End Of Transmission Packet Error Force Position */
#define DSI_INT_FORCE1_EOTP_ERR_Msk           (_UINT32_(0x1) << DSI_INT_FORCE1_EOTP_ERR_Pos)       /* (DSI_INT_FORCE1) End Of Transmission Packet Error Force Mask */
#define DSI_INT_FORCE1_EOTP_ERR(value)        (DSI_INT_FORCE1_EOTP_ERR_Msk & (_UINT32_(value) << DSI_INT_FORCE1_EOTP_ERR_Pos)) /* Assigment of value for EOTP_ERR in the DSI_INT_FORCE1 register */
#define DSI_INT_FORCE1_DPI_PLD_WR_ERR_Pos     _UINT32_(7)                                          /* (DSI_INT_FORCE1) Input Video Interface Payload Write Error Force Position */
#define DSI_INT_FORCE1_DPI_PLD_WR_ERR_Msk     (_UINT32_(0x1) << DSI_INT_FORCE1_DPI_PLD_WR_ERR_Pos) /* (DSI_INT_FORCE1) Input Video Interface Payload Write Error Force Mask */
#define DSI_INT_FORCE1_DPI_PLD_WR_ERR(value)  (DSI_INT_FORCE1_DPI_PLD_WR_ERR_Msk & (_UINT32_(value) << DSI_INT_FORCE1_DPI_PLD_WR_ERR_Pos)) /* Assigment of value for DPI_PLD_WR_ERR in the DSI_INT_FORCE1 register */
#define DSI_INT_FORCE1_GEN_CMD_WR_ERR_Pos     _UINT32_(8)                                          /* (DSI_INT_FORCE1) Generic Interface Command Write Error Force Position */
#define DSI_INT_FORCE1_GEN_CMD_WR_ERR_Msk     (_UINT32_(0x1) << DSI_INT_FORCE1_GEN_CMD_WR_ERR_Pos) /* (DSI_INT_FORCE1) Generic Interface Command Write Error Force Mask */
#define DSI_INT_FORCE1_GEN_CMD_WR_ERR(value)  (DSI_INT_FORCE1_GEN_CMD_WR_ERR_Msk & (_UINT32_(value) << DSI_INT_FORCE1_GEN_CMD_WR_ERR_Pos)) /* Assigment of value for GEN_CMD_WR_ERR in the DSI_INT_FORCE1 register */
#define DSI_INT_FORCE1_GEN_PLD_WR_ERR_Pos     _UINT32_(9)                                          /* (DSI_INT_FORCE1) Generic Interface Payload Write Error Force Position */
#define DSI_INT_FORCE1_GEN_PLD_WR_ERR_Msk     (_UINT32_(0x1) << DSI_INT_FORCE1_GEN_PLD_WR_ERR_Pos) /* (DSI_INT_FORCE1) Generic Interface Payload Write Error Force Mask */
#define DSI_INT_FORCE1_GEN_PLD_WR_ERR(value)  (DSI_INT_FORCE1_GEN_PLD_WR_ERR_Msk & (_UINT32_(value) << DSI_INT_FORCE1_GEN_PLD_WR_ERR_Pos)) /* Assigment of value for GEN_PLD_WR_ERR in the DSI_INT_FORCE1 register */
#define DSI_INT_FORCE1_GEN_PLD_SEND_ERR_Pos   _UINT32_(10)                                         /* (DSI_INT_FORCE1) Generic Interface Payload Send Error Force Position */
#define DSI_INT_FORCE1_GEN_PLD_SEND_ERR_Msk   (_UINT32_(0x1) << DSI_INT_FORCE1_GEN_PLD_SEND_ERR_Pos) /* (DSI_INT_FORCE1) Generic Interface Payload Send Error Force Mask */
#define DSI_INT_FORCE1_GEN_PLD_SEND_ERR(value) (DSI_INT_FORCE1_GEN_PLD_SEND_ERR_Msk & (_UINT32_(value) << DSI_INT_FORCE1_GEN_PLD_SEND_ERR_Pos)) /* Assigment of value for GEN_PLD_SEND_ERR in the DSI_INT_FORCE1 register */
#define DSI_INT_FORCE1_GEN_PLD_RD_ERR_Pos     _UINT32_(11)                                         /* (DSI_INT_FORCE1) Generic Interface Payload Read Error Force Position */
#define DSI_INT_FORCE1_GEN_PLD_RD_ERR_Msk     (_UINT32_(0x1) << DSI_INT_FORCE1_GEN_PLD_RD_ERR_Pos) /* (DSI_INT_FORCE1) Generic Interface Payload Read Error Force Mask */
#define DSI_INT_FORCE1_GEN_PLD_RD_ERR(value)  (DSI_INT_FORCE1_GEN_PLD_RD_ERR_Msk & (_UINT32_(value) << DSI_INT_FORCE1_GEN_PLD_RD_ERR_Pos)) /* Assigment of value for GEN_PLD_RD_ERR in the DSI_INT_FORCE1 register */
#define DSI_INT_FORCE1_GEN_PLD_RECEV_ERR_Pos  _UINT32_(12)                                         /* (DSI_INT_FORCE1) Generic Interface Payload Receive Error Force Position */
#define DSI_INT_FORCE1_GEN_PLD_RECEV_ERR_Msk  (_UINT32_(0x1) << DSI_INT_FORCE1_GEN_PLD_RECEV_ERR_Pos) /* (DSI_INT_FORCE1) Generic Interface Payload Receive Error Force Mask */
#define DSI_INT_FORCE1_GEN_PLD_RECEV_ERR(value) (DSI_INT_FORCE1_GEN_PLD_RECEV_ERR_Msk & (_UINT32_(value) << DSI_INT_FORCE1_GEN_PLD_RECEV_ERR_Pos)) /* Assigment of value for GEN_PLD_RECEV_ERR in the DSI_INT_FORCE1 register */
#define DSI_INT_FORCE1_Msk                    _UINT32_(0x00001FFF)                                 /* (DSI_INT_FORCE1) Register Mask  */


/* -------- DSI_AUTO_ULPS_MODE : (DSI Offset: 0xE0) (R/W 32) Automatic Ultra-Low-Power Mode Register -------- */
#define DSI_AUTO_ULPS_MODE_RESETVALUE         _UINT32_(0x00)                                       /*  (DSI_AUTO_ULPS_MODE) Automatic Ultra-Low-Power Mode Register  Reset Value */

#define DSI_AUTO_ULPS_MODE_AUTO_ULPS_Pos      _UINT32_(0)                                          /* (DSI_AUTO_ULPS_MODE) Automatic Ultra-Low-Power Enable Position */
#define DSI_AUTO_ULPS_MODE_AUTO_ULPS_Msk      (_UINT32_(0x1) << DSI_AUTO_ULPS_MODE_AUTO_ULPS_Pos)  /* (DSI_AUTO_ULPS_MODE) Automatic Ultra-Low-Power Enable Mask */
#define DSI_AUTO_ULPS_MODE_AUTO_ULPS(value)   (DSI_AUTO_ULPS_MODE_AUTO_ULPS_Msk & (_UINT32_(value) << DSI_AUTO_ULPS_MODE_AUTO_ULPS_Pos)) /* Assigment of value for AUTO_ULPS in the DSI_AUTO_ULPS_MODE register */
#define   DSI_AUTO_ULPS_MODE_AUTO_ULPS_0_Val  _UINT32_(0x0)                                        /* (DSI_AUTO_ULPS_MODE) Disables the automatic mechanism to enter and exit ULPS.  */
#define   DSI_AUTO_ULPS_MODE_AUTO_ULPS_1_Val  _UINT32_(0x1)                                        /* (DSI_AUTO_ULPS_MODE) Enables the automatic mechanism to enter and exit ULPS.  */
#define DSI_AUTO_ULPS_MODE_AUTO_ULPS_0        (DSI_AUTO_ULPS_MODE_AUTO_ULPS_0_Val << DSI_AUTO_ULPS_MODE_AUTO_ULPS_Pos) /* (DSI_AUTO_ULPS_MODE) Disables the automatic mechanism to enter and exit ULPS. Position  */
#define DSI_AUTO_ULPS_MODE_AUTO_ULPS_1        (DSI_AUTO_ULPS_MODE_AUTO_ULPS_1_Val << DSI_AUTO_ULPS_MODE_AUTO_ULPS_Pos) /* (DSI_AUTO_ULPS_MODE) Enables the automatic mechanism to enter and exit ULPS. Position  */
#define DSI_AUTO_ULPS_MODE_PLL_OFF_ULPS_Pos   _UINT32_(16)                                         /* (DSI_AUTO_ULPS_MODE) PLL Turned OFF During Ultra-Low-Power Position */
#define DSI_AUTO_ULPS_MODE_PLL_OFF_ULPS_Msk   (_UINT32_(0x1) << DSI_AUTO_ULPS_MODE_PLL_OFF_ULPS_Pos) /* (DSI_AUTO_ULPS_MODE) PLL Turned OFF During Ultra-Low-Power Mask */
#define DSI_AUTO_ULPS_MODE_PLL_OFF_ULPS(value) (DSI_AUTO_ULPS_MODE_PLL_OFF_ULPS_Msk & (_UINT32_(value) << DSI_AUTO_ULPS_MODE_PLL_OFF_ULPS_Pos)) /* Assigment of value for PLL_OFF_ULPS in the DSI_AUTO_ULPS_MODE register */
#define   DSI_AUTO_ULPS_MODE_PLL_OFF_ULPS_0_Val _UINT32_(0x0)                                        /* (DSI_AUTO_ULPS_MODE) Prevents turning off the D-PHY PLL during ULPS.  */
#define   DSI_AUTO_ULPS_MODE_PLL_OFF_ULPS_1_Val _UINT32_(0x1)                                        /* (DSI_AUTO_ULPS_MODE) Turns off the D-PHY PLL during ULPS.  */
#define DSI_AUTO_ULPS_MODE_PLL_OFF_ULPS_0     (DSI_AUTO_ULPS_MODE_PLL_OFF_ULPS_0_Val << DSI_AUTO_ULPS_MODE_PLL_OFF_ULPS_Pos) /* (DSI_AUTO_ULPS_MODE) Prevents turning off the D-PHY PLL during ULPS. Position  */
#define DSI_AUTO_ULPS_MODE_PLL_OFF_ULPS_1     (DSI_AUTO_ULPS_MODE_PLL_OFF_ULPS_1_Val << DSI_AUTO_ULPS_MODE_PLL_OFF_ULPS_Pos) /* (DSI_AUTO_ULPS_MODE) Turns off the D-PHY PLL during ULPS. Position  */
#define DSI_AUTO_ULPS_MODE_PRE_PLL_OFF_REQ_Pos _UINT32_(17)                                         /* (DSI_AUTO_ULPS_MODE) Automatic Ultra-Low-Power Enable Position */
#define DSI_AUTO_ULPS_MODE_PRE_PLL_OFF_REQ_Msk (_UINT32_(0x1) << DSI_AUTO_ULPS_MODE_PRE_PLL_OFF_REQ_Pos) /* (DSI_AUTO_ULPS_MODE) Automatic Ultra-Low-Power Enable Mask */
#define DSI_AUTO_ULPS_MODE_PRE_PLL_OFF_REQ(value) (DSI_AUTO_ULPS_MODE_PRE_PLL_OFF_REQ_Msk & (_UINT32_(value) << DSI_AUTO_ULPS_MODE_PRE_PLL_OFF_REQ_Pos)) /* Assigment of value for PRE_PLL_OFF_REQ in the DSI_AUTO_ULPS_MODE register */
#define   DSI_AUTO_ULPS_MODE_PRE_PLL_OFF_REQ_0_Val _UINT32_(0x0)                                        /* (DSI_AUTO_ULPS_MODE) No effect.  */
#define   DSI_AUTO_ULPS_MODE_PRE_PLL_OFF_REQ_1_Val _UINT32_(0x1)                                        /* (DSI_AUTO_ULPS_MODE) When pll_off_ulps is active, allows to turn off PLL before the request to enter ULPS.  */
#define DSI_AUTO_ULPS_MODE_PRE_PLL_OFF_REQ_0  (DSI_AUTO_ULPS_MODE_PRE_PLL_OFF_REQ_0_Val << DSI_AUTO_ULPS_MODE_PRE_PLL_OFF_REQ_Pos) /* (DSI_AUTO_ULPS_MODE) No effect. Position  */
#define DSI_AUTO_ULPS_MODE_PRE_PLL_OFF_REQ_1  (DSI_AUTO_ULPS_MODE_PRE_PLL_OFF_REQ_1_Val << DSI_AUTO_ULPS_MODE_PRE_PLL_OFF_REQ_Pos) /* (DSI_AUTO_ULPS_MODE) When pll_off_ulps is active, allows to turn off PLL before the request to enter ULPS. Position  */
#define DSI_AUTO_ULPS_MODE_Msk                _UINT32_(0x00030001)                                 /* (DSI_AUTO_ULPS_MODE) Register Mask  */


/* -------- DSI_AUTO_ULPS_ENTRY_DELAY : (DSI Offset: 0xE4) (R/W 32) Automatic Ultra-Low-Power Entry Delay Register -------- */
#define DSI_AUTO_ULPS_ENTRY_DELAY_RESETVALUE  _UINT32_(0x00)                                       /*  (DSI_AUTO_ULPS_ENTRY_DELAY) Automatic Ultra-Low-Power Entry Delay Register  Reset Value */

#define DSI_AUTO_ULPS_ENTRY_DELAY_ULPS_ENTRY_DELAY_Pos _UINT32_(0)                                          /* (DSI_AUTO_ULPS_ENTRY_DELAY) Ultra-Low-Power Enable Entry Delay Position */
#define DSI_AUTO_ULPS_ENTRY_DELAY_ULPS_ENTRY_DELAY_Msk (_UINT32_(0xFFFFFFFF) << DSI_AUTO_ULPS_ENTRY_DELAY_ULPS_ENTRY_DELAY_Pos) /* (DSI_AUTO_ULPS_ENTRY_DELAY) Ultra-Low-Power Enable Entry Delay Mask */
#define DSI_AUTO_ULPS_ENTRY_DELAY_ULPS_ENTRY_DELAY(value) (DSI_AUTO_ULPS_ENTRY_DELAY_ULPS_ENTRY_DELAY_Msk & (_UINT32_(value) << DSI_AUTO_ULPS_ENTRY_DELAY_ULPS_ENTRY_DELAY_Pos)) /* Assigment of value for ULPS_ENTRY_DELAY in the DSI_AUTO_ULPS_ENTRY_DELAY register */
#define DSI_AUTO_ULPS_ENTRY_DELAY_Msk         _UINT32_(0xFFFFFFFF)                                 /* (DSI_AUTO_ULPS_ENTRY_DELAY) Register Mask  */


/* -------- DSI_AUTO_ULPS_WAKEUP_TIME : (DSI Offset: 0xE8) (R/W 32) Automatic Ultra-Low-Power Wake-Up Time Register -------- */
#define DSI_AUTO_ULPS_WAKEUP_TIME_RESETVALUE  _UINT32_(0x00)                                       /*  (DSI_AUTO_ULPS_WAKEUP_TIME) Automatic Ultra-Low-Power Wake-Up Time Register  Reset Value */

#define DSI_AUTO_ULPS_WAKEUP_TIME_TWAKEUP_CLK_DIV_Pos _UINT32_(0)                                          /* (DSI_AUTO_ULPS_WAKEUP_TIME) Wake-Up Time Clock Divider Position */
#define DSI_AUTO_ULPS_WAKEUP_TIME_TWAKEUP_CLK_DIV_Msk (_UINT32_(0xFFFF) << DSI_AUTO_ULPS_WAKEUP_TIME_TWAKEUP_CLK_DIV_Pos) /* (DSI_AUTO_ULPS_WAKEUP_TIME) Wake-Up Time Clock Divider Mask */
#define DSI_AUTO_ULPS_WAKEUP_TIME_TWAKEUP_CLK_DIV(value) (DSI_AUTO_ULPS_WAKEUP_TIME_TWAKEUP_CLK_DIV_Msk & (_UINT32_(value) << DSI_AUTO_ULPS_WAKEUP_TIME_TWAKEUP_CLK_DIV_Pos)) /* Assigment of value for TWAKEUP_CLK_DIV in the DSI_AUTO_ULPS_WAKEUP_TIME register */
#define DSI_AUTO_ULPS_WAKEUP_TIME_TWAKEUP_ENTRY_DELAY_Pos _UINT32_(16)                                         /* (DSI_AUTO_ULPS_WAKEUP_TIME) Wake-Up Time Entry Delay Position */
#define DSI_AUTO_ULPS_WAKEUP_TIME_TWAKEUP_ENTRY_DELAY_Msk (_UINT32_(0xFFFF) << DSI_AUTO_ULPS_WAKEUP_TIME_TWAKEUP_ENTRY_DELAY_Pos) /* (DSI_AUTO_ULPS_WAKEUP_TIME) Wake-Up Time Entry Delay Mask */
#define DSI_AUTO_ULPS_WAKEUP_TIME_TWAKEUP_ENTRY_DELAY(value) (DSI_AUTO_ULPS_WAKEUP_TIME_TWAKEUP_ENTRY_DELAY_Msk & (_UINT32_(value) << DSI_AUTO_ULPS_WAKEUP_TIME_TWAKEUP_ENTRY_DELAY_Pos)) /* Assigment of value for TWAKEUP_ENTRY_DELAY in the DSI_AUTO_ULPS_WAKEUP_TIME register */
#define DSI_AUTO_ULPS_WAKEUP_TIME_Msk         _UINT32_(0xFFFFFFFF)                                 /* (DSI_AUTO_ULPS_WAKEUP_TIME) Register Mask  */


/* -------- DSI_DPHY_TMR_RD_CFG : (DSI Offset: 0xF4) (R/W 32) DHY Read Timing Configuration Register -------- */
#define DSI_DPHY_TMR_RD_CFG_RESETVALUE        _UINT32_(0x00)                                       /*  (DSI_DPHY_TMR_RD_CFG) DHY Read Timing Configuration Register  Reset Value */

#define DSI_DPHY_TMR_RD_CFG_MAX_RD_TIME_Pos   _UINT32_(0)                                          /* (DSI_DPHY_TMR_RD_CFG) Maximum Read Time Position */
#define DSI_DPHY_TMR_RD_CFG_MAX_RD_TIME_Msk   (_UINT32_(0xFFFF) << DSI_DPHY_TMR_RD_CFG_MAX_RD_TIME_Pos) /* (DSI_DPHY_TMR_RD_CFG) Maximum Read Time Mask */
#define DSI_DPHY_TMR_RD_CFG_MAX_RD_TIME(value) (DSI_DPHY_TMR_RD_CFG_MAX_RD_TIME_Msk & (_UINT32_(value) << DSI_DPHY_TMR_RD_CFG_MAX_RD_TIME_Pos)) /* Assigment of value for MAX_RD_TIME in the DSI_DPHY_TMR_RD_CFG register */
#define DSI_DPHY_TMR_RD_CFG_Msk               _UINT32_(0x0000FFFF)                                 /* (DSI_DPHY_TMR_RD_CFG) Register Mask  */


/* -------- DSI_AUTO_ULPS_MIN_TIME : (DSI Offset: 0xF8) (R/W 32) Automatic Ultra-Low-Power Minimum Time Register -------- */
#define DSI_AUTO_ULPS_MIN_TIME_RESETVALUE     _UINT32_(0x00)                                       /*  (DSI_AUTO_ULPS_MIN_TIME) Automatic Ultra-Low-Power Minimum Time Register  Reset Value */

#define DSI_AUTO_ULPS_MIN_TIME_ULPS_MIN_TIME_Pos _UINT32_(0)                                          /* (DSI_AUTO_ULPS_MIN_TIME) Ultra-Low-Power Minimum Time Position */
#define DSI_AUTO_ULPS_MIN_TIME_ULPS_MIN_TIME_Msk (_UINT32_(0xFFF) << DSI_AUTO_ULPS_MIN_TIME_ULPS_MIN_TIME_Pos) /* (DSI_AUTO_ULPS_MIN_TIME) Ultra-Low-Power Minimum Time Mask */
#define DSI_AUTO_ULPS_MIN_TIME_ULPS_MIN_TIME(value) (DSI_AUTO_ULPS_MIN_TIME_ULPS_MIN_TIME_Msk & (_UINT32_(value) << DSI_AUTO_ULPS_MIN_TIME_ULPS_MIN_TIME_Pos)) /* Assigment of value for ULPS_MIN_TIME in the DSI_AUTO_ULPS_MIN_TIME register */
#define DSI_AUTO_ULPS_MIN_TIME_Msk            _UINT32_(0x00000FFF)                                 /* (DSI_AUTO_ULPS_MIN_TIME) Register Mask  */


/* -------- DSI_VID_SHADOW_CTRL : (DSI Offset: 0x100) (R/W 32) Video Mode Shadow Feature Control Register -------- */
#define DSI_VID_SHADOW_CTRL_RESETVALUE        _UINT32_(0x00)                                       /*  (DSI_VID_SHADOW_CTRL) Video Mode Shadow Feature Control Register  Reset Value */

#define DSI_VID_SHADOW_CTRL_VID_SHADOW_EN_Pos _UINT32_(0)                                          /* (DSI_VID_SHADOW_CTRL) Video Interface Shadow Registers Enable Position */
#define DSI_VID_SHADOW_CTRL_VID_SHADOW_EN_Msk (_UINT32_(0x1) << DSI_VID_SHADOW_CTRL_VID_SHADOW_EN_Pos) /* (DSI_VID_SHADOW_CTRL) Video Interface Shadow Registers Enable Mask */
#define DSI_VID_SHADOW_CTRL_VID_SHADOW_EN(value) (DSI_VID_SHADOW_CTRL_VID_SHADOW_EN_Msk & (_UINT32_(value) << DSI_VID_SHADOW_CTRL_VID_SHADOW_EN_Pos)) /* Assigment of value for VID_SHADOW_EN in the DSI_VID_SHADOW_CTRL register */
#define   DSI_VID_SHADOW_CTRL_VID_SHADOW_EN_0_Val _UINT32_(0x0)                                        /* (DSI_VID_SHADOW_CTRL) No effect.  */
#define   DSI_VID_SHADOW_CTRL_VID_SHADOW_EN_1_Val _UINT32_(0x1)                                        /* (DSI_VID_SHADOW_CTRL) Input video bus receives the active configuration from the auxiliary registers. When the feature is set at the same time as VID_SHADOW_REQ, the auxiliary registers are automatically updated.  */
#define DSI_VID_SHADOW_CTRL_VID_SHADOW_EN_0   (DSI_VID_SHADOW_CTRL_VID_SHADOW_EN_0_Val << DSI_VID_SHADOW_CTRL_VID_SHADOW_EN_Pos) /* (DSI_VID_SHADOW_CTRL) No effect. Position  */
#define DSI_VID_SHADOW_CTRL_VID_SHADOW_EN_1   (DSI_VID_SHADOW_CTRL_VID_SHADOW_EN_1_Val << DSI_VID_SHADOW_CTRL_VID_SHADOW_EN_Pos) /* (DSI_VID_SHADOW_CTRL) Input video bus receives the active configuration from the auxiliary registers. When the feature is set at the same time as VID_SHADOW_REQ, the auxiliary registers are automatically updated. Position  */
#define DSI_VID_SHADOW_CTRL_VID_SHADOW_REQ_Pos _UINT32_(8)                                          /* (DSI_VID_SHADOW_CTRL) Video Interface Shadow Request Position */
#define DSI_VID_SHADOW_CTRL_VID_SHADOW_REQ_Msk (_UINT32_(0x1) << DSI_VID_SHADOW_CTRL_VID_SHADOW_REQ_Pos) /* (DSI_VID_SHADOW_CTRL) Video Interface Shadow Request Mask */
#define DSI_VID_SHADOW_CTRL_VID_SHADOW_REQ(value) (DSI_VID_SHADOW_CTRL_VID_SHADOW_REQ_Msk & (_UINT32_(value) << DSI_VID_SHADOW_CTRL_VID_SHADOW_REQ_Pos)) /* Assigment of value for VID_SHADOW_REQ in the DSI_VID_SHADOW_CTRL register */
#define   DSI_VID_SHADOW_CTRL_VID_SHADOW_REQ_0_Val _UINT32_(0x0)                                        /* (DSI_VID_SHADOW_CTRL) No effect.  */
#define   DSI_VID_SHADOW_CTRL_VID_SHADOW_REQ_1_Val _UINT32_(0x1)                                        /* (DSI_VID_SHADOW_CTRL) Requests that the input video interface registers from regbank are copied to the auxiliary registers. When the request is completed, this bit is automatically cleared.  */
#define DSI_VID_SHADOW_CTRL_VID_SHADOW_REQ_0  (DSI_VID_SHADOW_CTRL_VID_SHADOW_REQ_0_Val << DSI_VID_SHADOW_CTRL_VID_SHADOW_REQ_Pos) /* (DSI_VID_SHADOW_CTRL) No effect. Position  */
#define DSI_VID_SHADOW_CTRL_VID_SHADOW_REQ_1  (DSI_VID_SHADOW_CTRL_VID_SHADOW_REQ_1_Val << DSI_VID_SHADOW_CTRL_VID_SHADOW_REQ_Pos) /* (DSI_VID_SHADOW_CTRL) Requests that the input video interface registers from regbank are copied to the auxiliary registers. When the request is completed, this bit is automatically cleared. Position  */
#define DSI_VID_SHADOW_CTRL_Msk               _UINT32_(0x00000101)                                 /* (DSI_VID_SHADOW_CTRL) Register Mask  */


/* -------- DSI_DPI_VCID_ACT : (DSI Offset: 0x10C) ( R/ 32) Input Video Virtual Channel ID Active Value Register -------- */
#define DSI_DPI_VCID_ACT_RESETVALUE           _UINT32_(0x00)                                       /*  (DSI_DPI_VCID_ACT) Input Video Virtual Channel ID Active Value Register  Reset Value */

#define DSI_DPI_VCID_ACT_DPI_VCID_Pos         _UINT32_(0)                                          /* (DSI_DPI_VCID_ACT) Input Video Interface Virtual Channel Identifier Position */
#define DSI_DPI_VCID_ACT_DPI_VCID_Msk         (_UINT32_(0x3) << DSI_DPI_VCID_ACT_DPI_VCID_Pos)     /* (DSI_DPI_VCID_ACT) Input Video Interface Virtual Channel Identifier Mask */
#define DSI_DPI_VCID_ACT_DPI_VCID(value)      (DSI_DPI_VCID_ACT_DPI_VCID_Msk & (_UINT32_(value) << DSI_DPI_VCID_ACT_DPI_VCID_Pos)) /* Assigment of value for DPI_VCID in the DSI_DPI_VCID_ACT register */
#define DSI_DPI_VCID_ACT_Msk                  _UINT32_(0x00000003)                                 /* (DSI_DPI_VCID_ACT) Register Mask  */


/* -------- DSI_DPI_COLOR_CODING_ACT : (DSI Offset: 0x110) ( R/ 32) Input Video Color Coding Active Value Register -------- */
#define DSI_DPI_COLOR_CODING_ACT_RESETVALUE   _UINT32_(0x00)                                       /*  (DSI_DPI_COLOR_CODING_ACT) Input Video Color Coding Active Value Register  Reset Value */

#define DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_Pos _UINT32_(0)                                          /* (DSI_DPI_COLOR_CODING_ACT) Input Video Interface Color Coding Position */
#define DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_Msk (_UINT32_(0xF) << DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_Pos) /* (DSI_DPI_COLOR_CODING_ACT) Input Video Interface Color Coding Mask */
#define DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING(value) (DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_Msk & (_UINT32_(value) << DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_Pos)) /* Assigment of value for DPI_COLOR_CODING in the DSI_DPI_COLOR_CODING_ACT register */
#define   DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_16BIT_CFG1_Val _UINT32_(0x0)                                        /* (DSI_DPI_COLOR_CODING_ACT) 16-bit configuration 1  */
#define   DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_16BIT_CFG2_Val _UINT32_(0x1)                                        /* (DSI_DPI_COLOR_CODING_ACT) 16-bit configuration 2  */
#define   DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_16BIT_CFG3_Val _UINT32_(0x2)                                        /* (DSI_DPI_COLOR_CODING_ACT) 16-bit configuration 3  */
#define   DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_18BIT_CFG1_Val _UINT32_(0x3)                                        /* (DSI_DPI_COLOR_CODING_ACT) 18-bit configuration 1  */
#define   DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_18BIT_CFG2_Val _UINT32_(0x4)                                        /* (DSI_DPI_COLOR_CODING_ACT) 18-bit configuration 2  */
#define   DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_24BIT_Val _UINT32_(0x5)                                        /* (DSI_DPI_COLOR_CODING_ACT) 24-bit  */
#define DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_16BIT_CFG1 (DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_16BIT_CFG1_Val << DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_Pos) /* (DSI_DPI_COLOR_CODING_ACT) 16-bit configuration 1 Position  */
#define DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_16BIT_CFG2 (DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_16BIT_CFG2_Val << DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_Pos) /* (DSI_DPI_COLOR_CODING_ACT) 16-bit configuration 2 Position  */
#define DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_16BIT_CFG3 (DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_16BIT_CFG3_Val << DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_Pos) /* (DSI_DPI_COLOR_CODING_ACT) 16-bit configuration 3 Position  */
#define DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_18BIT_CFG1 (DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_18BIT_CFG1_Val << DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_Pos) /* (DSI_DPI_COLOR_CODING_ACT) 18-bit configuration 1 Position  */
#define DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_18BIT_CFG2 (DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_18BIT_CFG2_Val << DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_Pos) /* (DSI_DPI_COLOR_CODING_ACT) 18-bit configuration 2 Position  */
#define DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_24BIT (DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_24BIT_Val << DSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_Pos) /* (DSI_DPI_COLOR_CODING_ACT) 24-bit Position  */
#define DSI_DPI_COLOR_CODING_ACT_LOOSELY18_EN_Pos _UINT32_(8)                                          /* (DSI_DPI_COLOR_CODING_ACT) Loosely Packed Variant to 18-bit Enable Position */
#define DSI_DPI_COLOR_CODING_ACT_LOOSELY18_EN_Msk (_UINT32_(0x1) << DSI_DPI_COLOR_CODING_ACT_LOOSELY18_EN_Pos) /* (DSI_DPI_COLOR_CODING_ACT) Loosely Packed Variant to 18-bit Enable Mask */
#define DSI_DPI_COLOR_CODING_ACT_LOOSELY18_EN(value) (DSI_DPI_COLOR_CODING_ACT_LOOSELY18_EN_Msk & (_UINT32_(value) << DSI_DPI_COLOR_CODING_ACT_LOOSELY18_EN_Pos)) /* Assigment of value for LOOSELY18_EN in the DSI_DPI_COLOR_CODING_ACT register */
#define   DSI_DPI_COLOR_CODING_ACT_LOOSELY18_EN_0_Val _UINT32_(0x0)                                        /* (DSI_DPI_COLOR_CODING_ACT) Disables loosely packed variant to 18-bit configurations.  */
#define   DSI_DPI_COLOR_CODING_ACT_LOOSELY18_EN_1_Val _UINT32_(0x1)                                        /* (DSI_DPI_COLOR_CODING_ACT) Enables loosely packed variant to 18-bit configurations.  */
#define DSI_DPI_COLOR_CODING_ACT_LOOSELY18_EN_0 (DSI_DPI_COLOR_CODING_ACT_LOOSELY18_EN_0_Val << DSI_DPI_COLOR_CODING_ACT_LOOSELY18_EN_Pos) /* (DSI_DPI_COLOR_CODING_ACT) Disables loosely packed variant to 18-bit configurations. Position  */
#define DSI_DPI_COLOR_CODING_ACT_LOOSELY18_EN_1 (DSI_DPI_COLOR_CODING_ACT_LOOSELY18_EN_1_Val << DSI_DPI_COLOR_CODING_ACT_LOOSELY18_EN_Pos) /* (DSI_DPI_COLOR_CODING_ACT) Enables loosely packed variant to 18-bit configurations. Position  */
#define DSI_DPI_COLOR_CODING_ACT_Msk          _UINT32_(0x0000010F)                                 /* (DSI_DPI_COLOR_CODING_ACT) Register Mask  */


/* -------- DSI_DPI_LP_CMD_TIM_ACT : (DSI Offset: 0x118) ( R/ 32) Input Video Timing for Low-Power Commands Active Value Register -------- */
#define DSI_DPI_LP_CMD_TIM_ACT_RESETVALUE     _UINT32_(0x00)                                       /*  (DSI_DPI_LP_CMD_TIM_ACT) Input Video Timing for Low-Power Commands Active Value Register  Reset Value */

#define DSI_DPI_LP_CMD_TIM_ACT_INVACT_LPCMD_TIME_Pos _UINT32_(0)                                          /* (DSI_DPI_LP_CMD_TIM_ACT) Input Vertical Active Low-Power Command Time Position */
#define DSI_DPI_LP_CMD_TIM_ACT_INVACT_LPCMD_TIME_Msk (_UINT32_(0xFF) << DSI_DPI_LP_CMD_TIM_ACT_INVACT_LPCMD_TIME_Pos) /* (DSI_DPI_LP_CMD_TIM_ACT) Input Vertical Active Low-Power Command Time Mask */
#define DSI_DPI_LP_CMD_TIM_ACT_INVACT_LPCMD_TIME(value) (DSI_DPI_LP_CMD_TIM_ACT_INVACT_LPCMD_TIME_Msk & (_UINT32_(value) << DSI_DPI_LP_CMD_TIM_ACT_INVACT_LPCMD_TIME_Pos)) /* Assigment of value for INVACT_LPCMD_TIME in the DSI_DPI_LP_CMD_TIM_ACT register */
#define DSI_DPI_LP_CMD_TIM_ACT_OUTVACT_LPCMD_TIME_Pos _UINT32_(8)                                          /* (DSI_DPI_LP_CMD_TIM_ACT) Output Vertical Active Low-Power Command Time Position */
#define DSI_DPI_LP_CMD_TIM_ACT_OUTVACT_LPCMD_TIME_Msk (_UINT32_(0xFF) << DSI_DPI_LP_CMD_TIM_ACT_OUTVACT_LPCMD_TIME_Pos) /* (DSI_DPI_LP_CMD_TIM_ACT) Output Vertical Active Low-Power Command Time Mask */
#define DSI_DPI_LP_CMD_TIM_ACT_OUTVACT_LPCMD_TIME(value) (DSI_DPI_LP_CMD_TIM_ACT_OUTVACT_LPCMD_TIME_Msk & (_UINT32_(value) << DSI_DPI_LP_CMD_TIM_ACT_OUTVACT_LPCMD_TIME_Pos)) /* Assigment of value for OUTVACT_LPCMD_TIME in the DSI_DPI_LP_CMD_TIM_ACT register */
#define DSI_DPI_LP_CMD_TIM_ACT_Msk            _UINT32_(0x0000FFFF)                                 /* (DSI_DPI_LP_CMD_TIM_ACT) Register Mask  */


/* -------- DSI_VID_MODE_CFG_ACT : (DSI Offset: 0x138) ( R/ 32) Video Mode Active Value Register -------- */
#define DSI_VID_MODE_CFG_ACT_RESETVALUE       _UINT32_(0x00)                                       /*  (DSI_VID_MODE_CFG_ACT) Video Mode Active Value Register  Reset Value */

#define DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_Pos _UINT32_(0)                                          /* (DSI_VID_MODE_CFG_ACT) Video Mode Type Position */
#define DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_Msk (_UINT32_(0x3) << DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_Pos) /* (DSI_VID_MODE_CFG_ACT) Video Mode Type Mask */
#define DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE(value) (DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_Pos)) /* Assigment of value for VID_MODE_TYPE in the DSI_VID_MODE_CFG_ACT register */
#define   DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_0_Val _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG_ACT) Non-burst with sync pulses  */
#define   DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_1_Val _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG_ACT) Non-burst with sync events  */
#define   DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_2_Val _UINT32_(0x2)                                        /* (DSI_VID_MODE_CFG_ACT) Burst mode  */
#define   DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_3_Val _UINT32_(0x3)                                        /* (DSI_VID_MODE_CFG_ACT) Burst mode  */
#define DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_0  (DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_0_Val << DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_Pos) /* (DSI_VID_MODE_CFG_ACT) Non-burst with sync pulses Position  */
#define DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_1  (DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_1_Val << DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_Pos) /* (DSI_VID_MODE_CFG_ACT) Non-burst with sync events Position  */
#define DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_2  (DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_2_Val << DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_Pos) /* (DSI_VID_MODE_CFG_ACT) Burst mode Position  */
#define DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_3  (DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_3_Val << DSI_VID_MODE_CFG_ACT_VID_MODE_TYPE_Pos) /* (DSI_VID_MODE_CFG_ACT) Burst mode Position  */
#define DSI_VID_MODE_CFG_ACT_LP_VSA_EN_Pos    _UINT32_(2)                                          /* (DSI_VID_MODE_CFG_ACT) Low-Power Vertical Sync Active Enable Position */
#define DSI_VID_MODE_CFG_ACT_LP_VSA_EN_Msk    (_UINT32_(0x1) << DSI_VID_MODE_CFG_ACT_LP_VSA_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Low-Power Vertical Sync Active Enable Mask */
#define DSI_VID_MODE_CFG_ACT_LP_VSA_EN(value) (DSI_VID_MODE_CFG_ACT_LP_VSA_EN_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_ACT_LP_VSA_EN_Pos)) /* Assigment of value for LP_VSA_EN in the DSI_VID_MODE_CFG_ACT register */
#define   DSI_VID_MODE_CFG_ACT_LP_VSA_EN_0_Val _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG_ACT) Disables the return to low-power inside the VSA period when timing allows.  */
#define   DSI_VID_MODE_CFG_ACT_LP_VSA_EN_1_Val _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG_ACT) Enables the return to low-power inside the VSA period when timing allows.  */
#define DSI_VID_MODE_CFG_ACT_LP_VSA_EN_0      (DSI_VID_MODE_CFG_ACT_LP_VSA_EN_0_Val << DSI_VID_MODE_CFG_ACT_LP_VSA_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Disables the return to low-power inside the VSA period when timing allows. Position  */
#define DSI_VID_MODE_CFG_ACT_LP_VSA_EN_1      (DSI_VID_MODE_CFG_ACT_LP_VSA_EN_1_Val << DSI_VID_MODE_CFG_ACT_LP_VSA_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Enables the return to low-power inside the VSA period when timing allows. Position  */
#define DSI_VID_MODE_CFG_ACT_LP_VBP_EN_Pos    _UINT32_(3)                                          /* (DSI_VID_MODE_CFG_ACT) Low-Power Vertical Back Porch Enable Position */
#define DSI_VID_MODE_CFG_ACT_LP_VBP_EN_Msk    (_UINT32_(0x1) << DSI_VID_MODE_CFG_ACT_LP_VBP_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Low-Power Vertical Back Porch Enable Mask */
#define DSI_VID_MODE_CFG_ACT_LP_VBP_EN(value) (DSI_VID_MODE_CFG_ACT_LP_VBP_EN_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_ACT_LP_VBP_EN_Pos)) /* Assigment of value for LP_VBP_EN in the DSI_VID_MODE_CFG_ACT register */
#define   DSI_VID_MODE_CFG_ACT_LP_VBP_EN_0_Val _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG_ACT) Disables the return to low-power inside the VBP period when timing allows.  */
#define   DSI_VID_MODE_CFG_ACT_LP_VBP_EN_1_Val _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG_ACT) Enables the return to low-power inside the VBP period when timing allows.  */
#define DSI_VID_MODE_CFG_ACT_LP_VBP_EN_0      (DSI_VID_MODE_CFG_ACT_LP_VBP_EN_0_Val << DSI_VID_MODE_CFG_ACT_LP_VBP_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Disables the return to low-power inside the VBP period when timing allows. Position  */
#define DSI_VID_MODE_CFG_ACT_LP_VBP_EN_1      (DSI_VID_MODE_CFG_ACT_LP_VBP_EN_1_Val << DSI_VID_MODE_CFG_ACT_LP_VBP_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Enables the return to low-power inside the VBP period when timing allows. Position  */
#define DSI_VID_MODE_CFG_ACT_LP_VFP_EN_Pos    _UINT32_(4)                                          /* (DSI_VID_MODE_CFG_ACT) Low-Power Vertical Front Porch Enable Position */
#define DSI_VID_MODE_CFG_ACT_LP_VFP_EN_Msk    (_UINT32_(0x1) << DSI_VID_MODE_CFG_ACT_LP_VFP_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Low-Power Vertical Front Porch Enable Mask */
#define DSI_VID_MODE_CFG_ACT_LP_VFP_EN(value) (DSI_VID_MODE_CFG_ACT_LP_VFP_EN_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_ACT_LP_VFP_EN_Pos)) /* Assigment of value for LP_VFP_EN in the DSI_VID_MODE_CFG_ACT register */
#define   DSI_VID_MODE_CFG_ACT_LP_VFP_EN_0_Val _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG_ACT) Disables the return to low-power inside the VFP period when timing allows.  */
#define   DSI_VID_MODE_CFG_ACT_LP_VFP_EN_1_Val _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG_ACT) Enables the return to low-power inside the VFP period when timing allows.  */
#define DSI_VID_MODE_CFG_ACT_LP_VFP_EN_0      (DSI_VID_MODE_CFG_ACT_LP_VFP_EN_0_Val << DSI_VID_MODE_CFG_ACT_LP_VFP_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Disables the return to low-power inside the VFP period when timing allows. Position  */
#define DSI_VID_MODE_CFG_ACT_LP_VFP_EN_1      (DSI_VID_MODE_CFG_ACT_LP_VFP_EN_1_Val << DSI_VID_MODE_CFG_ACT_LP_VFP_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Enables the return to low-power inside the VFP period when timing allows. Position  */
#define DSI_VID_MODE_CFG_ACT_LP_VACT_EN_Pos   _UINT32_(5)                                          /* (DSI_VID_MODE_CFG_ACT) Low-Power Vertical Active Enable Position */
#define DSI_VID_MODE_CFG_ACT_LP_VACT_EN_Msk   (_UINT32_(0x1) << DSI_VID_MODE_CFG_ACT_LP_VACT_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Low-Power Vertical Active Enable Mask */
#define DSI_VID_MODE_CFG_ACT_LP_VACT_EN(value) (DSI_VID_MODE_CFG_ACT_LP_VACT_EN_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_ACT_LP_VACT_EN_Pos)) /* Assigment of value for LP_VACT_EN in the DSI_VID_MODE_CFG_ACT register */
#define   DSI_VID_MODE_CFG_ACT_LP_VACT_EN_0_Val _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG_ACT) Disables the return to low-power inside the VACT period when timing allows.  */
#define   DSI_VID_MODE_CFG_ACT_LP_VACT_EN_1_Val _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG_ACT) Enables the return to low-power inside the VACT period when timing allows.  */
#define DSI_VID_MODE_CFG_ACT_LP_VACT_EN_0     (DSI_VID_MODE_CFG_ACT_LP_VACT_EN_0_Val << DSI_VID_MODE_CFG_ACT_LP_VACT_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Disables the return to low-power inside the VACT period when timing allows. Position  */
#define DSI_VID_MODE_CFG_ACT_LP_VACT_EN_1     (DSI_VID_MODE_CFG_ACT_LP_VACT_EN_1_Val << DSI_VID_MODE_CFG_ACT_LP_VACT_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Enables the return to low-power inside the VACT period when timing allows. Position  */
#define DSI_VID_MODE_CFG_ACT_LP_HBP_EN_Pos    _UINT32_(6)                                          /* (DSI_VID_MODE_CFG_ACT) Low-Power Horizontal Back Porch Enable Position */
#define DSI_VID_MODE_CFG_ACT_LP_HBP_EN_Msk    (_UINT32_(0x1) << DSI_VID_MODE_CFG_ACT_LP_HBP_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Low-Power Horizontal Back Porch Enable Mask */
#define DSI_VID_MODE_CFG_ACT_LP_HBP_EN(value) (DSI_VID_MODE_CFG_ACT_LP_HBP_EN_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_ACT_LP_HBP_EN_Pos)) /* Assigment of value for LP_HBP_EN in the DSI_VID_MODE_CFG_ACT register */
#define   DSI_VID_MODE_CFG_ACT_LP_HBP_EN_0_Val _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG_ACT) Disables the return to low-power inside the HBP period when timing allows.  */
#define   DSI_VID_MODE_CFG_ACT_LP_HBP_EN_1_Val _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG_ACT) Enables the return to low-power inside the HBP period when timing allows.  */
#define DSI_VID_MODE_CFG_ACT_LP_HBP_EN_0      (DSI_VID_MODE_CFG_ACT_LP_HBP_EN_0_Val << DSI_VID_MODE_CFG_ACT_LP_HBP_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Disables the return to low-power inside the HBP period when timing allows. Position  */
#define DSI_VID_MODE_CFG_ACT_LP_HBP_EN_1      (DSI_VID_MODE_CFG_ACT_LP_HBP_EN_1_Val << DSI_VID_MODE_CFG_ACT_LP_HBP_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Enables the return to low-power inside the HBP period when timing allows. Position  */
#define DSI_VID_MODE_CFG_ACT_LP_HFP_EN_Pos    _UINT32_(7)                                          /* (DSI_VID_MODE_CFG_ACT) Low-Power Horizontal Front Porch Enable Position */
#define DSI_VID_MODE_CFG_ACT_LP_HFP_EN_Msk    (_UINT32_(0x1) << DSI_VID_MODE_CFG_ACT_LP_HFP_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Low-Power Horizontal Front Porch Enable Mask */
#define DSI_VID_MODE_CFG_ACT_LP_HFP_EN(value) (DSI_VID_MODE_CFG_ACT_LP_HFP_EN_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_ACT_LP_HFP_EN_Pos)) /* Assigment of value for LP_HFP_EN in the DSI_VID_MODE_CFG_ACT register */
#define   DSI_VID_MODE_CFG_ACT_LP_HFP_EN_0_Val _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG_ACT) Disables return to low-power inside the HFP period when timing allows.  */
#define   DSI_VID_MODE_CFG_ACT_LP_HFP_EN_1_Val _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG_ACT) Enables the return to low-power inside the HFP period when timing allows.  */
#define DSI_VID_MODE_CFG_ACT_LP_HFP_EN_0      (DSI_VID_MODE_CFG_ACT_LP_HFP_EN_0_Val << DSI_VID_MODE_CFG_ACT_LP_HFP_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Disables return to low-power inside the HFP period when timing allows. Position  */
#define DSI_VID_MODE_CFG_ACT_LP_HFP_EN_1      (DSI_VID_MODE_CFG_ACT_LP_HFP_EN_1_Val << DSI_VID_MODE_CFG_ACT_LP_HFP_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Enables the return to low-power inside the HFP period when timing allows. Position  */
#define DSI_VID_MODE_CFG_ACT_FRAME_BTA_ACK_EN_Pos _UINT32_(8)                                          /* (DSI_VID_MODE_CFG_ACT) Frame Bus Turn Around Acknowledge Enable Position */
#define DSI_VID_MODE_CFG_ACT_FRAME_BTA_ACK_EN_Msk (_UINT32_(0x1) << DSI_VID_MODE_CFG_ACT_FRAME_BTA_ACK_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Frame Bus Turn Around Acknowledge Enable Mask */
#define DSI_VID_MODE_CFG_ACT_FRAME_BTA_ACK_EN(value) (DSI_VID_MODE_CFG_ACT_FRAME_BTA_ACK_EN_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_ACT_FRAME_BTA_ACK_EN_Pos)) /* Assigment of value for FRAME_BTA_ACK_EN in the DSI_VID_MODE_CFG_ACT register */
#define   DSI_VID_MODE_CFG_ACT_FRAME_BTA_ACK_EN_0_Val _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG_ACT) Disables the request for an acknowledge response at the end of a frame.  */
#define   DSI_VID_MODE_CFG_ACT_FRAME_BTA_ACK_EN_1_Val _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG_ACT) Enables the request for an acknowledge response at the end of a frame.  */
#define DSI_VID_MODE_CFG_ACT_FRAME_BTA_ACK_EN_0 (DSI_VID_MODE_CFG_ACT_FRAME_BTA_ACK_EN_0_Val << DSI_VID_MODE_CFG_ACT_FRAME_BTA_ACK_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Disables the request for an acknowledge response at the end of a frame. Position  */
#define DSI_VID_MODE_CFG_ACT_FRAME_BTA_ACK_EN_1 (DSI_VID_MODE_CFG_ACT_FRAME_BTA_ACK_EN_1_Val << DSI_VID_MODE_CFG_ACT_FRAME_BTA_ACK_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Enables the request for an acknowledge response at the end of a frame. Position  */
#define DSI_VID_MODE_CFG_ACT_LP_CMD_EN_Pos    _UINT32_(9)                                          /* (DSI_VID_MODE_CFG_ACT) Low-Power Command Enable Position */
#define DSI_VID_MODE_CFG_ACT_LP_CMD_EN_Msk    (_UINT32_(0x1) << DSI_VID_MODE_CFG_ACT_LP_CMD_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Low-Power Command Enable Mask */
#define DSI_VID_MODE_CFG_ACT_LP_CMD_EN(value) (DSI_VID_MODE_CFG_ACT_LP_CMD_EN_Msk & (_UINT32_(value) << DSI_VID_MODE_CFG_ACT_LP_CMD_EN_Pos)) /* Assigment of value for LP_CMD_EN in the DSI_VID_MODE_CFG_ACT register */
#define   DSI_VID_MODE_CFG_ACT_LP_CMD_EN_0_Val _UINT32_(0x0)                                        /* (DSI_VID_MODE_CFG_ACT) Disables the command transmission only in Low-Power mode.  */
#define   DSI_VID_MODE_CFG_ACT_LP_CMD_EN_1_Val _UINT32_(0x1)                                        /* (DSI_VID_MODE_CFG_ACT) Enables the command transmission only in Low-Power mode.  */
#define DSI_VID_MODE_CFG_ACT_LP_CMD_EN_0      (DSI_VID_MODE_CFG_ACT_LP_CMD_EN_0_Val << DSI_VID_MODE_CFG_ACT_LP_CMD_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Disables the command transmission only in Low-Power mode. Position  */
#define DSI_VID_MODE_CFG_ACT_LP_CMD_EN_1      (DSI_VID_MODE_CFG_ACT_LP_CMD_EN_1_Val << DSI_VID_MODE_CFG_ACT_LP_CMD_EN_Pos) /* (DSI_VID_MODE_CFG_ACT) Enables the command transmission only in Low-Power mode. Position  */
#define DSI_VID_MODE_CFG_ACT_Msk              _UINT32_(0x000003FF)                                 /* (DSI_VID_MODE_CFG_ACT) Register Mask  */


/* -------- DSI_VID_PKT_SIZE_ACT : (DSI Offset: 0x13C) ( R/ 32) Video Mode packet size Active Value Register -------- */
#define DSI_VID_PKT_SIZE_ACT_RESETVALUE       _UINT32_(0x00)                                       /*  (DSI_VID_PKT_SIZE_ACT) Video Mode packet size Active Value Register  Reset Value */

#define DSI_VID_PKT_SIZE_ACT_VID_PKT_SIZE_Pos _UINT32_(0)                                          /* (DSI_VID_PKT_SIZE_ACT) Video Mode Packet Size Position */
#define DSI_VID_PKT_SIZE_ACT_VID_PKT_SIZE_Msk (_UINT32_(0x3FFF) << DSI_VID_PKT_SIZE_ACT_VID_PKT_SIZE_Pos) /* (DSI_VID_PKT_SIZE_ACT) Video Mode Packet Size Mask */
#define DSI_VID_PKT_SIZE_ACT_VID_PKT_SIZE(value) (DSI_VID_PKT_SIZE_ACT_VID_PKT_SIZE_Msk & (_UINT32_(value) << DSI_VID_PKT_SIZE_ACT_VID_PKT_SIZE_Pos)) /* Assigment of value for VID_PKT_SIZE in the DSI_VID_PKT_SIZE_ACT register */
#define DSI_VID_PKT_SIZE_ACT_Msk              _UINT32_(0x00003FFF)                                 /* (DSI_VID_PKT_SIZE_ACT) Register Mask  */


/* -------- DSI_VID_NUM_CHUNKS_ACT : (DSI Offset: 0x140) ( R/ 32) Video Mode Number of Chunks Active Value Register -------- */
#define DSI_VID_NUM_CHUNKS_ACT_RESETVALUE     _UINT32_(0x00)                                       /*  (DSI_VID_NUM_CHUNKS_ACT) Video Mode Number of Chunks Active Value Register  Reset Value */

#define DSI_VID_NUM_CHUNKS_ACT_VID_NUM_CHUNKS_Pos _UINT32_(0)                                          /* (DSI_VID_NUM_CHUNKS_ACT) Video Mode Number of Chunks Position */
#define DSI_VID_NUM_CHUNKS_ACT_VID_NUM_CHUNKS_Msk (_UINT32_(0x1FFF) << DSI_VID_NUM_CHUNKS_ACT_VID_NUM_CHUNKS_Pos) /* (DSI_VID_NUM_CHUNKS_ACT) Video Mode Number of Chunks Mask */
#define DSI_VID_NUM_CHUNKS_ACT_VID_NUM_CHUNKS(value) (DSI_VID_NUM_CHUNKS_ACT_VID_NUM_CHUNKS_Msk & (_UINT32_(value) << DSI_VID_NUM_CHUNKS_ACT_VID_NUM_CHUNKS_Pos)) /* Assigment of value for VID_NUM_CHUNKS in the DSI_VID_NUM_CHUNKS_ACT register */
#define DSI_VID_NUM_CHUNKS_ACT_Msk            _UINT32_(0x00001FFF)                                 /* (DSI_VID_NUM_CHUNKS_ACT) Register Mask  */


/* -------- DSI_VID_NULL_SIZE_ACT : (DSI Offset: 0x144) ( R/ 32) Video Mode Null Packets Size Active Value Register -------- */
#define DSI_VID_NULL_SIZE_ACT_RESETVALUE      _UINT32_(0x00)                                       /*  (DSI_VID_NULL_SIZE_ACT) Video Mode Null Packets Size Active Value Register  Reset Value */

#define DSI_VID_NULL_SIZE_ACT_VID_NULL_SIZE_Pos _UINT32_(0)                                          /* (DSI_VID_NULL_SIZE_ACT) Video Mode Null Packet Size Position */
#define DSI_VID_NULL_SIZE_ACT_VID_NULL_SIZE_Msk (_UINT32_(0x1FFF) << DSI_VID_NULL_SIZE_ACT_VID_NULL_SIZE_Pos) /* (DSI_VID_NULL_SIZE_ACT) Video Mode Null Packet Size Mask */
#define DSI_VID_NULL_SIZE_ACT_VID_NULL_SIZE(value) (DSI_VID_NULL_SIZE_ACT_VID_NULL_SIZE_Msk & (_UINT32_(value) << DSI_VID_NULL_SIZE_ACT_VID_NULL_SIZE_Pos)) /* Assigment of value for VID_NULL_SIZE in the DSI_VID_NULL_SIZE_ACT register */
#define DSI_VID_NULL_SIZE_ACT_Msk             _UINT32_(0x00001FFF)                                 /* (DSI_VID_NULL_SIZE_ACT) Register Mask  */


/* -------- DSI_VID_HSA_TIME_ACT : (DSI Offset: 0x148) ( R/ 32) Video Mode HSA Time Active Value Register -------- */
#define DSI_VID_HSA_TIME_ACT_RESETVALUE       _UINT32_(0x00)                                       /*  (DSI_VID_HSA_TIME_ACT) Video Mode HSA Time Active Value Register  Reset Value */

#define DSI_VID_HSA_TIME_ACT_VID_HSA_TIME_Pos _UINT32_(0)                                          /* (DSI_VID_HSA_TIME_ACT) Video Mode Horizontal Sync Active Time Position */
#define DSI_VID_HSA_TIME_ACT_VID_HSA_TIME_Msk (_UINT32_(0xFFF) << DSI_VID_HSA_TIME_ACT_VID_HSA_TIME_Pos) /* (DSI_VID_HSA_TIME_ACT) Video Mode Horizontal Sync Active Time Mask */
#define DSI_VID_HSA_TIME_ACT_VID_HSA_TIME(value) (DSI_VID_HSA_TIME_ACT_VID_HSA_TIME_Msk & (_UINT32_(value) << DSI_VID_HSA_TIME_ACT_VID_HSA_TIME_Pos)) /* Assigment of value for VID_HSA_TIME in the DSI_VID_HSA_TIME_ACT register */
#define DSI_VID_HSA_TIME_ACT_Msk              _UINT32_(0x00000FFF)                                 /* (DSI_VID_HSA_TIME_ACT) Register Mask  */


/* -------- DSI_VID_HBP_TIME_ACT : (DSI Offset: 0x14C) ( R/ 32) Video Mode HBP Time Active Value Register -------- */
#define DSI_VID_HBP_TIME_ACT_RESETVALUE       _UINT32_(0x00)                                       /*  (DSI_VID_HBP_TIME_ACT) Video Mode HBP Time Active Value Register  Reset Value */

#define DSI_VID_HBP_TIME_ACT_VID_HBP_TIME_Pos _UINT32_(0)                                          /* (DSI_VID_HBP_TIME_ACT) Video Mode Horizontal Back Porch Time Position */
#define DSI_VID_HBP_TIME_ACT_VID_HBP_TIME_Msk (_UINT32_(0xFFF) << DSI_VID_HBP_TIME_ACT_VID_HBP_TIME_Pos) /* (DSI_VID_HBP_TIME_ACT) Video Mode Horizontal Back Porch Time Mask */
#define DSI_VID_HBP_TIME_ACT_VID_HBP_TIME(value) (DSI_VID_HBP_TIME_ACT_VID_HBP_TIME_Msk & (_UINT32_(value) << DSI_VID_HBP_TIME_ACT_VID_HBP_TIME_Pos)) /* Assigment of value for VID_HBP_TIME in the DSI_VID_HBP_TIME_ACT register */
#define DSI_VID_HBP_TIME_ACT_Msk              _UINT32_(0x00000FFF)                                 /* (DSI_VID_HBP_TIME_ACT) Register Mask  */


/* -------- DSI_VID_HLINE_TIME_ACT : (DSI Offset: 0x150) ( R/ 32) Video Mode HLINE Time Active Value Register -------- */
#define DSI_VID_HLINE_TIME_ACT_RESETVALUE     _UINT32_(0x00)                                       /*  (DSI_VID_HLINE_TIME_ACT) Video Mode HLINE Time Active Value Register  Reset Value */

#define DSI_VID_HLINE_TIME_ACT_VID_HLINE_TIME_Pos _UINT32_(0)                                          /* (DSI_VID_HLINE_TIME_ACT) Video Mode Horizontal Line Time Position */
#define DSI_VID_HLINE_TIME_ACT_VID_HLINE_TIME_Msk (_UINT32_(0xFFFF) << DSI_VID_HLINE_TIME_ACT_VID_HLINE_TIME_Pos) /* (DSI_VID_HLINE_TIME_ACT) Video Mode Horizontal Line Time Mask */
#define DSI_VID_HLINE_TIME_ACT_VID_HLINE_TIME(value) (DSI_VID_HLINE_TIME_ACT_VID_HLINE_TIME_Msk & (_UINT32_(value) << DSI_VID_HLINE_TIME_ACT_VID_HLINE_TIME_Pos)) /* Assigment of value for VID_HLINE_TIME in the DSI_VID_HLINE_TIME_ACT register */
#define DSI_VID_HLINE_TIME_ACT_Msk            _UINT32_(0x0000FFFF)                                 /* (DSI_VID_HLINE_TIME_ACT) Register Mask  */


/* -------- DSI_VID_VSA_LINES_ACT : (DSI Offset: 0x154) ( R/ 32) Video Mode VSA Lines Active Value Register -------- */
#define DSI_VID_VSA_LINES_ACT_RESETVALUE      _UINT32_(0x00)                                       /*  (DSI_VID_VSA_LINES_ACT) Video Mode VSA Lines Active Value Register  Reset Value */

#define DSI_VID_VSA_LINES_ACT_VSA_LINES_Pos   _UINT32_(0)                                          /* (DSI_VID_VSA_LINES_ACT) Video Mode Vertical Sync Active Lines Position */
#define DSI_VID_VSA_LINES_ACT_VSA_LINES_Msk   (_UINT32_(0x3FF) << DSI_VID_VSA_LINES_ACT_VSA_LINES_Pos) /* (DSI_VID_VSA_LINES_ACT) Video Mode Vertical Sync Active Lines Mask */
#define DSI_VID_VSA_LINES_ACT_VSA_LINES(value) (DSI_VID_VSA_LINES_ACT_VSA_LINES_Msk & (_UINT32_(value) << DSI_VID_VSA_LINES_ACT_VSA_LINES_Pos)) /* Assigment of value for VSA_LINES in the DSI_VID_VSA_LINES_ACT register */
#define DSI_VID_VSA_LINES_ACT_Msk             _UINT32_(0x000003FF)                                 /* (DSI_VID_VSA_LINES_ACT) Register Mask  */


/* -------- DSI_VID_VBP_LINES_ACT : (DSI Offset: 0x158) ( R/ 32) Video Mode VBP Lines Active Value Register -------- */
#define DSI_VID_VBP_LINES_ACT_RESETVALUE      _UINT32_(0x00)                                       /*  (DSI_VID_VBP_LINES_ACT) Video Mode VBP Lines Active Value Register  Reset Value */

#define DSI_VID_VBP_LINES_ACT_VBP_LINES_Pos   _UINT32_(0)                                          /* (DSI_VID_VBP_LINES_ACT) Video Mode Vertical Back Porch Lines Position */
#define DSI_VID_VBP_LINES_ACT_VBP_LINES_Msk   (_UINT32_(0x3FF) << DSI_VID_VBP_LINES_ACT_VBP_LINES_Pos) /* (DSI_VID_VBP_LINES_ACT) Video Mode Vertical Back Porch Lines Mask */
#define DSI_VID_VBP_LINES_ACT_VBP_LINES(value) (DSI_VID_VBP_LINES_ACT_VBP_LINES_Msk & (_UINT32_(value) << DSI_VID_VBP_LINES_ACT_VBP_LINES_Pos)) /* Assigment of value for VBP_LINES in the DSI_VID_VBP_LINES_ACT register */
#define DSI_VID_VBP_LINES_ACT_Msk             _UINT32_(0x000003FF)                                 /* (DSI_VID_VBP_LINES_ACT) Register Mask  */


/* -------- DSI_VID_VFP_LINES_ACT : (DSI Offset: 0x15C) ( R/ 32) Video Mode VFP Lines Active Value Register -------- */
#define DSI_VID_VFP_LINES_ACT_RESETVALUE      _UINT32_(0x00)                                       /*  (DSI_VID_VFP_LINES_ACT) Video Mode VFP Lines Active Value Register  Reset Value */

#define DSI_VID_VFP_LINES_ACT_VFP_LINES_Pos   _UINT32_(0)                                          /* (DSI_VID_VFP_LINES_ACT) Video Mode Vertical Front Porch Lines Position */
#define DSI_VID_VFP_LINES_ACT_VFP_LINES_Msk   (_UINT32_(0x3FF) << DSI_VID_VFP_LINES_ACT_VFP_LINES_Pos) /* (DSI_VID_VFP_LINES_ACT) Video Mode Vertical Front Porch Lines Mask */
#define DSI_VID_VFP_LINES_ACT_VFP_LINES(value) (DSI_VID_VFP_LINES_ACT_VFP_LINES_Msk & (_UINT32_(value) << DSI_VID_VFP_LINES_ACT_VFP_LINES_Pos)) /* Assigment of value for VFP_LINES in the DSI_VID_VFP_LINES_ACT register */
#define DSI_VID_VFP_LINES_ACT_Msk             _UINT32_(0x000003FF)                                 /* (DSI_VID_VFP_LINES_ACT) Register Mask  */


/* -------- DSI_VID_VACTIVE_LINES_ACT : (DSI Offset: 0x160) ( R/ 32) Video Mode VACTIVE Lines Active Value Register -------- */
#define DSI_VID_VACTIVE_LINES_ACT_RESETVALUE  _UINT32_(0x00)                                       /*  (DSI_VID_VACTIVE_LINES_ACT) Video Mode VACTIVE Lines Active Value Register  Reset Value */

#define DSI_VID_VACTIVE_LINES_ACT_V_ACTIVE_LINES_Pos _UINT32_(0)                                          /* (DSI_VID_VACTIVE_LINES_ACT) Video Mode Vertical Active Lines Position */
#define DSI_VID_VACTIVE_LINES_ACT_V_ACTIVE_LINES_Msk (_UINT32_(0x3FFF) << DSI_VID_VACTIVE_LINES_ACT_V_ACTIVE_LINES_Pos) /* (DSI_VID_VACTIVE_LINES_ACT) Video Mode Vertical Active Lines Mask */
#define DSI_VID_VACTIVE_LINES_ACT_V_ACTIVE_LINES(value) (DSI_VID_VACTIVE_LINES_ACT_V_ACTIVE_LINES_Msk & (_UINT32_(value) << DSI_VID_VACTIVE_LINES_ACT_V_ACTIVE_LINES_Pos)) /* Assigment of value for V_ACTIVE_LINES in the DSI_VID_VACTIVE_LINES_ACT register */
#define DSI_VID_VACTIVE_LINES_ACT_Msk         _UINT32_(0x00003FFF)                                 /* (DSI_VID_VACTIVE_LINES_ACT) Register Mask  */


/* -------- DSI_VID_PKT_STATUS : (DSI Offset: 0x168) ( R/ 32) Video Mode Packet Status Register -------- */
#define DSI_VID_PKT_STATUS_RESETVALUE         _UINT32_(0x00)                                       /*  (DSI_VID_PKT_STATUS) Video Mode Packet Status Register  Reset Value */

#define DSI_VID_PKT_STATUS_DPI_CMD_W_EMPTY_Pos _UINT32_(0)                                          /* (DSI_VID_PKT_STATUS) Input Video Interface Command Fifo Empty Position */
#define DSI_VID_PKT_STATUS_DPI_CMD_W_EMPTY_Msk (_UINT32_(0x1) << DSI_VID_PKT_STATUS_DPI_CMD_W_EMPTY_Pos) /* (DSI_VID_PKT_STATUS) Input Video Interface Command Fifo Empty Mask */
#define DSI_VID_PKT_STATUS_DPI_CMD_W_EMPTY(value) (DSI_VID_PKT_STATUS_DPI_CMD_W_EMPTY_Msk & (_UINT32_(value) << DSI_VID_PKT_STATUS_DPI_CMD_W_EMPTY_Pos)) /* Assigment of value for DPI_CMD_W_EMPTY in the DSI_VID_PKT_STATUS register */
#define DSI_VID_PKT_STATUS_DPI_CMD_W_FULL_Pos _UINT32_(1)                                          /* (DSI_VID_PKT_STATUS) Input Video Interface Command Fifo Full Position */
#define DSI_VID_PKT_STATUS_DPI_CMD_W_FULL_Msk (_UINT32_(0x1) << DSI_VID_PKT_STATUS_DPI_CMD_W_FULL_Pos) /* (DSI_VID_PKT_STATUS) Input Video Interface Command Fifo Full Mask */
#define DSI_VID_PKT_STATUS_DPI_CMD_W_FULL(value) (DSI_VID_PKT_STATUS_DPI_CMD_W_FULL_Msk & (_UINT32_(value) << DSI_VID_PKT_STATUS_DPI_CMD_W_FULL_Pos)) /* Assigment of value for DPI_CMD_W_FULL in the DSI_VID_PKT_STATUS register */
#define DSI_VID_PKT_STATUS_DPI_PLD_W_EMPTY_Pos _UINT32_(2)                                          /* (DSI_VID_PKT_STATUS) Input Video Interface Write Payload Fifo Empty Position */
#define DSI_VID_PKT_STATUS_DPI_PLD_W_EMPTY_Msk (_UINT32_(0x1) << DSI_VID_PKT_STATUS_DPI_PLD_W_EMPTY_Pos) /* (DSI_VID_PKT_STATUS) Input Video Interface Write Payload Fifo Empty Mask */
#define DSI_VID_PKT_STATUS_DPI_PLD_W_EMPTY(value) (DSI_VID_PKT_STATUS_DPI_PLD_W_EMPTY_Msk & (_UINT32_(value) << DSI_VID_PKT_STATUS_DPI_PLD_W_EMPTY_Pos)) /* Assigment of value for DPI_PLD_W_EMPTY in the DSI_VID_PKT_STATUS register */
#define DSI_VID_PKT_STATUS_DPI_PLD_W_FULL_Pos _UINT32_(3)                                          /* (DSI_VID_PKT_STATUS) Input Video Interface Write Payload Fifo Full Position */
#define DSI_VID_PKT_STATUS_DPI_PLD_W_FULL_Msk (_UINT32_(0x1) << DSI_VID_PKT_STATUS_DPI_PLD_W_FULL_Pos) /* (DSI_VID_PKT_STATUS) Input Video Interface Write Payload Fifo Full Mask */
#define DSI_VID_PKT_STATUS_DPI_PLD_W_FULL(value) (DSI_VID_PKT_STATUS_DPI_PLD_W_FULL_Msk & (_UINT32_(value) << DSI_VID_PKT_STATUS_DPI_PLD_W_FULL_Pos)) /* Assigment of value for DPI_PLD_W_FULL in the DSI_VID_PKT_STATUS register */
#define DSI_VID_PKT_STATUS_DPI_BUFF_PLD_EMPTY_Pos _UINT32_(16)                                         /* (DSI_VID_PKT_STATUS) Input Video Interface Write Payload Fifo Empty Position */
#define DSI_VID_PKT_STATUS_DPI_BUFF_PLD_EMPTY_Msk (_UINT32_(0x1) << DSI_VID_PKT_STATUS_DPI_BUFF_PLD_EMPTY_Pos) /* (DSI_VID_PKT_STATUS) Input Video Interface Write Payload Fifo Empty Mask */
#define DSI_VID_PKT_STATUS_DPI_BUFF_PLD_EMPTY(value) (DSI_VID_PKT_STATUS_DPI_BUFF_PLD_EMPTY_Msk & (_UINT32_(value) << DSI_VID_PKT_STATUS_DPI_BUFF_PLD_EMPTY_Pos)) /* Assigment of value for DPI_BUFF_PLD_EMPTY in the DSI_VID_PKT_STATUS register */
#define DSI_VID_PKT_STATUS_DPI_BUFF_PLD_FULL_Pos _UINT32_(17)                                         /* (DSI_VID_PKT_STATUS) Input Video Interface Write Payload Fifo Full Position */
#define DSI_VID_PKT_STATUS_DPI_BUFF_PLD_FULL_Msk (_UINT32_(0x1) << DSI_VID_PKT_STATUS_DPI_BUFF_PLD_FULL_Pos) /* (DSI_VID_PKT_STATUS) Input Video Interface Write Payload Fifo Full Mask */
#define DSI_VID_PKT_STATUS_DPI_BUFF_PLD_FULL(value) (DSI_VID_PKT_STATUS_DPI_BUFF_PLD_FULL_Msk & (_UINT32_(value) << DSI_VID_PKT_STATUS_DPI_BUFF_PLD_FULL_Pos)) /* Assigment of value for DPI_BUFF_PLD_FULL in the DSI_VID_PKT_STATUS register */
#define DSI_VID_PKT_STATUS_Msk                _UINT32_(0x0003000F)                                 /* (DSI_VID_PKT_STATUS) Register Mask  */


/* -------- DSI_SDF_3D_ACT : (DSI Offset: 0x190) ( R/ 32) VSS Packet 3D Active Value Register -------- */
#define DSI_SDF_3D_ACT_RESETVALUE             _UINT32_(0x00)                                       /*  (DSI_SDF_3D_ACT) VSS Packet 3D Active Value Register  Reset Value */

#define DSI_SDF_3D_ACT_MODE_3D_Pos            _UINT32_(0)                                          /* (DSI_SDF_3D_ACT) 3D Mode Position */
#define DSI_SDF_3D_ACT_MODE_3D_Msk            (_UINT32_(0x3) << DSI_SDF_3D_ACT_MODE_3D_Pos)        /* (DSI_SDF_3D_ACT) 3D Mode Mask */
#define DSI_SDF_3D_ACT_MODE_3D(value)         (DSI_SDF_3D_ACT_MODE_3D_Msk & (_UINT32_(value) << DSI_SDF_3D_ACT_MODE_3D_Pos)) /* Assigment of value for MODE_3D in the DSI_SDF_3D_ACT register */
#define   DSI_SDF_3D_ACT_MODE_3D_0_Val        _UINT32_(0x0)                                        /* (DSI_SDF_3D_ACT) 3D Mode off (2D Mode on).  */
#define   DSI_SDF_3D_ACT_MODE_3D_1_Val        _UINT32_(0x1)                                        /* (DSI_SDF_3D_ACT) 3D Mode on, portrait orientation.  */
#define   DSI_SDF_3D_ACT_MODE_3D_2_Val        _UINT32_(0x2)                                        /* (DSI_SDF_3D_ACT) 3D Mode on, landscape orientation.  */
#define   DSI_SDF_3D_ACT_MODE_3D_3_Val        _UINT32_(0x3)                                        /* (DSI_SDF_3D_ACT) Reserved.  */
#define DSI_SDF_3D_ACT_MODE_3D_0              (DSI_SDF_3D_ACT_MODE_3D_0_Val << DSI_SDF_3D_ACT_MODE_3D_Pos) /* (DSI_SDF_3D_ACT) 3D Mode off (2D Mode on). Position  */
#define DSI_SDF_3D_ACT_MODE_3D_1              (DSI_SDF_3D_ACT_MODE_3D_1_Val << DSI_SDF_3D_ACT_MODE_3D_Pos) /* (DSI_SDF_3D_ACT) 3D Mode on, portrait orientation. Position  */
#define DSI_SDF_3D_ACT_MODE_3D_2              (DSI_SDF_3D_ACT_MODE_3D_2_Val << DSI_SDF_3D_ACT_MODE_3D_Pos) /* (DSI_SDF_3D_ACT) 3D Mode on, landscape orientation. Position  */
#define DSI_SDF_3D_ACT_MODE_3D_3              (DSI_SDF_3D_ACT_MODE_3D_3_Val << DSI_SDF_3D_ACT_MODE_3D_Pos) /* (DSI_SDF_3D_ACT) Reserved. Position  */
#define DSI_SDF_3D_ACT_FORMAT_3D_Pos          _UINT32_(2)                                          /* (DSI_SDF_3D_ACT) 3D Format Position */
#define DSI_SDF_3D_ACT_FORMAT_3D_Msk          (_UINT32_(0x3) << DSI_SDF_3D_ACT_FORMAT_3D_Pos)      /* (DSI_SDF_3D_ACT) 3D Format Mask */
#define DSI_SDF_3D_ACT_FORMAT_3D(value)       (DSI_SDF_3D_ACT_FORMAT_3D_Msk & (_UINT32_(value) << DSI_SDF_3D_ACT_FORMAT_3D_Pos)) /* Assigment of value for FORMAT_3D in the DSI_SDF_3D_ACT register */
#define   DSI_SDF_3D_ACT_FORMAT_3D_0_Val      _UINT32_(0x0)                                        /* (DSI_SDF_3D_ACT) Line (alternating lines of left and right data).  */
#define   DSI_SDF_3D_ACT_FORMAT_3D_1_Val      _UINT32_(0x1)                                        /* (DSI_SDF_3D_ACT) Frame (alternating frames of left and right data).  */
#define   DSI_SDF_3D_ACT_FORMAT_3D_2_Val      _UINT32_(0x2)                                        /* (DSI_SDF_3D_ACT) Pixel (alternating pixels of left and right data).  */
#define DSI_SDF_3D_ACT_FORMAT_3D_0            (DSI_SDF_3D_ACT_FORMAT_3D_0_Val << DSI_SDF_3D_ACT_FORMAT_3D_Pos) /* (DSI_SDF_3D_ACT) Line (alternating lines of left and right data). Position  */
#define DSI_SDF_3D_ACT_FORMAT_3D_1            (DSI_SDF_3D_ACT_FORMAT_3D_1_Val << DSI_SDF_3D_ACT_FORMAT_3D_Pos) /* (DSI_SDF_3D_ACT) Frame (alternating frames of left and right data). Position  */
#define DSI_SDF_3D_ACT_FORMAT_3D_2            (DSI_SDF_3D_ACT_FORMAT_3D_2_Val << DSI_SDF_3D_ACT_FORMAT_3D_Pos) /* (DSI_SDF_3D_ACT) Pixel (alternating pixels of left and right data). Position  */
#define DSI_SDF_3D_ACT_SECOND_VSYNC_Pos       _UINT32_(4)                                          /* (DSI_SDF_3D_ACT) Second Vertical Sync Enable Position */
#define DSI_SDF_3D_ACT_SECOND_VSYNC_Msk       (_UINT32_(0x1) << DSI_SDF_3D_ACT_SECOND_VSYNC_Pos)   /* (DSI_SDF_3D_ACT) Second Vertical Sync Enable Mask */
#define DSI_SDF_3D_ACT_SECOND_VSYNC(value)    (DSI_SDF_3D_ACT_SECOND_VSYNC_Msk & (_UINT32_(value) << DSI_SDF_3D_ACT_SECOND_VSYNC_Pos)) /* Assigment of value for SECOND_VSYNC in the DSI_SDF_3D_ACT register */
#define   DSI_SDF_3D_ACT_SECOND_VSYNC_0_Val   _UINT32_(0x0)                                        /* (DSI_SDF_3D_ACT) No sync pulses between left and right data.  */
#define   DSI_SDF_3D_ACT_SECOND_VSYNC_1_Val   _UINT32_(0x1)                                        /* (DSI_SDF_3D_ACT) Sync pulse (HSYNC, VSYNC, blanking) between left and right data.  */
#define DSI_SDF_3D_ACT_SECOND_VSYNC_0         (DSI_SDF_3D_ACT_SECOND_VSYNC_0_Val << DSI_SDF_3D_ACT_SECOND_VSYNC_Pos) /* (DSI_SDF_3D_ACT) No sync pulses between left and right data. Position  */
#define DSI_SDF_3D_ACT_SECOND_VSYNC_1         (DSI_SDF_3D_ACT_SECOND_VSYNC_1_Val << DSI_SDF_3D_ACT_SECOND_VSYNC_Pos) /* (DSI_SDF_3D_ACT) Sync pulse (HSYNC, VSYNC, blanking) between left and right data. Position  */
#define DSI_SDF_3D_ACT_RIGHT_FIRST_Pos        _UINT32_(5)                                          /* (DSI_SDF_3D_ACT) Right First Position */
#define DSI_SDF_3D_ACT_RIGHT_FIRST_Msk        (_UINT32_(0x1) << DSI_SDF_3D_ACT_RIGHT_FIRST_Pos)    /* (DSI_SDF_3D_ACT) Right First Mask */
#define DSI_SDF_3D_ACT_RIGHT_FIRST(value)     (DSI_SDF_3D_ACT_RIGHT_FIRST_Msk & (_UINT32_(value) << DSI_SDF_3D_ACT_RIGHT_FIRST_Pos)) /* Assigment of value for RIGHT_FIRST in the DSI_SDF_3D_ACT register */
#define   DSI_SDF_3D_ACT_RIGHT_FIRST_0_Val    _UINT32_(0x0)                                        /* (DSI_SDF_3D_ACT) Left eye is sent first, then right eye.  */
#define   DSI_SDF_3D_ACT_RIGHT_FIRST_1_Val    _UINT32_(0x1)                                        /* (DSI_SDF_3D_ACT) Right eye data is sent first, then left eye.  */
#define DSI_SDF_3D_ACT_RIGHT_FIRST_0          (DSI_SDF_3D_ACT_RIGHT_FIRST_0_Val << DSI_SDF_3D_ACT_RIGHT_FIRST_Pos) /* (DSI_SDF_3D_ACT) Left eye is sent first, then right eye. Position  */
#define DSI_SDF_3D_ACT_RIGHT_FIRST_1          (DSI_SDF_3D_ACT_RIGHT_FIRST_1_Val << DSI_SDF_3D_ACT_RIGHT_FIRST_Pos) /* (DSI_SDF_3D_ACT) Right eye data is sent first, then left eye. Position  */
#define DSI_SDF_3D_ACT_SEND_3D_CFG_Pos        _UINT32_(16)                                         /* (DSI_SDF_3D_ACT) Send 3D Configuration Enable Position */
#define DSI_SDF_3D_ACT_SEND_3D_CFG_Msk        (_UINT32_(0x1) << DSI_SDF_3D_ACT_SEND_3D_CFG_Pos)    /* (DSI_SDF_3D_ACT) Send 3D Configuration Enable Mask */
#define DSI_SDF_3D_ACT_SEND_3D_CFG(value)     (DSI_SDF_3D_ACT_SEND_3D_CFG_Msk & (_UINT32_(value) << DSI_SDF_3D_ACT_SEND_3D_CFG_Pos)) /* Assigment of value for SEND_3D_CFG in the DSI_SDF_3D_ACT register */
#define DSI_SDF_3D_ACT_Msk                    _UINT32_(0x0001003F)                                 /* (DSI_SDF_3D_ACT) Register Mask  */


/** \brief DSI register offsets definitions */
#define DSI_PWR_UP_REG_OFST            _UINT32_(0x04)      /* (DSI_PWR_UP) Power-Up Control Register Offset */
#define DSI_CLKMGR_CFG_REG_OFST        _UINT32_(0x08)      /* (DSI_CLKMGR_CFG) Clock Management Configuration Register Offset */
#define DSI_DPI_VCID_REG_OFST          _UINT32_(0x0C)      /* (DSI_DPI_VCID) Input Video Virtual Channel ID Configuration Register Offset */
#define DSI_DPI_COLOR_CODING_REG_OFST  _UINT32_(0x10)      /* (DSI_DPI_COLOR_CODING) Input Video Color Coding Configuration Register Offset */
#define DSI_DPI_CFG_POL_REG_OFST       _UINT32_(0x14)      /* (DSI_DPI_CFG_POL) Input Video Polarity Configuration Register Offset */
#define DSI_DPI_LP_CMD_TIM_REG_OFST    _UINT32_(0x18)      /* (DSI_DPI_LP_CMD_TIM) Input Video Timing for Low-Power Commands Configuration Register Offset */
#define DSI_PCKHDL_CFG_REG_OFST        _UINT32_(0x2C)      /* (DSI_PCKHDL_CFG) DSI Protocol Configuration Register Offset */
#define DSI_GEN_VCID_REG_OFST          _UINT32_(0x30)      /* (DSI_GEN_VCID) Read Generic Virtual Channel ID Configuration Register Offset */
#define DSI_MODE_CFG_REG_OFST          _UINT32_(0x34)      /* (DSI_MODE_CFG) Mode of Operation Configuration Register Offset */
#define DSI_VID_MODE_CFG_REG_OFST      _UINT32_(0x38)      /* (DSI_VID_MODE_CFG) Video Mode Configuration Register Offset */
#define DSI_VID_PKT_SIZE_REG_OFST      _UINT32_(0x3C)      /* (DSI_VID_PKT_SIZE) Video Mode packet size Configuration Register Offset */
#define DSI_VID_NUM_CHUNKS_REG_OFST    _UINT32_(0x40)      /* (DSI_VID_NUM_CHUNKS) Video Mode Number of Chunks Configuration Register Offset */
#define DSI_VID_NULL_SIZE_REG_OFST     _UINT32_(0x44)      /* (DSI_VID_NULL_SIZE) Video Mode Null Packets Size Configuration Register Offset */
#define DSI_VID_HSA_TIME_REG_OFST      _UINT32_(0x48)      /* (DSI_VID_HSA_TIME) Video Mode HSA Time Configuration Register Offset */
#define DSI_VID_HBP_TIME_REG_OFST      _UINT32_(0x4C)      /* (DSI_VID_HBP_TIME) Video Mode HBP Time Configuration Register Offset */
#define DSI_VID_HLINE_TIME_REG_OFST    _UINT32_(0x50)      /* (DSI_VID_HLINE_TIME) Video Mode HLINE Time Configuration Register Offset */
#define DSI_VID_VSA_LINES_REG_OFST     _UINT32_(0x54)      /* (DSI_VID_VSA_LINES) Video Mode VSA Lines Configuration Register Offset */
#define DSI_VID_VBP_LINES_REG_OFST     _UINT32_(0x58)      /* (DSI_VID_VBP_LINES) Video Mode VBP Lines Configuration Register Offset */
#define DSI_VID_VFP_LINES_REG_OFST     _UINT32_(0x5C)      /* (DSI_VID_VFP_LINES) Video Mode VFP Lines Configuration Register Offset */
#define DSI_VID_VACTIVE_LINES_REG_OFST _UINT32_(0x60)      /* (DSI_VID_VACTIVE_LINES) Video Mode VACTIVE Lines Configuration Register Offset */
#define DSI_CMD_MODE_CFG_REG_OFST      _UINT32_(0x68)      /* (DSI_CMD_MODE_CFG) Command Mode Configuration Register Offset */
#define DSI_GEN_HDR_REG_OFST           _UINT32_(0x6C)      /* (DSI_GEN_HDR) Generic Interface Header Register Offset */
#define DSI_GEN_PLD_DATA_REG_OFST      _UINT32_(0x70)      /* (DSI_GEN_PLD_DATA) Generic Interface Payload Register Offset */
#define DSI_CMD_PKT_STATUS_REG_OFST    _UINT32_(0x74)      /* (DSI_CMD_PKT_STATUS) Command Packet Status Register Offset */
#define DSI_TO_CNT_CFG_REG_OFST        _UINT32_(0x78)      /* (DSI_TO_CNT_CFG) Timeout Counters Configuration Register Offset */
#define DSI_HS_RD_TO_CNT_REG_OFST      _UINT32_(0x7C)      /* (DSI_HS_RD_TO_CNT) HS Read Response Timeout Counter Configuration Register Offset */
#define DSI_LP_RD_TO_CNT_REG_OFST      _UINT32_(0x80)      /* (DSI_LP_RD_TO_CNT) LP Read Response Timeout Counter Configuration Register Offset */
#define DSI_HS_WR_TO_CNT_REG_OFST      _UINT32_(0x84)      /* (DSI_HS_WR_TO_CNT) HS Write Response Timeout Counter Configuration Register Offset */
#define DSI_LP_WR_TO_CNT_REG_OFST      _UINT32_(0x88)      /* (DSI_LP_WR_TO_CNT) LP Write Response Timeout Counter Configuration Register Offset */
#define DSI_BTA_TO_CNT_REG_OFST        _UINT32_(0x8C)      /* (DSI_BTA_TO_CNT) BTA Response Timeout Counter Configuration Register Offset */
#define DSI_SDF_3D_REG_OFST            _UINT32_(0x90)      /* (DSI_SDF_3D) VSS Packet 3D Control Register Offset */
#define DSI_LPCLK_CTRL_REG_OFST        _UINT32_(0x94)      /* (DSI_LPCLK_CTRL) Clock Lane Control Register Offset */
#define DSI_DPHY_TMR_LPCLK_CFG_REG_OFST _UINT32_(0x98)      /* (DSI_DPHY_TMR_LPCLK_CFG) Clock Lane Switch Mode Timing Configuration Register Offset */
#define DSI_DPHY_TMR_CFG_REG_OFST      _UINT32_(0x9C)      /* (DSI_DPHY_TMR_CFG) Data Lane Switch Mode Timing Configuration Register Offset */
#define DSI_DPHY_RSTZ_REG_OFST         _UINT32_(0xA0)      /* (DSI_DPHY_RSTZ) Reset and PLL Control Register Offset */
#define DSI_DPHY_IF_CFG_REG_OFST       _UINT32_(0xA4)      /* (DSI_DPHY_IF_CFG) D-PHY Interface Configuration Register Offset */
#define DSI_DPHY_ULPS_CTRL_REG_OFST    _UINT32_(0xA8)      /* (DSI_DPHY_ULPS_CTRL) D-PHY ULPS Control Register Offset */
#define DSI_DPHY_TX_TRIGGERS_REG_OFST  _UINT32_(0xAC)      /* (DSI_DPHY_TX_TRIGGERS) D-PHY Tx Trigger Control Register Offset */
#define DSI_DPHY_STATUS_REG_OFST       _UINT32_(0xB0)      /* (DSI_DPHY_STATUS) D-PHY Status Register Offset */
#define DSI_DPHY_TST_CTRL0_REG_OFST    _UINT32_(0xB4)      /* (DSI_DPHY_TST_CTRL0) D-PHY Control Register 0 Offset */
#define DSI_DPHY_TST_CTRL1_REG_OFST    _UINT32_(0xB8)      /* (DSI_DPHY_TST_CTRL1) D-PHY Control Register 1 Offset */
#define DSI_INT_ST0_REG_OFST           _UINT32_(0xBC)      /* (DSI_INT_ST0) Interrupt Status Register 0 Offset */
#define DSI_INT_ST1_REG_OFST           _UINT32_(0xC0)      /* (DSI_INT_ST1) Interrupt Status Register 1 Offset */
#define DSI_INT_MSK0_REG_OFST          _UINT32_(0xC4)      /* (DSI_INT_MSK0) Interrupt Mask Configuration Register 0 Offset */
#define DSI_INT_MSK1_REG_OFST          _UINT32_(0xC8)      /* (DSI_INT_MSK1) Interrupt Mask Configuration Register 1 Offset */
#define DSI_DPHY_CAL_REG_OFST          _UINT32_(0xCC)      /* (DSI_DPHY_CAL) D-PHY Calibration Control Register Offset */
#define DSI_INT_FORCE0_REG_OFST        _UINT32_(0xD8)      /* (DSI_INT_FORCE0) Interrupt Force Control Register 0 Offset */
#define DSI_INT_FORCE1_REG_OFST        _UINT32_(0xDC)      /* (DSI_INT_FORCE1) Interrupt Force Control Register 1 Offset */
#define DSI_AUTO_ULPS_MODE_REG_OFST    _UINT32_(0xE0)      /* (DSI_AUTO_ULPS_MODE) Automatic Ultra-Low-Power Mode Register Offset */
#define DSI_AUTO_ULPS_ENTRY_DELAY_REG_OFST _UINT32_(0xE4)      /* (DSI_AUTO_ULPS_ENTRY_DELAY) Automatic Ultra-Low-Power Entry Delay Register Offset */
#define DSI_AUTO_ULPS_WAKEUP_TIME_REG_OFST _UINT32_(0xE8)      /* (DSI_AUTO_ULPS_WAKEUP_TIME) Automatic Ultra-Low-Power Wake-Up Time Register Offset */
#define DSI_DPHY_TMR_RD_CFG_REG_OFST   _UINT32_(0xF4)      /* (DSI_DPHY_TMR_RD_CFG) DHY Read Timing Configuration Register Offset */
#define DSI_AUTO_ULPS_MIN_TIME_REG_OFST _UINT32_(0xF8)      /* (DSI_AUTO_ULPS_MIN_TIME) Automatic Ultra-Low-Power Minimum Time Register Offset */
#define DSI_VID_SHADOW_CTRL_REG_OFST   _UINT32_(0x100)     /* (DSI_VID_SHADOW_CTRL) Video Mode Shadow Feature Control Register Offset */
#define DSI_DPI_VCID_ACT_REG_OFST      _UINT32_(0x10C)     /* (DSI_DPI_VCID_ACT) Input Video Virtual Channel ID Active Value Register Offset */
#define DSI_DPI_COLOR_CODING_ACT_REG_OFST _UINT32_(0x110)     /* (DSI_DPI_COLOR_CODING_ACT) Input Video Color Coding Active Value Register Offset */
#define DSI_DPI_LP_CMD_TIM_ACT_REG_OFST _UINT32_(0x118)     /* (DSI_DPI_LP_CMD_TIM_ACT) Input Video Timing for Low-Power Commands Active Value Register Offset */
#define DSI_VID_MODE_CFG_ACT_REG_OFST  _UINT32_(0x138)     /* (DSI_VID_MODE_CFG_ACT) Video Mode Active Value Register Offset */
#define DSI_VID_PKT_SIZE_ACT_REG_OFST  _UINT32_(0x13C)     /* (DSI_VID_PKT_SIZE_ACT) Video Mode packet size Active Value Register Offset */
#define DSI_VID_NUM_CHUNKS_ACT_REG_OFST _UINT32_(0x140)     /* (DSI_VID_NUM_CHUNKS_ACT) Video Mode Number of Chunks Active Value Register Offset */
#define DSI_VID_NULL_SIZE_ACT_REG_OFST _UINT32_(0x144)     /* (DSI_VID_NULL_SIZE_ACT) Video Mode Null Packets Size Active Value Register Offset */
#define DSI_VID_HSA_TIME_ACT_REG_OFST  _UINT32_(0x148)     /* (DSI_VID_HSA_TIME_ACT) Video Mode HSA Time Active Value Register Offset */
#define DSI_VID_HBP_TIME_ACT_REG_OFST  _UINT32_(0x14C)     /* (DSI_VID_HBP_TIME_ACT) Video Mode HBP Time Active Value Register Offset */
#define DSI_VID_HLINE_TIME_ACT_REG_OFST _UINT32_(0x150)     /* (DSI_VID_HLINE_TIME_ACT) Video Mode HLINE Time Active Value Register Offset */
#define DSI_VID_VSA_LINES_ACT_REG_OFST _UINT32_(0x154)     /* (DSI_VID_VSA_LINES_ACT) Video Mode VSA Lines Active Value Register Offset */
#define DSI_VID_VBP_LINES_ACT_REG_OFST _UINT32_(0x158)     /* (DSI_VID_VBP_LINES_ACT) Video Mode VBP Lines Active Value Register Offset */
#define DSI_VID_VFP_LINES_ACT_REG_OFST _UINT32_(0x15C)     /* (DSI_VID_VFP_LINES_ACT) Video Mode VFP Lines Active Value Register Offset */
#define DSI_VID_VACTIVE_LINES_ACT_REG_OFST _UINT32_(0x160)     /* (DSI_VID_VACTIVE_LINES_ACT) Video Mode VACTIVE Lines Active Value Register Offset */
#define DSI_VID_PKT_STATUS_REG_OFST    _UINT32_(0x168)     /* (DSI_VID_PKT_STATUS) Video Mode Packet Status Register Offset */
#define DSI_SDF_3D_ACT_REG_OFST        _UINT32_(0x190)     /* (DSI_SDF_3D_ACT) VSS Packet 3D Active Value Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief DSI register API structure */
typedef struct
{  /* LCD Controller */
  __I   uint8_t                        Reserved1[0x04];
  __IO  uint32_t                       DSI_PWR_UP;         /**< Offset: 0x04 (R/W  32) Power-Up Control Register */
  __IO  uint32_t                       DSI_CLKMGR_CFG;     /**< Offset: 0x08 (R/W  32) Clock Management Configuration Register */
  __IO  uint32_t                       DSI_DPI_VCID;       /**< Offset: 0x0C (R/W  32) Input Video Virtual Channel ID Configuration Register */
  __IO  uint32_t                       DSI_DPI_COLOR_CODING; /**< Offset: 0x10 (R/W  32) Input Video Color Coding Configuration Register */
  __IO  uint32_t                       DSI_DPI_CFG_POL;    /**< Offset: 0x14 (R/W  32) Input Video Polarity Configuration Register */
  __IO  uint32_t                       DSI_DPI_LP_CMD_TIM; /**< Offset: 0x18 (R/W  32) Input Video Timing for Low-Power Commands Configuration Register */
  __I   uint8_t                        Reserved2[0x10];
  __IO  uint32_t                       DSI_PCKHDL_CFG;     /**< Offset: 0x2C (R/W  32) DSI Protocol Configuration Register */
  __IO  uint32_t                       DSI_GEN_VCID;       /**< Offset: 0x30 (R/W  32) Read Generic Virtual Channel ID Configuration Register */
  __IO  uint32_t                       DSI_MODE_CFG;       /**< Offset: 0x34 (R/W  32) Mode of Operation Configuration Register */
  __IO  uint32_t                       DSI_VID_MODE_CFG;   /**< Offset: 0x38 (R/W  32) Video Mode Configuration Register */
  __IO  uint32_t                       DSI_VID_PKT_SIZE;   /**< Offset: 0x3C (R/W  32) Video Mode packet size Configuration Register */
  __IO  uint32_t                       DSI_VID_NUM_CHUNKS; /**< Offset: 0x40 (R/W  32) Video Mode Number of Chunks Configuration Register */
  __IO  uint32_t                       DSI_VID_NULL_SIZE;  /**< Offset: 0x44 (R/W  32) Video Mode Null Packets Size Configuration Register */
  __IO  uint32_t                       DSI_VID_HSA_TIME;   /**< Offset: 0x48 (R/W  32) Video Mode HSA Time Configuration Register */
  __IO  uint32_t                       DSI_VID_HBP_TIME;   /**< Offset: 0x4C (R/W  32) Video Mode HBP Time Configuration Register */
  __IO  uint32_t                       DSI_VID_HLINE_TIME; /**< Offset: 0x50 (R/W  32) Video Mode HLINE Time Configuration Register */
  __IO  uint32_t                       DSI_VID_VSA_LINES;  /**< Offset: 0x54 (R/W  32) Video Mode VSA Lines Configuration Register */
  __IO  uint32_t                       DSI_VID_VBP_LINES;  /**< Offset: 0x58 (R/W  32) Video Mode VBP Lines Configuration Register */
  __IO  uint32_t                       DSI_VID_VFP_LINES;  /**< Offset: 0x5C (R/W  32) Video Mode VFP Lines Configuration Register */
  __IO  uint32_t                       DSI_VID_VACTIVE_LINES; /**< Offset: 0x60 (R/W  32) Video Mode VACTIVE Lines Configuration Register */
  __I   uint8_t                        Reserved3[0x04];
  __IO  uint32_t                       DSI_CMD_MODE_CFG;   /**< Offset: 0x68 (R/W  32) Command Mode Configuration Register */
  __IO  uint32_t                       DSI_GEN_HDR;        /**< Offset: 0x6C (R/W  32) Generic Interface Header Register */
  __IO  uint32_t                       DSI_GEN_PLD_DATA;   /**< Offset: 0x70 (R/W  32) Generic Interface Payload Register */
  __I   uint32_t                       DSI_CMD_PKT_STATUS; /**< Offset: 0x74 (R/   32) Command Packet Status Register */
  __IO  uint32_t                       DSI_TO_CNT_CFG;     /**< Offset: 0x78 (R/W  32) Timeout Counters Configuration Register */
  __IO  uint32_t                       DSI_HS_RD_TO_CNT;   /**< Offset: 0x7C (R/W  32) HS Read Response Timeout Counter Configuration Register */
  __IO  uint32_t                       DSI_LP_RD_TO_CNT;   /**< Offset: 0x80 (R/W  32) LP Read Response Timeout Counter Configuration Register */
  __IO  uint32_t                       DSI_HS_WR_TO_CNT;   /**< Offset: 0x84 (R/W  32) HS Write Response Timeout Counter Configuration Register */
  __IO  uint32_t                       DSI_LP_WR_TO_CNT;   /**< Offset: 0x88 (R/W  32) LP Write Response Timeout Counter Configuration Register */
  __IO  uint32_t                       DSI_BTA_TO_CNT;     /**< Offset: 0x8C (R/W  32) BTA Response Timeout Counter Configuration Register */
  __IO  uint32_t                       DSI_SDF_3D;         /**< Offset: 0x90 (R/W  32) VSS Packet 3D Control Register */
  __IO  uint32_t                       DSI_LPCLK_CTRL;     /**< Offset: 0x94 (R/W  32) Clock Lane Control Register */
  __IO  uint32_t                       DSI_DPHY_TMR_LPCLK_CFG; /**< Offset: 0x98 (R/W  32) Clock Lane Switch Mode Timing Configuration Register */
  __IO  uint32_t                       DSI_DPHY_TMR_CFG;   /**< Offset: 0x9C (R/W  32) Data Lane Switch Mode Timing Configuration Register */
  __IO  uint32_t                       DSI_DPHY_RSTZ;      /**< Offset: 0xA0 (R/W  32) Reset and PLL Control Register */
  __IO  uint32_t                       DSI_DPHY_IF_CFG;    /**< Offset: 0xA4 (R/W  32) D-PHY Interface Configuration Register */
  __IO  uint32_t                       DSI_DPHY_ULPS_CTRL; /**< Offset: 0xA8 (R/W  32) D-PHY ULPS Control Register */
  __IO  uint32_t                       DSI_DPHY_TX_TRIGGERS; /**< Offset: 0xAC (R/W  32) D-PHY Tx Trigger Control Register */
  __I   uint32_t                       DSI_DPHY_STATUS;    /**< Offset: 0xB0 (R/   32) D-PHY Status Register */
  __IO  uint32_t                       DSI_DPHY_TST_CTRL0; /**< Offset: 0xB4 (R/W  32) D-PHY Control Register 0 */
  __IO  uint32_t                       DSI_DPHY_TST_CTRL1; /**< Offset: 0xB8 (R/W  32) D-PHY Control Register 1 */
  __I   uint32_t                       DSI_INT_ST0;        /**< Offset: 0xBC (R/   32) Interrupt Status Register 0 */
  __I   uint32_t                       DSI_INT_ST1;        /**< Offset: 0xC0 (R/   32) Interrupt Status Register 1 */
  __IO  uint32_t                       DSI_INT_MSK0;       /**< Offset: 0xC4 (R/W  32) Interrupt Mask Configuration Register 0 */
  __IO  uint32_t                       DSI_INT_MSK1;       /**< Offset: 0xC8 (R/W  32) Interrupt Mask Configuration Register 1 */
  __IO  uint32_t                       DSI_DPHY_CAL;       /**< Offset: 0xCC (R/W  32) D-PHY Calibration Control Register */
  __I   uint8_t                        Reserved4[0x08];
  __IO  uint32_t                       DSI_INT_FORCE0;     /**< Offset: 0xD8 (R/W  32) Interrupt Force Control Register 0 */
  __IO  uint32_t                       DSI_INT_FORCE1;     /**< Offset: 0xDC (R/W  32) Interrupt Force Control Register 1 */
  __IO  uint32_t                       DSI_AUTO_ULPS_MODE; /**< Offset: 0xE0 (R/W  32) Automatic Ultra-Low-Power Mode Register */
  __IO  uint32_t                       DSI_AUTO_ULPS_ENTRY_DELAY; /**< Offset: 0xE4 (R/W  32) Automatic Ultra-Low-Power Entry Delay Register */
  __IO  uint32_t                       DSI_AUTO_ULPS_WAKEUP_TIME; /**< Offset: 0xE8 (R/W  32) Automatic Ultra-Low-Power Wake-Up Time Register */
  __I   uint8_t                        Reserved5[0x08];
  __IO  uint32_t                       DSI_DPHY_TMR_RD_CFG; /**< Offset: 0xF4 (R/W  32) DHY Read Timing Configuration Register */
  __IO  uint32_t                       DSI_AUTO_ULPS_MIN_TIME; /**< Offset: 0xF8 (R/W  32) Automatic Ultra-Low-Power Minimum Time Register */
  __I   uint8_t                        Reserved6[0x04];
  __IO  uint32_t                       DSI_VID_SHADOW_CTRL; /**< Offset: 0x100 (R/W  32) Video Mode Shadow Feature Control Register */
  __I   uint8_t                        Reserved7[0x08];
  __I   uint32_t                       DSI_DPI_VCID_ACT;   /**< Offset: 0x10C (R/   32) Input Video Virtual Channel ID Active Value Register */
  __I   uint32_t                       DSI_DPI_COLOR_CODING_ACT; /**< Offset: 0x110 (R/   32) Input Video Color Coding Active Value Register */
  __I   uint8_t                        Reserved8[0x04];
  __I   uint32_t                       DSI_DPI_LP_CMD_TIM_ACT; /**< Offset: 0x118 (R/   32) Input Video Timing for Low-Power Commands Active Value Register */
  __I   uint8_t                        Reserved9[0x1C];
  __I   uint32_t                       DSI_VID_MODE_CFG_ACT; /**< Offset: 0x138 (R/   32) Video Mode Active Value Register */
  __I   uint32_t                       DSI_VID_PKT_SIZE_ACT; /**< Offset: 0x13C (R/   32) Video Mode packet size Active Value Register */
  __I   uint32_t                       DSI_VID_NUM_CHUNKS_ACT; /**< Offset: 0x140 (R/   32) Video Mode Number of Chunks Active Value Register */
  __I   uint32_t                       DSI_VID_NULL_SIZE_ACT; /**< Offset: 0x144 (R/   32) Video Mode Null Packets Size Active Value Register */
  __I   uint32_t                       DSI_VID_HSA_TIME_ACT; /**< Offset: 0x148 (R/   32) Video Mode HSA Time Active Value Register */
  __I   uint32_t                       DSI_VID_HBP_TIME_ACT; /**< Offset: 0x14C (R/   32) Video Mode HBP Time Active Value Register */
  __I   uint32_t                       DSI_VID_HLINE_TIME_ACT; /**< Offset: 0x150 (R/   32) Video Mode HLINE Time Active Value Register */
  __I   uint32_t                       DSI_VID_VSA_LINES_ACT; /**< Offset: 0x154 (R/   32) Video Mode VSA Lines Active Value Register */
  __I   uint32_t                       DSI_VID_VBP_LINES_ACT; /**< Offset: 0x158 (R/   32) Video Mode VBP Lines Active Value Register */
  __I   uint32_t                       DSI_VID_VFP_LINES_ACT; /**< Offset: 0x15C (R/   32) Video Mode VFP Lines Active Value Register */
  __I   uint32_t                       DSI_VID_VACTIVE_LINES_ACT; /**< Offset: 0x160 (R/   32) Video Mode VACTIVE Lines Active Value Register */
  __I   uint8_t                        Reserved10[0x04];
  __I   uint32_t                       DSI_VID_PKT_STATUS; /**< Offset: 0x168 (R/   32) Video Mode Packet Status Register */
  __I   uint8_t                        Reserved11[0x24];
  __I   uint32_t                       DSI_SDF_3D_ACT;     /**< Offset: 0x190 (R/   32) VSS Packet 3D Active Value Register */
} dsi_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X7_DSI_COMPONENT_H_ */
