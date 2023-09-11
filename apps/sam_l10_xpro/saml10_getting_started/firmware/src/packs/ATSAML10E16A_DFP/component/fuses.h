/*
 * Component description for FUSES
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

/* file generated from device description version 2023-04-12T14:18:35Z */
#ifndef _SAML10_FUSES_COMPONENT_H_
#define _SAML10_FUSES_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR FUSES                                        */
/* ************************************************************************** */

/* -------- FUSES_SW_CALIB_WORD_0 : (FUSES Offset: 0x00) ( R/ 32) SW_CALIB Page Word 0 -------- */
#define FUSES_SW_CALIB_WORD_0_ADC_BIASREFBUF_Pos _UINT32_(0)                                          /* (FUSES_SW_CALIB_WORD_0) ADC Bias Reference Buffer Scaling Position */
#define FUSES_SW_CALIB_WORD_0_ADC_BIASREFBUF_Msk (_UINT32_(0x7) << FUSES_SW_CALIB_WORD_0_ADC_BIASREFBUF_Pos) /* (FUSES_SW_CALIB_WORD_0) ADC Bias Reference Buffer Scaling Mask */
#define FUSES_SW_CALIB_WORD_0_ADC_BIASREFBUF(value) (FUSES_SW_CALIB_WORD_0_ADC_BIASREFBUF_Msk & (_UINT32_(value) << FUSES_SW_CALIB_WORD_0_ADC_BIASREFBUF_Pos)) /* Assigment of value for ADC_BIASREFBUF in the FUSES_SW_CALIB_WORD_0 register */
#define FUSES_SW_CALIB_WORD_0_ADC_BIASCOMP_Pos _UINT32_(3)                                          /* (FUSES_SW_CALIB_WORD_0) ADC Comparator Scaling Position */
#define FUSES_SW_CALIB_WORD_0_ADC_BIASCOMP_Msk (_UINT32_(0x7) << FUSES_SW_CALIB_WORD_0_ADC_BIASCOMP_Pos) /* (FUSES_SW_CALIB_WORD_0) ADC Comparator Scaling Mask */
#define FUSES_SW_CALIB_WORD_0_ADC_BIASCOMP(value) (FUSES_SW_CALIB_WORD_0_ADC_BIASCOMP_Msk & (_UINT32_(value) << FUSES_SW_CALIB_WORD_0_ADC_BIASCOMP_Pos)) /* Assigment of value for ADC_BIASCOMP in the FUSES_SW_CALIB_WORD_0 register */
#define FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL0_Pos _UINT32_(6)                                          /* (FUSES_SW_CALIB_WORD_0) DFLLULP DIV at PL0 Position */
#define FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL0_Msk (_UINT32_(0x7) << FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL0_Pos) /* (FUSES_SW_CALIB_WORD_0) DFLLULP DIV at PL0 Mask */
#define FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL0(value) (FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL0_Msk & (_UINT32_(value) << FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL0_Pos)) /* Assigment of value for DFLLULP_DIV_PL0 in the FUSES_SW_CALIB_WORD_0 register */
#define FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL2_Pos _UINT32_(9)                                          /* (FUSES_SW_CALIB_WORD_0) DFLLULP DIV at PL2 Position */
#define FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL2_Msk (_UINT32_(0x7) << FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL2_Pos) /* (FUSES_SW_CALIB_WORD_0) DFLLULP DIV at PL2 Mask */
#define FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL2(value) (FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL2_Msk & (_UINT32_(value) << FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL2_Pos)) /* Assigment of value for DFLLULP_DIV_PL2 in the FUSES_SW_CALIB_WORD_0 register */
#define FUSES_SW_CALIB_WORD_0_Msk             _UINT32_(0x00000FFF)                                 /* (FUSES_SW_CALIB_WORD_0) Register Mask  */


