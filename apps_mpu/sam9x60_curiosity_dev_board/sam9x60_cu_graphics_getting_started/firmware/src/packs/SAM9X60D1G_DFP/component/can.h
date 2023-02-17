/*
 * Component description for CAN
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
#ifndef _SAM9X_CAN_COMPONENT_H_
#define _SAM9X_CAN_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR CAN                                          */
/* ************************************************************************** */

/* -------- CAN_MMR : (CAN Offset: 0x00) (R/W 32) Mailbox Mode Register -------- */
#define CAN_MMR_MTIMEMARK_Pos                 _UINT32_(0)                                          /* (CAN_MMR) Mailbox Timemark Position */
#define CAN_MMR_MTIMEMARK_Msk                 (_UINT32_(0xFFFF) << CAN_MMR_MTIMEMARK_Pos)          /* (CAN_MMR) Mailbox Timemark Mask */
#define CAN_MMR_MTIMEMARK(value)              (CAN_MMR_MTIMEMARK_Msk & (_UINT32_(value) << CAN_MMR_MTIMEMARK_Pos)) /* Assigment of value for MTIMEMARK in the CAN_MMR register */
#define CAN_MMR_PRIOR_Pos                     _UINT32_(16)                                         /* (CAN_MMR) Mailbox Priority Position */
#define CAN_MMR_PRIOR_Msk                     (_UINT32_(0xF) << CAN_MMR_PRIOR_Pos)                 /* (CAN_MMR) Mailbox Priority Mask */
#define CAN_MMR_PRIOR(value)                  (CAN_MMR_PRIOR_Msk & (_UINT32_(value) << CAN_MMR_PRIOR_Pos)) /* Assigment of value for PRIOR in the CAN_MMR register */
#define CAN_MMR_MOT_Pos                       _UINT32_(24)                                         /* (CAN_MMR) Mailbox Object Type Position */
#define CAN_MMR_MOT_Msk                       (_UINT32_(0x7) << CAN_MMR_MOT_Pos)                   /* (CAN_MMR) Mailbox Object Type Mask */
#define CAN_MMR_MOT(value)                    (CAN_MMR_MOT_Msk & (_UINT32_(value) << CAN_MMR_MOT_Pos)) /* Assigment of value for MOT in the CAN_MMR register */
#define   CAN_MMR_MOT_MB_DISABLED_Val         _UINT32_(0x0)                                        /* (CAN_MMR) Mailbox is disabled. This prevents receiving or transmitting any messages with this mailbox.  */
#define   CAN_MMR_MOT_MB_RX_Val               _UINT32_(0x1)                                        /* (CAN_MMR) Reception Mailbox. Mailbox is configured for reception. If a message is received while the mailbox data register is full, it is discarded.  */
#define   CAN_MMR_MOT_MB_RX_OVERWRITE_Val     _UINT32_(0x2)                                        /* (CAN_MMR) Reception mailbox with overwrite. Mailbox is configured for reception. If a message is received while the mailbox is full, it overwrites the previous message.  */
#define   CAN_MMR_MOT_MB_TX_Val               _UINT32_(0x3)                                        /* (CAN_MMR) Transmit mailbox. Mailbox is configured for transmission.  */
#define   CAN_MMR_MOT_MB_CONSUMER_Val         _UINT32_(0x4)                                        /* (CAN_MMR) Consumer Mailbox. Mailbox is configured in reception but behaves as a Transmit Mailbox, i.e., it sends a remote frame and waits for an answer.  */
#define   CAN_MMR_MOT_MB_PRODUCER_Val         _UINT32_(0x5)                                        /* (CAN_MMR) Producer Mailbox. Mailbox is configured in transmission but also behaves like a reception mailbox, i.e., it waits to receive a Remote Frame before sending its contents.  */
#define CAN_MMR_MOT_MB_DISABLED               (CAN_MMR_MOT_MB_DISABLED_Val << CAN_MMR_MOT_Pos)     /* (CAN_MMR) Mailbox is disabled. This prevents receiving or transmitting any messages with this mailbox. Position  */
#define CAN_MMR_MOT_MB_RX                     (CAN_MMR_MOT_MB_RX_Val << CAN_MMR_MOT_Pos)           /* (CAN_MMR) Reception Mailbox. Mailbox is configured for reception. If a message is received while the mailbox data register is full, it is discarded. Position  */
#define CAN_MMR_MOT_MB_RX_OVERWRITE           (CAN_MMR_MOT_MB_RX_OVERWRITE_Val << CAN_MMR_MOT_Pos) /* (CAN_MMR) Reception mailbox with overwrite. Mailbox is configured for reception. If a message is received while the mailbox is full, it overwrites the previous message. Position  */
#define CAN_MMR_MOT_MB_TX                     (CAN_MMR_MOT_MB_TX_Val << CAN_MMR_MOT_Pos)           /* (CAN_MMR) Transmit mailbox. Mailbox is configured for transmission. Position  */
#define CAN_MMR_MOT_MB_CONSUMER               (CAN_MMR_MOT_MB_CONSUMER_Val << CAN_MMR_MOT_Pos)     /* (CAN_MMR) Consumer Mailbox. Mailbox is configured in reception but behaves as a Transmit Mailbox, i.e., it sends a remote frame and waits for an answer. Position  */
#define CAN_MMR_MOT_MB_PRODUCER               (CAN_MMR_MOT_MB_PRODUCER_Val << CAN_MMR_MOT_Pos)     /* (CAN_MMR) Producer Mailbox. Mailbox is configured in transmission but also behaves like a reception mailbox, i.e., it waits to receive a Remote Frame before sending its contents. Position  */
#define CAN_MMR_Msk                           _UINT32_(0x070FFFFF)                                 /* (CAN_MMR) Register Mask  */


/* -------- CAN_MAM : (CAN Offset: 0x04) (R/W 32) Mailbox Acceptance Mask Register -------- */
#define CAN_MAM_MIDvB_Pos                     _UINT32_(0)                                          /* (CAN_MAM) Complementary bits for identifier in extended frame mode Position */
#define CAN_MAM_MIDvB_Msk                     (_UINT32_(0x3FFFF) << CAN_MAM_MIDvB_Pos)             /* (CAN_MAM) Complementary bits for identifier in extended frame mode Mask */
#define CAN_MAM_MIDvB(value)                  (CAN_MAM_MIDvB_Msk & (_UINT32_(value) << CAN_MAM_MIDvB_Pos)) /* Assigment of value for MIDvB in the CAN_MAM register */
#define CAN_MAM_MIDvA_Pos                     _UINT32_(18)                                         /* (CAN_MAM) Identifier for standard frame mode Position */
#define CAN_MAM_MIDvA_Msk                     (_UINT32_(0x7FF) << CAN_MAM_MIDvA_Pos)               /* (CAN_MAM) Identifier for standard frame mode Mask */
#define CAN_MAM_MIDvA(value)                  (CAN_MAM_MIDvA_Msk & (_UINT32_(value) << CAN_MAM_MIDvA_Pos)) /* Assigment of value for MIDvA in the CAN_MAM register */
#define CAN_MAM_MIDE_Pos                      _UINT32_(29)                                         /* (CAN_MAM) Identifier Version Position */
#define CAN_MAM_MIDE_Msk                      (_UINT32_(0x1) << CAN_MAM_MIDE_Pos)                  /* (CAN_MAM) Identifier Version Mask */
#define CAN_MAM_MIDE(value)                   (CAN_MAM_MIDE_Msk & (_UINT32_(value) << CAN_MAM_MIDE_Pos)) /* Assigment of value for MIDE in the CAN_MAM register */
#define CAN_MAM_Msk                           _UINT32_(0x3FFFFFFF)                                 /* (CAN_MAM) Register Mask  */


/* -------- CAN_MID : (CAN Offset: 0x08) (R/W 32) Mailbox ID Register -------- */
#define CAN_MID_MIDvB_Pos                     _UINT32_(0)                                          /* (CAN_MID) Complementary bits for identifier in extended frame mode Position */
#define CAN_MID_MIDvB_Msk                     (_UINT32_(0x3FFFF) << CAN_MID_MIDvB_Pos)             /* (CAN_MID) Complementary bits for identifier in extended frame mode Mask */
#define CAN_MID_MIDvB(value)                  (CAN_MID_MIDvB_Msk & (_UINT32_(value) << CAN_MID_MIDvB_Pos)) /* Assigment of value for MIDvB in the CAN_MID register */
#define CAN_MID_MIDvA_Pos                     _UINT32_(18)                                         /* (CAN_MID) Identifier for standard frame mode Position */
#define CAN_MID_MIDvA_Msk                     (_UINT32_(0x7FF) << CAN_MID_MIDvA_Pos)               /* (CAN_MID) Identifier for standard frame mode Mask */
#define CAN_MID_MIDvA(value)                  (CAN_MID_MIDvA_Msk & (_UINT32_(value) << CAN_MID_MIDvA_Pos)) /* Assigment of value for MIDvA in the CAN_MID register */
#define CAN_MID_MIDE_Pos                      _UINT32_(29)                                         /* (CAN_MID) Identifier Version Position */
#define CAN_MID_MIDE_Msk                      (_UINT32_(0x1) << CAN_MID_MIDE_Pos)                  /* (CAN_MID) Identifier Version Mask */
#define CAN_MID_MIDE(value)                   (CAN_MID_MIDE_Msk & (_UINT32_(value) << CAN_MID_MIDE_Pos)) /* Assigment of value for MIDE in the CAN_MID register */
#define CAN_MID_Msk                           _UINT32_(0x3FFFFFFF)                                 /* (CAN_MID) Register Mask  */


/* -------- CAN_MFID : (CAN Offset: 0x0C) ( R/ 32) Mailbox Family ID Register -------- */
#define CAN_MFID_MFID_Pos                     _UINT32_(0)                                          /* (CAN_MFID) Family ID Position */
#define CAN_MFID_MFID_Msk                     (_UINT32_(0x1FFFFFFF) << CAN_MFID_MFID_Pos)          /* (CAN_MFID) Family ID Mask */
#define CAN_MFID_MFID(value)                  (CAN_MFID_MFID_Msk & (_UINT32_(value) << CAN_MFID_MFID_Pos)) /* Assigment of value for MFID in the CAN_MFID register */
#define CAN_MFID_Msk                          _UINT32_(0x1FFFFFFF)                                 /* (CAN_MFID) Register Mask  */


/* -------- CAN_MSR : (CAN Offset: 0x10) ( R/ 32) Mailbox Status Register -------- */
#define CAN_MSR_MTIMESTAMP_Pos                _UINT32_(0)                                          /* (CAN_MSR) Timer Value Position */
#define CAN_MSR_MTIMESTAMP_Msk                (_UINT32_(0xFFFF) << CAN_MSR_MTIMESTAMP_Pos)         /* (CAN_MSR) Timer Value Mask */
#define CAN_MSR_MTIMESTAMP(value)             (CAN_MSR_MTIMESTAMP_Msk & (_UINT32_(value) << CAN_MSR_MTIMESTAMP_Pos)) /* Assigment of value for MTIMESTAMP in the CAN_MSR register */
#define CAN_MSR_MDLC_Pos                      _UINT32_(16)                                         /* (CAN_MSR) Mailbox Data Length Code Position */
#define CAN_MSR_MDLC_Msk                      (_UINT32_(0xF) << CAN_MSR_MDLC_Pos)                  /* (CAN_MSR) Mailbox Data Length Code Mask */
#define CAN_MSR_MDLC(value)                   (CAN_MSR_MDLC_Msk & (_UINT32_(value) << CAN_MSR_MDLC_Pos)) /* Assigment of value for MDLC in the CAN_MSR register */
#define CAN_MSR_MRTR_Pos                      _UINT32_(20)                                         /* (CAN_MSR) Mailbox Remote Transmission Request Position */
#define CAN_MSR_MRTR_Msk                      (_UINT32_(0x1) << CAN_MSR_MRTR_Pos)                  /* (CAN_MSR) Mailbox Remote Transmission Request Mask */
#define CAN_MSR_MRTR(value)                   (CAN_MSR_MRTR_Msk & (_UINT32_(value) << CAN_MSR_MRTR_Pos)) /* Assigment of value for MRTR in the CAN_MSR register */
#define CAN_MSR_MABT_Pos                      _UINT32_(22)                                         /* (CAN_MSR) Mailbox Message Abort (cleared by writing MTCR or MACR in the CAN_MCRx) Position */
#define CAN_MSR_MABT_Msk                      (_UINT32_(0x1) << CAN_MSR_MABT_Pos)                  /* (CAN_MSR) Mailbox Message Abort (cleared by writing MTCR or MACR in the CAN_MCRx) Mask */
#define CAN_MSR_MABT(value)                   (CAN_MSR_MABT_Msk & (_UINT32_(value) << CAN_MSR_MABT_Pos)) /* Assigment of value for MABT in the CAN_MSR register */
#define CAN_MSR_MRDY_Pos                      _UINT32_(23)                                         /* (CAN_MSR) Mailbox Ready (cleared by writing MTCR or MACR in the CAN_MCRx) Position */
#define CAN_MSR_MRDY_Msk                      (_UINT32_(0x1) << CAN_MSR_MRDY_Pos)                  /* (CAN_MSR) Mailbox Ready (cleared by writing MTCR or MACR in the CAN_MCRx) Mask */
#define CAN_MSR_MRDY(value)                   (CAN_MSR_MRDY_Msk & (_UINT32_(value) << CAN_MSR_MRDY_Pos)) /* Assigment of value for MRDY in the CAN_MSR register */
#define CAN_MSR_MMI_Pos                       _UINT32_(24)                                         /* (CAN_MSR) Mailbox Message Ignored (cleared by reading CAN_MSRx) Position */
#define CAN_MSR_MMI_Msk                       (_UINT32_(0x1) << CAN_MSR_MMI_Pos)                   /* (CAN_MSR) Mailbox Message Ignored (cleared by reading CAN_MSRx) Mask */
#define CAN_MSR_MMI(value)                    (CAN_MSR_MMI_Msk & (_UINT32_(value) << CAN_MSR_MMI_Pos)) /* Assigment of value for MMI in the CAN_MSR register */
#define CAN_MSR_Msk                           _UINT32_(0x01DFFFFF)                                 /* (CAN_MSR) Register Mask  */


