/*
 * Component description for MLB
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
#ifndef _PIC32CZCA90_MLB_COMPONENT_H_
#define _PIC32CZCA90_MLB_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR MLB                                          */
/* ************************************************************************** */

/* -------- MLB_CTRLA : (MLB Offset: 0x00) (R/W 32) MLB Wrapper Control Register -------- */
#define MLB_CTRLA_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_CTRLA) MLB Wrapper Control Register  Reset Value */

#define MLB_CTRLA_SWRST_Pos                   _UINT32_(0)                                          /* (MLB_CTRLA) Software Reset Position */
#define MLB_CTRLA_SWRST_Msk                   (_UINT32_(0x1) << MLB_CTRLA_SWRST_Pos)               /* (MLB_CTRLA) Software Reset Mask */
#define MLB_CTRLA_SWRST(value)                (MLB_CTRLA_SWRST_Msk & (_UINT32_(value) << MLB_CTRLA_SWRST_Pos)) /* Assigment of value for SWRST in the MLB_CTRLA register */
#define MLB_CTRLA_ENABLE_Pos                  _UINT32_(1)                                          /* (MLB_CTRLA) MediaLB Enable (ON) bit Position */
#define MLB_CTRLA_ENABLE_Msk                  (_UINT32_(0x1) << MLB_CTRLA_ENABLE_Pos)              /* (MLB_CTRLA) MediaLB Enable (ON) bit Mask */
#define MLB_CTRLA_ENABLE(value)               (MLB_CTRLA_ENABLE_Msk & (_UINT32_(value) << MLB_CTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the MLB_CTRLA register */
#define MLB_CTRLA_RUNSTDBY_Pos                _UINT32_(6)                                          /* (MLB_CTRLA) Run In Standby Position */
#define MLB_CTRLA_RUNSTDBY_Msk                (_UINT32_(0x1) << MLB_CTRLA_RUNSTDBY_Pos)            /* (MLB_CTRLA) Run In Standby Mask */
#define MLB_CTRLA_RUNSTDBY(value)             (MLB_CTRLA_RUNSTDBY_Msk & (_UINT32_(value) << MLB_CTRLA_RUNSTDBY_Pos)) /* Assigment of value for RUNSTDBY in the MLB_CTRLA register */
#define MLB_CTRLA_Msk                         _UINT32_(0x00000043)                                 /* (MLB_CTRLA) Register Mask  */


/* -------- MLB_INTENCLR : (MLB Offset: 0x10) (R/W 32) Interrupt Enable Clear Register -------- */
#define MLB_INTENCLR_RESETVALUE               _UINT32_(0x00)                                       /*  (MLB_INTENCLR) Interrupt Enable Clear Register  Reset Value */

#define MLB_INTENCLR_INTMLB_Pos               _UINT32_(0)                                          /* (MLB_INTENCLR) MLB General Interrupt Enable Clear Position */
#define MLB_INTENCLR_INTMLB_Msk               (_UINT32_(0x1) << MLB_INTENCLR_INTMLB_Pos)           /* (MLB_INTENCLR) MLB General Interrupt Enable Clear Mask */
#define MLB_INTENCLR_INTMLB(value)            (MLB_INTENCLR_INTMLB_Msk & (_UINT32_(value) << MLB_INTENCLR_INTMLB_Pos)) /* Assigment of value for INTMLB in the MLB_INTENCLR register */
#define MLB_INTENCLR_INT0AHB_Pos              _UINT32_(1)                                          /* (MLB_INTENCLR) AHB Interrupt 0 Enable Clear Position */
#define MLB_INTENCLR_INT0AHB_Msk              (_UINT32_(0x1) << MLB_INTENCLR_INT0AHB_Pos)          /* (MLB_INTENCLR) AHB Interrupt 0 Enable Clear Mask */
#define MLB_INTENCLR_INT0AHB(value)           (MLB_INTENCLR_INT0AHB_Msk & (_UINT32_(value) << MLB_INTENCLR_INT0AHB_Pos)) /* Assigment of value for INT0AHB in the MLB_INTENCLR register */
#define MLB_INTENCLR_INT1AHB_Pos              _UINT32_(2)                                          /* (MLB_INTENCLR) AHB Interrupt 1 Enable Clear Position */
#define MLB_INTENCLR_INT1AHB_Msk              (_UINT32_(0x1) << MLB_INTENCLR_INT1AHB_Pos)          /* (MLB_INTENCLR) AHB Interrupt 1 Enable Clear Mask */
#define MLB_INTENCLR_INT1AHB(value)           (MLB_INTENCLR_INT1AHB_Msk & (_UINT32_(value) << MLB_INTENCLR_INT1AHB_Pos)) /* Assigment of value for INT1AHB in the MLB_INTENCLR register */
#define MLB_INTENCLR_Msk                      _UINT32_(0x00000007)                                 /* (MLB_INTENCLR) Register Mask  */


/* -------- MLB_INTENSET : (MLB Offset: 0x14) (R/W 32) Interrupt Enable Set Register -------- */
#define MLB_INTENSET_RESETVALUE               _UINT32_(0x00)                                       /*  (MLB_INTENSET) Interrupt Enable Set Register  Reset Value */

#define MLB_INTENSET_INTMLB_Pos               _UINT32_(0)                                          /* (MLB_INTENSET) MLB General Interrupt Enable Set Position */
#define MLB_INTENSET_INTMLB_Msk               (_UINT32_(0x1) << MLB_INTENSET_INTMLB_Pos)           /* (MLB_INTENSET) MLB General Interrupt Enable Set Mask */
#define MLB_INTENSET_INTMLB(value)            (MLB_INTENSET_INTMLB_Msk & (_UINT32_(value) << MLB_INTENSET_INTMLB_Pos)) /* Assigment of value for INTMLB in the MLB_INTENSET register */
#define MLB_INTENSET_INT0AHB_Pos              _UINT32_(1)                                          /* (MLB_INTENSET) AHB Interrupt 0 Enable Set Position */
#define MLB_INTENSET_INT0AHB_Msk              (_UINT32_(0x1) << MLB_INTENSET_INT0AHB_Pos)          /* (MLB_INTENSET) AHB Interrupt 0 Enable Set Mask */
#define MLB_INTENSET_INT0AHB(value)           (MLB_INTENSET_INT0AHB_Msk & (_UINT32_(value) << MLB_INTENSET_INT0AHB_Pos)) /* Assigment of value for INT0AHB in the MLB_INTENSET register */
#define MLB_INTENSET_INT1AHB_Pos              _UINT32_(2)                                          /* (MLB_INTENSET) AHB Interrupt 1 Enable Set Position */
#define MLB_INTENSET_INT1AHB_Msk              (_UINT32_(0x1) << MLB_INTENSET_INT1AHB_Pos)          /* (MLB_INTENSET) AHB Interrupt 1 Enable Set Mask */
#define MLB_INTENSET_INT1AHB(value)           (MLB_INTENSET_INT1AHB_Msk & (_UINT32_(value) << MLB_INTENSET_INT1AHB_Pos)) /* Assigment of value for INT1AHB in the MLB_INTENSET register */
#define MLB_INTENSET_Msk                      _UINT32_(0x00000007)                                 /* (MLB_INTENSET) Register Mask  */


/* -------- MLB_INTFLAG : (MLB Offset: 0x18) (R/W 32) Interrupt Status and Clear Register -------- */
#define MLB_INTFLAG_RESETVALUE                _UINT32_(0x00)                                       /*  (MLB_INTFLAG) Interrupt Status and Clear Register  Reset Value */

#define MLB_INTFLAG_INTMLB_Pos                _UINT32_(0)                                          /* (MLB_INTFLAG) MLB General Interrupt Flag Position */
#define MLB_INTFLAG_INTMLB_Msk                (_UINT32_(0x1) << MLB_INTFLAG_INTMLB_Pos)            /* (MLB_INTFLAG) MLB General Interrupt Flag Mask */
#define MLB_INTFLAG_INTMLB(value)             (MLB_INTFLAG_INTMLB_Msk & (_UINT32_(value) << MLB_INTFLAG_INTMLB_Pos)) /* Assigment of value for INTMLB in the MLB_INTFLAG register */
#define MLB_INTFLAG_INT0AHB_Pos               _UINT32_(1)                                          /* (MLB_INTFLAG) AHB Interrupt 0 Flag Position */
#define MLB_INTFLAG_INT0AHB_Msk               (_UINT32_(0x1) << MLB_INTFLAG_INT0AHB_Pos)           /* (MLB_INTFLAG) AHB Interrupt 0 Flag Mask */
#define MLB_INTFLAG_INT0AHB(value)            (MLB_INTFLAG_INT0AHB_Msk & (_UINT32_(value) << MLB_INTFLAG_INT0AHB_Pos)) /* Assigment of value for INT0AHB in the MLB_INTFLAG register */
#define MLB_INTFLAG_INT1AHB_Pos               _UINT32_(2)                                          /* (MLB_INTFLAG) AHB Interrupt 1 Flag Position */
#define MLB_INTFLAG_INT1AHB_Msk               (_UINT32_(0x1) << MLB_INTFLAG_INT1AHB_Pos)           /* (MLB_INTFLAG) AHB Interrupt 1 Flag Mask */
#define MLB_INTFLAG_INT1AHB(value)            (MLB_INTFLAG_INT1AHB_Msk & (_UINT32_(value) << MLB_INTFLAG_INT1AHB_Pos)) /* Assigment of value for INT1AHB in the MLB_INTFLAG register */
#define MLB_INTFLAG_Msk                       _UINT32_(0x00000007)                                 /* (MLB_INTFLAG) Register Mask  */


/* -------- MLB_DBGCTRL : (MLB Offset: 0x1C) (R/W 32) Debug Control Register -------- */
#define MLB_DBGCTRL_RESETVALUE                _UINT32_(0x00)                                       /*  (MLB_DBGCTRL) Debug Control Register  Reset Value */

