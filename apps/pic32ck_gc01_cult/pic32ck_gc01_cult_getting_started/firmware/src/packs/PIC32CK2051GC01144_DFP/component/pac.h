/*
 * Component description for PAC
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

/* file generated from device description version 2023-04-05T13:26:38Z */
#ifndef _PIC32CKGC01_PAC_COMPONENT_H_
#define _PIC32CKGC01_PAC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR PAC                                          */
/* ************************************************************************** */

/* -------- PAC_WRCTRL : (PAC Offset: 0x00) (R/W 32) Write control -------- */
#define PAC_WRCTRL_RESETVALUE                 _UINT32_(0x00)                                       /*  (PAC_WRCTRL) Write control  Reset Value */

#define PAC_WRCTRL_PERID_Pos                  _UINT32_(0)                                          /* (PAC_WRCTRL) Peripheral identifier Position */
#define PAC_WRCTRL_PERID_Msk                  (_UINT32_(0xFFFF) << PAC_WRCTRL_PERID_Pos)           /* (PAC_WRCTRL) Peripheral identifier Mask */
#define PAC_WRCTRL_PERID(value)               (PAC_WRCTRL_PERID_Msk & (_UINT32_(value) << PAC_WRCTRL_PERID_Pos)) /* Assigment of value for PERID in the PAC_WRCTRL register */
#define PAC_WRCTRL_KEY_Pos                    _UINT32_(16)                                         /* (PAC_WRCTRL) Peripheral access control key Position */
#define PAC_WRCTRL_KEY_Msk                    (_UINT32_(0xFF) << PAC_WRCTRL_KEY_Pos)               /* (PAC_WRCTRL) Peripheral access control key Mask */
#define PAC_WRCTRL_KEY(value)                 (PAC_WRCTRL_KEY_Msk & (_UINT32_(value) << PAC_WRCTRL_KEY_Pos)) /* Assigment of value for KEY in the PAC_WRCTRL register */
#define   PAC_WRCTRL_KEY_OFF_Val              _UINT32_(0x0)                                        /* (PAC_WRCTRL) No action  */
#define   PAC_WRCTRL_KEY_CLR_Val              _UINT32_(0x1)                                        /* (PAC_WRCTRL) Clear protection  */
#define   PAC_WRCTRL_KEY_SET_Val              _UINT32_(0x2)                                        /* (PAC_WRCTRL) Set protection  */
#define   PAC_WRCTRL_KEY_SETLCK_Val           _UINT32_(0x3)                                        /* (PAC_WRCTRL) Set and lock protection  */
#define PAC_WRCTRL_KEY_OFF                    (PAC_WRCTRL_KEY_OFF_Val << PAC_WRCTRL_KEY_Pos)       /* (PAC_WRCTRL) No action Position  */
#define PAC_WRCTRL_KEY_CLR                    (PAC_WRCTRL_KEY_CLR_Val << PAC_WRCTRL_KEY_Pos)       /* (PAC_WRCTRL) Clear protection Position  */
#define PAC_WRCTRL_KEY_SET                    (PAC_WRCTRL_KEY_SET_Val << PAC_WRCTRL_KEY_Pos)       /* (PAC_WRCTRL) Set protection Position  */
#define PAC_WRCTRL_KEY_SETLCK                 (PAC_WRCTRL_KEY_SETLCK_Val << PAC_WRCTRL_KEY_Pos)    /* (PAC_WRCTRL) Set and lock protection Position  */
#define PAC_WRCTRL_Msk                        _UINT32_(0x00FFFFFF)                                 /* (PAC_WRCTRL) Register Mask  */


/* -------- PAC_EVCTRL : (PAC Offset: 0x04) (R/W 8) Event control -------- */
#define PAC_EVCTRL_RESETVALUE                 _UINT8_(0x00)                                        /*  (PAC_EVCTRL) Event control  Reset Value */

#define PAC_EVCTRL_ERREO_Pos                  _UINT8_(0)                                           /* (PAC_EVCTRL) Peripheral acess error event output Position */
#define PAC_EVCTRL_ERREO_Msk                  (_UINT8_(0x1) << PAC_EVCTRL_ERREO_Pos)               /* (PAC_EVCTRL) Peripheral acess error event output Mask */
#define PAC_EVCTRL_ERREO(value)               (PAC_EVCTRL_ERREO_Msk & (_UINT8_(value) << PAC_EVCTRL_ERREO_Pos)) /* Assigment of value for ERREO in the PAC_EVCTRL register */
#define PAC_EVCTRL_Msk                        _UINT8_(0x01)                                        /* (PAC_EVCTRL) Register Mask  */