/* -------- CAN_MDL : (CAN Offset: 0x14) (R/W 32) Mailbox Data Low Register -------- */
#define CAN_MDL_MDL_Pos                       _UINT32_(0)                                          /* (CAN_MDL) Message Data Low Value Position */
#define CAN_MDL_MDL_Msk                       (_UINT32_(0xFFFFFFFF) << CAN_MDL_MDL_Pos)            /* (CAN_MDL) Message Data Low Value Mask */
#define CAN_MDL_MDL(value)                    (CAN_MDL_MDL_Msk & (_UINT32_(value) << CAN_MDL_MDL_Pos)) /* Assigment of value for MDL in the CAN_MDL register */
#define CAN_MDL_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (CAN_MDL) Register Mask  */


/* -------- CAN_MDH : (CAN Offset: 0x18) (R/W 32) Mailbox Data High Register -------- */
#define CAN_MDH_MDH_Pos                       _UINT32_(0)                                          /* (CAN_MDH) Message Data High Value Position */
#define CAN_MDH_MDH_Msk                       (_UINT32_(0xFFFFFFFF) << CAN_MDH_MDH_Pos)            /* (CAN_MDH) Message Data High Value Mask */
#define CAN_MDH_MDH(value)                    (CAN_MDH_MDH_Msk & (_UINT32_(value) << CAN_MDH_MDH_Pos)) /* Assigment of value for MDH in the CAN_MDH register */
#define CAN_MDH_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (CAN_MDH) Register Mask  */


/* -------- CAN_MCR : (CAN Offset: 0x1C) ( /W 32) Mailbox Control Register -------- */
#define CAN_MCR_MDLC_Pos                      _UINT32_(16)                                         /* (CAN_MCR) Mailbox Data Length Code Position */
#define CAN_MCR_MDLC_Msk                      (_UINT32_(0xF) << CAN_MCR_MDLC_Pos)                  /* (CAN_MCR) Mailbox Data Length Code Mask */
#define CAN_MCR_MDLC(value)                   (CAN_MCR_MDLC_Msk & (_UINT32_(value) << CAN_MCR_MDLC_Pos)) /* Assigment of value for MDLC in the CAN_MCR register */
#define CAN_MCR_MRTR_Pos                      _UINT32_(20)                                         /* (CAN_MCR) Mailbox Remote Transmission Request Position */
#define CAN_MCR_MRTR_Msk                      (_UINT32_(0x1) << CAN_MCR_MRTR_Pos)                  /* (CAN_MCR) Mailbox Remote Transmission Request Mask */
#define CAN_MCR_MRTR(value)                   (CAN_MCR_MRTR_Msk & (_UINT32_(value) << CAN_MCR_MRTR_Pos)) /* Assigment of value for MRTR in the CAN_MCR register */
#define CAN_MCR_MACR_Pos                      _UINT32_(22)                                         /* (CAN_MCR) Abort Request for Mailbox 0 Position */
#define CAN_MCR_MACR_Msk                      (_UINT32_(0x1) << CAN_MCR_MACR_Pos)                  /* (CAN_MCR) Abort Request for Mailbox 0 Mask */
#define CAN_MCR_MACR(value)                   (CAN_MCR_MACR_Msk & (_UINT32_(value) << CAN_MCR_MACR_Pos)) /* Assigment of value for MACR in the CAN_MCR register */
#define CAN_MCR_MTCR_Pos                      _UINT32_(23)                                         /* (CAN_MCR) Mailbox Transfer Command Position */
#define CAN_MCR_MTCR_Msk                      (_UINT32_(0x1) << CAN_MCR_MTCR_Pos)                  /* (CAN_MCR) Mailbox Transfer Command Mask */
#define CAN_MCR_MTCR(value)                   (CAN_MCR_MTCR_Msk & (_UINT32_(value) << CAN_MCR_MTCR_Pos)) /* Assigment of value for MTCR in the CAN_MCR register */
#define CAN_MCR_Msk                           _UINT32_(0x00DF0000)                                 /* (CAN_MCR) Register Mask  */


/* -------- CAN_MR : (CAN Offset: 0x00) (R/W 32) Mode Register -------- */
#define CAN_MR_CANEN_Pos                      _UINT32_(0)                                          /* (CAN_MR) CAN Controller Enable Position */
#define CAN_MR_CANEN_Msk                      (_UINT32_(0x1) << CAN_MR_CANEN_Pos)                  /* (CAN_MR) CAN Controller Enable Mask */
#define CAN_MR_CANEN(value)                   (CAN_MR_CANEN_Msk & (_UINT32_(value) << CAN_MR_CANEN_Pos)) /* Assigment of value for CANEN in the CAN_MR register */
#define CAN_MR_LPM_Pos                        _UINT32_(1)                                          /* (CAN_MR) Disable/Enable Low-power Mode Position */
#define CAN_MR_LPM_Msk                        (_UINT32_(0x1) << CAN_MR_LPM_Pos)                    /* (CAN_MR) Disable/Enable Low-power Mode Mask */
#define CAN_MR_LPM(value)                     (CAN_MR_LPM_Msk & (_UINT32_(value) << CAN_MR_LPM_Pos)) /* Assigment of value for LPM in the CAN_MR register */
#define CAN_MR_ABM_Pos                        _UINT32_(2)                                          /* (CAN_MR) Disable/Enable Autobaud/Listen mode Position */
#define CAN_MR_ABM_Msk                        (_UINT32_(0x1) << CAN_MR_ABM_Pos)                    /* (CAN_MR) Disable/Enable Autobaud/Listen mode Mask */
#define CAN_MR_ABM(value)                     (CAN_MR_ABM_Msk & (_UINT32_(value) << CAN_MR_ABM_Pos)) /* Assigment of value for ABM in the CAN_MR register */
#define CAN_MR_OVL_Pos                        _UINT32_(3)                                          /* (CAN_MR) Disable/Enable Overload Frame Position */
#define CAN_MR_OVL_Msk                        (_UINT32_(0x1) << CAN_MR_OVL_Pos)                    /* (CAN_MR) Disable/Enable Overload Frame Mask */
#define CAN_MR_OVL(value)                     (CAN_MR_OVL_Msk & (_UINT32_(value) << CAN_MR_OVL_Pos)) /* Assigment of value for OVL in the CAN_MR register */
#define CAN_MR_TEOF_Pos                       _UINT32_(4)                                          /* (CAN_MR) Timestamp messages at each end of Frame Position */
#define CAN_MR_TEOF_Msk                       (_UINT32_(0x1) << CAN_MR_TEOF_Pos)                   /* (CAN_MR) Timestamp messages at each end of Frame Mask */
#define CAN_MR_TEOF(value)                    (CAN_MR_TEOF_Msk & (_UINT32_(value) << CAN_MR_TEOF_Pos)) /* Assigment of value for TEOF in the CAN_MR register */
#define CAN_MR_TTM_Pos                        _UINT32_(5)                                          /* (CAN_MR) Disable/Enable Time-Triggered Mode Position */
#define CAN_MR_TTM_Msk                        (_UINT32_(0x1) << CAN_MR_TTM_Pos)                    /* (CAN_MR) Disable/Enable Time-Triggered Mode Mask */
#define CAN_MR_TTM(value)                     (CAN_MR_TTM_Msk & (_UINT32_(value) << CAN_MR_TTM_Pos)) /* Assigment of value for TTM in the CAN_MR register */
#define CAN_MR_TIMFRZ_Pos                     _UINT32_(6)                                          /* (CAN_MR) Enable Timer Freeze Position */
#define CAN_MR_TIMFRZ_Msk                     (_UINT32_(0x1) << CAN_MR_TIMFRZ_Pos)                 /* (CAN_MR) Enable Timer Freeze Mask */
#define CAN_MR_TIMFRZ(value)                  (CAN_MR_TIMFRZ_Msk & (_UINT32_(value) << CAN_MR_TIMFRZ_Pos)) /* Assigment of value for TIMFRZ in the CAN_MR register */
#define CAN_MR_DRPT_Pos                       _UINT32_(7)                                          /* (CAN_MR) Disable Repeat Position */
#define CAN_MR_DRPT_Msk                       (_UINT32_(0x1) << CAN_MR_DRPT_Pos)                   /* (CAN_MR) Disable Repeat Mask */
#define CAN_MR_DRPT(value)                    (CAN_MR_DRPT_Msk & (_UINT32_(value) << CAN_MR_DRPT_Pos)) /* Assigment of value for DRPT in the CAN_MR register */
#define CAN_MR_RXSYNC_Pos                     _UINT32_(24)                                         /* (CAN_MR) Reception Synchronization Stage (not readable) Position */
#define CAN_MR_RXSYNC_Msk                     (_UINT32_(0x7) << CAN_MR_RXSYNC_Pos)                 /* (CAN_MR) Reception Synchronization Stage (not readable) Mask */
#define CAN_MR_RXSYNC(value)                  (CAN_MR_RXSYNC_Msk & (_UINT32_(value) << CAN_MR_RXSYNC_Pos)) /* Assigment of value for RXSYNC in the CAN_MR register */
#define   CAN_MR_RXSYNC_DOUBLE_PP_Val         _UINT32_(0x0)                                        /* (CAN_MR) Rx Signal with Double Synchro Stages (2 Positive Edges)  */
#define   CAN_MR_RXSYNC_DOUBLE_PN_Val         _UINT32_(0x1)                                        /* (CAN_MR) Rx Signal with Double Synchro Stages (One Positive Edge and One Negative Edge)  */
#define   CAN_MR_RXSYNC_SINGLE_P_Val          _UINT32_(0x2)                                        /* (CAN_MR) Rx Signal with Single Synchro Stage (Positive Edge)  */
#define   CAN_MR_RXSYNC_NONE_Val              _UINT32_(0x3)                                        /* (CAN_MR) Rx Signal with No Synchro Stage  */
#define CAN_MR_RXSYNC_DOUBLE_PP               (CAN_MR_RXSYNC_DOUBLE_PP_Val << CAN_MR_RXSYNC_Pos)   /* (CAN_MR) Rx Signal with Double Synchro Stages (2 Positive Edges) Position  */
#define CAN_MR_RXSYNC_DOUBLE_PN               (CAN_MR_RXSYNC_DOUBLE_PN_Val << CAN_MR_RXSYNC_Pos)   /* (CAN_MR) Rx Signal with Double Synchro Stages (One Positive Edge and One Negative Edge) Position  */
#define CAN_MR_RXSYNC_SINGLE_P                (CAN_MR_RXSYNC_SINGLE_P_Val << CAN_MR_RXSYNC_Pos)    /* (CAN_MR) Rx Signal with Single Synchro Stage (Positive Edge) Position  */
#define CAN_MR_RXSYNC_NONE                    (CAN_MR_RXSYNC_NONE_Val << CAN_MR_RXSYNC_Pos)        /* (CAN_MR) Rx Signal with No Synchro Stage Position  */
#define CAN_MR_Msk                            _UINT32_(0x070000FF)                                 /* (CAN_MR) Register Mask  */


