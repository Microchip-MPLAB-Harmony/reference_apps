/*
 * Component description for FUSES
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

/* file generated from device description version 2022-03-14T06:33:44Z */
#ifndef _SAMC21_FUSES_COMPONENT_H_
#define _SAMC21_FUSES_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR FUSES                                        */
/* ************************************************************************** */

/* -------- FUSES_TEMP_LOG_WORD_0 : (FUSES Offset: 0x00) ( R/ 32) TEMP_LOG Page Word 0 -------- */
#define FUSES_TEMP_LOG_WORD_0_TSENS_TCAL_Pos  _UINT32_(0)                                          /* (FUSES_TEMP_LOG_WORD_0) Temperature Calibration Position */
#define FUSES_TEMP_LOG_WORD_0_TSENS_TCAL_Msk  (_UINT32_(0x3F) << FUSES_TEMP_LOG_WORD_0_TSENS_TCAL_Pos) /* (FUSES_TEMP_LOG_WORD_0) Temperature Calibration Mask */
#define FUSES_TEMP_LOG_WORD_0_TSENS_TCAL(value) (FUSES_TEMP_LOG_WORD_0_TSENS_TCAL_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_0_TSENS_TCAL_Pos)) /* Assigment of value for TSENS_TCAL in the FUSES_TEMP_LOG_WORD_0 register */
#define FUSES_TEMP_LOG_WORD_0_TSENS_FCAL_Pos  _UINT32_(6)                                          /* (FUSES_TEMP_LOG_WORD_0) Frequency Calibration Position */
#define FUSES_TEMP_LOG_WORD_0_TSENS_FCAL_Msk  (_UINT32_(0x3F) << FUSES_TEMP_LOG_WORD_0_TSENS_FCAL_Pos) /* (FUSES_TEMP_LOG_WORD_0) Frequency Calibration Mask */
#define FUSES_TEMP_LOG_WORD_0_TSENS_FCAL(value) (FUSES_TEMP_LOG_WORD_0_TSENS_FCAL_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_0_TSENS_FCAL_Pos)) /* Assigment of value for TSENS_FCAL in the FUSES_TEMP_LOG_WORD_0 register */
#define FUSES_TEMP_LOG_WORD_0_TSENS_GAIN_0_Pos _UINT32_(12)                                         /* (FUSES_TEMP_LOG_WORD_0) Gain Calibration bits 19:0 Position */
#define FUSES_TEMP_LOG_WORD_0_TSENS_GAIN_0_Msk (_UINT32_(0xFFFFF) << FUSES_TEMP_LOG_WORD_0_TSENS_GAIN_0_Pos) /* (FUSES_TEMP_LOG_WORD_0) Gain Calibration bits 19:0 Mask */
#define FUSES_TEMP_LOG_WORD_0_TSENS_GAIN_0(value) (FUSES_TEMP_LOG_WORD_0_TSENS_GAIN_0_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_0_TSENS_GAIN_0_Pos)) /* Assigment of value for TSENS_GAIN_0 in the FUSES_TEMP_LOG_WORD_0 register */
#define FUSES_TEMP_LOG_WORD_0_Msk             _UINT32_(0xFFFFFFFF)                                 /* (FUSES_TEMP_LOG_WORD_0) Register Mask  */


