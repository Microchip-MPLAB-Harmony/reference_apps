/*
 * Component description for GPBR
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
#ifndef _SAM9X7_GPBR_COMPONENT_H_
#define _SAM9X7_GPBR_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR GPBR                                         */
/* ************************************************************************** */

/* -------- GPBR_MR : (GPBR Offset: 0x00) (R/W 32) GPBR Mode Register -------- */
#define GPBR_MR_RESETVALUE                    _UINT32_(0x00)                                       /*  (GPBR_MR) GPBR Mode Register  Reset Value */

#define GPBR_MR_GPBRWP0_Pos                   _UINT32_(0)                                          /* (GPBR_MR) GPBRx Write Protection Position */
#define GPBR_MR_GPBRWP0_Msk                   (_UINT32_(0x1) << GPBR_MR_GPBRWP0_Pos)               /* (GPBR_MR) GPBRx Write Protection Mask */
#define GPBR_MR_GPBRWP0(value)                (GPBR_MR_GPBRWP0_Msk & (_UINT32_(value) << GPBR_MR_GPBRWP0_Pos)) /* Assigment of value for GPBRWP0 in the GPBR_MR register */
#define   GPBR_MR_GPBRWP0_0_Val               _UINT32_(0x0)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) can be written.  */
#define   GPBR_MR_GPBRWP0_1_Val               _UINT32_(0x1)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) is write-protected.  */
#define GPBR_MR_GPBRWP0_0                     (GPBR_MR_GPBRWP0_0_Val << GPBR_MR_GPBRWP0_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) can be written. Position  */
#define GPBR_MR_GPBRWP0_1                     (GPBR_MR_GPBRWP0_1_Val << GPBR_MR_GPBRWP0_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) is write-protected. Position  */
#define GPBR_MR_GPBRWP1_Pos                   _UINT32_(1)                                          /* (GPBR_MR) GPBRx Write Protection Position */
#define GPBR_MR_GPBRWP1_Msk                   (_UINT32_(0x1) << GPBR_MR_GPBRWP1_Pos)               /* (GPBR_MR) GPBRx Write Protection Mask */
#define GPBR_MR_GPBRWP1(value)                (GPBR_MR_GPBRWP1_Msk & (_UINT32_(value) << GPBR_MR_GPBRWP1_Pos)) /* Assigment of value for GPBRWP1 in the GPBR_MR register */
#define   GPBR_MR_GPBRWP1_0_Val               _UINT32_(0x0)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) can be written.  */
#define   GPBR_MR_GPBRWP1_1_Val               _UINT32_(0x1)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) is write-protected.  */
#define GPBR_MR_GPBRWP1_0                     (GPBR_MR_GPBRWP1_0_Val << GPBR_MR_GPBRWP1_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) can be written. Position  */
#define GPBR_MR_GPBRWP1_1                     (GPBR_MR_GPBRWP1_1_Val << GPBR_MR_GPBRWP1_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) is write-protected. Position  */
#define GPBR_MR_GPBRWP2_Pos                   _UINT32_(2)                                          /* (GPBR_MR) GPBRx Write Protection Position */
#define GPBR_MR_GPBRWP2_Msk                   (_UINT32_(0x1) << GPBR_MR_GPBRWP2_Pos)               /* (GPBR_MR) GPBRx Write Protection Mask */
#define GPBR_MR_GPBRWP2(value)                (GPBR_MR_GPBRWP2_Msk & (_UINT32_(value) << GPBR_MR_GPBRWP2_Pos)) /* Assigment of value for GPBRWP2 in the GPBR_MR register */
#define   GPBR_MR_GPBRWP2_0_Val               _UINT32_(0x0)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) can be written.  */
#define   GPBR_MR_GPBRWP2_1_Val               _UINT32_(0x1)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) is write-protected.  */
#define GPBR_MR_GPBRWP2_0                     (GPBR_MR_GPBRWP2_0_Val << GPBR_MR_GPBRWP2_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) can be written. Position  */
#define GPBR_MR_GPBRWP2_1                     (GPBR_MR_GPBRWP2_1_Val << GPBR_MR_GPBRWP2_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) is write-protected. Position  */
#define GPBR_MR_GPBRWP3_Pos                   _UINT32_(3)                                          /* (GPBR_MR) GPBRx Write Protection Position */
#define GPBR_MR_GPBRWP3_Msk                   (_UINT32_(0x1) << GPBR_MR_GPBRWP3_Pos)               /* (GPBR_MR) GPBRx Write Protection Mask */
#define GPBR_MR_GPBRWP3(value)                (GPBR_MR_GPBRWP3_Msk & (_UINT32_(value) << GPBR_MR_GPBRWP3_Pos)) /* Assigment of value for GPBRWP3 in the GPBR_MR register */
#define   GPBR_MR_GPBRWP3_0_Val               _UINT32_(0x0)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) can be written.  */
#define   GPBR_MR_GPBRWP3_1_Val               _UINT32_(0x1)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) is write-protected.  */
#define GPBR_MR_GPBRWP3_0                     (GPBR_MR_GPBRWP3_0_Val << GPBR_MR_GPBRWP3_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) can be written. Position  */
#define GPBR_MR_GPBRWP3_1                     (GPBR_MR_GPBRWP3_1_Val << GPBR_MR_GPBRWP3_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) is write-protected. Position  */
#define GPBR_MR_GPBRWP4_Pos                   _UINT32_(4)                                          /* (GPBR_MR) GPBRx Write Protection Position */
#define GPBR_MR_GPBRWP4_Msk                   (_UINT32_(0x1) << GPBR_MR_GPBRWP4_Pos)               /* (GPBR_MR) GPBRx Write Protection Mask */
#define GPBR_MR_GPBRWP4(value)                (GPBR_MR_GPBRWP4_Msk & (_UINT32_(value) << GPBR_MR_GPBRWP4_Pos)) /* Assigment of value for GPBRWP4 in the GPBR_MR register */
#define   GPBR_MR_GPBRWP4_0_Val               _UINT32_(0x0)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) can be written.  */
#define   GPBR_MR_GPBRWP4_1_Val               _UINT32_(0x1)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) is write-protected.  */
#define GPBR_MR_GPBRWP4_0                     (GPBR_MR_GPBRWP4_0_Val << GPBR_MR_GPBRWP4_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) can be written. Position  */
#define GPBR_MR_GPBRWP4_1                     (GPBR_MR_GPBRWP4_1_Val << GPBR_MR_GPBRWP4_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) is write-protected. Position  */
#define GPBR_MR_GPBRWP5_Pos                   _UINT32_(5)                                          /* (GPBR_MR) GPBRx Write Protection Position */
#define GPBR_MR_GPBRWP5_Msk                   (_UINT32_(0x1) << GPBR_MR_GPBRWP5_Pos)               /* (GPBR_MR) GPBRx Write Protection Mask */
#define GPBR_MR_GPBRWP5(value)                (GPBR_MR_GPBRWP5_Msk & (_UINT32_(value) << GPBR_MR_GPBRWP5_Pos)) /* Assigment of value for GPBRWP5 in the GPBR_MR register */
#define   GPBR_MR_GPBRWP5_0_Val               _UINT32_(0x0)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) can be written.  */
#define   GPBR_MR_GPBRWP5_1_Val               _UINT32_(0x1)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) is write-protected.  */
#define GPBR_MR_GPBRWP5_0                     (GPBR_MR_GPBRWP5_0_Val << GPBR_MR_GPBRWP5_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) can be written. Position  */
#define GPBR_MR_GPBRWP5_1                     (GPBR_MR_GPBRWP5_1_Val << GPBR_MR_GPBRWP5_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) is write-protected. Position  */
#define GPBR_MR_GPBRWP6_Pos                   _UINT32_(6)                                          /* (GPBR_MR) GPBRx Write Protection Position */
#define GPBR_MR_GPBRWP6_Msk                   (_UINT32_(0x1) << GPBR_MR_GPBRWP6_Pos)               /* (GPBR_MR) GPBRx Write Protection Mask */
#define GPBR_MR_GPBRWP6(value)                (GPBR_MR_GPBRWP6_Msk & (_UINT32_(value) << GPBR_MR_GPBRWP6_Pos)) /* Assigment of value for GPBRWP6 in the GPBR_MR register */
#define   GPBR_MR_GPBRWP6_0_Val               _UINT32_(0x0)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) can be written.  */
#define   GPBR_MR_GPBRWP6_1_Val               _UINT32_(0x1)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) is write-protected.  */
#define GPBR_MR_GPBRWP6_0                     (GPBR_MR_GPBRWP6_0_Val << GPBR_MR_GPBRWP6_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) can be written. Position  */
#define GPBR_MR_GPBRWP6_1                     (GPBR_MR_GPBRWP6_1_Val << GPBR_MR_GPBRWP6_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) is write-protected. Position  */
#define GPBR_MR_GPBRWP7_Pos                   _UINT32_(7)                                          /* (GPBR_MR) GPBRx Write Protection Position */
#define GPBR_MR_GPBRWP7_Msk                   (_UINT32_(0x1) << GPBR_MR_GPBRWP7_Pos)               /* (GPBR_MR) GPBRx Write Protection Mask */
#define GPBR_MR_GPBRWP7(value)                (GPBR_MR_GPBRWP7_Msk & (_UINT32_(value) << GPBR_MR_GPBRWP7_Pos)) /* Assigment of value for GPBRWP7 in the GPBR_MR register */
#define   GPBR_MR_GPBRWP7_0_Val               _UINT32_(0x0)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) can be written.  */
#define   GPBR_MR_GPBRWP7_1_Val               _UINT32_(0x1)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) is write-protected.  */
#define GPBR_MR_GPBRWP7_0                     (GPBR_MR_GPBRWP7_0_Val << GPBR_MR_GPBRWP7_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) can be written. Position  */
#define GPBR_MR_GPBRWP7_1                     (GPBR_MR_GPBRWP7_1_Val << GPBR_MR_GPBRWP7_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) is write-protected. Position  */
#define GPBR_MR_GPBRRP0_Pos                   _UINT32_(16)                                         /* (GPBR_MR) GPBRx Read Protection Position */
#define GPBR_MR_GPBRRP0_Msk                   (_UINT32_(0x1) << GPBR_MR_GPBRRP0_Pos)               /* (GPBR_MR) GPBRx Read Protection Mask */
#define GPBR_MR_GPBRRP0(value)                (GPBR_MR_GPBRRP0_Msk & (_UINT32_(value) << GPBR_MR_GPBRRP0_Pos)) /* Assigment of value for GPBRRP0 in the GPBR_MR register */
#define   GPBR_MR_GPBRRP0_0_Val               _UINT32_(0x0)                                        /* (GPBR_MR) The content of the corresponding GPBR register (32-bit part-select) can be read.  */
#define   GPBR_MR_GPBRRP0_1_Val               _UINT32_(0x1)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) always returns zero when read.  */
#define GPBR_MR_GPBRRP0_0                     (GPBR_MR_GPBRRP0_0_Val << GPBR_MR_GPBRRP0_Pos)       /* (GPBR_MR) The content of the corresponding GPBR register (32-bit part-select) can be read. Position  */
#define GPBR_MR_GPBRRP0_1                     (GPBR_MR_GPBRRP0_1_Val << GPBR_MR_GPBRRP0_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) always returns zero when read. Position  */
#define GPBR_MR_GPBRRP1_Pos                   _UINT32_(17)                                         /* (GPBR_MR) GPBRx Read Protection Position */
#define GPBR_MR_GPBRRP1_Msk                   (_UINT32_(0x1) << GPBR_MR_GPBRRP1_Pos)               /* (GPBR_MR) GPBRx Read Protection Mask */
#define GPBR_MR_GPBRRP1(value)                (GPBR_MR_GPBRRP1_Msk & (_UINT32_(value) << GPBR_MR_GPBRRP1_Pos)) /* Assigment of value for GPBRRP1 in the GPBR_MR register */
#define   GPBR_MR_GPBRRP1_0_Val               _UINT32_(0x0)                                        /* (GPBR_MR) The content of the corresponding GPBR register (32-bit part-select) can be read.  */
#define   GPBR_MR_GPBRRP1_1_Val               _UINT32_(0x1)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) always returns zero when read.  */
#define GPBR_MR_GPBRRP1_0                     (GPBR_MR_GPBRRP1_0_Val << GPBR_MR_GPBRRP1_Pos)       /* (GPBR_MR) The content of the corresponding GPBR register (32-bit part-select) can be read. Position  */
#define GPBR_MR_GPBRRP1_1                     (GPBR_MR_GPBRRP1_1_Val << GPBR_MR_GPBRRP1_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) always returns zero when read. Position  */
#define GPBR_MR_GPBRRP2_Pos                   _UINT32_(18)                                         /* (GPBR_MR) GPBRx Read Protection Position */
#define GPBR_MR_GPBRRP2_Msk                   (_UINT32_(0x1) << GPBR_MR_GPBRRP2_Pos)               /* (GPBR_MR) GPBRx Read Protection Mask */
#define GPBR_MR_GPBRRP2(value)                (GPBR_MR_GPBRRP2_Msk & (_UINT32_(value) << GPBR_MR_GPBRRP2_Pos)) /* Assigment of value for GPBRRP2 in the GPBR_MR register */
#define   GPBR_MR_GPBRRP2_0_Val               _UINT32_(0x0)                                        /* (GPBR_MR) The content of the corresponding GPBR register (32-bit part-select) can be read.  */
#define   GPBR_MR_GPBRRP2_1_Val               _UINT32_(0x1)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) always returns zero when read.  */
#define GPBR_MR_GPBRRP2_0                     (GPBR_MR_GPBRRP2_0_Val << GPBR_MR_GPBRRP2_Pos)       /* (GPBR_MR) The content of the corresponding GPBR register (32-bit part-select) can be read. Position  */
#define GPBR_MR_GPBRRP2_1                     (GPBR_MR_GPBRRP2_1_Val << GPBR_MR_GPBRRP2_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) always returns zero when read. Position  */
#define GPBR_MR_GPBRRP3_Pos                   _UINT32_(19)                                         /* (GPBR_MR) GPBRx Read Protection Position */
#define GPBR_MR_GPBRRP3_Msk                   (_UINT32_(0x1) << GPBR_MR_GPBRRP3_Pos)               /* (GPBR_MR) GPBRx Read Protection Mask */
#define GPBR_MR_GPBRRP3(value)                (GPBR_MR_GPBRRP3_Msk & (_UINT32_(value) << GPBR_MR_GPBRRP3_Pos)) /* Assigment of value for GPBRRP3 in the GPBR_MR register */
#define   GPBR_MR_GPBRRP3_0_Val               _UINT32_(0x0)                                        /* (GPBR_MR) The content of the corresponding GPBR register (32-bit part-select) can be read.  */
#define   GPBR_MR_GPBRRP3_1_Val               _UINT32_(0x1)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) always returns zero when read.  */
#define GPBR_MR_GPBRRP3_0                     (GPBR_MR_GPBRRP3_0_Val << GPBR_MR_GPBRRP3_Pos)       /* (GPBR_MR) The content of the corresponding GPBR register (32-bit part-select) can be read. Position  */
#define GPBR_MR_GPBRRP3_1                     (GPBR_MR_GPBRRP3_1_Val << GPBR_MR_GPBRRP3_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) always returns zero when read. Position  */
#define GPBR_MR_GPBRRP4_Pos                   _UINT32_(20)                                         /* (GPBR_MR) GPBRx Read Protection Position */
#define GPBR_MR_GPBRRP4_Msk                   (_UINT32_(0x1) << GPBR_MR_GPBRRP4_Pos)               /* (GPBR_MR) GPBRx Read Protection Mask */
#define GPBR_MR_GPBRRP4(value)                (GPBR_MR_GPBRRP4_Msk & (_UINT32_(value) << GPBR_MR_GPBRRP4_Pos)) /* Assigment of value for GPBRRP4 in the GPBR_MR register */
#define   GPBR_MR_GPBRRP4_0_Val               _UINT32_(0x0)                                        /* (GPBR_MR) The content of the corresponding GPBR register (32-bit part-select) can be read.  */
#define   GPBR_MR_GPBRRP4_1_Val               _UINT32_(0x1)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) always returns zero when read.  */
#define GPBR_MR_GPBRRP4_0                     (GPBR_MR_GPBRRP4_0_Val << GPBR_MR_GPBRRP4_Pos)       /* (GPBR_MR) The content of the corresponding GPBR register (32-bit part-select) can be read. Position  */
#define GPBR_MR_GPBRRP4_1                     (GPBR_MR_GPBRRP4_1_Val << GPBR_MR_GPBRRP4_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) always returns zero when read. Position  */
#define GPBR_MR_GPBRRP5_Pos                   _UINT32_(21)                                         /* (GPBR_MR) GPBRx Read Protection Position */
#define GPBR_MR_GPBRRP5_Msk                   (_UINT32_(0x1) << GPBR_MR_GPBRRP5_Pos)               /* (GPBR_MR) GPBRx Read Protection Mask */
#define GPBR_MR_GPBRRP5(value)                (GPBR_MR_GPBRRP5_Msk & (_UINT32_(value) << GPBR_MR_GPBRRP5_Pos)) /* Assigment of value for GPBRRP5 in the GPBR_MR register */
#define   GPBR_MR_GPBRRP5_0_Val               _UINT32_(0x0)                                        /* (GPBR_MR) The content of the corresponding GPBR register (32-bit part-select) can be read.  */
#define   GPBR_MR_GPBRRP5_1_Val               _UINT32_(0x1)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) always returns zero when read.  */
#define GPBR_MR_GPBRRP5_0                     (GPBR_MR_GPBRRP5_0_Val << GPBR_MR_GPBRRP5_Pos)       /* (GPBR_MR) The content of the corresponding GPBR register (32-bit part-select) can be read. Position  */
#define GPBR_MR_GPBRRP5_1                     (GPBR_MR_GPBRRP5_1_Val << GPBR_MR_GPBRRP5_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) always returns zero when read. Position  */
#define GPBR_MR_GPBRRP6_Pos                   _UINT32_(22)                                         /* (GPBR_MR) GPBRx Read Protection Position */
#define GPBR_MR_GPBRRP6_Msk                   (_UINT32_(0x1) << GPBR_MR_GPBRRP6_Pos)               /* (GPBR_MR) GPBRx Read Protection Mask */
#define GPBR_MR_GPBRRP6(value)                (GPBR_MR_GPBRRP6_Msk & (_UINT32_(value) << GPBR_MR_GPBRRP6_Pos)) /* Assigment of value for GPBRRP6 in the GPBR_MR register */
#define   GPBR_MR_GPBRRP6_0_Val               _UINT32_(0x0)                                        /* (GPBR_MR) The content of the corresponding GPBR register (32-bit part-select) can be read.  */
#define   GPBR_MR_GPBRRP6_1_Val               _UINT32_(0x1)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) always returns zero when read.  */
#define GPBR_MR_GPBRRP6_0                     (GPBR_MR_GPBRRP6_0_Val << GPBR_MR_GPBRRP6_Pos)       /* (GPBR_MR) The content of the corresponding GPBR register (32-bit part-select) can be read. Position  */
#define GPBR_MR_GPBRRP6_1                     (GPBR_MR_GPBRRP6_1_Val << GPBR_MR_GPBRRP6_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) always returns zero when read. Position  */
#define GPBR_MR_GPBRRP7_Pos                   _UINT32_(23)                                         /* (GPBR_MR) GPBRx Read Protection Position */
#define GPBR_MR_GPBRRP7_Msk                   (_UINT32_(0x1) << GPBR_MR_GPBRRP7_Pos)               /* (GPBR_MR) GPBRx Read Protection Mask */
#define GPBR_MR_GPBRRP7(value)                (GPBR_MR_GPBRRP7_Msk & (_UINT32_(value) << GPBR_MR_GPBRRP7_Pos)) /* Assigment of value for GPBRRP7 in the GPBR_MR register */
#define   GPBR_MR_GPBRRP7_0_Val               _UINT32_(0x0)                                        /* (GPBR_MR) The content of the corresponding GPBR register (32-bit part-select) can be read.  */
#define   GPBR_MR_GPBRRP7_1_Val               _UINT32_(0x1)                                        /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) always returns zero when read.  */
#define GPBR_MR_GPBRRP7_0                     (GPBR_MR_GPBRRP7_0_Val << GPBR_MR_GPBRRP7_Pos)       /* (GPBR_MR) The content of the corresponding GPBR register (32-bit part-select) can be read. Position  */
#define GPBR_MR_GPBRRP7_1                     (GPBR_MR_GPBRRP7_1_Val << GPBR_MR_GPBRRP7_Pos)       /* (GPBR_MR) The corresponding GPBR register (32-bit part-select) always returns zero when read. Position  */
#define GPBR_MR_Msk                           _UINT32_(0x00FF00FF)                                 /* (GPBR_MR) Register Mask  */

