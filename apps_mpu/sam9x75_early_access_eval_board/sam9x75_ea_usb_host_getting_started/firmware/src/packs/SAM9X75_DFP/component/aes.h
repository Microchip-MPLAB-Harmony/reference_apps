/*
 * Component description for AES
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
#ifndef _SAM9X7_AES_COMPONENT_H_
#define _SAM9X7_AES_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR AES                                          */
/* ************************************************************************** */

/* -------- AES_CR : (AES Offset: 0x00) ( /W 32) Control Register -------- */
#define AES_CR_START_Pos                      _UINT32_(0)                                          /* (AES_CR) Start Processing Position */
#define AES_CR_START_Msk                      (_UINT32_(0x1) << AES_CR_START_Pos)                  /* (AES_CR) Start Processing Mask */
#define AES_CR_START(value)                   (AES_CR_START_Msk & (_UINT32_(value) << AES_CR_START_Pos)) /* Assigment of value for START in the AES_CR register */
#define   AES_CR_START_0_Val                  _UINT32_(0x0)                                        /* (AES_CR) No effect.  */
#define   AES_CR_START_1_Val                  _UINT32_(0x1)                                        /* (AES_CR) Starts manual encryption/decryption process.  */
#define AES_CR_START_0                        (AES_CR_START_0_Val << AES_CR_START_Pos)             /* (AES_CR) No effect. Position  */
#define AES_CR_START_1                        (AES_CR_START_1_Val << AES_CR_START_Pos)             /* (AES_CR) Starts manual encryption/decryption process. Position  */
#define AES_CR_SWRST_Pos                      _UINT32_(8)                                          /* (AES_CR) Software Reset Position */
#define AES_CR_SWRST_Msk                      (_UINT32_(0x1) << AES_CR_SWRST_Pos)                  /* (AES_CR) Software Reset Mask */
#define AES_CR_SWRST(value)                   (AES_CR_SWRST_Msk & (_UINT32_(value) << AES_CR_SWRST_Pos)) /* Assigment of value for SWRST in the AES_CR register */
#define   AES_CR_SWRST_0_Val                  _UINT32_(0x0)                                        /* (AES_CR) No effect.  */
#define   AES_CR_SWRST_1_Val                  _UINT32_(0x1)                                        /* (AES_CR) Resets the AES. A software-triggered reset of the AES interface is performed.  */
#define AES_CR_SWRST_0                        (AES_CR_SWRST_0_Val << AES_CR_SWRST_Pos)             /* (AES_CR) No effect. Position  */
#define AES_CR_SWRST_1                        (AES_CR_SWRST_1_Val << AES_CR_SWRST_Pos)             /* (AES_CR) Resets the AES. A software-triggered reset of the AES interface is performed. Position  */
#define AES_CR_UNLOCK_Pos                     _UINT32_(24)                                         /* (AES_CR) Unlock Processing Position */
#define AES_CR_UNLOCK_Msk                     (_UINT32_(0x1) << AES_CR_UNLOCK_Pos)                 /* (AES_CR) Unlock Processing Mask */
#define AES_CR_UNLOCK(value)                  (AES_CR_UNLOCK_Msk & (_UINT32_(value) << AES_CR_UNLOCK_Pos)) /* Assigment of value for UNLOCK in the AES_CR register */
#define   AES_CR_UNLOCK_0_Val                 _UINT32_(0x0)                                        /* (AES_CR) No effect.  */
#define   AES_CR_UNLOCK_1_Val                 _UINT32_(0x1)                                        /* (AES_CR) Unlocks the processing in case of abnormal event detection if AES_WPMR.ACTION > 0.  */
#define AES_CR_UNLOCK_0                       (AES_CR_UNLOCK_0_Val << AES_CR_UNLOCK_Pos)           /* (AES_CR) No effect. Position  */
#define AES_CR_UNLOCK_1                       (AES_CR_UNLOCK_1_Val << AES_CR_UNLOCK_Pos)           /* (AES_CR) Unlocks the processing in case of abnormal event detection if AES_WPMR.ACTION > 0. Position  */
#define AES_CR_Msk                            _UINT32_(0x01000101)                                 /* (AES_CR) Register Mask  */


/* -------- AES_MR : (AES Offset: 0x04) (R/W 32) Mode Register -------- */
#define AES_MR_RESETVALUE                     _UINT32_(0x00)                                       /*  (AES_MR) Mode Register  Reset Value */

#define AES_MR_CIPHER_Pos                     _UINT32_(0)                                          /* (AES_MR) Processing Mode Position */
#define AES_MR_CIPHER_Msk                     (_UINT32_(0x1) << AES_MR_CIPHER_Pos)                 /* (AES_MR) Processing Mode Mask */
#define AES_MR_CIPHER(value)                  (AES_MR_CIPHER_Msk & (_UINT32_(value) << AES_MR_CIPHER_Pos)) /* Assigment of value for CIPHER in the AES_MR register */
#define   AES_MR_CIPHER_0_Val                 _UINT32_(0x0)                                        /* (AES_MR) Decrypts data.  */
#define   AES_MR_CIPHER_1_Val                 _UINT32_(0x1)                                        /* (AES_MR) Encrypts data.  */
#define AES_MR_CIPHER_0                       (AES_MR_CIPHER_0_Val << AES_MR_CIPHER_Pos)           /* (AES_MR) Decrypts data. Position  */
#define AES_MR_CIPHER_1                       (AES_MR_CIPHER_1_Val << AES_MR_CIPHER_Pos)           /* (AES_MR) Encrypts data. Position  */
#define AES_MR_GTAGEN_Pos                     _UINT32_(1)                                          /* (AES_MR) GCM Automatic Tag Generation Enable Position */
#define AES_MR_GTAGEN_Msk                     (_UINT32_(0x1) << AES_MR_GTAGEN_Pos)                 /* (AES_MR) GCM Automatic Tag Generation Enable Mask */
#define AES_MR_GTAGEN(value)                  (AES_MR_GTAGEN_Msk & (_UINT32_(value) << AES_MR_GTAGEN_Pos)) /* Assigment of value for GTAGEN in the AES_MR register */
#define   AES_MR_GTAGEN_0_Val                 _UINT32_(0x0)                                        /* (AES_MR) Automatic GCM Tag generation disabled.  */
#define   AES_MR_GTAGEN_1_Val                 _UINT32_(0x1)                                        /* (AES_MR) Automatic GCM Tag generation enabled.  */
#define AES_MR_GTAGEN_0                       (AES_MR_GTAGEN_0_Val << AES_MR_GTAGEN_Pos)           /* (AES_MR) Automatic GCM Tag generation disabled. Position  */
#define AES_MR_GTAGEN_1                       (AES_MR_GTAGEN_1_Val << AES_MR_GTAGEN_Pos)           /* (AES_MR) Automatic GCM Tag generation enabled. Position  */
#define AES_MR_DUALBUFF_Pos                   _UINT32_(3)                                          /* (AES_MR) Dual Input Buffer Position */
#define AES_MR_DUALBUFF_Msk                   (_UINT32_(0x1) << AES_MR_DUALBUFF_Pos)               /* (AES_MR) Dual Input Buffer Mask */
#define AES_MR_DUALBUFF(value)                (AES_MR_DUALBUFF_Msk & (_UINT32_(value) << AES_MR_DUALBUFF_Pos)) /* Assigment of value for DUALBUFF in the AES_MR register */
#define   AES_MR_DUALBUFF_INACTIVE_Val        _UINT32_(0x0)                                        /* (AES_MR) AES_IDATARx cannot be written during processing of previous block.  */
#define   AES_MR_DUALBUFF_ACTIVE_Val          _UINT32_(0x1)                                        /* (AES_MR) AES_IDATARx can be written during processing of previous block when SMOD = 2. It speeds up the overall runtime of large files.  */
#define AES_MR_DUALBUFF_INACTIVE              (AES_MR_DUALBUFF_INACTIVE_Val << AES_MR_DUALBUFF_Pos) /* (AES_MR) AES_IDATARx cannot be written during processing of previous block. Position  */
#define AES_MR_DUALBUFF_ACTIVE                (AES_MR_DUALBUFF_ACTIVE_Val << AES_MR_DUALBUFF_Pos)  /* (AES_MR) AES_IDATARx can be written during processing of previous block when SMOD = 2. It speeds up the overall runtime of large files. Position  */
#define AES_MR_PROCDLY_Pos                    _UINT32_(4)                                          /* (AES_MR) Processing Delay Position */
#define AES_MR_PROCDLY_Msk                    (_UINT32_(0xF) << AES_MR_PROCDLY_Pos)                /* (AES_MR) Processing Delay Mask */
#define AES_MR_PROCDLY(value)                 (AES_MR_PROCDLY_Msk & (_UINT32_(value) << AES_MR_PROCDLY_Pos)) /* Assigment of value for PROCDLY in the AES_MR register */
#define AES_MR_SMOD_Pos                       _UINT32_(8)                                          /* (AES_MR) Start Mode Position */
#define AES_MR_SMOD_Msk                       (_UINT32_(0x3) << AES_MR_SMOD_Pos)                   /* (AES_MR) Start Mode Mask */
#define AES_MR_SMOD(value)                    (AES_MR_SMOD_Msk & (_UINT32_(value) << AES_MR_SMOD_Pos)) /* Assigment of value for SMOD in the AES_MR register */
#define   AES_MR_SMOD_MANUAL_START_Val        _UINT32_(0x0)                                        /* (AES_MR) Manual Mode  */
#define   AES_MR_SMOD_AUTO_START_Val          _UINT32_(0x1)                                        /* (AES_MR) Auto Mode  */
#define   AES_MR_SMOD_IDATAR0_START_Val       _UINT32_(0x2)                                        /* (AES_MR) AES_IDATAR0 access only Auto Mode (DMA)  */
#define AES_MR_SMOD_MANUAL_START              (AES_MR_SMOD_MANUAL_START_Val << AES_MR_SMOD_Pos)    /* (AES_MR) Manual Mode Position  */
#define AES_MR_SMOD_AUTO_START                (AES_MR_SMOD_AUTO_START_Val << AES_MR_SMOD_Pos)      /* (AES_MR) Auto Mode Position  */
#define AES_MR_SMOD_IDATAR0_START             (AES_MR_SMOD_IDATAR0_START_Val << AES_MR_SMOD_Pos)   /* (AES_MR) AES_IDATAR0 access only Auto Mode (DMA) Position  */
#define AES_MR_KEYSIZE_Pos                    _UINT32_(10)                                         /* (AES_MR) Key Size Position */
#define AES_MR_KEYSIZE_Msk                    (_UINT32_(0x3) << AES_MR_KEYSIZE_Pos)                /* (AES_MR) Key Size Mask */
#define AES_MR_KEYSIZE(value)                 (AES_MR_KEYSIZE_Msk & (_UINT32_(value) << AES_MR_KEYSIZE_Pos)) /* Assigment of value for KEYSIZE in the AES_MR register */
#define   AES_MR_KEYSIZE_AES128_Val           _UINT32_(0x0)                                        /* (AES_MR) AES Key Size is 128 bits  */
#define   AES_MR_KEYSIZE_AES192_Val           _UINT32_(0x1)                                        /* (AES_MR) AES Key Size is 192 bits  */
#define   AES_MR_KEYSIZE_AES256_Val           _UINT32_(0x2)                                        /* (AES_MR) AES Key Size is 256 bits  */
#define AES_MR_KEYSIZE_AES128                 (AES_MR_KEYSIZE_AES128_Val << AES_MR_KEYSIZE_Pos)    /* (AES_MR) AES Key Size is 128 bits Position  */
#define AES_MR_KEYSIZE_AES192                 (AES_MR_KEYSIZE_AES192_Val << AES_MR_KEYSIZE_Pos)    /* (AES_MR) AES Key Size is 192 bits Position  */
#define AES_MR_KEYSIZE_AES256                 (AES_MR_KEYSIZE_AES256_Val << AES_MR_KEYSIZE_Pos)    /* (AES_MR) AES Key Size is 256 bits Position  */
#define AES_MR_OPMOD_Pos                      _UINT32_(12)                                         /* (AES_MR) Operating Mode Position */
#define AES_MR_OPMOD_Msk                      (_UINT32_(0x7) << AES_MR_OPMOD_Pos)                  /* (AES_MR) Operating Mode Mask */
#define AES_MR_OPMOD(value)                   (AES_MR_OPMOD_Msk & (_UINT32_(value) << AES_MR_OPMOD_Pos)) /* Assigment of value for OPMOD in the AES_MR register */
#define   AES_MR_OPMOD_ECB_Val                _UINT32_(0x0)                                        /* (AES_MR) ECB: Electronic Codebook mode  */
#define   AES_MR_OPMOD_CBC_Val                _UINT32_(0x1)                                        /* (AES_MR) CBC: Cipher Block Chaining mode  */
#define   AES_MR_OPMOD_OFB_Val                _UINT32_(0x2)                                        /* (AES_MR) OFB: Output Feedback mode  */
#define   AES_MR_OPMOD_CFB_Val                _UINT32_(0x3)                                        /* (AES_MR) CFB: Cipher Feedback mode  */
#define   AES_MR_OPMOD_CTR_Val                _UINT32_(0x4)                                        /* (AES_MR) CTR: Counter mode (16-bit internal counter)  */
#define   AES_MR_OPMOD_GCM_Val                _UINT32_(0x5)                                        /* (AES_MR) GCM: Galois/Counter mode  */
#define   AES_MR_OPMOD_XTS_Val                _UINT32_(0x6)                                        /* (AES_MR) XTS: XEX-based tweaked-codebook mode  */
#define AES_MR_OPMOD_ECB                      (AES_MR_OPMOD_ECB_Val << AES_MR_OPMOD_Pos)           /* (AES_MR) ECB: Electronic Codebook mode Position  */
#define AES_MR_OPMOD_CBC                      (AES_MR_OPMOD_CBC_Val << AES_MR_OPMOD_Pos)           /* (AES_MR) CBC: Cipher Block Chaining mode Position  */
#define AES_MR_OPMOD_OFB                      (AES_MR_OPMOD_OFB_Val << AES_MR_OPMOD_Pos)           /* (AES_MR) OFB: Output Feedback mode Position  */
#define AES_MR_OPMOD_CFB                      (AES_MR_OPMOD_CFB_Val << AES_MR_OPMOD_Pos)           /* (AES_MR) CFB: Cipher Feedback mode Position  */
#define AES_MR_OPMOD_CTR                      (AES_MR_OPMOD_CTR_Val << AES_MR_OPMOD_Pos)           /* (AES_MR) CTR: Counter mode (16-bit internal counter) Position  */
#define AES_MR_OPMOD_GCM                      (AES_MR_OPMOD_GCM_Val << AES_MR_OPMOD_Pos)           /* (AES_MR) GCM: Galois/Counter mode Position  */
#define AES_MR_OPMOD_XTS                      (AES_MR_OPMOD_XTS_Val << AES_MR_OPMOD_Pos)           /* (AES_MR) XTS: XEX-based tweaked-codebook mode Position  */
#define AES_MR_LOD_Pos                        _UINT32_(15)                                         /* (AES_MR) Last Output Data Mode Position */
#define AES_MR_LOD_Msk                        (_UINT32_(0x1) << AES_MR_LOD_Pos)                    /* (AES_MR) Last Output Data Mode Mask */
#define AES_MR_LOD(value)                     (AES_MR_LOD_Msk & (_UINT32_(value) << AES_MR_LOD_Pos)) /* Assigment of value for LOD in the AES_MR register */
#define   AES_MR_LOD_0_Val                    _UINT32_(0x0)                                        /* (AES_MR) No effect.  */
#define   AES_MR_LOD_1_Val                    _UINT32_(0x1)                                        /* (AES_MR) The DATRDY flag is cleared when at least one of the Input Data Registers is written.  */
#define AES_MR_LOD_0                          (AES_MR_LOD_0_Val << AES_MR_LOD_Pos)                 /* (AES_MR) No effect. Position  */
#define AES_MR_LOD_1                          (AES_MR_LOD_1_Val << AES_MR_LOD_Pos)                 /* (AES_MR) The DATRDY flag is cleared when at least one of the Input Data Registers is written. Position  */
#define AES_MR_CFBS_Pos                       _UINT32_(16)                                         /* (AES_MR) Cipher Feedback Data Size Position */
#define AES_MR_CFBS_Msk                       (_UINT32_(0x7) << AES_MR_CFBS_Pos)                   /* (AES_MR) Cipher Feedback Data Size Mask */
#define AES_MR_CFBS(value)                    (AES_MR_CFBS_Msk & (_UINT32_(value) << AES_MR_CFBS_Pos)) /* Assigment of value for CFBS in the AES_MR register */
#define   AES_MR_CFBS_SIZE_128BIT_Val         _UINT32_(0x0)                                        /* (AES_MR) 128-bit  */
#define   AES_MR_CFBS_SIZE_64BIT_Val          _UINT32_(0x1)                                        /* (AES_MR) 64-bit  */
#define   AES_MR_CFBS_SIZE_32BIT_Val          _UINT32_(0x2)                                        /* (AES_MR) 32-bit  */
#define   AES_MR_CFBS_SIZE_16BIT_Val          _UINT32_(0x3)                                        /* (AES_MR) 16-bit  */
#define   AES_MR_CFBS_SIZE_8BIT_Val           _UINT32_(0x4)                                        /* (AES_MR) 8-bit  */
#define AES_MR_CFBS_SIZE_128BIT               (AES_MR_CFBS_SIZE_128BIT_Val << AES_MR_CFBS_Pos)     /* (AES_MR) 128-bit Position  */
#define AES_MR_CFBS_SIZE_64BIT                (AES_MR_CFBS_SIZE_64BIT_Val << AES_MR_CFBS_Pos)      /* (AES_MR) 64-bit Position  */
#define AES_MR_CFBS_SIZE_32BIT                (AES_MR_CFBS_SIZE_32BIT_Val << AES_MR_CFBS_Pos)      /* (AES_MR) 32-bit Position  */
#define AES_MR_CFBS_SIZE_16BIT                (AES_MR_CFBS_SIZE_16BIT_Val << AES_MR_CFBS_Pos)      /* (AES_MR) 16-bit Position  */
#define AES_MR_CFBS_SIZE_8BIT                 (AES_MR_CFBS_SIZE_8BIT_Val << AES_MR_CFBS_Pos)       /* (AES_MR) 8-bit Position  */
#define AES_MR_CKEY_Pos                       _UINT32_(20)                                         /* (AES_MR) Key Position */
#define AES_MR_CKEY_Msk                       (_UINT32_(0xF) << AES_MR_CKEY_Pos)                   /* (AES_MR) Key Mask */
#define AES_MR_CKEY(value)                    (AES_MR_CKEY_Msk & (_UINT32_(value) << AES_MR_CKEY_Pos)) /* Assigment of value for CKEY in the AES_MR register */
#define   AES_MR_CKEY_PASSWD_Val              _UINT32_(0xE)                                        /* (AES_MR) This field must be written with 0xE the first time AES_MR is programmed. For subsequent programming of AES_MR, any value can be written, including that of 0xE. Always reads as 0.  */
#define AES_MR_CKEY_PASSWD                    (AES_MR_CKEY_PASSWD_Val << AES_MR_CKEY_Pos)          /* (AES_MR) This field must be written with 0xE the first time AES_MR is programmed. For subsequent programming of AES_MR, any value can be written, including that of 0xE. Always reads as 0. Position  */
#define AES_MR_TAMPCLR_Pos                    _UINT32_(31)                                         /* (AES_MR) Tamper Clear Enable Position */
#define AES_MR_TAMPCLR_Msk                    (_UINT32_(0x1) << AES_MR_TAMPCLR_Pos)                /* (AES_MR) Tamper Clear Enable Mask */
#define AES_MR_TAMPCLR(value)                 (AES_MR_TAMPCLR_Msk & (_UINT32_(value) << AES_MR_TAMPCLR_Pos)) /* Assigment of value for TAMPCLR in the AES_MR register */
#define   AES_MR_TAMPCLR_0_Val                _UINT32_(0x0)                                        /* (AES_MR) A tamper detection event has no effect on the AES_KEYWRx key.  */
#define   AES_MR_TAMPCLR_1_Val                _UINT32_(0x1)                                        /* (AES_MR) A tamper detection event immediately clears the AES_KEYWRx key.  */
#define AES_MR_TAMPCLR_0                      (AES_MR_TAMPCLR_0_Val << AES_MR_TAMPCLR_Pos)         /* (AES_MR) A tamper detection event has no effect on the AES_KEYWRx key. Position  */
#define AES_MR_TAMPCLR_1                      (AES_MR_TAMPCLR_1_Val << AES_MR_TAMPCLR_Pos)         /* (AES_MR) A tamper detection event immediately clears the AES_KEYWRx key. Position  */
#define AES_MR_Msk                            _UINT32_(0x80F7FFFB)                                 /* (AES_MR) Register Mask  */