#define MLB_DBGCTRL_DBGRUN_Pos                _UINT32_(0)                                          /* (MLB_DBGCTRL) Debug Run Enable Position */
#define MLB_DBGCTRL_DBGRUN_Msk                (_UINT32_(0x1) << MLB_DBGCTRL_DBGRUN_Pos)            /* (MLB_DBGCTRL) Debug Run Enable Mask */
#define MLB_DBGCTRL_DBGRUN(value)             (MLB_DBGCTRL_DBGRUN_Msk & (_UINT32_(value) << MLB_DBGCTRL_DBGRUN_Pos)) /* Assigment of value for DBGRUN in the MLB_DBGCTRL register */
#define MLB_DBGCTRL_Msk                       _UINT32_(0x00000001)                                 /* (MLB_DBGCTRL) Register Mask  */


/* -------- MLB_SYNCBUSY : (MLB Offset: 0x20) ( R/ 32) SYNCBUSY Register -------- */
#define MLB_SYNCBUSY_RESETVALUE               _UINT32_(0x00)                                       /*  (MLB_SYNCBUSY) SYNCBUSY Register  Reset Value */

#define MLB_SYNCBUSY_SWRST_Pos                _UINT32_(0)                                          /* (MLB_SYNCBUSY) Software Reset Synchronization Busy Position */
#define MLB_SYNCBUSY_SWRST_Msk                (_UINT32_(0x1) << MLB_SYNCBUSY_SWRST_Pos)            /* (MLB_SYNCBUSY) Software Reset Synchronization Busy Mask */
#define MLB_SYNCBUSY_SWRST(value)             (MLB_SYNCBUSY_SWRST_Msk & (_UINT32_(value) << MLB_SYNCBUSY_SWRST_Pos)) /* Assigment of value for SWRST in the MLB_SYNCBUSY register */
#define MLB_SYNCBUSY_ENABLE_Pos               _UINT32_(1)                                          /* (MLB_SYNCBUSY) Module Enable Synchronization Busy Position */
#define MLB_SYNCBUSY_ENABLE_Msk               (_UINT32_(0x1) << MLB_SYNCBUSY_ENABLE_Pos)           /* (MLB_SYNCBUSY) Module Enable Synchronization Busy Mask */
#define MLB_SYNCBUSY_ENABLE(value)            (MLB_SYNCBUSY_ENABLE_Msk & (_UINT32_(value) << MLB_SYNCBUSY_ENABLE_Pos)) /* Assigment of value for ENABLE in the MLB_SYNCBUSY register */
#define MLB_SYNCBUSY_Msk                      _UINT32_(0x00000003)                                 /* (MLB_SYNCBUSY) Register Mask  */


/* -------- MLB_MLBC0 : (MLB Offset: 0x400) (R/W 32) MediaLB Control 0 Register -------- */
#define MLB_MLBC0_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_MLBC0) MediaLB Control 0 Register  Reset Value */

#define MLB_MLBC0_MLBEN_Pos                   _UINT32_(0)                                          /* (MLB_MLBC0) MediaLB enable Position */
#define MLB_MLBC0_MLBEN_Msk                   (_UINT32_(0x1) << MLB_MLBC0_MLBEN_Pos)               /* (MLB_MLBC0) MediaLB enable Mask */
#define MLB_MLBC0_MLBEN(value)                (MLB_MLBC0_MLBEN_Msk & (_UINT32_(value) << MLB_MLBC0_MLBEN_Pos)) /* Assigment of value for MLBEN in the MLB_MLBC0 register */
#define MLB_MLBC0_MLBCLK_Pos                  _UINT32_(2)                                          /* (MLB_MLBC0) MediaLB clock speed select Position */
#define MLB_MLBC0_MLBCLK_Msk                  (_UINT32_(0x7) << MLB_MLBC0_MLBCLK_Pos)              /* (MLB_MLBC0) MediaLB clock speed select Mask */
#define MLB_MLBC0_MLBCLK(value)               (MLB_MLBC0_MLBCLK_Msk & (_UINT32_(value) << MLB_MLBC0_MLBCLK_Pos)) /* Assigment of value for MLBCLK in the MLB_MLBC0 register */
#define   MLB_MLBC0_MLBCLK_256xFs_Val         _UINT32_(0x0)                                        /* (MLB_MLBC0) 256x Frame Speed  */
#define   MLB_MLBC0_MLBCLK_512xFs_Val         _UINT32_(0x1)                                        /* (MLB_MLBC0) 512x Frame Speed  */
#define   MLB_MLBC0_MLBCLK_1024xFs_Val        _UINT32_(0x2)                                        /* (MLB_MLBC0) 1024x Frame Speed  */
#define   MLB_MLBC0_MLBCLK_reserved_Val       _UINT32_(0x3)                                        /* (MLB_MLBC0) Only for MLBPEN==1  */
#define MLB_MLBC0_MLBCLK_256xFs               (MLB_MLBC0_MLBCLK_256xFs_Val << MLB_MLBC0_MLBCLK_Pos) /* (MLB_MLBC0) 256x Frame Speed Position  */
#define MLB_MLBC0_MLBCLK_512xFs               (MLB_MLBC0_MLBCLK_512xFs_Val << MLB_MLBC0_MLBCLK_Pos) /* (MLB_MLBC0) 512x Frame Speed Position  */
#define MLB_MLBC0_MLBCLK_1024xFs              (MLB_MLBC0_MLBCLK_1024xFs_Val << MLB_MLBC0_MLBCLK_Pos) /* (MLB_MLBC0) 1024x Frame Speed Position  */
#define MLB_MLBC0_MLBCLK_reserved             (MLB_MLBC0_MLBCLK_reserved_Val << MLB_MLBC0_MLBCLK_Pos) /* (MLB_MLBC0) Only for MLBPEN==1 Position  */
#define MLB_MLBC0_MLBPEN_Pos                  _UINT32_(5)                                          /* (MLB_MLBC0) MediaLB 6-pin enable. Position */
#define MLB_MLBC0_MLBPEN_Msk                  (_UINT32_(0x1) << MLB_MLBC0_MLBPEN_Pos)              /* (MLB_MLBC0) MediaLB 6-pin enable. Mask */
#define MLB_MLBC0_MLBPEN(value)               (MLB_MLBC0_MLBPEN_Msk & (_UINT32_(value) << MLB_MLBC0_MLBPEN_Pos)) /* Assigment of value for MLBPEN in the MLB_MLBC0 register */
#define MLB_MLBC0_MLBLK_Pos                   _UINT32_(7)                                          /* (MLB_MLBC0) MediaLB lock status (read-only) Position */
#define MLB_MLBC0_MLBLK_Msk                   (_UINT32_(0x1) << MLB_MLBC0_MLBLK_Pos)               /* (MLB_MLBC0) MediaLB lock status (read-only) Mask */
#define MLB_MLBC0_MLBLK(value)                (MLB_MLBC0_MLBLK_Msk & (_UINT32_(value) << MLB_MLBC0_MLBLK_Pos)) /* Assigment of value for MLBLK in the MLB_MLBC0 register */
#define MLB_MLBC0_ASYRETRY_Pos                _UINT32_(12)                                         /* (MLB_MLBC0) Asynchronous Tx packet retry Position */
#define MLB_MLBC0_ASYRETRY_Msk                (_UINT32_(0x1) << MLB_MLBC0_ASYRETRY_Pos)            /* (MLB_MLBC0) Asynchronous Tx packet retry Mask */
#define MLB_MLBC0_ASYRETRY(value)             (MLB_MLBC0_ASYRETRY_Msk & (_UINT32_(value) << MLB_MLBC0_ASYRETRY_Pos)) /* Assigment of value for ASYRETRY in the MLB_MLBC0 register */
#define MLB_MLBC0_CTLRETRY_Pos                _UINT32_(14)                                         /* (MLB_MLBC0) Control Tx packet retry Position */
#define MLB_MLBC0_CTLRETRY_Msk                (_UINT32_(0x1) << MLB_MLBC0_CTLRETRY_Pos)            /* (MLB_MLBC0) Control Tx packet retry Mask */
#define MLB_MLBC0_CTLRETRY(value)             (MLB_MLBC0_CTLRETRY_Msk & (_UINT32_(value) << MLB_MLBC0_CTLRETRY_Pos)) /* Assigment of value for CTLRETRY in the MLB_MLBC0 register */
#define MLB_MLBC0_FCNT_Pos                    _UINT32_(15)                                         /* (MLB_MLBC0) Number of frames per sub-buffer (synchronous channels) Position */
#define MLB_MLBC0_FCNT_Msk                    (_UINT32_(0x7) << MLB_MLBC0_FCNT_Pos)                /* (MLB_MLBC0) Number of frames per sub-buffer (synchronous channels) Mask */
#define MLB_MLBC0_FCNT(value)                 (MLB_MLBC0_FCNT_Msk & (_UINT32_(value) << MLB_MLBC0_FCNT_Pos)) /* Assigment of value for FCNT in the MLB_MLBC0 register */
#define MLB_MLBC0_Msk                         _UINT32_(0x0003D0BD)                                 /* (MLB_MLBC0) Register Mask  */


/* -------- MLB_MS0 : (MLB Offset: 0x40C) (R/W 32) MediaLB Channel Status 0 Register -------- */
#define MLB_MS0_RESETVALUE                    _UINT32_(0x00)                                       /*  (MLB_MS0) MediaLB Channel Status 0 Register  Reset Value */

