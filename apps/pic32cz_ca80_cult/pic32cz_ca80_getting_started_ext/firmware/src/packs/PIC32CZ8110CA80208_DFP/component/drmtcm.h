/*
 * Component description for DRMTCM
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
#ifndef _PIC32CZCA80_DRMTCM_COMPONENT_H_
#define _PIC32CZCA80_DRMTCM_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR DRMTCM                                       */
/* ************************************************************************** */

/* -------- DRMTCM_CTRLA : (DRMTCM Offset: 0x00) (R/W 32) CONTROL ENABLE REGISTER A -------- */
#define DRMTCM_CTRLA_RESETVALUE               _UINT32_(0x02)                                       /*  (DRMTCM_CTRLA) CONTROL ENABLE REGISTER A  Reset Value */

#define DRMTCM_CTRLA_SWRST_Pos                _UINT32_(0)                                          /* (DRMTCM_CTRLA) DRMTCM Software Reset Position */
#define DRMTCM_CTRLA_SWRST_Msk                (_UINT32_(0x1) << DRMTCM_CTRLA_SWRST_Pos)            /* (DRMTCM_CTRLA) DRMTCM Software Reset Mask */
#define DRMTCM_CTRLA_SWRST(value)             (DRMTCM_CTRLA_SWRST_Msk & (_UINT32_(value) << DRMTCM_CTRLA_SWRST_Pos)) /* Assigment of value for SWRST in the DRMTCM_CTRLA register */
#define DRMTCM_CTRLA_ENABLE_Pos               _UINT32_(1)                                          /* (DRMTCM_CTRLA) DRMTCM ECC Enable (ON) bit (default ECC is always enabled) Position */
#define DRMTCM_CTRLA_ENABLE_Msk               (_UINT32_(0x1) << DRMTCM_CTRLA_ENABLE_Pos)           /* (DRMTCM_CTRLA) DRMTCM ECC Enable (ON) bit (default ECC is always enabled) Mask */
#define DRMTCM_CTRLA_ENABLE(value)            (DRMTCM_CTRLA_ENABLE_Msk & (_UINT32_(value) << DRMTCM_CTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the DRMTCM_CTRLA register */
#define DRMTCM_CTRLA_Msk                      _UINT32_(0x00000003)                                 /* (DRMTCM_CTRLA) Register Mask  */


/* -------- DRMTCM_CTRLB : (DRMTCM Offset: 0x04) (R/W 32) CONTROL ENABLE REGISTER B -------- */
#define DRMTCM_CTRLB_RESETVALUE               _UINT32_(0x70707)                                    /*  (DRMTCM_CTRLB) CONTROL ENABLE REGISTER B  Reset Value */

#define DRMTCM_CTRLB_IERRCNT_Pos              _UINT32_(0)                                          /* (DRMTCM_CTRLB) ITCM ERROR MAXIMUM COUNT (default 0x7) Position */
#define DRMTCM_CTRLB_IERRCNT_Msk              (_UINT32_(0xFF) << DRMTCM_CTRLB_IERRCNT_Pos)         /* (DRMTCM_CTRLB) ITCM ERROR MAXIMUM COUNT (default 0x7) Mask */
#define DRMTCM_CTRLB_IERRCNT(value)           (DRMTCM_CTRLB_IERRCNT_Msk & (_UINT32_(value) << DRMTCM_CTRLB_IERRCNT_Pos)) /* Assigment of value for IERRCNT in the DRMTCM_CTRLB register */
#define DRMTCM_CTRLB_D0ERRCNT_Pos             _UINT32_(8)                                          /* (DRMTCM_CTRLB) D0TCM ERROR MAXIMUM COUNT (default 0x7) Position */
#define DRMTCM_CTRLB_D0ERRCNT_Msk             (_UINT32_(0xFF) << DRMTCM_CTRLB_D0ERRCNT_Pos)        /* (DRMTCM_CTRLB) D0TCM ERROR MAXIMUM COUNT (default 0x7) Mask */
#define DRMTCM_CTRLB_D0ERRCNT(value)          (DRMTCM_CTRLB_D0ERRCNT_Msk & (_UINT32_(value) << DRMTCM_CTRLB_D0ERRCNT_Pos)) /* Assigment of value for D0ERRCNT in the DRMTCM_CTRLB register */
#define DRMTCM_CTRLB_D1ERRCNT_Pos             _UINT32_(16)                                         /* (DRMTCM_CTRLB) D1TCM ERROR MAXIMUM COUNT (default 0x7) Position */
#define DRMTCM_CTRLB_D1ERRCNT_Msk             (_UINT32_(0xFF) << DRMTCM_CTRLB_D1ERRCNT_Pos)        /* (DRMTCM_CTRLB) D1TCM ERROR MAXIMUM COUNT (default 0x7) Mask */
#define DRMTCM_CTRLB_D1ERRCNT(value)          (DRMTCM_CTRLB_D1ERRCNT_Msk & (_UINT32_(value) << DRMTCM_CTRLB_D1ERRCNT_Pos)) /* Assigment of value for D1ERRCNT in the DRMTCM_CTRLB register */
#define DRMTCM_CTRLB_IWAITSTEN_Pos            _UINT32_(24)                                         /* (DRMTCM_CTRLB) ITCM ONE WAIT STATE ENABLE BIT Position */
#define DRMTCM_CTRLB_IWAITSTEN_Msk            (_UINT32_(0x1) << DRMTCM_CTRLB_IWAITSTEN_Pos)        /* (DRMTCM_CTRLB) ITCM ONE WAIT STATE ENABLE BIT Mask */
#define DRMTCM_CTRLB_IWAITSTEN(value)         (DRMTCM_CTRLB_IWAITSTEN_Msk & (_UINT32_(value) << DRMTCM_CTRLB_IWAITSTEN_Pos)) /* Assigment of value for IWAITSTEN in the DRMTCM_CTRLB register */
#define DRMTCM_CTRLB_DWAITSTEN_Pos            _UINT32_(25)                                         /* (DRMTCM_CTRLB) D1TCM and D0TCM ONE WAIT STATE ENABLE BIT Position */
#define DRMTCM_CTRLB_DWAITSTEN_Msk            (_UINT32_(0x1) << DRMTCM_CTRLB_DWAITSTEN_Pos)        /* (DRMTCM_CTRLB) D1TCM and D0TCM ONE WAIT STATE ENABLE BIT Mask */
#define DRMTCM_CTRLB_DWAITSTEN(value)         (DRMTCM_CTRLB_DWAITSTEN_Msk & (_UINT32_(value) << DRMTCM_CTRLB_DWAITSTEN_Pos)) /* Assigment of value for DWAITSTEN in the DRMTCM_CTRLB register */
#define DRMTCM_CTRLB_IERCNTDIS_Pos            _UINT32_(28)                                         /* (DRMTCM_CTRLB) ITCM ERROR COUNTER DISABLE BIT Position */
#define DRMTCM_CTRLB_IERCNTDIS_Msk            (_UINT32_(0x1) << DRMTCM_CTRLB_IERCNTDIS_Pos)        /* (DRMTCM_CTRLB) ITCM ERROR COUNTER DISABLE BIT Mask */
#define DRMTCM_CTRLB_IERCNTDIS(value)         (DRMTCM_CTRLB_IERCNTDIS_Msk & (_UINT32_(value) << DRMTCM_CTRLB_IERCNTDIS_Pos)) /* Assigment of value for IERCNTDIS in the DRMTCM_CTRLB register */
#define DRMTCM_CTRLB_D0ERCNTDIS_Pos           _UINT32_(29)                                         /* (DRMTCM_CTRLB) D0TCM ERROR COUNTER DISABLE BIT Position */
#define DRMTCM_CTRLB_D0ERCNTDIS_Msk           (_UINT32_(0x1) << DRMTCM_CTRLB_D0ERCNTDIS_Pos)       /* (DRMTCM_CTRLB) D0TCM ERROR COUNTER DISABLE BIT Mask */
#define DRMTCM_CTRLB_D0ERCNTDIS(value)        (DRMTCM_CTRLB_D0ERCNTDIS_Msk & (_UINT32_(value) << DRMTCM_CTRLB_D0ERCNTDIS_Pos)) /* Assigment of value for D0ERCNTDIS in the DRMTCM_CTRLB register */
#define DRMTCM_CTRLB_D1ERCNTDIS_Pos           _UINT32_(30)                                         /* (DRMTCM_CTRLB) D1TCM ERROR COUNTER DISABLE BIT Position */
#define DRMTCM_CTRLB_D1ERCNTDIS_Msk           (_UINT32_(0x1) << DRMTCM_CTRLB_D1ERCNTDIS_Pos)       /* (DRMTCM_CTRLB) D1TCM ERROR COUNTER DISABLE BIT Mask */
#define DRMTCM_CTRLB_D1ERCNTDIS(value)        (DRMTCM_CTRLB_D1ERCNTDIS_Msk & (_UINT32_(value) << DRMTCM_CTRLB_D1ERCNTDIS_Pos)) /* Assigment of value for D1ERCNTDIS in the DRMTCM_CTRLB register */
#define DRMTCM_CTRLB_Msk                      _UINT32_(0x73FFFFFF)                                 /* (DRMTCM_CTRLB) Register Mask  */