/* -------- FUSES_TEMP_LOG_WORD_0 : (FUSES Offset: 0x00) ( R/ 32) TEMP_LOG Page Word 0 -------- */
#define FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_INT_Pos _UINT32_(0)                                          /* (FUSES_TEMP_LOG_WORD_0) Integer part of room temperature in oC Position */
#define FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_INT_Msk (_UINT32_(0xFF) << FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_INT_Pos) /* (FUSES_TEMP_LOG_WORD_0) Integer part of room temperature in oC Mask */
#define FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_INT(value) (FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_INT_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_INT_Pos)) /* Assigment of value for ROOM_TEMP_VAL_INT in the FUSES_TEMP_LOG_WORD_0 register */
#define FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_DEC_Pos _UINT32_(8)                                          /* (FUSES_TEMP_LOG_WORD_0) Decimal part of room temperature Position */
#define FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_DEC_Msk (_UINT32_(0xF) << FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_DEC_Pos) /* (FUSES_TEMP_LOG_WORD_0) Decimal part of room temperature Mask */
#define FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_DEC(value) (FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_DEC_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_DEC_Pos)) /* Assigment of value for ROOM_TEMP_VAL_DEC in the FUSES_TEMP_LOG_WORD_0 register */
#define FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_INT_Pos _UINT32_(12)                                         /* (FUSES_TEMP_LOG_WORD_0) Integer part of hot temperature in oC Position */
#define FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_INT_Msk (_UINT32_(0xFF) << FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_INT_Pos) /* (FUSES_TEMP_LOG_WORD_0) Integer part of hot temperature in oC Mask */
#define FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_INT(value) (FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_INT_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_INT_Pos)) /* Assigment of value for HOT_TEMP_VAL_INT in the FUSES_TEMP_LOG_WORD_0 register */
#define FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_DEC_Pos _UINT32_(20)                                         /* (FUSES_TEMP_LOG_WORD_0) Decimal part of hot temperature Position */
#define FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_DEC_Msk (_UINT32_(0xF) << FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_DEC_Pos) /* (FUSES_TEMP_LOG_WORD_0) Decimal part of hot temperature Mask */
#define FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_DEC(value) (FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_DEC_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_DEC_Pos)) /* Assigment of value for HOT_TEMP_VAL_DEC in the FUSES_TEMP_LOG_WORD_0 register */
#define FUSES_TEMP_LOG_WORD_0_ROOM_INT1V_VAL_Pos _UINT32_(24)                                         /* (FUSES_TEMP_LOG_WORD_0) 2's complement of the internal 1V reference drift at room temperature (versus a 1.0 centered value) Position */
#define FUSES_TEMP_LOG_WORD_0_ROOM_INT1V_VAL_Msk (_UINT32_(0xFF) << FUSES_TEMP_LOG_WORD_0_ROOM_INT1V_VAL_Pos) /* (FUSES_TEMP_LOG_WORD_0) 2's complement of the internal 1V reference drift at room temperature (versus a 1.0 centered value) Mask */
#define FUSES_TEMP_LOG_WORD_0_ROOM_INT1V_VAL(value) (FUSES_TEMP_LOG_WORD_0_ROOM_INT1V_VAL_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_0_ROOM_INT1V_VAL_Pos)) /* Assigment of value for ROOM_INT1V_VAL in the FUSES_TEMP_LOG_WORD_0 register */
#define FUSES_TEMP_LOG_WORD_0_Msk             _UINT32_(0xFFFFFFFF)                                 /* (FUSES_TEMP_LOG_WORD_0) Register Mask  */


/* -------- FUSES_TEMP_LOG_WORD_1 : (FUSES Offset: 0x04) ( R/ 32) TEMP_LOG Page Word 1 -------- */
#define FUSES_TEMP_LOG_WORD_1_HOT_INT1V_VAL_Pos _UINT32_(0)                                          /* (FUSES_TEMP_LOG_WORD_1) 2's complement of the internal 1V reference drift at hot temperature (versus a 1.0 centered value) Position */
#define FUSES_TEMP_LOG_WORD_1_HOT_INT1V_VAL_Msk (_UINT32_(0xFF) << FUSES_TEMP_LOG_WORD_1_HOT_INT1V_VAL_Pos) /* (FUSES_TEMP_LOG_WORD_1) 2's complement of the internal 1V reference drift at hot temperature (versus a 1.0 centered value) Mask */
#define FUSES_TEMP_LOG_WORD_1_HOT_INT1V_VAL(value) (FUSES_TEMP_LOG_WORD_1_HOT_INT1V_VAL_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_1_HOT_INT1V_VAL_Pos)) /* Assigment of value for HOT_INT1V_VAL in the FUSES_TEMP_LOG_WORD_1 register */
#define FUSES_TEMP_LOG_WORD_1_ROOM_ADC_VAL_PTAT_Pos _UINT32_(8)                                          /* (FUSES_TEMP_LOG_WORD_1) 12-bit ADC conversion at room temperature PTAT Position */
#define FUSES_TEMP_LOG_WORD_1_ROOM_ADC_VAL_PTAT_Msk (_UINT32_(0xFFF) << FUSES_TEMP_LOG_WORD_1_ROOM_ADC_VAL_PTAT_Pos) /* (FUSES_TEMP_LOG_WORD_1) 12-bit ADC conversion at room temperature PTAT Mask */
#define FUSES_TEMP_LOG_WORD_1_ROOM_ADC_VAL_PTAT(value) (FUSES_TEMP_LOG_WORD_1_ROOM_ADC_VAL_PTAT_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_1_ROOM_ADC_VAL_PTAT_Pos)) /* Assigment of value for ROOM_ADC_VAL_PTAT in the FUSES_TEMP_LOG_WORD_1 register */
#define FUSES_TEMP_LOG_WORD_1_HOT_ADC_VAL_PTAT_Pos _UINT32_(20)                                         /* (FUSES_TEMP_LOG_WORD_1) 12-bit ADC conversion at hot temperature PTAT Position */
#define FUSES_TEMP_LOG_WORD_1_HOT_ADC_VAL_PTAT_Msk (_UINT32_(0xFFF) << FUSES_TEMP_LOG_WORD_1_HOT_ADC_VAL_PTAT_Pos) /* (FUSES_TEMP_LOG_WORD_1) 12-bit ADC conversion at hot temperature PTAT Mask */
#define FUSES_TEMP_LOG_WORD_1_HOT_ADC_VAL_PTAT(value) (FUSES_TEMP_LOG_WORD_1_HOT_ADC_VAL_PTAT_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_1_HOT_ADC_VAL_PTAT_Pos)) /* Assigment of value for HOT_ADC_VAL_PTAT in the FUSES_TEMP_LOG_WORD_1 register */
#define FUSES_TEMP_LOG_WORD_1_Msk             _UINT32_(0xFFFFFFFF)                                 /* (FUSES_TEMP_LOG_WORD_1) Register Mask  */