#define GPBR_MR_GPBRWP_Pos                    _UINT32_(0)                                          /* (GPBR_MR Position) GPBRx Write Protection */
#define GPBR_MR_GPBRWP_Msk                    (_UINT32_(0xFF) << GPBR_MR_GPBRWP_Pos)               /* (GPBR_MR Mask) GPBRWP */
#define GPBR_MR_GPBRWP(value)                 (GPBR_MR_GPBRWP_Msk & (_UINT32_(value) << GPBR_MR_GPBRWP_Pos)) 
#define GPBR_MR_GPBRRP_Pos                    _UINT32_(16)                                         /* (GPBR_MR Position) GPBRx Read Protection */
#define GPBR_MR_GPBRRP_Msk                    (_UINT32_(0xFF) << GPBR_MR_GPBRRP_Pos)               /* (GPBR_MR Mask) GPBRRP */
#define GPBR_MR_GPBRRP(value)                 (GPBR_MR_GPBRRP_Msk & (_UINT32_(value) << GPBR_MR_GPBRRP_Pos)) 

/* -------- GPBR_FCLR : (GPBR Offset: 0x04) (R/W 32) GPBR Full Clear Register -------- */
#define GPBR_FCLR_RESETVALUE                  _UINT32_(0x00)                                       /*  (GPBR_FCLR) GPBR Full Clear Register  Reset Value */

