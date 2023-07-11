/*
 * Component description for OTPC
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
#ifndef _SAM9X7_OTPC_COMPONENT_H_
#define _SAM9X7_OTPC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR OTPC                                         */
/* ************************************************************************** */

/* -------- OTPC_CR : (OTPC Offset: 0x00) ( /W 32) Control Register -------- */
#define OTPC_CR_PGM_Pos                       _UINT32_(0)                                          /* (OTPC_CR) Program Packet Position */
#define OTPC_CR_PGM_Msk                       (_UINT32_(0x1) << OTPC_CR_PGM_Pos)                   /* (OTPC_CR) Program Packet Mask */
#define OTPC_CR_PGM(value)                    (OTPC_CR_PGM_Msk & (_UINT32_(value) << OTPC_CR_PGM_Pos)) /* Assigment of value for PGM in the OTPC_CR register */
#define   OTPC_CR_PGM_0_Val                   _UINT32_(0x0)                                        /* (OTPC_CR) No effect.  */
#define   OTPC_CR_PGM_1_Val                   _UINT32_(0x1)                                        /* (OTPC_CR) The selected packet is written.  */
#define OTPC_CR_PGM_0                         (OTPC_CR_PGM_0_Val << OTPC_CR_PGM_Pos)               /* (OTPC_CR) No effect. Position  */
#define OTPC_CR_PGM_1                         (OTPC_CR_PGM_1_Val << OTPC_CR_PGM_Pos)               /* (OTPC_CR) The selected packet is written. Position  */
#define OTPC_CR_CKSGEN_Pos                    _UINT32_(1)                                          /* (OTPC_CR) Generate Checksum Position */
#define OTPC_CR_CKSGEN_Msk                    (_UINT32_(0x1) << OTPC_CR_CKSGEN_Pos)                /* (OTPC_CR) Generate Checksum Mask */
#define OTPC_CR_CKSGEN(value)                 (OTPC_CR_CKSGEN_Msk & (_UINT32_(value) << OTPC_CR_CKSGEN_Pos)) /* Assigment of value for CKSGEN in the OTPC_CR register */
#define   OTPC_CR_CKSGEN_0_Val                _UINT32_(0x0)                                        /* (OTPC_CR) No effect.  */
#define   OTPC_CR_CKSGEN_1_Val                _UINT32_(0x1)                                        /* (OTPC_CR) Generates and programs the selected packet checksum. This action also locks the packet.  */
#define OTPC_CR_CKSGEN_0                      (OTPC_CR_CKSGEN_0_Val << OTPC_CR_CKSGEN_Pos)         /* (OTPC_CR) No effect. Position  */
#define OTPC_CR_CKSGEN_1                      (OTPC_CR_CKSGEN_1_Val << OTPC_CR_CKSGEN_Pos)         /* (OTPC_CR) Generates and programs the selected packet checksum. This action also locks the packet. Position  */
#define OTPC_CR_INVLD_Pos                     _UINT32_(2)                                          /* (OTPC_CR) Invalidate Packet Position */
#define OTPC_CR_INVLD_Msk                     (_UINT32_(0x1) << OTPC_CR_INVLD_Pos)                 /* (OTPC_CR) Invalidate Packet Mask */
#define OTPC_CR_INVLD(value)                  (OTPC_CR_INVLD_Msk & (_UINT32_(value) << OTPC_CR_INVLD_Pos)) /* Assigment of value for INVLD in the OTPC_CR register */
#define   OTPC_CR_INVLD_0_Val                 _UINT32_(0x0)                                        /* (OTPC_CR) No effect.  */
#define   OTPC_CR_INVLD_1_Val                 _UINT32_(0x1)                                        /* (OTPC_CR) Invalidates the selected packet.  */
#define OTPC_CR_INVLD_0                       (OTPC_CR_INVLD_0_Val << OTPC_CR_INVLD_Pos)           /* (OTPC_CR) No effect. Position  */
#define OTPC_CR_INVLD_1                       (OTPC_CR_INVLD_1_Val << OTPC_CR_INVLD_Pos)           /* (OTPC_CR) Invalidates the selected packet. Position  */
#define OTPC_CR_HIDE_Pos                      _UINT32_(4)                                          /* (OTPC_CR) Hide Packet Position */
#define OTPC_CR_HIDE_Msk                      (_UINT32_(0x1) << OTPC_CR_HIDE_Pos)                  /* (OTPC_CR) Hide Packet Mask */
#define OTPC_CR_HIDE(value)                   (OTPC_CR_HIDE_Msk & (_UINT32_(value) << OTPC_CR_HIDE_Pos)) /* Assigment of value for HIDE in the OTPC_CR register */
#define   OTPC_CR_HIDE_0_Val                  _UINT32_(0x0)                                        /* (OTPC_CR) No effect.  */
#define   OTPC_CR_HIDE_1_Val                  _UINT32_(0x1)                                        /* (OTPC_CR) The selected packet is not readable anymore until the next reset.  */
#define OTPC_CR_HIDE_0                        (OTPC_CR_HIDE_0_Val << OTPC_CR_HIDE_Pos)             /* (OTPC_CR) No effect. Position  */
#define OTPC_CR_HIDE_1                        (OTPC_CR_HIDE_1_Val << OTPC_CR_HIDE_Pos)             /* (OTPC_CR) The selected packet is not readable anymore until the next reset. Position  */
#define OTPC_CR_READ_Pos                      _UINT32_(6)                                          /* (OTPC_CR) Read Packet Position */
#define OTPC_CR_READ_Msk                      (_UINT32_(0x1) << OTPC_CR_READ_Pos)                  /* (OTPC_CR) Read Packet Mask */
#define OTPC_CR_READ(value)                   (OTPC_CR_READ_Msk & (_UINT32_(value) << OTPC_CR_READ_Pos)) /* Assigment of value for READ in the OTPC_CR register */
#define   OTPC_CR_READ_0_Val                  _UINT32_(0x0)                                        /* (OTPC_CR) No effect.  */
#define   OTPC_CR_READ_1_Val                  _UINT32_(0x1)                                        /* (OTPC_CR) Starts a read sequence of the selected packet.  */
#define OTPC_CR_READ_0                        (OTPC_CR_READ_0_Val << OTPC_CR_READ_Pos)             /* (OTPC_CR) No effect. Position  */
#define OTPC_CR_READ_1                        (OTPC_CR_READ_1_Val << OTPC_CR_READ_Pos)             /* (OTPC_CR) Starts a read sequence of the selected packet. Position  */
#define OTPC_CR_FLUSH_Pos                     _UINT32_(7)                                          /* (OTPC_CR) Flush Temporary Registers Position */
#define OTPC_CR_FLUSH_Msk                     (_UINT32_(0x1) << OTPC_CR_FLUSH_Pos)                 /* (OTPC_CR) Flush Temporary Registers Mask */
#define OTPC_CR_FLUSH(value)                  (OTPC_CR_FLUSH_Msk & (_UINT32_(value) << OTPC_CR_FLUSH_Pos)) /* Assigment of value for FLUSH in the OTPC_CR register */
#define   OTPC_CR_FLUSH_0_Val                 _UINT32_(0x0)                                        /* (OTPC_CR) No effect.  */
#define   OTPC_CR_FLUSH_1_Val                 _UINT32_(0x1)                                        /* (OTPC_CR) Starts a flush of the temporary registers used to store the payload of the packet.  */
#define OTPC_CR_FLUSH_0                       (OTPC_CR_FLUSH_0_Val << OTPC_CR_FLUSH_Pos)           /* (OTPC_CR) No effect. Position  */
#define OTPC_CR_FLUSH_1                       (OTPC_CR_FLUSH_1_Val << OTPC_CR_FLUSH_Pos)           /* (OTPC_CR) Starts a flush of the temporary registers used to store the payload of the packet. Position  */
#define OTPC_CR_KBSTART_Pos                   _UINT32_(8)                                          /* (OTPC_CR) Key Bus Transfer Start Position */
#define OTPC_CR_KBSTART_Msk                   (_UINT32_(0x1) << OTPC_CR_KBSTART_Pos)               /* (OTPC_CR) Key Bus Transfer Start Mask */
#define OTPC_CR_KBSTART(value)                (OTPC_CR_KBSTART_Msk & (_UINT32_(value) << OTPC_CR_KBSTART_Pos)) /* Assigment of value for KBSTART in the OTPC_CR register */
#define   OTPC_CR_KBSTART_0_Val               _UINT32_(0x0)                                        /* (OTPC_CR) No effect.  */
#define   OTPC_CR_KBSTART_1_Val               _UINT32_(0x1)                                        /* (OTPC_CR) Starts a transfer through the Master Key bus.  */
#define OTPC_CR_KBSTART_0                     (OTPC_CR_KBSTART_0_Val << OTPC_CR_KBSTART_Pos)       /* (OTPC_CR) No effect. Position  */
#define OTPC_CR_KBSTART_1                     (OTPC_CR_KBSTART_1_Val << OTPC_CR_KBSTART_Pos)       /* (OTPC_CR) Starts a transfer through the Master Key bus. Position  */
#define OTPC_CR_KBSTOP_Pos                    _UINT32_(9)                                          /* (OTPC_CR) Key Bus Transfer Stop Position */
#define OTPC_CR_KBSTOP_Msk                    (_UINT32_(0x1) << OTPC_CR_KBSTOP_Pos)                /* (OTPC_CR) Key Bus Transfer Stop Mask */
#define OTPC_CR_KBSTOP(value)                 (OTPC_CR_KBSTOP_Msk & (_UINT32_(value) << OTPC_CR_KBSTOP_Pos)) /* Assigment of value for KBSTOP in the OTPC_CR register */
#define   OTPC_CR_KBSTOP_0_Val                _UINT32_(0x0)                                        /* (OTPC_CR) No effect.  */
#define   OTPC_CR_KBSTOP_1_Val                _UINT32_(0x1)                                        /* (OTPC_CR) Stops an on-going transfer on the Master Key bus.  */
#define OTPC_CR_KBSTOP_0                      (OTPC_CR_KBSTOP_0_Val << OTPC_CR_KBSTOP_Pos)         /* (OTPC_CR) No effect. Position  */
#define OTPC_CR_KBSTOP_1                      (OTPC_CR_KBSTOP_1_Val << OTPC_CR_KBSTOP_Pos)         /* (OTPC_CR) Stops an on-going transfer on the Master Key bus. Position  */
#define OTPC_CR_REPAIR_Pos                    _UINT32_(12)                                         /* (OTPC_CR) Live Repair Position */
#define OTPC_CR_REPAIR_Msk                    (_UINT32_(0x1) << OTPC_CR_REPAIR_Pos)                /* (OTPC_CR) Live Repair Mask */
#define OTPC_CR_REPAIR(value)                 (OTPC_CR_REPAIR_Msk & (_UINT32_(value) << OTPC_CR_REPAIR_Pos)) /* Assigment of value for REPAIR in the OTPC_CR register */
#define   OTPC_CR_REPAIR_0_Val                _UINT32_(0x0)                                        /* (OTPC_CR) No effect.  */
#define   OTPC_CR_REPAIR_1_Val                _UINT32_(0x1)                                        /* (OTPC_CR) Starts the OTP live repair.  */
#define OTPC_CR_REPAIR_0                      (OTPC_CR_REPAIR_0_Val << OTPC_CR_REPAIR_Pos)         /* (OTPC_CR) No effect. Position  */
#define OTPC_CR_REPAIR_1                      (OTPC_CR_REPAIR_1_Val << OTPC_CR_REPAIR_Pos)         /* (OTPC_CR) Starts the OTP live repair. Position  */
#define OTPC_CR_REFRESH_Pos                   _UINT32_(15)                                         /* (OTPC_CR) Refresh the Area Position */
#define OTPC_CR_REFRESH_Msk                   (_UINT32_(0x1) << OTPC_CR_REFRESH_Pos)               /* (OTPC_CR) Refresh the Area Mask */
#define OTPC_CR_REFRESH(value)                (OTPC_CR_REFRESH_Msk & (_UINT32_(value) << OTPC_CR_REFRESH_Pos)) /* Assigment of value for REFRESH in the OTPC_CR register */
#define   OTPC_CR_REFRESH_0_Val               _UINT32_(0x0)                                        /* (OTPC_CR) No effect.  */
#define   OTPC_CR_REFRESH_1_Val               _UINT32_(0x1)                                        /* (OTPC_CR) Starts a refresh of the area.  */
#define OTPC_CR_REFRESH_0                     (OTPC_CR_REFRESH_0_Val << OTPC_CR_REFRESH_Pos)       /* (OTPC_CR) No effect. Position  */
#define OTPC_CR_REFRESH_1                     (OTPC_CR_REFRESH_1_Val << OTPC_CR_REFRESH_Pos)       /* (OTPC_CR) Starts a refresh of the area. Position  */
#define OTPC_CR_KEY_Pos                       _UINT32_(16)                                         /* (OTPC_CR) Programming Key Position */
#define OTPC_CR_KEY_Msk                       (_UINT32_(0xFFFF) << OTPC_CR_KEY_Pos)                /* (OTPC_CR) Programming Key Mask */
#define OTPC_CR_KEY(value)                    (OTPC_CR_KEY_Msk & (_UINT32_(value) << OTPC_CR_KEY_Pos)) /* Assigment of value for KEY in the OTPC_CR register */
#define OTPC_CR_Msk                           _UINT32_(0xFFFF93D7)                                 /* (OTPC_CR) Register Mask  */


/* -------- OTPC_MR : (OTPC Offset: 0x04) (R/W 32) Mode Register -------- */
#define OTPC_MR_RESETVALUE                    _UINT32_(0x00)                                       /*  (OTPC_MR) Mode Register  Reset Value */

#define OTPC_MR_UHCRRDIS_Pos                  _UINT32_(0)                                          /* (OTPC_MR) User Hardware Configuration Register Read Disable Position */
#define OTPC_MR_UHCRRDIS_Msk                  (_UINT32_(0x1) << OTPC_MR_UHCRRDIS_Pos)              /* (OTPC_MR) User Hardware Configuration Register Read Disable Mask */
#define OTPC_MR_UHCRRDIS(value)               (OTPC_MR_UHCRRDIS_Msk & (_UINT32_(value) << OTPC_MR_UHCRRDIS_Pos)) /* Assigment of value for UHCRRDIS in the OTPC_MR register */
#define   OTPC_MR_UHCRRDIS_0_Val              _UINT32_(0x0)                                        /* (OTPC_MR) The User Hardware Configuration register can be read through the User Interface.  */
#define   OTPC_MR_UHCRRDIS_1_Val              _UINT32_(0x1)                                        /* (OTPC_MR) The User Hardware Configuration register cannot be read through the User Interface.  */
#define OTPC_MR_UHCRRDIS_0                    (OTPC_MR_UHCRRDIS_0_Val << OTPC_MR_UHCRRDIS_Pos)     /* (OTPC_MR) The User Hardware Configuration register can be read through the User Interface. Position  */
#define OTPC_MR_UHCRRDIS_1                    (OTPC_MR_UHCRRDIS_1_Val << OTPC_MR_UHCRRDIS_Pos)     /* (OTPC_MR) The User Hardware Configuration register cannot be read through the User Interface. Position  */
#define OTPC_MR_NPCKT_Pos                     _UINT32_(4)                                          /* (OTPC_MR) New Packet Position */
#define OTPC_MR_NPCKT_Msk                     (_UINT32_(0x1) << OTPC_MR_NPCKT_Pos)                 /* (OTPC_MR) New Packet Mask */
#define OTPC_MR_NPCKT(value)                  (OTPC_MR_NPCKT_Msk & (_UINT32_(value) << OTPC_MR_NPCKT_Pos)) /* Assigment of value for NPCKT in the OTPC_MR register */
#define   OTPC_MR_NPCKT_0_Val                 _UINT32_(0x0)                                        /* (OTPC_MR) Updates the packet defined at the ADDR address.  */
#define   OTPC_MR_NPCKT_1_Val                 _UINT32_(0x1)                                        /* (OTPC_MR) Creates a new packet.  */
#define OTPC_MR_NPCKT_0                       (OTPC_MR_NPCKT_0_Val << OTPC_MR_NPCKT_Pos)           /* (OTPC_MR) Updates the packet defined at the ADDR address. Position  */
#define OTPC_MR_NPCKT_1                       (OTPC_MR_NPCKT_1_Val << OTPC_MR_NPCKT_Pos)           /* (OTPC_MR) Creates a new packet. Position  */
#define OTPC_MR_EMUL_Pos                      _UINT32_(7)                                          /* (OTPC_MR) Emulation Enable Position */
#define OTPC_MR_EMUL_Msk                      (_UINT32_(0x1) << OTPC_MR_EMUL_Pos)                  /* (OTPC_MR) Emulation Enable Mask */
#define OTPC_MR_EMUL(value)                   (OTPC_MR_EMUL_Msk & (_UINT32_(value) << OTPC_MR_EMUL_Pos)) /* Assigment of value for EMUL in the OTPC_MR register */
#define   OTPC_MR_EMUL_0_Val                  _UINT32_(0x0)                                        /* (OTPC_MR) The Emulation mode of the User area is disabled, all accesses are computed in the OTP memory.  */
#define   OTPC_MR_EMUL_1_Val                  _UINT32_(0x1)                                        /* (OTPC_MR) The Emulation mode of the User area is enabled, all accesses are computed in the Emulation memory.  */
#define OTPC_MR_EMUL_0                        (OTPC_MR_EMUL_0_Val << OTPC_MR_EMUL_Pos)             /* (OTPC_MR) The Emulation mode of the User area is disabled, all accesses are computed in the OTP memory. Position  */
#define OTPC_MR_EMUL_1                        (OTPC_MR_EMUL_1_Val << OTPC_MR_EMUL_Pos)             /* (OTPC_MR) The Emulation mode of the User area is enabled, all accesses are computed in the Emulation memory. Position  */
#define OTPC_MR_RDDIS_Pos                     _UINT32_(8)                                          /* (OTPC_MR) Read Disable Position */
#define OTPC_MR_RDDIS_Msk                     (_UINT32_(0x1) << OTPC_MR_RDDIS_Pos)                 /* (OTPC_MR) Read Disable Mask */
#define OTPC_MR_RDDIS(value)                  (OTPC_MR_RDDIS_Msk & (_UINT32_(value) << OTPC_MR_RDDIS_Pos)) /* Assigment of value for RDDIS in the OTPC_MR register */
#define   OTPC_MR_RDDIS_0_Val                 _UINT32_(0x0)                                        /* (OTPC_MR) The read capability of the OTPC_HR and OTPC_DR registers are enabled.  */
#define   OTPC_MR_RDDIS_1_Val                 _UINT32_(0x1)                                        /* (OTPC_MR) The read capability of the OTPC_HR and OTPC_DR registers are disabled. In case of read, the returned value is 0.  */
#define OTPC_MR_RDDIS_0                       (OTPC_MR_RDDIS_0_Val << OTPC_MR_RDDIS_Pos)           /* (OTPC_MR) The read capability of the OTPC_HR and OTPC_DR registers are enabled. Position  */
#define OTPC_MR_RDDIS_1                       (OTPC_MR_RDDIS_1_Val << OTPC_MR_RDDIS_Pos)           /* (OTPC_MR) The read capability of the OTPC_HR and OTPC_DR registers are disabled. In case of read, the returned value is 0. Position  */
#define OTPC_MR_WRDIS_Pos                     _UINT32_(9)                                          /* (OTPC_MR) Write Disable Position */
#define OTPC_MR_WRDIS_Msk                     (_UINT32_(0x1) << OTPC_MR_WRDIS_Pos)                 /* (OTPC_MR) Write Disable Mask */
#define OTPC_MR_WRDIS(value)                  (OTPC_MR_WRDIS_Msk & (_UINT32_(value) << OTPC_MR_WRDIS_Pos)) /* Assigment of value for WRDIS in the OTPC_MR register */
#define   OTPC_MR_WRDIS_0_Val                 _UINT32_(0x0)                                        /* (OTPC_MR) The write capability of the OTPC_DR register is enabled.  */
#define   OTPC_MR_WRDIS_1_Val                 _UINT32_(0x1)                                        /* (OTPC_MR) The write capability of the OTPC_DR register is disabled.  */
#define OTPC_MR_WRDIS_0                       (OTPC_MR_WRDIS_0_Val << OTPC_MR_WRDIS_Pos)           /* (OTPC_MR) The write capability of the OTPC_DR register is enabled. Position  */
#define OTPC_MR_WRDIS_1                       (OTPC_MR_WRDIS_1_Val << OTPC_MR_WRDIS_Pos)           /* (OTPC_MR) The write capability of the OTPC_DR register is disabled. Position  */
#define OTPC_MR_KBDST_Pos                     _UINT32_(12)                                         /* (OTPC_MR) Key Bus Destination Position */
#define OTPC_MR_KBDST_Msk                     (_UINT32_(0x1) << OTPC_MR_KBDST_Pos)                 /* (OTPC_MR) Key Bus Destination Mask */
#define OTPC_MR_KBDST(value)                  (OTPC_MR_KBDST_Msk & (_UINT32_(value) << OTPC_MR_KBDST_Pos)) /* Assigment of value for KBDST in the OTPC_MR register */
#define   OTPC_MR_KBDST_TDES_Val              _UINT32_(0x0)                                        /* (OTPC_MR) The TDES is the destination of the key transfer.  */
#define   OTPC_MR_KBDST_AES_Val               _UINT32_(0x1)                                        /* (OTPC_MR) The AES is the destination of the key transfer.  */
#define OTPC_MR_KBDST_TDES                    (OTPC_MR_KBDST_TDES_Val << OTPC_MR_KBDST_Pos)        /* (OTPC_MR) The TDES is the destination of the key transfer. Position  */
#define OTPC_MR_KBDST_AES                     (OTPC_MR_KBDST_AES_Val << OTPC_MR_KBDST_Pos)         /* (OTPC_MR) The AES is the destination of the key transfer. Position  */
#define OTPC_MR_LOCK_Pos                      _UINT32_(15)                                         /* (OTPC_MR) Lock Register Position */
#define OTPC_MR_LOCK_Msk                      (_UINT32_(0x1) << OTPC_MR_LOCK_Pos)                  /* (OTPC_MR) Lock Register Mask */
#define OTPC_MR_LOCK(value)                   (OTPC_MR_LOCK_Msk & (_UINT32_(value) << OTPC_MR_LOCK_Pos)) /* Assigment of value for LOCK in the OTPC_MR register */
#define   OTPC_MR_LOCK_0_Val                  _UINT32_(0x0)                                        /* (OTPC_MR) The OTPC_MR register is unlocked; write access changes its value.  */
#define   OTPC_MR_LOCK_1_Val                  _UINT32_(0x1)                                        /* (OTPC_MR) The OTPC_MR register is locked; write access does not change its value.  */
#define OTPC_MR_LOCK_0                        (OTPC_MR_LOCK_0_Val << OTPC_MR_LOCK_Pos)             /* (OTPC_MR) The OTPC_MR register is unlocked; write access changes its value. Position  */
#define OTPC_MR_LOCK_1                        (OTPC_MR_LOCK_1_Val << OTPC_MR_LOCK_Pos)             /* (OTPC_MR) The OTPC_MR register is locked; write access does not change its value. Position  */
#define OTPC_MR_ADDR_Pos                      _UINT32_(16)                                         /* (OTPC_MR) Address Position */
#define OTPC_MR_ADDR_Msk                      (_UINT32_(0xFFFF) << OTPC_MR_ADDR_Pos)               /* (OTPC_MR) Address Mask */
#define OTPC_MR_ADDR(value)                   (OTPC_MR_ADDR_Msk & (_UINT32_(value) << OTPC_MR_ADDR_Pos)) /* Assigment of value for ADDR in the OTPC_MR register */
#define OTPC_MR_Msk                           _UINT32_(0xFFFF9391)                                 /* (OTPC_MR) Register Mask  */


