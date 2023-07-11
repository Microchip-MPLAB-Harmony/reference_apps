/*
 * Component description for QSPI
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
#ifndef _SAM9X7_QSPI_COMPONENT_H_
#define _SAM9X7_QSPI_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR QSPI                                         */
/* ************************************************************************** */

/* -------- QSPI_CR : (QSPI Offset: 0x00) ( /W 32) Control Register -------- */
#define QSPI_CR_QSPIEN_Pos                    _UINT32_(0)                                          /* (QSPI_CR) QSPI Enable Position */
#define QSPI_CR_QSPIEN_Msk                    (_UINT32_(0x1) << QSPI_CR_QSPIEN_Pos)                /* (QSPI_CR) QSPI Enable Mask */
#define QSPI_CR_QSPIEN(value)                 (QSPI_CR_QSPIEN_Msk & (_UINT32_(value) << QSPI_CR_QSPIEN_Pos)) /* Assigment of value for QSPIEN in the QSPI_CR register */
#define   QSPI_CR_QSPIEN_0_Val                _UINT32_(0x0)                                        /* (QSPI_CR) No effect.  */
#define   QSPI_CR_QSPIEN_1_Val                _UINT32_(0x1)                                        /* (QSPI_CR) Enables the QSPI to transfer and receive data.  */
#define QSPI_CR_QSPIEN_0                      (QSPI_CR_QSPIEN_0_Val << QSPI_CR_QSPIEN_Pos)         /* (QSPI_CR) No effect. Position  */
#define QSPI_CR_QSPIEN_1                      (QSPI_CR_QSPIEN_1_Val << QSPI_CR_QSPIEN_Pos)         /* (QSPI_CR) Enables the QSPI to transfer and receive data. Position  */
#define QSPI_CR_QSPIDIS_Pos                   _UINT32_(1)                                          /* (QSPI_CR) QSPI Disable Position */
#define QSPI_CR_QSPIDIS_Msk                   (_UINT32_(0x1) << QSPI_CR_QSPIDIS_Pos)               /* (QSPI_CR) QSPI Disable Mask */
#define QSPI_CR_QSPIDIS(value)                (QSPI_CR_QSPIDIS_Msk & (_UINT32_(value) << QSPI_CR_QSPIDIS_Pos)) /* Assigment of value for QSPIDIS in the QSPI_CR register */
#define   QSPI_CR_QSPIDIS_0_Val               _UINT32_(0x0)                                        /* (QSPI_CR) No effect.  */
#define   QSPI_CR_QSPIDIS_1_Val               _UINT32_(0x1)                                        /* (QSPI_CR) Disables the QSPI.  */
#define QSPI_CR_QSPIDIS_0                     (QSPI_CR_QSPIDIS_0_Val << QSPI_CR_QSPIDIS_Pos)       /* (QSPI_CR) No effect. Position  */
#define QSPI_CR_QSPIDIS_1                     (QSPI_CR_QSPIDIS_1_Val << QSPI_CR_QSPIDIS_Pos)       /* (QSPI_CR) Disables the QSPI. Position  */
#define QSPI_CR_SRFRSH_Pos                    _UINT32_(5)                                          /* (QSPI_CR) Start REFRESH Position */
#define QSPI_CR_SRFRSH_Msk                    (_UINT32_(0x1) << QSPI_CR_SRFRSH_Pos)                /* (QSPI_CR) Start REFRESH Mask */
#define QSPI_CR_SRFRSH(value)                 (QSPI_CR_SRFRSH_Msk & (_UINT32_(value) << QSPI_CR_SRFRSH_Pos)) /* Assigment of value for SRFRSH in the QSPI_CR register */
#define   QSPI_CR_SRFRSH_0_Val                _UINT32_(0x0)                                        /* (QSPI_CR) No effect.  */
#define   QSPI_CR_SRFRSH_1_Val                _UINT32_(0x1)                                        /* (QSPI_CR) Starts a refresh sequence. QSPI_ISR.RFRSHD indicates when the refresh sequence is over.  */
#define QSPI_CR_SRFRSH_0                      (QSPI_CR_SRFRSH_0_Val << QSPI_CR_SRFRSH_Pos)         /* (QSPI_CR) No effect. Position  */
#define QSPI_CR_SRFRSH_1                      (QSPI_CR_SRFRSH_1_Val << QSPI_CR_SRFRSH_Pos)         /* (QSPI_CR) Starts a refresh sequence. QSPI_ISR.RFRSHD indicates when the refresh sequence is over. Position  */
#define QSPI_CR_SWRST_Pos                     _UINT32_(7)                                          /* (QSPI_CR) QSPI Software Reset Position */
#define QSPI_CR_SWRST_Msk                     (_UINT32_(0x1) << QSPI_CR_SWRST_Pos)                 /* (QSPI_CR) QSPI Software Reset Mask */
#define QSPI_CR_SWRST(value)                  (QSPI_CR_SWRST_Msk & (_UINT32_(value) << QSPI_CR_SWRST_Pos)) /* Assigment of value for SWRST in the QSPI_CR register */
#define   QSPI_CR_SWRST_0_Val                 _UINT32_(0x0)                                        /* (QSPI_CR) No effect.  */
#define   QSPI_CR_SWRST_1_Val                 _UINT32_(0x1)                                        /* (QSPI_CR) Resets the QSPI. A software-triggered hardware reset of the QSPI interface is performed.  */
#define QSPI_CR_SWRST_0                       (QSPI_CR_SWRST_0_Val << QSPI_CR_SWRST_Pos)           /* (QSPI_CR) No effect. Position  */
#define QSPI_CR_SWRST_1                       (QSPI_CR_SWRST_1_Val << QSPI_CR_SWRST_Pos)           /* (QSPI_CR) Resets the QSPI. A software-triggered hardware reset of the QSPI interface is performed. Position  */
#define QSPI_CR_UPDCFG_Pos                    _UINT32_(8)                                          /* (QSPI_CR) Update Configuration Position */
#define QSPI_CR_UPDCFG_Msk                    (_UINT32_(0x1) << QSPI_CR_UPDCFG_Pos)                /* (QSPI_CR) Update Configuration Mask */
#define QSPI_CR_UPDCFG(value)                 (QSPI_CR_UPDCFG_Msk & (_UINT32_(value) << QSPI_CR_UPDCFG_Pos)) /* Assigment of value for UPDCFG in the QSPI_CR register */
#define   QSPI_CR_UPDCFG_0_Val                _UINT32_(0x0)                                        /* (QSPI_CR) No effect.  */
#define   QSPI_CR_UPDCFG_1_Val                _UINT32_(0x1)                                        /* (QSPI_CR) Requests an update of the QSPI Controller core configuration.  */
#define QSPI_CR_UPDCFG_0                      (QSPI_CR_UPDCFG_0_Val << QSPI_CR_UPDCFG_Pos)         /* (QSPI_CR) No effect. Position  */
#define QSPI_CR_UPDCFG_1                      (QSPI_CR_UPDCFG_1_Val << QSPI_CR_UPDCFG_Pos)         /* (QSPI_CR) Requests an update of the QSPI Controller core configuration. Position  */
#define QSPI_CR_STTFR_Pos                     _UINT32_(9)                                          /* (QSPI_CR) Start Transfer Position */
#define QSPI_CR_STTFR_Msk                     (_UINT32_(0x1) << QSPI_CR_STTFR_Pos)                 /* (QSPI_CR) Start Transfer Mask */
#define QSPI_CR_STTFR(value)                  (QSPI_CR_STTFR_Msk & (_UINT32_(value) << QSPI_CR_STTFR_Pos)) /* Assigment of value for STTFR in the QSPI_CR register */
#define   QSPI_CR_STTFR_0_Val                 _UINT32_(0x0)                                        /* (QSPI_CR) No effect.  */
#define   QSPI_CR_STTFR_1_Val                 _UINT32_(0x1)                                        /* (QSPI_CR) Starts the transfer when TFRTYP = 0 and SMRM = 1 or when DATAEN = 0.  */
#define QSPI_CR_STTFR_0                       (QSPI_CR_STTFR_0_Val << QSPI_CR_STTFR_Pos)           /* (QSPI_CR) No effect. Position  */
#define QSPI_CR_STTFR_1                       (QSPI_CR_STTFR_1_Val << QSPI_CR_STTFR_Pos)           /* (QSPI_CR) Starts the transfer when TFRTYP = 0 and SMRM = 1 or when DATAEN = 0. Position  */
#define QSPI_CR_RTOUT_Pos                     _UINT32_(10)                                         /* (QSPI_CR) Reset Time-out Position */
#define QSPI_CR_RTOUT_Msk                     (_UINT32_(0x1) << QSPI_CR_RTOUT_Pos)                 /* (QSPI_CR) Reset Time-out Mask */
#define QSPI_CR_RTOUT(value)                  (QSPI_CR_RTOUT_Msk & (_UINT32_(value) << QSPI_CR_RTOUT_Pos)) /* Assigment of value for RTOUT in the QSPI_CR register */
#define   QSPI_CR_RTOUT_0_Val                 _UINT32_(0x0)                                        /* (QSPI_CR) No effect.  */
#define   QSPI_CR_RTOUT_1_Val                 _UINT32_(0x1)                                        /* (QSPI_CR) Request a TOUT flag reset.  */
#define QSPI_CR_RTOUT_0                       (QSPI_CR_RTOUT_0_Val << QSPI_CR_RTOUT_Pos)           /* (QSPI_CR) No effect. Position  */
#define QSPI_CR_RTOUT_1                       (QSPI_CR_RTOUT_1_Val << QSPI_CR_RTOUT_Pos)           /* (QSPI_CR) Request a TOUT flag reset. Position  */
#define QSPI_CR_LASTXFER_Pos                  _UINT32_(24)                                         /* (QSPI_CR) Last Transfer Position */
#define QSPI_CR_LASTXFER_Msk                  (_UINT32_(0x1) << QSPI_CR_LASTXFER_Pos)              /* (QSPI_CR) Last Transfer Mask */
#define QSPI_CR_LASTXFER(value)               (QSPI_CR_LASTXFER_Msk & (_UINT32_(value) << QSPI_CR_LASTXFER_Pos)) /* Assigment of value for LASTXFER in the QSPI_CR register */
#define   QSPI_CR_LASTXFER_0_Val              _UINT32_(0x0)                                        /* (QSPI_CR) No effect.  */
#define   QSPI_CR_LASTXFER_1_Val              _UINT32_(0x1)                                        /* (QSPI_CR) The chip select is deasserted after the end of character transmission.  */
#define QSPI_CR_LASTXFER_0                    (QSPI_CR_LASTXFER_0_Val << QSPI_CR_LASTXFER_Pos)     /* (QSPI_CR) No effect. Position  */
#define QSPI_CR_LASTXFER_1                    (QSPI_CR_LASTXFER_1_Val << QSPI_CR_LASTXFER_Pos)     /* (QSPI_CR) The chip select is deasserted after the end of character transmission. Position  */
#define QSPI_CR_Msk                           _UINT32_(0x010007A3)                                 /* (QSPI_CR) Register Mask  */


/* -------- QSPI_MR : (QSPI Offset: 0x04) (R/W 32) Mode Register -------- */
#define QSPI_MR_RESETVALUE                    _UINT32_(0x00)                                       /*  (QSPI_MR) Mode Register  Reset Value */

#define QSPI_MR_SMM_Pos                       _UINT32_(0)                                          /* (QSPI_MR) Serial Memory Mode Position */
#define QSPI_MR_SMM_Msk                       (_UINT32_(0x1) << QSPI_MR_SMM_Pos)                   /* (QSPI_MR) Serial Memory Mode Mask */
#define QSPI_MR_SMM(value)                    (QSPI_MR_SMM_Msk & (_UINT32_(value) << QSPI_MR_SMM_Pos)) /* Assigment of value for SMM in the QSPI_MR register */
#define   QSPI_MR_SMM_SPI_Val                 _UINT32_(0x0)                                        /* (QSPI_MR) The QSPI is in SPI mode.  */
#define   QSPI_MR_SMM_MEMORY_Val              _UINT32_(0x1)                                        /* (QSPI_MR) The QSPI is in Serial Memory mode.  */
#define QSPI_MR_SMM_SPI                       (QSPI_MR_SMM_SPI_Val << QSPI_MR_SMM_Pos)             /* (QSPI_MR) The QSPI is in SPI mode. Position  */
#define QSPI_MR_SMM_MEMORY                    (QSPI_MR_SMM_MEMORY_Val << QSPI_MR_SMM_Pos)          /* (QSPI_MR) The QSPI is in Serial Memory mode. Position  */
#define QSPI_MR_WDRBT_Pos                     _UINT32_(2)                                          /* (QSPI_MR) Wait Data Read Before Transfer Position */
#define QSPI_MR_WDRBT_Msk                     (_UINT32_(0x1) << QSPI_MR_WDRBT_Pos)                 /* (QSPI_MR) Wait Data Read Before Transfer Mask */
#define QSPI_MR_WDRBT(value)                  (QSPI_MR_WDRBT_Msk & (_UINT32_(value) << QSPI_MR_WDRBT_Pos)) /* Assigment of value for WDRBT in the QSPI_MR register */
#define   QSPI_MR_WDRBT_DISABLED_Val          _UINT32_(0x0)                                        /* (QSPI_MR) No effect. In SPI mode, a transfer can be initiated whatever the state of QSPI_RDR is.  */
#define   QSPI_MR_WDRBT_ENABLED_Val           _UINT32_(0x1)                                        /* (QSPI_MR) In SPI mode, a transfer can start only if QSPI_RDR is empty, i.e., does not contain any unread data. This mode prevents overrun error in reception.  */
#define QSPI_MR_WDRBT_DISABLED                (QSPI_MR_WDRBT_DISABLED_Val << QSPI_MR_WDRBT_Pos)    /* (QSPI_MR) No effect. In SPI mode, a transfer can be initiated whatever the state of QSPI_RDR is. Position  */
#define QSPI_MR_WDRBT_ENABLED                 (QSPI_MR_WDRBT_ENABLED_Val << QSPI_MR_WDRBT_Pos)     /* (QSPI_MR) In SPI mode, a transfer can start only if QSPI_RDR is empty, i.e., does not contain any unread data. This mode prevents overrun error in reception. Position  */
#define QSPI_MR_DQSDLYEN_Pos                  _UINT32_(3)                                          /* (QSPI_MR) DQS Delay Enable Position */
#define QSPI_MR_DQSDLYEN_Msk                  (_UINT32_(0x1) << QSPI_MR_DQSDLYEN_Pos)              /* (QSPI_MR) DQS Delay Enable Mask */
#define QSPI_MR_DQSDLYEN(value)               (QSPI_MR_DQSDLYEN_Msk & (_UINT32_(value) << QSPI_MR_DQSDLYEN_Pos)) /* Assigment of value for DQSDLYEN in the QSPI_MR register */
#define   QSPI_MR_DQSDLYEN_DISABLED_Val       _UINT32_(0x0)                                        /* (QSPI_MR) DQS Delay cell is disabled.  */
#define   QSPI_MR_DQSDLYEN_ENABLED_Val        _UINT32_(0x1)                                        /* (QSPI_MR) DQS Delay cell is enabled. The DQS Delay cell automatic refresh is triggered according to the configuration of QSPI_REFRESH.  */
#define QSPI_MR_DQSDLYEN_DISABLED             (QSPI_MR_DQSDLYEN_DISABLED_Val << QSPI_MR_DQSDLYEN_Pos) /* (QSPI_MR) DQS Delay cell is disabled. Position  */
#define QSPI_MR_DQSDLYEN_ENABLED              (QSPI_MR_DQSDLYEN_ENABLED_Val << QSPI_MR_DQSDLYEN_Pos) /* (QSPI_MR) DQS Delay cell is enabled. The DQS Delay cell automatic refresh is triggered according to the configuration of QSPI_REFRESH. Position  */
#define QSPI_MR_CSMODE_Pos                    _UINT32_(4)                                          /* (QSPI_MR) Chip Select Mode Position */
#define QSPI_MR_CSMODE_Msk                    (_UINT32_(0x3) << QSPI_MR_CSMODE_Pos)                /* (QSPI_MR) Chip Select Mode Mask */
#define QSPI_MR_CSMODE(value)                 (QSPI_MR_CSMODE_Msk & (_UINT32_(value) << QSPI_MR_CSMODE_Pos)) /* Assigment of value for CSMODE in the QSPI_MR register */
#define   QSPI_MR_CSMODE_NOT_RELOADED_Val     _UINT32_(0x0)                                        /* (QSPI_MR) The chip select is deasserted if QSPI_TDR.TD has not been reloaded before the end of the current transfer.  */
#define   QSPI_MR_CSMODE_LASTXFER_Val         _UINT32_(0x1)                                        /* (QSPI_MR) The chip select is deasserted when the bit LASTXFER is written to '1' and the character written in QSPI_TDR.TD has been transferred.  */
#define   QSPI_MR_CSMODE_SYSTEMATICALLY_Val   _UINT32_(0x2)                                        /* (QSPI_MR) The chip select is deasserted systematically after each transfer.  */
#define QSPI_MR_CSMODE_NOT_RELOADED           (QSPI_MR_CSMODE_NOT_RELOADED_Val << QSPI_MR_CSMODE_Pos) /* (QSPI_MR) The chip select is deasserted if QSPI_TDR.TD has not been reloaded before the end of the current transfer. Position  */
#define QSPI_MR_CSMODE_LASTXFER               (QSPI_MR_CSMODE_LASTXFER_Val << QSPI_MR_CSMODE_Pos)  /* (QSPI_MR) The chip select is deasserted when the bit LASTXFER is written to '1' and the character written in QSPI_TDR.TD has been transferred. Position  */
#define QSPI_MR_CSMODE_SYSTEMATICALLY         (QSPI_MR_CSMODE_SYSTEMATICALLY_Val << QSPI_MR_CSMODE_Pos) /* (QSPI_MR) The chip select is deasserted systematically after each transfer. Position  */
#define QSPI_MR_TAMPCLR_Pos                   _UINT32_(7)                                          /* (QSPI_MR) Tamper Clear Enable Position */
#define QSPI_MR_TAMPCLR_Msk                   (_UINT32_(0x1) << QSPI_MR_TAMPCLR_Pos)               /* (QSPI_MR) Tamper Clear Enable Mask */
#define QSPI_MR_TAMPCLR(value)                (QSPI_MR_TAMPCLR_Msk & (_UINT32_(value) << QSPI_MR_TAMPCLR_Pos)) /* Assigment of value for TAMPCLR in the QSPI_MR register */
#define   QSPI_MR_TAMPCLR_0_Val               _UINT32_(0x0)                                        /* (QSPI_MR) A tamper detection event has no effect on QSPI scrambling keys.  */
#define   QSPI_MR_TAMPCLR_1_Val               _UINT32_(0x1)                                        /* (QSPI_MR) A tamper detection event immediately clears QSPI scrambling keys.  */
#define QSPI_MR_TAMPCLR_0                     (QSPI_MR_TAMPCLR_0_Val << QSPI_MR_TAMPCLR_Pos)       /* (QSPI_MR) A tamper detection event has no effect on QSPI scrambling keys. Position  */
#define QSPI_MR_TAMPCLR_1                     (QSPI_MR_TAMPCLR_1_Val << QSPI_MR_TAMPCLR_Pos)       /* (QSPI_MR) A tamper detection event immediately clears QSPI scrambling keys. Position  */
#define QSPI_MR_NBBITS_Pos                    _UINT32_(8)                                          /* (QSPI_MR) Number Of Bits Per Transfer Position */
#define QSPI_MR_NBBITS_Msk                    (_UINT32_(0xF) << QSPI_MR_NBBITS_Pos)                /* (QSPI_MR) Number Of Bits Per Transfer Mask */
#define QSPI_MR_NBBITS(value)                 (QSPI_MR_NBBITS_Msk & (_UINT32_(value) << QSPI_MR_NBBITS_Pos)) /* Assigment of value for NBBITS in the QSPI_MR register */
#define   QSPI_MR_NBBITS_8_BIT_Val            _UINT32_(0x0)                                        /* (QSPI_MR) 8 bits for transfer  */
#define   QSPI_MR_NBBITS_16_BIT_Val           _UINT32_(0x8)                                        /* (QSPI_MR) 16 bits for transfer  */
#define QSPI_MR_NBBITS_8_BIT                  (QSPI_MR_NBBITS_8_BIT_Val << QSPI_MR_NBBITS_Pos)     /* (QSPI_MR) 8 bits for transfer Position  */
#define QSPI_MR_NBBITS_16_BIT                 (QSPI_MR_NBBITS_16_BIT_Val << QSPI_MR_NBBITS_Pos)    /* (QSPI_MR) 16 bits for transfer Position  */
#define QSPI_MR_QICMEN_Pos                    _UINT32_(13)                                         /* (QSPI_MR) QSPI Inter-chip Mode Enable Position */
#define QSPI_MR_QICMEN_Msk                    (_UINT32_(0x1) << QSPI_MR_QICMEN_Pos)                /* (QSPI_MR) QSPI Inter-chip Mode Enable Mask */
#define QSPI_MR_QICMEN(value)                 (QSPI_MR_QICMEN_Msk & (_UINT32_(value) << QSPI_MR_QICMEN_Pos)) /* Assigment of value for QICMEN in the QSPI_MR register */
#define   QSPI_MR_QICMEN_DISABLED_Val         _UINT32_(0x0)                                        /* (QSPI_MR) QSPI_WICR.WROPT and QSPI_RICR.RDOPT define the transfer options and QSPI_IFR.NBDUM defines the number of dummy cycles.  */
#define   QSPI_MR_QICMEN_ENABLED_Val          _UINT32_(0x1)                                        /* (QSPI_MR) No dummy cycles are inserted for write accesses, whatever the value configured in QSPI_IFR.NBDUM. The option field of the frame is automatically generated by the QSPI depending on the type of system bus transfer (the fields QSPI_RICR.RDOPT and QSPI_WICR.WROPT have no effect).  */
#define QSPI_MR_QICMEN_DISABLED               (QSPI_MR_QICMEN_DISABLED_Val << QSPI_MR_QICMEN_Pos)  /* (QSPI_MR) QSPI_WICR.WROPT and QSPI_RICR.RDOPT define the transfer options and QSPI_IFR.NBDUM defines the number of dummy cycles. Position  */
#define QSPI_MR_QICMEN_ENABLED                (QSPI_MR_QICMEN_ENABLED_Val << QSPI_MR_QICMEN_Pos)   /* (QSPI_MR) No dummy cycles are inserted for write accesses, whatever the value configured in QSPI_IFR.NBDUM. The option field of the frame is automatically generated by the QSPI depending on the type of system bus transfer (the fields QSPI_RICR.RDOPT and QSPI_WICR.WROPT have no effect). Position  */
#define QSPI_MR_OENSD_Pos                     _UINT32_(15)                                         /* (QSPI_MR) Output Enable Shift Disabled Position */
#define QSPI_MR_OENSD_Msk                     (_UINT32_(0x1) << QSPI_MR_OENSD_Pos)                 /* (QSPI_MR) Output Enable Shift Disabled Mask */
#define QSPI_MR_OENSD(value)                  (QSPI_MR_OENSD_Msk & (_UINT32_(value) << QSPI_MR_OENSD_Pos)) /* Assigment of value for OENSD in the QSPI_MR register */
#define   QSPI_MR_OENSD_0_Val                 _UINT32_(0x0)                                        /* (QSPI_MR) By default, the pad output enable signal is held for one QSCK period during the dummy cycles if QSPI.IFR_NBDUM is not equal to '0'.  */
#define   QSPI_MR_OENSD_1_Val                 _UINT32_(0x1)                                        /* (QSPI_MR) The pad output enable signal is not held for one QSCK period during the dummy cycles.  */
#define QSPI_MR_OENSD_0                       (QSPI_MR_OENSD_0_Val << QSPI_MR_OENSD_Pos)           /* (QSPI_MR) By default, the pad output enable signal is held for one QSCK period during the dummy cycles if QSPI.IFR_NBDUM is not equal to '0'. Position  */
#define QSPI_MR_OENSD_1                       (QSPI_MR_OENSD_1_Val << QSPI_MR_OENSD_Pos)           /* (QSPI_MR) The pad output enable signal is not held for one QSCK period during the dummy cycles. Position  */
#define QSPI_MR_DLYBCT_Pos                    _UINT32_(16)                                         /* (QSPI_MR) Delay Between Consecutive Transfers Position */
#define QSPI_MR_DLYBCT_Msk                    (_UINT32_(0xFF) << QSPI_MR_DLYBCT_Pos)               /* (QSPI_MR) Delay Between Consecutive Transfers Mask */
#define QSPI_MR_DLYBCT(value)                 (QSPI_MR_DLYBCT_Msk & (_UINT32_(value) << QSPI_MR_DLYBCT_Pos)) /* Assigment of value for DLYBCT in the QSPI_MR register */
#define QSPI_MR_DLYCS_Pos                     _UINT32_(24)                                         /* (QSPI_MR) Minimum Inactive QCS Delay Position */
#define QSPI_MR_DLYCS_Msk                     (_UINT32_(0xFF) << QSPI_MR_DLYCS_Pos)                /* (QSPI_MR) Minimum Inactive QCS Delay Mask */
#define QSPI_MR_DLYCS(value)                  (QSPI_MR_DLYCS_Msk & (_UINT32_(value) << QSPI_MR_DLYCS_Pos)) /* Assigment of value for DLYCS in the QSPI_MR register */
#define QSPI_MR_Msk                           _UINT32_(0xFFFFAFBD)                                 /* (QSPI_MR) Register Mask  */


