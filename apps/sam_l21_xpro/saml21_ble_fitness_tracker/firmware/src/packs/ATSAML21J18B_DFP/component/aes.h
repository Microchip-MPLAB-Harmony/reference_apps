/*
 * Component description for AES
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

/* file generated from device description version 2021-06-07T06:15:05Z */
#ifndef _SAML21_AES_COMPONENT_H_
#define _SAML21_AES_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR AES                                          */
/* ************************************************************************** */

/* -------- AES_CTRLA : (AES Offset: 0x00) (R/W 32) Control A -------- */
#define AES_CTRLA_RESETVALUE                  _UINT32_(0x00)                                       /*  (AES_CTRLA) Control A  Reset Value */

#define AES_CTRLA_SWRST_Pos                   _UINT32_(0)                                          /* (AES_CTRLA) Software Reset Position */
#define AES_CTRLA_SWRST_Msk                   (_UINT32_(0x1) << AES_CTRLA_SWRST_Pos)               /* (AES_CTRLA) Software Reset Mask */
#define AES_CTRLA_SWRST(value)                (AES_CTRLA_SWRST_Msk & (_UINT32_(value) << AES_CTRLA_SWRST_Pos)) /* Assigment of value for SWRST in the AES_CTRLA register */
#define AES_CTRLA_ENABLE_Pos                  _UINT32_(1)                                          /* (AES_CTRLA) Enable Position */
#define AES_CTRLA_ENABLE_Msk                  (_UINT32_(0x1) << AES_CTRLA_ENABLE_Pos)              /* (AES_CTRLA) Enable Mask */
#define AES_CTRLA_ENABLE(value)               (AES_CTRLA_ENABLE_Msk & (_UINT32_(value) << AES_CTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the AES_CTRLA register */
#define AES_CTRLA_AESMODE_Pos                 _UINT32_(2)                                          /* (AES_CTRLA) AES Modes of operation Position */
#define AES_CTRLA_AESMODE_Msk                 (_UINT32_(0x7) << AES_CTRLA_AESMODE_Pos)             /* (AES_CTRLA) AES Modes of operation Mask */
#define AES_CTRLA_AESMODE(value)              (AES_CTRLA_AESMODE_Msk & (_UINT32_(value) << AES_CTRLA_AESMODE_Pos)) /* Assigment of value for AESMODE in the AES_CTRLA register */
#define AES_CTRLA_CFBS_Pos                    _UINT32_(5)                                          /* (AES_CTRLA) CFB Types Position */
#define AES_CTRLA_CFBS_Msk                    (_UINT32_(0x7) << AES_CTRLA_CFBS_Pos)                /* (AES_CTRLA) CFB Types Mask */
#define AES_CTRLA_CFBS(value)                 (AES_CTRLA_CFBS_Msk & (_UINT32_(value) << AES_CTRLA_CFBS_Pos)) /* Assigment of value for CFBS in the AES_CTRLA register */
#define AES_CTRLA_KEYSIZE_Pos                 _UINT32_(8)                                          /* (AES_CTRLA) Keysize Position */
#define AES_CTRLA_KEYSIZE_Msk                 (_UINT32_(0x3) << AES_CTRLA_KEYSIZE_Pos)             /* (AES_CTRLA) Keysize Mask */
#define AES_CTRLA_KEYSIZE(value)              (AES_CTRLA_KEYSIZE_Msk & (_UINT32_(value) << AES_CTRLA_KEYSIZE_Pos)) /* Assigment of value for KEYSIZE in the AES_CTRLA register */
#define AES_CTRLA_CIPHER_Pos                  _UINT32_(10)                                         /* (AES_CTRLA) Cipher mode Position */
#define AES_CTRLA_CIPHER_Msk                  (_UINT32_(0x1) << AES_CTRLA_CIPHER_Pos)              /* (AES_CTRLA) Cipher mode Mask */
#define AES_CTRLA_CIPHER(value)               (AES_CTRLA_CIPHER_Msk & (_UINT32_(value) << AES_CTRLA_CIPHER_Pos)) /* Assigment of value for CIPHER in the AES_CTRLA register */
#define AES_CTRLA_STARTMODE_Pos               _UINT32_(11)                                         /* (AES_CTRLA) Start mode Position */
#define AES_CTRLA_STARTMODE_Msk               (_UINT32_(0x1) << AES_CTRLA_STARTMODE_Pos)           /* (AES_CTRLA) Start mode Mask */
#define AES_CTRLA_STARTMODE(value)            (AES_CTRLA_STARTMODE_Msk & (_UINT32_(value) << AES_CTRLA_STARTMODE_Pos)) /* Assigment of value for STARTMODE in the AES_CTRLA register */
#define AES_CTRLA_LOD_Pos                     _UINT32_(12)                                         /* (AES_CTRLA) LOD Enable Position */
#define AES_CTRLA_LOD_Msk                     (_UINT32_(0x1) << AES_CTRLA_LOD_Pos)                 /* (AES_CTRLA) LOD Enable Mask */
#define AES_CTRLA_LOD(value)                  (AES_CTRLA_LOD_Msk & (_UINT32_(value) << AES_CTRLA_LOD_Pos)) /* Assigment of value for LOD in the AES_CTRLA register */
#define AES_CTRLA_KEYGEN_Pos                  _UINT32_(13)                                         /* (AES_CTRLA) Last key generation Position */
#define AES_CTRLA_KEYGEN_Msk                  (_UINT32_(0x1) << AES_CTRLA_KEYGEN_Pos)              /* (AES_CTRLA) Last key generation Mask */
#define AES_CTRLA_KEYGEN(value)               (AES_CTRLA_KEYGEN_Msk & (_UINT32_(value) << AES_CTRLA_KEYGEN_Pos)) /* Assigment of value for KEYGEN in the AES_CTRLA register */
#define AES_CTRLA_XORKEY_Pos                  _UINT32_(14)                                         /* (AES_CTRLA) Xor Key operation Position */
#define AES_CTRLA_XORKEY_Msk                  (_UINT32_(0x1) << AES_CTRLA_XORKEY_Pos)              /* (AES_CTRLA) Xor Key operation Mask */
#define AES_CTRLA_XORKEY(value)               (AES_CTRLA_XORKEY_Msk & (_UINT32_(value) << AES_CTRLA_XORKEY_Pos)) /* Assigment of value for XORKEY in the AES_CTRLA register */
#define AES_CTRLA_CTYPE_Pos                   _UINT32_(16)                                         /* (AES_CTRLA) Counter measure types Position */
#define AES_CTRLA_CTYPE_Msk                   (_UINT32_(0xF) << AES_CTRLA_CTYPE_Pos)               /* (AES_CTRLA) Counter measure types Mask */
#define AES_CTRLA_CTYPE(value)                (AES_CTRLA_CTYPE_Msk & (_UINT32_(value) << AES_CTRLA_CTYPE_Pos)) /* Assigment of value for CTYPE in the AES_CTRLA register */
#define AES_CTRLA_Msk                         _UINT32_(0x000F7FFF)                                 /* (AES_CTRLA) Register Mask  */


