/*
 * Component description for DBGU
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
#ifndef _SAM9X7_DBGU_COMPONENT_H_
#define _SAM9X7_DBGU_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR DBGU                                         */
/* ************************************************************************** */

/* -------- DBGU_CR : (DBGU Offset: 0x00) ( /W 32) Control Register -------- */
#define DBGU_CR_RSTRX_Pos                     _UINT32_(2)                                          /* (DBGU_CR) Reset Receiver Position */
#define DBGU_CR_RSTRX_Msk                     (_UINT32_(0x1) << DBGU_CR_RSTRX_Pos)                 /* (DBGU_CR) Reset Receiver Mask */
#define DBGU_CR_RSTRX(value)                  (DBGU_CR_RSTRX_Msk & (_UINT32_(value) << DBGU_CR_RSTRX_Pos)) /* Assigment of value for RSTRX in the DBGU_CR register */
#define   DBGU_CR_RSTRX_0_Val                 _UINT32_(0x0)                                        /* (DBGU_CR) No effect.  */
#define   DBGU_CR_RSTRX_1_Val                 _UINT32_(0x1)                                        /* (DBGU_CR) The receiver logic is reset and disabled. If a character is being received, the reception is aborted.  */
#define DBGU_CR_RSTRX_0                       (DBGU_CR_RSTRX_0_Val << DBGU_CR_RSTRX_Pos)           /* (DBGU_CR) No effect. Position  */
#define DBGU_CR_RSTRX_1                       (DBGU_CR_RSTRX_1_Val << DBGU_CR_RSTRX_Pos)           /* (DBGU_CR) The receiver logic is reset and disabled. If a character is being received, the reception is aborted. Position  */
#define DBGU_CR_RSTTX_Pos                     _UINT32_(3)                                          /* (DBGU_CR) Reset Transmitter Position */
#define DBGU_CR_RSTTX_Msk                     (_UINT32_(0x1) << DBGU_CR_RSTTX_Pos)                 /* (DBGU_CR) Reset Transmitter Mask */
#define DBGU_CR_RSTTX(value)                  (DBGU_CR_RSTTX_Msk & (_UINT32_(value) << DBGU_CR_RSTTX_Pos)) /* Assigment of value for RSTTX in the DBGU_CR register */
#define   DBGU_CR_RSTTX_0_Val                 _UINT32_(0x0)                                        /* (DBGU_CR) No effect.  */
#define   DBGU_CR_RSTTX_1_Val                 _UINT32_(0x1)                                        /* (DBGU_CR) The transmitter logic is reset and disabled. If a character is being transmitted, the transmission is aborted.  */
#define DBGU_CR_RSTTX_0                       (DBGU_CR_RSTTX_0_Val << DBGU_CR_RSTTX_Pos)           /* (DBGU_CR) No effect. Position  */
#define DBGU_CR_RSTTX_1                       (DBGU_CR_RSTTX_1_Val << DBGU_CR_RSTTX_Pos)           /* (DBGU_CR) The transmitter logic is reset and disabled. If a character is being transmitted, the transmission is aborted. Position  */
#define DBGU_CR_RXEN_Pos                      _UINT32_(4)                                          /* (DBGU_CR) Receiver Enable Position */
#define DBGU_CR_RXEN_Msk                      (_UINT32_(0x1) << DBGU_CR_RXEN_Pos)                  /* (DBGU_CR) Receiver Enable Mask */
#define DBGU_CR_RXEN(value)                   (DBGU_CR_RXEN_Msk & (_UINT32_(value) << DBGU_CR_RXEN_Pos)) /* Assigment of value for RXEN in the DBGU_CR register */
#define   DBGU_CR_RXEN_0_Val                  _UINT32_(0x0)                                        /* (DBGU_CR) No effect.  */
#define   DBGU_CR_RXEN_1_Val                  _UINT32_(0x1)                                        /* (DBGU_CR) The receiver is enabled if RXDIS is 0.  */
#define DBGU_CR_RXEN_0                        (DBGU_CR_RXEN_0_Val << DBGU_CR_RXEN_Pos)             /* (DBGU_CR) No effect. Position  */
#define DBGU_CR_RXEN_1                        (DBGU_CR_RXEN_1_Val << DBGU_CR_RXEN_Pos)             /* (DBGU_CR) The receiver is enabled if RXDIS is 0. Position  */
#define DBGU_CR_RXDIS_Pos                     _UINT32_(5)                                          /* (DBGU_CR) Receiver Disable Position */
#define DBGU_CR_RXDIS_Msk                     (_UINT32_(0x1) << DBGU_CR_RXDIS_Pos)                 /* (DBGU_CR) Receiver Disable Mask */
#define DBGU_CR_RXDIS(value)                  (DBGU_CR_RXDIS_Msk & (_UINT32_(value) << DBGU_CR_RXDIS_Pos)) /* Assigment of value for RXDIS in the DBGU_CR register */
#define   DBGU_CR_RXDIS_0_Val                 _UINT32_(0x0)                                        /* (DBGU_CR) No effect.  */
#define   DBGU_CR_RXDIS_1_Val                 _UINT32_(0x1)                                        /* (DBGU_CR) The receiver is disabled. If a character is being processed and RSTRX is not set, the character is completed before the receiver is stopped.  */
#define DBGU_CR_RXDIS_0                       (DBGU_CR_RXDIS_0_Val << DBGU_CR_RXDIS_Pos)           /* (DBGU_CR) No effect. Position  */
#define DBGU_CR_RXDIS_1                       (DBGU_CR_RXDIS_1_Val << DBGU_CR_RXDIS_Pos)           /* (DBGU_CR) The receiver is disabled. If a character is being processed and RSTRX is not set, the character is completed before the receiver is stopped. Position  */
#define DBGU_CR_TXEN_Pos                      _UINT32_(6)                                          /* (DBGU_CR) Transmitter Enable Position */
#define DBGU_CR_TXEN_Msk                      (_UINT32_(0x1) << DBGU_CR_TXEN_Pos)                  /* (DBGU_CR) Transmitter Enable Mask */
#define DBGU_CR_TXEN(value)                   (DBGU_CR_TXEN_Msk & (_UINT32_(value) << DBGU_CR_TXEN_Pos)) /* Assigment of value for TXEN in the DBGU_CR register */
#define   DBGU_CR_TXEN_0_Val                  _UINT32_(0x0)                                        /* (DBGU_CR) No effect.  */
#define   DBGU_CR_TXEN_1_Val                  _UINT32_(0x1)                                        /* (DBGU_CR) The transmitter is enabled if TXDIS is 0.  */
#define DBGU_CR_TXEN_0                        (DBGU_CR_TXEN_0_Val << DBGU_CR_TXEN_Pos)             /* (DBGU_CR) No effect. Position  */
#define DBGU_CR_TXEN_1                        (DBGU_CR_TXEN_1_Val << DBGU_CR_TXEN_Pos)             /* (DBGU_CR) The transmitter is enabled if TXDIS is 0. Position  */
#define DBGU_CR_TXDIS_Pos                     _UINT32_(7)                                          /* (DBGU_CR) Transmitter Disable Position */
#define DBGU_CR_TXDIS_Msk                     (_UINT32_(0x1) << DBGU_CR_TXDIS_Pos)                 /* (DBGU_CR) Transmitter Disable Mask */
#define DBGU_CR_TXDIS(value)                  (DBGU_CR_TXDIS_Msk & (_UINT32_(value) << DBGU_CR_TXDIS_Pos)) /* Assigment of value for TXDIS in the DBGU_CR register */
#define   DBGU_CR_TXDIS_0_Val                 _UINT32_(0x0)                                        /* (DBGU_CR) No effect.  */
#define   DBGU_CR_TXDIS_1_Val                 _UINT32_(0x1)                                        /* (DBGU_CR) The transmitter is disabled. If a character is being processed and a character has been written in DBGU_THR and RSTTX is not set, both characters are completed before the transmitter is stopped.  */
#define DBGU_CR_TXDIS_0                       (DBGU_CR_TXDIS_0_Val << DBGU_CR_TXDIS_Pos)           /* (DBGU_CR) No effect. Position  */
#define DBGU_CR_TXDIS_1                       (DBGU_CR_TXDIS_1_Val << DBGU_CR_TXDIS_Pos)           /* (DBGU_CR) The transmitter is disabled. If a character is being processed and a character has been written in DBGU_THR and RSTTX is not set, both characters are completed before the transmitter is stopped. Position  */
#define DBGU_CR_RSTSTA_Pos                    _UINT32_(8)                                          /* (DBGU_CR) Reset Status Position */
#define DBGU_CR_RSTSTA_Msk                    (_UINT32_(0x1) << DBGU_CR_RSTSTA_Pos)                /* (DBGU_CR) Reset Status Mask */
#define DBGU_CR_RSTSTA(value)                 (DBGU_CR_RSTSTA_Msk & (_UINT32_(value) << DBGU_CR_RSTSTA_Pos)) /* Assigment of value for RSTSTA in the DBGU_CR register */
#define   DBGU_CR_RSTSTA_0_Val                _UINT32_(0x0)                                        /* (DBGU_CR) No effect.  */
#define   DBGU_CR_RSTSTA_1_Val                _UINT32_(0x1)                                        /* (DBGU_CR) Resets the status bits PARE, FRAME and OVRE in DBGU_SR.  */
#define DBGU_CR_RSTSTA_0                      (DBGU_CR_RSTSTA_0_Val << DBGU_CR_RSTSTA_Pos)         /* (DBGU_CR) No effect. Position  */
#define DBGU_CR_RSTSTA_1                      (DBGU_CR_RSTSTA_1_Val << DBGU_CR_RSTSTA_Pos)         /* (DBGU_CR) Resets the status bits PARE, FRAME and OVRE in DBGU_SR. Position  */
#define DBGU_CR_RETTO_Pos                     _UINT32_(10)                                         /* (DBGU_CR) Rearm Timeout Position */
#define DBGU_CR_RETTO_Msk                     (_UINT32_(0x1) << DBGU_CR_RETTO_Pos)                 /* (DBGU_CR) Rearm Timeout Mask */
#define DBGU_CR_RETTO(value)                  (DBGU_CR_RETTO_Msk & (_UINT32_(value) << DBGU_CR_RETTO_Pos)) /* Assigment of value for RETTO in the DBGU_CR register */
#define   DBGU_CR_RETTO_0_Val                 _UINT32_(0x0)                                        /* (DBGU_CR) No effect.  */
#define   DBGU_CR_RETTO_1_Val                 _UINT32_(0x1)                                        /* (DBGU_CR) Restarts timeout.  */
#define DBGU_CR_RETTO_0                       (DBGU_CR_RETTO_0_Val << DBGU_CR_RETTO_Pos)           /* (DBGU_CR) No effect. Position  */
#define DBGU_CR_RETTO_1                       (DBGU_CR_RETTO_1_Val << DBGU_CR_RETTO_Pos)           /* (DBGU_CR) Restarts timeout. Position  */
#define DBGU_CR_STTTO_Pos                     _UINT32_(11)                                         /* (DBGU_CR) Start Timeout Position */
#define DBGU_CR_STTTO_Msk                     (_UINT32_(0x1) << DBGU_CR_STTTO_Pos)                 /* (DBGU_CR) Start Timeout Mask */
#define DBGU_CR_STTTO(value)                  (DBGU_CR_STTTO_Msk & (_UINT32_(value) << DBGU_CR_STTTO_Pos)) /* Assigment of value for STTTO in the DBGU_CR register */
#define   DBGU_CR_STTTO_0_Val                 _UINT32_(0x0)                                        /* (DBGU_CR) No effect.  */
#define   DBGU_CR_STTTO_1_Val                 _UINT32_(0x1)                                        /* (DBGU_CR) Starts waiting for a character before clocking the timeout counter. Resets status bit DBGU_SR.TIMEOUT.  */
#define DBGU_CR_STTTO_0                       (DBGU_CR_STTTO_0_Val << DBGU_CR_STTTO_Pos)           /* (DBGU_CR) No effect. Position  */
#define DBGU_CR_STTTO_1                       (DBGU_CR_STTTO_1_Val << DBGU_CR_STTTO_Pos)           /* (DBGU_CR) Starts waiting for a character before clocking the timeout counter. Resets status bit DBGU_SR.TIMEOUT. Position  */
#define DBGU_CR_Msk                           _UINT32_(0x00000DFC)                                 /* (DBGU_CR) Register Mask  */


