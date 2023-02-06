/*
 * Component description for MCLK
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
#ifndef _PIC32CZCA90_MCLK_COMPONENT_H_
#define _PIC32CZCA90_MCLK_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR MCLK                                         */
/* ************************************************************************** */

/* -------- MCLK_INTENCLR : (MCLK Offset: 0x00) (R/W 32) Interrupt Enable Clear -------- */
#define MCLK_INTENCLR_RESETVALUE              _UINT32_(0x00)                                       /*  (MCLK_INTENCLR) Interrupt Enable Clear  Reset Value */

#define MCLK_INTENCLR_CKRDY_Pos               _UINT32_(0)                                          /* (MCLK_INTENCLR) Clock Ready Interrupt Enable Position */
#define MCLK_INTENCLR_CKRDY_Msk               (_UINT32_(0x1) << MCLK_INTENCLR_CKRDY_Pos)           /* (MCLK_INTENCLR) Clock Ready Interrupt Enable Mask */
#define MCLK_INTENCLR_CKRDY(value)            (MCLK_INTENCLR_CKRDY_Msk & (_UINT32_(value) << MCLK_INTENCLR_CKRDY_Pos)) /* Assigment of value for CKRDY in the MCLK_INTENCLR register */
#define MCLK_INTENCLR_Msk                     _UINT32_(0x00000001)                                 /* (MCLK_INTENCLR) Register Mask  */


/* -------- MCLK_INTENSET : (MCLK Offset: 0x04) (R/W 32) Interrupt Enable Set -------- */
#define MCLK_INTENSET_RESETVALUE              _UINT32_(0x00)                                       /*  (MCLK_INTENSET) Interrupt Enable Set  Reset Value */

#define MCLK_INTENSET_CKRDY_Pos               _UINT32_(0)                                          /* (MCLK_INTENSET) Clock Ready Interrupt Enable Position */
#define MCLK_INTENSET_CKRDY_Msk               (_UINT32_(0x1) << MCLK_INTENSET_CKRDY_Pos)           /* (MCLK_INTENSET) Clock Ready Interrupt Enable Mask */
#define MCLK_INTENSET_CKRDY(value)            (MCLK_INTENSET_CKRDY_Msk & (_UINT32_(value) << MCLK_INTENSET_CKRDY_Pos)) /* Assigment of value for CKRDY in the MCLK_INTENSET register */
#define MCLK_INTENSET_Msk                     _UINT32_(0x00000001)                                 /* (MCLK_INTENSET) Register Mask  */


/* -------- MCLK_INTFLAG : (MCLK Offset: 0x08) (R/W 32) Interrupt Flag Status and Clear -------- */
#define MCLK_INTFLAG_RESETVALUE               _UINT32_(0x01)                                       /*  (MCLK_INTFLAG) Interrupt Flag Status and Clear  Reset Value */

#define MCLK_INTFLAG_CKRDY_Pos                _UINT32_(0)                                          /* (MCLK_INTFLAG) Clock Ready Position */
#define MCLK_INTFLAG_CKRDY_Msk                (_UINT32_(0x1) << MCLK_INTFLAG_CKRDY_Pos)            /* (MCLK_INTFLAG) Clock Ready Mask */
#define MCLK_INTFLAG_CKRDY(value)             (MCLK_INTFLAG_CKRDY_Msk & (_UINT32_(value) << MCLK_INTFLAG_CKRDY_Pos)) /* Assigment of value for CKRDY in the MCLK_INTFLAG register */
#define MCLK_INTFLAG_Msk                      _UINT32_(0x00000001)                                 /* (MCLK_INTFLAG) Register Mask  */


/* -------- MCLK_CLKDIV : (MCLK Offset: 0x0C) (R/W 32) Clock Divider Control -------- */
#define MCLK_CLKDIV_RESETVALUE                _UINT32_(0x00)                                       /*  (MCLK_CLKDIV) Clock Divider Control  Reset Value */