/* -------- AES_CTRLB : (AES Offset: 0x04) (R/W 8) Control B -------- */
#define AES_CTRLB_RESETVALUE                  _UINT8_(0x00)                                        /*  (AES_CTRLB) Control B  Reset Value */

#define AES_CTRLB_START_Pos                   _UINT8_(0)                                           /* (AES_CTRLB) Manual Start Position */
#define AES_CTRLB_START_Msk                   (_UINT8_(0x1) << AES_CTRLB_START_Pos)                /* (AES_CTRLB) Manual Start Mask */
#define AES_CTRLB_START(value)                (AES_CTRLB_START_Msk & (_UINT8_(value) << AES_CTRLB_START_Pos)) /* Assigment of value for START in the AES_CTRLB register */
#define AES_CTRLB_NEWMSG_Pos                  _UINT8_(1)                                           /* (AES_CTRLB) New message Position */
#define AES_CTRLB_NEWMSG_Msk                  (_UINT8_(0x1) << AES_CTRLB_NEWMSG_Pos)               /* (AES_CTRLB) New message Mask */
#define AES_CTRLB_NEWMSG(value)               (AES_CTRLB_NEWMSG_Msk & (_UINT8_(value) << AES_CTRLB_NEWMSG_Pos)) /* Assigment of value for NEWMSG in the AES_CTRLB register */
#define AES_CTRLB_EOM_Pos                     _UINT8_(2)                                           /* (AES_CTRLB) End of message Position */
#define AES_CTRLB_EOM_Msk                     (_UINT8_(0x1) << AES_CTRLB_EOM_Pos)                  /* (AES_CTRLB) End of message Mask */
#define AES_CTRLB_EOM(value)                  (AES_CTRLB_EOM_Msk & (_UINT8_(value) << AES_CTRLB_EOM_Pos)) /* Assigment of value for EOM in the AES_CTRLB register */
#define AES_CTRLB_GFMUL_Pos                   _UINT8_(3)                                           /* (AES_CTRLB) GF Multiplication Position */
#define AES_CTRLB_GFMUL_Msk                   (_UINT8_(0x1) << AES_CTRLB_GFMUL_Pos)                /* (AES_CTRLB) GF Multiplication Mask */
#define AES_CTRLB_GFMUL(value)                (AES_CTRLB_GFMUL_Msk & (_UINT8_(value) << AES_CTRLB_GFMUL_Pos)) /* Assigment of value for GFMUL in the AES_CTRLB register */
#define AES_CTRLB_Msk                         _UINT8_(0x0F)                                        /* (AES_CTRLB) Register Mask  */