/* -------- FUSES_BOCOR_WORD_1 : (FUSES Offset: 0x04) (R/W 32) BOCOR Page Word 1 -------- */
#define FUSES_BOCOR_WORD_1_RESETVALUE         _UINT32_(0xFFFFFF00)                                 /*  (FUSES_BOCOR_WORD_1) BOCOR Page Word 1  Reset Value */

#define FUSES_BOCOR_WORD_1_IDAU_BOOTPROT_Pos  _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_1) Boot Protection Position */
#define FUSES_BOCOR_WORD_1_IDAU_BOOTPROT_Msk  (_UINT32_(0xFF) << FUSES_BOCOR_WORD_1_IDAU_BOOTPROT_Pos) /* (FUSES_BOCOR_WORD_1) Boot Protection Mask */
#define FUSES_BOCOR_WORD_1_IDAU_BOOTPROT(value) (FUSES_BOCOR_WORD_1_IDAU_BOOTPROT_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_1_IDAU_BOOTPROT_Pos)) /* Assigment of value for IDAU_BOOTPROT in the FUSES_BOCOR_WORD_1 register */
#define FUSES_BOCOR_WORD_1_Msk                _UINT32_(0x000000FF)                                 /* (FUSES_BOCOR_WORD_1) Register Mask  */


/* -------- FUSES_BOCOR_WORD_16 : (FUSES Offset: 0x40) (R/W 32) BOCOR Page Word 16 -------- */
#define FUSES_BOCOR_WORD_16_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_16) BOCOR Page Word 16  Reset Value */

#define FUSES_BOCOR_WORD_16_BOOTROM_CRCKEY_0_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_16) CRC Key bits 31:0 Position */
#define FUSES_BOCOR_WORD_16_BOOTROM_CRCKEY_0_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_16_BOOTROM_CRCKEY_0_Pos) /* (FUSES_BOCOR_WORD_16) CRC Key bits 31:0 Mask */
#define FUSES_BOCOR_WORD_16_BOOTROM_CRCKEY_0(value) (FUSES_BOCOR_WORD_16_BOOTROM_CRCKEY_0_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_16_BOOTROM_CRCKEY_0_Pos)) /* Assigment of value for BOOTROM_CRCKEY_0 in the FUSES_BOCOR_WORD_16 register */
#define FUSES_BOCOR_WORD_16_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_16) Register Mask  */


/* -------- FUSES_BOCOR_WORD_17 : (FUSES Offset: 0x44) (R/W 32) BOCOR Page Word 17 -------- */
#define FUSES_BOCOR_WORD_17_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_17) BOCOR Page Word 17  Reset Value */

#define FUSES_BOCOR_WORD_17_BOOTROM_CRCKEY_1_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_17) CRC Key bits 63:32 Position */
#define FUSES_BOCOR_WORD_17_BOOTROM_CRCKEY_1_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_17_BOOTROM_CRCKEY_1_Pos) /* (FUSES_BOCOR_WORD_17) CRC Key bits 63:32 Mask */
#define FUSES_BOCOR_WORD_17_BOOTROM_CRCKEY_1(value) (FUSES_BOCOR_WORD_17_BOOTROM_CRCKEY_1_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_17_BOOTROM_CRCKEY_1_Pos)) /* Assigment of value for BOOTROM_CRCKEY_1 in the FUSES_BOCOR_WORD_17 register */
#define FUSES_BOCOR_WORD_17_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_17) Register Mask  */


/* -------- FUSES_BOCOR_WORD_18 : (FUSES Offset: 0x48) (R/W 32) BOCOR Page Word 18 -------- */
#define FUSES_BOCOR_WORD_18_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_18) BOCOR Page Word 18  Reset Value */

#define FUSES_BOCOR_WORD_18_BOOTROM_CRCKEY_2_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_18) CRC Key bits 95:64 Position */
#define FUSES_BOCOR_WORD_18_BOOTROM_CRCKEY_2_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_18_BOOTROM_CRCKEY_2_Pos) /* (FUSES_BOCOR_WORD_18) CRC Key bits 95:64 Mask */
#define FUSES_BOCOR_WORD_18_BOOTROM_CRCKEY_2(value) (FUSES_BOCOR_WORD_18_BOOTROM_CRCKEY_2_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_18_BOOTROM_CRCKEY_2_Pos)) /* Assigment of value for BOOTROM_CRCKEY_2 in the FUSES_BOCOR_WORD_18 register */
#define FUSES_BOCOR_WORD_18_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_18) Register Mask  */