#define MLB_MS0_MCS_Pos                       _UINT32_(0)                                          /* (MLB_MS0) MediaLB channel status (for channels 31 to 0) Position */
#define MLB_MS0_MCS_Msk                       (_UINT32_(0xFFFFFFFF) << MLB_MS0_MCS_Pos)            /* (MLB_MS0) MediaLB channel status (for channels 31 to 0) Mask */
#define MLB_MS0_MCS(value)                    (MLB_MS0_MCS_Msk & (_UINT32_(value) << MLB_MS0_MCS_Pos)) /* Assigment of value for MCS in the MLB_MS0 register */
#define MLB_MS0_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (MLB_MS0) Register Mask  */


/* -------- MLB_MS1 : (MLB Offset: 0x414) (R/W 32) MediaLB Channel Status 1 Register -------- */
#define MLB_MS1_RESETVALUE                    _UINT32_(0x00)                                       /*  (MLB_MS1) MediaLB Channel Status 1 Register  Reset Value */

#define MLB_MS1_MCS_Pos                       _UINT32_(0)                                          /* (MLB_MS1) MediaLB channel status (for channels 63 to 32) Position */
#define MLB_MS1_MCS_Msk                       (_UINT32_(0xFFFFFFFF) << MLB_MS1_MCS_Pos)            /* (MLB_MS1) MediaLB channel status (for channels 63 to 32) Mask */
#define MLB_MS1_MCS(value)                    (MLB_MS1_MCS_Msk & (_UINT32_(value) << MLB_MS1_MCS_Pos)) /* Assigment of value for MCS in the MLB_MS1 register */
#define MLB_MS1_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (MLB_MS1) Register Mask  */


/* -------- MLB_MSS : (MLB Offset: 0x420) (R/W 32) MediaLB System Status Register -------- */
#define MLB_MSS_RESETVALUE                    _UINT32_(0x00)                                       /*  (MLB_MSS) MediaLB System Status Register  Reset Value */

#define MLB_MSS_RSTSYSCMD_Pos                 _UINT32_(0)                                          /* (MLB_MSS) Reset system command detected Position */
#define MLB_MSS_RSTSYSCMD_Msk                 (_UINT32_(0x1) << MLB_MSS_RSTSYSCMD_Pos)             /* (MLB_MSS) Reset system command detected Mask */
#define MLB_MSS_RSTSYSCMD(value)              (MLB_MSS_RSTSYSCMD_Msk & (_UINT32_(value) << MLB_MSS_RSTSYSCMD_Pos)) /* Assigment of value for RSTSYSCMD in the MLB_MSS register */
#define MLB_MSS_LKSYSCMD_Pos                  _UINT32_(1)                                          /* (MLB_MSS) Network lock system command detected Position */
#define MLB_MSS_LKSYSCMD_Msk                  (_UINT32_(0x1) << MLB_MSS_LKSYSCMD_Pos)              /* (MLB_MSS) Network lock system command detected Mask */
#define MLB_MSS_LKSYSCMD(value)               (MLB_MSS_LKSYSCMD_Msk & (_UINT32_(value) << MLB_MSS_LKSYSCMD_Pos)) /* Assigment of value for LKSYSCMD in the MLB_MSS register */
#define MLB_MSS_ULKSYSCMD_Pos                 _UINT32_(2)                                          /* (MLB_MSS) Network unlock system command detected Position */
#define MLB_MSS_ULKSYSCMD_Msk                 (_UINT32_(0x1) << MLB_MSS_ULKSYSCMD_Pos)             /* (MLB_MSS) Network unlock system command detected Mask */
#define MLB_MSS_ULKSYSCMD(value)              (MLB_MSS_ULKSYSCMD_Msk & (_UINT32_(value) << MLB_MSS_ULKSYSCMD_Pos)) /* Assigment of value for ULKSYSCMD in the MLB_MSS register */
#define MLB_MSS_CSSYSCMD_Pos                  _UINT32_(3)                                          /* (MLB_MSS) Channel scan system command detected Position */
#define MLB_MSS_CSSYSCMD_Msk                  (_UINT32_(0x1) << MLB_MSS_CSSYSCMD_Pos)              /* (MLB_MSS) Channel scan system command detected Mask */
#define MLB_MSS_CSSYSCMD(value)               (MLB_MSS_CSSYSCMD_Msk & (_UINT32_(value) << MLB_MSS_CSSYSCMD_Pos)) /* Assigment of value for CSSYSCMD in the MLB_MSS register */
#define MLB_MSS_SWSYSCMD_Pos                  _UINT32_(4)                                          /* (MLB_MSS) Software system command detected Position */
#define MLB_MSS_SWSYSCMD_Msk                  (_UINT32_(0x1) << MLB_MSS_SWSYSCMD_Pos)              /* (MLB_MSS) Software system command detected Mask */
#define MLB_MSS_SWSYSCMD(value)               (MLB_MSS_SWSYSCMD_Msk & (_UINT32_(value) << MLB_MSS_SWSYSCMD_Pos)) /* Assigment of value for SWSYSCMD in the MLB_MSS register */
#define MLB_MSS_SERVREQ_Pos                   _UINT32_(5)                                          /* (MLB_MSS) Service request enable Position */
#define MLB_MSS_SERVREQ_Msk                   (_UINT32_(0x1) << MLB_MSS_SERVREQ_Pos)               /* (MLB_MSS) Service request enable Mask */
#define MLB_MSS_SERVREQ(value)                (MLB_MSS_SERVREQ_Msk & (_UINT32_(value) << MLB_MSS_SERVREQ_Pos)) /* Assigment of value for SERVREQ in the MLB_MSS register */
#define MLB_MSS_Msk                           _UINT32_(0x0000003F)                                 /* (MLB_MSS) Register Mask  */


/* -------- MLB_MSD : (MLB Offset: 0x424) ( R/ 32) MediaLB System Data Register (Read-only) -------- */
#define MLB_MSD_RESETVALUE                    _UINT32_(0x00)                                       /*  (MLB_MSD) MediaLB System Data Register (Read-only)  Reset Value */

#define MLB_MSD_SD0_Pos                       _UINT32_(0)                                          /* (MLB_MSD) System data (byte 0) - LSB Position */
#define MLB_MSD_SD0_Msk                       (_UINT32_(0xFF) << MLB_MSD_SD0_Pos)                  /* (MLB_MSD) System data (byte 0) - LSB Mask */
#define MLB_MSD_SD0(value)                    (MLB_MSD_SD0_Msk & (_UINT32_(value) << MLB_MSD_SD0_Pos)) /* Assigment of value for SD0 in the MLB_MSD register */
#define MLB_MSD_SD1_Pos                       _UINT32_(8)                                          /* (MLB_MSD) System data (byte 1) Position */
#define MLB_MSD_SD1_Msk                       (_UINT32_(0xFF) << MLB_MSD_SD1_Pos)                  /* (MLB_MSD) System data (byte 1) Mask */
#define MLB_MSD_SD1(value)                    (MLB_MSD_SD1_Msk & (_UINT32_(value) << MLB_MSD_SD1_Pos)) /* Assigment of value for SD1 in the MLB_MSD register */
#define MLB_MSD_SD2_Pos                       _UINT32_(16)                                         /* (MLB_MSD) System data (byte 2) Position */
#define MLB_MSD_SD2_Msk                       (_UINT32_(0xFF) << MLB_MSD_SD2_Pos)                  /* (MLB_MSD) System data (byte 2) Mask */
#define MLB_MSD_SD2(value)                    (MLB_MSD_SD2_Msk & (_UINT32_(value) << MLB_MSD_SD2_Pos)) /* Assigment of value for SD2 in the MLB_MSD register */
#define MLB_MSD_SD3_Pos                       _UINT32_(24)                                         /* (MLB_MSD) System data (byte 3) - MSB Position */
#define MLB_MSD_SD3_Msk                       (_UINT32_(0xFF) << MLB_MSD_SD3_Pos)                  /* (MLB_MSD) System data (byte 3) - MSB Mask */
#define MLB_MSD_SD3(value)                    (MLB_MSD_SD3_Msk & (_UINT32_(value) << MLB_MSD_SD3_Pos)) /* Assigment of value for SD3 in the MLB_MSD register */
#define MLB_MSD_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (MLB_MSD) Register Mask  */


/* -------- MLB_MIEN : (MLB Offset: 0x42C) (R/W 32) MediaLB Interrupt Enable Register -------- */
#define MLB_MIEN_RESETVALUE                   _UINT32_(0x00)                                       /*  (MLB_MIEN) MediaLB Interrupt Enable Register  Reset Value */