/* -------- AES_INTENCLR : (AES Offset: 0x05) (R/W 8) Interrupt Enable Clear -------- */
#define AES_INTENCLR_RESETVALUE               _UINT8_(0x00)                                        /*  (AES_INTENCLR) Interrupt Enable Clear  Reset Value */

#define AES_INTENCLR_ENCCMP_Pos               _UINT8_(0)                                           /* (AES_INTENCLR) Encryption Complete Position */
#define AES_INTENCLR_ENCCMP_Msk               (_UINT8_(0x1) << AES_INTENCLR_ENCCMP_Pos)            /* (AES_INTENCLR) Encryption Complete Mask */
#define AES_INTENCLR_ENCCMP(value)            (AES_INTENCLR_ENCCMP_Msk & (_UINT8_(value) << AES_INTENCLR_ENCCMP_Pos)) /* Assigment of value for ENCCMP in the AES_INTENCLR register */
#define AES_INTENCLR_GFMCMP_Pos               _UINT8_(1)                                           /* (AES_INTENCLR) GF Multiplication Complete Position */
#define AES_INTENCLR_GFMCMP_Msk               (_UINT8_(0x1) << AES_INTENCLR_GFMCMP_Pos)            /* (AES_INTENCLR) GF Multiplication Complete Mask */
#define AES_INTENCLR_GFMCMP(value)            (AES_INTENCLR_GFMCMP_Msk & (_UINT8_(value) << AES_INTENCLR_GFMCMP_Pos)) /* Assigment of value for GFMCMP in the AES_INTENCLR register */
#define AES_INTENCLR_Msk                      _UINT8_(0x03)                                        /* (AES_INTENCLR) Register Mask  */


/* -------- AES_INTENSET : (AES Offset: 0x06) (R/W 8) Interrupt Enable Set -------- */
#define AES_INTENSET_RESETVALUE               _UINT8_(0x00)                                        /*  (AES_INTENSET) Interrupt Enable Set  Reset Value */

#define AES_INTENSET_ENCCMP_Pos               _UINT8_(0)                                           /* (AES_INTENSET) Encryption Complete Position */
#define AES_INTENSET_ENCCMP_Msk               (_UINT8_(0x1) << AES_INTENSET_ENCCMP_Pos)            /* (AES_INTENSET) Encryption Complete Mask */
#define AES_INTENSET_ENCCMP(value)            (AES_INTENSET_ENCCMP_Msk & (_UINT8_(value) << AES_INTENSET_ENCCMP_Pos)) /* Assigment of value for ENCCMP in the AES_INTENSET register */
#define AES_INTENSET_GFMCMP_Pos               _UINT8_(1)                                           /* (AES_INTENSET) GF Multiplication Complete Position */
#define AES_INTENSET_GFMCMP_Msk               (_UINT8_(0x1) << AES_INTENSET_GFMCMP_Pos)            /* (AES_INTENSET) GF Multiplication Complete Mask */
#define AES_INTENSET_GFMCMP(value)            (AES_INTENSET_GFMCMP_Msk & (_UINT8_(value) << AES_INTENSET_GFMCMP_Pos)) /* Assigment of value for GFMCMP in the AES_INTENSET register */
#define AES_INTENSET_Msk                      _UINT8_(0x03)                                        /* (AES_INTENSET) Register Mask  */


/* -------- AES_INTFLAG : (AES Offset: 0x07) (R/W 8) Interrupt Flag Status -------- */
#define AES_INTFLAG_RESETVALUE                _UINT8_(0x00)                                        /*  (AES_INTFLAG) Interrupt Flag Status  Reset Value */