/* -------- OTPC_AR : (OTPC Offset: 0x08) (R/W 32) Address Register -------- */
#define OTPC_AR_RESETVALUE                    _UINT32_(0x00)                                       /*  (OTPC_AR) Address Register  Reset Value */

#define OTPC_AR_DADDR_Pos                     _UINT32_(0)                                          /* (OTPC_AR) Data Address Position */
#define OTPC_AR_DADDR_Msk                     (_UINT32_(0xFF) << OTPC_AR_DADDR_Pos)                /* (OTPC_AR) Data Address Mask */
#define OTPC_AR_DADDR(value)                  (OTPC_AR_DADDR_Msk & (_UINT32_(value) << OTPC_AR_DADDR_Pos)) /* Assigment of value for DADDR in the OTPC_AR register */
#define OTPC_AR_INCRT_Pos                     _UINT32_(16)                                         /* (OTPC_AR) Increment Type Position */
#define OTPC_AR_INCRT_Msk                     (_UINT32_(0x1) << OTPC_AR_INCRT_Pos)                 /* (OTPC_AR) Increment Type Mask */
#define OTPC_AR_INCRT(value)                  (OTPC_AR_INCRT_Msk & (_UINT32_(value) << OTPC_AR_INCRT_Pos)) /* Assigment of value for INCRT in the OTPC_AR register */
#define   OTPC_AR_INCRT_AFTER_READ_Val        _UINT32_(0x0)                                        /* (OTPC_AR) Increment DADDR after a read of OTPC_DR.  */
#define   OTPC_AR_INCRT_AFTER_WRITE_Val       _UINT32_(0x1)                                        /* (OTPC_AR) Increment DADDR after a write of OTPC_DR.  */
#define OTPC_AR_INCRT_AFTER_READ              (OTPC_AR_INCRT_AFTER_READ_Val << OTPC_AR_INCRT_Pos)  /* (OTPC_AR) Increment DADDR after a read of OTPC_DR. Position  */
#define OTPC_AR_INCRT_AFTER_WRITE             (OTPC_AR_INCRT_AFTER_WRITE_Val << OTPC_AR_INCRT_Pos) /* (OTPC_AR) Increment DADDR after a write of OTPC_DR. Position  */
#define OTPC_AR_Msk                           _UINT32_(0x000100FF)                                 /* (OTPC_AR) Register Mask  */


/* -------- OTPC_SR : (OTPC Offset: 0x0C) ( R/ 32) Status Register -------- */
#define OTPC_SR_RESETVALUE                    _UINT32_(0x00)                                       /*  (OTPC_SR) Status Register  Reset Value */

#define OTPC_SR_PGM_Pos                       _UINT32_(0)                                          /* (OTPC_SR) Programming On-Going Position */
#define OTPC_SR_PGM_Msk                       (_UINT32_(0x1) << OTPC_SR_PGM_Pos)                   /* (OTPC_SR) Programming On-Going Mask */
#define OTPC_SR_PGM(value)                    (OTPC_SR_PGM_Msk & (_UINT32_(value) << OTPC_SR_PGM_Pos)) /* Assigment of value for PGM in the OTPC_SR register */
#define   OTPC_SR_PGM_0_Val                   _UINT32_(0x0)                                        /* (OTPC_SR) No packet programming is on-going.  */
#define   OTPC_SR_PGM_1_Val                   _UINT32_(0x1)                                        /* (OTPC_SR) A packet programming is running.  */
#define OTPC_SR_PGM_0                         (OTPC_SR_PGM_0_Val << OTPC_SR_PGM_Pos)               /* (OTPC_SR) No packet programming is on-going. Position  */
#define OTPC_SR_PGM_1                         (OTPC_SR_PGM_1_Val << OTPC_SR_PGM_Pos)               /* (OTPC_SR) A packet programming is running. Position  */
#define OTPC_SR_LOCK_Pos                      _UINT32_(1)                                          /* (OTPC_SR) Lock On-Going Position */
#define OTPC_SR_LOCK_Msk                      (_UINT32_(0x1) << OTPC_SR_LOCK_Pos)                  /* (OTPC_SR) Lock On-Going Mask */
#define OTPC_SR_LOCK(value)                   (OTPC_SR_LOCK_Msk & (_UINT32_(value) << OTPC_SR_LOCK_Pos)) /* Assigment of value for LOCK in the OTPC_SR register */
#define   OTPC_SR_LOCK_0_Val                  _UINT32_(0x0)                                        /* (OTPC_SR) No packet locking is on-going.  */
#define   OTPC_SR_LOCK_1_Val                  _UINT32_(0x1)                                        /* (OTPC_SR) A packet locking is running.  */
#define OTPC_SR_LOCK_0                        (OTPC_SR_LOCK_0_Val << OTPC_SR_LOCK_Pos)             /* (OTPC_SR) No packet locking is on-going. Position  */
#define OTPC_SR_LOCK_1                        (OTPC_SR_LOCK_1_Val << OTPC_SR_LOCK_Pos)             /* (OTPC_SR) A packet locking is running. Position  */
#define OTPC_SR_INVLD_Pos                     _UINT32_(2)                                          /* (OTPC_SR) Invalidation On-Going Position */
#define OTPC_SR_INVLD_Msk                     (_UINT32_(0x1) << OTPC_SR_INVLD_Pos)                 /* (OTPC_SR) Invalidation On-Going Mask */
#define OTPC_SR_INVLD(value)                  (OTPC_SR_INVLD_Msk & (_UINT32_(value) << OTPC_SR_INVLD_Pos)) /* Assigment of value for INVLD in the OTPC_SR register */
#define   OTPC_SR_INVLD_0_Val                 _UINT32_(0x0)                                        /* (OTPC_SR) No packet invalidation is on-going.  */
#define   OTPC_SR_INVLD_1_Val                 _UINT32_(0x1)                                        /* (OTPC_SR) A packet invalidation is running.  */
#define OTPC_SR_INVLD_0                       (OTPC_SR_INVLD_0_Val << OTPC_SR_INVLD_Pos)           /* (OTPC_SR) No packet invalidation is on-going. Position  */
#define OTPC_SR_INVLD_1                       (OTPC_SR_INVLD_1_Val << OTPC_SR_INVLD_Pos)           /* (OTPC_SR) A packet invalidation is running. Position  */
#define OTPC_SR_EMUL_Pos                      _UINT32_(3)                                          /* (OTPC_SR) Emulation Enabled Position */
#define OTPC_SR_EMUL_Msk                      (_UINT32_(0x1) << OTPC_SR_EMUL_Pos)                  /* (OTPC_SR) Emulation Enabled Mask */
#define OTPC_SR_EMUL(value)                   (OTPC_SR_EMUL_Msk & (_UINT32_(value) << OTPC_SR_EMUL_Pos)) /* Assigment of value for EMUL in the OTPC_SR register */
#define   OTPC_SR_EMUL_0_Val                  _UINT32_(0x0)                                        /* (OTPC_SR) The User area Emulation mode is disabled.  */
#define   OTPC_SR_EMUL_1_Val                  _UINT32_(0x1)                                        /* (OTPC_SR) The User area Emulation mode is enabled.  */
#define OTPC_SR_EMUL_0                        (OTPC_SR_EMUL_0_Val << OTPC_SR_EMUL_Pos)             /* (OTPC_SR) The User area Emulation mode is disabled. Position  */
#define OTPC_SR_EMUL_1                        (OTPC_SR_EMUL_1_Val << OTPC_SR_EMUL_Pos)             /* (OTPC_SR) The User area Emulation mode is enabled. Position  */
#define OTPC_SR_MKBB_Pos                      _UINT32_(4)                                          /* (OTPC_SR) Master Key Bus Busy Position */
#define OTPC_SR_MKBB_Msk                      (_UINT32_(0x1) << OTPC_SR_MKBB_Pos)                  /* (OTPC_SR) Master Key Bus Busy Mask */
#define OTPC_SR_MKBB(value)                   (OTPC_SR_MKBB_Msk & (_UINT32_(value) << OTPC_SR_MKBB_Pos)) /* Assigment of value for MKBB in the OTPC_SR register */
#define   OTPC_SR_MKBB_0_Val                  _UINT32_(0x0)                                        /* (OTPC_SR) The Master Key bus is not busy.  */
#define   OTPC_SR_MKBB_1_Val                  _UINT32_(0x1)                                        /* (OTPC_SR) The Master Key bus is busy.  */
#define OTPC_SR_MKBB_0                        (OTPC_SR_MKBB_0_Val << OTPC_SR_MKBB_Pos)             /* (OTPC_SR) The Master Key bus is not busy. Position  */
#define OTPC_SR_MKBB_1                        (OTPC_SR_MKBB_1_Val << OTPC_SR_MKBB_Pos)             /* (OTPC_SR) The Master Key bus is busy. Position  */
#define OTPC_SR_SKBB_Pos                      _UINT32_(5)                                          /* (OTPC_SR) Slave Key Bus Busy Position */
#define OTPC_SR_SKBB_Msk                      (_UINT32_(0x1) << OTPC_SR_SKBB_Pos)                  /* (OTPC_SR) Slave Key Bus Busy Mask */
#define OTPC_SR_SKBB(value)                   (OTPC_SR_SKBB_Msk & (_UINT32_(value) << OTPC_SR_SKBB_Pos)) /* Assigment of value for SKBB in the OTPC_SR register */
#define   OTPC_SR_SKBB_0_Val                  _UINT32_(0x0)                                        /* (OTPC_SR) The Slave Key bus is not busy.  */
#define   OTPC_SR_SKBB_1_Val                  _UINT32_(0x1)                                        /* (OTPC_SR) The Slave Key bus is busy.  */
#define OTPC_SR_SKBB_0                        (OTPC_SR_SKBB_0_Val << OTPC_SR_SKBB_Pos)             /* (OTPC_SR) The Slave Key bus is not busy. Position  */
#define OTPC_SR_SKBB_1                        (OTPC_SR_SKBB_1_Val << OTPC_SR_SKBB_Pos)             /* (OTPC_SR) The Slave Key bus is busy. Position  */
#define OTPC_SR_READ_Pos                      _UINT32_(6)                                          /* (OTPC_SR) Read On-Going Position */
#define OTPC_SR_READ_Msk                      (_UINT32_(0x1) << OTPC_SR_READ_Pos)                  /* (OTPC_SR) Read On-Going Mask */
#define OTPC_SR_READ(value)                   (OTPC_SR_READ_Msk & (_UINT32_(value) << OTPC_SR_READ_Pos)) /* Assigment of value for READ in the OTPC_SR register */
#define   OTPC_SR_READ_0_Val                  _UINT32_(0x0)                                        /* (OTPC_SR) No packet read is on-going.  */
#define   OTPC_SR_READ_1_Val                  _UINT32_(0x1)                                        /* (OTPC_SR) A packet read is running.  */
#define OTPC_SR_READ_0                        (OTPC_SR_READ_0_Val << OTPC_SR_READ_Pos)             /* (OTPC_SR) No packet read is on-going. Position  */
#define OTPC_SR_READ_1                        (OTPC_SR_READ_1_Val << OTPC_SR_READ_Pos)             /* (OTPC_SR) A packet read is running. Position  */
#define OTPC_SR_FLUSH_Pos                     _UINT32_(7)                                          /* (OTPC_SR) Flush On-Going Position */
#define OTPC_SR_FLUSH_Msk                     (_UINT32_(0x1) << OTPC_SR_FLUSH_Pos)                 /* (OTPC_SR) Flush On-Going Mask */
#define OTPC_SR_FLUSH(value)                  (OTPC_SR_FLUSH_Msk & (_UINT32_(value) << OTPC_SR_FLUSH_Pos)) /* Assigment of value for FLUSH in the OTPC_SR register */
#define   OTPC_SR_FLUSH_0_Val                 _UINT32_(0x0)                                        /* (OTPC_SR) The temporary registers are not flushed.  */
#define   OTPC_SR_FLUSH_1_Val                 _UINT32_(0x1)                                        /* (OTPC_SR) The temporary registers are being flushed.  */
#define OTPC_SR_FLUSH_0                       (OTPC_SR_FLUSH_0_Val << OTPC_SR_FLUSH_Pos)           /* (OTPC_SR) The temporary registers are not flushed. Position  */
#define OTPC_SR_FLUSH_1                       (OTPC_SR_FLUSH_1_Val << OTPC_SR_FLUSH_Pos)           /* (OTPC_SR) The temporary registers are being flushed. Position  */
#define OTPC_SR_HIDE_Pos                      _UINT32_(8)                                          /* (OTPC_SR) Hiding On-Going Position */
#define OTPC_SR_HIDE_Msk                      (_UINT32_(0x1) << OTPC_SR_HIDE_Pos)                  /* (OTPC_SR) Hiding On-Going Mask */
#define OTPC_SR_HIDE(value)                   (OTPC_SR_HIDE_Msk & (_UINT32_(value) << OTPC_SR_HIDE_Pos)) /* Assigment of value for HIDE in the OTPC_SR register */
#define   OTPC_SR_HIDE_0_Val                  _UINT32_(0x0)                                        /* (OTPC_SR) No packet hiding is on-going.  */
#define   OTPC_SR_HIDE_1_Val                  _UINT32_(0x1)                                        /* (OTPC_SR) A packet hiding is on-going.  */
#define OTPC_SR_HIDE_0                        (OTPC_SR_HIDE_0_Val << OTPC_SR_HIDE_Pos)             /* (OTPC_SR) No packet hiding is on-going. Position  */
#define OTPC_SR_HIDE_1                        (OTPC_SR_HIDE_1_Val << OTPC_SR_HIDE_Pos)             /* (OTPC_SR) A packet hiding is on-going. Position  */
#define OTPC_SR_ONEF_Pos                      _UINT32_(9)                                          /* (OTPC_SR) One Found Position */
#define OTPC_SR_ONEF_Msk                      (_UINT32_(0x1) << OTPC_SR_ONEF_Pos)                  /* (OTPC_SR) One Found Mask */
#define OTPC_SR_ONEF(value)                   (OTPC_SR_ONEF_Msk & (_UINT32_(value) << OTPC_SR_ONEF_Pos)) /* Assigment of value for ONEF in the OTPC_SR register */
#define   OTPC_SR_ONEF_0_Val                  _UINT32_(0x0)                                        /* (OTPC_SR) No bit at '1' found during the last packet read.  */
#define   OTPC_SR_ONEF_1_Val                  _UINT32_(0x1)                                        /* (OTPC_SR) At least one '1' has been found during the last packet read.  */
#define OTPC_SR_ONEF_0                        (OTPC_SR_ONEF_0_Val << OTPC_SR_ONEF_Pos)             /* (OTPC_SR) No bit at '1' found during the last packet read. Position  */
#define OTPC_SR_ONEF_1                        (OTPC_SR_ONEF_1_Val << OTPC_SR_ONEF_Pos)             /* (OTPC_SR) At least one '1' has been found during the last packet read. Position  */
#define OTPC_SR_MNT_Pos                       _UINT32_(15)                                         /* (OTPC_SR) Maintenance On-Going Position */
#define OTPC_SR_MNT_Msk                       (_UINT32_(0x1) << OTPC_SR_MNT_Pos)                   /* (OTPC_SR) Maintenance On-Going Mask */
#define OTPC_SR_MNT(value)                    (OTPC_SR_MNT_Msk & (_UINT32_(value) << OTPC_SR_MNT_Pos)) /* Assigment of value for MNT in the OTPC_SR register */
#define   OTPC_SR_MNT_0_Val                   _UINT32_(0x0)                                        /* (OTPC_SR) The OTP live repair is not running.  */
#define   OTPC_SR_MNT_1_Val                   _UINT32_(0x1)                                        /* (OTPC_SR) The OTP live repair is running, OTP maintenance is running.  */
#define OTPC_SR_MNT_0                         (OTPC_SR_MNT_0_Val << OTPC_SR_MNT_Pos)               /* (OTPC_SR) The OTP live repair is not running. Position  */
#define OTPC_SR_MNT_1                         (OTPC_SR_MNT_1_Val << OTPC_SR_MNT_Pos)               /* (OTPC_SR) The OTP live repair is running, OTP maintenance is running. Position  */
#define OTPC_SR_Msk                           _UINT32_(0x000083FF)                                 /* (OTPC_SR) Register Mask  */