/* -------- DBGU_MR : (DBGU Offset: 0x04) (R/W 32) Mode Register -------- */
#define DBGU_MR_RESETVALUE                    _UINT32_(0x00)                                       /*  (DBGU_MR) Mode Register  Reset Value */

#define DBGU_MR_FILTER_Pos                    _UINT32_(4)                                          /* (DBGU_MR) Receiver Digital Filter Position */
#define DBGU_MR_FILTER_Msk                    (_UINT32_(0x1) << DBGU_MR_FILTER_Pos)                /* (DBGU_MR) Receiver Digital Filter Mask */
#define DBGU_MR_FILTER(value)                 (DBGU_MR_FILTER_Msk & (_UINT32_(value) << DBGU_MR_FILTER_Pos)) /* Assigment of value for FILTER in the DBGU_MR register */
#define   DBGU_MR_FILTER_DISABLED_Val         _UINT32_(0x0)                                        /* (DBGU_MR) DBGU does not filter the receive line.  */
#define   DBGU_MR_FILTER_ENABLED_Val          _UINT32_(0x1)                                        /* (DBGU_MR) DBGU filters the receive line using a three-sample filter (16x-bit clock) (2 over 3 majority).  */
#define DBGU_MR_FILTER_DISABLED               (DBGU_MR_FILTER_DISABLED_Val << DBGU_MR_FILTER_Pos)  /* (DBGU_MR) DBGU does not filter the receive line. Position  */
#define DBGU_MR_FILTER_ENABLED                (DBGU_MR_FILTER_ENABLED_Val << DBGU_MR_FILTER_Pos)   /* (DBGU_MR) DBGU filters the receive line using a three-sample filter (16x-bit clock) (2 over 3 majority). Position  */
#define DBGU_MR_PAR_Pos                       _UINT32_(9)                                          /* (DBGU_MR) Parity Type Position */
#define DBGU_MR_PAR_Msk                       (_UINT32_(0x7) << DBGU_MR_PAR_Pos)                   /* (DBGU_MR) Parity Type Mask */
#define DBGU_MR_PAR(value)                    (DBGU_MR_PAR_Msk & (_UINT32_(value) << DBGU_MR_PAR_Pos)) /* Assigment of value for PAR in the DBGU_MR register */
#define   DBGU_MR_PAR_EVEN_Val                _UINT32_(0x0)                                        /* (DBGU_MR) Even Parity  */
#define   DBGU_MR_PAR_ODD_Val                 _UINT32_(0x1)                                        /* (DBGU_MR) Odd Parity  */
#define   DBGU_MR_PAR_SPACE_Val               _UINT32_(0x2)                                        /* (DBGU_MR) Space: parity forced to 0  */
#define   DBGU_MR_PAR_MARK_Val                _UINT32_(0x3)                                        /* (DBGU_MR) Mark: parity forced to 1  */
#define   DBGU_MR_PAR_NO_Val                  _UINT32_(0x4)                                        /* (DBGU_MR) No parity  */
#define DBGU_MR_PAR_EVEN                      (DBGU_MR_PAR_EVEN_Val << DBGU_MR_PAR_Pos)            /* (DBGU_MR) Even Parity Position  */
#define DBGU_MR_PAR_ODD                       (DBGU_MR_PAR_ODD_Val << DBGU_MR_PAR_Pos)             /* (DBGU_MR) Odd Parity Position  */
#define DBGU_MR_PAR_SPACE                     (DBGU_MR_PAR_SPACE_Val << DBGU_MR_PAR_Pos)           /* (DBGU_MR) Space: parity forced to 0 Position  */
#define DBGU_MR_PAR_MARK                      (DBGU_MR_PAR_MARK_Val << DBGU_MR_PAR_Pos)            /* (DBGU_MR) Mark: parity forced to 1 Position  */
#define DBGU_MR_PAR_NO                        (DBGU_MR_PAR_NO_Val << DBGU_MR_PAR_Pos)              /* (DBGU_MR) No parity Position  */
#define DBGU_MR_BRSRCCK_Pos                   _UINT32_(12)                                         /* (DBGU_MR) Baud Rate Source Clock Position */
#define DBGU_MR_BRSRCCK_Msk                   (_UINT32_(0x1) << DBGU_MR_BRSRCCK_Pos)               /* (DBGU_MR) Baud Rate Source Clock Mask */
#define DBGU_MR_BRSRCCK(value)                (DBGU_MR_BRSRCCK_Msk & (_UINT32_(value) << DBGU_MR_BRSRCCK_Pos)) /* Assigment of value for BRSRCCK in the DBGU_MR register */
#define   DBGU_MR_BRSRCCK_PERIPH_CLK_Val      _UINT32_(0x0)                                        /* (DBGU_MR) The baud rate is driven by the peripheral clock  */
#define   DBGU_MR_BRSRCCK_GCLK_Val            _UINT32_(0x1)                                        /* (DBGU_MR) The baud rate is driven by a PMC-programmable clock GCLK (see section Power Management Controller (PMC)).  */
#define DBGU_MR_BRSRCCK_PERIPH_CLK            (DBGU_MR_BRSRCCK_PERIPH_CLK_Val << DBGU_MR_BRSRCCK_Pos) /* (DBGU_MR) The baud rate is driven by the peripheral clock Position  */
#define DBGU_MR_BRSRCCK_GCLK                  (DBGU_MR_BRSRCCK_GCLK_Val << DBGU_MR_BRSRCCK_Pos)    /* (DBGU_MR) The baud rate is driven by a PMC-programmable clock GCLK (see section Power Management Controller (PMC)). Position  */
#define DBGU_MR_CHMODE_Pos                    _UINT32_(14)                                         /* (DBGU_MR) Channel Mode Position */
#define DBGU_MR_CHMODE_Msk                    (_UINT32_(0x3) << DBGU_MR_CHMODE_Pos)                /* (DBGU_MR) Channel Mode Mask */
#define DBGU_MR_CHMODE(value)                 (DBGU_MR_CHMODE_Msk & (_UINT32_(value) << DBGU_MR_CHMODE_Pos)) /* Assigment of value for CHMODE in the DBGU_MR register */
#define   DBGU_MR_CHMODE_NORMAL_Val           _UINT32_(0x0)                                        /* (DBGU_MR) Normal mode  */
#define   DBGU_MR_CHMODE_AUTOMATIC_Val        _UINT32_(0x1)                                        /* (DBGU_MR) Automatic echo  */
#define   DBGU_MR_CHMODE_LOCAL_LOOPBACK_Val   _UINT32_(0x2)                                        /* (DBGU_MR) Local loopback  */
#define   DBGU_MR_CHMODE_REMOTE_LOOPBACK_Val  _UINT32_(0x3)                                        /* (DBGU_MR) Remote loopback  */
#define DBGU_MR_CHMODE_NORMAL                 (DBGU_MR_CHMODE_NORMAL_Val << DBGU_MR_CHMODE_Pos)    /* (DBGU_MR) Normal mode Position  */
#define DBGU_MR_CHMODE_AUTOMATIC              (DBGU_MR_CHMODE_AUTOMATIC_Val << DBGU_MR_CHMODE_Pos) /* (DBGU_MR) Automatic echo Position  */
#define DBGU_MR_CHMODE_LOCAL_LOOPBACK         (DBGU_MR_CHMODE_LOCAL_LOOPBACK_Val << DBGU_MR_CHMODE_Pos) /* (DBGU_MR) Local loopback Position  */
#define DBGU_MR_CHMODE_REMOTE_LOOPBACK        (DBGU_MR_CHMODE_REMOTE_LOOPBACK_Val << DBGU_MR_CHMODE_Pos) /* (DBGU_MR) Remote loopback Position  */
#define DBGU_MR_Msk                           _UINT32_(0x0000DE10)                                 /* (DBGU_MR) Register Mask  */