/* -------- DRMTCM_SYNCBUSY : (DRMTCM Offset: 0x08) ( R/ 32) SYNC BUSY REGISTER -------- */
#define DRMTCM_SYNCBUSY_RESETVALUE            _UINT32_(0x00)                                       /*  (DRMTCM_SYNCBUSY) SYNC BUSY REGISTER  Reset Value */

#define DRMTCM_SYNCBUSY_SWRST_Pos             _UINT32_(0)                                          /* (DRMTCM_SYNCBUSY) Software reset busy bit   --- Synchronizing Busy bit for SWRST Position */
#define DRMTCM_SYNCBUSY_SWRST_Msk             (_UINT32_(0x1) << DRMTCM_SYNCBUSY_SWRST_Pos)         /* (DRMTCM_SYNCBUSY) Software reset busy bit   --- Synchronizing Busy bit for SWRST Mask */
#define DRMTCM_SYNCBUSY_SWRST(value)          (DRMTCM_SYNCBUSY_SWRST_Msk & (_UINT32_(value) << DRMTCM_SYNCBUSY_SWRST_Pos)) /* Assigment of value for SWRST in the DRMTCM_SYNCBUSY register */
#define DRMTCM_SYNCBUSY_FLTEN_Pos             _UINT32_(1)                                          /* (DRMTCM_SYNCBUSY) Fault Injection Enabled busy bit   --- Synchronizing Busy bit for FLTEN register (when hard-ware set this bit, no writes are allowed to the FLTCTRL register until after the synchronizing is not busy). Position */
#define DRMTCM_SYNCBUSY_FLTEN_Msk             (_UINT32_(0x1) << DRMTCM_SYNCBUSY_FLTEN_Pos)         /* (DRMTCM_SYNCBUSY) Fault Injection Enabled busy bit   --- Synchronizing Busy bit for FLTEN register (when hard-ware set this bit, no writes are allowed to the FLTCTRL register until after the synchronizing is not busy). Mask */
#define DRMTCM_SYNCBUSY_FLTEN(value)          (DRMTCM_SYNCBUSY_FLTEN_Msk & (_UINT32_(value) << DRMTCM_SYNCBUSY_FLTEN_Pos)) /* Assigment of value for FLTEN in the DRMTCM_SYNCBUSY register */
#define DRMTCM_SYNCBUSY_Msk                   _UINT32_(0x00000003)                                 /* (DRMTCM_SYNCBUSY) Register Mask  */


/* -------- DRMTCM_INTENCLR : (DRMTCM Offset: 0x0C) (R/W 32) INTERRUPT ENABLE CLR REGISTER -------- */
#define DRMTCM_INTENCLR_RESETVALUE            _UINT32_(0x00)                                       /*  (DRMTCM_INTENCLR) INTERRUPT ENABLE CLR REGISTER  Reset Value */

#define DRMTCM_INTENCLR_ISERREN_Pos           _UINT32_(0)                                          /* (DRMTCM_INTENCLR) ITCM Single Bit Error Detection Flag bit Disable Position */
#define DRMTCM_INTENCLR_ISERREN_Msk           (_UINT32_(0x1) << DRMTCM_INTENCLR_ISERREN_Pos)       /* (DRMTCM_INTENCLR) ITCM Single Bit Error Detection Flag bit Disable Mask */
#define DRMTCM_INTENCLR_ISERREN(value)        (DRMTCM_INTENCLR_ISERREN_Msk & (_UINT32_(value) << DRMTCM_INTENCLR_ISERREN_Pos)) /* Assigment of value for ISERREN in the DRMTCM_INTENCLR register */
#define DRMTCM_INTENCLR_IDERREN_Pos           _UINT32_(1)                                          /* (DRMTCM_INTENCLR) ITCM Double Bit Error Detection Flag bit Disable Position */
#define DRMTCM_INTENCLR_IDERREN_Msk           (_UINT32_(0x1) << DRMTCM_INTENCLR_IDERREN_Pos)       /* (DRMTCM_INTENCLR) ITCM Double Bit Error Detection Flag bit Disable Mask */
#define DRMTCM_INTENCLR_IDERREN(value)        (DRMTCM_INTENCLR_IDERREN_Msk & (_UINT32_(value) << DRMTCM_INTENCLR_IDERREN_Pos)) /* Assigment of value for IDERREN in the DRMTCM_INTENCLR register */
#define DRMTCM_INTENCLR_IECCECNTEN_Pos        _UINT32_(2)                                          /* (DRMTCM_INTENCLR) ITCM ECC Error Count Flag bit Disable Position */
#define DRMTCM_INTENCLR_IECCECNTEN_Msk        (_UINT32_(0x1) << DRMTCM_INTENCLR_IECCECNTEN_Pos)    /* (DRMTCM_INTENCLR) ITCM ECC Error Count Flag bit Disable Mask */
#define DRMTCM_INTENCLR_IECCECNTEN(value)     (DRMTCM_INTENCLR_IECCECNTEN_Msk & (_UINT32_(value) << DRMTCM_INTENCLR_IECCECNTEN_Pos)) /* Assigment of value for IECCECNTEN in the DRMTCM_INTENCLR register */
#define DRMTCM_INTENCLR_D0SERREN_Pos          _UINT32_(8)                                          /* (DRMTCM_INTENCLR) D0TCM Single Bit Error Detection Flag bit Disable Position */
#define DRMTCM_INTENCLR_D0SERREN_Msk          (_UINT32_(0x1) << DRMTCM_INTENCLR_D0SERREN_Pos)      /* (DRMTCM_INTENCLR) D0TCM Single Bit Error Detection Flag bit Disable Mask */
#define DRMTCM_INTENCLR_D0SERREN(value)       (DRMTCM_INTENCLR_D0SERREN_Msk & (_UINT32_(value) << DRMTCM_INTENCLR_D0SERREN_Pos)) /* Assigment of value for D0SERREN in the DRMTCM_INTENCLR register */
#define DRMTCM_INTENCLR_D0DERREN_Pos          _UINT32_(9)                                          /* (DRMTCM_INTENCLR) D0TCM Double Bit Error Detection Flag bit Disable Position */
#define DRMTCM_INTENCLR_D0DERREN_Msk          (_UINT32_(0x1) << DRMTCM_INTENCLR_D0DERREN_Pos)      /* (DRMTCM_INTENCLR) D0TCM Double Bit Error Detection Flag bit Disable Mask */
#define DRMTCM_INTENCLR_D0DERREN(value)       (DRMTCM_INTENCLR_D0DERREN_Msk & (_UINT32_(value) << DRMTCM_INTENCLR_D0DERREN_Pos)) /* Assigment of value for D0DERREN in the DRMTCM_INTENCLR register */
#define DRMTCM_INTENCLR_D0ECCECNTEN_Pos       _UINT32_(10)                                         /* (DRMTCM_INTENCLR) D0TCM ECC Error Count Flag bit Disable Position */
#define DRMTCM_INTENCLR_D0ECCECNTEN_Msk       (_UINT32_(0x1) << DRMTCM_INTENCLR_D0ECCECNTEN_Pos)   /* (DRMTCM_INTENCLR) D0TCM ECC Error Count Flag bit Disable Mask */
#define DRMTCM_INTENCLR_D0ECCECNTEN(value)    (DRMTCM_INTENCLR_D0ECCECNTEN_Msk & (_UINT32_(value) << DRMTCM_INTENCLR_D0ECCECNTEN_Pos)) /* Assigment of value for D0ECCECNTEN in the DRMTCM_INTENCLR register */
#define DRMTCM_INTENCLR_D1SERREN_Pos          _UINT32_(16)                                         /* (DRMTCM_INTENCLR) D1TCM Single Bit Error Detection Flag bit Disable Position */
#define DRMTCM_INTENCLR_D1SERREN_Msk          (_UINT32_(0x1) << DRMTCM_INTENCLR_D1SERREN_Pos)      /* (DRMTCM_INTENCLR) D1TCM Single Bit Error Detection Flag bit Disable Mask */
#define DRMTCM_INTENCLR_D1SERREN(value)       (DRMTCM_INTENCLR_D1SERREN_Msk & (_UINT32_(value) << DRMTCM_INTENCLR_D1SERREN_Pos)) /* Assigment of value for D1SERREN in the DRMTCM_INTENCLR register */
#define DRMTCM_INTENCLR_D1DERREN_Pos          _UINT32_(17)                                         /* (DRMTCM_INTENCLR) D1TCM Double Bit Error Detection Flag bit Disable Position */
#define DRMTCM_INTENCLR_D1DERREN_Msk          (_UINT32_(0x1) << DRMTCM_INTENCLR_D1DERREN_Pos)      /* (DRMTCM_INTENCLR) D1TCM Double Bit Error Detection Flag bit Disable Mask */
#define DRMTCM_INTENCLR_D1DERREN(value)       (DRMTCM_INTENCLR_D1DERREN_Msk & (_UINT32_(value) << DRMTCM_INTENCLR_D1DERREN_Pos)) /* Assigment of value for D1DERREN in the DRMTCM_INTENCLR register */
#define DRMTCM_INTENCLR_D1ECCECNTEN_Pos       _UINT32_(18)                                         /* (DRMTCM_INTENCLR) D1TCM ECC Error Count Flag bit Disable Position */
#define DRMTCM_INTENCLR_D1ECCECNTEN_Msk       (_UINT32_(0x1) << DRMTCM_INTENCLR_D1ECCECNTEN_Pos)   /* (DRMTCM_INTENCLR) D1TCM ECC Error Count Flag bit Disable Mask */
#define DRMTCM_INTENCLR_D1ECCECNTEN(value)    (DRMTCM_INTENCLR_D1ECCECNTEN_Msk & (_UINT32_(value) << DRMTCM_INTENCLR_D1ECCECNTEN_Pos)) /* Assigment of value for D1ECCECNTEN in the DRMTCM_INTENCLR register */
#define DRMTCM_INTENCLR_FLTCAPEN_Pos          _UINT32_(24)                                         /* (DRMTCM_INTENCLR) Fault Capture interrupt enable bit Disable Position */
#define DRMTCM_INTENCLR_FLTCAPEN_Msk          (_UINT32_(0x1) << DRMTCM_INTENCLR_FLTCAPEN_Pos)      /* (DRMTCM_INTENCLR) Fault Capture interrupt enable bit Disable Mask */
#define DRMTCM_INTENCLR_FLTCAPEN(value)       (DRMTCM_INTENCLR_FLTCAPEN_Msk & (_UINT32_(value) << DRMTCM_INTENCLR_FLTCAPEN_Pos)) /* Assigment of value for FLTCAPEN in the DRMTCM_INTENCLR register */
#define DRMTCM_INTENCLR_Msk                   _UINT32_(0x01070707)                                 /* (DRMTCM_INTENCLR) Register Mask  */