/* -------- OTPC_IER : (OTPC Offset: 0x10) ( /W 32) Interrupt Enable Register -------- */
#define OTPC_IER_EOP_Pos                      _UINT32_(0)                                          /* (OTPC_IER) End Of Programming Interrupt Enable Position */
#define OTPC_IER_EOP_Msk                      (_UINT32_(0x1) << OTPC_IER_EOP_Pos)                  /* (OTPC_IER) End Of Programming Interrupt Enable Mask */
#define OTPC_IER_EOP(value)                   (OTPC_IER_EOP_Msk & (_UINT32_(value) << OTPC_IER_EOP_Pos)) /* Assigment of value for EOP in the OTPC_IER register */
#define OTPC_IER_EOL_Pos                      _UINT32_(1)                                          /* (OTPC_IER) End Of Locking Interrupt Enable Position */
#define OTPC_IER_EOL_Msk                      (_UINT32_(0x1) << OTPC_IER_EOL_Pos)                  /* (OTPC_IER) End Of Locking Interrupt Enable Mask */
#define OTPC_IER_EOL(value)                   (OTPC_IER_EOL_Msk & (_UINT32_(value) << OTPC_IER_EOL_Pos)) /* Assigment of value for EOL in the OTPC_IER register */
#define OTPC_IER_EOI_Pos                      _UINT32_(2)                                          /* (OTPC_IER) End Of Invalidation Interrupt Enable Position */
#define OTPC_IER_EOI_Msk                      (_UINT32_(0x1) << OTPC_IER_EOI_Pos)                  /* (OTPC_IER) End Of Invalidation Interrupt Enable Mask */
#define OTPC_IER_EOI(value)                   (OTPC_IER_EOI_Msk & (_UINT32_(value) << OTPC_IER_EOI_Pos)) /* Assigment of value for EOI in the OTPC_IER register */
#define OTPC_IER_EOKT_Pos                     _UINT32_(3)                                          /* (OTPC_IER) End Of Key Transfer Interrupt Enable Position */
#define OTPC_IER_EOKT_Msk                     (_UINT32_(0x1) << OTPC_IER_EOKT_Pos)                 /* (OTPC_IER) End Of Key Transfer Interrupt Enable Mask */
#define OTPC_IER_EOKT(value)                  (OTPC_IER_EOKT_Msk & (_UINT32_(value) << OTPC_IER_EOKT_Pos)) /* Assigment of value for EOKT in the OTPC_IER register */
#define OTPC_IER_PGERR_Pos                    _UINT32_(4)                                          /* (OTPC_IER) Programming Error Interrupt Enable Position */
#define OTPC_IER_PGERR_Msk                    (_UINT32_(0x1) << OTPC_IER_PGERR_Pos)                /* (OTPC_IER) Programming Error Interrupt Enable Mask */
#define OTPC_IER_PGERR(value)                 (OTPC_IER_PGERR_Msk & (_UINT32_(value) << OTPC_IER_PGERR_Pos)) /* Assigment of value for PGERR in the OTPC_IER register */
#define OTPC_IER_LKERR_Pos                    _UINT32_(5)                                          /* (OTPC_IER) Locking Error Interrupt Enable Position */
#define OTPC_IER_LKERR_Msk                    (_UINT32_(0x1) << OTPC_IER_LKERR_Pos)                /* (OTPC_IER) Locking Error Interrupt Enable Mask */
#define OTPC_IER_LKERR(value)                 (OTPC_IER_LKERR_Msk & (_UINT32_(value) << OTPC_IER_LKERR_Pos)) /* Assigment of value for LKERR in the OTPC_IER register */
#define OTPC_IER_IVERR_Pos                    _UINT32_(6)                                          /* (OTPC_IER) Invalidation Error Interrupt Enable Position */
#define OTPC_IER_IVERR_Msk                    (_UINT32_(0x1) << OTPC_IER_IVERR_Pos)                /* (OTPC_IER) Invalidation Error Interrupt Enable Mask */
#define OTPC_IER_IVERR(value)                 (OTPC_IER_IVERR_Msk & (_UINT32_(value) << OTPC_IER_IVERR_Pos)) /* Assigment of value for IVERR in the OTPC_IER register */
#define OTPC_IER_WERR_Pos                     _UINT32_(7)                                          /* (OTPC_IER) Write Error Interrupt Enable Position */
#define OTPC_IER_WERR_Msk                     (_UINT32_(0x1) << OTPC_IER_WERR_Pos)                 /* (OTPC_IER) Write Error Interrupt Enable Mask */
#define OTPC_IER_WERR(value)                  (OTPC_IER_WERR_Msk & (_UINT32_(value) << OTPC_IER_WERR_Pos)) /* Assigment of value for WERR in the OTPC_IER register */
#define OTPC_IER_EOR_Pos                      _UINT32_(8)                                          /* (OTPC_IER) End Of Read Interrupt Enable Position */
#define OTPC_IER_EOR_Msk                      (_UINT32_(0x1) << OTPC_IER_EOR_Pos)                  /* (OTPC_IER) End Of Read Interrupt Enable Mask */
#define OTPC_IER_EOR(value)                   (OTPC_IER_EOR_Msk & (_UINT32_(value) << OTPC_IER_EOR_Pos)) /* Assigment of value for EOR in the OTPC_IER register */
#define OTPC_IER_EOF_Pos                      _UINT32_(9)                                          /* (OTPC_IER) End Of Flush Interrupt Enable Position */
#define OTPC_IER_EOF_Msk                      (_UINT32_(0x1) << OTPC_IER_EOF_Pos)                  /* (OTPC_IER) End Of Flush Interrupt Enable Mask */
#define OTPC_IER_EOF(value)                   (OTPC_IER_EOF_Msk & (_UINT32_(value) << OTPC_IER_EOF_Pos)) /* Assigment of value for EOF in the OTPC_IER register */
#define OTPC_IER_EOH_Pos                      _UINT32_(10)                                         /* (OTPC_IER) End Of Hide Interrupt Enable Position */
#define OTPC_IER_EOH_Msk                      (_UINT32_(0x1) << OTPC_IER_EOH_Pos)                  /* (OTPC_IER) End Of Hide Interrupt Enable Mask */
#define OTPC_IER_EOH(value)                   (OTPC_IER_EOH_Msk & (_UINT32_(value) << OTPC_IER_EOH_Pos)) /* Assigment of value for EOH in the OTPC_IER register */
#define OTPC_IER_EORF_Pos                     _UINT32_(11)                                         /* (OTPC_IER) End Of Refresh Interrupt Enable Position */
#define OTPC_IER_EORF_Msk                     (_UINT32_(0x1) << OTPC_IER_EORF_Pos)                 /* (OTPC_IER) End Of Refresh Interrupt Enable Mask */
#define OTPC_IER_EORF(value)                  (OTPC_IER_EORF_Msk & (_UINT32_(value) << OTPC_IER_EORF_Pos)) /* Assigment of value for EORF in the OTPC_IER register */
#define OTPC_IER_CKERR_Pos                    _UINT32_(12)                                         /* (OTPC_IER) Checksum Check Error Interrupt Enable Position */
#define OTPC_IER_CKERR_Msk                    (_UINT32_(0x1) << OTPC_IER_CKERR_Pos)                /* (OTPC_IER) Checksum Check Error Interrupt Enable Mask */
#define OTPC_IER_CKERR(value)                 (OTPC_IER_CKERR_Msk & (_UINT32_(value) << OTPC_IER_CKERR_Pos)) /* Assigment of value for CKERR in the OTPC_IER register */
#define OTPC_IER_COERR_Pos                    _UINT32_(13)                                         /* (OTPC_IER) Corruption Error Interrupt Enable Position */
#define OTPC_IER_COERR_Msk                    (_UINT32_(0x1) << OTPC_IER_COERR_Pos)                /* (OTPC_IER) Corruption Error Interrupt Enable Mask */
#define OTPC_IER_COERR(value)                 (OTPC_IER_COERR_Msk & (_UINT32_(value) << OTPC_IER_COERR_Pos)) /* Assigment of value for COERR in the OTPC_IER register */
#define OTPC_IER_HDERR_Pos                    _UINT32_(14)                                         /* (OTPC_IER) Hide Error Interrupt Enable Position */
#define OTPC_IER_HDERR_Msk                    (_UINT32_(0x1) << OTPC_IER_HDERR_Pos)                /* (OTPC_IER) Hide Error Interrupt Enable Mask */
#define OTPC_IER_HDERR(value)                 (OTPC_IER_HDERR_Msk & (_UINT32_(value) << OTPC_IER_HDERR_Pos)) /* Assigment of value for HDERR in the OTPC_IER register */
#define OTPC_IER_KBERR_Pos                    _UINT32_(16)                                         /* (OTPC_IER) Key Bus Error Interrupt Enable Position */
#define OTPC_IER_KBERR_Msk                    (_UINT32_(0x1) << OTPC_IER_KBERR_Pos)                /* (OTPC_IER) Key Bus Error Interrupt Enable Mask */
#define OTPC_IER_KBERR(value)                 (OTPC_IER_KBERR_Msk & (_UINT32_(value) << OTPC_IER_KBERR_Pos)) /* Assigment of value for KBERR in the OTPC_IER register */
#define OTPC_IER_SECE_Pos                     _UINT32_(28)                                         /* (OTPC_IER) Security and/or Safety Event Interrupt Enable Position */
#define OTPC_IER_SECE_Msk                     (_UINT32_(0x1) << OTPC_IER_SECE_Pos)                 /* (OTPC_IER) Security and/or Safety Event Interrupt Enable Mask */
#define OTPC_IER_SECE(value)                  (OTPC_IER_SECE_Msk & (_UINT32_(value) << OTPC_IER_SECE_Pos)) /* Assigment of value for SECE in the OTPC_IER register */
#define OTPC_IER_Msk                          _UINT32_(0x10017FFF)                                 /* (OTPC_IER) Register Mask  */


/* -------- OTPC_IDR : (OTPC Offset: 0x14) ( /W 32) Interrupt Disable Register -------- */
#define OTPC_IDR_EOP_Pos                      _UINT32_(0)                                          /* (OTPC_IDR) End Of Programming Interrupt Disable Position */
#define OTPC_IDR_EOP_Msk                      (_UINT32_(0x1) << OTPC_IDR_EOP_Pos)                  /* (OTPC_IDR) End Of Programming Interrupt Disable Mask */
#define OTPC_IDR_EOP(value)                   (OTPC_IDR_EOP_Msk & (_UINT32_(value) << OTPC_IDR_EOP_Pos)) /* Assigment of value for EOP in the OTPC_IDR register */
#define OTPC_IDR_EOL_Pos                      _UINT32_(1)                                          /* (OTPC_IDR) End Of Locking Interrupt Disable Position */
#define OTPC_IDR_EOL_Msk                      (_UINT32_(0x1) << OTPC_IDR_EOL_Pos)                  /* (OTPC_IDR) End Of Locking Interrupt Disable Mask */
#define OTPC_IDR_EOL(value)                   (OTPC_IDR_EOL_Msk & (_UINT32_(value) << OTPC_IDR_EOL_Pos)) /* Assigment of value for EOL in the OTPC_IDR register */
#define OTPC_IDR_EOI_Pos                      _UINT32_(2)                                          /* (OTPC_IDR) End Of Invalidation Interrupt Disable Position */
#define OTPC_IDR_EOI_Msk                      (_UINT32_(0x1) << OTPC_IDR_EOI_Pos)                  /* (OTPC_IDR) End Of Invalidation Interrupt Disable Mask */
#define OTPC_IDR_EOI(value)                   (OTPC_IDR_EOI_Msk & (_UINT32_(value) << OTPC_IDR_EOI_Pos)) /* Assigment of value for EOI in the OTPC_IDR register */
#define OTPC_IDR_EOKT_Pos                     _UINT32_(3)                                          /* (OTPC_IDR) End Of Key Transfer Interrupt Disable Position */
#define OTPC_IDR_EOKT_Msk                     (_UINT32_(0x1) << OTPC_IDR_EOKT_Pos)                 /* (OTPC_IDR) End Of Key Transfer Interrupt Disable Mask */
#define OTPC_IDR_EOKT(value)                  (OTPC_IDR_EOKT_Msk & (_UINT32_(value) << OTPC_IDR_EOKT_Pos)) /* Assigment of value for EOKT in the OTPC_IDR register */
#define OTPC_IDR_PGERR_Pos                    _UINT32_(4)                                          /* (OTPC_IDR) Programming Error Interrupt Disable Position */
#define OTPC_IDR_PGERR_Msk                    (_UINT32_(0x1) << OTPC_IDR_PGERR_Pos)                /* (OTPC_IDR) Programming Error Interrupt Disable Mask */
#define OTPC_IDR_PGERR(value)                 (OTPC_IDR_PGERR_Msk & (_UINT32_(value) << OTPC_IDR_PGERR_Pos)) /* Assigment of value for PGERR in the OTPC_IDR register */
#define OTPC_IDR_LKERR_Pos                    _UINT32_(5)                                          /* (OTPC_IDR) Locking Error Interrupt Disable Position */
#define OTPC_IDR_LKERR_Msk                    (_UINT32_(0x1) << OTPC_IDR_LKERR_Pos)                /* (OTPC_IDR) Locking Error Interrupt Disable Mask */
#define OTPC_IDR_LKERR(value)                 (OTPC_IDR_LKERR_Msk & (_UINT32_(value) << OTPC_IDR_LKERR_Pos)) /* Assigment of value for LKERR in the OTPC_IDR register */
#define OTPC_IDR_IVERR_Pos                    _UINT32_(6)                                          /* (OTPC_IDR) Invalidation Error Interrupt Disable Position */
#define OTPC_IDR_IVERR_Msk                    (_UINT32_(0x1) << OTPC_IDR_IVERR_Pos)                /* (OTPC_IDR) Invalidation Error Interrupt Disable Mask */
#define OTPC_IDR_IVERR(value)                 (OTPC_IDR_IVERR_Msk & (_UINT32_(value) << OTPC_IDR_IVERR_Pos)) /* Assigment of value for IVERR in the OTPC_IDR register */
#define OTPC_IDR_WERR_Pos                     _UINT32_(7)                                          /* (OTPC_IDR) Write Error Interrupt Disable Position */
#define OTPC_IDR_WERR_Msk                     (_UINT32_(0x1) << OTPC_IDR_WERR_Pos)                 /* (OTPC_IDR) Write Error Interrupt Disable Mask */
#define OTPC_IDR_WERR(value)                  (OTPC_IDR_WERR_Msk & (_UINT32_(value) << OTPC_IDR_WERR_Pos)) /* Assigment of value for WERR in the OTPC_IDR register */
#define OTPC_IDR_EOR_Pos                      _UINT32_(8)                                          /* (OTPC_IDR) End Of Read Interrupt Disable Position */
#define OTPC_IDR_EOR_Msk                      (_UINT32_(0x1) << OTPC_IDR_EOR_Pos)                  /* (OTPC_IDR) End Of Read Interrupt Disable Mask */
#define OTPC_IDR_EOR(value)                   (OTPC_IDR_EOR_Msk & (_UINT32_(value) << OTPC_IDR_EOR_Pos)) /* Assigment of value for EOR in the OTPC_IDR register */
#define OTPC_IDR_EOF_Pos                      _UINT32_(9)                                          /* (OTPC_IDR) End Of Flush Interrupt Disable Position */
#define OTPC_IDR_EOF_Msk                      (_UINT32_(0x1) << OTPC_IDR_EOF_Pos)                  /* (OTPC_IDR) End Of Flush Interrupt Disable Mask */
#define OTPC_IDR_EOF(value)                   (OTPC_IDR_EOF_Msk & (_UINT32_(value) << OTPC_IDR_EOF_Pos)) /* Assigment of value for EOF in the OTPC_IDR register */
#define OTPC_IDR_EOH_Pos                      _UINT32_(10)                                         /* (OTPC_IDR) End Of Hide Interrupt Disable Position */
#define OTPC_IDR_EOH_Msk                      (_UINT32_(0x1) << OTPC_IDR_EOH_Pos)                  /* (OTPC_IDR) End Of Hide Interrupt Disable Mask */
#define OTPC_IDR_EOH(value)                   (OTPC_IDR_EOH_Msk & (_UINT32_(value) << OTPC_IDR_EOH_Pos)) /* Assigment of value for EOH in the OTPC_IDR register */
#define OTPC_IDR_EORF_Pos                     _UINT32_(11)                                         /* (OTPC_IDR) End Of Refresh Interrupt Disable Position */
#define OTPC_IDR_EORF_Msk                     (_UINT32_(0x1) << OTPC_IDR_EORF_Pos)                 /* (OTPC_IDR) End Of Refresh Interrupt Disable Mask */
#define OTPC_IDR_EORF(value)                  (OTPC_IDR_EORF_Msk & (_UINT32_(value) << OTPC_IDR_EORF_Pos)) /* Assigment of value for EORF in the OTPC_IDR register */
#define OTPC_IDR_CKERR_Pos                    _UINT32_(12)                                         /* (OTPC_IDR) Checksum Check Error Interrupt Disable Position */
#define OTPC_IDR_CKERR_Msk                    (_UINT32_(0x1) << OTPC_IDR_CKERR_Pos)                /* (OTPC_IDR) Checksum Check Error Interrupt Disable Mask */
#define OTPC_IDR_CKERR(value)                 (OTPC_IDR_CKERR_Msk & (_UINT32_(value) << OTPC_IDR_CKERR_Pos)) /* Assigment of value for CKERR in the OTPC_IDR register */
#define OTPC_IDR_COERR_Pos                    _UINT32_(13)                                         /* (OTPC_IDR) Corruption Error Interrupt Disable Position */
#define OTPC_IDR_COERR_Msk                    (_UINT32_(0x1) << OTPC_IDR_COERR_Pos)                /* (OTPC_IDR) Corruption Error Interrupt Disable Mask */
#define OTPC_IDR_COERR(value)                 (OTPC_IDR_COERR_Msk & (_UINT32_(value) << OTPC_IDR_COERR_Pos)) /* Assigment of value for COERR in the OTPC_IDR register */
#define OTPC_IDR_HDERR_Pos                    _UINT32_(14)                                         /* (OTPC_IDR) Hide Error Interrupt Disable Position */
#define OTPC_IDR_HDERR_Msk                    (_UINT32_(0x1) << OTPC_IDR_HDERR_Pos)                /* (OTPC_IDR) Hide Error Interrupt Disable Mask */
#define OTPC_IDR_HDERR(value)                 (OTPC_IDR_HDERR_Msk & (_UINT32_(value) << OTPC_IDR_HDERR_Pos)) /* Assigment of value for HDERR in the OTPC_IDR register */
#define OTPC_IDR_KBERR_Pos                    _UINT32_(16)                                         /* (OTPC_IDR) Key Bus Error Interrupt Disable Position */
#define OTPC_IDR_KBERR_Msk                    (_UINT32_(0x1) << OTPC_IDR_KBERR_Pos)                /* (OTPC_IDR) Key Bus Error Interrupt Disable Mask */
#define OTPC_IDR_KBERR(value)                 (OTPC_IDR_KBERR_Msk & (_UINT32_(value) << OTPC_IDR_KBERR_Pos)) /* Assigment of value for KBERR in the OTPC_IDR register */
#define OTPC_IDR_SECE_Pos                     _UINT32_(28)                                         /* (OTPC_IDR) Security and/or Safety Event Interrupt Disable Position */
#define OTPC_IDR_SECE_Msk                     (_UINT32_(0x1) << OTPC_IDR_SECE_Pos)                 /* (OTPC_IDR) Security and/or Safety Event Interrupt Disable Mask */
#define OTPC_IDR_SECE(value)                  (OTPC_IDR_SECE_Msk & (_UINT32_(value) << OTPC_IDR_SECE_Pos)) /* Assigment of value for SECE in the OTPC_IDR register */
#define OTPC_IDR_Msk                          _UINT32_(0x10017FFF)                                 /* (OTPC_IDR) Register Mask  */


/* -------- OTPC_IMR : (OTPC Offset: 0x18) ( R/ 32) Interrupt Mask Register -------- */
#define OTPC_IMR_RESETVALUE                   _UINT32_(0x00)                                       /*  (OTPC_IMR) Interrupt Mask Register  Reset Value */