/* -------- DBGU_IER : (DBGU Offset: 0x08) ( /W 32) Interrupt Enable Register -------- */
#define DBGU_IER_RXRDY_Pos                    _UINT32_(0)                                          /* (DBGU_IER) Enable RXRDY Interrupt Position */
#define DBGU_IER_RXRDY_Msk                    (_UINT32_(0x1) << DBGU_IER_RXRDY_Pos)                /* (DBGU_IER) Enable RXRDY Interrupt Mask */
#define DBGU_IER_RXRDY(value)                 (DBGU_IER_RXRDY_Msk & (_UINT32_(value) << DBGU_IER_RXRDY_Pos)) /* Assigment of value for RXRDY in the DBGU_IER register */
#define DBGU_IER_TXRDY_Pos                    _UINT32_(1)                                          /* (DBGU_IER) Enable TXRDY Interrupt Position */
#define DBGU_IER_TXRDY_Msk                    (_UINT32_(0x1) << DBGU_IER_TXRDY_Pos)                /* (DBGU_IER) Enable TXRDY Interrupt Mask */
#define DBGU_IER_TXRDY(value)                 (DBGU_IER_TXRDY_Msk & (_UINT32_(value) << DBGU_IER_TXRDY_Pos)) /* Assigment of value for TXRDY in the DBGU_IER register */
#define DBGU_IER_OVRE_Pos                     _UINT32_(5)                                          /* (DBGU_IER) Enable Overrun Error Interrupt Position */
#define DBGU_IER_OVRE_Msk                     (_UINT32_(0x1) << DBGU_IER_OVRE_Pos)                 /* (DBGU_IER) Enable Overrun Error Interrupt Mask */
#define DBGU_IER_OVRE(value)                  (DBGU_IER_OVRE_Msk & (_UINT32_(value) << DBGU_IER_OVRE_Pos)) /* Assigment of value for OVRE in the DBGU_IER register */
#define DBGU_IER_FRAME_Pos                    _UINT32_(6)                                          /* (DBGU_IER) Enable Framing Error Interrupt Position */
#define DBGU_IER_FRAME_Msk                    (_UINT32_(0x1) << DBGU_IER_FRAME_Pos)                /* (DBGU_IER) Enable Framing Error Interrupt Mask */
#define DBGU_IER_FRAME(value)                 (DBGU_IER_FRAME_Msk & (_UINT32_(value) << DBGU_IER_FRAME_Pos)) /* Assigment of value for FRAME in the DBGU_IER register */
#define DBGU_IER_PARE_Pos                     _UINT32_(7)                                          /* (DBGU_IER) Enable Parity Error Interrupt Position */
#define DBGU_IER_PARE_Msk                     (_UINT32_(0x1) << DBGU_IER_PARE_Pos)                 /* (DBGU_IER) Enable Parity Error Interrupt Mask */
#define DBGU_IER_PARE(value)                  (DBGU_IER_PARE_Msk & (_UINT32_(value) << DBGU_IER_PARE_Pos)) /* Assigment of value for PARE in the DBGU_IER register */
#define DBGU_IER_TIMEOUT_Pos                  _UINT32_(8)                                          /* (DBGU_IER) Enable Timeout Interrupt Position */
#define DBGU_IER_TIMEOUT_Msk                  (_UINT32_(0x1) << DBGU_IER_TIMEOUT_Pos)              /* (DBGU_IER) Enable Timeout Interrupt Mask */
#define DBGU_IER_TIMEOUT(value)               (DBGU_IER_TIMEOUT_Msk & (_UINT32_(value) << DBGU_IER_TIMEOUT_Pos)) /* Assigment of value for TIMEOUT in the DBGU_IER register */
#define DBGU_IER_TXEMPTY_Pos                  _UINT32_(9)                                          /* (DBGU_IER) Enable TXEMPTY Interrupt Position */
#define DBGU_IER_TXEMPTY_Msk                  (_UINT32_(0x1) << DBGU_IER_TXEMPTY_Pos)              /* (DBGU_IER) Enable TXEMPTY Interrupt Mask */
#define DBGU_IER_TXEMPTY(value)               (DBGU_IER_TXEMPTY_Msk & (_UINT32_(value) << DBGU_IER_TXEMPTY_Pos)) /* Assigment of value for TXEMPTY in the DBGU_IER register */
#define DBGU_IER_COMMTX_Pos                   _UINT32_(30)                                         /* (DBGU_IER) Enable COMMTX (from ARM) Interrupt Position */
#define DBGU_IER_COMMTX_Msk                   (_UINT32_(0x1) << DBGU_IER_COMMTX_Pos)               /* (DBGU_IER) Enable COMMTX (from ARM) Interrupt Mask */
#define DBGU_IER_COMMTX(value)                (DBGU_IER_COMMTX_Msk & (_UINT32_(value) << DBGU_IER_COMMTX_Pos)) /* Assigment of value for COMMTX in the DBGU_IER register */
#define DBGU_IER_COMMRX_Pos                   _UINT32_(31)                                         /* (DBGU_IER) Enable COMMRX (from ARM) Interrupt Position */
#define DBGU_IER_COMMRX_Msk                   (_UINT32_(0x1) << DBGU_IER_COMMRX_Pos)               /* (DBGU_IER) Enable COMMRX (from ARM) Interrupt Mask */
#define DBGU_IER_COMMRX(value)                (DBGU_IER_COMMRX_Msk & (_UINT32_(value) << DBGU_IER_COMMRX_Pos)) /* Assigment of value for COMMRX in the DBGU_IER register */
#define DBGU_IER_Msk                          _UINT32_(0xC00003E3)                                 /* (DBGU_IER) Register Mask  */