/* -------- FUSES_TEMP_LOG_WORD_1 : (FUSES Offset: 0x04) ( R/ 32) TEMP_LOG Page Word 1 -------- */
#define FUSES_TEMP_LOG_WORD_1_TSENS_GAIN_1_Pos _UINT32_(0)                                          /* (FUSES_TEMP_LOG_WORD_1) Gain Calibration bits 23:20 Position */
#define FUSES_TEMP_LOG_WORD_1_TSENS_GAIN_1_Msk (_UINT32_(0xF) << FUSES_TEMP_LOG_WORD_1_TSENS_GAIN_1_Pos) /* (FUSES_TEMP_LOG_WORD_1) Gain Calibration bits 23:20 Mask */
#define FUSES_TEMP_LOG_WORD_1_TSENS_GAIN_1(value) (FUSES_TEMP_LOG_WORD_1_TSENS_GAIN_1_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_1_TSENS_GAIN_1_Pos)) /* Assigment of value for TSENS_GAIN_1 in the FUSES_TEMP_LOG_WORD_1 register */
#define FUSES_TEMP_LOG_WORD_1_TSENS_OFFSET_Pos _UINT32_(4)                                          /* (FUSES_TEMP_LOG_WORD_1) Offse Calibration Position */
#define FUSES_TEMP_LOG_WORD_1_TSENS_OFFSET_Msk (_UINT32_(0xFFFFFF) << FUSES_TEMP_LOG_WORD_1_TSENS_OFFSET_Pos) /* (FUSES_TEMP_LOG_WORD_1) Offse Calibration Mask */
#define FUSES_TEMP_LOG_WORD_1_TSENS_OFFSET(value) (FUSES_TEMP_LOG_WORD_1_TSENS_OFFSET_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_1_TSENS_OFFSET_Pos)) /* Assigment of value for TSENS_OFFSET in the FUSES_TEMP_LOG_WORD_1 register */
#define FUSES_TEMP_LOG_WORD_1_Msk             _UINT32_(0x0FFFFFFF)                                 /* (FUSES_TEMP_LOG_WORD_1) Register Mask  */


/* -------- FUSES_OTP5_WORD_0 : (FUSES Offset: 0x00) ( R/ 32) OTP5 Page Word 0 -------- */
#define FUSES_OTP5_WORD_0_ADC0_BIASREFBUF_Pos _UINT32_(0)                                          /* (FUSES_OTP5_WORD_0) ADC Bias Reference Buffer Scaling Position */
#define FUSES_OTP5_WORD_0_ADC0_BIASREFBUF_Msk (_UINT32_(0x7) << FUSES_OTP5_WORD_0_ADC0_BIASREFBUF_Pos) /* (FUSES_OTP5_WORD_0) ADC Bias Reference Buffer Scaling Mask */
#define FUSES_OTP5_WORD_0_ADC0_BIASREFBUF(value) (FUSES_OTP5_WORD_0_ADC0_BIASREFBUF_Msk & (_UINT32_(value) << FUSES_OTP5_WORD_0_ADC0_BIASREFBUF_Pos)) /* Assigment of value for ADC0_BIASREFBUF in the FUSES_OTP5_WORD_0 register */
#define FUSES_OTP5_WORD_0_ADC0_BIASCOMP_Pos   _UINT32_(3)                                          /* (FUSES_OTP5_WORD_0) ADC Comparator Scaling Position */
#define FUSES_OTP5_WORD_0_ADC0_BIASCOMP_Msk   (_UINT32_(0x7) << FUSES_OTP5_WORD_0_ADC0_BIASCOMP_Pos) /* (FUSES_OTP5_WORD_0) ADC Comparator Scaling Mask */
#define FUSES_OTP5_WORD_0_ADC0_BIASCOMP(value) (FUSES_OTP5_WORD_0_ADC0_BIASCOMP_Msk & (_UINT32_(value) << FUSES_OTP5_WORD_0_ADC0_BIASCOMP_Pos)) /* Assigment of value for ADC0_BIASCOMP in the FUSES_OTP5_WORD_0 register */
#define FUSES_OTP5_WORD_0_ADC1_BIASREFBUF_Pos _UINT32_(6)                                          /* (FUSES_OTP5_WORD_0) ADC Bias Reference Buffer Scaling Position */
#define FUSES_OTP5_WORD_0_ADC1_BIASREFBUF_Msk (_UINT32_(0x7) << FUSES_OTP5_WORD_0_ADC1_BIASREFBUF_Pos) /* (FUSES_OTP5_WORD_0) ADC Bias Reference Buffer Scaling Mask */
#define FUSES_OTP5_WORD_0_ADC1_BIASREFBUF(value) (FUSES_OTP5_WORD_0_ADC1_BIASREFBUF_Msk & (_UINT32_(value) << FUSES_OTP5_WORD_0_ADC1_BIASREFBUF_Pos)) /* Assigment of value for ADC1_BIASREFBUF in the FUSES_OTP5_WORD_0 register */
#define FUSES_OTP5_WORD_0_ADC1_BIASCOMP_Pos   _UINT32_(9)                                          /* (FUSES_OTP5_WORD_0) ADC Comparator Scaling Position */
#define FUSES_OTP5_WORD_0_ADC1_BIASCOMP_Msk   (_UINT32_(0x7) << FUSES_OTP5_WORD_0_ADC1_BIASCOMP_Pos) /* (FUSES_OTP5_WORD_0) ADC Comparator Scaling Mask */
#define FUSES_OTP5_WORD_0_ADC1_BIASCOMP(value) (FUSES_OTP5_WORD_0_ADC1_BIASCOMP_Msk & (_UINT32_(value) << FUSES_OTP5_WORD_0_ADC1_BIASCOMP_Pos)) /* Assigment of value for ADC1_BIASCOMP in the FUSES_OTP5_WORD_0 register */
#define FUSES_OTP5_WORD_0_Msk                 _UINT32_(0x00000FFF)                                 /* (FUSES_OTP5_WORD_0) Register Mask  */


