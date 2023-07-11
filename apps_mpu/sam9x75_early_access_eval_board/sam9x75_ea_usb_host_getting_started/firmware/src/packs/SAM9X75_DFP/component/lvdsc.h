/*
 * Component description for LVDSC
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
#ifndef _SAM9X7_LVDSC_COMPONENT_H_
#define _SAM9X7_LVDSC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR LVDSC                                        */
/* ************************************************************************** */

/* -------- LVDSC_CR : (LVDSC Offset: 0x00) ( /W 32) Control Register -------- */
#define LVDSC_CR_RESETVALUE                   _UINT32_(0x00)                                       /*  (LVDSC_CR) Control Register  Reset Value */

#define LVDSC_CR_SER_EN_Pos                   _UINT32_(0)                                          /* (LVDSC_CR) LVDS Serializer Enable Position */
#define LVDSC_CR_SER_EN_Msk                   (_UINT32_(0x1) << LVDSC_CR_SER_EN_Pos)               /* (LVDSC_CR) LVDS Serializer Enable Mask */
#define LVDSC_CR_SER_EN(value)                (LVDSC_CR_SER_EN_Msk & (_UINT32_(value) << LVDSC_CR_SER_EN_Pos)) /* Assigment of value for SER_EN in the LVDSC_CR register */
#define   LVDSC_CR_SER_EN_0_Val               _UINT32_(0x0)                                        /* (LVDSC_CR) Disables the serializer of the LVDS.  */
#define   LVDSC_CR_SER_EN_1_Val               _UINT32_(0x1)                                        /* (LVDSC_CR) Enables the serializer of the LVDS.  */
#define LVDSC_CR_SER_EN_0                     (LVDSC_CR_SER_EN_0_Val << LVDSC_CR_SER_EN_Pos)       /* (LVDSC_CR) Disables the serializer of the LVDS. Position  */
#define LVDSC_CR_SER_EN_1                     (LVDSC_CR_SER_EN_1_Val << LVDSC_CR_SER_EN_Pos)       /* (LVDSC_CR) Enables the serializer of the LVDS. Position  */
#define LVDSC_CR_Msk                          _UINT32_(0x00000001)                                 /* (LVDSC_CR) Register Mask  */


/* -------- LVDSC_CFGR : (LVDSC Offset: 0x04) (R/W 32) Configuration Register -------- */
#define LVDSC_CFGR_RESETVALUE                 _UINT32_(0x00)                                       /*  (LVDSC_CFGR) Configuration Register  Reset Value */