/* -------- QSPI_RDR : (QSPI Offset: 0x08) ( R/ 32) Receive Data Register -------- */
#define QSPI_RDR_RESETVALUE                   _UINT32_(0x00)                                       /*  (QSPI_RDR) Receive Data Register  Reset Value */

#define QSPI_RDR_RD_Pos                       _UINT32_(0)                                          /* (QSPI_RDR) Receive Data Position */
#define QSPI_RDR_RD_Msk                       (_UINT32_(0xFFFF) << QSPI_RDR_RD_Pos)                /* (QSPI_RDR) Receive Data Mask */
#define QSPI_RDR_RD(value)                    (QSPI_RDR_RD_Msk & (_UINT32_(value) << QSPI_RDR_RD_Pos)) /* Assigment of value for RD in the QSPI_RDR register */
#define QSPI_RDR_Msk                          _UINT32_(0x0000FFFF)                                 /* (QSPI_RDR) Register Mask  */


/* -------- QSPI_TDR : (QSPI Offset: 0x0C) ( /W 32) Transmit Data Register -------- */
#define QSPI_TDR_TD_Pos                       _UINT32_(0)                                          /* (QSPI_TDR) Transmit Data Position */
#define QSPI_TDR_TD_Msk                       (_UINT32_(0xFFFF) << QSPI_TDR_TD_Pos)                /* (QSPI_TDR) Transmit Data Mask */
#define QSPI_TDR_TD(value)                    (QSPI_TDR_TD_Msk & (_UINT32_(value) << QSPI_TDR_TD_Pos)) /* Assigment of value for TD in the QSPI_TDR register */
#define QSPI_TDR_Msk                          _UINT32_(0x0000FFFF)                                 /* (QSPI_TDR) Register Mask  */


/* -------- QSPI_ISR : (QSPI Offset: 0x10) ( R/ 32) Interrupt Status Register -------- */
#define QSPI_ISR_RESETVALUE                   _UINT32_(0x00)                                       /*  (QSPI_ISR) Interrupt Status Register  Reset Value */

#define QSPI_ISR_RDRF_Pos                     _UINT32_(0)                                          /* (QSPI_ISR) Receive Data Register Full (cleared by reading QSPI_RDR) Position */
#define QSPI_ISR_RDRF_Msk                     (_UINT32_(0x1) << QSPI_ISR_RDRF_Pos)                 /* (QSPI_ISR) Receive Data Register Full (cleared by reading QSPI_RDR) Mask */
#define QSPI_ISR_RDRF(value)                  (QSPI_ISR_RDRF_Msk & (_UINT32_(value) << QSPI_ISR_RDRF_Pos)) /* Assigment of value for RDRF in the QSPI_ISR register */
#define   QSPI_ISR_RDRF_0_Val                 _UINT32_(0x0)                                        /* (QSPI_ISR) No data has been received since the last read of QSPI_RDR.  */
#define   QSPI_ISR_RDRF_1_Val                 _UINT32_(0x1)                                        /* (QSPI_ISR) Data has been received and the received data has been transferred from the serializer to QSPI_RDR since the last read of QSPI_RDR.  */
#define QSPI_ISR_RDRF_0                       (QSPI_ISR_RDRF_0_Val << QSPI_ISR_RDRF_Pos)           /* (QSPI_ISR) No data has been received since the last read of QSPI_RDR. Position  */
#define QSPI_ISR_RDRF_1                       (QSPI_ISR_RDRF_1_Val << QSPI_ISR_RDRF_Pos)           /* (QSPI_ISR) Data has been received and the received data has been transferred from the serializer to QSPI_RDR since the last read of QSPI_RDR. Position  */
#define QSPI_ISR_TDRE_Pos                     _UINT32_(1)                                          /* (QSPI_ISR) Transmit Data Register Empty (cleared by writing QSPI_TDR) Position */
#define QSPI_ISR_TDRE_Msk                     (_UINT32_(0x1) << QSPI_ISR_TDRE_Pos)                 /* (QSPI_ISR) Transmit Data Register Empty (cleared by writing QSPI_TDR) Mask */
#define QSPI_ISR_TDRE(value)                  (QSPI_ISR_TDRE_Msk & (_UINT32_(value) << QSPI_ISR_TDRE_Pos)) /* Assigment of value for TDRE in the QSPI_ISR register */
#define   QSPI_ISR_TDRE_0_Val                 _UINT32_(0x0)                                        /* (QSPI_ISR) Data has been written to QSPI_TDR and not yet transferred to the serializer.  */
#define   QSPI_ISR_TDRE_1_Val                 _UINT32_(0x1)                                        /* (QSPI_ISR) The last data written in the QSPI_TDR has been transferred to the serializer.  */
#define QSPI_ISR_TDRE_0                       (QSPI_ISR_TDRE_0_Val << QSPI_ISR_TDRE_Pos)           /* (QSPI_ISR) Data has been written to QSPI_TDR and not yet transferred to the serializer. Position  */
#define QSPI_ISR_TDRE_1                       (QSPI_ISR_TDRE_1_Val << QSPI_ISR_TDRE_Pos)           /* (QSPI_ISR) The last data written in the QSPI_TDR has been transferred to the serializer. Position  */
#define QSPI_ISR_TXEMPTY_Pos                  _UINT32_(2)                                          /* (QSPI_ISR) Transmission Registers Empty (cleared by writing QSPI_TDR) Position */
#define QSPI_ISR_TXEMPTY_Msk                  (_UINT32_(0x1) << QSPI_ISR_TXEMPTY_Pos)              /* (QSPI_ISR) Transmission Registers Empty (cleared by writing QSPI_TDR) Mask */
#define QSPI_ISR_TXEMPTY(value)               (QSPI_ISR_TXEMPTY_Msk & (_UINT32_(value) << QSPI_ISR_TXEMPTY_Pos)) /* Assigment of value for TXEMPTY in the QSPI_ISR register */
#define   QSPI_ISR_TXEMPTY_0_Val              _UINT32_(0x0)                                        /* (QSPI_ISR) As soon as data is written in QSPI_TDR.  */
#define   QSPI_ISR_TXEMPTY_1_Val              _UINT32_(0x1)                                        /* (QSPI_ISR) QSPI_TDR and the internal shifter are empty. If a transfer delay has been defined, TXEMPTY is set after the completion of such delay.  */
#define QSPI_ISR_TXEMPTY_0                    (QSPI_ISR_TXEMPTY_0_Val << QSPI_ISR_TXEMPTY_Pos)     /* (QSPI_ISR) As soon as data is written in QSPI_TDR. Position  */
#define QSPI_ISR_TXEMPTY_1                    (QSPI_ISR_TXEMPTY_1_Val << QSPI_ISR_TXEMPTY_Pos)     /* (QSPI_ISR) QSPI_TDR and the internal shifter are empty. If a transfer delay has been defined, TXEMPTY is set after the completion of such delay. Position  */
#define QSPI_ISR_OVRES_Pos                    _UINT32_(3)                                          /* (QSPI_ISR) Overrun Error Status (cleared on read) Position */
#define QSPI_ISR_OVRES_Msk                    (_UINT32_(0x1) << QSPI_ISR_OVRES_Pos)                /* (QSPI_ISR) Overrun Error Status (cleared on read) Mask */
#define QSPI_ISR_OVRES(value)                 (QSPI_ISR_OVRES_Msk & (_UINT32_(value) << QSPI_ISR_OVRES_Pos)) /* Assigment of value for OVRES in the QSPI_ISR register */
#define   QSPI_ISR_OVRES_0_Val                _UINT32_(0x0)                                        /* (QSPI_ISR) No overrun has been detected since the last read of QSPI_ISR.  */
#define   QSPI_ISR_OVRES_1_Val                _UINT32_(0x1)                                        /* (QSPI_ISR) At least one overrun error has occurred since the last read of QSPI_ISR.  */
#define QSPI_ISR_OVRES_0                      (QSPI_ISR_OVRES_0_Val << QSPI_ISR_OVRES_Pos)         /* (QSPI_ISR) No overrun has been detected since the last read of QSPI_ISR. Position  */
#define QSPI_ISR_OVRES_1                      (QSPI_ISR_OVRES_1_Val << QSPI_ISR_OVRES_Pos)         /* (QSPI_ISR) At least one overrun error has occurred since the last read of QSPI_ISR. Position  */
#define QSPI_ISR_CSR_Pos                      _UINT32_(8)                                          /* (QSPI_ISR) Chip Select Rise (cleared on read) Position */
#define QSPI_ISR_CSR_Msk                      (_UINT32_(0x1) << QSPI_ISR_CSR_Pos)                  /* (QSPI_ISR) Chip Select Rise (cleared on read) Mask */
#define QSPI_ISR_CSR(value)                   (QSPI_ISR_CSR_Msk & (_UINT32_(value) << QSPI_ISR_CSR_Pos)) /* Assigment of value for CSR in the QSPI_ISR register */
#define   QSPI_ISR_CSR_0_Val                  _UINT32_(0x0)                                        /* (QSPI_ISR) No chip select rise has been detected since the last read of QSPI_SR.  */
#define   QSPI_ISR_CSR_1_Val                  _UINT32_(0x1)                                        /* (QSPI_ISR) At least one chip select rise has been detected since the last read of QSPI_SR.  */
#define QSPI_ISR_CSR_0                        (QSPI_ISR_CSR_0_Val << QSPI_ISR_CSR_Pos)             /* (QSPI_ISR) No chip select rise has been detected since the last read of QSPI_SR. Position  */
#define QSPI_ISR_CSR_1                        (QSPI_ISR_CSR_1_Val << QSPI_ISR_CSR_Pos)             /* (QSPI_ISR) At least one chip select rise has been detected since the last read of QSPI_SR. Position  */
#define QSPI_ISR_INSTRE_Pos                   _UINT32_(10)                                         /* (QSPI_ISR) Instruction End Status (cleared on read) Position */
#define QSPI_ISR_INSTRE_Msk                   (_UINT32_(0x1) << QSPI_ISR_INSTRE_Pos)               /* (QSPI_ISR) Instruction End Status (cleared on read) Mask */
#define QSPI_ISR_INSTRE(value)                (QSPI_ISR_INSTRE_Msk & (_UINT32_(value) << QSPI_ISR_INSTRE_Pos)) /* Assigment of value for INSTRE in the QSPI_ISR register */
#define   QSPI_ISR_INSTRE_0_Val               _UINT32_(0x0)                                        /* (QSPI_ISR) No instruction end has been detected since the last read of QSPI_SR.  */
#define   QSPI_ISR_INSTRE_1_Val               _UINT32_(0x1)                                        /* (QSPI_ISR) At least one instruction end has been detected since the last read of QSPI_SR.  */
#define QSPI_ISR_INSTRE_0                     (QSPI_ISR_INSTRE_0_Val << QSPI_ISR_INSTRE_Pos)       /* (QSPI_ISR) No instruction end has been detected since the last read of QSPI_SR. Position  */
#define QSPI_ISR_INSTRE_1                     (QSPI_ISR_INSTRE_1_Val << QSPI_ISR_INSTRE_Pos)       /* (QSPI_ISR) At least one instruction end has been detected since the last read of QSPI_SR. Position  */
#define QSPI_ISR_LWRA_Pos                     _UINT32_(11)                                         /* (QSPI_ISR) Last Write Access (cleared on read) Position */
#define QSPI_ISR_LWRA_Msk                     (_UINT32_(0x1) << QSPI_ISR_LWRA_Pos)                 /* (QSPI_ISR) Last Write Access (cleared on read) Mask */
#define QSPI_ISR_LWRA(value)                  (QSPI_ISR_LWRA_Msk & (_UINT32_(value) << QSPI_ISR_LWRA_Pos)) /* Assigment of value for LWRA in the QSPI_ISR register */
#define   QSPI_ISR_LWRA_0_Val                 _UINT32_(0x0)                                        /* (QSPI_ISR) Last write access has not been sent since the last read of QSPI_SR or NBWRA = 0.  */
#define   QSPI_ISR_LWRA_1_Val                 _UINT32_(0x1)                                        /* (QSPI_ISR) At least one last write access has been sent since the last read of QSPI_SR.  */
#define QSPI_ISR_LWRA_0                       (QSPI_ISR_LWRA_0_Val << QSPI_ISR_LWRA_Pos)           /* (QSPI_ISR) Last write access has not been sent since the last read of QSPI_SR or NBWRA = 0. Position  */
#define QSPI_ISR_LWRA_1                       (QSPI_ISR_LWRA_1_Val << QSPI_ISR_LWRA_Pos)           /* (QSPI_ISR) At least one last write access has been sent since the last read of QSPI_SR. Position  */
#define QSPI_ISR_QITF_Pos                     _UINT32_(12)                                         /* (QSPI_ISR) QSPI Interrupt Fall Position */
#define QSPI_ISR_QITF_Msk                     (_UINT32_(0x1) << QSPI_ISR_QITF_Pos)                 /* (QSPI_ISR) QSPI Interrupt Fall Mask */
#define QSPI_ISR_QITF(value)                  (QSPI_ISR_QITF_Msk & (_UINT32_(value) << QSPI_ISR_QITF_Pos)) /* Assigment of value for QITF in the QSPI_ISR register */
#define   QSPI_ISR_QITF_0_Val                 _UINT32_(0x0)                                        /* (QSPI_ISR) No falling of the QSPI memory interrupt line has been detected since the last read of QSPI_ISR.  */
#define   QSPI_ISR_QITF_1_Val                 _UINT32_(0x1)                                        /* (QSPI_ISR) At least one QSPI memory interrupt line falling edge occurred since the last read of QSPI_ISR.  */
#define QSPI_ISR_QITF_0                       (QSPI_ISR_QITF_0_Val << QSPI_ISR_QITF_Pos)           /* (QSPI_ISR) No falling of the QSPI memory interrupt line has been detected since the last read of QSPI_ISR. Position  */
#define QSPI_ISR_QITF_1                       (QSPI_ISR_QITF_1_Val << QSPI_ISR_QITF_Pos)           /* (QSPI_ISR) At least one QSPI memory interrupt line falling edge occurred since the last read of QSPI_ISR. Position  */
#define QSPI_ISR_QITR_Pos                     _UINT32_(13)                                         /* (QSPI_ISR) QSPI Interrupt Rise Position */
#define QSPI_ISR_QITR_Msk                     (_UINT32_(0x1) << QSPI_ISR_QITR_Pos)                 /* (QSPI_ISR) QSPI Interrupt Rise Mask */
#define QSPI_ISR_QITR(value)                  (QSPI_ISR_QITR_Msk & (_UINT32_(value) << QSPI_ISR_QITR_Pos)) /* Assigment of value for QITR in the QSPI_ISR register */
#define   QSPI_ISR_QITR_0_Val                 _UINT32_(0x0)                                        /* (QSPI_ISR) No rising of the QSPI memory interrupt line has been detected since the last read of QSPI_ISR.  */
#define   QSPI_ISR_QITR_1_Val                 _UINT32_(0x1)                                        /* (QSPI_ISR) At least one QSPI memory interrupt line rising edge occurred since the last read of QSPI_ISR.  */
#define QSPI_ISR_QITR_0                       (QSPI_ISR_QITR_0_Val << QSPI_ISR_QITR_Pos)           /* (QSPI_ISR) No rising of the QSPI memory interrupt line has been detected since the last read of QSPI_ISR. Position  */
#define QSPI_ISR_QITR_1                       (QSPI_ISR_QITR_1_Val << QSPI_ISR_QITR_Pos)           /* (QSPI_ISR) At least one QSPI memory interrupt line rising edge occurred since the last read of QSPI_ISR. Position  */
#define QSPI_ISR_CSFA_Pos                     _UINT32_(14)                                         /* (QSPI_ISR) Chip Select Fall Autoclear Position */
#define QSPI_ISR_CSFA_Msk                     (_UINT32_(0x1) << QSPI_ISR_CSFA_Pos)                 /* (QSPI_ISR) Chip Select Fall Autoclear Mask */
#define QSPI_ISR_CSFA(value)                  (QSPI_ISR_CSFA_Msk & (_UINT32_(value) << QSPI_ISR_CSFA_Pos)) /* Assigment of value for CSFA in the QSPI_ISR register */
#define   QSPI_ISR_CSFA_0_Val                 _UINT32_(0x0)                                        /* (QSPI_ISR) No chip select fall has been detected since end of the last command or the last read of QSPI_ISR.  */
#define   QSPI_ISR_CSFA_1_Val                 _UINT32_(0x1)                                        /* (QSPI_ISR) One chip select fall has been detected since the end of the last command or the last read of QSPI_ISR.  */
#define QSPI_ISR_CSFA_0                       (QSPI_ISR_CSFA_0_Val << QSPI_ISR_CSFA_Pos)           /* (QSPI_ISR) No chip select fall has been detected since end of the last command or the last read of QSPI_ISR. Position  */
#define QSPI_ISR_CSFA_1                       (QSPI_ISR_CSFA_1_Val << QSPI_ISR_CSFA_Pos)           /* (QSPI_ISR) One chip select fall has been detected since the end of the last command or the last read of QSPI_ISR. Position  */
#define QSPI_ISR_CSRA_Pos                     _UINT32_(15)                                         /* (QSPI_ISR) Chip Select Rise Autoclear Position */
#define QSPI_ISR_CSRA_Msk                     (_UINT32_(0x1) << QSPI_ISR_CSRA_Pos)                 /* (QSPI_ISR) Chip Select Rise Autoclear Mask */
#define QSPI_ISR_CSRA(value)                  (QSPI_ISR_CSRA_Msk & (_UINT32_(value) << QSPI_ISR_CSRA_Pos)) /* Assigment of value for CSRA in the QSPI_ISR register */
#define   QSPI_ISR_CSRA_0_Val                 _UINT32_(0x0)                                        /* (QSPI_ISR) No chip select rise has been detected since beginning of the last command or the last read of QSPI_ISR.  */
#define   QSPI_ISR_CSRA_1_Val                 _UINT32_(0x1)                                        /* (QSPI_ISR) One chip select rise has been detected since the beginning of the last command or the last read of QSPI_ISR.  */
#define QSPI_ISR_CSRA_0                       (QSPI_ISR_CSRA_0_Val << QSPI_ISR_CSRA_Pos)           /* (QSPI_ISR) No chip select rise has been detected since beginning of the last command or the last read of QSPI_ISR. Position  */
#define QSPI_ISR_CSRA_1                       (QSPI_ISR_CSRA_1_Val << QSPI_ISR_CSRA_Pos)           /* (QSPI_ISR) One chip select rise has been detected since the beginning of the last command or the last read of QSPI_ISR. Position  */
#define QSPI_ISR_RFRSHD_Pos                   _UINT32_(16)                                         /* (QSPI_ISR) Refresh Done Position */
#define QSPI_ISR_RFRSHD_Msk                   (_UINT32_(0x1) << QSPI_ISR_RFRSHD_Pos)               /* (QSPI_ISR) Refresh Done Mask */
#define QSPI_ISR_RFRSHD(value)                (QSPI_ISR_RFRSHD_Msk & (_UINT32_(value) << QSPI_ISR_RFRSHD_Pos)) /* Assigment of value for RFRSHD in the QSPI_ISR register */
#define   QSPI_ISR_RFRSHD_0_Val               _UINT32_(0x0)                                        /* (QSPI_ISR) No refresh done event occurred since the last read of QSPI_ISR.  */
#define   QSPI_ISR_RFRSHD_1_Val               _UINT32_(0x1)                                        /* (QSPI_ISR) One refresh done event has been detected since the end of the last refresh command or the last read of QSPI_ISR.  */
#define QSPI_ISR_RFRSHD_0                     (QSPI_ISR_RFRSHD_0_Val << QSPI_ISR_RFRSHD_Pos)       /* (QSPI_ISR) No refresh done event occurred since the last read of QSPI_ISR. Position  */
#define QSPI_ISR_RFRSHD_1                     (QSPI_ISR_RFRSHD_1_Val << QSPI_ISR_RFRSHD_Pos)       /* (QSPI_ISR) One refresh done event has been detected since the end of the last refresh command or the last read of QSPI_ISR. Position  */
#define QSPI_ISR_TOUT_Pos                     _UINT32_(17)                                         /* (QSPI_ISR) QSPI Time-out Position */
#define QSPI_ISR_TOUT_Msk                     (_UINT32_(0x1) << QSPI_ISR_TOUT_Pos)                 /* (QSPI_ISR) QSPI Time-out Mask */
#define QSPI_ISR_TOUT(value)                  (QSPI_ISR_TOUT_Msk & (_UINT32_(value) << QSPI_ISR_TOUT_Pos)) /* Assigment of value for TOUT in the QSPI_ISR register */
#define   QSPI_ISR_TOUT_0_Val                 _UINT32_(0x0)                                        /* (QSPI_ISR) No QSPI time-out occurred since the last write of RTOUT bit on QSPI_CR.  */
#define   QSPI_ISR_TOUT_1_Val                 _UINT32_(0x1)                                        /* (QSPI_ISR) At least one QSPI time-out occurred since the last write of RTOUT bit on QSPI_CR.  */
#define QSPI_ISR_TOUT_0                       (QSPI_ISR_TOUT_0_Val << QSPI_ISR_TOUT_Pos)           /* (QSPI_ISR) No QSPI time-out occurred since the last write of RTOUT bit on QSPI_CR. Position  */
#define QSPI_ISR_TOUT_1                       (QSPI_ISR_TOUT_1_Val << QSPI_ISR_TOUT_Pos)           /* (QSPI_ISR) At least one QSPI time-out occurred since the last write of RTOUT bit on QSPI_CR. Position  */
#define QSPI_ISR_Msk                          _UINT32_(0x0003FD0F)                                 /* (QSPI_ISR) Register Mask  */