/* -------- PAC_INTENCLR : (PAC Offset: 0x08) (R/W 8) Interrupt enable clear -------- */
#define PAC_INTENCLR_RESETVALUE               _UINT8_(0x00)                                        /*  (PAC_INTENCLR) Interrupt enable clear  Reset Value */

#define PAC_INTENCLR_ERR_Pos                  _UINT8_(0)                                           /* (PAC_INTENCLR) Peripheral access error interrupt disable Position */
#define PAC_INTENCLR_ERR_Msk                  (_UINT8_(0x1) << PAC_INTENCLR_ERR_Pos)               /* (PAC_INTENCLR) Peripheral access error interrupt disable Mask */
#define PAC_INTENCLR_ERR(value)               (PAC_INTENCLR_ERR_Msk & (_UINT8_(value) << PAC_INTENCLR_ERR_Pos)) /* Assigment of value for ERR in the PAC_INTENCLR register */
#define PAC_INTENCLR_Msk                      _UINT8_(0x01)                                        /* (PAC_INTENCLR) Register Mask  */


/* -------- PAC_INTENSET : (PAC Offset: 0x09) (R/W 8) Interrupt enable set -------- */
#define PAC_INTENSET_RESETVALUE               _UINT8_(0x00)                                        /*  (PAC_INTENSET) Interrupt enable set  Reset Value */

#define PAC_INTENSET_ERR_Pos                  _UINT8_(0)                                           /* (PAC_INTENSET) Peripheral access error interrupt enable Position */
#define PAC_INTENSET_ERR_Msk                  (_UINT8_(0x1) << PAC_INTENSET_ERR_Pos)               /* (PAC_INTENSET) Peripheral access error interrupt enable Mask */
#define PAC_INTENSET_ERR(value)               (PAC_INTENSET_ERR_Msk & (_UINT8_(value) << PAC_INTENSET_ERR_Pos)) /* Assigment of value for ERR in the PAC_INTENSET register */
#define PAC_INTENSET_Msk                      _UINT8_(0x01)                                        /* (PAC_INTENSET) Register Mask  */


/* -------- PAC_INTFLAGAHB : (PAC Offset: 0x10) (R/W 32) Bridge interrupt flag status -------- */
#define PAC_INTFLAGAHB_RESETVALUE             _UINT32_(0x00)                                       /*  (PAC_INTFLAGAHB) Bridge interrupt flag status  Reset Value */

#define PAC_INTFLAGAHB_Msk                    _UINT32_(0x00000000)                                 /* (PAC_INTFLAGAHB) Register Mask  */


/* -------- PAC_INTFLAGA : (PAC Offset: 0x14) (R/W 32) Peripheral interrupt flag status - Bridge A -------- */
#define PAC_INTFLAGA_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_INTFLAGA) Peripheral interrupt flag status - Bridge A  Reset Value */

#define PAC_INTFLAGA_Msk                      _UINT32_(0x00000000)                                 /* (PAC_INTFLAGA) Register Mask  */


/* -------- PAC_INTFLAGB : (PAC Offset: 0x18) (R/W 32) Peripheral interrupt flag status - Bridge B -------- */
#define PAC_INTFLAGB_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_INTFLAGB) Peripheral interrupt flag status - Bridge B  Reset Value */

#define PAC_INTFLAGB_Msk                      _UINT32_(0x00000000)                                 /* (PAC_INTFLAGB) Register Mask  */


/* -------- PAC_INTFLAGC : (PAC Offset: 0x1C) (R/W 32) Peripheral interrupt flag status - Bridge C -------- */
#define PAC_INTFLAGC_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_INTFLAGC) Peripheral interrupt flag status - Bridge C  Reset Value */

#define PAC_INTFLAGC_Msk                      _UINT32_(0x00000000)                                 /* (PAC_INTFLAGC) Register Mask  */