/* -------- AES_IER : (AES Offset: 0x10) ( /W 32) Interrupt Enable Register -------- */
#define AES_IER_DATRDY_Pos                    _UINT32_(0)                                          /* (AES_IER) Data Ready Interrupt Enable Position */
#define AES_IER_DATRDY_Msk                    (_UINT32_(0x1) << AES_IER_DATRDY_Pos)                /* (AES_IER) Data Ready Interrupt Enable Mask */
#define AES_IER_DATRDY(value)                 (AES_IER_DATRDY_Msk & (_UINT32_(value) << AES_IER_DATRDY_Pos)) /* Assigment of value for DATRDY in the AES_IER register */
#define AES_IER_URAD_Pos                      _UINT32_(8)                                          /* (AES_IER) Unspecified Register Access Detection Interrupt Enable Position */
#define AES_IER_URAD_Msk                      (_UINT32_(0x1) << AES_IER_URAD_Pos)                  /* (AES_IER) Unspecified Register Access Detection Interrupt Enable Mask */
#define AES_IER_URAD(value)                   (AES_IER_URAD_Msk & (_UINT32_(value) << AES_IER_URAD_Pos)) /* Assigment of value for URAD in the AES_IER register */
#define AES_IER_TAGRDY_Pos                    _UINT32_(16)                                         /* (AES_IER) GCM Tag Ready Interrupt Enable Position */
#define AES_IER_TAGRDY_Msk                    (_UINT32_(0x1) << AES_IER_TAGRDY_Pos)                /* (AES_IER) GCM Tag Ready Interrupt Enable Mask */
#define AES_IER_TAGRDY(value)                 (AES_IER_TAGRDY_Msk & (_UINT32_(value) << AES_IER_TAGRDY_Pos)) /* Assigment of value for TAGRDY in the AES_IER register */
#define AES_IER_EOPAD_Pos                     _UINT32_(17)                                         /* (AES_IER) End of Padding Interrupt Enable Position */
#define AES_IER_EOPAD_Msk                     (_UINT32_(0x1) << AES_IER_EOPAD_Pos)                 /* (AES_IER) End of Padding Interrupt Enable Mask */
#define AES_IER_EOPAD(value)                  (AES_IER_EOPAD_Msk & (_UINT32_(value) << AES_IER_EOPAD_Pos)) /* Assigment of value for EOPAD in the AES_IER register */
#define AES_IER_PLENERR_Pos                   _UINT32_(18)                                         /* (AES_IER) Padding Length Error Interrupt Enable Position */
#define AES_IER_PLENERR_Msk                   (_UINT32_(0x1) << AES_IER_PLENERR_Pos)               /* (AES_IER) Padding Length Error Interrupt Enable Mask */
#define AES_IER_PLENERR(value)                (AES_IER_PLENERR_Msk & (_UINT32_(value) << AES_IER_PLENERR_Pos)) /* Assigment of value for PLENERR in the AES_IER register */
#define AES_IER_SECE_Pos                      _UINT32_(19)                                         /* (AES_IER) Security and/or Safety Event Interrupt Enable Position */
#define AES_IER_SECE_Msk                      (_UINT32_(0x1) << AES_IER_SECE_Pos)                  /* (AES_IER) Security and/or Safety Event Interrupt Enable Mask */
#define AES_IER_SECE(value)                   (AES_IER_SECE_Msk & (_UINT32_(value) << AES_IER_SECE_Pos)) /* Assigment of value for SECE in the AES_IER register */
#define AES_IER_Msk                           _UINT32_(0x000F0101)                                 /* (AES_IER) Register Mask  */