/* -------- DRMTCM_INTENSET : (DRMTCM Offset: 0x10) (R/W 32) INTERRUPT ENABLE SET REGISTER -------- */
#define DRMTCM_INTENSET_RESETVALUE            _UINT32_(0x00)                                       /*  (DRMTCM_INTENSET) INTERRUPT ENABLE SET REGISTER  Reset Value */

#define DRMTCM_INTENSET_ISERREN_Pos           _UINT32_(0)                                          /* (DRMTCM_INTENSET) ITCM Single Bit Error Detection Flag bit Enable Position */
#define DRMTCM_INTENSET_ISERREN_Msk           (_UINT32_(0x1) << DRMTCM_INTENSET_ISERREN_Pos)       /* (DRMTCM_INTENSET) ITCM Single Bit Error Detection Flag bit Enable Mask */
#define DRMTCM_INTENSET_ISERREN(value)        (DRMTCM_INTENSET_ISERREN_Msk & (_UINT32_(value) << DRMTCM_INTENSET_ISERREN_Pos)) /* Assigment of value for ISERREN in the DRMTCM_INTENSET register */
#define DRMTCM_INTENSET_IDERREN_Pos           _UINT32_(1)                                          /* (DRMTCM_INTENSET) ITCM Double Bit Error Detection Flag bit Enable Position */
#define DRMTCM_INTENSET_IDERREN_Msk           (_UINT32_(0x1) << DRMTCM_INTENSET_IDERREN_Pos)       /* (DRMTCM_INTENSET) ITCM Double Bit Error Detection Flag bit Enable Mask */
#define DRMTCM_INTENSET_IDERREN(value)        (DRMTCM_INTENSET_IDERREN_Msk & (_UINT32_(value) << DRMTCM_INTENSET_IDERREN_Pos)) /* Assigment of value for IDERREN in the DRMTCM_INTENSET register */
#define DRMTCM_INTENSET_IECCECNTEN_Pos        _UINT32_(2)                                          /* (DRMTCM_INTENSET) ITCM ECC Error Count Flag bit Enable Position */
#define DRMTCM_INTENSET_IECCECNTEN_Msk        (_UINT32_(0x1) << DRMTCM_INTENSET_IECCECNTEN_Pos)    /* (DRMTCM_INTENSET) ITCM ECC Error Count Flag bit Enable Mask */
#define DRMTCM_INTENSET_IECCECNTEN(value)     (DRMTCM_INTENSET_IECCECNTEN_Msk & (_UINT32_(value) << DRMTCM_INTENSET_IECCECNTEN_Pos)) /* Assigment of value for IECCECNTEN in the DRMTCM_INTENSET register */
#define DRMTCM_INTENSET_D0SERREN_Pos          _UINT32_(8)                                          /* (DRMTCM_INTENSET) D0TCM Single Bit Error Detection Flag bit Enable Position */
#define DRMTCM_INTENSET_D0SERREN_Msk          (_UINT32_(0x1) << DRMTCM_INTENSET_D0SERREN_Pos)      /* (DRMTCM_INTENSET) D0TCM Single Bit Error Detection Flag bit Enable Mask */
#define DRMTCM_INTENSET_D0SERREN(value)       (DRMTCM_INTENSET_D0SERREN_Msk & (_UINT32_(value) << DRMTCM_INTENSET_D0SERREN_Pos)) /* Assigment of value for D0SERREN in the DRMTCM_INTENSET register */
#define DRMTCM_INTENSET_D0DERREN_Pos          _UINT32_(9)                                          /* (DRMTCM_INTENSET) D0TCM Double Bit Error Detection Flag bit Enable Position */
#define DRMTCM_INTENSET_D0DERREN_Msk          (_UINT32_(0x1) << DRMTCM_INTENSET_D0DERREN_Pos)      /* (DRMTCM_INTENSET) D0TCM Double Bit Error Detection Flag bit Enable Mask */
#define DRMTCM_INTENSET_D0DERREN(value)       (DRMTCM_INTENSET_D0DERREN_Msk & (_UINT32_(value) << DRMTCM_INTENSET_D0DERREN_Pos)) /* Assigment of value for D0DERREN in the DRMTCM_INTENSET register */
#define DRMTCM_INTENSET_D0ECCECNTEN_Pos       _UINT32_(10)                                         /* (DRMTCM_INTENSET) D0TCM ECC Error Count Flag bit Enable Position */
#define DRMTCM_INTENSET_D0ECCECNTEN_Msk       (_UINT32_(0x1) << DRMTCM_INTENSET_D0ECCECNTEN_Pos)   /* (DRMTCM_INTENSET) D0TCM ECC Error Count Flag bit Enable Mask */
#define DRMTCM_INTENSET_D0ECCECNTEN(value)    (DRMTCM_INTENSET_D0ECCECNTEN_Msk & (_UINT32_(value) << DRMTCM_INTENSET_D0ECCECNTEN_Pos)) /* Assigment of value for D0ECCECNTEN in the DRMTCM_INTENSET register */
#define DRMTCM_INTENSET_D1SERREN_Pos          _UINT32_(16)                                         /* (DRMTCM_INTENSET) D1TCM Single Bit Error Detection Flag bit Enable Position */
#define DRMTCM_INTENSET_D1SERREN_Msk          (_UINT32_(0x1) << DRMTCM_INTENSET_D1SERREN_Pos)      /* (DRMTCM_INTENSET) D1TCM Single Bit Error Detection Flag bit Enable Mask */
#define DRMTCM_INTENSET_D1SERREN(value)       (DRMTCM_INTENSET_D1SERREN_Msk & (_UINT32_(value) << DRMTCM_INTENSET_D1SERREN_Pos)) /* Assigment of value for D1SERREN in the DRMTCM_INTENSET register */
#define DRMTCM_INTENSET_D1DERREN_Pos          _UINT32_(17)                                         /* (DRMTCM_INTENSET) D1TCM Double Bit Error Detection Flag bit Enable Position */
#define DRMTCM_INTENSET_D1DERREN_Msk          (_UINT32_(0x1) << DRMTCM_INTENSET_D1DERREN_Pos)      /* (DRMTCM_INTENSET) D1TCM Double Bit Error Detection Flag bit Enable Mask */
#define DRMTCM_INTENSET_D1DERREN(value)       (DRMTCM_INTENSET_D1DERREN_Msk & (_UINT32_(value) << DRMTCM_INTENSET_D1DERREN_Pos)) /* Assigment of value for D1DERREN in the DRMTCM_INTENSET register */
#define DRMTCM_INTENSET_D1ECCECNTEN_Pos       _UINT32_(18)                                         /* (DRMTCM_INTENSET) D1TCM ECC Error Count Flag bit Enable Position */
#define DRMTCM_INTENSET_D1ECCECNTEN_Msk       (_UINT32_(0x1) << DRMTCM_INTENSET_D1ECCECNTEN_Pos)   /* (DRMTCM_INTENSET) D1TCM ECC Error Count Flag bit Enable Mask */
#define DRMTCM_INTENSET_D1ECCECNTEN(value)    (DRMTCM_INTENSET_D1ECCECNTEN_Msk & (_UINT32_(value) << DRMTCM_INTENSET_D1ECCECNTEN_Pos)) /* Assigment of value for D1ECCECNTEN in the DRMTCM_INTENSET register */
#define DRMTCM_INTENSET_FLTCAPEN_Pos          _UINT32_(24)                                         /* (DRMTCM_INTENSET) Fault Capture interrupt enable bit Enable Position */
#define DRMTCM_INTENSET_FLTCAPEN_Msk          (_UINT32_(0x1) << DRMTCM_INTENSET_FLTCAPEN_Pos)      /* (DRMTCM_INTENSET) Fault Capture interrupt enable bit Enable Mask */
#define DRMTCM_INTENSET_FLTCAPEN(value)       (DRMTCM_INTENSET_FLTCAPEN_Msk & (_UINT32_(value) << DRMTCM_INTENSET_FLTCAPEN_Pos)) /* Assigment of value for FLTCAPEN in the DRMTCM_INTENSET register */
#define DRMTCM_INTENSET_Msk                   _UINT32_(0x01070707)                                 /* (DRMTCM_INTENSET) Register Mask  */