#define OTPC_IMR_EOP_Pos                      _UINT32_(0)                                          /* (OTPC_IMR) End Of Programming Interrupt Mask Position */
#define OTPC_IMR_EOP_Msk                      (_UINT32_(0x1) << OTPC_IMR_EOP_Pos)                  /* (OTPC_IMR) End Of Programming Interrupt Mask Mask */
#define OTPC_IMR_EOP(value)                   (OTPC_IMR_EOP_Msk & (_UINT32_(value) << OTPC_IMR_EOP_Pos)) /* Assigment of value for EOP in the OTPC_IMR register */
#define OTPC_IMR_EOL_Pos                      _UINT32_(1)                                          /* (OTPC_IMR) End Of Locking Interrupt Mask Position */
#define OTPC_IMR_EOL_Msk                      (_UINT32_(0x1) << OTPC_IMR_EOL_Pos)                  /* (OTPC_IMR) End Of Locking Interrupt Mask Mask */
#define OTPC_IMR_EOL(value)                   (OTPC_IMR_EOL_Msk & (_UINT32_(value) << OTPC_IMR_EOL_Pos)) /* Assigment of value for EOL in the OTPC_IMR register */
#define OTPC_IMR_EOI_Pos                      _UINT32_(2)                                          /* (OTPC_IMR) End Of Invalidation Interrupt Mask Position */
#define OTPC_IMR_EOI_Msk                      (_UINT32_(0x1) << OTPC_IMR_EOI_Pos)                  /* (OTPC_IMR) End Of Invalidation Interrupt Mask Mask */
#define OTPC_IMR_EOI(value)                   (OTPC_IMR_EOI_Msk & (_UINT32_(value) << OTPC_IMR_EOI_Pos)) /* Assigment of value for EOI in the OTPC_IMR register */
#define OTPC_IMR_EOKT_Pos                     _UINT32_(3)                                          /* (OTPC_IMR) End Of Key Transfer Interrupt Mask Position */
#define OTPC_IMR_EOKT_Msk                     (_UINT32_(0x1) << OTPC_IMR_EOKT_Pos)                 /* (OTPC_IMR) End Of Key Transfer Interrupt Mask Mask */
#define OTPC_IMR_EOKT(value)                  (OTPC_IMR_EOKT_Msk & (_UINT32_(value) << OTPC_IMR_EOKT_Pos)) /* Assigment of value for EOKT in the OTPC_IMR register */
#define OTPC_IMR_PGERR_Pos                    _UINT32_(4)                                          /* (OTPC_IMR) Programming Error Interrupt Mask Position */
#define OTPC_IMR_PGERR_Msk                    (_UINT32_(0x1) << OTPC_IMR_PGERR_Pos)                /* (OTPC_IMR) Programming Error Interrupt Mask Mask */
#define OTPC_IMR_PGERR(value)                 (OTPC_IMR_PGERR_Msk & (_UINT32_(value) << OTPC_IMR_PGERR_Pos)) /* Assigment of value for PGERR in the OTPC_IMR register */
#define OTPC_IMR_LKERR_Pos                    _UINT32_(5)                                          /* (OTPC_IMR) Locking Error Interrupt Mask Position */
#define OTPC_IMR_LKERR_Msk                    (_UINT32_(0x1) << OTPC_IMR_LKERR_Pos)                /* (OTPC_IMR) Locking Error Interrupt Mask Mask */
#define OTPC_IMR_LKERR(value)                 (OTPC_IMR_LKERR_Msk & (_UINT32_(value) << OTPC_IMR_LKERR_Pos)) /* Assigment of value for LKERR in the OTPC_IMR register */
#define OTPC_IMR_IVERR_Pos                    _UINT32_(6)                                          /* (OTPC_IMR) Invalidation Error Interrupt Mask Position */
#define OTPC_IMR_IVERR_Msk                    (_UINT32_(0x1) << OTPC_IMR_IVERR_Pos)                /* (OTPC_IMR) Invalidation Error Interrupt Mask Mask */
#define OTPC_IMR_IVERR(value)                 (OTPC_IMR_IVERR_Msk & (_UINT32_(value) << OTPC_IMR_IVERR_Pos)) /* Assigment of value for IVERR in the OTPC_IMR register */
#define OTPC_IMR_WERR_Pos                     _UINT32_(7)                                          /* (OTPC_IMR) Write Error Interrupt Mask Position */
#define OTPC_IMR_WERR_Msk                     (_UINT32_(0x1) << OTPC_IMR_WERR_Pos)                 /* (OTPC_IMR) Write Error Interrupt Mask Mask */
#define OTPC_IMR_WERR(value)                  (OTPC_IMR_WERR_Msk & (_UINT32_(value) << OTPC_IMR_WERR_Pos)) /* Assigment of value for WERR in the OTPC_IMR register */
#define OTPC_IMR_EOR_Pos                      _UINT32_(8)                                          /* (OTPC_IMR) End Of Read Interrupt Mask Position */
#define OTPC_IMR_EOR_Msk                      (_UINT32_(0x1) << OTPC_IMR_EOR_Pos)                  /* (OTPC_IMR) End Of Read Interrupt Mask Mask */
#define OTPC_IMR_EOR(value)                   (OTPC_IMR_EOR_Msk & (_UINT32_(value) << OTPC_IMR_EOR_Pos)) /* Assigment of value for EOR in the OTPC_IMR register */
#define OTPC_IMR_EOF_Pos                      _UINT32_(9)                                          /* (OTPC_IMR) End Of Flush Interrupt Mask Position */
#define OTPC_IMR_EOF_Msk                      (_UINT32_(0x1) << OTPC_IMR_EOF_Pos)                  /* (OTPC_IMR) End Of Flush Interrupt Mask Mask */
#define OTPC_IMR_EOF(value)                   (OTPC_IMR_EOF_Msk & (_UINT32_(value) << OTPC_IMR_EOF_Pos)) /* Assigment of value for EOF in the OTPC_IMR register */
#define OTPC_IMR_EOH_Pos                      _UINT32_(10)                                         /* (OTPC_IMR) End Of Hide Interrupt Mask Position */
#define OTPC_IMR_EOH_Msk                      (_UINT32_(0x1) << OTPC_IMR_EOH_Pos)                  /* (OTPC_IMR) End Of Hide Interrupt Mask Mask */
#define OTPC_IMR_EOH(value)                   (OTPC_IMR_EOH_Msk & (_UINT32_(value) << OTPC_IMR_EOH_Pos)) /* Assigment of value for EOH in the OTPC_IMR register */
#define OTPC_IMR_EORF_Pos                     _UINT32_(11)                                         /* (OTPC_IMR) End Of Refresh Interrupt Mask Position */
#define OTPC_IMR_EORF_Msk                     (_UINT32_(0x1) << OTPC_IMR_EORF_Pos)                 /* (OTPC_IMR) End Of Refresh Interrupt Mask Mask */
#define OTPC_IMR_EORF(value)                  (OTPC_IMR_EORF_Msk & (_UINT32_(value) << OTPC_IMR_EORF_Pos)) /* Assigment of value for EORF in the OTPC_IMR register */
#define OTPC_IMR_CKERR_Pos                    _UINT32_(12)                                         /* (OTPC_IMR) Checksum Check Error Interrupt Mask Position */
#define OTPC_IMR_CKERR_Msk                    (_UINT32_(0x1) << OTPC_IMR_CKERR_Pos)                /* (OTPC_IMR) Checksum Check Error Interrupt Mask Mask */
#define OTPC_IMR_CKERR(value)                 (OTPC_IMR_CKERR_Msk & (_UINT32_(value) << OTPC_IMR_CKERR_Pos)) /* Assigment of value for CKERR in the OTPC_IMR register */
#define OTPC_IMR_COERR_Pos                    _UINT32_(13)                                         /* (OTPC_IMR) Corruption Error Interrupt Mask Position */
#define OTPC_IMR_COERR_Msk                    (_UINT32_(0x1) << OTPC_IMR_COERR_Pos)                /* (OTPC_IMR) Corruption Error Interrupt Mask Mask */
#define OTPC_IMR_COERR(value)                 (OTPC_IMR_COERR_Msk & (_UINT32_(value) << OTPC_IMR_COERR_Pos)) /* Assigment of value for COERR in the OTPC_IMR register */
#define OTPC_IMR_HDERR_Pos                    _UINT32_(14)                                         /* (OTPC_IMR) Hide Error Interrupt Mask Position */
#define OTPC_IMR_HDERR_Msk                    (_UINT32_(0x1) << OTPC_IMR_HDERR_Pos)                /* (OTPC_IMR) Hide Error Interrupt Mask Mask */
#define OTPC_IMR_HDERR(value)                 (OTPC_IMR_HDERR_Msk & (_UINT32_(value) << OTPC_IMR_HDERR_Pos)) /* Assigment of value for HDERR in the OTPC_IMR register */
#define OTPC_IMR_KBERR_Pos                    _UINT32_(16)                                         /* (OTPC_IMR) Key Bus Error Interrupt Mask Position */
#define OTPC_IMR_KBERR_Msk                    (_UINT32_(0x1) << OTPC_IMR_KBERR_Pos)                /* (OTPC_IMR) Key Bus Error Interrupt Mask Mask */
#define OTPC_IMR_KBERR(value)                 (OTPC_IMR_KBERR_Msk & (_UINT32_(value) << OTPC_IMR_KBERR_Pos)) /* Assigment of value for KBERR in the OTPC_IMR register */
#define OTPC_IMR_SECE_Pos                     _UINT32_(28)                                         /* (OTPC_IMR) Security and/or Safety Event Interrupt Mask Position */
#define OTPC_IMR_SECE_Msk                     (_UINT32_(0x1) << OTPC_IMR_SECE_Pos)                 /* (OTPC_IMR) Security and/or Safety Event Interrupt Mask Mask */
#define OTPC_IMR_SECE(value)                  (OTPC_IMR_SECE_Msk & (_UINT32_(value) << OTPC_IMR_SECE_Pos)) /* Assigment of value for SECE in the OTPC_IMR register */
#define OTPC_IMR_Msk                          _UINT32_(0x10017FFF)                                 /* (OTPC_IMR) Register Mask  */


/* -------- OTPC_ISR : (OTPC Offset: 0x1C) ( R/ 32) Interrupt Status Register -------- */
#define OTPC_ISR_RESETVALUE                   _UINT32_(0x00)                                       /*  (OTPC_ISR) Interrupt Status Register  Reset Value */