/* -------- DBGU_IDR : (DBGU Offset: 0x0C) ( /W 32) Interrupt Disable Register -------- */
#define DBGU_IDR_RXRDY_Pos                    _UINT32_(0)                                          /* (DBGU_IDR) Disable RXRDY Interrupt Position */
#define DBGU_IDR_RXRDY_Msk                    (_UINT32_(0x1) << DBGU_IDR_RXRDY_Pos)                /* (DBGU_IDR) Disable RXRDY Interrupt Mask */
#define DBGU_IDR_RXRDY(value)                 (DBGU_IDR_RXRDY_Msk & (_UINT32_(value) << DBGU_IDR_RXRDY_Pos)) /* Assigment of value for RXRDY in the DBGU_IDR register */
#define DBGU_IDR_TXRDY_Pos                    _UINT32_(1)                                          /* (DBGU_IDR) Disable TXRDY Interrupt Position */
#define DBGU_IDR_TXRDY_Msk                    (_UINT32_(0x1) << DBGU_IDR_TXRDY_Pos)                /* (DBGU_IDR) Disable TXRDY Interrupt Mask */
#define DBGU_IDR_TXRDY(value)                 (DBGU_IDR_TXRDY_Msk & (_UINT32_(value) << DBGU_IDR_TXRDY_Pos)) /* Assigment of value for TXRDY in the DBGU_IDR register */
#define DBGU_IDR_OVRE_Pos                     _UINT32_(5)                                          /* (DBGU_IDR) Disable Overrun Error Interrupt Position */
#define DBGU_IDR_OVRE_Msk                     (_UINT32_(0x1) << DBGU_IDR_OVRE_Pos)                 /* (DBGU_IDR) Disable Overrun Error Interrupt Mask */
#define DBGU_IDR_OVRE(value)                  (DBGU_IDR_OVRE_Msk & (_UINT32_(value) << DBGU_IDR_OVRE_Pos)) /* Assigment of value for OVRE in the DBGU_IDR register */
#define DBGU_IDR_FRAME_Pos                    _UINT32_(6)                                          /* (DBGU_IDR) Disable Framing Error Interrupt Position */
#define DBGU_IDR_FRAME_Msk                    (_UINT32_(0x1) << DBGU_IDR_FRAME_Pos)                /* (DBGU_IDR) Disable Framing Error Interrupt Mask */
#define DBGU_IDR_FRAME(value)                 (DBGU_IDR_FRAME_Msk & (_UINT32_(value) << DBGU_IDR_FRAME_Pos)) /* Assigment of value for FRAME in the DBGU_IDR register */
#define DBGU_IDR_PARE_Pos                     _UINT32_(7)                                          /* (DBGU_IDR) Disable Parity Error Interrupt Position */
#define DBGU_IDR_PARE_Msk                     (_UINT32_(0x1) << DBGU_IDR_PARE_Pos)                 /* (DBGU_IDR) Disable Parity Error Interrupt Mask */
#define DBGU_IDR_PARE(value)                  (DBGU_IDR_PARE_Msk & (_UINT32_(value) << DBGU_IDR_PARE_Pos)) /* Assigment of value for PARE in the DBGU_IDR register */
#define DBGU_IDR_TIMEOUT_Pos                  _UINT32_(8)                                          /* (DBGU_IDR) Disable Timeout Interrupt Position */
#define DBGU_IDR_TIMEOUT_Msk                  (_UINT32_(0x1) << DBGU_IDR_TIMEOUT_Pos)              /* (DBGU_IDR) Disable Timeout Interrupt Mask */
#define DBGU_IDR_TIMEOUT(value)               (DBGU_IDR_TIMEOUT_Msk & (_UINT32_(value) << DBGU_IDR_TIMEOUT_Pos)) /* Assigment of value for TIMEOUT in the DBGU_IDR register */
#define DBGU_IDR_TXEMPTY_Pos                  _UINT32_(9)                                          /* (DBGU_IDR) Disable TXEMPTY Interrupt Position */
#define DBGU_IDR_TXEMPTY_Msk                  (_UINT32_(0x1) << DBGU_IDR_TXEMPTY_Pos)              /* (DBGU_IDR) Disable TXEMPTY Interrupt Mask */
#define DBGU_IDR_TXEMPTY(value)               (DBGU_IDR_TXEMPTY_Msk & (_UINT32_(value) << DBGU_IDR_TXEMPTY_Pos)) /* Assigment of value for TXEMPTY in the DBGU_IDR register */
#define DBGU_IDR_COMMTX_Pos                   _UINT32_(30)                                         /* (DBGU_IDR) Disable COMMTX (from ARM) Interrupt Position */
#define DBGU_IDR_COMMTX_Msk                   (_UINT32_(0x1) << DBGU_IDR_COMMTX_Pos)               /* (DBGU_IDR) Disable COMMTX (from ARM) Interrupt Mask */
#define DBGU_IDR_COMMTX(value)                (DBGU_IDR_COMMTX_Msk & (_UINT32_(value) << DBGU_IDR_COMMTX_Pos)) /* Assigment of value for COMMTX in the DBGU_IDR register */
#define DBGU_IDR_COMMRX_Pos                   _UINT32_(31)                                         /* (DBGU_IDR) Disable COMMRX (from ARM) Interrupt Position */
#define DBGU_IDR_COMMRX_Msk                   (_UINT32_(0x1) << DBGU_IDR_COMMRX_Pos)               /* (DBGU_IDR) Disable COMMRX (from ARM) Interrupt Mask */
#define DBGU_IDR_COMMRX(value)                (DBGU_IDR_COMMRX_Msk & (_UINT32_(value) << DBGU_IDR_COMMRX_Pos)) /* Assigment of value for COMMRX in the DBGU_IDR register */
#define DBGU_IDR_Msk                          _UINT32_(0xC00003E3)                                 /* (DBGU_IDR) Register Mask  */


/* -------- DBGU_IMR : (DBGU Offset: 0x10) ( R/ 32) Interrupt Mask Register -------- */
#define DBGU_IMR_RESETVALUE                   _UINT32_(0x00)                                       /*  (DBGU_IMR) Interrupt Mask Register  Reset Value */