#define AES_INTFLAG_ENCCMP_Pos                _UINT8_(0)                                           /* (AES_INTFLAG) Encryption Complete Position */
#define AES_INTFLAG_ENCCMP_Msk                (_UINT8_(0x1) << AES_INTFLAG_ENCCMP_Pos)             /* (AES_INTFLAG) Encryption Complete Mask */
#define AES_INTFLAG_ENCCMP(value)             (AES_INTFLAG_ENCCMP_Msk & (_UINT8_(value) << AES_INTFLAG_ENCCMP_Pos)) /* Assigment of value for ENCCMP in the AES_INTFLAG register */
#define AES_INTFLAG_GFMCMP_Pos                _UINT8_(1)                                           /* (AES_INTFLAG) GF Multiplication Complete Position */
#define AES_INTFLAG_GFMCMP_Msk                (_UINT8_(0x1) << AES_INTFLAG_GFMCMP_Pos)             /* (AES_INTFLAG) GF Multiplication Complete Mask */
#define AES_INTFLAG_GFMCMP(value)             (AES_INTFLAG_GFMCMP_Msk & (_UINT8_(value) << AES_INTFLAG_GFMCMP_Pos)) /* Assigment of value for GFMCMP in the AES_INTFLAG register */
#define AES_INTFLAG_Msk                       _UINT8_(0x03)                                        /* (AES_INTFLAG) Register Mask  */


/* -------- AES_DATABUFPTR : (AES Offset: 0x08) (R/W 8) Data buffer pointer -------- */
#define AES_DATABUFPTR_RESETVALUE             _UINT8_(0x00)                                        /*  (AES_DATABUFPTR) Data buffer pointer  Reset Value */

#define AES_DATABUFPTR_INDATAPTR_Pos          _UINT8_(0)                                           /* (AES_DATABUFPTR) Input Data Pointer Position */
#define AES_DATABUFPTR_INDATAPTR_Msk          (_UINT8_(0x3) << AES_DATABUFPTR_INDATAPTR_Pos)       /* (AES_DATABUFPTR) Input Data Pointer Mask */
#define AES_DATABUFPTR_INDATAPTR(value)       (AES_DATABUFPTR_INDATAPTR_Msk & (_UINT8_(value) << AES_DATABUFPTR_INDATAPTR_Pos)) /* Assigment of value for INDATAPTR in the AES_DATABUFPTR register */
#define AES_DATABUFPTR_Msk                    _UINT8_(0x03)                                        /* (AES_DATABUFPTR) Register Mask  */


/* -------- AES_DBGCTRL : (AES Offset: 0x09) ( /W 8) Debug control -------- */
#define AES_DBGCTRL_RESETVALUE                _UINT8_(0x00)                                        /*  (AES_DBGCTRL) Debug control  Reset Value */

#define AES_DBGCTRL_DBGRUN_Pos                _UINT8_(0)                                           /* (AES_DBGCTRL) Debug Run Position */
#define AES_DBGCTRL_DBGRUN_Msk                (_UINT8_(0x1) << AES_DBGCTRL_DBGRUN_Pos)             /* (AES_DBGCTRL) Debug Run Mask */
#define AES_DBGCTRL_DBGRUN(value)             (AES_DBGCTRL_DBGRUN_Msk & (_UINT8_(value) << AES_DBGCTRL_DBGRUN_Pos)) /* Assigment of value for DBGRUN in the AES_DBGCTRL register */
#define AES_DBGCTRL_Msk                       _UINT8_(0x01)                                        /* (AES_DBGCTRL) Register Mask  */


/* -------- AES_KEYWORD : (AES Offset: 0x0C) ( /W 32) Keyword n -------- */
#define AES_KEYWORD_RESETVALUE                _UINT32_(0x00)                                       /*  (AES_KEYWORD) Keyword n  Reset Value */

#define AES_KEYWORD_Msk                       _UINT32_(0x00000000)                                 /* (AES_KEYWORD) Register Mask  */


/* -------- AES_INDATA : (AES Offset: 0x38) (R/W 32) Indata -------- */
#define AES_INDATA_RESETVALUE                 _UINT32_(0x00)                                       /*  (AES_INDATA) Indata  Reset Value */

#define AES_INDATA_Msk                        _UINT32_(0x00000000)                                 /* (AES_INDATA) Register Mask  */