#define MLB_MIEN_ISOC_PE_Pos                  _UINT32_(0)                                          /* (MLB_MIEN) Isochronous Rx protocol error enable Position */
#define MLB_MIEN_ISOC_PE_Msk                  (_UINT32_(0x1) << MLB_MIEN_ISOC_PE_Pos)              /* (MLB_MIEN) Isochronous Rx protocol error enable Mask */
#define MLB_MIEN_ISOC_PE(value)               (MLB_MIEN_ISOC_PE_Msk & (_UINT32_(value) << MLB_MIEN_ISOC_PE_Pos)) /* Assigment of value for ISOC_PE in the MLB_MIEN register */
#define MLB_MIEN_ISOC_BUFO_Pos                _UINT32_(1)                                          /* (MLB_MIEN) Isochronous Rx buffer overflow enable Position */
#define MLB_MIEN_ISOC_BUFO_Msk                (_UINT32_(0x1) << MLB_MIEN_ISOC_BUFO_Pos)            /* (MLB_MIEN) Isochronous Rx buffer overflow enable Mask */
#define MLB_MIEN_ISOC_BUFO(value)             (MLB_MIEN_ISOC_BUFO_Msk & (_UINT32_(value) << MLB_MIEN_ISOC_BUFO_Pos)) /* Assigment of value for ISOC_BUFO in the MLB_MIEN register */
#define MLB_MIEN_SYNC_PE_Pos                  _UINT32_(16)                                         /* (MLB_MIEN) Synchronous protocol error enable Position */
#define MLB_MIEN_SYNC_PE_Msk                  (_UINT32_(0x1) << MLB_MIEN_SYNC_PE_Pos)              /* (MLB_MIEN) Synchronous protocol error enable Mask */
#define MLB_MIEN_SYNC_PE(value)               (MLB_MIEN_SYNC_PE_Msk & (_UINT32_(value) << MLB_MIEN_SYNC_PE_Pos)) /* Assigment of value for SYNC_PE in the MLB_MIEN register */
#define MLB_MIEN_ARX_DONE_Pos                 _UINT32_(17)                                         /* (MLB_MIEN) Asynchronous Rx packet done enable Position */
#define MLB_MIEN_ARX_DONE_Msk                 (_UINT32_(0x1) << MLB_MIEN_ARX_DONE_Pos)             /* (MLB_MIEN) Asynchronous Rx packet done enable Mask */
#define MLB_MIEN_ARX_DONE(value)              (MLB_MIEN_ARX_DONE_Msk & (_UINT32_(value) << MLB_MIEN_ARX_DONE_Pos)) /* Assigment of value for ARX_DONE in the MLB_MIEN register */
#define MLB_MIEN_ARX_PE_Pos                   _UINT32_(18)                                         /* (MLB_MIEN) Asynchronous Rx protocol error enable Position */
#define MLB_MIEN_ARX_PE_Msk                   (_UINT32_(0x1) << MLB_MIEN_ARX_PE_Pos)               /* (MLB_MIEN) Asynchronous Rx protocol error enable Mask */
#define MLB_MIEN_ARX_PE(value)                (MLB_MIEN_ARX_PE_Msk & (_UINT32_(value) << MLB_MIEN_ARX_PE_Pos)) /* Assigment of value for ARX_PE in the MLB_MIEN register */
#define MLB_MIEN_ARX_BREAK_Pos                _UINT32_(19)                                         /* (MLB_MIEN) Asynchronous Rx break enable Position */
#define MLB_MIEN_ARX_BREAK_Msk                (_UINT32_(0x1) << MLB_MIEN_ARX_BREAK_Pos)            /* (MLB_MIEN) Asynchronous Rx break enable Mask */
#define MLB_MIEN_ARX_BREAK(value)             (MLB_MIEN_ARX_BREAK_Msk & (_UINT32_(value) << MLB_MIEN_ARX_BREAK_Pos)) /* Assigment of value for ARX_BREAK in the MLB_MIEN register */
#define MLB_MIEN_ATX_DONE_Pos                 _UINT32_(20)                                         /* (MLB_MIEN) Asynchronous Tx packet done enable Position */
#define MLB_MIEN_ATX_DONE_Msk                 (_UINT32_(0x1) << MLB_MIEN_ATX_DONE_Pos)             /* (MLB_MIEN) Asynchronous Tx packet done enable Mask */
#define MLB_MIEN_ATX_DONE(value)              (MLB_MIEN_ATX_DONE_Msk & (_UINT32_(value) << MLB_MIEN_ATX_DONE_Pos)) /* Assigment of value for ATX_DONE in the MLB_MIEN register */
#define MLB_MIEN_ATX_PE_Pos                   _UINT32_(21)                                         /* (MLB_MIEN) Asynchronous Tx protocol error enable Position */
#define MLB_MIEN_ATX_PE_Msk                   (_UINT32_(0x1) << MLB_MIEN_ATX_PE_Pos)               /* (MLB_MIEN) Asynchronous Tx protocol error enable Mask */
#define MLB_MIEN_ATX_PE(value)                (MLB_MIEN_ATX_PE_Msk & (_UINT32_(value) << MLB_MIEN_ATX_PE_Pos)) /* Assigment of value for ATX_PE in the MLB_MIEN register */
#define MLB_MIEN_ATX_BREAK_Pos                _UINT32_(22)                                         /* (MLB_MIEN) Asynchronous Tx break enable Position */
#define MLB_MIEN_ATX_BREAK_Msk                (_UINT32_(0x1) << MLB_MIEN_ATX_BREAK_Pos)            /* (MLB_MIEN) Asynchronous Tx break enable Mask */
#define MLB_MIEN_ATX_BREAK(value)             (MLB_MIEN_ATX_BREAK_Msk & (_UINT32_(value) << MLB_MIEN_ATX_BREAK_Pos)) /* Assigment of value for ATX_BREAK in the MLB_MIEN register */
#define MLB_MIEN_CRX_DONE_Pos                 _UINT32_(24)                                         /* (MLB_MIEN) Control Rx packet done enable Position */
#define MLB_MIEN_CRX_DONE_Msk                 (_UINT32_(0x1) << MLB_MIEN_CRX_DONE_Pos)             /* (MLB_MIEN) Control Rx packet done enable Mask */
#define MLB_MIEN_CRX_DONE(value)              (MLB_MIEN_CRX_DONE_Msk & (_UINT32_(value) << MLB_MIEN_CRX_DONE_Pos)) /* Assigment of value for CRX_DONE in the MLB_MIEN register */
#define MLB_MIEN_CRX_PE_Pos                   _UINT32_(25)                                         /* (MLB_MIEN) Control Rx protocol error enable Position */
#define MLB_MIEN_CRX_PE_Msk                   (_UINT32_(0x1) << MLB_MIEN_CRX_PE_Pos)               /* (MLB_MIEN) Control Rx protocol error enable Mask */
#define MLB_MIEN_CRX_PE(value)                (MLB_MIEN_CRX_PE_Msk & (_UINT32_(value) << MLB_MIEN_CRX_PE_Pos)) /* Assigment of value for CRX_PE in the MLB_MIEN register */
#define MLB_MIEN_CRX_BREAK_Pos                _UINT32_(26)                                         /* (MLB_MIEN) Control Rx break enable Position */
#define MLB_MIEN_CRX_BREAK_Msk                (_UINT32_(0x1) << MLB_MIEN_CRX_BREAK_Pos)            /* (MLB_MIEN) Control Rx break enable Mask */
#define MLB_MIEN_CRX_BREAK(value)             (MLB_MIEN_CRX_BREAK_Msk & (_UINT32_(value) << MLB_MIEN_CRX_BREAK_Pos)) /* Assigment of value for CRX_BREAK in the MLB_MIEN register */
#define MLB_MIEN_CTX_DONE_Pos                 _UINT32_(27)                                         /* (MLB_MIEN) Control Tx packet done enable Position */
#define MLB_MIEN_CTX_DONE_Msk                 (_UINT32_(0x1) << MLB_MIEN_CTX_DONE_Pos)             /* (MLB_MIEN) Control Tx packet done enable Mask */
#define MLB_MIEN_CTX_DONE(value)              (MLB_MIEN_CTX_DONE_Msk & (_UINT32_(value) << MLB_MIEN_CTX_DONE_Pos)) /* Assigment of value for CTX_DONE in the MLB_MIEN register */
#define MLB_MIEN_CTX_PE_Pos                   _UINT32_(28)                                         /* (MLB_MIEN) Control Tx protocol error enable Position */
#define MLB_MIEN_CTX_PE_Msk                   (_UINT32_(0x1) << MLB_MIEN_CTX_PE_Pos)               /* (MLB_MIEN) Control Tx protocol error enable Mask */
#define MLB_MIEN_CTX_PE(value)                (MLB_MIEN_CTX_PE_Msk & (_UINT32_(value) << MLB_MIEN_CTX_PE_Pos)) /* Assigment of value for CTX_PE in the MLB_MIEN register */
#define MLB_MIEN_CTX_BREAK_Pos                _UINT32_(29)                                         /* (MLB_MIEN) Control Tx break enable Position */
#define MLB_MIEN_CTX_BREAK_Msk                (_UINT32_(0x1) << MLB_MIEN_CTX_BREAK_Pos)            /* (MLB_MIEN) Control Tx break enable Mask */
#define MLB_MIEN_CTX_BREAK(value)             (MLB_MIEN_CTX_BREAK_Msk & (_UINT32_(value) << MLB_MIEN_CTX_BREAK_Pos)) /* Assigment of value for CTX_BREAK in the MLB_MIEN register */
#define MLB_MIEN_Msk                          _UINT32_(0x3F7F0003)                                 /* (MLB_MIEN) Register Mask  */


/* -------- MLB_MLBC1 : (MLB Offset: 0x43C) (R/W 32) MediaLB Control 1 Register -------- */
#define MLB_MLBC1_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_MLBC1) MediaLB Control 1 Register  Reset Value */

#define MLB_MLBC1_LOCK_Pos                    _UINT32_(6)                                          /* (MLB_MLBC1) MediaLB lock error status Position */
#define MLB_MLBC1_LOCK_Msk                    (_UINT32_(0x1) << MLB_MLBC1_LOCK_Pos)                /* (MLB_MLBC1) MediaLB lock error status Mask */
#define MLB_MLBC1_LOCK(value)                 (MLB_MLBC1_LOCK_Msk & (_UINT32_(value) << MLB_MLBC1_LOCK_Pos)) /* Assigment of value for LOCK in the MLB_MLBC1 register */
#define MLB_MLBC1_CLKM_Pos                    _UINT32_(7)                                          /* (MLB_MLBC1) MediaLB clock missing status Position */
#define MLB_MLBC1_CLKM_Msk                    (_UINT32_(0x1) << MLB_MLBC1_CLKM_Pos)                /* (MLB_MLBC1) MediaLB clock missing status Mask */
#define MLB_MLBC1_CLKM(value)                 (MLB_MLBC1_CLKM_Msk & (_UINT32_(value) << MLB_MLBC1_CLKM_Pos)) /* Assigment of value for CLKM in the MLB_MLBC1 register */
#define MLB_MLBC1_NDA_Pos                     _UINT32_(8)                                          /* (MLB_MLBC1) Node device address Position */
#define MLB_MLBC1_NDA_Msk                     (_UINT32_(0xFF) << MLB_MLBC1_NDA_Pos)                /* (MLB_MLBC1) Node device address Mask */
#define MLB_MLBC1_NDA(value)                  (MLB_MLBC1_NDA_Msk & (_UINT32_(value) << MLB_MLBC1_NDA_Pos)) /* Assigment of value for NDA in the MLB_MLBC1 register */
#define MLB_MLBC1_Msk                         _UINT32_(0x0000FFC0)                                 /* (MLB_MLBC1) Register Mask  */