/* -------- QSPI_IER : (QSPI Offset: 0x14) ( /W 32) Interrupt Enable Register -------- */
#define QSPI_IER_RDRF_Pos                     _UINT32_(0)                                          /* (QSPI_IER) Receive Data Register Full Interrupt Enable Position */
#define QSPI_IER_RDRF_Msk                     (_UINT32_(0x1) << QSPI_IER_RDRF_Pos)                 /* (QSPI_IER) Receive Data Register Full Interrupt Enable Mask */
#define QSPI_IER_RDRF(value)                  (QSPI_IER_RDRF_Msk & (_UINT32_(value) << QSPI_IER_RDRF_Pos)) /* Assigment of value for RDRF in the QSPI_IER register */
#define QSPI_IER_TDRE_Pos                     _UINT32_(1)                                          /* (QSPI_IER) Transmit Data Register Empty Interrupt Enable Position */
#define QSPI_IER_TDRE_Msk                     (_UINT32_(0x1) << QSPI_IER_TDRE_Pos)                 /* (QSPI_IER) Transmit Data Register Empty Interrupt Enable Mask */
#define QSPI_IER_TDRE(value)                  (QSPI_IER_TDRE_Msk & (_UINT32_(value) << QSPI_IER_TDRE_Pos)) /* Assigment of value for TDRE in the QSPI_IER register */
#define QSPI_IER_TXEMPTY_Pos                  _UINT32_(2)                                          /* (QSPI_IER) Transmission Registers Empty Enable Position */
#define QSPI_IER_TXEMPTY_Msk                  (_UINT32_(0x1) << QSPI_IER_TXEMPTY_Pos)              /* (QSPI_IER) Transmission Registers Empty Enable Mask */
#define QSPI_IER_TXEMPTY(value)               (QSPI_IER_TXEMPTY_Msk & (_UINT32_(value) << QSPI_IER_TXEMPTY_Pos)) /* Assigment of value for TXEMPTY in the QSPI_IER register */
#define QSPI_IER_OVRES_Pos                    _UINT32_(3)                                          /* (QSPI_IER) Overrun Error Interrupt Enable Position */
#define QSPI_IER_OVRES_Msk                    (_UINT32_(0x1) << QSPI_IER_OVRES_Pos)                /* (QSPI_IER) Overrun Error Interrupt Enable Mask */
#define QSPI_IER_OVRES(value)                 (QSPI_IER_OVRES_Msk & (_UINT32_(value) << QSPI_IER_OVRES_Pos)) /* Assigment of value for OVRES in the QSPI_IER register */
#define QSPI_IER_CSR_Pos                      _UINT32_(8)                                          /* (QSPI_IER) Chip Select Rise Interrupt Enable Position */
#define QSPI_IER_CSR_Msk                      (_UINT32_(0x1) << QSPI_IER_CSR_Pos)                  /* (QSPI_IER) Chip Select Rise Interrupt Enable Mask */
#define QSPI_IER_CSR(value)                   (QSPI_IER_CSR_Msk & (_UINT32_(value) << QSPI_IER_CSR_Pos)) /* Assigment of value for CSR in the QSPI_IER register */
#define QSPI_IER_INSTRE_Pos                   _UINT32_(10)                                         /* (QSPI_IER) Instruction End Interrupt Enable Position */
#define QSPI_IER_INSTRE_Msk                   (_UINT32_(0x1) << QSPI_IER_INSTRE_Pos)               /* (QSPI_IER) Instruction End Interrupt Enable Mask */
#define QSPI_IER_INSTRE(value)                (QSPI_IER_INSTRE_Msk & (_UINT32_(value) << QSPI_IER_INSTRE_Pos)) /* Assigment of value for INSTRE in the QSPI_IER register */
#define QSPI_IER_LWRA_Pos                     _UINT32_(11)                                         /* (QSPI_IER) Last Write Access Interrupt Enable Position */
#define QSPI_IER_LWRA_Msk                     (_UINT32_(0x1) << QSPI_IER_LWRA_Pos)                 /* (QSPI_IER) Last Write Access Interrupt Enable Mask */
#define QSPI_IER_LWRA(value)                  (QSPI_IER_LWRA_Msk & (_UINT32_(value) << QSPI_IER_LWRA_Pos)) /* Assigment of value for LWRA in the QSPI_IER register */
#define QSPI_IER_QITF_Pos                     _UINT32_(12)                                         /* (QSPI_IER) QSPI Interrupt Fall Interrupt Enable Position */
#define QSPI_IER_QITF_Msk                     (_UINT32_(0x1) << QSPI_IER_QITF_Pos)                 /* (QSPI_IER) QSPI Interrupt Fall Interrupt Enable Mask */
#define QSPI_IER_QITF(value)                  (QSPI_IER_QITF_Msk & (_UINT32_(value) << QSPI_IER_QITF_Pos)) /* Assigment of value for QITF in the QSPI_IER register */
#define QSPI_IER_QITR_Pos                     _UINT32_(13)                                         /* (QSPI_IER) QSPI Interrupt Rise Interrupt Enable Position */
#define QSPI_IER_QITR_Msk                     (_UINT32_(0x1) << QSPI_IER_QITR_Pos)                 /* (QSPI_IER) QSPI Interrupt Rise Interrupt Enable Mask */
#define QSPI_IER_QITR(value)                  (QSPI_IER_QITR_Msk & (_UINT32_(value) << QSPI_IER_QITR_Pos)) /* Assigment of value for QITR in the QSPI_IER register */
#define QSPI_IER_CSFA_Pos                     _UINT32_(14)                                         /* (QSPI_IER) Chip Select Fall Autoclear Interrupt Enable Position */
#define QSPI_IER_CSFA_Msk                     (_UINT32_(0x1) << QSPI_IER_CSFA_Pos)                 /* (QSPI_IER) Chip Select Fall Autoclear Interrupt Enable Mask */
#define QSPI_IER_CSFA(value)                  (QSPI_IER_CSFA_Msk & (_UINT32_(value) << QSPI_IER_CSFA_Pos)) /* Assigment of value for CSFA in the QSPI_IER register */
#define QSPI_IER_CSRA_Pos                     _UINT32_(15)                                         /* (QSPI_IER) Chip Select Rise Autoclear Interrupt Enable Position */
#define QSPI_IER_CSRA_Msk                     (_UINT32_(0x1) << QSPI_IER_CSRA_Pos)                 /* (QSPI_IER) Chip Select Rise Autoclear Interrupt Enable Mask */
#define QSPI_IER_CSRA(value)                  (QSPI_IER_CSRA_Msk & (_UINT32_(value) << QSPI_IER_CSRA_Pos)) /* Assigment of value for CSRA in the QSPI_IER register */
#define QSPI_IER_RFRSHD_Pos                   _UINT32_(16)                                         /* (QSPI_IER) Refresh Done Interrupt Enable Position */
#define QSPI_IER_RFRSHD_Msk                   (_UINT32_(0x1) << QSPI_IER_RFRSHD_Pos)               /* (QSPI_IER) Refresh Done Interrupt Enable Mask */
#define QSPI_IER_RFRSHD(value)                (QSPI_IER_RFRSHD_Msk & (_UINT32_(value) << QSPI_IER_RFRSHD_Pos)) /* Assigment of value for RFRSHD in the QSPI_IER register */
#define QSPI_IER_TOUT_Pos                     _UINT32_(17)                                         /* (QSPI_IER) QSPI Time-out Interrupt Enable Position */
#define QSPI_IER_TOUT_Msk                     (_UINT32_(0x1) << QSPI_IER_TOUT_Pos)                 /* (QSPI_IER) QSPI Time-out Interrupt Enable Mask */
#define QSPI_IER_TOUT(value)                  (QSPI_IER_TOUT_Msk & (_UINT32_(value) << QSPI_IER_TOUT_Pos)) /* Assigment of value for TOUT in the QSPI_IER register */
#define QSPI_IER_Msk                          _UINT32_(0x0003FD0F)                                 /* (QSPI_IER) Register Mask  */


/* -------- QSPI_IDR : (QSPI Offset: 0x18) ( /W 32) Interrupt Disable Register -------- */
#define QSPI_IDR_RDRF_Pos                     _UINT32_(0)                                          /* (QSPI_IDR) Receive Data Register Full Interrupt Disable Position */
#define QSPI_IDR_RDRF_Msk                     (_UINT32_(0x1) << QSPI_IDR_RDRF_Pos)                 /* (QSPI_IDR) Receive Data Register Full Interrupt Disable Mask */
#define QSPI_IDR_RDRF(value)                  (QSPI_IDR_RDRF_Msk & (_UINT32_(value) << QSPI_IDR_RDRF_Pos)) /* Assigment of value for RDRF in the QSPI_IDR register */
#define QSPI_IDR_TDRE_Pos                     _UINT32_(1)                                          /* (QSPI_IDR) Transmit Data Register Empty Interrupt Disable Position */
#define QSPI_IDR_TDRE_Msk                     (_UINT32_(0x1) << QSPI_IDR_TDRE_Pos)                 /* (QSPI_IDR) Transmit Data Register Empty Interrupt Disable Mask */
#define QSPI_IDR_TDRE(value)                  (QSPI_IDR_TDRE_Msk & (_UINT32_(value) << QSPI_IDR_TDRE_Pos)) /* Assigment of value for TDRE in the QSPI_IDR register */
#define QSPI_IDR_TXEMPTY_Pos                  _UINT32_(2)                                          /* (QSPI_IDR) Transmission Registers Empty Disable Position */
#define QSPI_IDR_TXEMPTY_Msk                  (_UINT32_(0x1) << QSPI_IDR_TXEMPTY_Pos)              /* (QSPI_IDR) Transmission Registers Empty Disable Mask */
#define QSPI_IDR_TXEMPTY(value)               (QSPI_IDR_TXEMPTY_Msk & (_UINT32_(value) << QSPI_IDR_TXEMPTY_Pos)) /* Assigment of value for TXEMPTY in the QSPI_IDR register */
#define QSPI_IDR_OVRES_Pos                    _UINT32_(3)                                          /* (QSPI_IDR) Overrun Error Interrupt Disable Position */
#define QSPI_IDR_OVRES_Msk                    (_UINT32_(0x1) << QSPI_IDR_OVRES_Pos)                /* (QSPI_IDR) Overrun Error Interrupt Disable Mask */
#define QSPI_IDR_OVRES(value)                 (QSPI_IDR_OVRES_Msk & (_UINT32_(value) << QSPI_IDR_OVRES_Pos)) /* Assigment of value for OVRES in the QSPI_IDR register */
#define QSPI_IDR_CSR_Pos                      _UINT32_(8)                                          /* (QSPI_IDR) Chip Select Rise Interrupt Disable Position */
#define QSPI_IDR_CSR_Msk                      (_UINT32_(0x1) << QSPI_IDR_CSR_Pos)                  /* (QSPI_IDR) Chip Select Rise Interrupt Disable Mask */
#define QSPI_IDR_CSR(value)                   (QSPI_IDR_CSR_Msk & (_UINT32_(value) << QSPI_IDR_CSR_Pos)) /* Assigment of value for CSR in the QSPI_IDR register */
#define QSPI_IDR_INSTRE_Pos                   _UINT32_(10)                                         /* (QSPI_IDR) Instruction End Interrupt Disable Position */
#define QSPI_IDR_INSTRE_Msk                   (_UINT32_(0x1) << QSPI_IDR_INSTRE_Pos)               /* (QSPI_IDR) Instruction End Interrupt Disable Mask */
#define QSPI_IDR_INSTRE(value)                (QSPI_IDR_INSTRE_Msk & (_UINT32_(value) << QSPI_IDR_INSTRE_Pos)) /* Assigment of value for INSTRE in the QSPI_IDR register */
#define QSPI_IDR_LWRA_Pos                     _UINT32_(11)                                         /* (QSPI_IDR) Last Write Access Interrupt Disable Position */
#define QSPI_IDR_LWRA_Msk                     (_UINT32_(0x1) << QSPI_IDR_LWRA_Pos)                 /* (QSPI_IDR) Last Write Access Interrupt Disable Mask */
#define QSPI_IDR_LWRA(value)                  (QSPI_IDR_LWRA_Msk & (_UINT32_(value) << QSPI_IDR_LWRA_Pos)) /* Assigment of value for LWRA in the QSPI_IDR register */
#define QSPI_IDR_QITF_Pos                     _UINT32_(12)                                         /* (QSPI_IDR) QSPI Interrupt Fall Interrupt Disable Position */
#define QSPI_IDR_QITF_Msk                     (_UINT32_(0x1) << QSPI_IDR_QITF_Pos)                 /* (QSPI_IDR) QSPI Interrupt Fall Interrupt Disable Mask */
#define QSPI_IDR_QITF(value)                  (QSPI_IDR_QITF_Msk & (_UINT32_(value) << QSPI_IDR_QITF_Pos)) /* Assigment of value for QITF in the QSPI_IDR register */
#define QSPI_IDR_QITR_Pos                     _UINT32_(13)                                         /* (QSPI_IDR) QSPI Interrupt Rise Interrupt Disable Position */
#define QSPI_IDR_QITR_Msk                     (_UINT32_(0x1) << QSPI_IDR_QITR_Pos)                 /* (QSPI_IDR) QSPI Interrupt Rise Interrupt Disable Mask */
#define QSPI_IDR_QITR(value)                  (QSPI_IDR_QITR_Msk & (_UINT32_(value) << QSPI_IDR_QITR_Pos)) /* Assigment of value for QITR in the QSPI_IDR register */
#define QSPI_IDR_CSFA_Pos                     _UINT32_(14)                                         /* (QSPI_IDR) Chip Select Fall Autoclear Interrupt Disable Position */
#define QSPI_IDR_CSFA_Msk                     (_UINT32_(0x1) << QSPI_IDR_CSFA_Pos)                 /* (QSPI_IDR) Chip Select Fall Autoclear Interrupt Disable Mask */
#define QSPI_IDR_CSFA(value)                  (QSPI_IDR_CSFA_Msk & (_UINT32_(value) << QSPI_IDR_CSFA_Pos)) /* Assigment of value for CSFA in the QSPI_IDR register */
#define QSPI_IDR_CSRA_Pos                     _UINT32_(15)                                         /* (QSPI_IDR) Chip Select Rise Autoclear Interrupt Disable Position */
#define QSPI_IDR_CSRA_Msk                     (_UINT32_(0x1) << QSPI_IDR_CSRA_Pos)                 /* (QSPI_IDR) Chip Select Rise Autoclear Interrupt Disable Mask */
#define QSPI_IDR_CSRA(value)                  (QSPI_IDR_CSRA_Msk & (_UINT32_(value) << QSPI_IDR_CSRA_Pos)) /* Assigment of value for CSRA in the QSPI_IDR register */
#define QSPI_IDR_RFRSHD_Pos                   _UINT32_(16)                                         /* (QSPI_IDR) Refresh Done Interrupt Disable Position */
#define QSPI_IDR_RFRSHD_Msk                   (_UINT32_(0x1) << QSPI_IDR_RFRSHD_Pos)               /* (QSPI_IDR) Refresh Done Interrupt Disable Mask */
#define QSPI_IDR_RFRSHD(value)                (QSPI_IDR_RFRSHD_Msk & (_UINT32_(value) << QSPI_IDR_RFRSHD_Pos)) /* Assigment of value for RFRSHD in the QSPI_IDR register */
#define QSPI_IDR_TOUT_Pos                     _UINT32_(17)                                         /* (QSPI_IDR) QSPI Time-out Interrupt Disable Position */
#define QSPI_IDR_TOUT_Msk                     (_UINT32_(0x1) << QSPI_IDR_TOUT_Pos)                 /* (QSPI_IDR) QSPI Time-out Interrupt Disable Mask */
#define QSPI_IDR_TOUT(value)                  (QSPI_IDR_TOUT_Msk & (_UINT32_(value) << QSPI_IDR_TOUT_Pos)) /* Assigment of value for TOUT in the QSPI_IDR register */
#define QSPI_IDR_Msk                          _UINT32_(0x0003FD0F)                                 /* (QSPI_IDR) Register Mask  */


/* -------- QSPI_IMR : (QSPI Offset: 0x1C) ( R/ 32) Interrupt Mask Register -------- */
#define QSPI_IMR_RESETVALUE                   _UINT32_(0x00)                                       /*  (QSPI_IMR) Interrupt Mask Register  Reset Value */

#define QSPI_IMR_RDRF_Pos                     _UINT32_(0)                                          /* (QSPI_IMR) Receive Data Register Full Interrupt Mask Position */
#define QSPI_IMR_RDRF_Msk                     (_UINT32_(0x1) << QSPI_IMR_RDRF_Pos)                 /* (QSPI_IMR) Receive Data Register Full Interrupt Mask Mask */
#define QSPI_IMR_RDRF(value)                  (QSPI_IMR_RDRF_Msk & (_UINT32_(value) << QSPI_IMR_RDRF_Pos)) /* Assigment of value for RDRF in the QSPI_IMR register */
#define QSPI_IMR_TDRE_Pos                     _UINT32_(1)                                          /* (QSPI_IMR) Transmit Data Register Empty Interrupt Mask Position */
#define QSPI_IMR_TDRE_Msk                     (_UINT32_(0x1) << QSPI_IMR_TDRE_Pos)                 /* (QSPI_IMR) Transmit Data Register Empty Interrupt Mask Mask */
#define QSPI_IMR_TDRE(value)                  (QSPI_IMR_TDRE_Msk & (_UINT32_(value) << QSPI_IMR_TDRE_Pos)) /* Assigment of value for TDRE in the QSPI_IMR register */
#define QSPI_IMR_TXEMPTY_Pos                  _UINT32_(2)                                          /* (QSPI_IMR) Transmission Registers Empty Mask Position */
#define QSPI_IMR_TXEMPTY_Msk                  (_UINT32_(0x1) << QSPI_IMR_TXEMPTY_Pos)              /* (QSPI_IMR) Transmission Registers Empty Mask Mask */
#define QSPI_IMR_TXEMPTY(value)               (QSPI_IMR_TXEMPTY_Msk & (_UINT32_(value) << QSPI_IMR_TXEMPTY_Pos)) /* Assigment of value for TXEMPTY in the QSPI_IMR register */
#define QSPI_IMR_OVRES_Pos                    _UINT32_(3)                                          /* (QSPI_IMR) Overrun Error Interrupt Mask Position */
#define QSPI_IMR_OVRES_Msk                    (_UINT32_(0x1) << QSPI_IMR_OVRES_Pos)                /* (QSPI_IMR) Overrun Error Interrupt Mask Mask */
#define QSPI_IMR_OVRES(value)                 (QSPI_IMR_OVRES_Msk & (_UINT32_(value) << QSPI_IMR_OVRES_Pos)) /* Assigment of value for OVRES in the QSPI_IMR register */
#define QSPI_IMR_CSR_Pos                      _UINT32_(8)                                          /* (QSPI_IMR) Chip Select Rise Interrupt Mask Position */
#define QSPI_IMR_CSR_Msk                      (_UINT32_(0x1) << QSPI_IMR_CSR_Pos)                  /* (QSPI_IMR) Chip Select Rise Interrupt Mask Mask */
#define QSPI_IMR_CSR(value)                   (QSPI_IMR_CSR_Msk & (_UINT32_(value) << QSPI_IMR_CSR_Pos)) /* Assigment of value for CSR in the QSPI_IMR register */
#define QSPI_IMR_INSTRE_Pos                   _UINT32_(10)                                         /* (QSPI_IMR) Instruction End Interrupt Mask Position */
#define QSPI_IMR_INSTRE_Msk                   (_UINT32_(0x1) << QSPI_IMR_INSTRE_Pos)               /* (QSPI_IMR) Instruction End Interrupt Mask Mask */
#define QSPI_IMR_INSTRE(value)                (QSPI_IMR_INSTRE_Msk & (_UINT32_(value) << QSPI_IMR_INSTRE_Pos)) /* Assigment of value for INSTRE in the QSPI_IMR register */
#define QSPI_IMR_LWRA_Pos                     _UINT32_(11)                                         /* (QSPI_IMR) Last Write Access Interrupt Mask Position */
#define QSPI_IMR_LWRA_Msk                     (_UINT32_(0x1) << QSPI_IMR_LWRA_Pos)                 /* (QSPI_IMR) Last Write Access Interrupt Mask Mask */
#define QSPI_IMR_LWRA(value)                  (QSPI_IMR_LWRA_Msk & (_UINT32_(value) << QSPI_IMR_LWRA_Pos)) /* Assigment of value for LWRA in the QSPI_IMR register */
#define QSPI_IMR_QITF_Pos                     _UINT32_(12)                                         /* (QSPI_IMR) QSPI Interrupt Fall Interrupt Mask Position */
#define QSPI_IMR_QITF_Msk                     (_UINT32_(0x1) << QSPI_IMR_QITF_Pos)                 /* (QSPI_IMR) QSPI Interrupt Fall Interrupt Mask Mask */
#define QSPI_IMR_QITF(value)                  (QSPI_IMR_QITF_Msk & (_UINT32_(value) << QSPI_IMR_QITF_Pos)) /* Assigment of value for QITF in the QSPI_IMR register */
#define QSPI_IMR_QITR_Pos                     _UINT32_(13)                                         /* (QSPI_IMR) QSPI Interrupt Rise Interrupt Mask Position */
#define QSPI_IMR_QITR_Msk                     (_UINT32_(0x1) << QSPI_IMR_QITR_Pos)                 /* (QSPI_IMR) QSPI Interrupt Rise Interrupt Mask Mask */
#define QSPI_IMR_QITR(value)                  (QSPI_IMR_QITR_Msk & (_UINT32_(value) << QSPI_IMR_QITR_Pos)) /* Assigment of value for QITR in the QSPI_IMR register */
#define QSPI_IMR_CSFA_Pos                     _UINT32_(14)                                         /* (QSPI_IMR) Chip Select Fall Autoclear Interrupt Mask Position */
#define QSPI_IMR_CSFA_Msk                     (_UINT32_(0x1) << QSPI_IMR_CSFA_Pos)                 /* (QSPI_IMR) Chip Select Fall Autoclear Interrupt Mask Mask */
#define QSPI_IMR_CSFA(value)                  (QSPI_IMR_CSFA_Msk & (_UINT32_(value) << QSPI_IMR_CSFA_Pos)) /* Assigment of value for CSFA in the QSPI_IMR register */
#define QSPI_IMR_CSRA_Pos                     _UINT32_(15)                                         /* (QSPI_IMR) Chip Select Rise Autoclear Interrupt Mask Position */
#define QSPI_IMR_CSRA_Msk                     (_UINT32_(0x1) << QSPI_IMR_CSRA_Pos)                 /* (QSPI_IMR) Chip Select Rise Autoclear Interrupt Mask Mask */
#define QSPI_IMR_CSRA(value)                  (QSPI_IMR_CSRA_Msk & (_UINT32_(value) << QSPI_IMR_CSRA_Pos)) /* Assigment of value for CSRA in the QSPI_IMR register */
#define QSPI_IMR_RFRSHD_Pos                   _UINT32_(16)                                         /* (QSPI_IMR) Refresh Done Interrupt Mask Position */
#define QSPI_IMR_RFRSHD_Msk                   (_UINT32_(0x1) << QSPI_IMR_RFRSHD_Pos)               /* (QSPI_IMR) Refresh Done Interrupt Mask Mask */
#define QSPI_IMR_RFRSHD(value)                (QSPI_IMR_RFRSHD_Msk & (_UINT32_(value) << QSPI_IMR_RFRSHD_Pos)) /* Assigment of value for RFRSHD in the QSPI_IMR register */
#define QSPI_IMR_TOUT_Pos                     _UINT32_(17)                                         /* (QSPI_IMR) QSPI Time-out Interrupt Mask Position */
#define QSPI_IMR_TOUT_Msk                     (_UINT32_(0x1) << QSPI_IMR_TOUT_Pos)                 /* (QSPI_IMR) QSPI Time-out Interrupt Mask Mask */
#define QSPI_IMR_TOUT(value)                  (QSPI_IMR_TOUT_Msk & (_UINT32_(value) << QSPI_IMR_TOUT_Pos)) /* Assigment of value for TOUT in the QSPI_IMR register */
#define QSPI_IMR_Msk                          _UINT32_(0x0003FD0F)                                 /* (QSPI_IMR) Register Mask  */


/* -------- QSPI_SCR : (QSPI Offset: 0x20) (R/W 32) Serial Clock Register -------- */
#define QSPI_SCR_RESETVALUE                   _UINT32_(0x00)                                       /*  (QSPI_SCR) Serial Clock Register  Reset Value */