/* -------- CAN_IER : (CAN Offset: 0x04) ( /W 32) Interrupt Enable Register -------- */
#define CAN_IER_MB0_Pos                       _UINT32_(0)                                          /* (CAN_IER) Mailbox 0 Interrupt Enable Position */
#define CAN_IER_MB0_Msk                       (_UINT32_(0x1) << CAN_IER_MB0_Pos)                   /* (CAN_IER) Mailbox 0 Interrupt Enable Mask */
#define CAN_IER_MB0(value)                    (CAN_IER_MB0_Msk & (_UINT32_(value) << CAN_IER_MB0_Pos)) /* Assigment of value for MB0 in the CAN_IER register */
#define CAN_IER_MB1_Pos                       _UINT32_(1)                                          /* (CAN_IER) Mailbox 1 Interrupt Enable Position */
#define CAN_IER_MB1_Msk                       (_UINT32_(0x1) << CAN_IER_MB1_Pos)                   /* (CAN_IER) Mailbox 1 Interrupt Enable Mask */
#define CAN_IER_MB1(value)                    (CAN_IER_MB1_Msk & (_UINT32_(value) << CAN_IER_MB1_Pos)) /* Assigment of value for MB1 in the CAN_IER register */
#define CAN_IER_MB2_Pos                       _UINT32_(2)                                          /* (CAN_IER) Mailbox 2 Interrupt Enable Position */
#define CAN_IER_MB2_Msk                       (_UINT32_(0x1) << CAN_IER_MB2_Pos)                   /* (CAN_IER) Mailbox 2 Interrupt Enable Mask */
#define CAN_IER_MB2(value)                    (CAN_IER_MB2_Msk & (_UINT32_(value) << CAN_IER_MB2_Pos)) /* Assigment of value for MB2 in the CAN_IER register */
#define CAN_IER_MB3_Pos                       _UINT32_(3)                                          /* (CAN_IER) Mailbox 3 Interrupt Enable Position */
#define CAN_IER_MB3_Msk                       (_UINT32_(0x1) << CAN_IER_MB3_Pos)                   /* (CAN_IER) Mailbox 3 Interrupt Enable Mask */
#define CAN_IER_MB3(value)                    (CAN_IER_MB3_Msk & (_UINT32_(value) << CAN_IER_MB3_Pos)) /* Assigment of value for MB3 in the CAN_IER register */
#define CAN_IER_MB4_Pos                       _UINT32_(4)                                          /* (CAN_IER) Mailbox 4 Interrupt Enable Position */
#define CAN_IER_MB4_Msk                       (_UINT32_(0x1) << CAN_IER_MB4_Pos)                   /* (CAN_IER) Mailbox 4 Interrupt Enable Mask */
#define CAN_IER_MB4(value)                    (CAN_IER_MB4_Msk & (_UINT32_(value) << CAN_IER_MB4_Pos)) /* Assigment of value for MB4 in the CAN_IER register */
#define CAN_IER_MB5_Pos                       _UINT32_(5)                                          /* (CAN_IER) Mailbox 5 Interrupt Enable Position */
#define CAN_IER_MB5_Msk                       (_UINT32_(0x1) << CAN_IER_MB5_Pos)                   /* (CAN_IER) Mailbox 5 Interrupt Enable Mask */
#define CAN_IER_MB5(value)                    (CAN_IER_MB5_Msk & (_UINT32_(value) << CAN_IER_MB5_Pos)) /* Assigment of value for MB5 in the CAN_IER register */
#define CAN_IER_MB6_Pos                       _UINT32_(6)                                          /* (CAN_IER) Mailbox 6 Interrupt Enable Position */
#define CAN_IER_MB6_Msk                       (_UINT32_(0x1) << CAN_IER_MB6_Pos)                   /* (CAN_IER) Mailbox 6 Interrupt Enable Mask */
#define CAN_IER_MB6(value)                    (CAN_IER_MB6_Msk & (_UINT32_(value) << CAN_IER_MB6_Pos)) /* Assigment of value for MB6 in the CAN_IER register */
#define CAN_IER_MB7_Pos                       _UINT32_(7)                                          /* (CAN_IER) Mailbox 7 Interrupt Enable Position */
#define CAN_IER_MB7_Msk                       (_UINT32_(0x1) << CAN_IER_MB7_Pos)                   /* (CAN_IER) Mailbox 7 Interrupt Enable Mask */
#define CAN_IER_MB7(value)                    (CAN_IER_MB7_Msk & (_UINT32_(value) << CAN_IER_MB7_Pos)) /* Assigment of value for MB7 in the CAN_IER register */
#define CAN_IER_ERRA_Pos                      _UINT32_(16)                                         /* (CAN_IER) Error Active Mode Interrupt Enable Position */
#define CAN_IER_ERRA_Msk                      (_UINT32_(0x1) << CAN_IER_ERRA_Pos)                  /* (CAN_IER) Error Active Mode Interrupt Enable Mask */
#define CAN_IER_ERRA(value)                   (CAN_IER_ERRA_Msk & (_UINT32_(value) << CAN_IER_ERRA_Pos)) /* Assigment of value for ERRA in the CAN_IER register */
#define CAN_IER_WARN_Pos                      _UINT32_(17)                                         /* (CAN_IER) Warning Limit Interrupt Enable Position */
#define CAN_IER_WARN_Msk                      (_UINT32_(0x1) << CAN_IER_WARN_Pos)                  /* (CAN_IER) Warning Limit Interrupt Enable Mask */
#define CAN_IER_WARN(value)                   (CAN_IER_WARN_Msk & (_UINT32_(value) << CAN_IER_WARN_Pos)) /* Assigment of value for WARN in the CAN_IER register */
#define CAN_IER_ERRP_Pos                      _UINT32_(18)                                         /* (CAN_IER) Error Passive Mode Interrupt Enable Position */
#define CAN_IER_ERRP_Msk                      (_UINT32_(0x1) << CAN_IER_ERRP_Pos)                  /* (CAN_IER) Error Passive Mode Interrupt Enable Mask */
#define CAN_IER_ERRP(value)                   (CAN_IER_ERRP_Msk & (_UINT32_(value) << CAN_IER_ERRP_Pos)) /* Assigment of value for ERRP in the CAN_IER register */
#define CAN_IER_BOFF_Pos                      _UINT32_(19)                                         /* (CAN_IER) Bus Off Mode Interrupt Enable Position */
#define CAN_IER_BOFF_Msk                      (_UINT32_(0x1) << CAN_IER_BOFF_Pos)                  /* (CAN_IER) Bus Off Mode Interrupt Enable Mask */
#define CAN_IER_BOFF(value)                   (CAN_IER_BOFF_Msk & (_UINT32_(value) << CAN_IER_BOFF_Pos)) /* Assigment of value for BOFF in the CAN_IER register */
#define CAN_IER_SLEEP_Pos                     _UINT32_(20)                                         /* (CAN_IER) Sleep Interrupt Enable Position */
#define CAN_IER_SLEEP_Msk                     (_UINT32_(0x1) << CAN_IER_SLEEP_Pos)                 /* (CAN_IER) Sleep Interrupt Enable Mask */
#define CAN_IER_SLEEP(value)                  (CAN_IER_SLEEP_Msk & (_UINT32_(value) << CAN_IER_SLEEP_Pos)) /* Assigment of value for SLEEP in the CAN_IER register */
#define CAN_IER_WAKEUP_Pos                    _UINT32_(21)                                         /* (CAN_IER) Wakeup Interrupt Enable Position */
#define CAN_IER_WAKEUP_Msk                    (_UINT32_(0x1) << CAN_IER_WAKEUP_Pos)                /* (CAN_IER) Wakeup Interrupt Enable Mask */
#define CAN_IER_WAKEUP(value)                 (CAN_IER_WAKEUP_Msk & (_UINT32_(value) << CAN_IER_WAKEUP_Pos)) /* Assigment of value for WAKEUP in the CAN_IER register */
#define CAN_IER_TOVF_Pos                      _UINT32_(22)                                         /* (CAN_IER) Timer Overflow Interrupt Enable Position */
#define CAN_IER_TOVF_Msk                      (_UINT32_(0x1) << CAN_IER_TOVF_Pos)                  /* (CAN_IER) Timer Overflow Interrupt Enable Mask */
#define CAN_IER_TOVF(value)                   (CAN_IER_TOVF_Msk & (_UINT32_(value) << CAN_IER_TOVF_Pos)) /* Assigment of value for TOVF in the CAN_IER register */
#define CAN_IER_TSTP_Pos                      _UINT32_(23)                                         /* (CAN_IER) TimeStamp Interrupt Enable Position */
#define CAN_IER_TSTP_Msk                      (_UINT32_(0x1) << CAN_IER_TSTP_Pos)                  /* (CAN_IER) TimeStamp Interrupt Enable Mask */
#define CAN_IER_TSTP(value)                   (CAN_IER_TSTP_Msk & (_UINT32_(value) << CAN_IER_TSTP_Pos)) /* Assigment of value for TSTP in the CAN_IER register */
#define CAN_IER_CERR_Pos                      _UINT32_(24)                                         /* (CAN_IER) CRC Error Interrupt Enable Position */
#define CAN_IER_CERR_Msk                      (_UINT32_(0x1) << CAN_IER_CERR_Pos)                  /* (CAN_IER) CRC Error Interrupt Enable Mask */
#define CAN_IER_CERR(value)                   (CAN_IER_CERR_Msk & (_UINT32_(value) << CAN_IER_CERR_Pos)) /* Assigment of value for CERR in the CAN_IER register */
#define CAN_IER_SERR_Pos                      _UINT32_(25)                                         /* (CAN_IER) Stuffing Error Interrupt Enable Position */
#define CAN_IER_SERR_Msk                      (_UINT32_(0x1) << CAN_IER_SERR_Pos)                  /* (CAN_IER) Stuffing Error Interrupt Enable Mask */
#define CAN_IER_SERR(value)                   (CAN_IER_SERR_Msk & (_UINT32_(value) << CAN_IER_SERR_Pos)) /* Assigment of value for SERR in the CAN_IER register */
#define CAN_IER_AERR_Pos                      _UINT32_(26)                                         /* (CAN_IER) Acknowledgment Error Interrupt Enable Position */
#define CAN_IER_AERR_Msk                      (_UINT32_(0x1) << CAN_IER_AERR_Pos)                  /* (CAN_IER) Acknowledgment Error Interrupt Enable Mask */
#define CAN_IER_AERR(value)                   (CAN_IER_AERR_Msk & (_UINT32_(value) << CAN_IER_AERR_Pos)) /* Assigment of value for AERR in the CAN_IER register */
#define CAN_IER_FERR_Pos                      _UINT32_(27)                                         /* (CAN_IER) Form Error Interrupt Enable Position */
#define CAN_IER_FERR_Msk                      (_UINT32_(0x1) << CAN_IER_FERR_Pos)                  /* (CAN_IER) Form Error Interrupt Enable Mask */
#define CAN_IER_FERR(value)                   (CAN_IER_FERR_Msk & (_UINT32_(value) << CAN_IER_FERR_Pos)) /* Assigment of value for FERR in the CAN_IER register */
#define CAN_IER_BERR_Pos                      _UINT32_(28)                                         /* (CAN_IER) Bit Error Interrupt Enable Position */
#define CAN_IER_BERR_Msk                      (_UINT32_(0x1) << CAN_IER_BERR_Pos)                  /* (CAN_IER) Bit Error Interrupt Enable Mask */
#define CAN_IER_BERR(value)                   (CAN_IER_BERR_Msk & (_UINT32_(value) << CAN_IER_BERR_Pos)) /* Assigment of value for BERR in the CAN_IER register */
#define CAN_IER_Msk                           _UINT32_(0x1FFF00FF)                                 /* (CAN_IER) Register Mask  */

#define CAN_IER_MB_Pos                        _UINT32_(0)                                          /* (CAN_IER Position) Mailbox x Interrupt Enable */
#define CAN_IER_MB_Msk                        (_UINT32_(0xFF) << CAN_IER_MB_Pos)                   /* (CAN_IER Mask) MB */
#define CAN_IER_MB(value)                     (CAN_IER_MB_Msk & (_UINT32_(value) << CAN_IER_MB_Pos)) 

