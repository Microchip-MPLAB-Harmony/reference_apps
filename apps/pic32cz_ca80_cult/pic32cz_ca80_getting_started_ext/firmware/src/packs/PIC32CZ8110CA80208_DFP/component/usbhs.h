/*
 * Component description for USBHS
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
#ifndef _PIC32CZCA80_USBHS_COMPONENT_H_
#define _PIC32CZCA80_USBHS_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR USBHS                                        */
/* ************************************************************************** */

/* -------- USBHS_DMACNTL : (USBHS Offset: 0x00) (R/W 32) DMA Transfer Control For Each Channel -------- */
#define USBHS_DMACNTL_RESETVALUE              _UINT32_(0x00)                                       /*  (USBHS_DMACNTL) DMA Transfer Control For Each Channel  Reset Value */

#define USBHS_DMACNTL_DMAEN_Pos               _UINT32_(0)                                          /* (USBHS_DMACNTL) dma transfer enable Position */
#define USBHS_DMACNTL_DMAEN_Msk               (_UINT32_(0x1) << USBHS_DMACNTL_DMAEN_Pos)           /* (USBHS_DMACNTL) dma transfer enable Mask */
#define USBHS_DMACNTL_DMAEN(value)            (USBHS_DMACNTL_DMAEN_Msk & (_UINT32_(value) << USBHS_DMACNTL_DMAEN_Pos)) /* Assigment of value for DMAEN in the USBHS_DMACNTL register */
#define USBHS_DMACNTL_DMADIR_Pos              _UINT32_(1)                                          /* (USBHS_DMACNTL) transfer direction Position */
#define USBHS_DMACNTL_DMADIR_Msk              (_UINT32_(0x1) << USBHS_DMACNTL_DMADIR_Pos)          /* (USBHS_DMACNTL) transfer direction Mask */
#define USBHS_DMACNTL_DMADIR(value)           (USBHS_DMACNTL_DMADIR_Msk & (_UINT32_(value) << USBHS_DMACNTL_DMADIR_Pos)) /* Assigment of value for DMADIR in the USBHS_DMACNTL register */
#define   USBHS_DMACNTL_DMADIR_WRITE_Val      _UINT32_(0x0)                                        /* (USBHS_DMACNTL) DMA Write (RX Endpoint)  */
#define   USBHS_DMACNTL_DMADIR_READ_Val       _UINT32_(0x1)                                        /* (USBHS_DMACNTL) DMA Read (TX Endpoint)  */
#define USBHS_DMACNTL_DMADIR_WRITE            (USBHS_DMACNTL_DMADIR_WRITE_Val << USBHS_DMACNTL_DMADIR_Pos) /* (USBHS_DMACNTL) DMA Write (RX Endpoint) Position  */
#define USBHS_DMACNTL_DMADIR_READ             (USBHS_DMACNTL_DMADIR_READ_Val << USBHS_DMACNTL_DMADIR_Pos) /* (USBHS_DMACNTL) DMA Read (TX Endpoint) Position  */
#define USBHS_DMACNTL_DMAMODE_Pos             _UINT32_(2)                                          /* (USBHS_DMACNTL) transfer mode Position */
#define USBHS_DMACNTL_DMAMODE_Msk             (_UINT32_(0x1) << USBHS_DMACNTL_DMAMODE_Pos)         /* (USBHS_DMACNTL) transfer mode Mask */
#define USBHS_DMACNTL_DMAMODE(value)          (USBHS_DMACNTL_DMAMODE_Msk & (_UINT32_(value) << USBHS_DMACNTL_DMAMODE_Pos)) /* Assigment of value for DMAMODE in the USBHS_DMACNTL register */
#define   USBHS_DMACNTL_DMAMODE_MODE0_Val     _UINT32_(0x0)                                        /* (USBHS_DMACNTL) Mode 0 Transfer  */
#define   USBHS_DMACNTL_DMAMODE_MODE1_Val     _UINT32_(0x1)                                        /* (USBHS_DMACNTL) Mode1 Transfer  */
#define USBHS_DMACNTL_DMAMODE_MODE0           (USBHS_DMACNTL_DMAMODE_MODE0_Val << USBHS_DMACNTL_DMAMODE_Pos) /* (USBHS_DMACNTL) Mode 0 Transfer Position  */
#define USBHS_DMACNTL_DMAMODE_MODE1           (USBHS_DMACNTL_DMAMODE_MODE1_Val << USBHS_DMACNTL_DMAMODE_Pos) /* (USBHS_DMACNTL) Mode1 Transfer Position  */
#define USBHS_DMACNTL_DMAIE_Pos               _UINT32_(3)                                          /* (USBHS_DMACNTL) interrupt enable Position */
#define USBHS_DMACNTL_DMAIE_Msk               (_UINT32_(0x1) << USBHS_DMACNTL_DMAIE_Pos)           /* (USBHS_DMACNTL) interrupt enable Mask */
#define USBHS_DMACNTL_DMAIE(value)            (USBHS_DMACNTL_DMAIE_Msk & (_UINT32_(value) << USBHS_DMACNTL_DMAIE_Pos)) /* Assigment of value for DMAIE in the USBHS_DMACNTL register */
#define USBHS_DMACNTL_DMAEP_Pos               _UINT32_(4)                                          /* (USBHS_DMACNTL) endpoint number this channel is assigned to Position */
#define USBHS_DMACNTL_DMAEP_Msk               (_UINT32_(0xF) << USBHS_DMACNTL_DMAEP_Pos)           /* (USBHS_DMACNTL) endpoint number this channel is assigned to Mask */
#define USBHS_DMACNTL_DMAEP(value)            (USBHS_DMACNTL_DMAEP_Msk & (_UINT32_(value) << USBHS_DMACNTL_DMAEP_Pos)) /* Assigment of value for DMAEP in the USBHS_DMACNTL register */
#define USBHS_DMACNTL_DMAERR_Pos              _UINT32_(8)                                          /* (USBHS_DMACNTL) bus error bit Position */
#define USBHS_DMACNTL_DMAERR_Msk              (_UINT32_(0x1) << USBHS_DMACNTL_DMAERR_Pos)          /* (USBHS_DMACNTL) bus error bit Mask */
#define USBHS_DMACNTL_DMAERR(value)           (USBHS_DMACNTL_DMAERR_Msk & (_UINT32_(value) << USBHS_DMACNTL_DMAERR_Pos)) /* Assigment of value for DMAERR in the USBHS_DMACNTL register */
#define USBHS_DMACNTL_DMABRSTM_Pos            _UINT32_(9)                                          /* (USBHS_DMACNTL) burst mode Position */
#define USBHS_DMACNTL_DMABRSTM_Msk            (_UINT32_(0x3) << USBHS_DMACNTL_DMABRSTM_Pos)        /* (USBHS_DMACNTL) burst mode Mask */
#define USBHS_DMACNTL_DMABRSTM(value)         (USBHS_DMACNTL_DMABRSTM_Msk & (_UINT32_(value) << USBHS_DMACNTL_DMABRSTM_Pos)) /* Assigment of value for DMABRSTM in the USBHS_DMACNTL register */
#define   USBHS_DMACNTL_DMABRSTM_BM0_Val      _UINT32_(0x0)                                        /* (USBHS_DMACNTL) Burst Mode 0  */
#define   USBHS_DMACNTL_DMABRSTM_BM1_Val      _UINT32_(0x1)                                        /* (USBHS_DMACNTL) Burst Mode 1  */
#define   USBHS_DMACNTL_DMABRSTM_BM2_Val      _UINT32_(0x2)                                        /* (USBHS_DMACNTL) Burst Mode 2  */
#define   USBHS_DMACNTL_DMABRSTM_BM3_Val      _UINT32_(0x3)                                        /* (USBHS_DMACNTL) Burst Mode 3  */
#define USBHS_DMACNTL_DMABRSTM_BM0            (USBHS_DMACNTL_DMABRSTM_BM0_Val << USBHS_DMACNTL_DMABRSTM_Pos) /* (USBHS_DMACNTL) Burst Mode 0 Position  */
#define USBHS_DMACNTL_DMABRSTM_BM1            (USBHS_DMACNTL_DMABRSTM_BM1_Val << USBHS_DMACNTL_DMABRSTM_Pos) /* (USBHS_DMACNTL) Burst Mode 1 Position  */
#define USBHS_DMACNTL_DMABRSTM_BM2            (USBHS_DMACNTL_DMABRSTM_BM2_Val << USBHS_DMACNTL_DMABRSTM_Pos) /* (USBHS_DMACNTL) Burst Mode 2 Position  */
#define USBHS_DMACNTL_DMABRSTM_BM3            (USBHS_DMACNTL_DMABRSTM_BM3_Val << USBHS_DMACNTL_DMABRSTM_Pos) /* (USBHS_DMACNTL) Burst Mode 3 Position  */
#define USBHS_DMACNTL_Msk                     _UINT32_(0x000007FF)                                 /* (USBHS_DMACNTL) Register Mask  */


/* -------- USBHS_DMAADDR : (USBHS Offset: 0x04) (R/W 32) Memory Address Of The Corresponding DMA Channel -------- */
#define USBHS_DMAADDR_RESETVALUE              _UINT32_(0x00)                                       /*  (USBHS_DMAADDR) Memory Address Of The Corresponding DMA Channel  Reset Value */

#define USBHS_DMAADDR_ADDR10_Pos              _UINT32_(0)                                          /* (USBHS_DMAADDR) Lower 2 bits of DMA memory address Position */
#define USBHS_DMAADDR_ADDR10_Msk              (_UINT32_(0x3) << USBHS_DMAADDR_ADDR10_Pos)          /* (USBHS_DMAADDR) Lower 2 bits of DMA memory address Mask */
#define USBHS_DMAADDR_ADDR10(value)           (USBHS_DMAADDR_ADDR10_Msk & (_UINT32_(value) << USBHS_DMAADDR_ADDR10_Pos)) /* Assigment of value for ADDR10 in the USBHS_DMAADDR register */
#define USBHS_DMAADDR_ADDR312_Pos             _UINT32_(2)                                          /* (USBHS_DMAADDR) upper 30 bits of address Position */
#define USBHS_DMAADDR_ADDR312_Msk             (_UINT32_(0x3FFFFFFF) << USBHS_DMAADDR_ADDR312_Pos)  /* (USBHS_DMAADDR) upper 30 bits of address Mask */
#define USBHS_DMAADDR_ADDR312(value)          (USBHS_DMAADDR_ADDR312_Msk & (_UINT32_(value) << USBHS_DMAADDR_ADDR312_Pos)) /* Assigment of value for ADDR312 in the USBHS_DMAADDR register */
#define USBHS_DMAADDR_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (USBHS_DMAADDR) Register Mask  */


/* -------- USBHS_DMACOUNT : (USBHS Offset: 0x08) (R/W 32) Current DMA Count Of The Transfer -------- */
#define USBHS_DMACOUNT_RESETVALUE             _UINT32_(0x00)                                       /*  (USBHS_DMACOUNT) Current DMA Count Of The Transfer  Reset Value */

#define USBHS_DMACOUNT_DMACOUNT_Pos           _UINT32_(0)                                          /* (USBHS_DMACOUNT) current dma count of the transfer Position */
#define USBHS_DMACOUNT_DMACOUNT_Msk           (_UINT32_(0xFFFFFFFF) << USBHS_DMACOUNT_DMACOUNT_Pos) /* (USBHS_DMACOUNT) current dma count of the transfer Mask */
#define USBHS_DMACOUNT_DMACOUNT(value)        (USBHS_DMACOUNT_DMACOUNT_Msk & (_UINT32_(value) << USBHS_DMACOUNT_DMACOUNT_Pos)) /* Assigment of value for DMACOUNT in the USBHS_DMACOUNT register */
#define USBHS_DMACOUNT_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (USBHS_DMACOUNT) Register Mask  */


/* -------- USBHS_TXFUNCADDREP : (USBHS Offset: 0x00) (R/W 8) Relevant In Host Mode Only. Address Of The Target Function. -------- */
#define USBHS_TXFUNCADDREP_RESETVALUE         _UINT8_(0x00)                                        /*  (USBHS_TXFUNCADDREP) Relevant In Host Mode Only. Address Of The Target Function.  Reset Value */

#define USBHS_TXFUNCADDREP_TXFUNCADDR_Pos     _UINT8_(0)                                           /* (USBHS_TXFUNCADDREP) address of the target function Position */
#define USBHS_TXFUNCADDREP_TXFUNCADDR_Msk     (_UINT8_(0x7F) << USBHS_TXFUNCADDREP_TXFUNCADDR_Pos) /* (USBHS_TXFUNCADDREP) address of the target function Mask */
#define USBHS_TXFUNCADDREP_TXFUNCADDR(value)  (USBHS_TXFUNCADDREP_TXFUNCADDR_Msk & (_UINT8_(value) << USBHS_TXFUNCADDREP_TXFUNCADDR_Pos)) /* Assigment of value for TXFUNCADDR in the USBHS_TXFUNCADDREP register */
#define USBHS_TXFUNCADDREP_Msk                _UINT8_(0x7F)                                        /* (USBHS_TXFUNCADDREP) Register Mask  */


/* -------- USBHS_TXHUBADDREP : (USBHS Offset: 0x02) (R/W 8) Relevant In Host Mode Only. HUB Address -------- */
#define USBHS_TXHUBADDREP_RESETVALUE          _UINT8_(0x00)                                        /*  (USBHS_TXHUBADDREP) Relevant In Host Mode Only. HUB Address  Reset Value */

#define USBHS_TXHUBADDREP_TXHUBADDR_Pos       _UINT8_(0)                                           /* (USBHS_TXHUBADDREP) hub address Position */
#define USBHS_TXHUBADDREP_TXHUBADDR_Msk       (_UINT8_(0x7F) << USBHS_TXHUBADDREP_TXHUBADDR_Pos)   /* (USBHS_TXHUBADDREP) hub address Mask */
#define USBHS_TXHUBADDREP_TXHUBADDR(value)    (USBHS_TXHUBADDREP_TXHUBADDR_Msk & (_UINT8_(value) << USBHS_TXHUBADDREP_TXHUBADDR_Pos)) /* Assigment of value for TXHUBADDR in the USBHS_TXHUBADDREP register */
#define USBHS_TXHUBADDREP_MULTRANS_Pos        _UINT8_(7)                                           /* (USBHS_TXHUBADDREP) hub has multiple or single translator Position */
#define USBHS_TXHUBADDREP_MULTRANS_Msk        (_UINT8_(0x1) << USBHS_TXHUBADDREP_MULTRANS_Pos)     /* (USBHS_TXHUBADDREP) hub has multiple or single translator Mask */
#define USBHS_TXHUBADDREP_MULTRANS(value)     (USBHS_TXHUBADDREP_MULTRANS_Msk & (_UINT8_(value) << USBHS_TXHUBADDREP_MULTRANS_Pos)) /* Assigment of value for MULTRANS in the USBHS_TXHUBADDREP register */
#define USBHS_TXHUBADDREP_Msk                 _UINT8_(0xFF)                                        /* (USBHS_TXHUBADDREP) Register Mask  */


/* -------- USBHS_TXHUBPORT : (USBHS Offset: 0x03) (R/W 8) Relevant In Host Mode Only. HUB Address -------- */
#define USBHS_TXHUBPORT_RESETVALUE            _UINT8_(0x00)                                        /*  (USBHS_TXHUBPORT) Relevant In Host Mode Only. HUB Address  Reset Value */

#define USBHS_TXHUBPORT_HUBPORT_Pos           _UINT8_(0)                                           /* (USBHS_TXHUBPORT) Hub Port Position */
#define USBHS_TXHUBPORT_HUBPORT_Msk           (_UINT8_(0x7F) << USBHS_TXHUBPORT_HUBPORT_Pos)       /* (USBHS_TXHUBPORT) Hub Port Mask */
#define USBHS_TXHUBPORT_HUBPORT(value)        (USBHS_TXHUBPORT_HUBPORT_Msk & (_UINT8_(value) << USBHS_TXHUBPORT_HUBPORT_Pos)) /* Assigment of value for HUBPORT in the USBHS_TXHUBPORT register */
#define USBHS_TXHUBPORT_Msk                   _UINT8_(0x7F)                                        /* (USBHS_TXHUBPORT) Register Mask  */


/* -------- USBHS_RXFUNCADDREP : (USBHS Offset: 0x04) (R/W 8) Relevant In Host Mode Only. Address Of The Target Function. -------- */
#define USBHS_RXFUNCADDREP_RESETVALUE         _UINT8_(0x00)                                        /*  (USBHS_RXFUNCADDREP) Relevant In Host Mode Only. Address Of The Target Function.  Reset Value */

#define USBHS_RXFUNCADDREP_RXFUNCADDR_Pos     _UINT8_(0)                                           /* (USBHS_RXFUNCADDREP) address of the target function Position */
#define USBHS_RXFUNCADDREP_RXFUNCADDR_Msk     (_UINT8_(0x7F) << USBHS_RXFUNCADDREP_RXFUNCADDR_Pos) /* (USBHS_RXFUNCADDREP) address of the target function Mask */
#define USBHS_RXFUNCADDREP_RXFUNCADDR(value)  (USBHS_RXFUNCADDREP_RXFUNCADDR_Msk & (_UINT8_(value) << USBHS_RXFUNCADDREP_RXFUNCADDR_Pos)) /* Assigment of value for RXFUNCADDR in the USBHS_RXFUNCADDREP register */
#define USBHS_RXFUNCADDREP_Msk                _UINT8_(0x7F)                                        /* (USBHS_RXFUNCADDREP) Register Mask  */


/* -------- USBHS_RXHUBADDREP : (USBHS Offset: 0x06) (R/W 8) Relevant In Host Mode Only. HUB Address -------- */
#define USBHS_RXHUBADDREP_RESETVALUE          _UINT8_(0x00)                                        /*  (USBHS_RXHUBADDREP) Relevant In Host Mode Only. HUB Address  Reset Value */

#define USBHS_RXHUBADDREP_RXHUBADDR_Pos       _UINT8_(0)                                           /* (USBHS_RXHUBADDREP) hub address Position */
#define USBHS_RXHUBADDREP_RXHUBADDR_Msk       (_UINT8_(0x7F) << USBHS_RXHUBADDREP_RXHUBADDR_Pos)   /* (USBHS_RXHUBADDREP) hub address Mask */
#define USBHS_RXHUBADDREP_RXHUBADDR(value)    (USBHS_RXHUBADDREP_RXHUBADDR_Msk & (_UINT8_(value) << USBHS_RXHUBADDREP_RXHUBADDR_Pos)) /* Assigment of value for RXHUBADDR in the USBHS_RXHUBADDREP register */
#define USBHS_RXHUBADDREP_MULTRANS_Pos        _UINT8_(7)                                           /* (USBHS_RXHUBADDREP) hub has multiple or single translator Position */
#define USBHS_RXHUBADDREP_MULTRANS_Msk        (_UINT8_(0x1) << USBHS_RXHUBADDREP_MULTRANS_Pos)     /* (USBHS_RXHUBADDREP) hub has multiple or single translator Mask */
#define USBHS_RXHUBADDREP_MULTRANS(value)     (USBHS_RXHUBADDREP_MULTRANS_Msk & (_UINT8_(value) << USBHS_RXHUBADDREP_MULTRANS_Pos)) /* Assigment of value for MULTRANS in the USBHS_RXHUBADDREP register */
#define USBHS_RXHUBADDREP_Msk                 _UINT8_(0xFF)                                        /* (USBHS_RXHUBADDREP) Register Mask  */


/* -------- USBHS_RXHUBPORT : (USBHS Offset: 0x07) (R/W 8) Relevant In Host Mode Only. HUB Address -------- */
#define USBHS_RXHUBPORT_RESETVALUE            _UINT8_(0x00)                                        /*  (USBHS_RXHUBPORT) Relevant In Host Mode Only. HUB Address  Reset Value */

#define USBHS_RXHUBPORT_HUBPORT_Pos           _UINT8_(0)                                           /* (USBHS_RXHUBPORT) Hub Port Position */
#define USBHS_RXHUBPORT_HUBPORT_Msk           (_UINT8_(0x7F) << USBHS_RXHUBPORT_HUBPORT_Pos)       /* (USBHS_RXHUBPORT) Hub Port Mask */
#define USBHS_RXHUBPORT_HUBPORT(value)        (USBHS_RXHUBPORT_HUBPORT_Msk & (_UINT8_(value) << USBHS_RXHUBPORT_HUBPORT_Pos)) /* Assigment of value for HUBPORT in the USBHS_RXHUBPORT register */
#define USBHS_RXHUBPORT_Msk                   _UINT8_(0x7F)                                        /* (USBHS_RXHUBPORT) Register Mask  */


/* -------- USBHS_CTRLA : (USBHS Offset: 0x00) (R/W 32) USBHS Control Register A. (All bits except ENABLE and SWRST are Enable protected) -------- */
#define USBHS_CTRLA_RESETVALUE                _UINT32_(0x00)                                       /*  (USBHS_CTRLA) USBHS Control Register A. (All bits except ENABLE and SWRST are Enable protected)  Reset Value */

#define USBHS_CTRLA_SWRST_Pos                 _UINT32_(0)                                          /* (USBHS_CTRLA) USBHS Software Reset Position */
#define USBHS_CTRLA_SWRST_Msk                 (_UINT32_(0x1) << USBHS_CTRLA_SWRST_Pos)             /* (USBHS_CTRLA) USBHS Software Reset Mask */
#define USBHS_CTRLA_SWRST(value)              (USBHS_CTRLA_SWRST_Msk & (_UINT32_(value) << USBHS_CTRLA_SWRST_Pos)) /* Assigment of value for SWRST in the USBHS_CTRLA register */
#define USBHS_CTRLA_ENABLE_Pos                _UINT32_(1)                                          /* (USBHS_CTRLA) USBHS Enable Position */
#define USBHS_CTRLA_ENABLE_Msk                (_UINT32_(0x1) << USBHS_CTRLA_ENABLE_Pos)            /* (USBHS_CTRLA) USBHS Enable Mask */
#define USBHS_CTRLA_ENABLE(value)             (USBHS_CTRLA_ENABLE_Msk & (_UINT32_(value) << USBHS_CTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the USBHS_CTRLA register */
#define USBHS_CTRLA_IDVAL_Pos                 _UINT32_(8)                                          /* (USBHS_CTRLA) Override Valud of ID Position */
#define USBHS_CTRLA_IDVAL_Msk                 (_UINT32_(0x1) << USBHS_CTRLA_IDVAL_Pos)             /* (USBHS_CTRLA) Override Valud of ID Mask */
#define USBHS_CTRLA_IDVAL(value)              (USBHS_CTRLA_IDVAL_Msk & (_UINT32_(value) << USBHS_CTRLA_IDVAL_Pos)) /* Assigment of value for IDVAL in the USBHS_CTRLA register */
#define USBHS_CTRLA_IDOVEN_Pos                _UINT32_(9)                                          /* (USBHS_CTRLA) ID Source Select Position */
#define USBHS_CTRLA_IDOVEN_Msk                (_UINT32_(0x1) << USBHS_CTRLA_IDOVEN_Pos)            /* (USBHS_CTRLA) ID Source Select Mask */
#define USBHS_CTRLA_IDOVEN(value)             (USBHS_CTRLA_IDOVEN_Msk & (_UINT32_(value) << USBHS_CTRLA_IDOVEN_Pos)) /* Assigment of value for IDOVEN in the USBHS_CTRLA register */
#define USBHS_CTRLA_REFCLKSEL_Pos             _UINT32_(10)                                         /* (USBHS_CTRLA) Select USB PLL Reference Clock  Speed Position */
#define USBHS_CTRLA_REFCLKSEL_Msk             (_UINT32_(0x1) << USBHS_CTRLA_REFCLKSEL_Pos)         /* (USBHS_CTRLA) Select USB PLL Reference Clock  Speed Mask */
#define USBHS_CTRLA_REFCLKSEL(value)          (USBHS_CTRLA_REFCLKSEL_Msk & (_UINT32_(value) << USBHS_CTRLA_REFCLKSEL_Pos)) /* Assigment of value for REFCLKSEL in the USBHS_CTRLA register */
#define USBHS_CTRLA_Msk                       _UINT32_(0x00000703)                                 /* (USBHS_CTRLA) Register Mask  */


/* -------- USBHS_CTRLB : (USBHS Offset: 0x04) (R/W 32) USBHS Control Register B -------- */
#define USBHS_CTRLB_RESETVALUE                _UINT32_(0x00)                                       /*  (USBHS_CTRLB) USBHS Control Register B  Reset Value */

#define USBHS_CTRLB_BLANK_Pos                 _UINT32_(0)                                          /* (USBHS_CTRLB) Blank the wakeup monitoring for a specific real time Position */
#define USBHS_CTRLB_BLANK_Msk                 (_UINT32_(0xFFFFF) << USBHS_CTRLB_BLANK_Pos)         /* (USBHS_CTRLB) Blank the wakeup monitoring for a specific real time Mask */
#define USBHS_CTRLB_BLANK(value)              (USBHS_CTRLB_BLANK_Msk & (_UINT32_(value) << USBHS_CTRLB_BLANK_Pos)) /* Assigment of value for BLANK in the USBHS_CTRLB register */
#define   USBHS_CTRLB_BLANK_BLANK0_Val        _UINT32_(0x0)                                        /* (USBHS_CTRLB) No blank delay  */
#define   USBHS_CTRLB_BLANK_BLANKMAX_Val      _UINT32_(0xFFFFF)                                    /* (USBHS_CTRLB) Maximum blank delay  */
#define USBHS_CTRLB_BLANK_BLANK0              (USBHS_CTRLB_BLANK_BLANK0_Val << USBHS_CTRLB_BLANK_Pos) /* (USBHS_CTRLB) No blank delay Position  */
#define USBHS_CTRLB_BLANK_BLANKMAX            (USBHS_CTRLB_BLANK_BLANKMAX_Val << USBHS_CTRLB_BLANK_Pos) /* (USBHS_CTRLB) Maximum blank delay Position  */
#define USBHS_CTRLB_Msk                       _UINT32_(0x000FFFFF)                                 /* (USBHS_CTRLB) Register Mask  */


/* -------- USBHS_CTRLC : (USBHS Offset: 0x08) (R/W 32) USBHS Control Register C -------- */
#define USBHS_CTRLC_RESETVALUE                _UINT32_(0x00)                                       /*  (USBHS_CTRLC) USBHS Control Register C  Reset Value */

#define USBHS_CTRLC_T1MSEN_Pos                _UINT32_(4)                                          /* (USBHS_CTRLC) REFCLK and SUSPENDM override Position */
#define USBHS_CTRLC_T1MSEN_Msk                (_UINT32_(0x1) << USBHS_CTRLC_T1MSEN_Pos)            /* (USBHS_CTRLC) REFCLK and SUSPENDM override Mask */
#define USBHS_CTRLC_T1MSEN(value)             (USBHS_CTRLC_T1MSEN_Msk & (_UINT32_(value) << USBHS_CTRLC_T1MSEN_Pos)) /* Assigment of value for T1MSEN in the USBHS_CTRLC register */
#define USBHS_CTRLC_Msk                       _UINT32_(0x00000010)                                 /* (USBHS_CTRLC) Register Mask  */


/* -------- USBHS_INTENCLR : (USBHS Offset: 0x0C) (R/W 32) USBHS Interrupt Enable Clear Register -------- */
#define USBHS_INTENCLR_RESETVALUE             _UINT32_(0x00)                                       /*  (USBHS_INTENCLR) USBHS Interrupt Enable Clear Register  Reset Value */

#define USBHS_INTENCLR_WAKEUP_Pos             _UINT32_(0)                                          /* (USBHS_INTENCLR) Clear USCORE Detaction Interrupt Enable Position */
#define USBHS_INTENCLR_WAKEUP_Msk             (_UINT32_(0x1) << USBHS_INTENCLR_WAKEUP_Pos)         /* (USBHS_INTENCLR) Clear USCORE Detaction Interrupt Enable Mask */
#define USBHS_INTENCLR_WAKEUP(value)          (USBHS_INTENCLR_WAKEUP_Msk & (_UINT32_(value) << USBHS_INTENCLR_WAKEUP_Pos)) /* Assigment of value for WAKEUP in the USBHS_INTENCLR register */
#define USBHS_INTENCLR_RESUME_Pos             _UINT32_(1)                                          /* (USBHS_INTENCLR) Clear Resume Interrupt Enable Position */
#define USBHS_INTENCLR_RESUME_Msk             (_UINT32_(0x1) << USBHS_INTENCLR_RESUME_Pos)         /* (USBHS_INTENCLR) Clear Resume Interrupt Enable Mask */
#define USBHS_INTENCLR_RESUME(value)          (USBHS_INTENCLR_RESUME_Msk & (_UINT32_(value) << USBHS_INTENCLR_RESUME_Pos)) /* Assigment of value for RESUME in the USBHS_INTENCLR register */
#define USBHS_INTENCLR_USB_Pos                _UINT32_(2)                                          /* (USBHS_INTENCLR) Clear USBCORE General Interrupt Enable Position */
#define USBHS_INTENCLR_USB_Msk                (_UINT32_(0x1) << USBHS_INTENCLR_USB_Pos)            /* (USBHS_INTENCLR) Clear USBCORE General Interrupt Enable Mask */
#define USBHS_INTENCLR_USB(value)             (USBHS_INTENCLR_USB_Msk & (_UINT32_(value) << USBHS_INTENCLR_USB_Pos)) /* Assigment of value for USB in the USBHS_INTENCLR register */
#define USBHS_INTENCLR_DMA_Pos                _UINT32_(3)                                          /* (USBHS_INTENCLR) Clear DMA Interrupt Enable Position */
#define USBHS_INTENCLR_DMA_Msk                (_UINT32_(0x1) << USBHS_INTENCLR_DMA_Pos)            /* (USBHS_INTENCLR) Clear DMA Interrupt Enable Mask */
#define USBHS_INTENCLR_DMA(value)             (USBHS_INTENCLR_DMA_Msk & (_UINT32_(value) << USBHS_INTENCLR_DMA_Pos)) /* Assigment of value for DMA in the USBHS_INTENCLR register */
#define USBHS_INTENCLR_T1MS_Pos               _UINT32_(4)                                          /* (USBHS_INTENCLR) Clear T1MS Interrupt Enable Position */
#define USBHS_INTENCLR_T1MS_Msk               (_UINT32_(0x1) << USBHS_INTENCLR_T1MS_Pos)           /* (USBHS_INTENCLR) Clear T1MS Interrupt Enable Mask */
#define USBHS_INTENCLR_T1MS(value)            (USBHS_INTENCLR_T1MS_Msk & (_UINT32_(value) << USBHS_INTENCLR_T1MS_Pos)) /* Assigment of value for T1MS in the USBHS_INTENCLR register */
#define USBHS_INTENCLR_PHYRDY_Pos             _UINT32_(5)                                          /* (USBHS_INTENCLR) Clear PHYRDY Interrupt Enable Position */
#define USBHS_INTENCLR_PHYRDY_Msk             (_UINT32_(0x1) << USBHS_INTENCLR_PHYRDY_Pos)         /* (USBHS_INTENCLR) Clear PHYRDY Interrupt Enable Mask */
#define USBHS_INTENCLR_PHYRDY(value)          (USBHS_INTENCLR_PHYRDY_Msk & (_UINT32_(value) << USBHS_INTENCLR_PHYRDY_Pos)) /* Assigment of value for PHYRDY in the USBHS_INTENCLR register */
#define USBHS_INTENCLR_Msk                    _UINT32_(0x0000003F)                                 /* (USBHS_INTENCLR) Register Mask  */


/* -------- USBHS_INTENSET : (USBHS Offset: 0x10) (R/W 32) USBHS Interrupt Enable Clear Register -------- */
#define USBHS_INTENSET_RESETVALUE             _UINT32_(0x00)                                       /*  (USBHS_INTENSET) USBHS Interrupt Enable Clear Register  Reset Value */

#define USBHS_INTENSET_WAKEUP_Pos             _UINT32_(0)                                          /* (USBHS_INTENSET) USCORE Detaction Interrupt Enable Position */
#define USBHS_INTENSET_WAKEUP_Msk             (_UINT32_(0x1) << USBHS_INTENSET_WAKEUP_Pos)         /* (USBHS_INTENSET) USCORE Detaction Interrupt Enable Mask */
#define USBHS_INTENSET_WAKEUP(value)          (USBHS_INTENSET_WAKEUP_Msk & (_UINT32_(value) << USBHS_INTENSET_WAKEUP_Pos)) /* Assigment of value for WAKEUP in the USBHS_INTENSET register */
#define USBHS_INTENSET_RESUME_Pos             _UINT32_(1)                                          /* (USBHS_INTENSET) Resume Interrupt Enable Position */
#define USBHS_INTENSET_RESUME_Msk             (_UINT32_(0x1) << USBHS_INTENSET_RESUME_Pos)         /* (USBHS_INTENSET) Resume Interrupt Enable Mask */
#define USBHS_INTENSET_RESUME(value)          (USBHS_INTENSET_RESUME_Msk & (_UINT32_(value) << USBHS_INTENSET_RESUME_Pos)) /* Assigment of value for RESUME in the USBHS_INTENSET register */
#define USBHS_INTENSET_USB_Pos                _UINT32_(2)                                          /* (USBHS_INTENSET) USBCORE General Interrupt Enable Position */
#define USBHS_INTENSET_USB_Msk                (_UINT32_(0x1) << USBHS_INTENSET_USB_Pos)            /* (USBHS_INTENSET) USBCORE General Interrupt Enable Mask */
#define USBHS_INTENSET_USB(value)             (USBHS_INTENSET_USB_Msk & (_UINT32_(value) << USBHS_INTENSET_USB_Pos)) /* Assigment of value for USB in the USBHS_INTENSET register */
#define USBHS_INTENSET_DMA_Pos                _UINT32_(3)                                          /* (USBHS_INTENSET) DMA Interrupt Enable Position */
#define USBHS_INTENSET_DMA_Msk                (_UINT32_(0x1) << USBHS_INTENSET_DMA_Pos)            /* (USBHS_INTENSET) DMA Interrupt Enable Mask */
#define USBHS_INTENSET_DMA(value)             (USBHS_INTENSET_DMA_Msk & (_UINT32_(value) << USBHS_INTENSET_DMA_Pos)) /* Assigment of value for DMA in the USBHS_INTENSET register */
#define USBHS_INTENSET_T1MS_Pos               _UINT32_(4)                                          /* (USBHS_INTENSET) T1MS Interrupt Enable Position */
#define USBHS_INTENSET_T1MS_Msk               (_UINT32_(0x1) << USBHS_INTENSET_T1MS_Pos)           /* (USBHS_INTENSET) T1MS Interrupt Enable Mask */
#define USBHS_INTENSET_T1MS(value)            (USBHS_INTENSET_T1MS_Msk & (_UINT32_(value) << USBHS_INTENSET_T1MS_Pos)) /* Assigment of value for T1MS in the USBHS_INTENSET register */
#define USBHS_INTENSET_PHYRDY_Pos             _UINT32_(5)                                          /* (USBHS_INTENSET) PHYRDY Interrupt Enable Position */
#define USBHS_INTENSET_PHYRDY_Msk             (_UINT32_(0x1) << USBHS_INTENSET_PHYRDY_Pos)         /* (USBHS_INTENSET) PHYRDY Interrupt Enable Mask */
#define USBHS_INTENSET_PHYRDY(value)          (USBHS_INTENSET_PHYRDY_Msk & (_UINT32_(value) << USBHS_INTENSET_PHYRDY_Pos)) /* Assigment of value for PHYRDY in the USBHS_INTENSET register */
#define USBHS_INTENSET_Msk                    _UINT32_(0x0000003F)                                 /* (USBHS_INTENSET) Register Mask  */


/* -------- USBHS_INTFLAG : (USBHS Offset: 0x14) (R/W 32) USBHS Interrupt Flag Register -------- */
#define USBHS_INTFLAG_RESETVALUE              _UINT32_(0x00)                                       /*  (USBHS_INTFLAG) USBHS Interrupt Flag Register  Reset Value */

#define USBHS_INTFLAG_WAKEUP_Pos              _UINT32_(0)                                          /* (USBHS_INTFLAG) USB Activity Detection Interrupt Position */
#define USBHS_INTFLAG_WAKEUP_Msk              (_UINT32_(0x1) << USBHS_INTFLAG_WAKEUP_Pos)          /* (USBHS_INTFLAG) USB Activity Detection Interrupt Mask */
#define USBHS_INTFLAG_WAKEUP(value)           (USBHS_INTFLAG_WAKEUP_Msk & (_UINT32_(value) << USBHS_INTFLAG_WAKEUP_Pos)) /* Assigment of value for WAKEUP in the USBHS_INTFLAG register */
#define USBHS_INTFLAG_RESUME_Pos              _UINT32_(1)                                          /* (USBHS_INTFLAG) Resume Interrupt Position */
#define USBHS_INTFLAG_RESUME_Msk              (_UINT32_(0x1) << USBHS_INTFLAG_RESUME_Pos)          /* (USBHS_INTFLAG) Resume Interrupt Mask */
#define USBHS_INTFLAG_RESUME(value)           (USBHS_INTFLAG_RESUME_Msk & (_UINT32_(value) << USBHS_INTFLAG_RESUME_Pos)) /* Assigment of value for RESUME in the USBHS_INTFLAG register */
#define USBHS_INTFLAG_USB_Pos                 _UINT32_(2)                                          /* (USBHS_INTFLAG) USBCORE General Interrupt Position */
#define USBHS_INTFLAG_USB_Msk                 (_UINT32_(0x1) << USBHS_INTFLAG_USB_Pos)             /* (USBHS_INTFLAG) USBCORE General Interrupt Mask */
#define USBHS_INTFLAG_USB(value)              (USBHS_INTFLAG_USB_Msk & (_UINT32_(value) << USBHS_INTFLAG_USB_Pos)) /* Assigment of value for USB in the USBHS_INTFLAG register */
#define USBHS_INTFLAG_DMA_Pos                 _UINT32_(3)                                          /* (USBHS_INTFLAG) DMA Interrupt Position */
#define USBHS_INTFLAG_DMA_Msk                 (_UINT32_(0x1) << USBHS_INTFLAG_DMA_Pos)             /* (USBHS_INTFLAG) DMA Interrupt Mask */
#define USBHS_INTFLAG_DMA(value)              (USBHS_INTFLAG_DMA_Msk & (_UINT32_(value) << USBHS_INTFLAG_DMA_Pos)) /* Assigment of value for DMA in the USBHS_INTFLAG register */
#define USBHS_INTFLAG_T1MS_Pos                _UINT32_(4)                                          /* (USBHS_INTFLAG) Timer 1ms Tick Interrupt Position */
#define USBHS_INTFLAG_T1MS_Msk                (_UINT32_(0x1) << USBHS_INTFLAG_T1MS_Pos)            /* (USBHS_INTFLAG) Timer 1ms Tick Interrupt Mask */
#define USBHS_INTFLAG_T1MS(value)             (USBHS_INTFLAG_T1MS_Msk & (_UINT32_(value) << USBHS_INTFLAG_T1MS_Pos)) /* Assigment of value for T1MS in the USBHS_INTFLAG register */
#define USBHS_INTFLAG_PHYRDY_Pos              _UINT32_(5)                                          /* (USBHS_INTFLAG) PHY Ready Interrupt Position */
#define USBHS_INTFLAG_PHYRDY_Msk              (_UINT32_(0x1) << USBHS_INTFLAG_PHYRDY_Pos)          /* (USBHS_INTFLAG) PHY Ready Interrupt Mask */
#define USBHS_INTFLAG_PHYRDY(value)           (USBHS_INTFLAG_PHYRDY_Msk & (_UINT32_(value) << USBHS_INTFLAG_PHYRDY_Pos)) /* Assigment of value for PHYRDY in the USBHS_INTFLAG register */
#define USBHS_INTFLAG_Msk                     _UINT32_(0x0000003F)                                 /* (USBHS_INTFLAG) Register Mask  */


/* -------- USBHS_STATUS : (USBHS Offset: 0x18) ( R/ 32) USBHS Status Register -------- */
#define USBHS_STATUS_RESETVALUE               _UINT32_(0x00)                                       /*  (USBHS_STATUS) USBHS Status Register  Reset Value */

#define USBHS_STATUS_PHYRDY_Pos               _UINT32_(0)                                          /* (USBHS_STATUS) PHY Is Ready for USBCORE Activity Position */
#define USBHS_STATUS_PHYRDY_Msk               (_UINT32_(0x1) << USBHS_STATUS_PHYRDY_Pos)           /* (USBHS_STATUS) PHY Is Ready for USBCORE Activity Mask */
#define USBHS_STATUS_PHYRDY(value)            (USBHS_STATUS_PHYRDY_Msk & (_UINT32_(value) << USBHS_STATUS_PHYRDY_Pos)) /* Assigment of value for PHYRDY in the USBHS_STATUS register */
#define USBHS_STATUS_PHYON_Pos                _UINT32_(1)                                          /* (USBHS_STATUS) Power On of PHY Complete Position */
#define USBHS_STATUS_PHYON_Msk                (_UINT32_(0x1) << USBHS_STATUS_PHYON_Pos)            /* (USBHS_STATUS) Power On of PHY Complete Mask */
#define USBHS_STATUS_PHYON(value)             (USBHS_STATUS_PHYON_Msk & (_UINT32_(value) << USBHS_STATUS_PHYON_Pos)) /* Assigment of value for PHYON in the USBHS_STATUS register */
#define USBHS_STATUS_VREGRDY_Pos              _UINT32_(2)                                          /* (USBHS_STATUS) USB Voltage Regulator Status Position */
#define USBHS_STATUS_VREGRDY_Msk              (_UINT32_(0x1) << USBHS_STATUS_VREGRDY_Pos)          /* (USBHS_STATUS) USB Voltage Regulator Status Mask */
#define USBHS_STATUS_VREGRDY(value)           (USBHS_STATUS_VREGRDY_Msk & (_UINT32_(value) << USBHS_STATUS_VREGRDY_Pos)) /* Assigment of value for VREGRDY in the USBHS_STATUS register */
#define USBHS_STATUS_Msk                      _UINT32_(0x00000007)                                 /* (USBHS_STATUS) Register Mask  */


/* -------- USBHS_SYNCBUSY : (USBHS Offset: 0x1C) ( R/ 32) USBHS Syncbusy Register -------- */
#define USBHS_SYNCBUSY_RESETVALUE             _UINT32_(0x00)                                       /*  (USBHS_SYNCBUSY) USBHS Syncbusy Register  Reset Value */

#define USBHS_SYNCBUSY_SWRST_Pos              _UINT32_(0)                                          /* (USBHS_SYNCBUSY) Software reset busy bit Position */
#define USBHS_SYNCBUSY_SWRST_Msk              (_UINT32_(0x1) << USBHS_SYNCBUSY_SWRST_Pos)          /* (USBHS_SYNCBUSY) Software reset busy bit Mask */
#define USBHS_SYNCBUSY_SWRST(value)           (USBHS_SYNCBUSY_SWRST_Msk & (_UINT32_(value) << USBHS_SYNCBUSY_SWRST_Pos)) /* Assigment of value for SWRST in the USBHS_SYNCBUSY register */
#define USBHS_SYNCBUSY_ENABLE_Pos             _UINT32_(1)                                          /* (USBHS_SYNCBUSY) Enable busy bit Position */
#define USBHS_SYNCBUSY_ENABLE_Msk             (_UINT32_(0x1) << USBHS_SYNCBUSY_ENABLE_Pos)         /* (USBHS_SYNCBUSY) Enable busy bit Mask */
#define USBHS_SYNCBUSY_ENABLE(value)          (USBHS_SYNCBUSY_ENABLE_Msk & (_UINT32_(value) << USBHS_SYNCBUSY_ENABLE_Pos)) /* Assigment of value for ENABLE in the USBHS_SYNCBUSY register */
#define USBHS_SYNCBUSY_T1MSEN_Pos             _UINT32_(2)                                          /* (USBHS_SYNCBUSY) T1MS enable busy bit Position */
#define USBHS_SYNCBUSY_T1MSEN_Msk             (_UINT32_(0x1) << USBHS_SYNCBUSY_T1MSEN_Pos)         /* (USBHS_SYNCBUSY) T1MS enable busy bit Mask */
#define USBHS_SYNCBUSY_T1MSEN(value)          (USBHS_SYNCBUSY_T1MSEN_Msk & (_UINT32_(value) << USBHS_SYNCBUSY_T1MSEN_Pos)) /* Assigment of value for T1MSEN in the USBHS_SYNCBUSY register */
#define USBHS_SYNCBUSY_Msk                    _UINT32_(0x00000007)                                 /* (USBHS_SYNCBUSY) Register Mask  */


/* -------- USBHS_FADDR : (USBHS Offset: 0x1000) (R/W 8) Function Address Register -------- */
#define USBHS_FADDR_RESETVALUE                _UINT8_(0x00)                                        /*  (USBHS_FADDR) Function Address Register  Reset Value */

#define USBHS_FADDR_FUNCADDR_Pos              _UINT8_(0)                                           /* (USBHS_FADDR) Function address Position */
#define USBHS_FADDR_FUNCADDR_Msk              (_UINT8_(0x7F) << USBHS_FADDR_FUNCADDR_Pos)          /* (USBHS_FADDR) Function address Mask */
#define USBHS_FADDR_FUNCADDR(value)           (USBHS_FADDR_FUNCADDR_Msk & (_UINT8_(value) << USBHS_FADDR_FUNCADDR_Pos)) /* Assigment of value for FUNCADDR in the USBHS_FADDR register */
#define USBHS_FADDR_Msk                       _UINT8_(0x7F)                                        /* (USBHS_FADDR) Register Mask  */


/* -------- USBHS_POWER : (USBHS Offset: 0x1001) (R/W 8) Used For Controlling Suspend And Resume Signaling And Some Basic Operation Of USBCORE -------- */
#define USBHS_POWER_RESETVALUE                _UINT8_(0x20)                                        /*  (USBHS_POWER) Used For Controlling Suspend And Resume Signaling And Some Basic Operation Of USBCORE  Reset Value */

#define USBHS_POWER_ENABLESUSPENDM_Pos        _UINT8_(0)                                           /* (USBHS_POWER) set by the cpu to enable suspendm output Position */
#define USBHS_POWER_ENABLESUSPENDM_Msk        (_UINT8_(0x1) << USBHS_POWER_ENABLESUSPENDM_Pos)     /* (USBHS_POWER) set by the cpu to enable suspendm output Mask */
#define USBHS_POWER_ENABLESUSPENDM(value)     (USBHS_POWER_ENABLESUSPENDM_Msk & (_UINT8_(value) << USBHS_POWER_ENABLESUSPENDM_Pos)) /* Assigment of value for ENABLESUSPENDM in the USBHS_POWER register */
#define USBHS_POWER_SUSPENDMODE_Pos           _UINT8_(1)                                           /* (USBHS_POWER) set by cpu to enter suspend mode Position */
#define USBHS_POWER_SUSPENDMODE_Msk           (_UINT8_(0x1) << USBHS_POWER_SUSPENDMODE_Pos)        /* (USBHS_POWER) set by cpu to enter suspend mode Mask */
#define USBHS_POWER_SUSPENDMODE(value)        (USBHS_POWER_SUSPENDMODE_Msk & (_UINT8_(value) << USBHS_POWER_SUSPENDMODE_Pos)) /* Assigment of value for SUSPENDMODE in the USBHS_POWER register */
#define USBHS_POWER_RESUME_Pos                _UINT8_(2)                                           /* (USBHS_POWER) set by cpu to generate resume signaling when te device is in suspend Position */
#define USBHS_POWER_RESUME_Msk                (_UINT8_(0x1) << USBHS_POWER_RESUME_Pos)             /* (USBHS_POWER) set by cpu to generate resume signaling when te device is in suspend Mask */
#define USBHS_POWER_RESUME(value)             (USBHS_POWER_RESUME_Msk & (_UINT8_(value) << USBHS_POWER_RESUME_Pos)) /* Assigment of value for RESUME in the USBHS_POWER register */
#define USBHS_POWER_RESET_Pos                 _UINT8_(3)                                           /* (USBHS_POWER) this bit is set when reset signaling is present on the bus Position */
#define USBHS_POWER_RESET_Msk                 (_UINT8_(0x1) << USBHS_POWER_RESET_Pos)              /* (USBHS_POWER) this bit is set when reset signaling is present on the bus Mask */
#define USBHS_POWER_RESET(value)              (USBHS_POWER_RESET_Msk & (_UINT8_(value) << USBHS_POWER_RESET_Pos)) /* Assigment of value for RESET in the USBHS_POWER register */
#define USBHS_POWER_HSMODE_Pos                _UINT8_(4)                                           /* (USBHS_POWER) when set this read only bit indicates high speed mode successfully negotiated during usb reset Position */
#define USBHS_POWER_HSMODE_Msk                (_UINT8_(0x1) << USBHS_POWER_HSMODE_Pos)             /* (USBHS_POWER) when set this read only bit indicates high speed mode successfully negotiated during usb reset Mask */
#define USBHS_POWER_HSMODE(value)             (USBHS_POWER_HSMODE_Msk & (_UINT8_(value) << USBHS_POWER_HSMODE_Pos)) /* Assigment of value for HSMODE in the USBHS_POWER register */
#define USBHS_POWER_HSENABLE_Pos              _UINT8_(5)                                           /* (USBHS_POWER) when set by cpu the usbcore will negotiate the high speed mode Position */
#define USBHS_POWER_HSENABLE_Msk              (_UINT8_(0x1) << USBHS_POWER_HSENABLE_Pos)           /* (USBHS_POWER) when set by cpu the usbcore will negotiate the high speed mode Mask */
#define USBHS_POWER_HSENABLE(value)           (USBHS_POWER_HSENABLE_Msk & (_UINT8_(value) << USBHS_POWER_HSENABLE_Pos)) /* Assigment of value for HSENABLE in the USBHS_POWER register */
#define USBHS_POWER_SOFTCONN_Pos              _UINT8_(6)                                           /* (USBHS_POWER) if enabled the D+ D- lines are enabled when this bit is set by the cpu Position */
#define USBHS_POWER_SOFTCONN_Msk              (_UINT8_(0x1) << USBHS_POWER_SOFTCONN_Pos)           /* (USBHS_POWER) if enabled the D+ D- lines are enabled when this bit is set by the cpu Mask */
#define USBHS_POWER_SOFTCONN(value)           (USBHS_POWER_SOFTCONN_Msk & (_UINT8_(value) << USBHS_POWER_SOFTCONN_Pos)) /* Assigment of value for SOFTCONN in the USBHS_POWER register */
#define USBHS_POWER_ISOUPDATE_Pos             _UINT8_(7)                                           /* (USBHS_POWER) when set by cpu the usbcore will wait for an sof token Position */
#define USBHS_POWER_ISOUPDATE_Msk             (_UINT8_(0x1) << USBHS_POWER_ISOUPDATE_Pos)          /* (USBHS_POWER) when set by cpu the usbcore will wait for an sof token Mask */
#define USBHS_POWER_ISOUPDATE(value)          (USBHS_POWER_ISOUPDATE_Msk & (_UINT8_(value) << USBHS_POWER_ISOUPDATE_Pos)) /* Assigment of value for ISOUPDATE in the USBHS_POWER register */
#define USBHS_POWER_Msk                       _UINT8_(0xFF)                                        /* (USBHS_POWER) Register Mask  */


/* -------- USBHS_INTRTX : (USBHS Offset: 0x1002) ( R/ 16) Read Only Register Which Indicates Which Interrupts Are Currently Active For EP0 And TX EP1-15 -------- */
#define USBHS_INTRTX_RESETVALUE               _UINT16_(0x00)                                       /*  (USBHS_INTRTX) Read Only Register Which Indicates Which Interrupts Are Currently Active For EP0 And TX EP1-15  Reset Value */

#define USBHS_INTRTX_EP0TX_Pos                _UINT16_(0)                                          /* (USBHS_INTRTX) Interrupts Active For TX0 Endpoint Position */
#define USBHS_INTRTX_EP0TX_Msk                (_UINT16_(0x1) << USBHS_INTRTX_EP0TX_Pos)            /* (USBHS_INTRTX) Interrupts Active For TX0 Endpoint Mask */
#define USBHS_INTRTX_EP0TX(value)             (USBHS_INTRTX_EP0TX_Msk & (_UINT16_(value) << USBHS_INTRTX_EP0TX_Pos)) /* Assigment of value for EP0TX in the USBHS_INTRTX register */
#define USBHS_INTRTX_EP1TX_Pos                _UINT16_(1)                                          /* (USBHS_INTRTX) Interrupts Active For TX1 Endpoint Position */
#define USBHS_INTRTX_EP1TX_Msk                (_UINT16_(0x1) << USBHS_INTRTX_EP1TX_Pos)            /* (USBHS_INTRTX) Interrupts Active For TX1 Endpoint Mask */
#define USBHS_INTRTX_EP1TX(value)             (USBHS_INTRTX_EP1TX_Msk & (_UINT16_(value) << USBHS_INTRTX_EP1TX_Pos)) /* Assigment of value for EP1TX in the USBHS_INTRTX register */
#define USBHS_INTRTX_EP2TX_Pos                _UINT16_(2)                                          /* (USBHS_INTRTX) Interrupts Active For TX2 Endpoint Position */
#define USBHS_INTRTX_EP2TX_Msk                (_UINT16_(0x1) << USBHS_INTRTX_EP2TX_Pos)            /* (USBHS_INTRTX) Interrupts Active For TX2 Endpoint Mask */
#define USBHS_INTRTX_EP2TX(value)             (USBHS_INTRTX_EP2TX_Msk & (_UINT16_(value) << USBHS_INTRTX_EP2TX_Pos)) /* Assigment of value for EP2TX in the USBHS_INTRTX register */
#define USBHS_INTRTX_EP3TX_Pos                _UINT16_(3)                                          /* (USBHS_INTRTX) Interrupts Active For TX3 Endpoint Position */
#define USBHS_INTRTX_EP3TX_Msk                (_UINT16_(0x1) << USBHS_INTRTX_EP3TX_Pos)            /* (USBHS_INTRTX) Interrupts Active For TX3 Endpoint Mask */
#define USBHS_INTRTX_EP3TX(value)             (USBHS_INTRTX_EP3TX_Msk & (_UINT16_(value) << USBHS_INTRTX_EP3TX_Pos)) /* Assigment of value for EP3TX in the USBHS_INTRTX register */
#define USBHS_INTRTX_EP4TX_Pos                _UINT16_(4)                                          /* (USBHS_INTRTX) Interrupts Active For TX4 Endpoint Position */
#define USBHS_INTRTX_EP4TX_Msk                (_UINT16_(0x1) << USBHS_INTRTX_EP4TX_Pos)            /* (USBHS_INTRTX) Interrupts Active For TX4 Endpoint Mask */
#define USBHS_INTRTX_EP4TX(value)             (USBHS_INTRTX_EP4TX_Msk & (_UINT16_(value) << USBHS_INTRTX_EP4TX_Pos)) /* Assigment of value for EP4TX in the USBHS_INTRTX register */
#define USBHS_INTRTX_EP5TX_Pos                _UINT16_(5)                                          /* (USBHS_INTRTX) Interrupts Active For TX5 Endpoint Position */
#define USBHS_INTRTX_EP5TX_Msk                (_UINT16_(0x1) << USBHS_INTRTX_EP5TX_Pos)            /* (USBHS_INTRTX) Interrupts Active For TX5 Endpoint Mask */
#define USBHS_INTRTX_EP5TX(value)             (USBHS_INTRTX_EP5TX_Msk & (_UINT16_(value) << USBHS_INTRTX_EP5TX_Pos)) /* Assigment of value for EP5TX in the USBHS_INTRTX register */
#define USBHS_INTRTX_EP6TX_Pos                _UINT16_(6)                                          /* (USBHS_INTRTX) Interrupts Active For TX6 Endpoint Position */
#define USBHS_INTRTX_EP6TX_Msk                (_UINT16_(0x1) << USBHS_INTRTX_EP6TX_Pos)            /* (USBHS_INTRTX) Interrupts Active For TX6 Endpoint Mask */
#define USBHS_INTRTX_EP6TX(value)             (USBHS_INTRTX_EP6TX_Msk & (_UINT16_(value) << USBHS_INTRTX_EP6TX_Pos)) /* Assigment of value for EP6TX in the USBHS_INTRTX register */
#define USBHS_INTRTX_EP7TX_Pos                _UINT16_(7)                                          /* (USBHS_INTRTX) Interrupts Active For TX7 Endpoint Position */
#define USBHS_INTRTX_EP7TX_Msk                (_UINT16_(0x1) << USBHS_INTRTX_EP7TX_Pos)            /* (USBHS_INTRTX) Interrupts Active For TX7 Endpoint Mask */
#define USBHS_INTRTX_EP7TX(value)             (USBHS_INTRTX_EP7TX_Msk & (_UINT16_(value) << USBHS_INTRTX_EP7TX_Pos)) /* Assigment of value for EP7TX in the USBHS_INTRTX register */
#define USBHS_INTRTX_Msk                      _UINT16_(0x00FF)                                     /* (USBHS_INTRTX) Register Mask  */


/* -------- USBHS_INTRRX : (USBHS Offset: 0x1004) ( R/ 16) Read Only Register Which Indicates Which Interrupts Are Currently Active For RX EP1-15 -------- */
#define USBHS_INTRRX_RESETVALUE               _UINT16_(0x00)                                       /*  (USBHS_INTRRX) Read Only Register Which Indicates Which Interrupts Are Currently Active For RX EP1-15  Reset Value */

#define USBHS_INTRRX_EP1RX_Pos                _UINT16_(1)                                          /* (USBHS_INTRRX) Interrupts Active For Which RX1 Endpoint Position */
#define USBHS_INTRRX_EP1RX_Msk                (_UINT16_(0x1) << USBHS_INTRRX_EP1RX_Pos)            /* (USBHS_INTRRX) Interrupts Active For Which RX1 Endpoint Mask */
#define USBHS_INTRRX_EP1RX(value)             (USBHS_INTRRX_EP1RX_Msk & (_UINT16_(value) << USBHS_INTRRX_EP1RX_Pos)) /* Assigment of value for EP1RX in the USBHS_INTRRX register */
#define USBHS_INTRRX_EP2RX_Pos                _UINT16_(2)                                          /* (USBHS_INTRRX) Interrupts Active For Which RX2 Endpoint Position */
#define USBHS_INTRRX_EP2RX_Msk                (_UINT16_(0x1) << USBHS_INTRRX_EP2RX_Pos)            /* (USBHS_INTRRX) Interrupts Active For Which RX2 Endpoint Mask */
#define USBHS_INTRRX_EP2RX(value)             (USBHS_INTRRX_EP2RX_Msk & (_UINT16_(value) << USBHS_INTRRX_EP2RX_Pos)) /* Assigment of value for EP2RX in the USBHS_INTRRX register */
#define USBHS_INTRRX_EP3RX_Pos                _UINT16_(3)                                          /* (USBHS_INTRRX) Interrupts Active For Which RX3 Endpoint Position */
#define USBHS_INTRRX_EP3RX_Msk                (_UINT16_(0x1) << USBHS_INTRRX_EP3RX_Pos)            /* (USBHS_INTRRX) Interrupts Active For Which RX3 Endpoint Mask */
#define USBHS_INTRRX_EP3RX(value)             (USBHS_INTRRX_EP3RX_Msk & (_UINT16_(value) << USBHS_INTRRX_EP3RX_Pos)) /* Assigment of value for EP3RX in the USBHS_INTRRX register */
#define USBHS_INTRRX_EP4RX_Pos                _UINT16_(4)                                          /* (USBHS_INTRRX) Interrupts Active For Which RX4 Endpoint Position */
#define USBHS_INTRRX_EP4RX_Msk                (_UINT16_(0x1) << USBHS_INTRRX_EP4RX_Pos)            /* (USBHS_INTRRX) Interrupts Active For Which RX4 Endpoint Mask */
#define USBHS_INTRRX_EP4RX(value)             (USBHS_INTRRX_EP4RX_Msk & (_UINT16_(value) << USBHS_INTRRX_EP4RX_Pos)) /* Assigment of value for EP4RX in the USBHS_INTRRX register */
#define USBHS_INTRRX_EP5RX_Pos                _UINT16_(5)                                          /* (USBHS_INTRRX) Interrupts Active For Which RX5 Endpoint Position */
#define USBHS_INTRRX_EP5RX_Msk                (_UINT16_(0x1) << USBHS_INTRRX_EP5RX_Pos)            /* (USBHS_INTRRX) Interrupts Active For Which RX5 Endpoint Mask */
#define USBHS_INTRRX_EP5RX(value)             (USBHS_INTRRX_EP5RX_Msk & (_UINT16_(value) << USBHS_INTRRX_EP5RX_Pos)) /* Assigment of value for EP5RX in the USBHS_INTRRX register */
#define USBHS_INTRRX_EP6RX_Pos                _UINT16_(6)                                          /* (USBHS_INTRRX) Interrupts Active For Which RX6 Endpoint Position */
#define USBHS_INTRRX_EP6RX_Msk                (_UINT16_(0x1) << USBHS_INTRRX_EP6RX_Pos)            /* (USBHS_INTRRX) Interrupts Active For Which RX6 Endpoint Mask */
#define USBHS_INTRRX_EP6RX(value)             (USBHS_INTRRX_EP6RX_Msk & (_UINT16_(value) << USBHS_INTRRX_EP6RX_Pos)) /* Assigment of value for EP6RX in the USBHS_INTRRX register */
#define USBHS_INTRRX_EP7RX_Pos                _UINT16_(7)                                          /* (USBHS_INTRRX) Interrupts Active For Which RX7 Endpoint Position */
#define USBHS_INTRRX_EP7RX_Msk                (_UINT16_(0x1) << USBHS_INTRRX_EP7RX_Pos)            /* (USBHS_INTRRX) Interrupts Active For Which RX7 Endpoint Mask */
#define USBHS_INTRRX_EP7RX(value)             (USBHS_INTRRX_EP7RX_Msk & (_UINT16_(value) << USBHS_INTRRX_EP7RX_Pos)) /* Assigment of value for EP7RX in the USBHS_INTRRX register */
#define USBHS_INTRRX_Msk                      _UINT16_(0x00FE)                                     /* (USBHS_INTRRX) Register Mask  */


/* -------- USBHS_INTRTXE : (USBHS Offset: 0x1006) (R/W 16) Interrupt Enable Bits for INTRTX -------- */
#define USBHS_INTRTXE_RESETVALUE              _UINT16_(0xFFFF)                                     /*  (USBHS_INTRTXE) Interrupt Enable Bits for INTRTX  Reset Value */

#define USBHS_INTRTXE_EP0TXEN_Pos             _UINT16_(0)                                          /* (USBHS_INTRTXE) Interrupt Enabled for TX EP0 Position */
#define USBHS_INTRTXE_EP0TXEN_Msk             (_UINT16_(0x1) << USBHS_INTRTXE_EP0TXEN_Pos)         /* (USBHS_INTRTXE) Interrupt Enabled for TX EP0 Mask */
#define USBHS_INTRTXE_EP0TXEN(value)          (USBHS_INTRTXE_EP0TXEN_Msk & (_UINT16_(value) << USBHS_INTRTXE_EP0TXEN_Pos)) /* Assigment of value for EP0TXEN in the USBHS_INTRTXE register */
#define USBHS_INTRTXE_EP1TXEN_Pos             _UINT16_(1)                                          /* (USBHS_INTRTXE) Interrupt Enabled for TX EP1 Position */
#define USBHS_INTRTXE_EP1TXEN_Msk             (_UINT16_(0x1) << USBHS_INTRTXE_EP1TXEN_Pos)         /* (USBHS_INTRTXE) Interrupt Enabled for TX EP1 Mask */
#define USBHS_INTRTXE_EP1TXEN(value)          (USBHS_INTRTXE_EP1TXEN_Msk & (_UINT16_(value) << USBHS_INTRTXE_EP1TXEN_Pos)) /* Assigment of value for EP1TXEN in the USBHS_INTRTXE register */
#define USBHS_INTRTXE_EP2TXEN_Pos             _UINT16_(2)                                          /* (USBHS_INTRTXE) Interrupt Enabled for TX EP2 Position */
#define USBHS_INTRTXE_EP2TXEN_Msk             (_UINT16_(0x1) << USBHS_INTRTXE_EP2TXEN_Pos)         /* (USBHS_INTRTXE) Interrupt Enabled for TX EP2 Mask */
#define USBHS_INTRTXE_EP2TXEN(value)          (USBHS_INTRTXE_EP2TXEN_Msk & (_UINT16_(value) << USBHS_INTRTXE_EP2TXEN_Pos)) /* Assigment of value for EP2TXEN in the USBHS_INTRTXE register */
#define USBHS_INTRTXE_EP3TXEN_Pos             _UINT16_(3)                                          /* (USBHS_INTRTXE) Interrupt Enabled for TX EP3 Position */
#define USBHS_INTRTXE_EP3TXEN_Msk             (_UINT16_(0x1) << USBHS_INTRTXE_EP3TXEN_Pos)         /* (USBHS_INTRTXE) Interrupt Enabled for TX EP3 Mask */
#define USBHS_INTRTXE_EP3TXEN(value)          (USBHS_INTRTXE_EP3TXEN_Msk & (_UINT16_(value) << USBHS_INTRTXE_EP3TXEN_Pos)) /* Assigment of value for EP3TXEN in the USBHS_INTRTXE register */
#define USBHS_INTRTXE_EP4TXEN_Pos             _UINT16_(4)                                          /* (USBHS_INTRTXE) Interrupt Enabled for TX EP4 Position */
#define USBHS_INTRTXE_EP4TXEN_Msk             (_UINT16_(0x1) << USBHS_INTRTXE_EP4TXEN_Pos)         /* (USBHS_INTRTXE) Interrupt Enabled for TX EP4 Mask */
#define USBHS_INTRTXE_EP4TXEN(value)          (USBHS_INTRTXE_EP4TXEN_Msk & (_UINT16_(value) << USBHS_INTRTXE_EP4TXEN_Pos)) /* Assigment of value for EP4TXEN in the USBHS_INTRTXE register */
#define USBHS_INTRTXE_EP5TXEN_Pos             _UINT16_(5)                                          /* (USBHS_INTRTXE) Interrupt Enabled for TX EP5 Position */
#define USBHS_INTRTXE_EP5TXEN_Msk             (_UINT16_(0x1) << USBHS_INTRTXE_EP5TXEN_Pos)         /* (USBHS_INTRTXE) Interrupt Enabled for TX EP5 Mask */
#define USBHS_INTRTXE_EP5TXEN(value)          (USBHS_INTRTXE_EP5TXEN_Msk & (_UINT16_(value) << USBHS_INTRTXE_EP5TXEN_Pos)) /* Assigment of value for EP5TXEN in the USBHS_INTRTXE register */
#define USBHS_INTRTXE_EP6TXEN_Pos             _UINT16_(6)                                          /* (USBHS_INTRTXE) Interrupt Enabled for TX EP6 Position */
#define USBHS_INTRTXE_EP6TXEN_Msk             (_UINT16_(0x1) << USBHS_INTRTXE_EP6TXEN_Pos)         /* (USBHS_INTRTXE) Interrupt Enabled for TX EP6 Mask */
#define USBHS_INTRTXE_EP6TXEN(value)          (USBHS_INTRTXE_EP6TXEN_Msk & (_UINT16_(value) << USBHS_INTRTXE_EP6TXEN_Pos)) /* Assigment of value for EP6TXEN in the USBHS_INTRTXE register */
#define USBHS_INTRTXE_EP7TXEN_Pos             _UINT16_(7)                                          /* (USBHS_INTRTXE) Interrupt Enabled for TX EP7 Position */
#define USBHS_INTRTXE_EP7TXEN_Msk             (_UINT16_(0x1) << USBHS_INTRTXE_EP7TXEN_Pos)         /* (USBHS_INTRTXE) Interrupt Enabled for TX EP7 Mask */
#define USBHS_INTRTXE_EP7TXEN(value)          (USBHS_INTRTXE_EP7TXEN_Msk & (_UINT16_(value) << USBHS_INTRTXE_EP7TXEN_Pos)) /* Assigment of value for EP7TXEN in the USBHS_INTRTXE register */
#define USBHS_INTRTXE_Msk                     _UINT16_(0x00FF)                                     /* (USBHS_INTRTXE) Register Mask  */


/* -------- USBHS_INTRRXE : (USBHS Offset: 0x1008) (R/W 16) Interrupt Enable Bits for INTRRX -------- */
#define USBHS_INTRRXE_RESETVALUE              _UINT16_(0xFFFE)                                     /*  (USBHS_INTRRXE) Interrupt Enable Bits for INTRRX  Reset Value */

#define USBHS_INTRRXE_EP1RXE_Pos              _UINT16_(1)                                          /* (USBHS_INTRRXE) Interrupt Enabled for RX EP1 Position */
#define USBHS_INTRRXE_EP1RXE_Msk              (_UINT16_(0x1) << USBHS_INTRRXE_EP1RXE_Pos)          /* (USBHS_INTRRXE) Interrupt Enabled for RX EP1 Mask */
#define USBHS_INTRRXE_EP1RXE(value)           (USBHS_INTRRXE_EP1RXE_Msk & (_UINT16_(value) << USBHS_INTRRXE_EP1RXE_Pos)) /* Assigment of value for EP1RXE in the USBHS_INTRRXE register */
#define USBHS_INTRRXE_EP2RXE_Pos              _UINT16_(2)                                          /* (USBHS_INTRRXE) Interrupt Enabled for RX EP2 Position */
#define USBHS_INTRRXE_EP2RXE_Msk              (_UINT16_(0x1) << USBHS_INTRRXE_EP2RXE_Pos)          /* (USBHS_INTRRXE) Interrupt Enabled for RX EP2 Mask */
#define USBHS_INTRRXE_EP2RXE(value)           (USBHS_INTRRXE_EP2RXE_Msk & (_UINT16_(value) << USBHS_INTRRXE_EP2RXE_Pos)) /* Assigment of value for EP2RXE in the USBHS_INTRRXE register */
#define USBHS_INTRRXE_EP3RXE_Pos              _UINT16_(3)                                          /* (USBHS_INTRRXE) Interrupt Enabled for RX EP3 Position */
#define USBHS_INTRRXE_EP3RXE_Msk              (_UINT16_(0x1) << USBHS_INTRRXE_EP3RXE_Pos)          /* (USBHS_INTRRXE) Interrupt Enabled for RX EP3 Mask */
#define USBHS_INTRRXE_EP3RXE(value)           (USBHS_INTRRXE_EP3RXE_Msk & (_UINT16_(value) << USBHS_INTRRXE_EP3RXE_Pos)) /* Assigment of value for EP3RXE in the USBHS_INTRRXE register */
#define USBHS_INTRRXE_EP4RXE_Pos              _UINT16_(4)                                          /* (USBHS_INTRRXE) Interrupt Enabled for RX EP4 Position */
#define USBHS_INTRRXE_EP4RXE_Msk              (_UINT16_(0x1) << USBHS_INTRRXE_EP4RXE_Pos)          /* (USBHS_INTRRXE) Interrupt Enabled for RX EP4 Mask */
#define USBHS_INTRRXE_EP4RXE(value)           (USBHS_INTRRXE_EP4RXE_Msk & (_UINT16_(value) << USBHS_INTRRXE_EP4RXE_Pos)) /* Assigment of value for EP4RXE in the USBHS_INTRRXE register */
#define USBHS_INTRRXE_EP5RXE_Pos              _UINT16_(5)                                          /* (USBHS_INTRRXE) Interrupt Enabled for RX EP5 Position */
#define USBHS_INTRRXE_EP5RXE_Msk              (_UINT16_(0x1) << USBHS_INTRRXE_EP5RXE_Pos)          /* (USBHS_INTRRXE) Interrupt Enabled for RX EP5 Mask */
#define USBHS_INTRRXE_EP5RXE(value)           (USBHS_INTRRXE_EP5RXE_Msk & (_UINT16_(value) << USBHS_INTRRXE_EP5RXE_Pos)) /* Assigment of value for EP5RXE in the USBHS_INTRRXE register */
#define USBHS_INTRRXE_EP6RXE_Pos              _UINT16_(6)                                          /* (USBHS_INTRRXE) Interrupt Enabled for RX EP6 Position */
#define USBHS_INTRRXE_EP6RXE_Msk              (_UINT16_(0x1) << USBHS_INTRRXE_EP6RXE_Pos)          /* (USBHS_INTRRXE) Interrupt Enabled for RX EP6 Mask */
#define USBHS_INTRRXE_EP6RXE(value)           (USBHS_INTRRXE_EP6RXE_Msk & (_UINT16_(value) << USBHS_INTRRXE_EP6RXE_Pos)) /* Assigment of value for EP6RXE in the USBHS_INTRRXE register */
#define USBHS_INTRRXE_EP7RXE_Pos              _UINT16_(7)                                          /* (USBHS_INTRRXE) Interrupt Enabled for RX EP7 Position */
#define USBHS_INTRRXE_EP7RXE_Msk              (_UINT16_(0x1) << USBHS_INTRRXE_EP7RXE_Pos)          /* (USBHS_INTRRXE) Interrupt Enabled for RX EP7 Mask */
#define USBHS_INTRRXE_EP7RXE(value)           (USBHS_INTRRXE_EP7RXE_Msk & (_UINT16_(value) << USBHS_INTRRXE_EP7RXE_Pos)) /* Assigment of value for EP7RXE in the USBHS_INTRRXE register */
#define USBHS_INTRRXE_Msk                     _UINT16_(0x00FE)                                     /* (USBHS_INTRRXE) Register Mask  */


/* -------- USBHS_INTRUSB : (USBHS Offset: 0x100A) ( R/ 8) Read Only Register Which Indicates Which USB Interrupts Are Currently Active. -------- */
#define USBHS_INTRUSB_RESETVALUE              _UINT8_(0x00)                                        /*  (USBHS_INTRUSB) Read Only Register Which Indicates Which USB Interrupts Are Currently Active.  Reset Value */

#define USBHS_INTRUSB_SUSPEND_Pos             _UINT8_(0)                                           /* (USBHS_INTRUSB) Set When Suspend Signal Is Detected On The Bus Position */
#define USBHS_INTRUSB_SUSPEND_Msk             (_UINT8_(0x1) << USBHS_INTRUSB_SUSPEND_Pos)          /* (USBHS_INTRUSB) Set When Suspend Signal Is Detected On The Bus Mask */
#define USBHS_INTRUSB_SUSPEND(value)          (USBHS_INTRUSB_SUSPEND_Msk & (_UINT8_(value) << USBHS_INTRUSB_SUSPEND_Pos)) /* Assigment of value for SUSPEND in the USBHS_INTRUSB register */
#define USBHS_INTRUSB_RESUME_Pos              _UINT8_(1)                                           /* (USBHS_INTRUSB) Set When Resume Signal Is Detected On The Bus Position */
#define USBHS_INTRUSB_RESUME_Msk              (_UINT8_(0x1) << USBHS_INTRUSB_RESUME_Pos)           /* (USBHS_INTRUSB) Set When Resume Signal Is Detected On The Bus Mask */
#define USBHS_INTRUSB_RESUME(value)           (USBHS_INTRUSB_RESUME_Msk & (_UINT8_(value) << USBHS_INTRUSB_RESUME_Pos)) /* Assigment of value for RESUME in the USBHS_INTRUSB register */
#define USBHS_INTRUSB_RESET_Pos               _UINT8_(2)                                           /* (USBHS_INTRUSB) Set In Peripheral Mode when Reset Is Detected On The Bus. In HostMode When Babble Is Detected Position */
#define USBHS_INTRUSB_RESET_Msk               (_UINT8_(0x1) << USBHS_INTRUSB_RESET_Pos)            /* (USBHS_INTRUSB) Set In Peripheral Mode when Reset Is Detected On The Bus. In HostMode When Babble Is Detected Mask */
#define USBHS_INTRUSB_RESET(value)            (USBHS_INTRUSB_RESET_Msk & (_UINT8_(value) << USBHS_INTRUSB_RESET_Pos)) /* Assigment of value for RESET in the USBHS_INTRUSB register */
#define USBHS_INTRUSB_SOF_Pos                 _UINT8_(3)                                           /* (USBHS_INTRUSB) Set When A New Frame Starts Position */
#define USBHS_INTRUSB_SOF_Msk                 (_UINT8_(0x1) << USBHS_INTRUSB_SOF_Pos)              /* (USBHS_INTRUSB) Set When A New Frame Starts Mask */
#define USBHS_INTRUSB_SOF(value)              (USBHS_INTRUSB_SOF_Msk & (_UINT8_(value) << USBHS_INTRUSB_SOF_Pos)) /* Assigment of value for SOF in the USBHS_INTRUSB register */
#define USBHS_INTRUSB_CONN_Pos                _UINT8_(4)                                           /* (USBHS_INTRUSB) Set When A Device Connection Is Detected Position */
#define USBHS_INTRUSB_CONN_Msk                (_UINT8_(0x1) << USBHS_INTRUSB_CONN_Pos)             /* (USBHS_INTRUSB) Set When A Device Connection Is Detected Mask */
#define USBHS_INTRUSB_CONN(value)             (USBHS_INTRUSB_CONN_Msk & (_UINT8_(value) << USBHS_INTRUSB_CONN_Pos)) /* Assigment of value for CONN in the USBHS_INTRUSB register */
#define USBHS_INTRUSB_DISCON_Pos              _UINT8_(5)                                           /* (USBHS_INTRUSB) Set In Host Mode When A Device Disconnect Is Detected.Set In Peripheral Mode When A Session Ends Position */
#define USBHS_INTRUSB_DISCON_Msk              (_UINT8_(0x1) << USBHS_INTRUSB_DISCON_Pos)           /* (USBHS_INTRUSB) Set In Host Mode When A Device Disconnect Is Detected.Set In Peripheral Mode When A Session Ends Mask */
#define USBHS_INTRUSB_DISCON(value)           (USBHS_INTRUSB_DISCON_Msk & (_UINT8_(value) << USBHS_INTRUSB_DISCON_Pos)) /* Assigment of value for DISCON in the USBHS_INTRUSB register */
#define USBHS_INTRUSB_SESSREQ_Pos             _UINT8_(6)                                           /* (USBHS_INTRUSB) Set When Session Request Signaling Has Been Detected. Position */
#define USBHS_INTRUSB_SESSREQ_Msk             (_UINT8_(0x1) << USBHS_INTRUSB_SESSREQ_Pos)          /* (USBHS_INTRUSB) Set When Session Request Signaling Has Been Detected. Mask */
#define USBHS_INTRUSB_SESSREQ(value)          (USBHS_INTRUSB_SESSREQ_Msk & (_UINT8_(value) << USBHS_INTRUSB_SESSREQ_Pos)) /* Assigment of value for SESSREQ in the USBHS_INTRUSB register */
#define USBHS_INTRUSB_VBUSERR_Pos             _UINT8_(7)                                           /* (USBHS_INTRUSB) Set When VBus Drops Below The VBus Valid Threshold During A Session. Position */
#define USBHS_INTRUSB_VBUSERR_Msk             (_UINT8_(0x1) << USBHS_INTRUSB_VBUSERR_Pos)          /* (USBHS_INTRUSB) Set When VBus Drops Below The VBus Valid Threshold During A Session. Mask */
#define USBHS_INTRUSB_VBUSERR(value)          (USBHS_INTRUSB_VBUSERR_Msk & (_UINT8_(value) << USBHS_INTRUSB_VBUSERR_Pos)) /* Assigment of value for VBUSERR in the USBHS_INTRUSB register */
#define USBHS_INTRUSB_Msk                     _UINT8_(0xFF)                                        /* (USBHS_INTRUSB) Register Mask  */


/* -------- USBHS_INTRUSBE : (USBHS Offset: 0x100B) (R/W 8) Interrupt Enable Bits for USB Interrupts -------- */
#define USBHS_INTRUSBE_RESETVALUE             _UINT8_(0x06)                                        /*  (USBHS_INTRUSBE) Interrupt Enable Bits for USB Interrupts  Reset Value */

#define USBHS_INTRUSBE_SUSPENDEN_Pos          _UINT8_(0)                                           /* (USBHS_INTRUSBE) SUSEPND Interrupt Enable Position */
#define USBHS_INTRUSBE_SUSPENDEN_Msk          (_UINT8_(0x1) << USBHS_INTRUSBE_SUSPENDEN_Pos)       /* (USBHS_INTRUSBE) SUSEPND Interrupt Enable Mask */
#define USBHS_INTRUSBE_SUSPENDEN(value)       (USBHS_INTRUSBE_SUSPENDEN_Msk & (_UINT8_(value) << USBHS_INTRUSBE_SUSPENDEN_Pos)) /* Assigment of value for SUSPENDEN in the USBHS_INTRUSBE register */
#define USBHS_INTRUSBE_RESUMEEN_Pos           _UINT8_(1)                                           /* (USBHS_INTRUSBE) RESUME Interrupt Enable Position */
#define USBHS_INTRUSBE_RESUMEEN_Msk           (_UINT8_(0x1) << USBHS_INTRUSBE_RESUMEEN_Pos)        /* (USBHS_INTRUSBE) RESUME Interrupt Enable Mask */
#define USBHS_INTRUSBE_RESUMEEN(value)        (USBHS_INTRUSBE_RESUMEEN_Msk & (_UINT8_(value) << USBHS_INTRUSBE_RESUMEEN_Pos)) /* Assigment of value for RESUMEEN in the USBHS_INTRUSBE register */
#define USBHS_INTRUSBE_RESETEN_Pos            _UINT8_(2)                                           /* (USBHS_INTRUSBE) RESET/BABBLE Interrupt Enable Position */
#define USBHS_INTRUSBE_RESETEN_Msk            (_UINT8_(0x1) << USBHS_INTRUSBE_RESETEN_Pos)         /* (USBHS_INTRUSBE) RESET/BABBLE Interrupt Enable Mask */
#define USBHS_INTRUSBE_RESETEN(value)         (USBHS_INTRUSBE_RESETEN_Msk & (_UINT8_(value) << USBHS_INTRUSBE_RESETEN_Pos)) /* Assigment of value for RESETEN in the USBHS_INTRUSBE register */
#define USBHS_INTRUSBE_SOFEN_Pos              _UINT8_(3)                                           /* (USBHS_INTRUSBE) SOF Interrupt Enable Position */
#define USBHS_INTRUSBE_SOFEN_Msk              (_UINT8_(0x1) << USBHS_INTRUSBE_SOFEN_Pos)           /* (USBHS_INTRUSBE) SOF Interrupt Enable Mask */
#define USBHS_INTRUSBE_SOFEN(value)           (USBHS_INTRUSBE_SOFEN_Msk & (_UINT8_(value) << USBHS_INTRUSBE_SOFEN_Pos)) /* Assigment of value for SOFEN in the USBHS_INTRUSBE register */
#define USBHS_INTRUSBE_CONNEN_Pos             _UINT8_(4)                                           /* (USBHS_INTRUSBE) CONN Interrupt Enable Position */
#define USBHS_INTRUSBE_CONNEN_Msk             (_UINT8_(0x1) << USBHS_INTRUSBE_CONNEN_Pos)          /* (USBHS_INTRUSBE) CONN Interrupt Enable Mask */
#define USBHS_INTRUSBE_CONNEN(value)          (USBHS_INTRUSBE_CONNEN_Msk & (_UINT8_(value) << USBHS_INTRUSBE_CONNEN_Pos)) /* Assigment of value for CONNEN in the USBHS_INTRUSBE register */
#define USBHS_INTRUSBE_DISCONEN_Pos           _UINT8_(5)                                           /* (USBHS_INTRUSBE) DISCONN Interrupt Enable Position */
#define USBHS_INTRUSBE_DISCONEN_Msk           (_UINT8_(0x1) << USBHS_INTRUSBE_DISCONEN_Pos)        /* (USBHS_INTRUSBE) DISCONN Interrupt Enable Mask */
#define USBHS_INTRUSBE_DISCONEN(value)        (USBHS_INTRUSBE_DISCONEN_Msk & (_UINT8_(value) << USBHS_INTRUSBE_DISCONEN_Pos)) /* Assigment of value for DISCONEN in the USBHS_INTRUSBE register */
#define USBHS_INTRUSBE_SESSREQEN_Pos          _UINT8_(6)                                           /* (USBHS_INTRUSBE) SESSREQ Interrupt Enable Position */
#define USBHS_INTRUSBE_SESSREQEN_Msk          (_UINT8_(0x1) << USBHS_INTRUSBE_SESSREQEN_Pos)       /* (USBHS_INTRUSBE) SESSREQ Interrupt Enable Mask */
#define USBHS_INTRUSBE_SESSREQEN(value)       (USBHS_INTRUSBE_SESSREQEN_Msk & (_UINT8_(value) << USBHS_INTRUSBE_SESSREQEN_Pos)) /* Assigment of value for SESSREQEN in the USBHS_INTRUSBE register */
#define USBHS_INTRUSBE_VBUSERREN_Pos          _UINT8_(7)                                           /* (USBHS_INTRUSBE) VBus Error Interrupt Enable Position */
#define USBHS_INTRUSBE_VBUSERREN_Msk          (_UINT8_(0x1) << USBHS_INTRUSBE_VBUSERREN_Pos)       /* (USBHS_INTRUSBE) VBus Error Interrupt Enable Mask */
#define USBHS_INTRUSBE_VBUSERREN(value)       (USBHS_INTRUSBE_VBUSERREN_Msk & (_UINT8_(value) << USBHS_INTRUSBE_VBUSERREN_Pos)) /* Assigment of value for VBUSERREN in the USBHS_INTRUSBE register */
#define USBHS_INTRUSBE_Msk                    _UINT8_(0xFF)                                        /* (USBHS_INTRUSBE) Register Mask  */


/* -------- USBHS_FRAME : (USBHS Offset: 0x100C) ( R/ 16) Holds The Last Received Frame Number -------- */
#define USBHS_FRAME_RESETVALUE                _UINT16_(0x00)                                       /*  (USBHS_FRAME) Holds The Last Received Frame Number  Reset Value */

#define USBHS_FRAME_FRMNUM_Pos                _UINT16_(0)                                          /* (USBHS_FRAME) Frame Number Position */
#define USBHS_FRAME_FRMNUM_Msk                (_UINT16_(0x7FF) << USBHS_FRAME_FRMNUM_Pos)          /* (USBHS_FRAME) Frame Number Mask */
#define USBHS_FRAME_FRMNUM(value)             (USBHS_FRAME_FRMNUM_Msk & (_UINT16_(value) << USBHS_FRAME_FRMNUM_Pos)) /* Assigment of value for FRMNUM in the USBHS_FRAME register */
#define USBHS_FRAME_Msk                       _UINT16_(0x07FF)                                     /* (USBHS_FRAME) Register Mask  */


/* -------- USBHS_INDEX : (USBHS Offset: 0x100E) (R/W 8) Index Is A 4-Bit Register That Determines Which Endpoint Control/Status Registers Are Accessed -------- */
#define USBHS_INDEX_RESETVALUE                _UINT8_(0x00)                                        /*  (USBHS_INDEX) Index Is A 4-Bit Register That Determines Which Endpoint Control/Status Registers Are Accessed  Reset Value */

#define USBHS_INDEX_SELEP_Pos                 _UINT8_(0)                                           /* (USBHS_INDEX) The Selected Endpoint Position */
#define USBHS_INDEX_SELEP_Msk                 (_UINT8_(0xF) << USBHS_INDEX_SELEP_Pos)              /* (USBHS_INDEX) The Selected Endpoint Mask */
#define USBHS_INDEX_SELEP(value)              (USBHS_INDEX_SELEP_Msk & (_UINT8_(value) << USBHS_INDEX_SELEP_Pos)) /* Assigment of value for SELEP in the USBHS_INDEX register */
#define   USBHS_INDEX_SELEP_EP0_Val           _UINT8_(0x0)                                         /* (USBHS_INDEX) Endpoint 0 Select  */
#define   USBHS_INDEX_SELEP_EP1_Val           _UINT8_(0x1)                                         /* (USBHS_INDEX) Endpoint 1 Select  */
#define   USBHS_INDEX_SELEP_EP2_Val           _UINT8_(0x2)                                         /* (USBHS_INDEX) Endpoint 2 Select  */
#define   USBHS_INDEX_SELEP_EP3_Val           _UINT8_(0x3)                                         /* (USBHS_INDEX) Endpoint 3 Select  */
#define   USBHS_INDEX_SELEP_EP4_Val           _UINT8_(0x4)                                         /* (USBHS_INDEX) Endpoint 4 Select  */
#define   USBHS_INDEX_SELEP_EP5_Val           _UINT8_(0x5)                                         /* (USBHS_INDEX) Endpoint 5 Select  */
#define   USBHS_INDEX_SELEP_EP6_Val           _UINT8_(0x6)                                         /* (USBHS_INDEX) Endpoint 6 Select  */
#define   USBHS_INDEX_SELEP_EP7_Val           _UINT8_(0x7)                                         /* (USBHS_INDEX) Endpoint 7 Select  */
#define   USBHS_INDEX_SELEP_EP8_Val           _UINT8_(0x8)                                         /* (USBHS_INDEX) Endpoint 8 Select  */
#define USBHS_INDEX_SELEP_EP0                 (USBHS_INDEX_SELEP_EP0_Val << USBHS_INDEX_SELEP_Pos) /* (USBHS_INDEX) Endpoint 0 Select Position  */
#define USBHS_INDEX_SELEP_EP1                 (USBHS_INDEX_SELEP_EP1_Val << USBHS_INDEX_SELEP_Pos) /* (USBHS_INDEX) Endpoint 1 Select Position  */
#define USBHS_INDEX_SELEP_EP2                 (USBHS_INDEX_SELEP_EP2_Val << USBHS_INDEX_SELEP_Pos) /* (USBHS_INDEX) Endpoint 2 Select Position  */
#define USBHS_INDEX_SELEP_EP3                 (USBHS_INDEX_SELEP_EP3_Val << USBHS_INDEX_SELEP_Pos) /* (USBHS_INDEX) Endpoint 3 Select Position  */
#define USBHS_INDEX_SELEP_EP4                 (USBHS_INDEX_SELEP_EP4_Val << USBHS_INDEX_SELEP_Pos) /* (USBHS_INDEX) Endpoint 4 Select Position  */
#define USBHS_INDEX_SELEP_EP5                 (USBHS_INDEX_SELEP_EP5_Val << USBHS_INDEX_SELEP_Pos) /* (USBHS_INDEX) Endpoint 5 Select Position  */
#define USBHS_INDEX_SELEP_EP6                 (USBHS_INDEX_SELEP_EP6_Val << USBHS_INDEX_SELEP_Pos) /* (USBHS_INDEX) Endpoint 6 Select Position  */
#define USBHS_INDEX_SELEP_EP7                 (USBHS_INDEX_SELEP_EP7_Val << USBHS_INDEX_SELEP_Pos) /* (USBHS_INDEX) Endpoint 7 Select Position  */
#define USBHS_INDEX_SELEP_EP8                 (USBHS_INDEX_SELEP_EP8_Val << USBHS_INDEX_SELEP_Pos) /* (USBHS_INDEX) Endpoint 8 Select Position  */
#define USBHS_INDEX_Msk                       _UINT8_(0x0F)                                        /* (USBHS_INDEX) Register Mask  */


/* -------- USBHS_TESTMODE : (USBHS Offset: 0x100F) (R/W 8) Not Used In Normal Operation. Configuration To Put the USBCORE Into One Of The Four Test Modes For HighSpeed Operation -------- */
#define USBHS_TESTMODE_RESETVALUE             _UINT8_(0x00)                                        /*  (USBHS_TESTMODE) Not Used In Normal Operation. Configuration To Put the USBCORE Into One Of The Four Test Modes For HighSpeed Operation  Reset Value */

#define USBHS_TESTMODE_TESTSE0NAK_Pos         _UINT8_(0)                                           /* (USBHS_TESTMODE) Set To Enter The Test_SE0_NAK mode Position */
#define USBHS_TESTMODE_TESTSE0NAK_Msk         (_UINT8_(0x1) << USBHS_TESTMODE_TESTSE0NAK_Pos)      /* (USBHS_TESTMODE) Set To Enter The Test_SE0_NAK mode Mask */
#define USBHS_TESTMODE_TESTSE0NAK(value)      (USBHS_TESTMODE_TESTSE0NAK_Msk & (_UINT8_(value) << USBHS_TESTMODE_TESTSE0NAK_Pos)) /* Assigment of value for TESTSE0NAK in the USBHS_TESTMODE register */
#define USBHS_TESTMODE_TESTJ_Pos              _UINT8_(1)                                           /* (USBHS_TESTMODE) Set To Enter The Test_J mode Position */
#define USBHS_TESTMODE_TESTJ_Msk              (_UINT8_(0x1) << USBHS_TESTMODE_TESTJ_Pos)           /* (USBHS_TESTMODE) Set To Enter The Test_J mode Mask */
#define USBHS_TESTMODE_TESTJ(value)           (USBHS_TESTMODE_TESTJ_Msk & (_UINT8_(value) << USBHS_TESTMODE_TESTJ_Pos)) /* Assigment of value for TESTJ in the USBHS_TESTMODE register */
#define USBHS_TESTMODE_TESTK_Pos              _UINT8_(2)                                           /* (USBHS_TESTMODE) Set To Enter The Test_K mode Position */
#define USBHS_TESTMODE_TESTK_Msk              (_UINT8_(0x1) << USBHS_TESTMODE_TESTK_Pos)           /* (USBHS_TESTMODE) Set To Enter The Test_K mode Mask */
#define USBHS_TESTMODE_TESTK(value)           (USBHS_TESTMODE_TESTK_Msk & (_UINT8_(value) << USBHS_TESTMODE_TESTK_Pos)) /* Assigment of value for TESTK in the USBHS_TESTMODE register */
#define USBHS_TESTMODE_TESTPACKET_Pos         _UINT8_(3)                                           /* (USBHS_TESTMODE) Set To Enter The Test_Packet mode Position */
#define USBHS_TESTMODE_TESTPACKET_Msk         (_UINT8_(0x1) << USBHS_TESTMODE_TESTPACKET_Pos)      /* (USBHS_TESTMODE) Set To Enter The Test_Packet mode Mask */
#define USBHS_TESTMODE_TESTPACKET(value)      (USBHS_TESTMODE_TESTPACKET_Msk & (_UINT8_(value) << USBHS_TESTMODE_TESTPACKET_Pos)) /* Assigment of value for TESTPACKET in the USBHS_TESTMODE register */
#define USBHS_TESTMODE_FORCEHS_Pos            _UINT8_(4)                                           /* (USBHS_TESTMODE) Depending On Bit 7 Force Controller Into High Speed Mode Position */
#define USBHS_TESTMODE_FORCEHS_Msk            (_UINT8_(0x1) << USBHS_TESTMODE_FORCEHS_Pos)         /* (USBHS_TESTMODE) Depending On Bit 7 Force Controller Into High Speed Mode Mask */
#define USBHS_TESTMODE_FORCEHS(value)         (USBHS_TESTMODE_FORCEHS_Msk & (_UINT8_(value) << USBHS_TESTMODE_FORCEHS_Pos)) /* Assigment of value for FORCEHS in the USBHS_TESTMODE register */
#define USBHS_TESTMODE_FORCEFS_Pos            _UINT8_(5)                                           /* (USBHS_TESTMODE) Depending On Bit 7 Force Controller Into FS Speed Mode Position */
#define USBHS_TESTMODE_FORCEFS_Msk            (_UINT8_(0x1) << USBHS_TESTMODE_FORCEFS_Pos)         /* (USBHS_TESTMODE) Depending On Bit 7 Force Controller Into FS Speed Mode Mask */
#define USBHS_TESTMODE_FORCEFS(value)         (USBHS_TESTMODE_FORCEFS_Msk & (_UINT8_(value) << USBHS_TESTMODE_FORCEFS_Pos)) /* Assigment of value for FORCEFS in the USBHS_TESTMODE register */
#define USBHS_TESTMODE_FIFOACCESS_Pos         _UINT8_(6)                                           /* (USBHS_TESTMODE) The CPU Sets This Bit To Transfer The Packet In The Endpoint 0 TX FIFO To The Endpoint 0 Rx FIFO. It Is Cleared Automatically. Position */
#define USBHS_TESTMODE_FIFOACCESS_Msk         (_UINT8_(0x1) << USBHS_TESTMODE_FIFOACCESS_Pos)      /* (USBHS_TESTMODE) The CPU Sets This Bit To Transfer The Packet In The Endpoint 0 TX FIFO To The Endpoint 0 Rx FIFO. It Is Cleared Automatically. Mask */
#define USBHS_TESTMODE_FIFOACCESS(value)      (USBHS_TESTMODE_FIFOACCESS_Msk & (_UINT8_(value) << USBHS_TESTMODE_FIFOACCESS_Pos)) /* Assigment of value for FIFOACCESS in the USBHS_TESTMODE register */
#define USBHS_TESTMODE_FORCEHOST_Pos          _UINT8_(7)                                           /* (USBHS_TESTMODE) The CPU Sets This Bit To Instruct The Core To Enter Host Mode When The Session Bit Is Set Position */
#define USBHS_TESTMODE_FORCEHOST_Msk          (_UINT8_(0x1) << USBHS_TESTMODE_FORCEHOST_Pos)       /* (USBHS_TESTMODE) The CPU Sets This Bit To Instruct The Core To Enter Host Mode When The Session Bit Is Set Mask */
#define USBHS_TESTMODE_FORCEHOST(value)       (USBHS_TESTMODE_FORCEHOST_Msk & (_UINT8_(value) << USBHS_TESTMODE_FORCEHOST_Pos)) /* Assigment of value for FORCEHOST in the USBHS_TESTMODE register */
#define USBHS_TESTMODE_Msk                    _UINT8_(0xFF)                                        /* (USBHS_TESTMODE) Register Mask  */


/* -------- USBHS_ENDPOINTX_TXMAXP : (USBHS Offset: 0x1010) (R/W 16) ENDPOINTX Maximum Amount Of Data That Can Be Transferred Through The Selected TX Endpoint In A Single Operation -------- */
#define USBHS_ENDPOINTX_TXMAXP_RESETVALUE     _UINT16_(0x00)                                       /*  (USBHS_ENDPOINTX_TXMAXP) ENDPOINTX Maximum Amount Of Data That Can Be Transferred Through The Selected TX Endpoint In A Single Operation  Reset Value */

#define USBHS_ENDPOINTX_TXMAXP_MAXPAYLOAD_Pos _UINT16_(0)                                          /* (USBHS_ENDPOINTX_TXMAXP) Maximum Payload/Transactions Position */
#define USBHS_ENDPOINTX_TXMAXP_MAXPAYLOAD_Msk (_UINT16_(0x7FF) << USBHS_ENDPOINTX_TXMAXP_MAXPAYLOAD_Pos) /* (USBHS_ENDPOINTX_TXMAXP) Maximum Payload/Transactions Mask */
#define USBHS_ENDPOINTX_TXMAXP_MAXPAYLOAD(value) (USBHS_ENDPOINTX_TXMAXP_MAXPAYLOAD_Msk & (_UINT16_(value) << USBHS_ENDPOINTX_TXMAXP_MAXPAYLOAD_Pos)) /* Assigment of value for MAXPAYLOAD in the USBHS_ENDPOINTX_TXMAXP register */
#define USBHS_ENDPOINTX_TXMAXP_MULTIPLIER_Pos _UINT16_(11)                                         /* (USBHS_ENDPOINTX_TXMAXP) Multiplier Value (m-1) Position */
#define USBHS_ENDPOINTX_TXMAXP_MULTIPLIER_Msk (_UINT16_(0x1F) << USBHS_ENDPOINTX_TXMAXP_MULTIPLIER_Pos) /* (USBHS_ENDPOINTX_TXMAXP) Multiplier Value (m-1) Mask */
#define USBHS_ENDPOINTX_TXMAXP_MULTIPLIER(value) (USBHS_ENDPOINTX_TXMAXP_MULTIPLIER_Msk & (_UINT16_(value) << USBHS_ENDPOINTX_TXMAXP_MULTIPLIER_Pos)) /* Assigment of value for MULTIPLIER in the USBHS_ENDPOINTX_TXMAXP register */
#define USBHS_ENDPOINTX_TXMAXP_Msk            _UINT16_(0xFFFF)                                     /* (USBHS_ENDPOINTX_TXMAXP) Register Mask  */


/* -------- USBHS_ENDPOINTX_TXCSRL : (USBHS Offset: 0x1012) (R/W 8) ENDPOINTX Control And Status Bits for TX Endpoints 1-15 -------- */
#define USBHS_ENDPOINTX_TXCSRL_RESETVALUE     _UINT8_(0x00)                                        /*  (USBHS_ENDPOINTX_TXCSRL) ENDPOINTX Control And Status Bits for TX Endpoints 1-15  Reset Value */

#define USBHS_ENDPOINTX_TXCSRL_TXPKTRDY_Pos   _UINT8_(0)                                           /* (USBHS_ENDPOINTX_TXCSRL) The CPU Sets This Bit After Loading A Data Packet Into The FIFO. Position */
#define USBHS_ENDPOINTX_TXCSRL_TXPKTRDY_Msk   (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRL_TXPKTRDY_Pos) /* (USBHS_ENDPOINTX_TXCSRL) The CPU Sets This Bit After Loading A Data Packet Into The FIFO. Mask */
#define USBHS_ENDPOINTX_TXCSRL_TXPKTRDY(value) (USBHS_ENDPOINTX_TXCSRL_TXPKTRDY_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRL_TXPKTRDY_Pos)) /* Assigment of value for TXPKTRDY in the USBHS_ENDPOINTX_TXCSRL register */
#define USBHS_ENDPOINTX_TXCSRL_FIFONOTEMPTY_Pos _UINT8_(1)                                           /* (USBHS_ENDPOINTX_TXCSRL) The USB Sets This Bit When There Is At Least 1 Packet In The TX FIFO. Position */
#define USBHS_ENDPOINTX_TXCSRL_FIFONOTEMPTY_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRL_FIFONOTEMPTY_Pos) /* (USBHS_ENDPOINTX_TXCSRL) The USB Sets This Bit When There Is At Least 1 Packet In The TX FIFO. Mask */
#define USBHS_ENDPOINTX_TXCSRL_FIFONOTEMPTY(value) (USBHS_ENDPOINTX_TXCSRL_FIFONOTEMPTY_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRL_FIFONOTEMPTY_Pos)) /* Assigment of value for FIFONOTEMPTY in the USBHS_ENDPOINTX_TXCSRL register */
#define USBHS_ENDPOINTX_TXCSRL_FLUSHFIFO_Pos  _UINT8_(3)                                           /* (USBHS_ENDPOINTX_TXCSRL) The CPU Writes A 1 To This Bit To Flush The Latest Packet From The Endpoint TX FIFO Position */
#define USBHS_ENDPOINTX_TXCSRL_FLUSHFIFO_Msk  (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRL_FLUSHFIFO_Pos) /* (USBHS_ENDPOINTX_TXCSRL) The CPU Writes A 1 To This Bit To Flush The Latest Packet From The Endpoint TX FIFO Mask */
#define USBHS_ENDPOINTX_TXCSRL_FLUSHFIFO(value) (USBHS_ENDPOINTX_TXCSRL_FLUSHFIFO_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRL_FLUSHFIFO_Pos)) /* Assigment of value for FLUSHFIFO in the USBHS_ENDPOINTX_TXCSRL register */
#define USBHS_ENDPOINTX_TXCSRL_CLRDATATOG_Pos _UINT8_(6)                                           /* (USBHS_ENDPOINTX_TXCSRL) The CPU Writes A 1 To This Bit To Reset The Endpoint Data Toggle To 0. Position */
#define USBHS_ENDPOINTX_TXCSRL_CLRDATATOG_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRL_CLRDATATOG_Pos) /* (USBHS_ENDPOINTX_TXCSRL) The CPU Writes A 1 To This Bit To Reset The Endpoint Data Toggle To 0. Mask */
#define USBHS_ENDPOINTX_TXCSRL_CLRDATATOG(value) (USBHS_ENDPOINTX_TXCSRL_CLRDATATOG_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRL_CLRDATATOG_Pos)) /* Assigment of value for CLRDATATOG in the USBHS_ENDPOINTX_TXCSRL register */
#define USBHS_ENDPOINTX_TXCSRL_Msk            _UINT8_(0x4B)                                        /* (USBHS_ENDPOINTX_TXCSRL) Register Mask  */

/* HOST_EPX mode */
#define USBHS_ENDPOINTX_TXCSRL_HOST_EPX_ERROR_Pos _UINT8_(2)                                           /* (USBHS_ENDPOINTX_TXCSRL) This Bit Will Be Set When Three Attempts Have Been Made To Perform A Transaction With No Response From The Peripheral Position */
#define USBHS_ENDPOINTX_TXCSRL_HOST_EPX_ERROR_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRL_HOST_EPX_ERROR_Pos) /* (USBHS_ENDPOINTX_TXCSRL) This Bit Will Be Set When Three Attempts Have Been Made To Perform A Transaction With No Response From The Peripheral Mask */
#define USBHS_ENDPOINTX_TXCSRL_HOST_EPX_ERROR(value) (USBHS_ENDPOINTX_TXCSRL_HOST_EPX_ERROR_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRL_HOST_EPX_ERROR_Pos))
#define USBHS_ENDPOINTX_TXCSRL_HOST_EPX_SETUPPKT_Pos _UINT8_(4)                                           /* (USBHS_ENDPOINTX_TXCSRL) The CPU Sets This Bit, At The Same Time As The TxPktRdy Bit Is Set, To Send A SETUP Token Instead Of An OUT Token For The Transaction Position */
#define USBHS_ENDPOINTX_TXCSRL_HOST_EPX_SETUPPKT_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRL_HOST_EPX_SETUPPKT_Pos) /* (USBHS_ENDPOINTX_TXCSRL) The CPU Sets This Bit, At The Same Time As The TxPktRdy Bit Is Set, To Send A SETUP Token Instead Of An OUT Token For The Transaction Mask */
#define USBHS_ENDPOINTX_TXCSRL_HOST_EPX_SETUPPKT(value) (USBHS_ENDPOINTX_TXCSRL_HOST_EPX_SETUPPKT_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRL_HOST_EPX_SETUPPKT_Pos))
#define USBHS_ENDPOINTX_TXCSRL_HOST_EPX_RXSTALL_Pos _UINT8_(5)                                           /* (USBHS_ENDPOINTX_TXCSRL) This Bit Is Set When A Stall Handshake Is Received. Position */
#define USBHS_ENDPOINTX_TXCSRL_HOST_EPX_RXSTALL_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRL_HOST_EPX_RXSTALL_Pos) /* (USBHS_ENDPOINTX_TXCSRL) This Bit Is Set When A Stall Handshake Is Received. Mask */
#define USBHS_ENDPOINTX_TXCSRL_HOST_EPX_RXSTALL(value) (USBHS_ENDPOINTX_TXCSRL_HOST_EPX_RXSTALL_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRL_HOST_EPX_RXSTALL_Pos))
#define USBHS_ENDPOINTX_TXCSRL_HOST_EPX_NAKTIMEOUT_Pos _UINT8_(7)                                           /* (USBHS_ENDPOINTX_TXCSRL) This Bit Will Be Set When Endpoint 0 Is Halted Following The Receipt Of NAK Responses For Longer Than The Time Set By The NAKLimit0 register. Position */
#define USBHS_ENDPOINTX_TXCSRL_HOST_EPX_NAKTIMEOUT_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRL_HOST_EPX_NAKTIMEOUT_Pos) /* (USBHS_ENDPOINTX_TXCSRL) This Bit Will Be Set When Endpoint 0 Is Halted Following The Receipt Of NAK Responses For Longer Than The Time Set By The NAKLimit0 register. Mask */
#define USBHS_ENDPOINTX_TXCSRL_HOST_EPX_NAKTIMEOUT(value) (USBHS_ENDPOINTX_TXCSRL_HOST_EPX_NAKTIMEOUT_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRL_HOST_EPX_NAKTIMEOUT_Pos))
#define USBHS_ENDPOINTX_TXCSRL_HOST_EPX_Msk   _UINT8_(0xB4)                                         /* (USBHS_ENDPOINTX_TXCSRL_HOST_EPX) Register Mask  */

/* PERIPHERAL_EPX mode */
#define USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_UNDERRUN_Pos _UINT8_(2)                                           /* (USBHS_ENDPOINTX_TXCSRL) The USB Sets This Bit If An In Token Is Received When TxPktRdy Is Not Set. Position */
#define USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_UNDERRUN_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_UNDERRUN_Pos) /* (USBHS_ENDPOINTX_TXCSRL) The USB Sets This Bit If An In Token Is Received When TxPktRdy Is Not Set. Mask */
#define USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_UNDERRUN(value) (USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_UNDERRUN_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_UNDERRUN_Pos))
#define USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_SENDSTALL_Pos _UINT8_(4)                                           /* (USBHS_ENDPOINTX_TXCSRL) The CPU Writes A 1 To This Bit To Issue A Stall Handshake To An In Token Position */
#define USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_SENDSTALL_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_SENDSTALL_Pos) /* (USBHS_ENDPOINTX_TXCSRL) The CPU Writes A 1 To This Bit To Issue A Stall Handshake To An In Token Mask */
#define USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_SENDSTALL(value) (USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_SENDSTALL_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_SENDSTALL_Pos))
#define USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_SENTSTALL_Pos _UINT8_(5)                                           /* (USBHS_ENDPOINTX_TXCSRL) This Bit Is Set When A Stall Handshake Is Transmitted. Position */
#define USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_SENTSTALL_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_SENTSTALL_Pos) /* (USBHS_ENDPOINTX_TXCSRL) This Bit Is Set When A Stall Handshake Is Transmitted. Mask */
#define USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_SENTSTALL(value) (USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_SENTSTALL_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_SENTSTALL_Pos))
#define USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_INCOMPTX_Pos _UINT8_(7)                                           /* (USBHS_ENDPOINTX_TXCSRL) When The Endpoint Is Being Used For High-Bandwidth Isochronous, This Bit Is Set To Indicate Where A Large Packet Has Been Split Into 2 Or 3 Packets For Transmission But Insufficient IN Tokens Have Been Received To Send All The Parts. Position */
#define USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_INCOMPTX_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_INCOMPTX_Pos) /* (USBHS_ENDPOINTX_TXCSRL) When The Endpoint Is Being Used For High-Bandwidth Isochronous, This Bit Is Set To Indicate Where A Large Packet Has Been Split Into 2 Or 3 Packets For Transmission But Insufficient IN Tokens Have Been Received To Send All The Parts. Mask */
#define USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_INCOMPTX(value) (USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_INCOMPTX_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_INCOMPTX_Pos))
#define USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX_Msk _UINT8_(0xB4)                                         /* (USBHS_ENDPOINTX_TXCSRL_PERIPHERAL_EPX) Register Mask  */


/* -------- USBHS_ENDPOINT0_CSR0L : (USBHS Offset: 0x1012) (R/W 8) ENDPOINT0 Control And Status Bits for TX Endpoint 0 -------- */
#define USBHS_ENDPOINT0_CSR0L_RESETVALUE      _UINT8_(0x00)                                        /*  (USBHS_ENDPOINT0_CSR0L) ENDPOINT0 Control And Status Bits for TX Endpoint 0  Reset Value */

#define USBHS_ENDPOINT0_CSR0L_RXPKTRDY_Pos    _UINT8_(0)                                           /* (USBHS_ENDPOINT0_CSR0L) This Bit Is Set When A Data Packet Has Been Received Position */
#define USBHS_ENDPOINT0_CSR0L_RXPKTRDY_Msk    (_UINT8_(0x1) << USBHS_ENDPOINT0_CSR0L_RXPKTRDY_Pos) /* (USBHS_ENDPOINT0_CSR0L) This Bit Is Set When A Data Packet Has Been Received Mask */
#define USBHS_ENDPOINT0_CSR0L_RXPKTRDY(value) (USBHS_ENDPOINT0_CSR0L_RXPKTRDY_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CSR0L_RXPKTRDY_Pos)) /* Assigment of value for RXPKTRDY in the USBHS_ENDPOINT0_CSR0L register */
#define USBHS_ENDPOINT0_CSR0L_TXPKTRDY_Pos    _UINT8_(1)                                           /* (USBHS_ENDPOINT0_CSR0L) The CPU Sets This Bit After Loading A Data Packet Into The FIFO. Position */
#define USBHS_ENDPOINT0_CSR0L_TXPKTRDY_Msk    (_UINT8_(0x1) << USBHS_ENDPOINT0_CSR0L_TXPKTRDY_Pos) /* (USBHS_ENDPOINT0_CSR0L) The CPU Sets This Bit After Loading A Data Packet Into The FIFO. Mask */
#define USBHS_ENDPOINT0_CSR0L_TXPKTRDY(value) (USBHS_ENDPOINT0_CSR0L_TXPKTRDY_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CSR0L_TXPKTRDY_Pos)) /* Assigment of value for TXPKTRDY in the USBHS_ENDPOINT0_CSR0L register */
#define USBHS_ENDPOINT0_CSR0L_Msk             _UINT8_(0x03)                                        /* (USBHS_ENDPOINT0_CSR0L) Register Mask  */

/* HOST_EP0 mode */
#define USBHS_ENDPOINT0_CSR0L_HOST_EP0_RXSTALL_Pos _UINT8_(2)                                           /* (USBHS_ENDPOINT0_CSR0L) This Bit Is Set When A Stall Handshake Is Received. Position */
#define USBHS_ENDPOINT0_CSR0L_HOST_EP0_RXSTALL_Msk (_UINT8_(0x1) << USBHS_ENDPOINT0_CSR0L_HOST_EP0_RXSTALL_Pos) /* (USBHS_ENDPOINT0_CSR0L) This Bit Is Set When A Stall Handshake Is Received. Mask */
#define USBHS_ENDPOINT0_CSR0L_HOST_EP0_RXSTALL(value) (USBHS_ENDPOINT0_CSR0L_HOST_EP0_RXSTALL_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CSR0L_HOST_EP0_RXSTALL_Pos))
#define USBHS_ENDPOINT0_CSR0L_HOST_EP0_SETUPPKT_Pos _UINT8_(3)                                           /* (USBHS_ENDPOINT0_CSR0L) The CPU Sets This Bit, At The Same Time As The TxPktRdy Bit Is Set, To Send A SETUP Token Instead Of An OUT Token For The Transaction Position */
#define USBHS_ENDPOINT0_CSR0L_HOST_EP0_SETUPPKT_Msk (_UINT8_(0x1) << USBHS_ENDPOINT0_CSR0L_HOST_EP0_SETUPPKT_Pos) /* (USBHS_ENDPOINT0_CSR0L) The CPU Sets This Bit, At The Same Time As The TxPktRdy Bit Is Set, To Send A SETUP Token Instead Of An OUT Token For The Transaction Mask */
#define USBHS_ENDPOINT0_CSR0L_HOST_EP0_SETUPPKT(value) (USBHS_ENDPOINT0_CSR0L_HOST_EP0_SETUPPKT_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CSR0L_HOST_EP0_SETUPPKT_Pos))
#define USBHS_ENDPOINT0_CSR0L_HOST_EP0_ERROR_Pos _UINT8_(4)                                           /* (USBHS_ENDPOINT0_CSR0L) This Bit Will Be Set When Three Attempts Have Been Made To Perform A Transaction With No Response From The Peripheral Position */
#define USBHS_ENDPOINT0_CSR0L_HOST_EP0_ERROR_Msk (_UINT8_(0x1) << USBHS_ENDPOINT0_CSR0L_HOST_EP0_ERROR_Pos) /* (USBHS_ENDPOINT0_CSR0L) This Bit Will Be Set When Three Attempts Have Been Made To Perform A Transaction With No Response From The Peripheral Mask */
#define USBHS_ENDPOINT0_CSR0L_HOST_EP0_ERROR(value) (USBHS_ENDPOINT0_CSR0L_HOST_EP0_ERROR_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CSR0L_HOST_EP0_ERROR_Pos))
#define USBHS_ENDPOINT0_CSR0L_HOST_EP0_REQPKT_Pos _UINT8_(5)                                           /* (USBHS_ENDPOINT0_CSR0L) The CPU Sets This Bit To Request An IN Transaction Position */
#define USBHS_ENDPOINT0_CSR0L_HOST_EP0_REQPKT_Msk (_UINT8_(0x1) << USBHS_ENDPOINT0_CSR0L_HOST_EP0_REQPKT_Pos) /* (USBHS_ENDPOINT0_CSR0L) The CPU Sets This Bit To Request An IN Transaction Mask */
#define USBHS_ENDPOINT0_CSR0L_HOST_EP0_REQPKT(value) (USBHS_ENDPOINT0_CSR0L_HOST_EP0_REQPKT_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CSR0L_HOST_EP0_REQPKT_Pos))
#define USBHS_ENDPOINT0_CSR0L_HOST_EP0_STATUSPKT_Pos _UINT8_(6)                                           /* (USBHS_ENDPOINT0_CSR0L) The CPU Sets This Bit At The Same Time As The TxPktRdy Or ReqPkt Bit Is Set, To Perform A Status Stage Transaction Position */
#define USBHS_ENDPOINT0_CSR0L_HOST_EP0_STATUSPKT_Msk (_UINT8_(0x1) << USBHS_ENDPOINT0_CSR0L_HOST_EP0_STATUSPKT_Pos) /* (USBHS_ENDPOINT0_CSR0L) The CPU Sets This Bit At The Same Time As The TxPktRdy Or ReqPkt Bit Is Set, To Perform A Status Stage Transaction Mask */
#define USBHS_ENDPOINT0_CSR0L_HOST_EP0_STATUSPKT(value) (USBHS_ENDPOINT0_CSR0L_HOST_EP0_STATUSPKT_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CSR0L_HOST_EP0_STATUSPKT_Pos))
#define USBHS_ENDPOINT0_CSR0L_HOST_EP0_NAKTIMEOUT_Pos _UINT8_(7)                                           /* (USBHS_ENDPOINT0_CSR0L) This Bit Will Be Set When Endpoint 0 Is Halted Following The Receipt Of NAK Responses For Longer Than The Time Set By The NAKLimit0 register. Position */
#define USBHS_ENDPOINT0_CSR0L_HOST_EP0_NAKTIMEOUT_Msk (_UINT8_(0x1) << USBHS_ENDPOINT0_CSR0L_HOST_EP0_NAKTIMEOUT_Pos) /* (USBHS_ENDPOINT0_CSR0L) This Bit Will Be Set When Endpoint 0 Is Halted Following The Receipt Of NAK Responses For Longer Than The Time Set By The NAKLimit0 register. Mask */
#define USBHS_ENDPOINT0_CSR0L_HOST_EP0_NAKTIMEOUT(value) (USBHS_ENDPOINT0_CSR0L_HOST_EP0_NAKTIMEOUT_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CSR0L_HOST_EP0_NAKTIMEOUT_Pos))
#define USBHS_ENDPOINT0_CSR0L_HOST_EP0_Msk    _UINT8_(0xFC)                                         /* (USBHS_ENDPOINT0_CSR0L_HOST_EP0) Register Mask  */

/* PERIPHERAL_EP0 mode */
#define USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SENTSTALL_Pos _UINT8_(2)                                           /* (USBHS_ENDPOINT0_CSR0L) This Bit Is Set When A Stall Handshake Is Transmitted. Position */
#define USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SENTSTALL_Msk (_UINT8_(0x1) << USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SENTSTALL_Pos) /* (USBHS_ENDPOINT0_CSR0L) This Bit Is Set When A Stall Handshake Is Transmitted. Mask */
#define USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SENTSTALL(value) (USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SENTSTALL_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SENTSTALL_Pos))
#define USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_DATAEND_Pos _UINT8_(3)                                           /* (USBHS_ENDPOINT0_CSR0L) The CPU Sets This Bit 1. When Setting TxPktRdy For The Last Data Packet 2. When Clearing RxPktRdy After Unloading The Last Data Packet.3. When Setting TxPktRdy For A Zero Length Data Packet. Position */
#define USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_DATAEND_Msk (_UINT8_(0x1) << USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_DATAEND_Pos) /* (USBHS_ENDPOINT0_CSR0L) The CPU Sets This Bit 1. When Setting TxPktRdy For The Last Data Packet 2. When Clearing RxPktRdy After Unloading The Last Data Packet.3. When Setting TxPktRdy For A Zero Length Data Packet. Mask */
#define USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_DATAEND(value) (USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_DATAEND_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_DATAEND_Pos))
#define USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SETUPEND_Pos _UINT8_(4)                                           /* (USBHS_ENDPOINT0_CSR0L) This Bit Will Be Set When A Control Transaction Ends Before The DataEnd Bit Has Been Set Position */
#define USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SETUPEND_Msk (_UINT8_(0x1) << USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SETUPEND_Pos) /* (USBHS_ENDPOINT0_CSR0L) This Bit Will Be Set When A Control Transaction Ends Before The DataEnd Bit Has Been Set Mask */
#define USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SETUPEND(value) (USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SETUPEND_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SETUPEND_Pos))
#define USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SENDSTALL_Pos _UINT8_(5)                                           /* (USBHS_ENDPOINT0_CSR0L) The CPU Writes A 1 To This Bit To Terminate The Current Transaction Position */
#define USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SENDSTALL_Msk (_UINT8_(0x1) << USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SENDSTALL_Pos) /* (USBHS_ENDPOINT0_CSR0L) The CPU Writes A 1 To This Bit To Terminate The Current Transaction Mask */
#define USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SENDSTALL(value) (USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SENDSTALL_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SENDSTALL_Pos))
#define USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SERVICEDRXPKTRDY_Pos _UINT8_(6)                                           /* (USBHS_ENDPOINT0_CSR0L) The CPU Writes A 1 To This Bit To Clear The RxPktRdy Bit. It Is Cleared Automatically Position */
#define USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SERVICEDRXPKTRDY_Msk (_UINT8_(0x1) << USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SERVICEDRXPKTRDY_Pos) /* (USBHS_ENDPOINT0_CSR0L) The CPU Writes A 1 To This Bit To Clear The RxPktRdy Bit. It Is Cleared Automatically Mask */
#define USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SERVICEDRXPKTRDY(value) (USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SERVICEDRXPKTRDY_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SERVICEDRXPKTRDY_Pos))
#define USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SERVICEDSETUPEND_Pos _UINT8_(7)                                           /* (USBHS_ENDPOINT0_CSR0L) The CPU Writes A 1 To This Bit To Clear The SetupEnd Bit. It Is Cleared Automatically. Position */
#define USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SERVICEDSETUPEND_Msk (_UINT8_(0x1) << USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SERVICEDSETUPEND_Pos) /* (USBHS_ENDPOINT0_CSR0L) The CPU Writes A 1 To This Bit To Clear The SetupEnd Bit. It Is Cleared Automatically. Mask */
#define USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SERVICEDSETUPEND(value) (USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SERVICEDSETUPEND_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_SERVICEDSETUPEND_Pos))
#define USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0_Msk _UINT8_(0xFC)                                         /* (USBHS_ENDPOINT0_CSR0L_PERIPHERAL_EP0) Register Mask  */


/* -------- USBHS_ENDPOINTX_TXCSRH : (USBHS Offset: 0x1013) (R/W 8) ENDPOINTX Additional Control And Status Bits For TX Endpoints 1-15 -------- */
#define USBHS_ENDPOINTX_TXCSRH_RESETVALUE     _UINT8_(0x00)                                        /*  (USBHS_ENDPOINTX_TXCSRH) ENDPOINTX Additional Control And Status Bits For TX Endpoints 1-15  Reset Value */

#define USBHS_ENDPOINTX_TXCSRH_MODE_Pos       _UINT8_(5)                                           /* (USBHS_ENDPOINTX_TXCSRH) The CPU Sets This Bit To Enable The Endpoint Direction As TX Position */
#define USBHS_ENDPOINTX_TXCSRH_MODE_Msk       (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRH_MODE_Pos)    /* (USBHS_ENDPOINTX_TXCSRH) The CPU Sets This Bit To Enable The Endpoint Direction As TX Mask */
#define USBHS_ENDPOINTX_TXCSRH_MODE(value)    (USBHS_ENDPOINTX_TXCSRH_MODE_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRH_MODE_Pos)) /* Assigment of value for MODE in the USBHS_ENDPOINTX_TXCSRH register */
#define USBHS_ENDPOINTX_TXCSRH_Msk            _UINT8_(0x20)                                        /* (USBHS_ENDPOINTX_TXCSRH) Register Mask  */

/* HOST_EPX mode */
#define USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DATATOGGLE_Pos _UINT8_(0)                                           /* (USBHS_ENDPOINTX_TXCSRH) When Read, This Bit Indicates The Current State Of The Endpoint Position */
#define USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DATATOGGLE_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DATATOGGLE_Pos) /* (USBHS_ENDPOINTX_TXCSRH) When Read, This Bit Indicates The Current State Of The Endpoint Mask */
#define USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DATATOGGLE(value) (USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DATATOGGLE_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DATATOGGLE_Pos))
#define USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DATATOGGLEWRENABLE_Pos _UINT8_(1)                                           /* (USBHS_ENDPOINTX_TXCSRH) The CPU Writes A 1 To This Bit To Enable The Current State Of The Endpoint 0 Data Toggle To Be Written Position */
#define USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DATATOGGLEWRENABLE_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DATATOGGLEWRENABLE_Pos) /* (USBHS_ENDPOINTX_TXCSRH) The CPU Writes A 1 To This Bit To Enable The Current State Of The Endpoint 0 Data Toggle To Be Written Mask */
#define USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DATATOGGLEWRENABLE(value) (USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DATATOGGLEWRENABLE_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DATATOGGLEWRENABLE_Pos))
#define USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DMAREQMODE_Pos _UINT8_(2)                                           /* (USBHS_ENDPOINTX_TXCSRH) The CPU Sets This Bit To Select DMA Request Mode Position */
#define USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DMAREQMODE_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DMAREQMODE_Pos) /* (USBHS_ENDPOINTX_TXCSRH) The CPU Sets This Bit To Select DMA Request Mode Mask */
#define USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DMAREQMODE(value) (USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DMAREQMODE_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DMAREQMODE_Pos))
#define USBHS_ENDPOINTX_TXCSRH_HOST_EPX_FRCDATATOG_Pos _UINT8_(3)                                           /* (USBHS_ENDPOINTX_TXCSRH) The CPU Sets This Bit To Force The Endpoint Data Toggle To Switch And The Data Packe Position */
#define USBHS_ENDPOINTX_TXCSRH_HOST_EPX_FRCDATATOG_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRH_HOST_EPX_FRCDATATOG_Pos) /* (USBHS_ENDPOINTX_TXCSRH) The CPU Sets This Bit To Force The Endpoint Data Toggle To Switch And The Data Packe Mask */
#define USBHS_ENDPOINTX_TXCSRH_HOST_EPX_FRCDATATOG(value) (USBHS_ENDPOINTX_TXCSRH_HOST_EPX_FRCDATATOG_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRH_HOST_EPX_FRCDATATOG_Pos))
#define USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DMAREQENAB_Pos _UINT8_(4)                                           /* (USBHS_ENDPOINTX_TXCSRH) The CPU Sets This Bit To Enable The DMA Request For The RX Endpoint Position */
#define USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DMAREQENAB_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DMAREQENAB_Pos) /* (USBHS_ENDPOINTX_TXCSRH) The CPU Sets This Bit To Enable The DMA Request For The RX Endpoint Mask */
#define USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DMAREQENAB(value) (USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DMAREQENAB_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRH_HOST_EPX_DMAREQENAB_Pos))
#define USBHS_ENDPOINTX_TXCSRH_HOST_EPX_AUTOSET_Pos _UINT8_(7)                                           /* (USBHS_ENDPOINTX_TXCSRH) If The CPU Sets This Bit, TxPktRdy Will Be Automatically Set When Data Of The Maximum P Position */
#define USBHS_ENDPOINTX_TXCSRH_HOST_EPX_AUTOSET_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRH_HOST_EPX_AUTOSET_Pos) /* (USBHS_ENDPOINTX_TXCSRH) If The CPU Sets This Bit, TxPktRdy Will Be Automatically Set When Data Of The Maximum P Mask */
#define USBHS_ENDPOINTX_TXCSRH_HOST_EPX_AUTOSET(value) (USBHS_ENDPOINTX_TXCSRH_HOST_EPX_AUTOSET_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRH_HOST_EPX_AUTOSET_Pos))
#define USBHS_ENDPOINTX_TXCSRH_HOST_EPX_Msk   _UINT8_(0x9F)                                         /* (USBHS_ENDPOINTX_TXCSRH_HOST_EPX) Register Mask  */

/* PERIPHERAL_EPX mode */
#define USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_DMAREQMODE_Pos _UINT8_(2)                                           /* (USBHS_ENDPOINTX_TXCSRH) The CPU Sets This Bit To Select DMA Request Mode 1 And Clears It To Select DMA Request Mode 0. Position */
#define USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_DMAREQMODE_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_DMAREQMODE_Pos) /* (USBHS_ENDPOINTX_TXCSRH) The CPU Sets This Bit To Select DMA Request Mode 1 And Clears It To Select DMA Request Mode 0. Mask */
#define USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_DMAREQMODE(value) (USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_DMAREQMODE_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_DMAREQMODE_Pos))
#define USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_FRCDATATOG_Pos _UINT8_(3)                                           /* (USBHS_ENDPOINTX_TXCSRH) The CPU Sets This Bit To Force The Endpoint Data Toggle To Switch And The Data Packet To Be Cleared From The FIFO. Position */
#define USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_FRCDATATOG_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_FRCDATATOG_Pos) /* (USBHS_ENDPOINTX_TXCSRH) The CPU Sets This Bit To Force The Endpoint Data Toggle To Switch And The Data Packet To Be Cleared From The FIFO. Mask */
#define USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_FRCDATATOG(value) (USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_FRCDATATOG_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_FRCDATATOG_Pos))
#define USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_DMAREQENAB_Pos _UINT8_(4)                                           /* (USBHS_ENDPOINTX_TXCSRH) The CPU Sets This Bit To Enable The DMA Request For The TX Endpoint Position */
#define USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_DMAREQENAB_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_DMAREQENAB_Pos) /* (USBHS_ENDPOINTX_TXCSRH) The CPU Sets This Bit To Enable The DMA Request For The TX Endpoint Mask */
#define USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_DMAREQENAB(value) (USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_DMAREQENAB_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_DMAREQENAB_Pos))
#define USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_ISO_Pos _UINT8_(6)                                           /* (USBHS_ENDPOINTX_TXCSRH) The CPU Sets This Bit To Enable The TX Endpoint For Isochronous Transfers Position */
#define USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_ISO_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_ISO_Pos) /* (USBHS_ENDPOINTX_TXCSRH) The CPU Sets This Bit To Enable The TX Endpoint For Isochronous Transfers Mask */
#define USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_ISO(value) (USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_ISO_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_ISO_Pos))
#define USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_AUTOSET_Pos _UINT8_(7)                                           /* (USBHS_ENDPOINTX_TXCSRH) If The CPU Sets This Bit, TxPktRdy Will Be Automatically Set When Data Of The Maximum Packet Size Is Loaded Into The TX FIFO. Position */
#define USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_AUTOSET_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_AUTOSET_Pos) /* (USBHS_ENDPOINTX_TXCSRH) If The CPU Sets This Bit, TxPktRdy Will Be Automatically Set When Data Of The Maximum Packet Size Is Loaded Into The TX FIFO. Mask */
#define USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_AUTOSET(value) (USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_AUTOSET_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_AUTOSET_Pos))
#define USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX_Msk _UINT8_(0xDC)                                         /* (USBHS_ENDPOINTX_TXCSRH_PERIPHERAL_EPX) Register Mask  */


/* -------- USBHS_ENDPOINT0_CSR0H : (USBHS Offset: 0x1013) (R/W 8) ENDPOINT0 Additional Control And Status Bits For TX Endpoint 0 -------- */
#define USBHS_ENDPOINT0_CSR0H_RESETVALUE      _UINT8_(0x00)                                        /*  (USBHS_ENDPOINT0_CSR0H) ENDPOINT0 Additional Control And Status Bits For TX Endpoint 0  Reset Value */

#define USBHS_ENDPOINT0_CSR0H_FLUSHFIFO_Pos   _UINT8_(0)                                           /* (USBHS_ENDPOINT0_CSR0H) Flush The Next Packet To Be Transmitted/Read Position */
#define USBHS_ENDPOINT0_CSR0H_FLUSHFIFO_Msk   (_UINT8_(0x1) << USBHS_ENDPOINT0_CSR0H_FLUSHFIFO_Pos) /* (USBHS_ENDPOINT0_CSR0H) Flush The Next Packet To Be Transmitted/Read Mask */
#define USBHS_ENDPOINT0_CSR0H_FLUSHFIFO(value) (USBHS_ENDPOINT0_CSR0H_FLUSHFIFO_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CSR0H_FLUSHFIFO_Pos)) /* Assigment of value for FLUSHFIFO in the USBHS_ENDPOINT0_CSR0H register */
#define USBHS_ENDPOINT0_CSR0H_Msk             _UINT8_(0x01)                                        /* (USBHS_ENDPOINT0_CSR0H) Register Mask  */

/* HOST_EP0 mode */
#define USBHS_ENDPOINT0_CSR0H_HOST_EP0_DATATOGGLE_Pos _UINT8_(1)                                           /* (USBHS_ENDPOINT0_CSR0H) When Read, This Bit Indicates The Current State Of The Endpoint 0 Data Toggle Position */
#define USBHS_ENDPOINT0_CSR0H_HOST_EP0_DATATOGGLE_Msk (_UINT8_(0x1) << USBHS_ENDPOINT0_CSR0H_HOST_EP0_DATATOGGLE_Pos) /* (USBHS_ENDPOINT0_CSR0H) When Read, This Bit Indicates The Current State Of The Endpoint 0 Data Toggle Mask */
#define USBHS_ENDPOINT0_CSR0H_HOST_EP0_DATATOGGLE(value) (USBHS_ENDPOINT0_CSR0H_HOST_EP0_DATATOGGLE_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CSR0H_HOST_EP0_DATATOGGLE_Pos))
#define USBHS_ENDPOINT0_CSR0H_HOST_EP0_DATATOGGLEWRTENABLE_Pos _UINT8_(2)                                           /* (USBHS_ENDPOINT0_CSR0H) The CPU Writes A 1 To This Bit To Enable The Current State Of The Endpoint 0 Data Toggle To Be Written Position */
#define USBHS_ENDPOINT0_CSR0H_HOST_EP0_DATATOGGLEWRTENABLE_Msk (_UINT8_(0x1) << USBHS_ENDPOINT0_CSR0H_HOST_EP0_DATATOGGLEWRTENABLE_Pos) /* (USBHS_ENDPOINT0_CSR0H) The CPU Writes A 1 To This Bit To Enable The Current State Of The Endpoint 0 Data Toggle To Be Written Mask */
#define USBHS_ENDPOINT0_CSR0H_HOST_EP0_DATATOGGLEWRTENABLE(value) (USBHS_ENDPOINT0_CSR0H_HOST_EP0_DATATOGGLEWRTENABLE_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CSR0H_HOST_EP0_DATATOGGLEWRTENABLE_Pos))
#define USBHS_ENDPOINT0_CSR0H_HOST_EP0_DISPING_Pos _UINT8_(3)                                           /* (USBHS_ENDPOINT0_CSR0H) The CPU Writes A 1 To This Bit To Instruct The Core Not To Issue PING Tokens In Data And Status Phases Of A High-Speed Control Transfer Position */
#define USBHS_ENDPOINT0_CSR0H_HOST_EP0_DISPING_Msk (_UINT8_(0x1) << USBHS_ENDPOINT0_CSR0H_HOST_EP0_DISPING_Pos) /* (USBHS_ENDPOINT0_CSR0H) The CPU Writes A 1 To This Bit To Instruct The Core Not To Issue PING Tokens In Data And Status Phases Of A High-Speed Control Transfer Mask */
#define USBHS_ENDPOINT0_CSR0H_HOST_EP0_DISPING(value) (USBHS_ENDPOINT0_CSR0H_HOST_EP0_DISPING_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CSR0H_HOST_EP0_DISPING_Pos))
#define USBHS_ENDPOINT0_CSR0H_HOST_EP0_Msk    _UINT8_(0x0E)                                         /* (USBHS_ENDPOINT0_CSR0H_HOST_EP0) Register Mask  */

/* PERIPHERAL_EP0 mode */
#define USBHS_ENDPOINT0_CSR0H_PERIPHERAL_EP0_Msk _UINT8_(0x00)                                         /* (USBHS_ENDPOINT0_CSR0H_PERIPHERAL_EP0) Register Mask  */


/* -------- USBHS_ENDPOINTX_RXMAXP : (USBHS Offset: 0x1014) (R/W 16) ENDPOINTX Maximum Amount Of Data That Can Be Transferred Through The Selected RX Endpoint In A Single Operation -------- */
#define USBHS_ENDPOINTX_RXMAXP_RESETVALUE     _UINT16_(0x00)                                       /*  (USBHS_ENDPOINTX_RXMAXP) ENDPOINTX Maximum Amount Of Data That Can Be Transferred Through The Selected RX Endpoint In A Single Operation  Reset Value */

#define USBHS_ENDPOINTX_RXMAXP_MAXPAYLOAD_Pos _UINT16_(0)                                          /* (USBHS_ENDPOINTX_RXMAXP) Maximum Payload/Transactions Position */
#define USBHS_ENDPOINTX_RXMAXP_MAXPAYLOAD_Msk (_UINT16_(0x7FF) << USBHS_ENDPOINTX_RXMAXP_MAXPAYLOAD_Pos) /* (USBHS_ENDPOINTX_RXMAXP) Maximum Payload/Transactions Mask */
#define USBHS_ENDPOINTX_RXMAXP_MAXPAYLOAD(value) (USBHS_ENDPOINTX_RXMAXP_MAXPAYLOAD_Msk & (_UINT16_(value) << USBHS_ENDPOINTX_RXMAXP_MAXPAYLOAD_Pos)) /* Assigment of value for MAXPAYLOAD in the USBHS_ENDPOINTX_RXMAXP register */
#define USBHS_ENDPOINTX_RXMAXP_MULTIPLIER_Pos _UINT16_(11)                                         /* (USBHS_ENDPOINTX_RXMAXP) Multiplier Value (m-1) Position */
#define USBHS_ENDPOINTX_RXMAXP_MULTIPLIER_Msk (_UINT16_(0x1F) << USBHS_ENDPOINTX_RXMAXP_MULTIPLIER_Pos) /* (USBHS_ENDPOINTX_RXMAXP) Multiplier Value (m-1) Mask */
#define USBHS_ENDPOINTX_RXMAXP_MULTIPLIER(value) (USBHS_ENDPOINTX_RXMAXP_MULTIPLIER_Msk & (_UINT16_(value) << USBHS_ENDPOINTX_RXMAXP_MULTIPLIER_Pos)) /* Assigment of value for MULTIPLIER in the USBHS_ENDPOINTX_RXMAXP register */
#define USBHS_ENDPOINTX_RXMAXP_Msk            _UINT16_(0xFFFF)                                     /* (USBHS_ENDPOINTX_RXMAXP) Register Mask  */


/* -------- USBHS_ENDPOINTX_RXCSRL : (USBHS Offset: 0x1016) (R/W 8) ENDPOINTX Control And Status Bits for RX Endpoint 0 Or Endpoint 1-15 -------- */
#define USBHS_ENDPOINTX_RXCSRL_RESETVALUE     _UINT8_(0x00)                                        /*  (USBHS_ENDPOINTX_RXCSRL) ENDPOINTX Control And Status Bits for RX Endpoint 0 Or Endpoint 1-15  Reset Value */

#define USBHS_ENDPOINTX_RXCSRL_RXPKTRDY_Pos   _UINT8_(0)                                           /* (USBHS_ENDPOINTX_RXCSRL) This Bit Is Set When A Data Packet Has Been Received. Position */
#define USBHS_ENDPOINTX_RXCSRL_RXPKTRDY_Msk   (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRL_RXPKTRDY_Pos) /* (USBHS_ENDPOINTX_RXCSRL) This Bit Is Set When A Data Packet Has Been Received. Mask */
#define USBHS_ENDPOINTX_RXCSRL_RXPKTRDY(value) (USBHS_ENDPOINTX_RXCSRL_RXPKTRDY_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRL_RXPKTRDY_Pos)) /* Assigment of value for RXPKTRDY in the USBHS_ENDPOINTX_RXCSRL register */
#define USBHS_ENDPOINTX_RXCSRL_FLUSHFIFO_Pos  _UINT8_(4)                                           /* (USBHS_ENDPOINTX_RXCSRL) The CPU Writes A 1 To This Bit To Flush The Next Packet To Be Read From The Endpoint Rx FIFO Position */
#define USBHS_ENDPOINTX_RXCSRL_FLUSHFIFO_Msk  (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRL_FLUSHFIFO_Pos) /* (USBHS_ENDPOINTX_RXCSRL) The CPU Writes A 1 To This Bit To Flush The Next Packet To Be Read From The Endpoint Rx FIFO Mask */
#define USBHS_ENDPOINTX_RXCSRL_FLUSHFIFO(value) (USBHS_ENDPOINTX_RXCSRL_FLUSHFIFO_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRL_FLUSHFIFO_Pos)) /* Assigment of value for FLUSHFIFO in the USBHS_ENDPOINTX_RXCSRL register */
#define USBHS_ENDPOINTX_RXCSRL_CLRDATATOG_Pos _UINT8_(7)                                           /* (USBHS_ENDPOINTX_RXCSRL) The CPU Writes A 1 To This Bit To Reset The Endpoint Data Toggle To 0. Position */
#define USBHS_ENDPOINTX_RXCSRL_CLRDATATOG_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRL_CLRDATATOG_Pos) /* (USBHS_ENDPOINTX_RXCSRL) The CPU Writes A 1 To This Bit To Reset The Endpoint Data Toggle To 0. Mask */
#define USBHS_ENDPOINTX_RXCSRL_CLRDATATOG(value) (USBHS_ENDPOINTX_RXCSRL_CLRDATATOG_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRL_CLRDATATOG_Pos)) /* Assigment of value for CLRDATATOG in the USBHS_ENDPOINTX_RXCSRL register */
#define USBHS_ENDPOINTX_RXCSRL_Msk            _UINT8_(0x91)                                        /* (USBHS_ENDPOINTX_RXCSRL) Register Mask  */

/* HOST_EPX mode */
#define USBHS_ENDPOINTX_RXCSRL_HOST_EPX_FIFOFULL_Pos _UINT8_(1)                                           /* (USBHS_ENDPOINTX_RXCSRL) This Bit Is Set When No More Packets Can Be Loaded Position */
#define USBHS_ENDPOINTX_RXCSRL_HOST_EPX_FIFOFULL_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRL_HOST_EPX_FIFOFULL_Pos) /* (USBHS_ENDPOINTX_RXCSRL) This Bit Is Set When No More Packets Can Be Loaded Mask */
#define USBHS_ENDPOINTX_RXCSRL_HOST_EPX_FIFOFULL(value) (USBHS_ENDPOINTX_RXCSRL_HOST_EPX_FIFOFULL_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRL_HOST_EPX_FIFOFULL_Pos))
#define USBHS_ENDPOINTX_RXCSRL_HOST_EPX_ERROR_Pos _UINT8_(2)                                           /* (USBHS_ENDPOINTX_RXCSRL) The USB Sets This Bit When 3 Attempts Have Been Made To Receive A Packet And No Data Packet Has Been Received. Position */
#define USBHS_ENDPOINTX_RXCSRL_HOST_EPX_ERROR_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRL_HOST_EPX_ERROR_Pos) /* (USBHS_ENDPOINTX_RXCSRL) The USB Sets This Bit When 3 Attempts Have Been Made To Receive A Packet And No Data Packet Has Been Received. Mask */
#define USBHS_ENDPOINTX_RXCSRL_HOST_EPX_ERROR(value) (USBHS_ENDPOINTX_RXCSRL_HOST_EPX_ERROR_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRL_HOST_EPX_ERROR_Pos))
#define USBHS_ENDPOINTX_RXCSRL_HOST_EPX_NAKTIMEOUT_Pos _UINT8_(3)                                           /* (USBHS_ENDPOINTX_RXCSRL) This Bit Is Set When RxPktRdy Is Set If The Data Packet Has A CRC Or Bit-stuff Error. Position */
#define USBHS_ENDPOINTX_RXCSRL_HOST_EPX_NAKTIMEOUT_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRL_HOST_EPX_NAKTIMEOUT_Pos) /* (USBHS_ENDPOINTX_RXCSRL) This Bit Is Set When RxPktRdy Is Set If The Data Packet Has A CRC Or Bit-stuff Error. Mask */
#define USBHS_ENDPOINTX_RXCSRL_HOST_EPX_NAKTIMEOUT(value) (USBHS_ENDPOINTX_RXCSRL_HOST_EPX_NAKTIMEOUT_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRL_HOST_EPX_NAKTIMEOUT_Pos))
#define USBHS_ENDPOINTX_RXCSRL_HOST_EPX_REQPKT_Pos _UINT8_(5)                                           /* (USBHS_ENDPOINTX_RXCSRL) The CPU Writes A 1 To This Bit To Request An IN Transaction. Position */
#define USBHS_ENDPOINTX_RXCSRL_HOST_EPX_REQPKT_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRL_HOST_EPX_REQPKT_Pos) /* (USBHS_ENDPOINTX_RXCSRL) The CPU Writes A 1 To This Bit To Request An IN Transaction. Mask */
#define USBHS_ENDPOINTX_RXCSRL_HOST_EPX_REQPKT(value) (USBHS_ENDPOINTX_RXCSRL_HOST_EPX_REQPKT_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRL_HOST_EPX_REQPKT_Pos))
#define USBHS_ENDPOINTX_RXCSRL_HOST_EPX_RXSTALL_Pos _UINT8_(6)                                           /* (USBHS_ENDPOINTX_RXCSRL) When A STALL Handshake Is Received, This Bit Is Set And An Interrupt Is Generated. Position */
#define USBHS_ENDPOINTX_RXCSRL_HOST_EPX_RXSTALL_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRL_HOST_EPX_RXSTALL_Pos) /* (USBHS_ENDPOINTX_RXCSRL) When A STALL Handshake Is Received, This Bit Is Set And An Interrupt Is Generated. Mask */
#define USBHS_ENDPOINTX_RXCSRL_HOST_EPX_RXSTALL(value) (USBHS_ENDPOINTX_RXCSRL_HOST_EPX_RXSTALL_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRL_HOST_EPX_RXSTALL_Pos))
#define USBHS_ENDPOINTX_RXCSRL_HOST_EPX_Msk   _UINT8_(0x6E)                                         /* (USBHS_ENDPOINTX_RXCSRL_HOST_EPX) Register Mask  */

/* PERIPHERAL_EPX mode */
#define USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_FIFOFULL_Pos _UINT8_(1)                                           /* (USBHS_ENDPOINTX_RXCSRL) This Bit Is Set When No More Packets Can Be Loaded Into The Rx FIFO. Position */
#define USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_FIFOFULL_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_FIFOFULL_Pos) /* (USBHS_ENDPOINTX_RXCSRL) This Bit Is Set When No More Packets Can Be Loaded Into The Rx FIFO. Mask */
#define USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_FIFOFULL(value) (USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_FIFOFULL_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_FIFOFULL_Pos))
#define USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_OVERRUN_Pos _UINT8_(2)                                           /* (USBHS_ENDPOINTX_RXCSRL) This Bit Is Set If An OUT Packet Cannot Be Loaded Into The Rx FIFO. Position */
#define USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_OVERRUN_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_OVERRUN_Pos) /* (USBHS_ENDPOINTX_RXCSRL) This Bit Is Set If An OUT Packet Cannot Be Loaded Into The Rx FIFO. Mask */
#define USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_OVERRUN(value) (USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_OVERRUN_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_OVERRUN_Pos))
#define USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_DATAERROR_Pos _UINT8_(3)                                           /* (USBHS_ENDPOINTX_RXCSRL) This Bit Is Set When RxPktRdy Is Set If The Data Packet Has A CRC Or Bit-stuff Error. Position */
#define USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_DATAERROR_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_DATAERROR_Pos) /* (USBHS_ENDPOINTX_RXCSRL) This Bit Is Set When RxPktRdy Is Set If The Data Packet Has A CRC Or Bit-stuff Error. Mask */
#define USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_DATAERROR(value) (USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_DATAERROR_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_DATAERROR_Pos))
#define USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_SENDSTALL_Pos _UINT8_(5)                                           /* (USBHS_ENDPOINTX_RXCSRL) The CPU Writes A 1 To This Bit To Issue A STALL Handshake. Position */
#define USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_SENDSTALL_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_SENDSTALL_Pos) /* (USBHS_ENDPOINTX_RXCSRL) The CPU Writes A 1 To This Bit To Issue A STALL Handshake. Mask */
#define USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_SENDSTALL(value) (USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_SENDSTALL_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_SENDSTALL_Pos))
#define USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_SENTSTALL_Pos _UINT8_(6)                                           /* (USBHS_ENDPOINTX_RXCSRL) This Bit Is Set When A STALL Handshake Is Transmitted. Position */
#define USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_SENTSTALL_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_SENTSTALL_Pos) /* (USBHS_ENDPOINTX_RXCSRL) This Bit Is Set When A STALL Handshake Is Transmitted. Mask */
#define USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_SENTSTALL(value) (USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_SENTSTALL_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_SENTSTALL_Pos))
#define USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX_Msk _UINT8_(0x6E)                                         /* (USBHS_ENDPOINTX_RXCSRL_PERIPHERAL_EPX) Register Mask  */


/* -------- USBHS_ENDPOINTX_RXCSRH : (USBHS Offset: 0x1017) (R/W 8) ENDPOINTX Additional Control And Status Bits for RX Endpoint 0 Or Endpoint 1-15 -------- */
#define USBHS_ENDPOINTX_RXCSRH_RESETVALUE     _UINT8_(0x00)                                        /*  (USBHS_ENDPOINTX_RXCSRH) ENDPOINTX Additional Control And Status Bits for RX Endpoint 0 Or Endpoint 1-15  Reset Value */

#define USBHS_ENDPOINTX_RXCSRH_DMAREQMODE_Pos _UINT8_(3)                                           /* (USBHS_ENDPOINTX_RXCSRH) The CPU Sets This Bit To Select DMA Request Mode Position */
#define USBHS_ENDPOINTX_RXCSRH_DMAREQMODE_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRH_DMAREQMODE_Pos) /* (USBHS_ENDPOINTX_RXCSRH) The CPU Sets This Bit To Select DMA Request Mode Mask */
#define USBHS_ENDPOINTX_RXCSRH_DMAREQMODE(value) (USBHS_ENDPOINTX_RXCSRH_DMAREQMODE_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRH_DMAREQMODE_Pos)) /* Assigment of value for DMAREQMODE in the USBHS_ENDPOINTX_RXCSRH register */
#define USBHS_ENDPOINTX_RXCSRH_DMAREQENAB_Pos _UINT8_(5)                                           /* (USBHS_ENDPOINTX_RXCSRH) The CPU Sets This Bit To Enable The DMA Request For The RX Endpoint Position */
#define USBHS_ENDPOINTX_RXCSRH_DMAREQENAB_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRH_DMAREQENAB_Pos) /* (USBHS_ENDPOINTX_RXCSRH) The CPU Sets This Bit To Enable The DMA Request For The RX Endpoint Mask */
#define USBHS_ENDPOINTX_RXCSRH_DMAREQENAB(value) (USBHS_ENDPOINTX_RXCSRH_DMAREQENAB_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRH_DMAREQENAB_Pos)) /* Assigment of value for DMAREQENAB in the USBHS_ENDPOINTX_RXCSRH register */
#define USBHS_ENDPOINTX_RXCSRH_Msk            _UINT8_(0x28)                                        /* (USBHS_ENDPOINTX_RXCSRH) Register Mask  */

/* HOST_EPX mode */
#define USBHS_ENDPOINTX_RXCSRH_HOST_EPX_INCOMPRX_Pos _UINT8_(0)                                           /* (USBHS_ENDPOINTX_RXCSRH) This Bit Is Set In A High-Bandwidth Isochronous/Interrupt Transfer If The Packet In The Rx FIFO Is Incomplete Position */
#define USBHS_ENDPOINTX_RXCSRH_HOST_EPX_INCOMPRX_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRH_HOST_EPX_INCOMPRX_Pos) /* (USBHS_ENDPOINTX_RXCSRH) This Bit Is Set In A High-Bandwidth Isochronous/Interrupt Transfer If The Packet In The Rx FIFO Is Incomplete Mask */
#define USBHS_ENDPOINTX_RXCSRH_HOST_EPX_INCOMPRX(value) (USBHS_ENDPOINTX_RXCSRH_HOST_EPX_INCOMPRX_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRH_HOST_EPX_INCOMPRX_Pos))
#define USBHS_ENDPOINTX_RXCSRH_HOST_EPX_DATATOGGLE_Pos _UINT8_(1)                                           /* (USBHS_ENDPOINTX_RXCSRH) When Read, This Bit Indicates The Current State Of The Endpoint Position */
#define USBHS_ENDPOINTX_RXCSRH_HOST_EPX_DATATOGGLE_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRH_HOST_EPX_DATATOGGLE_Pos) /* (USBHS_ENDPOINTX_RXCSRH) When Read, This Bit Indicates The Current State Of The Endpoint Mask */
#define USBHS_ENDPOINTX_RXCSRH_HOST_EPX_DATATOGGLE(value) (USBHS_ENDPOINTX_RXCSRH_HOST_EPX_DATATOGGLE_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRH_HOST_EPX_DATATOGGLE_Pos))
#define USBHS_ENDPOINTX_RXCSRH_HOST_EPX_DATATOGGLEWRTENABLE_Pos _UINT8_(2)                                           /* (USBHS_ENDPOINTX_RXCSRH) The CPU Writes A 1 To This Bit To Enable The Current State Of The Endpoint 0 Data Toggle To Be Written Position */
#define USBHS_ENDPOINTX_RXCSRH_HOST_EPX_DATATOGGLEWRTENABLE_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRH_HOST_EPX_DATATOGGLEWRTENABLE_Pos) /* (USBHS_ENDPOINTX_RXCSRH) The CPU Writes A 1 To This Bit To Enable The Current State Of The Endpoint 0 Data Toggle To Be Written Mask */
#define USBHS_ENDPOINTX_RXCSRH_HOST_EPX_DATATOGGLEWRTENABLE(value) (USBHS_ENDPOINTX_RXCSRH_HOST_EPX_DATATOGGLEWRTENABLE_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRH_HOST_EPX_DATATOGGLEWRTENABLE_Pos))
#define USBHS_ENDPOINTX_RXCSRH_HOST_EPX_PIDERROR_Pos _UINT8_(4)                                           /* (USBHS_ENDPOINTX_RXCSRH) Indicates A PID Error In The Received Packet Position */
#define USBHS_ENDPOINTX_RXCSRH_HOST_EPX_PIDERROR_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRH_HOST_EPX_PIDERROR_Pos) /* (USBHS_ENDPOINTX_RXCSRH) Indicates A PID Error In The Received Packet Mask */
#define USBHS_ENDPOINTX_RXCSRH_HOST_EPX_PIDERROR(value) (USBHS_ENDPOINTX_RXCSRH_HOST_EPX_PIDERROR_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRH_HOST_EPX_PIDERROR_Pos))
#define USBHS_ENDPOINTX_RXCSRH_HOST_EPX_AUTOREQ_Pos _UINT8_(6)                                           /* (USBHS_ENDPOINTX_RXCSRH) If The CPU Sets This Bit, The ReqPkt Bit Will Be Automatically Set When The RxPktRdy Bit Is Cleared. Position */
#define USBHS_ENDPOINTX_RXCSRH_HOST_EPX_AUTOREQ_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRH_HOST_EPX_AUTOREQ_Pos) /* (USBHS_ENDPOINTX_RXCSRH) If The CPU Sets This Bit, The ReqPkt Bit Will Be Automatically Set When The RxPktRdy Bit Is Cleared. Mask */
#define USBHS_ENDPOINTX_RXCSRH_HOST_EPX_AUTOREQ(value) (USBHS_ENDPOINTX_RXCSRH_HOST_EPX_AUTOREQ_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRH_HOST_EPX_AUTOREQ_Pos))
#define USBHS_ENDPOINTX_RXCSRH_HOST_EPX_AUTOCLEAR_Pos _UINT8_(7)                                           /* (USBHS_ENDPOINTX_RXCSRH) If The CPU Sets This Bit, TxPktRdy Will Be Automatically Cleared When A Packet Of RxMaxP Bytes Has Been Unloaded From The RX FIFO Position */
#define USBHS_ENDPOINTX_RXCSRH_HOST_EPX_AUTOCLEAR_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRH_HOST_EPX_AUTOCLEAR_Pos) /* (USBHS_ENDPOINTX_RXCSRH) If The CPU Sets This Bit, TxPktRdy Will Be Automatically Cleared When A Packet Of RxMaxP Bytes Has Been Unloaded From The RX FIFO Mask */
#define USBHS_ENDPOINTX_RXCSRH_HOST_EPX_AUTOCLEAR(value) (USBHS_ENDPOINTX_RXCSRH_HOST_EPX_AUTOCLEAR_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRH_HOST_EPX_AUTOCLEAR_Pos))
#define USBHS_ENDPOINTX_RXCSRH_HOST_EPX_Msk   _UINT8_(0xD7)                                         /* (USBHS_ENDPOINTX_RXCSRH_HOST_EPX) Register Mask  */

/* PERIPHERAL_EPX mode */
#define USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_INCOMPRX_Pos _UINT8_(0)                                           /* (USBHS_ENDPOINTX_RXCSRH) This Bit Is Set In A High-Bandwidth Isochronous/Interrupt Transfer If The Packet In The Rx FIFO Is Incomplete Because Parts Of The Data Were Not Received. Position */
#define USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_INCOMPRX_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_INCOMPRX_Pos) /* (USBHS_ENDPOINTX_RXCSRH) This Bit Is Set In A High-Bandwidth Isochronous/Interrupt Transfer If The Packet In The Rx FIFO Is Incomplete Because Parts Of The Data Were Not Received. Mask */
#define USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_INCOMPRX(value) (USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_INCOMPRX_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_INCOMPRX_Pos))
#define USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_DISNYET_Pos _UINT8_(4)                                           /* (USBHS_ENDPOINTX_RXCSRH) The CPU Sets This Bit To Disable The Sending Of NYET Handshakes Position */
#define USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_DISNYET_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_DISNYET_Pos) /* (USBHS_ENDPOINTX_RXCSRH) The CPU Sets This Bit To Disable The Sending Of NYET Handshakes Mask */
#define USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_DISNYET(value) (USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_DISNYET_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_DISNYET_Pos))
#define USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_ISO_Pos _UINT8_(6)                                           /* (USBHS_ENDPOINTX_RXCSRH) The CPU Sets This Bit To Enable the RX Endpoint For Isochronous Transfers Position */
#define USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_ISO_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_ISO_Pos) /* (USBHS_ENDPOINTX_RXCSRH) The CPU Sets This Bit To Enable the RX Endpoint For Isochronous Transfers Mask */
#define USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_ISO(value) (USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_ISO_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_ISO_Pos))
#define USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_AUTOCLEAR_Pos _UINT8_(7)                                           /* (USBHS_ENDPOINTX_RXCSRH) If The CPU Sets This Bit Then The RxPktRdy Bit Will Be Automatically Cleared Whean A Packet Of RxMaxP Bytes Has Benn Unloaded Froim The Rx FIFO Position */
#define USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_AUTOCLEAR_Msk (_UINT8_(0x1) << USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_AUTOCLEAR_Pos) /* (USBHS_ENDPOINTX_RXCSRH) If The CPU Sets This Bit Then The RxPktRdy Bit Will Be Automatically Cleared Whean A Packet Of RxMaxP Bytes Has Benn Unloaded Froim The Rx FIFO Mask */
#define USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_AUTOCLEAR(value) (USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_AUTOCLEAR_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_AUTOCLEAR_Pos))
#define USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX_Msk _UINT8_(0xD1)                                         /* (USBHS_ENDPOINTX_RXCSRH_PERIPHERAL_EPX) Register Mask  */


/* -------- USBHS_ENDPOINTX_RXCOUNT : (USBHS Offset: 0x1018) ( R/ 16) ENDPOINTX Number Of Data Bytes In The Packet Currently In Line To Be Read From The RX FIFO. -------- */
#define USBHS_ENDPOINTX_RXCOUNT_RESETVALUE    _UINT16_(0x00)                                       /*  (USBHS_ENDPOINTX_RXCOUNT) ENDPOINTX Number Of Data Bytes In The Packet Currently In Line To Be Read From The RX FIFO.  Reset Value */

#define USBHS_ENDPOINTX_RXCOUNT_ENDPOINTRXCOUNT_Pos _UINT16_(0)                                          /* (USBHS_ENDPOINTX_RXCOUNT) Number Of Data Bytes In The Packet Currently In Line To Be Read From The RX FIFO. Position */
#define USBHS_ENDPOINTX_RXCOUNT_ENDPOINTRXCOUNT_Msk (_UINT16_(0x3FFF) << USBHS_ENDPOINTX_RXCOUNT_ENDPOINTRXCOUNT_Pos) /* (USBHS_ENDPOINTX_RXCOUNT) Number Of Data Bytes In The Packet Currently In Line To Be Read From The RX FIFO. Mask */
#define USBHS_ENDPOINTX_RXCOUNT_ENDPOINTRXCOUNT(value) (USBHS_ENDPOINTX_RXCOUNT_ENDPOINTRXCOUNT_Msk & (_UINT16_(value) << USBHS_ENDPOINTX_RXCOUNT_ENDPOINTRXCOUNT_Pos)) /* Assigment of value for ENDPOINTRXCOUNT in the USBHS_ENDPOINTX_RXCOUNT register */
#define USBHS_ENDPOINTX_RXCOUNT_Msk           _UINT16_(0x3FFF)                                     /* (USBHS_ENDPOINTX_RXCOUNT) Register Mask  */


/* -------- USBHS_ENDPOINT0_COUNT0 : (USBHS Offset: 0x1018) ( R/ 8) ENDPOINT0 Number Of Received Bytes In Endpoint 0 FIFO -------- */
#define USBHS_ENDPOINT0_COUNT0_RESETVALUE     _UINT8_(0x00)                                        /*  (USBHS_ENDPOINT0_COUNT0) ENDPOINT0 Number Of Received Bytes In Endpoint 0 FIFO  Reset Value */

#define USBHS_ENDPOINT0_COUNT0_EP0RXCOUNT_Pos _UINT8_(0)                                           /* (USBHS_ENDPOINT0_COUNT0) Number Of Received Data Bytes In Endpoint 0 FIFO Position */
#define USBHS_ENDPOINT0_COUNT0_EP0RXCOUNT_Msk (_UINT8_(0x7F) << USBHS_ENDPOINT0_COUNT0_EP0RXCOUNT_Pos) /* (USBHS_ENDPOINT0_COUNT0) Number Of Received Data Bytes In Endpoint 0 FIFO Mask */
#define USBHS_ENDPOINT0_COUNT0_EP0RXCOUNT(value) (USBHS_ENDPOINT0_COUNT0_EP0RXCOUNT_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_COUNT0_EP0RXCOUNT_Pos)) /* Assigment of value for EP0RXCOUNT in the USBHS_ENDPOINT0_COUNT0 register */
#define USBHS_ENDPOINT0_COUNT0_Msk            _UINT8_(0x7F)                                        /* (USBHS_ENDPOINT0_COUNT0) Register Mask  */


/* -------- USBHS_ENDPOINTX_TXTYPE : (USBHS Offset: 0x101A) (R/W 8) ENDPOINTX Host Mode Only: Should Be Written With The Endpoint Number To Be Targeted By The Endpoint -------- */
#define USBHS_ENDPOINTX_TXTYPE_RESETVALUE     _UINT8_(0x00)                                        /*  (USBHS_ENDPOINTX_TXTYPE) ENDPOINTX Host Mode Only: Should Be Written With The Endpoint Number To Be Targeted By The Endpoint  Reset Value */

#define USBHS_ENDPOINTX_TXTYPE_ENDPOINTNUMBER_Pos _UINT8_(0)                                           /* (USBHS_ENDPOINTX_TXTYPE) the cpu should set this value to the endpoint number contained in the tx endpoint descriptor Position */
#define USBHS_ENDPOINTX_TXTYPE_ENDPOINTNUMBER_Msk (_UINT8_(0xF) << USBHS_ENDPOINTX_TXTYPE_ENDPOINTNUMBER_Pos) /* (USBHS_ENDPOINTX_TXTYPE) the cpu should set this value to the endpoint number contained in the tx endpoint descriptor Mask */
#define USBHS_ENDPOINTX_TXTYPE_ENDPOINTNUMBER(value) (USBHS_ENDPOINTX_TXTYPE_ENDPOINTNUMBER_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXTYPE_ENDPOINTNUMBER_Pos)) /* Assigment of value for ENDPOINTNUMBER in the USBHS_ENDPOINTX_TXTYPE register */
#define USBHS_ENDPOINTX_TXTYPE_PROTOCOL_Pos   _UINT8_(4)                                           /* (USBHS_ENDPOINTX_TXTYPE) the cpu should set this to select the required protocol for the tx endpoint 00: control 01: isochronous 10: bulk 11: interrupt Position */
#define USBHS_ENDPOINTX_TXTYPE_PROTOCOL_Msk   (_UINT8_(0x3) << USBHS_ENDPOINTX_TXTYPE_PROTOCOL_Pos) /* (USBHS_ENDPOINTX_TXTYPE) the cpu should set this to select the required protocol for the tx endpoint 00: control 01: isochronous 10: bulk 11: interrupt Mask */
#define USBHS_ENDPOINTX_TXTYPE_PROTOCOL(value) (USBHS_ENDPOINTX_TXTYPE_PROTOCOL_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXTYPE_PROTOCOL_Pos)) /* Assigment of value for PROTOCOL in the USBHS_ENDPOINTX_TXTYPE register */
#define   USBHS_ENDPOINTX_TXTYPE_PROTOCOL_CONTROL_Val _UINT8_(0x0)                                         /* (USBHS_ENDPOINTX_TXTYPE)   */
#define   USBHS_ENDPOINTX_TXTYPE_PROTOCOL_ISOCHRONOUS_Val _UINT8_(0x1)                                         /* (USBHS_ENDPOINTX_TXTYPE)   */
#define   USBHS_ENDPOINTX_TXTYPE_PROTOCOL_BULK_Val _UINT8_(0x2)                                         /* (USBHS_ENDPOINTX_TXTYPE)   */
#define   USBHS_ENDPOINTX_TXTYPE_PROTOCOL_INTERRUPT_Val _UINT8_(0x3)                                         /* (USBHS_ENDPOINTX_TXTYPE)   */
#define USBHS_ENDPOINTX_TXTYPE_PROTOCOL_CONTROL (USBHS_ENDPOINTX_TXTYPE_PROTOCOL_CONTROL_Val << USBHS_ENDPOINTX_TXTYPE_PROTOCOL_Pos) /* (USBHS_ENDPOINTX_TXTYPE)  Position  */
#define USBHS_ENDPOINTX_TXTYPE_PROTOCOL_ISOCHRONOUS (USBHS_ENDPOINTX_TXTYPE_PROTOCOL_ISOCHRONOUS_Val << USBHS_ENDPOINTX_TXTYPE_PROTOCOL_Pos) /* (USBHS_ENDPOINTX_TXTYPE)  Position  */
#define USBHS_ENDPOINTX_TXTYPE_PROTOCOL_BULK  (USBHS_ENDPOINTX_TXTYPE_PROTOCOL_BULK_Val << USBHS_ENDPOINTX_TXTYPE_PROTOCOL_Pos) /* (USBHS_ENDPOINTX_TXTYPE)  Position  */
#define USBHS_ENDPOINTX_TXTYPE_PROTOCOL_INTERRUPT (USBHS_ENDPOINTX_TXTYPE_PROTOCOL_INTERRUPT_Val << USBHS_ENDPOINTX_TXTYPE_PROTOCOL_Pos) /* (USBHS_ENDPOINTX_TXTYPE)  Position  */
#define USBHS_ENDPOINTX_TXTYPE_SPEED_Pos      _UINT8_(6)                                           /* (USBHS_ENDPOINTX_TXTYPE) operating speed of the target device when the core is configured with the multipoint option: 00: unused (note: if selected, the target will be assumed to be using the same connection speed as the core.) 01: high 10: full 11: low Position */
#define USBHS_ENDPOINTX_TXTYPE_SPEED_Msk      (_UINT8_(0x3) << USBHS_ENDPOINTX_TXTYPE_SPEED_Pos)   /* (USBHS_ENDPOINTX_TXTYPE) operating speed of the target device when the core is configured with the multipoint option: 00: unused (note: if selected, the target will be assumed to be using the same connection speed as the core.) 01: high 10: full 11: low Mask */
#define USBHS_ENDPOINTX_TXTYPE_SPEED(value)   (USBHS_ENDPOINTX_TXTYPE_SPEED_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXTYPE_SPEED_Pos)) /* Assigment of value for SPEED in the USBHS_ENDPOINTX_TXTYPE register */
#define   USBHS_ENDPOINTX_TXTYPE_SPEED_HIGH_Val _UINT8_(0x1)                                         /* (USBHS_ENDPOINTX_TXTYPE) Device In High Speed  */
#define   USBHS_ENDPOINTX_TXTYPE_SPEED_FULL_Val _UINT8_(0x2)                                         /* (USBHS_ENDPOINTX_TXTYPE) Device In Full Speed  */
#define   USBHS_ENDPOINTX_TXTYPE_SPEED_LOW_Val _UINT8_(0x3)                                         /* (USBHS_ENDPOINTX_TXTYPE) Device In Low Speed  */
#define USBHS_ENDPOINTX_TXTYPE_SPEED_HIGH     (USBHS_ENDPOINTX_TXTYPE_SPEED_HIGH_Val << USBHS_ENDPOINTX_TXTYPE_SPEED_Pos) /* (USBHS_ENDPOINTX_TXTYPE) Device In High Speed Position  */
#define USBHS_ENDPOINTX_TXTYPE_SPEED_FULL     (USBHS_ENDPOINTX_TXTYPE_SPEED_FULL_Val << USBHS_ENDPOINTX_TXTYPE_SPEED_Pos) /* (USBHS_ENDPOINTX_TXTYPE) Device In Full Speed Position  */
#define USBHS_ENDPOINTX_TXTYPE_SPEED_LOW      (USBHS_ENDPOINTX_TXTYPE_SPEED_LOW_Val << USBHS_ENDPOINTX_TXTYPE_SPEED_Pos) /* (USBHS_ENDPOINTX_TXTYPE) Device In Low Speed Position  */
#define USBHS_ENDPOINTX_TXTYPE_Msk            _UINT8_(0xFF)                                        /* (USBHS_ENDPOINTX_TXTYPE) Register Mask  */


/* -------- USBHS_ENDPOINT0_TYPE0 : (USBHS Offset: 0x101A) (R/W 8) ENDPOINT0 Host Mode Only: Operating Speed Of The Targeted Device -------- */
#define USBHS_ENDPOINT0_TYPE0_RESETVALUE      _UINT8_(0x00)                                        /*  (USBHS_ENDPOINT0_TYPE0) ENDPOINT0 Host Mode Only: Operating Speed Of The Targeted Device  Reset Value */

#define USBHS_ENDPOINT0_TYPE0_SPEED_Pos       _UINT8_(6)                                           /* (USBHS_ENDPOINT0_TYPE0) Operating Speed Of The Target Device Position */
#define USBHS_ENDPOINT0_TYPE0_SPEED_Msk       (_UINT8_(0x3) << USBHS_ENDPOINT0_TYPE0_SPEED_Pos)    /* (USBHS_ENDPOINT0_TYPE0) Operating Speed Of The Target Device Mask */
#define USBHS_ENDPOINT0_TYPE0_SPEED(value)    (USBHS_ENDPOINT0_TYPE0_SPEED_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_TYPE0_SPEED_Pos)) /* Assigment of value for SPEED in the USBHS_ENDPOINT0_TYPE0 register */
#define   USBHS_ENDPOINT0_TYPE0_SPEED_HIGH_Val _UINT8_(0x1)                                         /* (USBHS_ENDPOINT0_TYPE0) Device In High Speed  */
#define   USBHS_ENDPOINT0_TYPE0_SPEED_FULL_Val _UINT8_(0x2)                                         /* (USBHS_ENDPOINT0_TYPE0) Device In Full Speed  */
#define   USBHS_ENDPOINT0_TYPE0_SPEED_LOW_Val _UINT8_(0x3)                                         /* (USBHS_ENDPOINT0_TYPE0) Device In Low Speed  */
#define USBHS_ENDPOINT0_TYPE0_SPEED_HIGH      (USBHS_ENDPOINT0_TYPE0_SPEED_HIGH_Val << USBHS_ENDPOINT0_TYPE0_SPEED_Pos) /* (USBHS_ENDPOINT0_TYPE0) Device In High Speed Position  */
#define USBHS_ENDPOINT0_TYPE0_SPEED_FULL      (USBHS_ENDPOINT0_TYPE0_SPEED_FULL_Val << USBHS_ENDPOINT0_TYPE0_SPEED_Pos) /* (USBHS_ENDPOINT0_TYPE0) Device In Full Speed Position  */
#define USBHS_ENDPOINT0_TYPE0_SPEED_LOW       (USBHS_ENDPOINT0_TYPE0_SPEED_LOW_Val << USBHS_ENDPOINT0_TYPE0_SPEED_Pos) /* (USBHS_ENDPOINT0_TYPE0) Device In Low Speed Position  */
#define USBHS_ENDPOINT0_TYPE0_Msk             _UINT8_(0xC0)                                        /* (USBHS_ENDPOINT0_TYPE0) Register Mask  */


/* -------- USBHS_ENDPOINTX_TXINTERVAL : (USBHS Offset: 0x101B) (R/W 8) ENDPOINTX Host Mode Only: Defines The Polling Interval For The Currently Selected TX Endpoint. -------- */
#define USBHS_ENDPOINTX_TXINTERVAL_RESETVALUE _UINT8_(0x00)                                        /*  (USBHS_ENDPOINTX_TXINTERVAL) ENDPOINTX Host Mode Only: Defines The Polling Interval For The Currently Selected TX Endpoint.  Reset Value */

#define USBHS_ENDPOINTX_TXINTERVAL_TXPOLLINGINTERVAL_Pos _UINT8_(0)                                           /* (USBHS_ENDPOINTX_TXINTERVAL) polling interval Position */
#define USBHS_ENDPOINTX_TXINTERVAL_TXPOLLINGINTERVAL_Msk (_UINT8_(0xFF) << USBHS_ENDPOINTX_TXINTERVAL_TXPOLLINGINTERVAL_Pos) /* (USBHS_ENDPOINTX_TXINTERVAL) polling interval Mask */
#define USBHS_ENDPOINTX_TXINTERVAL_TXPOLLINGINTERVAL(value) (USBHS_ENDPOINTX_TXINTERVAL_TXPOLLINGINTERVAL_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_TXINTERVAL_TXPOLLINGINTERVAL_Pos)) /* Assigment of value for TXPOLLINGINTERVAL in the USBHS_ENDPOINTX_TXINTERVAL register */
#define USBHS_ENDPOINTX_TXINTERVAL_Msk        _UINT8_(0xFF)                                        /* (USBHS_ENDPOINTX_TXINTERVAL) Register Mask  */


/* -------- USBHS_ENDPOINT0_NAKLIMIT0 : (USBHS Offset: 0x101B) (R/W 8) ENDPOINT0 Host Mode Only: Sets The NAK Response Timeout On Endpoint 0. -------- */
#define USBHS_ENDPOINT0_NAKLIMIT0_RESETVALUE  _UINT8_(0x00)                                        /*  (USBHS_ENDPOINT0_NAKLIMIT0) ENDPOINT0 Host Mode Only: Sets The NAK Response Timeout On Endpoint 0.  Reset Value */

#define USBHS_ENDPOINT0_NAKLIMIT0_EP0NAKLIMIT_Pos _UINT8_(0)                                           /* (USBHS_ENDPOINT0_NAKLIMIT0) Number Of Frames/Microframes After Which Endpoint 0 Should Timeout Position */
#define USBHS_ENDPOINT0_NAKLIMIT0_EP0NAKLIMIT_Msk (_UINT8_(0x1F) << USBHS_ENDPOINT0_NAKLIMIT0_EP0NAKLIMIT_Pos) /* (USBHS_ENDPOINT0_NAKLIMIT0) Number Of Frames/Microframes After Which Endpoint 0 Should Timeout Mask */
#define USBHS_ENDPOINT0_NAKLIMIT0_EP0NAKLIMIT(value) (USBHS_ENDPOINT0_NAKLIMIT0_EP0NAKLIMIT_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_NAKLIMIT0_EP0NAKLIMIT_Pos)) /* Assigment of value for EP0NAKLIMIT in the USBHS_ENDPOINT0_NAKLIMIT0 register */
#define USBHS_ENDPOINT0_NAKLIMIT0_Msk         _UINT8_(0x1F)                                        /* (USBHS_ENDPOINT0_NAKLIMIT0) Register Mask  */


/* -------- USBHS_ENDPOINTX_RXTYPE : (USBHS Offset: 0x101C) (R/W 8) ENDPOINTX Host Mode Only: Should Be Written With The Endpoint Number To Be Targeted By The Endpoint -------- */
#define USBHS_ENDPOINTX_RXTYPE_RESETVALUE     _UINT8_(0x00)                                        /*  (USBHS_ENDPOINTX_RXTYPE) ENDPOINTX Host Mode Only: Should Be Written With The Endpoint Number To Be Targeted By The Endpoint  Reset Value */

#define USBHS_ENDPOINTX_RXTYPE_ENDPOINTNUMBER_Pos _UINT8_(0)                                           /* (USBHS_ENDPOINTX_RXTYPE) the cpu should set this value to the endpoint number contained in the rx endpoint descriptor returned to the musbmhdrc during device enumeration. Position */
#define USBHS_ENDPOINTX_RXTYPE_ENDPOINTNUMBER_Msk (_UINT8_(0xF) << USBHS_ENDPOINTX_RXTYPE_ENDPOINTNUMBER_Pos) /* (USBHS_ENDPOINTX_RXTYPE) the cpu should set this value to the endpoint number contained in the rx endpoint descriptor returned to the musbmhdrc during device enumeration. Mask */
#define USBHS_ENDPOINTX_RXTYPE_ENDPOINTNUMBER(value) (USBHS_ENDPOINTX_RXTYPE_ENDPOINTNUMBER_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXTYPE_ENDPOINTNUMBER_Pos)) /* Assigment of value for ENDPOINTNUMBER in the USBHS_ENDPOINTX_RXTYPE register */
#define USBHS_ENDPOINTX_RXTYPE_PROTOCOL_Pos   _UINT8_(4)                                           /* (USBHS_ENDPOINTX_RXTYPE) the cpu should set this to select the required protocol for the rx endpoint 00: control 01: isochronous 10: bulk 11: interrupt Position */
#define USBHS_ENDPOINTX_RXTYPE_PROTOCOL_Msk   (_UINT8_(0x3) << USBHS_ENDPOINTX_RXTYPE_PROTOCOL_Pos) /* (USBHS_ENDPOINTX_RXTYPE) the cpu should set this to select the required protocol for the rx endpoint 00: control 01: isochronous 10: bulk 11: interrupt Mask */
#define USBHS_ENDPOINTX_RXTYPE_PROTOCOL(value) (USBHS_ENDPOINTX_RXTYPE_PROTOCOL_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXTYPE_PROTOCOL_Pos)) /* Assigment of value for PROTOCOL in the USBHS_ENDPOINTX_RXTYPE register */
#define   USBHS_ENDPOINTX_RXTYPE_PROTOCOL_CONTROL_Val _UINT8_(0x0)                                         /* (USBHS_ENDPOINTX_RXTYPE)   */
#define   USBHS_ENDPOINTX_RXTYPE_PROTOCOL_ISOCHRONOUS_Val _UINT8_(0x1)                                         /* (USBHS_ENDPOINTX_RXTYPE)   */
#define   USBHS_ENDPOINTX_RXTYPE_PROTOCOL_BULK_Val _UINT8_(0x2)                                         /* (USBHS_ENDPOINTX_RXTYPE)   */
#define   USBHS_ENDPOINTX_RXTYPE_PROTOCOL_INTERRUPT_Val _UINT8_(0x3)                                         /* (USBHS_ENDPOINTX_RXTYPE)   */
#define USBHS_ENDPOINTX_RXTYPE_PROTOCOL_CONTROL (USBHS_ENDPOINTX_RXTYPE_PROTOCOL_CONTROL_Val << USBHS_ENDPOINTX_RXTYPE_PROTOCOL_Pos) /* (USBHS_ENDPOINTX_RXTYPE)  Position  */
#define USBHS_ENDPOINTX_RXTYPE_PROTOCOL_ISOCHRONOUS (USBHS_ENDPOINTX_RXTYPE_PROTOCOL_ISOCHRONOUS_Val << USBHS_ENDPOINTX_RXTYPE_PROTOCOL_Pos) /* (USBHS_ENDPOINTX_RXTYPE)  Position  */
#define USBHS_ENDPOINTX_RXTYPE_PROTOCOL_BULK  (USBHS_ENDPOINTX_RXTYPE_PROTOCOL_BULK_Val << USBHS_ENDPOINTX_RXTYPE_PROTOCOL_Pos) /* (USBHS_ENDPOINTX_RXTYPE)  Position  */
#define USBHS_ENDPOINTX_RXTYPE_PROTOCOL_INTERRUPT (USBHS_ENDPOINTX_RXTYPE_PROTOCOL_INTERRUPT_Val << USBHS_ENDPOINTX_RXTYPE_PROTOCOL_Pos) /* (USBHS_ENDPOINTX_RXTYPE)  Position  */
#define USBHS_ENDPOINTX_RXTYPE_SPEED_Pos      _UINT8_(6)                                           /* (USBHS_ENDPOINTX_RXTYPE) operating speed of the target device when the core is configured with the multipoint option: 00: unused (note: if selected, the target will be assumed to be using the same connection speed as the core.) 01: high 10: full 11: low Position */
#define USBHS_ENDPOINTX_RXTYPE_SPEED_Msk      (_UINT8_(0x3) << USBHS_ENDPOINTX_RXTYPE_SPEED_Pos)   /* (USBHS_ENDPOINTX_RXTYPE) operating speed of the target device when the core is configured with the multipoint option: 00: unused (note: if selected, the target will be assumed to be using the same connection speed as the core.) 01: high 10: full 11: low Mask */
#define USBHS_ENDPOINTX_RXTYPE_SPEED(value)   (USBHS_ENDPOINTX_RXTYPE_SPEED_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXTYPE_SPEED_Pos)) /* Assigment of value for SPEED in the USBHS_ENDPOINTX_RXTYPE register */
#define   USBHS_ENDPOINTX_RXTYPE_SPEED_UNUSED_Val _UINT8_(0x0)                                         /* (USBHS_ENDPOINTX_RXTYPE)   */
#define   USBHS_ENDPOINTX_RXTYPE_SPEED_HIGH_Val _UINT8_(0x1)                                         /* (USBHS_ENDPOINTX_RXTYPE)   */
#define   USBHS_ENDPOINTX_RXTYPE_SPEED_FULL_Val _UINT8_(0x2)                                         /* (USBHS_ENDPOINTX_RXTYPE)   */
#define   USBHS_ENDPOINTX_RXTYPE_SPEED_LOW_Val _UINT8_(0x3)                                         /* (USBHS_ENDPOINTX_RXTYPE)   */
#define USBHS_ENDPOINTX_RXTYPE_SPEED_UNUSED   (USBHS_ENDPOINTX_RXTYPE_SPEED_UNUSED_Val << USBHS_ENDPOINTX_RXTYPE_SPEED_Pos) /* (USBHS_ENDPOINTX_RXTYPE)  Position  */
#define USBHS_ENDPOINTX_RXTYPE_SPEED_HIGH     (USBHS_ENDPOINTX_RXTYPE_SPEED_HIGH_Val << USBHS_ENDPOINTX_RXTYPE_SPEED_Pos) /* (USBHS_ENDPOINTX_RXTYPE)  Position  */
#define USBHS_ENDPOINTX_RXTYPE_SPEED_FULL     (USBHS_ENDPOINTX_RXTYPE_SPEED_FULL_Val << USBHS_ENDPOINTX_RXTYPE_SPEED_Pos) /* (USBHS_ENDPOINTX_RXTYPE)  Position  */
#define USBHS_ENDPOINTX_RXTYPE_SPEED_LOW      (USBHS_ENDPOINTX_RXTYPE_SPEED_LOW_Val << USBHS_ENDPOINTX_RXTYPE_SPEED_Pos) /* (USBHS_ENDPOINTX_RXTYPE)  Position  */
#define USBHS_ENDPOINTX_RXTYPE_Msk            _UINT8_(0xFF)                                        /* (USBHS_ENDPOINTX_RXTYPE) Register Mask  */


/* -------- USBHS_ENDPOINTX_RXINTERVAL : (USBHS Offset: 0x101D) (R/W 8) ENDPOINTX Host Mode Only: Defines The Polling Interval For The Currently Selected RX Endpoint. -------- */
#define USBHS_ENDPOINTX_RXINTERVAL_RESETVALUE _UINT8_(0x00)                                        /*  (USBHS_ENDPOINTX_RXINTERVAL) ENDPOINTX Host Mode Only: Defines The Polling Interval For The Currently Selected RX Endpoint.  Reset Value */

#define USBHS_ENDPOINTX_RXINTERVAL_RXPOLLINGINTERVAL_Pos _UINT8_(0)                                           /* (USBHS_ENDPOINTX_RXINTERVAL) polling interval Position */
#define USBHS_ENDPOINTX_RXINTERVAL_RXPOLLINGINTERVAL_Msk (_UINT8_(0xFF) << USBHS_ENDPOINTX_RXINTERVAL_RXPOLLINGINTERVAL_Pos) /* (USBHS_ENDPOINTX_RXINTERVAL) polling interval Mask */
#define USBHS_ENDPOINTX_RXINTERVAL_RXPOLLINGINTERVAL(value) (USBHS_ENDPOINTX_RXINTERVAL_RXPOLLINGINTERVAL_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_RXINTERVAL_RXPOLLINGINTERVAL_Pos)) /* Assigment of value for RXPOLLINGINTERVAL in the USBHS_ENDPOINTX_RXINTERVAL register */
#define USBHS_ENDPOINTX_RXINTERVAL_Msk        _UINT8_(0xFF)                                        /* (USBHS_ENDPOINTX_RXINTERVAL) Register Mask  */


/* -------- USBHS_ENDPOINTX_FIFOSIZE : (USBHS Offset: 0x101F) ( R/ 8) ENDPOINTX Read Only Register That Returns The Sizes Of The FIFO's Associated With The Selected Additional TX/RX Endpoints. INDEX Regsiter should be set 1-15 -------- */
#define USBHS_ENDPOINTX_FIFOSIZE_RESETVALUE   _UINT8_(0x00)                                        /*  (USBHS_ENDPOINTX_FIFOSIZE) ENDPOINTX Read Only Register That Returns The Sizes Of The FIFO's Associated With The Selected Additional TX/RX Endpoints. INDEX Regsiter should be set 1-15  Reset Value */

#define USBHS_ENDPOINTX_FIFOSIZE_TXFIFOSIZE_Pos _UINT8_(0)                                           /* (USBHS_ENDPOINTX_FIFOSIZE) Tx FIFO Size Position */
#define USBHS_ENDPOINTX_FIFOSIZE_TXFIFOSIZE_Msk (_UINT8_(0xF) << USBHS_ENDPOINTX_FIFOSIZE_TXFIFOSIZE_Pos) /* (USBHS_ENDPOINTX_FIFOSIZE) Tx FIFO Size Mask */
#define USBHS_ENDPOINTX_FIFOSIZE_TXFIFOSIZE(value) (USBHS_ENDPOINTX_FIFOSIZE_TXFIFOSIZE_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_FIFOSIZE_TXFIFOSIZE_Pos)) /* Assigment of value for TXFIFOSIZE in the USBHS_ENDPOINTX_FIFOSIZE register */
#define USBHS_ENDPOINTX_FIFOSIZE_RXFIFOSIZE_Pos _UINT8_(4)                                           /* (USBHS_ENDPOINTX_FIFOSIZE) Rx FIFO Size Position */
#define USBHS_ENDPOINTX_FIFOSIZE_RXFIFOSIZE_Msk (_UINT8_(0xF) << USBHS_ENDPOINTX_FIFOSIZE_RXFIFOSIZE_Pos) /* (USBHS_ENDPOINTX_FIFOSIZE) Rx FIFO Size Mask */
#define USBHS_ENDPOINTX_FIFOSIZE_RXFIFOSIZE(value) (USBHS_ENDPOINTX_FIFOSIZE_RXFIFOSIZE_Msk & (_UINT8_(value) << USBHS_ENDPOINTX_FIFOSIZE_RXFIFOSIZE_Pos)) /* Assigment of value for RXFIFOSIZE in the USBHS_ENDPOINTX_FIFOSIZE register */
#define USBHS_ENDPOINTX_FIFOSIZE_Msk          _UINT8_(0xFF)                                        /* (USBHS_ENDPOINTX_FIFOSIZE) Register Mask  */


/* -------- USBHS_ENDPOINT0_CONFIGDATA : (USBHS Offset: 0x101F) ( R/ 8) ENDPOINT0 Returns Information About The Selected Core Configuration. Only Applicable when INDEX Regsiter Is 0. That Is Endpoint0 Is Selected. -------- */
#define USBHS_ENDPOINT0_CONFIGDATA_RESETVALUE _UINT8_(0x00)                                        /*  (USBHS_ENDPOINT0_CONFIGDATA) ENDPOINT0 Returns Information About The Selected Core Configuration. Only Applicable when INDEX Regsiter Is 0. That Is Endpoint0 Is Selected.  Reset Value */

#define USBHS_ENDPOINT0_CONFIGDATA_UTMIDATAWIDTH_Pos _UINT8_(0)                                           /* (USBHS_ENDPOINT0_CONFIGDATA) Indicates Selected UTMI+ DataWidth. Always 0 Indicates 8 Bits Position */
#define USBHS_ENDPOINT0_CONFIGDATA_UTMIDATAWIDTH_Msk (_UINT8_(0x1) << USBHS_ENDPOINT0_CONFIGDATA_UTMIDATAWIDTH_Pos) /* (USBHS_ENDPOINT0_CONFIGDATA) Indicates Selected UTMI+ DataWidth. Always 0 Indicates 8 Bits Mask */
#define USBHS_ENDPOINT0_CONFIGDATA_UTMIDATAWIDTH(value) (USBHS_ENDPOINT0_CONFIGDATA_UTMIDATAWIDTH_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CONFIGDATA_UTMIDATAWIDTH_Pos)) /* Assigment of value for UTMIDATAWIDTH in the USBHS_ENDPOINT0_CONFIGDATA register */
#define USBHS_ENDPOINT0_CONFIGDATA_SOFTCONE_Pos _UINT8_(1)                                           /* (USBHS_ENDPOINT0_CONFIGDATA) Indicates Soft Connect Or Disconnect Position */
#define USBHS_ENDPOINT0_CONFIGDATA_SOFTCONE_Msk (_UINT8_(0x1) << USBHS_ENDPOINT0_CONFIGDATA_SOFTCONE_Pos) /* (USBHS_ENDPOINT0_CONFIGDATA) Indicates Soft Connect Or Disconnect Mask */
#define USBHS_ENDPOINT0_CONFIGDATA_SOFTCONE(value) (USBHS_ENDPOINT0_CONFIGDATA_SOFTCONE_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CONFIGDATA_SOFTCONE_Pos)) /* Assigment of value for SOFTCONE in the USBHS_ENDPOINT0_CONFIGDATA register */
#define USBHS_ENDPOINT0_CONFIGDATA_DYNFIFOSIZING_Pos _UINT8_(2)                                           /* (USBHS_ENDPOINT0_CONFIGDATA) Dynamic FIFO Sizing Is Selected Or Not Position */
#define USBHS_ENDPOINT0_CONFIGDATA_DYNFIFOSIZING_Msk (_UINT8_(0x1) << USBHS_ENDPOINT0_CONFIGDATA_DYNFIFOSIZING_Pos) /* (USBHS_ENDPOINT0_CONFIGDATA) Dynamic FIFO Sizing Is Selected Or Not Mask */
#define USBHS_ENDPOINT0_CONFIGDATA_DYNFIFOSIZING(value) (USBHS_ENDPOINT0_CONFIGDATA_DYNFIFOSIZING_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CONFIGDATA_DYNFIFOSIZING_Pos)) /* Assigment of value for DYNFIFOSIZING in the USBHS_ENDPOINT0_CONFIGDATA register */
#define USBHS_ENDPOINT0_CONFIGDATA_HBTXE_Pos  _UINT8_(3)                                           /* (USBHS_ENDPOINT0_CONFIGDATA) Indicates High Bandwidth TX ISO Endpoint Support Selected Position */
#define USBHS_ENDPOINT0_CONFIGDATA_HBTXE_Msk  (_UINT8_(0x1) << USBHS_ENDPOINT0_CONFIGDATA_HBTXE_Pos) /* (USBHS_ENDPOINT0_CONFIGDATA) Indicates High Bandwidth TX ISO Endpoint Support Selected Mask */
#define USBHS_ENDPOINT0_CONFIGDATA_HBTXE(value) (USBHS_ENDPOINT0_CONFIGDATA_HBTXE_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CONFIGDATA_HBTXE_Pos)) /* Assigment of value for HBTXE in the USBHS_ENDPOINT0_CONFIGDATA register */
#define USBHS_ENDPOINT0_CONFIGDATA_HBRXE_Pos  _UINT8_(4)                                           /* (USBHS_ENDPOINT0_CONFIGDATA) Indicates High Bandwidth RX ISO Endpoint Support Selected Position */
#define USBHS_ENDPOINT0_CONFIGDATA_HBRXE_Msk  (_UINT8_(0x1) << USBHS_ENDPOINT0_CONFIGDATA_HBRXE_Pos) /* (USBHS_ENDPOINT0_CONFIGDATA) Indicates High Bandwidth RX ISO Endpoint Support Selected Mask */
#define USBHS_ENDPOINT0_CONFIGDATA_HBRXE(value) (USBHS_ENDPOINT0_CONFIGDATA_HBRXE_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CONFIGDATA_HBRXE_Pos)) /* Assigment of value for HBRXE in the USBHS_ENDPOINT0_CONFIGDATA register */
#define USBHS_ENDPOINT0_CONFIGDATA_BIGENDIAN_Pos _UINT8_(5)                                           /* (USBHS_ENDPOINT0_CONFIGDATA) Indicates Little Endian Ordering Position */
#define USBHS_ENDPOINT0_CONFIGDATA_BIGENDIAN_Msk (_UINT8_(0x1) << USBHS_ENDPOINT0_CONFIGDATA_BIGENDIAN_Pos) /* (USBHS_ENDPOINT0_CONFIGDATA) Indicates Little Endian Ordering Mask */
#define USBHS_ENDPOINT0_CONFIGDATA_BIGENDIAN(value) (USBHS_ENDPOINT0_CONFIGDATA_BIGENDIAN_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CONFIGDATA_BIGENDIAN_Pos)) /* Assigment of value for BIGENDIAN in the USBHS_ENDPOINT0_CONFIGDATA register */
#define USBHS_ENDPOINT0_CONFIGDATA_MPTXE_Pos  _UINT8_(6)                                           /* (USBHS_ENDPOINT0_CONFIGDATA) Automatic Splitting Of Bulk Packets Is Selected Position */
#define USBHS_ENDPOINT0_CONFIGDATA_MPTXE_Msk  (_UINT8_(0x1) << USBHS_ENDPOINT0_CONFIGDATA_MPTXE_Pos) /* (USBHS_ENDPOINT0_CONFIGDATA) Automatic Splitting Of Bulk Packets Is Selected Mask */
#define USBHS_ENDPOINT0_CONFIGDATA_MPTXE(value) (USBHS_ENDPOINT0_CONFIGDATA_MPTXE_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CONFIGDATA_MPTXE_Pos)) /* Assigment of value for MPTXE in the USBHS_ENDPOINT0_CONFIGDATA register */
#define USBHS_ENDPOINT0_CONFIGDATA_MPRXE_Pos  _UINT8_(7)                                           /* (USBHS_ENDPOINT0_CONFIGDATA) Automatic Splitting Of Bulk Amalgamation Is Selected Position */
#define USBHS_ENDPOINT0_CONFIGDATA_MPRXE_Msk  (_UINT8_(0x1) << USBHS_ENDPOINT0_CONFIGDATA_MPRXE_Pos) /* (USBHS_ENDPOINT0_CONFIGDATA) Automatic Splitting Of Bulk Amalgamation Is Selected Mask */
#define USBHS_ENDPOINT0_CONFIGDATA_MPRXE(value) (USBHS_ENDPOINT0_CONFIGDATA_MPRXE_Msk & (_UINT8_(value) << USBHS_ENDPOINT0_CONFIGDATA_MPRXE_Pos)) /* Assigment of value for MPRXE in the USBHS_ENDPOINT0_CONFIGDATA register */
#define USBHS_ENDPOINT0_CONFIGDATA_Msk        _UINT8_(0xFF)                                        /* (USBHS_ENDPOINT0_CONFIGDATA) Register Mask  */


/* -------- USBHS_FIFOX : (USBHS Offset: 0x1020) (R/W 32) Address Range Provides 16 Addresses For CPU Access To The FIFO's For Each Endpoint -------- */
#define USBHS_FIFOX_RESETVALUE                _UINT32_(0x00)                                       /*  (USBHS_FIFOX) Address Range Provides 16 Addresses For CPU Access To The FIFO's For Each Endpoint  Reset Value */

#define USBHS_FIFOX_FIFOADDR_Pos              _UINT32_(0)                                          /* (USBHS_FIFOX) Writing To These Addresses Loads Data Into The TXFIFO For The Corresponding Endpoint Position */
#define USBHS_FIFOX_FIFOADDR_Msk              (_UINT32_(0xFFFFFFFF) << USBHS_FIFOX_FIFOADDR_Pos)   /* (USBHS_FIFOX) Writing To These Addresses Loads Data Into The TXFIFO For The Corresponding Endpoint Mask */
#define USBHS_FIFOX_FIFOADDR(value)           (USBHS_FIFOX_FIFOADDR_Msk & (_UINT32_(value) << USBHS_FIFOX_FIFOADDR_Pos)) /* Assigment of value for FIFOADDR in the USBHS_FIFOX register */
#define USBHS_FIFOX_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (USBHS_FIFOX) Register Mask  */


/* -------- USBHS_DEVCTL : (USBHS Offset: 0x1060) (R/W 8) Selects Whether The Core Is Operating In Peripheral Or Host Mode -------- */
#define USBHS_DEVCTL_RESETVALUE               _UINT8_(0x80)                                        /*  (USBHS_DEVCTL) Selects Whether The Core Is Operating In Peripheral Or Host Mode  Reset Value */

#define USBHS_DEVCTL_SESSION_Pos              _UINT8_(0)                                           /* (USBHS_DEVCTL) when operating as an 'A' device, this bit is set or cleared by CPU to state or end a session. when operating as a 'B' device, this bit is set/cleared by the USBCORE when a session starts/ends Position */
#define USBHS_DEVCTL_SESSION_Msk              (_UINT8_(0x1) << USBHS_DEVCTL_SESSION_Pos)           /* (USBHS_DEVCTL) when operating as an 'A' device, this bit is set or cleared by CPU to state or end a session. when operating as a 'B' device, this bit is set/cleared by the USBCORE when a session starts/ends Mask */
#define USBHS_DEVCTL_SESSION(value)           (USBHS_DEVCTL_SESSION_Msk & (_UINT8_(value) << USBHS_DEVCTL_SESSION_Pos)) /* Assigment of value for SESSION in the USBHS_DEVCTL register */
#define USBHS_DEVCTL_HOSTREQ_Pos              _UINT8_(1)                                           /* (USBHS_DEVCTL) when set, the USBCORE will initiate the host negotiation when suspend mode is entered. Position */
#define USBHS_DEVCTL_HOSTREQ_Msk              (_UINT8_(0x1) << USBHS_DEVCTL_HOSTREQ_Pos)           /* (USBHS_DEVCTL) when set, the USBCORE will initiate the host negotiation when suspend mode is entered. Mask */
#define USBHS_DEVCTL_HOSTREQ(value)           (USBHS_DEVCTL_HOSTREQ_Msk & (_UINT8_(value) << USBHS_DEVCTL_HOSTREQ_Pos)) /* Assigment of value for HOSTREQ in the USBHS_DEVCTL register */
#define USBHS_DEVCTL_HOSTMODE_Pos             _UINT8_(2)                                           /* (USBHS_DEVCTL) this read-only bit is set when the USBCORE is acting as a host Position */
#define USBHS_DEVCTL_HOSTMODE_Msk             (_UINT8_(0x1) << USBHS_DEVCTL_HOSTMODE_Pos)          /* (USBHS_DEVCTL) this read-only bit is set when the USBCORE is acting as a host Mask */
#define USBHS_DEVCTL_HOSTMODE(value)          (USBHS_DEVCTL_HOSTMODE_Msk & (_UINT8_(value) << USBHS_DEVCTL_HOSTMODE_Pos)) /* Assigment of value for HOSTMODE in the USBHS_DEVCTL register */
#define USBHS_DEVCTL_VBUS_Pos                 _UINT8_(3)                                           /* (USBHS_DEVCTL) encoded value for the VBus level Position */
#define USBHS_DEVCTL_VBUS_Msk                 (_UINT8_(0x3) << USBHS_DEVCTL_VBUS_Pos)              /* (USBHS_DEVCTL) encoded value for the VBus level Mask */
#define USBHS_DEVCTL_VBUS(value)              (USBHS_DEVCTL_VBUS_Msk & (_UINT8_(value) << USBHS_DEVCTL_VBUS_Pos)) /* Assigment of value for VBUS in the USBHS_DEVCTL register */
#define   USBHS_DEVCTL_VBUS_BSESSEND_Val      _UINT8_(0x0)                                         /* (USBHS_DEVCTL) Below SessionEnd  */
#define   USBHS_DEVCTL_VBUS_ASESSEND_Val      _UINT8_(0x1)                                         /* (USBHS_DEVCTL) Above SessionEnd, below AValid  */
#define   USBHS_DEVCTL_VBUS_AAVALID_Val       _UINT8_(0x2)                                         /* (USBHS_DEVCTL) Above AValid, below VBus Valid  */
#define   USBHS_DEVCTL_VBUS_AVBUSVALID_Val    _UINT8_(0x3)                                         /* (USBHS_DEVCTL) Above VBusValid  */
#define USBHS_DEVCTL_VBUS_BSESSEND            (USBHS_DEVCTL_VBUS_BSESSEND_Val << USBHS_DEVCTL_VBUS_Pos) /* (USBHS_DEVCTL) Below SessionEnd Position  */
#define USBHS_DEVCTL_VBUS_ASESSEND            (USBHS_DEVCTL_VBUS_ASESSEND_Val << USBHS_DEVCTL_VBUS_Pos) /* (USBHS_DEVCTL) Above SessionEnd, below AValid Position  */
#define USBHS_DEVCTL_VBUS_AAVALID             (USBHS_DEVCTL_VBUS_AAVALID_Val << USBHS_DEVCTL_VBUS_Pos) /* (USBHS_DEVCTL) Above AValid, below VBus Valid Position  */
#define USBHS_DEVCTL_VBUS_AVBUSVALID          (USBHS_DEVCTL_VBUS_AVBUSVALID_Val << USBHS_DEVCTL_VBUS_Pos) /* (USBHS_DEVCTL) Above VBusValid Position  */
#define USBHS_DEVCTL_LSDEV_Pos                _UINT8_(5)                                           /* (USBHS_DEVCTL) host mode only: this bit is set when a low speed device has been detected being connected to the port Position */
#define USBHS_DEVCTL_LSDEV_Msk                (_UINT8_(0x1) << USBHS_DEVCTL_LSDEV_Pos)             /* (USBHS_DEVCTL) host mode only: this bit is set when a low speed device has been detected being connected to the port Mask */
#define USBHS_DEVCTL_LSDEV(value)             (USBHS_DEVCTL_LSDEV_Msk & (_UINT8_(value) << USBHS_DEVCTL_LSDEV_Pos)) /* Assigment of value for LSDEV in the USBHS_DEVCTL register */
#define USBHS_DEVCTL_FSDEV_Pos                _UINT8_(6)                                           /* (USBHS_DEVCTL) host mode only: this bit is set when a full or high speed device has been detected being connected to the port Position */
#define USBHS_DEVCTL_FSDEV_Msk                (_UINT8_(0x1) << USBHS_DEVCTL_FSDEV_Pos)             /* (USBHS_DEVCTL) host mode only: this bit is set when a full or high speed device has been detected being connected to the port Mask */
#define USBHS_DEVCTL_FSDEV(value)             (USBHS_DEVCTL_FSDEV_Msk & (_UINT8_(value) << USBHS_DEVCTL_FSDEV_Pos)) /* Assigment of value for FSDEV in the USBHS_DEVCTL register */
#define USBHS_DEVCTL_BDEVICE_Pos              _UINT8_(7)                                           /* (USBHS_DEVCTL) indicates whether the core is operating as a 'A' device or 'B' device Position */
#define USBHS_DEVCTL_BDEVICE_Msk              (_UINT8_(0x1) << USBHS_DEVCTL_BDEVICE_Pos)           /* (USBHS_DEVCTL) indicates whether the core is operating as a 'A' device or 'B' device Mask */
#define USBHS_DEVCTL_BDEVICE(value)           (USBHS_DEVCTL_BDEVICE_Msk & (_UINT8_(value) << USBHS_DEVCTL_BDEVICE_Pos)) /* Assigment of value for BDEVICE in the USBHS_DEVCTL register */
#define USBHS_DEVCTL_Msk                      _UINT8_(0xFF)                                        /* (USBHS_DEVCTL) Register Mask  */


/* -------- USBHS_MISC : (USBHS Offset: 0x1061) (R/W 8) RX/TX Early DMA Enable Bits -------- */
#define USBHS_MISC_RESETVALUE                 _UINT8_(0x00)                                        /*  (USBHS_MISC) RX/TX Early DMA Enable Bits  Reset Value */

#define USBHS_MISC_RXEDMA_Pos                 _UINT8_(0)                                           /* (USBHS_MISC) DMA_REQ signal for all OUT endpoints will be deasserted based on this bit selection Position */
#define USBHS_MISC_RXEDMA_Msk                 (_UINT8_(0x1) << USBHS_MISC_RXEDMA_Pos)              /* (USBHS_MISC) DMA_REQ signal for all OUT endpoints will be deasserted based on this bit selection Mask */
#define USBHS_MISC_RXEDMA(value)              (USBHS_MISC_RXEDMA_Msk & (_UINT8_(value) << USBHS_MISC_RXEDMA_Pos)) /* Assigment of value for RXEDMA in the USBHS_MISC register */
#define   USBHS_MISC_RXEDMA_MAXP_Val          _UINT8_(0x0)                                         /* (USBHS_MISC) Dma_req signal for all out endpoints will be de-asserted when maxp bytes have been written to an endpoint. this is late mode.  */
#define   USBHS_MISC_RXEDMA_MAXP_8_Val        _UINT8_(0x1)                                         /* (USBHS_MISC) Dma_req signal for all out endpoints will be de-asserted when maxp-8 bytes have been written to an endpoint. this is early mode.  */
#define USBHS_MISC_RXEDMA_MAXP                (USBHS_MISC_RXEDMA_MAXP_Val << USBHS_MISC_RXEDMA_Pos) /* (USBHS_MISC) Dma_req signal for all out endpoints will be de-asserted when maxp bytes have been written to an endpoint. this is late mode. Position  */
#define USBHS_MISC_RXEDMA_MAXP_8              (USBHS_MISC_RXEDMA_MAXP_8_Val << USBHS_MISC_RXEDMA_Pos) /* (USBHS_MISC) Dma_req signal for all out endpoints will be de-asserted when maxp-8 bytes have been written to an endpoint. this is early mode. Position  */
#define USBHS_MISC_TXEDMA_Pos                 _UINT8_(1)                                           /* (USBHS_MISC) DMA_REQ signal for all IN endpoints will be deasserted based on this bit selection Position */
#define USBHS_MISC_TXEDMA_Msk                 (_UINT8_(0x1) << USBHS_MISC_TXEDMA_Pos)              /* (USBHS_MISC) DMA_REQ signal for all IN endpoints will be deasserted based on this bit selection Mask */
#define USBHS_MISC_TXEDMA(value)              (USBHS_MISC_TXEDMA_Msk & (_UINT8_(value) << USBHS_MISC_TXEDMA_Pos)) /* Assigment of value for TXEDMA in the USBHS_MISC register */
#define   USBHS_MISC_TXEDMA_MAXP_Val          _UINT8_(0x0)                                         /* (USBHS_MISC) Dma_req signal for all in endpoints will be de-asserted when maxp bytes have been written to an endpoint. this is late mode.  */
#define   USBHS_MISC_TXEDMA_MAXP_8_Val        _UINT8_(0x1)                                         /* (USBHS_MISC) Dma_req signal for all in endpoints will be de-asserted when maxp-8 bytes have been written to an endpoint. this is early mode.  */
#define USBHS_MISC_TXEDMA_MAXP                (USBHS_MISC_TXEDMA_MAXP_Val << USBHS_MISC_TXEDMA_Pos) /* (USBHS_MISC) Dma_req signal for all in endpoints will be de-asserted when maxp bytes have been written to an endpoint. this is late mode. Position  */
#define USBHS_MISC_TXEDMA_MAXP_8              (USBHS_MISC_TXEDMA_MAXP_8_Val << USBHS_MISC_TXEDMA_Pos) /* (USBHS_MISC) Dma_req signal for all in endpoints will be de-asserted when maxp-8 bytes have been written to an endpoint. this is early mode. Position  */
#define USBHS_MISC_Msk                        _UINT8_(0x03)                                        /* (USBHS_MISC) Register Mask  */


/* -------- USBHS_TXFIFOSZ : (USBHS Offset: 0x1062) (R/W 8) Controls The Size Of The Selected TX Endpoint FIFO -------- */
#define USBHS_TXFIFOSZ_RESETVALUE             _UINT8_(0x00)                                        /*  (USBHS_TXFIFOSZ) Controls The Size Of The Selected TX Endpoint FIFO  Reset Value */

#define USBHS_TXFIFOSZ_SZ_Pos                 _UINT8_(0)                                           /* (USBHS_TXFIFOSZ) maximum packet size to be allowed Position */
#define USBHS_TXFIFOSZ_SZ_Msk                 (_UINT8_(0xF) << USBHS_TXFIFOSZ_SZ_Pos)              /* (USBHS_TXFIFOSZ) maximum packet size to be allowed Mask */
#define USBHS_TXFIFOSZ_SZ(value)              (USBHS_TXFIFOSZ_SZ_Msk & (_UINT8_(value) << USBHS_TXFIFOSZ_SZ_Pos)) /* Assigment of value for SZ in the USBHS_TXFIFOSZ register */
#define   USBHS_TXFIFOSZ_SZ_8BYTES_Val        _UINT8_(0x0)                                         /* (USBHS_TXFIFOSZ) 8 BYTES  */
#define   USBHS_TXFIFOSZ_SZ_16BYTES_Val       _UINT8_(0x1)                                         /* (USBHS_TXFIFOSZ) 16 BYTES  */
#define   USBHS_TXFIFOSZ_SZ_32BYTES_Val       _UINT8_(0x2)                                         /* (USBHS_TXFIFOSZ) 32 BYTES  */
#define   USBHS_TXFIFOSZ_SZ_64BYTES_Val       _UINT8_(0x3)                                         /* (USBHS_TXFIFOSZ) 64 BYTES  */
#define   USBHS_TXFIFOSZ_SZ_128BYTES_Val      _UINT8_(0x4)                                         /* (USBHS_TXFIFOSZ) 128 BYTES  */
#define   USBHS_TXFIFOSZ_SZ_256BYTES_Val      _UINT8_(0x5)                                         /* (USBHS_TXFIFOSZ) 256 BYTES  */
#define   USBHS_TXFIFOSZ_SZ_512BYTES_Val      _UINT8_(0x6)                                         /* (USBHS_TXFIFOSZ) 512 BYTES  */
#define   USBHS_TXFIFOSZ_SZ_1024BYTES_Val     _UINT8_(0x7)                                         /* (USBHS_TXFIFOSZ) 1024 BYTES  */
#define   USBHS_TXFIFOSZ_SZ_2048BYTES_Val     _UINT8_(0x8)                                         /* (USBHS_TXFIFOSZ) 2048 BYTES  */
#define   USBHS_TXFIFOSZ_SZ_4096BYTES_Val     _UINT8_(0x9)                                         /* (USBHS_TXFIFOSZ) 4096 BYTES  */
#define USBHS_TXFIFOSZ_SZ_8BYTES              (USBHS_TXFIFOSZ_SZ_8BYTES_Val << USBHS_TXFIFOSZ_SZ_Pos) /* (USBHS_TXFIFOSZ) 8 BYTES Position  */
#define USBHS_TXFIFOSZ_SZ_16BYTES             (USBHS_TXFIFOSZ_SZ_16BYTES_Val << USBHS_TXFIFOSZ_SZ_Pos) /* (USBHS_TXFIFOSZ) 16 BYTES Position  */
#define USBHS_TXFIFOSZ_SZ_32BYTES             (USBHS_TXFIFOSZ_SZ_32BYTES_Val << USBHS_TXFIFOSZ_SZ_Pos) /* (USBHS_TXFIFOSZ) 32 BYTES Position  */
#define USBHS_TXFIFOSZ_SZ_64BYTES             (USBHS_TXFIFOSZ_SZ_64BYTES_Val << USBHS_TXFIFOSZ_SZ_Pos) /* (USBHS_TXFIFOSZ) 64 BYTES Position  */
#define USBHS_TXFIFOSZ_SZ_128BYTES            (USBHS_TXFIFOSZ_SZ_128BYTES_Val << USBHS_TXFIFOSZ_SZ_Pos) /* (USBHS_TXFIFOSZ) 128 BYTES Position  */
#define USBHS_TXFIFOSZ_SZ_256BYTES            (USBHS_TXFIFOSZ_SZ_256BYTES_Val << USBHS_TXFIFOSZ_SZ_Pos) /* (USBHS_TXFIFOSZ) 256 BYTES Position  */
#define USBHS_TXFIFOSZ_SZ_512BYTES            (USBHS_TXFIFOSZ_SZ_512BYTES_Val << USBHS_TXFIFOSZ_SZ_Pos) /* (USBHS_TXFIFOSZ) 512 BYTES Position  */
#define USBHS_TXFIFOSZ_SZ_1024BYTES           (USBHS_TXFIFOSZ_SZ_1024BYTES_Val << USBHS_TXFIFOSZ_SZ_Pos) /* (USBHS_TXFIFOSZ) 1024 BYTES Position  */
#define USBHS_TXFIFOSZ_SZ_2048BYTES           (USBHS_TXFIFOSZ_SZ_2048BYTES_Val << USBHS_TXFIFOSZ_SZ_Pos) /* (USBHS_TXFIFOSZ) 2048 BYTES Position  */
#define USBHS_TXFIFOSZ_SZ_4096BYTES           (USBHS_TXFIFOSZ_SZ_4096BYTES_Val << USBHS_TXFIFOSZ_SZ_Pos) /* (USBHS_TXFIFOSZ) 4096 BYTES Position  */
#define USBHS_TXFIFOSZ_DPB_Pos                _UINT8_(4)                                           /* (USBHS_TXFIFOSZ) double packet buffering supported or not Position */
#define USBHS_TXFIFOSZ_DPB_Msk                (_UINT8_(0x1) << USBHS_TXFIFOSZ_DPB_Pos)             /* (USBHS_TXFIFOSZ) double packet buffering supported or not Mask */
#define USBHS_TXFIFOSZ_DPB(value)             (USBHS_TXFIFOSZ_DPB_Msk & (_UINT8_(value) << USBHS_TXFIFOSZ_DPB_Pos)) /* Assigment of value for DPB in the USBHS_TXFIFOSZ register */
#define USBHS_TXFIFOSZ_Msk                    _UINT8_(0x1F)                                        /* (USBHS_TXFIFOSZ) Register Mask  */


/* -------- USBHS_RXFIFOSZ : (USBHS Offset: 0x1063) (R/W 8) Controls The Size Of The Selected RX Endpoint FIFO -------- */
#define USBHS_RXFIFOSZ_RESETVALUE             _UINT8_(0x00)                                        /*  (USBHS_RXFIFOSZ) Controls The Size Of The Selected RX Endpoint FIFO  Reset Value */

#define USBHS_RXFIFOSZ_SZ_Pos                 _UINT8_(0)                                           /* (USBHS_RXFIFOSZ) maximum packet size to be allowed Position */
#define USBHS_RXFIFOSZ_SZ_Msk                 (_UINT8_(0xF) << USBHS_RXFIFOSZ_SZ_Pos)              /* (USBHS_RXFIFOSZ) maximum packet size to be allowed Mask */
#define USBHS_RXFIFOSZ_SZ(value)              (USBHS_RXFIFOSZ_SZ_Msk & (_UINT8_(value) << USBHS_RXFIFOSZ_SZ_Pos)) /* Assigment of value for SZ in the USBHS_RXFIFOSZ register */
#define   USBHS_RXFIFOSZ_SZ_8BYTES_Val        _UINT8_(0x0)                                         /* (USBHS_RXFIFOSZ) 8 BYTES  */
#define   USBHS_RXFIFOSZ_SZ_16BYTES_Val       _UINT8_(0x1)                                         /* (USBHS_RXFIFOSZ) 16 BYTES  */
#define   USBHS_RXFIFOSZ_SZ_32BYTES_Val       _UINT8_(0x2)                                         /* (USBHS_RXFIFOSZ) 32 BYTES  */
#define   USBHS_RXFIFOSZ_SZ_64BYTES_Val       _UINT8_(0x3)                                         /* (USBHS_RXFIFOSZ) 64 BYTES  */
#define   USBHS_RXFIFOSZ_SZ_128BYTES_Val      _UINT8_(0x4)                                         /* (USBHS_RXFIFOSZ) 128 BYTES  */
#define   USBHS_RXFIFOSZ_SZ_256BYTES_Val      _UINT8_(0x5)                                         /* (USBHS_RXFIFOSZ) 256 BYTES  */
#define   USBHS_RXFIFOSZ_SZ_512BYTES_Val      _UINT8_(0x6)                                         /* (USBHS_RXFIFOSZ) 512 BYTES  */
#define   USBHS_RXFIFOSZ_SZ_1024BYTES_Val     _UINT8_(0x7)                                         /* (USBHS_RXFIFOSZ) 1024 BYTES  */
#define   USBHS_RXFIFOSZ_SZ_2048BYTES_Val     _UINT8_(0x8)                                         /* (USBHS_RXFIFOSZ) 2048 BYTES  */
#define   USBHS_RXFIFOSZ_SZ_4096BYTES_Val     _UINT8_(0x9)                                         /* (USBHS_RXFIFOSZ) 4096 BYTES  */
#define USBHS_RXFIFOSZ_SZ_8BYTES              (USBHS_RXFIFOSZ_SZ_8BYTES_Val << USBHS_RXFIFOSZ_SZ_Pos) /* (USBHS_RXFIFOSZ) 8 BYTES Position  */
#define USBHS_RXFIFOSZ_SZ_16BYTES             (USBHS_RXFIFOSZ_SZ_16BYTES_Val << USBHS_RXFIFOSZ_SZ_Pos) /* (USBHS_RXFIFOSZ) 16 BYTES Position  */
#define USBHS_RXFIFOSZ_SZ_32BYTES             (USBHS_RXFIFOSZ_SZ_32BYTES_Val << USBHS_RXFIFOSZ_SZ_Pos) /* (USBHS_RXFIFOSZ) 32 BYTES Position  */
#define USBHS_RXFIFOSZ_SZ_64BYTES             (USBHS_RXFIFOSZ_SZ_64BYTES_Val << USBHS_RXFIFOSZ_SZ_Pos) /* (USBHS_RXFIFOSZ) 64 BYTES Position  */
#define USBHS_RXFIFOSZ_SZ_128BYTES            (USBHS_RXFIFOSZ_SZ_128BYTES_Val << USBHS_RXFIFOSZ_SZ_Pos) /* (USBHS_RXFIFOSZ) 128 BYTES Position  */
#define USBHS_RXFIFOSZ_SZ_256BYTES            (USBHS_RXFIFOSZ_SZ_256BYTES_Val << USBHS_RXFIFOSZ_SZ_Pos) /* (USBHS_RXFIFOSZ) 256 BYTES Position  */
#define USBHS_RXFIFOSZ_SZ_512BYTES            (USBHS_RXFIFOSZ_SZ_512BYTES_Val << USBHS_RXFIFOSZ_SZ_Pos) /* (USBHS_RXFIFOSZ) 512 BYTES Position  */
#define USBHS_RXFIFOSZ_SZ_1024BYTES           (USBHS_RXFIFOSZ_SZ_1024BYTES_Val << USBHS_RXFIFOSZ_SZ_Pos) /* (USBHS_RXFIFOSZ) 1024 BYTES Position  */
#define USBHS_RXFIFOSZ_SZ_2048BYTES           (USBHS_RXFIFOSZ_SZ_2048BYTES_Val << USBHS_RXFIFOSZ_SZ_Pos) /* (USBHS_RXFIFOSZ) 2048 BYTES Position  */
#define USBHS_RXFIFOSZ_SZ_4096BYTES           (USBHS_RXFIFOSZ_SZ_4096BYTES_Val << USBHS_RXFIFOSZ_SZ_Pos) /* (USBHS_RXFIFOSZ) 4096 BYTES Position  */
#define USBHS_RXFIFOSZ_DPB_Pos                _UINT8_(4)                                           /* (USBHS_RXFIFOSZ) double packet buffering enabled or not Position */
#define USBHS_RXFIFOSZ_DPB_Msk                (_UINT8_(0x1) << USBHS_RXFIFOSZ_DPB_Pos)             /* (USBHS_RXFIFOSZ) double packet buffering enabled or not Mask */
#define USBHS_RXFIFOSZ_DPB(value)             (USBHS_RXFIFOSZ_DPB_Msk & (_UINT8_(value) << USBHS_RXFIFOSZ_DPB_Pos)) /* Assigment of value for DPB in the USBHS_RXFIFOSZ register */
#define USBHS_RXFIFOSZ_Msk                    _UINT8_(0x1F)                                        /* (USBHS_RXFIFOSZ) Register Mask  */


/* -------- USBHS_TXFIFOADD : (USBHS Offset: 0x1064) (R/W 16) Controls The Start Address Of the Selected TX Endpoint FIFO -------- */
#define USBHS_TXFIFOADD_RESETVALUE            _UINT16_(0x00)                                       /*  (USBHS_TXFIFOADD) Controls The Start Address Of the Selected TX Endpoint FIFO  Reset Value */

#define USBHS_TXFIFOADD_ADDR_Pos              _UINT16_(0)                                          /* (USBHS_TXFIFOADD) start address of the endpoint FIFO Position */
#define USBHS_TXFIFOADD_ADDR_Msk              (_UINT16_(0x1FFF) << USBHS_TXFIFOADD_ADDR_Pos)       /* (USBHS_TXFIFOADD) start address of the endpoint FIFO Mask */
#define USBHS_TXFIFOADD_ADDR(value)           (USBHS_TXFIFOADD_ADDR_Msk & (_UINT16_(value) << USBHS_TXFIFOADD_ADDR_Pos)) /* Assigment of value for ADDR in the USBHS_TXFIFOADD register */
#define USBHS_TXFIFOADD_Msk                   _UINT16_(0x1FFF)                                     /* (USBHS_TXFIFOADD) Register Mask  */


/* -------- USBHS_RXFIFOADD : (USBHS Offset: 0x1066) (R/W 16) Controls The Start Address Of the Selected RX Endpoint FIFO -------- */
#define USBHS_RXFIFOADD_RESETVALUE            _UINT16_(0x00)                                       /*  (USBHS_RXFIFOADD) Controls The Start Address Of the Selected RX Endpoint FIFO  Reset Value */

#define USBHS_RXFIFOADD_ADDR_Pos              _UINT16_(0)                                          /* (USBHS_RXFIFOADD) start address of the endpoint FIFO Position */
#define USBHS_RXFIFOADD_ADDR_Msk              (_UINT16_(0x1FFF) << USBHS_RXFIFOADD_ADDR_Pos)       /* (USBHS_RXFIFOADD) start address of the endpoint FIFO Mask */
#define USBHS_RXFIFOADD_ADDR(value)           (USBHS_RXFIFOADD_ADDR_Msk & (_UINT16_(value) << USBHS_RXFIFOADD_ADDR_Pos)) /* Assigment of value for ADDR in the USBHS_RXFIFOADD register */
#define USBHS_RXFIFOADD_Msk                   _UINT16_(0x1FFF)                                     /* (USBHS_RXFIFOADD) Register Mask  */


/* -------- USBHS_EPINFO : (USBHS Offset: 0x1078) ( R/ 8) Allows Read-Back Of The Number Of TX And RX Endpoints -------- */
#define USBHS_EPINFO_RESETVALUE               _UINT8_(0xFF)                                        /*  (USBHS_EPINFO) Allows Read-Back Of The Number Of TX And RX Endpoints  Reset Value */

#define USBHS_EPINFO_TXENDPOINTS_Pos          _UINT8_(0)                                           /* (USBHS_EPINFO) number of tx endpoints Position */
#define USBHS_EPINFO_TXENDPOINTS_Msk          (_UINT8_(0xF) << USBHS_EPINFO_TXENDPOINTS_Pos)       /* (USBHS_EPINFO) number of tx endpoints Mask */
#define USBHS_EPINFO_TXENDPOINTS(value)       (USBHS_EPINFO_TXENDPOINTS_Msk & (_UINT8_(value) << USBHS_EPINFO_TXENDPOINTS_Pos)) /* Assigment of value for TXENDPOINTS in the USBHS_EPINFO register */
#define USBHS_EPINFO_RXENDPOINTS_Pos          _UINT8_(4)                                           /* (USBHS_EPINFO) number of rx endpoints Position */
#define USBHS_EPINFO_RXENDPOINTS_Msk          (_UINT8_(0xF) << USBHS_EPINFO_RXENDPOINTS_Pos)       /* (USBHS_EPINFO) number of rx endpoints Mask */
#define USBHS_EPINFO_RXENDPOINTS(value)       (USBHS_EPINFO_RXENDPOINTS_Msk & (_UINT8_(value) << USBHS_EPINFO_RXENDPOINTS_Pos)) /* Assigment of value for RXENDPOINTS in the USBHS_EPINFO register */
#define USBHS_EPINFO_Msk                      _UINT8_(0xFF)                                        /* (USBHS_EPINFO) Register Mask  */


/* -------- USBHS_RAMINFO : (USBHS Offset: 0x1079) ( R/ 8) Details About Width Of RAM and DMA Channels -------- */
#define USBHS_RAMINFO_RESETVALUE              _UINT8_(0x8D)                                        /*  (USBHS_RAMINFO) Details About Width Of RAM and DMA Channels  Reset Value */

#define USBHS_RAMINFO_RAMBITS_Pos             _UINT8_(0)                                           /* (USBHS_RAMINFO) width of the ram address bus Position */
#define USBHS_RAMINFO_RAMBITS_Msk             (_UINT8_(0xF) << USBHS_RAMINFO_RAMBITS_Pos)          /* (USBHS_RAMINFO) width of the ram address bus Mask */
#define USBHS_RAMINFO_RAMBITS(value)          (USBHS_RAMINFO_RAMBITS_Msk & (_UINT8_(value) << USBHS_RAMINFO_RAMBITS_Pos)) /* Assigment of value for RAMBITS in the USBHS_RAMINFO register */
#define USBHS_RAMINFO_DMACHANS_Pos            _UINT8_(4)                                           /* (USBHS_RAMINFO) number of dma channels implemented in the design Position */
#define USBHS_RAMINFO_DMACHANS_Msk            (_UINT8_(0xF) << USBHS_RAMINFO_DMACHANS_Pos)         /* (USBHS_RAMINFO) number of dma channels implemented in the design Mask */
#define USBHS_RAMINFO_DMACHANS(value)         (USBHS_RAMINFO_DMACHANS_Msk & (_UINT8_(value) << USBHS_RAMINFO_DMACHANS_Pos)) /* Assigment of value for DMACHANS in the USBHS_RAMINFO register */
#define USBHS_RAMINFO_Msk                     _UINT8_(0xFF)                                        /* (USBHS_RAMINFO) Register Mask  */


/* -------- USBHS_LINKINFO : (USBHS Offset: 0x107A) (R/W 8) Allows Some Delays To Be Specified -------- */
#define USBHS_LINKINFO_RESETVALUE             _UINT8_(0x5C)                                        /*  (USBHS_LINKINFO) Allows Some Delays To Be Specified  Reset Value */

#define USBHS_LINKINFO_WTID_Pos               _UINT8_(0)                                           /* (USBHS_LINKINFO) sets the delay to be applied from idpullup being asserted to iddig being considered valid in units of 4.369ms Position */
#define USBHS_LINKINFO_WTID_Msk               (_UINT8_(0xF) << USBHS_LINKINFO_WTID_Pos)            /* (USBHS_LINKINFO) sets the delay to be applied from idpullup being asserted to iddig being considered valid in units of 4.369ms Mask */
#define USBHS_LINKINFO_WTID(value)            (USBHS_LINKINFO_WTID_Msk & (_UINT8_(value) << USBHS_LINKINFO_WTID_Pos)) /* Assigment of value for WTID in the USBHS_LINKINFO register */
#define USBHS_LINKINFO_WTCON_Pos              _UINT8_(4)                                           /* (USBHS_LINKINFO) sets the wait to be applied to allow for the user's connect/disconnect filter in units of 533.3ns Position */
#define USBHS_LINKINFO_WTCON_Msk              (_UINT8_(0xF) << USBHS_LINKINFO_WTCON_Pos)           /* (USBHS_LINKINFO) sets the wait to be applied to allow for the user's connect/disconnect filter in units of 533.3ns Mask */
#define USBHS_LINKINFO_WTCON(value)           (USBHS_LINKINFO_WTCON_Msk & (_UINT8_(value) << USBHS_LINKINFO_WTCON_Pos)) /* Assigment of value for WTCON in the USBHS_LINKINFO register */
#define USBHS_LINKINFO_Msk                    _UINT8_(0xFF)                                        /* (USBHS_LINKINFO) Register Mask  */


/* -------- USBHS_VPLEN : (USBHS Offset: 0x107B) (R/W 8) Sets The Duration Of The VBus Pulsing Charge -------- */
#define USBHS_VPLEN_RESETVALUE                _UINT8_(0x3C)                                        /*  (USBHS_VPLEN) Sets The Duration Of The VBus Pulsing Charge  Reset Value */

#define USBHS_VPLEN_VPLEN_Pos                 _UINT8_(0)                                           /* (USBHS_VPLEN) duration of VBus pulsing charge in units of 546.1us Position */
#define USBHS_VPLEN_VPLEN_Msk                 (_UINT8_(0xFF) << USBHS_VPLEN_VPLEN_Pos)             /* (USBHS_VPLEN) duration of VBus pulsing charge in units of 546.1us Mask */
#define USBHS_VPLEN_VPLEN(value)              (USBHS_VPLEN_VPLEN_Msk & (_UINT8_(value) << USBHS_VPLEN_VPLEN_Pos)) /* Assigment of value for VPLEN in the USBHS_VPLEN register */
#define USBHS_VPLEN_Msk                       _UINT8_(0xFF)                                        /* (USBHS_VPLEN) Register Mask  */


/* -------- USBHS_HSEOF1 : (USBHS Offset: 0x107C) (R/W 8) Sets The Minimum Time Gap That Is To Be Allowed Between The Start Of The Last Transaction And The EOF For HS Transactions -------- */
#define USBHS_HSEOF1_RESETVALUE               _UINT8_(0x80)                                        /*  (USBHS_HSEOF1) Sets The Minimum Time Gap That Is To Be Allowed Between The Start Of The Last Transaction And The EOF For HS Transactions  Reset Value */

#define USBHS_HSEOF1_HSEOF1_Pos               _UINT8_(0)                                           /* (USBHS_HSEOF1) sets for high-speed transactions the time before eof to stop beginning new transactions, in units of 133.3ns. (the default setting corresponds to 17.07us.) Position */
#define USBHS_HSEOF1_HSEOF1_Msk               (_UINT8_(0xFF) << USBHS_HSEOF1_HSEOF1_Pos)           /* (USBHS_HSEOF1) sets for high-speed transactions the time before eof to stop beginning new transactions, in units of 133.3ns. (the default setting corresponds to 17.07us.) Mask */
#define USBHS_HSEOF1_HSEOF1(value)            (USBHS_HSEOF1_HSEOF1_Msk & (_UINT8_(value) << USBHS_HSEOF1_HSEOF1_Pos)) /* Assigment of value for HSEOF1 in the USBHS_HSEOF1 register */
#define USBHS_HSEOF1_Msk                      _UINT8_(0xFF)                                        /* (USBHS_HSEOF1) Register Mask  */


/* -------- USBHS_FSEOF1 : (USBHS Offset: 0x107D) (R/W 8) Sets The Minimum Time Gap That Is To Be Allowed Between The Start Of The Last Transaction And The EOF For FS Transactions -------- */
#define USBHS_FSEOF1_RESETVALUE               _UINT8_(0x77)                                        /*  (USBHS_FSEOF1) Sets The Minimum Time Gap That Is To Be Allowed Between The Start Of The Last Transaction And The EOF For FS Transactions  Reset Value */

#define USBHS_FSEOF1_FSEOF1_Pos               _UINT8_(0)                                           /* (USBHS_FSEOF1) sets for full-speed transactions the time before eof to stop beginning new transactions, in units of 533.3ns. (the default setting corresponds to 63.46us.) Position */
#define USBHS_FSEOF1_FSEOF1_Msk               (_UINT8_(0xFF) << USBHS_FSEOF1_FSEOF1_Pos)           /* (USBHS_FSEOF1) sets for full-speed transactions the time before eof to stop beginning new transactions, in units of 533.3ns. (the default setting corresponds to 63.46us.) Mask */
#define USBHS_FSEOF1_FSEOF1(value)            (USBHS_FSEOF1_FSEOF1_Msk & (_UINT8_(value) << USBHS_FSEOF1_FSEOF1_Pos)) /* Assigment of value for FSEOF1 in the USBHS_FSEOF1 register */
#define USBHS_FSEOF1_Msk                      _UINT8_(0xFF)                                        /* (USBHS_FSEOF1) Register Mask  */


/* -------- USBHS_LSEOF1 : (USBHS Offset: 0x107E) (R/W 8) Sets The Minimum Time Gap That Is To Be Allowed Between The Start Of The Last Transaction And The EOF For LS Transactions -------- */
#define USBHS_LSEOF1_RESETVALUE               _UINT8_(0x72)                                        /*  (USBHS_LSEOF1) Sets The Minimum Time Gap That Is To Be Allowed Between The Start Of The Last Transaction And The EOF For LS Transactions  Reset Value */

#define USBHS_LSEOF1_LSEOF1_Pos               _UINT8_(0)                                           /* (USBHS_LSEOF1) sets for low-speed transactions the time before eof to stop beginning new transactions, in units of 1.067us. (the default setting corresponds to 121.6us.) Position */
#define USBHS_LSEOF1_LSEOF1_Msk               (_UINT8_(0xFF) << USBHS_LSEOF1_LSEOF1_Pos)           /* (USBHS_LSEOF1) sets for low-speed transactions the time before eof to stop beginning new transactions, in units of 1.067us. (the default setting corresponds to 121.6us.) Mask */
#define USBHS_LSEOF1_LSEOF1(value)            (USBHS_LSEOF1_LSEOF1_Msk & (_UINT8_(value) << USBHS_LSEOF1_LSEOF1_Pos)) /* Assigment of value for LSEOF1 in the USBHS_LSEOF1 register */
#define USBHS_LSEOF1_Msk                      _UINT8_(0xFF)                                        /* (USBHS_LSEOF1) Register Mask  */


/* -------- USBHS_SOFTRST : (USBHS Offset: 0x107F) (R/W 8) Assert Low The Output Reset Signals NRSTO and NRSTXO -------- */
#define USBHS_SOFTRST_RESETVALUE              _UINT8_(0x00)                                        /*  (USBHS_SOFTRST) Assert Low The Output Reset Signals NRSTO and NRSTXO  Reset Value */

#define USBHS_SOFTRST_NRST_Pos                _UINT8_(0)                                           /* (USBHS_SOFTRST) when a 1 is written to this bit, the output nrsto will be asserted (low) within a minimum delay of 7 cycles of the clk input. the output nrsto will be asynchronously asserted and synchronously de-asserted with respect to clk. Position */
#define USBHS_SOFTRST_NRST_Msk                (_UINT8_(0x1) << USBHS_SOFTRST_NRST_Pos)             /* (USBHS_SOFTRST) when a 1 is written to this bit, the output nrsto will be asserted (low) within a minimum delay of 7 cycles of the clk input. the output nrsto will be asynchronously asserted and synchronously de-asserted with respect to clk. Mask */
#define USBHS_SOFTRST_NRST(value)             (USBHS_SOFTRST_NRST_Msk & (_UINT8_(value) << USBHS_SOFTRST_NRST_Pos)) /* Assigment of value for NRST in the USBHS_SOFTRST register */
#define USBHS_SOFTRST_NRSTX_Pos               _UINT8_(1)                                           /* (USBHS_SOFTRST) when a 1 is written to this bit, the output nrstxo will be asserted (low) within a minimum delay of 7 cycles of the clk input. the output nrstxo will be asynchronously asserted and synchronously de-asserted with respect to xclk. Position */
#define USBHS_SOFTRST_NRSTX_Msk               (_UINT8_(0x1) << USBHS_SOFTRST_NRSTX_Pos)            /* (USBHS_SOFTRST) when a 1 is written to this bit, the output nrstxo will be asserted (low) within a minimum delay of 7 cycles of the clk input. the output nrstxo will be asynchronously asserted and synchronously de-asserted with respect to xclk. Mask */
#define USBHS_SOFTRST_NRSTX(value)            (USBHS_SOFTRST_NRSTX_Msk & (_UINT8_(value) << USBHS_SOFTRST_NRSTX_Pos)) /* Assigment of value for NRSTX in the USBHS_SOFTRST register */
#define USBHS_SOFTRST_Msk                     _UINT8_(0x03)                                        /* (USBHS_SOFTRST) Register Mask  */


/* -------- USBHS_DMAINTR : (USBHS Offset: 0x1200) (R/W 32) DMA Interrupt Status for Each Channel -------- */
#define USBHS_DMAINTR_RESETVALUE              _UINT32_(0x00)                                       /*  (USBHS_DMAINTR) DMA Interrupt Status for Each Channel  Reset Value */

#define USBHS_DMAINTR_DMAINTR_Pos             _UINT32_(0)                                          /* (USBHS_DMAINTR) DMA Interrupt for each channel Position */
#define USBHS_DMAINTR_DMAINTR_Msk             (_UINT32_(0xFF) << USBHS_DMAINTR_DMAINTR_Pos)        /* (USBHS_DMAINTR) DMA Interrupt for each channel Mask */
#define USBHS_DMAINTR_DMAINTR(value)          (USBHS_DMAINTR_DMAINTR_Msk & (_UINT32_(value) << USBHS_DMAINTR_DMAINTR_Pos)) /* Assigment of value for DMAINTR in the USBHS_DMAINTR register */
#define USBHS_DMAINTR_Msk                     _UINT32_(0x000000FF)                                 /* (USBHS_DMAINTR) Register Mask  */


/* -------- USBHS_RQPKTCOUNT : (USBHS Offset: 0x1304) (R/W 32) Host Mode Only: Used To Specify Number Of Packets That Are To Be Transaferred In A Block Transfer -------- */
#define USBHS_RQPKTCOUNT_RESETVALUE           _UINT32_(0x00)                                       /*  (USBHS_RQPKTCOUNT) Host Mode Only: Used To Specify Number Of Packets That Are To Be Transaferred In A Block Transfer  Reset Value */

#define USBHS_RQPKTCOUNT_RQPKTCOUNT_Pos       _UINT32_(0)                                          /* (USBHS_RQPKTCOUNT) sets the number of packets of size maxp that are to be transferred in a block transfer. only used in host mode when autoreq is set. has no effect in peripheral mode or when autoreq is not set. Position */
#define USBHS_RQPKTCOUNT_RQPKTCOUNT_Msk       (_UINT32_(0xFFFF) << USBHS_RQPKTCOUNT_RQPKTCOUNT_Pos) /* (USBHS_RQPKTCOUNT) sets the number of packets of size maxp that are to be transferred in a block transfer. only used in host mode when autoreq is set. has no effect in peripheral mode or when autoreq is not set. Mask */
#define USBHS_RQPKTCOUNT_RQPKTCOUNT(value)    (USBHS_RQPKTCOUNT_RQPKTCOUNT_Msk & (_UINT32_(value) << USBHS_RQPKTCOUNT_RQPKTCOUNT_Pos)) /* Assigment of value for RQPKTCOUNT in the USBHS_RQPKTCOUNT register */
#define USBHS_RQPKTCOUNT_Msk                  _UINT32_(0x0000FFFF)                                 /* (USBHS_RQPKTCOUNT) Register Mask  */


/* -------- USBHS_RXDPKTBUFDIS : (USBHS Offset: 0x1340) (R/W 16) Indicates Which Of The RX Endpoints Have Disabled Double Packet Buffer Functionality -------- */
#define USBHS_RXDPKTBUFDIS_RESETVALUE         _UINT16_(0x00)                                       /*  (USBHS_RXDPKTBUFDIS) Indicates Which Of The RX Endpoints Have Disabled Double Packet Buffer Functionality  Reset Value */

#define USBHS_RXDPKTBUFDIS_EPxRXDIS_Pos       _UINT16_(1)                                          /* (USBHS_RXDPKTBUFDIS) each bit indicates which of the Rx endpoint have disabled double buffer functionality Position */
#define USBHS_RXDPKTBUFDIS_EPxRXDIS_Msk       (_UINT16_(0x7FFF) << USBHS_RXDPKTBUFDIS_EPxRXDIS_Pos) /* (USBHS_RXDPKTBUFDIS) each bit indicates which of the Rx endpoint have disabled double buffer functionality Mask */
#define USBHS_RXDPKTBUFDIS_EPxRXDIS(value)    (USBHS_RXDPKTBUFDIS_EPxRXDIS_Msk & (_UINT16_(value) << USBHS_RXDPKTBUFDIS_EPxRXDIS_Pos)) /* Assigment of value for EPxRXDIS in the USBHS_RXDPKTBUFDIS register */
#define USBHS_RXDPKTBUFDIS_Msk                _UINT16_(0xFFFE)                                     /* (USBHS_RXDPKTBUFDIS) Register Mask  */


/* -------- USBHS_TXDPKTBUFDIS : (USBHS Offset: 0x1342) (R/W 16) Indicates Which Of The TX Endpoints Have Disabled Double Packet Buffer Functionality -------- */
#define USBHS_TXDPKTBUFDIS_RESETVALUE         _UINT16_(0x00)                                       /*  (USBHS_TXDPKTBUFDIS) Indicates Which Of The TX Endpoints Have Disabled Double Packet Buffer Functionality  Reset Value */

#define USBHS_TXDPKTBUFDIS_EPxTXDIS_Pos       _UINT16_(1)                                          /* (USBHS_TXDPKTBUFDIS) each bit indicates which of the Tx endpoint have disabled double buffer functionality Position */
#define USBHS_TXDPKTBUFDIS_EPxTXDIS_Msk       (_UINT16_(0x7FFF) << USBHS_TXDPKTBUFDIS_EPxTXDIS_Pos) /* (USBHS_TXDPKTBUFDIS) each bit indicates which of the Tx endpoint have disabled double buffer functionality Mask */
#define USBHS_TXDPKTBUFDIS_EPxTXDIS(value)    (USBHS_TXDPKTBUFDIS_EPxTXDIS_Msk & (_UINT16_(value) << USBHS_TXDPKTBUFDIS_EPxTXDIS_Pos)) /* Assigment of value for EPxTXDIS in the USBHS_TXDPKTBUFDIS register */
#define USBHS_TXDPKTBUFDIS_Msk                _UINT16_(0xFFFE)                                     /* (USBHS_TXDPKTBUFDIS) Register Mask  */


/* -------- USBHS_CTUCH : (USBHS Offset: 0x1344) (R/W 16) Chirp Timeout. Number Of XCLK Cycles Before The Timeout -------- */
#define USBHS_CTUCH_RESETVALUE                _UINT16_(0x4074)                                     /*  (USBHS_CTUCH) Chirp Timeout. Number Of XCLK Cycles Before The Timeout  Reset Value */

#define USBHS_CTUCH_CTUCH_Pos                 _UINT16_(0)                                          /* (USBHS_CTUCH) this number when multiplied by 4 represents the number of xclk cycles before the timeout occurs Position */
#define USBHS_CTUCH_CTUCH_Msk                 (_UINT16_(0xFFFF) << USBHS_CTUCH_CTUCH_Pos)          /* (USBHS_CTUCH) this number when multiplied by 4 represents the number of xclk cycles before the timeout occurs Mask */
#define USBHS_CTUCH_CTUCH(value)              (USBHS_CTUCH_CTUCH_Msk & (_UINT16_(value) << USBHS_CTUCH_CTUCH_Pos)) /* Assigment of value for CTUCH in the USBHS_CTUCH register */
#define USBHS_CTUCH_Msk                       _UINT16_(0xFFFF)                                     /* (USBHS_CTUCH) Register Mask  */


/* -------- USBHS_CTHHSRTN : (USBHS Offset: 0x1346) (R/W 16) Sets The Delay From The End Of High-Speed Resume Signaling (Acting As A Host) To Enable The UTM Normal Operating Mode -------- */
#define USBHS_CTHHSRTN_RESETVALUE             _UINT16_(0x32)                                       /*  (USBHS_CTHHSRTN) Sets The Delay From The End Of High-Speed Resume Signaling (Acting As A Host) To Enable The UTM Normal Operating Mode  Reset Value */

#define USBHS_CTHHSRTN_CTHHSRTN_Pos           _UINT16_(0)                                          /* (USBHS_CTHHSRTN) the delay from the end of high speed resume signaling to enabling utm normal operating mode. Position */
#define USBHS_CTHHSRTN_CTHHSRTN_Msk           (_UINT16_(0xFFFF) << USBHS_CTHHSRTN_CTHHSRTN_Pos)    /* (USBHS_CTHHSRTN) the delay from the end of high speed resume signaling to enabling utm normal operating mode. Mask */
#define USBHS_CTHHSRTN_CTHHSRTN(value)        (USBHS_CTHHSRTN_CTHHSRTN_Msk & (_UINT16_(value) << USBHS_CTHHSRTN_CTHHSRTN_Pos)) /* Assigment of value for CTHHSRTN in the USBHS_CTHHSRTN register */
#define USBHS_CTHHSRTN_Msk                    _UINT16_(0xFFFF)                                     /* (USBHS_CTHHSRTN) Register Mask  */


/* -------- USBHS_CTHSBT : (USBHS Offset: 0x1348) (R/W 16) This Register Represents The Value To Be Added To The Minimum High Speed Timeout Period Of 736 Bit Times. -------- */
#define USBHS_CTHSBT_RESETVALUE               _UINT16_(0x00)                                       /*  (USBHS_CTHSBT) This Register Represents The Value To Be Added To The Minimum High Speed Timeout Period Of 736 Bit Times.  Reset Value */

#define USBHS_CTHSBT_HSTMEOUTADD_Pos          _UINT16_(0)                                          /* (USBHS_CTHSBT) this register represents the value to be added to the mimumum high speed timeout period of 736 bit times Position */
#define USBHS_CTHSBT_HSTMEOUTADD_Msk          (_UINT16_(0xF) << USBHS_CTHSBT_HSTMEOUTADD_Pos)      /* (USBHS_CTHSBT) this register represents the value to be added to the mimumum high speed timeout period of 736 bit times Mask */
#define USBHS_CTHSBT_HSTMEOUTADD(value)       (USBHS_CTHSBT_HSTMEOUTADD_Msk & (_UINT16_(value) << USBHS_CTHSBT_HSTMEOUTADD_Pos)) /* Assigment of value for HSTMEOUTADD in the USBHS_CTHSBT register */
#define USBHS_CTHSBT_Msk                      _UINT16_(0x000F)                                     /* (USBHS_CTHSBT) Register Mask  */


/* -------- USBHS_LPMATTR : (USBHS Offset: 0x1360) (R/W 16) Defines The Attributes Of An LPM Transaction And Sleep Cycle. -------- */
#define USBHS_LPMATTR_RESETVALUE              _UINT16_(0x00)                                       /*  (USBHS_LPMATTR) Defines The Attributes Of An LPM Transaction And Sleep Cycle.  Reset Value */

#define USBHS_LPMATTR_LINKSTATE_Pos           _UINT16_(0)                                          /* (USBHS_LPMATTR) this value is provided by the host to the peripheral to indicate what state the peripheral must transition to after the receipt and acceptance of a lpm transaction. Position */
#define USBHS_LPMATTR_LINKSTATE_Msk           (_UINT16_(0xF) << USBHS_LPMATTR_LINKSTATE_Pos)       /* (USBHS_LPMATTR) this value is provided by the host to the peripheral to indicate what state the peripheral must transition to after the receipt and acceptance of a lpm transaction. Mask */
#define USBHS_LPMATTR_LINKSTATE(value)        (USBHS_LPMATTR_LINKSTATE_Msk & (_UINT16_(value) << USBHS_LPMATTR_LINKSTATE_Pos)) /* Assigment of value for LINKSTATE in the USBHS_LPMATTR register */
#define   USBHS_LPMATTR_LINKSTATE_SLEEPSTATE_Val _UINT16_(0x1)                                        /* (USBHS_LPMATTR) Sleep State (L1)  */
#define USBHS_LPMATTR_LINKSTATE_SLEEPSTATE    (USBHS_LPMATTR_LINKSTATE_SLEEPSTATE_Val << USBHS_LPMATTR_LINKSTATE_Pos) /* (USBHS_LPMATTR) Sleep State (L1) Position  */
#define USBHS_LPMATTR_HIRD_Pos                _UINT16_(4)                                          /* (USBHS_LPMATTR) this is the host initiated resume duration. Position */
#define USBHS_LPMATTR_HIRD_Msk                (_UINT16_(0xF) << USBHS_LPMATTR_HIRD_Pos)            /* (USBHS_LPMATTR) this is the host initiated resume duration. Mask */
#define USBHS_LPMATTR_HIRD(value)             (USBHS_LPMATTR_HIRD_Msk & (_UINT16_(value) << USBHS_LPMATTR_HIRD_Pos)) /* Assigment of value for HIRD in the USBHS_LPMATTR register */
#define USBHS_LPMATTR_RMTWAK_Pos              _UINT16_(8)                                          /* (USBHS_LPMATTR) this bit is the remote wakeup enable bit. Position */
#define USBHS_LPMATTR_RMTWAK_Msk              (_UINT16_(0x1) << USBHS_LPMATTR_RMTWAK_Pos)          /* (USBHS_LPMATTR) this bit is the remote wakeup enable bit. Mask */
#define USBHS_LPMATTR_RMTWAK(value)           (USBHS_LPMATTR_RMTWAK_Msk & (_UINT16_(value) << USBHS_LPMATTR_RMTWAK_Pos)) /* Assigment of value for RMTWAK in the USBHS_LPMATTR register */
#define USBHS_LPMATTR_ENDPOINT_Pos            _UINT16_(12)                                         /* (USBHS_LPMATTR) this is the endpnt that in the token packet of the lpm transaction. Position */
#define USBHS_LPMATTR_ENDPOINT_Msk            (_UINT16_(0xF) << USBHS_LPMATTR_ENDPOINT_Pos)        /* (USBHS_LPMATTR) this is the endpnt that in the token packet of the lpm transaction. Mask */
#define USBHS_LPMATTR_ENDPOINT(value)         (USBHS_LPMATTR_ENDPOINT_Msk & (_UINT16_(value) << USBHS_LPMATTR_ENDPOINT_Pos)) /* Assigment of value for ENDPOINT in the USBHS_LPMATTR register */
#define USBHS_LPMATTR_Msk                     _UINT16_(0xF1FF)                                     /* (USBHS_LPMATTR) Register Mask  */


/* -------- USBHS_LPMCNTRL : (USBHS Offset: 0x1362) (R/W 8) LPM Control Register -------- */
#define USBHS_LPMCNTRL_RESETVALUE             _UINT8_(0x00)                                        /*  (USBHS_LPMCNTRL) LPM Control Register  Reset Value */

#define USBHS_LPMCNTRL_Msk                    _UINT8_(0x00)                                        /* (USBHS_LPMCNTRL) Register Mask  */

/* HOST mode */
#define USBHS_LPMCNTRL_HOST_LPMXMT_Pos        _UINT8_(0)                                           /* (USBHS_LPMCNTRL) software should set this bit to transmit an lpm transaction. Position */
#define USBHS_LPMCNTRL_HOST_LPMXMT_Msk        (_UINT8_(0x1) << USBHS_LPMCNTRL_HOST_LPMXMT_Pos)     /* (USBHS_LPMCNTRL) software should set this bit to transmit an lpm transaction. Mask */
#define USBHS_LPMCNTRL_HOST_LPMXMT(value)     (USBHS_LPMCNTRL_HOST_LPMXMT_Msk & (_UINT8_(value) << USBHS_LPMCNTRL_HOST_LPMXMT_Pos))
#define USBHS_LPMCNTRL_HOST_LPMRES_Pos        _UINT8_(1)                                           /* (USBHS_LPMCNTRL) this bit is used by software to initiate a resume from the l1 state Position */
#define USBHS_LPMCNTRL_HOST_LPMRES_Msk        (_UINT8_(0x1) << USBHS_LPMCNTRL_HOST_LPMRES_Pos)     /* (USBHS_LPMCNTRL) this bit is used by software to initiate a resume from the l1 state Mask */
#define USBHS_LPMCNTRL_HOST_LPMRES(value)     (USBHS_LPMCNTRL_HOST_LPMRES_Msk & (_UINT8_(value) << USBHS_LPMCNTRL_HOST_LPMRES_Pos))
#define USBHS_LPMCNTRL_HOST_Msk               _UINT8_(0x03)                                         /* (USBHS_LPMCNTRL_HOST) Register Mask  */

/* PERIPHERAL mode */
#define USBHS_LPMCNTRL_PERIPHERAL_LPMXMT_Pos  _UINT8_(0)                                           /* (USBHS_LPMCNTRL) this bit is set by software to instruct the core to transition to the l1 state upon the receipt of the next lpm transaction. Position */
#define USBHS_LPMCNTRL_PERIPHERAL_LPMXMT_Msk  (_UINT8_(0x1) << USBHS_LPMCNTRL_PERIPHERAL_LPMXMT_Pos) /* (USBHS_LPMCNTRL) this bit is set by software to instruct the core to transition to the l1 state upon the receipt of the next lpm transaction. Mask */
#define USBHS_LPMCNTRL_PERIPHERAL_LPMXMT(value) (USBHS_LPMCNTRL_PERIPHERAL_LPMXMT_Msk & (_UINT8_(value) << USBHS_LPMCNTRL_PERIPHERAL_LPMXMT_Pos))
#define USBHS_LPMCNTRL_PERIPHERAL_LPMRES_Pos  _UINT8_(1)                                           /* (USBHS_LPMCNTRL) this bit is used by software to initiate resume (remote wakeup). Position */
#define USBHS_LPMCNTRL_PERIPHERAL_LPMRES_Msk  (_UINT8_(0x1) << USBHS_LPMCNTRL_PERIPHERAL_LPMRES_Pos) /* (USBHS_LPMCNTRL) this bit is used by software to initiate resume (remote wakeup). Mask */
#define USBHS_LPMCNTRL_PERIPHERAL_LPMRES(value) (USBHS_LPMCNTRL_PERIPHERAL_LPMRES_Msk & (_UINT8_(value) << USBHS_LPMCNTRL_PERIPHERAL_LPMRES_Pos))
#define USBHS_LPMCNTRL_PERIPHERAL_LPMEN_Pos   _UINT8_(2)                                           /* (USBHS_LPMCNTRL) this register is used to enable lpm in the musbmhdrc. Position */
#define USBHS_LPMCNTRL_PERIPHERAL_LPMEN_Msk   (_UINT8_(0x3) << USBHS_LPMCNTRL_PERIPHERAL_LPMEN_Pos) /* (USBHS_LPMCNTRL) this register is used to enable lpm in the musbmhdrc. Mask */
#define USBHS_LPMCNTRL_PERIPHERAL_LPMEN(value) (USBHS_LPMCNTRL_PERIPHERAL_LPMEN_Msk & (_UINT8_(value) << USBHS_LPMCNTRL_PERIPHERAL_LPMEN_Pos))
#define   USBHS_LPMCNTRL_PERIPHERAL_LPMEN_LPMTRANS_Val _UINT8_(0x0)                                         /* (USBHS_LPMCNTRL) Core supports LPM extended transactions  */
#define   USBHS_LPMCNTRL_PERIPHERAL_LPMEN_EXTNTRANS_Val _UINT8_(0x1)                                         /* (USBHS_LPMCNTRL) LPM is not supported but extended transactions are supported.  */
#define   USBHS_LPMCNTRL_PERIPHERAL_LPMEN_NOTSUPPORTED1_Val _UINT8_(0x2)                                         /* (USBHS_LPMCNTRL) LPM and extended transactions are not supported  */
#define   USBHS_LPMCNTRL_PERIPHERAL_LPMEN_NOTSUPPORTED2_Val _UINT8_(0x3)                                         /* (USBHS_LPMCNTRL) LPM and extended transactions are not supported  */
#define USBHS_LPMCNTRL_PERIPHERAL_LPMEN_LPMTRANS (USBHS_LPMCNTRL_PERIPHERAL_LPMEN_LPMTRANS_Val << USBHS_LPMCNTRL_PERIPHERAL_LPMEN_Pos) /* (USBHS_LPMCNTRL) Core supports LPM extended transactions Position  */
#define USBHS_LPMCNTRL_PERIPHERAL_LPMEN_EXTNTRANS (USBHS_LPMCNTRL_PERIPHERAL_LPMEN_EXTNTRANS_Val << USBHS_LPMCNTRL_PERIPHERAL_LPMEN_Pos) /* (USBHS_LPMCNTRL) LPM is not supported but extended transactions are supported. Position  */
#define USBHS_LPMCNTRL_PERIPHERAL_LPMEN_NOTSUPPORTED1 (USBHS_LPMCNTRL_PERIPHERAL_LPMEN_NOTSUPPORTED1_Val << USBHS_LPMCNTRL_PERIPHERAL_LPMEN_Pos) /* (USBHS_LPMCNTRL) LPM and extended transactions are not supported Position  */
#define USBHS_LPMCNTRL_PERIPHERAL_LPMEN_NOTSUPPORTED2 (USBHS_LPMCNTRL_PERIPHERAL_LPMEN_NOTSUPPORTED2_Val << USBHS_LPMCNTRL_PERIPHERAL_LPMEN_Pos) /* (USBHS_LPMCNTRL) LPM and extended transactions are not supported Position  */
#define USBHS_LPMCNTRL_PERIPHERAL_LPMNAK_Pos  _UINT8_(4)                                           /* (USBHS_LPMCNTRL) this bit is used to place all end points in a state such that the response to all transactions other then an lpm transaction will be a nak. Position */
#define USBHS_LPMCNTRL_PERIPHERAL_LPMNAK_Msk  (_UINT8_(0x1) << USBHS_LPMCNTRL_PERIPHERAL_LPMNAK_Pos) /* (USBHS_LPMCNTRL) this bit is used to place all end points in a state such that the response to all transactions other then an lpm transaction will be a nak. Mask */
#define USBHS_LPMCNTRL_PERIPHERAL_LPMNAK(value) (USBHS_LPMCNTRL_PERIPHERAL_LPMNAK_Msk & (_UINT8_(value) << USBHS_LPMCNTRL_PERIPHERAL_LPMNAK_Pos))
#define USBHS_LPMCNTRL_PERIPHERAL_Msk         _UINT8_(0x1F)                                         /* (USBHS_LPMCNTRL_PERIPHERAL) Register Mask  */


/* -------- USBHS_LPMINTREN : (USBHS Offset: 0x1363) (R/W 8) LPM Interrupts Enable Register -------- */
#define USBHS_LPMINTREN_RESETVALUE            _UINT8_(0x00)                                        /*  (USBHS_LPMINTREN) LPM Interrupts Enable Register  Reset Value */

#define USBHS_LPMINTREN_LPMSTEN_Pos           _UINT8_(0)                                           /* (USBHS_LPMINTREN) LPMMST interrupt Position */
#define USBHS_LPMINTREN_LPMSTEN_Msk           (_UINT8_(0x1) << USBHS_LPMINTREN_LPMSTEN_Pos)        /* (USBHS_LPMINTREN) LPMMST interrupt Mask */
#define USBHS_LPMINTREN_LPMSTEN(value)        (USBHS_LPMINTREN_LPMSTEN_Msk & (_UINT8_(value) << USBHS_LPMINTREN_LPMSTEN_Pos)) /* Assigment of value for LPMSTEN in the USBHS_LPMINTREN register */
#define USBHS_LPMINTREN_LPMNYEN_Pos           _UINT8_(1)                                           /* (USBHS_LPMINTREN) LPMMNY interrupt Position */
#define USBHS_LPMINTREN_LPMNYEN_Msk           (_UINT8_(0x1) << USBHS_LPMINTREN_LPMNYEN_Pos)        /* (USBHS_LPMINTREN) LPMMNY interrupt Mask */
#define USBHS_LPMINTREN_LPMNYEN(value)        (USBHS_LPMINTREN_LPMNYEN_Msk & (_UINT8_(value) << USBHS_LPMINTREN_LPMNYEN_Pos)) /* Assigment of value for LPMNYEN in the USBHS_LPMINTREN register */
#define USBHS_LPMINTREN_LPMACKEN_Pos          _UINT8_(2)                                           /* (USBHS_LPMINTREN) LPMACK interrupt Position */
#define USBHS_LPMINTREN_LPMACKEN_Msk          (_UINT8_(0x1) << USBHS_LPMINTREN_LPMACKEN_Pos)       /* (USBHS_LPMINTREN) LPMACK interrupt Mask */
#define USBHS_LPMINTREN_LPMACKEN(value)       (USBHS_LPMINTREN_LPMACKEN_Msk & (_UINT8_(value) << USBHS_LPMINTREN_LPMACKEN_Pos)) /* Assigment of value for LPMACKEN in the USBHS_LPMINTREN register */
#define USBHS_LPMINTREN_LPMNCEN_Pos           _UINT8_(3)                                           /* (USBHS_LPMINTREN) LPMNC interrupt Position */
#define USBHS_LPMINTREN_LPMNCEN_Msk           (_UINT8_(0x1) << USBHS_LPMINTREN_LPMNCEN_Pos)        /* (USBHS_LPMINTREN) LPMNC interrupt Mask */
#define USBHS_LPMINTREN_LPMNCEN(value)        (USBHS_LPMINTREN_LPMNCEN_Msk & (_UINT8_(value) << USBHS_LPMINTREN_LPMNCEN_Pos)) /* Assigment of value for LPMNCEN in the USBHS_LPMINTREN register */
#define USBHS_LPMINTREN_LPMRESEN_Pos          _UINT8_(4)                                           /* (USBHS_LPMINTREN) LPMRES interrupt Position */
#define USBHS_LPMINTREN_LPMRESEN_Msk          (_UINT8_(0x1) << USBHS_LPMINTREN_LPMRESEN_Pos)       /* (USBHS_LPMINTREN) LPMRES interrupt Mask */
#define USBHS_LPMINTREN_LPMRESEN(value)       (USBHS_LPMINTREN_LPMRESEN_Msk & (_UINT8_(value) << USBHS_LPMINTREN_LPMRESEN_Pos)) /* Assigment of value for LPMRESEN in the USBHS_LPMINTREN register */
#define USBHS_LPMINTREN_LPMERREN_Pos          _UINT8_(5)                                           /* (USBHS_LPMINTREN) LPMERR interrupt Position */
#define USBHS_LPMINTREN_LPMERREN_Msk          (_UINT8_(0x1) << USBHS_LPMINTREN_LPMERREN_Pos)       /* (USBHS_LPMINTREN) LPMERR interrupt Mask */
#define USBHS_LPMINTREN_LPMERREN(value)       (USBHS_LPMINTREN_LPMERREN_Msk & (_UINT8_(value) << USBHS_LPMINTREN_LPMERREN_Pos)) /* Assigment of value for LPMERREN in the USBHS_LPMINTREN register */
#define USBHS_LPMINTREN_Msk                   _UINT8_(0x3F)                                        /* (USBHS_LPMINTREN) Register Mask  */


/* -------- USBHS_LPMINTR : (USBHS Offset: 0x1364) (R/W 8) Status Of The LPM Power State -------- */
#define USBHS_LPMINTR_RESETVALUE              _UINT8_(0x00)                                        /*  (USBHS_LPMINTR) Status Of The LPM Power State  Reset Value */

#define USBHS_LPMINTR_Msk                     _UINT8_(0x00)                                        /* (USBHS_LPMINTR) Register Mask  */

/* HOST mode */
#define USBHS_LPMINTR_HOST_LPMST_Pos          _UINT8_(0)                                           /* (USBHS_LPMINTR) this bit is set when an lpm transaction is transmitted and the device responds with a stall. Position */
#define USBHS_LPMINTR_HOST_LPMST_Msk          (_UINT8_(0x1) << USBHS_LPMINTR_HOST_LPMST_Pos)       /* (USBHS_LPMINTR) this bit is set when an lpm transaction is transmitted and the device responds with a stall. Mask */
#define USBHS_LPMINTR_HOST_LPMST(value)       (USBHS_LPMINTR_HOST_LPMST_Msk & (_UINT8_(value) << USBHS_LPMINTR_HOST_LPMST_Pos))
#define USBHS_LPMINTR_HOST_LPMNY_Pos          _UINT8_(1)                                           /* (USBHS_LPMINTR) this bit is set when an lpm transaction is transmitted and the device responds with a nyet. Position */
#define USBHS_LPMINTR_HOST_LPMNY_Msk          (_UINT8_(0x1) << USBHS_LPMINTR_HOST_LPMNY_Pos)       /* (USBHS_LPMINTR) this bit is set when an lpm transaction is transmitted and the device responds with a nyet. Mask */
#define USBHS_LPMINTR_HOST_LPMNY(value)       (USBHS_LPMINTR_HOST_LPMNY_Msk & (_UINT8_(value) << USBHS_LPMINTR_HOST_LPMNY_Pos))
#define USBHS_LPMINTR_HOST_LPMACK_Pos         _UINT8_(2)                                           /* (USBHS_LPMINTR) this bit is set when an lpm transaction is transmitted and the device responds with an ack. Position */
#define USBHS_LPMINTR_HOST_LPMACK_Msk         (_UINT8_(0x1) << USBHS_LPMINTR_HOST_LPMACK_Pos)      /* (USBHS_LPMINTR) this bit is set when an lpm transaction is transmitted and the device responds with an ack. Mask */
#define USBHS_LPMINTR_HOST_LPMACK(value)      (USBHS_LPMINTR_HOST_LPMACK_Msk & (_UINT8_(value) << USBHS_LPMINTR_HOST_LPMACK_Pos))
#define USBHS_LPMINTR_HOST_LPMNC_Pos          _UINT8_(3)                                           /* (USBHS_LPMINTR) this bit is set when an lpm transaction has been transmitted and has failed to complete. Position */
#define USBHS_LPMINTR_HOST_LPMNC_Msk          (_UINT8_(0x1) << USBHS_LPMINTR_HOST_LPMNC_Pos)       /* (USBHS_LPMINTR) this bit is set when an lpm transaction has been transmitted and has failed to complete. Mask */
#define USBHS_LPMINTR_HOST_LPMNC(value)       (USBHS_LPMINTR_HOST_LPMNC_Msk & (_UINT8_(value) << USBHS_LPMINTR_HOST_LPMNC_Pos))
#define USBHS_LPMINTR_HOST_LPMRES_Pos         _UINT8_(4)                                           /* (USBHS_LPMINTR) this bit is set when the core has been resumed for any reason. Position */
#define USBHS_LPMINTR_HOST_LPMRES_Msk         (_UINT8_(0x1) << USBHS_LPMINTR_HOST_LPMRES_Pos)      /* (USBHS_LPMINTR) this bit is set when the core has been resumed for any reason. Mask */
#define USBHS_LPMINTR_HOST_LPMRES(value)      (USBHS_LPMINTR_HOST_LPMRES_Msk & (_UINT8_(value) << USBHS_LPMINTR_HOST_LPMRES_Pos))
#define USBHS_LPMINTR_HOST_LPMERR_Pos         _UINT8_(5)                                           /* (USBHS_LPMINTR) this bit is set if a response to the lpm transaction is received with a bit stuff error or a pid error Position */
#define USBHS_LPMINTR_HOST_LPMERR_Msk         (_UINT8_(0x1) << USBHS_LPMINTR_HOST_LPMERR_Pos)      /* (USBHS_LPMINTR) this bit is set if a response to the lpm transaction is received with a bit stuff error or a pid error Mask */
#define USBHS_LPMINTR_HOST_LPMERR(value)      (USBHS_LPMINTR_HOST_LPMERR_Msk & (_UINT8_(value) << USBHS_LPMINTR_HOST_LPMERR_Pos))
#define USBHS_LPMINTR_HOST_Msk                _UINT8_(0x3F)                                         /* (USBHS_LPMINTR_HOST) Register Mask  */

/* PERIPHERAL mode */
#define USBHS_LPMINTR_PERIPHERAL_LPMST_Pos    _UINT8_(0)                                           /* (USBHS_LPMINTR) this bit is set when an lpm transaction is received and the core responds with a stall. Position */
#define USBHS_LPMINTR_PERIPHERAL_LPMST_Msk    (_UINT8_(0x1) << USBHS_LPMINTR_PERIPHERAL_LPMST_Pos) /* (USBHS_LPMINTR) this bit is set when an lpm transaction is received and the core responds with a stall. Mask */
#define USBHS_LPMINTR_PERIPHERAL_LPMST(value) (USBHS_LPMINTR_PERIPHERAL_LPMST_Msk & (_UINT8_(value) << USBHS_LPMINTR_PERIPHERAL_LPMST_Pos))
#define USBHS_LPMINTR_PERIPHERAL_LPMNY_Pos    _UINT8_(1)                                           /* (USBHS_LPMINTR) this bit is set when an lpm transaction is received and the core responds with a nyet Position */
#define USBHS_LPMINTR_PERIPHERAL_LPMNY_Msk    (_UINT8_(0x1) << USBHS_LPMINTR_PERIPHERAL_LPMNY_Pos) /* (USBHS_LPMINTR) this bit is set when an lpm transaction is received and the core responds with a nyet Mask */
#define USBHS_LPMINTR_PERIPHERAL_LPMNY(value) (USBHS_LPMINTR_PERIPHERAL_LPMNY_Msk & (_UINT8_(value) << USBHS_LPMINTR_PERIPHERAL_LPMNY_Pos))
#define USBHS_LPMINTR_PERIPHERAL_LPMACK_Pos   _UINT8_(2)                                           /* (USBHS_LPMINTR) this bit is set when an lpm transaction is received and the core responds with an ack. Position */
#define USBHS_LPMINTR_PERIPHERAL_LPMACK_Msk   (_UINT8_(0x1) << USBHS_LPMINTR_PERIPHERAL_LPMACK_Pos) /* (USBHS_LPMINTR) this bit is set when an lpm transaction is received and the core responds with an ack. Mask */
#define USBHS_LPMINTR_PERIPHERAL_LPMACK(value) (USBHS_LPMINTR_PERIPHERAL_LPMACK_Msk & (_UINT8_(value) << USBHS_LPMINTR_PERIPHERAL_LPMACK_Pos))
#define USBHS_LPMINTR_PERIPHERAL_LPMNC_Pos    _UINT8_(3)                                           /* (USBHS_LPMINTR) this bit is set when an lpm transaction is received and the core responds with a nyet due to data pending in the rx fifos. Position */
#define USBHS_LPMINTR_PERIPHERAL_LPMNC_Msk    (_UINT8_(0x1) << USBHS_LPMINTR_PERIPHERAL_LPMNC_Pos) /* (USBHS_LPMINTR) this bit is set when an lpm transaction is received and the core responds with a nyet due to data pending in the rx fifos. Mask */
#define USBHS_LPMINTR_PERIPHERAL_LPMNC(value) (USBHS_LPMINTR_PERIPHERAL_LPMNC_Msk & (_UINT8_(value) << USBHS_LPMINTR_PERIPHERAL_LPMNC_Pos))
#define USBHS_LPMINTR_PERIPHERAL_LPMRES_Pos   _UINT8_(4)                                           /* (USBHS_LPMINTR) this bit is set if the core has been resumed for any reason. Position */
#define USBHS_LPMINTR_PERIPHERAL_LPMRES_Msk   (_UINT8_(0x1) << USBHS_LPMINTR_PERIPHERAL_LPMRES_Pos) /* (USBHS_LPMINTR) this bit is set if the core has been resumed for any reason. Mask */
#define USBHS_LPMINTR_PERIPHERAL_LPMRES(value) (USBHS_LPMINTR_PERIPHERAL_LPMRES_Msk & (_UINT8_(value) << USBHS_LPMINTR_PERIPHERAL_LPMRES_Pos))
#define USBHS_LPMINTR_PERIPHERAL_LPMERR_Pos   _UINT8_(5)                                           /* (USBHS_LPMINTR) this bit is set if an lpm transaction is received that has a linkstate field that is not supported Position */
#define USBHS_LPMINTR_PERIPHERAL_LPMERR_Msk   (_UINT8_(0x1) << USBHS_LPMINTR_PERIPHERAL_LPMERR_Pos) /* (USBHS_LPMINTR) this bit is set if an lpm transaction is received that has a linkstate field that is not supported Mask */
#define USBHS_LPMINTR_PERIPHERAL_LPMERR(value) (USBHS_LPMINTR_PERIPHERAL_LPMERR_Msk & (_UINT8_(value) << USBHS_LPMINTR_PERIPHERAL_LPMERR_Pos))
#define USBHS_LPMINTR_PERIPHERAL_Msk          _UINT8_(0x3F)                                         /* (USBHS_LPMINTR_PERIPHERAL) Register Mask  */


/* -------- USBHS_LPMFADDR : (USBHS Offset: 0x1365) (R/W 8) Function Address In LPM Payload -------- */
#define USBHS_LPMFADDR_RESETVALUE             _UINT8_(0x00)                                        /*  (USBHS_LPMFADDR) Function Address In LPM Payload  Reset Value */

#define USBHS_LPMFADDR_FUNCADDR_Pos           _UINT8_(0)                                           /* (USBHS_LPMFADDR) function address that will be placed in the LPM payload Position */
#define USBHS_LPMFADDR_FUNCADDR_Msk           (_UINT8_(0x7F) << USBHS_LPMFADDR_FUNCADDR_Pos)       /* (USBHS_LPMFADDR) function address that will be placed in the LPM payload Mask */
#define USBHS_LPMFADDR_FUNCADDR(value)        (USBHS_LPMFADDR_FUNCADDR_Msk & (_UINT8_(value) << USBHS_LPMFADDR_FUNCADDR_Pos)) /* Assigment of value for FUNCADDR in the USBHS_LPMFADDR register */
#define USBHS_LPMFADDR_Msk                    _UINT8_(0x7F)                                        /* (USBHS_LPMFADDR) Register Mask  */


/* -------- USBHS_PHY00 : (USBHS Offset: 0x1500) (R/W 32) USBHPHY Control Register. -------- */
#define USBHS_PHY00_RESETVALUE                _UINT32_(0x19)                                       /*  (USBHS_PHY00) USBHPHY Control Register.  Reset Value */

#define USBHS_PHY00_PREEMP_Pos                _UINT32_(0)                                          /* (USBHS_PHY00) enables pre-emphasis Position */
#define USBHS_PHY00_PREEMP_Msk                (_UINT32_(0x7) << USBHS_PHY00_PREEMP_Pos)            /* (USBHS_PHY00) enables pre-emphasis Mask */
#define USBHS_PHY00_PREEMP(value)             (USBHS_PHY00_PREEMP_Msk & (_UINT32_(value) << USBHS_PHY00_PREEMP_Pos)) /* Assigment of value for PREEMP in the USBHS_PHY00 register */
#define   USBHS_PHY00_PREEMP_SOFEOP_Val       _UINT32_(0x0)                                        /* (USBHS_PHY00) Enable pre-emphasis during SOF and EOP  */
#define   USBHS_PHY00_PREEMP_CHIRP_Val        _UINT32_(0x1)                                        /* (USBHS_PHY00) Enable pre-emphasis during chirp  */
#define   USBHS_PHY00_PREEMP_NONCHIRP_Val     _UINT32_(0x2)                                        /* (USBHS_PHY00) Enable pre-emphasis in non-chirp state  */
#define   USBHS_PHY00_PREEMP_ALWAYS_Val       _UINT32_(0x3)                                        /* (USBHS_PHY00) Always enable pre-emphasis  */
#define USBHS_PHY00_PREEMP_SOFEOP             (USBHS_PHY00_PREEMP_SOFEOP_Val << USBHS_PHY00_PREEMP_Pos) /* (USBHS_PHY00) Enable pre-emphasis during SOF and EOP Position  */
#define USBHS_PHY00_PREEMP_CHIRP              (USBHS_PHY00_PREEMP_CHIRP_Val << USBHS_PHY00_PREEMP_Pos) /* (USBHS_PHY00) Enable pre-emphasis during chirp Position  */
#define USBHS_PHY00_PREEMP_NONCHIRP           (USBHS_PHY00_PREEMP_NONCHIRP_Val << USBHS_PHY00_PREEMP_Pos) /* (USBHS_PHY00) Enable pre-emphasis in non-chirp state Position  */
#define USBHS_PHY00_PREEMP_ALWAYS             (USBHS_PHY00_PREEMP_ALWAYS_Val << USBHS_PHY00_PREEMP_Pos) /* (USBHS_PHY00) Always enable pre-emphasis Position  */
#define USBHS_PHY00_SLEWRATE_Pos              _UINT32_(3)                                          /* (USBHS_PHY00) adjust FS/LS slew rate Position */
#define USBHS_PHY00_SLEWRATE_Msk              (_UINT32_(0x3) << USBHS_PHY00_SLEWRATE_Pos)          /* (USBHS_PHY00) adjust FS/LS slew rate Mask */
#define USBHS_PHY00_SLEWRATE(value)           (USBHS_PHY00_SLEWRATE_Msk & (_UINT32_(value) << USBHS_PHY00_SLEWRATE_Pos)) /* Assigment of value for SLEWRATE in the USBHS_PHY00 register */
#define   USBHS_PHY00_SLEWRATE_HIGH_Val       _UINT32_(0x0)                                        /* (USBHS_PHY00) Highest slew rate  */
#define   USBHS_PHY00_SLEWRATE_MIDDLE0_Val    _UINT32_(0x1)                                        /* (USBHS_PHY00) Middle slew rate  */
#define   USBHS_PHY00_SLEWRATE_MIDDLE1_Val    _UINT32_(0x2)                                        /* (USBHS_PHY00) Middle slew rate  */
#define   USBHS_PHY00_SLEWRATE_SMALLEST_Val   _UINT32_(0x3)                                        /* (USBHS_PHY00) Smallest slew rate  */
#define USBHS_PHY00_SLEWRATE_HIGH             (USBHS_PHY00_SLEWRATE_HIGH_Val << USBHS_PHY00_SLEWRATE_Pos) /* (USBHS_PHY00) Highest slew rate Position  */
#define USBHS_PHY00_SLEWRATE_MIDDLE0          (USBHS_PHY00_SLEWRATE_MIDDLE0_Val << USBHS_PHY00_SLEWRATE_Pos) /* (USBHS_PHY00) Middle slew rate Position  */
#define USBHS_PHY00_SLEWRATE_MIDDLE1          (USBHS_PHY00_SLEWRATE_MIDDLE1_Val << USBHS_PHY00_SLEWRATE_Pos) /* (USBHS_PHY00) Middle slew rate Position  */
#define USBHS_PHY00_SLEWRATE_SMALLEST         (USBHS_PHY00_SLEWRATE_SMALLEST_Val << USBHS_PHY00_SLEWRATE_Pos) /* (USBHS_PHY00) Smallest slew rate Position  */
#define USBHS_PHY00_RXPHSSEL_Pos              _UINT32_(5)                                          /* (USBHS_PHY00) RX clock phase select Position */
#define USBHS_PHY00_RXPHSSEL_Msk              (_UINT32_(0x7) << USBHS_PHY00_RXPHSSEL_Pos)          /* (USBHS_PHY00) RX clock phase select Mask */
#define USBHS_PHY00_RXPHSSEL(value)           (USBHS_PHY00_RXPHSSEL_Msk & (_UINT32_(value) << USBHS_PHY00_RXPHSSEL_Pos)) /* Assigment of value for RXPHSSEL in the USBHS_PHY00 register */
#define   USBHS_PHY00_RXPHSSEL_EARLIEST_Val   _UINT32_(0x0)                                        /* (USBHS_PHY00) Earliest phase  */
#define   USBHS_PHY00_RXPHSSEL_LATEST_Val     _UINT32_(0x7)                                        /* (USBHS_PHY00) Latest phase  */
#define USBHS_PHY00_RXPHSSEL_EARLIEST         (USBHS_PHY00_RXPHSSEL_EARLIEST_Val << USBHS_PHY00_RXPHSSEL_Pos) /* (USBHS_PHY00) Earliest phase Position  */
#define USBHS_PHY00_RXPHSSEL_LATEST           (USBHS_PHY00_RXPHSSEL_LATEST_Val << USBHS_PHY00_RXPHSSEL_Pos) /* (USBHS_PHY00) Latest phase Position  */
#define USBHS_PHY00_Msk                       _UINT32_(0x000000FF)                                 /* (USBHS_PHY00) Register Mask  */


/* -------- USBHS_PHY04 : (USBHS Offset: 0x1504) (R/W 32) USBHPHY Control Register. -------- */
#define USBHS_PHY04_RESETVALUE                _UINT32_(0x8F)                                       /*  (USBHS_PHY04) USBHPHY Control Register.  Reset Value */

#define USBHS_PHY04_TXPHSSEL_Pos              _UINT32_(0)                                          /* (USBHS_PHY04) set the Tx clock phase select Position */
#define USBHS_PHY04_TXPHSSEL_Msk              (_UINT32_(0x3) << USBHS_PHY04_TXPHSSEL_Pos)          /* (USBHS_PHY04) set the Tx clock phase select Mask */
#define USBHS_PHY04_TXPHSSEL(value)           (USBHS_PHY04_TXPHSSEL_Msk & (_UINT32_(value) << USBHS_PHY04_TXPHSSEL_Pos)) /* Assigment of value for TXPHSSEL in the USBHS_PHY04 register */
#define USBHS_PHY04_RSVD_Pos                  _UINT32_(3)                                          /* (USBHS_PHY04) Reserved Position */
#define USBHS_PHY04_RSVD_Msk                  (_UINT32_(0x1) << USBHS_PHY04_RSVD_Pos)              /* (USBHS_PHY04) Reserved Mask */
#define USBHS_PHY04_RSVD(value)               (USBHS_PHY04_RSVD_Msk & (_UINT32_(value) << USBHS_PHY04_RSVD_Pos)) /* Assigment of value for RSVD in the USBHS_PHY04 register */
#define USBHS_PHY04_HIZ_Pos                   _UINT32_(4)                                          /* (USBHS_PHY04) Set D+/D- to a high impedence state Position */
#define USBHS_PHY04_HIZ_Msk                   (_UINT32_(0x1) << USBHS_PHY04_HIZ_Pos)               /* (USBHS_PHY04) Set D+/D- to a high impedence state Mask */
#define USBHS_PHY04_HIZ(value)                (USBHS_PHY04_HIZ_Msk & (_UINT32_(value) << USBHS_PHY04_HIZ_Pos)) /* Assigment of value for HIZ in the USBHS_PHY04 register */
#define USBHS_PHY04_SQUELCH210_Pos            _UINT32_(5)                                          /* (USBHS_PHY04) Lower 3 bits of RX squelch trigger point configuration Position */
#define USBHS_PHY04_SQUELCH210_Msk            (_UINT32_(0x7) << USBHS_PHY04_SQUELCH210_Pos)        /* (USBHS_PHY04) Lower 3 bits of RX squelch trigger point configuration Mask */
#define USBHS_PHY04_SQUELCH210(value)         (USBHS_PHY04_SQUELCH210_Msk & (_UINT32_(value) << USBHS_PHY04_SQUELCH210_Pos)) /* Assigment of value for SQUELCH210 in the USBHS_PHY04 register */
#define USBHS_PHY04_Msk                       _UINT32_(0x000000FB)                                 /* (USBHS_PHY04) Register Mask  */


/* -------- USBHS_PHY08 : (USBHS Offset: 0x1508) (R/W 32) USBHPHY Control Register. -------- */
#define USBHS_PHY08_RESETVALUE                _UINT32_(0x07)                                       /*  (USBHS_PHY08) USBHPHY Control Register.  Reset Value */

#define USBHS_PHY08_SQUELCH3_Pos              _UINT32_(0)                                          /* (USBHS_PHY08) MSB of Squelch configuration Position */
#define USBHS_PHY08_SQUELCH3_Msk              (_UINT32_(0x1) << USBHS_PHY08_SQUELCH3_Pos)          /* (USBHS_PHY08) MSB of Squelch configuration Mask */
#define USBHS_PHY08_SQUELCH3(value)           (USBHS_PHY08_SQUELCH3_Msk & (_UINT32_(value) << USBHS_PHY08_SQUELCH3_Pos)) /* Assigment of value for SQUELCH3 in the USBHS_PHY08 register */
#define USBHS_PHY08_RSVD_Pos                  _UINT32_(1)                                          /* (USBHS_PHY08) Reserved Position */
#define USBHS_PHY08_RSVD_Msk                  (_UINT32_(0x7F) << USBHS_PHY08_RSVD_Pos)             /* (USBHS_PHY08) Reserved Mask */
#define USBHS_PHY08_RSVD(value)               (USBHS_PHY08_RSVD_Msk & (_UINT32_(value) << USBHS_PHY08_RSVD_Pos)) /* Assigment of value for RSVD in the USBHS_PHY08 register */
#define USBHS_PHY08_Msk                       _UINT32_(0x000000FF)                                 /* (USBHS_PHY08) Register Mask  */

#define USBHS_PHY08_SQUELCH_Pos               _UINT32_(0)                                          /* (USBHS_PHY08 Position) MSB of Squelch configuration */
#define USBHS_PHY08_SQUELCH_Msk               (_UINT32_(0x1) << USBHS_PHY08_SQUELCH_Pos)           /* (USBHS_PHY08 Mask) SQUELCH */
#define USBHS_PHY08_SQUELCH(value)            (USBHS_PHY08_SQUELCH_Msk & (_UINT32_(value) << USBHS_PHY08_SQUELCH_Pos)) 

/* -------- USBHS_PHY0C : (USBHS Offset: 0x150C) (R/W 32) USBHPHY Control Register. -------- */
#define USBHS_PHY0C_RESETVALUE                _UINT32_(0xE0)                                       /*  (USBHS_PHY0C) USBHPHY Control Register.  Reset Value */

#define USBHS_PHY0C_TUNE210_Pos               _UINT32_(5)                                          /* (USBHS_PHY0C) Lower 3 bits for HS amplitude tuning Position */
#define USBHS_PHY0C_TUNE210_Msk               (_UINT32_(0x7F) << USBHS_PHY0C_TUNE210_Pos)          /* (USBHS_PHY0C) Lower 3 bits for HS amplitude tuning Mask */
#define USBHS_PHY0C_TUNE210(value)            (USBHS_PHY0C_TUNE210_Msk & (_UINT32_(value) << USBHS_PHY0C_TUNE210_Pos)) /* Assigment of value for TUNE210 in the USBHS_PHY0C register */
#define USBHS_PHY0C_Msk                       _UINT32_(0x00000FE0)                                 /* (USBHS_PHY0C) Register Mask  */


/* -------- USBHS_PHY10 : (USBHS Offset: 0x1510) (R/W 32) USBHPHY Control Register. -------- */
#define USBHS_PHY10_RESETVALUE                _UINT32_(0xAA)                                       /*  (USBHS_PHY10) USBHPHY Control Register.  Reset Value */

#define USBHS_PHY10_TUNE76543_Pos             _UINT32_(0)                                          /* (USBHS_PHY10) Upper 5 bits for HS amplitude tuning Position */
#define USBHS_PHY10_TUNE76543_Msk             (_UINT32_(0x1F) << USBHS_PHY10_TUNE76543_Pos)        /* (USBHS_PHY10) Upper 5 bits for HS amplitude tuning Mask */
#define USBHS_PHY10_TUNE76543(value)          (USBHS_PHY10_TUNE76543_Msk & (_UINT32_(value) << USBHS_PHY10_TUNE76543_Pos)) /* Assigment of value for TUNE76543 in the USBHS_PHY10 register */
#define USBHS_PHY10_DRVTUNE210_Pos            _UINT32_(5)                                          /* (USBHS_PHY10) Lower 3 bits for HS/FS/LS driver strength tuning Position */
#define USBHS_PHY10_DRVTUNE210_Msk            (_UINT32_(0x7) << USBHS_PHY10_DRVTUNE210_Pos)        /* (USBHS_PHY10) Lower 3 bits for HS/FS/LS driver strength tuning Mask */
#define USBHS_PHY10_DRVTUNE210(value)         (USBHS_PHY10_DRVTUNE210_Msk & (_UINT32_(value) << USBHS_PHY10_DRVTUNE210_Pos)) /* Assigment of value for DRVTUNE210 in the USBHS_PHY10 register */
#define USBHS_PHY10_Msk                       _UINT32_(0x000000FF)                                 /* (USBHS_PHY10) Register Mask  */


/* -------- USBHS_PHY14 : (USBHS Offset: 0x1514) (R/W 32) USBHPHY Control Register. -------- */
#define USBHS_PHY14_RESETVALUE                _UINT32_(0x12)                                       /*  (USBHS_PHY14) USBHPHY Control Register.  Reset Value */

#define USBHS_PHY14_DRVTUNE43_Pos             _UINT32_(0)                                          /* (USBHS_PHY14) Upper 2 bits for HS/FS/LS driver strength tuning Position */
#define USBHS_PHY14_DRVTUNE43_Msk             (_UINT32_(0x3) << USBHS_PHY14_DRVTUNE43_Pos)         /* (USBHS_PHY14) Upper 2 bits for HS/FS/LS driver strength tuning Mask */
#define USBHS_PHY14_DRVTUNE43(value)          (USBHS_PHY14_DRVTUNE43_Msk & (_UINT32_(value) << USBHS_PHY14_DRVTUNE43_Pos)) /* Assigment of value for DRVTUNE43 in the USBHS_PHY14 register */
#define USBHS_PHY14_COMPBYPSS_Pos             _UINT32_(2)                                          /* (USBHS_PHY14) Auto compensation bypass Position */
#define USBHS_PHY14_COMPBYPSS_Msk             (_UINT32_(0x3) << USBHS_PHY14_COMPBYPSS_Pos)         /* (USBHS_PHY14) Auto compensation bypass Mask */
#define USBHS_PHY14_COMPBYPSS(value)          (USBHS_PHY14_COMPBYPSS_Msk & (_UINT32_(value) << USBHS_PHY14_COMPBYPSS_Pos)) /* Assigment of value for COMPBYPSS in the USBHS_PHY14 register */
#define USBHS_PHY14_BYPSSSQUELCH_Pos          _UINT32_(4)                                          /* (USBHS_PHY14) Bypass squelch trigger point configure in chirp mode Position */
#define USBHS_PHY14_BYPSSSQUELCH_Msk          (_UINT32_(0x1) << USBHS_PHY14_BYPSSSQUELCH_Pos)      /* (USBHS_PHY14) Bypass squelch trigger point configure in chirp mode Mask */
#define USBHS_PHY14_BYPSSSQUELCH(value)       (USBHS_PHY14_BYPSSSQUELCH_Msk & (_UINT32_(value) << USBHS_PHY14_BYPSSSQUELCH_Pos)) /* Assigment of value for BYPSSSQUELCH in the USBHS_PHY14 register */
#define USBHS_PHY14_ODT0_Pos                  _UINT32_(7)                                          /* (USBHS_PHY14) On die termination compensation voltage reference Position */
#define USBHS_PHY14_ODT0_Msk                  (_UINT32_(0x1) << USBHS_PHY14_ODT0_Pos)              /* (USBHS_PHY14) On die termination compensation voltage reference Mask */
#define USBHS_PHY14_ODT0(value)               (USBHS_PHY14_ODT0_Msk & (_UINT32_(value) << USBHS_PHY14_ODT0_Pos)) /* Assigment of value for ODT0 in the USBHS_PHY14 register */
#define USBHS_PHY14_Msk                       _UINT32_(0x0000009F)                                 /* (USBHS_PHY14) Register Mask  */

#define USBHS_PHY14_ODT_Pos                   _UINT32_(7)                                          /* (USBHS_PHY14 Position) On die termination compensation voltage reference */
#define USBHS_PHY14_ODT_Msk                   (_UINT32_(0x1) << USBHS_PHY14_ODT_Pos)               /* (USBHS_PHY14 Mask) ODT */
#define USBHS_PHY14_ODT(value)                (USBHS_PHY14_ODT_Msk & (_UINT32_(value) << USBHS_PHY14_ODT_Pos)) 

/* -------- USBHS_PHY18 : (USBHS Offset: 0x1518) (R/W 32) USBHPHY Control Register. -------- */
#define USBHS_PHY18_RESETVALUE                _UINT32_(0x08)                                       /*  (USBHS_PHY18) USBHPHY Control Register.  Reset Value */

#define USBHS_PHY18_ODT21_Pos                 _UINT32_(0)                                          /* (USBHS_PHY18) Upper 3 bits for on die termination compensation voltage reference Position */
#define USBHS_PHY18_ODT21_Msk                 (_UINT32_(0x3) << USBHS_PHY18_ODT21_Pos)             /* (USBHS_PHY18) Upper 3 bits for on die termination compensation voltage reference Mask */
#define USBHS_PHY18_ODT21(value)              (USBHS_PHY18_ODT21_Msk & (_UINT32_(value) << USBHS_PHY18_ODT21_Pos)) /* Assigment of value for ODT21 in the USBHS_PHY18 register */
#define USBHS_PHY18_RSVD_Pos                  _UINT32_(2)                                          /* (USBHS_PHY18) reserved Position */
#define USBHS_PHY18_RSVD_Msk                  (_UINT32_(0xF) << USBHS_PHY18_RSVD_Pos)              /* (USBHS_PHY18) reserved Mask */
#define USBHS_PHY18_RSVD(value)               (USBHS_PHY18_RSVD_Msk & (_UINT32_(value) << USBHS_PHY18_RSVD_Pos)) /* Assigment of value for RSVD in the USBHS_PHY18 register */
#define USBHS_PHY18_Msk                       _UINT32_(0x0000003F)                                 /* (USBHS_PHY18) Register Mask  */


/* -------- USBHS_PHY1C : (USBHS Offset: 0x151C) (R/W 32) USBHPHY Control Register. -------- */
#define USBHS_PHY1C_RESETVALUE                _UINT32_(0x82)                                       /*  (USBHS_PHY1C) USBHPHY Control Register.  Reset Value */

#define USBHS_PHY1C_ODTBYPASS_Pos             _UINT32_(1)                                          /* (USBHS_PHY1C) ODT auto-refresh bypass Position */
#define USBHS_PHY1C_ODTBYPASS_Msk             (_UINT32_(0x1) << USBHS_PHY1C_ODTBYPASS_Pos)         /* (USBHS_PHY1C) ODT auto-refresh bypass Mask */
#define USBHS_PHY1C_ODTBYPASS(value)          (USBHS_PHY1C_ODTBYPASS_Msk & (_UINT32_(value) << USBHS_PHY1C_ODTBYPASS_Pos)) /* Assigment of value for ODTBYPASS in the USBHS_PHY1C register */
#define USBHS_PHY1C_FSLSDIFF_Pos              _UINT32_(7)                                          /* (USBHS_PHY1C) Turn off FS/LS differential receiver in suspend mode Position */
#define USBHS_PHY1C_FSLSDIFF_Msk              (_UINT32_(0x1) << USBHS_PHY1C_FSLSDIFF_Pos)          /* (USBHS_PHY1C) Turn off FS/LS differential receiver in suspend mode Mask */
#define USBHS_PHY1C_FSLSDIFF(value)           (USBHS_PHY1C_FSLSDIFF_Msk & (_UINT32_(value) << USBHS_PHY1C_FSLSDIFF_Pos)) /* Assigment of value for FSLSDIFF in the USBHS_PHY1C register */
#define USBHS_PHY1C_Msk                       _UINT32_(0x00000082)                                 /* (USBHS_PHY1C) Register Mask  */


/* -------- USBHS_PHY20 : (USBHS Offset: 0x1520) (R/W 32) USBHPHY Control Register. -------- */
#define USBHS_PHY20_RESETVALUE                _UINT32_(0x80)                                       /*  (USBHS_PHY20) USBHPHY Control Register.  Reset Value */

#define USBHS_PHY20_RSVD_Pos                  _UINT32_(0)                                          /* (USBHS_PHY20) Reserved Position */
#define USBHS_PHY20_RSVD_Msk                  (_UINT32_(0xF) << USBHS_PHY20_RSVD_Pos)              /* (USBHS_PHY20) Reserved Mask */
#define USBHS_PHY20_RSVD(value)               (USBHS_PHY20_RSVD_Msk & (_UINT32_(value) << USBHS_PHY20_RSVD_Pos)) /* Assigment of value for RSVD in the USBHS_PHY20 register */
#define USBHS_PHY20_HSSLEW10_Pos              _UINT32_(6)                                          /* (USBHS_PHY20) Lower 2 bits for HS slew adjust rate Position */
#define USBHS_PHY20_HSSLEW10_Msk              (_UINT32_(0x3) << USBHS_PHY20_HSSLEW10_Pos)          /* (USBHS_PHY20) Lower 2 bits for HS slew adjust rate Mask */
#define USBHS_PHY20_HSSLEW10(value)           (USBHS_PHY20_HSSLEW10_Msk & (_UINT32_(value) << USBHS_PHY20_HSSLEW10_Pos)) /* Assigment of value for HSSLEW10 in the USBHS_PHY20 register */
#define USBHS_PHY20_Msk                       _UINT32_(0x000000CF)                                 /* (USBHS_PHY20) Register Mask  */


/* -------- USBHS_PHY24 : (USBHS Offset: 0x1524) (R/W 32) USBHPHY Control Register. -------- */
#define USBHS_PHY24_RESETVALUE                _UINT32_(0x0C)                                       /*  (USBHS_PHY24) USBHPHY Control Register.  Reset Value */

#define USBHS_PHY24_HSSLEW2_Pos               _UINT32_(0)                                          /* (USBHS_PHY24) MSB of HS slew rate adjust Position */
#define USBHS_PHY24_HSSLEW2_Msk               (_UINT32_(0x1) << USBHS_PHY24_HSSLEW2_Pos)           /* (USBHS_PHY24) MSB of HS slew rate adjust Mask */
#define USBHS_PHY24_HSSLEW2(value)            (USBHS_PHY24_HSSLEW2_Msk & (_UINT32_(value) << USBHS_PHY24_HSSLEW2_Pos)) /* Assigment of value for HSSLEW2 in the USBHS_PHY24 register */
#define USBHS_PHY24_RSVD_Pos                  _UINT32_(2)                                          /* (USBHS_PHY24) Reserved Position */
#define USBHS_PHY24_RSVD_Msk                  (_UINT32_(0x1) << USBHS_PHY24_RSVD_Pos)              /* (USBHS_PHY24) Reserved Mask */
#define USBHS_PHY24_RSVD(value)               (USBHS_PHY24_RSVD_Msk & (_UINT32_(value) << USBHS_PHY24_RSVD_Pos)) /* Assigment of value for RSVD in the USBHS_PHY24 register */
#define USBHS_PHY24_HSPREEMPST_Pos            _UINT32_(3)                                          /* (USBHS_PHY24) HS transmit pre emphasis strength Position */
#define USBHS_PHY24_HSPREEMPST_Msk            (_UINT32_(0x7) << USBHS_PHY24_HSPREEMPST_Pos)        /* (USBHS_PHY24) HS transmit pre emphasis strength Mask */
#define USBHS_PHY24_HSPREEMPST(value)         (USBHS_PHY24_HSPREEMPST_Msk & (_UINT32_(value) << USBHS_PHY24_HSPREEMPST_Pos)) /* Assigment of value for HSPREEMPST in the USBHS_PHY24 register */
#define USBHS_PHY24_HSDRIVST10_Pos            _UINT32_(6)                                          /* (USBHS_PHY24) HS transmit drive strength Position */
#define USBHS_PHY24_HSDRIVST10_Msk            (_UINT32_(0x3) << USBHS_PHY24_HSDRIVST10_Pos)        /* (USBHS_PHY24) HS transmit drive strength Mask */
#define USBHS_PHY24_HSDRIVST10(value)         (USBHS_PHY24_HSDRIVST10_Msk & (_UINT32_(value) << USBHS_PHY24_HSDRIVST10_Pos)) /* Assigment of value for HSDRIVST10 in the USBHS_PHY24 register */
#define USBHS_PHY24_Msk                       _UINT32_(0x000000FD)                                 /* (USBHS_PHY24) Register Mask  */

#define USBHS_PHY24_HSSLEW_Pos                _UINT32_(0)                                          /* (USBHS_PHY24 Position) MSB of HS slew rate adjust */
#define USBHS_PHY24_HSSLEW_Msk                (_UINT32_(0x1) << USBHS_PHY24_HSSLEW_Pos)            /* (USBHS_PHY24 Mask) HSSLEW */
#define USBHS_PHY24_HSSLEW(value)             (USBHS_PHY24_HSSLEW_Msk & (_UINT32_(value) << USBHS_PHY24_HSSLEW_Pos)) 

/* -------- USBHS_PHY28 : (USBHS Offset: 0x1528) (R/W 32) USBHPHY Control Register. -------- */
#define USBHS_PHY28_RESETVALUE                _UINT32_(0x1B)                                       /*  (USBHS_PHY28) USBHPHY Control Register.  Reset Value */

#define USBHS_PHY28_HSDRIVST2_Pos             _UINT32_(0)                                          /* (USBHS_PHY28) MSB of HS transmit driver strength Position */
#define USBHS_PHY28_HSDRIVST2_Msk             (_UINT32_(0x1) << USBHS_PHY28_HSDRIVST2_Pos)         /* (USBHS_PHY28) MSB of HS transmit driver strength Mask */
#define USBHS_PHY28_HSDRIVST2(value)          (USBHS_PHY28_HSDRIVST2_Msk & (_UINT32_(value) << USBHS_PHY28_HSDRIVST2_Pos)) /* Assigment of value for HSDRIVST2 in the USBHS_PHY28 register */
#define USBHS_PHY28_DISCONDET_Pos             _UINT32_(1)                                          /* (USBHS_PHY28) HOST disconnects detection trigger point Position */
#define USBHS_PHY28_DISCONDET_Msk             (_UINT32_(0xF) << USBHS_PHY28_DISCONDET_Pos)         /* (USBHS_PHY28) HOST disconnects detection trigger point Mask */
#define USBHS_PHY28_DISCONDET(value)          (USBHS_PHY28_DISCONDET_Msk & (_UINT32_(value) << USBHS_PHY28_DISCONDET_Pos)) /* Assigment of value for DISCONDET in the USBHS_PHY28 register */
#define USBHS_PHY28_HSDRVCOMP_Pos             _UINT32_(5)                                          /* (USBHS_PHY28) HS drive current compensation voltage reference Position */
#define USBHS_PHY28_HSDRVCOMP_Msk             (_UINT32_(0x7) << USBHS_PHY28_HSDRVCOMP_Pos)         /* (USBHS_PHY28) HS drive current compensation voltage reference Mask */
#define USBHS_PHY28_HSDRVCOMP(value)          (USBHS_PHY28_HSDRVCOMP_Msk & (_UINT32_(value) << USBHS_PHY28_HSDRVCOMP_Pos)) /* Assigment of value for HSDRVCOMP in the USBHS_PHY28 register */
#define USBHS_PHY28_Msk                       _UINT32_(0x000000FF)                                 /* (USBHS_PHY28) Register Mask  */

#define USBHS_PHY28_HSDRIVST_Pos              _UINT32_(0)                                          /* (USBHS_PHY28 Position) MSB of HS transmit driver strength */
#define USBHS_PHY28_HSDRIVST_Msk              (_UINT32_(0x1) << USBHS_PHY28_HSDRIVST_Pos)          /* (USBHS_PHY28 Mask) HSDRIVST */
#define USBHS_PHY28_HSDRIVST(value)           (USBHS_PHY28_HSDRIVST_Msk & (_UINT32_(value) << USBHS_PHY28_HSDRIVST_Pos)) 

/* -------- USBHS_PHY44 : (USBHS Offset: 0x1544) (R/W 32) USBHPHY Control Register. -------- */
#define USBHS_PHY44_RESETVALUE                _UINT32_(0x40)                                       /*  (USBHS_PHY44) USBHPHY Control Register.  Reset Value */

#define USBHS_PHY44_PLLDAMP_Pos               _UINT32_(1)                                          /* (USBHS_PHY44) PLL damping factor Position */
#define USBHS_PHY44_PLLDAMP_Msk               (_UINT32_(0x1) << USBHS_PHY44_PLLDAMP_Pos)           /* (USBHS_PHY44) PLL damping factor Mask */
#define USBHS_PHY44_PLLDAMP(value)            (USBHS_PHY44_PLLDAMP_Msk & (_UINT32_(value) << USBHS_PHY44_PLLDAMP_Pos)) /* Assigment of value for PLLDAMP in the USBHS_PHY44 register */
#define USBHS_PHY44_DIGDBG_Pos                _UINT32_(2)                                          /* (USBHS_PHY44) Digital debug interface Position */
#define USBHS_PHY44_DIGDBG_Msk                (_UINT32_(0x1) << USBHS_PHY44_DIGDBG_Pos)            /* (USBHS_PHY44) Digital debug interface Mask */
#define USBHS_PHY44_DIGDBG(value)             (USBHS_PHY44_DIGDBG_Msk & (_UINT32_(value) << USBHS_PHY44_DIGDBG_Pos)) /* Assigment of value for DIGDBG in the USBHS_PHY44 register */
#define USBHS_PHY44_FRCVBUSVAL_Pos            _UINT32_(3)                                          /* (USBHS_PHY44) Force output vbus_valid Position */
#define USBHS_PHY44_FRCVBUSVAL_Msk            (_UINT32_(0x1) << USBHS_PHY44_FRCVBUSVAL_Pos)        /* (USBHS_PHY44) Force output vbus_valid Mask */
#define USBHS_PHY44_FRCVBUSVAL(value)         (USBHS_PHY44_FRCVBUSVAL_Msk & (_UINT32_(value) << USBHS_PHY44_FRCVBUSVAL_Pos)) /* Assigment of value for FRCVBUSVAL in the USBHS_PHY44 register */
#define USBHS_PHY44_RSVD_Pos                  _UINT32_(4)                                          /* (USBHS_PHY44) reserved Position */
#define USBHS_PHY44_RSVD_Msk                  (_UINT32_(0x7) << USBHS_PHY44_RSVD_Pos)              /* (USBHS_PHY44) reserved Mask */
#define USBHS_PHY44_RSVD(value)               (USBHS_PHY44_RSVD_Msk & (_UINT32_(value) << USBHS_PHY44_RSVD_Pos)) /* Assigment of value for RSVD in the USBHS_PHY44 register */
#define USBHS_PHY44_FRCSESSEND_Pos            _UINT32_(7)                                          /* (USBHS_PHY44) force session end Position */
#define USBHS_PHY44_FRCSESSEND_Msk            (_UINT32_(0x1) << USBHS_PHY44_FRCSESSEND_Pos)        /* (USBHS_PHY44) force session end Mask */
#define USBHS_PHY44_FRCSESSEND(value)         (USBHS_PHY44_FRCSESSEND_Msk & (_UINT32_(value) << USBHS_PHY44_FRCSESSEND_Pos)) /* Assigment of value for FRCSESSEND in the USBHS_PHY44 register */
#define USBHS_PHY44_Msk                       _UINT32_(0x000000FE)                                 /* (USBHS_PHY44) Register Mask  */


/* -------- USBHS_PHY48 : (USBHS Offset: 0x1548) (R/W 32) USBHPHY Control Register. -------- */
#define USBHS_PHY48_RESETVALUE                _UINT32_(0x04)                                       /*  (USBHS_PHY48) USBHPHY Control Register.  Reset Value */

#define USBHS_PHY48_FRCASESSVAL_Pos           _UINT32_(0)                                          /* (USBHS_PHY48) force A_sessionvalid Position */
#define USBHS_PHY48_FRCASESSVAL_Msk           (_UINT32_(0x1) << USBHS_PHY48_FRCASESSVAL_Pos)       /* (USBHS_PHY48) force A_sessionvalid Mask */
#define USBHS_PHY48_FRCASESSVAL(value)        (USBHS_PHY48_FRCASESSVAL_Msk & (_UINT32_(value) << USBHS_PHY48_FRCASESSVAL_Pos)) /* Assigment of value for FRCASESSVAL in the USBHS_PHY48 register */
#define USBHS_PHY48_FRCBSESSVAL_Pos           _UINT32_(1)                                          /* (USBHS_PHY48) force B_sessionvalid Position */
#define USBHS_PHY48_FRCBSESSVAL_Msk           (_UINT32_(0x1) << USBHS_PHY48_FRCBSESSVAL_Pos)       /* (USBHS_PHY48) force B_sessionvalid Mask */
#define USBHS_PHY48_FRCBSESSVAL(value)        (USBHS_PHY48_FRCBSESSVAL_Msk & (_UINT32_(value) << USBHS_PHY48_FRCBSESSVAL_Pos)) /* Assigment of value for FRCBSESSVAL in the USBHS_PHY48 register */
#define USBHS_PHY48_VBUSCHRGE_Pos             _UINT32_(2)                                          /* (USBHS_PHY48) VBus charging/discharging bypass Position */
#define USBHS_PHY48_VBUSCHRGE_Msk             (_UINT32_(0x1) << USBHS_PHY48_VBUSCHRGE_Pos)         /* (USBHS_PHY48) VBus charging/discharging bypass Mask */
#define USBHS_PHY48_VBUSCHRGE(value)          (USBHS_PHY48_VBUSCHRGE_Msk & (_UINT32_(value) << USBHS_PHY48_VBUSCHRGE_Pos)) /* Assigment of value for VBUSCHRGE in the USBHS_PHY48 register */
#define USBHS_PHY48_SESSENDTUNE_Pos           _UINT32_(5)                                          /* (USBHS_PHY48) Session end reference tuning Position */
#define USBHS_PHY48_SESSENDTUNE_Msk           (_UINT32_(0x7) << USBHS_PHY48_SESSENDTUNE_Pos)       /* (USBHS_PHY48) Session end reference tuning Mask */
#define USBHS_PHY48_SESSENDTUNE(value)        (USBHS_PHY48_SESSENDTUNE_Msk & (_UINT32_(value) << USBHS_PHY48_SESSENDTUNE_Pos)) /* Assigment of value for SESSENDTUNE in the USBHS_PHY48 register */
#define USBHS_PHY48_Msk                       _UINT32_(0x000000E7)                                 /* (USBHS_PHY48) Register Mask  */


/* -------- USBHS_PHY4C : (USBHS Offset: 0x154C) (R/W 32) USBHPHY Control Register. -------- */
#define USBHS_PHY4C_RESETVALUE                _UINT32_(0x00)                                       /*  (USBHS_PHY4C) USBHPHY Control Register.  Reset Value */

#define USBHS_PHY4C_VBUSVALTUNE_Pos           _UINT32_(0)                                          /* (USBHS_PHY4C) VBus_valid reference tuning Position */
#define USBHS_PHY4C_VBUSVALTUNE_Msk           (_UINT32_(0x7) << USBHS_PHY4C_VBUSVALTUNE_Pos)       /* (USBHS_PHY4C) VBus_valid reference tuning Mask */
#define USBHS_PHY4C_VBUSVALTUNE(value)        (USBHS_PHY4C_VBUSVALTUNE_Msk & (_UINT32_(value) << USBHS_PHY4C_VBUSVALTUNE_Pos)) /* Assigment of value for VBUSVALTUNE in the USBHS_PHY4C register */
#define USBHS_PHY4C_BSESSVALIDTUNE10_Pos      _UINT32_(6)                                          /* (USBHS_PHY4C) Lower 2 B_sessionvalid reference tune Position */
#define USBHS_PHY4C_BSESSVALIDTUNE10_Msk      (_UINT32_(0x3) << USBHS_PHY4C_BSESSVALIDTUNE10_Pos)  /* (USBHS_PHY4C) Lower 2 B_sessionvalid reference tune Mask */
#define USBHS_PHY4C_BSESSVALIDTUNE10(value)   (USBHS_PHY4C_BSESSVALIDTUNE10_Msk & (_UINT32_(value) << USBHS_PHY4C_BSESSVALIDTUNE10_Pos)) /* Assigment of value for BSESSVALIDTUNE10 in the USBHS_PHY4C register */
#define USBHS_PHY4C_Msk                       _UINT32_(0x000000C7)                                 /* (USBHS_PHY4C) Register Mask  */


/* -------- USBHS_PHY50 : (USBHS Offset: 0x1550) (R/W 32) USBHPHY Control Register. -------- */
#define USBHS_PHY50_RESETVALUE                _UINT32_(0x00)                                       /*  (USBHS_PHY50) USBHPHY Control Register.  Reset Value */

#define USBHS_PHY50_BSESSVALIDTUNE2_Pos       _UINT32_(0)                                          /* (USBHS_PHY50) MSB of B_sessionvalid reference tune Position */
#define USBHS_PHY50_BSESSVALIDTUNE2_Msk       (_UINT32_(0x1) << USBHS_PHY50_BSESSVALIDTUNE2_Pos)   /* (USBHS_PHY50) MSB of B_sessionvalid reference tune Mask */
#define USBHS_PHY50_BSESSVALIDTUNE2(value)    (USBHS_PHY50_BSESSVALIDTUNE2_Msk & (_UINT32_(value) << USBHS_PHY50_BSESSVALIDTUNE2_Pos)) /* Assigment of value for BSESSVALIDTUNE2 in the USBHS_PHY50 register */
#define USBHS_PHY50_ASESSVALIDTUNE_Pos        _UINT32_(1)                                          /* (USBHS_PHY50) A_sessionvalid reference tune Position */
#define USBHS_PHY50_ASESSVALIDTUNE_Msk        (_UINT32_(0x7) << USBHS_PHY50_ASESSVALIDTUNE_Pos)    /* (USBHS_PHY50) A_sessionvalid reference tune Mask */
#define USBHS_PHY50_ASESSVALIDTUNE(value)     (USBHS_PHY50_ASESSVALIDTUNE_Msk & (_UINT32_(value) << USBHS_PHY50_ASESSVALIDTUNE_Pos)) /* Assigment of value for ASESSVALIDTUNE in the USBHS_PHY50 register */
#define USBHS_PHY50_COMPCURREF_Pos            _UINT32_(5)                                          /* (USBHS_PHY50) Compensation current tuning reference Position */
#define USBHS_PHY50_COMPCURREF_Msk            (_UINT32_(0x7) << USBHS_PHY50_COMPCURREF_Pos)        /* (USBHS_PHY50) Compensation current tuning reference Mask */
#define USBHS_PHY50_COMPCURREF(value)         (USBHS_PHY50_COMPCURREF_Msk & (_UINT32_(value) << USBHS_PHY50_COMPCURREF_Pos)) /* Assigment of value for COMPCURREF in the USBHS_PHY50 register */
#define USBHS_PHY50_Msk                       _UINT32_(0x000000EF)                                 /* (USBHS_PHY50) Register Mask  */

#define USBHS_PHY50_BSESSVALIDTUNE_Pos        _UINT32_(0)                                          /* (USBHS_PHY50 Position) MSB of B_sessionvalid reference tune */
#define USBHS_PHY50_BSESSVALIDTUNE_Msk        (_UINT32_(0x1) << USBHS_PHY50_BSESSVALIDTUNE_Pos)    /* (USBHS_PHY50 Mask) BSESSVALIDTUNE */
#define USBHS_PHY50_BSESSVALIDTUNE(value)     (USBHS_PHY50_BSESSVALIDTUNE_Msk & (_UINT32_(value) << USBHS_PHY50_BSESSVALIDTUNE_Pos)) 

/** \brief USBHS register offsets definitions */
#define USBHS_DMACNTL_REG_OFST         _UINT32_(0x00)      /* (USBHS_DMACNTL) DMA Transfer Control For Each Channel Offset */
#define USBHS_DMAADDR_REG_OFST         _UINT32_(0x04)      /* (USBHS_DMAADDR) Memory Address Of The Corresponding DMA Channel Offset */
#define USBHS_DMACOUNT_REG_OFST        _UINT32_(0x08)      /* (USBHS_DMACOUNT) Current DMA Count Of The Transfer Offset */
#define USBHS_TXFUNCADDREP_REG_OFST    _UINT32_(0x00)      /* (USBHS_TXFUNCADDREP) Relevant In Host Mode Only. Address Of The Target Function. Offset */
#define USBHS_TXHUBADDREP_REG_OFST     _UINT32_(0x02)      /* (USBHS_TXHUBADDREP) Relevant In Host Mode Only. HUB Address Offset */
#define USBHS_TXHUBPORT_REG_OFST       _UINT32_(0x03)      /* (USBHS_TXHUBPORT) Relevant In Host Mode Only. HUB Address Offset */
#define USBHS_RXFUNCADDREP_REG_OFST    _UINT32_(0x04)      /* (USBHS_RXFUNCADDREP) Relevant In Host Mode Only. Address Of The Target Function. Offset */
#define USBHS_RXHUBADDREP_REG_OFST     _UINT32_(0x06)      /* (USBHS_RXHUBADDREP) Relevant In Host Mode Only. HUB Address Offset */
#define USBHS_RXHUBPORT_REG_OFST       _UINT32_(0x07)      /* (USBHS_RXHUBPORT) Relevant In Host Mode Only. HUB Address Offset */
#define USBHS_CTRLA_REG_OFST           _UINT32_(0x00)      /* (USBHS_CTRLA) USBHS Control Register A. (All bits except ENABLE and SWRST are Enable protected) Offset */
#define USBHS_CTRLB_REG_OFST           _UINT32_(0x04)      /* (USBHS_CTRLB) USBHS Control Register B Offset */
#define USBHS_CTRLC_REG_OFST           _UINT32_(0x08)      /* (USBHS_CTRLC) USBHS Control Register C Offset */
#define USBHS_INTENCLR_REG_OFST        _UINT32_(0x0C)      /* (USBHS_INTENCLR) USBHS Interrupt Enable Clear Register Offset */
#define USBHS_INTENSET_REG_OFST        _UINT32_(0x10)      /* (USBHS_INTENSET) USBHS Interrupt Enable Clear Register Offset */
#define USBHS_INTFLAG_REG_OFST         _UINT32_(0x14)      /* (USBHS_INTFLAG) USBHS Interrupt Flag Register Offset */
#define USBHS_STATUS_REG_OFST          _UINT32_(0x18)      /* (USBHS_STATUS) USBHS Status Register Offset */
#define USBHS_SYNCBUSY_REG_OFST        _UINT32_(0x1C)      /* (USBHS_SYNCBUSY) USBHS Syncbusy Register Offset */
#define USBHS_FADDR_REG_OFST           _UINT32_(0x1000)    /* (USBHS_FADDR) Function Address Register Offset */
#define USBHS_POWER_REG_OFST           _UINT32_(0x1001)    /* (USBHS_POWER) Used For Controlling Suspend And Resume Signaling And Some Basic Operation Of USBCORE Offset */
#define USBHS_INTRTX_REG_OFST          _UINT32_(0x1002)    /* (USBHS_INTRTX) Read Only Register Which Indicates Which Interrupts Are Currently Active For EP0 And TX EP1-15 Offset */
#define USBHS_INTRRX_REG_OFST          _UINT32_(0x1004)    /* (USBHS_INTRRX) Read Only Register Which Indicates Which Interrupts Are Currently Active For RX EP1-15 Offset */
#define USBHS_INTRTXE_REG_OFST         _UINT32_(0x1006)    /* (USBHS_INTRTXE) Interrupt Enable Bits for INTRTX Offset */
#define USBHS_INTRRXE_REG_OFST         _UINT32_(0x1008)    /* (USBHS_INTRRXE) Interrupt Enable Bits for INTRRX Offset */
#define USBHS_INTRUSB_REG_OFST         _UINT32_(0x100A)    /* (USBHS_INTRUSB) Read Only Register Which Indicates Which USB Interrupts Are Currently Active. Offset */
#define USBHS_INTRUSBE_REG_OFST        _UINT32_(0x100B)    /* (USBHS_INTRUSBE) Interrupt Enable Bits for USB Interrupts Offset */
#define USBHS_FRAME_REG_OFST           _UINT32_(0x100C)    /* (USBHS_FRAME) Holds The Last Received Frame Number Offset */
#define USBHS_INDEX_REG_OFST           _UINT32_(0x100E)    /* (USBHS_INDEX) Index Is A 4-Bit Register That Determines Which Endpoint Control/Status Registers Are Accessed Offset */
#define USBHS_TESTMODE_REG_OFST        _UINT32_(0x100F)    /* (USBHS_TESTMODE) Not Used In Normal Operation. Configuration To Put the USBCORE Into One Of The Four Test Modes For HighSpeed Operation Offset */
#define USBHS_ENDPOINTX_TXMAXP_REG_OFST _UINT32_(0x1010)    /* (USBHS_ENDPOINTX_TXMAXP) ENDPOINTX Maximum Amount Of Data That Can Be Transferred Through The Selected TX Endpoint In A Single Operation Offset */
#define USBHS_ENDPOINTX_TXCSRL_REG_OFST _UINT32_(0x1012)    /* (USBHS_ENDPOINTX_TXCSRL) ENDPOINTX Control And Status Bits for TX Endpoints 1-15 Offset */
#define USBHS_ENDPOINT0_CSR0L_REG_OFST _UINT32_(0x1012)    /* (USBHS_ENDPOINT0_CSR0L) ENDPOINT0 Control And Status Bits for TX Endpoint 0 Offset */
#define USBHS_ENDPOINTX_TXCSRH_REG_OFST _UINT32_(0x1013)    /* (USBHS_ENDPOINTX_TXCSRH) ENDPOINTX Additional Control And Status Bits For TX Endpoints 1-15 Offset */
#define USBHS_ENDPOINT0_CSR0H_REG_OFST _UINT32_(0x1013)    /* (USBHS_ENDPOINT0_CSR0H) ENDPOINT0 Additional Control And Status Bits For TX Endpoint 0 Offset */
#define USBHS_ENDPOINTX_RXMAXP_REG_OFST _UINT32_(0x1014)    /* (USBHS_ENDPOINTX_RXMAXP) ENDPOINTX Maximum Amount Of Data That Can Be Transferred Through The Selected RX Endpoint In A Single Operation Offset */
#define USBHS_ENDPOINTX_RXCSRL_REG_OFST _UINT32_(0x1016)    /* (USBHS_ENDPOINTX_RXCSRL) ENDPOINTX Control And Status Bits for RX Endpoint 0 Or Endpoint 1-15 Offset */
#define USBHS_ENDPOINTX_RXCSRH_REG_OFST _UINT32_(0x1017)    /* (USBHS_ENDPOINTX_RXCSRH) ENDPOINTX Additional Control And Status Bits for RX Endpoint 0 Or Endpoint 1-15 Offset */
#define USBHS_ENDPOINTX_RXCOUNT_REG_OFST _UINT32_(0x1018)    /* (USBHS_ENDPOINTX_RXCOUNT) ENDPOINTX Number Of Data Bytes In The Packet Currently In Line To Be Read From The RX FIFO. Offset */
#define USBHS_ENDPOINT0_COUNT0_REG_OFST _UINT32_(0x1018)    /* (USBHS_ENDPOINT0_COUNT0) ENDPOINT0 Number Of Received Bytes In Endpoint 0 FIFO Offset */
#define USBHS_ENDPOINTX_TXTYPE_REG_OFST _UINT32_(0x101A)    /* (USBHS_ENDPOINTX_TXTYPE) ENDPOINTX Host Mode Only: Should Be Written With The Endpoint Number To Be Targeted By The Endpoint Offset */
#define USBHS_ENDPOINT0_TYPE0_REG_OFST _UINT32_(0x101A)    /* (USBHS_ENDPOINT0_TYPE0) ENDPOINT0 Host Mode Only: Operating Speed Of The Targeted Device Offset */
#define USBHS_ENDPOINTX_TXINTERVAL_REG_OFST _UINT32_(0x101B)    /* (USBHS_ENDPOINTX_TXINTERVAL) ENDPOINTX Host Mode Only: Defines The Polling Interval For The Currently Selected TX Endpoint. Offset */
#define USBHS_ENDPOINT0_NAKLIMIT0_REG_OFST _UINT32_(0x101B)    /* (USBHS_ENDPOINT0_NAKLIMIT0) ENDPOINT0 Host Mode Only: Sets The NAK Response Timeout On Endpoint 0. Offset */
#define USBHS_ENDPOINTX_RXTYPE_REG_OFST _UINT32_(0x101C)    /* (USBHS_ENDPOINTX_RXTYPE) ENDPOINTX Host Mode Only: Should Be Written With The Endpoint Number To Be Targeted By The Endpoint Offset */
#define USBHS_ENDPOINTX_RXINTERVAL_REG_OFST _UINT32_(0x101D)    /* (USBHS_ENDPOINTX_RXINTERVAL) ENDPOINTX Host Mode Only: Defines The Polling Interval For The Currently Selected RX Endpoint. Offset */
#define USBHS_ENDPOINTX_FIFOSIZE_REG_OFST _UINT32_(0x101F)    /* (USBHS_ENDPOINTX_FIFOSIZE) ENDPOINTX Read Only Register That Returns The Sizes Of The FIFO's Associated With The Selected Additional TX/RX Endpoints. INDEX Regsiter should be set 1-15 Offset */
#define USBHS_ENDPOINT0_CONFIGDATA_REG_OFST _UINT32_(0x101F)    /* (USBHS_ENDPOINT0_CONFIGDATA) ENDPOINT0 Returns Information About The Selected Core Configuration. Only Applicable when INDEX Regsiter Is 0. That Is Endpoint0 Is Selected. Offset */
#define USBHS_FIFOX_REG_OFST           _UINT32_(0x1020)    /* (USBHS_FIFOX) Address Range Provides 16 Addresses For CPU Access To The FIFO's For Each Endpoint Offset */
#define USBHS_FIFOX0_REG_OFST          _UINT32_(0x1020)    /* (USBHS_FIFOX0) Address Range Provides 16 Addresses For CPU Access To The FIFO's For Each Endpoint Offset */
#define USBHS_FIFOX1_REG_OFST          _UINT32_(0x1024)    /* (USBHS_FIFOX1) Address Range Provides 16 Addresses For CPU Access To The FIFO's For Each Endpoint Offset */
#define USBHS_FIFOX2_REG_OFST          _UINT32_(0x1028)    /* (USBHS_FIFOX2) Address Range Provides 16 Addresses For CPU Access To The FIFO's For Each Endpoint Offset */
#define USBHS_FIFOX3_REG_OFST          _UINT32_(0x102C)    /* (USBHS_FIFOX3) Address Range Provides 16 Addresses For CPU Access To The FIFO's For Each Endpoint Offset */
#define USBHS_FIFOX4_REG_OFST          _UINT32_(0x1030)    /* (USBHS_FIFOX4) Address Range Provides 16 Addresses For CPU Access To The FIFO's For Each Endpoint Offset */
#define USBHS_FIFOX5_REG_OFST          _UINT32_(0x1034)    /* (USBHS_FIFOX5) Address Range Provides 16 Addresses For CPU Access To The FIFO's For Each Endpoint Offset */
#define USBHS_FIFOX6_REG_OFST          _UINT32_(0x1038)    /* (USBHS_FIFOX6) Address Range Provides 16 Addresses For CPU Access To The FIFO's For Each Endpoint Offset */
#define USBHS_FIFOX7_REG_OFST          _UINT32_(0x103C)    /* (USBHS_FIFOX7) Address Range Provides 16 Addresses For CPU Access To The FIFO's For Each Endpoint Offset */
#define USBHS_DEVCTL_REG_OFST          _UINT32_(0x1060)    /* (USBHS_DEVCTL) Selects Whether The Core Is Operating In Peripheral Or Host Mode Offset */
#define USBHS_MISC_REG_OFST            _UINT32_(0x1061)    /* (USBHS_MISC) RX/TX Early DMA Enable Bits Offset */
#define USBHS_TXFIFOSZ_REG_OFST        _UINT32_(0x1062)    /* (USBHS_TXFIFOSZ) Controls The Size Of The Selected TX Endpoint FIFO Offset */
#define USBHS_RXFIFOSZ_REG_OFST        _UINT32_(0x1063)    /* (USBHS_RXFIFOSZ) Controls The Size Of The Selected RX Endpoint FIFO Offset */
#define USBHS_TXFIFOADD_REG_OFST       _UINT32_(0x1064)    /* (USBHS_TXFIFOADD) Controls The Start Address Of the Selected TX Endpoint FIFO Offset */
#define USBHS_RXFIFOADD_REG_OFST       _UINT32_(0x1066)    /* (USBHS_RXFIFOADD) Controls The Start Address Of the Selected RX Endpoint FIFO Offset */
#define USBHS_EPINFO_REG_OFST          _UINT32_(0x1078)    /* (USBHS_EPINFO) Allows Read-Back Of The Number Of TX And RX Endpoints Offset */
#define USBHS_RAMINFO_REG_OFST         _UINT32_(0x1079)    /* (USBHS_RAMINFO) Details About Width Of RAM and DMA Channels Offset */
#define USBHS_LINKINFO_REG_OFST        _UINT32_(0x107A)    /* (USBHS_LINKINFO) Allows Some Delays To Be Specified Offset */
#define USBHS_VPLEN_REG_OFST           _UINT32_(0x107B)    /* (USBHS_VPLEN) Sets The Duration Of The VBus Pulsing Charge Offset */
#define USBHS_HSEOF1_REG_OFST          _UINT32_(0x107C)    /* (USBHS_HSEOF1) Sets The Minimum Time Gap That Is To Be Allowed Between The Start Of The Last Transaction And The EOF For HS Transactions Offset */
#define USBHS_FSEOF1_REG_OFST          _UINT32_(0x107D)    /* (USBHS_FSEOF1) Sets The Minimum Time Gap That Is To Be Allowed Between The Start Of The Last Transaction And The EOF For FS Transactions Offset */
#define USBHS_LSEOF1_REG_OFST          _UINT32_(0x107E)    /* (USBHS_LSEOF1) Sets The Minimum Time Gap That Is To Be Allowed Between The Start Of The Last Transaction And The EOF For LS Transactions Offset */
#define USBHS_SOFTRST_REG_OFST         _UINT32_(0x107F)    /* (USBHS_SOFTRST) Assert Low The Output Reset Signals NRSTO and NRSTXO Offset */
#define USBHS_DMAINTR_REG_OFST         _UINT32_(0x1200)    /* (USBHS_DMAINTR) DMA Interrupt Status for Each Channel Offset */
#define USBHS_RQPKTCOUNT_REG_OFST      _UINT32_(0x1304)    /* (USBHS_RQPKTCOUNT) Host Mode Only: Used To Specify Number Of Packets That Are To Be Transaferred In A Block Transfer Offset */
#define USBHS_RQPKTCOUNT0_REG_OFST     _UINT32_(0x1304)    /* (USBHS_RQPKTCOUNT0) Host Mode Only: Used To Specify Number Of Packets That Are To Be Transaferred In A Block Transfer Offset */
#define USBHS_RQPKTCOUNT1_REG_OFST     _UINT32_(0x1308)    /* (USBHS_RQPKTCOUNT1) Host Mode Only: Used To Specify Number Of Packets That Are To Be Transaferred In A Block Transfer Offset */
#define USBHS_RQPKTCOUNT2_REG_OFST     _UINT32_(0x130C)    /* (USBHS_RQPKTCOUNT2) Host Mode Only: Used To Specify Number Of Packets That Are To Be Transaferred In A Block Transfer Offset */
#define USBHS_RQPKTCOUNT3_REG_OFST     _UINT32_(0x1310)    /* (USBHS_RQPKTCOUNT3) Host Mode Only: Used To Specify Number Of Packets That Are To Be Transaferred In A Block Transfer Offset */
#define USBHS_RQPKTCOUNT4_REG_OFST     _UINT32_(0x1314)    /* (USBHS_RQPKTCOUNT4) Host Mode Only: Used To Specify Number Of Packets That Are To Be Transaferred In A Block Transfer Offset */
#define USBHS_RQPKTCOUNT5_REG_OFST     _UINT32_(0x1318)    /* (USBHS_RQPKTCOUNT5) Host Mode Only: Used To Specify Number Of Packets That Are To Be Transaferred In A Block Transfer Offset */
#define USBHS_RQPKTCOUNT6_REG_OFST     _UINT32_(0x131C)    /* (USBHS_RQPKTCOUNT6) Host Mode Only: Used To Specify Number Of Packets That Are To Be Transaferred In A Block Transfer Offset */
#define USBHS_RXDPKTBUFDIS_REG_OFST    _UINT32_(0x1340)    /* (USBHS_RXDPKTBUFDIS) Indicates Which Of The RX Endpoints Have Disabled Double Packet Buffer Functionality Offset */
#define USBHS_TXDPKTBUFDIS_REG_OFST    _UINT32_(0x1342)    /* (USBHS_TXDPKTBUFDIS) Indicates Which Of The TX Endpoints Have Disabled Double Packet Buffer Functionality Offset */
#define USBHS_CTUCH_REG_OFST           _UINT32_(0x1344)    /* (USBHS_CTUCH) Chirp Timeout. Number Of XCLK Cycles Before The Timeout Offset */
#define USBHS_CTHHSRTN_REG_OFST        _UINT32_(0x1346)    /* (USBHS_CTHHSRTN) Sets The Delay From The End Of High-Speed Resume Signaling (Acting As A Host) To Enable The UTM Normal Operating Mode Offset */
#define USBHS_CTHSBT_REG_OFST          _UINT32_(0x1348)    /* (USBHS_CTHSBT) This Register Represents The Value To Be Added To The Minimum High Speed Timeout Period Of 736 Bit Times. Offset */
#define USBHS_LPMATTR_REG_OFST         _UINT32_(0x1360)    /* (USBHS_LPMATTR) Defines The Attributes Of An LPM Transaction And Sleep Cycle. Offset */
#define USBHS_LPMCNTRL_REG_OFST        _UINT32_(0x1362)    /* (USBHS_LPMCNTRL) LPM Control Register Offset */
#define USBHS_LPMINTREN_REG_OFST       _UINT32_(0x1363)    /* (USBHS_LPMINTREN) LPM Interrupts Enable Register Offset */
#define USBHS_LPMINTR_REG_OFST         _UINT32_(0x1364)    /* (USBHS_LPMINTR) Status Of The LPM Power State Offset */
#define USBHS_LPMFADDR_REG_OFST        _UINT32_(0x1365)    /* (USBHS_LPMFADDR) Function Address In LPM Payload Offset */
#define USBHS_PHY00_REG_OFST           _UINT32_(0x1500)    /* (USBHS_PHY00) USBHPHY Control Register. Offset */
#define USBHS_PHY04_REG_OFST           _UINT32_(0x1504)    /* (USBHS_PHY04) USBHPHY Control Register. Offset */
#define USBHS_PHY08_REG_OFST           _UINT32_(0x1508)    /* (USBHS_PHY08) USBHPHY Control Register. Offset */
#define USBHS_PHY0C_REG_OFST           _UINT32_(0x150C)    /* (USBHS_PHY0C) USBHPHY Control Register. Offset */
#define USBHS_PHY10_REG_OFST           _UINT32_(0x1510)    /* (USBHS_PHY10) USBHPHY Control Register. Offset */
#define USBHS_PHY14_REG_OFST           _UINT32_(0x1514)    /* (USBHS_PHY14) USBHPHY Control Register. Offset */
#define USBHS_PHY18_REG_OFST           _UINT32_(0x1518)    /* (USBHS_PHY18) USBHPHY Control Register. Offset */
#define USBHS_PHY1C_REG_OFST           _UINT32_(0x151C)    /* (USBHS_PHY1C) USBHPHY Control Register. Offset */
#define USBHS_PHY20_REG_OFST           _UINT32_(0x1520)    /* (USBHS_PHY20) USBHPHY Control Register. Offset */
#define USBHS_PHY24_REG_OFST           _UINT32_(0x1524)    /* (USBHS_PHY24) USBHPHY Control Register. Offset */
#define USBHS_PHY28_REG_OFST           _UINT32_(0x1528)    /* (USBHS_PHY28) USBHPHY Control Register. Offset */
#define USBHS_PHY44_REG_OFST           _UINT32_(0x1544)    /* (USBHS_PHY44) USBHPHY Control Register. Offset */
#define USBHS_PHY48_REG_OFST           _UINT32_(0x1548)    /* (USBHS_PHY48) USBHPHY Control Register. Offset */
#define USBHS_PHY4C_REG_OFST           _UINT32_(0x154C)    /* (USBHS_PHY4C) USBHPHY Control Register. Offset */
#define USBHS_PHY50_REG_OFST           _UINT32_(0x1550)    /* (USBHS_PHY50) USBHPHY Control Register. Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief DMACNT register API structure */
typedef struct
{
  __IO  uint32_t                       USBHS_DMACNTL;      /**< Offset: 0x00 (R/W  32) DMA Transfer Control For Each Channel */
  __IO  uint32_t                       USBHS_DMAADDR;      /**< Offset: 0x04 (R/W  32) Memory Address Of The Corresponding DMA Channel */
  __IO  uint32_t                       USBHS_DMACOUNT;     /**< Offset: 0x08 (R/W  32) Current DMA Count Of The Transfer */
  __I   uint8_t                        Reserved1[0x04];
} usbhs_dmacnt_registers_t;

/** \brief TXFUNADDR register API structure */
typedef struct
{
  __IO  uint8_t                        USBHS_TXFUNCADDREP; /**< Offset: 0x00 (R/W  8) Relevant In Host Mode Only. Address Of The Target Function. */
  __I   uint8_t                        Reserved1[0x01];
  __IO  uint8_t                        USBHS_TXHUBADDREP;  /**< Offset: 0x02 (R/W  8) Relevant In Host Mode Only. HUB Address */
  __IO  uint8_t                        USBHS_TXHUBPORT;    /**< Offset: 0x03 (R/W  8) Relevant In Host Mode Only. HUB Address */
  __IO  uint8_t                        USBHS_RXFUNCADDREP; /**< Offset: 0x04 (R/W  8) Relevant In Host Mode Only. Address Of The Target Function. */
  __I   uint8_t                        Reserved2[0x01];
  __IO  uint8_t                        USBHS_RXHUBADDREP;  /**< Offset: 0x06 (R/W  8) Relevant In Host Mode Only. HUB Address */
  __IO  uint8_t                        USBHS_RXHUBPORT;    /**< Offset: 0x07 (R/W  8) Relevant In Host Mode Only. HUB Address */
} usbhs_txfunaddr_registers_t;

#define USBHS_TXFUNADDR_NUMBER 8

#define USBHS_DMACNT_NUMBER 8

/** \brief USBHS register API structure */
typedef struct
{  /* USB High Speed */
  __IO  uint32_t                       USBHS_CTRLA;        /**< Offset: 0x00 (R/W  32) USBHS Control Register A. (All bits except ENABLE and SWRST are Enable protected) */
  __IO  uint32_t                       USBHS_CTRLB;        /**< Offset: 0x04 (R/W  32) USBHS Control Register B */
  __IO  uint32_t                       USBHS_CTRLC;        /**< Offset: 0x08 (R/W  32) USBHS Control Register C */
  __IO  uint32_t                       USBHS_INTENCLR;     /**< Offset: 0x0C (R/W  32) USBHS Interrupt Enable Clear Register */
  __IO  uint32_t                       USBHS_INTENSET;     /**< Offset: 0x10 (R/W  32) USBHS Interrupt Enable Clear Register */
  __IO  uint32_t                       USBHS_INTFLAG;      /**< Offset: 0x14 (R/W  32) USBHS Interrupt Flag Register */
  __I   uint32_t                       USBHS_STATUS;       /**< Offset: 0x18 (R/   32) USBHS Status Register */
  __I   uint32_t                       USBHS_SYNCBUSY;     /**< Offset: 0x1C (R/   32) USBHS Syncbusy Register */
  __I   uint8_t                        Reserved1[0xFE0];
  __IO  uint8_t                        USBHS_FADDR;        /**< Offset: 0x1000 (R/W  8) Function Address Register */
  __IO  uint8_t                        USBHS_POWER;        /**< Offset: 0x1001 (R/W  8) Used For Controlling Suspend And Resume Signaling And Some Basic Operation Of USBCORE */
  __I   uint16_t                       USBHS_INTRTX;       /**< Offset: 0x1002 (R/   16) Read Only Register Which Indicates Which Interrupts Are Currently Active For EP0 And TX EP1-15 */
  __I   uint16_t                       USBHS_INTRRX;       /**< Offset: 0x1004 (R/   16) Read Only Register Which Indicates Which Interrupts Are Currently Active For RX EP1-15 */
  __IO  uint16_t                       USBHS_INTRTXE;      /**< Offset: 0x1006 (R/W  16) Interrupt Enable Bits for INTRTX */
  __IO  uint16_t                       USBHS_INTRRXE;      /**< Offset: 0x1008 (R/W  16) Interrupt Enable Bits for INTRRX */
  __I   uint8_t                        USBHS_INTRUSB;      /**< Offset: 0x100A (R/   8) Read Only Register Which Indicates Which USB Interrupts Are Currently Active. */
  __IO  uint8_t                        USBHS_INTRUSBE;     /**< Offset: 0x100B (R/W  8) Interrupt Enable Bits for USB Interrupts */
  __I   uint16_t                       USBHS_FRAME;        /**< Offset: 0x100C (R/   16) Holds The Last Received Frame Number */
  __IO  uint8_t                        USBHS_INDEX;        /**< Offset: 0x100E (R/W  8) Index Is A 4-Bit Register That Determines Which Endpoint Control/Status Registers Are Accessed */
  __IO  uint8_t                        USBHS_TESTMODE;     /**< Offset: 0x100F (R/W  8) Not Used In Normal Operation. Configuration To Put the USBCORE Into One Of The Four Test Modes For HighSpeed Operation */
  __IO  uint16_t                       USBHS_TXMAXP;       /**< Offset: 0x1010 (R/W  16) ENDPOINTX Maximum Amount Of Data That Can Be Transferred Through The Selected TX Endpoint In A Single Operation */
  __IO  uint8_t                        USBHS_TXCSRL;       /**< Offset: 0x1012 (R/W  8) ENDPOINTX Control And Status Bits for TX Endpoints 1-15 */
  __IO  uint8_t                        USBHS_TXCSRH;       /**< Offset: 0x1013 (R/W  8) ENDPOINTX Additional Control And Status Bits For TX Endpoints 1-15 */
  __IO  uint16_t                       USBHS_RXMAXP;       /**< Offset: 0x1014 (R/W  16) ENDPOINTX Maximum Amount Of Data That Can Be Transferred Through The Selected RX Endpoint In A Single Operation */
  __IO  uint8_t                        USBHS_RXCSRL;       /**< Offset: 0x1016 (R/W  8) ENDPOINTX Control And Status Bits for RX Endpoint 0 Or Endpoint 1-15 */
  __IO  uint8_t                        USBHS_RXCSRH;       /**< Offset: 0x1017 (R/W  8) ENDPOINTX Additional Control And Status Bits for RX Endpoint 0 Or Endpoint 1-15 */
  __I   uint16_t                       USBHS_RXCOUNT;      /**< Offset: 0x1018 (R/   16) ENDPOINTX Number Of Data Bytes In The Packet Currently In Line To Be Read From The RX FIFO. */
  __IO  uint8_t                        USBHS_TXTYPE;       /**< Offset: 0x101A (R/W  8) ENDPOINTX Host Mode Only: Should Be Written With The Endpoint Number To Be Targeted By The Endpoint */
  __IO  uint8_t                        USBHS_TXINTERVAL;   /**< Offset: 0x101B (R/W  8) ENDPOINTX Host Mode Only: Defines The Polling Interval For The Currently Selected TX Endpoint. */
  __IO  uint8_t                        USBHS_RXTYPE;       /**< Offset: 0x101C (R/W  8) ENDPOINTX Host Mode Only: Should Be Written With The Endpoint Number To Be Targeted By The Endpoint */
  __IO  uint8_t                        USBHS_RXINTERVAL;   /**< Offset: 0x101D (R/W  8) ENDPOINTX Host Mode Only: Defines The Polling Interval For The Currently Selected RX Endpoint. */
  __I   uint8_t                        Reserved2[0x01];
  __I   uint8_t                        USBHS_FIFOSIZE;     /**< Offset: 0x101F (R/   8) ENDPOINTX Read Only Register That Returns The Sizes Of The FIFO's Associated With The Selected Additional TX/RX Endpoints. INDEX Regsiter should be set 1-15 */
  __IO  uint32_t                       USBHS_FIFOX[8];     /**< Offset: 0x1020 (R/W  32) Address Range Provides 16 Addresses For CPU Access To The FIFO's For Each Endpoint */
  __I   uint8_t                        Reserved3[0x20];
  __IO  uint8_t                        USBHS_DEVCTL;       /**< Offset: 0x1060 (R/W  8) Selects Whether The Core Is Operating In Peripheral Or Host Mode */
  __IO  uint8_t                        USBHS_MISC;         /**< Offset: 0x1061 (R/W  8) RX/TX Early DMA Enable Bits */
  __IO  uint8_t                        USBHS_TXFIFOSZ;     /**< Offset: 0x1062 (R/W  8) Controls The Size Of The Selected TX Endpoint FIFO */
  __IO  uint8_t                        USBHS_RXFIFOSZ;     /**< Offset: 0x1063 (R/W  8) Controls The Size Of The Selected RX Endpoint FIFO */
  __IO  uint16_t                       USBHS_TXFIFOADD;    /**< Offset: 0x1064 (R/W  16) Controls The Start Address Of the Selected TX Endpoint FIFO */
  __IO  uint16_t                       USBHS_RXFIFOADD;    /**< Offset: 0x1066 (R/W  16) Controls The Start Address Of the Selected RX Endpoint FIFO */
  __I   uint8_t                        Reserved4[0x10];
  __I   uint8_t                        USBHS_EPINFO;       /**< Offset: 0x1078 (R/   8) Allows Read-Back Of The Number Of TX And RX Endpoints */
  __I   uint8_t                        USBHS_RAMINFO;      /**< Offset: 0x1079 (R/   8) Details About Width Of RAM and DMA Channels */
  __IO  uint8_t                        USBHS_LINKINFO;     /**< Offset: 0x107A (R/W  8) Allows Some Delays To Be Specified */
  __IO  uint8_t                        USBHS_VPLEN;        /**< Offset: 0x107B (R/W  8) Sets The Duration Of The VBus Pulsing Charge */
  __IO  uint8_t                        USBHS_HSEOF1;       /**< Offset: 0x107C (R/W  8) Sets The Minimum Time Gap That Is To Be Allowed Between The Start Of The Last Transaction And The EOF For HS Transactions */
  __IO  uint8_t                        USBHS_FSEOF1;       /**< Offset: 0x107D (R/W  8) Sets The Minimum Time Gap That Is To Be Allowed Between The Start Of The Last Transaction And The EOF For FS Transactions */
  __IO  uint8_t                        USBHS_LSEOF1;       /**< Offset: 0x107E (R/W  8) Sets The Minimum Time Gap That Is To Be Allowed Between The Start Of The Last Transaction And The EOF For LS Transactions */
  __IO  uint8_t                        USBHS_SOFTRST;      /**< Offset: 0x107F (R/W  8) Assert Low The Output Reset Signals NRSTO and NRSTXO */
        usbhs_txfunaddr_registers_t    TXFUNADDR[USBHS_TXFUNADDR_NUMBER]; /**< Offset: 0x1080  */
  __I   uint8_t                        Reserved5[0x140];
  __IO  uint32_t                       USBHS_DMAINTR;      /**< Offset: 0x1200 (R/W  32) DMA Interrupt Status for Each Channel */
        usbhs_dmacnt_registers_t       DMACNT[USBHS_DMACNT_NUMBER]; /**< Offset: 0x1204  */
  __I   uint8_t                        Reserved6[0x80];
  __IO  uint32_t                       USBHS_RQPKTCOUNT[7]; /**< Offset: 0x1304 (R/W  32) Host Mode Only: Used To Specify Number Of Packets That Are To Be Transaferred In A Block Transfer */
  __I   uint8_t                        Reserved7[0x20];
  __IO  uint16_t                       USBHS_RXDPKTBUFDIS; /**< Offset: 0x1340 (R/W  16) Indicates Which Of The RX Endpoints Have Disabled Double Packet Buffer Functionality */
  __IO  uint16_t                       USBHS_TXDPKTBUFDIS; /**< Offset: 0x1342 (R/W  16) Indicates Which Of The TX Endpoints Have Disabled Double Packet Buffer Functionality */
  __IO  uint16_t                       USBHS_CTUCH;        /**< Offset: 0x1344 (R/W  16) Chirp Timeout. Number Of XCLK Cycles Before The Timeout */
  __IO  uint16_t                       USBHS_CTHHSRTN;     /**< Offset: 0x1346 (R/W  16) Sets The Delay From The End Of High-Speed Resume Signaling (Acting As A Host) To Enable The UTM Normal Operating Mode */
  __IO  uint16_t                       USBHS_CTHSBT;       /**< Offset: 0x1348 (R/W  16) This Register Represents The Value To Be Added To The Minimum High Speed Timeout Period Of 736 Bit Times. */
  __I   uint8_t                        Reserved8[0x16];
  __IO  uint16_t                       USBHS_LPMATTR;      /**< Offset: 0x1360 (R/W  16) Defines The Attributes Of An LPM Transaction And Sleep Cycle. */
  __IO  uint8_t                        USBHS_LPMCNTRL;     /**< Offset: 0x1362 (R/W  8) LPM Control Register */
  __IO  uint8_t                        USBHS_LPMINTREN;    /**< Offset: 0x1363 (R/W  8) LPM Interrupts Enable Register */
  __IO  uint8_t                        USBHS_LPMINTR;      /**< Offset: 0x1364 (R/W  8) Status Of The LPM Power State */
  __IO  uint8_t                        USBHS_LPMFADDR;     /**< Offset: 0x1365 (R/W  8) Function Address In LPM Payload */
  __I   uint8_t                        Reserved9[0x19A];
  __IO  uint32_t                       USBHS_PHY00;        /**< Offset: 0x1500 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY04;        /**< Offset: 0x1504 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY08;        /**< Offset: 0x1508 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY0C;        /**< Offset: 0x150C (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY10;        /**< Offset: 0x1510 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY14;        /**< Offset: 0x1514 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY18;        /**< Offset: 0x1518 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY1C;        /**< Offset: 0x151C (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY20;        /**< Offset: 0x1520 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY24;        /**< Offset: 0x1524 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY28;        /**< Offset: 0x1528 (R/W  32) USBHPHY Control Register. */
  __I   uint8_t                        Reserved10[0x18];
  __IO  uint32_t                       USBHS_PHY44;        /**< Offset: 0x1544 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY48;        /**< Offset: 0x1548 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY4C;        /**< Offset: 0x154C (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY50;        /**< Offset: 0x1550 (R/W  32) USBHPHY Control Register. */
} usbhs_endpointx_registers_t;

#define USBHS_TXFUNADDR_NUMBER 8

#define USBHS_DMACNT_NUMBER 8

/** \brief USBHS register API structure */
typedef struct
{  /* USB High Speed */
  __IO  uint32_t                       USBHS_CTRLA;        /**< Offset: 0x00 (R/W  32) USBHS Control Register A. (All bits except ENABLE and SWRST are Enable protected) */
  __IO  uint32_t                       USBHS_CTRLB;        /**< Offset: 0x04 (R/W  32) USBHS Control Register B */
  __IO  uint32_t                       USBHS_CTRLC;        /**< Offset: 0x08 (R/W  32) USBHS Control Register C */
  __IO  uint32_t                       USBHS_INTENCLR;     /**< Offset: 0x0C (R/W  32) USBHS Interrupt Enable Clear Register */
  __IO  uint32_t                       USBHS_INTENSET;     /**< Offset: 0x10 (R/W  32) USBHS Interrupt Enable Clear Register */
  __IO  uint32_t                       USBHS_INTFLAG;      /**< Offset: 0x14 (R/W  32) USBHS Interrupt Flag Register */
  __I   uint32_t                       USBHS_STATUS;       /**< Offset: 0x18 (R/   32) USBHS Status Register */
  __I   uint32_t                       USBHS_SYNCBUSY;     /**< Offset: 0x1C (R/   32) USBHS Syncbusy Register */
  __I   uint8_t                        Reserved1[0xFE0];
  __IO  uint8_t                        USBHS_FADDR;        /**< Offset: 0x1000 (R/W  8) Function Address Register */
  __IO  uint8_t                        USBHS_POWER;        /**< Offset: 0x1001 (R/W  8) Used For Controlling Suspend And Resume Signaling And Some Basic Operation Of USBCORE */
  __I   uint16_t                       USBHS_INTRTX;       /**< Offset: 0x1002 (R/   16) Read Only Register Which Indicates Which Interrupts Are Currently Active For EP0 And TX EP1-15 */
  __I   uint16_t                       USBHS_INTRRX;       /**< Offset: 0x1004 (R/   16) Read Only Register Which Indicates Which Interrupts Are Currently Active For RX EP1-15 */
  __IO  uint16_t                       USBHS_INTRTXE;      /**< Offset: 0x1006 (R/W  16) Interrupt Enable Bits for INTRTX */
  __IO  uint16_t                       USBHS_INTRRXE;      /**< Offset: 0x1008 (R/W  16) Interrupt Enable Bits for INTRRX */
  __I   uint8_t                        USBHS_INTRUSB;      /**< Offset: 0x100A (R/   8) Read Only Register Which Indicates Which USB Interrupts Are Currently Active. */
  __IO  uint8_t                        USBHS_INTRUSBE;     /**< Offset: 0x100B (R/W  8) Interrupt Enable Bits for USB Interrupts */
  __I   uint16_t                       USBHS_FRAME;        /**< Offset: 0x100C (R/   16) Holds The Last Received Frame Number */
  __IO  uint8_t                        USBHS_INDEX;        /**< Offset: 0x100E (R/W  8) Index Is A 4-Bit Register That Determines Which Endpoint Control/Status Registers Are Accessed */
  __IO  uint8_t                        USBHS_TESTMODE;     /**< Offset: 0x100F (R/W  8) Not Used In Normal Operation. Configuration To Put the USBCORE Into One Of The Four Test Modes For HighSpeed Operation */
  __I   uint8_t                        Reserved2[0x02];
  __IO  uint8_t                        USBHS_CSR0L;        /**< Offset: 0x1012 (R/W  8) ENDPOINT0 Control And Status Bits for TX Endpoint 0 */
  __IO  uint8_t                        USBHS_CSR0H;        /**< Offset: 0x1013 (R/W  8) ENDPOINT0 Additional Control And Status Bits For TX Endpoint 0 */
  __I   uint8_t                        Reserved3[0x04];
  __I   uint8_t                        USBHS_COUNT0;       /**< Offset: 0x1018 (R/   8) ENDPOINT0 Number Of Received Bytes In Endpoint 0 FIFO */
  __I   uint8_t                        Reserved4[0x01];
  __IO  uint8_t                        USBHS_TYPE0;        /**< Offset: 0x101A (R/W  8) ENDPOINT0 Host Mode Only: Operating Speed Of The Targeted Device */
  __IO  uint8_t                        USBHS_NAKLIMIT0;    /**< Offset: 0x101B (R/W  8) ENDPOINT0 Host Mode Only: Sets The NAK Response Timeout On Endpoint 0. */
  __I   uint8_t                        Reserved5[0x03];
  __I   uint8_t                        USBHS_CONFIGDATA;   /**< Offset: 0x101F (R/   8) ENDPOINT0 Returns Information About The Selected Core Configuration. Only Applicable when INDEX Regsiter Is 0. That Is Endpoint0 Is Selected. */
  __IO  uint32_t                       USBHS_FIFOX[8];     /**< Offset: 0x1020 (R/W  32) Address Range Provides 16 Addresses For CPU Access To The FIFO's For Each Endpoint */
  __I   uint8_t                        Reserved6[0x20];
  __IO  uint8_t                        USBHS_DEVCTL;       /**< Offset: 0x1060 (R/W  8) Selects Whether The Core Is Operating In Peripheral Or Host Mode */
  __IO  uint8_t                        USBHS_MISC;         /**< Offset: 0x1061 (R/W  8) RX/TX Early DMA Enable Bits */
  __IO  uint8_t                        USBHS_TXFIFOSZ;     /**< Offset: 0x1062 (R/W  8) Controls The Size Of The Selected TX Endpoint FIFO */
  __IO  uint8_t                        USBHS_RXFIFOSZ;     /**< Offset: 0x1063 (R/W  8) Controls The Size Of The Selected RX Endpoint FIFO */
  __IO  uint16_t                       USBHS_TXFIFOADD;    /**< Offset: 0x1064 (R/W  16) Controls The Start Address Of the Selected TX Endpoint FIFO */
  __IO  uint16_t                       USBHS_RXFIFOADD;    /**< Offset: 0x1066 (R/W  16) Controls The Start Address Of the Selected RX Endpoint FIFO */
  __I   uint8_t                        Reserved7[0x10];
  __I   uint8_t                        USBHS_EPINFO;       /**< Offset: 0x1078 (R/   8) Allows Read-Back Of The Number Of TX And RX Endpoints */
  __I   uint8_t                        USBHS_RAMINFO;      /**< Offset: 0x1079 (R/   8) Details About Width Of RAM and DMA Channels */
  __IO  uint8_t                        USBHS_LINKINFO;     /**< Offset: 0x107A (R/W  8) Allows Some Delays To Be Specified */
  __IO  uint8_t                        USBHS_VPLEN;        /**< Offset: 0x107B (R/W  8) Sets The Duration Of The VBus Pulsing Charge */
  __IO  uint8_t                        USBHS_HSEOF1;       /**< Offset: 0x107C (R/W  8) Sets The Minimum Time Gap That Is To Be Allowed Between The Start Of The Last Transaction And The EOF For HS Transactions */
  __IO  uint8_t                        USBHS_FSEOF1;       /**< Offset: 0x107D (R/W  8) Sets The Minimum Time Gap That Is To Be Allowed Between The Start Of The Last Transaction And The EOF For FS Transactions */
  __IO  uint8_t                        USBHS_LSEOF1;       /**< Offset: 0x107E (R/W  8) Sets The Minimum Time Gap That Is To Be Allowed Between The Start Of The Last Transaction And The EOF For LS Transactions */
  __IO  uint8_t                        USBHS_SOFTRST;      /**< Offset: 0x107F (R/W  8) Assert Low The Output Reset Signals NRSTO and NRSTXO */
        usbhs_txfunaddr_registers_t    TXFUNADDR[USBHS_TXFUNADDR_NUMBER]; /**< Offset: 0x1080  */
  __I   uint8_t                        Reserved8[0x140];
  __IO  uint32_t                       USBHS_DMAINTR;      /**< Offset: 0x1200 (R/W  32) DMA Interrupt Status for Each Channel */
        usbhs_dmacnt_registers_t       DMACNT[USBHS_DMACNT_NUMBER]; /**< Offset: 0x1204  */
  __I   uint8_t                        Reserved9[0x80];
  __IO  uint32_t                       USBHS_RQPKTCOUNT[7]; /**< Offset: 0x1304 (R/W  32) Host Mode Only: Used To Specify Number Of Packets That Are To Be Transaferred In A Block Transfer */
  __I   uint8_t                        Reserved10[0x20];
  __IO  uint16_t                       USBHS_RXDPKTBUFDIS; /**< Offset: 0x1340 (R/W  16) Indicates Which Of The RX Endpoints Have Disabled Double Packet Buffer Functionality */
  __IO  uint16_t                       USBHS_TXDPKTBUFDIS; /**< Offset: 0x1342 (R/W  16) Indicates Which Of The TX Endpoints Have Disabled Double Packet Buffer Functionality */
  __IO  uint16_t                       USBHS_CTUCH;        /**< Offset: 0x1344 (R/W  16) Chirp Timeout. Number Of XCLK Cycles Before The Timeout */
  __IO  uint16_t                       USBHS_CTHHSRTN;     /**< Offset: 0x1346 (R/W  16) Sets The Delay From The End Of High-Speed Resume Signaling (Acting As A Host) To Enable The UTM Normal Operating Mode */
  __IO  uint16_t                       USBHS_CTHSBT;       /**< Offset: 0x1348 (R/W  16) This Register Represents The Value To Be Added To The Minimum High Speed Timeout Period Of 736 Bit Times. */
  __I   uint8_t                        Reserved11[0x16];
  __IO  uint16_t                       USBHS_LPMATTR;      /**< Offset: 0x1360 (R/W  16) Defines The Attributes Of An LPM Transaction And Sleep Cycle. */
  __IO  uint8_t                        USBHS_LPMCNTRL;     /**< Offset: 0x1362 (R/W  8) LPM Control Register */
  __IO  uint8_t                        USBHS_LPMINTREN;    /**< Offset: 0x1363 (R/W  8) LPM Interrupts Enable Register */
  __IO  uint8_t                        USBHS_LPMINTR;      /**< Offset: 0x1364 (R/W  8) Status Of The LPM Power State */
  __IO  uint8_t                        USBHS_LPMFADDR;     /**< Offset: 0x1365 (R/W  8) Function Address In LPM Payload */
  __I   uint8_t                        Reserved12[0x19A];
  __IO  uint32_t                       USBHS_PHY00;        /**< Offset: 0x1500 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY04;        /**< Offset: 0x1504 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY08;        /**< Offset: 0x1508 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY0C;        /**< Offset: 0x150C (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY10;        /**< Offset: 0x1510 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY14;        /**< Offset: 0x1514 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY18;        /**< Offset: 0x1518 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY1C;        /**< Offset: 0x151C (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY20;        /**< Offset: 0x1520 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY24;        /**< Offset: 0x1524 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY28;        /**< Offset: 0x1528 (R/W  32) USBHPHY Control Register. */
  __I   uint8_t                        Reserved13[0x18];
  __IO  uint32_t                       USBHS_PHY44;        /**< Offset: 0x1544 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY48;        /**< Offset: 0x1548 (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY4C;        /**< Offset: 0x154C (R/W  32) USBHPHY Control Register. */
  __IO  uint32_t                       USBHS_PHY50;        /**< Offset: 0x1550 (R/W  32) USBHPHY Control Register. */
} usbhs_endpoint0_registers_t;

/** \brief USBHS hardware registers */
typedef union
{  /* USB High Speed */
       usbhs_endpointx_registers_t    ENDPOINTX;      /**< Endpont 1-15 are selected. INDEX.SELEP value needs to be greater than 0 */
       usbhs_endpoint0_registers_t    ENDPOINT0;      /**< Endpont 0 is selected */
} usbhs_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA80_USBHS_COMPONENT_H_ */