/* -------- AES_IDR : (AES Offset: 0x14) ( /W 32) Interrupt Disable Register -------- */
#define AES_IDR_DATRDY_Pos                    _UINT32_(0)                                          /* (AES_IDR) Data Ready Interrupt Disable Position */
#define AES_IDR_DATRDY_Msk                    (_UINT32_(0x1) << AES_IDR_DATRDY_Pos)                /* (AES_IDR) Data Ready Interrupt Disable Mask */
#define AES_IDR_DATRDY(value)                 (AES_IDR_DATRDY_Msk & (_UINT32_(value) << AES_IDR_DATRDY_Pos)) /* Assigment of value for DATRDY in the AES_IDR register */
#define AES_IDR_URAD_Pos                      _UINT32_(8)                                          /* (AES_IDR) Unspecified Register Access Detection Interrupt Disable Position */
#define AES_IDR_URAD_Msk                      (_UINT32_(0x1) << AES_IDR_URAD_Pos)                  /* (AES_IDR) Unspecified Register Access Detection Interrupt Disable Mask */
#define AES_IDR_URAD(value)                   (AES_IDR_URAD_Msk & (_UINT32_(value) << AES_IDR_URAD_Pos)) /* Assigment of value for URAD in the AES_IDR register */
#define AES_IDR_TAGRDY_Pos                    _UINT32_(16)                                         /* (AES_IDR) GCM Tag Ready Interrupt Disable Position */
#define AES_IDR_TAGRDY_Msk                    (_UINT32_(0x1) << AES_IDR_TAGRDY_Pos)                /* (AES_IDR) GCM Tag Ready Interrupt Disable Mask */
#define AES_IDR_TAGRDY(value)                 (AES_IDR_TAGRDY_Msk & (_UINT32_(value) << AES_IDR_TAGRDY_Pos)) /* Assigment of value for TAGRDY in the AES_IDR register */
#define AES_IDR_EOPAD_Pos                     _UINT32_(17)                                         /* (AES_IDR) End of Padding Interrupt Disable Position */
#define AES_IDR_EOPAD_Msk                     (_UINT32_(0x1) << AES_IDR_EOPAD_Pos)                 /* (AES_IDR) End of Padding Interrupt Disable Mask */
#define AES_IDR_EOPAD(value)                  (AES_IDR_EOPAD_Msk & (_UINT32_(value) << AES_IDR_EOPAD_Pos)) /* Assigment of value for EOPAD in the AES_IDR register */
#define AES_IDR_PLENERR_Pos                   _UINT32_(18)                                         /* (AES_IDR) Padding Length Error Interrupt Disable Position */
#define AES_IDR_PLENERR_Msk                   (_UINT32_(0x1) << AES_IDR_PLENERR_Pos)               /* (AES_IDR) Padding Length Error Interrupt Disable Mask */
#define AES_IDR_PLENERR(value)                (AES_IDR_PLENERR_Msk & (_UINT32_(value) << AES_IDR_PLENERR_Pos)) /* Assigment of value for PLENERR in the AES_IDR register */
#define AES_IDR_SECE_Pos                      _UINT32_(19)                                         /* (AES_IDR) Security and/or Safety Event Interrupt Disable Position */
#define AES_IDR_SECE_Msk                      (_UINT32_(0x1) << AES_IDR_SECE_Pos)                  /* (AES_IDR) Security and/or Safety Event Interrupt Disable Mask */
#define AES_IDR_SECE(value)                   (AES_IDR_SECE_Msk & (_UINT32_(value) << AES_IDR_SECE_Pos)) /* Assigment of value for SECE in the AES_IDR register */
#define AES_IDR_Msk                           _UINT32_(0x000F0101)                                 /* (AES_IDR) Register Mask  */


/* -------- AES_IMR : (AES Offset: 0x18) ( R/ 32) Interrupt Mask Register -------- */
#define AES_IMR_RESETVALUE                    _UINT32_(0x00)                                       /*  (AES_IMR) Interrupt Mask Register  Reset Value */

#define AES_IMR_DATRDY_Pos                    _UINT32_(0)                                          /* (AES_IMR) Data Ready Interrupt Mask Position */
#define AES_IMR_DATRDY_Msk                    (_UINT32_(0x1) << AES_IMR_DATRDY_Pos)                /* (AES_IMR) Data Ready Interrupt Mask Mask */
#define AES_IMR_DATRDY(value)                 (AES_IMR_DATRDY_Msk & (_UINT32_(value) << AES_IMR_DATRDY_Pos)) /* Assigment of value for DATRDY in the AES_IMR register */
#define AES_IMR_URAD_Pos                      _UINT32_(8)                                          /* (AES_IMR) Unspecified Register Access Detection Interrupt Mask Position */
#define AES_IMR_URAD_Msk                      (_UINT32_(0x1) << AES_IMR_URAD_Pos)                  /* (AES_IMR) Unspecified Register Access Detection Interrupt Mask Mask */
#define AES_IMR_URAD(value)                   (AES_IMR_URAD_Msk & (_UINT32_(value) << AES_IMR_URAD_Pos)) /* Assigment of value for URAD in the AES_IMR register */
#define AES_IMR_TAGRDY_Pos                    _UINT32_(16)                                         /* (AES_IMR) GCM Tag Ready Interrupt Mask Position */
#define AES_IMR_TAGRDY_Msk                    (_UINT32_(0x1) << AES_IMR_TAGRDY_Pos)                /* (AES_IMR) GCM Tag Ready Interrupt Mask Mask */
#define AES_IMR_TAGRDY(value)                 (AES_IMR_TAGRDY_Msk & (_UINT32_(value) << AES_IMR_TAGRDY_Pos)) /* Assigment of value for TAGRDY in the AES_IMR register */
#define AES_IMR_EOPAD_Pos                     _UINT32_(17)                                         /* (AES_IMR) End of Padding Interrupt Mask Position */
#define AES_IMR_EOPAD_Msk                     (_UINT32_(0x1) << AES_IMR_EOPAD_Pos)                 /* (AES_IMR) End of Padding Interrupt Mask Mask */
#define AES_IMR_EOPAD(value)                  (AES_IMR_EOPAD_Msk & (_UINT32_(value) << AES_IMR_EOPAD_Pos)) /* Assigment of value for EOPAD in the AES_IMR register */
#define AES_IMR_PLENERR_Pos                   _UINT32_(18)                                         /* (AES_IMR) Padding Length Error Interrupt Mask Position */
#define AES_IMR_PLENERR_Msk                   (_UINT32_(0x1) << AES_IMR_PLENERR_Pos)               /* (AES_IMR) Padding Length Error Interrupt Mask Mask */
#define AES_IMR_PLENERR(value)                (AES_IMR_PLENERR_Msk & (_UINT32_(value) << AES_IMR_PLENERR_Pos)) /* Assigment of value for PLENERR in the AES_IMR register */
#define AES_IMR_SECE_Pos                      _UINT32_(19)                                         /* (AES_IMR) Security and/or Safety Event Interrupt Mask Position */
#define AES_IMR_SECE_Msk                      (_UINT32_(0x1) << AES_IMR_SECE_Pos)                  /* (AES_IMR) Security and/or Safety Event Interrupt Mask Mask */
#define AES_IMR_SECE(value)                   (AES_IMR_SECE_Msk & (_UINT32_(value) << AES_IMR_SECE_Pos)) /* Assigment of value for SECE in the AES_IMR register */
#define AES_IMR_Msk                           _UINT32_(0x000F0101)                                 /* (AES_IMR) Register Mask  */


/* -------- AES_ISR : (AES Offset: 0x1C) ( R/ 32) Interrupt Status Register -------- */
#define AES_ISR_RESETVALUE                    _UINT32_(0x00)                                       /*  (AES_ISR) Interrupt Status Register  Reset Value */

#define AES_ISR_DATRDY_Pos                    _UINT32_(0)                                          /* (AES_ISR) Data Ready (cleared by setting bit START or bit SWRST in AES_CR or by reading AES_ODATARx) Position */
#define AES_ISR_DATRDY_Msk                    (_UINT32_(0x1) << AES_ISR_DATRDY_Pos)                /* (AES_ISR) Data Ready (cleared by setting bit START or bit SWRST in AES_CR or by reading AES_ODATARx) Mask */
#define AES_ISR_DATRDY(value)                 (AES_ISR_DATRDY_Msk & (_UINT32_(value) << AES_ISR_DATRDY_Pos)) /* Assigment of value for DATRDY in the AES_ISR register */
#define   AES_ISR_DATRDY_0_Val                _UINT32_(0x0)                                        /* (AES_ISR) Output data not valid.  */
#define   AES_ISR_DATRDY_1_Val                _UINT32_(0x1)                                        /* (AES_ISR) Encryption or decryption process is completed.  */
#define AES_ISR_DATRDY_0                      (AES_ISR_DATRDY_0_Val << AES_ISR_DATRDY_Pos)         /* (AES_ISR) Output data not valid. Position  */
#define AES_ISR_DATRDY_1                      (AES_ISR_DATRDY_1_Val << AES_ISR_DATRDY_Pos)         /* (AES_ISR) Encryption or decryption process is completed. Position  */
#define AES_ISR_URAD_Pos                      _UINT32_(8)                                          /* (AES_ISR) Unspecified Register Access Detection Status (cleared by writing SWRST in AES_CR) Position */
#define AES_ISR_URAD_Msk                      (_UINT32_(0x1) << AES_ISR_URAD_Pos)                  /* (AES_ISR) Unspecified Register Access Detection Status (cleared by writing SWRST in AES_CR) Mask */
#define AES_ISR_URAD(value)                   (AES_ISR_URAD_Msk & (_UINT32_(value) << AES_ISR_URAD_Pos)) /* Assigment of value for URAD in the AES_ISR register */
#define   AES_ISR_URAD_0_Val                  _UINT32_(0x0)                                        /* (AES_ISR) No unspecified register access has been detected since the last SWRST.  */
#define   AES_ISR_URAD_1_Val                  _UINT32_(0x1)                                        /* (AES_ISR) At least one unspecified register access has been detected since the last SWRST.  */
#define AES_ISR_URAD_0                        (AES_ISR_URAD_0_Val << AES_ISR_URAD_Pos)             /* (AES_ISR) No unspecified register access has been detected since the last SWRST. Position  */
#define AES_ISR_URAD_1                        (AES_ISR_URAD_1_Val << AES_ISR_URAD_Pos)             /* (AES_ISR) At least one unspecified register access has been detected since the last SWRST. Position  */
#define AES_ISR_URAT_Pos                      _UINT32_(12)                                         /* (AES_ISR) Unspecified Register Access (cleared by writing SWRST in AES_CR) Position */
#define AES_ISR_URAT_Msk                      (_UINT32_(0xF) << AES_ISR_URAT_Pos)                  /* (AES_ISR) Unspecified Register Access (cleared by writing SWRST in AES_CR) Mask */
#define AES_ISR_URAT(value)                   (AES_ISR_URAT_Msk & (_UINT32_(value) << AES_ISR_URAT_Pos)) /* Assigment of value for URAT in the AES_ISR register */
#define   AES_ISR_URAT_IDR_WR_PROCESSING_Val  _UINT32_(0x0)                                        /* (AES_ISR) Input Data register written during the data processing when SMOD = 2 mode.  */
#define   AES_ISR_URAT_ODR_RD_PROCESSING_Val  _UINT32_(0x1)                                        /* (AES_ISR) Output Data register read during the data processing.  */
#define   AES_ISR_URAT_MR_WR_PROCESSING_Val   _UINT32_(0x2)                                        /* (AES_ISR) Mode register written during the data processing.  */
#define   AES_ISR_URAT_ODR_RD_SUBKGEN_Val     _UINT32_(0x3)                                        /* (AES_ISR) Output Data register read during the sub-keys generation.  */
#define   AES_ISR_URAT_MR_WR_SUBKGEN_Val      _UINT32_(0x4)                                        /* (AES_ISR) Mode register written during the sub-keys generation.  */
#define   AES_ISR_URAT_WOR_RD_ACCESS_Val      _UINT32_(0x5)                                        /* (AES_ISR) Write-only register read access.  */
#define AES_ISR_URAT_IDR_WR_PROCESSING        (AES_ISR_URAT_IDR_WR_PROCESSING_Val << AES_ISR_URAT_Pos) /* (AES_ISR) Input Data register written during the data processing when SMOD = 2 mode. Position  */
#define AES_ISR_URAT_ODR_RD_PROCESSING        (AES_ISR_URAT_ODR_RD_PROCESSING_Val << AES_ISR_URAT_Pos) /* (AES_ISR) Output Data register read during the data processing. Position  */
#define AES_ISR_URAT_MR_WR_PROCESSING         (AES_ISR_URAT_MR_WR_PROCESSING_Val << AES_ISR_URAT_Pos) /* (AES_ISR) Mode register written during the data processing. Position  */
#define AES_ISR_URAT_ODR_RD_SUBKGEN           (AES_ISR_URAT_ODR_RD_SUBKGEN_Val << AES_ISR_URAT_Pos) /* (AES_ISR) Output Data register read during the sub-keys generation. Position  */
#define AES_ISR_URAT_MR_WR_SUBKGEN            (AES_ISR_URAT_MR_WR_SUBKGEN_Val << AES_ISR_URAT_Pos) /* (AES_ISR) Mode register written during the sub-keys generation. Position  */
#define AES_ISR_URAT_WOR_RD_ACCESS            (AES_ISR_URAT_WOR_RD_ACCESS_Val << AES_ISR_URAT_Pos) /* (AES_ISR) Write-only register read access. Position  */
#define AES_ISR_TAGRDY_Pos                    _UINT32_(16)                                         /* (AES_ISR) GCM Tag Ready Position */
#define AES_ISR_TAGRDY_Msk                    (_UINT32_(0x1) << AES_ISR_TAGRDY_Pos)                /* (AES_ISR) GCM Tag Ready Mask */
#define AES_ISR_TAGRDY(value)                 (AES_ISR_TAGRDY_Msk & (_UINT32_(value) << AES_ISR_TAGRDY_Pos)) /* Assigment of value for TAGRDY in the AES_ISR register */
#define   AES_ISR_TAGRDY_0_Val                _UINT32_(0x0)                                        /* (AES_ISR) GCM Tag is not valid.  */
#define   AES_ISR_TAGRDY_1_Val                _UINT32_(0x1)                                        /* (AES_ISR) GCM Tag generation is complete (cleared by reading GCM Tag, starting another processing or when writing a new key).  */
#define AES_ISR_TAGRDY_0                      (AES_ISR_TAGRDY_0_Val << AES_ISR_TAGRDY_Pos)         /* (AES_ISR) GCM Tag is not valid. Position  */
#define AES_ISR_TAGRDY_1                      (AES_ISR_TAGRDY_1_Val << AES_ISR_TAGRDY_Pos)         /* (AES_ISR) GCM Tag generation is complete (cleared by reading GCM Tag, starting another processing or when writing a new key). Position  */
#define AES_ISR_EOPAD_Pos                     _UINT32_(17)                                         /* (AES_ISR) End of Padding Position */
#define AES_ISR_EOPAD_Msk                     (_UINT32_(0x1) << AES_ISR_EOPAD_Pos)                 /* (AES_ISR) End of Padding Mask */
#define AES_ISR_EOPAD(value)                  (AES_ISR_EOPAD_Msk & (_UINT32_(value) << AES_ISR_EOPAD_Pos)) /* Assigment of value for EOPAD in the AES_ISR register */
#define   AES_ISR_EOPAD_0_Val                 _UINT32_(0x0)                                        /* (AES_ISR) Padding is not over.  */
#define   AES_ISR_EOPAD_1_Val                 _UINT32_(0x1)                                        /* (AES_ISR) Padding phase is over.  */
#define AES_ISR_EOPAD_0                       (AES_ISR_EOPAD_0_Val << AES_ISR_EOPAD_Pos)           /* (AES_ISR) Padding is not over. Position  */
#define AES_ISR_EOPAD_1                       (AES_ISR_EOPAD_1_Val << AES_ISR_EOPAD_Pos)           /* (AES_ISR) Padding phase is over. Position  */
#define AES_ISR_PLENERR_Pos                   _UINT32_(18)                                         /* (AES_ISR) Padding Length Error Position */
#define AES_ISR_PLENERR_Msk                   (_UINT32_(0x1) << AES_ISR_PLENERR_Pos)               /* (AES_ISR) Padding Length Error Mask */
#define AES_ISR_PLENERR(value)                (AES_ISR_PLENERR_Msk & (_UINT32_(value) << AES_ISR_PLENERR_Pos)) /* Assigment of value for PLENERR in the AES_ISR register */
#define   AES_ISR_PLENERR_0_Val               _UINT32_(0x0)                                        /* (AES_ISR) No Padding Length Error occurred.  */
#define   AES_ISR_PLENERR_1_Val               _UINT32_(0x1)                                        /* (AES_ISR) Padding Length Error detected.  */
#define AES_ISR_PLENERR_0                     (AES_ISR_PLENERR_0_Val << AES_ISR_PLENERR_Pos)       /* (AES_ISR) No Padding Length Error occurred. Position  */
#define AES_ISR_PLENERR_1                     (AES_ISR_PLENERR_1_Val << AES_ISR_PLENERR_Pos)       /* (AES_ISR) Padding Length Error detected. Position  */
#define AES_ISR_SECE_Pos                      _UINT32_(19)                                         /* (AES_ISR) Security and/or Safety Event (cleared on read) Position */
#define AES_ISR_SECE_Msk                      (_UINT32_(0x1) << AES_ISR_SECE_Pos)                  /* (AES_ISR) Security and/or Safety Event (cleared on read) Mask */
#define AES_ISR_SECE(value)                   (AES_ISR_SECE_Msk & (_UINT32_(value) << AES_ISR_SECE_Pos)) /* Assigment of value for SECE in the AES_ISR register */
#define   AES_ISR_SECE_0_Val                  _UINT32_(0x0)                                        /* (AES_ISR) There is no security report in AES_WPSR.  */
#define   AES_ISR_SECE_1_Val                  _UINT32_(0x1)                                        /* (AES_ISR) One security flag is set in AES_WPSR.  */
#define AES_ISR_SECE_0                        (AES_ISR_SECE_0_Val << AES_ISR_SECE_Pos)             /* (AES_ISR) There is no security report in AES_WPSR. Position  */
#define AES_ISR_SECE_1                        (AES_ISR_SECE_1_Val << AES_ISR_SECE_Pos)             /* (AES_ISR) One security flag is set in AES_WPSR. Position  */
#define AES_ISR_Msk                           _UINT32_(0x000FF101)                                 /* (AES_ISR) Register Mask  */