/* -------- MLB_HCTL : (MLB Offset: 0x480) (R/W 32) HBI Control Register -------- */
#define MLB_HCTL_RESETVALUE                   _UINT32_(0x00)                                       /*  (MLB_HCTL) HBI Control Register  Reset Value */

#define MLB_HCTL_RST0_Pos                     _UINT32_(0)                                          /* (MLB_HCTL) AGU0 software reset: 1 = reset active, 0 = reset inactive Position */
#define MLB_HCTL_RST0_Msk                     (_UINT32_(0x1) << MLB_HCTL_RST0_Pos)                 /* (MLB_HCTL) AGU0 software reset: 1 = reset active, 0 = reset inactive Mask */
#define MLB_HCTL_RST0(value)                  (MLB_HCTL_RST0_Msk & (_UINT32_(value) << MLB_HCTL_RST0_Pos)) /* Assigment of value for RST0 in the MLB_HCTL register */
#define MLB_HCTL_RST1_Pos                     _UINT32_(1)                                          /* (MLB_HCTL) AGU1 software reset: 1 = reset active, 0 = reset inactive Position */
#define MLB_HCTL_RST1_Msk                     (_UINT32_(0x1) << MLB_HCTL_RST1_Pos)                 /* (MLB_HCTL) AGU1 software reset: 1 = reset active, 0 = reset inactive Mask */
#define MLB_HCTL_RST1(value)                  (MLB_HCTL_RST1_Msk & (_UINT32_(value) << MLB_HCTL_RST1_Pos)) /* Assigment of value for RST1 in the MLB_HCTL register */
#define MLB_HCTL_EN_Pos                       _UINT32_(15)                                         /* (MLB_HCTL) HBI enable: 1 = enabled, 0 = disabled Position */
#define MLB_HCTL_EN_Msk                       (_UINT32_(0x1) << MLB_HCTL_EN_Pos)                   /* (MLB_HCTL) HBI enable: 1 = enabled, 0 = disabled Mask */
#define MLB_HCTL_EN(value)                    (MLB_HCTL_EN_Msk & (_UINT32_(value) << MLB_HCTL_EN_Pos)) /* Assigment of value for EN in the MLB_HCTL register */
#define MLB_HCTL_Msk                          _UINT32_(0x00008003)                                 /* (MLB_HCTL) Register Mask  */

#define MLB_HCTL_RST_Pos                      _UINT32_(0)                                          /* (MLB_HCTL Position) AGUx software reset: x = reset active, x = reset inactive */
#define MLB_HCTL_RST_Msk                      (_UINT32_(0x3) << MLB_HCTL_RST_Pos)                  /* (MLB_HCTL Mask) RST */
#define MLB_HCTL_RST(value)                   (MLB_HCTL_RST_Msk & (_UINT32_(value) << MLB_HCTL_RST_Pos)) 

/* -------- MLB_HCMR0 : (MLB Offset: 0x488) (R/W 32) HBI Channel Mask 0 Register -------- */
#define MLB_HCMR0_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_HCMR0) HBI Channel Mask 0 Register  Reset Value */

#define MLB_HCMR0_CHM_Pos                     _UINT32_(0)                                          /* (MLB_HCMR0) Bitwise channel mask bit: 0 = masked, 1 = unmasked Position */
#define MLB_HCMR0_CHM_Msk                     (_UINT32_(0xFFFFFFFF) << MLB_HCMR0_CHM_Pos)          /* (MLB_HCMR0) Bitwise channel mask bit: 0 = masked, 1 = unmasked Mask */
#define MLB_HCMR0_CHM(value)                  (MLB_HCMR0_CHM_Msk & (_UINT32_(value) << MLB_HCMR0_CHM_Pos)) /* Assigment of value for CHM in the MLB_HCMR0 register */
#define MLB_HCMR0_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (MLB_HCMR0) Register Mask  */


/* -------- MLB_HCMR1 : (MLB Offset: 0x48C) (R/W 32) HBI Channel Mask 1 Register -------- */
#define MLB_HCMR1_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_HCMR1) HBI Channel Mask 1 Register  Reset Value */

#define MLB_HCMR1_CHM_Pos                     _UINT32_(0)                                          /* (MLB_HCMR1) Bitwise channel mask bit: 0 = masked, 1 = unmasked Position */
#define MLB_HCMR1_CHM_Msk                     (_UINT32_(0xFFFFFFFF) << MLB_HCMR1_CHM_Pos)          /* (MLB_HCMR1) Bitwise channel mask bit: 0 = masked, 1 = unmasked Mask */
#define MLB_HCMR1_CHM(value)                  (MLB_HCMR1_CHM_Msk & (_UINT32_(value) << MLB_HCMR1_CHM_Pos)) /* Assigment of value for CHM in the MLB_HCMR1 register */
#define MLB_HCMR1_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (MLB_HCMR1) Register Mask  */


/* -------- MLB_HCER0 : (MLB Offset: 0x490) (R/W 32) HBI Channel Error 0 Register -------- */
#define MLB_HCER0_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_HCER0) HBI Channel Error 0 Register  Reset Value */

#define MLB_HCER0_CERR_Pos                    _UINT32_(0)                                          /* (MLB_HCER0) Bitwise channel error bit Position */
#define MLB_HCER0_CERR_Msk                    (_UINT32_(0xFFFFFFFF) << MLB_HCER0_CERR_Pos)         /* (MLB_HCER0) Bitwise channel error bit Mask */
#define MLB_HCER0_CERR(value)                 (MLB_HCER0_CERR_Msk & (_UINT32_(value) << MLB_HCER0_CERR_Pos)) /* Assigment of value for CERR in the MLB_HCER0 register */
#define MLB_HCER0_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (MLB_HCER0) Register Mask  */


/* -------- MLB_HCER1 : (MLB Offset: 0x494) (R/W 32) HBI Channel Error 1 Register -------- */
#define MLB_HCER1_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_HCER1) HBI Channel Error 1 Register  Reset Value */

#define MLB_HCER1_CERR_Pos                    _UINT32_(0)                                          /* (MLB_HCER1) Bitwise channel error bit Position */
#define MLB_HCER1_CERR_Msk                    (_UINT32_(0xFFFFFFFF) << MLB_HCER1_CERR_Pos)         /* (MLB_HCER1) Bitwise channel error bit Mask */
#define MLB_HCER1_CERR(value)                 (MLB_HCER1_CERR_Msk & (_UINT32_(value) << MLB_HCER1_CERR_Pos)) /* Assigment of value for CERR in the MLB_HCER1 register */
#define MLB_HCER1_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (MLB_HCER1) Register Mask  */


/* -------- MLB_HCBR0 : (MLB Offset: 0x498) ( R/ 32) HBI Channel Busy 0 Register -------- */
#define MLB_HCBR0_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_HCBR0) HBI Channel Busy 0 Register  Reset Value */

#define MLB_HCBR0_CHB_Pos                     _UINT32_(0)                                          /* (MLB_HCBR0) Bitwise channel busy bit: 0 = idle, 1 = busy Position */
#define MLB_HCBR0_CHB_Msk                     (_UINT32_(0xFFFFFFFF) << MLB_HCBR0_CHB_Pos)          /* (MLB_HCBR0) Bitwise channel busy bit: 0 = idle, 1 = busy Mask */
#define MLB_HCBR0_CHB(value)                  (MLB_HCBR0_CHB_Msk & (_UINT32_(value) << MLB_HCBR0_CHB_Pos)) /* Assigment of value for CHB in the MLB_HCBR0 register */
#define MLB_HCBR0_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (MLB_HCBR0) Register Mask  */


/* -------- MLB_HCBR1 : (MLB Offset: 0x49C) ( R/ 32) HBI Channel Busy 1 Register -------- */
#define MLB_HCBR1_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_HCBR1) HBI Channel Busy 1 Register  Reset Value */

#define MLB_HCBR1_CHB_Pos                     _UINT32_(0)                                          /* (MLB_HCBR1) Bitwise channel busy bit: 0 = idle, 1 = busy Position */
#define MLB_HCBR1_CHB_Msk                     (_UINT32_(0xFFFFFFFF) << MLB_HCBR1_CHB_Pos)          /* (MLB_HCBR1) Bitwise channel busy bit: 0 = idle, 1 = busy Mask */
#define MLB_HCBR1_CHB(value)                  (MLB_HCBR1_CHB_Msk & (_UINT32_(value) << MLB_HCBR1_CHB_Pos)) /* Assigment of value for CHB in the MLB_HCBR1 register */
#define MLB_HCBR1_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (MLB_HCBR1) Register Mask  */


/* -------- MLB_MDAT0 : (MLB Offset: 0x4C0) (R/W 32) MIF Data 0 Register -------- */
#define MLB_MDAT0_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_MDAT0) MIF Data 0 Register  Reset Value */

#define MLB_MDAT0_DATA_Pos                    _UINT32_(0)                                          /* (MLB_MDAT0) CTR data - bits[31:0] of 128-bit entry or DBR data - bits[7:0] of 8-bit entry Position */
#define MLB_MDAT0_DATA_Msk                    (_UINT32_(0xFFFFFFFF) << MLB_MDAT0_DATA_Pos)         /* (MLB_MDAT0) CTR data - bits[31:0] of 128-bit entry or DBR data - bits[7:0] of 8-bit entry Mask */
#define MLB_MDAT0_DATA(value)                 (MLB_MDAT0_DATA_Msk & (_UINT32_(value) << MLB_MDAT0_DATA_Pos)) /* Assigment of value for DATA in the MLB_MDAT0 register */
#define MLB_MDAT0_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (MLB_MDAT0) Register Mask  */