/* -------- DRMTCM_INTFLAG : (DRMTCM Offset: 0x14) (R/W 32) INTERRUPT FLAG REGISTER -------- */
#define DRMTCM_INTFLAG_RESETVALUE             _UINT32_(0x00)                                       /*  (DRMTCM_INTFLAG) INTERRUPT FLAG REGISTER  Reset Value */

#define DRMTCM_INTFLAG_ISERR_Pos              _UINT32_(0)                                          /* (DRMTCM_INTFLAG) ITCM Single Bit Error Detection Flag Position */
#define DRMTCM_INTFLAG_ISERR_Msk              (_UINT32_(0x1) << DRMTCM_INTFLAG_ISERR_Pos)          /* (DRMTCM_INTFLAG) ITCM Single Bit Error Detection Flag Mask */
#define DRMTCM_INTFLAG_ISERR(value)           (DRMTCM_INTFLAG_ISERR_Msk & (_UINT32_(value) << DRMTCM_INTFLAG_ISERR_Pos)) /* Assigment of value for ISERR in the DRMTCM_INTFLAG register */
#define DRMTCM_INTFLAG_IDERR_Pos              _UINT32_(1)                                          /* (DRMTCM_INTFLAG) ITCM Double Bit Error Detection Flag Position */
#define DRMTCM_INTFLAG_IDERR_Msk              (_UINT32_(0x1) << DRMTCM_INTFLAG_IDERR_Pos)          /* (DRMTCM_INTFLAG) ITCM Double Bit Error Detection Flag Mask */
#define DRMTCM_INTFLAG_IDERR(value)           (DRMTCM_INTFLAG_IDERR_Msk & (_UINT32_(value) << DRMTCM_INTFLAG_IDERR_Pos)) /* Assigment of value for IDERR in the DRMTCM_INTFLAG register */
#define DRMTCM_INTFLAG_IECCECNT_Pos           _UINT32_(2)                                          /* (DRMTCM_INTFLAG) ITCM ECC Error Count Flag Position */
#define DRMTCM_INTFLAG_IECCECNT_Msk           (_UINT32_(0x1) << DRMTCM_INTFLAG_IECCECNT_Pos)       /* (DRMTCM_INTFLAG) ITCM ECC Error Count Flag Mask */
#define DRMTCM_INTFLAG_IECCECNT(value)        (DRMTCM_INTFLAG_IECCECNT_Msk & (_UINT32_(value) << DRMTCM_INTFLAG_IECCECNT_Pos)) /* Assigment of value for IECCECNT in the DRMTCM_INTFLAG register */
#define DRMTCM_INTFLAG_D0SERR_Pos             _UINT32_(8)                                          /* (DRMTCM_INTFLAG) D0TCM Single Bit Error Detection Flag Position */
#define DRMTCM_INTFLAG_D0SERR_Msk             (_UINT32_(0x1) << DRMTCM_INTFLAG_D0SERR_Pos)         /* (DRMTCM_INTFLAG) D0TCM Single Bit Error Detection Flag Mask */
#define DRMTCM_INTFLAG_D0SERR(value)          (DRMTCM_INTFLAG_D0SERR_Msk & (_UINT32_(value) << DRMTCM_INTFLAG_D0SERR_Pos)) /* Assigment of value for D0SERR in the DRMTCM_INTFLAG register */
#define DRMTCM_INTFLAG_D0DERR_Pos             _UINT32_(9)                                          /* (DRMTCM_INTFLAG) D0TCM Double Bit Error Detection Flag Position */
#define DRMTCM_INTFLAG_D0DERR_Msk             (_UINT32_(0x1) << DRMTCM_INTFLAG_D0DERR_Pos)         /* (DRMTCM_INTFLAG) D0TCM Double Bit Error Detection Flag Mask */
#define DRMTCM_INTFLAG_D0DERR(value)          (DRMTCM_INTFLAG_D0DERR_Msk & (_UINT32_(value) << DRMTCM_INTFLAG_D0DERR_Pos)) /* Assigment of value for D0DERR in the DRMTCM_INTFLAG register */
#define DRMTCM_INTFLAG_D0ECCECNT_Pos          _UINT32_(10)                                         /* (DRMTCM_INTFLAG) D0TCM ECC Error Count Flag Position */
#define DRMTCM_INTFLAG_D0ECCECNT_Msk          (_UINT32_(0x1) << DRMTCM_INTFLAG_D0ECCECNT_Pos)      /* (DRMTCM_INTFLAG) D0TCM ECC Error Count Flag Mask */
#define DRMTCM_INTFLAG_D0ECCECNT(value)       (DRMTCM_INTFLAG_D0ECCECNT_Msk & (_UINT32_(value) << DRMTCM_INTFLAG_D0ECCECNT_Pos)) /* Assigment of value for D0ECCECNT in the DRMTCM_INTFLAG register */
#define DRMTCM_INTFLAG_D1SERR_Pos             _UINT32_(16)                                         /* (DRMTCM_INTFLAG) D1TCM Single Bit Error Detection Flag Position */
#define DRMTCM_INTFLAG_D1SERR_Msk             (_UINT32_(0x1) << DRMTCM_INTFLAG_D1SERR_Pos)         /* (DRMTCM_INTFLAG) D1TCM Single Bit Error Detection Flag Mask */
#define DRMTCM_INTFLAG_D1SERR(value)          (DRMTCM_INTFLAG_D1SERR_Msk & (_UINT32_(value) << DRMTCM_INTFLAG_D1SERR_Pos)) /* Assigment of value for D1SERR in the DRMTCM_INTFLAG register */
#define DRMTCM_INTFLAG_D1DERR_Pos             _UINT32_(17)                                         /* (DRMTCM_INTFLAG) D1TCM Double Bit Error Detection Flag Position */
#define DRMTCM_INTFLAG_D1DERR_Msk             (_UINT32_(0x1) << DRMTCM_INTFLAG_D1DERR_Pos)         /* (DRMTCM_INTFLAG) D1TCM Double Bit Error Detection Flag Mask */
#define DRMTCM_INTFLAG_D1DERR(value)          (DRMTCM_INTFLAG_D1DERR_Msk & (_UINT32_(value) << DRMTCM_INTFLAG_D1DERR_Pos)) /* Assigment of value for D1DERR in the DRMTCM_INTFLAG register */
#define DRMTCM_INTFLAG_D1ECCECNT_Pos          _UINT32_(18)                                         /* (DRMTCM_INTFLAG) D1TCM ECC Error Count Flag Position */
#define DRMTCM_INTFLAG_D1ECCECNT_Msk          (_UINT32_(0x1) << DRMTCM_INTFLAG_D1ECCECNT_Pos)      /* (DRMTCM_INTFLAG) D1TCM ECC Error Count Flag Mask */
#define DRMTCM_INTFLAG_D1ECCECNT(value)       (DRMTCM_INTFLAG_D1ECCECNT_Msk & (_UINT32_(value) << DRMTCM_INTFLAG_D1ECCECNT_Pos)) /* Assigment of value for D1ECCECNT in the DRMTCM_INTFLAG register */
#define DRMTCM_INTFLAG_FLTCAP_Pos             _UINT32_(24)                                         /* (DRMTCM_INTFLAG) Fault Capture interrupt Position */
#define DRMTCM_INTFLAG_FLTCAP_Msk             (_UINT32_(0x1) << DRMTCM_INTFLAG_FLTCAP_Pos)         /* (DRMTCM_INTFLAG) Fault Capture interrupt Mask */
#define DRMTCM_INTFLAG_FLTCAP(value)          (DRMTCM_INTFLAG_FLTCAP_Msk & (_UINT32_(value) << DRMTCM_INTFLAG_FLTCAP_Pos)) /* Assigment of value for FLTCAP in the DRMTCM_INTFLAG register */
#define DRMTCM_INTFLAG_Msk                    _UINT32_(0x01070707)                                 /* (DRMTCM_INTFLAG) Register Mask  */


/* -------- DRMTCM_FLTCTRL : (DRMTCM Offset: 0x18) (R/W 32) FAULT INJECTION CONTROL REGISTER -------- */
#define DRMTCM_FLTCTRL_RESETVALUE             _UINT32_(0x00)                                       /*  (DRMTCM_FLTCTRL) FAULT INJECTION CONTROL REGISTER  Reset Value */