/* -------- AES_KEYWR : (AES Offset: 0x20) ( /W 32) Key Word Register x -------- */
#define AES_KEYWR_KEYW_Pos                    _UINT32_(0)                                          /* (AES_KEYWR) Key Word Position */
#define AES_KEYWR_KEYW_Msk                    (_UINT32_(0xFFFFFFFF) << AES_KEYWR_KEYW_Pos)         /* (AES_KEYWR) Key Word Mask */
#define AES_KEYWR_KEYW(value)                 (AES_KEYWR_KEYW_Msk & (_UINT32_(value) << AES_KEYWR_KEYW_Pos)) /* Assigment of value for KEYW in the AES_KEYWR register */
#define AES_KEYWR_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (AES_KEYWR) Register Mask  */


/* -------- AES_IDATAR : (AES Offset: 0x40) ( /W 32) Input Data Register x -------- */
#define AES_IDATAR_IDATA_Pos                  _UINT32_(0)                                          /* (AES_IDATAR) Input Data Word Position */
#define AES_IDATAR_IDATA_Msk                  (_UINT32_(0xFFFFFFFF) << AES_IDATAR_IDATA_Pos)       /* (AES_IDATAR) Input Data Word Mask */
#define AES_IDATAR_IDATA(value)               (AES_IDATAR_IDATA_Msk & (_UINT32_(value) << AES_IDATAR_IDATA_Pos)) /* Assigment of value for IDATA in the AES_IDATAR register */
#define AES_IDATAR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (AES_IDATAR) Register Mask  */


/* -------- AES_ODATAR : (AES Offset: 0x50) ( R/ 32) Output Data Register x -------- */
#define AES_ODATAR_RESETVALUE                 _UINT32_(0x00)                                       /*  (AES_ODATAR) Output Data Register x  Reset Value */

#define AES_ODATAR_ODATA_Pos                  _UINT32_(0)                                          /* (AES_ODATAR) Output Data Position */
#define AES_ODATAR_ODATA_Msk                  (_UINT32_(0xFFFFFFFF) << AES_ODATAR_ODATA_Pos)       /* (AES_ODATAR) Output Data Mask */
#define AES_ODATAR_ODATA(value)               (AES_ODATAR_ODATA_Msk & (_UINT32_(value) << AES_ODATAR_ODATA_Pos)) /* Assigment of value for ODATA in the AES_ODATAR register */
#define AES_ODATAR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (AES_ODATAR) Register Mask  */


/* -------- AES_IVR : (AES Offset: 0x60) ( /W 32) Initialization Vector Register x -------- */
#define AES_IVR_IV_Pos                        _UINT32_(0)                                          /* (AES_IVR) Initialization Vector Position */
#define AES_IVR_IV_Msk                        (_UINT32_(0xFFFFFFFF) << AES_IVR_IV_Pos)             /* (AES_IVR) Initialization Vector Mask */
#define AES_IVR_IV(value)                     (AES_IVR_IV_Msk & (_UINT32_(value) << AES_IVR_IV_Pos)) /* Assigment of value for IV in the AES_IVR register */
#define AES_IVR_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (AES_IVR) Register Mask  */


/* -------- AES_AADLENR : (AES Offset: 0x70) (R/W 32) Additional Authenticated Data Length Register -------- */
#define AES_AADLENR_AADLEN_Pos                _UINT32_(0)                                          /* (AES_AADLENR) Additional Authenticated Data Length Position */
#define AES_AADLENR_AADLEN_Msk                (_UINT32_(0xFFFFFFFF) << AES_AADLENR_AADLEN_Pos)     /* (AES_AADLENR) Additional Authenticated Data Length Mask */
#define AES_AADLENR_AADLEN(value)             (AES_AADLENR_AADLEN_Msk & (_UINT32_(value) << AES_AADLENR_AADLEN_Pos)) /* Assigment of value for AADLEN in the AES_AADLENR register */
#define AES_AADLENR_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (AES_AADLENR) Register Mask  */


/* -------- AES_CLENR : (AES Offset: 0x74) (R/W 32) Plaintext/Ciphertext Length Register -------- */
#define AES_CLENR_CLEN_Pos                    _UINT32_(0)                                          /* (AES_CLENR) Plaintext/Ciphertext Length Position */
#define AES_CLENR_CLEN_Msk                    (_UINT32_(0xFFFFFFFF) << AES_CLENR_CLEN_Pos)         /* (AES_CLENR) Plaintext/Ciphertext Length Mask */
#define AES_CLENR_CLEN(value)                 (AES_CLENR_CLEN_Msk & (_UINT32_(value) << AES_CLENR_CLEN_Pos)) /* Assigment of value for CLEN in the AES_CLENR register */
#define AES_CLENR_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (AES_CLENR) Register Mask  */


/* -------- AES_GHASHR : (AES Offset: 0x78) (R/W 32) GCM Intermediate Hash Word Register x -------- */
#define AES_GHASHR_GHASH_Pos                  _UINT32_(0)                                          /* (AES_GHASHR) Intermediate GCM Hash Word Position */
#define AES_GHASHR_GHASH_Msk                  (_UINT32_(0xFFFFFFFF) << AES_GHASHR_GHASH_Pos)       /* (AES_GHASHR) Intermediate GCM Hash Word Mask */
#define AES_GHASHR_GHASH(value)               (AES_GHASHR_GHASH_Msk & (_UINT32_(value) << AES_GHASHR_GHASH_Pos)) /* Assigment of value for GHASH in the AES_GHASHR register */
#define AES_GHASHR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (AES_GHASHR) Register Mask  */


/* -------- AES_TAGR : (AES Offset: 0x88) ( R/ 32) GCM Authentication Tag Word Register x -------- */
#define AES_TAGR_TAG_Pos                      _UINT32_(0)                                          /* (AES_TAGR) GCM Authentication Tag Position */
#define AES_TAGR_TAG_Msk                      (_UINT32_(0xFFFFFFFF) << AES_TAGR_TAG_Pos)           /* (AES_TAGR) GCM Authentication Tag Mask */
#define AES_TAGR_TAG(value)                   (AES_TAGR_TAG_Msk & (_UINT32_(value) << AES_TAGR_TAG_Pos)) /* Assigment of value for TAG in the AES_TAGR register */
#define AES_TAGR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (AES_TAGR) Register Mask  */


/* -------- AES_CTRR : (AES Offset: 0x98) ( R/ 32) GCM Encryption Counter Value Register -------- */
#define AES_CTRR_CTR_Pos                      _UINT32_(0)                                          /* (AES_CTRR) GCM Encryption Counter Position */
#define AES_CTRR_CTR_Msk                      (_UINT32_(0xFFFFFFFF) << AES_CTRR_CTR_Pos)           /* (AES_CTRR) GCM Encryption Counter Mask */
#define AES_CTRR_CTR(value)                   (AES_CTRR_CTR_Msk & (_UINT32_(value) << AES_CTRR_CTR_Pos)) /* Assigment of value for CTR in the AES_CTRR register */
#define AES_CTRR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (AES_CTRR) Register Mask  */


/* -------- AES_GCMHR : (AES Offset: 0x9C) (R/W 32) GCM H Word Register x -------- */
#define AES_GCMHR_H_Pos                       _UINT32_(0)                                          /* (AES_GCMHR) GCM H Word Position */
#define AES_GCMHR_H_Msk                       (_UINT32_(0xFFFFFFFF) << AES_GCMHR_H_Pos)            /* (AES_GCMHR) GCM H Word Mask */
#define AES_GCMHR_H(value)                    (AES_GCMHR_H_Msk & (_UINT32_(value) << AES_GCMHR_H_Pos)) /* Assigment of value for H in the AES_GCMHR register */
#define AES_GCMHR_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (AES_GCMHR) Register Mask  */