/* -------- PAC_INTFLAGD : (PAC Offset: 0x20) (R/W 32) Peripheral interrupt flag status - Bridge D -------- */
#define PAC_INTFLAGD_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_INTFLAGD) Peripheral interrupt flag status - Bridge D  Reset Value */

#define PAC_INTFLAGD_Msk                      _UINT32_(0x00000000)                                 /* (PAC_INTFLAGD) Register Mask  */


/* -------- PAC_STATUSA : (PAC Offset: 0x34) ( R/ 32) Peripheral write protection status - Bridge A -------- */
#define PAC_STATUSA_RESETVALUE                _UINT32_(0xF0000)                                    /*  (PAC_STATUSA) Peripheral write protection status - Bridge A  Reset Value */

#define PAC_STATUSA_Msk                       _UINT32_(0x00000000)                                 /* (PAC_STATUSA) Register Mask  */


/* -------- PAC_STATUSB : (PAC Offset: 0x38) ( R/ 32) Peripheral write protection status - Bridge B -------- */
#define PAC_STATUSB_RESETVALUE                _UINT32_(0x00)                                       /*  (PAC_STATUSB) Peripheral write protection status - Bridge B  Reset Value */

#define PAC_STATUSB_Msk                       _UINT32_(0x00000000)                                 /* (PAC_STATUSB) Register Mask  */


/* -------- PAC_STATUSC : (PAC Offset: 0x3C) ( R/ 32) Peripheral write protection status - Bridge C -------- */
#define PAC_STATUSC_RESETVALUE                _UINT32_(0x00)                                       /*  (PAC_STATUSC) Peripheral write protection status - Bridge C  Reset Value */

#define PAC_STATUSC_Msk                       _UINT32_(0x00000000)                                 /* (PAC_STATUSC) Register Mask  */


/* -------- PAC_STATUSD : (PAC Offset: 0x40) ( R/ 32) Peripheral write protection status - Bridge D -------- */
#define PAC_STATUSD_RESETVALUE                _UINT32_(0x00)                                       /*  (PAC_STATUSD) Peripheral write protection status - Bridge D  Reset Value */

#define PAC_STATUSD_Msk                       _UINT32_(0x00000000)                                 /* (PAC_STATUSD) Register Mask  */


/* -------- PAC_NONSECA : (PAC Offset: 0x54) ( R/ 32) Peripheral Non-Secure Status - Bridge A -------- */
#define PAC_NONSECA_RESETVALUE                _UINT32_(0x00)                                       /*  (PAC_NONSECA) Peripheral Non-Secure Status - Bridge A  Reset Value */

#define PAC_NONSECA_Msk                       _UINT32_(0x00000000)                                 /* (PAC_NONSECA) Register Mask  */


/* -------- PAC_NONSECB : (PAC Offset: 0x58) ( R/ 32) Peripheral Non-Secure Status - Bridge B -------- */
#define PAC_NONSECB_RESETVALUE                _UINT32_(0x00)                                       /*  (PAC_NONSECB) Peripheral Non-Secure Status - Bridge B  Reset Value */

#define PAC_NONSECB_Msk                       _UINT32_(0x00000000)                                 /* (PAC_NONSECB) Register Mask  */


/* -------- PAC_NONSECC : (PAC Offset: 0x5C) ( R/ 32) Peripheral Non-Secure Status - Bridge C -------- */
#define PAC_NONSECC_RESETVALUE                _UINT32_(0x00)                                       /*  (PAC_NONSECC) Peripheral Non-Secure Status - Bridge C  Reset Value */

#define PAC_NONSECC_Msk                       _UINT32_(0x00000000)                                 /* (PAC_NONSECC) Register Mask  */


/* -------- PAC_NONSECD : (PAC Offset: 0x60) ( R/ 32) Peripheral Non-Secure Status - Bridge D -------- */
#define PAC_NONSECD_RESETVALUE                _UINT32_(0x00)                                       /*  (PAC_NONSECD) Peripheral Non-Secure Status - Bridge D  Reset Value */

#define PAC_NONSECD_Msk                       _UINT32_(0x00000000)                                 /* (PAC_NONSECD) Register Mask  */


/* -------- PAC_SECLOCKA : (PAC Offset: 0x74) ( R/ 32) Peripheral Security Lock Status - Bridge A -------- */
#define PAC_SECLOCKA_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_SECLOCKA) Peripheral Security Lock Status - Bridge A  Reset Value */