/* -------- FUSES_BOCOR_WORD_19 : (FUSES Offset: 0x4C) (R/W 32) BOCOR Page Word 19 -------- */
#define FUSES_BOCOR_WORD_19_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_19) BOCOR Page Word 19  Reset Value */

#define FUSES_BOCOR_WORD_19_BOOTROM_CRCKEY_3_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_19) CRC Key bits 127:96 Position */
#define FUSES_BOCOR_WORD_19_BOOTROM_CRCKEY_3_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_19_BOOTROM_CRCKEY_3_Pos) /* (FUSES_BOCOR_WORD_19) CRC Key bits 127:96 Mask */
#define FUSES_BOCOR_WORD_19_BOOTROM_CRCKEY_3(value) (FUSES_BOCOR_WORD_19_BOOTROM_CRCKEY_3_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_19_BOOTROM_CRCKEY_3_Pos)) /* Assigment of value for BOOTROM_CRCKEY_3 in the FUSES_BOCOR_WORD_19 register */
#define FUSES_BOCOR_WORD_19_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_19) Register Mask  */


/* -------- FUSES_USER_WORD_0 : (FUSES Offset: 0x00) (R/W 32) USER Page Word 0 -------- */
#define FUSES_USER_WORD_0_RESETVALUE          _UINT32_(0xB08F437F)                                 /*  (FUSES_USER_WORD_0) USER Page Word 0  Reset Value */

