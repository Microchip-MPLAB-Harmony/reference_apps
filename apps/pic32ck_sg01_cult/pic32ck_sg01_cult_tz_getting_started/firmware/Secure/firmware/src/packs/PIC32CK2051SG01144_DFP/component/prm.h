/*
 * Component description for PRM
 *
 * Copyright (c) 2023 Microchip Technology Inc. and its subsidiaries.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/* file generated from device description file (ATDF) version 2023-11-16T06:44:02Z */
#ifndef _PIC32CKSG01_PRM_COMPONENT_H_
#define _PIC32CKSG01_PRM_COMPONENT_H_

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
#endif /* _PIC32CKSG01_PRM_COMPONENT_H_ */