#define DBGU_IMR_RXRDY_Pos                    _UINT32_(0)                                          /* (DBGU_IMR) Mask RXRDY Interrupt Position */
#define DBGU_IMR_RXRDY_Msk                    (_UINT32_(0x1) << DBGU_IMR_RXRDY_Pos)                /* (DBGU_IMR) Mask RXRDY Interrupt Mask */
#define DBGU_IMR_RXRDY(value)                 (DBGU_IMR_RXRDY_Msk & (_UINT32_(value) << DBGU_IMR_RXRDY_Pos)) /* Assigment of value for RXRDY in the DBGU_IMR register */
#define DBGU_IMR_TXRDY_Pos                    _UINT32_(1)                                          /* (DBGU_IMR) Disable TXRDY Interrupt Position */
#define DBGU_IMR_TXRDY_Msk                    (_UINT32_(0x1) << DBGU_IMR_TXRDY_Pos)                /* (DBGU_IMR) Disable TXRDY Interrupt Mask */
#define DBGU_IMR_TXRDY(value)                 (DBGU_IMR_TXRDY_Msk & (_UINT32_(value) << DBGU_IMR_TXRDY_Pos)) /* Assigment of value for TXRDY in the DBGU_IMR register */
#define DBGU_IMR_OVRE_Pos                     _UINT32_(5)                                          /* (DBGU_IMR) Mask Overrun Error Interrupt Position */
#define DBGU_IMR_OVRE_Msk                     (_UINT32_(0x1) << DBGU_IMR_OVRE_Pos)                 /* (DBGU_IMR) Mask Overrun Error Interrupt Mask */
#define DBGU_IMR_OVRE(value)                  (DBGU_IMR_OVRE_Msk & (_UINT32_(value) << DBGU_IMR_OVRE_Pos)) /* Assigment of value for OVRE in the DBGU_IMR register */
#define DBGU_IMR_FRAME_Pos                    _UINT32_(6)                                          /* (DBGU_IMR) Mask Framing Error Interrupt Position */
#define DBGU_IMR_FRAME_Msk                    (_UINT32_(0x1) << DBGU_IMR_FRAME_Pos)                /* (DBGU_IMR) Mask Framing Error Interrupt Mask */
#define DBGU_IMR_FRAME(value)                 (DBGU_IMR_FRAME_Msk & (_UINT32_(value) << DBGU_IMR_FRAME_Pos)) /* Assigment of value for FRAME in the DBGU_IMR register */
#define DBGU_IMR_PARE_Pos                     _UINT32_(7)                                          /* (DBGU_IMR) Mask Parity Error Interrupt Position */
#define DBGU_IMR_PARE_Msk                     (_UINT32_(0x1) << DBGU_IMR_PARE_Pos)                 /* (DBGU_IMR) Mask Parity Error Interrupt Mask */
#define DBGU_IMR_PARE(value)                  (DBGU_IMR_PARE_Msk & (_UINT32_(value) << DBGU_IMR_PARE_Pos)) /* Assigment of value for PARE in the DBGU_IMR register */
#define DBGU_IMR_TIMEOUT_Pos                  _UINT32_(8)                                          /* (DBGU_IMR) Mask Timeout Interrupt Position */
#define DBGU_IMR_TIMEOUT_Msk                  (_UINT32_(0x1) << DBGU_IMR_TIMEOUT_Pos)              /* (DBGU_IMR) Mask Timeout Interrupt Mask */
#define DBGU_IMR_TIMEOUT(value)               (DBGU_IMR_TIMEOUT_Msk & (_UINT32_(value) << DBGU_IMR_TIMEOUT_Pos)) /* Assigment of value for TIMEOUT in the DBGU_IMR register */
#define DBGU_IMR_TXEMPTY_Pos                  _UINT32_(9)                                          /* (DBGU_IMR) Mask TXEMPTY Interrupt Position */
#define DBGU_IMR_TXEMPTY_Msk                  (_UINT32_(0x1) << DBGU_IMR_TXEMPTY_Pos)              /* (DBGU_IMR) Mask TXEMPTY Interrupt Mask */
#define DBGU_IMR_TXEMPTY(value)               (DBGU_IMR_TXEMPTY_Msk & (_UINT32_(value) << DBGU_IMR_TXEMPTY_Pos)) /* Assigment of value for TXEMPTY in the DBGU_IMR register */
#define DBGU_IMR_COMMTX_Pos                   _UINT32_(30)                                         /* (DBGU_IMR) Mask COMMTX (from ARM) Interrupt Position */
#define DBGU_IMR_COMMTX_Msk                   (_UINT32_(0x1) << DBGU_IMR_COMMTX_Pos)               /* (DBGU_IMR) Mask COMMTX (from ARM) Interrupt Mask */
#define DBGU_IMR_COMMTX(value)                (DBGU_IMR_COMMTX_Msk & (_UINT32_(value) << DBGU_IMR_COMMTX_Pos)) /* Assigment of value for COMMTX in the DBGU_IMR register */
#define DBGU_IMR_COMMRX_Pos                   _UINT32_(31)                                         /* (DBGU_IMR) Mask COMMRX (from ARM) Interrupt Position */
#define DBGU_IMR_COMMRX_Msk                   (_UINT32_(0x1) << DBGU_IMR_COMMRX_Pos)               /* (DBGU_IMR) Mask COMMRX (from ARM) Interrupt Mask */
#define DBGU_IMR_COMMRX(value)                (DBGU_IMR_COMMRX_Msk & (_UINT32_(value) << DBGU_IMR_COMMRX_Pos)) /* Assigment of value for COMMRX in the DBGU_IMR register */
#define DBGU_IMR_Msk                          _UINT32_(0xC00003E3)                                 /* (DBGU_IMR) Register Mask  */