#define DRMTCM_FLTCTRL_FLTEN_Pos              _UINT32_(1)                                          /* (DRMTCM_FLTCTRL) Fault Injection Enabled Position */
#define DRMTCM_FLTCTRL_FLTEN_Msk              (_UINT32_(0x1) << DRMTCM_FLTCTRL_FLTEN_Pos)          /* (DRMTCM_FLTCTRL) Fault Injection Enabled Mask */
#define DRMTCM_FLTCTRL_FLTEN(value)           (DRMTCM_FLTCTRL_FLTEN_Msk & (_UINT32_(value) << DRMTCM_FLTCTRL_FLTEN_Pos)) /* Assigment of value for FLTEN in the DRMTCM_FLTCTRL register */
#define DRMTCM_FLTCTRL_FLTMD_Pos              _UINT32_(12)                                         /* (DRMTCM_FLTCTRL) Fault Mode Control Position */
#define DRMTCM_FLTCTRL_FLTMD_Msk              (_UINT32_(0x3) << DRMTCM_FLTCTRL_FLTMD_Pos)          /* (DRMTCM_FLTCTRL) Fault Mode Control Mask */
#define DRMTCM_FLTCTRL_FLTMD(value)           (DRMTCM_FLTCTRL_FLTMD_Msk & (_UINT32_(value) << DRMTCM_FLTCTRL_FLTMD_Pos)) /* Assigment of value for FLTMD in the DRMTCM_FLTCTRL register */
#define DRMTCM_FLTCTRL_Msk                    _UINT32_(0x00003002)                                 /* (DRMTCM_FLTCTRL) Register Mask  */


/* -------- DRMTCM_IFLTPTR : (DRMTCM Offset: 0x1C) (R/W 32) ITCM FAULT INJECTION POINTER REGISTER -------- */
#define DRMTCM_IFLTPTR_RESETVALUE             _UINT32_(0x00)                                       /*  (DRMTCM_IFLTPTR) ITCM FAULT INJECTION POINTER REGISTER  Reset Value */

#define DRMTCM_IFLTPTR_FLT1PTR_Pos            _UINT32_(0)                                          /* (DRMTCM_IFLTPTR) ECC Fault injection Bit position pointer (for single bit error). Position */
#define DRMTCM_IFLTPTR_FLT1PTR_Msk            (_UINT32_(0x7F) << DRMTCM_IFLTPTR_FLT1PTR_Pos)       /* (DRMTCM_IFLTPTR) ECC Fault injection Bit position pointer (for single bit error). Mask */
#define DRMTCM_IFLTPTR_FLT1PTR(value)         (DRMTCM_IFLTPTR_FLT1PTR_Msk & (_UINT32_(value) << DRMTCM_IFLTPTR_FLT1PTR_Pos)) /* Assigment of value for FLT1PTR in the DRMTCM_IFLTPTR register */
#define DRMTCM_IFLTPTR_FLT2PTR_Pos            _UINT32_(16)                                         /* (DRMTCM_IFLTPTR) ECC Fault injection Bit position pointer (for double bit error). Position */
#define DRMTCM_IFLTPTR_FLT2PTR_Msk            (_UINT32_(0x7F) << DRMTCM_IFLTPTR_FLT2PTR_Pos)       /* (DRMTCM_IFLTPTR) ECC Fault injection Bit position pointer (for double bit error). Mask */
#define DRMTCM_IFLTPTR_FLT2PTR(value)         (DRMTCM_IFLTPTR_FLT2PTR_Msk & (_UINT32_(value) << DRMTCM_IFLTPTR_FLT2PTR_Pos)) /* Assigment of value for FLT2PTR in the DRMTCM_IFLTPTR register */
#define DRMTCM_IFLTPTR_Msk                    _UINT32_(0x007F007F)                                 /* (DRMTCM_IFLTPTR) Register Mask  */


/* -------- DRMTCM_IFLTADR : (DRMTCM Offset: 0x20) (R/W 32) ITCM FAULT INJECTION ADDRESS REGISTER -------- */
#define DRMTCM_IFLTADR_RESETVALUE             _UINT32_(0x00)                                       /*  (DRMTCM_IFLTADR) ITCM FAULT INJECTION ADDRESS REGISTER  Reset Value */

#define DRMTCM_IFLTADR_IFLTADR_Pos            _UINT32_(0)                                          /* (DRMTCM_IFLTADR) Instruction ITCM ECC Fault Injection, Address Match Com-pare bits. Position */
#define DRMTCM_IFLTADR_IFLTADR_Msk            (_UINT32_(0x1FFFF) << DRMTCM_IFLTADR_IFLTADR_Pos)    /* (DRMTCM_IFLTADR) Instruction ITCM ECC Fault Injection, Address Match Com-pare bits. Mask */
#define DRMTCM_IFLTADR_IFLTADR(value)         (DRMTCM_IFLTADR_IFLTADR_Msk & (_UINT32_(value) << DRMTCM_IFLTADR_IFLTADR_Pos)) /* Assigment of value for IFLTADR in the DRMTCM_IFLTADR register */
#define DRMTCM_IFLTADR_Msk                    _UINT32_(0x0001FFFF)                                 /* (DRMTCM_IFLTADR) Register Mask  */


/* -------- DRMTCM_IFLTCAP : (DRMTCM Offset: 0x24) ( R/ 32) ITCM FAULT ERROR CAPTURE ADDRESS REGISTER -------- */
#define DRMTCM_IFLTCAP_RESETVALUE             _UINT32_(0x00)                                       /*  (DRMTCM_IFLTCAP) ITCM FAULT ERROR CAPTURE ADDRESS REGISTER  Reset Value */

#define DRMTCM_IFLTCAP_FLTADR_Pos             _UINT32_(0)                                          /* (DRMTCM_IFLTCAP) Instruction TCM ECC Fault Address bits which caused the ECC Error. Position */
#define DRMTCM_IFLTCAP_FLTADR_Msk             (_UINT32_(0x1FFFF) << DRMTCM_IFLTCAP_FLTADR_Pos)     /* (DRMTCM_IFLTCAP) Instruction TCM ECC Fault Address bits which caused the ECC Error. Mask */
#define DRMTCM_IFLTCAP_FLTADR(value)          (DRMTCM_IFLTCAP_FLTADR_Msk & (_UINT32_(value) << DRMTCM_IFLTCAP_FLTADR_Pos)) /* Assigment of value for FLTADR in the DRMTCM_IFLTCAP register */
#define DRMTCM_IFLTCAP_ITCMMASTER_Pos         _UINT32_(28)                                         /* (DRMTCM_IFLTCAP) Master ID of the requester of the current Error access. Position */
#define DRMTCM_IFLTCAP_ITCMMASTER_Msk         (_UINT32_(0xF) << DRMTCM_IFLTCAP_ITCMMASTER_Pos)     /* (DRMTCM_IFLTCAP) Master ID of the requester of the current Error access. Mask */
#define DRMTCM_IFLTCAP_ITCMMASTER(value)      (DRMTCM_IFLTCAP_ITCMMASTER_Msk & (_UINT32_(value) << DRMTCM_IFLTCAP_ITCMMASTER_Pos)) /* Assigment of value for ITCMMASTER in the DRMTCM_IFLTCAP register */
#define DRMTCM_IFLTCAP_Msk                    _UINT32_(0xF001FFFF)                                 /* (DRMTCM_IFLTCAP) Register Mask  */


/* -------- DRMTCM_IFLTPAR : (DRMTCM Offset: 0x28) ( R/ 32) ITCM FAULT PARITY REGISTER -------- */
#define DRMTCM_IFLTPAR_RESETVALUE             _UINT32_(0x00)                                       /*  (DRMTCM_IFLTPAR) ITCM FAULT PARITY REGISTER  Reset Value */

#define DRMTCM_IFLTPAR_SECIN_Pos              _UINT32_(0)                                          /* (DRMTCM_IFLTPAR) Single Error Parity Bits from ITCM Position */
#define DRMTCM_IFLTPAR_SECIN_Msk              (_UINT32_(0xFF) << DRMTCM_IFLTPAR_SECIN_Pos)         /* (DRMTCM_IFLTPAR) Single Error Parity Bits from ITCM Mask */
#define DRMTCM_IFLTPAR_SECIN(value)           (DRMTCM_IFLTPAR_SECIN_Msk & (_UINT32_(value) << DRMTCM_IFLTPAR_SECIN_Pos)) /* Assigment of value for SECIN in the DRMTCM_IFLTPAR register */
#define DRMTCM_IFLTPAR_Msk                    _UINT32_(0x000000FF)                                 /* (DRMTCM_IFLTPAR) Register Mask  */


/* -------- DRMTCM_IFLTSYN : (DRMTCM Offset: 0x2C) ( R/ 32) ITCM FAULT ECC SYNDROME REGISTER -------- */
#define DRMTCM_IFLTSYN_RESETVALUE             _UINT32_(0x00)                                       /*  (DRMTCM_IFLTSYN) ITCM FAULT ECC SYNDROME REGISTER  Reset Value */