/* -------- AES_INTVECTV : (AES Offset: 0x3C) ( /W 32) Initialisation Vector n -------- */
#define AES_INTVECTV_RESETVALUE               _UINT32_(0x00)                                       /*  (AES_INTVECTV) Initialisation Vector n  Reset Value */

#define AES_INTVECTV_Msk                      _UINT32_(0x00000000)                                 /* (AES_INTVECTV) Register Mask  */


/* -------- AES_HASHKEY : (AES Offset: 0x5C) (R/W 32) Hash key n -------- */
#define AES_HASHKEY_RESETVALUE                _UINT32_(0x00)                                       /*  (AES_HASHKEY) Hash key n  Reset Value */

#define AES_HASHKEY_Msk                       _UINT32_(0x00000000)                                 /* (AES_HASHKEY) Register Mask  */


/* -------- AES_GHASH : (AES Offset: 0x6C) (R/W 32) Galois Hash n -------- */
#define AES_GHASH_RESETVALUE                  _UINT32_(0x00)                                       /*  (AES_GHASH) Galois Hash n  Reset Value */

#define AES_GHASH_Msk                         _UINT32_(0x00000000)                                 /* (AES_GHASH) Register Mask  */


/* -------- AES_CIPLEN : (AES Offset: 0x80) (R/W 32) Cipher Length -------- */
#define AES_CIPLEN_RESETVALUE                 _UINT32_(0x00)                                       /*  (AES_CIPLEN) Cipher Length  Reset Value */

#define AES_CIPLEN_Msk                        _UINT32_(0x00000000)                                 /* (AES_CIPLEN) Register Mask  */


/* -------- AES_RANDSEED : (AES Offset: 0x84) (R/W 32) Random Seed -------- */
#define AES_RANDSEED_RESETVALUE               _UINT32_(0x00)                                       /*  (AES_RANDSEED) Random Seed  Reset Value */

#define AES_RANDSEED_Msk                      _UINT32_(0x00000000)                                 /* (AES_RANDSEED) Register Mask  */