#define OTPC_ISR_EOP_Pos                      _UINT32_(0)                                          /* (OTPC_ISR) End Of Programming (cleared on read) Position */
#define OTPC_ISR_EOP_Msk                      (_UINT32_(0x1) << OTPC_ISR_EOP_Pos)                  /* (OTPC_ISR) End Of Programming (cleared on read) Mask */
#define OTPC_ISR_EOP(value)                   (OTPC_ISR_EOP_Msk & (_UINT32_(value) << OTPC_ISR_EOP_Pos)) /* Assigment of value for EOP in the OTPC_ISR register */
#define   OTPC_ISR_EOP_0_Val                  _UINT32_(0x0)                                        /* (OTPC_ISR) No programming sequence completion since the last read of OTPC_ISR.  */
#define   OTPC_ISR_EOP_1_Val                  _UINT32_(0x1)                                        /* (OTPC_ISR) At least one programming sequence completion since the last read of OTPC_ISR.  */
#define OTPC_ISR_EOP_0                        (OTPC_ISR_EOP_0_Val << OTPC_ISR_EOP_Pos)             /* (OTPC_ISR) No programming sequence completion since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_EOP_1                        (OTPC_ISR_EOP_1_Val << OTPC_ISR_EOP_Pos)             /* (OTPC_ISR) At least one programming sequence completion since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_EOL_Pos                      _UINT32_(1)                                          /* (OTPC_ISR) End Of Locking (cleared on read) Position */
#define OTPC_ISR_EOL_Msk                      (_UINT32_(0x1) << OTPC_ISR_EOL_Pos)                  /* (OTPC_ISR) End Of Locking (cleared on read) Mask */
#define OTPC_ISR_EOL(value)                   (OTPC_ISR_EOL_Msk & (_UINT32_(value) << OTPC_ISR_EOL_Pos)) /* Assigment of value for EOL in the OTPC_ISR register */
#define   OTPC_ISR_EOL_0_Val                  _UINT32_(0x0)                                        /* (OTPC_ISR) No locking sequence completion since the last read of OTPC_ISR.  */
#define   OTPC_ISR_EOL_1_Val                  _UINT32_(0x1)                                        /* (OTPC_ISR) At least one locking sequence completion since the last read of OTPC_ISR.  */
#define OTPC_ISR_EOL_0                        (OTPC_ISR_EOL_0_Val << OTPC_ISR_EOL_Pos)             /* (OTPC_ISR) No locking sequence completion since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_EOL_1                        (OTPC_ISR_EOL_1_Val << OTPC_ISR_EOL_Pos)             /* (OTPC_ISR) At least one locking sequence completion since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_EOI_Pos                      _UINT32_(2)                                          /* (OTPC_ISR) End Of Invalidation (cleared on read) Position */
#define OTPC_ISR_EOI_Msk                      (_UINT32_(0x1) << OTPC_ISR_EOI_Pos)                  /* (OTPC_ISR) End Of Invalidation (cleared on read) Mask */
#define OTPC_ISR_EOI(value)                   (OTPC_ISR_EOI_Msk & (_UINT32_(value) << OTPC_ISR_EOI_Pos)) /* Assigment of value for EOI in the OTPC_ISR register */
#define   OTPC_ISR_EOI_0_Val                  _UINT32_(0x0)                                        /* (OTPC_ISR) No invalidation sequence completion since the last read of OTPC_ISR.  */
#define   OTPC_ISR_EOI_1_Val                  _UINT32_(0x1)                                        /* (OTPC_ISR) At least one invalidation sequence completion since the last read of OTPC_ISR.  */
#define OTPC_ISR_EOI_0                        (OTPC_ISR_EOI_0_Val << OTPC_ISR_EOI_Pos)             /* (OTPC_ISR) No invalidation sequence completion since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_EOI_1                        (OTPC_ISR_EOI_1_Val << OTPC_ISR_EOI_Pos)             /* (OTPC_ISR) At least one invalidation sequence completion since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_EOKT_Pos                     _UINT32_(3)                                          /* (OTPC_ISR) End Of Key Transfer (cleared on read) Position */
#define OTPC_ISR_EOKT_Msk                     (_UINT32_(0x1) << OTPC_ISR_EOKT_Pos)                 /* (OTPC_ISR) End Of Key Transfer (cleared on read) Mask */
#define OTPC_ISR_EOKT(value)                  (OTPC_ISR_EOKT_Msk & (_UINT32_(value) << OTPC_ISR_EOKT_Pos)) /* Assigment of value for EOKT in the OTPC_ISR register */
#define   OTPC_ISR_EOKT_0_Val                 _UINT32_(0x0)                                        /* (OTPC_ISR) No key transfer completion since the last read of OTPC_ISR.  */
#define   OTPC_ISR_EOKT_1_Val                 _UINT32_(0x1)                                        /* (OTPC_ISR) At least one key transfer has been completed on the Master Key bus since the last read of OTPC_ISR.  */
#define OTPC_ISR_EOKT_0                       (OTPC_ISR_EOKT_0_Val << OTPC_ISR_EOKT_Pos)           /* (OTPC_ISR) No key transfer completion since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_EOKT_1                       (OTPC_ISR_EOKT_1_Val << OTPC_ISR_EOKT_Pos)           /* (OTPC_ISR) At least one key transfer has been completed on the Master Key bus since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_PGERR_Pos                    _UINT32_(4)                                          /* (OTPC_ISR) Programming Error (cleared on read) Position */
#define OTPC_ISR_PGERR_Msk                    (_UINT32_(0x1) << OTPC_ISR_PGERR_Pos)                /* (OTPC_ISR) Programming Error (cleared on read) Mask */
#define OTPC_ISR_PGERR(value)                 (OTPC_ISR_PGERR_Msk & (_UINT32_(value) << OTPC_ISR_PGERR_Pos)) /* Assigment of value for PGERR in the OTPC_ISR register */
#define   OTPC_ISR_PGERR_0_Val                _UINT32_(0x0)                                        /* (OTPC_ISR) No programming failure occurred during last programming sequence since the last read of OTPC_ISR.  */
#define   OTPC_ISR_PGERR_1_Val                _UINT32_(0x1)                                        /* (OTPC_ISR) A programming failure occurred since the last read of OTPC_ISR.  */
#define OTPC_ISR_PGERR_0                      (OTPC_ISR_PGERR_0_Val << OTPC_ISR_PGERR_Pos)         /* (OTPC_ISR) No programming failure occurred during last programming sequence since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_PGERR_1                      (OTPC_ISR_PGERR_1_Val << OTPC_ISR_PGERR_Pos)         /* (OTPC_ISR) A programming failure occurred since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_LKERR_Pos                    _UINT32_(5)                                          /* (OTPC_ISR) Locking Error (cleared on read) Position */
#define OTPC_ISR_LKERR_Msk                    (_UINT32_(0x1) << OTPC_ISR_LKERR_Pos)                /* (OTPC_ISR) Locking Error (cleared on read) Mask */
#define OTPC_ISR_LKERR(value)                 (OTPC_ISR_LKERR_Msk & (_UINT32_(value) << OTPC_ISR_LKERR_Pos)) /* Assigment of value for LKERR in the OTPC_ISR register */
#define   OTPC_ISR_LKERR_0_Val                _UINT32_(0x0)                                        /* (OTPC_ISR) No locking failure occurred during last locking sequence since the last read of OTPC_ISR.  */
#define   OTPC_ISR_LKERR_1_Val                _UINT32_(0x1)                                        /* (OTPC_ISR) A locking failure occurred since the last read of OTPC_ISR.  */
#define OTPC_ISR_LKERR_0                      (OTPC_ISR_LKERR_0_Val << OTPC_ISR_LKERR_Pos)         /* (OTPC_ISR) No locking failure occurred during last locking sequence since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_LKERR_1                      (OTPC_ISR_LKERR_1_Val << OTPC_ISR_LKERR_Pos)         /* (OTPC_ISR) A locking failure occurred since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_IVERR_Pos                    _UINT32_(6)                                          /* (OTPC_ISR) Invalidation Error (cleared on read) Position */
#define OTPC_ISR_IVERR_Msk                    (_UINT32_(0x1) << OTPC_ISR_IVERR_Pos)                /* (OTPC_ISR) Invalidation Error (cleared on read) Mask */
#define OTPC_ISR_IVERR(value)                 (OTPC_ISR_IVERR_Msk & (_UINT32_(value) << OTPC_ISR_IVERR_Pos)) /* Assigment of value for IVERR in the OTPC_ISR register */
#define   OTPC_ISR_IVERR_0_Val                _UINT32_(0x0)                                        /* (OTPC_ISR) No invalidation failure occurred during last invalidation sequence since the last read of OTPC_ISR.  */
#define   OTPC_ISR_IVERR_1_Val                _UINT32_(0x1)                                        /* (OTPC_ISR) A invalidation failure occurred since the last read of OTPC_ISR.  */
#define OTPC_ISR_IVERR_0                      (OTPC_ISR_IVERR_0_Val << OTPC_ISR_IVERR_Pos)         /* (OTPC_ISR) No invalidation failure occurred during last invalidation sequence since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_IVERR_1                      (OTPC_ISR_IVERR_1_Val << OTPC_ISR_IVERR_Pos)         /* (OTPC_ISR) A invalidation failure occurred since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_WERR_Pos                     _UINT32_(7)                                          /* (OTPC_ISR) Write Error (cleared on read) Position */
#define OTPC_ISR_WERR_Msk                     (_UINT32_(0x1) << OTPC_ISR_WERR_Pos)                 /* (OTPC_ISR) Write Error (cleared on read) Mask */
#define OTPC_ISR_WERR(value)                  (OTPC_ISR_WERR_Msk & (_UINT32_(value) << OTPC_ISR_WERR_Pos)) /* Assigment of value for WERR in the OTPC_ISR register */
#define   OTPC_ISR_WERR_0_Val                 _UINT32_(0x0)                                        /* (OTPC_ISR) No write error occurred since the last read of OTPC_ISR.  */
#define   OTPC_ISR_WERR_1_Val                 _UINT32_(0x1)                                        /* (OTPC_ISR) A write error occurred since the last read of OTPC_ISR.  */
#define OTPC_ISR_WERR_0                       (OTPC_ISR_WERR_0_Val << OTPC_ISR_WERR_Pos)           /* (OTPC_ISR) No write error occurred since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_WERR_1                       (OTPC_ISR_WERR_1_Val << OTPC_ISR_WERR_Pos)           /* (OTPC_ISR) A write error occurred since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_EOR_Pos                      _UINT32_(8)                                          /* (OTPC_ISR) End Of Read (cleared on read) Position */
#define OTPC_ISR_EOR_Msk                      (_UINT32_(0x1) << OTPC_ISR_EOR_Pos)                  /* (OTPC_ISR) End Of Read (cleared on read) Mask */
#define OTPC_ISR_EOR(value)                   (OTPC_ISR_EOR_Msk & (_UINT32_(value) << OTPC_ISR_EOR_Pos)) /* Assigment of value for EOR in the OTPC_ISR register */
#define   OTPC_ISR_EOR_0_Val                  _UINT32_(0x0)                                        /* (OTPC_ISR) No reading sequence completion since the last read of OTPC_ISR.  */
#define   OTPC_ISR_EOR_1_Val                  _UINT32_(0x1)                                        /* (OTPC_ISR) At least one reading sequence completion since the last read of OTPC_ISR.  */
#define OTPC_ISR_EOR_0                        (OTPC_ISR_EOR_0_Val << OTPC_ISR_EOR_Pos)             /* (OTPC_ISR) No reading sequence completion since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_EOR_1                        (OTPC_ISR_EOR_1_Val << OTPC_ISR_EOR_Pos)             /* (OTPC_ISR) At least one reading sequence completion since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_EOF_Pos                      _UINT32_(9)                                          /* (OTPC_ISR) End Of Flush (cleared on read) Position */
#define OTPC_ISR_EOF_Msk                      (_UINT32_(0x1) << OTPC_ISR_EOF_Pos)                  /* (OTPC_ISR) End Of Flush (cleared on read) Mask */
#define OTPC_ISR_EOF(value)                   (OTPC_ISR_EOF_Msk & (_UINT32_(value) << OTPC_ISR_EOF_Pos)) /* Assigment of value for EOF in the OTPC_ISR register */
#define   OTPC_ISR_EOF_0_Val                  _UINT32_(0x0)                                        /* (OTPC_ISR) No flush of the temporary registers since the last read of OTPC_ISR.  */
#define   OTPC_ISR_EOF_1_Val                  _UINT32_(0x1)                                        /* (OTPC_ISR) At least one flush hof the temporary registers has been completed since the last read of OTPC_ISR.  */
#define OTPC_ISR_EOF_0                        (OTPC_ISR_EOF_0_Val << OTPC_ISR_EOF_Pos)             /* (OTPC_ISR) No flush of the temporary registers since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_EOF_1                        (OTPC_ISR_EOF_1_Val << OTPC_ISR_EOF_Pos)             /* (OTPC_ISR) At least one flush hof the temporary registers has been completed since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_EOH_Pos                      _UINT32_(10)                                         /* (OTPC_ISR) End Of Hide (cleared on read) Position */
#define OTPC_ISR_EOH_Msk                      (_UINT32_(0x1) << OTPC_ISR_EOH_Pos)                  /* (OTPC_ISR) End Of Hide (cleared on read) Mask */
#define OTPC_ISR_EOH(value)                   (OTPC_ISR_EOH_Msk & (_UINT32_(value) << OTPC_ISR_EOH_Pos)) /* Assigment of value for EOH in the OTPC_ISR register */
#define   OTPC_ISR_EOH_0_Val                  _UINT32_(0x0)                                        /* (OTPC_ISR) No hiding sequence completion since the last read of OTPC_ISR.  */
#define   OTPC_ISR_EOH_1_Val                  _UINT32_(0x1)                                        /* (OTPC_ISR) At least one hiding sequence completion since the last read of OTPC_ISR.  */
#define OTPC_ISR_EOH_0                        (OTPC_ISR_EOH_0_Val << OTPC_ISR_EOH_Pos)             /* (OTPC_ISR) No hiding sequence completion since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_EOH_1                        (OTPC_ISR_EOH_1_Val << OTPC_ISR_EOH_Pos)             /* (OTPC_ISR) At least one hiding sequence completion since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_EORF_Pos                     _UINT32_(11)                                         /* (OTPC_ISR) End Of Refresh (cleared on read) Position */
#define OTPC_ISR_EORF_Msk                     (_UINT32_(0x1) << OTPC_ISR_EORF_Pos)                 /* (OTPC_ISR) End Of Refresh (cleared on read) Mask */
#define OTPC_ISR_EORF(value)                  (OTPC_ISR_EORF_Msk & (_UINT32_(value) << OTPC_ISR_EORF_Pos)) /* Assigment of value for EORF in the OTPC_ISR register */
#define   OTPC_ISR_EORF_0_Val                 _UINT32_(0x0)                                        /* (OTPC_ISR) No refresh sequence completion since the last read of OTPC_ISR.  */
#define   OTPC_ISR_EORF_1_Val                 _UINT32_(0x1)                                        /* (OTPC_ISR) At least one refresh sequence completion since the last read of OTPC_ISR.  */
#define OTPC_ISR_EORF_0                       (OTPC_ISR_EORF_0_Val << OTPC_ISR_EORF_Pos)           /* (OTPC_ISR) No refresh sequence completion since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_EORF_1                       (OTPC_ISR_EORF_1_Val << OTPC_ISR_EORF_Pos)           /* (OTPC_ISR) At least one refresh sequence completion since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_CKERR_Pos                    _UINT32_(12)                                         /* (OTPC_ISR) Checksum Check Error (cleared on read) Position */
#define OTPC_ISR_CKERR_Msk                    (_UINT32_(0x1) << OTPC_ISR_CKERR_Pos)                /* (OTPC_ISR) Checksum Check Error (cleared on read) Mask */
#define OTPC_ISR_CKERR(value)                 (OTPC_ISR_CKERR_Msk & (_UINT32_(value) << OTPC_ISR_CKERR_Pos)) /* Assigment of value for CKERR in the OTPC_ISR register */
#define   OTPC_ISR_CKERR_0_Val                _UINT32_(0x0)                                        /* (OTPC_ISR) No checksum check failure occurred during last reading sequence since the last read of OTPC_ISR.  */
#define   OTPC_ISR_CKERR_1_Val                _UINT32_(0x1)                                        /* (OTPC_ISR) A checksum check failure occurred since the last read of OTPC_ISR.  */
#define OTPC_ISR_CKERR_0                      (OTPC_ISR_CKERR_0_Val << OTPC_ISR_CKERR_Pos)         /* (OTPC_ISR) No checksum check failure occurred during last reading sequence since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_CKERR_1                      (OTPC_ISR_CKERR_1_Val << OTPC_ISR_CKERR_Pos)         /* (OTPC_ISR) A checksum check failure occurred since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_COERR_Pos                    _UINT32_(13)                                         /* (OTPC_ISR) Corruption Error (cleared on read) Position */
#define OTPC_ISR_COERR_Msk                    (_UINT32_(0x1) << OTPC_ISR_COERR_Pos)                /* (OTPC_ISR) Corruption Error (cleared on read) Mask */
#define OTPC_ISR_COERR(value)                 (OTPC_ISR_COERR_Msk & (_UINT32_(value) << OTPC_ISR_COERR_Pos)) /* Assigment of value for COERR in the OTPC_ISR register */
#define   OTPC_ISR_COERR_0_Val                _UINT32_(0x0)                                        /* (OTPC_ISR) No corruption occurred during the last start-up since the last read of OTPC_ISR.  */
#define   OTPC_ISR_COERR_1_Val                _UINT32_(0x1)                                        /* (OTPC_ISR) A corruption occurred since the last read of OTPC_ISR.  */
#define OTPC_ISR_COERR_0                      (OTPC_ISR_COERR_0_Val << OTPC_ISR_COERR_Pos)         /* (OTPC_ISR) No corruption occurred during the last start-up since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_COERR_1                      (OTPC_ISR_COERR_1_Val << OTPC_ISR_COERR_Pos)         /* (OTPC_ISR) A corruption occurred since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_HDERR_Pos                    _UINT32_(14)                                         /* (OTPC_ISR) Hide Error (cleared on read) Position */
#define OTPC_ISR_HDERR_Msk                    (_UINT32_(0x1) << OTPC_ISR_HDERR_Pos)                /* (OTPC_ISR) Hide Error (cleared on read) Mask */
#define OTPC_ISR_HDERR(value)                 (OTPC_ISR_HDERR_Msk & (_UINT32_(value) << OTPC_ISR_HDERR_Pos)) /* Assigment of value for HDERR in the OTPC_ISR register */
#define   OTPC_ISR_HDERR_0_Val                _UINT32_(0x0)                                        /* (OTPC_ISR) No hiding error occurred since the last read of OTPC_ISR.  */
#define   OTPC_ISR_HDERR_1_Val                _UINT32_(0x1)                                        /* (OTPC_ISR) A hiding error occurred since the last read of OTPC_ISR.  */
#define OTPC_ISR_HDERR_0                      (OTPC_ISR_HDERR_0_Val << OTPC_ISR_HDERR_Pos)         /* (OTPC_ISR) No hiding error occurred since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_HDERR_1                      (OTPC_ISR_HDERR_1_Val << OTPC_ISR_HDERR_Pos)         /* (OTPC_ISR) A hiding error occurred since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_KBERR_Pos                    _UINT32_(16)                                         /* (OTPC_ISR) Key Bus Error (cleared on read) Position */
#define OTPC_ISR_KBERR_Msk                    (_UINT32_(0x1) << OTPC_ISR_KBERR_Pos)                /* (OTPC_ISR) Key Bus Error (cleared on read) Mask */
#define OTPC_ISR_KBERR(value)                 (OTPC_ISR_KBERR_Msk & (_UINT32_(value) << OTPC_ISR_KBERR_Pos)) /* Assigment of value for KBERR in the OTPC_ISR register */
#define   OTPC_ISR_KBERR_0_Val                _UINT32_(0x0)                                        /* (OTPC_ISR) No error happened on the Key bus since the last read of OTPC_ISR.  */
#define   OTPC_ISR_KBERR_1_Val                _UINT32_(0x1)                                        /* (OTPC_ISR) An error happened on the Key bus since the last read of OTPC_ISR.  */
#define OTPC_ISR_KBERR_0                      (OTPC_ISR_KBERR_0_Val << OTPC_ISR_KBERR_Pos)         /* (OTPC_ISR) No error happened on the Key bus since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_KBERR_1                      (OTPC_ISR_KBERR_1_Val << OTPC_ISR_KBERR_Pos)         /* (OTPC_ISR) An error happened on the Key bus since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_SECE_Pos                     _UINT32_(28)                                         /* (OTPC_ISR) Security and/or Safety Event (cleared on read) Position */
#define OTPC_ISR_SECE_Msk                     (_UINT32_(0x1) << OTPC_ISR_SECE_Pos)                 /* (OTPC_ISR) Security and/or Safety Event (cleared on read) Mask */
#define OTPC_ISR_SECE(value)                  (OTPC_ISR_SECE_Msk & (_UINT32_(value) << OTPC_ISR_SECE_Pos)) /* Assigment of value for SECE in the OTPC_ISR register */
#define   OTPC_ISR_SECE_0_Val                 _UINT32_(0x0)                                        /* (OTPC_ISR) No security or safety event occurred since the last read of OTPC_ISR.  */
#define   OTPC_ISR_SECE_1_Val                 _UINT32_(0x1)                                        /* (OTPC_ISR) One or more safety or security event occurred since the last read of OTPC_ISR. For details on the event, refer to OTPC_WPSR.  */
#define OTPC_ISR_SECE_0                       (OTPC_ISR_SECE_0_Val << OTPC_ISR_SECE_Pos)           /* (OTPC_ISR) No security or safety event occurred since the last read of OTPC_ISR. Position  */
#define OTPC_ISR_SECE_1                       (OTPC_ISR_SECE_1_Val << OTPC_ISR_SECE_Pos)           /* (OTPC_ISR) One or more safety or security event occurred since the last read of OTPC_ISR. For details on the event, refer to OTPC_WPSR. Position  */
#define OTPC_ISR_Msk                          _UINT32_(0x10017FFF)                                 /* (OTPC_ISR) Register Mask  */


/* -------- OTPC_HR : (OTPC Offset: 0x20) (R/W 32) Header Register -------- */
#define OTPC_HR_RESETVALUE                    _UINT32_(0x00)                                       /*  (OTPC_HR) Header Register  Reset Value */

#define OTPC_HR_PACKET_Pos                    _UINT32_(0)                                          /* (OTPC_HR) Packet Type Position */
#define OTPC_HR_PACKET_Msk                    (_UINT32_(0x7) << OTPC_HR_PACKET_Pos)                /* (OTPC_HR) Packet Type Mask */
#define OTPC_HR_PACKET(value)                 (OTPC_HR_PACKET_Msk & (_UINT32_(value) << OTPC_HR_PACKET_Pos)) /* Assigment of value for PACKET in the OTPC_HR register */
#define   OTPC_HR_PACKET_REGULAR_Val          _UINT32_(0x1)                                        /* (OTPC_HR) Regular packet accessible through the User Interface  */
#define   OTPC_HR_PACKET_KEY_Val              _UINT32_(0x2)                                        /* (OTPC_HR) Key packet accessible only through the Key Buses  */
#define   OTPC_HR_PACKET_BOOT_CONFIGURATION_Val _UINT32_(0x3)                                        /* (OTPC_HR) Boot Configuration packet  */
#define   OTPC_HR_PACKET_SECURE_BOOT_CONFIGURATION_Val _UINT32_(0x4)                                        /* (OTPC_HR) Secure Boot Configuration packet  */
#define   OTPC_HR_PACKET_HARDWARE_CONFIGURATION_Val _UINT32_(0x5)                                        /* (OTPC_HR) Hardware Configuration packet  */
#define   OTPC_HR_PACKET_CUSTOM_Val           _UINT32_(0x6)                                        /* (OTPC_HR) Custom packet  */
#define OTPC_HR_PACKET_REGULAR                (OTPC_HR_PACKET_REGULAR_Val << OTPC_HR_PACKET_Pos)   /* (OTPC_HR) Regular packet accessible through the User Interface Position  */
#define OTPC_HR_PACKET_KEY                    (OTPC_HR_PACKET_KEY_Val << OTPC_HR_PACKET_Pos)       /* (OTPC_HR) Key packet accessible only through the Key Buses Position  */
#define OTPC_HR_PACKET_BOOT_CONFIGURATION     (OTPC_HR_PACKET_BOOT_CONFIGURATION_Val << OTPC_HR_PACKET_Pos) /* (OTPC_HR) Boot Configuration packet Position  */
#define OTPC_HR_PACKET_SECURE_BOOT_CONFIGURATION (OTPC_HR_PACKET_SECURE_BOOT_CONFIGURATION_Val << OTPC_HR_PACKET_Pos) /* (OTPC_HR) Secure Boot Configuration packet Position  */
#define OTPC_HR_PACKET_HARDWARE_CONFIGURATION (OTPC_HR_PACKET_HARDWARE_CONFIGURATION_Val << OTPC_HR_PACKET_Pos) /* (OTPC_HR) Hardware Configuration packet Position  */
#define OTPC_HR_PACKET_CUSTOM                 (OTPC_HR_PACKET_CUSTOM_Val << OTPC_HR_PACKET_Pos)    /* (OTPC_HR) Custom packet Position  */
#define OTPC_HR_LOCK_Pos                      _UINT32_(3)                                          /* (OTPC_HR) Lock Status Position */
#define OTPC_HR_LOCK_Msk                      (_UINT32_(0x1) << OTPC_HR_LOCK_Pos)                  /* (OTPC_HR) Lock Status Mask */
#define OTPC_HR_LOCK(value)                   (OTPC_HR_LOCK_Msk & (_UINT32_(value) << OTPC_HR_LOCK_Pos)) /* Assigment of value for LOCK in the OTPC_HR register */
#define   OTPC_HR_LOCK_0_Val                  _UINT32_(0x0)                                        /* (OTPC_HR) The packet is not locked.  */
#define   OTPC_HR_LOCK_1_Val                  _UINT32_(0x1)                                        /* (OTPC_HR) The packet is locked.  */
#define OTPC_HR_LOCK_0                        (OTPC_HR_LOCK_0_Val << OTPC_HR_LOCK_Pos)             /* (OTPC_HR) The packet is not locked. Position  */
#define OTPC_HR_LOCK_1                        (OTPC_HR_LOCK_1_Val << OTPC_HR_LOCK_Pos)             /* (OTPC_HR) The packet is locked. Position  */
#define OTPC_HR_INVLD_Pos                     _UINT32_(4)                                          /* (OTPC_HR) Invalid Status Position */
#define OTPC_HR_INVLD_Msk                     (_UINT32_(0x3) << OTPC_HR_INVLD_Pos)                 /* (OTPC_HR) Invalid Status Mask */
#define OTPC_HR_INVLD(value)                  (OTPC_HR_INVLD_Msk & (_UINT32_(value) << OTPC_HR_INVLD_Pos)) /* Assigment of value for INVLD in the OTPC_HR register */
#define OTPC_HR_ONE_Pos                       _UINT32_(7)                                          /* (OTPC_HR) One Position */
#define OTPC_HR_ONE_Msk                       (_UINT32_(0x1) << OTPC_HR_ONE_Pos)                   /* (OTPC_HR) One Mask */
#define OTPC_HR_ONE(value)                    (OTPC_HR_ONE_Msk & (_UINT32_(value) << OTPC_HR_ONE_Pos)) /* Assigment of value for ONE in the OTPC_HR register */
#define OTPC_HR_SIZE_Pos                      _UINT32_(8)                                          /* (OTPC_HR) Packet Size Position */
#define OTPC_HR_SIZE_Msk                      (_UINT32_(0xFF) << OTPC_HR_SIZE_Pos)                 /* (OTPC_HR) Packet Size Mask */
#define OTPC_HR_SIZE(value)                   (OTPC_HR_SIZE_Msk & (_UINT32_(value) << OTPC_HR_SIZE_Pos)) /* Assigment of value for SIZE in the OTPC_HR register */
#define OTPC_HR_CHECKSUM_Pos                  _UINT32_(16)                                         /* (OTPC_HR) Packet Checksum Position */
#define OTPC_HR_CHECKSUM_Msk                  (_UINT32_(0xFFFF) << OTPC_HR_CHECKSUM_Pos)           /* (OTPC_HR) Packet Checksum Mask */
#define OTPC_HR_CHECKSUM(value)               (OTPC_HR_CHECKSUM_Msk & (_UINT32_(value) << OTPC_HR_CHECKSUM_Pos)) /* Assigment of value for CHECKSUM in the OTPC_HR register */
#define OTPC_HR_Msk                           _UINT32_(0xFFFFFFBF)                                 /* (OTPC_HR) Register Mask  */


/* -------- OTPC_DR : (OTPC Offset: 0x24) (R/W 32) Data Register -------- */
#define OTPC_DR_RESETVALUE                    _UINT32_(0x00)                                       /*  (OTPC_DR) Data Register  Reset Value */

#define OTPC_DR_DATA_Pos                      _UINT32_(0)                                          /* (OTPC_DR) Packet Data Position */
#define OTPC_DR_DATA_Msk                      (_UINT32_(0xFFFFFFFF) << OTPC_DR_DATA_Pos)           /* (OTPC_DR) Packet Data Mask */
#define OTPC_DR_DATA(value)                   (OTPC_DR_DATA_Msk & (_UINT32_(value) << OTPC_DR_DATA_Pos)) /* Assigment of value for DATA in the OTPC_DR register */
#define OTPC_DR_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (OTPC_DR) Register Mask  */


/* -------- OTPC_BAR : (OTPC Offset: 0x30) ( R/ 32) Boot Addresses Register -------- */
#define OTPC_BAR_RESETVALUE                   _UINT32_(0x00)                                       /*  (OTPC_BAR) Boot Addresses Register  Reset Value */

#define OTPC_BAR_BCADDR_Pos                   _UINT32_(0)                                          /* (OTPC_BAR) Boot Configuration Address Position */
#define OTPC_BAR_BCADDR_Msk                   (_UINT32_(0xFFFF) << OTPC_BAR_BCADDR_Pos)            /* (OTPC_BAR) Boot Configuration Address Mask */
#define OTPC_BAR_BCADDR(value)                (OTPC_BAR_BCADDR_Msk & (_UINT32_(value) << OTPC_BAR_BCADDR_Pos)) /* Assigment of value for BCADDR in the OTPC_BAR register */
#define OTPC_BAR_SBCADDR_Pos                  _UINT32_(16)                                         /* (OTPC_BAR) Secure Boot Configuration Address Position */
#define OTPC_BAR_SBCADDR_Msk                  (_UINT32_(0xFFFF) << OTPC_BAR_SBCADDR_Pos)           /* (OTPC_BAR) Secure Boot Configuration Address Mask */
#define OTPC_BAR_SBCADDR(value)               (OTPC_BAR_SBCADDR_Msk & (_UINT32_(value) << OTPC_BAR_SBCADDR_Pos)) /* Assigment of value for SBCADDR in the OTPC_BAR register */
#define OTPC_BAR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (OTPC_BAR) Register Mask  */