#define DRMTCM_IFLTSYN_SECSYN_Pos             _UINT32_(0)                                          /* (DRMTCM_IFLTSYN) Single Error Syndrome Position */
#define DRMTCM_IFLTSYN_SECSYN_Msk             (_UINT32_(0xFF) << DRMTCM_IFLTSYN_SECSYN_Pos)        /* (DRMTCM_IFLTSYN) Single Error Syndrome Mask */
#define DRMTCM_IFLTSYN_SECSYN(value)          (DRMTCM_IFLTSYN_SECSYN_Msk & (_UINT32_(value) << DRMTCM_IFLTSYN_SECSYN_Pos)) /* Assigment of value for SECSYN in the DRMTCM_IFLTSYN register */
#define DRMTCM_IFLTSYN_ERR1_Pos               _UINT32_(14)                                         /* (DRMTCM_IFLTSYN) Single Bit Error Position */
#define DRMTCM_IFLTSYN_ERR1_Msk               (_UINT32_(0x1) << DRMTCM_IFLTSYN_ERR1_Pos)           /* (DRMTCM_IFLTSYN) Single Bit Error Mask */
#define DRMTCM_IFLTSYN_ERR1(value)            (DRMTCM_IFLTSYN_ERR1_Msk & (_UINT32_(value) << DRMTCM_IFLTSYN_ERR1_Pos)) /* Assigment of value for ERR1 in the DRMTCM_IFLTSYN register */
#define DRMTCM_IFLTSYN_ERR2_Pos               _UINT32_(15)                                         /* (DRMTCM_IFLTSYN) Double bit Error Position */
#define DRMTCM_IFLTSYN_ERR2_Msk               (_UINT32_(0x1) << DRMTCM_IFLTSYN_ERR2_Pos)           /* (DRMTCM_IFLTSYN) Double bit Error Mask */
#define DRMTCM_IFLTSYN_ERR2(value)            (DRMTCM_IFLTSYN_ERR2_Msk & (_UINT32_(value) << DRMTCM_IFLTSYN_ERR2_Pos)) /* Assigment of value for ERR2 in the DRMTCM_IFLTSYN register */
#define DRMTCM_IFLTSYN_Msk                    _UINT32_(0x0000C0FF)                                 /* (DRMTCM_IFLTSYN) Register Mask  */

#define DRMTCM_IFLTSYN_ERR_Pos                _UINT32_(14)                                         /* (DRMTCM_IFLTSYN Position) Double bit Error */
#define DRMTCM_IFLTSYN_ERR_Msk                (_UINT32_(0x3) << DRMTCM_IFLTSYN_ERR_Pos)            /* (DRMTCM_IFLTSYN Mask) ERR */
#define DRMTCM_IFLTSYN_ERR(value)             (DRMTCM_IFLTSYN_ERR_Msk & (_UINT32_(value) << DRMTCM_IFLTSYN_ERR_Pos)) 

/* -------- DRMTCM_DFLTPTR : (DRMTCM Offset: 0x30) (R/W 32) DTCM FAULT INJECTION POINTER REGISTER -------- */
#define DRMTCM_DFLTPTR_RESETVALUE             _UINT32_(0x00)                                       /*  (DRMTCM_DFLTPTR) DTCM FAULT INJECTION POINTER REGISTER  Reset Value */

#define DRMTCM_DFLTPTR_FLT1PTR_Pos            _UINT32_(0)                                          /* (DRMTCM_DFLTPTR) ECC Fault injection Bit position pointer (for single bit error). Position */
#define DRMTCM_DFLTPTR_FLT1PTR_Msk            (_UINT32_(0x3F) << DRMTCM_DFLTPTR_FLT1PTR_Pos)       /* (DRMTCM_DFLTPTR) ECC Fault injection Bit position pointer (for single bit error). Mask */
#define DRMTCM_DFLTPTR_FLT1PTR(value)         (DRMTCM_DFLTPTR_FLT1PTR_Msk & (_UINT32_(value) << DRMTCM_DFLTPTR_FLT1PTR_Pos)) /* Assigment of value for FLT1PTR in the DRMTCM_DFLTPTR register */
#define DRMTCM_DFLTPTR_FLT2PTR_Pos            _UINT32_(16)                                         /* (DRMTCM_DFLTPTR) ECC Fault injection Bit position pointer (for double bit error). Position */
#define DRMTCM_DFLTPTR_FLT2PTR_Msk            (_UINT32_(0x3F) << DRMTCM_DFLTPTR_FLT2PTR_Pos)       /* (DRMTCM_DFLTPTR) ECC Fault injection Bit position pointer (for double bit error). Mask */
#define DRMTCM_DFLTPTR_FLT2PTR(value)         (DRMTCM_DFLTPTR_FLT2PTR_Msk & (_UINT32_(value) << DRMTCM_DFLTPTR_FLT2PTR_Pos)) /* Assigment of value for FLT2PTR in the DRMTCM_DFLTPTR register */
#define DRMTCM_DFLTPTR_Msk                    _UINT32_(0x003F003F)                                 /* (DRMTCM_DFLTPTR) Register Mask  */


/* -------- DRMTCM_DFLTADR : (DRMTCM Offset: 0x34) (R/W 32) DTCM FAULT INJECTION ADDRESS REGISTER -------- */
#define DRMTCM_DFLTADR_RESETVALUE             _UINT32_(0x00)                                       /*  (DRMTCM_DFLTADR) DTCM FAULT INJECTION ADDRESS REGISTER  Reset Value */

#define DRMTCM_DFLTADR_FLTADR_Pos             _UINT32_(0)                                          /* (DRMTCM_DFLTADR) Data TCM ECC Fault Injection, Address Match Compare bits. Position */
#define DRMTCM_DFLTADR_FLTADR_Msk             (_UINT32_(0x1FFFF) << DRMTCM_DFLTADR_FLTADR_Pos)     /* (DRMTCM_DFLTADR) Data TCM ECC Fault Injection, Address Match Compare bits. Mask */
#define DRMTCM_DFLTADR_FLTADR(value)          (DRMTCM_DFLTADR_FLTADR_Msk & (_UINT32_(value) << DRMTCM_DFLTADR_FLTADR_Pos)) /* Assigment of value for FLTADR in the DRMTCM_DFLTADR register */
#define DRMTCM_DFLTADR_D1D0EN_Pos             _UINT32_(31)                                         /* (DRMTCM_DFLTADR) Fault Injection D1 or D0 Address Enable. Position */
#define DRMTCM_DFLTADR_D1D0EN_Msk             (_UINT32_(0x1) << DRMTCM_DFLTADR_D1D0EN_Pos)         /* (DRMTCM_DFLTADR) Fault Injection D1 or D0 Address Enable. Mask */
#define DRMTCM_DFLTADR_D1D0EN(value)          (DRMTCM_DFLTADR_D1D0EN_Msk & (_UINT32_(value) << DRMTCM_DFLTADR_D1D0EN_Pos)) /* Assigment of value for D1D0EN in the DRMTCM_DFLTADR register */
#define DRMTCM_DFLTADR_Msk                    _UINT32_(0x8001FFFF)                                 /* (DRMTCM_DFLTADR) Register Mask  */


/* -------- DRMTCM_D0FLTCAP : (DRMTCM Offset: 0x38) ( R/ 32) D0TCM FAULT ERROR CAPTURE ADDRESS REGISTER -------- */
#define DRMTCM_D0FLTCAP_RESETVALUE            _UINT32_(0x00)                                       /*  (DRMTCM_D0FLTCAP) D0TCM FAULT ERROR CAPTURE ADDRESS REGISTER  Reset Value */

#define DRMTCM_D0FLTCAP_FLTADR_Pos            _UINT32_(0)                                          /* (DRMTCM_D0FLTCAP) Data 0 TCM ECC Fault Address bits which caused the ECC Error. Position */
#define DRMTCM_D0FLTCAP_FLTADR_Msk            (_UINT32_(0x1FFFF) << DRMTCM_D0FLTCAP_FLTADR_Pos)    /* (DRMTCM_D0FLTCAP) Data 0 TCM ECC Fault Address bits which caused the ECC Error. Mask */
#define DRMTCM_D0FLTCAP_FLTADR(value)         (DRMTCM_D0FLTCAP_FLTADR_Msk & (_UINT32_(value) << DRMTCM_D0FLTCAP_FLTADR_Pos)) /* Assigment of value for FLTADR in the DRMTCM_D0FLTCAP register */
#define DRMTCM_D0FLTCAP_TCMMASTER_Pos         _UINT32_(28)                                         /* (DRMTCM_D0FLTCAP) Master ID of the requester of the current Error access. Position */
#define DRMTCM_D0FLTCAP_TCMMASTER_Msk         (_UINT32_(0xF) << DRMTCM_D0FLTCAP_TCMMASTER_Pos)     /* (DRMTCM_D0FLTCAP) Master ID of the requester of the current Error access. Mask */
#define DRMTCM_D0FLTCAP_TCMMASTER(value)      (DRMTCM_D0FLTCAP_TCMMASTER_Msk & (_UINT32_(value) << DRMTCM_D0FLTCAP_TCMMASTER_Pos)) /* Assigment of value for TCMMASTER in the DRMTCM_D0FLTCAP register */
#define DRMTCM_D0FLTCAP_Msk                   _UINT32_(0xF001FFFF)                                 /* (DRMTCM_D0FLTCAP) Register Mask  */


/* -------- DRMTCM_D0FLTPAR : (DRMTCM Offset: 0x3C) ( R/ 32) D0TCM FAULT PARITY REGISTER -------- */
#define DRMTCM_D0FLTPAR_RESETVALUE            _UINT32_(0x00)                                       /*  (DRMTCM_D0FLTPAR) D0TCM FAULT PARITY REGISTER  Reset Value */