/* -------- AES_EMR : (AES Offset: 0xB0) (R/W 32) Extended Mode Register -------- */
#define AES_EMR_RESETVALUE                    _UINT32_(0x00)                                       /*  (AES_EMR) Extended Mode Register  Reset Value */

#define AES_EMR_APEN_Pos                      _UINT32_(0)                                          /* (AES_EMR) Auto Padding Enable Position */
#define AES_EMR_APEN_Msk                      (_UINT32_(0x1) << AES_EMR_APEN_Pos)                  /* (AES_EMR) Auto Padding Enable Mask */
#define AES_EMR_APEN(value)                   (AES_EMR_APEN_Msk & (_UINT32_(value) << AES_EMR_APEN_Pos)) /* Assigment of value for APEN in the AES_EMR register */
#define   AES_EMR_APEN_0_Val                  _UINT32_(0x0)                                        /* (AES_EMR) Auto Padding feature is disabled.  */
#define   AES_EMR_APEN_1_Val                  _UINT32_(0x1)                                        /* (AES_EMR) Auto Padding feature is enabled.  */
#define AES_EMR_APEN_0                        (AES_EMR_APEN_0_Val << AES_EMR_APEN_Pos)             /* (AES_EMR) Auto Padding feature is disabled. Position  */
#define AES_EMR_APEN_1                        (AES_EMR_APEN_1_Val << AES_EMR_APEN_Pos)             /* (AES_EMR) Auto Padding feature is enabled. Position  */
#define AES_EMR_APM_Pos                       _UINT32_(1)                                          /* (AES_EMR) Auto Padding Mode Position */
#define AES_EMR_APM_Msk                       (_UINT32_(0x1) << AES_EMR_APM_Pos)                   /* (AES_EMR) Auto Padding Mode Mask */
#define AES_EMR_APM(value)                    (AES_EMR_APM_Msk & (_UINT32_(value) << AES_EMR_APM_Pos)) /* Assigment of value for APM in the AES_EMR register */
#define   AES_EMR_APM_0_Val                   _UINT32_(0x0)                                        /* (AES_EMR) Auto Padding performed according to IPSec standard.  */
#define   AES_EMR_APM_1_Val                   _UINT32_(0x1)                                        /* (AES_EMR) Auto Padding performed according to SSL standard.  */
#define AES_EMR_APM_0                         (AES_EMR_APM_0_Val << AES_EMR_APM_Pos)               /* (AES_EMR) Auto Padding performed according to IPSec standard. Position  */
#define AES_EMR_APM_1                         (AES_EMR_APM_1_Val << AES_EMR_APM_Pos)               /* (AES_EMR) Auto Padding performed according to SSL standard. Position  */
#define AES_EMR_PLIPEN_Pos                    _UINT32_(4)                                          /* (AES_EMR) Protocol Layer Improved Performance Enable Position */
#define AES_EMR_PLIPEN_Msk                    (_UINT32_(0x1) << AES_EMR_PLIPEN_Pos)                /* (AES_EMR) Protocol Layer Improved Performance Enable Mask */
#define AES_EMR_PLIPEN(value)                 (AES_EMR_PLIPEN_Msk & (_UINT32_(value) << AES_EMR_PLIPEN_Pos)) /* Assigment of value for PLIPEN in the AES_EMR register */
#define   AES_EMR_PLIPEN_0_Val                _UINT32_(0x0)                                        /* (AES_EMR) Protocol layer improved performance is disabled.  */
#define   AES_EMR_PLIPEN_1_Val                _UINT32_(0x1)                                        /* (AES_EMR) Protocol layer improved performance is enabled.  */
#define AES_EMR_PLIPEN_0                      (AES_EMR_PLIPEN_0_Val << AES_EMR_PLIPEN_Pos)         /* (AES_EMR) Protocol layer improved performance is disabled. Position  */
#define AES_EMR_PLIPEN_1                      (AES_EMR_PLIPEN_1_Val << AES_EMR_PLIPEN_Pos)         /* (AES_EMR) Protocol layer improved performance is enabled. Position  */
#define AES_EMR_PLIPD_Pos                     _UINT32_(5)                                          /* (AES_EMR) Protocol Layer Improved Performance Decipher Position */
#define AES_EMR_PLIPD_Msk                     (_UINT32_(0x1) << AES_EMR_PLIPD_Pos)                 /* (AES_EMR) Protocol Layer Improved Performance Decipher Mask */
#define AES_EMR_PLIPD(value)                  (AES_EMR_PLIPD_Msk & (_UINT32_(value) << AES_EMR_PLIPD_Pos)) /* Assigment of value for PLIPD in the AES_EMR register */
#define   AES_EMR_PLIPD_0_Val                 _UINT32_(0x0)                                        /* (AES_EMR) Protocol layer improved performance is in ciphering mode.  */
#define   AES_EMR_PLIPD_1_Val                 _UINT32_(0x1)                                        /* (AES_EMR) Protocol layer improved performance is in deciphering mode.  */
#define AES_EMR_PLIPD_0                       (AES_EMR_PLIPD_0_Val << AES_EMR_PLIPD_Pos)           /* (AES_EMR) Protocol layer improved performance is in ciphering mode. Position  */
#define AES_EMR_PLIPD_1                       (AES_EMR_PLIPD_1_Val << AES_EMR_PLIPD_Pos)           /* (AES_EMR) Protocol layer improved performance is in deciphering mode. Position  */
#define AES_EMR_PKRS_Pos                      _UINT32_(7)                                          /* (AES_EMR) Private Key Internal Register Select Position */
#define AES_EMR_PKRS_Msk                      (_UINT32_(0x1) << AES_EMR_PKRS_Pos)                  /* (AES_EMR) Private Key Internal Register Select Mask */
#define AES_EMR_PKRS(value)                   (AES_EMR_PKRS_Msk & (_UINT32_(value) << AES_EMR_PKRS_Pos)) /* Assigment of value for PKRS in the AES_EMR register */
#define   AES_EMR_PKRS_0_Val                  _UINT32_(0x0)                                        /* (AES_EMR) The key used by the AES is in the AES_KEYWRx registers.  */
#define   AES_EMR_PKRS_1_Val                  _UINT32_(0x1)                                        /* (AES_EMR) The key used by the AES is in the Private Key internal registers written via the Private Key bus.  */
#define AES_EMR_PKRS_0                        (AES_EMR_PKRS_0_Val << AES_EMR_PKRS_Pos)             /* (AES_EMR) The key used by the AES is in the AES_KEYWRx registers. Position  */
#define AES_EMR_PKRS_1                        (AES_EMR_PKRS_1_Val << AES_EMR_PKRS_Pos)             /* (AES_EMR) The key used by the AES is in the Private Key internal registers written via the Private Key bus. Position  */
#define AES_EMR_PADLEN_Pos                    _UINT32_(8)                                          /* (AES_EMR) Auto Padding Length Position */
#define AES_EMR_PADLEN_Msk                    (_UINT32_(0xFF) << AES_EMR_PADLEN_Pos)               /* (AES_EMR) Auto Padding Length Mask */
#define AES_EMR_PADLEN(value)                 (AES_EMR_PADLEN_Msk & (_UINT32_(value) << AES_EMR_PADLEN_Pos)) /* Assigment of value for PADLEN in the AES_EMR register */
#define AES_EMR_NHEAD_Pos                     _UINT32_(16)                                         /* (AES_EMR) IPSec Next Header Position */
#define AES_EMR_NHEAD_Msk                     (_UINT32_(0xFF) << AES_EMR_NHEAD_Pos)                /* (AES_EMR) IPSec Next Header Mask */
#define AES_EMR_NHEAD(value)                  (AES_EMR_NHEAD_Msk & (_UINT32_(value) << AES_EMR_NHEAD_Pos)) /* Assigment of value for NHEAD in the AES_EMR register */
#define AES_EMR_BPE_Pos                       _UINT32_(31)                                         /* (AES_EMR) Block Processing End Position */
#define AES_EMR_BPE_Msk                       (_UINT32_(0x1) << AES_EMR_BPE_Pos)                   /* (AES_EMR) Block Processing End Mask */
#define AES_EMR_BPE(value)                    (AES_EMR_BPE_Msk & (_UINT32_(value) << AES_EMR_BPE_Pos)) /* Assigment of value for BPE in the AES_EMR register */
#define   AES_EMR_BPE_0_Val                   _UINT32_(0x0)                                        /* (AES_EMR) AES_ISR.DATRDY flag reports only the end message encryption processing. No intermediate block processing is reported when SMOD=2. When a DMA is used to transfer data, BPE must be cleared.  */
#define   AES_EMR_BPE_1_Val                   _UINT32_(0x1)                                        /* (AES_EMR) AES_ISR.DATRDY flag reports each end of block processing when SMOD=2. When AES_IDATARx are not loaded by a DMA and SMOD=2, this bit can be written to 1 to rise the AES_ISR.DATRDY flag when a new data block can be written.  */
#define AES_EMR_BPE_0                         (AES_EMR_BPE_0_Val << AES_EMR_BPE_Pos)               /* (AES_EMR) AES_ISR.DATRDY flag reports only the end message encryption processing. No intermediate block processing is reported when SMOD=2. When a DMA is used to transfer data, BPE must be cleared. Position  */
#define AES_EMR_BPE_1                         (AES_EMR_BPE_1_Val << AES_EMR_BPE_Pos)               /* (AES_EMR) AES_ISR.DATRDY flag reports each end of block processing when SMOD=2. When AES_IDATARx are not loaded by a DMA and SMOD=2, this bit can be written to 1 to rise the AES_ISR.DATRDY flag when a new data block can be written. Position  */
#define AES_EMR_Msk                           _UINT32_(0x80FFFFB3)                                 /* (AES_EMR) Register Mask  */


/* -------- AES_BCNT : (AES Offset: 0xB4) (R/W 32) Byte Counter Register -------- */
#define AES_BCNT_RESETVALUE                   _UINT32_(0x00)                                       /*  (AES_BCNT) Byte Counter Register  Reset Value */

#define AES_BCNT_BCNT_Pos                     _UINT32_(0)                                          /* (AES_BCNT) Auto Padding Byte Counter Position */
#define AES_BCNT_BCNT_Msk                     (_UINT32_(0xFFFFFFFF) << AES_BCNT_BCNT_Pos)          /* (AES_BCNT) Auto Padding Byte Counter Mask */
#define AES_BCNT_BCNT(value)                  (AES_BCNT_BCNT_Msk & (_UINT32_(value) << AES_BCNT_BCNT_Pos)) /* Assigment of value for BCNT in the AES_BCNT register */
#define AES_BCNT_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (AES_BCNT) Register Mask  */


/* -------- AES_TWR : (AES Offset: 0xC0) (R/W 32) Tweak Word Register x -------- */
#define AES_TWR_RESETVALUE                    _UINT32_(0x00)                                       /*  (AES_TWR) Tweak Word Register x  Reset Value */

#define AES_TWR_TWEAK_Pos                     _UINT32_(0)                                          /* (AES_TWR) Tweak Word Position */
#define AES_TWR_TWEAK_Msk                     (_UINT32_(0xFFFFFFFF) << AES_TWR_TWEAK_Pos)          /* (AES_TWR) Tweak Word Mask */
#define AES_TWR_TWEAK(value)                  (AES_TWR_TWEAK_Msk & (_UINT32_(value) << AES_TWR_TWEAK_Pos)) /* Assigment of value for TWEAK in the AES_TWR register */
#define AES_TWR_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (AES_TWR) Register Mask  */


/* -------- AES_ALPHAR : (AES Offset: 0xD0) ( /W 32) Alpha Word Register x -------- */
#define AES_ALPHAR_ALPHA_Pos                  _UINT32_(0)                                          /* (AES_ALPHAR) Alpha Word Position */
#define AES_ALPHAR_ALPHA_Msk                  (_UINT32_(0xFFFFFFFF) << AES_ALPHAR_ALPHA_Pos)       /* (AES_ALPHAR) Alpha Word Mask */
#define AES_ALPHAR_ALPHA(value)               (AES_ALPHAR_ALPHA_Msk & (_UINT32_(value) << AES_ALPHAR_ALPHA_Pos)) /* Assigment of value for ALPHA in the AES_ALPHAR register */
#define AES_ALPHAR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (AES_ALPHAR) Register Mask  */


/* -------- AES_WPMR : (AES Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define AES_WPMR_RESETVALUE                   _UINT32_(0x00)                                       /*  (AES_WPMR) Write Protection Mode Register  Reset Value */