/* -------- OTPC_CAR : (OTPC Offset: 0x34) ( R/ 32) Custom Address Register -------- */
#define OTPC_CAR_RESETVALUE                   _UINT32_(0x00)                                       /*  (OTPC_CAR) Custom Address Register  Reset Value */

#define OTPC_CAR_CADDR_Pos                    _UINT32_(0)                                          /* (OTPC_CAR) Custom Address Position */
#define OTPC_CAR_CADDR_Msk                    (_UINT32_(0xFFFF) << OTPC_CAR_CADDR_Pos)             /* (OTPC_CAR) Custom Address Mask */
#define OTPC_CAR_CADDR(value)                 (OTPC_CAR_CADDR_Msk & (_UINT32_(value) << OTPC_CAR_CADDR_Pos)) /* Assigment of value for CADDR in the OTPC_CAR register */
#define OTPC_CAR_Msk                          _UINT32_(0x0000FFFF)                                 /* (OTPC_CAR) Register Mask  */


/* -------- OTPC_LRMR : (OTPC Offset: 0x40) (R/W 32) Live Repair Mode Register -------- */
#define OTPC_LRMR_RESETVALUE                  _UINT32_(0x00)                                       /*  (OTPC_LRMR) Live Repair Mode Register  Reset Value */

#define OTPC_LRMR_FREQ_Pos                    _UINT32_(0)                                          /* (OTPC_LRMR) Automatic Live Repair Frequency Position */
#define OTPC_LRMR_FREQ_Msk                    (_UINT32_(0x3) << OTPC_LRMR_FREQ_Pos)                /* (OTPC_LRMR) Automatic Live Repair Frequency Mask */
#define OTPC_LRMR_FREQ(value)                 (OTPC_LRMR_FREQ_Msk & (_UINT32_(value) << OTPC_LRMR_FREQ_Pos)) /* Assigment of value for FREQ in the OTPC_LRMR register */
#define   OTPC_LRMR_FREQ_ONE_DAY_Val          _UINT32_(0x0)                                        /* (OTPC_LRMR) The live repair is started every day  */
#define   OTPC_LRMR_FREQ_FOUR_DAYS_Val        _UINT32_(0x1)                                        /* (OTPC_LRMR) The live repair is started every 4 days  */
#define   OTPC_LRMR_FREQ_EIGHT_DAYS_Val       _UINT32_(0x2)                                        /* (OTPC_LRMR) The live repair is started every 8 days  */
#define   OTPC_LRMR_FREQ_SIXTEEN_DAYS_Val     _UINT32_(0x3)                                        /* (OTPC_LRMR) The live repair is started every 16 days  */
#define OTPC_LRMR_FREQ_ONE_DAY                (OTPC_LRMR_FREQ_ONE_DAY_Val << OTPC_LRMR_FREQ_Pos)   /* (OTPC_LRMR) The live repair is started every day Position  */
#define OTPC_LRMR_FREQ_FOUR_DAYS              (OTPC_LRMR_FREQ_FOUR_DAYS_Val << OTPC_LRMR_FREQ_Pos) /* (OTPC_LRMR) The live repair is started every 4 days Position  */
#define OTPC_LRMR_FREQ_EIGHT_DAYS             (OTPC_LRMR_FREQ_EIGHT_DAYS_Val << OTPC_LRMR_FREQ_Pos) /* (OTPC_LRMR) The live repair is started every 8 days Position  */
#define OTPC_LRMR_FREQ_SIXTEEN_DAYS           (OTPC_LRMR_FREQ_SIXTEEN_DAYS_Val << OTPC_LRMR_FREQ_Pos) /* (OTPC_LRMR) The live repair is started every 16 days Position  */
#define OTPC_LRMR_EN_Pos                      _UINT32_(4)                                          /* (OTPC_LRMR) Automatic Live Repair Enable Position */
#define OTPC_LRMR_EN_Msk                      (_UINT32_(0x1) << OTPC_LRMR_EN_Pos)                  /* (OTPC_LRMR) Automatic Live Repair Enable Mask */
#define OTPC_LRMR_EN(value)                   (OTPC_LRMR_EN_Msk & (_UINT32_(value) << OTPC_LRMR_EN_Pos)) /* Assigment of value for EN in the OTPC_LRMR register */
#define   OTPC_LRMR_EN_0_Val                  _UINT32_(0x0)                                        /* (OTPC_LRMR) The automatic start of OTP live repair is disabled.  */
#define   OTPC_LRMR_EN_1_Val                  _UINT32_(0x1)                                        /* (OTPC_LRMR) The automatic start of OTP live repair is enabled.  */
#define OTPC_LRMR_EN_0                        (OTPC_LRMR_EN_0_Val << OTPC_LRMR_EN_Pos)             /* (OTPC_LRMR) The automatic start of OTP live repair is disabled. Position  */
#define OTPC_LRMR_EN_1                        (OTPC_LRMR_EN_1_Val << OTPC_LRMR_EN_Pos)             /* (OTPC_LRMR) The automatic start of OTP live repair is enabled. Position  */
#define OTPC_LRMR_KEY_Pos                     _UINT32_(16)                                         /* (OTPC_LRMR) Programming Key Position */
#define OTPC_LRMR_KEY_Msk                     (_UINT32_(0xFFFF) << OTPC_LRMR_KEY_Pos)              /* (OTPC_LRMR) Programming Key Mask */
#define OTPC_LRMR_KEY(value)                  (OTPC_LRMR_KEY_Msk & (_UINT32_(value) << OTPC_LRMR_KEY_Pos)) /* Assigment of value for KEY in the OTPC_LRMR register */
#define OTPC_LRMR_Msk                         _UINT32_(0xFFFF0013)                                 /* (OTPC_LRMR) Register Mask  */


/* -------- OTPC_UHC0R : (OTPC Offset: 0x50) ( R/ 32) User Hardware Configuration 0 Register -------- */
#define OTPC_UHC0R_RESETVALUE                 _UINT32_(0x00)                                       /*  (OTPC_UHC0R) User Hardware Configuration 0 Register  Reset Value */

#define OTPC_UHC0R_JTAGDIS_Pos                _UINT32_(0)                                          /* (OTPC_UHC0R) JTAG Disable Position */
#define OTPC_UHC0R_JTAGDIS_Msk                (_UINT32_(0xFF) << OTPC_UHC0R_JTAGDIS_Pos)           /* (OTPC_UHC0R) JTAG Disable Mask */
#define OTPC_UHC0R_JTAGDIS(value)             (OTPC_UHC0R_JTAGDIS_Msk & (_UINT32_(value) << OTPC_UHC0R_JTAGDIS_Pos)) /* Assigment of value for JTAGDIS in the OTPC_UHC0R register */
#define   OTPC_UHC0R_JTAGDIS_0_Val            _UINT32_(0x0)                                        /* (OTPC_UHC0R) The JTAG is enabled.  */
#define OTPC_UHC0R_JTAGDIS_0                  (OTPC_UHC0R_JTAGDIS_0_Val << OTPC_UHC0R_JTAGDIS_Pos) /* (OTPC_UHC0R) The JTAG is enabled. Position  */
#define OTPC_UHC0R_Msk                        _UINT32_(0x000000FF)                                 /* (OTPC_UHC0R) Register Mask  */


/* -------- OTPC_UHC1R : (OTPC Offset: 0x54) ( R/ 32) User Hardware Configuration 1 Register -------- */
#define OTPC_UHC1R_RESETVALUE                 _UINT32_(0x00)                                       /*  (OTPC_UHC1R) User Hardware Configuration 1 Register  Reset Value */

#define OTPC_UHC1R_URDDIS_Pos                 _UINT32_(0)                                          /* (OTPC_UHC1R) User Read Disable Position */
#define OTPC_UHC1R_URDDIS_Msk                 (_UINT32_(0x1) << OTPC_UHC1R_URDDIS_Pos)             /* (OTPC_UHC1R) User Read Disable Mask */
#define OTPC_UHC1R_URDDIS(value)              (OTPC_UHC1R_URDDIS_Msk & (_UINT32_(value) << OTPC_UHC1R_URDDIS_Pos)) /* Assigment of value for URDDIS in the OTPC_UHC1R register */
#define   OTPC_UHC1R_URDDIS_0_Val             _UINT32_(0x0)                                        /* (OTPC_UHC1R) The OTPC_CR.READ bit is fully functional.  */
#define   OTPC_UHC1R_URDDIS_1_Val             _UINT32_(0x1)                                        /* (OTPC_UHC1R) The OTPC_CR.READ bit is not functional.  */
#define OTPC_UHC1R_URDDIS_0                   (OTPC_UHC1R_URDDIS_0_Val << OTPC_UHC1R_URDDIS_Pos)   /* (OTPC_UHC1R) The OTPC_CR.READ bit is fully functional. Position  */
#define OTPC_UHC1R_URDDIS_1                   (OTPC_UHC1R_URDDIS_1_Val << OTPC_UHC1R_URDDIS_Pos)   /* (OTPC_UHC1R) The OTPC_CR.READ bit is not functional. Position  */
#define OTPC_UHC1R_UPGDIS_Pos                 _UINT32_(1)                                          /* (OTPC_UHC1R) User programming Disable Position */
#define OTPC_UHC1R_UPGDIS_Msk                 (_UINT32_(0x1) << OTPC_UHC1R_UPGDIS_Pos)             /* (OTPC_UHC1R) User programming Disable Mask */
#define OTPC_UHC1R_UPGDIS(value)              (OTPC_UHC1R_UPGDIS_Msk & (_UINT32_(value) << OTPC_UHC1R_UPGDIS_Pos)) /* Assigment of value for UPGDIS in the OTPC_UHC1R register */
#define   OTPC_UHC1R_UPGDIS_0_Val             _UINT32_(0x0)                                        /* (OTPC_UHC1R) The OTPC_CR.PGM bit is fully functional.  */
#define   OTPC_UHC1R_UPGDIS_1_Val             _UINT32_(0x1)                                        /* (OTPC_UHC1R) The OTPC_CR.PGM bit is not functional.  */
#define OTPC_UHC1R_UPGDIS_0                   (OTPC_UHC1R_UPGDIS_0_Val << OTPC_UHC1R_UPGDIS_Pos)   /* (OTPC_UHC1R) The OTPC_CR.PGM bit is fully functional. Position  */
#define OTPC_UHC1R_UPGDIS_1                   (OTPC_UHC1R_UPGDIS_1_Val << OTPC_UHC1R_UPGDIS_Pos)   /* (OTPC_UHC1R) The OTPC_CR.PGM bit is not functional. Position  */
#define OTPC_UHC1R_UHCINVDIS_Pos              _UINT32_(2)                                          /* (OTPC_UHC1R) User Hardware Configuration Packet Invalidation Disable Position */
#define OTPC_UHC1R_UHCINVDIS_Msk              (_UINT32_(0x1) << OTPC_UHC1R_UHCINVDIS_Pos)          /* (OTPC_UHC1R) User Hardware Configuration Packet Invalidation Disable Mask */
#define OTPC_UHC1R_UHCINVDIS(value)           (OTPC_UHC1R_UHCINVDIS_Msk & (_UINT32_(value) << OTPC_UHC1R_UHCINVDIS_Pos)) /* Assigment of value for UHCINVDIS in the OTPC_UHC1R register */
#define   OTPC_UHC1R_UHCINVDIS_0_Val          _UINT32_(0x0)                                        /* (OTPC_UHC1R) The invalidation of the User Hardware Configuration Special Packet is allowed.  */
#define   OTPC_UHC1R_UHCINVDIS_1_Val          _UINT32_(0x1)                                        /* (OTPC_UHC1R) The invalidation of the User Hardware Configuration Special Packet is forbidden.  */
#define OTPC_UHC1R_UHCINVDIS_0                (OTPC_UHC1R_UHCINVDIS_0_Val << OTPC_UHC1R_UHCINVDIS_Pos) /* (OTPC_UHC1R) The invalidation of the User Hardware Configuration Special Packet is allowed. Position  */
#define OTPC_UHC1R_UHCINVDIS_1                (OTPC_UHC1R_UHCINVDIS_1_Val << OTPC_UHC1R_UHCINVDIS_Pos) /* (OTPC_UHC1R) The invalidation of the User Hardware Configuration Special Packet is forbidden. Position  */
#define OTPC_UHC1R_UHCLKDIS_Pos               _UINT32_(3)                                          /* (OTPC_UHC1R) User Hardware Configuration Packet Lock Disable Position */
#define OTPC_UHC1R_UHCLKDIS_Msk               (_UINT32_(0x1) << OTPC_UHC1R_UHCLKDIS_Pos)           /* (OTPC_UHC1R) User Hardware Configuration Packet Lock Disable Mask */
#define OTPC_UHC1R_UHCLKDIS(value)            (OTPC_UHC1R_UHCLKDIS_Msk & (_UINT32_(value) << OTPC_UHC1R_UHCLKDIS_Pos)) /* Assigment of value for UHCLKDIS in the OTPC_UHC1R register */
#define   OTPC_UHC1R_UHCLKDIS_0_Val           _UINT32_(0x0)                                        /* (OTPC_UHC1R) The generation of the checksum (lock) of the User Hardware Configuration Special Packet is allowed.  */
#define   OTPC_UHC1R_UHCLKDIS_1_Val           _UINT32_(0x1)                                        /* (OTPC_UHC1R) The generation of the checksum (lock) of the User Hardware Configuration Special Packet is forbidden.  */
#define OTPC_UHC1R_UHCLKDIS_0                 (OTPC_UHC1R_UHCLKDIS_0_Val << OTPC_UHC1R_UHCLKDIS_Pos) /* (OTPC_UHC1R) The generation of the checksum (lock) of the User Hardware Configuration Special Packet is allowed. Position  */
#define OTPC_UHC1R_UHCLKDIS_1                 (OTPC_UHC1R_UHCLKDIS_1_Val << OTPC_UHC1R_UHCLKDIS_Pos) /* (OTPC_UHC1R) The generation of the checksum (lock) of the User Hardware Configuration Special Packet is forbidden. Position  */
#define OTPC_UHC1R_UHCPGDIS_Pos               _UINT32_(4)                                          /* (OTPC_UHC1R) User Hardware Configuration Packet Program Disable Position */
#define OTPC_UHC1R_UHCPGDIS_Msk               (_UINT32_(0x1) << OTPC_UHC1R_UHCPGDIS_Pos)           /* (OTPC_UHC1R) User Hardware Configuration Packet Program Disable Mask */
#define OTPC_UHC1R_UHCPGDIS(value)            (OTPC_UHC1R_UHCPGDIS_Msk & (_UINT32_(value) << OTPC_UHC1R_UHCPGDIS_Pos)) /* Assigment of value for UHCPGDIS in the OTPC_UHC1R register */
#define   OTPC_UHC1R_UHCPGDIS_0_Val           _UINT32_(0x0)                                        /* (OTPC_UHC1R) The programming of User Hardware Configuration Special Packet is allowed.  */
#define   OTPC_UHC1R_UHCPGDIS_1_Val           _UINT32_(0x1)                                        /* (OTPC_UHC1R) The programming of User Hardware Configuration Special Packet is forbidden.  */
#define OTPC_UHC1R_UHCPGDIS_0                 (OTPC_UHC1R_UHCPGDIS_0_Val << OTPC_UHC1R_UHCPGDIS_Pos) /* (OTPC_UHC1R) The programming of User Hardware Configuration Special Packet is allowed. Position  */
#define OTPC_UHC1R_UHCPGDIS_1                 (OTPC_UHC1R_UHCPGDIS_1_Val << OTPC_UHC1R_UHCPGDIS_Pos) /* (OTPC_UHC1R) The programming of User Hardware Configuration Special Packet is forbidden. Position  */
#define OTPC_UHC1R_BCINVDIS_Pos               _UINT32_(5)                                          /* (OTPC_UHC1R) Boot Configuration Packet Invalidation Disable Position */
#define OTPC_UHC1R_BCINVDIS_Msk               (_UINT32_(0x1) << OTPC_UHC1R_BCINVDIS_Pos)           /* (OTPC_UHC1R) Boot Configuration Packet Invalidation Disable Mask */
#define OTPC_UHC1R_BCINVDIS(value)            (OTPC_UHC1R_BCINVDIS_Msk & (_UINT32_(value) << OTPC_UHC1R_BCINVDIS_Pos)) /* Assigment of value for BCINVDIS in the OTPC_UHC1R register */
#define   OTPC_UHC1R_BCINVDIS_0_Val           _UINT32_(0x0)                                        /* (OTPC_UHC1R) The invalidation of the Boot Configuration Special Packet is allowed.  */
#define   OTPC_UHC1R_BCINVDIS_1_Val           _UINT32_(0x1)                                        /* (OTPC_UHC1R) The invalidation of the Boot Configuration Special Packet is forbidden.  */
#define OTPC_UHC1R_BCINVDIS_0                 (OTPC_UHC1R_BCINVDIS_0_Val << OTPC_UHC1R_BCINVDIS_Pos) /* (OTPC_UHC1R) The invalidation of the Boot Configuration Special Packet is allowed. Position  */
#define OTPC_UHC1R_BCINVDIS_1                 (OTPC_UHC1R_BCINVDIS_1_Val << OTPC_UHC1R_BCINVDIS_Pos) /* (OTPC_UHC1R) The invalidation of the Boot Configuration Special Packet is forbidden. Position  */
#define OTPC_UHC1R_BCLKDIS_Pos                _UINT32_(6)                                          /* (OTPC_UHC1R) Boot Configuration Packet Lock Disable Position */
#define OTPC_UHC1R_BCLKDIS_Msk                (_UINT32_(0x1) << OTPC_UHC1R_BCLKDIS_Pos)            /* (OTPC_UHC1R) Boot Configuration Packet Lock Disable Mask */
#define OTPC_UHC1R_BCLKDIS(value)             (OTPC_UHC1R_BCLKDIS_Msk & (_UINT32_(value) << OTPC_UHC1R_BCLKDIS_Pos)) /* Assigment of value for BCLKDIS in the OTPC_UHC1R register */
#define   OTPC_UHC1R_BCLKDIS_0_Val            _UINT32_(0x0)                                        /* (OTPC_UHC1R) The generation of the checksum (lock) of the Boot Configuration Special Packet is allowed.  */
#define   OTPC_UHC1R_BCLKDIS_1_Val            _UINT32_(0x1)                                        /* (OTPC_UHC1R) The generation of the checksum (lock) of the Boot Configuration Special Packet is forbidden.  */
#define OTPC_UHC1R_BCLKDIS_0                  (OTPC_UHC1R_BCLKDIS_0_Val << OTPC_UHC1R_BCLKDIS_Pos) /* (OTPC_UHC1R) The generation of the checksum (lock) of the Boot Configuration Special Packet is allowed. Position  */
#define OTPC_UHC1R_BCLKDIS_1                  (OTPC_UHC1R_BCLKDIS_1_Val << OTPC_UHC1R_BCLKDIS_Pos) /* (OTPC_UHC1R) The generation of the checksum (lock) of the Boot Configuration Special Packet is forbidden. Position  */
#define OTPC_UHC1R_BCPGDIS_Pos                _UINT32_(7)                                          /* (OTPC_UHC1R) Boot Configuration Packet Program Disable Position */
#define OTPC_UHC1R_BCPGDIS_Msk                (_UINT32_(0x1) << OTPC_UHC1R_BCPGDIS_Pos)            /* (OTPC_UHC1R) Boot Configuration Packet Program Disable Mask */
#define OTPC_UHC1R_BCPGDIS(value)             (OTPC_UHC1R_BCPGDIS_Msk & (_UINT32_(value) << OTPC_UHC1R_BCPGDIS_Pos)) /* Assigment of value for BCPGDIS in the OTPC_UHC1R register */
#define   OTPC_UHC1R_BCPGDIS_0_Val            _UINT32_(0x0)                                        /* (OTPC_UHC1R) The programming of Boot Configuration Special Packet is allowed.  */
#define   OTPC_UHC1R_BCPGDIS_1_Val            _UINT32_(0x1)                                        /* (OTPC_UHC1R) The programming of Boot Configuration Special Packet is forbidden.  */
#define OTPC_UHC1R_BCPGDIS_0                  (OTPC_UHC1R_BCPGDIS_0_Val << OTPC_UHC1R_BCPGDIS_Pos) /* (OTPC_UHC1R) The programming of Boot Configuration Special Packet is allowed. Position  */
#define OTPC_UHC1R_BCPGDIS_1                  (OTPC_UHC1R_BCPGDIS_1_Val << OTPC_UHC1R_BCPGDIS_Pos) /* (OTPC_UHC1R) The programming of Boot Configuration Special Packet is forbidden. Position  */
#define OTPC_UHC1R_SBCINVDIS_Pos              _UINT32_(8)                                          /* (OTPC_UHC1R) Secure Boot Configuration Packet Invalidation Disable Position */
#define OTPC_UHC1R_SBCINVDIS_Msk              (_UINT32_(0x1) << OTPC_UHC1R_SBCINVDIS_Pos)          /* (OTPC_UHC1R) Secure Boot Configuration Packet Invalidation Disable Mask */
#define OTPC_UHC1R_SBCINVDIS(value)           (OTPC_UHC1R_SBCINVDIS_Msk & (_UINT32_(value) << OTPC_UHC1R_SBCINVDIS_Pos)) /* Assigment of value for SBCINVDIS in the OTPC_UHC1R register */
#define   OTPC_UHC1R_SBCINVDIS_0_Val          _UINT32_(0x0)                                        /* (OTPC_UHC1R) The invalidation of the Secure Boot Configuration Special Packet is allowed.  */
#define   OTPC_UHC1R_SBCINVDIS_1_Val          _UINT32_(0x1)                                        /* (OTPC_UHC1R) The invalidation of the Secure Boot Configuration Special Packet is forbidden.  */
#define OTPC_UHC1R_SBCINVDIS_0                (OTPC_UHC1R_SBCINVDIS_0_Val << OTPC_UHC1R_SBCINVDIS_Pos) /* (OTPC_UHC1R) The invalidation of the Secure Boot Configuration Special Packet is allowed. Position  */
#define OTPC_UHC1R_SBCINVDIS_1                (OTPC_UHC1R_SBCINVDIS_1_Val << OTPC_UHC1R_SBCINVDIS_Pos) /* (OTPC_UHC1R) The invalidation of the Secure Boot Configuration Special Packet is forbidden. Position  */
#define OTPC_UHC1R_SBCLKDIS_Pos               _UINT32_(9)                                          /* (OTPC_UHC1R) Secure Boot Configuration Packet Lock Disable Position */
#define OTPC_UHC1R_SBCLKDIS_Msk               (_UINT32_(0x1) << OTPC_UHC1R_SBCLKDIS_Pos)           /* (OTPC_UHC1R) Secure Boot Configuration Packet Lock Disable Mask */
#define OTPC_UHC1R_SBCLKDIS(value)            (OTPC_UHC1R_SBCLKDIS_Msk & (_UINT32_(value) << OTPC_UHC1R_SBCLKDIS_Pos)) /* Assigment of value for SBCLKDIS in the OTPC_UHC1R register */
#define   OTPC_UHC1R_SBCLKDIS_0_Val           _UINT32_(0x0)                                        /* (OTPC_UHC1R) The generation of the checksum (lock) of the Secure Boot Configuration Special Packet is allowed.  */
#define   OTPC_UHC1R_SBCLKDIS_1_Val           _UINT32_(0x1)                                        /* (OTPC_UHC1R) The generation of the checksum (lock) of the Secure Boot Configuration Special Packet is forbidden.  */
#define OTPC_UHC1R_SBCLKDIS_0                 (OTPC_UHC1R_SBCLKDIS_0_Val << OTPC_UHC1R_SBCLKDIS_Pos) /* (OTPC_UHC1R) The generation of the checksum (lock) of the Secure Boot Configuration Special Packet is allowed. Position  */
#define OTPC_UHC1R_SBCLKDIS_1                 (OTPC_UHC1R_SBCLKDIS_1_Val << OTPC_UHC1R_SBCLKDIS_Pos) /* (OTPC_UHC1R) The generation of the checksum (lock) of the Secure Boot Configuration Special Packet is forbidden. Position  */
#define OTPC_UHC1R_SBCPGDIS_Pos               _UINT32_(10)                                         /* (OTPC_UHC1R) Secure Boot Configuration Packet Program Disable Position */
#define OTPC_UHC1R_SBCPGDIS_Msk               (_UINT32_(0x1) << OTPC_UHC1R_SBCPGDIS_Pos)           /* (OTPC_UHC1R) Secure Boot Configuration Packet Program Disable Mask */
#define OTPC_UHC1R_SBCPGDIS(value)            (OTPC_UHC1R_SBCPGDIS_Msk & (_UINT32_(value) << OTPC_UHC1R_SBCPGDIS_Pos)) /* Assigment of value for SBCPGDIS in the OTPC_UHC1R register */
#define   OTPC_UHC1R_SBCPGDIS_0_Val           _UINT32_(0x0)                                        /* (OTPC_UHC1R) The programming of Secure Boot Configuration Special Packet is allowed.  */
#define   OTPC_UHC1R_SBCPGDIS_1_Val           _UINT32_(0x1)                                        /* (OTPC_UHC1R) The programming of Secure Boot Configuration Special Packet is forbidden.  */
#define OTPC_UHC1R_SBCPGDIS_0                 (OTPC_UHC1R_SBCPGDIS_0_Val << OTPC_UHC1R_SBCPGDIS_Pos) /* (OTPC_UHC1R) The programming of Secure Boot Configuration Special Packet is allowed. Position  */
#define OTPC_UHC1R_SBCPGDIS_1                 (OTPC_UHC1R_SBCPGDIS_1_Val << OTPC_UHC1R_SBCPGDIS_Pos) /* (OTPC_UHC1R) The programming of Secure Boot Configuration Special Packet is forbidden. Position  */
#define OTPC_UHC1R_CINVDIS_Pos                _UINT32_(14)                                         /* (OTPC_UHC1R) Custom Packet Invalidation Disable Position */
#define OTPC_UHC1R_CINVDIS_Msk                (_UINT32_(0x1) << OTPC_UHC1R_CINVDIS_Pos)            /* (OTPC_UHC1R) Custom Packet Invalidation Disable Mask */
#define OTPC_UHC1R_CINVDIS(value)             (OTPC_UHC1R_CINVDIS_Msk & (_UINT32_(value) << OTPC_UHC1R_CINVDIS_Pos)) /* Assigment of value for CINVDIS in the OTPC_UHC1R register */
#define   OTPC_UHC1R_CINVDIS_0_Val            _UINT32_(0x0)                                        /* (OTPC_UHC1R) The invalidation of the Custom Special Packet is allowed.  */
#define   OTPC_UHC1R_CINVDIS_1_Val            _UINT32_(0x1)                                        /* (OTPC_UHC1R) The invalidation of the Custom Special Packet is forbidden.  */
#define OTPC_UHC1R_CINVDIS_0                  (OTPC_UHC1R_CINVDIS_0_Val << OTPC_UHC1R_CINVDIS_Pos) /* (OTPC_UHC1R) The invalidation of the Custom Special Packet is allowed. Position  */
#define OTPC_UHC1R_CINVDIS_1                  (OTPC_UHC1R_CINVDIS_1_Val << OTPC_UHC1R_CINVDIS_Pos) /* (OTPC_UHC1R) The invalidation of the Custom Special Packet is forbidden. Position  */
#define OTPC_UHC1R_CLKDIS_Pos                 _UINT32_(15)                                         /* (OTPC_UHC1R) Custom Packet Lock Disable Position */
#define OTPC_UHC1R_CLKDIS_Msk                 (_UINT32_(0x1) << OTPC_UHC1R_CLKDIS_Pos)             /* (OTPC_UHC1R) Custom Packet Lock Disable Mask */
#define OTPC_UHC1R_CLKDIS(value)              (OTPC_UHC1R_CLKDIS_Msk & (_UINT32_(value) << OTPC_UHC1R_CLKDIS_Pos)) /* Assigment of value for CLKDIS in the OTPC_UHC1R register */
#define   OTPC_UHC1R_CLKDIS_0_Val             _UINT32_(0x0)                                        /* (OTPC_UHC1R) The generation of the checksum (lock) of the Custom Special Packet is allowed.  */
#define   OTPC_UHC1R_CLKDIS_1_Val             _UINT32_(0x1)                                        /* (OTPC_UHC1R) The generation of the checksum (lock) of the Custom Special Packet is forbidden.  */
#define OTPC_UHC1R_CLKDIS_0                   (OTPC_UHC1R_CLKDIS_0_Val << OTPC_UHC1R_CLKDIS_Pos)   /* (OTPC_UHC1R) The generation of the checksum (lock) of the Custom Special Packet is allowed. Position  */
#define OTPC_UHC1R_CLKDIS_1                   (OTPC_UHC1R_CLKDIS_1_Val << OTPC_UHC1R_CLKDIS_Pos)   /* (OTPC_UHC1R) The generation of the checksum (lock) of the Custom Special Packet is forbidden. Position  */
#define OTPC_UHC1R_CPGDIS_Pos                 _UINT32_(16)                                         /* (OTPC_UHC1R) Custom Packet Program Disable Position */
#define OTPC_UHC1R_CPGDIS_Msk                 (_UINT32_(0x1) << OTPC_UHC1R_CPGDIS_Pos)             /* (OTPC_UHC1R) Custom Packet Program Disable Mask */
#define OTPC_UHC1R_CPGDIS(value)              (OTPC_UHC1R_CPGDIS_Msk & (_UINT32_(value) << OTPC_UHC1R_CPGDIS_Pos)) /* Assigment of value for CPGDIS in the OTPC_UHC1R register */
#define   OTPC_UHC1R_CPGDIS_0_Val             _UINT32_(0x0)                                        /* (OTPC_UHC1R) The programming of Custom Special Packet is allowed.  */
#define   OTPC_UHC1R_CPGDIS_1_Val             _UINT32_(0x1)                                        /* (OTPC_UHC1R) The programming of Custom Special Packet is forbidden.  */
#define OTPC_UHC1R_CPGDIS_0                   (OTPC_UHC1R_CPGDIS_0_Val << OTPC_UHC1R_CPGDIS_Pos)   /* (OTPC_UHC1R) The programming of Custom Special Packet is allowed. Position  */
#define OTPC_UHC1R_CPGDIS_1                   (OTPC_UHC1R_CPGDIS_1_Val << OTPC_UHC1R_CPGDIS_Pos)   /* (OTPC_UHC1R) The programming of Custom Special Packet is forbidden. Position  */
#define OTPC_UHC1R_URFDIS_Pos                 _UINT32_(17)                                         /* (OTPC_UHC1R) User Refresh Disable Position */
#define OTPC_UHC1R_URFDIS_Msk                 (_UINT32_(0x1) << OTPC_UHC1R_URFDIS_Pos)             /* (OTPC_UHC1R) User Refresh Disable Mask */
#define OTPC_UHC1R_URFDIS(value)              (OTPC_UHC1R_URFDIS_Msk & (_UINT32_(value) << OTPC_UHC1R_URFDIS_Pos)) /* Assigment of value for URFDIS in the OTPC_UHC1R register */
#define   OTPC_UHC1R_URFDIS_0_Val             _UINT32_(0x0)                                        /* (OTPC_UHC1R) The OTPC_CR.REFRESH bit is fully functional.  */
#define   OTPC_UHC1R_URFDIS_1_Val             _UINT32_(0x1)                                        /* (OTPC_UHC1R) The OTPC_CR.REFRESH bit is only functional in Emulation mode.  */
#define OTPC_UHC1R_URFDIS_0                   (OTPC_UHC1R_URFDIS_0_Val << OTPC_UHC1R_URFDIS_Pos)   /* (OTPC_UHC1R) The OTPC_CR.REFRESH bit is fully functional. Position  */
#define OTPC_UHC1R_URFDIS_1                   (OTPC_UHC1R_URFDIS_1_Val << OTPC_UHC1R_URFDIS_Pos)   /* (OTPC_UHC1R) The OTPC_CR.REFRESH bit is only functional in Emulation mode. Position  */
#define OTPC_UHC1R_Msk                        _UINT32_(0x0003C7FF)                                 /* (OTPC_UHC1R) Register Mask  */