/* -------- MLB_MDAT1 : (MLB Offset: 0x4C4) (R/W 32) MIF Data 1 Register -------- */
#define MLB_MDAT1_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_MDAT1) MIF Data 1 Register  Reset Value */

#define MLB_MDAT1_DATA_Pos                    _UINT32_(0)                                          /* (MLB_MDAT1) CTR data - bits[63:32] of 128-bit entry Position */
#define MLB_MDAT1_DATA_Msk                    (_UINT32_(0xFFFFFFFF) << MLB_MDAT1_DATA_Pos)         /* (MLB_MDAT1) CTR data - bits[63:32] of 128-bit entry Mask */
#define MLB_MDAT1_DATA(value)                 (MLB_MDAT1_DATA_Msk & (_UINT32_(value) << MLB_MDAT1_DATA_Pos)) /* Assigment of value for DATA in the MLB_MDAT1 register */
#define MLB_MDAT1_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (MLB_MDAT1) Register Mask  */


/* -------- MLB_MDAT2 : (MLB Offset: 0x4C8) (R/W 32) MIF Data 2 Register -------- */
#define MLB_MDAT2_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_MDAT2) MIF Data 2 Register  Reset Value */

#define MLB_MDAT2_DATA_Pos                    _UINT32_(0)                                          /* (MLB_MDAT2) CTR data - bits[95:64] of 128-bit entry Position */
#define MLB_MDAT2_DATA_Msk                    (_UINT32_(0xFFFFFFFF) << MLB_MDAT2_DATA_Pos)         /* (MLB_MDAT2) CTR data - bits[95:64] of 128-bit entry Mask */
#define MLB_MDAT2_DATA(value)                 (MLB_MDAT2_DATA_Msk & (_UINT32_(value) << MLB_MDAT2_DATA_Pos)) /* Assigment of value for DATA in the MLB_MDAT2 register */
#define MLB_MDAT2_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (MLB_MDAT2) Register Mask  */


/* -------- MLB_MDAT3 : (MLB Offset: 0x4CC) (R/W 32) MIF Data 3 Register -------- */
#define MLB_MDAT3_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_MDAT3) MIF Data 3 Register  Reset Value */

#define MLB_MDAT3_DATA_Pos                    _UINT32_(0)                                          /* (MLB_MDAT3) CTR data - bits[127:96] of 128-bit entry Position */
#define MLB_MDAT3_DATA_Msk                    (_UINT32_(0xFFFFFFFF) << MLB_MDAT3_DATA_Pos)         /* (MLB_MDAT3) CTR data - bits[127:96] of 128-bit entry Mask */
#define MLB_MDAT3_DATA(value)                 (MLB_MDAT3_DATA_Msk & (_UINT32_(value) << MLB_MDAT3_DATA_Pos)) /* Assigment of value for DATA in the MLB_MDAT3 register */
#define MLB_MDAT3_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (MLB_MDAT3) Register Mask  */


/* -------- MLB_MDWE0 : (MLB Offset: 0x4D0) (R/W 32) MIF Data Write Enable 0 Register -------- */
#define MLB_MDWE0_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_MDWE0) MIF Data Write Enable 0 Register  Reset Value */

#define MLB_MDWE0_MASK_Pos                    _UINT32_(0)                                          /* (MLB_MDWE0) Bitwise write enable for CTR data - bits[31:0] (0 = disabled, 1 = enabled) Position */
#define MLB_MDWE0_MASK_Msk                    (_UINT32_(0xFFFFFFFF) << MLB_MDWE0_MASK_Pos)         /* (MLB_MDWE0) Bitwise write enable for CTR data - bits[31:0] (0 = disabled, 1 = enabled) Mask */
#define MLB_MDWE0_MASK(value)                 (MLB_MDWE0_MASK_Msk & (_UINT32_(value) << MLB_MDWE0_MASK_Pos)) /* Assigment of value for MASK in the MLB_MDWE0 register */
#define MLB_MDWE0_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (MLB_MDWE0) Register Mask  */


/* -------- MLB_MDWE1 : (MLB Offset: 0x4D4) (R/W 32) MIF Data Write Enable 1 Register -------- */
#define MLB_MDWE1_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_MDWE1) MIF Data Write Enable 1 Register  Reset Value */

#define MLB_MDWE1_MASK_Pos                    _UINT32_(0)                                          /* (MLB_MDWE1) Bitwise write enable for CTR data - bits[63:32] (0 = disabled, 1 = enabled) Position */
#define MLB_MDWE1_MASK_Msk                    (_UINT32_(0xFFFFFFFF) << MLB_MDWE1_MASK_Pos)         /* (MLB_MDWE1) Bitwise write enable for CTR data - bits[63:32] (0 = disabled, 1 = enabled) Mask */
#define MLB_MDWE1_MASK(value)                 (MLB_MDWE1_MASK_Msk & (_UINT32_(value) << MLB_MDWE1_MASK_Pos)) /* Assigment of value for MASK in the MLB_MDWE1 register */
#define MLB_MDWE1_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (MLB_MDWE1) Register Mask  */


/* -------- MLB_MDWE2 : (MLB Offset: 0x4D8) (R/W 32) MIF Data Write Enable 2 Register -------- */
#define MLB_MDWE2_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_MDWE2) MIF Data Write Enable 2 Register  Reset Value */

#define MLB_MDWE2_MASK_Pos                    _UINT32_(0)                                          /* (MLB_MDWE2) Bitwise write enable for CTR data - bits[95:64] (0 = disabled, 1 = enabled) Position */
#define MLB_MDWE2_MASK_Msk                    (_UINT32_(0xFFFFFFFF) << MLB_MDWE2_MASK_Pos)         /* (MLB_MDWE2) Bitwise write enable for CTR data - bits[95:64] (0 = disabled, 1 = enabled) Mask */
#define MLB_MDWE2_MASK(value)                 (MLB_MDWE2_MASK_Msk & (_UINT32_(value) << MLB_MDWE2_MASK_Pos)) /* Assigment of value for MASK in the MLB_MDWE2 register */
#define MLB_MDWE2_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (MLB_MDWE2) Register Mask  */


/* -------- MLB_MDWE3 : (MLB Offset: 0x4DC) (R/W 32) MIF Data Write Enable 3 Register -------- */
#define MLB_MDWE3_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_MDWE3) MIF Data Write Enable 3 Register  Reset Value */

#define MLB_MDWE3_MASK_Pos                    _UINT32_(0)                                          /* (MLB_MDWE3) Bitwise write enable for CTR data - bits[127:96] (0 = disabled, 1 = enabled) Position */
#define MLB_MDWE3_MASK_Msk                    (_UINT32_(0xFFFFFFFF) << MLB_MDWE3_MASK_Pos)         /* (MLB_MDWE3) Bitwise write enable for CTR data - bits[127:96] (0 = disabled, 1 = enabled) Mask */
#define MLB_MDWE3_MASK(value)                 (MLB_MDWE3_MASK_Msk & (_UINT32_(value) << MLB_MDWE3_MASK_Pos)) /* Assigment of value for MASK in the MLB_MDWE3 register */
#define MLB_MDWE3_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (MLB_MDWE3) Register Mask  */


/* -------- MLB_MCTL : (MLB Offset: 0x4E0) (R/W 32) MIF Control Register -------- */
#define MLB_MCTL_RESETVALUE                   _UINT32_(0x00)                                       /*  (MLB_MCTL) MIF Control Register  Reset Value */

#define MLB_MCTL_XCMP_Pos                     _UINT32_(0)                                          /* (MLB_MCTL) Transfer complete (write 0 to clear) Position */
#define MLB_MCTL_XCMP_Msk                     (_UINT32_(0x1) << MLB_MCTL_XCMP_Pos)                 /* (MLB_MCTL) Transfer complete (write 0 to clear) Mask */
#define MLB_MCTL_XCMP(value)                  (MLB_MCTL_XCMP_Msk & (_UINT32_(value) << MLB_MCTL_XCMP_Pos)) /* Assigment of value for XCMP in the MLB_MCTL register */
#define MLB_MCTL_Msk                          _UINT32_(0x00000001)                                 /* (MLB_MCTL) Register Mask  */


/* -------- MLB_MADR : (MLB Offset: 0x4E4) (R/W 32) MIF Address Register -------- */
#define MLB_MADR_RESETVALUE                   _UINT32_(0x00)                                       /*  (MLB_MADR) MIF Address Register  Reset Value */

#define MLB_MADR_ADDR_Pos                     _UINT32_(0)                                          /* (MLB_MADR) DBR address of 8-bit entry - bits[13:8].CTR address of 128-bit entry or DBR address of 8-bit entry - bits[7:0] Position */
#define MLB_MADR_ADDR_Msk                     (_UINT32_(0x3FFF) << MLB_MADR_ADDR_Pos)              /* (MLB_MADR) DBR address of 8-bit entry - bits[13:8].CTR address of 128-bit entry or DBR address of 8-bit entry - bits[7:0] Mask */
#define MLB_MADR_ADDR(value)                  (MLB_MADR_ADDR_Msk & (_UINT32_(value) << MLB_MADR_ADDR_Pos)) /* Assigment of value for ADDR in the MLB_MADR register */
#define MLB_MADR_TB_Pos                       _UINT32_(30)                                         /* (MLB_MADR) Target location bit (0 = selects CTR, 1 = selects DBR) Position */
#define MLB_MADR_TB_Msk                       (_UINT32_(0x1) << MLB_MADR_TB_Pos)                   /* (MLB_MADR) Target location bit (0 = selects CTR, 1 = selects DBR) Mask */
#define MLB_MADR_TB(value)                    (MLB_MADR_TB_Msk & (_UINT32_(value) << MLB_MADR_TB_Pos)) /* Assigment of value for TB in the MLB_MADR register */
#define MLB_MADR_WNR_Pos                      _UINT32_(31)                                         /* (MLB_MADR) Write-Not-Read selection (0 = read, 1 = write) Position */
#define MLB_MADR_WNR_Msk                      (_UINT32_(0x1) << MLB_MADR_WNR_Pos)                  /* (MLB_MADR) Write-Not-Read selection (0 = read, 1 = write) Mask */
#define MLB_MADR_WNR(value)                   (MLB_MADR_WNR_Msk & (_UINT32_(value) << MLB_MADR_WNR_Pos)) /* Assigment of value for WNR in the MLB_MADR register */
#define MLB_MADR_Msk                          _UINT32_(0xC0003FFF)                                 /* (MLB_MADR) Register Mask  */