/* -------- CAN_IDR : (CAN Offset: 0x08) ( /W 32) Interrupt Disable Register -------- */
#define CAN_IDR_MB0_Pos                       _UINT32_(0)                                          /* (CAN_IDR) Mailbox 0 Interrupt Disable Position */
#define CAN_IDR_MB0_Msk                       (_UINT32_(0x1) << CAN_IDR_MB0_Pos)                   /* (CAN_IDR) Mailbox 0 Interrupt Disable Mask */
#define CAN_IDR_MB0(value)                    (CAN_IDR_MB0_Msk & (_UINT32_(value) << CAN_IDR_MB0_Pos)) /* Assigment of value for MB0 in the CAN_IDR register */
#define CAN_IDR_MB1_Pos                       _UINT32_(1)                                          /* (CAN_IDR) Mailbox 1 Interrupt Disable Position */
#define CAN_IDR_MB1_Msk                       (_UINT32_(0x1) << CAN_IDR_MB1_Pos)                   /* (CAN_IDR) Mailbox 1 Interrupt Disable Mask */
#define CAN_IDR_MB1(value)                    (CAN_IDR_MB1_Msk & (_UINT32_(value) << CAN_IDR_MB1_Pos)) /* Assigment of value for MB1 in the CAN_IDR register */
#define CAN_IDR_MB2_Pos                       _UINT32_(2)                                          /* (CAN_IDR) Mailbox 2 Interrupt Disable Position */
#define CAN_IDR_MB2_Msk                       (_UINT32_(0x1) << CAN_IDR_MB2_Pos)                   /* (CAN_IDR) Mailbox 2 Interrupt Disable Mask */
#define CAN_IDR_MB2(value)                    (CAN_IDR_MB2_Msk & (_UINT32_(value) << CAN_IDR_MB2_Pos)) /* Assigment of value for MB2 in the CAN_IDR register */
#define CAN_IDR_MB3_Pos                       _UINT32_(3)                                          /* (CAN_IDR) Mailbox 3 Interrupt Disable Position */
#define CAN_IDR_MB3_Msk                       (_UINT32_(0x1) << CAN_IDR_MB3_Pos)                   /* (CAN_IDR) Mailbox 3 Interrupt Disable Mask */
#define CAN_IDR_MB3(value)                    (CAN_IDR_MB3_Msk & (_UINT32_(value) << CAN_IDR_MB3_Pos)) /* Assigment of value for MB3 in the CAN_IDR register */
#define CAN_IDR_MB4_Pos                       _UINT32_(4)                                          /* (CAN_IDR) Mailbox 4 Interrupt Disable Position */
#define CAN_IDR_MB4_Msk                       (_UINT32_(0x1) << CAN_IDR_MB4_Pos)                   /* (CAN_IDR) Mailbox 4 Interrupt Disable Mask */
#define CAN_IDR_MB4(value)                    (CAN_IDR_MB4_Msk & (_UINT32_(value) << CAN_IDR_MB4_Pos)) /* Assigment of value for MB4 in the CAN_IDR register */
#define CAN_IDR_MB5_Pos                       _UINT32_(5)                                          /* (CAN_IDR) Mailbox 5 Interrupt Disable Position */
#define CAN_IDR_MB5_Msk                       (_UINT32_(0x1) << CAN_IDR_MB5_Pos)                   /* (CAN_IDR) Mailbox 5 Interrupt Disable Mask */
#define CAN_IDR_MB5(value)                    (CAN_IDR_MB5_Msk & (_UINT32_(value) << CAN_IDR_MB5_Pos)) /* Assigment of value for MB5 in the CAN_IDR register */
#define CAN_IDR_MB6_Pos                       _UINT32_(6)                                          /* (CAN_IDR) Mailbox 6 Interrupt Disable Position */
#define CAN_IDR_MB6_Msk                       (_UINT32_(0x1) << CAN_IDR_MB6_Pos)                   /* (CAN_IDR) Mailbox 6 Interrupt Disable Mask */
#define CAN_IDR_MB6(value)                    (CAN_IDR_MB6_Msk & (_UINT32_(value) << CAN_IDR_MB6_Pos)) /* Assigment of value for MB6 in the CAN_IDR register */
#define CAN_IDR_MB7_Pos                       _UINT32_(7)                                          /* (CAN_IDR) Mailbox 7 Interrupt Disable Position */
#define CAN_IDR_MB7_Msk                       (_UINT32_(0x1) << CAN_IDR_MB7_Pos)                   /* (CAN_IDR) Mailbox 7 Interrupt Disable Mask */
#define CAN_IDR_MB7(value)                    (CAN_IDR_MB7_Msk & (_UINT32_(value) << CAN_IDR_MB7_Pos)) /* Assigment of value for MB7 in the CAN_IDR register */
#define CAN_IDR_ERRA_Pos                      _UINT32_(16)                                         /* (CAN_IDR) Error Active Mode Interrupt Disable Position */
#define CAN_IDR_ERRA_Msk                      (_UINT32_(0x1) << CAN_IDR_ERRA_Pos)                  /* (CAN_IDR) Error Active Mode Interrupt Disable Mask */
#define CAN_IDR_ERRA(value)                   (CAN_IDR_ERRA_Msk & (_UINT32_(value) << CAN_IDR_ERRA_Pos)) /* Assigment of value for ERRA in the CAN_IDR register */
#define CAN_IDR_WARN_Pos                      _UINT32_(17)                                         /* (CAN_IDR) Warning Limit Interrupt Disable Position */
#define CAN_IDR_WARN_Msk                      (_UINT32_(0x1) << CAN_IDR_WARN_Pos)                  /* (CAN_IDR) Warning Limit Interrupt Disable Mask */
#define CAN_IDR_WARN(value)                   (CAN_IDR_WARN_Msk & (_UINT32_(value) << CAN_IDR_WARN_Pos)) /* Assigment of value for WARN in the CAN_IDR register */
#define CAN_IDR_ERRP_Pos                      _UINT32_(18)                                         /* (CAN_IDR) Error Passive Mode Interrupt Disable Position */
#define CAN_IDR_ERRP_Msk                      (_UINT32_(0x1) << CAN_IDR_ERRP_Pos)                  /* (CAN_IDR) Error Passive Mode Interrupt Disable Mask */
#define CAN_IDR_ERRP(value)                   (CAN_IDR_ERRP_Msk & (_UINT32_(value) << CAN_IDR_ERRP_Pos)) /* Assigment of value for ERRP in the CAN_IDR register */
#define CAN_IDR_BOFF_Pos                      _UINT32_(19)                                         /* (CAN_IDR) Bus Off Mode Interrupt Disable Position */
#define CAN_IDR_BOFF_Msk                      (_UINT32_(0x1) << CAN_IDR_BOFF_Pos)                  /* (CAN_IDR) Bus Off Mode Interrupt Disable Mask */
#define CAN_IDR_BOFF(value)                   (CAN_IDR_BOFF_Msk & (_UINT32_(value) << CAN_IDR_BOFF_Pos)) /* Assigment of value for BOFF in the CAN_IDR register */
#define CAN_IDR_SLEEP_Pos                     _UINT32_(20)                                         /* (CAN_IDR) Sleep Interrupt Disable Position */
#define CAN_IDR_SLEEP_Msk                     (_UINT32_(0x1) << CAN_IDR_SLEEP_Pos)                 /* (CAN_IDR) Sleep Interrupt Disable Mask */
#define CAN_IDR_SLEEP(value)                  (CAN_IDR_SLEEP_Msk & (_UINT32_(value) << CAN_IDR_SLEEP_Pos)) /* Assigment of value for SLEEP in the CAN_IDR register */
#define CAN_IDR_WAKEUP_Pos                    _UINT32_(21)                                         /* (CAN_IDR) Wakeup Interrupt Disable Position */
#define CAN_IDR_WAKEUP_Msk                    (_UINT32_(0x1) << CAN_IDR_WAKEUP_Pos)                /* (CAN_IDR) Wakeup Interrupt Disable Mask */
#define CAN_IDR_WAKEUP(value)                 (CAN_IDR_WAKEUP_Msk & (_UINT32_(value) << CAN_IDR_WAKEUP_Pos)) /* Assigment of value for WAKEUP in the CAN_IDR register */
#define CAN_IDR_TOVF_Pos                      _UINT32_(22)                                         /* (CAN_IDR) Timer Overflow Interrupt Position */
#define CAN_IDR_TOVF_Msk                      (_UINT32_(0x1) << CAN_IDR_TOVF_Pos)                  /* (CAN_IDR) Timer Overflow Interrupt Mask */
#define CAN_IDR_TOVF(value)                   (CAN_IDR_TOVF_Msk & (_UINT32_(value) << CAN_IDR_TOVF_Pos)) /* Assigment of value for TOVF in the CAN_IDR register */
#define CAN_IDR_TSTP_Pos                      _UINT32_(23)                                         /* (CAN_IDR) TimeStamp Interrupt Disable Position */
#define CAN_IDR_TSTP_Msk                      (_UINT32_(0x1) << CAN_IDR_TSTP_Pos)                  /* (CAN_IDR) TimeStamp Interrupt Disable Mask */
#define CAN_IDR_TSTP(value)                   (CAN_IDR_TSTP_Msk & (_UINT32_(value) << CAN_IDR_TSTP_Pos)) /* Assigment of value for TSTP in the CAN_IDR register */
#define CAN_IDR_CERR_Pos                      _UINT32_(24)                                         /* (CAN_IDR) CRC Error Interrupt Disable Position */
#define CAN_IDR_CERR_Msk                      (_UINT32_(0x1) << CAN_IDR_CERR_Pos)                  /* (CAN_IDR) CRC Error Interrupt Disable Mask */
#define CAN_IDR_CERR(value)                   (CAN_IDR_CERR_Msk & (_UINT32_(value) << CAN_IDR_CERR_Pos)) /* Assigment of value for CERR in the CAN_IDR register */
#define CAN_IDR_SERR_Pos                      _UINT32_(25)                                         /* (CAN_IDR) Stuffing Error Interrupt Disable Position */
#define CAN_IDR_SERR_Msk                      (_UINT32_(0x1) << CAN_IDR_SERR_Pos)                  /* (CAN_IDR) Stuffing Error Interrupt Disable Mask */
#define CAN_IDR_SERR(value)                   (CAN_IDR_SERR_Msk & (_UINT32_(value) << CAN_IDR_SERR_Pos)) /* Assigment of value for SERR in the CAN_IDR register */
#define CAN_IDR_AERR_Pos                      _UINT32_(26)                                         /* (CAN_IDR) Acknowledgment Error Interrupt Disable Position */
#define CAN_IDR_AERR_Msk                      (_UINT32_(0x1) << CAN_IDR_AERR_Pos)                  /* (CAN_IDR) Acknowledgment Error Interrupt Disable Mask */
#define CAN_IDR_AERR(value)                   (CAN_IDR_AERR_Msk & (_UINT32_(value) << CAN_IDR_AERR_Pos)) /* Assigment of value for AERR in the CAN_IDR register */
#define CAN_IDR_FERR_Pos                      _UINT32_(27)                                         /* (CAN_IDR) Form Error Interrupt Disable Position */
#define CAN_IDR_FERR_Msk                      (_UINT32_(0x1) << CAN_IDR_FERR_Pos)                  /* (CAN_IDR) Form Error Interrupt Disable Mask */
#define CAN_IDR_FERR(value)                   (CAN_IDR_FERR_Msk & (_UINT32_(value) << CAN_IDR_FERR_Pos)) /* Assigment of value for FERR in the CAN_IDR register */
#define CAN_IDR_BERR_Pos                      _UINT32_(28)                                         /* (CAN_IDR) Bit Error Interrupt Disable Position */
#define CAN_IDR_BERR_Msk                      (_UINT32_(0x1) << CAN_IDR_BERR_Pos)                  /* (CAN_IDR) Bit Error Interrupt Disable Mask */
#define CAN_IDR_BERR(value)                   (CAN_IDR_BERR_Msk & (_UINT32_(value) << CAN_IDR_BERR_Pos)) /* Assigment of value for BERR in the CAN_IDR register */
#define CAN_IDR_Msk                           _UINT32_(0x1FFF00FF)                                 /* (CAN_IDR) Register Mask  */

#define CAN_IDR_MB_Pos                        _UINT32_(0)                                          /* (CAN_IDR Position) Mailbox x Interrupt Disable */
#define CAN_IDR_MB_Msk                        (_UINT32_(0xFF) << CAN_IDR_MB_Pos)                   /* (CAN_IDR Mask) MB */
#define CAN_IDR_MB(value)                     (CAN_IDR_MB_Msk & (_UINT32_(value) << CAN_IDR_MB_Pos)) 