/** \brief AES register offsets definitions */
#define AES_CTRLA_REG_OFST             _UINT32_(0x00)      /* (AES_CTRLA) Control A Offset */
#define AES_CTRLB_REG_OFST             _UINT32_(0x04)      /* (AES_CTRLB) Control B Offset */
#define AES_INTENCLR_REG_OFST          _UINT32_(0x05)      /* (AES_INTENCLR) Interrupt Enable Clear Offset */
#define AES_INTENSET_REG_OFST          _UINT32_(0x06)      /* (AES_INTENSET) Interrupt Enable Set Offset */
#define AES_INTFLAG_REG_OFST           _UINT32_(0x07)      /* (AES_INTFLAG) Interrupt Flag Status Offset */
#define AES_DATABUFPTR_REG_OFST        _UINT32_(0x08)      /* (AES_DATABUFPTR) Data buffer pointer Offset */
#define AES_DBGCTRL_REG_OFST           _UINT32_(0x09)      /* (AES_DBGCTRL) Debug control Offset */
#define AES_KEYWORD_REG_OFST           _UINT32_(0x0C)      /* (AES_KEYWORD) Keyword n Offset */
#define AES_KEYWORD0_REG_OFST          _UINT32_(0x0C)      /* (AES_KEYWORD0) Keyword n Offset */
#define AES_KEYWORD1_REG_OFST          _UINT32_(0x10)      /* (AES_KEYWORD1) Keyword n Offset */
#define AES_KEYWORD2_REG_OFST          _UINT32_(0x14)      /* (AES_KEYWORD2) Keyword n Offset */
#define AES_KEYWORD3_REG_OFST          _UINT32_(0x18)      /* (AES_KEYWORD3) Keyword n Offset */
#define AES_KEYWORD4_REG_OFST          _UINT32_(0x1C)      /* (AES_KEYWORD4) Keyword n Offset */
#define AES_KEYWORD5_REG_OFST          _UINT32_(0x20)      /* (AES_KEYWORD5) Keyword n Offset */
#define AES_KEYWORD6_REG_OFST          _UINT32_(0x24)      /* (AES_KEYWORD6) Keyword n Offset */
#define AES_KEYWORD7_REG_OFST          _UINT32_(0x28)      /* (AES_KEYWORD7) Keyword n Offset */
#define AES_INDATA_REG_OFST            _UINT32_(0x38)      /* (AES_INDATA) Indata Offset */
#define AES_INTVECTV_REG_OFST          _UINT32_(0x3C)      /* (AES_INTVECTV) Initialisation Vector n Offset */
#define AES_INTVECTV0_REG_OFST         _UINT32_(0x3C)      /* (AES_INTVECTV0) Initialisation Vector n Offset */
#define AES_INTVECTV1_REG_OFST         _UINT32_(0x40)      /* (AES_INTVECTV1) Initialisation Vector n Offset */
#define AES_INTVECTV2_REG_OFST         _UINT32_(0x44)      /* (AES_INTVECTV2) Initialisation Vector n Offset */
#define AES_INTVECTV3_REG_OFST         _UINT32_(0x48)      /* (AES_INTVECTV3) Initialisation Vector n Offset */
#define AES_HASHKEY_REG_OFST           _UINT32_(0x5C)      /* (AES_HASHKEY) Hash key n Offset */
#define AES_HASHKEY0_REG_OFST          _UINT32_(0x5C)      /* (AES_HASHKEY0) Hash key n Offset */
#define AES_HASHKEY1_REG_OFST          _UINT32_(0x60)      /* (AES_HASHKEY1) Hash key n Offset */
#define AES_HASHKEY2_REG_OFST          _UINT32_(0x64)      /* (AES_HASHKEY2) Hash key n Offset */
#define AES_HASHKEY3_REG_OFST          _UINT32_(0x68)      /* (AES_HASHKEY3) Hash key n Offset */
#define AES_GHASH_REG_OFST             _UINT32_(0x6C)      /* (AES_GHASH) Galois Hash n Offset */
#define AES_GHASH0_REG_OFST            _UINT32_(0x6C)      /* (AES_GHASH0) Galois Hash n Offset */
#define AES_GHASH1_REG_OFST            _UINT32_(0x70)      /* (AES_GHASH1) Galois Hash n Offset */
#define AES_GHASH2_REG_OFST            _UINT32_(0x74)      /* (AES_GHASH2) Galois Hash n Offset */
#define AES_GHASH3_REG_OFST            _UINT32_(0x78)      /* (AES_GHASH3) Galois Hash n Offset */
#define AES_CIPLEN_REG_OFST            _UINT32_(0x80)      /* (AES_CIPLEN) Cipher Length Offset */
#define AES_RANDSEED_REG_OFST          _UINT32_(0x84)      /* (AES_RANDSEED) Random Seed Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief AES register API structure */
typedef struct
{  /* Advanced Encryption Standard */
  __IO  uint32_t                       AES_CTRLA;          /**< Offset: 0x00 (R/W  32) Control A */
  __IO  uint8_t                        AES_CTRLB;          /**< Offset: 0x04 (R/W  8) Control B */
  __IO  uint8_t                        AES_INTENCLR;       /**< Offset: 0x05 (R/W  8) Interrupt Enable Clear */
  __IO  uint8_t                        AES_INTENSET;       /**< Offset: 0x06 (R/W  8) Interrupt Enable Set */
  __IO  uint8_t                        AES_INTFLAG;        /**< Offset: 0x07 (R/W  8) Interrupt Flag Status */
  __IO  uint8_t                        AES_DATABUFPTR;     /**< Offset: 0x08 (R/W  8) Data buffer pointer */
  __O   uint8_t                        AES_DBGCTRL;        /**< Offset: 0x09 ( /W  8) Debug control */
  __I   uint8_t                        Reserved1[0x02];
  __O   uint32_t                       AES_KEYWORD[8];     /**< Offset: 0x0C ( /W  32) Keyword n */
  __I   uint8_t                        Reserved2[0x0C];
  __IO  uint32_t                       AES_INDATA;         /**< Offset: 0x38 (R/W  32) Indata */
  __O   uint32_t                       AES_INTVECTV[4];    /**< Offset: 0x3C ( /W  32) Initialisation Vector n */
  __I   uint8_t                        Reserved3[0x10];
  __IO  uint32_t                       AES_HASHKEY[4];     /**< Offset: 0x5C (R/W  32) Hash key n */
  __IO  uint32_t                       AES_GHASH[4];       /**< Offset: 0x6C (R/W  32) Galois Hash n */
  __I   uint8_t                        Reserved4[0x04];
  __IO  uint32_t                       AES_CIPLEN;         /**< Offset: 0x80 (R/W  32) Cipher Length */
  __IO  uint32_t                       AES_RANDSEED;       /**< Offset: 0x84 (R/W  32) Random Seed */
} aes_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAML21_AES_COMPONENT_H_ */