/* -------- DBGU_SR : (DBGU Offset: 0x14) ( R/ 32) Status Register -------- */
#define DBGU_SR_RXRDY_Pos                     _UINT32_(0)                                          /* (DBGU_SR) Receiver Ready Position */
#define DBGU_SR_RXRDY_Msk                     (_UINT32_(0x1) << DBGU_SR_RXRDY_Pos)                 /* (DBGU_SR) Receiver Ready Mask */
#define DBGU_SR_RXRDY(value)                  (DBGU_SR_RXRDY_Msk & (_UINT32_(value) << DBGU_SR_RXRDY_Pos)) /* Assigment of value for RXRDY in the DBGU_SR register */
#define   DBGU_SR_RXRDY_0_Val                 _UINT32_(0x0)                                        /* (DBGU_SR) No character has been received since the last read of DBGU_RHR, or the receiver is disabled.  */
#define   DBGU_SR_RXRDY_1_Val                 _UINT32_(0x1)                                        /* (DBGU_SR) At least one complete character has been received, transferred to DBGU_RHR, and not yet read.  */
#define DBGU_SR_RXRDY_0                       (DBGU_SR_RXRDY_0_Val << DBGU_SR_RXRDY_Pos)           /* (DBGU_SR) No character has been received since the last read of DBGU_RHR, or the receiver is disabled. Position  */
#define DBGU_SR_RXRDY_1                       (DBGU_SR_RXRDY_1_Val << DBGU_SR_RXRDY_Pos)           /* (DBGU_SR) At least one complete character has been received, transferred to DBGU_RHR, and not yet read. Position  */
#define DBGU_SR_TXRDY_Pos                     _UINT32_(1)                                          /* (DBGU_SR) Transmitter Ready Position */
#define DBGU_SR_TXRDY_Msk                     (_UINT32_(0x1) << DBGU_SR_TXRDY_Pos)                 /* (DBGU_SR) Transmitter Ready Mask */
#define DBGU_SR_TXRDY(value)                  (DBGU_SR_TXRDY_Msk & (_UINT32_(value) << DBGU_SR_TXRDY_Pos)) /* Assigment of value for TXRDY in the DBGU_SR register */
#define   DBGU_SR_TXRDY_0_Val                 _UINT32_(0x0)                                        /* (DBGU_SR) A character has been written to DBGU_THR and not yet transferred to the internal shift register, or the transmitter is disabled.  */
#define   DBGU_SR_TXRDY_1_Val                 _UINT32_(0x1)                                        /* (DBGU_SR) There is no character written to DBGU_THR that is not yet transferred to the internal shift register.  */
#define DBGU_SR_TXRDY_0                       (DBGU_SR_TXRDY_0_Val << DBGU_SR_TXRDY_Pos)           /* (DBGU_SR) A character has been written to DBGU_THR and not yet transferred to the internal shift register, or the transmitter is disabled. Position  */
#define DBGU_SR_TXRDY_1                       (DBGU_SR_TXRDY_1_Val << DBGU_SR_TXRDY_Pos)           /* (DBGU_SR) There is no character written to DBGU_THR that is not yet transferred to the internal shift register. Position  */
#define DBGU_SR_OVRE_Pos                      _UINT32_(5)                                          /* (DBGU_SR) Overrun Error Position */
#define DBGU_SR_OVRE_Msk                      (_UINT32_(0x1) << DBGU_SR_OVRE_Pos)                  /* (DBGU_SR) Overrun Error Mask */
#define DBGU_SR_OVRE(value)                   (DBGU_SR_OVRE_Msk & (_UINT32_(value) << DBGU_SR_OVRE_Pos)) /* Assigment of value for OVRE in the DBGU_SR register */
#define   DBGU_SR_OVRE_0_Val                  _UINT32_(0x0)                                        /* (DBGU_SR) No overrun error has occurred since the last RSTSTA.  */
#define   DBGU_SR_OVRE_1_Val                  _UINT32_(0x1)                                        /* (DBGU_SR) At least one overrun error has occurred since the last RSTSTA.  */
#define DBGU_SR_OVRE_0                        (DBGU_SR_OVRE_0_Val << DBGU_SR_OVRE_Pos)             /* (DBGU_SR) No overrun error has occurred since the last RSTSTA. Position  */
#define DBGU_SR_OVRE_1                        (DBGU_SR_OVRE_1_Val << DBGU_SR_OVRE_Pos)             /* (DBGU_SR) At least one overrun error has occurred since the last RSTSTA. Position  */
#define DBGU_SR_FRAME_Pos                     _UINT32_(6)                                          /* (DBGU_SR) Framing Error Position */
#define DBGU_SR_FRAME_Msk                     (_UINT32_(0x1) << DBGU_SR_FRAME_Pos)                 /* (DBGU_SR) Framing Error Mask */
#define DBGU_SR_FRAME(value)                  (DBGU_SR_FRAME_Msk & (_UINT32_(value) << DBGU_SR_FRAME_Pos)) /* Assigment of value for FRAME in the DBGU_SR register */
#define   DBGU_SR_FRAME_0_Val                 _UINT32_(0x0)                                        /* (DBGU_SR) No framing error has occurred since the last RSTSTA.  */
#define   DBGU_SR_FRAME_1_Val                 _UINT32_(0x1)                                        /* (DBGU_SR) At least one framing error has occurred since the last RSTSTA.  */
#define DBGU_SR_FRAME_0                       (DBGU_SR_FRAME_0_Val << DBGU_SR_FRAME_Pos)           /* (DBGU_SR) No framing error has occurred since the last RSTSTA. Position  */
#define DBGU_SR_FRAME_1                       (DBGU_SR_FRAME_1_Val << DBGU_SR_FRAME_Pos)           /* (DBGU_SR) At least one framing error has occurred since the last RSTSTA. Position  */
#define DBGU_SR_PARE_Pos                      _UINT32_(7)                                          /* (DBGU_SR) Parity Error Position */
#define DBGU_SR_PARE_Msk                      (_UINT32_(0x1) << DBGU_SR_PARE_Pos)                  /* (DBGU_SR) Parity Error Mask */
#define DBGU_SR_PARE(value)                   (DBGU_SR_PARE_Msk & (_UINT32_(value) << DBGU_SR_PARE_Pos)) /* Assigment of value for PARE in the DBGU_SR register */
#define   DBGU_SR_PARE_0_Val                  _UINT32_(0x0)                                        /* (DBGU_SR) No parity error has occurred since the last RSTSTA.  */
#define   DBGU_SR_PARE_1_Val                  _UINT32_(0x1)                                        /* (DBGU_SR) At least one parity error has occurred since the last RSTSTA.  */
#define DBGU_SR_PARE_0                        (DBGU_SR_PARE_0_Val << DBGU_SR_PARE_Pos)             /* (DBGU_SR) No parity error has occurred since the last RSTSTA. Position  */
#define DBGU_SR_PARE_1                        (DBGU_SR_PARE_1_Val << DBGU_SR_PARE_Pos)             /* (DBGU_SR) At least one parity error has occurred since the last RSTSTA. Position  */
#define DBGU_SR_TIMEOUT_Pos                   _UINT32_(8)                                          /* (DBGU_SR) Receiver Timeout Position */
#define DBGU_SR_TIMEOUT_Msk                   (_UINT32_(0x1) << DBGU_SR_TIMEOUT_Pos)               /* (DBGU_SR) Receiver Timeout Mask */
#define DBGU_SR_TIMEOUT(value)                (DBGU_SR_TIMEOUT_Msk & (_UINT32_(value) << DBGU_SR_TIMEOUT_Pos)) /* Assigment of value for TIMEOUT in the DBGU_SR register */
#define   DBGU_SR_TIMEOUT_0_Val               _UINT32_(0x0)                                        /* (DBGU_SR) There has not been any timeout since the last Start timeout command (DBGU_CR.STTTO), or the Timeout register is 0.  */
#define   DBGU_SR_TIMEOUT_1_Val               _UINT32_(0x1)                                        /* (DBGU_SR) There has been a timeout since the last Start timeout command (DBGU_CR.STTTO).  */
#define DBGU_SR_TIMEOUT_0                     (DBGU_SR_TIMEOUT_0_Val << DBGU_SR_TIMEOUT_Pos)       /* (DBGU_SR) There has not been any timeout since the last Start timeout command (DBGU_CR.STTTO), or the Timeout register is 0. Position  */
#define DBGU_SR_TIMEOUT_1                     (DBGU_SR_TIMEOUT_1_Val << DBGU_SR_TIMEOUT_Pos)       /* (DBGU_SR) There has been a timeout since the last Start timeout command (DBGU_CR.STTTO). Position  */
#define DBGU_SR_TXEMPTY_Pos                   _UINT32_(9)                                          /* (DBGU_SR) Transmitter Empty Position */
#define DBGU_SR_TXEMPTY_Msk                   (_UINT32_(0x1) << DBGU_SR_TXEMPTY_Pos)               /* (DBGU_SR) Transmitter Empty Mask */
#define DBGU_SR_TXEMPTY(value)                (DBGU_SR_TXEMPTY_Msk & (_UINT32_(value) << DBGU_SR_TXEMPTY_Pos)) /* Assigment of value for TXEMPTY in the DBGU_SR register */
#define   DBGU_SR_TXEMPTY_0_Val               _UINT32_(0x0)                                        /* (DBGU_SR) There are characters in DBGU_THR, or characters are being processed by the transmitter, or the transmitter is disabled.  */
#define   DBGU_SR_TXEMPTY_1_Val               _UINT32_(0x1)                                        /* (DBGU_SR) There are no characters in DBGU_THR and there are no characters being processed by the transmitter.  */
#define DBGU_SR_TXEMPTY_0                     (DBGU_SR_TXEMPTY_0_Val << DBGU_SR_TXEMPTY_Pos)       /* (DBGU_SR) There are characters in DBGU_THR, or characters are being processed by the transmitter, or the transmitter is disabled. Position  */
#define DBGU_SR_TXEMPTY_1                     (DBGU_SR_TXEMPTY_1_Val << DBGU_SR_TXEMPTY_Pos)       /* (DBGU_SR) There are no characters in DBGU_THR and there are no characters being processed by the transmitter. Position  */
#define DBGU_SR_COMMTX_Pos                    _UINT32_(30)                                         /* (DBGU_SR) Debug Communication Channel Write Status Position */
#define DBGU_SR_COMMTX_Msk                    (_UINT32_(0x1) << DBGU_SR_COMMTX_Pos)                /* (DBGU_SR) Debug Communication Channel Write Status Mask */
#define DBGU_SR_COMMTX(value)                 (DBGU_SR_COMMTX_Msk & (_UINT32_(value) << DBGU_SR_COMMTX_Pos)) /* Assigment of value for COMMTX in the DBGU_SR register */
#define   DBGU_SR_COMMTX_0_Val                _UINT32_(0x0)                                        /* (DBGU_SR) COMMTX from the ARM processor is inactive.  */
#define   DBGU_SR_COMMTX_1_Val                _UINT32_(0x1)                                        /* (DBGU_SR) COMMTX from the ARM processor is active.  */
#define DBGU_SR_COMMTX_0                      (DBGU_SR_COMMTX_0_Val << DBGU_SR_COMMTX_Pos)         /* (DBGU_SR) COMMTX from the ARM processor is inactive. Position  */
#define DBGU_SR_COMMTX_1                      (DBGU_SR_COMMTX_1_Val << DBGU_SR_COMMTX_Pos)         /* (DBGU_SR) COMMTX from the ARM processor is active. Position  */
#define DBGU_SR_COMMRX_Pos                    _UINT32_(31)                                         /* (DBGU_SR) Debug Communication Channel Read Status Position */
#define DBGU_SR_COMMRX_Msk                    (_UINT32_(0x1) << DBGU_SR_COMMRX_Pos)                /* (DBGU_SR) Debug Communication Channel Read Status Mask */
#define DBGU_SR_COMMRX(value)                 (DBGU_SR_COMMRX_Msk & (_UINT32_(value) << DBGU_SR_COMMRX_Pos)) /* Assigment of value for COMMRX in the DBGU_SR register */
#define   DBGU_SR_COMMRX_0_Val                _UINT32_(0x0)                                        /* (DBGU_SR) COMMRX from the ARM processor is inactive.  */
#define   DBGU_SR_COMMRX_1_Val                _UINT32_(0x1)                                        /* (DBGU_SR) COMMRX from the ARM processor is active.  */
#define DBGU_SR_COMMRX_0                      (DBGU_SR_COMMRX_0_Val << DBGU_SR_COMMRX_Pos)         /* (DBGU_SR) COMMRX from the ARM processor is inactive. Position  */
#define DBGU_SR_COMMRX_1                      (DBGU_SR_COMMRX_1_Val << DBGU_SR_COMMRX_Pos)         /* (DBGU_SR) COMMRX from the ARM processor is active. Position  */
#define DBGU_SR_Msk                           _UINT32_(0xC00003E3)                                 /* (DBGU_SR) Register Mask  */