/* -------- CAN_IMR : (CAN Offset: 0x0C) ( R/ 32) Interrupt Mask Register -------- */
#define CAN_IMR_MB0_Pos                       _UINT32_(0)                                          /* (CAN_IMR) Mailbox 0 Interrupt Mask Position */
#define CAN_IMR_MB0_Msk                       (_UINT32_(0x1) << CAN_IMR_MB0_Pos)                   /* (CAN_IMR) Mailbox 0 Interrupt Mask Mask */
#define CAN_IMR_MB0(value)                    (CAN_IMR_MB0_Msk & (_UINT32_(value) << CAN_IMR_MB0_Pos)) /* Assigment of value for MB0 in the CAN_IMR register */
#define CAN_IMR_MB1_Pos                       _UINT32_(1)                                          /* (CAN_IMR) Mailbox 1 Interrupt Mask Position */
#define CAN_IMR_MB1_Msk                       (_UINT32_(0x1) << CAN_IMR_MB1_Pos)                   /* (CAN_IMR) Mailbox 1 Interrupt Mask Mask */
#define CAN_IMR_MB1(value)                    (CAN_IMR_MB1_Msk & (_UINT32_(value) << CAN_IMR_MB1_Pos)) /* Assigment of value for MB1 in the CAN_IMR register */
#define CAN_IMR_MB2_Pos                       _UINT32_(2)                                          /* (CAN_IMR) Mailbox 2 Interrupt Mask Position */
#define CAN_IMR_MB2_Msk                       (_UINT32_(0x1) << CAN_IMR_MB2_Pos)                   /* (CAN_IMR) Mailbox 2 Interrupt Mask Mask */
#define CAN_IMR_MB2(value)                    (CAN_IMR_MB2_Msk & (_UINT32_(value) << CAN_IMR_MB2_Pos)) /* Assigment of value for MB2 in the CAN_IMR register */
#define CAN_IMR_MB3_Pos                       _UINT32_(3)                                          /* (CAN_IMR) Mailbox 3 Interrupt Mask Position */
#define CAN_IMR_MB3_Msk                       (_UINT32_(0x1) << CAN_IMR_MB3_Pos)                   /* (CAN_IMR) Mailbox 3 Interrupt Mask Mask */
#define CAN_IMR_MB3(value)                    (CAN_IMR_MB3_Msk & (_UINT32_(value) << CAN_IMR_MB3_Pos)) /* Assigment of value for MB3 in the CAN_IMR register */
#define CAN_IMR_MB4_Pos                       _UINT32_(4)                                          /* (CAN_IMR) Mailbox 4 Interrupt Mask Position */
#define CAN_IMR_MB4_Msk                       (_UINT32_(0x1) << CAN_IMR_MB4_Pos)                   /* (CAN_IMR) Mailbox 4 Interrupt Mask Mask */
#define CAN_IMR_MB4(value)                    (CAN_IMR_MB4_Msk & (_UINT32_(value) << CAN_IMR_MB4_Pos)) /* Assigment of value for MB4 in the CAN_IMR register */
#define CAN_IMR_MB5_Pos                       _UINT32_(5)                                          /* (CAN_IMR) Mailbox 5 Interrupt Mask Position */
#define CAN_IMR_MB5_Msk                       (_UINT32_(0x1) << CAN_IMR_MB5_Pos)                   /* (CAN_IMR) Mailbox 5 Interrupt Mask Mask */
#define CAN_IMR_MB5(value)                    (CAN_IMR_MB5_Msk & (_UINT32_(value) << CAN_IMR_MB5_Pos)) /* Assigment of value for MB5 in the CAN_IMR register */
#define CAN_IMR_MB6_Pos                       _UINT32_(6)                                          /* (CAN_IMR) Mailbox 6 Interrupt Mask Position */
#define CAN_IMR_MB6_Msk                       (_UINT32_(0x1) << CAN_IMR_MB6_Pos)                   /* (CAN_IMR) Mailbox 6 Interrupt Mask Mask */
#define CAN_IMR_MB6(value)                    (CAN_IMR_MB6_Msk & (_UINT32_(value) << CAN_IMR_MB6_Pos)) /* Assigment of value for MB6 in the CAN_IMR register */
#define CAN_IMR_MB7_Pos                       _UINT32_(7)                                          /* (CAN_IMR) Mailbox 7 Interrupt Mask Position */
#define CAN_IMR_MB7_Msk                       (_UINT32_(0x1) << CAN_IMR_MB7_Pos)                   /* (CAN_IMR) Mailbox 7 Interrupt Mask Mask */
#define CAN_IMR_MB7(value)                    (CAN_IMR_MB7_Msk & (_UINT32_(value) << CAN_IMR_MB7_Pos)) /* Assigment of value for MB7 in the CAN_IMR register */
#define CAN_IMR_ERRA_Pos                      _UINT32_(16)                                         /* (CAN_IMR) Error Active Mode Interrupt Mask Position */
#define CAN_IMR_ERRA_Msk                      (_UINT32_(0x1) << CAN_IMR_ERRA_Pos)                  /* (CAN_IMR) Error Active Mode Interrupt Mask Mask */
#define CAN_IMR_ERRA(value)                   (CAN_IMR_ERRA_Msk & (_UINT32_(value) << CAN_IMR_ERRA_Pos)) /* Assigment of value for ERRA in the CAN_IMR register */
#define CAN_IMR_WARN_Pos                      _UINT32_(17)                                         /* (CAN_IMR) Warning Limit Interrupt Mask Position */
#define CAN_IMR_WARN_Msk                      (_UINT32_(0x1) << CAN_IMR_WARN_Pos)                  /* (CAN_IMR) Warning Limit Interrupt Mask Mask */
#define CAN_IMR_WARN(value)                   (CAN_IMR_WARN_Msk & (_UINT32_(value) << CAN_IMR_WARN_Pos)) /* Assigment of value for WARN in the CAN_IMR register */
#define CAN_IMR_ERRP_Pos                      _UINT32_(18)                                         /* (CAN_IMR) Error Passive Mode Interrupt Mask Position */
#define CAN_IMR_ERRP_Msk                      (_UINT32_(0x1) << CAN_IMR_ERRP_Pos)                  /* (CAN_IMR) Error Passive Mode Interrupt Mask Mask */
#define CAN_IMR_ERRP(value)                   (CAN_IMR_ERRP_Msk & (_UINT32_(value) << CAN_IMR_ERRP_Pos)) /* Assigment of value for ERRP in the CAN_IMR register */
#define CAN_IMR_BOFF_Pos                      _UINT32_(19)                                         /* (CAN_IMR) Bus Off Mode Interrupt Mask Position */
#define CAN_IMR_BOFF_Msk                      (_UINT32_(0x1) << CAN_IMR_BOFF_Pos)                  /* (CAN_IMR) Bus Off Mode Interrupt Mask Mask */
#define CAN_IMR_BOFF(value)                   (CAN_IMR_BOFF_Msk & (_UINT32_(value) << CAN_IMR_BOFF_Pos)) /* Assigment of value for BOFF in the CAN_IMR register */
#define CAN_IMR_SLEEP_Pos                     _UINT32_(20)                                         /* (CAN_IMR) Sleep Interrupt Mask Position */
#define CAN_IMR_SLEEP_Msk                     (_UINT32_(0x1) << CAN_IMR_SLEEP_Pos)                 /* (CAN_IMR) Sleep Interrupt Mask Mask */
#define CAN_IMR_SLEEP(value)                  (CAN_IMR_SLEEP_Msk & (_UINT32_(value) << CAN_IMR_SLEEP_Pos)) /* Assigment of value for SLEEP in the CAN_IMR register */
#define CAN_IMR_WAKEUP_Pos                    _UINT32_(21)                                         /* (CAN_IMR) Wakeup Interrupt Mask Position */
#define CAN_IMR_WAKEUP_Msk                    (_UINT32_(0x1) << CAN_IMR_WAKEUP_Pos)                /* (CAN_IMR) Wakeup Interrupt Mask Mask */
#define CAN_IMR_WAKEUP(value)                 (CAN_IMR_WAKEUP_Msk & (_UINT32_(value) << CAN_IMR_WAKEUP_Pos)) /* Assigment of value for WAKEUP in the CAN_IMR register */
#define CAN_IMR_TOVF_Pos                      _UINT32_(22)                                         /* (CAN_IMR) Timer Overflow Interrupt Mask Position */
#define CAN_IMR_TOVF_Msk                      (_UINT32_(0x1) << CAN_IMR_TOVF_Pos)                  /* (CAN_IMR) Timer Overflow Interrupt Mask Mask */
#define CAN_IMR_TOVF(value)                   (CAN_IMR_TOVF_Msk & (_UINT32_(value) << CAN_IMR_TOVF_Pos)) /* Assigment of value for TOVF in the CAN_IMR register */
#define CAN_IMR_TSTP_Pos                      _UINT32_(23)                                         /* (CAN_IMR) Timestamp Interrupt Mask Position */
#define CAN_IMR_TSTP_Msk                      (_UINT32_(0x1) << CAN_IMR_TSTP_Pos)                  /* (CAN_IMR) Timestamp Interrupt Mask Mask */
#define CAN_IMR_TSTP(value)                   (CAN_IMR_TSTP_Msk & (_UINT32_(value) << CAN_IMR_TSTP_Pos)) /* Assigment of value for TSTP in the CAN_IMR register */
#define CAN_IMR_CERR_Pos                      _UINT32_(24)                                         /* (CAN_IMR) CRC Error Interrupt Mask Position */
#define CAN_IMR_CERR_Msk                      (_UINT32_(0x1) << CAN_IMR_CERR_Pos)                  /* (CAN_IMR) CRC Error Interrupt Mask Mask */
#define CAN_IMR_CERR(value)                   (CAN_IMR_CERR_Msk & (_UINT32_(value) << CAN_IMR_CERR_Pos)) /* Assigment of value for CERR in the CAN_IMR register */
#define CAN_IMR_SERR_Pos                      _UINT32_(25)                                         /* (CAN_IMR) Stuffing Error Interrupt Mask Position */
#define CAN_IMR_SERR_Msk                      (_UINT32_(0x1) << CAN_IMR_SERR_Pos)                  /* (CAN_IMR) Stuffing Error Interrupt Mask Mask */
#define CAN_IMR_SERR(value)                   (CAN_IMR_SERR_Msk & (_UINT32_(value) << CAN_IMR_SERR_Pos)) /* Assigment of value for SERR in the CAN_IMR register */
#define CAN_IMR_AERR_Pos                      _UINT32_(26)                                         /* (CAN_IMR) Acknowledgment Error Interrupt Mask Position */
#define CAN_IMR_AERR_Msk                      (_UINT32_(0x1) << CAN_IMR_AERR_Pos)                  /* (CAN_IMR) Acknowledgment Error Interrupt Mask Mask */
#define CAN_IMR_AERR(value)                   (CAN_IMR_AERR_Msk & (_UINT32_(value) << CAN_IMR_AERR_Pos)) /* Assigment of value for AERR in the CAN_IMR register */
#define CAN_IMR_FERR_Pos                      _UINT32_(27)                                         /* (CAN_IMR) Form Error Interrupt Mask Position */
#define CAN_IMR_FERR_Msk                      (_UINT32_(0x1) << CAN_IMR_FERR_Pos)                  /* (CAN_IMR) Form Error Interrupt Mask Mask */
#define CAN_IMR_FERR(value)                   (CAN_IMR_FERR_Msk & (_UINT32_(value) << CAN_IMR_FERR_Pos)) /* Assigment of value for FERR in the CAN_IMR register */
#define CAN_IMR_BERR_Pos                      _UINT32_(28)                                         /* (CAN_IMR) Bit Error Interrupt Mask Position */
#define CAN_IMR_BERR_Msk                      (_UINT32_(0x1) << CAN_IMR_BERR_Pos)                  /* (CAN_IMR) Bit Error Interrupt Mask Mask */
#define CAN_IMR_BERR(value)                   (CAN_IMR_BERR_Msk & (_UINT32_(value) << CAN_IMR_BERR_Pos)) /* Assigment of value for BERR in the CAN_IMR register */
#define CAN_IMR_Msk                           _UINT32_(0x1FFF00FF)                                 /* (CAN_IMR) Register Mask  */

#define CAN_IMR_MB_Pos                        _UINT32_(0)                                          /* (CAN_IMR Position) Mailbox x Interrupt Mask */
#define CAN_IMR_MB_Msk                        (_UINT32_(0xFF) << CAN_IMR_MB_Pos)                   /* (CAN_IMR Mask) MB */
#define CAN_IMR_MB(value)                     (CAN_IMR_MB_Msk & (_UINT32_(value) << CAN_IMR_MB_Pos)) 