#define QSPI_SCR_CPOL_Pos                     _UINT32_(0)                                          /* (QSPI_SCR) Clock Polarity Position */
#define QSPI_SCR_CPOL_Msk                     (_UINT32_(0x1) << QSPI_SCR_CPOL_Pos)                 /* (QSPI_SCR) Clock Polarity Mask */
#define QSPI_SCR_CPOL(value)                  (QSPI_SCR_CPOL_Msk & (_UINT32_(value) << QSPI_SCR_CPOL_Pos)) /* Assigment of value for CPOL in the QSPI_SCR register */
#define   QSPI_SCR_CPOL_0_Val                 _UINT32_(0x0)                                        /* (QSPI_SCR) The inactive state value of QSCK is logic level zero.  */
#define   QSPI_SCR_CPOL_1_Val                 _UINT32_(0x1)                                        /* (QSPI_SCR) The inactive state value of QSCK is logic level one.  */
#define QSPI_SCR_CPOL_0                       (QSPI_SCR_CPOL_0_Val << QSPI_SCR_CPOL_Pos)           /* (QSPI_SCR) The inactive state value of QSCK is logic level zero. Position  */
#define QSPI_SCR_CPOL_1                       (QSPI_SCR_CPOL_1_Val << QSPI_SCR_CPOL_Pos)           /* (QSPI_SCR) The inactive state value of QSCK is logic level one. Position  */
#define QSPI_SCR_CPHA_Pos                     _UINT32_(1)                                          /* (QSPI_SCR) Clock Phase Position */
#define QSPI_SCR_CPHA_Msk                     (_UINT32_(0x1) << QSPI_SCR_CPHA_Pos)                 /* (QSPI_SCR) Clock Phase Mask */
#define QSPI_SCR_CPHA(value)                  (QSPI_SCR_CPHA_Msk & (_UINT32_(value) << QSPI_SCR_CPHA_Pos)) /* Assigment of value for CPHA in the QSPI_SCR register */
#define   QSPI_SCR_CPHA_0_Val                 _UINT32_(0x0)                                        /* (QSPI_SCR) Data is captured on the leading edge of QSCK and changed on the following edge of QSCK.  */
#define   QSPI_SCR_CPHA_1_Val                 _UINT32_(0x1)                                        /* (QSPI_SCR) Data is changed on the leading edge of QSCK and captured on the following edge of QSCK.  */
#define QSPI_SCR_CPHA_0                       (QSPI_SCR_CPHA_0_Val << QSPI_SCR_CPHA_Pos)           /* (QSPI_SCR) Data is captured on the leading edge of QSCK and changed on the following edge of QSCK. Position  */
#define QSPI_SCR_CPHA_1                       (QSPI_SCR_CPHA_1_Val << QSPI_SCR_CPHA_Pos)           /* (QSPI_SCR) Data is changed on the leading edge of QSCK and captured on the following edge of QSCK. Position  */
#define QSPI_SCR_DLYBS_Pos                    _UINT32_(16)                                         /* (QSPI_SCR) Delay Before QSCK Position */
#define QSPI_SCR_DLYBS_Msk                    (_UINT32_(0xFF) << QSPI_SCR_DLYBS_Pos)               /* (QSPI_SCR) Delay Before QSCK Mask */
#define QSPI_SCR_DLYBS(value)                 (QSPI_SCR_DLYBS_Msk & (_UINT32_(value) << QSPI_SCR_DLYBS_Pos)) /* Assigment of value for DLYBS in the QSPI_SCR register */
#define QSPI_SCR_Msk                          _UINT32_(0x00FF0003)                                 /* (QSPI_SCR) Register Mask  */


/* -------- QSPI_SR : (QSPI Offset: 0x24) (R/W 32) Status Register -------- */
#define QSPI_SR_RESETVALUE                    _UINT32_(0x00)                                       /*  (QSPI_SR) Status Register  Reset Value */

#define QSPI_SR_SYNCBSY_Pos                   _UINT32_(0)                                          /* (QSPI_SR) Synchronization Busy Position */
#define QSPI_SR_SYNCBSY_Msk                   (_UINT32_(0x1) << QSPI_SR_SYNCBSY_Pos)               /* (QSPI_SR) Synchronization Busy Mask */
#define QSPI_SR_SYNCBSY(value)                (QSPI_SR_SYNCBSY_Msk & (_UINT32_(value) << QSPI_SR_SYNCBSY_Pos)) /* Assigment of value for SYNCBSY in the QSPI_SR register */
#define   QSPI_SR_SYNCBSY_0_Val               _UINT32_(0x0)                                        /* (QSPI_SR) No event synchronization between the QSPI Controller interface and QSPI Controller core is ongoing. Register accesses requiring synchronization are allowed, see Register Synchronization.  */
#define   QSPI_SR_SYNCBSY_1_Val               _UINT32_(0x1)                                        /* (QSPI_SR) Event synchronization between the QSPI Controller interface and QSPI Controller core is ongoing. Register accesses requiring synchronization are not allowed, see Register Synchronization.  */
#define QSPI_SR_SYNCBSY_0                     (QSPI_SR_SYNCBSY_0_Val << QSPI_SR_SYNCBSY_Pos)       /* (QSPI_SR) No event synchronization between the QSPI Controller interface and QSPI Controller core is ongoing. Register accesses requiring synchronization are allowed, see Register Synchronization. Position  */
#define QSPI_SR_SYNCBSY_1                     (QSPI_SR_SYNCBSY_1_Val << QSPI_SR_SYNCBSY_Pos)       /* (QSPI_SR) Event synchronization between the QSPI Controller interface and QSPI Controller core is ongoing. Register accesses requiring synchronization are not allowed, see Register Synchronization. Position  */
#define QSPI_SR_QSPIENS_Pos                   _UINT32_(1)                                          /* (QSPI_SR) QSPI Enable Status Position */
#define QSPI_SR_QSPIENS_Msk                   (_UINT32_(0x1) << QSPI_SR_QSPIENS_Pos)               /* (QSPI_SR) QSPI Enable Status Mask */
#define QSPI_SR_QSPIENS(value)                (QSPI_SR_QSPIENS_Msk & (_UINT32_(value) << QSPI_SR_QSPIENS_Pos)) /* Assigment of value for QSPIENS in the QSPI_SR register */
#define   QSPI_SR_QSPIENS_0_Val               _UINT32_(0x0)                                        /* (QSPI_SR) The QSPI is disabled.  */
#define   QSPI_SR_QSPIENS_1_Val               _UINT32_(0x1)                                        /* (QSPI_SR) The QSPI is enabled.  */
#define QSPI_SR_QSPIENS_0                     (QSPI_SR_QSPIENS_0_Val << QSPI_SR_QSPIENS_Pos)       /* (QSPI_SR) The QSPI is disabled. Position  */
#define QSPI_SR_QSPIENS_1                     (QSPI_SR_QSPIENS_1_Val << QSPI_SR_QSPIENS_Pos)       /* (QSPI_SR) The QSPI is enabled. Position  */
#define QSPI_SR_CSS_Pos                       _UINT32_(2)                                          /* (QSPI_SR) Chip Select Status Position */
#define QSPI_SR_CSS_Msk                       (_UINT32_(0x1) << QSPI_SR_CSS_Pos)                   /* (QSPI_SR) Chip Select Status Mask */
#define QSPI_SR_CSS(value)                    (QSPI_SR_CSS_Msk & (_UINT32_(value) << QSPI_SR_CSS_Pos)) /* Assigment of value for CSS in the QSPI_SR register */
#define   QSPI_SR_CSS_0_Val                   _UINT32_(0x0)                                        /* (QSPI_SR) The chip select is asserted.  */
#define   QSPI_SR_CSS_1_Val                   _UINT32_(0x1)                                        /* (QSPI_SR) The chip select is not asserted.  */
#define QSPI_SR_CSS_0                         (QSPI_SR_CSS_0_Val << QSPI_SR_CSS_Pos)               /* (QSPI_SR) The chip select is asserted. Position  */
#define QSPI_SR_CSS_1                         (QSPI_SR_CSS_1_Val << QSPI_SR_CSS_Pos)               /* (QSPI_SR) The chip select is not asserted. Position  */
#define QSPI_SR_RBUSY_Pos                     _UINT32_(3)                                          /* (QSPI_SR) Read Busy Position */
#define QSPI_SR_RBUSY_Msk                     (_UINT32_(0x1) << QSPI_SR_RBUSY_Pos)                 /* (QSPI_SR) Read Busy Mask */
#define QSPI_SR_RBUSY(value)                  (QSPI_SR_RBUSY_Msk & (_UINT32_(value) << QSPI_SR_RBUSY_Pos)) /* Assigment of value for RBUSY in the QSPI_SR register */
#define   QSPI_SR_RBUSY_0_Val                 _UINT32_(0x0)                                        /* (QSPI_SR) The system bus interface has no activity.  */
#define   QSPI_SR_RBUSY_1_Val                 _UINT32_(0x1)                                        /* (QSPI_SR) The system bus interface is currently processing accesses.  */
#define QSPI_SR_RBUSY_0                       (QSPI_SR_RBUSY_0_Val << QSPI_SR_RBUSY_Pos)           /* (QSPI_SR) The system bus interface has no activity. Position  */
#define QSPI_SR_RBUSY_1                       (QSPI_SR_RBUSY_1_Val << QSPI_SR_RBUSY_Pos)           /* (QSPI_SR) The system bus interface is currently processing accesses. Position  */
#define QSPI_SR_HIDLE_Pos                     _UINT32_(4)                                          /* (QSPI_SR) QSPI Idle Position */
#define QSPI_SR_HIDLE_Msk                     (_UINT32_(0x1) << QSPI_SR_HIDLE_Pos)                 /* (QSPI_SR) QSPI Idle Mask */
#define QSPI_SR_HIDLE(value)                  (QSPI_SR_HIDLE_Msk & (_UINT32_(value) << QSPI_SR_HIDLE_Pos)) /* Assigment of value for HIDLE in the QSPI_SR register */
#define   QSPI_SR_HIDLE_0_Val                 _UINT32_(0x0)                                        /* (QSPI_SR) The QSPI is not in Idle state (either transmitting or Chip Select is active).  */
#define   QSPI_SR_HIDLE_1_Val                 _UINT32_(0x1)                                        /* (QSPI_SR) The QSPI is in Idle state (not transmitting and Chip Select is inactive).  */
#define QSPI_SR_HIDLE_0                       (QSPI_SR_HIDLE_0_Val << QSPI_SR_HIDLE_Pos)           /* (QSPI_SR) The QSPI is not in Idle state (either transmitting or Chip Select is active). Position  */
#define QSPI_SR_HIDLE_1                       (QSPI_SR_HIDLE_1_Val << QSPI_SR_HIDLE_Pos)           /* (QSPI_SR) The QSPI is in Idle state (not transmitting and Chip Select is inactive). Position  */
#define QSPI_SR_Msk                           _UINT32_(0x0000001F)                                 /* (QSPI_SR) Register Mask  */


/* -------- QSPI_IAR : (QSPI Offset: 0x30) (R/W 32) Instruction Address Register -------- */
#define QSPI_IAR_RESETVALUE                   _UINT32_(0x00)                                       /*  (QSPI_IAR) Instruction Address Register  Reset Value */

#define QSPI_IAR_ADDR_Pos                     _UINT32_(0)                                          /* (QSPI_IAR) Address Position */
#define QSPI_IAR_ADDR_Msk                     (_UINT32_(0xFFFFFFFF) << QSPI_IAR_ADDR_Pos)          /* (QSPI_IAR) Address Mask */
#define QSPI_IAR_ADDR(value)                  (QSPI_IAR_ADDR_Msk & (_UINT32_(value) << QSPI_IAR_ADDR_Pos)) /* Assigment of value for ADDR in the QSPI_IAR register */
#define QSPI_IAR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (QSPI_IAR) Register Mask  */


/* -------- QSPI_WICR : (QSPI Offset: 0x34) (R/W 32) Write Instruction Code Register -------- */
#define QSPI_WICR_RESETVALUE                  _UINT32_(0x00)                                       /*  (QSPI_WICR) Write Instruction Code Register  Reset Value */

#define QSPI_WICR_WRINST_Pos                  _UINT32_(0)                                          /* (QSPI_WICR) Write Instruction Code Position */
#define QSPI_WICR_WRINST_Msk                  (_UINT32_(0xFFFF) << QSPI_WICR_WRINST_Pos)           /* (QSPI_WICR) Write Instruction Code Mask */
#define QSPI_WICR_WRINST(value)               (QSPI_WICR_WRINST_Msk & (_UINT32_(value) << QSPI_WICR_WRINST_Pos)) /* Assigment of value for WRINST in the QSPI_WICR register */
#define QSPI_WICR_WROPT_Pos                   _UINT32_(16)                                         /* (QSPI_WICR) Write Option Code Position */
#define QSPI_WICR_WROPT_Msk                   (_UINT32_(0xFF) << QSPI_WICR_WROPT_Pos)              /* (QSPI_WICR) Write Option Code Mask */
#define QSPI_WICR_WROPT(value)                (QSPI_WICR_WROPT_Msk & (_UINT32_(value) << QSPI_WICR_WROPT_Pos)) /* Assigment of value for WROPT in the QSPI_WICR register */
#define QSPI_WICR_Msk                         _UINT32_(0x00FFFFFF)                                 /* (QSPI_WICR) Register Mask  */


/* -------- QSPI_IFR : (QSPI Offset: 0x38) (R/W 32) Instruction Frame Register -------- */
#define QSPI_IFR_RESETVALUE                   _UINT32_(0x00)                                       /*  (QSPI_IFR) Instruction Frame Register  Reset Value */

