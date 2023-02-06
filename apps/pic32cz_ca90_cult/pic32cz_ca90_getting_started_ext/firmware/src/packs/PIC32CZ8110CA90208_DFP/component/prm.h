/*
 * Component description for PRM
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
#ifndef _PIC32CZCA90_PRM_COMPONENT_H_
#define _PIC32CZCA90_PRM_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR PRM                                          */
/* ************************************************************************** */

/* -------- PRM_CTRLA : (PRM Offset: 0x00) (R/W 32) CONTROL A REGISTER -------- */
#define PRM_CTRLA_RESETVALUE                  _UINT32_(0x02)                                       /*  (PRM_CTRLA) CONTROL A REGISTER  Reset Value */

#define PRM_CTRLA_SWRST_Pos                   _UINT32_(0)                                          /* (PRM_CTRLA) SOFTWARE RESET BIT Position */
#define PRM_CTRLA_SWRST_Msk                   (_UINT32_(0x1) << PRM_CTRLA_SWRST_Pos)               /* (PRM_CTRLA) SOFTWARE RESET BIT Mask */
#define PRM_CTRLA_SWRST(value)                (PRM_CTRLA_SWRST_Msk & (_UINT32_(value) << PRM_CTRLA_SWRST_Pos)) /* Assigment of value for SWRST in the PRM_CTRLA register */
#define PRM_CTRLA_ENABLE_Pos                  _UINT32_(1)                                          /* (PRM_CTRLA) ENABLE BIT Position */
#define PRM_CTRLA_ENABLE_Msk                  (_UINT32_(0x1) << PRM_CTRLA_ENABLE_Pos)              /* (PRM_CTRLA) ENABLE BIT Mask */
#define PRM_CTRLA_ENABLE(value)               (PRM_CTRLA_ENABLE_Msk & (_UINT32_(value) << PRM_CTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the PRM_CTRLA register */
#define PRM_CTRLA_PRMWS_Pos                   _UINT32_(8)                                          /* (PRM_CTRLA) ROM ACCESS TIME WAIT STATE Position */
#define PRM_CTRLA_PRMWS_Msk                   (_UINT32_(0x7) << PRM_CTRLA_PRMWS_Pos)               /* (PRM_CTRLA) ROM ACCESS TIME WAIT STATE Mask */
#define PRM_CTRLA_PRMWS(value)                (PRM_CTRLA_PRMWS_Msk & (_UINT32_(value) << PRM_CTRLA_PRMWS_Pos)) /* Assigment of value for PRMWS in the PRM_CTRLA register */
#define PRM_CTRLA_Msk                         _UINT32_(0x00000703)                                 /* (PRM_CTRLA) Register Mask  */


/** \brief PRM register offsets definitions */
#define PRM_CTRLA_REG_OFST             _UINT32_(0x00)      /* (PRM_CTRLA) CONTROL A REGISTER Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief PRM register API structure */
typedef struct
{  /* Boot ROM Controller */
  __IO  uint32_t                       PRM_CTRLA;          /**< Offset: 0x00 (R/W  32) CONTROL A REGISTER */
} prm_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA90_PRM_COMPONENT_H_ */