#define MCLK_CLKDIV_DIV_Pos                   _UINT32_(0)                                          /* (MCLK_CLKDIV) Clock Domain Division Factor Position */
#define MCLK_CLKDIV_DIV_Msk                   (_UINT32_(0xFF) << MCLK_CLKDIV_DIV_Pos)              /* (MCLK_CLKDIV) Clock Domain Division Factor Mask */
#define MCLK_CLKDIV_DIV(value)                (MCLK_CLKDIV_DIV_Msk & (_UINT32_(value) << MCLK_CLKDIV_DIV_Pos)) /* Assigment of value for DIV in the MCLK_CLKDIV register */
#define   MCLK_CLKDIV_DIV_DIV1_Val            _UINT32_(0x1)                                        /* (MCLK_CLKDIV) Divide by 1  */
#define   MCLK_CLKDIV_DIV_DIV2_Val            _UINT32_(0x2)                                        /* (MCLK_CLKDIV) Divide by 2  */
#define   MCLK_CLKDIV_DIV_DIV4_Val            _UINT32_(0x4)                                        /* (MCLK_CLKDIV) Divide by 4  */
#define   MCLK_CLKDIV_DIV_DIV8_Val            _UINT32_(0x8)                                        /* (MCLK_CLKDIV) Divide by 8  */
#define   MCLK_CLKDIV_DIV_DIV16_Val           _UINT32_(0x10)                                       /* (MCLK_CLKDIV) Divide by 16  */
#define   MCLK_CLKDIV_DIV_DIV32_Val           _UINT32_(0x20)                                       /* (MCLK_CLKDIV) Divide by 32  */
#define   MCLK_CLKDIV_DIV_DIV64_Val           _UINT32_(0x40)                                       /* (MCLK_CLKDIV) Divide by 64  */
#define   MCLK_CLKDIV_DIV_DIV128_Val          _UINT32_(0x80)                                       /* (MCLK_CLKDIV) Divide by 128  */
#define MCLK_CLKDIV_DIV_DIV1                  (MCLK_CLKDIV_DIV_DIV1_Val << MCLK_CLKDIV_DIV_Pos)    /* (MCLK_CLKDIV) Divide by 1 Position  */
#define MCLK_CLKDIV_DIV_DIV2                  (MCLK_CLKDIV_DIV_DIV2_Val << MCLK_CLKDIV_DIV_Pos)    /* (MCLK_CLKDIV) Divide by 2 Position  */
#define MCLK_CLKDIV_DIV_DIV4                  (MCLK_CLKDIV_DIV_DIV4_Val << MCLK_CLKDIV_DIV_Pos)    /* (MCLK_CLKDIV) Divide by 4 Position  */
#define MCLK_CLKDIV_DIV_DIV8                  (MCLK_CLKDIV_DIV_DIV8_Val << MCLK_CLKDIV_DIV_Pos)    /* (MCLK_CLKDIV) Divide by 8 Position  */
#define MCLK_CLKDIV_DIV_DIV16                 (MCLK_CLKDIV_DIV_DIV16_Val << MCLK_CLKDIV_DIV_Pos)   /* (MCLK_CLKDIV) Divide by 16 Position  */
#define MCLK_CLKDIV_DIV_DIV32                 (MCLK_CLKDIV_DIV_DIV32_Val << MCLK_CLKDIV_DIV_Pos)   /* (MCLK_CLKDIV) Divide by 32 Position  */
#define MCLK_CLKDIV_DIV_DIV64                 (MCLK_CLKDIV_DIV_DIV64_Val << MCLK_CLKDIV_DIV_Pos)   /* (MCLK_CLKDIV) Divide by 64 Position  */
#define MCLK_CLKDIV_DIV_DIV128                (MCLK_CLKDIV_DIV_DIV128_Val << MCLK_CLKDIV_DIV_Pos)  /* (MCLK_CLKDIV) Divide by 128 Position  */
#define MCLK_CLKDIV_Msk                       _UINT32_(0x000000FF)                                 /* (MCLK_CLKDIV) Register Mask  */


/* -------- MCLK_CLKMSK : (MCLK Offset: 0x3C) (R/W 32) Peripheral Clock Enable Mask -------- */
#define MCLK_CLKMSK_RESETVALUE                _UINT32_(0x00)                                       /*  (MCLK_CLKMSK) Peripheral Clock Enable Mask  Reset Value */