#define QSPI_IFR_WIDTH_Pos                    _UINT32_(0)                                          /* (QSPI_IFR) Width of Instruction Code, Address, Option Code and Data Position */
#define QSPI_IFR_WIDTH_Msk                    (_UINT32_(0xF) << QSPI_IFR_WIDTH_Pos)                /* (QSPI_IFR) Width of Instruction Code, Address, Option Code and Data Mask */
#define QSPI_IFR_WIDTH(value)                 (QSPI_IFR_WIDTH_Msk & (_UINT32_(value) << QSPI_IFR_WIDTH_Pos)) /* Assigment of value for WIDTH in the QSPI_IFR register */
#define   QSPI_IFR_WIDTH_SINGLE_BIT_SPI_Val   _UINT32_(0x0)                                        /* (QSPI_IFR) Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Single-bit SPI  */
#define   QSPI_IFR_WIDTH_DUAL_OUTPUT_Val      _UINT32_(0x1)                                        /* (QSPI_IFR) Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Dual SPI  */
#define   QSPI_IFR_WIDTH_QUAD_OUTPUT_Val      _UINT32_(0x2)                                        /* (QSPI_IFR) Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Quad SPI  */
#define   QSPI_IFR_WIDTH_DUAL_IO_Val          _UINT32_(0x3)                                        /* (QSPI_IFR) Instruction: Single-bit SPI / Address-Option: Dual SPI / Data: Dual SPI  */
#define   QSPI_IFR_WIDTH_QUAD_IO_Val          _UINT32_(0x4)                                        /* (QSPI_IFR) Instruction: Single-bit SPI / Address-Option: Quad SPI / Data: Quad SPI  */
#define   QSPI_IFR_WIDTH_DUAL_CMD_Val         _UINT32_(0x5)                                        /* (QSPI_IFR) Instruction: Dual SPI / Address-Option: Dual SPI / Data: Dual SPI  */
#define   QSPI_IFR_WIDTH_QUAD_CMD_Val         _UINT32_(0x6)                                        /* (QSPI_IFR) Instruction: Quad SPI / Address-Option: Quad SPI / Data: Quad SPI  */
#define   QSPI_IFR_WIDTH_OCT_OUTPUT_Val       _UINT32_(0x7)                                        /* (QSPI_IFR) Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Octal SPI  */
#define   QSPI_IFR_WIDTH_OCT_IO_Val           _UINT32_(0x8)                                        /* (QSPI_IFR) Instruction: Single-bit SPI / Address-Option: Octal SPI / Data: Octal SPI  */
#define   QSPI_IFR_WIDTH_OCT_CMD_Val          _UINT32_(0x9)                                        /* (QSPI_IFR) Instruction: Octal SPI / Address-Option: Octal SPI / Data: Octal SPI  */
#define QSPI_IFR_WIDTH_SINGLE_BIT_SPI         (QSPI_IFR_WIDTH_SINGLE_BIT_SPI_Val << QSPI_IFR_WIDTH_Pos) /* (QSPI_IFR) Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Single-bit SPI Position  */
#define QSPI_IFR_WIDTH_DUAL_OUTPUT            (QSPI_IFR_WIDTH_DUAL_OUTPUT_Val << QSPI_IFR_WIDTH_Pos) /* (QSPI_IFR) Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Dual SPI Position  */
#define QSPI_IFR_WIDTH_QUAD_OUTPUT            (QSPI_IFR_WIDTH_QUAD_OUTPUT_Val << QSPI_IFR_WIDTH_Pos) /* (QSPI_IFR) Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Quad SPI Position  */
#define QSPI_IFR_WIDTH_DUAL_IO                (QSPI_IFR_WIDTH_DUAL_IO_Val << QSPI_IFR_WIDTH_Pos)   /* (QSPI_IFR) Instruction: Single-bit SPI / Address-Option: Dual SPI / Data: Dual SPI Position  */
#define QSPI_IFR_WIDTH_QUAD_IO                (QSPI_IFR_WIDTH_QUAD_IO_Val << QSPI_IFR_WIDTH_Pos)   /* (QSPI_IFR) Instruction: Single-bit SPI / Address-Option: Quad SPI / Data: Quad SPI Position  */
#define QSPI_IFR_WIDTH_DUAL_CMD               (QSPI_IFR_WIDTH_DUAL_CMD_Val << QSPI_IFR_WIDTH_Pos)  /* (QSPI_IFR) Instruction: Dual SPI / Address-Option: Dual SPI / Data: Dual SPI Position  */
#define QSPI_IFR_WIDTH_QUAD_CMD               (QSPI_IFR_WIDTH_QUAD_CMD_Val << QSPI_IFR_WIDTH_Pos)  /* (QSPI_IFR) Instruction: Quad SPI / Address-Option: Quad SPI / Data: Quad SPI Position  */
#define QSPI_IFR_WIDTH_OCT_OUTPUT             (QSPI_IFR_WIDTH_OCT_OUTPUT_Val << QSPI_IFR_WIDTH_Pos) /* (QSPI_IFR) Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Octal SPI Position  */
#define QSPI_IFR_WIDTH_OCT_IO                 (QSPI_IFR_WIDTH_OCT_IO_Val << QSPI_IFR_WIDTH_Pos)    /* (QSPI_IFR) Instruction: Single-bit SPI / Address-Option: Octal SPI / Data: Octal SPI Position  */
#define QSPI_IFR_WIDTH_OCT_CMD                (QSPI_IFR_WIDTH_OCT_CMD_Val << QSPI_IFR_WIDTH_Pos)   /* (QSPI_IFR) Instruction: Octal SPI / Address-Option: Octal SPI / Data: Octal SPI Position  */
#define QSPI_IFR_INSTEN_Pos                   _UINT32_(4)                                          /* (QSPI_IFR) Instruction Enable Position */
#define QSPI_IFR_INSTEN_Msk                   (_UINT32_(0x1) << QSPI_IFR_INSTEN_Pos)               /* (QSPI_IFR) Instruction Enable Mask */
#define QSPI_IFR_INSTEN(value)                (QSPI_IFR_INSTEN_Msk & (_UINT32_(value) << QSPI_IFR_INSTEN_Pos)) /* Assigment of value for INSTEN in the QSPI_IFR register */
#define   QSPI_IFR_INSTEN_0_Val               _UINT32_(0x0)                                        /* (QSPI_IFR) The instruction is not sent to the serial Flash memory.  */
#define   QSPI_IFR_INSTEN_1_Val               _UINT32_(0x1)                                        /* (QSPI_IFR) The instruction is sent to the serial Flash memory.  */
#define QSPI_IFR_INSTEN_0                     (QSPI_IFR_INSTEN_0_Val << QSPI_IFR_INSTEN_Pos)       /* (QSPI_IFR) The instruction is not sent to the serial Flash memory. Position  */
#define QSPI_IFR_INSTEN_1                     (QSPI_IFR_INSTEN_1_Val << QSPI_IFR_INSTEN_Pos)       /* (QSPI_IFR) The instruction is sent to the serial Flash memory. Position  */
#define QSPI_IFR_ADDREN_Pos                   _UINT32_(5)                                          /* (QSPI_IFR) Address Enable Position */
#define QSPI_IFR_ADDREN_Msk                   (_UINT32_(0x1) << QSPI_IFR_ADDREN_Pos)               /* (QSPI_IFR) Address Enable Mask */
#define QSPI_IFR_ADDREN(value)                (QSPI_IFR_ADDREN_Msk & (_UINT32_(value) << QSPI_IFR_ADDREN_Pos)) /* Assigment of value for ADDREN in the QSPI_IFR register */
#define   QSPI_IFR_ADDREN_0_Val               _UINT32_(0x0)                                        /* (QSPI_IFR) The transfer address is not sent to the serial Flash memory.  */
#define   QSPI_IFR_ADDREN_1_Val               _UINT32_(0x1)                                        /* (QSPI_IFR) The transfer address is sent to the serial Flash memory.  */
#define QSPI_IFR_ADDREN_0                     (QSPI_IFR_ADDREN_0_Val << QSPI_IFR_ADDREN_Pos)       /* (QSPI_IFR) The transfer address is not sent to the serial Flash memory. Position  */
#define QSPI_IFR_ADDREN_1                     (QSPI_IFR_ADDREN_1_Val << QSPI_IFR_ADDREN_Pos)       /* (QSPI_IFR) The transfer address is sent to the serial Flash memory. Position  */
#define QSPI_IFR_OPTEN_Pos                    _UINT32_(6)                                          /* (QSPI_IFR) Option Enable Position */
#define QSPI_IFR_OPTEN_Msk                    (_UINT32_(0x1) << QSPI_IFR_OPTEN_Pos)                /* (QSPI_IFR) Option Enable Mask */
#define QSPI_IFR_OPTEN(value)                 (QSPI_IFR_OPTEN_Msk & (_UINT32_(value) << QSPI_IFR_OPTEN_Pos)) /* Assigment of value for OPTEN in the QSPI_IFR register */
#define   QSPI_IFR_OPTEN_0_Val                _UINT32_(0x0)                                        /* (QSPI_IFR) The option is not sent to the serial Flash memory.  */
#define   QSPI_IFR_OPTEN_1_Val                _UINT32_(0x1)                                        /* (QSPI_IFR) The option is sent to the serial Flash memory.  */
#define QSPI_IFR_OPTEN_0                      (QSPI_IFR_OPTEN_0_Val << QSPI_IFR_OPTEN_Pos)         /* (QSPI_IFR) The option is not sent to the serial Flash memory. Position  */
#define QSPI_IFR_OPTEN_1                      (QSPI_IFR_OPTEN_1_Val << QSPI_IFR_OPTEN_Pos)         /* (QSPI_IFR) The option is sent to the serial Flash memory. Position  */
#define QSPI_IFR_DATAEN_Pos                   _UINT32_(7)                                          /* (QSPI_IFR) Data Enable Position */
#define QSPI_IFR_DATAEN_Msk                   (_UINT32_(0x1) << QSPI_IFR_DATAEN_Pos)               /* (QSPI_IFR) Data Enable Mask */
#define QSPI_IFR_DATAEN(value)                (QSPI_IFR_DATAEN_Msk & (_UINT32_(value) << QSPI_IFR_DATAEN_Pos)) /* Assigment of value for DATAEN in the QSPI_IFR register */
#define   QSPI_IFR_DATAEN_0_Val               _UINT32_(0x0)                                        /* (QSPI_IFR) No data is sent/received to/from the serial Flash memory.  */
#define   QSPI_IFR_DATAEN_1_Val               _UINT32_(0x1)                                        /* (QSPI_IFR) Data is sent/received to/from the serial Flash memory.  */
#define QSPI_IFR_DATAEN_0                     (QSPI_IFR_DATAEN_0_Val << QSPI_IFR_DATAEN_Pos)       /* (QSPI_IFR) No data is sent/received to/from the serial Flash memory. Position  */
#define QSPI_IFR_DATAEN_1                     (QSPI_IFR_DATAEN_1_Val << QSPI_IFR_DATAEN_Pos)       /* (QSPI_IFR) Data is sent/received to/from the serial Flash memory. Position  */
#define QSPI_IFR_OPTL_Pos                     _UINT32_(8)                                          /* (QSPI_IFR) Option Code Length Position */
#define QSPI_IFR_OPTL_Msk                     (_UINT32_(0x3) << QSPI_IFR_OPTL_Pos)                 /* (QSPI_IFR) Option Code Length Mask */
#define QSPI_IFR_OPTL(value)                  (QSPI_IFR_OPTL_Msk & (_UINT32_(value) << QSPI_IFR_OPTL_Pos)) /* Assigment of value for OPTL in the QSPI_IFR register */
#define   QSPI_IFR_OPTL_OPTION_1BIT_Val       _UINT32_(0x0)                                        /* (QSPI_IFR) The option code is 1 bit long.  */
#define   QSPI_IFR_OPTL_OPTION_2BIT_Val       _UINT32_(0x1)                                        /* (QSPI_IFR) The option code is 2 bits long.  */
#define   QSPI_IFR_OPTL_OPTION_4BIT_Val       _UINT32_(0x2)                                        /* (QSPI_IFR) The option code is 4 bits long.  */
#define   QSPI_IFR_OPTL_OPTION_8BIT_Val       _UINT32_(0x3)                                        /* (QSPI_IFR) The option code is 8 bits long.  */
#define QSPI_IFR_OPTL_OPTION_1BIT             (QSPI_IFR_OPTL_OPTION_1BIT_Val << QSPI_IFR_OPTL_Pos) /* (QSPI_IFR) The option code is 1 bit long. Position  */
#define QSPI_IFR_OPTL_OPTION_2BIT             (QSPI_IFR_OPTL_OPTION_2BIT_Val << QSPI_IFR_OPTL_Pos) /* (QSPI_IFR) The option code is 2 bits long. Position  */
#define QSPI_IFR_OPTL_OPTION_4BIT             (QSPI_IFR_OPTL_OPTION_4BIT_Val << QSPI_IFR_OPTL_Pos) /* (QSPI_IFR) The option code is 4 bits long. Position  */
#define QSPI_IFR_OPTL_OPTION_8BIT             (QSPI_IFR_OPTL_OPTION_8BIT_Val << QSPI_IFR_OPTL_Pos) /* (QSPI_IFR) The option code is 8 bits long. Position  */
#define QSPI_IFR_ADDRL_Pos                    _UINT32_(10)                                         /* (QSPI_IFR) Address Length Position */
#define QSPI_IFR_ADDRL_Msk                    (_UINT32_(0x3) << QSPI_IFR_ADDRL_Pos)                /* (QSPI_IFR) Address Length Mask */
#define QSPI_IFR_ADDRL(value)                 (QSPI_IFR_ADDRL_Msk & (_UINT32_(value) << QSPI_IFR_ADDRL_Pos)) /* Assigment of value for ADDRL in the QSPI_IFR register */
#define   QSPI_IFR_ADDRL_8_BIT_Val            _UINT32_(0x0)                                        /* (QSPI_IFR) 8-bit address size  */
#define   QSPI_IFR_ADDRL_16_BIT_Val           _UINT32_(0x1)                                        /* (QSPI_IFR) 16-bit address size  */
#define   QSPI_IFR_ADDRL_24_BIT_Val           _UINT32_(0x2)                                        /* (QSPI_IFR) 24-bit address size  */
#define   QSPI_IFR_ADDRL_32_BIT_Val           _UINT32_(0x3)                                        /* (QSPI_IFR) 32-bit address size  */
#define QSPI_IFR_ADDRL_8_BIT                  (QSPI_IFR_ADDRL_8_BIT_Val << QSPI_IFR_ADDRL_Pos)     /* (QSPI_IFR) 8-bit address size Position  */
#define QSPI_IFR_ADDRL_16_BIT                 (QSPI_IFR_ADDRL_16_BIT_Val << QSPI_IFR_ADDRL_Pos)    /* (QSPI_IFR) 16-bit address size Position  */
#define QSPI_IFR_ADDRL_24_BIT                 (QSPI_IFR_ADDRL_24_BIT_Val << QSPI_IFR_ADDRL_Pos)    /* (QSPI_IFR) 24-bit address size Position  */
#define QSPI_IFR_ADDRL_32_BIT                 (QSPI_IFR_ADDRL_32_BIT_Val << QSPI_IFR_ADDRL_Pos)    /* (QSPI_IFR) 32-bit address size Position  */
#define QSPI_IFR_TFRTYP_Pos                   _UINT32_(12)                                         /* (QSPI_IFR) Data Transfer Type Position */
#define QSPI_IFR_TFRTYP_Msk                   (_UINT32_(0x1) << QSPI_IFR_TFRTYP_Pos)               /* (QSPI_IFR) Data Transfer Type Mask */
#define QSPI_IFR_TFRTYP(value)                (QSPI_IFR_TFRTYP_Msk & (_UINT32_(value) << QSPI_IFR_TFRTYP_Pos)) /* Assigment of value for TFRTYP in the QSPI_IFR register */
#define   QSPI_IFR_TFRTYP_TRSFR_REGISTER_Val  _UINT32_(0x0)                                        /* (QSPI_IFR) Read/Write of memory register, write of memory page buffer. This configuration implies the following: Either the AHB or the APB interface can be used to initiate the transfer (SMRM bit). Returned data represents the memory register value. If the APB interface is used, the RDRF and TDRE flags help to control the frame. Scrambling is possible only if the APB interface is used. For HyperFlash memories the "target" bit is set to register space in the HyperFlash header.  */
#define   QSPI_IFR_TFRTYP_TRSFR_MEMORY_Val    _UINT32_(0x1)                                        /* (QSPI_IFR) Read/Write accesses to the memory space. This configuration implies the following: Only the System Bus interface can be used to trigger accesses. Access to random location is possible. Address mask is applied and full size accesses only are performed. Internal optimization algorithm is enabled to minimize latency. Data are returned in a system bus protocol compliant way. Seamless scrambling is enabled. Seamless handling of HyperFlash Write Buffer programming command (one command for each data) Seamless protocol-specific page boundary handling Address shift is handled seamlessly (e.g. halfword memories).  */
#define QSPI_IFR_TFRTYP_TRSFR_REGISTER        (QSPI_IFR_TFRTYP_TRSFR_REGISTER_Val << QSPI_IFR_TFRTYP_Pos) /* (QSPI_IFR) Read/Write of memory register, write of memory page buffer. This configuration implies the following: Either the AHB or the APB interface can be used to initiate the transfer (SMRM bit). Returned data represents the memory register value. If the APB interface is used, the RDRF and TDRE flags help to control the frame. Scrambling is possible only if the APB interface is used. For HyperFlash memories the "target" bit is set to register space in the HyperFlash header. Position  */
#define QSPI_IFR_TFRTYP_TRSFR_MEMORY          (QSPI_IFR_TFRTYP_TRSFR_MEMORY_Val << QSPI_IFR_TFRTYP_Pos) /* (QSPI_IFR) Read/Write accesses to the memory space. This configuration implies the following: Only the System Bus interface can be used to trigger accesses. Access to random location is possible. Address mask is applied and full size accesses only are performed. Internal optimization algorithm is enabled to minimize latency. Data are returned in a system bus protocol compliant way. Seamless scrambling is enabled. Seamless handling of HyperFlash Write Buffer programming command (one command for each data) Seamless protocol-specific page boundary handling Address shift is handled seamlessly (e.g. halfword memories). Position  */
#define QSPI_IFR_CRM_Pos                      _UINT32_(14)                                         /* (QSPI_IFR) Continuous Read Mode Position */
#define QSPI_IFR_CRM_Msk                      (_UINT32_(0x1) << QSPI_IFR_CRM_Pos)                  /* (QSPI_IFR) Continuous Read Mode Mask */
#define QSPI_IFR_CRM(value)                   (QSPI_IFR_CRM_Msk & (_UINT32_(value) << QSPI_IFR_CRM_Pos)) /* Assigment of value for CRM in the QSPI_IFR register */
#define   QSPI_IFR_CRM_DISABLED_Val           _UINT32_(0x0)                                        /* (QSPI_IFR) Continuous Read mode is disabled.  */
#define   QSPI_IFR_CRM_ENABLED_Val            _UINT32_(0x1)                                        /* (QSPI_IFR) Continuous Read mode is enabled.  */
#define QSPI_IFR_CRM_DISABLED                 (QSPI_IFR_CRM_DISABLED_Val << QSPI_IFR_CRM_Pos)      /* (QSPI_IFR) Continuous Read mode is disabled. Position  */
#define QSPI_IFR_CRM_ENABLED                  (QSPI_IFR_CRM_ENABLED_Val << QSPI_IFR_CRM_Pos)       /* (QSPI_IFR) Continuous Read mode is enabled. Position  */
#define QSPI_IFR_DDREN_Pos                    _UINT32_(15)                                         /* (QSPI_IFR) DDR Mode Enable Position */
#define QSPI_IFR_DDREN_Msk                    (_UINT32_(0x1) << QSPI_IFR_DDREN_Pos)                /* (QSPI_IFR) DDR Mode Enable Mask */
#define QSPI_IFR_DDREN(value)                 (QSPI_IFR_DDREN_Msk & (_UINT32_(value) << QSPI_IFR_DDREN_Pos)) /* Assigment of value for DDREN in the QSPI_IFR register */
#define   QSPI_IFR_DDREN_DISABLED_Val         _UINT32_(0x0)                                        /* (QSPI_IFR) Transfers are performed in Single Data Rate mode.  */
#define   QSPI_IFR_DDREN_ENABLED_Val          _UINT32_(0x1)                                        /* (QSPI_IFR) Transfers are performed in Double Data Rate mode, whereas the instruction field is still transferred in Single Data Rate mode.  */
#define QSPI_IFR_DDREN_DISABLED               (QSPI_IFR_DDREN_DISABLED_Val << QSPI_IFR_DDREN_Pos)  /* (QSPI_IFR) Transfers are performed in Single Data Rate mode. Position  */
#define QSPI_IFR_DDREN_ENABLED                (QSPI_IFR_DDREN_ENABLED_Val << QSPI_IFR_DDREN_Pos)   /* (QSPI_IFR) Transfers are performed in Double Data Rate mode, whereas the instruction field is still transferred in Single Data Rate mode. Position  */
#define QSPI_IFR_NBDUM_Pos                    _UINT32_(16)                                         /* (QSPI_IFR) Number Of Dummy Cycles Position */
#define QSPI_IFR_NBDUM_Msk                    (_UINT32_(0x1F) << QSPI_IFR_NBDUM_Pos)               /* (QSPI_IFR) Number Of Dummy Cycles Mask */
#define QSPI_IFR_NBDUM(value)                 (QSPI_IFR_NBDUM_Msk & (_UINT32_(value) << QSPI_IFR_NBDUM_Pos)) /* Assigment of value for NBDUM in the QSPI_IFR register */
#define QSPI_IFR_END_Pos                      _UINT32_(22)                                         /* (QSPI_IFR) Endianness Position */
#define QSPI_IFR_END_Msk                      (_UINT32_(0x1) << QSPI_IFR_END_Pos)                  /* (QSPI_IFR) Endianness Mask */
#define QSPI_IFR_END(value)                   (QSPI_IFR_END_Msk & (_UINT32_(value) << QSPI_IFR_END_Pos)) /* Assigment of value for END in the QSPI_IFR register */
#define   QSPI_IFR_END_0_Val                  _UINT32_(0x0)                                        /* (QSPI_IFR) Data are sent in little-endian format to the memory.  */
#define   QSPI_IFR_END_1_Val                  _UINT32_(0x1)                                        /* (QSPI_IFR) Data are sent in big-endian format to the memory.  */
#define QSPI_IFR_END_0                        (QSPI_IFR_END_0_Val << QSPI_IFR_END_Pos)             /* (QSPI_IFR) Data are sent in little-endian format to the memory. Position  */
#define QSPI_IFR_END_1                        (QSPI_IFR_END_1_Val << QSPI_IFR_END_Pos)             /* (QSPI_IFR) Data are sent in big-endian format to the memory. Position  */
#define QSPI_IFR_SMRM_Pos                     _UINT32_(23)                                         /* (QSPI_IFR) Serial Memory Register Mode Position */
#define QSPI_IFR_SMRM_Msk                     (_UINT32_(0x1) << QSPI_IFR_SMRM_Pos)                 /* (QSPI_IFR) Serial Memory Register Mode Mask */
#define QSPI_IFR_SMRM(value)                  (QSPI_IFR_SMRM_Msk & (_UINT32_(value) << QSPI_IFR_SMRM_Pos)) /* Assigment of value for SMRM in the QSPI_IFR register */
#define   QSPI_IFR_SMRM_0_Val                 _UINT32_(0x0)                                        /* (QSPI_IFR) Serial Memory registers are written via AHB access. See Instruction Frame Transmission for details.  */
#define   QSPI_IFR_SMRM_1_Val                 _UINT32_(0x1)                                        /* (QSPI_IFR) Serial Memory registers are written via APB access. See Instruction Frame Transmission for details.  */
#define QSPI_IFR_SMRM_0                       (QSPI_IFR_SMRM_0_Val << QSPI_IFR_SMRM_Pos)           /* (QSPI_IFR) Serial Memory registers are written via AHB access. See Instruction Frame Transmission for details. Position  */
#define QSPI_IFR_SMRM_1                       (QSPI_IFR_SMRM_1_Val << QSPI_IFR_SMRM_Pos)           /* (QSPI_IFR) Serial Memory registers are written via APB access. See Instruction Frame Transmission for details. Position  */
#define QSPI_IFR_APBTFRTYP_Pos                _UINT32_(24)                                         /* (QSPI_IFR) Peripheral BusTransfer Type Position */
#define QSPI_IFR_APBTFRTYP_Msk                (_UINT32_(0x1) << QSPI_IFR_APBTFRTYP_Pos)            /* (QSPI_IFR) Peripheral BusTransfer Type Mask */
#define QSPI_IFR_APBTFRTYP(value)             (QSPI_IFR_APBTFRTYP_Msk & (_UINT32_(value) << QSPI_IFR_APBTFRTYP_Pos)) /* Assigment of value for APBTFRTYP in the QSPI_IFR register */
#define   QSPI_IFR_APBTFRTYP_0_Val            _UINT32_(0x0)                                        /* (QSPI_IFR) Peripheral bus register transfer to the memory is a write transfer. Used when TRFTYP is written to '0' and SMRM to '1'.  */
#define   QSPI_IFR_APBTFRTYP_1_Val            _UINT32_(0x1)                                        /* (QSPI_IFR) Peripheral bus register transfer to the memory is a read transfer. Used when TRFTYP is written to '0' and SMRM to '1'.  */
#define QSPI_IFR_APBTFRTYP_0                  (QSPI_IFR_APBTFRTYP_0_Val << QSPI_IFR_APBTFRTYP_Pos) /* (QSPI_IFR) Peripheral bus register transfer to the memory is a write transfer. Used when TRFTYP is written to '0' and SMRM to '1'. Position  */
#define QSPI_IFR_APBTFRTYP_1                  (QSPI_IFR_APBTFRTYP_1_Val << QSPI_IFR_APBTFRTYP_Pos) /* (QSPI_IFR) Peripheral bus register transfer to the memory is a read transfer. Used when TRFTYP is written to '0' and SMRM to '1'. Position  */
#define QSPI_IFR_DQSEN_Pos                    _UINT32_(25)                                         /* (QSPI_IFR) DQS Sampling Enable Position */
#define QSPI_IFR_DQSEN_Msk                    (_UINT32_(0x1) << QSPI_IFR_DQSEN_Pos)                /* (QSPI_IFR) DQS Sampling Enable Mask */
#define QSPI_IFR_DQSEN(value)                 (QSPI_IFR_DQSEN_Msk & (_UINT32_(value) << QSPI_IFR_DQSEN_Pos)) /* Assigment of value for DQSEN in the QSPI_IFR register */
#define   QSPI_IFR_DQSEN_0_Val                _UINT32_(0x0)                                        /* (QSPI_IFR) Data from the memory are not sampled with DQS signal.  */
#define   QSPI_IFR_DQSEN_1_Val                _UINT32_(0x1)                                        /* (QSPI_IFR) Data from the memory are sampled with DQS signal.  */
#define QSPI_IFR_DQSEN_0                      (QSPI_IFR_DQSEN_0_Val << QSPI_IFR_DQSEN_Pos)         /* (QSPI_IFR) Data from the memory are not sampled with DQS signal. Position  */
#define QSPI_IFR_DQSEN_1                      (QSPI_IFR_DQSEN_1_Val << QSPI_IFR_DQSEN_Pos)         /* (QSPI_IFR) Data from the memory are sampled with DQS signal. Position  */
#define QSPI_IFR_DDRCMDEN_Pos                 _UINT32_(26)                                         /* (QSPI_IFR) DDR Mode Command Enable Position */
#define QSPI_IFR_DDRCMDEN_Msk                 (_UINT32_(0x1) << QSPI_IFR_DDRCMDEN_Pos)             /* (QSPI_IFR) DDR Mode Command Enable Mask */
#define QSPI_IFR_DDRCMDEN(value)              (QSPI_IFR_DDRCMDEN_Msk & (_UINT32_(value) << QSPI_IFR_DDRCMDEN_Pos)) /* Assigment of value for DDRCMDEN in the QSPI_IFR register */
#define   QSPI_IFR_DDRCMDEN_DISABLED_Val      _UINT32_(0x0)                                        /* (QSPI_IFR) Transfer of instruction field is performed in Single Data Rate mode even if DDREN is written to '1'.  */
#define   QSPI_IFR_DDRCMDEN_ENABLED_Val       _UINT32_(0x1)                                        /* (QSPI_IFR) Transfer of instruction field is performed in Double Data Rate mode if DDREN bit is written to '1'. If DDREN is written to '0', the instruction field is sent in Single Data Rate mode.  */
#define QSPI_IFR_DDRCMDEN_DISABLED            (QSPI_IFR_DDRCMDEN_DISABLED_Val << QSPI_IFR_DDRCMDEN_Pos) /* (QSPI_IFR) Transfer of instruction field is performed in Single Data Rate mode even if DDREN is written to '1'. Position  */
#define QSPI_IFR_DDRCMDEN_ENABLED             (QSPI_IFR_DDRCMDEN_ENABLED_Val << QSPI_IFR_DDRCMDEN_Pos) /* (QSPI_IFR) Transfer of instruction field is performed in Double Data Rate mode if DDREN bit is written to '1'. If DDREN is written to '0', the instruction field is sent in Single Data Rate mode. Position  */
#define QSPI_IFR_HFWBEN_Pos                   _UINT32_(27)                                         /* (QSPI_IFR) HyperFlash Write Buffer Enable Position */
#define QSPI_IFR_HFWBEN_Msk                   (_UINT32_(0x1) << QSPI_IFR_HFWBEN_Pos)               /* (QSPI_IFR) HyperFlash Write Buffer Enable Mask */
#define QSPI_IFR_HFWBEN(value)                (QSPI_IFR_HFWBEN_Msk & (_UINT32_(value) << QSPI_IFR_HFWBEN_Pos)) /* Assigment of value for HFWBEN in the QSPI_IFR register */
#define   QSPI_IFR_HFWBEN_0_Val               _UINT32_(0x0)                                        /* (QSPI_IFR) No effect.  */
#define   QSPI_IFR_HFWBEN_1_Val               _UINT32_(0x1)                                        /* (QSPI_IFR) Each write access received on the system bus interface generates a new command. IMPORTANT: Mandatory if HyperFlash Write Buffer feature is used.  */
#define QSPI_IFR_HFWBEN_0                     (QSPI_IFR_HFWBEN_0_Val << QSPI_IFR_HFWBEN_Pos)       /* (QSPI_IFR) No effect. Position  */
#define QSPI_IFR_HFWBEN_1                     (QSPI_IFR_HFWBEN_1_Val << QSPI_IFR_HFWBEN_Pos)       /* (QSPI_IFR) Each write access received on the system bus interface generates a new command. IMPORTANT: Mandatory if HyperFlash Write Buffer feature is used. Position  */
#define QSPI_IFR_PROTTYP_Pos                  _UINT32_(28)                                         /* (QSPI_IFR) Protocol Type Position */
#define QSPI_IFR_PROTTYP_Msk                  (_UINT32_(0x3) << QSPI_IFR_PROTTYP_Pos)              /* (QSPI_IFR) Protocol Type Mask */
#define QSPI_IFR_PROTTYP(value)               (QSPI_IFR_PROTTYP_Msk & (_UINT32_(value) << QSPI_IFR_PROTTYP_Pos)) /* Assigment of value for PROTTYP in the QSPI_IFR register */
#define   QSPI_IFR_PROTTYP_STD_SPI_Val        _UINT32_(0x0)                                        /* (QSPI_IFR) Standard (Q)SPI Protocol  */
#define   QSPI_IFR_PROTTYP_TWIN_QUAD_Val      _UINT32_(0x1)                                        /* (QSPI_IFR) Twin-Quad Protocol  */
#define   QSPI_IFR_PROTTYP_OCTAFLASH_Val      _UINT32_(0x2)                                        /* (QSPI_IFR) OctaFlash Protocol  */
#define   QSPI_IFR_PROTTYP_HYPERFLASH_Val     _UINT32_(0x3)                                        /* (QSPI_IFR) HyperFlash Protocol  */
#define QSPI_IFR_PROTTYP_STD_SPI              (QSPI_IFR_PROTTYP_STD_SPI_Val << QSPI_IFR_PROTTYP_Pos) /* (QSPI_IFR) Standard (Q)SPI Protocol Position  */
#define QSPI_IFR_PROTTYP_TWIN_QUAD            (QSPI_IFR_PROTTYP_TWIN_QUAD_Val << QSPI_IFR_PROTTYP_Pos) /* (QSPI_IFR) Twin-Quad Protocol Position  */
#define QSPI_IFR_PROTTYP_OCTAFLASH            (QSPI_IFR_PROTTYP_OCTAFLASH_Val << QSPI_IFR_PROTTYP_Pos) /* (QSPI_IFR) OctaFlash Protocol Position  */
#define QSPI_IFR_PROTTYP_HYPERFLASH           (QSPI_IFR_PROTTYP_HYPERFLASH_Val << QSPI_IFR_PROTTYP_Pos) /* (QSPI_IFR) HyperFlash Protocol Position  */
#define QSPI_IFR_Msk                          _UINT32_(0x3FDFDFFF)                                 /* (QSPI_IFR) Register Mask  */


/* -------- QSPI_RICR : (QSPI Offset: 0x3C) (R/W 32) Read Instruction Code Register -------- */
#define QSPI_RICR_RESETVALUE                  _UINT32_(0x00)                                       /*  (QSPI_RICR) Read Instruction Code Register  Reset Value */

#define QSPI_RICR_RDINST_Pos                  _UINT32_(0)                                          /* (QSPI_RICR) Read Instruction Code Position */
#define QSPI_RICR_RDINST_Msk                  (_UINT32_(0xFFFF) << QSPI_RICR_RDINST_Pos)           /* (QSPI_RICR) Read Instruction Code Mask */
#define QSPI_RICR_RDINST(value)               (QSPI_RICR_RDINST_Msk & (_UINT32_(value) << QSPI_RICR_RDINST_Pos)) /* Assigment of value for RDINST in the QSPI_RICR register */
#define QSPI_RICR_RDOPT_Pos                   _UINT32_(16)                                         /* (QSPI_RICR) Read Option Code Position */
#define QSPI_RICR_RDOPT_Msk                   (_UINT32_(0xFF) << QSPI_RICR_RDOPT_Pos)              /* (QSPI_RICR) Read Option Code Mask */
#define QSPI_RICR_RDOPT(value)                (QSPI_RICR_RDOPT_Msk & (_UINT32_(value) << QSPI_RICR_RDOPT_Pos)) /* Assigment of value for RDOPT in the QSPI_RICR register */
#define QSPI_RICR_Msk                         _UINT32_(0x00FFFFFF)                                 /* (QSPI_RICR) Register Mask  */


/* -------- QSPI_SMR : (QSPI Offset: 0x40) (R/W 32) Scrambling Mode Register -------- */
#define QSPI_SMR_RESETVALUE                   _UINT32_(0x00)                                       /*  (QSPI_SMR) Scrambling Mode Register  Reset Value */