#define LVDSC_CFGR_LCDC_PIXSIZE_Pos           _UINT32_(0)                                          /* (LVDSC_CFGR) LCD Controller Pixel Size Position */
#define LVDSC_CFGR_LCDC_PIXSIZE_Msk           (_UINT32_(0x1) << LVDSC_CFGR_LCDC_PIXSIZE_Pos)       /* (LVDSC_CFGR) LCD Controller Pixel Size Mask */
#define LVDSC_CFGR_LCDC_PIXSIZE(value)        (LVDSC_CFGR_LCDC_PIXSIZE_Msk & (_UINT32_(value) << LVDSC_CFGR_LCDC_PIXSIZE_Pos)) /* Assigment of value for LCDC_PIXSIZE in the LVDSC_CFGR register */
#define   LVDSC_CFGR_LCDC_PIXSIZE_24BITS_Val  _UINT32_(0x0)                                        /* (LVDSC_CFGR) LCD controller provides 24 bits per pixel.  */
#define   LVDSC_CFGR_LCDC_PIXSIZE_18BITS_Val  _UINT32_(0x1)                                        /* (LVDSC_CFGR) LCD controller provides 18 bits per pixel.  */
#define LVDSC_CFGR_LCDC_PIXSIZE_24BITS        (LVDSC_CFGR_LCDC_PIXSIZE_24BITS_Val << LVDSC_CFGR_LCDC_PIXSIZE_Pos) /* (LVDSC_CFGR) LCD controller provides 24 bits per pixel. Position  */
#define LVDSC_CFGR_LCDC_PIXSIZE_18BITS        (LVDSC_CFGR_LCDC_PIXSIZE_18BITS_Val << LVDSC_CFGR_LCDC_PIXSIZE_Pos) /* (LVDSC_CFGR) LCD controller provides 18 bits per pixel. Position  */
#define LVDSC_CFGR_LCDC_DEN_POL_Pos           _UINT32_(1)                                          /* (LVDSC_CFGR) LCDC Controller Data Enable Polarity Position */
#define LVDSC_CFGR_LCDC_DEN_POL_Msk           (_UINT32_(0x1) << LVDSC_CFGR_LCDC_DEN_POL_Pos)       /* (LVDSC_CFGR) LCDC Controller Data Enable Polarity Mask */
#define LVDSC_CFGR_LCDC_DEN_POL(value)        (LVDSC_CFGR_LCDC_DEN_POL_Msk & (_UINT32_(value) << LVDSC_CFGR_LCDC_DEN_POL_Pos)) /* Assigment of value for LCDC_DEN_POL in the LVDSC_CFGR register */
#define   LVDSC_CFGR_LCDC_DEN_POL_HIGH_Val    _UINT32_(0x0)                                        /* (LVDSC_CFGR) LCD_DEN input is active high  */
#define   LVDSC_CFGR_LCDC_DEN_POL_LOW_Val     _UINT32_(0x1)                                        /* (LVDSC_CFGR) LCD_DEN input is active low  */
#define LVDSC_CFGR_LCDC_DEN_POL_HIGH          (LVDSC_CFGR_LCDC_DEN_POL_HIGH_Val << LVDSC_CFGR_LCDC_DEN_POL_Pos) /* (LVDSC_CFGR) LCD_DEN input is active high Position  */
#define LVDSC_CFGR_LCDC_DEN_POL_LOW           (LVDSC_CFGR_LCDC_DEN_POL_LOW_Val << LVDSC_CFGR_LCDC_DEN_POL_Pos) /* (LVDSC_CFGR) LCD_DEN input is active low Position  */
#define LVDSC_CFGR_DC_BAL_Pos                 _UINT32_(5)                                          /* (LVDSC_CFGR) DC Mode Position */
#define LVDSC_CFGR_DC_BAL_Msk                 (_UINT32_(0x1) << LVDSC_CFGR_DC_BAL_Pos)             /* (LVDSC_CFGR) DC Mode Mask */
#define LVDSC_CFGR_DC_BAL(value)              (LVDSC_CFGR_DC_BAL_Msk & (_UINT32_(value) << LVDSC_CFGR_DC_BAL_Pos)) /* Assigment of value for DC_BAL in the LVDSC_CFGR register */
#define   LVDSC_CFGR_DC_BAL_UNBALANCED_Val    _UINT32_(0x0)                                        /* (LVDSC_CFGR) LVDS lane is DC-unbalanced  */
#define   LVDSC_CFGR_DC_BAL_BALANCED_Val      _UINT32_(0x1)                                        /* (LVDSC_CFGR) LVDS lane is DC-balanced  */
#define LVDSC_CFGR_DC_BAL_UNBALANCED          (LVDSC_CFGR_DC_BAL_UNBALANCED_Val << LVDSC_CFGR_DC_BAL_Pos) /* (LVDSC_CFGR) LVDS lane is DC-unbalanced Position  */
#define LVDSC_CFGR_DC_BAL_BALANCED            (LVDSC_CFGR_DC_BAL_BALANCED_Val << LVDSC_CFGR_DC_BAL_Pos) /* (LVDSC_CFGR) LVDS lane is DC-balanced Position  */
#define LVDSC_CFGR_MAPPING_Pos                _UINT32_(6)                                          /* (LVDSC_CFGR) LVDS mapping format (unbalanced mode only) Position */
#define LVDSC_CFGR_MAPPING_Msk                (_UINT32_(0x1) << LVDSC_CFGR_MAPPING_Pos)            /* (LVDSC_CFGR) LVDS mapping format (unbalanced mode only) Mask */
#define LVDSC_CFGR_MAPPING(value)             (LVDSC_CFGR_MAPPING_Msk & (_UINT32_(value) << LVDSC_CFGR_MAPPING_Pos)) /* Assigment of value for MAPPING in the LVDSC_CFGR register */
#define   LVDSC_CFGR_MAPPING_VESA_Val         _UINT32_(0x0)                                        /* (LVDSC_CFGR) Maps LVDS lanes to VESA format  */
#define   LVDSC_CFGR_MAPPING_JEIDA_Val        _UINT32_(0x1)                                        /* (LVDSC_CFGR) Maps LVDS lanes to JEIDA format  */
#define LVDSC_CFGR_MAPPING_VESA               (LVDSC_CFGR_MAPPING_VESA_Val << LVDSC_CFGR_MAPPING_Pos) /* (LVDSC_CFGR) Maps LVDS lanes to VESA format Position  */
#define LVDSC_CFGR_MAPPING_JEIDA              (LVDSC_CFGR_MAPPING_JEIDA_Val << LVDSC_CFGR_MAPPING_Pos) /* (LVDSC_CFGR) Maps LVDS lanes to JEIDA format Position  */
#define LVDSC_CFGR_Msk                        _UINT32_(0x00000063)                                 /* (LVDSC_CFGR) Register Mask  */