/* -------- DBGU_RHR : (DBGU Offset: 0x18) ( R/ 32) Receive Holding Register -------- */
#define DBGU_RHR_RESETVALUE                   _UINT32_(0x00)                                       /*  (DBGU_RHR) Receive Holding Register  Reset Value */

#define DBGU_RHR_RXCHR_Pos                    _UINT32_(0)                                          /* (DBGU_RHR) Received Character Position */
#define DBGU_RHR_RXCHR_Msk                    (_UINT32_(0xFF) << DBGU_RHR_RXCHR_Pos)               /* (DBGU_RHR) Received Character Mask */
#define DBGU_RHR_RXCHR(value)                 (DBGU_RHR_RXCHR_Msk & (_UINT32_(value) << DBGU_RHR_RXCHR_Pos)) /* Assigment of value for RXCHR in the DBGU_RHR register */
#define DBGU_RHR_Msk                          _UINT32_(0x000000FF)                                 /* (DBGU_RHR) Register Mask  */


/* -------- DBGU_THR : (DBGU Offset: 0x1C) ( /W 32) Transmit Holding Register -------- */
#define DBGU_THR_TXCHR_Pos                    _UINT32_(0)                                          /* (DBGU_THR) Character to be Transmitted Position */
#define DBGU_THR_TXCHR_Msk                    (_UINT32_(0xFF) << DBGU_THR_TXCHR_Pos)               /* (DBGU_THR) Character to be Transmitted Mask */
#define DBGU_THR_TXCHR(value)                 (DBGU_THR_TXCHR_Msk & (_UINT32_(value) << DBGU_THR_TXCHR_Pos)) /* Assigment of value for TXCHR in the DBGU_THR register */
#define DBGU_THR_Msk                          _UINT32_(0x000000FF)                                 /* (DBGU_THR) Register Mask  */


/* -------- DBGU_BRGR : (DBGU Offset: 0x20) (R/W 32) Baud Rate Generator Register -------- */
#define DBGU_BRGR_RESETVALUE                  _UINT32_(0x00)                                       /*  (DBGU_BRGR) Baud Rate Generator Register  Reset Value */

#define DBGU_BRGR_CD_Pos                      _UINT32_(0)                                          /* (DBGU_BRGR) Clock Divisor Position */
#define DBGU_BRGR_CD_Msk                      (_UINT32_(0xFFFF) << DBGU_BRGR_CD_Pos)               /* (DBGU_BRGR) Clock Divisor Mask */
#define DBGU_BRGR_CD(value)                   (DBGU_BRGR_CD_Msk & (_UINT32_(value) << DBGU_BRGR_CD_Pos)) /* Assigment of value for CD in the DBGU_BRGR register */
#define   DBGU_BRGR_CD_0_Val                  _UINT32_(0x0)                                        /* (DBGU_BRGR) Baud rate clock is disabled.  */
#define DBGU_BRGR_CD_0                        (DBGU_BRGR_CD_0_Val << DBGU_BRGR_CD_Pos)             /* (DBGU_BRGR) Baud rate clock is disabled. Position  */
#define DBGU_BRGR_Msk                         _UINT32_(0x0000FFFF)                                 /* (DBGU_BRGR) Register Mask  */


/* -------- DBGU_RTOR : (DBGU Offset: 0x28) (R/W 32) Receiver Timeout Register -------- */
#define DBGU_RTOR_RESETVALUE                  _UINT32_(0x00)                                       /*  (DBGU_RTOR) Receiver Timeout Register  Reset Value */

#define DBGU_RTOR_TO_Pos                      _UINT32_(0)                                          /* (DBGU_RTOR) Timeout Value Position */
#define DBGU_RTOR_TO_Msk                      (_UINT32_(0xFF) << DBGU_RTOR_TO_Pos)                 /* (DBGU_RTOR) Timeout Value Mask */
#define DBGU_RTOR_TO(value)                   (DBGU_RTOR_TO_Msk & (_UINT32_(value) << DBGU_RTOR_TO_Pos)) /* Assigment of value for TO in the DBGU_RTOR register */
#define   DBGU_RTOR_TO_0_Val                  _UINT32_(0x0)                                        /* (DBGU_RTOR) The receiver timeout is disabled.  */
#define DBGU_RTOR_TO_0                        (DBGU_RTOR_TO_0_Val << DBGU_RTOR_TO_Pos)             /* (DBGU_RTOR) The receiver timeout is disabled. Position  */
#define DBGU_RTOR_Msk                         _UINT32_(0x000000FF)                                 /* (DBGU_RTOR) Register Mask  */


/* -------- DBGU_CIDR : (DBGU Offset: 0x40) ( R/ 32) Chip ID Register -------- */
#define DBGU_CIDR_RESETVALUE                  _UINT32_(0x819B35A1)                                 /*  (DBGU_CIDR) Chip ID Register  Reset Value */

#define DBGU_CIDR_CHID_Pos                    _UINT32_(0)                                          /* (DBGU_CIDR) Chip ID Value Position */
#define DBGU_CIDR_CHID_Msk                    (_UINT32_(0x7FFFFFFF) << DBGU_CIDR_CHID_Pos)         /* (DBGU_CIDR) Chip ID Value Mask */
#define DBGU_CIDR_CHID(value)                 (DBGU_CIDR_CHID_Msk & (_UINT32_(value) << DBGU_CIDR_CHID_Pos)) /* Assigment of value for CHID in the DBGU_CIDR register */
#define DBGU_CIDR_EXT_Pos                     _UINT32_(31)                                         /* (DBGU_CIDR) Extension Flag Position */
#define DBGU_CIDR_EXT_Msk                     (_UINT32_(0x1) << DBGU_CIDR_EXT_Pos)                 /* (DBGU_CIDR) Extension Flag Mask */
#define DBGU_CIDR_EXT(value)                  (DBGU_CIDR_EXT_Msk & (_UINT32_(value) << DBGU_CIDR_EXT_Pos)) /* Assigment of value for EXT in the DBGU_CIDR register */
#define   DBGU_CIDR_EXT_0_Val                 _UINT32_(0x0)                                        /* (DBGU_CIDR) Chip ID has a single register definition without extension.  */
#define   DBGU_CIDR_EXT_1_Val                 _UINT32_(0x1)                                        /* (DBGU_CIDR) An extended Chip ID exists.  */
#define DBGU_CIDR_EXT_0                       (DBGU_CIDR_EXT_0_Val << DBGU_CIDR_EXT_Pos)           /* (DBGU_CIDR) Chip ID has a single register definition without extension. Position  */
#define DBGU_CIDR_EXT_1                       (DBGU_CIDR_EXT_1_Val << DBGU_CIDR_EXT_Pos)           /* (DBGU_CIDR) An extended Chip ID exists. Position  */
#define DBGU_CIDR_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (DBGU_CIDR) Register Mask  */


/* -------- DBGU_EXID : (DBGU Offset: 0x44) ( R/ 32) Chip ID Extension Register -------- */
#define DBGU_EXID_EXID_Pos                    _UINT32_(0)                                          /* (DBGU_EXID) Chip ID Extension Position */
#define DBGU_EXID_EXID_Msk                    (_UINT32_(0xFFFFFFFF) << DBGU_EXID_EXID_Pos)         /* (DBGU_EXID) Chip ID Extension Mask */
#define DBGU_EXID_EXID(value)                 (DBGU_EXID_EXID_Msk & (_UINT32_(value) << DBGU_EXID_EXID_Pos)) /* Assigment of value for EXID in the DBGU_EXID register */
#define DBGU_EXID_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (DBGU_EXID) Register Mask  */


/* -------- DBGU_FNR : (DBGU Offset: 0x48) (R/W 32) Force NTRST Register -------- */
#define DBGU_FNR_RESETVALUE                   _UINT32_(0x00)                                       /*  (DBGU_FNR) Force NTRST Register  Reset Value */