#define FUSES_USER_WORD_0_NVMCTRL_NSULCK_Pos  _UINT32_(3)                                          /* (FUSES_USER_WORD_0) NVM Non-Secure Region Locks Position */
#define FUSES_USER_WORD_0_NVMCTRL_NSULCK_Msk  (_UINT32_(0x7) << FUSES_USER_WORD_0_NVMCTRL_NSULCK_Pos) /* (FUSES_USER_WORD_0) NVM Non-Secure Region Locks Mask */
#define FUSES_USER_WORD_0_NVMCTRL_NSULCK(value) (FUSES_USER_WORD_0_NVMCTRL_NSULCK_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_NVMCTRL_NSULCK_Pos)) /* Assigment of value for NVMCTRL_NSULCK in the FUSES_USER_WORD_0 register */
#define FUSES_USER_WORD_0_BOD33_LEVEL_Pos     _UINT32_(7)                                          /* (FUSES_USER_WORD_0) BOD33 threshold Level Position */
#define FUSES_USER_WORD_0_BOD33_LEVEL_Msk     (_UINT32_(0x3F) << FUSES_USER_WORD_0_BOD33_LEVEL_Pos) /* (FUSES_USER_WORD_0) BOD33 threshold Level Mask */
#define FUSES_USER_WORD_0_BOD33_LEVEL(value)  (FUSES_USER_WORD_0_BOD33_LEVEL_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_BOD33_LEVEL_Pos)) /* Assigment of value for BOD33_LEVEL in the FUSES_USER_WORD_0 register */
#define FUSES_USER_WORD_0_BOD33_DIS_Pos       _UINT32_(13)                                         /* (FUSES_USER_WORD_0) BOD33 Disable Position */
#define FUSES_USER_WORD_0_BOD33_DIS_Msk       (_UINT32_(0x1) << FUSES_USER_WORD_0_BOD33_DIS_Pos)   /* (FUSES_USER_WORD_0) BOD33 Disable Mask */
#define FUSES_USER_WORD_0_BOD33_DIS(value)    (FUSES_USER_WORD_0_BOD33_DIS_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_BOD33_DIS_Pos)) /* Assigment of value for BOD33_DIS in the FUSES_USER_WORD_0 register */
#define FUSES_USER_WORD_0_BOD33_ACTION_Pos    _UINT32_(14)                                         /* (FUSES_USER_WORD_0) BOD33 Action Position */
#define FUSES_USER_WORD_0_BOD33_ACTION_Msk    (_UINT32_(0x3) << FUSES_USER_WORD_0_BOD33_ACTION_Pos) /* (FUSES_USER_WORD_0) BOD33 Action Mask */
#define FUSES_USER_WORD_0_BOD33_ACTION(value) (FUSES_USER_WORD_0_BOD33_ACTION_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_BOD33_ACTION_Pos)) /* Assigment of value for BOD33_ACTION in the FUSES_USER_WORD_0 register */
#define   FUSES_USER_WORD_0_BOD33_ACTION_NONE_Val _UINT32_(0x0)                                        /* (FUSES_USER_WORD_0) No action  */
#define   FUSES_USER_WORD_0_BOD33_ACTION_RESET_Val _UINT32_(0x1)                                        /* (FUSES_USER_WORD_0) The BOD33 generates a reset  */
#define   FUSES_USER_WORD_0_BOD33_ACTION_INT_Val _UINT32_(0x2)                                        /* (FUSES_USER_WORD_0) The BOD33 generates an interrupt  */
#define FUSES_USER_WORD_0_BOD33_ACTION_NONE   (FUSES_USER_WORD_0_BOD33_ACTION_NONE_Val << FUSES_USER_WORD_0_BOD33_ACTION_Pos) /* (FUSES_USER_WORD_0) No action Position  */
#define FUSES_USER_WORD_0_BOD33_ACTION_RESET  (FUSES_USER_WORD_0_BOD33_ACTION_RESET_Val << FUSES_USER_WORD_0_BOD33_ACTION_Pos) /* (FUSES_USER_WORD_0) The BOD33 generates a reset Position  */
#define FUSES_USER_WORD_0_BOD33_ACTION_INT    (FUSES_USER_WORD_0_BOD33_ACTION_INT_Val << FUSES_USER_WORD_0_BOD33_ACTION_Pos) /* (FUSES_USER_WORD_0) The BOD33 generates an interrupt Position  */
#define FUSES_USER_WORD_0_WDT_RUNSTDBY_Pos    _UINT32_(25)                                         /* (FUSES_USER_WORD_0) WDT Run During Standby Position */
#define FUSES_USER_WORD_0_WDT_RUNSTDBY_Msk    (_UINT32_(0x1) << FUSES_USER_WORD_0_WDT_RUNSTDBY_Pos) /* (FUSES_USER_WORD_0) WDT Run During Standby Mask */
#define FUSES_USER_WORD_0_WDT_RUNSTDBY(value) (FUSES_USER_WORD_0_WDT_RUNSTDBY_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_WDT_RUNSTDBY_Pos)) /* Assigment of value for WDT_RUNSTDBY in the FUSES_USER_WORD_0 register */
#define FUSES_USER_WORD_0_WDT_ENABLE_Pos      _UINT32_(26)                                         /* (FUSES_USER_WORD_0) WDT Enable Position */
#define FUSES_USER_WORD_0_WDT_ENABLE_Msk      (_UINT32_(0x1) << FUSES_USER_WORD_0_WDT_ENABLE_Pos)  /* (FUSES_USER_WORD_0) WDT Enable Mask */
#define FUSES_USER_WORD_0_WDT_ENABLE(value)   (FUSES_USER_WORD_0_WDT_ENABLE_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_WDT_ENABLE_Pos)) /* Assigment of value for WDT_ENABLE in the FUSES_USER_WORD_0 register */
#define FUSES_USER_WORD_0_WDT_ALWAYSON_Pos    _UINT32_(27)                                         /* (FUSES_USER_WORD_0) WDT Always On Position */
#define FUSES_USER_WORD_0_WDT_ALWAYSON_Msk    (_UINT32_(0x1) << FUSES_USER_WORD_0_WDT_ALWAYSON_Pos) /* (FUSES_USER_WORD_0) WDT Always On Mask */
#define FUSES_USER_WORD_0_WDT_ALWAYSON(value) (FUSES_USER_WORD_0_WDT_ALWAYSON_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_WDT_ALWAYSON_Pos)) /* Assigment of value for WDT_ALWAYSON in the FUSES_USER_WORD_0 register */
#define FUSES_USER_WORD_0_WDT_PER_Pos         _UINT32_(28)                                         /* (FUSES_USER_WORD_0) WDT Period Position */
#define FUSES_USER_WORD_0_WDT_PER_Msk         (_UINT32_(0xF) << FUSES_USER_WORD_0_WDT_PER_Pos)     /* (FUSES_USER_WORD_0) WDT Period Mask */
#define FUSES_USER_WORD_0_WDT_PER(value)      (FUSES_USER_WORD_0_WDT_PER_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_WDT_PER_Pos)) /* Assigment of value for WDT_PER in the FUSES_USER_WORD_0 register */
#define   FUSES_USER_WORD_0_WDT_PER_CYC8_Val  _UINT32_(0x0)                                        /* (FUSES_USER_WORD_0) 8 clock cycles  */
#define   FUSES_USER_WORD_0_WDT_PER_CYC16_Val _UINT32_(0x1)                                        /* (FUSES_USER_WORD_0) 16 clock cycles  */
#define   FUSES_USER_WORD_0_WDT_PER_CYC32_Val _UINT32_(0x2)                                        /* (FUSES_USER_WORD_0) 32 clock cycles  */
#define   FUSES_USER_WORD_0_WDT_PER_CYC64_Val _UINT32_(0x3)                                        /* (FUSES_USER_WORD_0) 64 clock cycles  */
#define   FUSES_USER_WORD_0_WDT_PER_CYC128_Val _UINT32_(0x4)                                        /* (FUSES_USER_WORD_0) 128 clock cycles  */
#define   FUSES_USER_WORD_0_WDT_PER_CYC256_Val _UINT32_(0x5)                                        /* (FUSES_USER_WORD_0) 256 clock cycles  */
#define   FUSES_USER_WORD_0_WDT_PER_CYC512_Val _UINT32_(0x6)                                        /* (FUSES_USER_WORD_0) 512 clock cycles  */
#define   FUSES_USER_WORD_0_WDT_PER_CYC1024_Val _UINT32_(0x7)                                        /* (FUSES_USER_WORD_0) 1024 clock cycles  */
#define   FUSES_USER_WORD_0_WDT_PER_CYC2048_Val _UINT32_(0x8)                                        /* (FUSES_USER_WORD_0) 2048 clock cycles  */
#define   FUSES_USER_WORD_0_WDT_PER_CYC4096_Val _UINT32_(0x9)                                        /* (FUSES_USER_WORD_0) 4096 clock cycles  */
#define   FUSES_USER_WORD_0_WDT_PER_CYC8192_Val _UINT32_(0xA)                                        /* (FUSES_USER_WORD_0) 8192 clock cycles  */
#define   FUSES_USER_WORD_0_WDT_PER_CYC16384_Val _UINT32_(0xB)                                        /* (FUSES_USER_WORD_0) 16384 clock cycles  */
#define FUSES_USER_WORD_0_WDT_PER_CYC8        (FUSES_USER_WORD_0_WDT_PER_CYC8_Val << FUSES_USER_WORD_0_WDT_PER_Pos) /* (FUSES_USER_WORD_0) 8 clock cycles Position  */
#define FUSES_USER_WORD_0_WDT_PER_CYC16       (FUSES_USER_WORD_0_WDT_PER_CYC16_Val << FUSES_USER_WORD_0_WDT_PER_Pos) /* (FUSES_USER_WORD_0) 16 clock cycles Position  */
#define FUSES_USER_WORD_0_WDT_PER_CYC32       (FUSES_USER_WORD_0_WDT_PER_CYC32_Val << FUSES_USER_WORD_0_WDT_PER_Pos) /* (FUSES_USER_WORD_0) 32 clock cycles Position  */
#define FUSES_USER_WORD_0_WDT_PER_CYC64       (FUSES_USER_WORD_0_WDT_PER_CYC64_Val << FUSES_USER_WORD_0_WDT_PER_Pos) /* (FUSES_USER_WORD_0) 64 clock cycles Position  */
#define FUSES_USER_WORD_0_WDT_PER_CYC128      (FUSES_USER_WORD_0_WDT_PER_CYC128_Val << FUSES_USER_WORD_0_WDT_PER_Pos) /* (FUSES_USER_WORD_0) 128 clock cycles Position  */
#define FUSES_USER_WORD_0_WDT_PER_CYC256      (FUSES_USER_WORD_0_WDT_PER_CYC256_Val << FUSES_USER_WORD_0_WDT_PER_Pos) /* (FUSES_USER_WORD_0) 256 clock cycles Position  */
#define FUSES_USER_WORD_0_WDT_PER_CYC512      (FUSES_USER_WORD_0_WDT_PER_CYC512_Val << FUSES_USER_WORD_0_WDT_PER_Pos) /* (FUSES_USER_WORD_0) 512 clock cycles Position  */
#define FUSES_USER_WORD_0_WDT_PER_CYC1024     (FUSES_USER_WORD_0_WDT_PER_CYC1024_Val << FUSES_USER_WORD_0_WDT_PER_Pos) /* (FUSES_USER_WORD_0) 1024 clock cycles Position  */
#define FUSES_USER_WORD_0_WDT_PER_CYC2048     (FUSES_USER_WORD_0_WDT_PER_CYC2048_Val << FUSES_USER_WORD_0_WDT_PER_Pos) /* (FUSES_USER_WORD_0) 2048 clock cycles Position  */
#define FUSES_USER_WORD_0_WDT_PER_CYC4096     (FUSES_USER_WORD_0_WDT_PER_CYC4096_Val << FUSES_USER_WORD_0_WDT_PER_Pos) /* (FUSES_USER_WORD_0) 4096 clock cycles Position  */
#define FUSES_USER_WORD_0_WDT_PER_CYC8192     (FUSES_USER_WORD_0_WDT_PER_CYC8192_Val << FUSES_USER_WORD_0_WDT_PER_Pos) /* (FUSES_USER_WORD_0) 8192 clock cycles Position  */
#define FUSES_USER_WORD_0_WDT_PER_CYC16384    (FUSES_USER_WORD_0_WDT_PER_CYC16384_Val << FUSES_USER_WORD_0_WDT_PER_Pos) /* (FUSES_USER_WORD_0) 16384 clock cycles Position  */
#define FUSES_USER_WORD_0_Msk                 _UINT32_(0xFE00FFB8)                                 /* (FUSES_USER_WORD_0) Register Mask  */