/* -------- LVDSC_UCBR : (LVDSC Offset: 0x08) (R/W 32) User Control Bits Register -------- */
#define LVDSC_UCBR_RESETVALUE                 _UINT32_(0x00)                                       /*  (LVDSC_UCBR) User Control Bits Register  Reset Value */

#define LVDSC_UCBR_RESA3_Pos                  _UINT32_(2)                                          /* (LVDSC_UCBR) Lane A3 Reserved Bit Value Position */
#define LVDSC_UCBR_RESA3_Msk                  (_UINT32_(0x1) << LVDSC_UCBR_RESA3_Pos)              /* (LVDSC_UCBR) Lane A3 Reserved Bit Value Mask */
#define LVDSC_UCBR_RESA3(value)               (LVDSC_UCBR_RESA3_Msk & (_UINT32_(value) << LVDSC_UCBR_RESA3_Pos)) /* Assigment of value for RESA3 in the LVDSC_UCBR register */
#define   LVDSC_UCBR_RESA3_0_Val              _UINT32_(0x0)                                        /* (LVDSC_UCBR) Asserts a logical 0 on lane A3 reserved bit location.  */
#define   LVDSC_UCBR_RESA3_1_Val              _UINT32_(0x1)                                        /* (LVDSC_UCBR) Asserts a logical 1 on lane A3 reserved bit location.  */
#define LVDSC_UCBR_RESA3_0                    (LVDSC_UCBR_RESA3_0_Val << LVDSC_UCBR_RESA3_Pos)     /* (LVDSC_UCBR) Asserts a logical 0 on lane A3 reserved bit location. Position  */
#define LVDSC_UCBR_RESA3_1                    (LVDSC_UCBR_RESA3_1_Val << LVDSC_UCBR_RESA3_Pos)     /* (LVDSC_UCBR) Asserts a logical 1 on lane A3 reserved bit location. Position  */
#define LVDSC_UCBR_Msk                        _UINT32_(0x00000004)                                 /* (LVDSC_UCBR) Register Mask  */

#define LVDSC_UCBR_RESA_Pos                   _UINT32_(2)                                          /* (LVDSC_UCBR Position) Lane A3 Reserved Bit Value */
#define LVDSC_UCBR_RESA_Msk                   (_UINT32_(0x1) << LVDSC_UCBR_RESA_Pos)               /* (LVDSC_UCBR Mask) RESA */
#define LVDSC_UCBR_RESA(value)                (LVDSC_UCBR_RESA_Msk & (_UINT32_(value) << LVDSC_UCBR_RESA_Pos)) 