/* -------- MLB_ACTL : (MLB Offset: 0x7C0) (R/W 32) AHB Control Register -------- */
#define MLB_ACTL_RESETVALUE                   _UINT32_(0x00)                                       /*  (MLB_ACTL) AHB Control Register  Reset Value */

#define MLB_ACTL_SCE_Pos                      _UINT32_(0)                                          /* (MLB_ACTL) Software clear enable: 0 = Hardware clears interrupt after a ACSRn register read 1 = Software clears interrupt Position */
#define MLB_ACTL_SCE_Msk                      (_UINT32_(0x1) << MLB_ACTL_SCE_Pos)                  /* (MLB_ACTL) Software clear enable: 0 = Hardware clears interrupt after a ACSRn register read 1 = Software clears interrupt Mask */
#define MLB_ACTL_SCE(value)                   (MLB_ACTL_SCE_Msk & (_UINT32_(value) << MLB_ACTL_SCE_Pos)) /* Assigment of value for SCE in the MLB_ACTL register */
#define MLB_ACTL_SMX_Pos                      _UINT32_(1)                                          /* (MLB_ACTL) AHB interrupt mux enable: 0 = ACSR0 generates an interrupt on ahb_int[0]; ACSR1 generates an interrupt on ahb_int[1] 1 = ACSR0 and ACSR1 generate an interrupts on ahb_int[0] only Position */
#define MLB_ACTL_SMX_Msk                      (_UINT32_(0x1) << MLB_ACTL_SMX_Pos)                  /* (MLB_ACTL) AHB interrupt mux enable: 0 = ACSR0 generates an interrupt on ahb_int[0]; ACSR1 generates an interrupt on ahb_int[1] 1 = ACSR0 and ACSR1 generate an interrupts on ahb_int[0] only Mask */
#define MLB_ACTL_SMX(value)                   (MLB_ACTL_SMX_Msk & (_UINT32_(value) << MLB_ACTL_SMX_Pos)) /* Assigment of value for SMX in the MLB_ACTL register */
#define MLB_ACTL_DMAMODE_Pos                  _UINT32_(2)                                          /* (MLB_ACTL) DMA Mode: 0 = DMA Mode 0 1 = DMA Mode 1 Position */
#define MLB_ACTL_DMAMODE_Msk                  (_UINT32_(0x1) << MLB_ACTL_DMAMODE_Pos)              /* (MLB_ACTL) DMA Mode: 0 = DMA Mode 0 1 = DMA Mode 1 Mask */
#define MLB_ACTL_DMAMODE(value)               (MLB_ACTL_DMAMODE_Msk & (_UINT32_(value) << MLB_ACTL_DMAMODE_Pos)) /* Assigment of value for DMAMODE in the MLB_ACTL register */
#define MLB_ACTL_MPB_Pos                      _UINT32_(4)                                          /* (MLB_ACTL) Packet buffering mode: 0 = single-packet mode 1 = multiple-packet mode Position */
#define MLB_ACTL_MPB_Msk                      (_UINT32_(0x1) << MLB_ACTL_MPB_Pos)                  /* (MLB_ACTL) Packet buffering mode: 0 = single-packet mode 1 = multiple-packet mode Mask */
#define MLB_ACTL_MPB(value)                   (MLB_ACTL_MPB_Msk & (_UINT32_(value) << MLB_ACTL_MPB_Pos)) /* Assigment of value for MPB in the MLB_ACTL register */
#define MLB_ACTL_Msk                          _UINT32_(0x00000017)                                 /* (MLB_ACTL) Register Mask  */


/* -------- MLB_ACSR0 : (MLB Offset: 0x7D0) (R/W 32) AHB Channel Status 0 Register -------- */
#define MLB_ACSR0_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_ACSR0) AHB Channel Status 0 Register  Reset Value */

#define MLB_ACSR0_CHS_Pos                     _UINT32_(0)                                          /* (MLB_ACSR0) Interrupt status for logical channels 31 to 0: 0 = None 1 = Interrupt Position */
#define MLB_ACSR0_CHS_Msk                     (_UINT32_(0xFFFFFFFF) << MLB_ACSR0_CHS_Pos)          /* (MLB_ACSR0) Interrupt status for logical channels 31 to 0: 0 = None 1 = Interrupt Mask */
#define MLB_ACSR0_CHS(value)                  (MLB_ACSR0_CHS_Msk & (_UINT32_(value) << MLB_ACSR0_CHS_Pos)) /* Assigment of value for CHS in the MLB_ACSR0 register */
#define MLB_ACSR0_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (MLB_ACSR0) Register Mask  */


/* -------- MLB_ACSR1 : (MLB Offset: 0x7D4) (R/W 32) AHB Channel Status 1 Register -------- */
#define MLB_ACSR1_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_ACSR1) AHB Channel Status 1 Register  Reset Value */

#define MLB_ACSR1_CHS_Pos                     _UINT32_(0)                                          /* (MLB_ACSR1) Interrupt status for logical channels 63 to 32: 0 = None 1 = Interrupt Position */
#define MLB_ACSR1_CHS_Msk                     (_UINT32_(0xFFFFFFFF) << MLB_ACSR1_CHS_Pos)          /* (MLB_ACSR1) Interrupt status for logical channels 63 to 32: 0 = None 1 = Interrupt Mask */
#define MLB_ACSR1_CHS(value)                  (MLB_ACSR1_CHS_Msk & (_UINT32_(value) << MLB_ACSR1_CHS_Pos)) /* Assigment of value for CHS in the MLB_ACSR1 register */
#define MLB_ACSR1_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (MLB_ACSR1) Register Mask  */


/* -------- MLB_ACMR0 : (MLB Offset: 0x7D8) (R/W 32) AHB Channel Mask 0 Register -------- */
#define MLB_ACMR0_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_ACMR0) AHB Channel Mask 0 Register  Reset Value */

#define MLB_ACMR0_CHM_Pos                     _UINT32_(0)                                          /* (MLB_ACMR0) Bitwise channel mask bit:0 = Masked 1 = Unmasked Position */
#define MLB_ACMR0_CHM_Msk                     (_UINT32_(0xFFFFFFFF) << MLB_ACMR0_CHM_Pos)          /* (MLB_ACMR0) Bitwise channel mask bit:0 = Masked 1 = Unmasked Mask */
#define MLB_ACMR0_CHM(value)                  (MLB_ACMR0_CHM_Msk & (_UINT32_(value) << MLB_ACMR0_CHM_Pos)) /* Assigment of value for CHM in the MLB_ACMR0 register */
#define MLB_ACMR0_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (MLB_ACMR0) Register Mask  */


/* -------- MLB_ACMR1 : (MLB Offset: 0x7DC) (R/W 32) AHB Channel Mask 1 Register -------- */
#define MLB_ACMR1_RESETVALUE                  _UINT32_(0x00)                                       /*  (MLB_ACMR1) AHB Channel Mask 1 Register  Reset Value */

#define MLB_ACMR1_CHM_Pos                     _UINT32_(0)                                          /* (MLB_ACMR1) Bitwise channel mask bit:0 = Masked 1 = Unmasked Position */
#define MLB_ACMR1_CHM_Msk                     (_UINT32_(0xFFFFFFFF) << MLB_ACMR1_CHM_Pos)          /* (MLB_ACMR1) Bitwise channel mask bit:0 = Masked 1 = Unmasked Mask */
#define MLB_ACMR1_CHM(value)                  (MLB_ACMR1_CHM_Msk & (_UINT32_(value) << MLB_ACMR1_CHM_Pos)) /* Assigment of value for CHM in the MLB_ACMR1 register */
#define MLB_ACMR1_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (MLB_ACMR1) Register Mask  */