/* -------- FUSES_USER_WORD_1 : (FUSES Offset: 0x04) (R/W 32) USER Page Word 1 -------- */
#define FUSES_USER_WORD_1_RESETVALUE          _UINT32_(0xFFFFFCBB)                                 /*  (FUSES_USER_WORD_1) USER Page Word 1  Reset Value */

#define FUSES_USER_WORD_1_WDT_WINDOW_Pos      _UINT32_(0)                                          /* (FUSES_USER_WORD_1) WDT Window Position */
#define FUSES_USER_WORD_1_WDT_WINDOW_Msk      (_UINT32_(0xF) << FUSES_USER_WORD_1_WDT_WINDOW_Pos)  /* (FUSES_USER_WORD_1) WDT Window Mask */
#define FUSES_USER_WORD_1_WDT_WINDOW(value)   (FUSES_USER_WORD_1_WDT_WINDOW_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_WDT_WINDOW_Pos)) /* Assigment of value for WDT_WINDOW in the FUSES_USER_WORD_1 register */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC8_Val _UINT32_(0x0)                                        /* (FUSES_USER_WORD_1) 8 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC16_Val _UINT32_(0x1)                                        /* (FUSES_USER_WORD_1) 16 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC32_Val _UINT32_(0x2)                                        /* (FUSES_USER_WORD_1) 32 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC64_Val _UINT32_(0x3)                                        /* (FUSES_USER_WORD_1) 64 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC128_Val _UINT32_(0x4)                                        /* (FUSES_USER_WORD_1) 128 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC256_Val _UINT32_(0x5)                                        /* (FUSES_USER_WORD_1) 256 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC512_Val _UINT32_(0x6)                                        /* (FUSES_USER_WORD_1) 512 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC1024_Val _UINT32_(0x7)                                        /* (FUSES_USER_WORD_1) 1024 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC2048_Val _UINT32_(0x8)                                        /* (FUSES_USER_WORD_1) 2048 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC4096_Val _UINT32_(0x9)                                        /* (FUSES_USER_WORD_1) 4096 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC8192_Val _UINT32_(0xA)                                        /* (FUSES_USER_WORD_1) 8192 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC16384_Val _UINT32_(0xB)                                        /* (FUSES_USER_WORD_1) 16384 clock cycles  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC8     (FUSES_USER_WORD_1_WDT_WINDOW_CYC8_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 8 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC16    (FUSES_USER_WORD_1_WDT_WINDOW_CYC16_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 16 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC32    (FUSES_USER_WORD_1_WDT_WINDOW_CYC32_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 32 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC64    (FUSES_USER_WORD_1_WDT_WINDOW_CYC64_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 64 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC128   (FUSES_USER_WORD_1_WDT_WINDOW_CYC128_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 128 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC256   (FUSES_USER_WORD_1_WDT_WINDOW_CYC256_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 256 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC512   (FUSES_USER_WORD_1_WDT_WINDOW_CYC512_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 512 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC1024  (FUSES_USER_WORD_1_WDT_WINDOW_CYC1024_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 1024 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC2048  (FUSES_USER_WORD_1_WDT_WINDOW_CYC2048_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 2048 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC4096  (FUSES_USER_WORD_1_WDT_WINDOW_CYC4096_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 4096 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC8192  (FUSES_USER_WORD_1_WDT_WINDOW_CYC8192_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 8192 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC16384 (FUSES_USER_WORD_1_WDT_WINDOW_CYC16384_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 16384 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_Pos    _UINT32_(4)                                          /* (FUSES_USER_WORD_1) WDT Early Warning Offset Position */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_Msk    (_UINT32_(0xF) << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) WDT Early Warning Offset Mask */
#define FUSES_USER_WORD_1_WDT_EWOFFSET(value) (FUSES_USER_WORD_1_WDT_EWOFFSET_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos)) /* Assigment of value for WDT_EWOFFSET in the FUSES_USER_WORD_1 register */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC8_Val _UINT32_(0x0)                                        /* (FUSES_USER_WORD_1) 8 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC16_Val _UINT32_(0x1)                                        /* (FUSES_USER_WORD_1) 16 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC32_Val _UINT32_(0x2)                                        /* (FUSES_USER_WORD_1) 32 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC64_Val _UINT32_(0x3)                                        /* (FUSES_USER_WORD_1) 64 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC128_Val _UINT32_(0x4)                                        /* (FUSES_USER_WORD_1) 128 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC256_Val _UINT32_(0x5)                                        /* (FUSES_USER_WORD_1) 256 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC512_Val _UINT32_(0x6)                                        /* (FUSES_USER_WORD_1) 512 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC1024_Val _UINT32_(0x7)                                        /* (FUSES_USER_WORD_1) 1024 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC2048_Val _UINT32_(0x8)                                        /* (FUSES_USER_WORD_1) 2048 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC4096_Val _UINT32_(0x9)                                        /* (FUSES_USER_WORD_1) 4096 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC8192_Val _UINT32_(0xA)                                        /* (FUSES_USER_WORD_1) 8192 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC16384_Val _UINT32_(0xB)                                        /* (FUSES_USER_WORD_1) 16384 clock cycles  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC8   (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC8_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 8 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC16  (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC16_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 16 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC32  (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC32_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 32 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC64  (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC64_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 64 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC128 (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC128_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 128 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC256 (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC256_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 256 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC512 (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC512_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 512 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC1024 (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC1024_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 1024 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC2048 (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC2048_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 2048 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC4096 (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC4096_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 4096 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC8192 (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC8192_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 8192 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC16384 (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC16384_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 16384 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WEN_Pos         _UINT32_(8)                                          /* (FUSES_USER_WORD_1) WDT Window Mode Enable Position */
#define FUSES_USER_WORD_1_WDT_WEN_Msk         (_UINT32_(0x1) << FUSES_USER_WORD_1_WDT_WEN_Pos)     /* (FUSES_USER_WORD_1) WDT Window Mode Enable Mask */
#define FUSES_USER_WORD_1_WDT_WEN(value)      (FUSES_USER_WORD_1_WDT_WEN_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_WDT_WEN_Pos)) /* Assigment of value for WDT_WEN in the FUSES_USER_WORD_1 register */
#define FUSES_USER_WORD_1_BOD33_HYST_Pos      _UINT32_(9)                                          /* (FUSES_USER_WORD_1) BOD33 Hysteresis Position */
#define FUSES_USER_WORD_1_BOD33_HYST_Msk      (_UINT32_(0x1) << FUSES_USER_WORD_1_BOD33_HYST_Pos)  /* (FUSES_USER_WORD_1) BOD33 Hysteresis Mask */
#define FUSES_USER_WORD_1_BOD33_HYST(value)   (FUSES_USER_WORD_1_BOD33_HYST_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_BOD33_HYST_Pos)) /* Assigment of value for BOD33_HYST in the FUSES_USER_WORD_1 register */
#define FUSES_USER_WORD_1_Msk                 _UINT32_(0x000003FF)                                 /* (FUSES_USER_WORD_1) Register Mask  */