#define AES_WPMR_WPEN_Pos                     _UINT32_(0)                                          /* (AES_WPMR) Write Protection Configuration Enable Position */
#define AES_WPMR_WPEN_Msk                     (_UINT32_(0x1) << AES_WPMR_WPEN_Pos)                 /* (AES_WPMR) Write Protection Configuration Enable Mask */
#define AES_WPMR_WPEN(value)                  (AES_WPMR_WPEN_Msk & (_UINT32_(value) << AES_WPMR_WPEN_Pos)) /* Assigment of value for WPEN in the AES_WPMR register */
#define   AES_WPMR_WPEN_0_Val                 _UINT32_(0x0)                                        /* (AES_WPMR) Disables the write protection on configuration registers if WPKEY corresponds to 0x414553 ("AES" in ASCII).  */
#define   AES_WPMR_WPEN_1_Val                 _UINT32_(0x1)                                        /* (AES_WPMR) Enables the write protection on configuration registers if WPKEY corresponds to 0x414553 ("AES" in ASCII).  */
#define AES_WPMR_WPEN_0                       (AES_WPMR_WPEN_0_Val << AES_WPMR_WPEN_Pos)           /* (AES_WPMR) Disables the write protection on configuration registers if WPKEY corresponds to 0x414553 ("AES" in ASCII). Position  */
#define AES_WPMR_WPEN_1                       (AES_WPMR_WPEN_1_Val << AES_WPMR_WPEN_Pos)           /* (AES_WPMR) Enables the write protection on configuration registers if WPKEY corresponds to 0x414553 ("AES" in ASCII). Position  */
#define AES_WPMR_WPITEN_Pos                   _UINT32_(1)                                          /* (AES_WPMR) Write Protection Interruption Enable Position */
#define AES_WPMR_WPITEN_Msk                   (_UINT32_(0x1) << AES_WPMR_WPITEN_Pos)               /* (AES_WPMR) Write Protection Interruption Enable Mask */
#define AES_WPMR_WPITEN(value)                (AES_WPMR_WPITEN_Msk & (_UINT32_(value) << AES_WPMR_WPITEN_Pos)) /* Assigment of value for WPITEN in the AES_WPMR register */
#define   AES_WPMR_WPITEN_0_Val               _UINT32_(0x0)                                        /* (AES_WPMR) Disables the write protection on interrupt registers if WPKEY corresponds to 0x414553 ("AES" in ASCII).  */
#define   AES_WPMR_WPITEN_1_Val               _UINT32_(0x1)                                        /* (AES_WPMR) Enables the write protection on interrupt registers if WPKEY corresponds to 0x414553 ("AES" in ASCII).  */
#define AES_WPMR_WPITEN_0                     (AES_WPMR_WPITEN_0_Val << AES_WPMR_WPITEN_Pos)       /* (AES_WPMR) Disables the write protection on interrupt registers if WPKEY corresponds to 0x414553 ("AES" in ASCII). Position  */
#define AES_WPMR_WPITEN_1                     (AES_WPMR_WPITEN_1_Val << AES_WPMR_WPITEN_Pos)       /* (AES_WPMR) Enables the write protection on interrupt registers if WPKEY corresponds to 0x414553 ("AES" in ASCII). Position  */
#define AES_WPMR_WPCREN_Pos                   _UINT32_(2)                                          /* (AES_WPMR) Write Protection Control Enable Position */
#define AES_WPMR_WPCREN_Msk                   (_UINT32_(0x1) << AES_WPMR_WPCREN_Pos)               /* (AES_WPMR) Write Protection Control Enable Mask */
#define AES_WPMR_WPCREN(value)                (AES_WPMR_WPCREN_Msk & (_UINT32_(value) << AES_WPMR_WPCREN_Pos)) /* Assigment of value for WPCREN in the AES_WPMR register */
#define   AES_WPMR_WPCREN_0_Val               _UINT32_(0x0)                                        /* (AES_WPMR) Disables the write protection on control register if WPKEY corresponds to 0x414553 ("AES" in ASCII).  */
#define   AES_WPMR_WPCREN_1_Val               _UINT32_(0x1)                                        /* (AES_WPMR) Enables the write protection on control register if WPKEY corresponds to 0x414553 ("AES" in ASCII).  */
#define AES_WPMR_WPCREN_0                     (AES_WPMR_WPCREN_0_Val << AES_WPMR_WPCREN_Pos)       /* (AES_WPMR) Disables the write protection on control register if WPKEY corresponds to 0x414553 ("AES" in ASCII). Position  */
#define AES_WPMR_WPCREN_1                     (AES_WPMR_WPCREN_1_Val << AES_WPMR_WPCREN_Pos)       /* (AES_WPMR) Enables the write protection on control register if WPKEY corresponds to 0x414553 ("AES" in ASCII). Position  */
#define AES_WPMR_FIRSTE_Pos                   _UINT32_(4)                                          /* (AES_WPMR) First Error Report Enable Position */
#define AES_WPMR_FIRSTE_Msk                   (_UINT32_(0x1) << AES_WPMR_FIRSTE_Pos)               /* (AES_WPMR) First Error Report Enable Mask */
#define AES_WPMR_FIRSTE(value)                (AES_WPMR_FIRSTE_Msk & (_UINT32_(value) << AES_WPMR_FIRSTE_Pos)) /* Assigment of value for FIRSTE in the AES_WPMR register */
#define   AES_WPMR_FIRSTE_0_Val               _UINT32_(0x0)                                        /* (AES_WPMR) The last write protection violation source is reported in AES_WPSR.WPVSRC and the last software control error type is reported in AES_WPSR.SWETYP. The AES_ISR.SECE flag is set at the first error occurrence within a series.  */
#define   AES_WPMR_FIRSTE_1_Val               _UINT32_(0x1)                                        /* (AES_WPMR) Only the first write protection violation source is reported in AES_WPSR.WPVSRC and only the first software control error type is reported in AES_WPSR.SWETYP. The AES_ISR.SECE flag is set at the first error occurrence within a series.  */
#define AES_WPMR_FIRSTE_0                     (AES_WPMR_FIRSTE_0_Val << AES_WPMR_FIRSTE_Pos)       /* (AES_WPMR) The last write protection violation source is reported in AES_WPSR.WPVSRC and the last software control error type is reported in AES_WPSR.SWETYP. The AES_ISR.SECE flag is set at the first error occurrence within a series. Position  */
#define AES_WPMR_FIRSTE_1                     (AES_WPMR_FIRSTE_1_Val << AES_WPMR_FIRSTE_Pos)       /* (AES_WPMR) Only the first write protection violation source is reported in AES_WPSR.WPVSRC and only the first software control error type is reported in AES_WPSR.SWETYP. The AES_ISR.SECE flag is set at the first error occurrence within a series. Position  */
#define AES_WPMR_ACTION_Pos                   _UINT32_(5)                                          /* (AES_WPMR) Action on Abnormal Event Detection Position */
#define AES_WPMR_ACTION_Msk                   (_UINT32_(0x7) << AES_WPMR_ACTION_Pos)               /* (AES_WPMR) Action on Abnormal Event Detection Mask */
#define AES_WPMR_ACTION(value)                (AES_WPMR_ACTION_Msk & (_UINT32_(value) << AES_WPMR_ACTION_Pos)) /* Assigment of value for ACTION in the AES_WPMR register */
#define   AES_WPMR_ACTION_REPORT_ONLY_Val     _UINT32_(0x0)                                        /* (AES_WPMR) No action (stop or clear key) is performed when one of PKRPVS, WPVS, CGD, SEQE, or SWE flags is set.  */
#define   AES_WPMR_ACTION_LOCK_PKRPVS_WPVS_SWE_Val _UINT32_(0x1)                                        /* (AES_WPMR) If a processing is in progress when the AES_WPSR.PKRPVS/WPVS/SWE event detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued.  */
#define   AES_WPMR_ACTION_LOCK_CGD_SEQE_Val   _UINT32_(0x2)                                        /* (AES_WPMR) If a processing is in progress when the AES_WPSR.CGD/SEQE event detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued.  */
#define   AES_WPMR_ACTION_LOCK_ANY_EV_Val     _UINT32_(0x3)                                        /* (AES_WPMR) If a processing is in progress when the AES_WPSR.PKRPVS/WPVS/CGD/SEQE/SWE events detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued.  */
#define   AES_WPMR_ACTION_CLEAR_PKRPVS_WPVS_SWE_Val _UINT32_(0x4)                                        /* (AES_WPMR) If a processing is in progress when the AES_WPSR.PKRPVS/WPVS/SWE events detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued. Moreover, the AES_KEYWRx key is immediately cleared.  */
#define   AES_WPMR_ACTION_CLEAR_CGD_SEQE_Val  _UINT32_(0x5)                                        /* (AES_WPMR) If a processing is in progress when the AES_WPSR.CGD/SEQE events detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued. Moreover, the AES_KEYWRx key is immediately cleared.  */
#define   AES_WPMR_ACTION_CLEAR_ANY_EV_Val    _UINT32_(0x6)                                        /* (AES_WPMR) If a processing is in progress when the AES_WPSR.PKRPVS/WPVS/CGD/SEQE/SWE events detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued. Moreover, the AES_KEYWRx key is immediately cleared.  */
#define AES_WPMR_ACTION_REPORT_ONLY           (AES_WPMR_ACTION_REPORT_ONLY_Val << AES_WPMR_ACTION_Pos) /* (AES_WPMR) No action (stop or clear key) is performed when one of PKRPVS, WPVS, CGD, SEQE, or SWE flags is set. Position  */
#define AES_WPMR_ACTION_LOCK_PKRPVS_WPVS_SWE  (AES_WPMR_ACTION_LOCK_PKRPVS_WPVS_SWE_Val << AES_WPMR_ACTION_Pos) /* (AES_WPMR) If a processing is in progress when the AES_WPSR.PKRPVS/WPVS/SWE event detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued. Position  */
#define AES_WPMR_ACTION_LOCK_CGD_SEQE         (AES_WPMR_ACTION_LOCK_CGD_SEQE_Val << AES_WPMR_ACTION_Pos) /* (AES_WPMR) If a processing is in progress when the AES_WPSR.CGD/SEQE event detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued. Position  */
#define AES_WPMR_ACTION_LOCK_ANY_EV           (AES_WPMR_ACTION_LOCK_ANY_EV_Val << AES_WPMR_ACTION_Pos) /* (AES_WPMR) If a processing is in progress when the AES_WPSR.PKRPVS/WPVS/CGD/SEQE/SWE events detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued. Position  */
#define AES_WPMR_ACTION_CLEAR_PKRPVS_WPVS_SWE (AES_WPMR_ACTION_CLEAR_PKRPVS_WPVS_SWE_Val << AES_WPMR_ACTION_Pos) /* (AES_WPMR) If a processing is in progress when the AES_WPSR.PKRPVS/WPVS/SWE events detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued. Moreover, the AES_KEYWRx key is immediately cleared. Position  */
#define AES_WPMR_ACTION_CLEAR_CGD_SEQE        (AES_WPMR_ACTION_CLEAR_CGD_SEQE_Val << AES_WPMR_ACTION_Pos) /* (AES_WPMR) If a processing is in progress when the AES_WPSR.CGD/SEQE events detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued. Moreover, the AES_KEYWRx key is immediately cleared. Position  */
#define AES_WPMR_ACTION_CLEAR_ANY_EV          (AES_WPMR_ACTION_CLEAR_ANY_EV_Val << AES_WPMR_ACTION_Pos) /* (AES_WPMR) If a processing is in progress when the AES_WPSR.PKRPVS/WPVS/CGD/SEQE/SWE events detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued. Moreover, the AES_KEYWRx key is immediately cleared. Position  */
#define AES_WPMR_WPKEY_Pos                    _UINT32_(8)                                          /* (AES_WPMR) Write Protection Key Position */
#define AES_WPMR_WPKEY_Msk                    (_UINT32_(0xFFFFFF) << AES_WPMR_WPKEY_Pos)           /* (AES_WPMR) Write Protection Key Mask */
#define AES_WPMR_WPKEY(value)                 (AES_WPMR_WPKEY_Msk & (_UINT32_(value) << AES_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the AES_WPMR register */
#define   AES_WPMR_WPKEY_PASSWD_Val           _UINT32_(0x414553)                                   /* (AES_WPMR) Writing any other value in this field aborts the write operation of the WPEN,WPITEN,WPCREN bits. Always reads as 0.  */
#define AES_WPMR_WPKEY_PASSWD                 (AES_WPMR_WPKEY_PASSWD_Val << AES_WPMR_WPKEY_Pos)    /* (AES_WPMR) Writing any other value in this field aborts the write operation of the WPEN,WPITEN,WPCREN bits. Always reads as 0. Position  */
#define AES_WPMR_Msk                          _UINT32_(0xFFFFFFF7)                                 /* (AES_WPMR) Register Mask  */