#define DRMTCM_D0FLTPAR_SECIN_Pos             _UINT32_(0)                                          /* (DRMTCM_D0FLTPAR) Single Error Parity Bits from D0TCM Position */
#define DRMTCM_D0FLTPAR_SECIN_Msk             (_UINT32_(0x7F) << DRMTCM_D0FLTPAR_SECIN_Pos)        /* (DRMTCM_D0FLTPAR) Single Error Parity Bits from D0TCM Mask */
#define DRMTCM_D0FLTPAR_SECIN(value)          (DRMTCM_D0FLTPAR_SECIN_Msk & (_UINT32_(value) << DRMTCM_D0FLTPAR_SECIN_Pos)) /* Assigment of value for SECIN in the DRMTCM_D0FLTPAR register */
#define DRMTCM_D0FLTPAR_Msk                   _UINT32_(0x0000007F)                                 /* (DRMTCM_D0FLTPAR) Register Mask  */


/* -------- DRMTCM_D0FLTSYN : (DRMTCM Offset: 0x40) ( R/ 32) D0TCM FAULT ECC SYNDROME REGISTER -------- */
#define DRMTCM_D0FLTSYN_RESETVALUE            _UINT32_(0x00)                                       /*  (DRMTCM_D0FLTSYN) D0TCM FAULT ECC SYNDROME REGISTER  Reset Value */

#define DRMTCM_D0FLTSYN_SECSYN_Pos            _UINT32_(0)                                          /* (DRMTCM_D0FLTSYN) Single Error Syndrome Position */
#define DRMTCM_D0FLTSYN_SECSYN_Msk            (_UINT32_(0x7F) << DRMTCM_D0FLTSYN_SECSYN_Pos)       /* (DRMTCM_D0FLTSYN) Single Error Syndrome Mask */
#define DRMTCM_D0FLTSYN_SECSYN(value)         (DRMTCM_D0FLTSYN_SECSYN_Msk & (_UINT32_(value) << DRMTCM_D0FLTSYN_SECSYN_Pos)) /* Assigment of value for SECSYN in the DRMTCM_D0FLTSYN register */
#define DRMTCM_D0FLTSYN_ERR1_Pos              _UINT32_(14)                                         /* (DRMTCM_D0FLTSYN) Single Bit Error Position */
#define DRMTCM_D0FLTSYN_ERR1_Msk              (_UINT32_(0x1) << DRMTCM_D0FLTSYN_ERR1_Pos)          /* (DRMTCM_D0FLTSYN) Single Bit Error Mask */
#define DRMTCM_D0FLTSYN_ERR1(value)           (DRMTCM_D0FLTSYN_ERR1_Msk & (_UINT32_(value) << DRMTCM_D0FLTSYN_ERR1_Pos)) /* Assigment of value for ERR1 in the DRMTCM_D0FLTSYN register */
#define DRMTCM_D0FLTSYN_ERR2_Pos              _UINT32_(15)                                         /* (DRMTCM_D0FLTSYN) Double bit Error Position */
#define DRMTCM_D0FLTSYN_ERR2_Msk              (_UINT32_(0x1) << DRMTCM_D0FLTSYN_ERR2_Pos)          /* (DRMTCM_D0FLTSYN) Double bit Error Mask */
#define DRMTCM_D0FLTSYN_ERR2(value)           (DRMTCM_D0FLTSYN_ERR2_Msk & (_UINT32_(value) << DRMTCM_D0FLTSYN_ERR2_Pos)) /* Assigment of value for ERR2 in the DRMTCM_D0FLTSYN register */
#define DRMTCM_D0FLTSYN_Msk                   _UINT32_(0x0000C07F)                                 /* (DRMTCM_D0FLTSYN) Register Mask  */

#define DRMTCM_D0FLTSYN_ERR_Pos               _UINT32_(14)                                         /* (DRMTCM_D0FLTSYN Position) Double bit Error */
#define DRMTCM_D0FLTSYN_ERR_Msk               (_UINT32_(0x3) << DRMTCM_D0FLTSYN_ERR_Pos)           /* (DRMTCM_D0FLTSYN Mask) ERR */
#define DRMTCM_D0FLTSYN_ERR(value)            (DRMTCM_D0FLTSYN_ERR_Msk & (_UINT32_(value) << DRMTCM_D0FLTSYN_ERR_Pos)) 

/* -------- DRMTCM_D1FLTCAP : (DRMTCM Offset: 0x44) ( R/ 32) D1TCM FAULT ERROR CAPTURE ADDRESS REGISTER -------- */
#define DRMTCM_D1FLTCAP_RESETVALUE            _UINT32_(0x00)                                       /*  (DRMTCM_D1FLTCAP) D1TCM FAULT ERROR CAPTURE ADDRESS REGISTER  Reset Value */

#define DRMTCM_D1FLTCAP_FLTADR_Pos            _UINT32_(0)                                          /* (DRMTCM_D1FLTCAP) Data 1 TCM ECC Fault Address bits which caused the ECC Error. Position */
#define DRMTCM_D1FLTCAP_FLTADR_Msk            (_UINT32_(0x1FFFF) << DRMTCM_D1FLTCAP_FLTADR_Pos)    /* (DRMTCM_D1FLTCAP) Data 1 TCM ECC Fault Address bits which caused the ECC Error. Mask */
#define DRMTCM_D1FLTCAP_FLTADR(value)         (DRMTCM_D1FLTCAP_FLTADR_Msk & (_UINT32_(value) << DRMTCM_D1FLTCAP_FLTADR_Pos)) /* Assigment of value for FLTADR in the DRMTCM_D1FLTCAP register */
#define DRMTCM_D1FLTCAP_D1TCMMASTER_Pos       _UINT32_(28)                                         /* (DRMTCM_D1FLTCAP) Master ID of the requester of the current Error access. Position */
#define DRMTCM_D1FLTCAP_D1TCMMASTER_Msk       (_UINT32_(0xF) << DRMTCM_D1FLTCAP_D1TCMMASTER_Pos)   /* (DRMTCM_D1FLTCAP) Master ID of the requester of the current Error access. Mask */
#define DRMTCM_D1FLTCAP_D1TCMMASTER(value)    (DRMTCM_D1FLTCAP_D1TCMMASTER_Msk & (_UINT32_(value) << DRMTCM_D1FLTCAP_D1TCMMASTER_Pos)) /* Assigment of value for D1TCMMASTER in the DRMTCM_D1FLTCAP register */
#define DRMTCM_D1FLTCAP_Msk                   _UINT32_(0xF001FFFF)                                 /* (DRMTCM_D1FLTCAP) Register Mask  */


/* -------- DRMTCM_D1FLTPAR : (DRMTCM Offset: 0x48) ( R/ 32) D1TCM FAULT PARITY REGISTER -------- */
#define DRMTCM_D1FLTPAR_RESETVALUE            _UINT32_(0x00)                                       /*  (DRMTCM_D1FLTPAR) D1TCM FAULT PARITY REGISTER  Reset Value */

#define DRMTCM_D1FLTPAR_SECIN_Pos             _UINT32_(0)                                          /* (DRMTCM_D1FLTPAR) Single Error Parity Bits from D1TCM Position */
#define DRMTCM_D1FLTPAR_SECIN_Msk             (_UINT32_(0x7F) << DRMTCM_D1FLTPAR_SECIN_Pos)        /* (DRMTCM_D1FLTPAR) Single Error Parity Bits from D1TCM Mask */
#define DRMTCM_D1FLTPAR_SECIN(value)          (DRMTCM_D1FLTPAR_SECIN_Msk & (_UINT32_(value) << DRMTCM_D1FLTPAR_SECIN_Pos)) /* Assigment of value for SECIN in the DRMTCM_D1FLTPAR register */
#define DRMTCM_D1FLTPAR_Msk                   _UINT32_(0x0000007F)                                 /* (DRMTCM_D1FLTPAR) Register Mask  */


/* -------- DRMTCM_D1FLTSYN : (DRMTCM Offset: 0x4C) ( R/ 32) D1TCM FAULT ECC SYNDROME REGISTER -------- */
#define DRMTCM_D1FLTSYN_RESETVALUE            _UINT32_(0x00)                                       /*  (DRMTCM_D1FLTSYN) D1TCM FAULT ECC SYNDROME REGISTER  Reset Value */

#define DRMTCM_D1FLTSYN_SECSYN_Pos            _UINT32_(0)                                          /* (DRMTCM_D1FLTSYN) Single Error Syndrome Position */
#define DRMTCM_D1FLTSYN_SECSYN_Msk            (_UINT32_(0x7F) << DRMTCM_D1FLTSYN_SECSYN_Pos)       /* (DRMTCM_D1FLTSYN) Single Error Syndrome Mask */
#define DRMTCM_D1FLTSYN_SECSYN(value)         (DRMTCM_D1FLTSYN_SECSYN_Msk & (_UINT32_(value) << DRMTCM_D1FLTSYN_SECSYN_Pos)) /* Assigment of value for SECSYN in the DRMTCM_D1FLTSYN register */
#define DRMTCM_D1FLTSYN_ERR1_Pos              _UINT32_(14)                                         /* (DRMTCM_D1FLTSYN) Single Bit Error Position */
#define DRMTCM_D1FLTSYN_ERR1_Msk              (_UINT32_(0x1) << DRMTCM_D1FLTSYN_ERR1_Pos)          /* (DRMTCM_D1FLTSYN) Single Bit Error Mask */
#define DRMTCM_D1FLTSYN_ERR1(value)           (DRMTCM_D1FLTSYN_ERR1_Msk & (_UINT32_(value) << DRMTCM_D1FLTSYN_ERR1_Pos)) /* Assigment of value for ERR1 in the DRMTCM_D1FLTSYN register */
#define DRMTCM_D1FLTSYN_ERR2_Pos              _UINT32_(15)                                         /* (DRMTCM_D1FLTSYN) Double bit Error Position */
#define DRMTCM_D1FLTSYN_ERR2_Msk              (_UINT32_(0x1) << DRMTCM_D1FLTSYN_ERR2_Pos)          /* (DRMTCM_D1FLTSYN) Double bit Error Mask */
#define DRMTCM_D1FLTSYN_ERR2(value)           (DRMTCM_D1FLTSYN_ERR2_Msk & (_UINT32_(value) << DRMTCM_D1FLTSYN_ERR2_Pos)) /* Assigment of value for ERR2 in the DRMTCM_D1FLTSYN register */
#define DRMTCM_D1FLTSYN_Msk                   _UINT32_(0x0000C07F)                                 /* (DRMTCM_D1FLTSYN) Register Mask  */