#define PAC_SECLOCKA_Msk                      _UINT32_(0x00000000)                                 /* (PAC_SECLOCKA) Register Mask  */


/* -------- PAC_SECLOCKB : (PAC Offset: 0x78) ( R/ 32) Peripheral Security Lock Status - Bridge B -------- */
#define PAC_SECLOCKB_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_SECLOCKB) Peripheral Security Lock Status - Bridge B  Reset Value */

#define PAC_SECLOCKB_Msk                      _UINT32_(0x00000000)                                 /* (PAC_SECLOCKB) Register Mask  */


/* -------- PAC_SECLOCKC : (PAC Offset: 0x7C) ( R/ 32) Peripheral Security Lock Status - Bridge C -------- */
#define PAC_SECLOCKC_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_SECLOCKC) Peripheral Security Lock Status - Bridge C  Reset Value */

#define PAC_SECLOCKC_Msk                      _UINT32_(0x00000000)                                 /* (PAC_SECLOCKC) Register Mask  */


/* -------- PAC_SECLOCKD : (PAC Offset: 0x80) ( R/ 32) Peripheral Security Lock Status - Bridge D -------- */
#define PAC_SECLOCKD_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_SECLOCKD) Peripheral Security Lock Status - Bridge D  Reset Value */

#define PAC_SECLOCKD_Msk                      _UINT32_(0x00000000)                                 /* (PAC_SECLOCKD) Register Mask  */