/* -------- AES_WPSR : (AES Offset: 0xE8) ( R/ 32) Write Protection Status Register -------- */
#define AES_WPSR_RESETVALUE                   _UINT32_(0x00)                                       /*  (AES_WPSR) Write Protection Status Register  Reset Value */

#define AES_WPSR_WPVS_Pos                     _UINT32_(0)                                          /* (AES_WPSR) Write Protection Violation Status (cleared on read) Position */
#define AES_WPSR_WPVS_Msk                     (_UINT32_(0x1) << AES_WPSR_WPVS_Pos)                 /* (AES_WPSR) Write Protection Violation Status (cleared on read) Mask */
#define AES_WPSR_WPVS(value)                  (AES_WPSR_WPVS_Msk & (_UINT32_(value) << AES_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the AES_WPSR register */
#define   AES_WPSR_WPVS_0_Val                 _UINT32_(0x0)                                        /* (AES_WPSR) No write protect violation has occurred since the last read of AES_WPSR.  */
#define   AES_WPSR_WPVS_1_Val                 _UINT32_(0x1)                                        /* (AES_WPSR) A write protect violation has occurred since the last read of AES_WPSR. The address offset of the violated register is reported into field WPVSRC.  */
#define AES_WPSR_WPVS_0                       (AES_WPSR_WPVS_0_Val << AES_WPSR_WPVS_Pos)           /* (AES_WPSR) No write protect violation has occurred since the last read of AES_WPSR. Position  */
#define AES_WPSR_WPVS_1                       (AES_WPSR_WPVS_1_Val << AES_WPSR_WPVS_Pos)           /* (AES_WPSR) A write protect violation has occurred since the last read of AES_WPSR. The address offset of the violated register is reported into field WPVSRC. Position  */
#define AES_WPSR_CGD_Pos                      _UINT32_(1)                                          /* (AES_WPSR) Clock Glitch Detected (cleared on read) Position */
#define AES_WPSR_CGD_Msk                      (_UINT32_(0x1) << AES_WPSR_CGD_Pos)                  /* (AES_WPSR) Clock Glitch Detected (cleared on read) Mask */
#define AES_WPSR_CGD(value)                   (AES_WPSR_CGD_Msk & (_UINT32_(value) << AES_WPSR_CGD_Pos)) /* Assigment of value for CGD in the AES_WPSR register */
#define   AES_WPSR_CGD_0_Val                  _UINT32_(0x0)                                        /* (AES_WPSR) The clock monitoring circuitry has not been corrupted since the last read of AES_WPSR. Under normal operating conditions, this bit is always cleared.  */
#define   AES_WPSR_CGD_1_Val                  _UINT32_(0x1)                                        /* (AES_WPSR) The clock monitoring circuitry has been corrupted since the last read of AES_WPSR. This flag can only be set in case of an abnormal clock signal waveform (glitch).  */
#define AES_WPSR_CGD_0                        (AES_WPSR_CGD_0_Val << AES_WPSR_CGD_Pos)             /* (AES_WPSR) The clock monitoring circuitry has not been corrupted since the last read of AES_WPSR. Under normal operating conditions, this bit is always cleared. Position  */
#define AES_WPSR_CGD_1                        (AES_WPSR_CGD_1_Val << AES_WPSR_CGD_Pos)             /* (AES_WPSR) The clock monitoring circuitry has been corrupted since the last read of AES_WPSR. This flag can only be set in case of an abnormal clock signal waveform (glitch). Position  */
#define AES_WPSR_SEQE_Pos                     _UINT32_(2)                                          /* (AES_WPSR) Internal Sequencer Error (cleared on read) Position */
#define AES_WPSR_SEQE_Msk                     (_UINT32_(0x1) << AES_WPSR_SEQE_Pos)                 /* (AES_WPSR) Internal Sequencer Error (cleared on read) Mask */
#define AES_WPSR_SEQE(value)                  (AES_WPSR_SEQE_Msk & (_UINT32_(value) << AES_WPSR_SEQE_Pos)) /* Assigment of value for SEQE in the AES_WPSR register */
#define   AES_WPSR_SEQE_0_Val                 _UINT32_(0x0)                                        /* (AES_WPSR) No peripheral internal sequencer error has occurred since the last read of AES_WPSR.  */
#define   AES_WPSR_SEQE_1_Val                 _UINT32_(0x1)                                        /* (AES_WPSR) A peripheral internal sequencer error has occurred since the last read of AES_WPSR. This flag can only be set under abnormal operating conditions.  */
#define AES_WPSR_SEQE_0                       (AES_WPSR_SEQE_0_Val << AES_WPSR_SEQE_Pos)           /* (AES_WPSR) No peripheral internal sequencer error has occurred since the last read of AES_WPSR. Position  */
#define AES_WPSR_SEQE_1                       (AES_WPSR_SEQE_1_Val << AES_WPSR_SEQE_Pos)           /* (AES_WPSR) A peripheral internal sequencer error has occurred since the last read of AES_WPSR. This flag can only be set under abnormal operating conditions. Position  */
#define AES_WPSR_SWE_Pos                      _UINT32_(3)                                          /* (AES_WPSR) Software Control Error (cleared on read) Position */
#define AES_WPSR_SWE_Msk                      (_UINT32_(0x1) << AES_WPSR_SWE_Pos)                  /* (AES_WPSR) Software Control Error (cleared on read) Mask */
#define AES_WPSR_SWE(value)                   (AES_WPSR_SWE_Msk & (_UINT32_(value) << AES_WPSR_SWE_Pos)) /* Assigment of value for SWE in the AES_WPSR register */
#define   AES_WPSR_SWE_0_Val                  _UINT32_(0x0)                                        /* (AES_WPSR) No software error has occurred since the last read of AES_WPSR.  */
#define   AES_WPSR_SWE_1_Val                  _UINT32_(0x1)                                        /* (AES_WPSR) A software error has occurred since the last read of AES_WPSR. The field SWETYP details the type of software error; the associated incorrect software access is reported in the field WPVSRC (if WPVS=0).  */
#define AES_WPSR_SWE_0                        (AES_WPSR_SWE_0_Val << AES_WPSR_SWE_Pos)             /* (AES_WPSR) No software error has occurred since the last read of AES_WPSR. Position  */
#define AES_WPSR_SWE_1                        (AES_WPSR_SWE_1_Val << AES_WPSR_SWE_Pos)             /* (AES_WPSR) A software error has occurred since the last read of AES_WPSR. The field SWETYP details the type of software error; the associated incorrect software access is reported in the field WPVSRC (if WPVS=0). Position  */
#define AES_WPSR_PKRPVS_Pos                   _UINT32_(4)                                          /* (AES_WPSR) Private Key Internal Register Protection Violation Status (cleared on read) Position */
#define AES_WPSR_PKRPVS_Msk                   (_UINT32_(0x1) << AES_WPSR_PKRPVS_Pos)               /* (AES_WPSR) Private Key Internal Register Protection Violation Status (cleared on read) Mask */
#define AES_WPSR_PKRPVS(value)                (AES_WPSR_PKRPVS_Msk & (_UINT32_(value) << AES_WPSR_PKRPVS_Pos)) /* Assigment of value for PKRPVS in the AES_WPSR register */
#define   AES_WPSR_PKRPVS_0_Val               _UINT32_(0x0)                                        /* (AES_WPSR) No Private Key internal register access violation has occurred since the last read of AES_WPSR.  */
#define   AES_WPSR_PKRPVS_1_Val               _UINT32_(0x1)                                        /* (AES_WPSR) A Private Key internal register access violation has occurred since the last read of AES_WPSR.  */
#define AES_WPSR_PKRPVS_0                     (AES_WPSR_PKRPVS_0_Val << AES_WPSR_PKRPVS_Pos)       /* (AES_WPSR) No Private Key internal register access violation has occurred since the last read of AES_WPSR. Position  */
#define AES_WPSR_PKRPVS_1                     (AES_WPSR_PKRPVS_1_Val << AES_WPSR_PKRPVS_Pos)       /* (AES_WPSR) A Private Key internal register access violation has occurred since the last read of AES_WPSR. Position  */
#define AES_WPSR_WPVSRC_Pos                   _UINT32_(8)                                          /* (AES_WPSR) Write Protection Violation Source Position */
#define AES_WPSR_WPVSRC_Msk                   (_UINT32_(0xFF) << AES_WPSR_WPVSRC_Pos)              /* (AES_WPSR) Write Protection Violation Source Mask */
#define AES_WPSR_WPVSRC(value)                (AES_WPSR_WPVSRC_Msk & (_UINT32_(value) << AES_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the AES_WPSR register */
#define AES_WPSR_SWETYP_Pos                   _UINT32_(24)                                         /* (AES_WPSR) Software Error Type (cleared on read) Position */
#define AES_WPSR_SWETYP_Msk                   (_UINT32_(0xF) << AES_WPSR_SWETYP_Pos)               /* (AES_WPSR) Software Error Type (cleared on read) Mask */
#define AES_WPSR_SWETYP(value)                (AES_WPSR_SWETYP_Msk & (_UINT32_(value) << AES_WPSR_SWETYP_Pos)) /* Assigment of value for SWETYP in the AES_WPSR register */
#define   AES_WPSR_SWETYP_READ_WO_Val         _UINT32_(0x0)                                        /* (AES_WPSR) A write-only register has been read (Warning).  */
#define   AES_WPSR_SWETYP_WRITE_RO_Val        _UINT32_(0x1)                                        /* (AES_WPSR) AES is enabled and a write access has been performed on a read-only register (Warning).  */
#define   AES_WPSR_SWETYP_UNDEF_RW_Val        _UINT32_(0x2)                                        /* (AES_WPSR) Access to an undefined address (Warning).  */
#define   AES_WPSR_SWETYP_CTRL_START_Val      _UINT32_(0x3)                                        /* (AES_WPSR) Abnormal use of AES_CR.START command when DMA access is configured.  */
#define   AES_WPSR_SWETYP_WEIRD_ACTION_Val    _UINT32_(0x4)                                        /* (AES_WPSR) A key write, init value write, output data read, AES_MR and AES_EMR write, GCM configuration registers write, AES_TWRx and AES_ALPHARx registers write, AES_BCNT write, Private Key bus access has been performed while a current processing is in progress (abnormal).  */
#define   AES_WPSR_SWETYP_INCOMPLETE_KEY_Val  _UINT32_(0x5)                                        /* (AES_WPSR) A tentative of start is required while the key is not fully loaded into the AES_KEYWRx registers.  */
#define AES_WPSR_SWETYP_READ_WO               (AES_WPSR_SWETYP_READ_WO_Val << AES_WPSR_SWETYP_Pos) /* (AES_WPSR) A write-only register has been read (Warning). Position  */
#define AES_WPSR_SWETYP_WRITE_RO              (AES_WPSR_SWETYP_WRITE_RO_Val << AES_WPSR_SWETYP_Pos) /* (AES_WPSR) AES is enabled and a write access has been performed on a read-only register (Warning). Position  */
#define AES_WPSR_SWETYP_UNDEF_RW              (AES_WPSR_SWETYP_UNDEF_RW_Val << AES_WPSR_SWETYP_Pos) /* (AES_WPSR) Access to an undefined address (Warning). Position  */
#define AES_WPSR_SWETYP_CTRL_START            (AES_WPSR_SWETYP_CTRL_START_Val << AES_WPSR_SWETYP_Pos) /* (AES_WPSR) Abnormal use of AES_CR.START command when DMA access is configured. Position  */
#define AES_WPSR_SWETYP_WEIRD_ACTION          (AES_WPSR_SWETYP_WEIRD_ACTION_Val << AES_WPSR_SWETYP_Pos) /* (AES_WPSR) A key write, init value write, output data read, AES_MR and AES_EMR write, GCM configuration registers write, AES_TWRx and AES_ALPHARx registers write, AES_BCNT write, Private Key bus access has been performed while a current processing is in progress (abnormal). Position  */
#define AES_WPSR_SWETYP_INCOMPLETE_KEY        (AES_WPSR_SWETYP_INCOMPLETE_KEY_Val << AES_WPSR_SWETYP_Pos) /* (AES_WPSR) A tentative of start is required while the key is not fully loaded into the AES_KEYWRx registers. Position  */
#define AES_WPSR_ECLASS_Pos                   _UINT32_(31)                                         /* (AES_WPSR) Software Error Class (cleared on read) Position */
#define AES_WPSR_ECLASS_Msk                   (_UINT32_(0x1) << AES_WPSR_ECLASS_Pos)               /* (AES_WPSR) Software Error Class (cleared on read) Mask */
#define AES_WPSR_ECLASS(value)                (AES_WPSR_ECLASS_Msk & (_UINT32_(value) << AES_WPSR_ECLASS_Pos)) /* Assigment of value for ECLASS in the AES_WPSR register */
#define   AES_WPSR_ECLASS_WARNING_Val         _UINT32_(0x0)                                        /* (AES_WPSR) An abnormal access that does not affect system functionality  */
#define   AES_WPSR_ECLASS_ERROR_Val           _UINT32_(0x1)                                        /* (AES_WPSR) An access is performed into key, input data, control registers while the AES is performing an encryption/decryption or a start is request by software or DMA while the key is not fully configured.  */
#define AES_WPSR_ECLASS_WARNING               (AES_WPSR_ECLASS_WARNING_Val << AES_WPSR_ECLASS_Pos) /* (AES_WPSR) An abnormal access that does not affect system functionality Position  */
#define AES_WPSR_ECLASS_ERROR                 (AES_WPSR_ECLASS_ERROR_Val << AES_WPSR_ECLASS_Pos)   /* (AES_WPSR) An access is performed into key, input data, control registers while the AES is performing an encryption/decryption or a start is request by software or DMA while the key is not fully configured. Position  */
#define AES_WPSR_Msk                          _UINT32_(0x8F00FF1F)                                 /* (AES_WPSR) Register Mask  */