/** \brief FUSES register offsets definitions */
#define FUSES_SW_CALIB_WORD_0_REG_OFST _UINT32_(0x00)      /* (FUSES_SW_CALIB_WORD_0) SW_CALIB Page Word 0 Offset */
#define FUSES_TEMP_LOG_WORD_0_REG_OFST _UINT32_(0x00)      /* (FUSES_TEMP_LOG_WORD_0) TEMP_LOG Page Word 0 Offset */
#define FUSES_TEMP_LOG_WORD_1_REG_OFST _UINT32_(0x04)      /* (FUSES_TEMP_LOG_WORD_1) TEMP_LOG Page Word 1 Offset */
#define FUSES_BOCOR_WORD_1_REG_OFST    _UINT32_(0x04)      /* (FUSES_BOCOR_WORD_1) BOCOR Page Word 1 Offset */
#define FUSES_BOCOR_WORD_16_REG_OFST   _UINT32_(0x40)      /* (FUSES_BOCOR_WORD_16) BOCOR Page Word 16 Offset */
#define FUSES_BOCOR_WORD_17_REG_OFST   _UINT32_(0x44)      /* (FUSES_BOCOR_WORD_17) BOCOR Page Word 17 Offset */
#define FUSES_BOCOR_WORD_18_REG_OFST   _UINT32_(0x48)      /* (FUSES_BOCOR_WORD_18) BOCOR Page Word 18 Offset */
#define FUSES_BOCOR_WORD_19_REG_OFST   _UINT32_(0x4C)      /* (FUSES_BOCOR_WORD_19) BOCOR Page Word 19 Offset */
#define FUSES_USER_WORD_0_REG_OFST     _UINT32_(0x00)      /* (FUSES_USER_WORD_0) USER Page Word 0 Offset */
#define FUSES_USER_WORD_1_REG_OFST     _UINT32_(0x04)      /* (FUSES_USER_WORD_1) USER Page Word 1 Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief SW_CALIB_FUSES register API structure */
typedef struct
{
  __I   uint32_t                       FUSES_SW_CALIB_WORD_0; /**< Offset: 0x00 (R/   32) SW_CALIB Page Word 0 */
} fuses_sw_calib_fuses_registers_t;

