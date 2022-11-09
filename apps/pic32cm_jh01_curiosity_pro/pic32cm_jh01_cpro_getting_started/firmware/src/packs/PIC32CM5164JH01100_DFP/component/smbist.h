/*
 * Component description for SMBIST
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

/* file generated from device description version 2022-05-20T08:40:47Z */
#ifndef _PIC32CMJH01_SMBIST_COMPONENT_H_
#define _PIC32CMJH01_SMBIST_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR SMBIST                                       */
/* ************************************************************************** */

/* -------- SMBIST_CTRL : (SMBIST Offset: 0x00) (R/W 32) Control -------- */
#define SMBIST_CTRL_RESETVALUE                _UINT32_(0x00)                                       /*  (SMBIST_CTRL) Control  Reset Value */

#define SMBIST_CTRL_SMBISTP1_Pos              _UINT32_(0)                                          /* (SMBIST_CTRL) SRAM MBIST Partition 1 test start Position */
#define SMBIST_CTRL_SMBISTP1_Msk              (_UINT32_(0x1) << SMBIST_CTRL_SMBISTP1_Pos)          /* (SMBIST_CTRL) SRAM MBIST Partition 1 test start Mask */
#define SMBIST_CTRL_SMBISTP1(value)           (SMBIST_CTRL_SMBISTP1_Msk & (_UINT32_(value) << SMBIST_CTRL_SMBISTP1_Pos)) /* Assigment of value for SMBISTP1 in the SMBIST_CTRL register */
#define SMBIST_CTRL_SMBISTP2_Pos              _UINT32_(1)                                          /* (SMBIST_CTRL) SRAM MBIST Partition 2 test start Position */
#define SMBIST_CTRL_SMBISTP2_Msk              (_UINT32_(0x1) << SMBIST_CTRL_SMBISTP2_Pos)          /* (SMBIST_CTRL) SRAM MBIST Partition 2 test start Mask */
#define SMBIST_CTRL_SMBISTP2(value)           (SMBIST_CTRL_SMBISTP2_Msk & (_UINT32_(value) << SMBIST_CTRL_SMBISTP2_Pos)) /* Assigment of value for SMBISTP2 in the SMBIST_CTRL register */
#define SMBIST_CTRL_Msk                       _UINT32_(0x00000003)                                 /* (SMBIST_CTRL) Register Mask  */

#define SMBIST_CTRL_SMBISTP_Pos               _UINT32_(0)                                          /* (SMBIST_CTRL Position) SRAM MBIST Partition 2 test start */
#define SMBIST_CTRL_SMBISTP_Msk               (_UINT32_(0x3) << SMBIST_CTRL_SMBISTP_Pos)           /* (SMBIST_CTRL Mask) SMBISTP */
#define SMBIST_CTRL_SMBISTP(value)            (SMBIST_CTRL_SMBISTP_Msk & (_UINT32_(value) << SMBIST_CTRL_SMBISTP_Pos)) 

/* -------- SMBIST_STATUS : (SMBIST Offset: 0x04) (R/W 32) Status -------- */
#define SMBIST_STATUS_RESETVALUE              _UINT32_(0x00)                                       /*  (SMBIST_STATUS) Status  Reset Value */

#define SMBIST_STATUS_DONE_Pos                _UINT32_(0)                                          /* (SMBIST_STATUS) Done Position */
#define SMBIST_STATUS_DONE_Msk                (_UINT32_(0x1) << SMBIST_STATUS_DONE_Pos)            /* (SMBIST_STATUS) Done Mask */
#define SMBIST_STATUS_DONE(value)             (SMBIST_STATUS_DONE_Msk & (_UINT32_(value) << SMBIST_STATUS_DONE_Pos)) /* Assigment of value for DONE in the SMBIST_STATUS register */
#define SMBIST_STATUS_FAIL_Pos                _UINT32_(1)                                          /* (SMBIST_STATUS) Fail Position */
#define SMBIST_STATUS_FAIL_Msk                (_UINT32_(0x1) << SMBIST_STATUS_FAIL_Pos)            /* (SMBIST_STATUS) Fail Mask */
#define SMBIST_STATUS_FAIL(value)             (SMBIST_STATUS_FAIL_Msk & (_UINT32_(value) << SMBIST_STATUS_FAIL_Pos)) /* Assigment of value for FAIL in the SMBIST_STATUS register */
#define SMBIST_STATUS_Msk                     _UINT32_(0x00000003)                                 /* (SMBIST_STATUS) Register Mask  */


/** \brief SMBIST register offsets definitions */
#define SMBIST_CTRL_REG_OFST           _UINT32_(0x00)      /* (SMBIST_CTRL) Control Offset */
#define SMBIST_STATUS_REG_OFST         _UINT32_(0x04)      /* (SMBIST_STATUS) Status Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief SMBIST register API structure */
typedef struct
{  /* SRAM MBIST Interface */
  __IO  uint32_t                       SMBIST_CTRL;        /**< Offset: 0x00 (R/W  32) Control */
  __IO  uint32_t                       SMBIST_STATUS;      /**< Offset: 0x04 (R/W  32) Status */
} smbist_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CMJH01_SMBIST_COMPONENT_H_ */