#define DBGU_FNR_FNTRST_Pos                   _UINT32_(0)                                          /* (DBGU_FNR) Force NTRST Position */
#define DBGU_FNR_FNTRST_Msk                   (_UINT32_(0x1) << DBGU_FNR_FNTRST_Pos)               /* (DBGU_FNR) Force NTRST Mask */
#define DBGU_FNR_FNTRST(value)                (DBGU_FNR_FNTRST_Msk & (_UINT32_(value) << DBGU_FNR_FNTRST_Pos)) /* Assigment of value for FNTRST in the DBGU_FNR register */
#define   DBGU_FNR_FNTRST_0_Val               _UINT32_(0x0)                                        /* (DBGU_FNR) NTRST of the ARM processor's TAP controller is driven by the power_on_reset signal.  */
#define   DBGU_FNR_FNTRST_1_Val               _UINT32_(0x1)                                        /* (DBGU_FNR) NTRST of the ARM processor's TAP controller is held low.  */
#define DBGU_FNR_FNTRST_0                     (DBGU_FNR_FNTRST_0_Val << DBGU_FNR_FNTRST_Pos)       /* (DBGU_FNR) NTRST of the ARM processor's TAP controller is driven by the power_on_reset signal. Position  */
#define DBGU_FNR_FNTRST_1                     (DBGU_FNR_FNTRST_1_Val << DBGU_FNR_FNTRST_Pos)       /* (DBGU_FNR) NTRST of the ARM processor's TAP controller is held low. Position  */
#define DBGU_FNR_Msk                          _UINT32_(0x00000001)                                 /* (DBGU_FNR) Register Mask  */


/* -------- DBGU_WPMR : (DBGU Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define DBGU_WPMR_RESETVALUE                  _UINT32_(0x00)                                       /*  (DBGU_WPMR) Write Protection Mode Register  Reset Value */

#define DBGU_WPMR_WPEN_Pos                    _UINT32_(0)                                          /* (DBGU_WPMR) Write Protection Enable Position */
#define DBGU_WPMR_WPEN_Msk                    (_UINT32_(0x1) << DBGU_WPMR_WPEN_Pos)                /* (DBGU_WPMR) Write Protection Enable Mask */
#define DBGU_WPMR_WPEN(value)                 (DBGU_WPMR_WPEN_Msk & (_UINT32_(value) << DBGU_WPMR_WPEN_Pos)) /* Assigment of value for WPEN in the DBGU_WPMR register */
#define   DBGU_WPMR_WPEN_0_Val                _UINT32_(0x0)                                        /* (DBGU_WPMR) Disables the write protection if WPKEY corresponds to 0x554152 (DBGU in ASCII).  */
#define   DBGU_WPMR_WPEN_1_Val                _UINT32_(0x1)                                        /* (DBGU_WPMR) Enables the write protection if WPKEY corresponds to 0x554152 (DBGU in ASCII).  */
#define DBGU_WPMR_WPEN_0                      (DBGU_WPMR_WPEN_0_Val << DBGU_WPMR_WPEN_Pos)         /* (DBGU_WPMR) Disables the write protection if WPKEY corresponds to 0x554152 (DBGU in ASCII). Position  */
#define DBGU_WPMR_WPEN_1                      (DBGU_WPMR_WPEN_1_Val << DBGU_WPMR_WPEN_Pos)         /* (DBGU_WPMR) Enables the write protection if WPKEY corresponds to 0x554152 (DBGU in ASCII). Position  */
#define DBGU_WPMR_WPKEY_Pos                   _UINT32_(8)                                          /* (DBGU_WPMR) Write Protection Key Position */
#define DBGU_WPMR_WPKEY_Msk                   (_UINT32_(0xFFFFFF) << DBGU_WPMR_WPKEY_Pos)          /* (DBGU_WPMR) Write Protection Key Mask */
#define DBGU_WPMR_WPKEY(value)                (DBGU_WPMR_WPKEY_Msk & (_UINT32_(value) << DBGU_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the DBGU_WPMR register */
#define   DBGU_WPMR_WPKEY_PASSWD_Val          _UINT32_(0x554152)                                   /* (DBGU_WPMR) Writing any other value in this field aborts the write operation. Always reads as 0.  */
#define DBGU_WPMR_WPKEY_PASSWD                (DBGU_WPMR_WPKEY_PASSWD_Val << DBGU_WPMR_WPKEY_Pos)  /* (DBGU_WPMR) Writing any other value in this field aborts the write operation. Always reads as 0. Position  */
#define DBGU_WPMR_Msk                         _UINT32_(0xFFFFFF01)                                 /* (DBGU_WPMR) Register Mask  */


/** \brief DBGU register offsets definitions */
#define DBGU_CR_REG_OFST               _UINT32_(0x00)      /* (DBGU_CR) Control Register Offset */
#define DBGU_MR_REG_OFST               _UINT32_(0x04)      /* (DBGU_MR) Mode Register Offset */
#define DBGU_IER_REG_OFST              _UINT32_(0x08)      /* (DBGU_IER) Interrupt Enable Register Offset */
#define DBGU_IDR_REG_OFST              _UINT32_(0x0C)      /* (DBGU_IDR) Interrupt Disable Register Offset */
#define DBGU_IMR_REG_OFST              _UINT32_(0x10)      /* (DBGU_IMR) Interrupt Mask Register Offset */
#define DBGU_SR_REG_OFST               _UINT32_(0x14)      /* (DBGU_SR) Status Register Offset */
#define DBGU_RHR_REG_OFST              _UINT32_(0x18)      /* (DBGU_RHR) Receive Holding Register Offset */
#define DBGU_THR_REG_OFST              _UINT32_(0x1C)      /* (DBGU_THR) Transmit Holding Register Offset */
#define DBGU_BRGR_REG_OFST             _UINT32_(0x20)      /* (DBGU_BRGR) Baud Rate Generator Register Offset */
#define DBGU_RTOR_REG_OFST             _UINT32_(0x28)      /* (DBGU_RTOR) Receiver Timeout Register Offset */
#define DBGU_CIDR_REG_OFST             _UINT32_(0x40)      /* (DBGU_CIDR) Chip ID Register Offset */
#define DBGU_EXID_REG_OFST             _UINT32_(0x44)      /* (DBGU_EXID) Chip ID Extension Register Offset */
#define DBGU_FNR_REG_OFST              _UINT32_(0x48)      /* (DBGU_FNR) Force NTRST Register Offset */
#define DBGU_WPMR_REG_OFST             _UINT32_(0xE4)      /* (DBGU_WPMR) Write Protection Mode Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief DBGU register API structure */
typedef struct
{  /* Debug Unit */
  __O   uint32_t                       DBGU_CR;            /**< Offset: 0x00 ( /W  32) Control Register */
  __IO  uint32_t                       DBGU_MR;            /**< Offset: 0x04 (R/W  32) Mode Register */
  __O   uint32_t                       DBGU_IER;           /**< Offset: 0x08 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       DBGU_IDR;           /**< Offset: 0x0C ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       DBGU_IMR;           /**< Offset: 0x10 (R/   32) Interrupt Mask Register */
  __I   uint32_t                       DBGU_SR;            /**< Offset: 0x14 (R/   32) Status Register */
  __I   uint32_t                       DBGU_RHR;           /**< Offset: 0x18 (R/   32) Receive Holding Register */
  __O   uint32_t                       DBGU_THR;           /**< Offset: 0x1C ( /W  32) Transmit Holding Register */
  __IO  uint32_t                       DBGU_BRGR;          /**< Offset: 0x20 (R/W  32) Baud Rate Generator Register */
  __I   uint8_t                        Reserved1[0x04];
  __IO  uint32_t                       DBGU_RTOR;          /**< Offset: 0x28 (R/W  32) Receiver Timeout Register */
  __I   uint8_t                        Reserved2[0x14];
  __I   uint32_t                       DBGU_CIDR;          /**< Offset: 0x40 (R/   32) Chip ID Register */
  __I   uint32_t                       DBGU_EXID;          /**< Offset: 0x44 (R/   32) Chip ID Extension Register */
  __IO  uint32_t                       DBGU_FNR;           /**< Offset: 0x48 (R/W  32) Force NTRST Register */
  __I   uint8_t                        Reserved3[0x98];
  __IO  uint32_t                       DBGU_WPMR;          /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
} dbgu_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X7_DBGU_COMPONENT_H_ */