/** \brief TEMP_LOG_FUSES register API structure */
typedef struct
{
  __I   uint32_t                       FUSES_TEMP_LOG_WORD_0; /**< Offset: 0x00 (R/   32) TEMP_LOG Page Word 0 */
  __I   uint32_t                       FUSES_TEMP_LOG_WORD_1; /**< Offset: 0x04 (R/   32) TEMP_LOG Page Word 1 */
} fuses_temp_log_fuses_registers_t;

/** \brief BOCOR_FUSES register API structure */
typedef struct
{
  __I   uint8_t                        Reserved1[0x04];
  __IO  uint32_t                       FUSES_BOCOR_WORD_1; /**< Offset: 0x04 (R/W  32) BOCOR Page Word 1 */
  __I   uint8_t                        Reserved2[0x38];
  __IO  uint32_t                       FUSES_BOCOR_WORD_16; /**< Offset: 0x40 (R/W  32) BOCOR Page Word 16 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_17; /**< Offset: 0x44 (R/W  32) BOCOR Page Word 17 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_18; /**< Offset: 0x48 (R/W  32) BOCOR Page Word 18 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_19; /**< Offset: 0x4C (R/W  32) BOCOR Page Word 19 */
} fuses_bocor_fuses_registers_t;

/** \brief USER_FUSES register API structure */
typedef struct
{
  __IO  uint32_t                       FUSES_USER_WORD_0;  /**< Offset: 0x00 (R/W  32) USER Page Word 0 */
  __IO  uint32_t                       FUSES_USER_WORD_1;  /**< Offset: 0x04 (R/W  32) USER Page Word 1 */
} fuses_user_fuses_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAML10_FUSES_COMPONENT_H_ */