/** \brief MLB register offsets definitions */
#define MLB_CTRLA_REG_OFST             _UINT32_(0x00)      /* (MLB_CTRLA) MLB Wrapper Control Register Offset */
#define MLB_INTENCLR_REG_OFST          _UINT32_(0x10)      /* (MLB_INTENCLR) Interrupt Enable Clear Register Offset */
#define MLB_INTENSET_REG_OFST          _UINT32_(0x14)      /* (MLB_INTENSET) Interrupt Enable Set Register Offset */
#define MLB_INTFLAG_REG_OFST           _UINT32_(0x18)      /* (MLB_INTFLAG) Interrupt Status and Clear Register Offset */
#define MLB_DBGCTRL_REG_OFST           _UINT32_(0x1C)      /* (MLB_DBGCTRL) Debug Control Register Offset */
#define MLB_SYNCBUSY_REG_OFST          _UINT32_(0x20)      /* (MLB_SYNCBUSY) SYNCBUSY Register Offset */
#define MLB_MLBC0_REG_OFST             _UINT32_(0x400)     /* (MLB_MLBC0) MediaLB Control 0 Register Offset */
#define MLB_MS0_REG_OFST               _UINT32_(0x40C)     /* (MLB_MS0) MediaLB Channel Status 0 Register Offset */
#define MLB_MS1_REG_OFST               _UINT32_(0x414)     /* (MLB_MS1) MediaLB Channel Status 1 Register Offset */
#define MLB_MSS_REG_OFST               _UINT32_(0x420)     /* (MLB_MSS) MediaLB System Status Register Offset */
#define MLB_MSD_REG_OFST               _UINT32_(0x424)     /* (MLB_MSD) MediaLB System Data Register (Read-only) Offset */
#define MLB_MIEN_REG_OFST              _UINT32_(0x42C)     /* (MLB_MIEN) MediaLB Interrupt Enable Register Offset */
#define MLB_MLBC1_REG_OFST             _UINT32_(0x43C)     /* (MLB_MLBC1) MediaLB Control 1 Register Offset */
#define MLB_HCTL_REG_OFST              _UINT32_(0x480)     /* (MLB_HCTL) HBI Control Register Offset */
#define MLB_HCMR0_REG_OFST             _UINT32_(0x488)     /* (MLB_HCMR0) HBI Channel Mask 0 Register Offset */
#define MLB_HCMR1_REG_OFST             _UINT32_(0x48C)     /* (MLB_HCMR1) HBI Channel Mask 1 Register Offset */
#define MLB_HCER0_REG_OFST             _UINT32_(0x490)     /* (MLB_HCER0) HBI Channel Error 0 Register Offset */
#define MLB_HCER1_REG_OFST             _UINT32_(0x494)     /* (MLB_HCER1) HBI Channel Error 1 Register Offset */
#define MLB_HCBR0_REG_OFST             _UINT32_(0x498)     /* (MLB_HCBR0) HBI Channel Busy 0 Register Offset */
#define MLB_HCBR1_REG_OFST             _UINT32_(0x49C)     /* (MLB_HCBR1) HBI Channel Busy 1 Register Offset */
#define MLB_MDAT0_REG_OFST             _UINT32_(0x4C0)     /* (MLB_MDAT0) MIF Data 0 Register Offset */
#define MLB_MDAT1_REG_OFST             _UINT32_(0x4C4)     /* (MLB_MDAT1) MIF Data 1 Register Offset */
#define MLB_MDAT2_REG_OFST             _UINT32_(0x4C8)     /* (MLB_MDAT2) MIF Data 2 Register Offset */
#define MLB_MDAT3_REG_OFST             _UINT32_(0x4CC)     /* (MLB_MDAT3) MIF Data 3 Register Offset */
#define MLB_MDWE0_REG_OFST             _UINT32_(0x4D0)     /* (MLB_MDWE0) MIF Data Write Enable 0 Register Offset */
#define MLB_MDWE1_REG_OFST             _UINT32_(0x4D4)     /* (MLB_MDWE1) MIF Data Write Enable 1 Register Offset */
#define MLB_MDWE2_REG_OFST             _UINT32_(0x4D8)     /* (MLB_MDWE2) MIF Data Write Enable 2 Register Offset */
#define MLB_MDWE3_REG_OFST             _UINT32_(0x4DC)     /* (MLB_MDWE3) MIF Data Write Enable 3 Register Offset */
#define MLB_MCTL_REG_OFST              _UINT32_(0x4E0)     /* (MLB_MCTL) MIF Control Register Offset */
#define MLB_MADR_REG_OFST              _UINT32_(0x4E4)     /* (MLB_MADR) MIF Address Register Offset */
#define MLB_ACTL_REG_OFST              _UINT32_(0x7C0)     /* (MLB_ACTL) AHB Control Register Offset */
#define MLB_ACSR0_REG_OFST             _UINT32_(0x7D0)     /* (MLB_ACSR0) AHB Channel Status 0 Register Offset */
#define MLB_ACSR1_REG_OFST             _UINT32_(0x7D4)     /* (MLB_ACSR1) AHB Channel Status 1 Register Offset */
#define MLB_ACMR0_REG_OFST             _UINT32_(0x7D8)     /* (MLB_ACMR0) AHB Channel Mask 0 Register Offset */
#define MLB_ACMR1_REG_OFST             _UINT32_(0x7DC)     /* (MLB_ACMR1) AHB Channel Mask 1 Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief MLB register API structure */
typedef struct
{  /* Media Local Bus */
  __IO  uint32_t                       MLB_CTRLA;          /**< Offset: 0x00 (R/W  32) MLB Wrapper Control Register */
  __I   uint8_t                        Reserved1[0x0C];
  __IO  uint32_t                       MLB_INTENCLR;       /**< Offset: 0x10 (R/W  32) Interrupt Enable Clear Register */
  __IO  uint32_t                       MLB_INTENSET;       /**< Offset: 0x14 (R/W  32) Interrupt Enable Set Register */
  __IO  uint32_t                       MLB_INTFLAG;        /**< Offset: 0x18 (R/W  32) Interrupt Status and Clear Register */
  __IO  uint32_t                       MLB_DBGCTRL;        /**< Offset: 0x1C (R/W  32) Debug Control Register */
  __I   uint32_t                       MLB_SYNCBUSY;       /**< Offset: 0x20 (R/   32) SYNCBUSY Register */
  __I   uint8_t                        Reserved2[0x3DC];
  __IO  uint32_t                       MLB_MLBC0;          /**< Offset: 0x400 (R/W  32) MediaLB Control 0 Register */
  __I   uint8_t                        Reserved3[0x08];
  __IO  uint32_t                       MLB_MS0;            /**< Offset: 0x40C (R/W  32) MediaLB Channel Status 0 Register */
  __I   uint8_t                        Reserved4[0x04];
  __IO  uint32_t                       MLB_MS1;            /**< Offset: 0x414 (R/W  32) MediaLB Channel Status 1 Register */
  __I   uint8_t                        Reserved5[0x08];
  __IO  uint32_t                       MLB_MSS;            /**< Offset: 0x420 (R/W  32) MediaLB System Status Register */
  __I   uint32_t                       MLB_MSD;            /**< Offset: 0x424 (R/   32) MediaLB System Data Register (Read-only) */
  __I   uint8_t                        Reserved6[0x04];
  __IO  uint32_t                       MLB_MIEN;           /**< Offset: 0x42C (R/W  32) MediaLB Interrupt Enable Register */
  __I   uint8_t                        Reserved7[0x0C];
  __IO  uint32_t                       MLB_MLBC1;          /**< Offset: 0x43C (R/W  32) MediaLB Control 1 Register */
  __I   uint8_t                        Reserved8[0x40];
  __IO  uint32_t                       MLB_HCTL;           /**< Offset: 0x480 (R/W  32) HBI Control Register */
  __I   uint8_t                        Reserved9[0x04];
  __IO  uint32_t                       MLB_HCMR0;          /**< Offset: 0x488 (R/W  32) HBI Channel Mask 0 Register */
  __IO  uint32_t                       MLB_HCMR1;          /**< Offset: 0x48C (R/W  32) HBI Channel Mask 1 Register */
  __IO  uint32_t                       MLB_HCER0;          /**< Offset: 0x490 (R/W  32) HBI Channel Error 0 Register */
  __IO  uint32_t                       MLB_HCER1;          /**< Offset: 0x494 (R/W  32) HBI Channel Error 1 Register */
  __I   uint32_t                       MLB_HCBR0;          /**< Offset: 0x498 (R/   32) HBI Channel Busy 0 Register */
  __I   uint32_t                       MLB_HCBR1;          /**< Offset: 0x49C (R/   32) HBI Channel Busy 1 Register */
  __I   uint8_t                        Reserved10[0x20];
  __IO  uint32_t                       MLB_MDAT0;          /**< Offset: 0x4C0 (R/W  32) MIF Data 0 Register */
  __IO  uint32_t                       MLB_MDAT1;          /**< Offset: 0x4C4 (R/W  32) MIF Data 1 Register */
  __IO  uint32_t                       MLB_MDAT2;          /**< Offset: 0x4C8 (R/W  32) MIF Data 2 Register */
  __IO  uint32_t                       MLB_MDAT3;          /**< Offset: 0x4CC (R/W  32) MIF Data 3 Register */
  __IO  uint32_t                       MLB_MDWE0;          /**< Offset: 0x4D0 (R/W  32) MIF Data Write Enable 0 Register */
  __IO  uint32_t                       MLB_MDWE1;          /**< Offset: 0x4D4 (R/W  32) MIF Data Write Enable 1 Register */
  __IO  uint32_t                       MLB_MDWE2;          /**< Offset: 0x4D8 (R/W  32) MIF Data Write Enable 2 Register */
  __IO  uint32_t                       MLB_MDWE3;          /**< Offset: 0x4DC (R/W  32) MIF Data Write Enable 3 Register */
  __IO  uint32_t                       MLB_MCTL;           /**< Offset: 0x4E0 (R/W  32) MIF Control Register */
  __IO  uint32_t                       MLB_MADR;           /**< Offset: 0x4E4 (R/W  32) MIF Address Register */
  __I   uint8_t                        Reserved11[0x2D8];
  __IO  uint32_t                       MLB_ACTL;           /**< Offset: 0x7C0 (R/W  32) AHB Control Register */
  __I   uint8_t                        Reserved12[0x0C];
  __IO  uint32_t                       MLB_ACSR0;          /**< Offset: 0x7D0 (R/W  32) AHB Channel Status 0 Register */
  __IO  uint32_t                       MLB_ACSR1;          /**< Offset: 0x7D4 (R/W  32) AHB Channel Status 1 Register */
  __IO  uint32_t                       MLB_ACMR0;          /**< Offset: 0x7D8 (R/W  32) AHB Channel Mask 0 Register */
  __IO  uint32_t                       MLB_ACMR1;          /**< Offset: 0x7DC (R/W  32) AHB Channel Mask 1 Register */
} mlb_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA90_MLB_COMPONENT_H_ */