#define QSPI_SMR_SCREN_Pos                    _UINT32_(0)                                          /* (QSPI_SMR) Scrambling/Unscrambling Enable Position */
#define QSPI_SMR_SCREN_Msk                    (_UINT32_(0x1) << QSPI_SMR_SCREN_Pos)                /* (QSPI_SMR) Scrambling/Unscrambling Enable Mask */
#define QSPI_SMR_SCREN(value)                 (QSPI_SMR_SCREN_Msk & (_UINT32_(value) << QSPI_SMR_SCREN_Pos)) /* Assigment of value for SCREN in the QSPI_SMR register */
#define   QSPI_SMR_SCREN_DISABLED_Val         _UINT32_(0x0)                                        /* (QSPI_SMR) The scrambling/unscrambling is disabled.  */
#define   QSPI_SMR_SCREN_ENABLED_Val          _UINT32_(0x1)                                        /* (QSPI_SMR) The scrambling/unscrambling is enabled.  */
#define QSPI_SMR_SCREN_DISABLED               (QSPI_SMR_SCREN_DISABLED_Val << QSPI_SMR_SCREN_Pos)  /* (QSPI_SMR) The scrambling/unscrambling is disabled. Position  */
#define QSPI_SMR_SCREN_ENABLED                (QSPI_SMR_SCREN_ENABLED_Val << QSPI_SMR_SCREN_Pos)   /* (QSPI_SMR) The scrambling/unscrambling is enabled. Position  */
#define QSPI_SMR_RVDIS_Pos                    _UINT32_(1)                                          /* (QSPI_SMR) Scrambling/Unscrambling Random Value Disable Position */
#define QSPI_SMR_RVDIS_Msk                    (_UINT32_(0x1) << QSPI_SMR_RVDIS_Pos)                /* (QSPI_SMR) Scrambling/Unscrambling Random Value Disable Mask */
#define QSPI_SMR_RVDIS(value)                 (QSPI_SMR_RVDIS_Msk & (_UINT32_(value) << QSPI_SMR_RVDIS_Pos)) /* Assigment of value for RVDIS in the QSPI_SMR register */
#define   QSPI_SMR_RVDIS_0_Val                _UINT32_(0x0)                                        /* (QSPI_SMR) The scrambling/unscrambling algorithm includes the user scrambling key plus a random value that may differ between devices.  */
#define   QSPI_SMR_RVDIS_1_Val                _UINT32_(0x1)                                        /* (QSPI_SMR) The scrambling/unscrambling algorithm includes only the user scrambling key.  */
#define QSPI_SMR_RVDIS_0                      (QSPI_SMR_RVDIS_0_Val << QSPI_SMR_RVDIS_Pos)         /* (QSPI_SMR) The scrambling/unscrambling algorithm includes the user scrambling key plus a random value that may differ between devices. Position  */
#define QSPI_SMR_RVDIS_1                      (QSPI_SMR_RVDIS_1_Val << QSPI_SMR_RVDIS_Pos)         /* (QSPI_SMR) The scrambling/unscrambling algorithm includes only the user scrambling key. Position  */
#define QSPI_SMR_SCRKL_Pos                    _UINT32_(2)                                          /* (QSPI_SMR) Scrambling Key Lock Position */
#define QSPI_SMR_SCRKL_Msk                    (_UINT32_(0x1) << QSPI_SMR_SCRKL_Pos)                /* (QSPI_SMR) Scrambling Key Lock Mask */
#define QSPI_SMR_SCRKL(value)                 (QSPI_SMR_SCRKL_Msk & (_UINT32_(value) << QSPI_SMR_SCRKL_Pos)) /* Assigment of value for SCRKL in the QSPI_SMR register */
#define   QSPI_SMR_SCRKL_0_Val                _UINT32_(0x0)                                        /* (QSPI_SMR) No action.  */
#define   QSPI_SMR_SCRKL_1_Val                _UINT32_(0x1)                                        /* (QSPI_SMR) QSPI_SKR.USRK cannot be written until the next VDDCORE reset.  */
#define QSPI_SMR_SCRKL_0                      (QSPI_SMR_SCRKL_0_Val << QSPI_SMR_SCRKL_Pos)         /* (QSPI_SMR) No action. Position  */
#define QSPI_SMR_SCRKL_1                      (QSPI_SMR_SCRKL_1_Val << QSPI_SMR_SCRKL_Pos)         /* (QSPI_SMR) QSPI_SKR.USRK cannot be written until the next VDDCORE reset. Position  */
#define QSPI_SMR_Msk                          _UINT32_(0x00000007)                                 /* (QSPI_SMR) Register Mask  */


/* -------- QSPI_SKR : (QSPI Offset: 0x44) ( /W 32) Scrambling Key Register -------- */
#define QSPI_SKR_USRK_Pos                     _UINT32_(0)                                          /* (QSPI_SKR) User Scrambling Key Position */
#define QSPI_SKR_USRK_Msk                     (_UINT32_(0xFFFFFFFF) << QSPI_SKR_USRK_Pos)          /* (QSPI_SKR) User Scrambling Key Mask */
#define QSPI_SKR_USRK(value)                  (QSPI_SKR_USRK_Msk & (_UINT32_(value) << QSPI_SKR_USRK_Pos)) /* Assigment of value for USRK in the QSPI_SKR register */
#define QSPI_SKR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (QSPI_SKR) Register Mask  */


/* -------- QSPI_REFRESH : (QSPI Offset: 0x50) (R/W 32) Refresh Register -------- */
#define QSPI_REFRESH_RESETVALUE               _UINT32_(0x00)                                       /*  (QSPI_REFRESH) Refresh Register  Reset Value */

#define QSPI_REFRESH_REFRESH_Pos              _UINT32_(0)                                          /* (QSPI_REFRESH) REFRESH Delay Counter Position */
#define QSPI_REFRESH_REFRESH_Msk              (_UINT32_(0xFFFFFFFF) << QSPI_REFRESH_REFRESH_Pos)   /* (QSPI_REFRESH) REFRESH Delay Counter Mask */
#define QSPI_REFRESH_REFRESH(value)           (QSPI_REFRESH_REFRESH_Msk & (_UINT32_(value) << QSPI_REFRESH_REFRESH_Pos)) /* Assigment of value for REFRESH in the QSPI_REFRESH register */
#define QSPI_REFRESH_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (QSPI_REFRESH) Register Mask  */


/* -------- QSPI_WRACNT : (QSPI Offset: 0x54) (R/W 32) Write Access Counter Register -------- */
#define QSPI_WRACNT_RESETVALUE                _UINT32_(0x00)                                       /*  (QSPI_WRACNT) Write Access Counter Register  Reset Value */

#define QSPI_WRACNT_NBWRA_Pos                 _UINT32_(0)                                          /* (QSPI_WRACNT) Number of Write Accesses Position */
#define QSPI_WRACNT_NBWRA_Msk                 (_UINT32_(0xFFFFFFFF) << QSPI_WRACNT_NBWRA_Pos)      /* (QSPI_WRACNT) Number of Write Accesses Mask */
#define QSPI_WRACNT_NBWRA(value)              (QSPI_WRACNT_NBWRA_Msk & (_UINT32_(value) << QSPI_WRACNT_NBWRA_Pos)) /* Assigment of value for NBWRA in the QSPI_WRACNT register */
#define QSPI_WRACNT_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (QSPI_WRACNT) Register Mask  */


/* -------- QSPI_PCALCFG : (QSPI Offset: 0x5C) (R/W 32) Pad Calibration Configuration Register -------- */
#define QSPI_PCALCFG_RESETVALUE               _UINT32_(0x70)                                       /*  (QSPI_PCALCFG) Pad Calibration Configuration Register  Reset Value */

#define QSPI_PCALCFG_DIFFPM_Pos               _UINT32_(2)                                          /* (QSPI_PCALCFG) Differential Pad Mode Position */
#define QSPI_PCALCFG_DIFFPM_Msk               (_UINT32_(0x1) << QSPI_PCALCFG_DIFFPM_Pos)           /* (QSPI_PCALCFG) Differential Pad Mode Mask */
#define QSPI_PCALCFG_DIFFPM(value)            (QSPI_PCALCFG_DIFFPM_Msk & (_UINT32_(value) << QSPI_PCALCFG_DIFFPM_Pos)) /* Assigment of value for DIFFPM in the QSPI_PCALCFG register */
#define   QSPI_PCALCFG_DIFFPM_0_Val           _UINT32_(0x0)                                        /* (QSPI_PCALCFG) Pad differential mode is not enabled.  */
#define   QSPI_PCALCFG_DIFFPM_1_Val           _UINT32_(0x1)                                        /* (QSPI_PCALCFG) Pad differential mode is enabled.  */
#define QSPI_PCALCFG_DIFFPM_0                 (QSPI_PCALCFG_DIFFPM_0_Val << QSPI_PCALCFG_DIFFPM_Pos) /* (QSPI_PCALCFG) Pad differential mode is not enabled. Position  */
#define QSPI_PCALCFG_DIFFPM_1                 (QSPI_PCALCFG_DIFFPM_1_Val << QSPI_PCALCFG_DIFFPM_Pos) /* (QSPI_PCALCFG) Pad differential mode is enabled. Position  */
#define QSPI_PCALCFG_Msk                      _UINT32_(0x00000004)                                 /* (QSPI_PCALCFG) Register Mask  */


/* -------- QSPI_TOUT : (QSPI Offset: 0x64) (R/W 32) Timeout Register -------- */
#define QSPI_TOUT_RESETVALUE                  _UINT32_(0x00)                                       /*  (QSPI_TOUT) Timeout Register  Reset Value */

#define QSPI_TOUT_TCNTM_Pos                   _UINT32_(0)                                          /* (QSPI_TOUT) Time-out Counter Maximum Value Position */
#define QSPI_TOUT_TCNTM_Msk                   (_UINT32_(0xFFFF) << QSPI_TOUT_TCNTM_Pos)            /* (QSPI_TOUT) Time-out Counter Maximum Value Mask */
#define QSPI_TOUT_TCNTM(value)                (QSPI_TOUT_TCNTM_Msk & (_UINT32_(value) << QSPI_TOUT_TCNTM_Pos)) /* Assigment of value for TCNTM in the QSPI_TOUT register */
#define QSPI_TOUT_Msk                         _UINT32_(0x0000FFFF)                                 /* (QSPI_TOUT) Register Mask  */


/* -------- QSPI_WPMR : (QSPI Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define QSPI_WPMR_RESETVALUE                  _UINT32_(0x00)                                       /*  (QSPI_WPMR) Write Protection Mode Register  Reset Value */

#define QSPI_WPMR_WPEN_Pos                    _UINT32_(0)                                          /* (QSPI_WPMR) Write Protection Enable Position */
#define QSPI_WPMR_WPEN_Msk                    (_UINT32_(0x1) << QSPI_WPMR_WPEN_Pos)                /* (QSPI_WPMR) Write Protection Enable Mask */
#define QSPI_WPMR_WPEN(value)                 (QSPI_WPMR_WPEN_Msk & (_UINT32_(value) << QSPI_WPMR_WPEN_Pos)) /* Assigment of value for WPEN in the QSPI_WPMR register */
#define   QSPI_WPMR_WPEN_0_Val                _UINT32_(0x0)                                        /* (QSPI_WPMR) Disables the write protection if WPKEY corresponds to 0x515350 ("QSP" in ASCII)  */
#define   QSPI_WPMR_WPEN_1_Val                _UINT32_(0x1)                                        /* (QSPI_WPMR) Enables the write protection if WPKEY corresponds to 0x515350 ("QSP" in ASCII)  */
#define QSPI_WPMR_WPEN_0                      (QSPI_WPMR_WPEN_0_Val << QSPI_WPMR_WPEN_Pos)         /* (QSPI_WPMR) Disables the write protection if WPKEY corresponds to 0x515350 ("QSP" in ASCII) Position  */
#define QSPI_WPMR_WPEN_1                      (QSPI_WPMR_WPEN_1_Val << QSPI_WPMR_WPEN_Pos)         /* (QSPI_WPMR) Enables the write protection if WPKEY corresponds to 0x515350 ("QSP" in ASCII) Position  */
#define QSPI_WPMR_WPITEN_Pos                  _UINT32_(1)                                          /* (QSPI_WPMR) Write Protection Interrupt Enable Position */
#define QSPI_WPMR_WPITEN_Msk                  (_UINT32_(0x1) << QSPI_WPMR_WPITEN_Pos)              /* (QSPI_WPMR) Write Protection Interrupt Enable Mask */
#define QSPI_WPMR_WPITEN(value)               (QSPI_WPMR_WPITEN_Msk & (_UINT32_(value) << QSPI_WPMR_WPITEN_Pos)) /* Assigment of value for WPITEN in the QSPI_WPMR register */
#define   QSPI_WPMR_WPITEN_0_Val              _UINT32_(0x0)                                        /* (QSPI_WPMR) Disables the write protection on Interrupt registers if WPKEY corresponds to 0x515350.  */
#define   QSPI_WPMR_WPITEN_1_Val              _UINT32_(0x1)                                        /* (QSPI_WPMR) Enables the write protection on Interrupt registers if WPKEY corresponds to 0x515350.  */
#define QSPI_WPMR_WPITEN_0                    (QSPI_WPMR_WPITEN_0_Val << QSPI_WPMR_WPITEN_Pos)     /* (QSPI_WPMR) Disables the write protection on Interrupt registers if WPKEY corresponds to 0x515350. Position  */
#define QSPI_WPMR_WPITEN_1                    (QSPI_WPMR_WPITEN_1_Val << QSPI_WPMR_WPITEN_Pos)     /* (QSPI_WPMR) Enables the write protection on Interrupt registers if WPKEY corresponds to 0x515350. Position  */
#define QSPI_WPMR_WPCREN_Pos                  _UINT32_(2)                                          /* (QSPI_WPMR) Write Protection Control Register Enable Position */
#define QSPI_WPMR_WPCREN_Msk                  (_UINT32_(0x1) << QSPI_WPMR_WPCREN_Pos)              /* (QSPI_WPMR) Write Protection Control Register Enable Mask */
#define QSPI_WPMR_WPCREN(value)               (QSPI_WPMR_WPCREN_Msk & (_UINT32_(value) << QSPI_WPMR_WPCREN_Pos)) /* Assigment of value for WPCREN in the QSPI_WPMR register */
#define   QSPI_WPMR_WPCREN_0_Val              _UINT32_(0x0)                                        /* (QSPI_WPMR) Disables the write protection on the Control register if WPKEY corresponds to 0x515350.  */
#define   QSPI_WPMR_WPCREN_1_Val              _UINT32_(0x1)                                        /* (QSPI_WPMR) Enables the write protection on the Control register if WPKEY corresponds to 0x515350.  */
#define QSPI_WPMR_WPCREN_0                    (QSPI_WPMR_WPCREN_0_Val << QSPI_WPMR_WPCREN_Pos)     /* (QSPI_WPMR) Disables the write protection on the Control register if WPKEY corresponds to 0x515350. Position  */
#define QSPI_WPMR_WPCREN_1                    (QSPI_WPMR_WPCREN_1_Val << QSPI_WPMR_WPCREN_Pos)     /* (QSPI_WPMR) Enables the write protection on the Control register if WPKEY corresponds to 0x515350. Position  */
#define QSPI_WPMR_WPKEY_Pos                   _UINT32_(8)                                          /* (QSPI_WPMR) Write Protection Key Position */
#define QSPI_WPMR_WPKEY_Msk                   (_UINT32_(0xFFFFFF) << QSPI_WPMR_WPKEY_Pos)          /* (QSPI_WPMR) Write Protection Key Mask */
#define QSPI_WPMR_WPKEY(value)                (QSPI_WPMR_WPKEY_Msk & (_UINT32_(value) << QSPI_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the QSPI_WPMR register */
#define   QSPI_WPMR_WPKEY_PASSWD_Val          _UINT32_(0x515350)                                   /* (QSPI_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0.  */
#define QSPI_WPMR_WPKEY_PASSWD                (QSPI_WPMR_WPKEY_PASSWD_Val << QSPI_WPMR_WPKEY_Pos)  /* (QSPI_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0. Position  */
#define QSPI_WPMR_Msk                         _UINT32_(0xFFFFFF07)                                 /* (QSPI_WPMR) Register Mask  */


/* -------- QSPI_WPSR : (QSPI Offset: 0xE8) ( R/ 32) Write Protection Status Register -------- */
#define QSPI_WPSR_RESETVALUE                  _UINT32_(0x00)                                       /*  (QSPI_WPSR) Write Protection Status Register  Reset Value */

#define QSPI_WPSR_WPVS_Pos                    _UINT32_(0)                                          /* (QSPI_WPSR) Write Protection Violation Status Position */
#define QSPI_WPSR_WPVS_Msk                    (_UINT32_(0x1) << QSPI_WPSR_WPVS_Pos)                /* (QSPI_WPSR) Write Protection Violation Status Mask */
#define QSPI_WPSR_WPVS(value)                 (QSPI_WPSR_WPVS_Msk & (_UINT32_(value) << QSPI_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the QSPI_WPSR register */
#define   QSPI_WPSR_WPVS_0_Val                _UINT32_(0x0)                                        /* (QSPI_WPSR) No write protection violation has occurred since the last read of the QSPI_WPSR.  */
#define   QSPI_WPSR_WPVS_1_Val                _UINT32_(0x1)                                        /* (QSPI_WPSR) A write protection violation has occurred since the last read of the QSPI_WPSR. If this violation is an unauthorized attempt to write a protected register, the associated violation is reported into field WPVSRC.  */
#define QSPI_WPSR_WPVS_0                      (QSPI_WPSR_WPVS_0_Val << QSPI_WPSR_WPVS_Pos)         /* (QSPI_WPSR) No write protection violation has occurred since the last read of the QSPI_WPSR. Position  */
#define QSPI_WPSR_WPVS_1                      (QSPI_WPSR_WPVS_1_Val << QSPI_WPSR_WPVS_Pos)         /* (QSPI_WPSR) A write protection violation has occurred since the last read of the QSPI_WPSR. If this violation is an unauthorized attempt to write a protected register, the associated violation is reported into field WPVSRC. Position  */
#define QSPI_WPSR_WPVSRC_Pos                  _UINT32_(8)                                          /* (QSPI_WPSR) Write Protection Violation Source Position */
#define QSPI_WPSR_WPVSRC_Msk                  (_UINT32_(0xFF) << QSPI_WPSR_WPVSRC_Pos)             /* (QSPI_WPSR) Write Protection Violation Source Mask */
#define QSPI_WPSR_WPVSRC(value)               (QSPI_WPSR_WPVSRC_Msk & (_UINT32_(value) << QSPI_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the QSPI_WPSR register */
#define QSPI_WPSR_Msk                         _UINT32_(0x0000FF01)                                 /* (QSPI_WPSR) Register Mask  */


/* -------- QSPI_DLL_OS : (QSPI Offset: 0x300) (R/W 32) QSPI DLL Offset Selection Register -------- */
#define QSPI_DLL_OS_RESETVALUE                _UINT32_(0x00)                                       /*  (QSPI_DLL_OS) QSPI DLL Offset Selection Register  Reset Value */

#define QSPI_DLL_OS_SELOFF_Pos                _UINT32_(0)                                          /* (QSPI_DLL_OS) Offset Selection Position */
#define QSPI_DLL_OS_SELOFF_Msk                (_UINT32_(0x1) << QSPI_DLL_OS_SELOFF_Pos)            /* (QSPI_DLL_OS) Offset Selection Mask */
#define QSPI_DLL_OS_SELOFF(value)             (QSPI_DLL_OS_SELOFF_Msk & (_UINT32_(value) << QSPI_DLL_OS_SELOFF_Pos)) /* Assigment of value for SELOFF in the QSPI_DLL_OS register */
#define   QSPI_DLL_OS_SELOFF_0_Val            _UINT32_(0x0)                                        /* (QSPI_DLL_OS) The hardcoded offsets are selected.  */
#define   QSPI_DLL_OS_SELOFF_1_Val            _UINT32_(0x1)                                        /* (QSPI_DLL_OS) The programmable offsets are selected.  */
#define QSPI_DLL_OS_SELOFF_0                  (QSPI_DLL_OS_SELOFF_0_Val << QSPI_DLL_OS_SELOFF_Pos) /* (QSPI_DLL_OS) The hardcoded offsets are selected. Position  */
#define QSPI_DLL_OS_SELOFF_1                  (QSPI_DLL_OS_SELOFF_1_Val << QSPI_DLL_OS_SELOFF_Pos) /* (QSPI_DLL_OS) The programmable offsets are selected. Position  */
#define QSPI_DLL_OS_Msk                       _UINT32_(0x00000001)                                 /* (QSPI_DLL_OS) Register Mask  */


/* -------- QSPI_DLL_MAO : (QSPI Offset: 0x304) (R/W 32) QSPI DLL Host Offset Register -------- */
#define QSPI_DLL_MAO_RESETVALUE               _UINT32_(0x00)                                       /*  (QSPI_DLL_MAO) QSPI DLL Host Offset Register  Reset Value */

#define QSPI_DLL_MAO_MAOFF_Pos                _UINT32_(0)                                          /* (QSPI_DLL_MAO) Host Delay Line Offset Position */
#define QSPI_DLL_MAO_MAOFF_Msk                (_UINT32_(0xFF) << QSPI_DLL_MAO_MAOFF_Pos)           /* (QSPI_DLL_MAO) Host Delay Line Offset Mask */
#define QSPI_DLL_MAO_MAOFF(value)             (QSPI_DLL_MAO_MAOFF_Msk & (_UINT32_(value) << QSPI_DLL_MAO_MAOFF_Pos)) /* Assigment of value for MAOFF in the QSPI_DLL_MAO register */
#define QSPI_DLL_MAO_Msk                      _UINT32_(0x000000FF)                                 /* (QSPI_DLL_MAO) Register Mask  */


/* -------- QSPI_DLL_SO0 : (QSPI Offset: 0x308) (R/W 32) QSPI DLL Client Offset 0 Register -------- */
#define QSPI_DLL_SO0_RESETVALUE               _UINT32_(0x00)                                       /*  (QSPI_DLL_SO0) QSPI DLL Client Offset 0 Register  Reset Value */

#define QSPI_DLL_SO0_S0OFF_Pos                _UINT32_(0)                                          /* (QSPI_DLL_SO0) SLAVEx Delay Line Offset Position */
#define QSPI_DLL_SO0_S0OFF_Msk                (_UINT32_(0xFF) << QSPI_DLL_SO0_S0OFF_Pos)           /* (QSPI_DLL_SO0) SLAVEx Delay Line Offset Mask */
#define QSPI_DLL_SO0_S0OFF(value)             (QSPI_DLL_SO0_S0OFF_Msk & (_UINT32_(value) << QSPI_DLL_SO0_S0OFF_Pos)) /* Assigment of value for S0OFF in the QSPI_DLL_SO0 register */
#define QSPI_DLL_SO0_S1OFF_Pos                _UINT32_(8)                                          /* (QSPI_DLL_SO0) SLAVEx Delay Line Offset Position */
#define QSPI_DLL_SO0_S1OFF_Msk                (_UINT32_(0xFF) << QSPI_DLL_SO0_S1OFF_Pos)           /* (QSPI_DLL_SO0) SLAVEx Delay Line Offset Mask */
#define QSPI_DLL_SO0_S1OFF(value)             (QSPI_DLL_SO0_S1OFF_Msk & (_UINT32_(value) << QSPI_DLL_SO0_S1OFF_Pos)) /* Assigment of value for S1OFF in the QSPI_DLL_SO0 register */
#define QSPI_DLL_SO0_S2OFF_Pos                _UINT32_(16)                                         /* (QSPI_DLL_SO0) SLAVEx Delay Line Offset Position */
#define QSPI_DLL_SO0_S2OFF_Msk                (_UINT32_(0xFF) << QSPI_DLL_SO0_S2OFF_Pos)           /* (QSPI_DLL_SO0) SLAVEx Delay Line Offset Mask */
#define QSPI_DLL_SO0_S2OFF(value)             (QSPI_DLL_SO0_S2OFF_Msk & (_UINT32_(value) << QSPI_DLL_SO0_S2OFF_Pos)) /* Assigment of value for S2OFF in the QSPI_DLL_SO0 register */
#define QSPI_DLL_SO0_S3OFF_Pos                _UINT32_(24)                                         /* (QSPI_DLL_SO0) SLAVEx Delay Line Offset Position */
#define QSPI_DLL_SO0_S3OFF_Msk                (_UINT32_(0xFF) << QSPI_DLL_SO0_S3OFF_Pos)           /* (QSPI_DLL_SO0) SLAVEx Delay Line Offset Mask */
#define QSPI_DLL_SO0_S3OFF(value)             (QSPI_DLL_SO0_S3OFF_Msk & (_UINT32_(value) << QSPI_DLL_SO0_S3OFF_Pos)) /* Assigment of value for S3OFF in the QSPI_DLL_SO0 register */
#define QSPI_DLL_SO0_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (QSPI_DLL_SO0) Register Mask  */


/* -------- QSPI_DLL_SO1 : (QSPI Offset: 0x30C) (R/W 32) QSPI DLL Client Offset 1 Register -------- */
#define QSPI_DLL_SO1_RESETVALUE               _UINT32_(0x00)                                       /*  (QSPI_DLL_SO1) QSPI DLL Client Offset 1 Register  Reset Value */