/* -------- OTPC_UID0R : (OTPC Offset: 0x60) ( R/ 32) Product UID 0 Register -------- */
#define OTPC_UID0R_UID_Pos                    _UINT32_(0)                                          /* (OTPC_UID0R) Unique Product ID Position */
#define OTPC_UID0R_UID_Msk                    (_UINT32_(0xFFFFFFFF) << OTPC_UID0R_UID_Pos)         /* (OTPC_UID0R) Unique Product ID Mask */
#define OTPC_UID0R_UID(value)                 (OTPC_UID0R_UID_Msk & (_UINT32_(value) << OTPC_UID0R_UID_Pos)) /* Assigment of value for UID in the OTPC_UID0R register */
#define OTPC_UID0R_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (OTPC_UID0R) Register Mask  */


/* -------- OTPC_UID1R : (OTPC Offset: 0x64) ( R/ 32) Product UID 1 Register -------- */
#define OTPC_UID1R_UID_Pos                    _UINT32_(0)                                          /* (OTPC_UID1R) Unique Product ID Position */
#define OTPC_UID1R_UID_Msk                    (_UINT32_(0xFFFFFFFF) << OTPC_UID1R_UID_Pos)         /* (OTPC_UID1R) Unique Product ID Mask */
#define OTPC_UID1R_UID(value)                 (OTPC_UID1R_UID_Msk & (_UINT32_(value) << OTPC_UID1R_UID_Pos)) /* Assigment of value for UID in the OTPC_UID1R register */
#define OTPC_UID1R_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (OTPC_UID1R) Register Mask  */


/* -------- OTPC_UID2R : (OTPC Offset: 0x68) ( R/ 32) Product UID 2 Register -------- */
#define OTPC_UID2R_UID_Pos                    _UINT32_(0)                                          /* (OTPC_UID2R) Unique Product ID Position */
#define OTPC_UID2R_UID_Msk                    (_UINT32_(0xFFFFFFFF) << OTPC_UID2R_UID_Pos)         /* (OTPC_UID2R) Unique Product ID Mask */
#define OTPC_UID2R_UID(value)                 (OTPC_UID2R_UID_Msk & (_UINT32_(value) << OTPC_UID2R_UID_Pos)) /* Assigment of value for UID in the OTPC_UID2R register */
#define OTPC_UID2R_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (OTPC_UID2R) Register Mask  */


/* -------- OTPC_UID3R : (OTPC Offset: 0x6C) ( R/ 32) Product UID 3 Register -------- */
#define OTPC_UID3R_UID_Pos                    _UINT32_(0)                                          /* (OTPC_UID3R) Unique Product ID Position */
#define OTPC_UID3R_UID_Msk                    (_UINT32_(0xFFFFFFFF) << OTPC_UID3R_UID_Pos)         /* (OTPC_UID3R) Unique Product ID Mask */
#define OTPC_UID3R_UID(value)                 (OTPC_UID3R_UID_Msk & (_UINT32_(value) << OTPC_UID3R_UID_Pos)) /* Assigment of value for UID in the OTPC_UID3R register */
#define OTPC_UID3R_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (OTPC_UID3R) Register Mask  */


/* -------- OTPC_WPMR : (OTPC Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define OTPC_WPMR_RESETVALUE                  _UINT32_(0x00)                                       /*  (OTPC_WPMR) Write Protection Mode Register  Reset Value */

#define OTPC_WPMR_WPCFEN_Pos                  _UINT32_(0)                                          /* (OTPC_WPMR) Write Protection Configuration Enable Position */
#define OTPC_WPMR_WPCFEN_Msk                  (_UINT32_(0x1) << OTPC_WPMR_WPCFEN_Pos)              /* (OTPC_WPMR) Write Protection Configuration Enable Mask */
#define OTPC_WPMR_WPCFEN(value)               (OTPC_WPMR_WPCFEN_Msk & (_UINT32_(value) << OTPC_WPMR_WPCFEN_Pos)) /* Assigment of value for WPCFEN in the OTPC_WPMR register */
#define   OTPC_WPMR_WPCFEN_0_Val              _UINT32_(0x0)                                        /* (OTPC_WPMR) Disables the write protection of the configuration if WPKEY matches to 0x4F5450 (OTP in ASCII).  */
#define   OTPC_WPMR_WPCFEN_1_Val              _UINT32_(0x1)                                        /* (OTPC_WPMR) Enables the write protection of the configuration if WPKEY matches to 0x4F5450 (OTP in ASCII).  */
#define OTPC_WPMR_WPCFEN_0                    (OTPC_WPMR_WPCFEN_0_Val << OTPC_WPMR_WPCFEN_Pos)     /* (OTPC_WPMR) Disables the write protection of the configuration if WPKEY matches to 0x4F5450 (OTP in ASCII). Position  */
#define OTPC_WPMR_WPCFEN_1                    (OTPC_WPMR_WPCFEN_1_Val << OTPC_WPMR_WPCFEN_Pos)     /* (OTPC_WPMR) Enables the write protection of the configuration if WPKEY matches to 0x4F5450 (OTP in ASCII). Position  */
#define OTPC_WPMR_WPITEN_Pos                  _UINT32_(1)                                          /* (OTPC_WPMR) Write Protection Interrupt Enable Position */
#define OTPC_WPMR_WPITEN_Msk                  (_UINT32_(0x1) << OTPC_WPMR_WPITEN_Pos)              /* (OTPC_WPMR) Write Protection Interrupt Enable Mask */
#define OTPC_WPMR_WPITEN(value)               (OTPC_WPMR_WPITEN_Msk & (_UINT32_(value) << OTPC_WPMR_WPITEN_Pos)) /* Assigment of value for WPITEN in the OTPC_WPMR register */
#define   OTPC_WPMR_WPITEN_0_Val              _UINT32_(0x0)                                        /* (OTPC_WPMR) Disables the write protection of the interruption configuration if WPKEY matches to 0x4F5450 (OTP in ASCII).  */
#define   OTPC_WPMR_WPITEN_1_Val              _UINT32_(0x1)                                        /* (OTPC_WPMR) Enables the write protection of the interruption configuration if WPKEY matches to 0x4F5450 (OTP in ASCII).  */
#define OTPC_WPMR_WPITEN_0                    (OTPC_WPMR_WPITEN_0_Val << OTPC_WPMR_WPITEN_Pos)     /* (OTPC_WPMR) Disables the write protection of the interruption configuration if WPKEY matches to 0x4F5450 (OTP in ASCII). Position  */
#define OTPC_WPMR_WPITEN_1                    (OTPC_WPMR_WPITEN_1_Val << OTPC_WPMR_WPITEN_Pos)     /* (OTPC_WPMR) Enables the write protection of the interruption configuration if WPKEY matches to 0x4F5450 (OTP in ASCII). Position  */
#define OTPC_WPMR_WPCTEN_Pos                  _UINT32_(2)                                          /* (OTPC_WPMR) Write Protection Control Enable Position */
#define OTPC_WPMR_WPCTEN_Msk                  (_UINT32_(0x1) << OTPC_WPMR_WPCTEN_Pos)              /* (OTPC_WPMR) Write Protection Control Enable Mask */
#define OTPC_WPMR_WPCTEN(value)               (OTPC_WPMR_WPCTEN_Msk & (_UINT32_(value) << OTPC_WPMR_WPCTEN_Pos)) /* Assigment of value for WPCTEN in the OTPC_WPMR register */
#define   OTPC_WPMR_WPCTEN_0_Val              _UINT32_(0x0)                                        /* (OTPC_WPMR) Disables the write protection of the control if WPKEY matches to 0x4F5450 (OTP in ASCII).  */
#define   OTPC_WPMR_WPCTEN_1_Val              _UINT32_(0x1)                                        /* (OTPC_WPMR) Enables the write protection of the control if WPKEY matches to 0x4F5450 (OTP in ASCII).  */
#define OTPC_WPMR_WPCTEN_0                    (OTPC_WPMR_WPCTEN_0_Val << OTPC_WPMR_WPCTEN_Pos)     /* (OTPC_WPMR) Disables the write protection of the control if WPKEY matches to 0x4F5450 (OTP in ASCII). Position  */
#define OTPC_WPMR_WPCTEN_1                    (OTPC_WPMR_WPCTEN_1_Val << OTPC_WPMR_WPCTEN_Pos)     /* (OTPC_WPMR) Enables the write protection of the control if WPKEY matches to 0x4F5450 (OTP in ASCII). Position  */
#define OTPC_WPMR_FIRSTE_Pos                  _UINT32_(4)                                          /* (OTPC_WPMR) First Error Report Enable Position */
#define OTPC_WPMR_FIRSTE_Msk                  (_UINT32_(0x1) << OTPC_WPMR_FIRSTE_Pos)              /* (OTPC_WPMR) First Error Report Enable Mask */
#define OTPC_WPMR_FIRSTE(value)               (OTPC_WPMR_FIRSTE_Msk & (_UINT32_(value) << OTPC_WPMR_FIRSTE_Pos)) /* Assigment of value for FIRSTE in the OTPC_WPMR register */
#define   OTPC_WPMR_FIRSTE_0_Val              _UINT32_(0x0)                                        /* (OTPC_WPMR) The last write protection violation source is reported in OTPC_WPSR.WPVSRC and the last software control error type is reported in OTPC_WPSR.SWETYP; The OTPC_ISR.SECE flag is set at the first error occurrence within a series.  */
#define   OTPC_WPMR_FIRSTE_1_Val              _UINT32_(0x1)                                        /* (OTPC_WPMR) Only the first write protection violation source is reported in OTPC_WPSR.WPVSRC and only the first software control error type is reported in OTPC_WPSR.SWETYP. The OTPC_ISR.SECE flag is set at the first error occurrence within a series.  */
#define OTPC_WPMR_FIRSTE_0                    (OTPC_WPMR_FIRSTE_0_Val << OTPC_WPMR_FIRSTE_Pos)     /* (OTPC_WPMR) The last write protection violation source is reported in OTPC_WPSR.WPVSRC and the last software control error type is reported in OTPC_WPSR.SWETYP; The OTPC_ISR.SECE flag is set at the first error occurrence within a series. Position  */
#define OTPC_WPMR_FIRSTE_1                    (OTPC_WPMR_FIRSTE_1_Val << OTPC_WPMR_FIRSTE_Pos)     /* (OTPC_WPMR) Only the first write protection violation source is reported in OTPC_WPSR.WPVSRC and only the first software control error type is reported in OTPC_WPSR.SWETYP. The OTPC_ISR.SECE flag is set at the first error occurrence within a series. Position  */
#define OTPC_WPMR_WPKEY_Pos                   _UINT32_(8)                                          /* (OTPC_WPMR) Write Protection Key Position */
#define OTPC_WPMR_WPKEY_Msk                   (_UINT32_(0xFFFFFF) << OTPC_WPMR_WPKEY_Pos)          /* (OTPC_WPMR) Write Protection Key Mask */
#define OTPC_WPMR_WPKEY(value)                (OTPC_WPMR_WPKEY_Msk & (_UINT32_(value) << OTPC_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the OTPC_WPMR register */
#define   OTPC_WPMR_WPKEY_PASSWD_Val          _UINT32_(0x4F5450)                                   /* (OTPC_WPMR) Writing any other value in this field aborts the write operation. Always reads as 0.  */
#define OTPC_WPMR_WPKEY_PASSWD                (OTPC_WPMR_WPKEY_PASSWD_Val << OTPC_WPMR_WPKEY_Pos)  /* (OTPC_WPMR) Writing any other value in this field aborts the write operation. Always reads as 0. Position  */
#define OTPC_WPMR_Msk                         _UINT32_(0xFFFFFF17)                                 /* (OTPC_WPMR) Register Mask  */