/* -------- CAN_SR : (CAN Offset: 0x10) ( R/ 32) Status Register -------- */
#define CAN_SR_MB0_Pos                        _UINT32_(0)                                          /* (CAN_SR) Mailbox 0 Event Position */
#define CAN_SR_MB0_Msk                        (_UINT32_(0x1) << CAN_SR_MB0_Pos)                    /* (CAN_SR) Mailbox 0 Event Mask */
#define CAN_SR_MB0(value)                     (CAN_SR_MB0_Msk & (_UINT32_(value) << CAN_SR_MB0_Pos)) /* Assigment of value for MB0 in the CAN_SR register */
#define CAN_SR_MB1_Pos                        _UINT32_(1)                                          /* (CAN_SR) Mailbox 1 Event Position */
#define CAN_SR_MB1_Msk                        (_UINT32_(0x1) << CAN_SR_MB1_Pos)                    /* (CAN_SR) Mailbox 1 Event Mask */
#define CAN_SR_MB1(value)                     (CAN_SR_MB1_Msk & (_UINT32_(value) << CAN_SR_MB1_Pos)) /* Assigment of value for MB1 in the CAN_SR register */
#define CAN_SR_MB2_Pos                        _UINT32_(2)                                          /* (CAN_SR) Mailbox 2 Event Position */
#define CAN_SR_MB2_Msk                        (_UINT32_(0x1) << CAN_SR_MB2_Pos)                    /* (CAN_SR) Mailbox 2 Event Mask */
#define CAN_SR_MB2(value)                     (CAN_SR_MB2_Msk & (_UINT32_(value) << CAN_SR_MB2_Pos)) /* Assigment of value for MB2 in the CAN_SR register */
#define CAN_SR_MB3_Pos                        _UINT32_(3)                                          /* (CAN_SR) Mailbox 3 Event Position */
#define CAN_SR_MB3_Msk                        (_UINT32_(0x1) << CAN_SR_MB3_Pos)                    /* (CAN_SR) Mailbox 3 Event Mask */
#define CAN_SR_MB3(value)                     (CAN_SR_MB3_Msk & (_UINT32_(value) << CAN_SR_MB3_Pos)) /* Assigment of value for MB3 in the CAN_SR register */
#define CAN_SR_MB4_Pos                        _UINT32_(4)                                          /* (CAN_SR) Mailbox 4 Event Position */
#define CAN_SR_MB4_Msk                        (_UINT32_(0x1) << CAN_SR_MB4_Pos)                    /* (CAN_SR) Mailbox 4 Event Mask */
#define CAN_SR_MB4(value)                     (CAN_SR_MB4_Msk & (_UINT32_(value) << CAN_SR_MB4_Pos)) /* Assigment of value for MB4 in the CAN_SR register */
#define CAN_SR_MB5_Pos                        _UINT32_(5)                                          /* (CAN_SR) Mailbox 5 Event Position */
#define CAN_SR_MB5_Msk                        (_UINT32_(0x1) << CAN_SR_MB5_Pos)                    /* (CAN_SR) Mailbox 5 Event Mask */
#define CAN_SR_MB5(value)                     (CAN_SR_MB5_Msk & (_UINT32_(value) << CAN_SR_MB5_Pos)) /* Assigment of value for MB5 in the CAN_SR register */
#define CAN_SR_MB6_Pos                        _UINT32_(6)                                          /* (CAN_SR) Mailbox 6 Event Position */
#define CAN_SR_MB6_Msk                        (_UINT32_(0x1) << CAN_SR_MB6_Pos)                    /* (CAN_SR) Mailbox 6 Event Mask */
#define CAN_SR_MB6(value)                     (CAN_SR_MB6_Msk & (_UINT32_(value) << CAN_SR_MB6_Pos)) /* Assigment of value for MB6 in the CAN_SR register */
#define CAN_SR_MB7_Pos                        _UINT32_(7)                                          /* (CAN_SR) Mailbox 7 Event Position */
#define CAN_SR_MB7_Msk                        (_UINT32_(0x1) << CAN_SR_MB7_Pos)                    /* (CAN_SR) Mailbox 7 Event Mask */
#define CAN_SR_MB7(value)                     (CAN_SR_MB7_Msk & (_UINT32_(value) << CAN_SR_MB7_Pos)) /* Assigment of value for MB7 in the CAN_SR register */
#define CAN_SR_ERRA_Pos                       _UINT32_(16)                                         /* (CAN_SR) Error Active Mode (automatically cleared by reading CAN_SR) Position */
#define CAN_SR_ERRA_Msk                       (_UINT32_(0x1) << CAN_SR_ERRA_Pos)                   /* (CAN_SR) Error Active Mode (automatically cleared by reading CAN_SR) Mask */
#define CAN_SR_ERRA(value)                    (CAN_SR_ERRA_Msk & (_UINT32_(value) << CAN_SR_ERRA_Pos)) /* Assigment of value for ERRA in the CAN_SR register */
#define CAN_SR_WARN_Pos                       _UINT32_(17)                                         /* (CAN_SR) Warning Limit (automatically cleared by reading CAN_SR) Position */
#define CAN_SR_WARN_Msk                       (_UINT32_(0x1) << CAN_SR_WARN_Pos)                   /* (CAN_SR) Warning Limit (automatically cleared by reading CAN_SR) Mask */
#define CAN_SR_WARN(value)                    (CAN_SR_WARN_Msk & (_UINT32_(value) << CAN_SR_WARN_Pos)) /* Assigment of value for WARN in the CAN_SR register */
#define CAN_SR_ERRP_Pos                       _UINT32_(18)                                         /* (CAN_SR) Error Passive Mode (automatically cleared by reading CAN_SR) Position */
#define CAN_SR_ERRP_Msk                       (_UINT32_(0x1) << CAN_SR_ERRP_Pos)                   /* (CAN_SR) Error Passive Mode (automatically cleared by reading CAN_SR) Mask */
#define CAN_SR_ERRP(value)                    (CAN_SR_ERRP_Msk & (_UINT32_(value) << CAN_SR_ERRP_Pos)) /* Assigment of value for ERRP in the CAN_SR register */
#define CAN_SR_BOFF_Pos                       _UINT32_(19)                                         /* (CAN_SR) Bus Off Mode (automatically cleared by reading CAN_SR) Position */
#define CAN_SR_BOFF_Msk                       (_UINT32_(0x1) << CAN_SR_BOFF_Pos)                   /* (CAN_SR) Bus Off Mode (automatically cleared by reading CAN_SR) Mask */
#define CAN_SR_BOFF(value)                    (CAN_SR_BOFF_Msk & (_UINT32_(value) << CAN_SR_BOFF_Pos)) /* Assigment of value for BOFF in the CAN_SR register */
#define CAN_SR_SLEEP_Pos                      _UINT32_(20)                                         /* (CAN_SR) CAN Controller in Low-power Mode Position */
#define CAN_SR_SLEEP_Msk                      (_UINT32_(0x1) << CAN_SR_SLEEP_Pos)                  /* (CAN_SR) CAN Controller in Low-power Mode Mask */
#define CAN_SR_SLEEP(value)                   (CAN_SR_SLEEP_Msk & (_UINT32_(value) << CAN_SR_SLEEP_Pos)) /* Assigment of value for SLEEP in the CAN_SR register */
#define CAN_SR_WAKEUP_Pos                     _UINT32_(21)                                         /* (CAN_SR) CAN Controller is not in Low-power Mode Position */
#define CAN_SR_WAKEUP_Msk                     (_UINT32_(0x1) << CAN_SR_WAKEUP_Pos)                 /* (CAN_SR) CAN Controller is not in Low-power Mode Mask */
#define CAN_SR_WAKEUP(value)                  (CAN_SR_WAKEUP_Msk & (_UINT32_(value) << CAN_SR_WAKEUP_Pos)) /* Assigment of value for WAKEUP in the CAN_SR register */
#define CAN_SR_TOVF_Pos                       _UINT32_(22)                                         /* (CAN_SR) Timer Overflow (automatically cleared by reading CAN_SR) Position */
#define CAN_SR_TOVF_Msk                       (_UINT32_(0x1) << CAN_SR_TOVF_Pos)                   /* (CAN_SR) Timer Overflow (automatically cleared by reading CAN_SR) Mask */
#define CAN_SR_TOVF(value)                    (CAN_SR_TOVF_Msk & (_UINT32_(value) << CAN_SR_TOVF_Pos)) /* Assigment of value for TOVF in the CAN_SR register */
#define CAN_SR_TSTP_Pos                       _UINT32_(23)                                         /* (CAN_SR) Timestamp (automatically cleared by reading CAN_SR) Position */
#define CAN_SR_TSTP_Msk                       (_UINT32_(0x1) << CAN_SR_TSTP_Pos)                   /* (CAN_SR) Timestamp (automatically cleared by reading CAN_SR) Mask */
#define CAN_SR_TSTP(value)                    (CAN_SR_TSTP_Msk & (_UINT32_(value) << CAN_SR_TSTP_Pos)) /* Assigment of value for TSTP in the CAN_SR register */
#define CAN_SR_CERR_Pos                       _UINT32_(24)                                         /* (CAN_SR) Mailbox CRC Error (automatically cleared by reading CAN_SR) Position */
#define CAN_SR_CERR_Msk                       (_UINT32_(0x1) << CAN_SR_CERR_Pos)                   /* (CAN_SR) Mailbox CRC Error (automatically cleared by reading CAN_SR) Mask */
#define CAN_SR_CERR(value)                    (CAN_SR_CERR_Msk & (_UINT32_(value) << CAN_SR_CERR_Pos)) /* Assigment of value for CERR in the CAN_SR register */
#define CAN_SR_SERR_Pos                       _UINT32_(25)                                         /* (CAN_SR) Mailbox Stuffing Error (automatically cleared by reading CAN_SR) Position */
#define CAN_SR_SERR_Msk                       (_UINT32_(0x1) << CAN_SR_SERR_Pos)                   /* (CAN_SR) Mailbox Stuffing Error (automatically cleared by reading CAN_SR) Mask */
#define CAN_SR_SERR(value)                    (CAN_SR_SERR_Msk & (_UINT32_(value) << CAN_SR_SERR_Pos)) /* Assigment of value for SERR in the CAN_SR register */
#define CAN_SR_AERR_Pos                       _UINT32_(26)                                         /* (CAN_SR) Acknowledgment Error (automatically cleared by reading CAN_SR) Position */
#define CAN_SR_AERR_Msk                       (_UINT32_(0x1) << CAN_SR_AERR_Pos)                   /* (CAN_SR) Acknowledgment Error (automatically cleared by reading CAN_SR) Mask */
#define CAN_SR_AERR(value)                    (CAN_SR_AERR_Msk & (_UINT32_(value) << CAN_SR_AERR_Pos)) /* Assigment of value for AERR in the CAN_SR register */
#define CAN_SR_FERR_Pos                       _UINT32_(27)                                         /* (CAN_SR) Form Error (automatically cleared by reading CAN_SR) Position */
#define CAN_SR_FERR_Msk                       (_UINT32_(0x1) << CAN_SR_FERR_Pos)                   /* (CAN_SR) Form Error (automatically cleared by reading CAN_SR) Mask */
#define CAN_SR_FERR(value)                    (CAN_SR_FERR_Msk & (_UINT32_(value) << CAN_SR_FERR_Pos)) /* Assigment of value for FERR in the CAN_SR register */
#define CAN_SR_BERR_Pos                       _UINT32_(28)                                         /* (CAN_SR) Bit Error (automatically cleared by reading CAN_SR) Position */
#define CAN_SR_BERR_Msk                       (_UINT32_(0x1) << CAN_SR_BERR_Pos)                   /* (CAN_SR) Bit Error (automatically cleared by reading CAN_SR) Mask */
#define CAN_SR_BERR(value)                    (CAN_SR_BERR_Msk & (_UINT32_(value) << CAN_SR_BERR_Pos)) /* Assigment of value for BERR in the CAN_SR register */
#define CAN_SR_RBSY_Pos                       _UINT32_(29)                                         /* (CAN_SR) Receiver Busy Position */
#define CAN_SR_RBSY_Msk                       (_UINT32_(0x1) << CAN_SR_RBSY_Pos)                   /* (CAN_SR) Receiver Busy Mask */
#define CAN_SR_RBSY(value)                    (CAN_SR_RBSY_Msk & (_UINT32_(value) << CAN_SR_RBSY_Pos)) /* Assigment of value for RBSY in the CAN_SR register */
#define CAN_SR_TBSY_Pos                       _UINT32_(30)                                         /* (CAN_SR) Transmitter Busy Position */
#define CAN_SR_TBSY_Msk                       (_UINT32_(0x1) << CAN_SR_TBSY_Pos)                   /* (CAN_SR) Transmitter Busy Mask */
#define CAN_SR_TBSY(value)                    (CAN_SR_TBSY_Msk & (_UINT32_(value) << CAN_SR_TBSY_Pos)) /* Assigment of value for TBSY in the CAN_SR register */
#define CAN_SR_OVLSY_Pos                      _UINT32_(31)                                         /* (CAN_SR) Overload busy Position */
#define CAN_SR_OVLSY_Msk                      (_UINT32_(0x1) << CAN_SR_OVLSY_Pos)                  /* (CAN_SR) Overload busy Mask */
#define CAN_SR_OVLSY(value)                   (CAN_SR_OVLSY_Msk & (_UINT32_(value) << CAN_SR_OVLSY_Pos)) /* Assigment of value for OVLSY in the CAN_SR register */
#define CAN_SR_Msk                            _UINT32_(0xFFFF00FF)                                 /* (CAN_SR) Register Mask  */

#define CAN_SR_MB_Pos                         _UINT32_(0)                                          /* (CAN_SR Position) Mailbox x Event */
#define CAN_SR_MB_Msk                         (_UINT32_(0xFF) << CAN_SR_MB_Pos)                    /* (CAN_SR Mask) MB */
#define CAN_SR_MB(value)                      (CAN_SR_MB_Msk & (_UINT32_(value) << CAN_SR_MB_Pos)) 