/* -------- FUSES_USER_WORD_0 : (FUSES Offset: 0x00) (R/W 32) USER Page Word 0 -------- */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos _UINT32_(0)                                          /* (FUSES_USER_WORD_0) Bootloader Size Position */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Msk (_UINT32_(0x7) << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) Bootloader Size Mask */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT(value) (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos)) /* Assigment of value for NVMCTRL_BOOTPROT in the FUSES_USER_WORD_0 register */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_0BYTES_Val _UINT32_(0x7)                                        /* (FUSES_USER_WORD_0) 0 Bytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_512BYTES_Val _UINT32_(0x6)                                        /* (FUSES_USER_WORD_0) 512 Bytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_1024BYTES_Val _UINT32_(0x5)                                        /* (FUSES_USER_WORD_0) 1024 Bytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_2048BYTES_Val _UINT32_(0x4)                                        /* (FUSES_USER_WORD_0) 2048 Bytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_4096BYTES_Val _UINT32_(0x3)                                        /* (FUSES_USER_WORD_0) 4096 Bytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_8192BYTES_Val _UINT32_(0x2)                                        /* (FUSES_USER_WORD_0) 8192 Bytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_16384BYTES_Val _UINT32_(0x1)                                        /* (FUSES_USER_WORD_0) 16384 Bytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_32768BYTES_Val _UINT32_(0x0)                                        /* (FUSES_USER_WORD_0) 32768 Bytes  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_0BYTES (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_0BYTES_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 0 Bytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_512BYTES (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_512BYTES_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 512 Bytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_1024BYTES (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_1024BYTES_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 1024 Bytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_2048BYTES (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_2048BYTES_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 2048 Bytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_4096BYTES (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_4096BYTES_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 4096 Bytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_8192BYTES (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_8192BYTES_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 8192 Bytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_16384BYTES (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_16384BYTES_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 16384 Bytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_32768BYTES (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_SIZE_32768BYTES_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 32768 Bytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_Pos _UINT32_(4)                                          /* (FUSES_USER_WORD_0) EEPROM Size Position */
#define FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_Msk (_UINT32_(0x7) << FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_Pos) /* (FUSES_USER_WORD_0) EEPROM Size Mask */
#define FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE(value) (FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_Pos)) /* Assigment of value for NVMCTRL_EEPROM_SIZE in the FUSES_USER_WORD_0 register */
#define   FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_0BYTES_Val _UINT32_(0x7)                                        /* (FUSES_USER_WORD_0) 0 Bytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_256BYTES_Val _UINT32_(0x6)                                        /* (FUSES_USER_WORD_0) 256 Bytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_512BYTES_Val _UINT32_(0x5)                                        /* (FUSES_USER_WORD_0) 512 Bytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_1024BYTES_Val _UINT32_(0x4)                                        /* (FUSES_USER_WORD_0) 1024 Bytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_2048BYTES_Val _UINT32_(0x3)                                        /* (FUSES_USER_WORD_0) 2048 Bytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_4096BYTES_Val _UINT32_(0x2)                                        /* (FUSES_USER_WORD_0) 4096 Bytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_8192BYTES_Val _UINT32_(0x1)                                        /* (FUSES_USER_WORD_0) 8192 Bytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_16384BYTES_Val _UINT32_(0x0)                                        /* (FUSES_USER_WORD_0) 16384 Bytes  */
#define FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_0BYTES (FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_0BYTES_Val << FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_Pos) /* (FUSES_USER_WORD_0) 0 Bytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_256BYTES (FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_256BYTES_Val << FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_Pos) /* (FUSES_USER_WORD_0) 256 Bytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_512BYTES (FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_512BYTES_Val << FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_Pos) /* (FUSES_USER_WORD_0) 512 Bytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_1024BYTES (FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_1024BYTES_Val << FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_Pos) /* (FUSES_USER_WORD_0) 1024 Bytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_2048BYTES (FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_2048BYTES_Val << FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_Pos) /* (FUSES_USER_WORD_0) 2048 Bytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_4096BYTES (FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_4096BYTES_Val << FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_Pos) /* (FUSES_USER_WORD_0) 4096 Bytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_8192BYTES (FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_8192BYTES_Val << FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_Pos) /* (FUSES_USER_WORD_0) 8192 Bytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_16384BYTES (FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_SIZE_16384BYTES_Val << FUSES_USER_WORD_0_NVMCTRL_EEPROM_SIZE_Pos) /* (FUSES_USER_WORD_0) 16384 Bytes Position  */
#define FUSES_USER_WORD_0_BODVDDUSERLEVEL_Pos _UINT32_(8)                                          /* (FUSES_USER_WORD_0) BODVDD User Level Position */
#define FUSES_USER_WORD_0_BODVDDUSERLEVEL_Msk (_UINT32_(0x3F) << FUSES_USER_WORD_0_BODVDDUSERLEVEL_Pos) /* (FUSES_USER_WORD_0) BODVDD User Level Mask */
#define FUSES_USER_WORD_0_BODVDDUSERLEVEL(value) (FUSES_USER_WORD_0_BODVDDUSERLEVEL_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_BODVDDUSERLEVEL_Pos)) /* Assigment of value for BODVDDUSERLEVEL in the FUSES_USER_WORD_0 register */
#define FUSES_USER_WORD_0_BODVDD_DIS_Pos      _UINT32_(14)                                         /* (FUSES_USER_WORD_0) BODVDD Disable Position */
#define FUSES_USER_WORD_0_BODVDD_DIS_Msk      (_UINT32_(0x1) << FUSES_USER_WORD_0_BODVDD_DIS_Pos)  /* (FUSES_USER_WORD_0) BODVDD Disable Mask */
#define FUSES_USER_WORD_0_BODVDD_DIS(value)   (FUSES_USER_WORD_0_BODVDD_DIS_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_BODVDD_DIS_Pos)) /* Assigment of value for BODVDD_DIS in the FUSES_USER_WORD_0 register */
#define   FUSES_USER_WORD_0_BODVDD_DIS_DISABLED_Val _UINT32_(0x0)                                        /* (FUSES_USER_WORD_0) BODVDD is disabled  */
#define   FUSES_USER_WORD_0_BODVDD_DIS_ENABLED_Val _UINT32_(0x1)                                        /* (FUSES_USER_WORD_0) BODVDD is enabled  */
#define FUSES_USER_WORD_0_BODVDD_DIS_DISABLED (FUSES_USER_WORD_0_BODVDD_DIS_DISABLED_Val << FUSES_USER_WORD_0_BODVDD_DIS_Pos) /* (FUSES_USER_WORD_0) BODVDD is disabled Position  */
#define FUSES_USER_WORD_0_BODVDD_DIS_ENABLED  (FUSES_USER_WORD_0_BODVDD_DIS_ENABLED_Val << FUSES_USER_WORD_0_BODVDD_DIS_Pos) /* (FUSES_USER_WORD_0) BODVDD is enabled Position  */
#define FUSES_USER_WORD_0_BODVDD_ACTION_Pos   _UINT32_(15)                                         /* (FUSES_USER_WORD_0) BODVDD Action Position */
#define FUSES_USER_WORD_0_BODVDD_ACTION_Msk   (_UINT32_(0x3) << FUSES_USER_WORD_0_BODVDD_ACTION_Pos) /* (FUSES_USER_WORD_0) BODVDD Action Mask */
#define FUSES_USER_WORD_0_BODVDD_ACTION(value) (FUSES_USER_WORD_0_BODVDD_ACTION_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_BODVDD_ACTION_Pos)) /* Assigment of value for BODVDD_ACTION in the FUSES_USER_WORD_0 register */
#define   FUSES_USER_WORD_0_BODVDD_ACTION_NONE_Val _UINT32_(0x0)                                        /* (FUSES_USER_WORD_0) No action  */
#define   FUSES_USER_WORD_0_BODVDD_ACTION_RESET_Val _UINT32_(0x1)                                        /* (FUSES_USER_WORD_0) The BODVDD generates a reset  */
#define   FUSES_USER_WORD_0_BODVDD_ACTION_INT_Val _UINT32_(0x2)                                        /* (FUSES_USER_WORD_0) The BODVDD generates an interrupt  */
#define FUSES_USER_WORD_0_BODVDD_ACTION_NONE  (FUSES_USER_WORD_0_BODVDD_ACTION_NONE_Val << FUSES_USER_WORD_0_BODVDD_ACTION_Pos) /* (FUSES_USER_WORD_0) No action Position  */
#define FUSES_USER_WORD_0_BODVDD_ACTION_RESET (FUSES_USER_WORD_0_BODVDD_ACTION_RESET_Val << FUSES_USER_WORD_0_BODVDD_ACTION_Pos) /* (FUSES_USER_WORD_0) The BODVDD generates a reset Position  */
#define FUSES_USER_WORD_0_BODVDD_ACTION_INT   (FUSES_USER_WORD_0_BODVDD_ACTION_INT_Val << FUSES_USER_WORD_0_BODVDD_ACTION_Pos) /* (FUSES_USER_WORD_0) The BODVDD generates an interrupt Position  */
#define FUSES_USER_WORD_0_WDT_ENABLE_Pos      _UINT32_(26)                                         /* (FUSES_USER_WORD_0) WDT Enable Position */
#define FUSES_USER_WORD_0_WDT_ENABLE_Msk      (_UINT32_(0x1) << FUSES_USER_WORD_0_WDT_ENABLE_Pos)  /* (FUSES_USER_WORD_0) WDT Enable Mask */
#define FUSES_USER_WORD_0_WDT_ENABLE(value)   (FUSES_USER_WORD_0_WDT_ENABLE_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_WDT_ENABLE_Pos)) /* Assigment of value for WDT_ENABLE in the FUSES_USER_WORD_0 register */
#define   FUSES_USER_WORD_0_WDT_ENABLE_DISABLED_Val _UINT32_(0x0)                                        /* (FUSES_USER_WORD_0) WDT is disabled  */
#define   FUSES_USER_WORD_0_WDT_ENABLE_ENABLED_Val _UINT32_(0x1)                                        /* (FUSES_USER_WORD_0) WDT is enabled  */
#define FUSES_USER_WORD_0_WDT_ENABLE_DISABLED (FUSES_USER_WORD_0_WDT_ENABLE_DISABLED_Val << FUSES_USER_WORD_0_WDT_ENABLE_Pos) /* (FUSES_USER_WORD_0) WDT is disabled Position  */
#define FUSES_USER_WORD_0_WDT_ENABLE_ENABLED  (FUSES_USER_WORD_0_WDT_ENABLE_ENABLED_Val << FUSES_USER_WORD_0_WDT_ENABLE_Pos) /* (FUSES_USER_WORD_0) WDT is enabled Position  */
#define FUSES_USER_WORD_0_WDT_ALWAYSON_Pos    _UINT32_(27)                                         /* (FUSES_USER_WORD_0) WDT Always On Position */
#define FUSES_USER_WORD_0_WDT_ALWAYSON_Msk    (_UINT32_(0x1) << FUSES_USER_WORD_0_WDT_ALWAYSON_Pos) /* (FUSES_USER_WORD_0) WDT Always On Mask */
#define FUSES_USER_WORD_0_WDT_ALWAYSON(value) (FUSES_USER_WORD_0_WDT_ALWAYSON_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_WDT_ALWAYSON_Pos)) /* Assigment of value for WDT_ALWAYSON in the FUSES_USER_WORD_0 register */
#define   FUSES_USER_WORD_0_WDT_ALWAYSON_DISABLED_Val _UINT32_(0x0)                                        /* (FUSES_USER_WORD_0) WDT is enabled and disabled through ENABLE bit  */
#define   FUSES_USER_WORD_0_WDT_ALWAYSON_ENABLED_Val _UINT32_(0x1)                                        /* (FUSES_USER_WORD_0) WDT is enabled and can only be disabled by a power-on reset  */
#define FUSES_USER_WORD_0_WDT_ALWAYSON_DISABLED (FUSES_USER_WORD_0_WDT_ALWAYSON_DISABLED_Val << FUSES_USER_WORD_0_WDT_ALWAYSON_Pos) /* (FUSES_USER_WORD_0) WDT is enabled and disabled through ENABLE bit Position  */
#define FUSES_USER_WORD_0_WDT_ALWAYSON_ENABLED (FUSES_USER_WORD_0_WDT_ALWAYSON_ENABLED_Val << FUSES_USER_WORD_0_WDT_ALWAYSON_Pos) /* (FUSES_USER_WORD_0) WDT is enabled and can only be disabled by a power-on reset Position  */
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
#define FUSES_USER_WORD_0_Msk                 _UINT32_(0xFC01FF77)                                 /* (FUSES_USER_WORD_0) Register Mask  */