#define DRMTCM_D1FLTSYN_ERR_Pos               _UINT32_(14)                                         /* (DRMTCM_D1FLTSYN Position) Double bit Error */
#define DRMTCM_D1FLTSYN_ERR_Msk               (_UINT32_(0x3) << DRMTCM_D1FLTSYN_ERR_Pos)           /* (DRMTCM_D1FLTSYN Mask) ERR */
#define DRMTCM_D1FLTSYN_ERR(value)            (DRMTCM_D1FLTSYN_ERR_Msk & (_UINT32_(value) << DRMTCM_D1FLTSYN_ERR_Pos)) 

/** \brief DRMTCM register offsets definitions */
#define DRMTCM_CTRLA_REG_OFST          _UINT32_(0x00)      /* (DRMTCM_CTRLA) CONTROL ENABLE REGISTER A Offset */
#define DRMTCM_CTRLB_REG_OFST          _UINT32_(0x04)      /* (DRMTCM_CTRLB) CONTROL ENABLE REGISTER B Offset */
#define DRMTCM_SYNCBUSY_REG_OFST       _UINT32_(0x08)      /* (DRMTCM_SYNCBUSY) SYNC BUSY REGISTER Offset */
#define DRMTCM_INTENCLR_REG_OFST       _UINT32_(0x0C)      /* (DRMTCM_INTENCLR) INTERRUPT ENABLE CLR REGISTER Offset */
#define DRMTCM_INTENSET_REG_OFST       _UINT32_(0x10)      /* (DRMTCM_INTENSET) INTERRUPT ENABLE SET REGISTER Offset */
#define DRMTCM_INTFLAG_REG_OFST        _UINT32_(0x14)      /* (DRMTCM_INTFLAG) INTERRUPT FLAG REGISTER Offset */
#define DRMTCM_FLTCTRL_REG_OFST        _UINT32_(0x18)      /* (DRMTCM_FLTCTRL) FAULT INJECTION CONTROL REGISTER Offset */
#define DRMTCM_IFLTPTR_REG_OFST        _UINT32_(0x1C)      /* (DRMTCM_IFLTPTR) ITCM FAULT INJECTION POINTER REGISTER Offset */
#define DRMTCM_IFLTADR_REG_OFST        _UINT32_(0x20)      /* (DRMTCM_IFLTADR) ITCM FAULT INJECTION ADDRESS REGISTER Offset */
#define DRMTCM_IFLTCAP_REG_OFST        _UINT32_(0x24)      /* (DRMTCM_IFLTCAP) ITCM FAULT ERROR CAPTURE ADDRESS REGISTER Offset */
#define DRMTCM_IFLTPAR_REG_OFST        _UINT32_(0x28)      /* (DRMTCM_IFLTPAR) ITCM FAULT PARITY REGISTER Offset */
#define DRMTCM_IFLTSYN_REG_OFST        _UINT32_(0x2C)      /* (DRMTCM_IFLTSYN) ITCM FAULT ECC SYNDROME REGISTER Offset */
#define DRMTCM_DFLTPTR_REG_OFST        _UINT32_(0x30)      /* (DRMTCM_DFLTPTR) DTCM FAULT INJECTION POINTER REGISTER Offset */
#define DRMTCM_DFLTADR_REG_OFST        _UINT32_(0x34)      /* (DRMTCM_DFLTADR) DTCM FAULT INJECTION ADDRESS REGISTER Offset */
#define DRMTCM_D0FLTCAP_REG_OFST       _UINT32_(0x38)      /* (DRMTCM_D0FLTCAP) D0TCM FAULT ERROR CAPTURE ADDRESS REGISTER Offset */
#define DRMTCM_D0FLTPAR_REG_OFST       _UINT32_(0x3C)      /* (DRMTCM_D0FLTPAR) D0TCM FAULT PARITY REGISTER Offset */
#define DRMTCM_D0FLTSYN_REG_OFST       _UINT32_(0x40)      /* (DRMTCM_D0FLTSYN) D0TCM FAULT ECC SYNDROME REGISTER Offset */
#define DRMTCM_D1FLTCAP_REG_OFST       _UINT32_(0x44)      /* (DRMTCM_D1FLTCAP) D1TCM FAULT ERROR CAPTURE ADDRESS REGISTER Offset */
#define DRMTCM_D1FLTPAR_REG_OFST       _UINT32_(0x48)      /* (DRMTCM_D1FLTPAR) D1TCM FAULT PARITY REGISTER Offset */
#define DRMTCM_D1FLTSYN_REG_OFST       _UINT32_(0x4C)      /* (DRMTCM_D1FLTSYN) D1TCM FAULT ECC SYNDROME REGISTER Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief DRMTCM register API structure */
typedef struct
{  /* DRM TCM ECC */
  __IO  uint32_t                       DRMTCM_CTRLA;       /**< Offset: 0x00 (R/W  32) CONTROL ENABLE REGISTER A */
  __IO  uint32_t                       DRMTCM_CTRLB;       /**< Offset: 0x04 (R/W  32) CONTROL ENABLE REGISTER B */
  __I   uint32_t                       DRMTCM_SYNCBUSY;    /**< Offset: 0x08 (R/   32) SYNC BUSY REGISTER */
  __IO  uint32_t                       DRMTCM_INTENCLR;    /**< Offset: 0x0C (R/W  32) INTERRUPT ENABLE CLR REGISTER */
  __IO  uint32_t                       DRMTCM_INTENSET;    /**< Offset: 0x10 (R/W  32) INTERRUPT ENABLE SET REGISTER */
  __IO  uint32_t                       DRMTCM_INTFLAG;     /**< Offset: 0x14 (R/W  32) INTERRUPT FLAG REGISTER */
  __IO  uint32_t                       DRMTCM_FLTCTRL;     /**< Offset: 0x18 (R/W  32) FAULT INJECTION CONTROL REGISTER */
  __IO  uint32_t                       DRMTCM_IFLTPTR;     /**< Offset: 0x1C (R/W  32) ITCM FAULT INJECTION POINTER REGISTER */
  __IO  uint32_t                       DRMTCM_IFLTADR;     /**< Offset: 0x20 (R/W  32) ITCM FAULT INJECTION ADDRESS REGISTER */
  __I   uint32_t                       DRMTCM_IFLTCAP;     /**< Offset: 0x24 (R/   32) ITCM FAULT ERROR CAPTURE ADDRESS REGISTER */
  __I   uint32_t                       DRMTCM_IFLTPAR;     /**< Offset: 0x28 (R/   32) ITCM FAULT PARITY REGISTER */
  __I   uint32_t                       DRMTCM_IFLTSYN;     /**< Offset: 0x2C (R/   32) ITCM FAULT ECC SYNDROME REGISTER */
  __IO  uint32_t                       DRMTCM_DFLTPTR;     /**< Offset: 0x30 (R/W  32) DTCM FAULT INJECTION POINTER REGISTER */
  __IO  uint32_t                       DRMTCM_DFLTADR;     /**< Offset: 0x34 (R/W  32) DTCM FAULT INJECTION ADDRESS REGISTER */
  __I   uint32_t                       DRMTCM_D0FLTCAP;    /**< Offset: 0x38 (R/   32) D0TCM FAULT ERROR CAPTURE ADDRESS REGISTER */
  __I   uint32_t                       DRMTCM_D0FLTPAR;    /**< Offset: 0x3C (R/   32) D0TCM FAULT PARITY REGISTER */
  __I   uint32_t                       DRMTCM_D0FLTSYN;    /**< Offset: 0x40 (R/   32) D0TCM FAULT ECC SYNDROME REGISTER */
  __I   uint32_t                       DRMTCM_D1FLTCAP;    /**< Offset: 0x44 (R/   32) D1TCM FAULT ERROR CAPTURE ADDRESS REGISTER */
  __I   uint32_t                       DRMTCM_D1FLTPAR;    /**< Offset: 0x48 (R/   32) D1TCM FAULT PARITY REGISTER */
  __I   uint32_t                       DRMTCM_D1FLTSYN;    /**< Offset: 0x4C (R/   32) D1TCM FAULT ECC SYNDROME REGISTER */
} drmtcm_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA80_DRMTCM_COMPONENT_H_ */