/** \brief AES register offsets definitions */
#define AES_CR_REG_OFST                _UINT32_(0x00)      /* (AES_CR) Control Register Offset */
#define AES_MR_REG_OFST                _UINT32_(0x04)      /* (AES_MR) Mode Register Offset */
#define AES_IER_REG_OFST               _UINT32_(0x10)      /* (AES_IER) Interrupt Enable Register Offset */
#define AES_IDR_REG_OFST               _UINT32_(0x14)      /* (AES_IDR) Interrupt Disable Register Offset */
#define AES_IMR_REG_OFST               _UINT32_(0x18)      /* (AES_IMR) Interrupt Mask Register Offset */
#define AES_ISR_REG_OFST               _UINT32_(0x1C)      /* (AES_ISR) Interrupt Status Register Offset */
#define AES_KEYWR_REG_OFST             _UINT32_(0x20)      /* (AES_KEYWR) Key Word Register x Offset */
#define AES_KEYWR0_REG_OFST            _UINT32_(0x20)      /* (AES_KEYWR0) Key Word Register x Offset */
#define AES_KEYWR1_REG_OFST            _UINT32_(0x24)      /* (AES_KEYWR1) Key Word Register x Offset */
#define AES_KEYWR2_REG_OFST            _UINT32_(0x28)      /* (AES_KEYWR2) Key Word Register x Offset */
#define AES_KEYWR3_REG_OFST            _UINT32_(0x2C)      /* (AES_KEYWR3) Key Word Register x Offset */
#define AES_KEYWR4_REG_OFST            _UINT32_(0x30)      /* (AES_KEYWR4) Key Word Register x Offset */
#define AES_KEYWR5_REG_OFST            _UINT32_(0x34)      /* (AES_KEYWR5) Key Word Register x Offset */
#define AES_KEYWR6_REG_OFST            _UINT32_(0x38)      /* (AES_KEYWR6) Key Word Register x Offset */
#define AES_KEYWR7_REG_OFST            _UINT32_(0x3C)      /* (AES_KEYWR7) Key Word Register x Offset */
#define AES_IDATAR_REG_OFST            _UINT32_(0x40)      /* (AES_IDATAR) Input Data Register x Offset */
#define AES_IDATAR0_REG_OFST           _UINT32_(0x40)      /* (AES_IDATAR0) Input Data Register x Offset */
#define AES_IDATAR1_REG_OFST           _UINT32_(0x44)      /* (AES_IDATAR1) Input Data Register x Offset */
#define AES_IDATAR2_REG_OFST           _UINT32_(0x48)      /* (AES_IDATAR2) Input Data Register x Offset */
#define AES_IDATAR3_REG_OFST           _UINT32_(0x4C)      /* (AES_IDATAR3) Input Data Register x Offset */
#define AES_ODATAR_REG_OFST            _UINT32_(0x50)      /* (AES_ODATAR) Output Data Register x Offset */
#define AES_ODATAR0_REG_OFST           _UINT32_(0x50)      /* (AES_ODATAR0) Output Data Register x Offset */
#define AES_ODATAR1_REG_OFST           _UINT32_(0x54)      /* (AES_ODATAR1) Output Data Register x Offset */
#define AES_ODATAR2_REG_OFST           _UINT32_(0x58)      /* (AES_ODATAR2) Output Data Register x Offset */
#define AES_ODATAR3_REG_OFST           _UINT32_(0x5C)      /* (AES_ODATAR3) Output Data Register x Offset */
#define AES_IVR_REG_OFST               _UINT32_(0x60)      /* (AES_IVR) Initialization Vector Register x Offset */
#define AES_IVR0_REG_OFST              _UINT32_(0x60)      /* (AES_IVR0) Initialization Vector Register x Offset */
#define AES_IVR1_REG_OFST              _UINT32_(0x64)      /* (AES_IVR1) Initialization Vector Register x Offset */
#define AES_IVR2_REG_OFST              _UINT32_(0x68)      /* (AES_IVR2) Initialization Vector Register x Offset */
#define AES_IVR3_REG_OFST              _UINT32_(0x6C)      /* (AES_IVR3) Initialization Vector Register x Offset */
#define AES_AADLENR_REG_OFST           _UINT32_(0x70)      /* (AES_AADLENR) Additional Authenticated Data Length Register Offset */
#define AES_CLENR_REG_OFST             _UINT32_(0x74)      /* (AES_CLENR) Plaintext/Ciphertext Length Register Offset */
#define AES_GHASHR_REG_OFST            _UINT32_(0x78)      /* (AES_GHASHR) GCM Intermediate Hash Word Register x Offset */
#define AES_GHASHR0_REG_OFST           _UINT32_(0x78)      /* (AES_GHASHR0) GCM Intermediate Hash Word Register x Offset */
#define AES_GHASHR1_REG_OFST           _UINT32_(0x7C)      /* (AES_GHASHR1) GCM Intermediate Hash Word Register x Offset */
#define AES_GHASHR2_REG_OFST           _UINT32_(0x80)      /* (AES_GHASHR2) GCM Intermediate Hash Word Register x Offset */
#define AES_GHASHR3_REG_OFST           _UINT32_(0x84)      /* (AES_GHASHR3) GCM Intermediate Hash Word Register x Offset */
#define AES_TAGR_REG_OFST              _UINT32_(0x88)      /* (AES_TAGR) GCM Authentication Tag Word Register x Offset */
#define AES_TAGR0_REG_OFST             _UINT32_(0x88)      /* (AES_TAGR0) GCM Authentication Tag Word Register x Offset */
#define AES_TAGR1_REG_OFST             _UINT32_(0x8C)      /* (AES_TAGR1) GCM Authentication Tag Word Register x Offset */
#define AES_TAGR2_REG_OFST             _UINT32_(0x90)      /* (AES_TAGR2) GCM Authentication Tag Word Register x Offset */
#define AES_TAGR3_REG_OFST             _UINT32_(0x94)      /* (AES_TAGR3) GCM Authentication Tag Word Register x Offset */
#define AES_CTRR_REG_OFST              _UINT32_(0x98)      /* (AES_CTRR) GCM Encryption Counter Value Register Offset */
#define AES_GCMHR_REG_OFST             _UINT32_(0x9C)      /* (AES_GCMHR) GCM H Word Register x Offset */
#define AES_GCMHR0_REG_OFST            _UINT32_(0x9C)      /* (AES_GCMHR0) GCM H Word Register x Offset */
#define AES_GCMHR1_REG_OFST            _UINT32_(0xA0)      /* (AES_GCMHR1) GCM H Word Register x Offset */
#define AES_GCMHR2_REG_OFST            _UINT32_(0xA4)      /* (AES_GCMHR2) GCM H Word Register x Offset */
#define AES_GCMHR3_REG_OFST            _UINT32_(0xA8)      /* (AES_GCMHR3) GCM H Word Register x Offset */
#define AES_EMR_REG_OFST               _UINT32_(0xB0)      /* (AES_EMR) Extended Mode Register Offset */
#define AES_BCNT_REG_OFST              _UINT32_(0xB4)      /* (AES_BCNT) Byte Counter Register Offset */
#define AES_TWR_REG_OFST               _UINT32_(0xC0)      /* (AES_TWR) Tweak Word Register x Offset */
#define AES_TWR0_REG_OFST              _UINT32_(0xC0)      /* (AES_TWR0) Tweak Word Register x Offset */
#define AES_TWR1_REG_OFST              _UINT32_(0xC4)      /* (AES_TWR1) Tweak Word Register x Offset */
#define AES_TWR2_REG_OFST              _UINT32_(0xC8)      /* (AES_TWR2) Tweak Word Register x Offset */
#define AES_TWR3_REG_OFST              _UINT32_(0xCC)      /* (AES_TWR3) Tweak Word Register x Offset */
#define AES_ALPHAR_REG_OFST            _UINT32_(0xD0)      /* (AES_ALPHAR) Alpha Word Register x Offset */
#define AES_ALPHAR0_REG_OFST           _UINT32_(0xD0)      /* (AES_ALPHAR0) Alpha Word Register x Offset */
#define AES_ALPHAR1_REG_OFST           _UINT32_(0xD4)      /* (AES_ALPHAR1) Alpha Word Register x Offset */
#define AES_ALPHAR2_REG_OFST           _UINT32_(0xD8)      /* (AES_ALPHAR2) Alpha Word Register x Offset */
#define AES_ALPHAR3_REG_OFST           _UINT32_(0xDC)      /* (AES_ALPHAR3) Alpha Word Register x Offset */
#define AES_WPMR_REG_OFST              _UINT32_(0xE4)      /* (AES_WPMR) Write Protection Mode Register Offset */
#define AES_WPSR_REG_OFST              _UINT32_(0xE8)      /* (AES_WPSR) Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief AES register API structure */
typedef struct
{  /* Advanced Encryption Standard */
  __O   uint32_t                       AES_CR;             /**< Offset: 0x00 ( /W  32) Control Register */
  __IO  uint32_t                       AES_MR;             /**< Offset: 0x04 (R/W  32) Mode Register */
  __I   uint8_t                        Reserved1[0x08];
  __O   uint32_t                       AES_IER;            /**< Offset: 0x10 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       AES_IDR;            /**< Offset: 0x14 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       AES_IMR;            /**< Offset: 0x18 (R/   32) Interrupt Mask Register */
  __I   uint32_t                       AES_ISR;            /**< Offset: 0x1C (R/   32) Interrupt Status Register */
  __O   uint32_t                       AES_KEYWR[8];       /**< Offset: 0x20 ( /W  32) Key Word Register x */
  __O   uint32_t                       AES_IDATAR[4];      /**< Offset: 0x40 ( /W  32) Input Data Register x */
  __I   uint32_t                       AES_ODATAR[4];      /**< Offset: 0x50 (R/   32) Output Data Register x */
  __O   uint32_t                       AES_IVR[4];         /**< Offset: 0x60 ( /W  32) Initialization Vector Register x */
  __IO  uint32_t                       AES_AADLENR;        /**< Offset: 0x70 (R/W  32) Additional Authenticated Data Length Register */
  __IO  uint32_t                       AES_CLENR;          /**< Offset: 0x74 (R/W  32) Plaintext/Ciphertext Length Register */
  __IO  uint32_t                       AES_GHASHR[4];      /**< Offset: 0x78 (R/W  32) GCM Intermediate Hash Word Register x */
  __I   uint32_t                       AES_TAGR[4];        /**< Offset: 0x88 (R/   32) GCM Authentication Tag Word Register x */
  __I   uint32_t                       AES_CTRR;           /**< Offset: 0x98 (R/   32) GCM Encryption Counter Value Register */
  __IO  uint32_t                       AES_GCMHR[4];       /**< Offset: 0x9C (R/W  32) GCM H Word Register x */
  __I   uint8_t                        Reserved2[0x04];
  __IO  uint32_t                       AES_EMR;            /**< Offset: 0xB0 (R/W  32) Extended Mode Register */
  __IO  uint32_t                       AES_BCNT;           /**< Offset: 0xB4 (R/W  32) Byte Counter Register */
  __I   uint8_t                        Reserved3[0x08];
  __IO  uint32_t                       AES_TWR[4];         /**< Offset: 0xC0 (R/W  32) Tweak Word Register x */
  __O   uint32_t                       AES_ALPHAR[4];      /**< Offset: 0xD0 ( /W  32) Alpha Word Register x */
  __I   uint8_t                        Reserved4[0x04];
  __IO  uint32_t                       AES_WPMR;           /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   uint32_t                       AES_WPSR;           /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
} aes_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X7_AES_COMPONENT_H_ */