/* -------- LVDSC_SR : (LVDSC Offset: 0x0C) ( R/ 32) Status Register -------- */
#define LVDSC_SR_RESETVALUE                   _UINT32_(0x00)                                       /*  (LVDSC_SR) Status Register  Reset Value */

#define LVDSC_SR_CS_Pos                       _UINT32_(0)                                          /* (LVDSC_SR) Configuration Status Position */
#define LVDSC_SR_CS_Msk                       (_UINT32_(0x1) << LVDSC_SR_CS_Pos)                   /* (LVDSC_SR) Configuration Status Mask */
#define LVDSC_SR_CS(value)                    (LVDSC_SR_CS_Msk & (_UINT32_(value) << LVDSC_SR_CS_Pos)) /* Assigment of value for CS in the LVDSC_SR register */
#define   LVDSC_SR_CS_0_Val                   _UINT32_(0x0)                                        /* (LVDSC_SR) The LVDSC_CFGRand LVDSC_UCBR registers can be modified.  */
#define   LVDSC_SR_CS_1_Val                   _UINT32_(0x1)                                        /* (LVDSC_SR) The LVDSC_CFGRand LVDSC_UCBRregistersmust not be modified.  */
#define LVDSC_SR_CS_0                         (LVDSC_SR_CS_0_Val << LVDSC_SR_CS_Pos)               /* (LVDSC_SR) The LVDSC_CFGRand LVDSC_UCBR registers can be modified. Position  */
#define LVDSC_SR_CS_1                         (LVDSC_SR_CS_1_Val << LVDSC_SR_CS_Pos)               /* (LVDSC_SR) The LVDSC_CFGRand LVDSC_UCBRregistersmust not be modified. Position  */
#define LVDSC_SR_Msk                          _UINT32_(0x00000001)                                 /* (LVDSC_SR) Register Mask  */


/* -------- LVDSC_ACR : (LVDSC Offset: 0x14) (R/W 32) Analog Control Register -------- */
#define LVDSC_ACR_RESETVALUE                  _UINT32_(0x00)                                       /*  (LVDSC_ACR) Analog Control Register  Reset Value */