#define QSPI_DLL_SO1_S4OFF_Pos                _UINT32_(0)                                          /* (QSPI_DLL_SO1) SLAVEx Delay Line Offset Position */
#define QSPI_DLL_SO1_S4OFF_Msk                (_UINT32_(0xFF) << QSPI_DLL_SO1_S4OFF_Pos)           /* (QSPI_DLL_SO1) SLAVEx Delay Line Offset Mask */
#define QSPI_DLL_SO1_S4OFF(value)             (QSPI_DLL_SO1_S4OFF_Msk & (_UINT32_(value) << QSPI_DLL_SO1_S4OFF_Pos)) /* Assigment of value for S4OFF in the QSPI_DLL_SO1 register */
#define QSPI_DLL_SO1_S5OFF_Pos                _UINT32_(8)                                          /* (QSPI_DLL_SO1) SLAVEx Delay Line Offset Position */
#define QSPI_DLL_SO1_S5OFF_Msk                (_UINT32_(0xFF) << QSPI_DLL_SO1_S5OFF_Pos)           /* (QSPI_DLL_SO1) SLAVEx Delay Line Offset Mask */
#define QSPI_DLL_SO1_S5OFF(value)             (QSPI_DLL_SO1_S5OFF_Msk & (_UINT32_(value) << QSPI_DLL_SO1_S5OFF_Pos)) /* Assigment of value for S5OFF in the QSPI_DLL_SO1 register */
#define QSPI_DLL_SO1_S6OFF_Pos                _UINT32_(16)                                         /* (QSPI_DLL_SO1) SLAVEx Delay Line Offset Position */
#define QSPI_DLL_SO1_S6OFF_Msk                (_UINT32_(0xFF) << QSPI_DLL_SO1_S6OFF_Pos)           /* (QSPI_DLL_SO1) SLAVEx Delay Line Offset Mask */
#define QSPI_DLL_SO1_S6OFF(value)             (QSPI_DLL_SO1_S6OFF_Msk & (_UINT32_(value) << QSPI_DLL_SO1_S6OFF_Pos)) /* Assigment of value for S6OFF in the QSPI_DLL_SO1 register */
#define QSPI_DLL_SO1_S7OFF_Pos                _UINT32_(24)                                         /* (QSPI_DLL_SO1) SLAVEx Delay Line Offset Position */
#define QSPI_DLL_SO1_S7OFF_Msk                (_UINT32_(0xFF) << QSPI_DLL_SO1_S7OFF_Pos)           /* (QSPI_DLL_SO1) SLAVEx Delay Line Offset Mask */
#define QSPI_DLL_SO1_S7OFF(value)             (QSPI_DLL_SO1_S7OFF_Msk & (_UINT32_(value) << QSPI_DLL_SO1_S7OFF_Pos)) /* Assigment of value for S7OFF in the QSPI_DLL_SO1 register */
#define QSPI_DLL_SO1_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (QSPI_DLL_SO1) Register Mask  */


/* -------- QSPI_DLL_SM0 : (QSPI Offset: 0x318) ( R/ 32) QSPI DLL Status Host 0 Register -------- */
#define QSPI_DLL_SM0_RESETVALUE               _UINT32_(0x00)                                       /*  (QSPI_DLL_SM0) QSPI DLL Status Host 0 Register  Reset Value */

#define QSPI_DLL_SM0_MDINC_Pos                _UINT32_(0)                                          /* (QSPI_DLL_SM0) MASTER0 Delay Increment Position */
#define QSPI_DLL_SM0_MDINC_Msk                (_UINT32_(0x1) << QSPI_DLL_SM0_MDINC_Pos)            /* (QSPI_DLL_SM0) MASTER0 Delay Increment Mask */
#define QSPI_DLL_SM0_MDINC(value)             (QSPI_DLL_SM0_MDINC_Msk & (_UINT32_(value) << QSPI_DLL_SM0_MDINC_Pos)) /* Assigment of value for MDINC in the QSPI_DLL_SM0 register */
#define   QSPI_DLL_SM0_MDINC_0_Val            _UINT32_(0x0)                                        /* (QSPI_DLL_SM0) The DQSDELAY is not incrementing the MASTER0 delay counter.  */
#define   QSPI_DLL_SM0_MDINC_1_Val            _UINT32_(0x1)                                        /* (QSPI_DLL_SM0) The DQSDELAY is incrementing the MASTER0 delay counter.  */
#define QSPI_DLL_SM0_MDINC_0                  (QSPI_DLL_SM0_MDINC_0_Val << QSPI_DLL_SM0_MDINC_Pos) /* (QSPI_DLL_SM0) The DQSDELAY is not incrementing the MASTER0 delay counter. Position  */
#define QSPI_DLL_SM0_MDINC_1                  (QSPI_DLL_SM0_MDINC_1_Val << QSPI_DLL_SM0_MDINC_Pos) /* (QSPI_DLL_SM0) The DQSDELAY is incrementing the MASTER0 delay counter. Position  */
#define QSPI_DLL_SM0_MDDEC_Pos                _UINT32_(1)                                          /* (QSPI_DLL_SM0) MASTER0 Delay Decrement Position */
#define QSPI_DLL_SM0_MDDEC_Msk                (_UINT32_(0x1) << QSPI_DLL_SM0_MDDEC_Pos)            /* (QSPI_DLL_SM0) MASTER0 Delay Decrement Mask */
#define QSPI_DLL_SM0_MDDEC(value)             (QSPI_DLL_SM0_MDDEC_Msk & (_UINT32_(value) << QSPI_DLL_SM0_MDDEC_Pos)) /* Assigment of value for MDDEC in the QSPI_DLL_SM0 register */
#define   QSPI_DLL_SM0_MDDEC_0_Val            _UINT32_(0x0)                                        /* (QSPI_DLL_SM0) The DQSDELAY is not decrementing the MASTER0 delay counter.  */
#define   QSPI_DLL_SM0_MDDEC_1_Val            _UINT32_(0x1)                                        /* (QSPI_DLL_SM0) The DQSDELAY is decrementing the MASTER0 delay counter.  */
#define QSPI_DLL_SM0_MDDEC_0                  (QSPI_DLL_SM0_MDDEC_0_Val << QSPI_DLL_SM0_MDDEC_Pos) /* (QSPI_DLL_SM0) The DQSDELAY is not decrementing the MASTER0 delay counter. Position  */
#define QSPI_DLL_SM0_MDDEC_1                  (QSPI_DLL_SM0_MDDEC_1_Val << QSPI_DLL_SM0_MDDEC_Pos) /* (QSPI_DLL_SM0) The DQSDELAY is decrementing the MASTER0 delay counter. Position  */
#define QSPI_DLL_SM0_MDOVF_Pos                _UINT32_(2)                                          /* (QSPI_DLL_SM0) MASTER0 Delay Overflow Flag Position */
#define QSPI_DLL_SM0_MDOVF_Msk                (_UINT32_(0x1) << QSPI_DLL_SM0_MDOVF_Pos)            /* (QSPI_DLL_SM0) MASTER0 Delay Overflow Flag Mask */
#define QSPI_DLL_SM0_MDOVF(value)             (QSPI_DLL_SM0_MDOVF_Msk & (_UINT32_(value) << QSPI_DLL_SM0_MDOVF_Pos)) /* Assigment of value for MDOVF in the QSPI_DLL_SM0 register */
#define   QSPI_DLL_SM0_MDOVF_0_Val            _UINT32_(0x0)                                        /* (QSPI_DLL_SM0) The MASTER0 delay counter has not reached its maximum value, or MASTER0 is not locked yet.  */
#define   QSPI_DLL_SM0_MDOVF_1_Val            _UINT32_(0x1)                                        /* (QSPI_DLL_SM0) The MASTER0 delay counter has reached its maximum value, the MASTER0 delay counter increment is stopped and the DQSDELAY forces the MASTER0 clock. If this flag is set, it means the DDR-SDRAM controller clock frequency is too low compared to MASTER0 delay line number of elements.  */
#define QSPI_DLL_SM0_MDOVF_0                  (QSPI_DLL_SM0_MDOVF_0_Val << QSPI_DLL_SM0_MDOVF_Pos) /* (QSPI_DLL_SM0) The MASTER0 delay counter has not reached its maximum value, or MASTER0 is not locked yet. Position  */
#define QSPI_DLL_SM0_MDOVF_1                  (QSPI_DLL_SM0_MDOVF_1_Val << QSPI_DLL_SM0_MDOVF_Pos) /* (QSPI_DLL_SM0) The MASTER0 delay counter has reached its maximum value, the MASTER0 delay counter increment is stopped and the DQSDELAY forces the MASTER0 clock. If this flag is set, it means the DDR-SDRAM controller clock frequency is too low compared to MASTER0 delay line number of elements. Position  */
#define QSPI_DLL_SM0_MDLVAL_Pos               _UINT32_(8)                                          /* (QSPI_DLL_SM0) MASTER0 Delay Lock Value Position */
#define QSPI_DLL_SM0_MDLVAL_Msk               (_UINT32_(0xFF) << QSPI_DLL_SM0_MDLVAL_Pos)          /* (QSPI_DLL_SM0) MASTER0 Delay Lock Value Mask */
#define QSPI_DLL_SM0_MDLVAL(value)            (QSPI_DLL_SM0_MDLVAL_Msk & (_UINT32_(value) << QSPI_DLL_SM0_MDLVAL_Pos)) /* Assigment of value for MDLVAL in the QSPI_DLL_SM0 register */
#define QSPI_DLL_SM0_MDCNT_Pos                _UINT32_(20)                                         /* (QSPI_DLL_SM0) MASTER0 Delay Counter Value Position */
#define QSPI_DLL_SM0_MDCNT_Msk                (_UINT32_(0xFF) << QSPI_DLL_SM0_MDCNT_Pos)           /* (QSPI_DLL_SM0) MASTER0 Delay Counter Value Mask */
#define QSPI_DLL_SM0_MDCNT(value)             (QSPI_DLL_SM0_MDCNT_Msk & (_UINT32_(value) << QSPI_DLL_SM0_MDCNT_Pos)) /* Assigment of value for MDCNT in the QSPI_DLL_SM0 register */
#define QSPI_DLL_SM0_Msk                      _UINT32_(0x0FF0FF07)                                 /* (QSPI_DLL_SM0) Register Mask  */


/* -------- QSPI_DLL_SSL : (QSPI Offset: 0x328) ( R/ 32) QSPI DLL Status Client x Register -------- */
#define QSPI_DLL_SSL_RESETVALUE               _UINT32_(0x00)                                       /*  (QSPI_DLL_SSL) QSPI DLL Status Client x Register  Reset Value */

#define QSPI_DLL_SSL_SDCOVF_Pos               _UINT32_(0)                                          /* (QSPI_DLL_SSL) SLAVE0 Delay Correction Overflow Flag Position */
#define QSPI_DLL_SSL_SDCOVF_Msk               (_UINT32_(0x1) << QSPI_DLL_SSL_SDCOVF_Pos)           /* (QSPI_DLL_SSL) SLAVE0 Delay Correction Overflow Flag Mask */
#define QSPI_DLL_SSL_SDCOVF(value)            (QSPI_DLL_SSL_SDCOVF_Msk & (_UINT32_(value) << QSPI_DLL_SSL_SDCOVF_Pos)) /* Assigment of value for SDCOVF in the QSPI_DLL_SSL register */
#define   QSPI_DLL_SSL_SDCOVF_0_Val           _UINT32_(0x0)                                        /* (QSPI_DLL_SSL) Due to the correction, the SLAVE0 delay counter has not reached its maximum value, or SLAVE0 is not locked yet.  */
#define   QSPI_DLL_SSL_SDCOVF_1_Val           _UINT32_(0x1)                                        /* (QSPI_DLL_SSL) Due to the correction, the SLAVE0 delay counter has reached its maximum value. The correction is not optimal because it is not applied entirely.  */
#define QSPI_DLL_SSL_SDCOVF_0                 (QSPI_DLL_SSL_SDCOVF_0_Val << QSPI_DLL_SSL_SDCOVF_Pos) /* (QSPI_DLL_SSL) Due to the correction, the SLAVE0 delay counter has not reached its maximum value, or SLAVE0 is not locked yet. Position  */
#define QSPI_DLL_SSL_SDCOVF_1                 (QSPI_DLL_SSL_SDCOVF_1_Val << QSPI_DLL_SSL_SDCOVF_Pos) /* (QSPI_DLL_SSL) Due to the correction, the SLAVE0 delay counter has reached its maximum value. The correction is not optimal because it is not applied entirely. Position  */
#define QSPI_DLL_SSL_SDCUDF_Pos               _UINT32_(1)                                          /* (QSPI_DLL_SSL) SLAVE0 Delay Correction Underflow Flag Position */
#define QSPI_DLL_SSL_SDCUDF_Msk               (_UINT32_(0x1) << QSPI_DLL_SSL_SDCUDF_Pos)           /* (QSPI_DLL_SSL) SLAVE0 Delay Correction Underflow Flag Mask */
#define QSPI_DLL_SSL_SDCUDF(value)            (QSPI_DLL_SSL_SDCUDF_Msk & (_UINT32_(value) << QSPI_DLL_SSL_SDCUDF_Pos)) /* Assigment of value for SDCUDF in the QSPI_DLL_SSL register */
#define   QSPI_DLL_SSL_SDCUDF_0_Val           _UINT32_(0x0)                                        /* (QSPI_DLL_SSL) Due to the correction, the SLAVE0 delay counter has not reached its minimum value, or SLAVE0 is not locked yet.  */
#define   QSPI_DLL_SSL_SDCUDF_1_Val           _UINT32_(0x1)                                        /* (QSPI_DLL_SSL) Due to the correction, the SLAVE0 delay counter has reached its minimum value. The correction is not optimal because it has not been applied entirely.  */
#define QSPI_DLL_SSL_SDCUDF_0                 (QSPI_DLL_SSL_SDCUDF_0_Val << QSPI_DLL_SSL_SDCUDF_Pos) /* (QSPI_DLL_SSL) Due to the correction, the SLAVE0 delay counter has not reached its minimum value, or SLAVE0 is not locked yet. Position  */
#define QSPI_DLL_SSL_SDCUDF_1                 (QSPI_DLL_SSL_SDCUDF_1_Val << QSPI_DLL_SSL_SDCUDF_Pos) /* (QSPI_DLL_SSL) Due to the correction, the SLAVE0 delay counter has reached its minimum value. The correction is not optimal because it has not been applied entirely. Position  */
#define QSPI_DLL_SSL_SDERF_Pos                _UINT32_(2)                                          /* (QSPI_DLL_SSL) SLAVE0 Delay Correction Error Flag Position */
#define QSPI_DLL_SSL_SDERF_Msk                (_UINT32_(0x1) << QSPI_DLL_SSL_SDERF_Pos)            /* (QSPI_DLL_SSL) SLAVE0 Delay Correction Error Flag Mask */
#define QSPI_DLL_SSL_SDERF(value)             (QSPI_DLL_SSL_SDERF_Msk & (_UINT32_(value) << QSPI_DLL_SSL_SDERF_Pos)) /* Assigment of value for SDERF in the QSPI_DLL_SSL register */
#define   QSPI_DLL_SSL_SDERF_0_Val            _UINT32_(0x0)                                        /* (QSPI_DLL_SSL) The DQSDELAY has succeeded in computing the SLAVE0 delay correction, or the client is not locked yet.  */
#define   QSPI_DLL_SSL_SDERF_1_Val            _UINT32_(0x1)                                        /* (QSPI_DLL_SSL) The DQSDELAY has not succeeded in computing the SLAVE0 delay correction.  */
#define QSPI_DLL_SSL_SDERF_0                  (QSPI_DLL_SSL_SDERF_0_Val << QSPI_DLL_SSL_SDERF_Pos) /* (QSPI_DLL_SSL) The DQSDELAY has succeeded in computing the SLAVE0 delay correction, or the client is not locked yet. Position  */
#define QSPI_DLL_SSL_SDERF_1                  (QSPI_DLL_SSL_SDERF_1_Val << QSPI_DLL_SSL_SDERF_Pos) /* (QSPI_DLL_SSL) The DQSDELAY has not succeeded in computing the SLAVE0 delay correction. Position  */
#define QSPI_DLL_SSL_SDCNT_Pos                _UINT32_(8)                                          /* (QSPI_DLL_SSL) SLAVE0 Delay Counter Value Position */
#define QSPI_DLL_SSL_SDCNT_Msk                (_UINT32_(0xFF) << QSPI_DLL_SSL_SDCNT_Pos)           /* (QSPI_DLL_SSL) SLAVE0 Delay Counter Value Mask */
#define QSPI_DLL_SSL_SDCNT(value)             (QSPI_DLL_SSL_SDCNT_Msk & (_UINT32_(value) << QSPI_DLL_SSL_SDCNT_Pos)) /* Assigment of value for SDCNT in the QSPI_DLL_SSL register */
#define QSPI_DLL_SSL_SDCVAL_Pos               _UINT32_(20)                                         /* (QSPI_DLL_SSL) SLAVE0 Delay Correction Value Position */
#define QSPI_DLL_SSL_SDCVAL_Msk               (_UINT32_(0xFF) << QSPI_DLL_SSL_SDCVAL_Pos)          /* (QSPI_DLL_SSL) SLAVE0 Delay Correction Value Mask */
#define QSPI_DLL_SSL_SDCVAL(value)            (QSPI_DLL_SSL_SDCVAL_Msk & (_UINT32_(value) << QSPI_DLL_SSL_SDCVAL_Pos)) /* Assigment of value for SDCVAL in the QSPI_DLL_SSL register */
#define QSPI_DLL_SSL_Msk                      _UINT32_(0x0FF0FF07)                                 /* (QSPI_DLL_SSL) Register Mask  */


/* -------- QSPI_DLL_BCR : (QSPI Offset: 0x3D0) (R/W 32) QSPI DLL BIST Control Register -------- */
#define QSPI_DLL_BCR_RESETVALUE               _UINT32_(0x00)                                       /*  (QSPI_DLL_BCR) QSPI DLL BIST Control Register  Reset Value */

#define QSPI_DLL_BCR_BMOD_Pos                 _UINT32_(0)                                          /* (QSPI_DLL_BCR) BIST Mode Position */
#define QSPI_DLL_BCR_BMOD_Msk                 (_UINT32_(0x1) << QSPI_DLL_BCR_BMOD_Pos)             /* (QSPI_DLL_BCR) BIST Mode Mask */
#define QSPI_DLL_BCR_BMOD(value)              (QSPI_DLL_BCR_BMOD_Msk & (_UINT32_(value) << QSPI_DLL_BCR_BMOD_Pos)) /* Assigment of value for BMOD in the QSPI_DLL_BCR register */
#define QSPI_DLL_BCR_BMOD2_Pos                _UINT32_(1)                                          /* (QSPI_DLL_BCR) BIST Mode 2 Position */
#define QSPI_DLL_BCR_BMOD2_Msk                (_UINT32_(0x1) << QSPI_DLL_BCR_BMOD2_Pos)            /* (QSPI_DLL_BCR) BIST Mode 2 Mask */
#define QSPI_DLL_BCR_BMOD2(value)             (QSPI_DLL_BCR_BMOD2_Msk & (_UINT32_(value) << QSPI_DLL_BCR_BMOD2_Pos)) /* Assigment of value for BMOD2 in the QSPI_DLL_BCR register */
#define QSPI_DLL_BCR_BISTKEY_Pos              _UINT32_(8)                                          /* (QSPI_DLL_BCR) BIST Key Position */
#define QSPI_DLL_BCR_BISTKEY_Msk              (_UINT32_(0xFFFFFF) << QSPI_DLL_BCR_BISTKEY_Pos)     /* (QSPI_DLL_BCR) BIST Key Mask */
#define QSPI_DLL_BCR_BISTKEY(value)           (QSPI_DLL_BCR_BISTKEY_Msk & (_UINT32_(value) << QSPI_DLL_BCR_BISTKEY_Pos)) /* Assigment of value for BISTKEY in the QSPI_DLL_BCR register */
#define   QSPI_DLL_BCR_BISTKEY_VALUE_Val      _UINT32_(0xDD3313)                                   /* (QSPI_DLL_BCR) Write to 0xDD3313 to enable modification of BMOD or BMOD2 state.  */
#define QSPI_DLL_BCR_BISTKEY_VALUE            (QSPI_DLL_BCR_BISTKEY_VALUE_Val << QSPI_DLL_BCR_BISTKEY_Pos) /* (QSPI_DLL_BCR) Write to 0xDD3313 to enable modification of BMOD or BMOD2 state. Position  */
#define QSPI_DLL_BCR_Msk                      _UINT32_(0xFFFFFF03)                                 /* (QSPI_DLL_BCR) Register Mask  */


/* -------- QSPI_DLL_BSR : (QSPI Offset: 0x3D4) ( R/ 32) QSPI DLL BIST Status Register -------- */
#define QSPI_DLL_BSR_RESETVALUE               _UINT32_(0x00)                                       /*  (QSPI_DLL_BSR) QSPI DLL BIST Status Register  Reset Value */