#define MCLK_CLKMSK_MASK_Pos                  _UINT32_(0)                                          /* (MCLK_CLKMSK) Peripheral Clock Enable Mask Position */
#define MCLK_CLKMSK_MASK_Msk                  (_UINT32_(0xFFFFFFFF) << MCLK_CLKMSK_MASK_Pos)       /* (MCLK_CLKMSK) Peripheral Clock Enable Mask Mask */
#define MCLK_CLKMSK_MASK(value)               (MCLK_CLKMSK_MASK_Msk & (_UINT32_(value) << MCLK_CLKMSK_MASK_Pos)) /* Assigment of value for MASK in the MCLK_CLKMSK register */
#define MCLK_CLKMSK_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (MCLK_CLKMSK) Register Mask  */


/** \brief MCLK register offsets definitions */
#define MCLK_INTENCLR_REG_OFST         _UINT32_(0x00)      /* (MCLK_INTENCLR) Interrupt Enable Clear Offset */
#define MCLK_INTENSET_REG_OFST         _UINT32_(0x04)      /* (MCLK_INTENSET) Interrupt Enable Set Offset */
#define MCLK_INTFLAG_REG_OFST          _UINT32_(0x08)      /* (MCLK_INTFLAG) Interrupt Flag Status and Clear Offset */
#define MCLK_CLKDIV_REG_OFST           _UINT32_(0x0C)      /* (MCLK_CLKDIV) Clock Divider Control Offset */
#define MCLK_CLKDIV0_REG_OFST          _UINT32_(0x0C)      /* (MCLK_CLKDIV0) Clock Divider Control Offset */
#define MCLK_CLKDIV1_REG_OFST          _UINT32_(0x10)      /* (MCLK_CLKDIV1) Clock Divider Control Offset */
#define MCLK_CLKMSK_REG_OFST           _UINT32_(0x3C)      /* (MCLK_CLKMSK) Peripheral Clock Enable Mask Offset */
#define MCLK_CLKMSK0_REG_OFST          _UINT32_(0x3C)      /* (MCLK_CLKMSK0) Peripheral Clock Enable Mask Offset */
#define MCLK_CLKMSK1_REG_OFST          _UINT32_(0x40)      /* (MCLK_CLKMSK1) Peripheral Clock Enable Mask Offset */
#define MCLK_CLKMSK2_REG_OFST          _UINT32_(0x44)      /* (MCLK_CLKMSK2) Peripheral Clock Enable Mask Offset */
#define MCLK_CLKMSK3_REG_OFST          _UINT32_(0x48)      /* (MCLK_CLKMSK3) Peripheral Clock Enable Mask Offset */
#define MCLK_CLKMSK4_REG_OFST          _UINT32_(0x4C)      /* (MCLK_CLKMSK4) Peripheral Clock Enable Mask Offset */
#define MCLK_CLKMSK5_REG_OFST          _UINT32_(0x50)      /* (MCLK_CLKMSK5) Peripheral Clock Enable Mask Offset */
#define MCLK_CLKMSK6_REG_OFST          _UINT32_(0x54)      /* (MCLK_CLKMSK6) Peripheral Clock Enable Mask Offset */
#define MCLK_CLKMSK7_REG_OFST          _UINT32_(0x58)      /* (MCLK_CLKMSK7) Peripheral Clock Enable Mask Offset */
#define MCLK_CLKMSK8_REG_OFST          _UINT32_(0x5C)      /* (MCLK_CLKMSK8) Peripheral Clock Enable Mask Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief MCLK register API structure */
typedef struct
{  /* Main Clock */
  __IO  uint32_t                       MCLK_INTENCLR;      /**< Offset: 0x00 (R/W  32) Interrupt Enable Clear */
  __IO  uint32_t                       MCLK_INTENSET;      /**< Offset: 0x04 (R/W  32) Interrupt Enable Set */
  __IO  uint32_t                       MCLK_INTFLAG;       /**< Offset: 0x08 (R/W  32) Interrupt Flag Status and Clear */
  __IO  uint32_t                       MCLK_CLKDIV[2];     /**< Offset: 0x0C (R/W  32) Clock Divider Control */
  __I   uint8_t                        Reserved1[0x28];
  __IO  uint32_t                       MCLK_CLKMSK[9];     /**< Offset: 0x3C (R/W  32) Peripheral Clock Enable Mask */
} mclk_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA90_MCLK_COMPONENT_H_ */