/* -------- FUSES_USER_WORD_1 : (FUSES Offset: 0x04) (R/W 32) USER Page Word 1 -------- */
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
#define   FUSES_USER_WORD_1_WDT_WEN_DISABLED_Val _UINT32_(0x0)                                        /* (FUSES_USER_WORD_1) WDT is disabled  */
#define   FUSES_USER_WORD_1_WDT_WEN_ENABLED_Val _UINT32_(0x1)                                        /* (FUSES_USER_WORD_1) WDT is enabled  */
#define FUSES_USER_WORD_1_WDT_WEN_DISABLED    (FUSES_USER_WORD_1_WDT_WEN_DISABLED_Val << FUSES_USER_WORD_1_WDT_WEN_Pos) /* (FUSES_USER_WORD_1) WDT is disabled Position  */
#define FUSES_USER_WORD_1_WDT_WEN_ENABLED     (FUSES_USER_WORD_1_WDT_WEN_ENABLED_Val << FUSES_USER_WORD_1_WDT_WEN_Pos) /* (FUSES_USER_WORD_1) WDT is enabled Position  */
#define FUSES_USER_WORD_1_BODVDD_HYST_Pos     _UINT32_(9)                                          /* (FUSES_USER_WORD_1) BODVDD Hysterisis Position */
#define FUSES_USER_WORD_1_BODVDD_HYST_Msk     (_UINT32_(0x1) << FUSES_USER_WORD_1_BODVDD_HYST_Pos) /* (FUSES_USER_WORD_1) BODVDD Hysterisis Mask */
#define FUSES_USER_WORD_1_BODVDD_HYST(value)  (FUSES_USER_WORD_1_BODVDD_HYST_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_BODVDD_HYST_Pos)) /* Assigment of value for BODVDD_HYST in the FUSES_USER_WORD_1 register */
#define   FUSES_USER_WORD_1_BODVDD_HYST_DISABLED_Val _UINT32_(0x0)                                        /* (FUSES_USER_WORD_1) No Hysteresis  */
#define   FUSES_USER_WORD_1_BODVDD_HYST_ENABLED_Val _UINT32_(0x1)                                        /* (FUSES_USER_WORD_1) Hysteresis Enabled  */
#define FUSES_USER_WORD_1_BODVDD_HYST_DISABLED (FUSES_USER_WORD_1_BODVDD_HYST_DISABLED_Val << FUSES_USER_WORD_1_BODVDD_HYST_Pos) /* (FUSES_USER_WORD_1) No Hysteresis Position  */
#define FUSES_USER_WORD_1_BODVDD_HYST_ENABLED (FUSES_USER_WORD_1_BODVDD_HYST_ENABLED_Val << FUSES_USER_WORD_1_BODVDD_HYST_Pos) /* (FUSES_USER_WORD_1) Hysteresis Enabled Position  */
#define FUSES_USER_WORD_1_NVMCTRL_REGION_LOCKS_Pos _UINT32_(16)                                         /* (FUSES_USER_WORD_1) NVM Region Locks Position */
#define FUSES_USER_WORD_1_NVMCTRL_REGION_LOCKS_Msk (_UINT32_(0xFFFF) << FUSES_USER_WORD_1_NVMCTRL_REGION_LOCKS_Pos) /* (FUSES_USER_WORD_1) NVM Region Locks Mask */
#define FUSES_USER_WORD_1_NVMCTRL_REGION_LOCKS(value) (FUSES_USER_WORD_1_NVMCTRL_REGION_LOCKS_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_NVMCTRL_REGION_LOCKS_Pos)) /* Assigment of value for NVMCTRL_REGION_LOCKS in the FUSES_USER_WORD_1 register */
#define FUSES_USER_WORD_1_Msk                 _UINT32_(0xFFFF03FF)                                 /* (FUSES_USER_WORD_1) Register Mask  */