#define LVDSC_ACR_DCBIAS_Pos                  _UINT32_(0)                                          /* (LVDSC_ACR) Common DC-bias Control for LVDS lanes Position */
#define LVDSC_ACR_DCBIAS_Msk                  (_UINT32_(0x1F) << LVDSC_ACR_DCBIAS_Pos)             /* (LVDSC_ACR) Common DC-bias Control for LVDS lanes Mask */
#define LVDSC_ACR_DCBIAS(value)               (LVDSC_ACR_DCBIAS_Msk & (_UINT32_(value) << LVDSC_ACR_DCBIAS_Pos)) /* Assigment of value for DCBIAS in the LVDSC_ACR register */
#define LVDSC_ACR_PREEMP_A0_Pos               _UINT32_(8)                                          /* (LVDSC_ACR) Pre-Emphasis Control for A0 LVDS lane Position */
#define LVDSC_ACR_PREEMP_A0_Msk               (_UINT32_(0x7) << LVDSC_ACR_PREEMP_A0_Pos)           /* (LVDSC_ACR) Pre-Emphasis Control for A0 LVDS lane Mask */
#define LVDSC_ACR_PREEMP_A0(value)            (LVDSC_ACR_PREEMP_A0_Msk & (_UINT32_(value) << LVDSC_ACR_PREEMP_A0_Pos)) /* Assigment of value for PREEMP_A0 in the LVDSC_ACR register */
#define LVDSC_ACR_PREEMP_A1_Pos               _UINT32_(12)                                         /* (LVDSC_ACR) Pre-Emphasis Control for A1 LVDS lane Position */
#define LVDSC_ACR_PREEMP_A1_Msk               (_UINT32_(0x7) << LVDSC_ACR_PREEMP_A1_Pos)           /* (LVDSC_ACR) Pre-Emphasis Control for A1 LVDS lane Mask */
#define LVDSC_ACR_PREEMP_A1(value)            (LVDSC_ACR_PREEMP_A1_Msk & (_UINT32_(value) << LVDSC_ACR_PREEMP_A1_Pos)) /* Assigment of value for PREEMP_A1 in the LVDSC_ACR register */
#define LVDSC_ACR_PREEMP_A2_Pos               _UINT32_(16)                                         /* (LVDSC_ACR) Pre-Emphasis Control for A2 LVDS lane Position */
#define LVDSC_ACR_PREEMP_A2_Msk               (_UINT32_(0x7) << LVDSC_ACR_PREEMP_A2_Pos)           /* (LVDSC_ACR) Pre-Emphasis Control for A2 LVDS lane Mask */
#define LVDSC_ACR_PREEMP_A2(value)            (LVDSC_ACR_PREEMP_A2_Msk & (_UINT32_(value) << LVDSC_ACR_PREEMP_A2_Pos)) /* Assigment of value for PREEMP_A2 in the LVDSC_ACR register */
#define LVDSC_ACR_PREEMP_A3_Pos               _UINT32_(20)                                         /* (LVDSC_ACR) Pre-Emphasis Control for A3 LVDS lane Position */
#define LVDSC_ACR_PREEMP_A3_Msk               (_UINT32_(0x7) << LVDSC_ACR_PREEMP_A3_Pos)           /* (LVDSC_ACR) Pre-Emphasis Control for A3 LVDS lane Mask */
#define LVDSC_ACR_PREEMP_A3(value)            (LVDSC_ACR_PREEMP_A3_Msk & (_UINT32_(value) << LVDSC_ACR_PREEMP_A3_Pos)) /* Assigment of value for PREEMP_A3 in the LVDSC_ACR register */
#define LVDSC_ACR_PREEMP_CLK1_Pos             _UINT32_(24)                                         /* (LVDSC_ACR)  Position */
#define LVDSC_ACR_PREEMP_CLK1_Msk             (_UINT32_(0x7) << LVDSC_ACR_PREEMP_CLK1_Pos)         /* (LVDSC_ACR)  Mask */
#define LVDSC_ACR_PREEMP_CLK1(value)          (LVDSC_ACR_PREEMP_CLK1_Msk & (_UINT32_(value) << LVDSC_ACR_PREEMP_CLK1_Pos)) /* Assigment of value for PREEMP_CLK1 in the LVDSC_ACR register */
#define LVDSC_ACR_Msk                         _UINT32_(0x0777771F)                                 /* (LVDSC_ACR) Register Mask  */


/* -------- LVDSC_WPMR : (LVDSC Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define LVDSC_WPMR_RESETVALUE                 _UINT32_(0x00)                                       /*  (LVDSC_WPMR) Write Protection Mode Register  Reset Value */

