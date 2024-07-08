/*
 * Component description for SIG
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
#ifndef _PIC32CKGC01_SIG_COMPONENT_H_
#define _PIC32CKGC01_SIG_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR SIG                                          */
/* ************************************************************************** */

/* -------- SIG_STIR : (SIG Offset: 0x00) ( /W 32) Software Triggered Interrupt Register -------- */
#define SIG_STIR_INTID_Pos                    _UINT32_(0)                                          /* (SIG_STIR) Interrupt ID to be pended Position */
#define SIG_STIR_INTID_Msk                    (_UINT32_(0x1FF) << SIG_STIR_INTID_Pos)              /* (SIG_STIR) Interrupt ID to be pended Mask */
#define SIG_STIR_INTID(value)                 (SIG_STIR_INTID_Msk & (_UINT32_(value) << SIG_STIR_INTID_Pos)) /* Assigment of value for INTID in the SIG_STIR register */
#define SIG_STIR_Msk                          _UINT32_(0x000001FF)                                 /* (SIG_STIR) Register Mask  */


/** \brief SIG register offsets definitions */
#define SIG_STIR_REG_OFST              _UINT32_(0x00)      /* (SIG_STIR) Software Triggered Interrupt Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief SIG register API structure */
typedef struct
{  /* Software Interrupt Generation */
  __O   uint32_t                       SIG_STIR;           /**< Offset: 0x00 ( /W  32) Software Triggered Interrupt Register */
} sig_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CKGC01_SIG_COMPONENT_H_ */