/** \brief FUSES register offsets definitions */
#define FUSES_TEMP_LOG_WORD_0_REG_OFST _UINT32_(0x00)      /* (FUSES_TEMP_LOG_WORD_0) TEMP_LOG Page Word 0 Offset */
#define FUSES_TEMP_LOG_WORD_1_REG_OFST _UINT32_(0x04)      /* (FUSES_TEMP_LOG_WORD_1) TEMP_LOG Page Word 1 Offset */
#define FUSES_OTP5_WORD_0_REG_OFST     _UINT32_(0x00)      /* (FUSES_OTP5_WORD_0) OTP5 Page Word 0 Offset */
#define FUSES_USER_WORD_0_REG_OFST     _UINT32_(0x00)      /* (FUSES_USER_WORD_0) USER Page Word 0 Offset */
#define FUSES_USER_WORD_1_REG_OFST     _UINT32_(0x04)      /* (FUSES_USER_WORD_1) USER Page Word 1 Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief TEMP_LOG_FUSES register API structure */
typedef struct
{
  __I   uint32_t                       FUSES_TEMP_LOG_WORD_0; /**< Offset: 0x00 (R/   32) TEMP_LOG Page Word 0 */
  __I   uint32_t                       FUSES_TEMP_LOG_WORD_1; /**< Offset: 0x04 (R/   32) TEMP_LOG Page Word 1 */
} fuses_temp_log_fuses_registers_t;

/** \brief OTP5_FUSES register API structure */
typedef struct
{
  __I   uint32_t                       FUSES_OTP5_WORD_0;  /**< Offset: 0x00 (R/   32) OTP5 Page Word 0 */
} fuses_otp5_fuses_registers_t;

/** \brief USER_FUSES register API structure */
typedef struct
{
  __IO  uint32_t                       FUSES_USER_WORD_0;  /**< Offset: 0x00 (R/W  32) USER Page Word 0 */
  __IO  uint32_t                       FUSES_USER_WORD_1;  /**< Offset: 0x04 (R/W  32) USER Page Word 1 */
} fuses_user_fuses_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMC21_FUSES_COMPONENT_H_ */