#define LVDSC_WPMR_WPEN_Pos                   _UINT32_(0)                                          /* (LVDSC_WPMR) Write Protection Enable Position */
#define LVDSC_WPMR_WPEN_Msk                   (_UINT32_(0x1) << LVDSC_WPMR_WPEN_Pos)               /* (LVDSC_WPMR) Write Protection Enable Mask */
#define LVDSC_WPMR_WPEN(value)                (LVDSC_WPMR_WPEN_Msk & (_UINT32_(value) << LVDSC_WPMR_WPEN_Pos)) /* Assigment of value for WPEN in the LVDSC_WPMR register */
#define   LVDSC_WPMR_WPEN_0_Val               _UINT32_(0x0)                                        /* (LVDSC_WPMR) Disables write protection if WPKEY corresponds to 0x4C5644 ("LVD" in ASCII).  */
#define   LVDSC_WPMR_WPEN_1_Val               _UINT32_(0x1)                                        /* (LVDSC_WPMR) Enables write protection if WPKEY corresponds to 0x4C5644 ("LVD" in ASCII).  */
#define LVDSC_WPMR_WPEN_0                     (LVDSC_WPMR_WPEN_0_Val << LVDSC_WPMR_WPEN_Pos)       /* (LVDSC_WPMR) Disables write protection if WPKEY corresponds to 0x4C5644 ("LVD" in ASCII). Position  */
#define LVDSC_WPMR_WPEN_1                     (LVDSC_WPMR_WPEN_1_Val << LVDSC_WPMR_WPEN_Pos)       /* (LVDSC_WPMR) Enables write protection if WPKEY corresponds to 0x4C5644 ("LVD" in ASCII). Position  */
#define LVDSC_WPMR_LCKWPEN_Pos                _UINT32_(4)                                          /* (LVDSC_WPMR) Lock Write Protection Enable Until Next System Reset Position */
#define LVDSC_WPMR_LCKWPEN_Msk                (_UINT32_(0x1) << LVDSC_WPMR_LCKWPEN_Pos)            /* (LVDSC_WPMR) Lock Write Protection Enable Until Next System Reset Mask */
#define LVDSC_WPMR_LCKWPEN(value)             (LVDSC_WPMR_LCKWPEN_Msk & (_UINT32_(value) << LVDSC_WPMR_LCKWPEN_Pos)) /* Assigment of value for LCKWPEN in the LVDSC_WPMR register */
#define   LVDSC_WPMR_LCKWPEN_0_Val            _UINT32_(0x0)                                        /* (LVDSC_WPMR) No effect.  */
#define   LVDSC_WPMR_LCKWPEN_1_Val            _UINT32_(0x1)                                        /* (LVDSC_WPMR) Locks the WPEN bit to 1 until the next system reset if on the same access WPEN=1 and WPKEY corresponds to 0x4C5644 ("LVD" in ASCII).  */
#define LVDSC_WPMR_LCKWPEN_0                  (LVDSC_WPMR_LCKWPEN_0_Val << LVDSC_WPMR_LCKWPEN_Pos) /* (LVDSC_WPMR) No effect. Position  */
#define LVDSC_WPMR_LCKWPEN_1                  (LVDSC_WPMR_LCKWPEN_1_Val << LVDSC_WPMR_LCKWPEN_Pos) /* (LVDSC_WPMR) Locks the WPEN bit to 1 until the next system reset if on the same access WPEN=1 and WPKEY corresponds to 0x4C5644 ("LVD" in ASCII). Position  */
#define LVDSC_WPMR_WPKEY_Pos                  _UINT32_(8)                                          /* (LVDSC_WPMR) Write Protection Key Position */
#define LVDSC_WPMR_WPKEY_Msk                  (_UINT32_(0xFFFFFF) << LVDSC_WPMR_WPKEY_Pos)         /* (LVDSC_WPMR) Write Protection Key Mask */
#define LVDSC_WPMR_WPKEY(value)               (LVDSC_WPMR_WPKEY_Msk & (_UINT32_(value) << LVDSC_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the LVDSC_WPMR register */
#define   LVDSC_WPMR_WPKEY_PASSWD_Val         _UINT32_(0x4C5644)                                   /* (LVDSC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.  Always reads as 0.  */
#define LVDSC_WPMR_WPKEY_PASSWD               (LVDSC_WPMR_WPKEY_PASSWD_Val << LVDSC_WPMR_WPKEY_Pos) /* (LVDSC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.  Always reads as 0. Position  */
#define LVDSC_WPMR_Msk                        _UINT32_(0xFFFFFF11)                                 /* (LVDSC_WPMR) Register Mask  */


/* -------- LVDSC_WPSR : (LVDSC Offset: 0xE8) ( R/ 32) Write Protection Status Register -------- */
#define LVDSC_WPSR_RESETVALUE                 _UINT32_(0x00)                                       /*  (LVDSC_WPSR) Write Protection Status Register  Reset Value */