#define QSPI_DLL_BSR_BEND_Pos                 _UINT32_(0)                                          /* (QSPI_DLL_BSR) BIST End Position */
#define QSPI_DLL_BSR_BEND_Msk                 (_UINT32_(0x1) << QSPI_DLL_BSR_BEND_Pos)             /* (QSPI_DLL_BSR) BIST End Mask */
#define QSPI_DLL_BSR_BEND(value)              (QSPI_DLL_BSR_BEND_Msk & (_UINT32_(value) << QSPI_DLL_BSR_BEND_Pos)) /* Assigment of value for BEND in the QSPI_DLL_BSR register */
#define   QSPI_DLL_BSR_BEND_0_Val             _UINT32_(0x0)                                        /* (QSPI_DLL_BSR) BIST test has not started or is in progress.  */
#define   QSPI_DLL_BSR_BEND_1_Val             _UINT32_(0x1)                                        /* (QSPI_DLL_BSR) BIST test is finished.  */
#define QSPI_DLL_BSR_BEND_0                   (QSPI_DLL_BSR_BEND_0_Val << QSPI_DLL_BSR_BEND_Pos)   /* (QSPI_DLL_BSR) BIST test has not started or is in progress. Position  */
#define QSPI_DLL_BSR_BEND_1                   (QSPI_DLL_BSR_BEND_1_Val << QSPI_DLL_BSR_BEND_Pos)   /* (QSPI_DLL_BSR) BIST test is finished. Position  */
#define QSPI_DLL_BSR_B2END_Pos                _UINT32_(1)                                          /* (QSPI_DLL_BSR) BIST 2 End Position */
#define QSPI_DLL_BSR_B2END_Msk                (_UINT32_(0x1) << QSPI_DLL_BSR_B2END_Pos)            /* (QSPI_DLL_BSR) BIST 2 End Mask */
#define QSPI_DLL_BSR_B2END(value)             (QSPI_DLL_BSR_B2END_Msk & (_UINT32_(value) << QSPI_DLL_BSR_B2END_Pos)) /* Assigment of value for B2END in the QSPI_DLL_BSR register */
#define   QSPI_DLL_BSR_B2END_0_Val            _UINT32_(0x0)                                        /* (QSPI_DLL_BSR) BIST 2 test has not started or in progress.  */
#define   QSPI_DLL_BSR_B2END_1_Val            _UINT32_(0x1)                                        /* (QSPI_DLL_BSR) BIST 2 test is finished.  */
#define QSPI_DLL_BSR_B2END_0                  (QSPI_DLL_BSR_B2END_0_Val << QSPI_DLL_BSR_B2END_Pos) /* (QSPI_DLL_BSR) BIST 2 test has not started or in progress. Position  */
#define QSPI_DLL_BSR_B2END_1                  (QSPI_DLL_BSR_B2END_1_Val << QSPI_DLL_BSR_B2END_Pos) /* (QSPI_DLL_BSR) BIST 2 test is finished. Position  */
#define QSPI_DLL_BSR_B2PASS_Pos               _UINT32_(2)                                          /* (QSPI_DLL_BSR) BIST 2 Pass Position */
#define QSPI_DLL_BSR_B2PASS_Msk               (_UINT32_(0x1) << QSPI_DLL_BSR_B2PASS_Pos)           /* (QSPI_DLL_BSR) BIST 2 Pass Mask */
#define QSPI_DLL_BSR_B2PASS(value)            (QSPI_DLL_BSR_B2PASS_Msk & (_UINT32_(value) << QSPI_DLL_BSR_B2PASS_Pos)) /* Assigment of value for B2PASS in the QSPI_DLL_BSR register */
#define   QSPI_DLL_BSR_B2PASS_0_Val           _UINT32_(0x0)                                        /* (QSPI_DLL_BSR) The BIST 2 test has not finished or failed.  */
#define   QSPI_DLL_BSR_B2PASS_1_Val           _UINT32_(0x1)                                        /* (QSPI_DLL_BSR) The BIST 2 test ended successfully.  */
#define QSPI_DLL_BSR_B2PASS_0                 (QSPI_DLL_BSR_B2PASS_0_Val << QSPI_DLL_BSR_B2PASS_Pos) /* (QSPI_DLL_BSR) The BIST 2 test has not finished or failed. Position  */
#define QSPI_DLL_BSR_B2PASS_1                 (QSPI_DLL_BSR_B2PASS_1_Val << QSPI_DLL_BSR_B2PASS_Pos) /* (QSPI_DLL_BSR) The BIST 2 test ended successfully. Position  */
#define QSPI_DLL_BSR_B2FAIL_Pos               _UINT32_(3)                                          /* (QSPI_DLL_BSR) BIST 2 Fail Position */
#define QSPI_DLL_BSR_B2FAIL_Msk               (_UINT32_(0x1) << QSPI_DLL_BSR_B2FAIL_Pos)           /* (QSPI_DLL_BSR) BIST 2 Fail Mask */
#define QSPI_DLL_BSR_B2FAIL(value)            (QSPI_DLL_BSR_B2FAIL_Msk & (_UINT32_(value) << QSPI_DLL_BSR_B2FAIL_Pos)) /* Assigment of value for B2FAIL in the QSPI_DLL_BSR register */
#define   QSPI_DLL_BSR_B2FAIL_0_Val           _UINT32_(0x0)                                        /* (QSPI_DLL_BSR) The BIST 2 test has not finished or succeeded.  */
#define   QSPI_DLL_BSR_B2FAIL_1_Val           _UINT32_(0x1)                                        /* (QSPI_DLL_BSR) The BIST 2 test failed. Check DLB2FAILx bits to identify the corrupted delay lines.  */
#define QSPI_DLL_BSR_B2FAIL_0                 (QSPI_DLL_BSR_B2FAIL_0_Val << QSPI_DLL_BSR_B2FAIL_Pos) /* (QSPI_DLL_BSR) The BIST 2 test has not finished or succeeded. Position  */
#define QSPI_DLL_BSR_B2FAIL_1                 (QSPI_DLL_BSR_B2FAIL_1_Val << QSPI_DLL_BSR_B2FAIL_Pos) /* (QSPI_DLL_BSR) The BIST 2 test failed. Check DLB2FAILx bits to identify the corrupted delay lines. Position  */
#define QSPI_DLL_BSR_DLB2FAIL0_Pos            _UINT32_(8)                                          /* (QSPI_DLL_BSR) Delay Line BIST 2 Fail for Delay Line 0 Position */
#define QSPI_DLL_BSR_DLB2FAIL0_Msk            (_UINT32_(0x1) << QSPI_DLL_BSR_DLB2FAIL0_Pos)        /* (QSPI_DLL_BSR) Delay Line BIST 2 Fail for Delay Line 0 Mask */
#define QSPI_DLL_BSR_DLB2FAIL0(value)         (QSPI_DLL_BSR_DLB2FAIL0_Msk & (_UINT32_(value) << QSPI_DLL_BSR_DLB2FAIL0_Pos)) /* Assigment of value for DLB2FAIL0 in the QSPI_DLL_BSR register */
#define   QSPI_DLL_BSR_DLB2FAIL0_0_Val        _UINT32_(0x0)                                        /* (QSPI_DLL_BSR) The BIST 2 test did not fail.  */
#define   QSPI_DLL_BSR_DLB2FAIL0_1_Val        _UINT32_(0x1)                                        /* (QSPI_DLL_BSR) The BIST 2 test failed for delay line x.  */
#define QSPI_DLL_BSR_DLB2FAIL0_0              (QSPI_DLL_BSR_DLB2FAIL0_0_Val << QSPI_DLL_BSR_DLB2FAIL0_Pos) /* (QSPI_DLL_BSR) The BIST 2 test did not fail. Position  */
#define QSPI_DLL_BSR_DLB2FAIL0_1              (QSPI_DLL_BSR_DLB2FAIL0_1_Val << QSPI_DLL_BSR_DLB2FAIL0_Pos) /* (QSPI_DLL_BSR) The BIST 2 test failed for delay line x. Position  */
#define QSPI_DLL_BSR_DLB2FAIL1_Pos            _UINT32_(9)                                          /* (QSPI_DLL_BSR) Delay Line BIST 2 Fail for Delay Line 1 Position */
#define QSPI_DLL_BSR_DLB2FAIL1_Msk            (_UINT32_(0x1) << QSPI_DLL_BSR_DLB2FAIL1_Pos)        /* (QSPI_DLL_BSR) Delay Line BIST 2 Fail for Delay Line 1 Mask */
#define QSPI_DLL_BSR_DLB2FAIL1(value)         (QSPI_DLL_BSR_DLB2FAIL1_Msk & (_UINT32_(value) << QSPI_DLL_BSR_DLB2FAIL1_Pos)) /* Assigment of value for DLB2FAIL1 in the QSPI_DLL_BSR register */
#define   QSPI_DLL_BSR_DLB2FAIL1_0_Val        _UINT32_(0x0)                                        /* (QSPI_DLL_BSR) The BIST 2 test did not fail.  */
#define   QSPI_DLL_BSR_DLB2FAIL1_1_Val        _UINT32_(0x1)                                        /* (QSPI_DLL_BSR) The BIST 2 test failed for delay line x.  */
#define QSPI_DLL_BSR_DLB2FAIL1_0              (QSPI_DLL_BSR_DLB2FAIL1_0_Val << QSPI_DLL_BSR_DLB2FAIL1_Pos) /* (QSPI_DLL_BSR) The BIST 2 test did not fail. Position  */
#define QSPI_DLL_BSR_DLB2FAIL1_1              (QSPI_DLL_BSR_DLB2FAIL1_1_Val << QSPI_DLL_BSR_DLB2FAIL1_Pos) /* (QSPI_DLL_BSR) The BIST 2 test failed for delay line x. Position  */
#define QSPI_DLL_BSR_DLB2FAIL2_Pos            _UINT32_(10)                                         /* (QSPI_DLL_BSR) Delay Line BIST 2 Fail for Delay Line 2 Position */
#define QSPI_DLL_BSR_DLB2FAIL2_Msk            (_UINT32_(0x1) << QSPI_DLL_BSR_DLB2FAIL2_Pos)        /* (QSPI_DLL_BSR) Delay Line BIST 2 Fail for Delay Line 2 Mask */
#define QSPI_DLL_BSR_DLB2FAIL2(value)         (QSPI_DLL_BSR_DLB2FAIL2_Msk & (_UINT32_(value) << QSPI_DLL_BSR_DLB2FAIL2_Pos)) /* Assigment of value for DLB2FAIL2 in the QSPI_DLL_BSR register */
#define   QSPI_DLL_BSR_DLB2FAIL2_0_Val        _UINT32_(0x0)                                        /* (QSPI_DLL_BSR) The BIST 2 test did not fail.  */
#define   QSPI_DLL_BSR_DLB2FAIL2_1_Val        _UINT32_(0x1)                                        /* (QSPI_DLL_BSR) The BIST 2 test failed for delay line x.  */
#define QSPI_DLL_BSR_DLB2FAIL2_0              (QSPI_DLL_BSR_DLB2FAIL2_0_Val << QSPI_DLL_BSR_DLB2FAIL2_Pos) /* (QSPI_DLL_BSR) The BIST 2 test did not fail. Position  */
#define QSPI_DLL_BSR_DLB2FAIL2_1              (QSPI_DLL_BSR_DLB2FAIL2_1_Val << QSPI_DLL_BSR_DLB2FAIL2_Pos) /* (QSPI_DLL_BSR) The BIST 2 test failed for delay line x. Position  */
#define QSPI_DLL_BSR_DLB2FAIL3_Pos            _UINT32_(11)                                         /* (QSPI_DLL_BSR) Delay Line BIST 2 Fail for Delay Line 3 Position */
#define QSPI_DLL_BSR_DLB2FAIL3_Msk            (_UINT32_(0x1) << QSPI_DLL_BSR_DLB2FAIL3_Pos)        /* (QSPI_DLL_BSR) Delay Line BIST 2 Fail for Delay Line 3 Mask */
#define QSPI_DLL_BSR_DLB2FAIL3(value)         (QSPI_DLL_BSR_DLB2FAIL3_Msk & (_UINT32_(value) << QSPI_DLL_BSR_DLB2FAIL3_Pos)) /* Assigment of value for DLB2FAIL3 in the QSPI_DLL_BSR register */
#define   QSPI_DLL_BSR_DLB2FAIL3_0_Val        _UINT32_(0x0)                                        /* (QSPI_DLL_BSR) The BIST 2 test did not fail.  */
#define   QSPI_DLL_BSR_DLB2FAIL3_1_Val        _UINT32_(0x1)                                        /* (QSPI_DLL_BSR) The BIST 2 test failed for delay line x.  */
#define QSPI_DLL_BSR_DLB2FAIL3_0              (QSPI_DLL_BSR_DLB2FAIL3_0_Val << QSPI_DLL_BSR_DLB2FAIL3_Pos) /* (QSPI_DLL_BSR) The BIST 2 test did not fail. Position  */
#define QSPI_DLL_BSR_DLB2FAIL3_1              (QSPI_DLL_BSR_DLB2FAIL3_1_Val << QSPI_DLL_BSR_DLB2FAIL3_Pos) /* (QSPI_DLL_BSR) The BIST 2 test failed for delay line x. Position  */
#define QSPI_DLL_BSR_Msk                      _UINT32_(0x00000F0F)                                 /* (QSPI_DLL_BSR) Register Mask  */

#define QSPI_DLL_BSR_DLB2FAIL_Pos             _UINT32_(8)                                          /* (QSPI_DLL_BSR Position) Delay Line BIST 2 Fail for Delay Line 3 */
#define QSPI_DLL_BSR_DLB2FAIL_Msk             (_UINT32_(0xF) << QSPI_DLL_BSR_DLB2FAIL_Pos)         /* (QSPI_DLL_BSR Mask) DLB2FAIL */
#define QSPI_DLL_BSR_DLB2FAIL(value)          (QSPI_DLL_BSR_DLB2FAIL_Msk & (_UINT32_(value) << QSPI_DLL_BSR_DLB2FAIL_Pos)) 

/* -------- QSPI_DLL_SYNCR : (QSPI Offset: 0x3E0) (R/W 32) QSPI DLL Synchro Register -------- */
#define QSPI_DLL_SYNCR_RESETVALUE             _UINT32_(0x00)                                       /*  (QSPI_DLL_SYNCR) QSPI DLL Synchro Register  Reset Value */

#define QSPI_DLL_SYNCR_UPDT_Pos               _UINT32_(0)                                          /* (QSPI_DLL_SYNCR) Update configuration Position */
#define QSPI_DLL_SYNCR_UPDT_Msk               (_UINT32_(0x1) << QSPI_DLL_SYNCR_UPDT_Pos)           /* (QSPI_DLL_SYNCR) Update configuration Mask */
#define QSPI_DLL_SYNCR_UPDT(value)            (QSPI_DLL_SYNCR_UPDT_Msk & (_UINT32_(value) << QSPI_DLL_SYNCR_UPDT_Pos)) /* Assigment of value for UPDT in the QSPI_DLL_SYNCR register */
#define   QSPI_DLL_SYNCR_UPDT_0_Val           _UINT32_(0x0)                                        /* (QSPI_DLL_SYNCR) No effect.  */
#define   QSPI_DLL_SYNCR_UPDT_0_Val           _UINT32_(0x0)                                        /* (QSPI_DLL_SYNCR) Configuration is up to date.  */
#define   QSPI_DLL_SYNCR_UPDT_1_Val           _UINT32_(0x1)                                        /* (QSPI_DLL_SYNCR) Initiates the configuration update.  */
#define   QSPI_DLL_SYNCR_UPDT_1_Val           _UINT32_(0x1)                                        /* (QSPI_DLL_SYNCR) Configuration is being updated.  */
#define QSPI_DLL_SYNCR_UPDT_0                 (QSPI_DLL_SYNCR_UPDT_0_Val << QSPI_DLL_SYNCR_UPDT_Pos) /* (QSPI_DLL_SYNCR) No effect. Position  */
#define QSPI_DLL_SYNCR_UPDT_0                 (QSPI_DLL_SYNCR_UPDT_0_Val << QSPI_DLL_SYNCR_UPDT_Pos) /* (QSPI_DLL_SYNCR) Configuration is up to date. Position  */
#define QSPI_DLL_SYNCR_UPDT_1                 (QSPI_DLL_SYNCR_UPDT_1_Val << QSPI_DLL_SYNCR_UPDT_Pos) /* (QSPI_DLL_SYNCR) Initiates the configuration update. Position  */
#define QSPI_DLL_SYNCR_UPDT_1                 (QSPI_DLL_SYNCR_UPDT_1_Val << QSPI_DLL_SYNCR_UPDT_Pos) /* (QSPI_DLL_SYNCR) Configuration is being updated. Position  */
#define QSPI_DLL_SYNCR_Msk                    _UINT32_(0x00000001)                                 /* (QSPI_DLL_SYNCR) Register Mask  */


/* -------- QSPI_DLL_REVISION : (QSPI Offset: 0x3FC) ( R/ 32) QSPI DQSDELAY Revision Register -------- */
#define QSPI_DLL_REVISION_RESETVALUE          _UINT32_(0x00)                                       /*  (QSPI_DLL_REVISION) QSPI DQSDELAY Revision Register  Reset Value */

#define QSPI_DLL_REVISION_VERSION_Pos         _UINT32_(0)                                          /* (QSPI_DLL_REVISION) Hardware Module Version Position */
#define QSPI_DLL_REVISION_VERSION_Msk         (_UINT32_(0xFFF) << QSPI_DLL_REVISION_VERSION_Pos)   /* (QSPI_DLL_REVISION) Hardware Module Version Mask */
#define QSPI_DLL_REVISION_VERSION(value)      (QSPI_DLL_REVISION_VERSION_Msk & (_UINT32_(value) << QSPI_DLL_REVISION_VERSION_Pos)) /* Assigment of value for VERSION in the QSPI_DLL_REVISION register */
#define QSPI_DLL_REVISION_MFN_Pos             _UINT32_(16)                                         /* (QSPI_DLL_REVISION) Metal Fix Number Position */
#define QSPI_DLL_REVISION_MFN_Msk             (_UINT32_(0x7) << QSPI_DLL_REVISION_MFN_Pos)         /* (QSPI_DLL_REVISION) Metal Fix Number Mask */
#define QSPI_DLL_REVISION_MFN(value)          (QSPI_DLL_REVISION_MFN_Msk & (_UINT32_(value) << QSPI_DLL_REVISION_MFN_Pos)) /* Assigment of value for MFN in the QSPI_DLL_REVISION register */
#define QSPI_DLL_REVISION_Msk                 _UINT32_(0x00070FFF)                                 /* (QSPI_DLL_REVISION) Register Mask  */


/** \brief QSPI register offsets definitions */
#define QSPI_CR_REG_OFST               _UINT32_(0x00)      /* (QSPI_CR) Control Register Offset */
#define QSPI_MR_REG_OFST               _UINT32_(0x04)      /* (QSPI_MR) Mode Register Offset */
#define QSPI_RDR_REG_OFST              _UINT32_(0x08)      /* (QSPI_RDR) Receive Data Register Offset */
#define QSPI_TDR_REG_OFST              _UINT32_(0x0C)      /* (QSPI_TDR) Transmit Data Register Offset */
#define QSPI_ISR_REG_OFST              _UINT32_(0x10)      /* (QSPI_ISR) Interrupt Status Register Offset */
#define QSPI_IER_REG_OFST              _UINT32_(0x14)      /* (QSPI_IER) Interrupt Enable Register Offset */
#define QSPI_IDR_REG_OFST              _UINT32_(0x18)      /* (QSPI_IDR) Interrupt Disable Register Offset */
#define QSPI_IMR_REG_OFST              _UINT32_(0x1C)      /* (QSPI_IMR) Interrupt Mask Register Offset */
#define QSPI_SCR_REG_OFST              _UINT32_(0x20)      /* (QSPI_SCR) Serial Clock Register Offset */
#define QSPI_SR_REG_OFST               _UINT32_(0x24)      /* (QSPI_SR) Status Register Offset */
#define QSPI_IAR_REG_OFST              _UINT32_(0x30)      /* (QSPI_IAR) Instruction Address Register Offset */
#define QSPI_WICR_REG_OFST             _UINT32_(0x34)      /* (QSPI_WICR) Write Instruction Code Register Offset */
#define QSPI_IFR_REG_OFST              _UINT32_(0x38)      /* (QSPI_IFR) Instruction Frame Register Offset */
#define QSPI_RICR_REG_OFST             _UINT32_(0x3C)      /* (QSPI_RICR) Read Instruction Code Register Offset */
#define QSPI_SMR_REG_OFST              _UINT32_(0x40)      /* (QSPI_SMR) Scrambling Mode Register Offset */
#define QSPI_SKR_REG_OFST              _UINT32_(0x44)      /* (QSPI_SKR) Scrambling Key Register Offset */
#define QSPI_REFRESH_REG_OFST          _UINT32_(0x50)      /* (QSPI_REFRESH) Refresh Register Offset */
#define QSPI_WRACNT_REG_OFST           _UINT32_(0x54)      /* (QSPI_WRACNT) Write Access Counter Register Offset */
#define QSPI_PCALCFG_REG_OFST          _UINT32_(0x5C)      /* (QSPI_PCALCFG) Pad Calibration Configuration Register Offset */
#define QSPI_TOUT_REG_OFST             _UINT32_(0x64)      /* (QSPI_TOUT) Timeout Register Offset */
#define QSPI_WPMR_REG_OFST             _UINT32_(0xE4)      /* (QSPI_WPMR) Write Protection Mode Register Offset */
#define QSPI_WPSR_REG_OFST             _UINT32_(0xE8)      /* (QSPI_WPSR) Write Protection Status Register Offset */
#define QSPI_DLL_OS_REG_OFST           _UINT32_(0x300)     /* (QSPI_DLL_OS) QSPI DLL Offset Selection Register Offset */
#define QSPI_DLL_MAO_REG_OFST          _UINT32_(0x304)     /* (QSPI_DLL_MAO) QSPI DLL Host Offset Register Offset */
#define QSPI_DLL_SO0_REG_OFST          _UINT32_(0x308)     /* (QSPI_DLL_SO0) QSPI DLL Client Offset 0 Register Offset */
#define QSPI_DLL_SO1_REG_OFST          _UINT32_(0x30C)     /* (QSPI_DLL_SO1) QSPI DLL Client Offset 1 Register Offset */
#define QSPI_DLL_SM0_REG_OFST          _UINT32_(0x318)     /* (QSPI_DLL_SM0) QSPI DLL Status Host 0 Register Offset */
#define QSPI_DLL_SSL_REG_OFST          _UINT32_(0x328)     /* (QSPI_DLL_SSL) QSPI DLL Status Client x Register Offset */
#define QSPI_DLL_SSL0_REG_OFST         _UINT32_(0x328)     /* (QSPI_DLL_SSL0) QSPI DLL Status Client x Register Offset */
#define QSPI_DLL_SSL1_REG_OFST         _UINT32_(0x32C)     /* (QSPI_DLL_SSL1) QSPI DLL Status Client x Register Offset */
#define QSPI_DLL_SSL2_REG_OFST         _UINT32_(0x330)     /* (QSPI_DLL_SSL2) QSPI DLL Status Client x Register Offset */
#define QSPI_DLL_BCR_REG_OFST          _UINT32_(0x3D0)     /* (QSPI_DLL_BCR) QSPI DLL BIST Control Register Offset */
#define QSPI_DLL_BSR_REG_OFST          _UINT32_(0x3D4)     /* (QSPI_DLL_BSR) QSPI DLL BIST Status Register Offset */
#define QSPI_DLL_SYNCR_REG_OFST        _UINT32_(0x3E0)     /* (QSPI_DLL_SYNCR) QSPI DLL Synchro Register Offset */
#define QSPI_DLL_REVISION_REG_OFST     _UINT32_(0x3FC)     /* (QSPI_DLL_REVISION) QSPI DQSDELAY Revision Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief QSPI register API structure */
typedef struct
{  /* Quad Serial Peripheral Interface */
  __O   uint32_t                       QSPI_CR;            /**< Offset: 0x00 ( /W  32) Control Register */
  __IO  uint32_t                       QSPI_MR;            /**< Offset: 0x04 (R/W  32) Mode Register */
  __I   uint32_t                       QSPI_RDR;           /**< Offset: 0x08 (R/   32) Receive Data Register */
  __O   uint32_t                       QSPI_TDR;           /**< Offset: 0x0C ( /W  32) Transmit Data Register */
  __I   uint32_t                       QSPI_ISR;           /**< Offset: 0x10 (R/   32) Interrupt Status Register */
  __O   uint32_t                       QSPI_IER;           /**< Offset: 0x14 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       QSPI_IDR;           /**< Offset: 0x18 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       QSPI_IMR;           /**< Offset: 0x1C (R/   32) Interrupt Mask Register */
  __IO  uint32_t                       QSPI_SCR;           /**< Offset: 0x20 (R/W  32) Serial Clock Register */
  __IO  uint32_t                       QSPI_SR;            /**< Offset: 0x24 (R/W  32) Status Register */
  __I   uint8_t                        Reserved1[0x08];
  __IO  uint32_t                       QSPI_IAR;           /**< Offset: 0x30 (R/W  32) Instruction Address Register */
  __IO  uint32_t                       QSPI_WICR;          /**< Offset: 0x34 (R/W  32) Write Instruction Code Register */
  __IO  uint32_t                       QSPI_IFR;           /**< Offset: 0x38 (R/W  32) Instruction Frame Register */
  __IO  uint32_t                       QSPI_RICR;          /**< Offset: 0x3C (R/W  32) Read Instruction Code Register */
  __IO  uint32_t                       QSPI_SMR;           /**< Offset: 0x40 (R/W  32) Scrambling Mode Register */
  __O   uint32_t                       QSPI_SKR;           /**< Offset: 0x44 ( /W  32) Scrambling Key Register */
  __I   uint8_t                        Reserved2[0x08];
  __IO  uint32_t                       QSPI_REFRESH;       /**< Offset: 0x50 (R/W  32) Refresh Register */
  __IO  uint32_t                       QSPI_WRACNT;        /**< Offset: 0x54 (R/W  32) Write Access Counter Register */
  __I   uint8_t                        Reserved3[0x04];
  __IO  uint32_t                       QSPI_PCALCFG;       /**< Offset: 0x5C (R/W  32) Pad Calibration Configuration Register */
  __I   uint8_t                        Reserved4[0x04];
  __IO  uint32_t                       QSPI_TOUT;          /**< Offset: 0x64 (R/W  32) Timeout Register */
  __I   uint8_t                        Reserved5[0x7C];
  __IO  uint32_t                       QSPI_WPMR;          /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   uint32_t                       QSPI_WPSR;          /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
  __I   uint8_t                        Reserved6[0x214];
  __IO  uint32_t                       QSPI_DLL_OS;        /**< Offset: 0x300 (R/W  32) QSPI DLL Offset Selection Register */
  __IO  uint32_t                       QSPI_DLL_MAO;       /**< Offset: 0x304 (R/W  32) QSPI DLL Host Offset Register */
  __IO  uint32_t                       QSPI_DLL_SO0;       /**< Offset: 0x308 (R/W  32) QSPI DLL Client Offset 0 Register */
  __IO  uint32_t                       QSPI_DLL_SO1;       /**< Offset: 0x30C (R/W  32) QSPI DLL Client Offset 1 Register */
  __I   uint8_t                        Reserved7[0x08];
  __I   uint32_t                       QSPI_DLL_SM0;       /**< Offset: 0x318 (R/   32) QSPI DLL Status Host 0 Register */
  __I   uint8_t                        Reserved8[0x0C];
  __I   uint32_t                       QSPI_DLL_SSL[3];    /**< Offset: 0x328 (R/   32) QSPI DLL Status Client x Register */
  __I   uint8_t                        Reserved9[0x9C];
  __IO  uint32_t                       QSPI_DLL_BCR;       /**< Offset: 0x3D0 (R/W  32) QSPI DLL BIST Control Register */
  __I   uint32_t                       QSPI_DLL_BSR;       /**< Offset: 0x3D4 (R/   32) QSPI DLL BIST Status Register */
  __I   uint8_t                        Reserved10[0x08];
  __IO  uint32_t                       QSPI_DLL_SYNCR;     /**< Offset: 0x3E0 (R/W  32) QSPI DLL Synchro Register */
  __I   uint8_t                        Reserved11[0x18];
  __I   uint32_t                       QSPI_DLL_REVISION;  /**< Offset: 0x3FC (R/   32) QSPI DQSDELAY Revision Register */
} qspi_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X7_QSPI_COMPONENT_H_ */