/* -------- CAN_BR : (CAN Offset: 0x14) (R/W 32) Baudrate Register -------- */
#define CAN_BR_PHASE2_Pos                     _UINT32_(0)                                          /* (CAN_BR) Phase 2 Segment Position */
#define CAN_BR_PHASE2_Msk                     (_UINT32_(0x7) << CAN_BR_PHASE2_Pos)                 /* (CAN_BR) Phase 2 Segment Mask */
#define CAN_BR_PHASE2(value)                  (CAN_BR_PHASE2_Msk & (_UINT32_(value) << CAN_BR_PHASE2_Pos)) /* Assigment of value for PHASE2 in the CAN_BR register */
#define CAN_BR_PHASE1_Pos                     _UINT32_(4)                                          /* (CAN_BR) Phase 1 Segment Position */
#define CAN_BR_PHASE1_Msk                     (_UINT32_(0x7) << CAN_BR_PHASE1_Pos)                 /* (CAN_BR) Phase 1 Segment Mask */
#define CAN_BR_PHASE1(value)                  (CAN_BR_PHASE1_Msk & (_UINT32_(value) << CAN_BR_PHASE1_Pos)) /* Assigment of value for PHASE1 in the CAN_BR register */
#define CAN_BR_PROPAG_Pos                     _UINT32_(8)                                          /* (CAN_BR) Programming Time Segment Position */
#define CAN_BR_PROPAG_Msk                     (_UINT32_(0x7) << CAN_BR_PROPAG_Pos)                 /* (CAN_BR) Programming Time Segment Mask */
#define CAN_BR_PROPAG(value)                  (CAN_BR_PROPAG_Msk & (_UINT32_(value) << CAN_BR_PROPAG_Pos)) /* Assigment of value for PROPAG in the CAN_BR register */
#define CAN_BR_SJW_Pos                        _UINT32_(12)                                         /* (CAN_BR) Re-synchronization Jump Width Position */
#define CAN_BR_SJW_Msk                        (_UINT32_(0x3) << CAN_BR_SJW_Pos)                    /* (CAN_BR) Re-synchronization Jump Width Mask */
#define CAN_BR_SJW(value)                     (CAN_BR_SJW_Msk & (_UINT32_(value) << CAN_BR_SJW_Pos)) /* Assigment of value for SJW in the CAN_BR register */
#define CAN_BR_BRP_Pos                        _UINT32_(16)                                         /* (CAN_BR) Baudrate Prescaler Position */
#define CAN_BR_BRP_Msk                        (_UINT32_(0x7F) << CAN_BR_BRP_Pos)                   /* (CAN_BR) Baudrate Prescaler Mask */
#define CAN_BR_BRP(value)                     (CAN_BR_BRP_Msk & (_UINT32_(value) << CAN_BR_BRP_Pos)) /* Assigment of value for BRP in the CAN_BR register */
#define CAN_BR_SMP_Pos                        _UINT32_(24)                                         /* (CAN_BR) Sampling Mode Position */
#define CAN_BR_SMP_Msk                        (_UINT32_(0x1) << CAN_BR_SMP_Pos)                    /* (CAN_BR) Sampling Mode Mask */
#define CAN_BR_SMP(value)                     (CAN_BR_SMP_Msk & (_UINT32_(value) << CAN_BR_SMP_Pos)) /* Assigment of value for SMP in the CAN_BR register */
#define   CAN_BR_SMP_ONCE_Val                 _UINT32_(0x0)                                        /* (CAN_BR) The incoming bit stream is sampled once at sample point.  */
#define   CAN_BR_SMP_THREE_Val                _UINT32_(0x1)                                        /* (CAN_BR) The incoming bit stream is sampled three times with a period of a peripheral clock, centered on sample point.  */
#define CAN_BR_SMP_ONCE                       (CAN_BR_SMP_ONCE_Val << CAN_BR_SMP_Pos)              /* (CAN_BR) The incoming bit stream is sampled once at sample point. Position  */
#define CAN_BR_SMP_THREE                      (CAN_BR_SMP_THREE_Val << CAN_BR_SMP_Pos)             /* (CAN_BR) The incoming bit stream is sampled three times with a period of a peripheral clock, centered on sample point. Position  */
#define CAN_BR_Msk                            _UINT32_(0x017F3777)                                 /* (CAN_BR) Register Mask  */


/* -------- CAN_TIM : (CAN Offset: 0x18) ( R/ 32) Timer Register -------- */
#define CAN_TIM_TIMER_Pos                     _UINT32_(0)                                          /* (CAN_TIM) Timer Position */
#define CAN_TIM_TIMER_Msk                     (_UINT32_(0xFFFF) << CAN_TIM_TIMER_Pos)              /* (CAN_TIM) Timer Mask */
#define CAN_TIM_TIMER(value)                  (CAN_TIM_TIMER_Msk & (_UINT32_(value) << CAN_TIM_TIMER_Pos)) /* Assigment of value for TIMER in the CAN_TIM register */
#define CAN_TIM_Msk                           _UINT32_(0x0000FFFF)                                 /* (CAN_TIM) Register Mask  */


/* -------- CAN_TIMESTP : (CAN Offset: 0x1C) ( R/ 32) Timestamp Register -------- */
#define CAN_TIMESTP_MTIMESTAMP_Pos            _UINT32_(0)                                          /* (CAN_TIMESTP) Timestamp Position */
#define CAN_TIMESTP_MTIMESTAMP_Msk            (_UINT32_(0xFFFF) << CAN_TIMESTP_MTIMESTAMP_Pos)     /* (CAN_TIMESTP) Timestamp Mask */
#define CAN_TIMESTP_MTIMESTAMP(value)         (CAN_TIMESTP_MTIMESTAMP_Msk & (_UINT32_(value) << CAN_TIMESTP_MTIMESTAMP_Pos)) /* Assigment of value for MTIMESTAMP in the CAN_TIMESTP register */
#define CAN_TIMESTP_Msk                       _UINT32_(0x0000FFFF)                                 /* (CAN_TIMESTP) Register Mask  */


/* -------- CAN_ECR : (CAN Offset: 0x20) ( R/ 32) Error Counter Register -------- */
#define CAN_ECR_REC_Pos                       _UINT32_(0)                                          /* (CAN_ECR) Receive Error Counter Position */
#define CAN_ECR_REC_Msk                       (_UINT32_(0xFF) << CAN_ECR_REC_Pos)                  /* (CAN_ECR) Receive Error Counter Mask */
#define CAN_ECR_REC(value)                    (CAN_ECR_REC_Msk & (_UINT32_(value) << CAN_ECR_REC_Pos)) /* Assigment of value for REC in the CAN_ECR register */
#define CAN_ECR_TEC_Pos                       _UINT32_(16)                                         /* (CAN_ECR) Transmit Error Counter Position */
#define CAN_ECR_TEC_Msk                       (_UINT32_(0x1FF) << CAN_ECR_TEC_Pos)                 /* (CAN_ECR) Transmit Error Counter Mask */
#define CAN_ECR_TEC(value)                    (CAN_ECR_TEC_Msk & (_UINT32_(value) << CAN_ECR_TEC_Pos)) /* Assigment of value for TEC in the CAN_ECR register */
#define CAN_ECR_Msk                           _UINT32_(0x01FF00FF)                                 /* (CAN_ECR) Register Mask  */


/* -------- CAN_TCR : (CAN Offset: 0x24) ( /W 32) Transfer Command Register -------- */
#define CAN_TCR_MB0_Pos                       _UINT32_(0)                                          /* (CAN_TCR) Transfer Request for Mailbox 0 Position */
#define CAN_TCR_MB0_Msk                       (_UINT32_(0x1) << CAN_TCR_MB0_Pos)                   /* (CAN_TCR) Transfer Request for Mailbox 0 Mask */
#define CAN_TCR_MB0(value)                    (CAN_TCR_MB0_Msk & (_UINT32_(value) << CAN_TCR_MB0_Pos)) /* Assigment of value for MB0 in the CAN_TCR register */
#define CAN_TCR_MB1_Pos                       _UINT32_(1)                                          /* (CAN_TCR) Transfer Request for Mailbox 1 Position */
#define CAN_TCR_MB1_Msk                       (_UINT32_(0x1) << CAN_TCR_MB1_Pos)                   /* (CAN_TCR) Transfer Request for Mailbox 1 Mask */
#define CAN_TCR_MB1(value)                    (CAN_TCR_MB1_Msk & (_UINT32_(value) << CAN_TCR_MB1_Pos)) /* Assigment of value for MB1 in the CAN_TCR register */
#define CAN_TCR_MB2_Pos                       _UINT32_(2)                                          /* (CAN_TCR) Transfer Request for Mailbox 2 Position */
#define CAN_TCR_MB2_Msk                       (_UINT32_(0x1) << CAN_TCR_MB2_Pos)                   /* (CAN_TCR) Transfer Request for Mailbox 2 Mask */
#define CAN_TCR_MB2(value)                    (CAN_TCR_MB2_Msk & (_UINT32_(value) << CAN_TCR_MB2_Pos)) /* Assigment of value for MB2 in the CAN_TCR register */
#define CAN_TCR_MB3_Pos                       _UINT32_(3)                                          /* (CAN_TCR) Transfer Request for Mailbox 3 Position */
#define CAN_TCR_MB3_Msk                       (_UINT32_(0x1) << CAN_TCR_MB3_Pos)                   /* (CAN_TCR) Transfer Request for Mailbox 3 Mask */
#define CAN_TCR_MB3(value)                    (CAN_TCR_MB3_Msk & (_UINT32_(value) << CAN_TCR_MB3_Pos)) /* Assigment of value for MB3 in the CAN_TCR register */
#define CAN_TCR_MB4_Pos                       _UINT32_(4)                                          /* (CAN_TCR) Transfer Request for Mailbox 4 Position */
#define CAN_TCR_MB4_Msk                       (_UINT32_(0x1) << CAN_TCR_MB4_Pos)                   /* (CAN_TCR) Transfer Request for Mailbox 4 Mask */
#define CAN_TCR_MB4(value)                    (CAN_TCR_MB4_Msk & (_UINT32_(value) << CAN_TCR_MB4_Pos)) /* Assigment of value for MB4 in the CAN_TCR register */
#define CAN_TCR_MB5_Pos                       _UINT32_(5)                                          /* (CAN_TCR) Transfer Request for Mailbox 5 Position */
#define CAN_TCR_MB5_Msk                       (_UINT32_(0x1) << CAN_TCR_MB5_Pos)                   /* (CAN_TCR) Transfer Request for Mailbox 5 Mask */
#define CAN_TCR_MB5(value)                    (CAN_TCR_MB5_Msk & (_UINT32_(value) << CAN_TCR_MB5_Pos)) /* Assigment of value for MB5 in the CAN_TCR register */
#define CAN_TCR_MB6_Pos                       _UINT32_(6)                                          /* (CAN_TCR) Transfer Request for Mailbox 6 Position */
#define CAN_TCR_MB6_Msk                       (_UINT32_(0x1) << CAN_TCR_MB6_Pos)                   /* (CAN_TCR) Transfer Request for Mailbox 6 Mask */
#define CAN_TCR_MB6(value)                    (CAN_TCR_MB6_Msk & (_UINT32_(value) << CAN_TCR_MB6_Pos)) /* Assigment of value for MB6 in the CAN_TCR register */
#define CAN_TCR_MB7_Pos                       _UINT32_(7)                                          /* (CAN_TCR) Transfer Request for Mailbox 7 Position */
#define CAN_TCR_MB7_Msk                       (_UINT32_(0x1) << CAN_TCR_MB7_Pos)                   /* (CAN_TCR) Transfer Request for Mailbox 7 Mask */
#define CAN_TCR_MB7(value)                    (CAN_TCR_MB7_Msk & (_UINT32_(value) << CAN_TCR_MB7_Pos)) /* Assigment of value for MB7 in the CAN_TCR register */
#define CAN_TCR_TIMRST_Pos                    _UINT32_(31)                                         /* (CAN_TCR) Timer Reset Position */
#define CAN_TCR_TIMRST_Msk                    (_UINT32_(0x1) << CAN_TCR_TIMRST_Pos)                /* (CAN_TCR) Timer Reset Mask */
#define CAN_TCR_TIMRST(value)                 (CAN_TCR_TIMRST_Msk & (_UINT32_(value) << CAN_TCR_TIMRST_Pos)) /* Assigment of value for TIMRST in the CAN_TCR register */
#define CAN_TCR_Msk                           _UINT32_(0x800000FF)                                 /* (CAN_TCR) Register Mask  */

#define CAN_TCR_MB_Pos                        _UINT32_(0)                                          /* (CAN_TCR Position) Transfer Request for Mailbox x */
#define CAN_TCR_MB_Msk                        (_UINT32_(0xFF) << CAN_TCR_MB_Pos)                   /* (CAN_TCR Mask) MB */
#define CAN_TCR_MB(value)                     (CAN_TCR_MB_Msk & (_UINT32_(value) << CAN_TCR_MB_Pos)) 