#define LVDSC_WPSR_WPVS_Pos                   _UINT32_(0)                                          /* (LVDSC_WPSR) Write Protection Violation Status (cleared on read) Position */
#define LVDSC_WPSR_WPVS_Msk                   (_UINT32_(0x1) << LVDSC_WPSR_WPVS_Pos)               /* (LVDSC_WPSR) Write Protection Violation Status (cleared on read) Mask */
#define LVDSC_WPSR_WPVS(value)                (LVDSC_WPSR_WPVS_Msk & (_UINT32_(value) << LVDSC_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the LVDSC_WPSR register */
#define   LVDSC_WPSR_WPVS_0_Val               _UINT32_(0x0)                                        /* (LVDSC_WPSR) No write protect violation has occurred since the last read of LVDSC_WPSR.  */
#define   LVDSC_WPSR_WPVS_1_Val               _UINT32_(0x1)                                        /* (LVDSC_WPSR) A write protect violation has occurred since the last read of LVDSC_WPSR. The address offset of the violated register is reported into field WPVSRC.  */
#define LVDSC_WPSR_WPVS_0                     (LVDSC_WPSR_WPVS_0_Val << LVDSC_WPSR_WPVS_Pos)       /* (LVDSC_WPSR) No write protect violation has occurred since the last read of LVDSC_WPSR. Position  */
#define LVDSC_WPSR_WPVS_1                     (LVDSC_WPSR_WPVS_1_Val << LVDSC_WPSR_WPVS_Pos)       /* (LVDSC_WPSR) A write protect violation has occurred since the last read of LVDSC_WPSR. The address offset of the violated register is reported into field WPVSRC. Position  */
#define LVDSC_WPSR_SWE_Pos                    _UINT32_(3)                                          /* (LVDSC_WPSR) Software Control Error (cleared on read) Position */
#define LVDSC_WPSR_SWE_Msk                    (_UINT32_(0x1) << LVDSC_WPSR_SWE_Pos)                /* (LVDSC_WPSR) Software Control Error (cleared on read) Mask */
#define LVDSC_WPSR_SWE(value)                 (LVDSC_WPSR_SWE_Msk & (_UINT32_(value) << LVDSC_WPSR_SWE_Pos)) /* Assigment of value for SWE in the LVDSC_WPSR register */
#define   LVDSC_WPSR_SWE_0_Val                _UINT32_(0x0)                                        /* (LVDSC_WPSR) No software error has occurred since the last read of LVDSC_WPSR.  */
#define   LVDSC_WPSR_SWE_1_Val                _UINT32_(0x1)                                        /* (LVDSC_WPSR) A software error has occurred since the last read of LVDSC_WPSR. The field SWETYP details the type of software error; the associated incorrect software access is reported in the field WPVSRC (if WPVS=0).  */
#define LVDSC_WPSR_SWE_0                      (LVDSC_WPSR_SWE_0_Val << LVDSC_WPSR_SWE_Pos)         /* (LVDSC_WPSR) No software error has occurred since the last read of LVDSC_WPSR. Position  */
#define LVDSC_WPSR_SWE_1                      (LVDSC_WPSR_SWE_1_Val << LVDSC_WPSR_SWE_Pos)         /* (LVDSC_WPSR) A software error has occurred since the last read of LVDSC_WPSR. The field SWETYP details the type of software error; the associated incorrect software access is reported in the field WPVSRC (if WPVS=0). Position  */
#define LVDSC_WPSR_WPVSRC_Pos                 _UINT32_(8)                                          /* (LVDSC_WPSR) Write Protection Violation Source Position */
#define LVDSC_WPSR_WPVSRC_Msk                 (_UINT32_(0xFF) << LVDSC_WPSR_WPVSRC_Pos)            /* (LVDSC_WPSR) Write Protection Violation Source Mask */
#define LVDSC_WPSR_WPVSRC(value)              (LVDSC_WPSR_WPVSRC_Msk & (_UINT32_(value) << LVDSC_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the LVDSC_WPSR register */
#define LVDSC_WPSR_SWETYP_Pos                 _UINT32_(24)                                         /* (LVDSC_WPSR) Software Error Type (cleared on read) Position */
#define LVDSC_WPSR_SWETYP_Msk                 (_UINT32_(0x3) << LVDSC_WPSR_SWETYP_Pos)             /* (LVDSC_WPSR) Software Error Type (cleared on read) Mask */
#define LVDSC_WPSR_SWETYP(value)              (LVDSC_WPSR_SWETYP_Msk & (_UINT32_(value) << LVDSC_WPSR_SWETYP_Pos)) /* Assigment of value for SWETYP in the LVDSC_WPSR register */
#define   LVDSC_WPSR_SWETYP_WRITE_RO_Val      _UINT32_(0x1)                                        /* (LVDSC_WPSR) LVDSC is enabled and a write access has been performed on a read-only register.  */
#define   LVDSC_WPSR_SWETYP_UNDEF_RW_Val      _UINT32_(0x2)                                        /* (LVDSC_WPSR) Access to an undefined address.  */
#define   LVDSC_WPSR_SWETYP_WEIRD_ACTION_Val  _UINT32_(0x3)                                        /* (LVDSC_WPSR) Tentative to modify the LVDSC_CFGR when LVDSC_CR.SER_EN=1.  */
#define LVDSC_WPSR_SWETYP_WRITE_RO            (LVDSC_WPSR_SWETYP_WRITE_RO_Val << LVDSC_WPSR_SWETYP_Pos) /* (LVDSC_WPSR) LVDSC is enabled and a write access has been performed on a read-only register. Position  */
#define LVDSC_WPSR_SWETYP_UNDEF_RW            (LVDSC_WPSR_SWETYP_UNDEF_RW_Val << LVDSC_WPSR_SWETYP_Pos) /* (LVDSC_WPSR) Access to an undefined address. Position  */
#define LVDSC_WPSR_SWETYP_WEIRD_ACTION        (LVDSC_WPSR_SWETYP_WEIRD_ACTION_Val << LVDSC_WPSR_SWETYP_Pos) /* (LVDSC_WPSR) Tentative to modify the LVDSC_CFGR when LVDSC_CR.SER_EN=1. Position  */
#define LVDSC_WPSR_Msk                        _UINT32_(0x0300FF09)                                 /* (LVDSC_WPSR) Register Mask  */