#define GPBR_FCLR_FCLR_Pos                    _UINT32_(0)                                          /* (GPBR_FCLR) Full Clear Enable Position */
#define GPBR_FCLR_FCLR_Msk                    (_UINT32_(0x1) << GPBR_FCLR_FCLR_Pos)                /* (GPBR_FCLR) Full Clear Enable Mask */
#define GPBR_FCLR_FCLR(value)                 (GPBR_FCLR_FCLR_Msk & (_UINT32_(value) << GPBR_FCLR_FCLR_Pos)) /* Assigment of value for FCLR in the GPBR_FCLR register */
#define   GPBR_FCLR_FCLR_0_Val                _UINT32_(0x0)                                        /* (GPBR_FCLR) SYS_GPBR0 to SYS_GPBR3 are immediately cleared in case of fast wakeup pin tamper event.  */
#define   GPBR_FCLR_FCLR_1_Val                _UINT32_(0x1)                                        /* (GPBR_FCLR) All SYS_GPBRx are immediately cleared in case of fast wakeup pin tamper event.  */
#define GPBR_FCLR_FCLR_0                      (GPBR_FCLR_FCLR_0_Val << GPBR_FCLR_FCLR_Pos)         /* (GPBR_FCLR) SYS_GPBR0 to SYS_GPBR3 are immediately cleared in case of fast wakeup pin tamper event. Position  */
#define GPBR_FCLR_FCLR_1                      (GPBR_FCLR_FCLR_1_Val << GPBR_FCLR_FCLR_Pos)         /* (GPBR_FCLR) All SYS_GPBRx are immediately cleared in case of fast wakeup pin tamper event. Position  */
#define GPBR_FCLR_Msk                         _UINT32_(0x00000001)                                 /* (GPBR_FCLR) Register Mask  */