/* -------- CAN_ACR : (CAN Offset: 0x28) ( /W 32) Abort Command Register -------- */
#define CAN_ACR_MB0_Pos                       _UINT32_(0)                                          /* (CAN_ACR) Abort Request for Mailbox 0 Position */
#define CAN_ACR_MB0_Msk                       (_UINT32_(0x1) << CAN_ACR_MB0_Pos)                   /* (CAN_ACR) Abort Request for Mailbox 0 Mask */
#define CAN_ACR_MB0(value)                    (CAN_ACR_MB0_Msk & (_UINT32_(value) << CAN_ACR_MB0_Pos)) /* Assigment of value for MB0 in the CAN_ACR register */
#define CAN_ACR_MB1_Pos                       _UINT32_(1)                                          /* (CAN_ACR) Abort Request for Mailbox 1 Position */
#define CAN_ACR_MB1_Msk                       (_UINT32_(0x1) << CAN_ACR_MB1_Pos)                   /* (CAN_ACR) Abort Request for Mailbox 1 Mask */
#define CAN_ACR_MB1(value)                    (CAN_ACR_MB1_Msk & (_UINT32_(value) << CAN_ACR_MB1_Pos)) /* Assigment of value for MB1 in the CAN_ACR register */
#define CAN_ACR_MB2_Pos                       _UINT32_(2)                                          /* (CAN_ACR) Abort Request for Mailbox 2 Position */
#define CAN_ACR_MB2_Msk                       (_UINT32_(0x1) << CAN_ACR_MB2_Pos)                   /* (CAN_ACR) Abort Request for Mailbox 2 Mask */
#define CAN_ACR_MB2(value)                    (CAN_ACR_MB2_Msk & (_UINT32_(value) << CAN_ACR_MB2_Pos)) /* Assigment of value for MB2 in the CAN_ACR register */
#define CAN_ACR_MB3_Pos                       _UINT32_(3)                                          /* (CAN_ACR) Abort Request for Mailbox 3 Position */
#define CAN_ACR_MB3_Msk                       (_UINT32_(0x1) << CAN_ACR_MB3_Pos)                   /* (CAN_ACR) Abort Request for Mailbox 3 Mask */
#define CAN_ACR_MB3(value)                    (CAN_ACR_MB3_Msk & (_UINT32_(value) << CAN_ACR_MB3_Pos)) /* Assigment of value for MB3 in the CAN_ACR register */
#define CAN_ACR_MB4_Pos                       _UINT32_(4)                                          /* (CAN_ACR) Abort Request for Mailbox 4 Position */
#define CAN_ACR_MB4_Msk                       (_UINT32_(0x1) << CAN_ACR_MB4_Pos)                   /* (CAN_ACR) Abort Request for Mailbox 4 Mask */
#define CAN_ACR_MB4(value)                    (CAN_ACR_MB4_Msk & (_UINT32_(value) << CAN_ACR_MB4_Pos)) /* Assigment of value for MB4 in the CAN_ACR register */
#define CAN_ACR_MB5_Pos                       _UINT32_(5)                                          /* (CAN_ACR) Abort Request for Mailbox 5 Position */
#define CAN_ACR_MB5_Msk                       (_UINT32_(0x1) << CAN_ACR_MB5_Pos)                   /* (CAN_ACR) Abort Request for Mailbox 5 Mask */
#define CAN_ACR_MB5(value)                    (CAN_ACR_MB5_Msk & (_UINT32_(value) << CAN_ACR_MB5_Pos)) /* Assigment of value for MB5 in the CAN_ACR register */
#define CAN_ACR_MB6_Pos                       _UINT32_(6)                                          /* (CAN_ACR) Abort Request for Mailbox 6 Position */
#define CAN_ACR_MB6_Msk                       (_UINT32_(0x1) << CAN_ACR_MB6_Pos)                   /* (CAN_ACR) Abort Request for Mailbox 6 Mask */
#define CAN_ACR_MB6(value)                    (CAN_ACR_MB6_Msk & (_UINT32_(value) << CAN_ACR_MB6_Pos)) /* Assigment of value for MB6 in the CAN_ACR register */
#define CAN_ACR_MB7_Pos                       _UINT32_(7)                                          /* (CAN_ACR) Abort Request for Mailbox 7 Position */
#define CAN_ACR_MB7_Msk                       (_UINT32_(0x1) << CAN_ACR_MB7_Pos)                   /* (CAN_ACR) Abort Request for Mailbox 7 Mask */
#define CAN_ACR_MB7(value)                    (CAN_ACR_MB7_Msk & (_UINT32_(value) << CAN_ACR_MB7_Pos)) /* Assigment of value for MB7 in the CAN_ACR register */
#define CAN_ACR_Msk                           _UINT32_(0x000000FF)                                 /* (CAN_ACR) Register Mask  */

#define CAN_ACR_MB_Pos                        _UINT32_(0)                                          /* (CAN_ACR Position) Abort Request for Mailbox 7 */
#define CAN_ACR_MB_Msk                        (_UINT32_(0xFF) << CAN_ACR_MB_Pos)                   /* (CAN_ACR Mask) MB */
#define CAN_ACR_MB(value)                     (CAN_ACR_MB_Msk & (_UINT32_(value) << CAN_ACR_MB_Pos)) 

/* -------- CAN_WPMR : (CAN Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define CAN_WPMR_WPEN_Pos                     _UINT32_(0)                                          /* (CAN_WPMR) Write Protection Enable Position */
#define CAN_WPMR_WPEN_Msk                     (_UINT32_(0x1) << CAN_WPMR_WPEN_Pos)                 /* (CAN_WPMR) Write Protection Enable Mask */
#define CAN_WPMR_WPEN(value)                  (CAN_WPMR_WPEN_Msk & (_UINT32_(value) << CAN_WPMR_WPEN_Pos)) /* Assigment of value for WPEN in the CAN_WPMR register */
#define CAN_WPMR_WPKEY_Pos                    _UINT32_(8)                                          /* (CAN_WPMR) Write Protection Key Password Position */
#define CAN_WPMR_WPKEY_Msk                    (_UINT32_(0xFFFFFF) << CAN_WPMR_WPKEY_Pos)           /* (CAN_WPMR) Write Protection Key Password Mask */
#define CAN_WPMR_WPKEY(value)                 (CAN_WPMR_WPKEY_Msk & (_UINT32_(value) << CAN_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the CAN_WPMR register */
#define   CAN_WPMR_WPKEY_PASSWD_Val           _UINT32_(0x43414E)                                   /* (CAN_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0  */
#define CAN_WPMR_WPKEY_PASSWD                 (CAN_WPMR_WPKEY_PASSWD_Val << CAN_WPMR_WPKEY_Pos)    /* (CAN_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0 Position  */
#define CAN_WPMR_Msk                          _UINT32_(0xFFFFFF01)                                 /* (CAN_WPMR) Register Mask  */


/* -------- CAN_WPSR : (CAN Offset: 0xE8) ( R/ 32) Write Protection Status Register -------- */
#define CAN_WPSR_WPVS_Pos                     _UINT32_(0)                                          /* (CAN_WPSR) Write Protection Violation Status Position */
#define CAN_WPSR_WPVS_Msk                     (_UINT32_(0x1) << CAN_WPSR_WPVS_Pos)                 /* (CAN_WPSR) Write Protection Violation Status Mask */
#define CAN_WPSR_WPVS(value)                  (CAN_WPSR_WPVS_Msk & (_UINT32_(value) << CAN_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the CAN_WPSR register */
#define CAN_WPSR_WPVSRC_Pos                   _UINT32_(8)                                          /* (CAN_WPSR) Write Protection Violation Source Position */
#define CAN_WPSR_WPVSRC_Msk                   (_UINT32_(0xFF) << CAN_WPSR_WPVSRC_Pos)              /* (CAN_WPSR) Write Protection Violation Source Mask */
#define CAN_WPSR_WPVSRC(value)                (CAN_WPSR_WPVSRC_Msk & (_UINT32_(value) << CAN_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the CAN_WPSR register */
#define CAN_WPSR_Msk                          _UINT32_(0x0000FF01)                                 /* (CAN_WPSR) Register Mask  */


/** \brief CAN register offsets definitions */
#define CAN_MMR_REG_OFST               _UINT32_(0x00)      /* (CAN_MMR) Mailbox Mode Register Offset */
#define CAN_MAM_REG_OFST               _UINT32_(0x04)      /* (CAN_MAM) Mailbox Acceptance Mask Register Offset */
#define CAN_MID_REG_OFST               _UINT32_(0x08)      /* (CAN_MID) Mailbox ID Register Offset */
#define CAN_MFID_REG_OFST              _UINT32_(0x0C)      /* (CAN_MFID) Mailbox Family ID Register Offset */
#define CAN_MSR_REG_OFST               _UINT32_(0x10)      /* (CAN_MSR) Mailbox Status Register Offset */
#define CAN_MDL_REG_OFST               _UINT32_(0x14)      /* (CAN_MDL) Mailbox Data Low Register Offset */
#define CAN_MDH_REG_OFST               _UINT32_(0x18)      /* (CAN_MDH) Mailbox Data High Register Offset */
#define CAN_MCR_REG_OFST               _UINT32_(0x1C)      /* (CAN_MCR) Mailbox Control Register Offset */
#define CAN_MR_REG_OFST                _UINT32_(0x00)      /* (CAN_MR) Mode Register Offset */
#define CAN_IER_REG_OFST               _UINT32_(0x04)      /* (CAN_IER) Interrupt Enable Register Offset */
#define CAN_IDR_REG_OFST               _UINT32_(0x08)      /* (CAN_IDR) Interrupt Disable Register Offset */
#define CAN_IMR_REG_OFST               _UINT32_(0x0C)      /* (CAN_IMR) Interrupt Mask Register Offset */
#define CAN_SR_REG_OFST                _UINT32_(0x10)      /* (CAN_SR) Status Register Offset */
#define CAN_BR_REG_OFST                _UINT32_(0x14)      /* (CAN_BR) Baudrate Register Offset */
#define CAN_TIM_REG_OFST               _UINT32_(0x18)      /* (CAN_TIM) Timer Register Offset */
#define CAN_TIMESTP_REG_OFST           _UINT32_(0x1C)      /* (CAN_TIMESTP) Timestamp Register Offset */
#define CAN_ECR_REG_OFST               _UINT32_(0x20)      /* (CAN_ECR) Error Counter Register Offset */
#define CAN_TCR_REG_OFST               _UINT32_(0x24)      /* (CAN_TCR) Transfer Command Register Offset */
#define CAN_ACR_REG_OFST               _UINT32_(0x28)      /* (CAN_ACR) Abort Command Register Offset */
#define CAN_WPMR_REG_OFST              _UINT32_(0xE4)      /* (CAN_WPMR) Write Protection Mode Register Offset */
#define CAN_WPSR_REG_OFST              _UINT32_(0xE8)      /* (CAN_WPSR) Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief CAN_MB register API structure */
typedef struct
{
  __IO  uint32_t                       CAN_MMR;            /**< Offset: 0x00 (R/W  32) Mailbox Mode Register */
  __IO  uint32_t                       CAN_MAM;            /**< Offset: 0x04 (R/W  32) Mailbox Acceptance Mask Register */
  __IO  uint32_t                       CAN_MID;            /**< Offset: 0x08 (R/W  32) Mailbox ID Register */
  __I   uint32_t                       CAN_MFID;           /**< Offset: 0x0C (R/   32) Mailbox Family ID Register */
  __I   uint32_t                       CAN_MSR;            /**< Offset: 0x10 (R/   32) Mailbox Status Register */
  __IO  uint32_t                       CAN_MDL;            /**< Offset: 0x14 (R/W  32) Mailbox Data Low Register */
  __IO  uint32_t                       CAN_MDH;            /**< Offset: 0x18 (R/W  32) Mailbox Data High Register */
  __O   uint32_t                       CAN_MCR;            /**< Offset: 0x1C ( /W  32) Mailbox Control Register */
} can_mb_registers_t;

#define CAN_MB_NUMBER 8

/** \brief CAN register API structure */
typedef struct
{
  __IO  uint32_t                       CAN_MR;             /**< Offset: 0x00 (R/W  32) Mode Register */
  __O   uint32_t                       CAN_IER;            /**< Offset: 0x04 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       CAN_IDR;            /**< Offset: 0x08 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       CAN_IMR;            /**< Offset: 0x0C (R/   32) Interrupt Mask Register */
  __I   uint32_t                       CAN_SR;             /**< Offset: 0x10 (R/   32) Status Register */
  __IO  uint32_t                       CAN_BR;             /**< Offset: 0x14 (R/W  32) Baudrate Register */
  __I   uint32_t                       CAN_TIM;            /**< Offset: 0x18 (R/   32) Timer Register */
  __I   uint32_t                       CAN_TIMESTP;        /**< Offset: 0x1C (R/   32) Timestamp Register */
  __I   uint32_t                       CAN_ECR;            /**< Offset: 0x20 (R/   32) Error Counter Register */
  __O   uint32_t                       CAN_TCR;            /**< Offset: 0x24 ( /W  32) Transfer Command Register */
  __O   uint32_t                       CAN_ACR;            /**< Offset: 0x28 ( /W  32) Abort Command Register */
  __I   uint8_t                        Reserved1[0xB8];
  __IO  uint32_t                       CAN_WPMR;           /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   uint32_t                       CAN_WPSR;           /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
  __I   uint8_t                        Reserved2[0x114];
        can_mb_registers_t             CAN_MB[CAN_MB_NUMBER]; /**< Offset: 0x200  */
} can_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X_CAN_COMPONENT_H_ */