/** \brief LVDSC register offsets definitions */
#define LVDSC_CR_REG_OFST              _UINT32_(0x00)      /* (LVDSC_CR) Control Register Offset */
#define LVDSC_CFGR_REG_OFST            _UINT32_(0x04)      /* (LVDSC_CFGR) Configuration Register Offset */
#define LVDSC_UCBR_REG_OFST            _UINT32_(0x08)      /* (LVDSC_UCBR) User Control Bits Register Offset */
#define LVDSC_SR_REG_OFST              _UINT32_(0x0C)      /* (LVDSC_SR) Status Register Offset */
#define LVDSC_ACR_REG_OFST             _UINT32_(0x14)      /* (LVDSC_ACR) Analog Control Register Offset */
#define LVDSC_WPMR_REG_OFST            _UINT32_(0xE4)      /* (LVDSC_WPMR) Write Protection Mode Register Offset */
#define LVDSC_WPSR_REG_OFST            _UINT32_(0xE8)      /* (LVDSC_WPSR) Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief LVDSC register API structure */
typedef struct
{  /* LVDS Controller */
  __O   uint32_t                       LVDSC_CR;           /**< Offset: 0x00 ( /W  32) Control Register */
  __IO  uint32_t                       LVDSC_CFGR;         /**< Offset: 0x04 (R/W  32) Configuration Register */
  __IO  uint32_t                       LVDSC_UCBR;         /**< Offset: 0x08 (R/W  32) User Control Bits Register */
  __I   uint32_t                       LVDSC_SR;           /**< Offset: 0x0C (R/   32) Status Register */
  __I   uint8_t                        Reserved1[0x04];
  __IO  uint32_t                       LVDSC_ACR;          /**< Offset: 0x14 (R/W  32) Analog Control Register */
  __I   uint8_t                        Reserved2[0xCC];
  __IO  uint32_t                       LVDSC_WPMR;         /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   uint32_t                       LVDSC_WPSR;         /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
} lvdsc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X7_LVDSC_COMPONENT_H_ */