/* -------- SYS_GPBR : (GPBR Offset: 0x08) (R/W 32) General Purpose Backup Register x -------- */
#define SYS_GPBR_RESETVALUE                   _UINT32_(0x00)                                       /*  (SYS_GPBR) General Purpose Backup Register x  Reset Value */

#define SYS_GPBR_GPBR_VALUE_Pos               _UINT32_(0)                                          /* (SYS_GPBR) Value of SYS_GPBRx Position */
#define SYS_GPBR_GPBR_VALUE_Msk               (_UINT32_(0xFFFFFFFF) << SYS_GPBR_GPBR_VALUE_Pos)    /* (SYS_GPBR) Value of SYS_GPBRx Mask */
#define SYS_GPBR_GPBR_VALUE(value)            (SYS_GPBR_GPBR_VALUE_Msk & (_UINT32_(value) << SYS_GPBR_GPBR_VALUE_Pos)) /* Assigment of value for GPBR_VALUE in the SYS_GPBR register */
#define SYS_GPBR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (SYS_GPBR) Register Mask  */


/** \brief GPBR register offsets definitions */
#define GPBR_MR_REG_OFST               _UINT32_(0x00)      /* (GPBR_MR) GPBR Mode Register Offset */
#define GPBR_FCLR_REG_OFST             _UINT32_(0x04)      /* (GPBR_FCLR) GPBR Full Clear Register Offset */
#define SYS_GPBR_REG_OFST              _UINT32_(0x08)      /* (SYS_GPBR) General Purpose Backup Register x Offset */
#define SYS_GPBR0_REG_OFST             _UINT32_(0x08)      /* (SYS_GPBR0) General Purpose Backup Register x Offset */
#define SYS_GPBR1_REG_OFST             _UINT32_(0x0C)      /* (SYS_GPBR1) General Purpose Backup Register x Offset */
#define SYS_GPBR2_REG_OFST             _UINT32_(0x10)      /* (SYS_GPBR2) General Purpose Backup Register x Offset */
#define SYS_GPBR3_REG_OFST             _UINT32_(0x14)      /* (SYS_GPBR3) General Purpose Backup Register x Offset */
#define SYS_GPBR4_REG_OFST             _UINT32_(0x18)      /* (SYS_GPBR4) General Purpose Backup Register x Offset */
#define SYS_GPBR5_REG_OFST             _UINT32_(0x1C)      /* (SYS_GPBR5) General Purpose Backup Register x Offset */
#define SYS_GPBR6_REG_OFST             _UINT32_(0x20)      /* (SYS_GPBR6) General Purpose Backup Register x Offset */
#define SYS_GPBR7_REG_OFST             _UINT32_(0x24)      /* (SYS_GPBR7) General Purpose Backup Register x Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief GPBR register API structure */
typedef struct
{  /* General Purpose Backup Registers */
  __IO  uint32_t                       GPBR_MR;            /**< Offset: 0x00 (R/W  32) GPBR Mode Register */
  __IO  uint32_t                       GPBR_FCLR;          /**< Offset: 0x04 (R/W  32) GPBR Full Clear Register */
  __IO  uint32_t                       SYS_GPBR[8];        /**< Offset: 0x08 (R/W  32) General Purpose Backup Register x */
} gpbr_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X7_GPBR_COMPONENT_H_ */