/** \brief PAC register offsets definitions */
#define PAC_WRCTRL_REG_OFST            _UINT32_(0x00)      /* (PAC_WRCTRL) Write control Offset */
#define PAC_EVCTRL_REG_OFST            _UINT32_(0x04)      /* (PAC_EVCTRL) Event control Offset */
#define PAC_INTENCLR_REG_OFST          _UINT32_(0x08)      /* (PAC_INTENCLR) Interrupt enable clear Offset */
#define PAC_INTENSET_REG_OFST          _UINT32_(0x09)      /* (PAC_INTENSET) Interrupt enable set Offset */
#define PAC_INTFLAGAHB_REG_OFST        _UINT32_(0x10)      /* (PAC_INTFLAGAHB) Bridge interrupt flag status Offset */
#define PAC_INTFLAGA_REG_OFST          _UINT32_(0x14)      /* (PAC_INTFLAGA) Peripheral interrupt flag status - Bridge A Offset */
#define PAC_INTFLAGB_REG_OFST          _UINT32_(0x18)      /* (PAC_INTFLAGB) Peripheral interrupt flag status - Bridge B Offset */
#define PAC_INTFLAGC_REG_OFST          _UINT32_(0x1C)      /* (PAC_INTFLAGC) Peripheral interrupt flag status - Bridge C Offset */
#define PAC_INTFLAGD_REG_OFST          _UINT32_(0x20)      /* (PAC_INTFLAGD) Peripheral interrupt flag status - Bridge D Offset */
#define PAC_STATUSA_REG_OFST           _UINT32_(0x34)      /* (PAC_STATUSA) Peripheral write protection status - Bridge A Offset */
#define PAC_STATUSB_REG_OFST           _UINT32_(0x38)      /* (PAC_STATUSB) Peripheral write protection status - Bridge B Offset */
#define PAC_STATUSC_REG_OFST           _UINT32_(0x3C)      /* (PAC_STATUSC) Peripheral write protection status - Bridge C Offset */
#define PAC_STATUSD_REG_OFST           _UINT32_(0x40)      /* (PAC_STATUSD) Peripheral write protection status - Bridge D Offset */
#define PAC_NONSECA_REG_OFST           _UINT32_(0x54)      /* (PAC_NONSECA) Peripheral Non-Secure Status - Bridge A Offset */
#define PAC_NONSECB_REG_OFST           _UINT32_(0x58)      /* (PAC_NONSECB) Peripheral Non-Secure Status - Bridge B Offset */
#define PAC_NONSECC_REG_OFST           _UINT32_(0x5C)      /* (PAC_NONSECC) Peripheral Non-Secure Status - Bridge C Offset */
#define PAC_NONSECD_REG_OFST           _UINT32_(0x60)      /* (PAC_NONSECD) Peripheral Non-Secure Status - Bridge D Offset */
#define PAC_SECLOCKA_REG_OFST          _UINT32_(0x74)      /* (PAC_SECLOCKA) Peripheral Security Lock Status - Bridge A Offset */
#define PAC_SECLOCKB_REG_OFST          _UINT32_(0x78)      /* (PAC_SECLOCKB) Peripheral Security Lock Status - Bridge B Offset */
#define PAC_SECLOCKC_REG_OFST          _UINT32_(0x7C)      /* (PAC_SECLOCKC) Peripheral Security Lock Status - Bridge C Offset */
#define PAC_SECLOCKD_REG_OFST          _UINT32_(0x80)      /* (PAC_SECLOCKD) Peripheral Security Lock Status - Bridge D Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief PAC register API structure */
typedef struct
{  /* Peripheral Access Controller */
  __IO  uint32_t                       PAC_WRCTRL;         /**< Offset: 0x00 (R/W  32) Write control */
  __IO  uint8_t                        PAC_EVCTRL;         /**< Offset: 0x04 (R/W  8) Event control */
  __I   uint8_t                        Reserved1[0x03];
  __IO  uint8_t                        PAC_INTENCLR;       /**< Offset: 0x08 (R/W  8) Interrupt enable clear */
  __IO  uint8_t                        PAC_INTENSET;       /**< Offset: 0x09 (R/W  8) Interrupt enable set */
  __I   uint8_t                        Reserved2[0x06];
  __IO  uint32_t                       PAC_INTFLAGAHB;     /**< Offset: 0x10 (R/W  32) Bridge interrupt flag status */
  __IO  uint32_t                       PAC_INTFLAGA;       /**< Offset: 0x14 (R/W  32) Peripheral interrupt flag status - Bridge A */
  __IO  uint32_t                       PAC_INTFLAGB;       /**< Offset: 0x18 (R/W  32) Peripheral interrupt flag status - Bridge B */
  __IO  uint32_t                       PAC_INTFLAGC;       /**< Offset: 0x1C (R/W  32) Peripheral interrupt flag status - Bridge C */
  __IO  uint32_t                       PAC_INTFLAGD;       /**< Offset: 0x20 (R/W  32) Peripheral interrupt flag status - Bridge D */
  __I   uint8_t                        Reserved3[0x10];
  __I   uint32_t                       PAC_STATUSA;        /**< Offset: 0x34 (R/   32) Peripheral write protection status - Bridge A */
  __I   uint32_t                       PAC_STATUSB;        /**< Offset: 0x38 (R/   32) Peripheral write protection status - Bridge B */
  __I   uint32_t                       PAC_STATUSC;        /**< Offset: 0x3C (R/   32) Peripheral write protection status - Bridge C */
  __I   uint32_t                       PAC_STATUSD;        /**< Offset: 0x40 (R/   32) Peripheral write protection status - Bridge D */
  __I   uint8_t                        Reserved4[0x10];
  __I   uint32_t                       PAC_NONSECA;        /**< Offset: 0x54 (R/   32) Peripheral Non-Secure Status - Bridge A */
  __I   uint32_t                       PAC_NONSECB;        /**< Offset: 0x58 (R/   32) Peripheral Non-Secure Status - Bridge B */
  __I   uint32_t                       PAC_NONSECC;        /**< Offset: 0x5C (R/   32) Peripheral Non-Secure Status - Bridge C */
  __I   uint32_t                       PAC_NONSECD;        /**< Offset: 0x60 (R/   32) Peripheral Non-Secure Status - Bridge D */
  __I   uint8_t                        Reserved5[0x10];
  __I   uint32_t                       PAC_SECLOCKA;       /**< Offset: 0x74 (R/   32) Peripheral Security Lock Status - Bridge A */
  __I   uint32_t                       PAC_SECLOCKB;       /**< Offset: 0x78 (R/   32) Peripheral Security Lock Status - Bridge B */
  __I   uint32_t                       PAC_SECLOCKC;       /**< Offset: 0x7C (R/   32) Peripheral Security Lock Status - Bridge C */
  __I   uint32_t                       PAC_SECLOCKD;       /**< Offset: 0x80 (R/   32) Peripheral Security Lock Status - Bridge D */
} pac_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CKGC01_PAC_COMPONENT_H_ */