/* -------- OTPC_WPSR : (OTPC Offset: 0xE8) ( R/ 32) Write Protection Status Register -------- */
#define OTPC_WPSR_RESETVALUE                  _UINT32_(0x00)                                       /*  (OTPC_WPSR) Write Protection Status Register  Reset Value */

#define OTPC_WPSR_WPVS_Pos                    _UINT32_(0)                                          /* (OTPC_WPSR) Write Protection Violation Status (cleared on read) Position */
#define OTPC_WPSR_WPVS_Msk                    (_UINT32_(0x1) << OTPC_WPSR_WPVS_Pos)                /* (OTPC_WPSR) Write Protection Violation Status (cleared on read) Mask */
#define OTPC_WPSR_WPVS(value)                 (OTPC_WPSR_WPVS_Msk & (_UINT32_(value) << OTPC_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the OTPC_WPSR register */
#define   OTPC_WPSR_WPVS_0_Val                _UINT32_(0x0)                                        /* (OTPC_WPSR) No write protection violation has occurred since the last read of OTPC_WPSR.  */
#define   OTPC_WPSR_WPVS_1_Val                _UINT32_(0x1)                                        /* (OTPC_WPSR) A write protection violation has occurred since the last read of OTPC_WPSR. If this violation is an unauthorized attempt to write a protected register, the associated violation is reported into WPVSRC.  */
#define OTPC_WPSR_WPVS_0                      (OTPC_WPSR_WPVS_0_Val << OTPC_WPSR_WPVS_Pos)         /* (OTPC_WPSR) No write protection violation has occurred since the last read of OTPC_WPSR. Position  */
#define OTPC_WPSR_WPVS_1                      (OTPC_WPSR_WPVS_1_Val << OTPC_WPSR_WPVS_Pos)         /* (OTPC_WPSR) A write protection violation has occurred since the last read of OTPC_WPSR. If this violation is an unauthorized attempt to write a protected register, the associated violation is reported into WPVSRC. Position  */
#define OTPC_WPSR_CGD_Pos                     _UINT32_(1)                                          /* (OTPC_WPSR) Clock Glitch Detected (cleared on read) Position */
#define OTPC_WPSR_CGD_Msk                     (_UINT32_(0x1) << OTPC_WPSR_CGD_Pos)                 /* (OTPC_WPSR) Clock Glitch Detected (cleared on read) Mask */
#define OTPC_WPSR_CGD(value)                  (OTPC_WPSR_CGD_Msk & (_UINT32_(value) << OTPC_WPSR_CGD_Pos)) /* Assigment of value for CGD in the OTPC_WPSR register */
#define   OTPC_WPSR_CGD_0_Val                 _UINT32_(0x0)                                        /* (OTPC_WPSR) No clock glitch has occurred since the last read of OTPC_WPSR.  */
#define   OTPC_WPSR_CGD_1_Val                 _UINT32_(0x1)                                        /* (OTPC_WPSR) A clock glitch has occurred since the last read of OTPC_WPSR. This flag can be set under abnormal operating conditions.  */
#define OTPC_WPSR_CGD_0                       (OTPC_WPSR_CGD_0_Val << OTPC_WPSR_CGD_Pos)           /* (OTPC_WPSR) No clock glitch has occurred since the last read of OTPC_WPSR. Position  */
#define OTPC_WPSR_CGD_1                       (OTPC_WPSR_CGD_1_Val << OTPC_WPSR_CGD_Pos)           /* (OTPC_WPSR) A clock glitch has occurred since the last read of OTPC_WPSR. This flag can be set under abnormal operating conditions. Position  */
#define OTPC_WPSR_SEQE_Pos                    _UINT32_(2)                                          /* (OTPC_WPSR) Internal Sequencer Error (cleared on read) Position */
#define OTPC_WPSR_SEQE_Msk                    (_UINT32_(0x1) << OTPC_WPSR_SEQE_Pos)                /* (OTPC_WPSR) Internal Sequencer Error (cleared on read) Mask */
#define OTPC_WPSR_SEQE(value)                 (OTPC_WPSR_SEQE_Msk & (_UINT32_(value) << OTPC_WPSR_SEQE_Pos)) /* Assigment of value for SEQE in the OTPC_WPSR register */
#define   OTPC_WPSR_SEQE_0_Val                _UINT32_(0x0)                                        /* (OTPC_WPSR) No peripheral internal sequencer error has occurred since the last read of OTPC_WPSR.  */
#define   OTPC_WPSR_SEQE_1_Val                _UINT32_(0x1)                                        /* (OTPC_WPSR) A peripheral internal sequencer error has occurred since the last read of OTPC_WPSR. This flag can be set under abnormal operating conditions.  */
#define OTPC_WPSR_SEQE_0                      (OTPC_WPSR_SEQE_0_Val << OTPC_WPSR_SEQE_Pos)         /* (OTPC_WPSR) No peripheral internal sequencer error has occurred since the last read of OTPC_WPSR. Position  */
#define OTPC_WPSR_SEQE_1                      (OTPC_WPSR_SEQE_1_Val << OTPC_WPSR_SEQE_Pos)         /* (OTPC_WPSR) A peripheral internal sequencer error has occurred since the last read of OTPC_WPSR. This flag can be set under abnormal operating conditions. Position  */
#define OTPC_WPSR_SWE_Pos                     _UINT32_(3)                                          /* (OTPC_WPSR) Software Control Error (cleared on read) Position */
#define OTPC_WPSR_SWE_Msk                     (_UINT32_(0x1) << OTPC_WPSR_SWE_Pos)                 /* (OTPC_WPSR) Software Control Error (cleared on read) Mask */
#define OTPC_WPSR_SWE(value)                  (OTPC_WPSR_SWE_Msk & (_UINT32_(value) << OTPC_WPSR_SWE_Pos)) /* Assigment of value for SWE in the OTPC_WPSR register */
#define   OTPC_WPSR_SWE_0_Val                 _UINT32_(0x0)                                        /* (OTPC_WPSR) No software error has occurred since the last read of OTPC_WPSR.  */
#define   OTPC_WPSR_SWE_1_Val                 _UINT32_(0x1)                                        /* (OTPC_WPSR) A software error has occurred since the last read of OTPC_WPSR. The field SWETYP details the type of software error encountered.  */
#define OTPC_WPSR_SWE_0                       (OTPC_WPSR_SWE_0_Val << OTPC_WPSR_SWE_Pos)           /* (OTPC_WPSR) No software error has occurred since the last read of OTPC_WPSR. Position  */
#define OTPC_WPSR_SWE_1                       (OTPC_WPSR_SWE_1_Val << OTPC_WPSR_SWE_Pos)           /* (OTPC_WPSR) A software error has occurred since the last read of OTPC_WPSR. The field SWETYP details the type of software error encountered. Position  */
#define OTPC_WPSR_WPVSRC_Pos                  _UINT32_(8)                                          /* (OTPC_WPSR) Write Protection Violation Source Position */
#define OTPC_WPSR_WPVSRC_Msk                  (_UINT32_(0xFFFF) << OTPC_WPSR_WPVSRC_Pos)           /* (OTPC_WPSR) Write Protection Violation Source Mask */
#define OTPC_WPSR_WPVSRC(value)               (OTPC_WPSR_WPVSRC_Msk & (_UINT32_(value) << OTPC_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the OTPC_WPSR register */
#define OTPC_WPSR_SWETYP_Pos                  _UINT32_(24)                                         /* (OTPC_WPSR) Software Error Type Position */
#define OTPC_WPSR_SWETYP_Msk                  (_UINT32_(0xF) << OTPC_WPSR_SWETYP_Pos)              /* (OTPC_WPSR) Software Error Type Mask */
#define OTPC_WPSR_SWETYP(value)               (OTPC_WPSR_SWETYP_Msk & (_UINT32_(value) << OTPC_WPSR_SWETYP_Pos)) /* Assigment of value for SWETYP in the OTPC_WPSR register */
#define   OTPC_WPSR_SWETYP_READ_WO_Val        _UINT32_(0x0)                                        /* (OTPC_WPSR) A write-only register has been read (warning).  */
#define   OTPC_WPSR_SWETYP_WRITE_RO_Val       _UINT32_(0x1)                                        /* (OTPC_WPSR) A write access has been performed on a read-only register (warning).  */
#define   OTPC_WPSR_SWETYP_CONF_CHG_Val       _UINT32_(0x2)                                        /* (OTPC_WPSR) A change has been made into the configuration (error).  */
#define   OTPC_WPSR_SWETYP_KEY_ERROR_Val      _UINT32_(0x3)                                        /* (OTPC_WPSR) A write has been computed in OTPC_CR or OTPC_WPMR register with a wrong value in the related KEY field (error).  */
#define OTPC_WPSR_SWETYP_READ_WO              (OTPC_WPSR_SWETYP_READ_WO_Val << OTPC_WPSR_SWETYP_Pos) /* (OTPC_WPSR) A write-only register has been read (warning). Position  */
#define OTPC_WPSR_SWETYP_WRITE_RO             (OTPC_WPSR_SWETYP_WRITE_RO_Val << OTPC_WPSR_SWETYP_Pos) /* (OTPC_WPSR) A write access has been performed on a read-only register (warning). Position  */
#define OTPC_WPSR_SWETYP_CONF_CHG             (OTPC_WPSR_SWETYP_CONF_CHG_Val << OTPC_WPSR_SWETYP_Pos) /* (OTPC_WPSR) A change has been made into the configuration (error). Position  */
#define OTPC_WPSR_SWETYP_KEY_ERROR            (OTPC_WPSR_SWETYP_KEY_ERROR_Val << OTPC_WPSR_SWETYP_Pos) /* (OTPC_WPSR) A write has been computed in OTPC_CR or OTPC_WPMR register with a wrong value in the related KEY field (error). Position  */
#define OTPC_WPSR_ECLASS_Pos                  _UINT32_(31)                                         /* (OTPC_WPSR) Software Error Class Position */
#define OTPC_WPSR_ECLASS_Msk                  (_UINT32_(0x1) << OTPC_WPSR_ECLASS_Pos)              /* (OTPC_WPSR) Software Error Class Mask */
#define OTPC_WPSR_ECLASS(value)               (OTPC_WPSR_ECLASS_Msk & (_UINT32_(value) << OTPC_WPSR_ECLASS_Pos)) /* Assigment of value for ECLASS in the OTPC_WPSR register */
#define   OTPC_WPSR_ECLASS_WARNING_Val        _UINT32_(0x0)                                        /* (OTPC_WPSR) An abnormal access that does not have any impact.  */
#define   OTPC_WPSR_ECLASS_ERROR_Val          _UINT32_(0x1)                                        /* (OTPC_WPSR) An abnormal access that may have an impact.  */
#define OTPC_WPSR_ECLASS_WARNING              (OTPC_WPSR_ECLASS_WARNING_Val << OTPC_WPSR_ECLASS_Pos) /* (OTPC_WPSR) An abnormal access that does not have any impact. Position  */
#define OTPC_WPSR_ECLASS_ERROR                (OTPC_WPSR_ECLASS_ERROR_Val << OTPC_WPSR_ECLASS_Pos) /* (OTPC_WPSR) An abnormal access that may have an impact. Position  */
#define OTPC_WPSR_Msk                         _UINT32_(0x8FFFFF0F)                                 /* (OTPC_WPSR) Register Mask  */


/** \brief OTPC register offsets definitions */
#define OTPC_CR_REG_OFST               _UINT32_(0x00)      /* (OTPC_CR) Control Register Offset */
#define OTPC_MR_REG_OFST               _UINT32_(0x04)      /* (OTPC_MR) Mode Register Offset */
#define OTPC_AR_REG_OFST               _UINT32_(0x08)      /* (OTPC_AR) Address Register Offset */
#define OTPC_SR_REG_OFST               _UINT32_(0x0C)      /* (OTPC_SR) Status Register Offset */
#define OTPC_IER_REG_OFST              _UINT32_(0x10)      /* (OTPC_IER) Interrupt Enable Register Offset */
#define OTPC_IDR_REG_OFST              _UINT32_(0x14)      /* (OTPC_IDR) Interrupt Disable Register Offset */
#define OTPC_IMR_REG_OFST              _UINT32_(0x18)      /* (OTPC_IMR) Interrupt Mask Register Offset */
#define OTPC_ISR_REG_OFST              _UINT32_(0x1C)      /* (OTPC_ISR) Interrupt Status Register Offset */
#define OTPC_HR_REG_OFST               _UINT32_(0x20)      /* (OTPC_HR) Header Register Offset */
#define OTPC_DR_REG_OFST               _UINT32_(0x24)      /* (OTPC_DR) Data Register Offset */
#define OTPC_BAR_REG_OFST              _UINT32_(0x30)      /* (OTPC_BAR) Boot Addresses Register Offset */
#define OTPC_CAR_REG_OFST              _UINT32_(0x34)      /* (OTPC_CAR) Custom Address Register Offset */
#define OTPC_LRMR_REG_OFST             _UINT32_(0x40)      /* (OTPC_LRMR) Live Repair Mode Register Offset */
#define OTPC_UHC0R_REG_OFST            _UINT32_(0x50)      /* (OTPC_UHC0R) User Hardware Configuration 0 Register Offset */
#define OTPC_UHC1R_REG_OFST            _UINT32_(0x54)      /* (OTPC_UHC1R) User Hardware Configuration 1 Register Offset */
#define OTPC_UID0R_REG_OFST            _UINT32_(0x60)      /* (OTPC_UID0R) Product UID 0 Register Offset */
#define OTPC_UID1R_REG_OFST            _UINT32_(0x64)      /* (OTPC_UID1R) Product UID 1 Register Offset */
#define OTPC_UID2R_REG_OFST            _UINT32_(0x68)      /* (OTPC_UID2R) Product UID 2 Register Offset */
#define OTPC_UID3R_REG_OFST            _UINT32_(0x6C)      /* (OTPC_UID3R) Product UID 3 Register Offset */
#define OTPC_WPMR_REG_OFST             _UINT32_(0xE4)      /* (OTPC_WPMR) Write Protection Mode Register Offset */
#define OTPC_WPSR_REG_OFST             _UINT32_(0xE8)      /* (OTPC_WPSR) Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief OTPC register API structure */
typedef struct
{  /* OTP Memory Controller */
  __O   uint32_t                       OTPC_CR;            /**< Offset: 0x00 ( /W  32) Control Register */
  __IO  uint32_t                       OTPC_MR;            /**< Offset: 0x04 (R/W  32) Mode Register */
  __IO  uint32_t                       OTPC_AR;            /**< Offset: 0x08 (R/W  32) Address Register */
  __I   uint32_t                       OTPC_SR;            /**< Offset: 0x0C (R/   32) Status Register */
  __O   uint32_t                       OTPC_IER;           /**< Offset: 0x10 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       OTPC_IDR;           /**< Offset: 0x14 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       OTPC_IMR;           /**< Offset: 0x18 (R/   32) Interrupt Mask Register */
  __I   uint32_t                       OTPC_ISR;           /**< Offset: 0x1C (R/   32) Interrupt Status Register */
  __IO  uint32_t                       OTPC_HR;            /**< Offset: 0x20 (R/W  32) Header Register */
  __IO  uint32_t                       OTPC_DR;            /**< Offset: 0x24 (R/W  32) Data Register */
  __I   uint8_t                        Reserved1[0x08];
  __I   uint32_t                       OTPC_BAR;           /**< Offset: 0x30 (R/   32) Boot Addresses Register */
  __I   uint32_t                       OTPC_CAR;           /**< Offset: 0x34 (R/   32) Custom Address Register */
  __I   uint8_t                        Reserved2[0x08];
  __IO  uint32_t                       OTPC_LRMR;          /**< Offset: 0x40 (R/W  32) Live Repair Mode Register */
  __I   uint8_t                        Reserved3[0x0C];
  __I   uint32_t                       OTPC_UHC0R;         /**< Offset: 0x50 (R/   32) User Hardware Configuration 0 Register */
  __I   uint32_t                       OTPC_UHC1R;         /**< Offset: 0x54 (R/   32) User Hardware Configuration 1 Register */
  __I   uint8_t                        Reserved4[0x08];
  __I   uint32_t                       OTPC_UID0R;         /**< Offset: 0x60 (R/   32) Product UID 0 Register */
  __I   uint32_t                       OTPC_UID1R;         /**< Offset: 0x64 (R/   32) Product UID 1 Register */
  __I   uint32_t                       OTPC_UID2R;         /**< Offset: 0x68 (R/   32) Product UID 2 Register */
  __I   uint32_t                       OTPC_UID3R;         /**< Offset: 0x6C (R/   32) Product UID 3 Register */
  __I   uint8_t                        Reserved5[0x74];
  __IO  uint32_t                       OTPC_WPMR;          /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   uint32_t                       OTPC_WPSR;          /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
} otpc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X7_OTPC_COMPONENT_H_ */
