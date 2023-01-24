/*
 * Component description for SQI
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

/* file generated from device description version 2022-07-07T22:59:24Z */
#ifndef _PIC32CZCA80_SQI_COMPONENT_H_
#define _PIC32CZCA80_SQI_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR SQI                                          */
/* ************************************************************************** */

/* -------- SQI_BDCTRL : (SQI Offset: 0x00) (R/W 32) Buffer Descriptor Control Register -------- */
#define SQI_BDCTRL_BD_BUFLEN_Pos              _UINT32_(0)                                          /* (SQI_BDCTRL) Buffer Descriptor Length Position */
#define SQI_BDCTRL_BD_BUFLEN_Msk              (_UINT32_(0x1FF) << SQI_BDCTRL_BD_BUFLEN_Pos)        /* (SQI_BDCTRL) Buffer Descriptor Length Mask */
#define SQI_BDCTRL_BD_BUFLEN(value)           (SQI_BDCTRL_BD_BUFLEN_Msk & (_UINT32_(value) << SQI_BDCTRL_BD_BUFLEN_Pos)) /* Assigment of value for BD_BUFLEN in the SQI_BDCTRL register */
#define SQI_BDCTRL_CBD_INT_EN_Pos             _UINT32_(16)                                         /* (SQI_BDCTRL) Generate Interrupt after processing the current buffer descriptor Position */
#define SQI_BDCTRL_CBD_INT_EN_Msk             (_UINT32_(0x1) << SQI_BDCTRL_CBD_INT_EN_Pos)         /* (SQI_BDCTRL) Generate Interrupt after processing the current buffer descriptor Mask */
#define SQI_BDCTRL_CBD_INT_EN(value)          (SQI_BDCTRL_CBD_INT_EN_Msk & (_UINT32_(value) << SQI_BDCTRL_CBD_INT_EN_Pos)) /* Assigment of value for CBD_INT_EN in the SQI_BDCTRL register */
#define SQI_BDCTRL_PKT_INT_EN_Pos             _UINT32_(17)                                         /* (SQI_BDCTRL) Generate Interrupt after processing the current buffer descriptor, if it is the end of the packet. Position */
#define SQI_BDCTRL_PKT_INT_EN_Msk             (_UINT32_(0x1) << SQI_BDCTRL_PKT_INT_EN_Pos)         /* (SQI_BDCTRL) Generate Interrupt after processing the current buffer descriptor, if it is the end of the packet. Mask */
#define SQI_BDCTRL_PKT_INT_EN(value)          (SQI_BDCTRL_PKT_INT_EN_Msk & (_UINT32_(value) << SQI_BDCTRL_PKT_INT_EN_Pos)) /* Assigment of value for PKT_INT_EN in the SQI_BDCTRL register */
#define SQI_BDCTRL_LIFM_Pos                   _UINT32_(18)                                         /* (SQI_BDCTRL) Indicates last data of the packet. Position */
#define SQI_BDCTRL_LIFM_Msk                   (_UINT32_(0x1) << SQI_BDCTRL_LIFM_Pos)               /* (SQI_BDCTRL) Indicates last data of the packet. Mask */
#define SQI_BDCTRL_LIFM(value)                (SQI_BDCTRL_LIFM_Msk & (_UINT32_(value) << SQI_BDCTRL_LIFM_Pos)) /* Assigment of value for LIFM in the SQI_BDCTRL register */
#define SQI_BDCTRL_LAST_BD_Pos                _UINT32_(19)                                         /* (SQI_BDCTRL) Last Buffer Descriptors. Position */
#define SQI_BDCTRL_LAST_BD_Msk                (_UINT32_(0x1) << SQI_BDCTRL_LAST_BD_Pos)            /* (SQI_BDCTRL) Last Buffer Descriptors. Mask */
#define SQI_BDCTRL_LAST_BD(value)             (SQI_BDCTRL_LAST_BD_Msk & (_UINT32_(value) << SQI_BDCTRL_LAST_BD_Pos)) /* Assigment of value for LAST_BD in the SQI_BDCTRL register */
#define SQI_BDCTRL_DIR_Pos                    _UINT32_(20)                                         /* (SQI_BDCTRL) Direction of data transfer. Position */
#define SQI_BDCTRL_DIR_Msk                    (_UINT32_(0x1) << SQI_BDCTRL_DIR_Pos)                /* (SQI_BDCTRL) Direction of data transfer. Mask */
#define SQI_BDCTRL_DIR(value)                 (SQI_BDCTRL_DIR_Msk & (_UINT32_(value) << SQI_BDCTRL_DIR_Pos)) /* Assigment of value for DIR in the SQI_BDCTRL register */
#define SQI_BDCTRL_SDR_DDR_Pos                _UINT32_(21)                                         /* (SQI_BDCTRL) SDR or DDR mode Position */
#define SQI_BDCTRL_SDR_DDR_Msk                (_UINT32_(0x1) << SQI_BDCTRL_SDR_DDR_Pos)            /* (SQI_BDCTRL) SDR or DDR mode Mask */
#define SQI_BDCTRL_SDR_DDR(value)             (SQI_BDCTRL_SDR_DDR_Msk & (_UINT32_(value) << SQI_BDCTRL_SDR_DDR_Pos)) /* Assigment of value for SDR_DDR in the SQI_BDCTRL register */
#define SQI_BDCTRL_MODE_Pos                   _UINT32_(22)                                         /* (SQI_BDCTRL) Based on the mode, the controller has to transmit or receive the data in one or two or 4 lanes Position */
#define SQI_BDCTRL_MODE_Msk                   (_UINT32_(0x3) << SQI_BDCTRL_MODE_Pos)               /* (SQI_BDCTRL) Based on the mode, the controller has to transmit or receive the data in one or two or 4 lanes Mask */
#define SQI_BDCTRL_MODE(value)                (SQI_BDCTRL_MODE_Msk & (_UINT32_(value) << SQI_BDCTRL_MODE_Pos)) /* Assigment of value for MODE in the SQI_BDCTRL register */
#define SQI_BDCTRL_SPI_DEV_SEL2_Pos           _UINT32_(24)                                         /* (SQI_BDCTRL) SPI Device Select bit 2 Position */
#define SQI_BDCTRL_SPI_DEV_SEL2_Msk           (_UINT32_(0x1) << SQI_BDCTRL_SPI_DEV_SEL2_Pos)       /* (SQI_BDCTRL) SPI Device Select bit 2 Mask */
#define SQI_BDCTRL_SPI_DEV_SEL2(value)        (SQI_BDCTRL_SPI_DEV_SEL2_Msk & (_UINT32_(value) << SQI_BDCTRL_SPI_DEV_SEL2_Pos)) /* Assigment of value for SPI_DEV_SEL2 in the SQI_BDCTRL register */
#define SQI_BDCTRL_LSBF_Pos                   _UINT32_(25)                                         /* (SQI_BDCTRL) Data format on SPI Data Lanes Position */
#define SQI_BDCTRL_LSBF_Msk                   (_UINT32_(0x1) << SQI_BDCTRL_LSBF_Pos)               /* (SQI_BDCTRL) Data format on SPI Data Lanes Mask */
#define SQI_BDCTRL_LSBF(value)                (SQI_BDCTRL_LSBF_Msk & (_UINT32_(value) << SQI_BDCTRL_LSBF_Pos)) /* Assigment of value for LSBF in the SQI_BDCTRL register */
#define SQI_BDCTRL_STAT_CHECK_Pos             _UINT32_(27)                                         /* (SQI_BDCTRL) Status Check Position */
#define SQI_BDCTRL_STAT_CHECK_Msk             (_UINT32_(0x1) << SQI_BDCTRL_STAT_CHECK_Pos)         /* (SQI_BDCTRL) Status Check Mask */
#define SQI_BDCTRL_STAT_CHECK(value)          (SQI_BDCTRL_STAT_CHECK_Msk & (_UINT32_(value) << SQI_BDCTRL_STAT_CHECK_Pos)) /* Assigment of value for STAT_CHECK in the SQI_BDCTRL register */
#define SQI_BDCTRL_SPI_DEV_SEL10_Pos          _UINT32_(28)                                         /* (SQI_BDCTRL) SPI Device Select bits 1:0 Position */
#define SQI_BDCTRL_SPI_DEV_SEL10_Msk          (_UINT32_(0x3) << SQI_BDCTRL_SPI_DEV_SEL10_Pos)      /* (SQI_BDCTRL) SPI Device Select bits 1:0 Mask */
#define SQI_BDCTRL_SPI_DEV_SEL10(value)       (SQI_BDCTRL_SPI_DEV_SEL10_Msk & (_UINT32_(value) << SQI_BDCTRL_SPI_DEV_SEL10_Pos)) /* Assigment of value for SPI_DEV_SEL10 in the SQI_BDCTRL register */
#define SQI_BDCTRL_CS_ASSERT_Pos              _UINT32_(30)                                         /* (SQI_BDCTRL) Chip Select Assert/Deassert Position */
#define SQI_BDCTRL_CS_ASSERT_Msk              (_UINT32_(0x1) << SQI_BDCTRL_CS_ASSERT_Pos)          /* (SQI_BDCTRL) Chip Select Assert/Deassert Mask */
#define SQI_BDCTRL_CS_ASSERT(value)           (SQI_BDCTRL_CS_ASSERT_Msk & (_UINT32_(value) << SQI_BDCTRL_CS_ASSERT_Pos)) /* Assigment of value for CS_ASSERT in the SQI_BDCTRL register */
#define SQI_BDCTRL_DESC_EN_Pos                _UINT32_(31)                                         /* (SQI_BDCTRL) Descriptor Enable Position */
#define SQI_BDCTRL_DESC_EN_Msk                (_UINT32_(0x1) << SQI_BDCTRL_DESC_EN_Pos)            /* (SQI_BDCTRL) Descriptor Enable Mask */
#define SQI_BDCTRL_DESC_EN(value)             (SQI_BDCTRL_DESC_EN_Msk & (_UINT32_(value) << SQI_BDCTRL_DESC_EN_Pos)) /* Assigment of value for DESC_EN in the SQI_BDCTRL register */
#define SQI_BDCTRL_Msk                        _UINT32_(0xFBFF01FF)                                 /* (SQI_BDCTRL) Register Mask  */

#define SQI_BDCTRL_SPI_DEV_SEL_Pos            _UINT32_(24)                                         /* (SQI_BDCTRL Position) SPI Device Select bit 2 */
#define SQI_BDCTRL_SPI_DEV_SEL_Msk            (_UINT32_(0x1) << SQI_BDCTRL_SPI_DEV_SEL_Pos)        /* (SQI_BDCTRL Mask) SPI_DEV_SEL */
#define SQI_BDCTRL_SPI_DEV_SEL(value)         (SQI_BDCTRL_SPI_DEV_SEL_Msk & (_UINT32_(value) << SQI_BDCTRL_SPI_DEV_SEL_Pos)) 

/* -------- SQI_BDSTATUS : (SQI Offset: 0x04) (R/W 32) Buffer Descriptor Status Register -------- */
#define SQI_BDSTATUS_Msk                      _UINT32_(0x00000000)                                 /* (SQI_BDSTATUS) Register Mask  */


/* -------- SQI_BDADDR : (SQI Offset: 0x08) (R/W 32) Buffer Descriptor Address Register -------- */
#define SQI_BDADDR_Msk                        _UINT32_(0x00000000)                                 /* (SQI_BDADDR) Register Mask  */


/* -------- SQI_BDNXTPTR : (SQI Offset: 0x0C) (R/W 32) Buffer Descriptor Next Pointer Register -------- */
#define SQI_BDNXTPTR_Msk                      _UINT32_(0x00000000)                                 /* (SQI_BDNXTPTR) Register Mask  */


/* -------- SQI_CTRLA : (SQI Offset: 0x00) (R/W 32) Control A register -------- */
#define SQI_CTRLA_RESETVALUE                  _UINT32_(0x00)                                       /*  (SQI_CTRLA) Control A register  Reset Value */

#define SQI_CTRLA_SWRST_Pos                   _UINT32_(0)                                          /* (SQI_CTRLA) Software Reset Position */
#define SQI_CTRLA_SWRST_Msk                   (_UINT32_(0x1) << SQI_CTRLA_SWRST_Pos)               /* (SQI_CTRLA) Software Reset Mask */
#define SQI_CTRLA_SWRST(value)                (SQI_CTRLA_SWRST_Msk & (_UINT32_(value) << SQI_CTRLA_SWRST_Pos)) /* Assigment of value for SWRST in the SQI_CTRLA register */
#define   SQI_CTRLA_SWRST_LOW_Val             _UINT32_(0x0)                                        /* (SQI_CTRLA) No reset in progress  */
#define   SQI_CTRLA_SWRST_HIGH_Val            _UINT32_(0x1)                                        /* (SQI_CTRLA) Reseting the registers and EIP  */
#define SQI_CTRLA_SWRST_LOW                   (SQI_CTRLA_SWRST_LOW_Val << SQI_CTRLA_SWRST_Pos)     /* (SQI_CTRLA) No reset in progress Position  */
#define SQI_CTRLA_SWRST_HIGH                  (SQI_CTRLA_SWRST_HIGH_Val << SQI_CTRLA_SWRST_Pos)    /* (SQI_CTRLA) Reseting the registers and EIP Position  */
#define SQI_CTRLA_RUNSTDBY_Pos                _UINT32_(6)                                          /* (SQI_CTRLA) Run in Standby Position */
#define SQI_CTRLA_RUNSTDBY_Msk                (_UINT32_(0x1) << SQI_CTRLA_RUNSTDBY_Pos)            /* (SQI_CTRLA) Run in Standby Mask */
#define SQI_CTRLA_RUNSTDBY(value)             (SQI_CTRLA_RUNSTDBY_Msk & (_UINT32_(value) << SQI_CTRLA_RUNSTDBY_Pos)) /* Assigment of value for RUNSTDBY in the SQI_CTRLA register */
#define   SQI_CTRLA_RUNSTDBY_LOW_Val          _UINT32_(0x0)                                        /* (SQI_CTRLA) Module is disabled in Standby Sleep mode  */
#define   SQI_CTRLA_RUNSTDBY_HIGH_Val         _UINT32_(0x1)                                        /* (SQI_CTRLA) Module continues to run in Standby Sleep mode  */
#define SQI_CTRLA_RUNSTDBY_LOW                (SQI_CTRLA_RUNSTDBY_LOW_Val << SQI_CTRLA_RUNSTDBY_Pos) /* (SQI_CTRLA) Module is disabled in Standby Sleep mode Position  */
#define SQI_CTRLA_RUNSTDBY_HIGH               (SQI_CTRLA_RUNSTDBY_HIGH_Val << SQI_CTRLA_RUNSTDBY_Pos) /* (SQI_CTRLA) Module continues to run in Standby Sleep mode Position  */
#define SQI_CTRLA_Msk                         _UINT32_(0x00000041)                                 /* (SQI_CTRLA) Register Mask  */


/* -------- SQI_INTENCLR : (SQI Offset: 0x10) (R/W 32) Interrupt Enable Clear Register -------- */
#define SQI_INTENCLR_RESETVALUE               _UINT32_(0x00)                                       /*  (SQI_INTENCLR) Interrupt Enable Clear Register  Reset Value */

#define SQI_INTENCLR_SQI_Pos                  _UINT32_(0)                                          /* (SQI_INTENCLR) SQI Interrupt Enable Clear Position */
#define SQI_INTENCLR_SQI_Msk                  (_UINT32_(0x1) << SQI_INTENCLR_SQI_Pos)              /* (SQI_INTENCLR) SQI Interrupt Enable Clear Mask */
#define SQI_INTENCLR_SQI(value)               (SQI_INTENCLR_SQI_Msk & (_UINT32_(value) << SQI_INTENCLR_SQI_Pos)) /* Assigment of value for SQI in the SQI_INTENCLR register */
#define   SQI_INTENCLR_SQI_LOW_Val            _UINT32_(0x0)                                        /* (SQI_INTENCLR) Interrupt Enabled  */
#define   SQI_INTENCLR_SQI_HIGH_Val           _UINT32_(0x1)                                        /* (SQI_INTENCLR) Interrupt Disabled  */
#define SQI_INTENCLR_SQI_LOW                  (SQI_INTENCLR_SQI_LOW_Val << SQI_INTENCLR_SQI_Pos)   /* (SQI_INTENCLR) Interrupt Enabled Position  */
#define SQI_INTENCLR_SQI_HIGH                 (SQI_INTENCLR_SQI_HIGH_Val << SQI_INTENCLR_SQI_Pos)  /* (SQI_INTENCLR) Interrupt Disabled Position  */
#define SQI_INTENCLR_Msk                      _UINT32_(0x00000001)                                 /* (SQI_INTENCLR) Register Mask  */


/* -------- SQI_INTENSET : (SQI Offset: 0x14) (R/W 32) Interrupt Enable Set Register -------- */
#define SQI_INTENSET_RESETVALUE               _UINT32_(0x00)                                       /*  (SQI_INTENSET) Interrupt Enable Set Register  Reset Value */

#define SQI_INTENSET_SQI_Pos                  _UINT32_(0)                                          /* (SQI_INTENSET) SQI Interrupt Enable Set Position */
#define SQI_INTENSET_SQI_Msk                  (_UINT32_(0x1) << SQI_INTENSET_SQI_Pos)              /* (SQI_INTENSET) SQI Interrupt Enable Set Mask */
#define SQI_INTENSET_SQI(value)               (SQI_INTENSET_SQI_Msk & (_UINT32_(value) << SQI_INTENSET_SQI_Pos)) /* Assigment of value for SQI in the SQI_INTENSET register */
#define   SQI_INTENSET_SQI_LOW_Val            _UINT32_(0x0)                                        /* (SQI_INTENSET) Interrupt disabled  */
#define   SQI_INTENSET_SQI_HIGH_Val           _UINT32_(0x1)                                        /* (SQI_INTENSET) Interrupt enabled  */
#define SQI_INTENSET_SQI_LOW                  (SQI_INTENSET_SQI_LOW_Val << SQI_INTENSET_SQI_Pos)   /* (SQI_INTENSET) Interrupt disabled Position  */
#define SQI_INTENSET_SQI_HIGH                 (SQI_INTENSET_SQI_HIGH_Val << SQI_INTENSET_SQI_Pos)  /* (SQI_INTENSET) Interrupt enabled Position  */
#define SQI_INTENSET_Msk                      _UINT32_(0x00000001)                                 /* (SQI_INTENSET) Register Mask  */


/* -------- SQI_INTFLAG : (SQI Offset: 0x18) (R/W 32) Interrupt Status and Clear Register -------- */
#define SQI_INTFLAG_RESETVALUE                _UINT32_(0x00)                                       /*  (SQI_INTFLAG) Interrupt Status and Clear Register  Reset Value */

#define SQI_INTFLAG_SQI_Pos                   _UINT32_(0)                                          /* (SQI_INTFLAG) Read value reflects the state of the interrupt flag. Do not use the interrupt flag and associated mask registers if the EIP already provides similar controls for its interrupts. This feature is design for interrupts created in the SIB or EIP which do not have mask or flag bits. Write to 1 to clear the flag. Position */
#define SQI_INTFLAG_SQI_Msk                   (_UINT32_(0x1) << SQI_INTFLAG_SQI_Pos)               /* (SQI_INTFLAG) Read value reflects the state of the interrupt flag. Do not use the interrupt flag and associated mask registers if the EIP already provides similar controls for its interrupts. This feature is design for interrupts created in the SIB or EIP which do not have mask or flag bits. Write to 1 to clear the flag. Mask */
#define SQI_INTFLAG_SQI(value)                (SQI_INTFLAG_SQI_Msk & (_UINT32_(value) << SQI_INTFLAG_SQI_Pos)) /* Assigment of value for SQI in the SQI_INTFLAG register */
#define SQI_INTFLAG_Msk                       _UINT32_(0x00000001)                                 /* (SQI_INTFLAG) Register Mask  */


/* -------- SQI_SYNCBUSY : (SQI Offset: 0x20) ( R/ 32) Syncbusy Register -------- */
#define SQI_SYNCBUSY_RESETVALUE               _UINT32_(0x00)                                       /*  (SQI_SYNCBUSY) Syncbusy Register  Reset Value */

#define SQI_SYNCBUSY_SWRST_Pos                _UINT32_(0)                                          /* (SQI_SYNCBUSY) Software Reset Synchronization Busy Position */
#define SQI_SYNCBUSY_SWRST_Msk                (_UINT32_(0x1) << SQI_SYNCBUSY_SWRST_Pos)            /* (SQI_SYNCBUSY) Software Reset Synchronization Busy Mask */
#define SQI_SYNCBUSY_SWRST(value)             (SQI_SYNCBUSY_SWRST_Msk & (_UINT32_(value) << SQI_SYNCBUSY_SWRST_Pos)) /* Assigment of value for SWRST in the SQI_SYNCBUSY register */
#define   SQI_SYNCBUSY_SWRST_LOW_Val          _UINT32_(0x0)                                        /* (SQI_SYNCBUSY) SWRST synchronization is not busy  */
#define   SQI_SYNCBUSY_SWRST_HIGH_Val         _UINT32_(0x1)                                        /* (SQI_SYNCBUSY) SWRST synchronization is busy  */
#define SQI_SYNCBUSY_SWRST_LOW                (SQI_SYNCBUSY_SWRST_LOW_Val << SQI_SYNCBUSY_SWRST_Pos) /* (SQI_SYNCBUSY) SWRST synchronization is not busy Position  */
#define SQI_SYNCBUSY_SWRST_HIGH               (SQI_SYNCBUSY_SWRST_HIGH_Val << SQI_SYNCBUSY_SWRST_Pos) /* (SQI_SYNCBUSY) SWRST synchronization is busy Position  */
#define SQI_SYNCBUSY_Msk                      _UINT32_(0x00000001)                                 /* (SQI_SYNCBUSY) Register Mask  */


/* -------- SQI_XCON1 : (SQI Offset: 0x100) (R/W 32) SPI XIP Control1 register -------- */
#define SQI_XCON1_RESETVALUE                  _UINT32_(0x202C0C00)                                 /*  (SQI_XCON1) SPI XIP Control1 register  Reset Value */

#define SQI_XCON1_TYPECMD_Pos                 _UINT32_(0)                                          /* (SQI_XCON1) SPI TYPE Command  - Single lane mode, - Dual lane mode, - Quad lane mode, - Reserved for Future use, Based on this field, the boot controller will send the command in 1/2/4 lane. Position */
#define SQI_XCON1_TYPECMD_Msk                 (_UINT32_(0x3) << SQI_XCON1_TYPECMD_Pos)             /* (SQI_XCON1) SPI TYPE Command  - Single lane mode, - Dual lane mode, - Quad lane mode, - Reserved for Future use, Based on this field, the boot controller will send the command in 1/2/4 lane. Mask */
#define SQI_XCON1_TYPECMD(value)              (SQI_XCON1_TYPECMD_Msk & (_UINT32_(value) << SQI_XCON1_TYPECMD_Pos)) /* Assigment of value for TYPECMD in the SQI_XCON1 register */
#define SQI_XCON1_TYPEADDR_Pos                _UINT32_(2)                                          /* (SQI_XCON1) SPI TYPE Address 00 - Single lane mode ,01 - Dual lane mode ,10 - Quad lane mode ,11 - Reserved for Future use  Based on this field, the boot controller will send  the Address in 1/2/4 lane. Position */
#define SQI_XCON1_TYPEADDR_Msk                (_UINT32_(0x3) << SQI_XCON1_TYPEADDR_Pos)            /* (SQI_XCON1) SPI TYPE Address 00 - Single lane mode ,01 - Dual lane mode ,10 - Quad lane mode ,11 - Reserved for Future use  Based on this field, the boot controller will send  the Address in 1/2/4 lane. Mask */
#define SQI_XCON1_TYPEADDR(value)             (SQI_XCON1_TYPEADDR_Msk & (_UINT32_(value) << SQI_XCON1_TYPEADDR_Pos)) /* Assigment of value for TYPEADDR in the SQI_XCON1 register */
#define SQI_XCON1_TYPEMODE_Pos                _UINT32_(4)                                          /* (SQI_XCON1) SPI TYPE Mode: 00 - Single lane mode, 01 - Dual lane mode, 10 - Quad lane mode, 11 - Reserved for Future use. Based on this field, the boot controller will send the Mode in 1/2/4 lane. Position */
#define SQI_XCON1_TYPEMODE_Msk                (_UINT32_(0x3) << SQI_XCON1_TYPEMODE_Pos)            /* (SQI_XCON1) SPI TYPE Mode: 00 - Single lane mode, 01 - Dual lane mode, 10 - Quad lane mode, 11 - Reserved for Future use. Based on this field, the boot controller will send the Mode in 1/2/4 lane. Mask */
#define SQI_XCON1_TYPEMODE(value)             (SQI_XCON1_TYPEMODE_Msk & (_UINT32_(value) << SQI_XCON1_TYPEMODE_Pos)) /* Assigment of value for TYPEMODE in the SQI_XCON1 register */
#define SQI_XCON1_TYPEDUMMY_Pos               _UINT32_(6)                                          /* (SQI_XCON1) SPI TYPE DUMMY: 00 - Single lane mode ,01 - Dual lane mode,10 - Quad lane mode ,11 - Reserved for Future use. Based on this field, the boot controller will send the Dummy in 1/2/4 lane. Position */
#define SQI_XCON1_TYPEDUMMY_Msk               (_UINT32_(0x3) << SQI_XCON1_TYPEDUMMY_Pos)           /* (SQI_XCON1) SPI TYPE DUMMY: 00 - Single lane mode ,01 - Dual lane mode,10 - Quad lane mode ,11 - Reserved for Future use. Based on this field, the boot controller will send the Dummy in 1/2/4 lane. Mask */
#define SQI_XCON1_TYPEDUMMY(value)            (SQI_XCON1_TYPEDUMMY_Msk & (_UINT32_(value) << SQI_XCON1_TYPEDUMMY_Pos)) /* Assigment of value for TYPEDUMMY in the SQI_XCON1 register */
#define SQI_XCON1_TYPEDATA_Pos                _UINT32_(8)                                          /* (SQI_XCON1) SPI TYPE DATA: 00 - Single lane mode  ,01 - Dual lane mode  ,10 - Quad lane mode  ,11 - Reserved for Future use  Based on this field, the boot controller will receive the data in 1/2/4 lane. Position */
#define SQI_XCON1_TYPEDATA_Msk                (_UINT32_(0x3) << SQI_XCON1_TYPEDATA_Pos)            /* (SQI_XCON1) SPI TYPE DATA: 00 - Single lane mode  ,01 - Dual lane mode  ,10 - Quad lane mode  ,11 - Reserved for Future use  Based on this field, the boot controller will receive the data in 1/2/4 lane. Mask */
#define SQI_XCON1_TYPEDATA(value)             (SQI_XCON1_TYPEDATA_Msk & (_UINT32_(value) << SQI_XCON1_TYPEDATA_Pos)) /* Assigment of value for TYPEDATA in the SQI_XCON1 register */
#define SQI_XCON1_READOPCODE_Pos              _UINT32_(10)                                         /* (SQI_XCON1) 8bit opcode value for Read operation Position */
#define SQI_XCON1_READOPCODE_Msk              (_UINT32_(0xFF) << SQI_XCON1_READOPCODE_Pos)         /* (SQI_XCON1) 8bit opcode value for Read operation Mask */
#define SQI_XCON1_READOPCODE(value)           (SQI_XCON1_READOPCODE_Msk & (_UINT32_(value) << SQI_XCON1_READOPCODE_Pos)) /* Assigment of value for READOPCODE in the SQI_XCON1 register */
#define SQI_XCON1_ADDRBYTES_Pos               _UINT32_(18)                                         /* (SQI_XCON1) 000  - Zero Address Bytes ,001  - 1 Address Byte ,010  - 2 Address Bytes ,011  - 3 Address Bytes ,100  - 4 Address Bytes ,101  - 111- Reserved for Future Use Position */
#define SQI_XCON1_ADDRBYTES_Msk               (_UINT32_(0x7) << SQI_XCON1_ADDRBYTES_Pos)           /* (SQI_XCON1) 000  - Zero Address Bytes ,001  - 1 Address Byte ,010  - 2 Address Bytes ,011  - 3 Address Bytes ,100  - 4 Address Bytes ,101  - 111- Reserved for Future Use Mask */
#define SQI_XCON1_ADDRBYTES(value)            (SQI_XCON1_ADDRBYTES_Msk & (_UINT32_(value) << SQI_XCON1_ADDRBYTES_Pos)) /* Assigment of value for ADDRBYTES in the SQI_XCON1 register */
#define SQI_XCON1_DUMMYBYTES_Pos              _UINT32_(21)                                         /* (SQI_XCON1) 000  - Zero Dummy bytes ,001  - Transmit one dummy byte (8?h ff) ,010  - Transmit two dummy bytes (16?h ffff) ,011  - Transmit three dummy bytes (24?h ffffff) ,111  - Transmit Seven dummy bytes Position */
#define SQI_XCON1_DUMMYBYTES_Msk              (_UINT32_(0x7) << SQI_XCON1_DUMMYBYTES_Pos)          /* (SQI_XCON1) 000  - Zero Dummy bytes ,001  - Transmit one dummy byte (8?h ff) ,010  - Transmit two dummy bytes (16?h ffff) ,011  - Transmit three dummy bytes (24?h ffffff) ,111  - Transmit Seven dummy bytes Mask */
#define SQI_XCON1_DUMMYBYTES(value)           (SQI_XCON1_DUMMYBYTES_Msk & (_UINT32_(value) << SQI_XCON1_DUMMYBYTES_Pos)) /* Assigment of value for DUMMYBYTES in the SQI_XCON1 register */
#define SQI_XCON1_DDRCMD_Pos                  _UINT32_(24)                                         /* (SQI_XCON1) XIP SPI TYPE CMD DDR  0 - SDR mode, 1 - DDR mode. Based on this field, the boot controller will send  the command in SDR/DDR mode. Position */
#define SQI_XCON1_DDRCMD_Msk                  (_UINT32_(0x1) << SQI_XCON1_DDRCMD_Pos)              /* (SQI_XCON1) XIP SPI TYPE CMD DDR  0 - SDR mode, 1 - DDR mode. Based on this field, the boot controller will send  the command in SDR/DDR mode. Mask */
#define SQI_XCON1_DDRCMD(value)               (SQI_XCON1_DDRCMD_Msk & (_UINT32_(value) << SQI_XCON1_DDRCMD_Pos)) /* Assigment of value for DDRCMD in the SQI_XCON1 register */
#define SQI_XCON1_DDRADDR_Pos                 _UINT32_(25)                                         /* (SQI_XCON1) XIP SPI TYPE ADDR DDR  0 - SDR mode, 1 - DDR mode. Based on this field, the boot controller will send  the address bytes in SDR/DDR mode. Position */
#define SQI_XCON1_DDRADDR_Msk                 (_UINT32_(0x1) << SQI_XCON1_DDRADDR_Pos)             /* (SQI_XCON1) XIP SPI TYPE ADDR DDR  0 - SDR mode, 1 - DDR mode. Based on this field, the boot controller will send  the address bytes in SDR/DDR mode. Mask */
#define SQI_XCON1_DDRADDR(value)              (SQI_XCON1_DDRADDR_Msk & (_UINT32_(value) << SQI_XCON1_DDRADDR_Pos)) /* Assigment of value for DDRADDR in the SQI_XCON1 register */
#define SQI_XCON1_DDRMODE_Pos                 _UINT32_(26)                                         /* (SQI_XCON1) XIP SPI TYPE MODE DDR  0 - SDR mode, 1 - DDR mode. Based on this field, the boot controller will send the mode bytes in SDR/DDR mode. Position */
#define SQI_XCON1_DDRMODE_Msk                 (_UINT32_(0x1) << SQI_XCON1_DDRMODE_Pos)             /* (SQI_XCON1) XIP SPI TYPE MODE DDR  0 - SDR mode, 1 - DDR mode. Based on this field, the boot controller will send the mode bytes in SDR/DDR mode. Mask */
#define SQI_XCON1_DDRMODE(value)              (SQI_XCON1_DDRMODE_Msk & (_UINT32_(value) << SQI_XCON1_DDRMODE_Pos)) /* Assigment of value for DDRMODE in the SQI_XCON1 register */
#define SQI_XCON1_DDRDUMMY_Pos                _UINT32_(27)                                         /* (SQI_XCON1) XIP SPI TYPE DUMMY DDR. 0 - SDR mode, 1 - DDR mode. Based on this field, the boot controller will send the dummy bytes in SDR/DDR mode. Position */
#define SQI_XCON1_DDRDUMMY_Msk                (_UINT32_(0x1) << SQI_XCON1_DDRDUMMY_Pos)            /* (SQI_XCON1) XIP SPI TYPE DUMMY DDR. 0 - SDR mode, 1 - DDR mode. Based on this field, the boot controller will send the dummy bytes in SDR/DDR mode. Mask */
#define SQI_XCON1_DDRDUMMY(value)             (SQI_XCON1_DDRDUMMY_Msk & (_UINT32_(value) << SQI_XCON1_DDRDUMMY_Pos)) /* Assigment of value for DDRDUMMY in the SQI_XCON1 register */
#define SQI_XCON1_DDRDATA_Pos                 _UINT32_(28)                                         /* (SQI_XCON1) XIP SPI TYPE DATA DDR  0 - SDR mode, 1 - DDR mode. Based on this field, the boot controller will send  the data in SDR/DDR mode. Position */
#define SQI_XCON1_DDRDATA_Msk                 (_UINT32_(0x1) << SQI_XCON1_DDRDATA_Pos)             /* (SQI_XCON1) XIP SPI TYPE DATA DDR  0 - SDR mode, 1 - DDR mode. Based on this field, the boot controller will send  the data in SDR/DDR mode. Mask */
#define SQI_XCON1_DDRDATA(value)              (SQI_XCON1_DDRDATA_Msk & (_UINT32_(value) << SQI_XCON1_DDRDATA_Pos)) /* Assigment of value for DDRDATA in the SQI_XCON1 register */
#define SQI_XCON1_SDRCMD_Pos                  _UINT32_(29)                                         /* (SQI_XCON1) SPI TYPE CMD SDR2DDR: This bit is used by the controller only when  XIP_SPI_TYPE_CMD_DDR is 1?b1 i.e., when command sent in DDR mode. 0 - The command (XIP_SPI_READ_OPCODE) will take 4 clock cycles. Data will go in both the edges. Used when Flash expecting the cmd in ddr mode. Here the command will go as 1byte only. 1- The command (XIP_SPI_READ_OPCODE) will take 8 clock cycles. Data will go in both the edges. Used when Flash expecting the cmd in sdr mode, but user wants to send in ddr mode. Here the command will go as 2bytes. The value (single byte) programmed in XIP_SPI_READ_OPCODE is replicated into 2bytes by the controller and sent on spi bus. Example for CMD SDR2DDR bit 1: Say opcode = 'h ac (1010 1100) Replicated pattern 11 00 11 00 11 11 00 00 ('h ccf0). So 1st 4 clock cycles hcc; next 4 clock cycles hf0 goes on spi bus. Position */
#define SQI_XCON1_SDRCMD_Msk                  (_UINT32_(0x1) << SQI_XCON1_SDRCMD_Pos)              /* (SQI_XCON1) SPI TYPE CMD SDR2DDR: This bit is used by the controller only when  XIP_SPI_TYPE_CMD_DDR is 1?b1 i.e., when command sent in DDR mode. 0 - The command (XIP_SPI_READ_OPCODE) will take 4 clock cycles. Data will go in both the edges. Used when Flash expecting the cmd in ddr mode. Here the command will go as 1byte only. 1- The command (XIP_SPI_READ_OPCODE) will take 8 clock cycles. Data will go in both the edges. Used when Flash expecting the cmd in sdr mode, but user wants to send in ddr mode. Here the command will go as 2bytes. The value (single byte) programmed in XIP_SPI_READ_OPCODE is replicated into 2bytes by the controller and sent on spi bus. Example for CMD SDR2DDR bit 1: Say opcode = 'h ac (1010 1100) Replicated pattern 11 00 11 00 11 11 00 00 ('h ccf0). So 1st 4 clock cycles hcc; next 4 clock cycles hf0 goes on spi bus. Mask */
#define SQI_XCON1_SDRCMD(value)               (SQI_XCON1_SDRCMD_Msk & (_UINT32_(value) << SQI_XCON1_SDRCMD_Pos)) /* Assigment of value for SDRCMD in the SQI_XCON1 register */
#define SQI_XCON1_Msk                         _UINT32_(0x3FFFFFFF)                                 /* (SQI_XCON1) Register Mask  */


/* -------- SQI_XCON2 : (SQI Offset: 0x104) (R/W 32) SPI XIP Control2 register -------- */
#define SQI_XCON2_RESETVALUE                  _UINT32_(0xA0)                                       /*  (SQI_XCON2) SPI XIP Control2 register  Reset Value */

#define SQI_XCON2_MODECODE_Pos                _UINT32_(0)                                          /* (SQI_XCON2) 8bit value for Mode byte Position */
#define SQI_XCON2_MODECODE_Msk                (_UINT32_(0xFF) << SQI_XCON2_MODECODE_Pos)           /* (SQI_XCON2) 8bit value for Mode byte Mask */
#define SQI_XCON2_MODECODE(value)             (SQI_XCON2_MODECODE_Msk & (_UINT32_(value) << SQI_XCON2_MODECODE_Pos)) /* Assigment of value for MODECODE in the SQI_XCON2 register */
#define SQI_XCON2_MODEBYTES_Pos               _UINT32_(8)                                          /* (SQI_XCON2) Mode Bytes 00 - 0 Mode Bytes , 01 - 1 Mode Byte , 10 - 2 Mode Bytes , 11 - 3 Mode Bytes Position */
#define SQI_XCON2_MODEBYTES_Msk               (_UINT32_(0x3) << SQI_XCON2_MODEBYTES_Pos)           /* (SQI_XCON2) Mode Bytes 00 - 0 Mode Bytes , 01 - 1 Mode Byte , 10 - 2 Mode Bytes , 11 - 3 Mode Bytes Mask */
#define SQI_XCON2_MODEBYTES(value)            (SQI_XCON2_MODEBYTES_Msk & (_UINT32_(value) << SQI_XCON2_MODEBYTES_Pos)) /* Assigment of value for MODEBYTES in the SQI_XCON2 register */
#define SQI_XCON2_DEVSEL_Pos                  _UINT32_(10)                                         /* (SQI_XCON2) XIP SPI Device Select: This field is used to select a particular SPI device 000 - Select Device0 , 001 - Select Device1 , 010 - Select Device2 , 011 - Select Device3 , 100 - Select Device4 , 101 - Select Device5 , 110 - Select Device6 , 111 - Select Device7 Position */
#define SQI_XCON2_DEVSEL_Msk                  (_UINT32_(0x7) << SQI_XCON2_DEVSEL_Pos)              /* (SQI_XCON2) XIP SPI Device Select: This field is used to select a particular SPI device 000 - Select Device0 , 001 - Select Device1 , 010 - Select Device2 , 011 - Select Device3 , 100 - Select Device4 , 101 - Select Device5 , 110 - Select Device6 , 111 - Select Device7 Mask */
#define SQI_XCON2_DEVSEL(value)               (SQI_XCON2_DEVSEL_Msk & (_UINT32_(value) << SQI_XCON2_DEVSEL_Pos)) /* Assigment of value for DEVSEL in the SQI_XCON2 register */
#define SQI_XCON2_Msk                         _UINT32_(0x00001FFF)                                 /* (SQI_XCON2) Register Mask  */


/* -------- SQI_CFG : (SQI Offset: 0x108) (R/W 32) SPI Configuration Register -------- */
#define SQI_CFG_RESETVALUE                    _UINT32_(0x1007E01)                                  /*  (SQI_CFG) SPI Configuration Register  Reset Value */

#define SQI_CFG_MODE_Pos                      _UINT32_(0)                                          /* (SQI_CFG) Mode Select The default value of this field is 0. After power on reset, the controller enters boot mode. 000 - Boot mode. The CSR registers are loaded with boot strap values. 001 - PIO mode. The controller is controlled by the CPU in PIO mode. 010 - DMA mode.  011 - XIP mode. When this mode is entered the controller behaves as if executing in Place (XIP) but uses the register data to control timing. 100 - 111 - Reserved Position */
#define SQI_CFG_MODE_Msk                      (_UINT32_(0x7) << SQI_CFG_MODE_Pos)                  /* (SQI_CFG) Mode Select The default value of this field is 0. After power on reset, the controller enters boot mode. 000 - Boot mode. The CSR registers are loaded with boot strap values. 001 - PIO mode. The controller is controlled by the CPU in PIO mode. 010 - DMA mode.  011 - XIP mode. When this mode is entered the controller behaves as if executing in Place (XIP) but uses the register data to control timing. 100 - 111 - Reserved Mask */
#define SQI_CFG_MODE(value)                   (SQI_CFG_MODE_Msk & (_UINT32_(value) << SQI_CFG_MODE_Pos)) /* Assigment of value for MODE in the SQI_CFG register */
#define SQI_CFG_CPHA_Pos                      _UINT32_(3)                                          /* (SQI_CFG) Clock phase (selects the transfer format) 0 = SPICLK starts toggling at the middle of 1st data bit. 1 = SPICLK starts toggling at the start of 1st data bit. Position */
#define SQI_CFG_CPHA_Msk                      (_UINT32_(0x1) << SQI_CFG_CPHA_Pos)                  /* (SQI_CFG) Clock phase (selects the transfer format) 0 = SPICLK starts toggling at the middle of 1st data bit. 1 = SPICLK starts toggling at the start of 1st data bit. Mask */
#define SQI_CFG_CPHA(value)                   (SQI_CFG_CPHA_Msk & (_UINT32_(value) << SQI_CFG_CPHA_Pos)) /* Assigment of value for CPHA in the SQI_CFG register */
#define SQI_CFG_CPOL_Pos                      _UINT32_(4)                                          /* (SQI_CFG) Clock polarity 0 = active-high SPICLK (SPICLK low is the idle state) 1 = active-low SPICLK (SPICLK high is the idle state) Position */
#define SQI_CFG_CPOL_Msk                      (_UINT32_(0x1) << SQI_CFG_CPOL_Pos)                  /* (SQI_CFG) Clock polarity 0 = active-high SPICLK (SPICLK low is the idle state) 1 = active-low SPICLK (SPICLK high is the idle state) Mask */
#define SQI_CFG_CPOL(value)                   (SQI_CFG_CPOL_Msk & (_UINT32_(value) << SQI_CFG_CPOL_Pos)) /* Assigment of value for CPOL in the SQI_CFG register */
#define SQI_CFG_LSBF_Pos                      _UINT32_(5)                                          /* (SQI_CFG) Data format on SPI interface  0 = MSBit sent/received first. 1 = LSBit sent/received first.  This setting is supeceded by LSBF control bit in Buffer Descriptor during DMA operations. Position */
#define SQI_CFG_LSBF_Msk                      (_UINT32_(0x1) << SQI_CFG_LSBF_Pos)                  /* (SQI_CFG) Data format on SPI interface  0 = MSBit sent/received first. 1 = LSBit sent/received first.  This setting is supeceded by LSBF control bit in Buffer Descriptor during DMA operations. Mask */
#define SQI_CFG_LSBF(value)                   (SQI_CFG_LSBF_Msk & (_UINT32_(value) << SQI_CFG_LSBF_Pos)) /* Assigment of value for LSBF in the SQI_CFG register */
#define SQI_CFG_WP_Pos                        _UINT32_(9)                                          /* (SQI_CFG) Write Protect: In single or Dual lane mode, this bit is used to drive the spiout2 signal. Whenever this bit is high, the controller drives 0 on spiout2 line and sets spimoe2 high (active only during transfer). Position */
#define SQI_CFG_WP_Msk                        (_UINT32_(0x1) << SQI_CFG_WP_Pos)                    /* (SQI_CFG) Write Protect: In single or Dual lane mode, this bit is used to drive the spiout2 signal. Whenever this bit is high, the controller drives 0 on spiout2 line and sets spimoe2 high (active only during transfer). Mask */
#define SQI_CFG_WP(value)                     (SQI_CFG_WP_Msk & (_UINT32_(value) << SQI_CFG_WP_Pos)) /* Assigment of value for WP in the SQI_CFG register */
#define SQI_CFG_HOLD_Pos                      _UINT32_(10)                                         /* (SQI_CFG) Hold: In Single or Dual lane mode, this bit is used to drive the spiout3 signal. Whenever this bit is high, the controller drives 0 on spiout3 line and sets spimoe3 high (active only during transfer). Position */
#define SQI_CFG_HOLD_Msk                      (_UINT32_(0x1) << SQI_CFG_HOLD_Pos)                  /* (SQI_CFG) Hold: In Single or Dual lane mode, this bit is used to drive the spiout3 signal. Whenever this bit is high, the controller drives 0 on spiout3 line and sets spimoe3 high (active only during transfer). Mask */
#define SQI_CFG_HOLD(value)                   (SQI_CFG_HOLD_Msk & (_UINT32_(value) << SQI_CFG_HOLD_Pos)) /* Assigment of value for HOLD in the SQI_CFG register */
#define SQI_CFG_BURSTEN_Pos                   _UINT32_(11)                                         /* (SQI_CFG) This field is used to configure the AHB Master Burst capability. 1 - AHB INCR is enabled 0 - AHB INCR is disabled Position */
#define SQI_CFG_BURSTEN_Msk                   (_UINT32_(0x1) << SQI_CFG_BURSTEN_Pos)               /* (SQI_CFG) This field is used to configure the AHB Master Burst capability. 1 - AHB INCR is enabled 0 - AHB INCR is disabled Mask */
#define SQI_CFG_BURSTEN(value)                (SQI_CFG_BURSTEN_Msk & (_UINT32_(value) << SQI_CFG_BURSTEN_Pos)) /* Assigment of value for BURSTEN in the SQI_CFG register */
#define SQI_CFG_AHB_BURST_INCR4_EN_Pos        _UINT32_(12)                                         /* (SQI_CFG) This field is used to configure the AHB Master Burst capability. 1 - AHB INCR4 is enabled. 0 - AHB INCR4 is disabled Position */
#define SQI_CFG_AHB_BURST_INCR4_EN_Msk        (_UINT32_(0x1) << SQI_CFG_AHB_BURST_INCR4_EN_Pos)    /* (SQI_CFG) This field is used to configure the AHB Master Burst capability. 1 - AHB INCR4 is enabled. 0 - AHB INCR4 is disabled Mask */
#define SQI_CFG_AHB_BURST_INCR4_EN(value)     (SQI_CFG_AHB_BURST_INCR4_EN_Msk & (_UINT32_(value) << SQI_CFG_AHB_BURST_INCR4_EN_Pos)) /* Assigment of value for AHB_BURST_INCR4_EN in the SQI_CFG register */
#define SQI_CFG_AHB_BURST_INCR8_EN_Pos        _UINT32_(13)                                         /* (SQI_CFG) This field is used to configure the AHB Master Burst capability. 1 - AHB INCR8 is enabled. 0 - AHB INCR8 is disabled Position */
#define SQI_CFG_AHB_BURST_INCR8_EN_Msk        (_UINT32_(0x1) << SQI_CFG_AHB_BURST_INCR8_EN_Pos)    /* (SQI_CFG) This field is used to configure the AHB Master Burst capability. 1 - AHB INCR8 is enabled. 0 - AHB INCR8 is disabled Mask */
#define SQI_CFG_AHB_BURST_INCR8_EN(value)     (SQI_CFG_AHB_BURST_INCR8_EN_Msk & (_UINT32_(value) << SQI_CFG_AHB_BURST_INCR8_EN_Pos)) /* Assigment of value for AHB_BURST_INCR8_EN in the SQI_CFG register */
#define SQI_CFG_AHB_BURST_INCR16_EN_Pos       _UINT32_(14)                                         /* (SQI_CFG) This field is used to configure the AHB Master Burst capability.  1 - AHB INCR16 is enabled.  0 - AHB INCR16 is disabled Position */
#define SQI_CFG_AHB_BURST_INCR16_EN_Msk       (_UINT32_(0x1) << SQI_CFG_AHB_BURST_INCR16_EN_Pos)   /* (SQI_CFG) This field is used to configure the AHB Master Burst capability.  1 - AHB INCR16 is enabled.  0 - AHB INCR16 is disabled Mask */
#define SQI_CFG_AHB_BURST_INCR16_EN(value)    (SQI_CFG_AHB_BURST_INCR16_EN_Msk & (_UINT32_(value) << SQI_CFG_AHB_BURST_INCR16_EN_Pos)) /* Assigment of value for AHB_BURST_INCR16_EN in the SQI_CFG register */
#define SQI_CFG_TXBUFRST_Pos                  _UINT32_(17)                                         /* (SQI_CFG) Transmit FIFO Reset A reset pulse is generated when writing 1 to this bit. This bit is Auto clear and SPI Controller will clear this bit. Transmit FIFO pointers will get reset by this reset pulse. Note: Transmit FIFO reset can be done only after a transaction is complete on spi bus; however if we want to reset FIFO during  transaction, we need to go for soft reset only.Note: For Michigan Ax versions, treat as Reserved, keep 0. Position */
#define SQI_CFG_TXBUFRST_Msk                  (_UINT32_(0x1) << SQI_CFG_TXBUFRST_Pos)              /* (SQI_CFG) Transmit FIFO Reset A reset pulse is generated when writing 1 to this bit. This bit is Auto clear and SPI Controller will clear this bit. Transmit FIFO pointers will get reset by this reset pulse. Note: Transmit FIFO reset can be done only after a transaction is complete on spi bus; however if we want to reset FIFO during  transaction, we need to go for soft reset only.Note: For Michigan Ax versions, treat as Reserved, keep 0. Mask */
#define SQI_CFG_TXBUFRST(value)               (SQI_CFG_TXBUFRST_Msk & (_UINT32_(value) << SQI_CFG_TXBUFRST_Pos)) /* Assigment of value for TXBUFRST in the SQI_CFG register */
#define SQI_CFG_RXBUFRST_Pos                  _UINT32_(18)                                         /* (SQI_CFG) Receive FIFO Reset A reset pulse is generated when writing 1 to this bit. This bit is Auto clear and SPI Controller will clear this bit. Receive fifo pointers will get reset by this reset pulse. Note: Receive FIFO reset can be done only after a transaction is complete on spi bus; however if we want to reset FIFO during transaction, we need to go for soft reset only. Note: For Michigan Ax versions, treat as Reserved, keep 0. Position */
#define SQI_CFG_RXBUFRST_Msk                  (_UINT32_(0x1) << SQI_CFG_RXBUFRST_Pos)              /* (SQI_CFG) Receive FIFO Reset A reset pulse is generated when writing 1 to this bit. This bit is Auto clear and SPI Controller will clear this bit. Receive fifo pointers will get reset by this reset pulse. Note: Receive FIFO reset can be done only after a transaction is complete on spi bus; however if we want to reset FIFO during transaction, we need to go for soft reset only. Note: For Michigan Ax versions, treat as Reserved, keep 0. Mask */
#define SQI_CFG_RXBUFRST(value)               (SQI_CFG_RXBUFRST_Msk & (_UINT32_(value) << SQI_CFG_RXBUFRST_Pos)) /* Assigment of value for RXBUFRST in the SQI_CFG register */
#define SQI_CFG_CONBUFRST_Pos                 _UINT32_(19)                                         /* (SQI_CFG) Control FIFO Reset A reset pulse is generated when writing 1 to this bit. This bit is Auto clear and SPI Controller will clear this bit. Control fifo pointers will get reset by this reset pulse. Note: Control FIFO reset can be done only after a transaction is complete on spi bus; however if we want to reset FIFO during transaction, we need to go for soft reset only. Note: For Michigan Ax versions, treat as Reserved, keep 0. Position */
#define SQI_CFG_CONBUFRST_Msk                 (_UINT32_(0x1) << SQI_CFG_CONBUFRST_Pos)             /* (SQI_CFG) Control FIFO Reset A reset pulse is generated when writing 1 to this bit. This bit is Auto clear and SPI Controller will clear this bit. Control fifo pointers will get reset by this reset pulse. Note: Control FIFO reset can be done only after a transaction is complete on spi bus; however if we want to reset FIFO during transaction, we need to go for soft reset only. Note: For Michigan Ax versions, treat as Reserved, keep 0. Mask */
#define SQI_CFG_CONBUFRST(value)              (SQI_CFG_CONBUFRST_Msk & (_UINT32_(value) << SQI_CFG_CONBUFRST_Pos)) /* Assigment of value for CONBUFRST in the SQI_CFG register */
#define SQI_CFG_DATAEN_Pos                    _UINT32_(20)                                         /* (SQI_CFG) Max Data Lanes 11 - Reserved, 10 - 4, 01 - 2, 00 - 1 SPI_OUT_PIN_EN[3:0] output pins are controlled by writing to these bits. Position */
#define SQI_CFG_DATAEN_Msk                    (_UINT32_(0x3) << SQI_CFG_DATAEN_Pos)                /* (SQI_CFG) Max Data Lanes 11 - Reserved, 10 - 4, 01 - 2, 00 - 1 SPI_OUT_PIN_EN[3:0] output pins are controlled by writing to these bits. Mask */
#define SQI_CFG_DATAEN(value)                 (SQI_CFG_DATAEN_Msk & (_UINT32_(value) << SQI_CFG_DATAEN_Pos)) /* Assigment of value for DATAEN in the SQI_CFG register */
#define SQI_CFG_SQIEN_Pos                     _UINT32_(23)                                         /* (SQI_CFG) 1 - Enabled, 0 - Disabled SPI_ON output pin is controlled by writing to  this bit. Position */
#define SQI_CFG_SQIEN_Msk                     (_UINT32_(0x1) << SQI_CFG_SQIEN_Pos)                 /* (SQI_CFG) 1 - Enabled, 0 - Disabled SPI_ON output pin is controlled by writing to  this bit. Mask */
#define SQI_CFG_SQIEN(value)                  (SQI_CFG_SQIEN_Msk & (_UINT32_(value) << SQI_CFG_SQIEN_Pos)) /* Assigment of value for SQIEN in the SQI_CFG register */
#define SQI_CFG_CSEN_Pos                      _UINT32_(24)                                         /* (SQI_CFG) 1 - Chip Select is used 0 - Chip Select is not used SPI_CS[7] for  CS7, SPI_CS[6] for  CS6, SPI_CS[5] for  CS5, SPI_CS[4] for  CS4, SPI_CS[3] for  CS3, SPI_CS[2] for  CS2, SPI_CS[1] for  CS1, SPI_CS[0] for  CS0. SPI_CS_PIN_EN[7:0/3:0] output pins are  controlled by writing to these bits. Position */
#define SQI_CFG_CSEN_Msk                      (_UINT32_(0xFF) << SQI_CFG_CSEN_Pos)                 /* (SQI_CFG) 1 - Chip Select is used 0 - Chip Select is not used SPI_CS[7] for  CS7, SPI_CS[6] for  CS6, SPI_CS[5] for  CS5, SPI_CS[4] for  CS4, SPI_CS[3] for  CS3, SPI_CS[2] for  CS2, SPI_CS[1] for  CS1, SPI_CS[0] for  CS0. SPI_CS_PIN_EN[7:0/3:0] output pins are  controlled by writing to these bits. Mask */
#define SQI_CFG_CSEN(value)                   (SQI_CFG_CSEN_Msk & (_UINT32_(value) << SQI_CFG_CSEN_Pos)) /* Assigment of value for CSEN in the SQI_CFG register */
#define SQI_CFG_Msk                           _UINT32_(0xFFBE7E3F)                                 /* (SQI_CFG) Register Mask  */


/* -------- SQI_CON : (SQI Offset: 0x10C) (R/W 32) SPI Control register -------- */
#define SQI_CON_RESETVALUE                    _UINT32_(0x00)                                       /*  (SQI_CON) SPI Control register  Reset Value */

#define SQI_CON_TXRXCOUNT_Pos                 _UINT32_(0)                                          /* (SQI_CON) This bit specifies the total number of bytes to transmit or receive (based on CMD_INIT field). ,16?d 0 - Reserved,16?d 1 - 1byte to transmit/receive ,16?d 2 - 2bytes to transmit/receive NOTE: Count must be programmed to non-zero value prior to initiating transaction Position */
#define SQI_CON_TXRXCOUNT_Msk                 (_UINT32_(0xFFFF) << SQI_CON_TXRXCOUNT_Pos)          /* (SQI_CON) This bit specifies the total number of bytes to transmit or receive (based on CMD_INIT field). ,16?d 0 - Reserved,16?d 1 - 1byte to transmit/receive ,16?d 2 - 2bytes to transmit/receive NOTE: Count must be programmed to non-zero value prior to initiating transaction Mask */
#define SQI_CON_TXRXCOUNT(value)              (SQI_CON_TXRXCOUNT_Msk & (_UINT32_(value) << SQI_CON_TXRXCOUNT_Pos)) /* Assigment of value for TXRXCOUNT in the SQI_CON register */
#define SQI_CON_CMDINIT_Pos                   _UINT32_(16)                                         /* (SQI_CON) This signal indicates the command initiation mode. If it is Transmit, Commands are initiated based on writes to transmit register or the contents of TX FIFO. If the CMD_INIT is Receive, commands are initiated based on reads to Read register or RX FIFO availability. 00 = Reserved.  01 = Initiate Transmit.  10 = Initiate Receive. 11 = Reserved.  Note: If Boot mode is enabled, the default value  is 2?b10  This is NOT active status field, see SPI Status2 Reg (0x30) Position */
#define SQI_CON_CMDINIT_Msk                   (_UINT32_(0x3) << SQI_CON_CMDINIT_Pos)               /* (SQI_CON) This signal indicates the command initiation mode. If it is Transmit, Commands are initiated based on writes to transmit register or the contents of TX FIFO. If the CMD_INIT is Receive, commands are initiated based on reads to Read register or RX FIFO availability. 00 = Reserved.  01 = Initiate Transmit.  10 = Initiate Receive. 11 = Reserved.  Note: If Boot mode is enabled, the default value  is 2?b10  This is NOT active status field, see SPI Status2 Reg (0x30) Mask */
#define SQI_CON_CMDINIT(value)                (SQI_CON_CMDINIT_Msk & (_UINT32_(value) << SQI_CON_CMDINIT_Pos)) /* Assigment of value for CMDINIT in the SQI_CON register */
#define SQI_CON_LANEMODE_Pos                  _UINT32_(18)                                         /* (SQI_CON) SPI Lane mode 00 - Single lane mode ,01 - Dual lane mode ,10 - Quad lane mode ,11 - Reserved for Future use Position */
#define SQI_CON_LANEMODE_Msk                  (_UINT32_(0x3) << SQI_CON_LANEMODE_Pos)              /* (SQI_CON) SPI Lane mode 00 - Single lane mode ,01 - Dual lane mode ,10 - Quad lane mode ,11 - Reserved for Future use Mask */
#define SQI_CON_LANEMODE(value)               (SQI_CON_LANEMODE_Msk & (_UINT32_(value) << SQI_CON_LANEMODE_Pos)) /* Assigment of value for LANEMODE in the SQI_CON register */
#define SQI_CON_DEVSEL_Pos                    _UINT32_(20)                                         /* (SQI_CON) SPI Device Select: This field along with bit25 is used to select a particular SPI device. Note: For Michigan Ax versions, extension by bit25 is NOT used (only 4 devices are selectable, by bits 21:20 here). Position */
#define SQI_CON_DEVSEL_Msk                    (_UINT32_(0x3) << SQI_CON_DEVSEL_Pos)                /* (SQI_CON) SPI Device Select: This field along with bit25 is used to select a particular SPI device. Note: For Michigan Ax versions, extension by bit25 is NOT used (only 4 devices are selectable, by bits 21:20 here). Mask */
#define SQI_CON_DEVSEL(value)                 (SQI_CON_DEVSEL_Msk & (_UINT32_(value) << SQI_CON_DEVSEL_Pos)) /* Assigment of value for DEVSEL in the SQI_CON register */
#define SQI_CON_DASSERT_Pos                   _UINT32_(22)                                         /* (SQI_CON) Chip Select Assert 0 - CS is not de-asserted after transmission/reception of specified number of bytes in the control register 1 - CS is de-asserted after transmission/reception of specified number of bytes in the control register Position */
#define SQI_CON_DASSERT_Msk                   (_UINT32_(0x1) << SQI_CON_DASSERT_Pos)               /* (SQI_CON) Chip Select Assert 0 - CS is not de-asserted after transmission/reception of specified number of bytes in the control register 1 - CS is de-asserted after transmission/reception of specified number of bytes in the control register Mask */
#define SQI_CON_DASSERT(value)                (SQI_CON_DASSERT_Msk & (_UINT32_(value) << SQI_CON_DASSERT_Pos)) /* Assigment of value for DASSERT in the SQI_CON register */
#define SQI_CON_DDRMODE_Pos                   _UINT32_(23)                                         /* (SQI_CON) SDR_DDR: 0 - SDR mode, 1 - DDR mode. Note: For Michigan Ax versions this bit is Reserved and should be kept 0. Position */
#define SQI_CON_DDRMODE_Msk                   (_UINT32_(0x1) << SQI_CON_DDRMODE_Pos)               /* (SQI_CON) SDR_DDR: 0 - SDR mode, 1 - DDR mode. Note: For Michigan Ax versions this bit is Reserved and should be kept 0. Mask */
#define SQI_CON_DDRMODE(value)                (SQI_CON_DDRMODE_Msk & (_UINT32_(value) << SQI_CON_DDRMODE_Pos)) /* Assigment of value for DDRMODE in the SQI_CON register */
#define SQI_CON_SCHECK_Pos                    _UINT32_(24)                                         /* (SQI_CON) Status Check This bit is mainly used for Programming or Erase operations. 0 - do not check status, 1 - check status. If this bit is set to 1, the hardware will issue the status command automatically after the current operation and wait for busy bit to clear. The hardware will issue the next command only after this Status check phase. Note: For Michigan Ax versions, this bit is Reserved and should be kept 0. Position */
#define SQI_CON_SCHECK_Msk                    (_UINT32_(0x1) << SQI_CON_SCHECK_Pos)                /* (SQI_CON) Status Check This bit is mainly used for Programming or Erase operations. 0 - do not check status, 1 - check status. If this bit is set to 1, the hardware will issue the status command automatically after the current operation and wait for busy bit to clear. The hardware will issue the next command only after this Status check phase. Note: For Michigan Ax versions, this bit is Reserved and should be kept 0. Mask */
#define SQI_CON_SCHECK(value)                 (SQI_CON_SCHECK_Msk & (_UINT32_(value) << SQI_CON_SCHECK_Pos)) /* Assigment of value for SCHECK in the SQI_CON register */
#define SQI_CON_DEV_SEL_2_Pos                 _UINT32_(25)                                         /* (SQI_CON) SPI Device Select[2]: This field along with SPI DEVICE SELECT [1:0] (bits 21:20) together is used to select a particular SPI device. Bit25 Bit21 Bit20  0 0 0 - SPI Device 0 ,0 0 1 - SPI Device 1 ,0 1 0 - SPI Device 2  ,0 1 1 - SPI Device 3, 1 0 0 - SPI Device 4 ,1 0 1 - SPI Device 5 ,1 1 0 - SPI Device 6 ,1 1 1 - SPI Device 7 Note: For Michigan Ax versions, this bit is Reserved and should be kept 0. Position */
#define SQI_CON_DEV_SEL_2_Msk                 (_UINT32_(0x1) << SQI_CON_DEV_SEL_2_Pos)             /* (SQI_CON) SPI Device Select[2]: This field along with SPI DEVICE SELECT [1:0] (bits 21:20) together is used to select a particular SPI device. Bit25 Bit21 Bit20  0 0 0 - SPI Device 0 ,0 0 1 - SPI Device 1 ,0 1 0 - SPI Device 2  ,0 1 1 - SPI Device 3, 1 0 0 - SPI Device 4 ,1 0 1 - SPI Device 5 ,1 1 0 - SPI Device 6 ,1 1 1 - SPI Device 7 Note: For Michigan Ax versions, this bit is Reserved and should be kept 0. Mask */
#define SQI_CON_DEV_SEL_2(value)              (SQI_CON_DEV_SEL_2_Msk & (_UINT32_(value) << SQI_CON_DEV_SEL_2_Pos)) /* Assigment of value for DEV_SEL_2 in the SQI_CON register */
#define SQI_CON_Msk                           _UINT32_(0x03FFFFFF)                                 /* (SQI_CON) Register Mask  */

#define SQI_CON_DEV_SEL__Pos                  _UINT32_(25)                                         /* (SQI_CON Position) SPI Device Select[2]: This field along with SPI DEVICE SELECT [x:x] (bits 2x:2x) together is used to select a particular SPI device. Bit25 Bit2x Bit2x  x x x - SPI Device x ,x x x - SPI Device x ,x x x - SPI Device 2  ,x x x - SPI Device 3, x x x - SPI Device 4 ,x x x - SPI Device 5 ,x x x - SPI Device 6 ,x x x - SPI Device 7 Note: For Michigan Ax versions, this bit is Reserved and should be kept x. */
#define SQI_CON_DEV_SEL__Msk                  (_UINT32_(0x1) << SQI_CON_DEV_SEL__Pos)              /* (SQI_CON Mask) DEV_SEL_ */
#define SQI_CON_DEV_SEL_(value)               (SQI_CON_DEV_SEL__Msk & (_UINT32_(value) << SQI_CON_DEV_SEL__Pos)) 

/* -------- SQI_CLKCON : (SQI Offset: 0x110) (R/W 32) SPI Clock Control register -------- */
#define SQI_CLKCON_RESETVALUE                 _UINT32_(0x01)                                       /*  (SQI_CLKCON) SPI Clock Control register  Reset Value */

#define SQI_CLKCON_EN_Pos                     _UINT32_(0)                                          /* (SQI_CLKCON) This bit is set to 0 when the SPI Driver is not using the SPI Controller. The SPI  Controller should stop its internal clock to go very low power state. Still, registers  will be able to be read and written. Clock starts to oscillate when this bit is set to 1. When clock oscillation is stable, the SPI Controller will set Internal Clock Stable in this register to 1. 1 - Enable 0 - Disable Position */
#define SQI_CLKCON_EN_Msk                     (_UINT32_(0x1) << SQI_CLKCON_EN_Pos)                 /* (SQI_CLKCON) This bit is set to 0 when the SPI Driver is not using the SPI Controller. The SPI  Controller should stop its internal clock to go very low power state. Still, registers  will be able to be read and written. Clock starts to oscillate when this bit is set to 1. When clock oscillation is stable, the SPI Controller will set Internal Clock Stable in this register to 1. 1 - Enable 0 - Disable Mask */
#define SQI_CLKCON_EN(value)                  (SQI_CLKCON_EN_Msk & (_UINT32_(value) << SQI_CLKCON_EN_Pos)) /* Assigment of value for EN in the SQI_CLKCON register */
#define SQI_CLKCON_STABLE_Pos                 _UINT32_(1)                                          /* (SQI_CLKCON) After Reset, this bit is set to 1 when SPI Clock  is  stable  after  writing  Internal Clock  Enable  in  this  register  to  1. The Clock  Stable  indication  will  continue unless   the   Clock   Divisor   Value   is changed, in which case it will wait until Clock is stable again. Stability is reached when the Clock Divisor period has been reached. The SPI Host Driver should wait until this bit is set to 1 (and the Enable is 1) before programming the SPI Control register. 1 - Stable 0 - Not stable Position */
#define SQI_CLKCON_STABLE_Msk                 (_UINT32_(0x1) << SQI_CLKCON_STABLE_Pos)             /* (SQI_CLKCON) After Reset, this bit is set to 1 when SPI Clock  is  stable  after  writing  Internal Clock  Enable  in  this  register  to  1. The Clock  Stable  indication  will  continue unless   the   Clock   Divisor   Value   is changed, in which case it will wait until Clock is stable again. Stability is reached when the Clock Divisor period has been reached. The SPI Host Driver should wait until this bit is set to 1 (and the Enable is 1) before programming the SPI Control register. 1 - Stable 0 - Not stable Mask */
#define SQI_CLKCON_STABLE(value)              (SQI_CLKCON_STABLE_Msk & (_UINT32_(value) << SQI_CLKCON_STABLE_Pos)) /* Assigment of value for STABLE in the SQI_CLKCON register */
#define SQI_CLKCON_CLKDIV_Pos                 _UINT32_(8)                                          /* (SQI_CLKCON) SPI Clock Frequency Select 400h - base clock divided by 2048 ,200h - base clock divided by 1024  ,100h - base clock divided by 512 ,080h - base clock divided by 256 ,040h - base clock divided by 128 ,020h - base clock divided by 64 ,010h - base clock divided by 32 ,008h - base clock divided by 16 ,004h - base clock divided by 8 ,002h - base clock divided by 4 ,001h - base clock divided by 2 ,000h - base clock Setting 000h specifies the highest frequency of the SPI Clock. NOTE:  When  DDR  mode  is  active,  the output SPI_CLK is further divided by two (so that internal clocking remains rise edge active internally)  Max output SPI_CLK for DDR is 66Mhz. Position */
#define SQI_CLKCON_CLKDIV_Msk                 (_UINT32_(0x7FF) << SQI_CLKCON_CLKDIV_Pos)           /* (SQI_CLKCON) SPI Clock Frequency Select 400h - base clock divided by 2048 ,200h - base clock divided by 1024  ,100h - base clock divided by 512 ,080h - base clock divided by 256 ,040h - base clock divided by 128 ,020h - base clock divided by 64 ,010h - base clock divided by 32 ,008h - base clock divided by 16 ,004h - base clock divided by 8 ,002h - base clock divided by 4 ,001h - base clock divided by 2 ,000h - base clock Setting 000h specifies the highest frequency of the SPI Clock. NOTE:  When  DDR  mode  is  active,  the output SPI_CLK is further divided by two (so that internal clocking remains rise edge active internally)  Max output SPI_CLK for DDR is 66Mhz. Mask */
#define SQI_CLKCON_CLKDIV(value)              (SQI_CLKCON_CLKDIV_Msk & (_UINT32_(value) << SQI_CLKCON_CLKDIV_Pos)) /* Assigment of value for CLKDIV in the SQI_CLKCON register */
#define SQI_CLKCON_Msk                        _UINT32_(0x0007FF03)                                 /* (SQI_CLKCON) Register Mask  */


/* -------- SQI_CMDTHR : (SQI Offset: 0x114) (R/W 32) SPI command threshold register -------- */
#define SQI_CMDTHR_RESETVALUE                 _UINT32_(0x101)                                      /*  (SQI_CMDTHR) SPI command threshold register  Reset Value */

#define SQI_CMDTHR_RXCMDTHR_Pos               _UINT32_(0)                                          /* (SQI_CMDTHR) In RX initiation mode, SPI attempts to perform receive fetch operations until RX_CMD_THRES bytes of space remain in the receive buffer. If space for RX_CMD_THRES bytes is not present in the FIFO, then SPI would not initiate any transfer. RX_CMD_THRES should only be programmed when RX is not active, during IDLE or TX. Please note that if S/W performs any reads, thereby reducing the FIFO count, then HW would initiate RX transfer to get back FIFO count equal to RX_CMD_THRES. If S/W would not like any more words latched into FIFO, then command initiation mode needs to be changed to IDLE before any FIFO reads by S/W. In case of Boot/XIP mode, the SPI Controller uses the AHB Burst size, instead of RX CMD Threshold value. Position */
#define SQI_CMDTHR_RXCMDTHR_Msk               (_UINT32_(0xFF) << SQI_CMDTHR_RXCMDTHR_Pos)          /* (SQI_CMDTHR) In RX initiation mode, SPI attempts to perform receive fetch operations until RX_CMD_THRES bytes of space remain in the receive buffer. If space for RX_CMD_THRES bytes is not present in the FIFO, then SPI would not initiate any transfer. RX_CMD_THRES should only be programmed when RX is not active, during IDLE or TX. Please note that if S/W performs any reads, thereby reducing the FIFO count, then HW would initiate RX transfer to get back FIFO count equal to RX_CMD_THRES. If S/W would not like any more words latched into FIFO, then command initiation mode needs to be changed to IDLE before any FIFO reads by S/W. In case of Boot/XIP mode, the SPI Controller uses the AHB Burst size, instead of RX CMD Threshold value. Mask */
#define SQI_CMDTHR_RXCMDTHR(value)            (SQI_CMDTHR_RXCMDTHR_Msk & (_UINT32_(value) << SQI_CMDTHR_RXCMDTHR_Pos)) /* Assigment of value for RXCMDTHR in the SQI_CMDTHR register */
#define SQI_CMDTHR_TXCMDTHR_Pos               _UINT32_(8)                                          /* (SQI_CMDTHR) In TX Initiation Mode, SPI Performs a transmit Operation when TX_CMD_THRES bytes are present in the TX FIFO. This should usually be set to 1 for normal flash commands, and is desired to be set to a higher value for page programming. NOTE: Value of 8?d0 should be treated as Reserved (illegal) for this field. May produce unexpected activity on SPI bus. Furthermore, values should generally be limited to EVEN values (excepting a value  of 1), and MUST be so limited in DMA mode. Position */
#define SQI_CMDTHR_TXCMDTHR_Msk               (_UINT32_(0xFF) << SQI_CMDTHR_TXCMDTHR_Pos)          /* (SQI_CMDTHR) In TX Initiation Mode, SPI Performs a transmit Operation when TX_CMD_THRES bytes are present in the TX FIFO. This should usually be set to 1 for normal flash commands, and is desired to be set to a higher value for page programming. NOTE: Value of 8?d0 should be treated as Reserved (illegal) for this field. May produce unexpected activity on SPI bus. Furthermore, values should generally be limited to EVEN values (excepting a value  of 1), and MUST be so limited in DMA mode. Mask */
#define SQI_CMDTHR_TXCMDTHR(value)            (SQI_CMDTHR_TXCMDTHR_Msk & (_UINT32_(value) << SQI_CMDTHR_TXCMDTHR_Pos)) /* Assigment of value for TXCMDTHR in the SQI_CMDTHR register */
#define SQI_CMDTHR_Msk                        _UINT32_(0x0000FFFF)                                 /* (SQI_CMDTHR) Register Mask  */


/* -------- SQI_INTTHR : (SQI Offset: 0x118) (R/W 32) SPI Interrupt Threshold register -------- */
#define SQI_INTTHR_RESETVALUE                 _UINT32_(0x00)                                       /*  (SQI_INTTHR) SPI Interrupt Threshold register  Reset Value */

#define SQI_INTTHR_RXINTTHR_Pos               _UINT32_(0)                                          /* (SQI_INTTHR) Receive Interrupt is set when Receive FIFO CNT is larger than or equal to RX_INT_THRES Value. Position */
#define SQI_INTTHR_RXINTTHR_Msk               (_UINT32_(0xFF) << SQI_INTTHR_RXINTTHR_Pos)          /* (SQI_INTTHR) Receive Interrupt is set when Receive FIFO CNT is larger than or equal to RX_INT_THRES Value. Mask */
#define SQI_INTTHR_RXINTTHR(value)            (SQI_INTTHR_RXINTTHR_Msk & (_UINT32_(value) << SQI_INTTHR_RXINTTHR_Pos)) /* Assigment of value for RXINTTHR in the SQI_INTTHR register */
#define SQI_INTTHR_TXINTTHR_Pos               _UINT32_(8)                                          /* (SQI_INTTHR) Transmit Interrupt is set when Transmit FIFO has equal or more space than TX_INT_THRES bytes. Position */
#define SQI_INTTHR_TXINTTHR_Msk               (_UINT32_(0xFF) << SQI_INTTHR_TXINTTHR_Pos)          /* (SQI_INTTHR) Transmit Interrupt is set when Transmit FIFO has equal or more space than TX_INT_THRES bytes. Mask */
#define SQI_INTTHR_TXINTTHR(value)            (SQI_INTTHR_TXINTTHR_Msk & (_UINT32_(value) << SQI_INTTHR_TXINTTHR_Pos)) /* Assigment of value for TXINTTHR in the SQI_INTTHR register */
#define SQI_INTTHR_Msk                        _UINT32_(0x0000FFFF)                                 /* (SQI_INTTHR) Register Mask  */


/* -------- SQI_INTEN : (SQI Offset: 0x11C) (R/W 32) SPI Interrupt Enable Register -------- */
#define SQI_INTEN_RESETVALUE                  _UINT32_(0xAD)                                       /*  (SQI_INTEN) SPI Interrupt Enable Register  Reset Value */

#define SQI_INTEN_TXEMPTYIE_Pos               _UINT32_(0)                                          /* (SQI_INTEN) TX FIFO Empty Interrupt Enable. Position */
#define SQI_INTEN_TXEMPTYIE_Msk               (_UINT32_(0x1) << SQI_INTEN_TXEMPTYIE_Pos)           /* (SQI_INTEN) TX FIFO Empty Interrupt Enable. Mask */
#define SQI_INTEN_TXEMPTYIE(value)            (SQI_INTEN_TXEMPTYIE_Msk & (_UINT32_(value) << SQI_INTEN_TXEMPTYIE_Pos)) /* Assigment of value for TXEMPTYIE in the SQI_INTEN register */
#define SQI_INTEN_TXFULLIE_Pos                _UINT32_(1)                                          /* (SQI_INTEN) TX FIFO Full Interrupt Enable. Position */
#define SQI_INTEN_TXFULLIE_Msk                (_UINT32_(0x1) << SQI_INTEN_TXFULLIE_Pos)            /* (SQI_INTEN) TX FIFO Full Interrupt Enable. Mask */
#define SQI_INTEN_TXFULLIE(value)             (SQI_INTEN_TXFULLIE_Msk & (_UINT32_(value) << SQI_INTEN_TXFULLIE_Pos)) /* Assigment of value for TXFULLIE in the SQI_INTEN register */
#define SQI_INTEN_TXTHRIE_Pos                 _UINT32_(2)                                          /* (SQI_INTEN) Enable Interrupt to be generated when the TX FIFO has space equal to or more than TX_INT_THRES words. Position */
#define SQI_INTEN_TXTHRIE_Msk                 (_UINT32_(0x1) << SQI_INTEN_TXTHRIE_Pos)             /* (SQI_INTEN) Enable Interrupt to be generated when the TX FIFO has space equal to or more than TX_INT_THRES words. Mask */
#define SQI_INTEN_TXTHRIE(value)              (SQI_INTEN_TXTHRIE_Msk & (_UINT32_(value) << SQI_INTEN_TXTHRIE_Pos)) /* Assigment of value for TXTHRIE in the SQI_INTEN register */
#define SQI_INTEN_RXEMPTYIE_Pos               _UINT32_(3)                                          /* (SQI_INTEN) RX FIFO Empty Interrupt Enable. Position */
#define SQI_INTEN_RXEMPTYIE_Msk               (_UINT32_(0x1) << SQI_INTEN_RXEMPTYIE_Pos)           /* (SQI_INTEN) RX FIFO Empty Interrupt Enable. Mask */
#define SQI_INTEN_RXEMPTYIE(value)            (SQI_INTEN_RXEMPTYIE_Msk & (_UINT32_(value) << SQI_INTEN_RXEMPTYIE_Pos)) /* Assigment of value for RXEMPTYIE in the SQI_INTEN register */
#define SQI_INTEN_RXFULLIE_Pos                _UINT32_(4)                                          /* (SQI_INTEN) RX FIFO Full Interrupt Enable. Position */
#define SQI_INTEN_RXFULLIE_Msk                (_UINT32_(0x1) << SQI_INTEN_RXFULLIE_Pos)            /* (SQI_INTEN) RX FIFO Full Interrupt Enable. Mask */
#define SQI_INTEN_RXFULLIE(value)             (SQI_INTEN_RXFULLIE_Msk & (_UINT32_(value) << SQI_INTEN_RXFULLIE_Pos)) /* Assigment of value for RXFULLIE in the SQI_INTEN register */
#define SQI_INTEN_RXTHRIE_Pos                 _UINT32_(5)                                          /* (SQI_INTEN) Enable Interrupt to be generated when the RX FIFO has data more than or equal to RX_INT_THRES words. In case of Boot/XIP mode, the power on reset value of RX buffer threshold is zero. So this bit will be set to 1, immediately after power  on reset, till a read request on the AHB Bus. Position */
#define SQI_INTEN_RXTHRIE_Msk                 (_UINT32_(0x1) << SQI_INTEN_RXTHRIE_Pos)             /* (SQI_INTEN) Enable Interrupt to be generated when the RX FIFO has data more than or equal to RX_INT_THRES words. In case of Boot/XIP mode, the power on reset value of RX buffer threshold is zero. So this bit will be set to 1, immediately after power  on reset, till a read request on the AHB Bus. Mask */
#define SQI_INTEN_RXTHRIE(value)              (SQI_INTEN_RXTHRIE_Msk & (_UINT32_(value) << SQI_INTEN_RXTHRIE_Pos)) /* Assigment of value for RXTHRIE in the SQI_INTEN register */
#define SQI_INTEN_CONFULLIE_Pos               _UINT32_(6)                                          /* (SQI_INTEN) Control Buffer Full Interrupt Enable Position */
#define SQI_INTEN_CONFULLIE_Msk               (_UINT32_(0x1) << SQI_INTEN_CONFULLIE_Pos)           /* (SQI_INTEN) Control Buffer Full Interrupt Enable Mask */
#define SQI_INTEN_CONFULLIE(value)            (SQI_INTEN_CONFULLIE_Msk & (_UINT32_(value) << SQI_INTEN_CONFULLIE_Pos)) /* Assigment of value for CONFULLIE in the SQI_INTEN register */
#define SQI_INTEN_CONEMPTYIE_Pos              _UINT32_(7)                                          /* (SQI_INTEN) Control Buffer Empty Interrupt Enable Position */
#define SQI_INTEN_CONEMPTYIE_Msk              (_UINT32_(0x1) << SQI_INTEN_CONEMPTYIE_Pos)          /* (SQI_INTEN) Control Buffer Empty Interrupt Enable Mask */
#define SQI_INTEN_CONEMPTYIE(value)           (SQI_INTEN_CONEMPTYIE_Msk & (_UINT32_(value) << SQI_INTEN_CONEMPTYIE_Pos)) /* Assigment of value for CONEMPTYIE in the SQI_INTEN register */
#define SQI_INTEN_CONTHRIE_Pos                _UINT32_(8)                                          /* (SQI_INTEN) Control Buffer Threshold Interrupt Enable Position */
#define SQI_INTEN_CONTHRIE_Msk                (_UINT32_(0x1) << SQI_INTEN_CONTHRIE_Pos)            /* (SQI_INTEN) Control Buffer Threshold Interrupt Enable Mask */
#define SQI_INTEN_CONTHRIE(value)             (SQI_INTEN_CONTHRIE_Msk & (_UINT32_(value) << SQI_INTEN_CONTHRIE_Pos)) /* Assigment of value for CONTHRIE in the SQI_INTEN register */
#define SQI_INTEN_BDDONEIE_Pos                _UINT32_(9)                                          /* (SQI_INTEN) Current Buffer Descriptor Interrupt Enable Position */
#define SQI_INTEN_BDDONEIE_Msk                (_UINT32_(0x1) << SQI_INTEN_BDDONEIE_Pos)            /* (SQI_INTEN) Current Buffer Descriptor Interrupt Enable Mask */
#define SQI_INTEN_BDDONEIE(value)             (SQI_INTEN_BDDONEIE_Msk & (_UINT32_(value) << SQI_INTEN_BDDONEIE_Pos)) /* Assigment of value for BDDONEIE in the SQI_INTEN register */
#define SQI_INTEN_PKTCOMPIE_Pos               _UINT32_(10)                                         /* (SQI_INTEN) Packet completion Interrupt Position */
#define SQI_INTEN_PKTCOMPIE_Msk               (_UINT32_(0x1) << SQI_INTEN_PKTCOMPIE_Pos)           /* (SQI_INTEN) Packet completion Interrupt Mask */
#define SQI_INTEN_PKTCOMPIE(value)            (SQI_INTEN_PKTCOMPIE_Msk & (_UINT32_(value) << SQI_INTEN_PKTCOMPIE_Pos)) /* Assigment of value for PKTCOMPIE in the SQI_INTEN register */
#define SQI_INTEN_DMAEIE_Pos                  _UINT32_(11)                                         /* (SQI_INTEN) Master Error Interrupt Enable Position */
#define SQI_INTEN_DMAEIE_Msk                  (_UINT32_(0x1) << SQI_INTEN_DMAEIE_Pos)              /* (SQI_INTEN) Master Error Interrupt Enable Mask */
#define SQI_INTEN_DMAEIE(value)               (SQI_INTEN_DMAEIE_Msk & (_UINT32_(value) << SQI_INTEN_DMAEIE_Pos)) /* Assigment of value for DMAEIE in the SQI_INTEN register */
#define SQI_INTEN_Msk                         _UINT32_(0x00000FFF)                                 /* (SQI_INTEN) Register Mask  */


/* -------- SQI_INTSTAT : (SQI Offset: 0x120) (R/W 32) SPI Interrupt Status Register -------- */
#define SQI_INTSTAT_RESETVALUE                _UINT32_(0xAD)                                       /*  (SQI_INTSTAT) SPI Interrupt Status Register  Reset Value */

#define SQI_INTSTAT_TXEMPTYIF_Pos             _UINT32_(0)                                          /* (SQI_INTSTAT) TX FIFO Empty Interrupt. Position */
#define SQI_INTSTAT_TXEMPTYIF_Msk             (_UINT32_(0x1) << SQI_INTSTAT_TXEMPTYIF_Pos)         /* (SQI_INTSTAT) TX FIFO Empty Interrupt. Mask */
#define SQI_INTSTAT_TXEMPTYIF(value)          (SQI_INTSTAT_TXEMPTYIF_Msk & (_UINT32_(value) << SQI_INTSTAT_TXEMPTYIF_Pos)) /* Assigment of value for TXEMPTYIF in the SQI_INTSTAT register */
#define SQI_INTSTAT_TXFULLIF_Pos              _UINT32_(1)                                          /* (SQI_INTSTAT) TX FIFO Full Interrupt. Position */
#define SQI_INTSTAT_TXFULLIF_Msk              (_UINT32_(0x1) << SQI_INTSTAT_TXFULLIF_Pos)          /* (SQI_INTSTAT) TX FIFO Full Interrupt. Mask */
#define SQI_INTSTAT_TXFULLIF(value)           (SQI_INTSTAT_TXFULLIF_Msk & (_UINT32_(value) << SQI_INTSTAT_TXFULLIF_Pos)) /* Assigment of value for TXFULLIF in the SQI_INTSTAT register */
#define SQI_INTSTAT_TXTHRIF_Pos               _UINT32_(2)                                          /* (SQI_INTSTAT) Interrupt to be generated when the TX FIFO has space equal to or more than  TX_INT_THRES words. Position */
#define SQI_INTSTAT_TXTHRIF_Msk               (_UINT32_(0x1) << SQI_INTSTAT_TXTHRIF_Pos)           /* (SQI_INTSTAT) Interrupt to be generated when the TX FIFO has space equal to or more than  TX_INT_THRES words. Mask */
#define SQI_INTSTAT_TXTHRIF(value)            (SQI_INTSTAT_TXTHRIF_Msk & (_UINT32_(value) << SQI_INTSTAT_TXTHRIF_Pos)) /* Assigment of value for TXTHRIF in the SQI_INTSTAT register */
#define SQI_INTSTAT_RXEMPTYIF_Pos             _UINT32_(3)                                          /* (SQI_INTSTAT) RX FIFO Empty Interrupt. Position */
#define SQI_INTSTAT_RXEMPTYIF_Msk             (_UINT32_(0x1) << SQI_INTSTAT_RXEMPTYIF_Pos)         /* (SQI_INTSTAT) RX FIFO Empty Interrupt. Mask */
#define SQI_INTSTAT_RXEMPTYIF(value)          (SQI_INTSTAT_RXEMPTYIF_Msk & (_UINT32_(value) << SQI_INTSTAT_RXEMPTYIF_Pos)) /* Assigment of value for RXEMPTYIF in the SQI_INTSTAT register */
#define SQI_INTSTAT_RXFULLIF_Pos              _UINT32_(4)                                          /* (SQI_INTSTAT) RX FIFO Full Interrupt. Position */
#define SQI_INTSTAT_RXFULLIF_Msk              (_UINT32_(0x1) << SQI_INTSTAT_RXFULLIF_Pos)          /* (SQI_INTSTAT) RX FIFO Full Interrupt. Mask */
#define SQI_INTSTAT_RXFULLIF(value)           (SQI_INTSTAT_RXFULLIF_Msk & (_UINT32_(value) << SQI_INTSTAT_RXFULLIF_Pos)) /* Assigment of value for RXFULLIF in the SQI_INTSTAT register */
#define SQI_INTSTAT_RXTHRIF_Pos               _UINT32_(5)                                          /* (SQI_INTSTAT) Interrupt to be generated when the RX FIFO has data more than or equal to  RX_INT_THRES words. In case of Boot/XIP mode, the power on reset value of RX buffer threshold is zero. So this bit will be set to 1, immediately after power on reset, till a read request on the AHB Bus. Position */
#define SQI_INTSTAT_RXTHRIF_Msk               (_UINT32_(0x1) << SQI_INTSTAT_RXTHRIF_Pos)           /* (SQI_INTSTAT) Interrupt to be generated when the RX FIFO has data more than or equal to  RX_INT_THRES words. In case of Boot/XIP mode, the power on reset value of RX buffer threshold is zero. So this bit will be set to 1, immediately after power on reset, till a read request on the AHB Bus. Mask */
#define SQI_INTSTAT_RXTHRIF(value)            (SQI_INTSTAT_RXTHRIF_Msk & (_UINT32_(value) << SQI_INTSTAT_RXTHRIF_Pos)) /* Assigment of value for RXTHRIF in the SQI_INTSTAT register */
#define SQI_INTSTAT_CONFULLIF_Pos             _UINT32_(6)                                          /* (SQI_INTSTAT) Control Buffer Full Interrupt Position */
#define SQI_INTSTAT_CONFULLIF_Msk             (_UINT32_(0x1) << SQI_INTSTAT_CONFULLIF_Pos)         /* (SQI_INTSTAT) Control Buffer Full Interrupt Mask */
#define SQI_INTSTAT_CONFULLIF(value)          (SQI_INTSTAT_CONFULLIF_Msk & (_UINT32_(value) << SQI_INTSTAT_CONFULLIF_Pos)) /* Assigment of value for CONFULLIF in the SQI_INTSTAT register */
#define SQI_INTSTAT_CONEMPTYIF_Pos            _UINT32_(7)                                          /* (SQI_INTSTAT) Control Buffer Empty Interrupt Position */
#define SQI_INTSTAT_CONEMPTYIF_Msk            (_UINT32_(0x1) << SQI_INTSTAT_CONEMPTYIF_Pos)        /* (SQI_INTSTAT) Control Buffer Empty Interrupt Mask */
#define SQI_INTSTAT_CONEMPTYIF(value)         (SQI_INTSTAT_CONEMPTYIF_Msk & (_UINT32_(value) << SQI_INTSTAT_CONEMPTYIF_Pos)) /* Assigment of value for CONEMPTYIF in the SQI_INTSTAT register */
#define SQI_INTSTAT_CONTHRIF_Pos              _UINT32_(8)                                          /* (SQI_INTSTAT) Control Buffer Threshold Interrupt Position */
#define SQI_INTSTAT_CONTHRIF_Msk              (_UINT32_(0x1) << SQI_INTSTAT_CONTHRIF_Pos)          /* (SQI_INTSTAT) Control Buffer Threshold Interrupt Mask */
#define SQI_INTSTAT_CONTHRIF(value)           (SQI_INTSTAT_CONTHRIF_Msk & (_UINT32_(value) << SQI_INTSTAT_CONTHRIF_Pos)) /* Assigment of value for CONTHRIF in the SQI_INTSTAT register */
#define SQI_INTSTAT_BDDONEIF_Pos              _UINT32_(9)                                          /* (SQI_INTSTAT) BDP sets this bit to '1' after current buffer descriptor is processed Position */
#define SQI_INTSTAT_BDDONEIF_Msk              (_UINT32_(0x1) << SQI_INTSTAT_BDDONEIF_Pos)          /* (SQI_INTSTAT) BDP sets this bit to '1' after current buffer descriptor is processed Mask */
#define SQI_INTSTAT_BDDONEIF(value)           (SQI_INTSTAT_BDDONEIF_Msk & (_UINT32_(value) << SQI_INTSTAT_BDDONEIF_Pos)) /* Assigment of value for BDDONEIF in the SQI_INTSTAT register */
#define SQI_INTSTAT_PKTCOMPIF_Pos             _UINT32_(10)                                         /* (SQI_INTSTAT) Packet completion Interrupt Position */
#define SQI_INTSTAT_PKTCOMPIF_Msk             (_UINT32_(0x1) << SQI_INTSTAT_PKTCOMPIF_Pos)         /* (SQI_INTSTAT) Packet completion Interrupt Mask */
#define SQI_INTSTAT_PKTCOMPIF(value)          (SQI_INTSTAT_PKTCOMPIF_Msk & (_UINT32_(value) << SQI_INTSTAT_PKTCOMPIF_Pos)) /* Assigment of value for PKTCOMPIF in the SQI_INTSTAT register */
#define SQI_INTSTAT_DMAEIF_Pos                _UINT32_(11)                                         /* (SQI_INTSTAT) Master Error Interrupt Position */
#define SQI_INTSTAT_DMAEIF_Msk                (_UINT32_(0x1) << SQI_INTSTAT_DMAEIF_Pos)            /* (SQI_INTSTAT) Master Error Interrupt Mask */
#define SQI_INTSTAT_DMAEIF(value)             (SQI_INTSTAT_DMAEIF_Msk & (_UINT32_(value) << SQI_INTSTAT_DMAEIF_Pos)) /* Assigment of value for DMAEIF in the SQI_INTSTAT register */
#define SQI_INTSTAT_Msk                       _UINT32_(0x00000FFF)                                 /* (SQI_INTSTAT) Register Mask  */


/* -------- SQI_TXDATA : (SQI Offset: 0x124) (R/W 32) SPI Transmit Data Register -------- */
#define SQI_TXDATA_RESETVALUE                 _UINT32_(0x00)                                       /*  (SQI_TXDATA) SPI Transmit Data Register  Reset Value */

#define SQI_TXDATA_TXDATA_Pos                 _UINT32_(0)                                          /* (SQI_TXDATA) Data is loaded into this register before being transmitted. Just prior to the beginning of a data transfer, the data in TX_DATA is loaded into the shift register. This register is  used as a window to write data into Transmit buffer. Position */
#define SQI_TXDATA_TXDATA_Msk                 (_UINT32_(0xFFFFFFFF) << SQI_TXDATA_TXDATA_Pos)      /* (SQI_TXDATA) Data is loaded into this register before being transmitted. Just prior to the beginning of a data transfer, the data in TX_DATA is loaded into the shift register. This register is  used as a window to write data into Transmit buffer. Mask */
#define SQI_TXDATA_TXDATA(value)              (SQI_TXDATA_TXDATA_Msk & (_UINT32_(value) << SQI_TXDATA_TXDATA_Pos)) /* Assigment of value for TXDATA in the SQI_TXDATA register */
#define SQI_TXDATA_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (SQI_TXDATA) Register Mask  */


/* -------- SQI_RXDATA : (SQI Offset: 0x128) ( R/ 32) SPI Receive Data Register -------- */
#define SQI_RXDATA_RESETVALUE                 _UINT32_(0x00)                                       /*  (SQI_RXDATA) SPI Receive Data Register  Reset Value */

#define SQI_RXDATA_RXDATA_Pos                 _UINT32_(0)                                          /* (SQI_RXDATA) At the end of a data transfer, the data in the shift register is loaded into RX_DATA register. This register is used as a window to read data from Receive buffer. Position */
#define SQI_RXDATA_RXDATA_Msk                 (_UINT32_(0xFFFFFFFF) << SQI_RXDATA_RXDATA_Pos)      /* (SQI_RXDATA) At the end of a data transfer, the data in the shift register is loaded into RX_DATA register. This register is used as a window to read data from Receive buffer. Mask */
#define SQI_RXDATA_RXDATA(value)              (SQI_RXDATA_RXDATA_Msk & (_UINT32_(value) << SQI_RXDATA_RXDATA_Pos)) /* Assigment of value for RXDATA in the SQI_RXDATA register */
#define SQI_RXDATA_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (SQI_RXDATA) Register Mask  */


/* -------- SQI_STAT1 : (SQI Offset: 0x12C) ( R/ 32) SPI Status1 Register -------- */
#define SQI_STAT1_RESETVALUE                  _UINT32_(0x1000000)                                  /*  (SQI_STAT1) SPI Status1 Register  Reset Value */

#define SQI_STAT1_RXBUFCNT_Pos                _UINT32_(0)                                          /* (SQI_STAT1) Number of Words of Read Data in the FIFO. Position */
#define SQI_STAT1_RXBUFCNT_Msk                (_UINT32_(0xFFFF) << SQI_STAT1_RXBUFCNT_Pos)         /* (SQI_STAT1) Number of Words of Read Data in the FIFO. Mask */
#define SQI_STAT1_RXBUFCNT(value)             (SQI_STAT1_RXBUFCNT_Msk & (_UINT32_(value) << SQI_STAT1_RXBUFCNT_Pos)) /* Assigment of value for RXBUFCNT in the SQI_STAT1 register */
#define SQI_STAT1_TXBUFFREE_Pos               _UINT32_(16)                                         /* (SQI_STAT1) Number of Words of Space available in the TX FIFO. Max value equals value of MEM_SIZE_BYTES parameter. Default value is Max Position */
#define SQI_STAT1_TXBUFFREE_Msk               (_UINT32_(0xFFFF) << SQI_STAT1_TXBUFFREE_Pos)        /* (SQI_STAT1) Number of Words of Space available in the TX FIFO. Max value equals value of MEM_SIZE_BYTES parameter. Default value is Max Mask */
#define SQI_STAT1_TXBUFFREE(value)            (SQI_STAT1_TXBUFFREE_Msk & (_UINT32_(value) << SQI_STAT1_TXBUFFREE_Pos)) /* Assigment of value for TXBUFFREE in the SQI_STAT1 register */
#define SQI_STAT1_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (SQI_STAT1) Register Mask  */


/* -------- SQI_STAT2 : (SQI Offset: 0x130) ( R/ 32) SPI status 2 register -------- */
#define SQI_STAT2_RESETVALUE                  _UINT32_(0x00)                                       /*  (SQI_STAT2) SPI status 2 register  Reset Value */

#define SQI_STAT2_TXOV_Pos                    _UINT32_(0)                                          /* (SQI_STAT2) This bit would get set when TX FIFO OVERFLOW happens. S/W needs to monitor TX_FIFO_FREE when filling TX_FIFO to make sure TX FIFO doesn?t over flow or in case OVERFLOW bit gets set, then TX_FIFO_RST (bit 17 of SPI Configuration register) should be set which would then clear TX FIFO pointers and hence this bit would get cleared. Generally software should avoid getting into this condition. Position */
#define SQI_STAT2_TXOV_Msk                    (_UINT32_(0x1) << SQI_STAT2_TXOV_Pos)                /* (SQI_STAT2) This bit would get set when TX FIFO OVERFLOW happens. S/W needs to monitor TX_FIFO_FREE when filling TX_FIFO to make sure TX FIFO doesn?t over flow or in case OVERFLOW bit gets set, then TX_FIFO_RST (bit 17 of SPI Configuration register) should be set which would then clear TX FIFO pointers and hence this bit would get cleared. Generally software should avoid getting into this condition. Mask */
#define SQI_STAT2_TXOV(value)                 (SQI_STAT2_TXOV_Msk & (_UINT32_(value) << SQI_STAT2_TXOV_Pos)) /* Assigment of value for TXOV in the SQI_STAT2 register */
#define SQI_STAT2_RXUN_Pos                    _UINT32_(1)                                          /* (SQI_STAT2) This bit would get set when RX FIFO UNDERFLOW happens.  S/W needs to monitor RX_FIFO_CNT when emptying RX_FIFO to make sure RX FIFO doesn?t under flow or in case UNDERFLOW bit gets set, then RX_FIFO_RST (bit 18 of SPI Configuration register) must be set which would then clear RX FIFO pointers and hence this bit would get cleared. Generally software should avoid getting into this condition. Position */
#define SQI_STAT2_RXUN_Msk                    (_UINT32_(0x1) << SQI_STAT2_RXUN_Pos)                /* (SQI_STAT2) This bit would get set when RX FIFO UNDERFLOW happens.  S/W needs to monitor RX_FIFO_CNT when emptying RX_FIFO to make sure RX FIFO doesn?t under flow or in case UNDERFLOW bit gets set, then RX_FIFO_RST (bit 18 of SPI Configuration register) must be set which would then clear RX FIFO pointers and hence this bit would get cleared. Generally software should avoid getting into this condition. Mask */
#define SQI_STAT2_RXUN(value)                 (SQI_STAT2_RXUN_Msk & (_UINT32_(value) << SQI_STAT2_RXUN_Pos)) /* Assigment of value for RXUN in the SQI_STAT2 register */
#define SQI_STAT2_SQID0_Pos                   _UINT32_(3)                                          /* (SQI_STAT2) SPI Data bus:  This status is used to check the SPI DATA line level for Debugging. Bit3 - SPI_IO0 ,Bit4 - SPI_IO1 ,Bit5 - SPI_IO2 ,Bit6 - SPI_IO3 Position */
#define SQI_STAT2_SQID0_Msk                   (_UINT32_(0x1) << SQI_STAT2_SQID0_Pos)               /* (SQI_STAT2) SPI Data bus:  This status is used to check the SPI DATA line level for Debugging. Bit3 - SPI_IO0 ,Bit4 - SPI_IO1 ,Bit5 - SPI_IO2 ,Bit6 - SPI_IO3 Mask */
#define SQI_STAT2_SQID0(value)                (SQI_STAT2_SQID0_Msk & (_UINT32_(value) << SQI_STAT2_SQID0_Pos)) /* Assigment of value for SQID0 in the SQI_STAT2 register */
#define SQI_STAT2_SQID1_Pos                   _UINT32_(4)                                          /* (SQI_STAT2) SPI Data bus:  This status is used to check the SPI DATA line level for Debugging. Bit3 - SPI_IO0 ,Bit4 - SPI_IO1 ,Bit5 - SPI_IO2 ,Bit6 - SPI_IO3 Position */
#define SQI_STAT2_SQID1_Msk                   (_UINT32_(0x1) << SQI_STAT2_SQID1_Pos)               /* (SQI_STAT2) SPI Data bus:  This status is used to check the SPI DATA line level for Debugging. Bit3 - SPI_IO0 ,Bit4 - SPI_IO1 ,Bit5 - SPI_IO2 ,Bit6 - SPI_IO3 Mask */
#define SQI_STAT2_SQID1(value)                (SQI_STAT2_SQID1_Msk & (_UINT32_(value) << SQI_STAT2_SQID1_Pos)) /* Assigment of value for SQID1 in the SQI_STAT2 register */
#define SQI_STAT2_SQID2_Pos                   _UINT32_(5)                                          /* (SQI_STAT2) SPI Data bus:  This status is used to check the SPI DATA line level for Debugging. Bit3 - SPI_IO0 ,Bit4 - SPI_IO1 ,Bit5 - SPI_IO2 ,Bit6 - SPI_IO3 Position */
#define SQI_STAT2_SQID2_Msk                   (_UINT32_(0x1) << SQI_STAT2_SQID2_Pos)               /* (SQI_STAT2) SPI Data bus:  This status is used to check the SPI DATA line level for Debugging. Bit3 - SPI_IO0 ,Bit4 - SPI_IO1 ,Bit5 - SPI_IO2 ,Bit6 - SPI_IO3 Mask */
#define SQI_STAT2_SQID2(value)                (SQI_STAT2_SQID2_Msk & (_UINT32_(value) << SQI_STAT2_SQID2_Pos)) /* Assigment of value for SQID2 in the SQI_STAT2 register */
#define SQI_STAT2_SQID3_Pos                   _UINT32_(6)                                          /* (SQI_STAT2) SPI Data bus:  This status is used to check the SPI DATA line level for Debugging. Bit3 - SPI_IO0 ,Bit4 - SPI_IO1 ,Bit5 - SPI_IO2 ,Bit6 - SPI_IO3 Position */
#define SQI_STAT2_SQID3_Msk                   (_UINT32_(0x1) << SQI_STAT2_SQID3_Pos)               /* (SQI_STAT2) SPI Data bus:  This status is used to check the SPI DATA line level for Debugging. Bit3 - SPI_IO0 ,Bit4 - SPI_IO1 ,Bit5 - SPI_IO2 ,Bit6 - SPI_IO3 Mask */
#define SQI_STAT2_SQID3(value)                (SQI_STAT2_SQID3_Msk & (_UINT32_(value) << SQI_STAT2_SQID3_Pos)) /* Assigment of value for SQID3 in the SQI_STAT2 register */
#define SQI_STAT2_CONAVAIL_Pos                _UINT32_(7)                                          /* (SQI_STAT2) Indicates the number of entries in Control Buffer remaining. NOTE: This field not present in Michigan Ax versions. Treat as Reserved. Position */
#define SQI_STAT2_CONAVAIL_Msk                (_UINT32_(0x7) << SQI_STAT2_CONAVAIL_Pos)            /* (SQI_STAT2) Indicates the number of entries in Control Buffer remaining. NOTE: This field not present in Michigan Ax versions. Treat as Reserved. Mask */
#define SQI_STAT2_CONAVAIL(value)             (SQI_STAT2_CONAVAIL_Msk & (_UINT32_(value) << SQI_STAT2_CONAVAIL_Pos)) /* Assigment of value for CONAVAIL in the SQI_STAT2 register */
#define SQI_STAT2_CMDSTAT_Pos                 _UINT32_(16)                                         /* (SQI_STAT2) Reflect the (internal state machine) CMD_INIT value. Indicates whether the controller is in Transmit/Receive/IDLE state. 2?b00 - IDLE ,2?b01 - Transmit ,2?b10 - Receive ,2?b11 - Reserved Position */
#define SQI_STAT2_CMDSTAT_Msk                 (_UINT32_(0x3) << SQI_STAT2_CMDSTAT_Pos)             /* (SQI_STAT2) Reflect the (internal state machine) CMD_INIT value. Indicates whether the controller is in Transmit/Receive/IDLE state. 2?b00 - IDLE ,2?b01 - Transmit ,2?b10 - Receive ,2?b11 - Reserved Mask */
#define SQI_STAT2_CMDSTAT(value)              (SQI_STAT2_CMDSTAT_Msk & (_UINT32_(value) << SQI_STAT2_CMDSTAT_Pos)) /* Assigment of value for CMDSTAT in the SQI_STAT2 register */
#define SQI_STAT2_Msk                         _UINT32_(0x000303FB)                                 /* (SQI_STAT2) Register Mask  */

#define SQI_STAT2_SQID_Pos                    _UINT32_(3)                                          /* (SQI_STAT2 Position) SPI Data bus:  This status is used to check the SPI DATA line level for Debugging. Bit3 - SPI_IOx ,Bit4 - SPI_IOx ,Bit5 - SPI_IO2 ,Bit6 - SPI_IO3 */
#define SQI_STAT2_SQID_Msk                    (_UINT32_(0xF) << SQI_STAT2_SQID_Pos)                /* (SQI_STAT2 Mask) SQID */
#define SQI_STAT2_SQID(value)                 (SQI_STAT2_SQID_Msk & (_UINT32_(value) << SQI_STAT2_SQID_Pos)) 

/* -------- SQI_BDCON : (SQI Offset: 0x134) (R/W 32) BD_CTRL Register -------- */
#define SQI_BDCON_RESETVALUE                  _UINT32_(0x00)                                       /*  (SQI_BDCON) BD_CTRL Register  Reset Value */

#define SQI_BDCON_DMAEN_Pos                   _UINT32_(0)                                          /* (SQI_BDCON) DMA Enable Bit 1 - Enabled, 0 - Disabled Position */
#define SQI_BDCON_DMAEN_Msk                   (_UINT32_(0x1) << SQI_BDCON_DMAEN_Pos)               /* (SQI_BDCON) DMA Enable Bit 1 - Enabled, 0 - Disabled Mask */
#define SQI_BDCON_DMAEN(value)                (SQI_BDCON_DMAEN_Msk & (_UINT32_(value) << SQI_BDCON_DMAEN_Pos)) /* Assigment of value for DMAEN in the SQI_BDCON register */
#define SQI_BDCON_POLLEN_Pos                  _UINT32_(1)                                          /* (SQI_BDCON) Setting this bit would cause Buffer Descriptor processor (BDP) to poll for descriptor valid till descriptor valid bit is set or till poll counter expires based on value programmed in BD_POLL_CTRL register. Position */
#define SQI_BDCON_POLLEN_Msk                  (_UINT32_(0x1) << SQI_BDCON_POLLEN_Pos)              /* (SQI_BDCON) Setting this bit would cause Buffer Descriptor processor (BDP) to poll for descriptor valid till descriptor valid bit is set or till poll counter expires based on value programmed in BD_POLL_CTRL register. Mask */
#define SQI_BDCON_POLLEN(value)               (SQI_BDCON_POLLEN_Msk & (_UINT32_(value) << SQI_BDCON_POLLEN_Pos)) /* Assigment of value for POLLEN in the SQI_BDCON register */
#define SQI_BDCON_START_Pos                   _UINT32_(2)                                          /* (SQI_BDCON) Setting this bit to '1' would start BDP (Buffer Descriptor Processor) to fetch a  descriptor and hence this bit should be enabled only after all the DMA descriptor programming is done. Hardware clears this bit automatically after one clock cycle. Position */
#define SQI_BDCON_START_Msk                   (_UINT32_(0x1) << SQI_BDCON_START_Pos)               /* (SQI_BDCON) Setting this bit to '1' would start BDP (Buffer Descriptor Processor) to fetch a  descriptor and hence this bit should be enabled only after all the DMA descriptor programming is done. Hardware clears this bit automatically after one clock cycle. Mask */
#define SQI_BDCON_START(value)                (SQI_BDCON_START_Msk & (_UINT32_(value) << SQI_BDCON_START_Pos)) /* Assigment of value for START in the SQI_BDCON register */
#define SQI_BDCON_Msk                         _UINT32_(0x00000007)                                 /* (SQI_BDCON) Register Mask  */


/* -------- SQI_BDCURADD : (SQI Offset: 0x138) ( R/ 32) BD_CURR_ADDR Register -------- */
#define SQI_BDCURADD_RESETVALUE               _UINT32_(0x00)                                       /*  (SQI_BDCURADD) BD_CURR_ADDR Register  Reset Value */

#define SQI_BDCURADD_BDCURRADDR_Pos           _UINT32_(0)                                          /* (SQI_BDCURADD) This register field contains the current descriptor address being processed by Buffer Descriptor Processor (BDP) Position */
#define SQI_BDCURADD_BDCURRADDR_Msk           (_UINT32_(0xFFFFFFFF) << SQI_BDCURADD_BDCURRADDR_Pos) /* (SQI_BDCURADD) This register field contains the current descriptor address being processed by Buffer Descriptor Processor (BDP) Mask */
#define SQI_BDCURADD_BDCURRADDR(value)        (SQI_BDCURADD_BDCURRADDR_Msk & (_UINT32_(value) << SQI_BDCURADD_BDCURRADDR_Pos)) /* Assigment of value for BDCURRADDR in the SQI_BDCURADD register */
#define SQI_BDCURADD_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (SQI_BDCURADD) Register Mask  */


/* -------- SQI_BDBASEADD : (SQI Offset: 0x140) (R/W 32) BD_BASE_ADDR register -------- */
#define SQI_BDBASEADD_RESETVALUE              _UINT32_(0x00)                                       /*  (SQI_BDBASEADD) BD_BASE_ADDR register  Reset Value */

#define SQI_BDBASEADD_BDADDR_Pos              _UINT32_(0)                                          /* (SQI_BDBASEADD) This register field contains the base address of the DMA. This register must be updated only when the DMA is IDLE. Position */
#define SQI_BDBASEADD_BDADDR_Msk              (_UINT32_(0xFFFFFFFF) << SQI_BDBASEADD_BDADDR_Pos)   /* (SQI_BDBASEADD) This register field contains the base address of the DMA. This register must be updated only when the DMA is IDLE. Mask */
#define SQI_BDBASEADD_BDADDR(value)           (SQI_BDBASEADD_BDADDR_Msk & (_UINT32_(value) << SQI_BDBASEADD_BDADDR_Pos)) /* Assigment of value for BDADDR in the SQI_BDBASEADD register */
#define SQI_BDBASEADD_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (SQI_BDBASEADD) Register Mask  */


/* -------- SQI_BDSTAT : (SQI Offset: 0x144) ( R/ 32) BD_STATUS Register -------- */
#define SQI_BDSTAT_BDCON_Pos                  _UINT32_(0)                                          /* (SQI_BDSTAT) This register field contains the current Descriptor control information. Bits [31:16] of BD_CTRL field of current descriptor are indicated in this register field. Position */
#define SQI_BDSTAT_BDCON_Msk                  (_UINT32_(0xFFFF) << SQI_BDSTAT_BDCON_Pos)           /* (SQI_BDSTAT) This register field contains the current Descriptor control information. Bits [31:16] of BD_CTRL field of current descriptor are indicated in this register field. Mask */
#define SQI_BDSTAT_BDCON(value)               (SQI_BDSTAT_BDCON_Msk & (_UINT32_(value) << SQI_BDSTAT_BDCON_Pos)) /* Assigment of value for BDCON in the SQI_BDSTAT register */
#define SQI_BDSTAT_DMAACTV_Pos                _UINT32_(16)                                         /* (SQI_BDSTAT) A value of '1' would indicate that Buffer Descriptor Processor (BDP) is not Idle. Value of '0' would indicate that BDP is in IDLE state Position */
#define SQI_BDSTAT_DMAACTV_Msk                (_UINT32_(0x1) << SQI_BDSTAT_DMAACTV_Pos)            /* (SQI_BDSTAT) A value of '1' would indicate that Buffer Descriptor Processor (BDP) is not Idle. Value of '0' would indicate that BDP is in IDLE state Mask */
#define SQI_BDSTAT_DMAACTV(value)             (SQI_BDSTAT_DMAACTV_Msk & (_UINT32_(value) << SQI_BDSTAT_DMAACTV_Pos)) /* Assigment of value for DMAACTV in the SQI_BDSTAT register */
#define SQI_BDSTAT_DMASTART_Pos               _UINT32_(17)                                         /* (SQI_BDSTAT) This register field would indicate whether DMA has started or not, if bit it set '1', then it indicates DMA start has happened. Value of '0' would indicate that DMA hasn't started. Position */
#define SQI_BDSTAT_DMASTART_Msk               (_UINT32_(0x1) << SQI_BDSTAT_DMASTART_Pos)           /* (SQI_BDSTAT) This register field would indicate whether DMA has started or not, if bit it set '1', then it indicates DMA start has happened. Value of '0' would indicate that DMA hasn't started. Mask */
#define SQI_BDSTAT_DMASTART(value)            (SQI_BDSTAT_DMASTART_Msk & (_UINT32_(value) << SQI_BDSTAT_DMASTART_Pos)) /* Assigment of value for DMASTART in the SQI_BDSTAT register */
#define SQI_BDSTAT_BDSTATE_Pos                _UINT32_(18)                                         /* (SQI_BDSTAT) This register field contains current BDP state :  0  IDLE, 1  Descriptor fetch Request Pending, 2  BD loading, 3  Data phase , 4  Descriptor Done, 5  Fetched BD is disabled, 6  Wait for Control Buffer Available, 7  Wait for AHB Error Acknowledgement Position */
#define SQI_BDSTAT_BDSTATE_Msk                (_UINT32_(0xF) << SQI_BDSTAT_BDSTATE_Pos)            /* (SQI_BDSTAT) This register field contains current BDP state :  0  IDLE, 1  Descriptor fetch Request Pending, 2  BD loading, 3  Data phase , 4  Descriptor Done, 5  Fetched BD is disabled, 6  Wait for Control Buffer Available, 7  Wait for AHB Error Acknowledgement Mask */
#define SQI_BDSTAT_BDSTATE(value)             (SQI_BDSTAT_BDSTATE_Msk & (_UINT32_(value) << SQI_BDSTAT_BDSTATE_Pos)) /* Assigment of value for BDSTATE in the SQI_BDSTAT register */
#define SQI_BDSTAT_Msk                        _UINT32_(0x003FFFFF)                                 /* (SQI_BDSTAT) Register Mask  */


/* -------- SQI_BDPOLLCON : (SQI Offset: 0x148) (R/W 32) BD_POLL_CTRL Register -------- */
#define SQI_BDPOLLCON_POLLCON_Pos             _UINT32_(0)                                          /* (SQI_BDPOLLCON) Number of cycles that BDP block would wait before re-fetching the Descriptor control word if the previous descriptor fetched was disabled Position */
#define SQI_BDPOLLCON_POLLCON_Msk             (_UINT32_(0xFFFF) << SQI_BDPOLLCON_POLLCON_Pos)      /* (SQI_BDPOLLCON) Number of cycles that BDP block would wait before re-fetching the Descriptor control word if the previous descriptor fetched was disabled Mask */
#define SQI_BDPOLLCON_POLLCON(value)          (SQI_BDPOLLCON_POLLCON_Msk & (_UINT32_(value) << SQI_BDPOLLCON_POLLCON_Pos)) /* Assigment of value for POLLCON in the SQI_BDPOLLCON register */
#define SQI_BDPOLLCON_Msk                     _UINT32_(0x0000FFFF)                                 /* (SQI_BDPOLLCON) Register Mask  */


/* -------- SQI_BDTXDSTAT : (SQI Offset: 0x14C) (R/W 32) BD_TX_DMA_STATUS Register -------- */
#define SQI_BDTXDSTAT_TXCURBUFLEN_Pos         _UINT32_(0)                                          /* (SQI_BDTXDSTAT) This register field gives the length of the current buffer transmit length Position */
#define SQI_BDTXDSTAT_TXCURBUFLEN_Msk         (_UINT32_(0xFFFF) << SQI_BDTXDSTAT_TXCURBUFLEN_Pos)  /* (SQI_BDTXDSTAT) This register field gives the length of the current buffer transmit length Mask */
#define SQI_BDTXDSTAT_TXCURBUFLEN(value)      (SQI_BDTXDSTAT_TXCURBUFLEN_Msk & (_UINT32_(value) << SQI_BDTXDSTAT_TXCURBUFLEN_Pos)) /* Assigment of value for TXCURBUFLEN in the SQI_BDTXDSTAT register */
#define SQI_BDTXDSTAT_TXBUFCNT_Pos            _UINT32_(16)                                         /* (SQI_BDTXDSTAT) This register field gives the information about the internal transmit FIFO space. Position */
#define SQI_BDTXDSTAT_TXBUFCNT_Msk            (_UINT32_(0xFF) << SQI_BDTXDSTAT_TXBUFCNT_Pos)       /* (SQI_BDTXDSTAT) This register field gives the information about the internal transmit FIFO space. Mask */
#define SQI_BDTXDSTAT_TXBUFCNT(value)         (SQI_BDTXDSTAT_TXBUFCNT_Msk & (_UINT32_(value) << SQI_BDTXDSTAT_TXBUFCNT_Pos)) /* Assigment of value for TXBUFCNT in the SQI_BDTXDSTAT register */
#define SQI_BDTXDSTAT_Msk                     _UINT32_(0x00FFFFFF)                                 /* (SQI_BDTXDSTAT) Register Mask  */


/* -------- SQI_BDRXDSTAT : (SQI Offset: 0x150) ( R/ 32) BD_RX_DMA_STATUS Register -------- */
#define SQI_BDRXDSTAT_RXCURBUFLEN_Pos         _UINT32_(0)                                          /* (SQI_BDRXDSTAT) This register field gives the length of the current buffer receive length Position */
#define SQI_BDRXDSTAT_RXCURBUFLEN_Msk         (_UINT32_(0xFFFF) << SQI_BDRXDSTAT_RXCURBUFLEN_Pos)  /* (SQI_BDRXDSTAT) This register field gives the length of the current buffer receive length Mask */
#define SQI_BDRXDSTAT_RXCURBUFLEN(value)      (SQI_BDRXDSTAT_RXCURBUFLEN_Msk & (_UINT32_(value) << SQI_BDRXDSTAT_RXCURBUFLEN_Pos)) /* Assigment of value for RXCURBUFLEN in the SQI_BDRXDSTAT register */
#define SQI_BDRXDSTAT_RXBUFCNT_Pos            _UINT32_(16)                                         /* (SQI_BDRXDSTAT) This register field gives the information about the internal receive FIFO space. Position */
#define SQI_BDRXDSTAT_RXBUFCNT_Msk            (_UINT32_(0x1) << SQI_BDRXDSTAT_RXBUFCNT_Pos)        /* (SQI_BDRXDSTAT) This register field gives the information about the internal receive FIFO space. Mask */
#define SQI_BDRXDSTAT_RXBUFCNT(value)         (SQI_BDRXDSTAT_RXBUFCNT_Msk & (_UINT32_(value) << SQI_BDRXDSTAT_RXBUFCNT_Pos)) /* Assigment of value for RXBUFCNT in the SQI_BDRXDSTAT register */
#define SQI_BDRXDSTAT_Msk                     _UINT32_(0x0001FFFF)                                 /* (SQI_BDRXDSTAT) Register Mask  */


/* -------- SQI_THR : (SQI Offset: 0x154) (R/W 32) SPI Control threshold register -------- */
#define SQI_THR_RESETVALUE                    _UINT32_(0x00)                                       /*  (SQI_THR) SPI Control threshold register  Reset Value */

#define SQI_THR_THRES_Pos                     _UINT32_(0)                                          /* (SQI_THR) SPI Control Threshold Value. SPI Control Threshold Interrupt is asserted, whenever larger than SPI Control Threshold amount of space available in SPI Control Buffer. Position */
#define SQI_THR_THRES_Msk                     (_UINT32_(0x7) << SQI_THR_THRES_Pos)                 /* (SQI_THR) SPI Control Threshold Value. SPI Control Threshold Interrupt is asserted, whenever larger than SPI Control Threshold amount of space available in SPI Control Buffer. Mask */
#define SQI_THR_THRES(value)                  (SQI_THR_THRES_Msk & (_UINT32_(value) << SQI_THR_THRES_Pos)) /* Assigment of value for THRES in the SQI_THR register */
#define SQI_THR_Msk                           _UINT32_(0x00000007)                                 /* (SQI_THR) Register Mask  */


/* -------- SQI_INTSIGEN : (SQI Offset: 0x158) (R/W 32) SPI Interrupt Signal Enable Register -------- */
#define SQI_INTSIGEN_RESETVALUE               _UINT32_(0x8AD)                                      /*  (SQI_INTSIGEN) SPI Interrupt Signal Enable Register  Reset Value */

#define SQI_INTSIGEN_TXEMPTYISE_Pos           _UINT32_(0)                                          /* (SQI_INTSIGEN) TX FIFO Empty Interrupt Signal Enable. Position */
#define SQI_INTSIGEN_TXEMPTYISE_Msk           (_UINT32_(0x1) << SQI_INTSIGEN_TXEMPTYISE_Pos)       /* (SQI_INTSIGEN) TX FIFO Empty Interrupt Signal Enable. Mask */
#define SQI_INTSIGEN_TXEMPTYISE(value)        (SQI_INTSIGEN_TXEMPTYISE_Msk & (_UINT32_(value) << SQI_INTSIGEN_TXEMPTYISE_Pos)) /* Assigment of value for TXEMPTYISE in the SQI_INTSIGEN register */
#define SQI_INTSIGEN_TXFULLISE_Pos            _UINT32_(1)                                          /* (SQI_INTSIGEN) TX FIFO Full Interrupt Signal Enable. Position */
#define SQI_INTSIGEN_TXFULLISE_Msk            (_UINT32_(0x1) << SQI_INTSIGEN_TXFULLISE_Pos)        /* (SQI_INTSIGEN) TX FIFO Full Interrupt Signal Enable. Mask */
#define SQI_INTSIGEN_TXFULLISE(value)         (SQI_INTSIGEN_TXFULLISE_Msk & (_UINT32_(value) << SQI_INTSIGEN_TXFULLISE_Pos)) /* Assigment of value for TXFULLISE in the SQI_INTSIGEN register */
#define SQI_INTSIGEN_TXTHRISE_Pos             _UINT32_(2)                                          /* (SQI_INTSIGEN) Signal Enable Interrupt to be generated when the TX FIFO has space equal to or more than TX_INT_THRES words. Position */
#define SQI_INTSIGEN_TXTHRISE_Msk             (_UINT32_(0x1) << SQI_INTSIGEN_TXTHRISE_Pos)         /* (SQI_INTSIGEN) Signal Enable Interrupt to be generated when the TX FIFO has space equal to or more than TX_INT_THRES words. Mask */
#define SQI_INTSIGEN_TXTHRISE(value)          (SQI_INTSIGEN_TXTHRISE_Msk & (_UINT32_(value) << SQI_INTSIGEN_TXTHRISE_Pos)) /* Assigment of value for TXTHRISE in the SQI_INTSIGEN register */
#define SQI_INTSIGEN_RXEMPTYISE_Pos           _UINT32_(3)                                          /* (SQI_INTSIGEN) RX FIFO Empty Interrupt Signal Enable. Position */
#define SQI_INTSIGEN_RXEMPTYISE_Msk           (_UINT32_(0x1) << SQI_INTSIGEN_RXEMPTYISE_Pos)       /* (SQI_INTSIGEN) RX FIFO Empty Interrupt Signal Enable. Mask */
#define SQI_INTSIGEN_RXEMPTYISE(value)        (SQI_INTSIGEN_RXEMPTYISE_Msk & (_UINT32_(value) << SQI_INTSIGEN_RXEMPTYISE_Pos)) /* Assigment of value for RXEMPTYISE in the SQI_INTSIGEN register */
#define SQI_INTSIGEN_RXFULLISE_Pos            _UINT32_(4)                                          /* (SQI_INTSIGEN) RX FIFO Full Interrupt Signal Enable. Position */
#define SQI_INTSIGEN_RXFULLISE_Msk            (_UINT32_(0x1) << SQI_INTSIGEN_RXFULLISE_Pos)        /* (SQI_INTSIGEN) RX FIFO Full Interrupt Signal Enable. Mask */
#define SQI_INTSIGEN_RXFULLISE(value)         (SQI_INTSIGEN_RXFULLISE_Msk & (_UINT32_(value) << SQI_INTSIGEN_RXFULLISE_Pos)) /* Assigment of value for RXFULLISE in the SQI_INTSIGEN register */
#define SQI_INTSIGEN_RXTHRISE_Pos             _UINT32_(5)                                          /* (SQI_INTSIGEN) Signal Enable Interrupt to be generated when the RX FIFO has data more than or equal to RX_INT_THRES words.  In case of Boot/XIP mode, the power on reset value of RX buffer threshold is zero. So this bit will be set to 1, immediately after power on reset, till a read request on the AHB Bus. Position */
#define SQI_INTSIGEN_RXTHRISE_Msk             (_UINT32_(0x1) << SQI_INTSIGEN_RXTHRISE_Pos)         /* (SQI_INTSIGEN) Signal Enable Interrupt to be generated when the RX FIFO has data more than or equal to RX_INT_THRES words.  In case of Boot/XIP mode, the power on reset value of RX buffer threshold is zero. So this bit will be set to 1, immediately after power on reset, till a read request on the AHB Bus. Mask */
#define SQI_INTSIGEN_RXTHRISE(value)          (SQI_INTSIGEN_RXTHRISE_Msk & (_UINT32_(value) << SQI_INTSIGEN_RXTHRISE_Pos)) /* Assigment of value for RXTHRISE in the SQI_INTSIGEN register */
#define SQI_INTSIGEN_CONFULLISE_Pos           _UINT32_(6)                                          /* (SQI_INTSIGEN) Control Buffer Full Interrupt Signal Enable Position */
#define SQI_INTSIGEN_CONFULLISE_Msk           (_UINT32_(0x1) << SQI_INTSIGEN_CONFULLISE_Pos)       /* (SQI_INTSIGEN) Control Buffer Full Interrupt Signal Enable Mask */
#define SQI_INTSIGEN_CONFULLISE(value)        (SQI_INTSIGEN_CONFULLISE_Msk & (_UINT32_(value) << SQI_INTSIGEN_CONFULLISE_Pos)) /* Assigment of value for CONFULLISE in the SQI_INTSIGEN register */
#define SQI_INTSIGEN_CONEMPTYISE_Pos          _UINT32_(7)                                          /* (SQI_INTSIGEN) Control Buffer Empty Interrupt Signal Enable Position */
#define SQI_INTSIGEN_CONEMPTYISE_Msk          (_UINT32_(0x1) << SQI_INTSIGEN_CONEMPTYISE_Pos)      /* (SQI_INTSIGEN) Control Buffer Empty Interrupt Signal Enable Mask */
#define SQI_INTSIGEN_CONEMPTYISE(value)       (SQI_INTSIGEN_CONEMPTYISE_Msk & (_UINT32_(value) << SQI_INTSIGEN_CONEMPTYISE_Pos)) /* Assigment of value for CONEMPTYISE in the SQI_INTSIGEN register */
#define SQI_INTSIGEN_CONTHRISE_Pos            _UINT32_(8)                                          /* (SQI_INTSIGEN) Control Buffer Threshold Interrupt Signal Enable Position */
#define SQI_INTSIGEN_CONTHRISE_Msk            (_UINT32_(0x1) << SQI_INTSIGEN_CONTHRISE_Pos)        /* (SQI_INTSIGEN) Control Buffer Threshold Interrupt Signal Enable Mask */
#define SQI_INTSIGEN_CONTHRISE(value)         (SQI_INTSIGEN_CONTHRISE_Msk & (_UINT32_(value) << SQI_INTSIGEN_CONTHRISE_Pos)) /* Assigment of value for CONTHRISE in the SQI_INTSIGEN register */
#define SQI_INTSIGEN_BDDONEISE_Pos            _UINT32_(9)                                          /* (SQI_INTSIGEN) Current Buffer Descriptor Interrupt Signal Enable Position */
#define SQI_INTSIGEN_BDDONEISE_Msk            (_UINT32_(0x1) << SQI_INTSIGEN_BDDONEISE_Pos)        /* (SQI_INTSIGEN) Current Buffer Descriptor Interrupt Signal Enable Mask */
#define SQI_INTSIGEN_BDDONEISE(value)         (SQI_INTSIGEN_BDDONEISE_Msk & (_UINT32_(value) << SQI_INTSIGEN_BDDONEISE_Pos)) /* Assigment of value for BDDONEISE in the SQI_INTSIGEN register */
#define SQI_INTSIGEN_PKTCOMPISE_Pos           _UINT32_(10)                                         /* (SQI_INTSIGEN) Packet completion Interrupt Signal Enable Position */
#define SQI_INTSIGEN_PKTCOMPISE_Msk           (_UINT32_(0x1) << SQI_INTSIGEN_PKTCOMPISE_Pos)       /* (SQI_INTSIGEN) Packet completion Interrupt Signal Enable Mask */
#define SQI_INTSIGEN_PKTCOMPISE(value)        (SQI_INTSIGEN_PKTCOMPISE_Msk & (_UINT32_(value) << SQI_INTSIGEN_PKTCOMPISE_Pos)) /* Assigment of value for PKTCOMPISE in the SQI_INTSIGEN register */
#define SQI_INTSIGEN_DMAEISE_Pos              _UINT32_(11)                                         /* (SQI_INTSIGEN) Master Error Interrupt Signal Enable Position */
#define SQI_INTSIGEN_DMAEISE_Msk              (_UINT32_(0x1) << SQI_INTSIGEN_DMAEISE_Pos)          /* (SQI_INTSIGEN) Master Error Interrupt Signal Enable Mask */
#define SQI_INTSIGEN_DMAEISE(value)           (SQI_INTSIGEN_DMAEISE_Msk & (_UINT32_(value) << SQI_INTSIGEN_DMAEISE_Pos)) /* Assigment of value for DMAEISE in the SQI_INTSIGEN register */
#define SQI_INTSIGEN_Msk                      _UINT32_(0x00000FFF)                                 /* (SQI_INTSIGEN) Register Mask  */


/* -------- SQI_TAPCON : (SQI Offset: 0x15C) (R/W 32) Tap Control Register -------- */
#define SQI_TAPCON_RESETVALUE                 _UINT32_(0x110021)                                   /*  (SQI_TAPCON) Tap Control Register  Reset Value */

#define SQI_TAPCON_CLKOUTDLY_Pos              _UINT32_(0)                                          /* (SQI_TAPCON) Used to add delay on spi clock output.16 taps available. Position */
#define SQI_TAPCON_CLKOUTDLY_Msk              (_UINT32_(0xF) << SQI_TAPCON_CLKOUTDLY_Pos)          /* (SQI_TAPCON) Used to add delay on spi clock output.16 taps available. Mask */
#define SQI_TAPCON_CLKOUTDLY(value)           (SQI_TAPCON_CLKOUTDLY_Msk & (_UINT32_(value) << SQI_TAPCON_CLKOUTDLY_Pos)) /* Assigment of value for CLKOUTDLY in the SQI_TAPCON register */
#define SQI_TAPCON_DATAOUTDLY_Pos             _UINT32_(4)                                          /* (SQI_TAPCON) Used to add delay on spi data outputs (1/2/4lanes). 16 taps available. Position */
#define SQI_TAPCON_DATAOUTDLY_Msk             (_UINT32_(0xF) << SQI_TAPCON_DATAOUTDLY_Pos)         /* (SQI_TAPCON) Used to add delay on spi data outputs (1/2/4lanes). 16 taps available. Mask */
#define SQI_TAPCON_DATAOUTDLY(value)          (SQI_TAPCON_DATAOUTDLY_Msk & (_UINT32_(value) << SQI_TAPCON_DATAOUTDLY_Pos)) /* Assigment of value for DATAOUTDLY in the SQI_TAPCON register */
#define SQI_TAPCON_SDRCLKINDLY_Pos            _UINT32_(8)                                          /* (SQI_TAPCON) Used only in SDR mode. This field is used to add tap delay cells on the spi clock input. Based on the mode of operation (SDR Vs DDR), the controller dynamically picks the appropriate delay values  (CLK_IN_DLY_CNT Vs CLK_IN_ALT_DLY_CNT). Position */
#define SQI_TAPCON_SDRCLKINDLY_Msk            (_UINT32_(0x3F) << SQI_TAPCON_SDRCLKINDLY_Pos)       /* (SQI_TAPCON) Used only in SDR mode. This field is used to add tap delay cells on the spi clock input. Based on the mode of operation (SDR Vs DDR), the controller dynamically picks the appropriate delay values  (CLK_IN_DLY_CNT Vs CLK_IN_ALT_DLY_CNT). Mask */
#define SQI_TAPCON_SDRCLKINDLY(value)         (SQI_TAPCON_SDRCLKINDLY_Msk & (_UINT32_(value) << SQI_TAPCON_SDRCLKINDLY_Pos)) /* Assigment of value for SDRCLKINDLY in the SQI_TAPCON register */
#define SQI_TAPCON_DDRDATINDLY_Pos            _UINT32_(16)                                         /* (SQI_TAPCON) Used only in DDR mode. This field is used to add tap delay cells on the data input. Based on the mode of operation (SDR Vs DDR), the controller dynamically picks the appropriate delay values (DATA_IN_ALT_DLY_CNT Vs DATA_IN_DLY_CNT). Position */
#define SQI_TAPCON_DDRDATINDLY_Msk            (_UINT32_(0xF) << SQI_TAPCON_DDRDATINDLY_Pos)        /* (SQI_TAPCON) Used only in DDR mode. This field is used to add tap delay cells on the data input. Based on the mode of operation (SDR Vs DDR), the controller dynamically picks the appropriate delay values (DATA_IN_ALT_DLY_CNT Vs DATA_IN_DLY_CNT). Mask */
#define SQI_TAPCON_DDRDATINDLY(value)         (SQI_TAPCON_DDRDATINDLY_Msk & (_UINT32_(value) << SQI_TAPCON_DDRDATINDLY_Pos)) /* Assigment of value for DDRDATINDLY in the SQI_TAPCON register */
#define SQI_TAPCON_SDRDATINDLY_Pos            _UINT32_(20)                                         /* (SQI_TAPCON) Used only in SDR mode. This field is used to add tap delay cells on the Data input. Based on the mode of operation (SDR Vs DDR), the controller dynamically picks the appropriate delay values (DATA_IN_ALT_DLY_CNT Vs DATA_IN_DLY_CNT). Position */
#define SQI_TAPCON_SDRDATINDLY_Msk            (_UINT32_(0xF) << SQI_TAPCON_SDRDATINDLY_Pos)        /* (SQI_TAPCON) Used only in SDR mode. This field is used to add tap delay cells on the Data input. Based on the mode of operation (SDR Vs DDR), the controller dynamically picks the appropriate delay values (DATA_IN_ALT_DLY_CNT Vs DATA_IN_DLY_CNT). Mask */
#define SQI_TAPCON_SDRDATINDLY(value)         (SQI_TAPCON_SDRDATINDLY_Msk & (_UINT32_(value) << SQI_TAPCON_SDRDATINDLY_Pos)) /* Assigment of value for SDRDATINDLY in the SQI_TAPCON register */
#define SQI_TAPCON_DDRCLKINDLY_Pos            _UINT32_(24)                                         /* (SQI_TAPCON) Used only in DDR mode. This field is used to add tap delay cells on the spi clock input. Based on the mode of operation (SDR Vs DDR), the controller dynamically picks the appropriate delay values (CLK_IN_DLY_CNT Vs CLK_IN_ALT_DLY_CNT). Position */
#define SQI_TAPCON_DDRCLKINDLY_Msk            (_UINT32_(0x3F) << SQI_TAPCON_DDRCLKINDLY_Pos)       /* (SQI_TAPCON) Used only in DDR mode. This field is used to add tap delay cells on the spi clock input. Based on the mode of operation (SDR Vs DDR), the controller dynamically picks the appropriate delay values (CLK_IN_DLY_CNT Vs CLK_IN_ALT_DLY_CNT). Mask */
#define SQI_TAPCON_DDRCLKINDLY(value)         (SQI_TAPCON_DDRCLKINDLY_Msk & (_UINT32_(value) << SQI_TAPCON_DDRCLKINDLY_Pos)) /* Assigment of value for DDRCLKINDLY in the SQI_TAPCON register */
#define SQI_TAPCON_Msk                        _UINT32_(0x3FFF3FFF)                                 /* (SQI_TAPCON) Register Mask  */


/* -------- SQI_MEMSTAT : (SQI Offset: 0x160) (R/W 32) SPI Status Control Register -------- */
#define SQI_MEMSTAT_RESETVALUE                _UINT32_(0x10005)                                    /*  (SQI_MEMSTAT) SPI Status Control Register  Reset Value */

#define SQI_MEMSTAT_STATCMD_Pos               _UINT32_(0)                                          /* (SQI_MEMSTAT) Status Data: The first byte to be sent must be in LSB. For example if the user wants to send 0F first and 0C second, then we should program 16?h0C0F. Position */
#define SQI_MEMSTAT_STATCMD_Msk               (_UINT32_(0xFFFF) << SQI_MEMSTAT_STATCMD_Pos)        /* (SQI_MEMSTAT) Status Data: The first byte to be sent must be in LSB. For example if the user wants to send 0F first and 0C second, then we should program 16?h0C0F. Mask */
#define SQI_MEMSTAT_STATCMD(value)            (SQI_MEMSTAT_STATCMD_Msk & (_UINT32_(value) << SQI_MEMSTAT_STATCMD_Pos)) /* Assigment of value for STATCMD in the SQI_MEMSTAT register */
#define SQI_MEMSTAT_STATBYTES_Pos             _UINT32_(16)                                         /* (SQI_MEMSTAT) No. of bytes to send: 00 - Reserved ,01 - 1 byte ,10 - 2 bytes ,11 - Reserved Position */
#define SQI_MEMSTAT_STATBYTES_Msk             (_UINT32_(0x3) << SQI_MEMSTAT_STATBYTES_Pos)         /* (SQI_MEMSTAT) No. of bytes to send: 00 - Reserved ,01 - 1 byte ,10 - 2 bytes ,11 - Reserved Mask */
#define SQI_MEMSTAT_STATBYTES(value)          (SQI_MEMSTAT_STATBYTES_Msk & (_UINT32_(value) << SQI_MEMSTAT_STATBYTES_Pos)) /* Assigment of value for STATBYTES in the SQI_MEMSTAT register */
#define SQI_MEMSTAT_TYPESTAT_Pos              _UINT32_(18)                                         /* (SQI_MEMSTAT) Status Lane: Indicates the number of lanes (single/dual/quad) in which the Status command/ Read Status Register value is transmitted to /received from flash. 2?b00 - single lane, 2?b01 - dual lane, 2?b10 - quad lane Position */
#define SQI_MEMSTAT_TYPESTAT_Msk              (_UINT32_(0x3) << SQI_MEMSTAT_TYPESTAT_Pos)          /* (SQI_MEMSTAT) Status Lane: Indicates the number of lanes (single/dual/quad) in which the Status command/ Read Status Register value is transmitted to /received from flash. 2?b00 - single lane, 2?b01 - dual lane, 2?b10 - quad lane Mask */
#define SQI_MEMSTAT_TYPESTAT(value)           (SQI_MEMSTAT_TYPESTAT_Msk & (_UINT32_(value) << SQI_MEMSTAT_TYPESTAT_Pos)) /* Assigment of value for TYPESTAT in the SQI_MEMSTAT register */
#define SQI_MEMSTAT_STATPOS_Pos               _UINT32_(20)                                         /* (SQI_MEMSTAT) Indicates whether the BUSY bit position in Status Register of flash is 0 or 7. 1?b0 - 0th bit position (bit 0 is valid for busy status), 1?b1 - 7th bit position (bit7 is valid for busy status) The Controller continuously reads the Status register value from flash until this bit which indicates the flash busy status goes low. Position */
#define SQI_MEMSTAT_STATPOS_Msk               (_UINT32_(0x1) << SQI_MEMSTAT_STATPOS_Pos)           /* (SQI_MEMSTAT) Indicates whether the BUSY bit position in Status Register of flash is 0 or 7. 1?b0 - 0th bit position (bit 0 is valid for busy status), 1?b1 - 7th bit position (bit7 is valid for busy status) The Controller continuously reads the Status register value from flash until this bit which indicates the flash busy status goes low. Mask */
#define SQI_MEMSTAT_STATPOS(value)            (SQI_MEMSTAT_STATPOS_Msk & (_UINT32_(value) << SQI_MEMSTAT_STATPOS_Pos)) /* Assigment of value for STATPOS in the SQI_MEMSTAT register */
#define SQI_MEMSTAT_Msk                       _UINT32_(0x001FFFFF)                                 /* (SQI_MEMSTAT) Register Mask  */


/* -------- SQI_XCON3 : (SQI Offset: 0x164) (R/W 32) SPI XIP Control 3 Register -------- */
#define SQI_XCON3_RESETVALUE                  _UINT32_(0x00)                                       /*  (SQI_XCON3) SPI XIP Control 3 Register  Reset Value */

#define SQI_XCON3_INIT1CMD1_Pos               _UINT32_(0)                                          /* (SQI_XCON3) 8bit SPI Init1 Code1 value. Position */
#define SQI_XCON3_INIT1CMD1_Msk               (_UINT32_(0xFF) << SQI_XCON3_INIT1CMD1_Pos)          /* (SQI_XCON3) 8bit SPI Init1 Code1 value. Mask */
#define SQI_XCON3_INIT1CMD1(value)            (SQI_XCON3_INIT1CMD1_Msk & (_UINT32_(value) << SQI_XCON3_INIT1CMD1_Pos)) /* Assigment of value for INIT1CMD1 in the SQI_XCON3 register */
#define SQI_XCON3_INIT1CMD2_Pos               _UINT32_(8)                                          /* (SQI_XCON3) 8bit SPI Init1 Code2 value. Position */
#define SQI_XCON3_INIT1CMD2_Msk               (_UINT32_(0xFF) << SQI_XCON3_INIT1CMD2_Pos)          /* (SQI_XCON3) 8bit SPI Init1 Code2 value. Mask */
#define SQI_XCON3_INIT1CMD2(value)            (SQI_XCON3_INIT1CMD2_Msk & (_UINT32_(value) << SQI_XCON3_INIT1CMD2_Pos)) /* Assigment of value for INIT1CMD2 in the SQI_XCON3 register */
#define SQI_XCON3_INIT1CMD3_Pos               _UINT32_(16)                                         /* (SQI_XCON3) 8bit SPI Init1 Code3 value. Position */
#define SQI_XCON3_INIT1CMD3_Msk               (_UINT32_(0xFF) << SQI_XCON3_INIT1CMD3_Pos)          /* (SQI_XCON3) 8bit SPI Init1 Code3 value. Mask */
#define SQI_XCON3_INIT1CMD3(value)            (SQI_XCON3_INIT1CMD3_Msk & (_UINT32_(value) << SQI_XCON3_INIT1CMD3_Pos)) /* Assigment of value for INIT1CMD3 in the SQI_XCON3 register */
#define SQI_XCON3_INIT1TYPE_Pos               _UINT32_(24)                                         /* (SQI_XCON3) SPI TYPE  INIT1: 00 - Single lane mode , 01 - Dual lane mode , 10 - Quad lane mode , 11 - Reserved for Future use. Based on this field, the boot controller will send the INIT1 Code in 1/2/4 lane. Position */
#define SQI_XCON3_INIT1TYPE_Msk               (_UINT32_(0x3) << SQI_XCON3_INIT1TYPE_Pos)           /* (SQI_XCON3) SPI TYPE  INIT1: 00 - Single lane mode , 01 - Dual lane mode , 10 - Quad lane mode , 11 - Reserved for Future use. Based on this field, the boot controller will send the INIT1 Code in 1/2/4 lane. Mask */
#define SQI_XCON3_INIT1TYPE(value)            (SQI_XCON3_INIT1TYPE_Msk & (_UINT32_(value) << SQI_XCON3_INIT1TYPE_Pos)) /* Assigment of value for INIT1TYPE in the SQI_XCON3 register */
#define SQI_XCON3_INIT1COUNT_Pos              _UINT32_(26)                                         /* (SQI_XCON3) 2bit SPI INIT1 Count. Indicates whether 1, 2 or 3 bytes of INIT1 Code value are being sent. Position */
#define SQI_XCON3_INIT1COUNT_Msk              (_UINT32_(0x3) << SQI_XCON3_INIT1COUNT_Pos)          /* (SQI_XCON3) 2bit SPI INIT1 Count. Indicates whether 1, 2 or 3 bytes of INIT1 Code value are being sent. Mask */
#define SQI_XCON3_INIT1COUNT(value)           (SQI_XCON3_INIT1COUNT_Msk & (_UINT32_(value) << SQI_XCON3_INIT1COUNT_Pos)) /* Assigment of value for INIT1COUNT in the SQI_XCON3 register */
#define SQI_XCON3_INIT1SCHECK_Pos             _UINT32_(28)                                         /* (SQI_XCON3) SPI Init1 Status Check: 0 - do not check status, 1 - check status. If this bit is set to 1, the hardware will issue the status command automatically after the current operation and wait for busy bit to clear. The hardware will issue the next command only after this Status check phase. Note: The Status Command will be formed according to the settings in the SPI Status Control Reg (@0x60) Position */
#define SQI_XCON3_INIT1SCHECK_Msk             (_UINT32_(0x1) << SQI_XCON3_INIT1SCHECK_Pos)         /* (SQI_XCON3) SPI Init1 Status Check: 0 - do not check status, 1 - check status. If this bit is set to 1, the hardware will issue the status command automatically after the current operation and wait for busy bit to clear. The hardware will issue the next command only after this Status check phase. Note: The Status Command will be formed according to the settings in the SPI Status Control Reg (@0x60) Mask */
#define SQI_XCON3_INIT1SCHECK(value)          (SQI_XCON3_INIT1SCHECK_Msk & (_UINT32_(value) << SQI_XCON3_INIT1SCHECK_Pos)) /* Assigment of value for INIT1SCHECK in the SQI_XCON3 register */
#define SQI_XCON3_Msk                         _UINT32_(0x1FFFFFFF)                                 /* (SQI_XCON3) Register Mask  */


/* -------- SQI_XCON4 : (SQI Offset: 0x168) (R/W 32) SPI XIP Control4 Register -------- */
#define SQI_XCON4_RESETVALUE                  _UINT32_(0x00)                                       /*  (SQI_XCON4) SPI XIP Control4 Register  Reset Value */

#define SQI_XCON4_INIT2CMD1_Pos               _UINT32_(0)                                          /* (SQI_XCON4) 8bit SPI Init2 Code1 value. Position */
#define SQI_XCON4_INIT2CMD1_Msk               (_UINT32_(0xFF) << SQI_XCON4_INIT2CMD1_Pos)          /* (SQI_XCON4) 8bit SPI Init2 Code1 value. Mask */
#define SQI_XCON4_INIT2CMD1(value)            (SQI_XCON4_INIT2CMD1_Msk & (_UINT32_(value) << SQI_XCON4_INIT2CMD1_Pos)) /* Assigment of value for INIT2CMD1 in the SQI_XCON4 register */
#define SQI_XCON4_INIT2CMD2_Pos               _UINT32_(8)                                          /* (SQI_XCON4) 8bit SPI Init2 Code2 value Position */
#define SQI_XCON4_INIT2CMD2_Msk               (_UINT32_(0xFF) << SQI_XCON4_INIT2CMD2_Pos)          /* (SQI_XCON4) 8bit SPI Init2 Code2 value Mask */
#define SQI_XCON4_INIT2CMD2(value)            (SQI_XCON4_INIT2CMD2_Msk & (_UINT32_(value) << SQI_XCON4_INIT2CMD2_Pos)) /* Assigment of value for INIT2CMD2 in the SQI_XCON4 register */
#define SQI_XCON4_INIT2CMD3_Pos               _UINT32_(16)                                         /* (SQI_XCON4) 8bit SPI Init2 Code3 value Position */
#define SQI_XCON4_INIT2CMD3_Msk               (_UINT32_(0xFF) << SQI_XCON4_INIT2CMD3_Pos)          /* (SQI_XCON4) 8bit SPI Init2 Code3 value Mask */
#define SQI_XCON4_INIT2CMD3(value)            (SQI_XCON4_INIT2CMD3_Msk & (_UINT32_(value) << SQI_XCON4_INIT2CMD3_Pos)) /* Assigment of value for INIT2CMD3 in the SQI_XCON4 register */
#define SQI_XCON4_INIT2TYPE_Pos               _UINT32_(24)                                         /* (SQI_XCON4) SPI TYPE INIT2:  00 - Single lane mode. 01 - Dual lane mode. 10 - Quad lane mode. 11 - Reserved for Future use. Based on this field, the boot controller will send the INIT2 Code in 1/2/4 lane. Position */
#define SQI_XCON4_INIT2TYPE_Msk               (_UINT32_(0x3) << SQI_XCON4_INIT2TYPE_Pos)           /* (SQI_XCON4) SPI TYPE INIT2:  00 - Single lane mode. 01 - Dual lane mode. 10 - Quad lane mode. 11 - Reserved for Future use. Based on this field, the boot controller will send the INIT2 Code in 1/2/4 lane. Mask */
#define SQI_XCON4_INIT2TYPE(value)            (SQI_XCON4_INIT2TYPE_Msk & (_UINT32_(value) << SQI_XCON4_INIT2TYPE_Pos)) /* Assigment of value for INIT2TYPE in the SQI_XCON4 register */
#define SQI_XCON4_INIT2COUNT_Pos              _UINT32_(26)                                         /* (SQI_XCON4) 2bit SPI INIT2 Count. Indicates whether 1, 2 or 3 bytes of INIT2 Code value are being sent. Position */
#define SQI_XCON4_INIT2COUNT_Msk              (_UINT32_(0x3) << SQI_XCON4_INIT2COUNT_Pos)          /* (SQI_XCON4) 2bit SPI INIT2 Count. Indicates whether 1, 2 or 3 bytes of INIT2 Code value are being sent. Mask */
#define SQI_XCON4_INIT2COUNT(value)           (SQI_XCON4_INIT2COUNT_Msk & (_UINT32_(value) << SQI_XCON4_INIT2COUNT_Pos)) /* Assigment of value for INIT2COUNT in the SQI_XCON4 register */
#define SQI_XCON4_INIT2SCHECK_Pos             _UINT32_(28)                                         /* (SQI_XCON4) SPI Init2 Status Check: 0 - do not check status 1 - check status If this bit is set to 1, the hardware will issue the status command automatically after thecurrent operation and wait for busy bit to clear. The hardware will issue the next command only after this Status check phase. Note: The Status Command will be formed according to the settings in the SPI Status  Control Reg (@0x60) Position */
#define SQI_XCON4_INIT2SCHECK_Msk             (_UINT32_(0x1) << SQI_XCON4_INIT2SCHECK_Pos)         /* (SQI_XCON4) SPI Init2 Status Check: 0 - do not check status 1 - check status If this bit is set to 1, the hardware will issue the status command automatically after thecurrent operation and wait for busy bit to clear. The hardware will issue the next command only after this Status check phase. Note: The Status Command will be formed according to the settings in the SPI Status  Control Reg (@0x60) Mask */
#define SQI_XCON4_INIT2SCHECK(value)          (SQI_XCON4_INIT2SCHECK_Msk & (_UINT32_(value) << SQI_XCON4_INIT2SCHECK_Pos)) /* Assigment of value for INIT2SCHECK in the SQI_XCON4 register */
#define SQI_XCON4_Msk                         _UINT32_(0x1FFFFFFF)                                 /* (SQI_XCON4) Register Mask  */


/** \brief SQI register offsets definitions */
#define SQI_BDCTRL_REG_OFST            _UINT32_(0x00)      /* (SQI_BDCTRL) Buffer Descriptor Control Register Offset */
#define SQI_BDSTATUS_REG_OFST          _UINT32_(0x04)      /* (SQI_BDSTATUS) Buffer Descriptor Status Register Offset */
#define SQI_BDADDR_REG_OFST            _UINT32_(0x08)      /* (SQI_BDADDR) Buffer Descriptor Address Register Offset */
#define SQI_BDNXTPTR_REG_OFST          _UINT32_(0x0C)      /* (SQI_BDNXTPTR) Buffer Descriptor Next Pointer Register Offset */
#define SQI_CTRLA_REG_OFST             _UINT32_(0x00)      /* (SQI_CTRLA) Control A register Offset */
#define SQI_INTENCLR_REG_OFST          _UINT32_(0x10)      /* (SQI_INTENCLR) Interrupt Enable Clear Register Offset */
#define SQI_INTENSET_REG_OFST          _UINT32_(0x14)      /* (SQI_INTENSET) Interrupt Enable Set Register Offset */
#define SQI_INTFLAG_REG_OFST           _UINT32_(0x18)      /* (SQI_INTFLAG) Interrupt Status and Clear Register Offset */
#define SQI_SYNCBUSY_REG_OFST          _UINT32_(0x20)      /* (SQI_SYNCBUSY) Syncbusy Register Offset */
#define SQI_XCON1_REG_OFST             _UINT32_(0x100)     /* (SQI_XCON1) SPI XIP Control1 register Offset */
#define SQI_XCON2_REG_OFST             _UINT32_(0x104)     /* (SQI_XCON2) SPI XIP Control2 register Offset */
#define SQI_CFG_REG_OFST               _UINT32_(0x108)     /* (SQI_CFG) SPI Configuration Register Offset */
#define SQI_CON_REG_OFST               _UINT32_(0x10C)     /* (SQI_CON) SPI Control register Offset */
#define SQI_CLKCON_REG_OFST            _UINT32_(0x110)     /* (SQI_CLKCON) SPI Clock Control register Offset */
#define SQI_CMDTHR_REG_OFST            _UINT32_(0x114)     /* (SQI_CMDTHR) SPI command threshold register Offset */
#define SQI_INTTHR_REG_OFST            _UINT32_(0x118)     /* (SQI_INTTHR) SPI Interrupt Threshold register Offset */
#define SQI_INTEN_REG_OFST             _UINT32_(0x11C)     /* (SQI_INTEN) SPI Interrupt Enable Register Offset */
#define SQI_INTSTAT_REG_OFST           _UINT32_(0x120)     /* (SQI_INTSTAT) SPI Interrupt Status Register Offset */
#define SQI_TXDATA_REG_OFST            _UINT32_(0x124)     /* (SQI_TXDATA) SPI Transmit Data Register Offset */
#define SQI_RXDATA_REG_OFST            _UINT32_(0x128)     /* (SQI_RXDATA) SPI Receive Data Register Offset */
#define SQI_STAT1_REG_OFST             _UINT32_(0x12C)     /* (SQI_STAT1) SPI Status1 Register Offset */
#define SQI_STAT2_REG_OFST             _UINT32_(0x130)     /* (SQI_STAT2) SPI status 2 register Offset */
#define SQI_BDCON_REG_OFST             _UINT32_(0x134)     /* (SQI_BDCON) BD_CTRL Register Offset */
#define SQI_BDCURADD_REG_OFST          _UINT32_(0x138)     /* (SQI_BDCURADD) BD_CURR_ADDR Register Offset */
#define SQI_BDBASEADD_REG_OFST         _UINT32_(0x140)     /* (SQI_BDBASEADD) BD_BASE_ADDR register Offset */
#define SQI_BDSTAT_REG_OFST            _UINT32_(0x144)     /* (SQI_BDSTAT) BD_STATUS Register Offset */
#define SQI_BDPOLLCON_REG_OFST         _UINT32_(0x148)     /* (SQI_BDPOLLCON) BD_POLL_CTRL Register Offset */
#define SQI_BDTXDSTAT_REG_OFST         _UINT32_(0x14C)     /* (SQI_BDTXDSTAT) BD_TX_DMA_STATUS Register Offset */
#define SQI_BDRXDSTAT_REG_OFST         _UINT32_(0x150)     /* (SQI_BDRXDSTAT) BD_RX_DMA_STATUS Register Offset */
#define SQI_THR_REG_OFST               _UINT32_(0x154)     /* (SQI_THR) SPI Control threshold register Offset */
#define SQI_INTSIGEN_REG_OFST          _UINT32_(0x158)     /* (SQI_INTSIGEN) SPI Interrupt Signal Enable Register Offset */
#define SQI_TAPCON_REG_OFST            _UINT32_(0x15C)     /* (SQI_TAPCON) Tap Control Register Offset */
#define SQI_MEMSTAT_REG_OFST           _UINT32_(0x160)     /* (SQI_MEMSTAT) SPI Status Control Register Offset */
#define SQI_XCON3_REG_OFST             _UINT32_(0x164)     /* (SQI_XCON3) SPI XIP Control 3 Register Offset */
#define SQI_XCON4_REG_OFST             _UINT32_(0x168)     /* (SQI_XCON4) SPI XIP Control4 Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief SQI_DESCRIPTOR register API structure */
typedef struct
{  /* Polaris Serial Quad Interface SIB */
  __IO  uint32_t                       SQI_BDCTRL;         /**< Offset: 0x00 (R/W  32) Buffer Descriptor Control Register */
  __IO  uint32_t                       SQI_BDSTATUS;       /**< Offset: 0x04 (R/W  32) Buffer Descriptor Status Register */
  __IO  uint32_t                       SQI_BDADDR;         /**< Offset: 0x08 (R/W  32) Buffer Descriptor Address Register */
  __IO  uint32_t                       SQI_BDNXTPTR;       /**< Offset: 0x0C (R/W  32) Buffer Descriptor Next Pointer Register */
} sqi_descriptor_registers_t
#ifdef __GNUC__
  __attribute__ ((aligned (4)))
#endif
;

/** \brief SQI register API structure */
typedef struct
{  /* Polaris Serial Quad Interface SIB */
  __IO  uint32_t                       SQI_CTRLA;          /**< Offset: 0x00 (R/W  32) Control A register */
  __I   uint8_t                        Reserved1[0x0C];
  __IO  uint32_t                       SQI_INTENCLR;       /**< Offset: 0x10 (R/W  32) Interrupt Enable Clear Register */
  __IO  uint32_t                       SQI_INTENSET;       /**< Offset: 0x14 (R/W  32) Interrupt Enable Set Register */
  __IO  uint32_t                       SQI_INTFLAG;        /**< Offset: 0x18 (R/W  32) Interrupt Status and Clear Register */
  __I   uint8_t                        Reserved2[0x04];
  __I   uint32_t                       SQI_SYNCBUSY;       /**< Offset: 0x20 (R/   32) Syncbusy Register */
  __I   uint8_t                        Reserved3[0xDC];
  __IO  uint32_t                       SQI_XCON1;          /**< Offset: 0x100 (R/W  32) SPI XIP Control1 register */
  __IO  uint32_t                       SQI_XCON2;          /**< Offset: 0x104 (R/W  32) SPI XIP Control2 register */
  __IO  uint32_t                       SQI_CFG;            /**< Offset: 0x108 (R/W  32) SPI Configuration Register */
  __IO  uint32_t                       SQI_CON;            /**< Offset: 0x10C (R/W  32) SPI Control register */
  __IO  uint32_t                       SQI_CLKCON;         /**< Offset: 0x110 (R/W  32) SPI Clock Control register */
  __IO  uint32_t                       SQI_CMDTHR;         /**< Offset: 0x114 (R/W  32) SPI command threshold register */
  __IO  uint32_t                       SQI_INTTHR;         /**< Offset: 0x118 (R/W  32) SPI Interrupt Threshold register */
  __IO  uint32_t                       SQI_INTEN;          /**< Offset: 0x11C (R/W  32) SPI Interrupt Enable Register */
  __IO  uint32_t                       SQI_INTSTAT;        /**< Offset: 0x120 (R/W  32) SPI Interrupt Status Register */
  __IO  uint32_t                       SQI_TXDATA;         /**< Offset: 0x124 (R/W  32) SPI Transmit Data Register */
  __I   uint32_t                       SQI_RXDATA;         /**< Offset: 0x128 (R/   32) SPI Receive Data Register */
  __I   uint32_t                       SQI_STAT1;          /**< Offset: 0x12C (R/   32) SPI Status1 Register */
  __I   uint32_t                       SQI_STAT2;          /**< Offset: 0x130 (R/   32) SPI status 2 register */
  __IO  uint32_t                       SQI_BDCON;          /**< Offset: 0x134 (R/W  32) BD_CTRL Register */
  __I   uint32_t                       SQI_BDCURADD;       /**< Offset: 0x138 (R/   32) BD_CURR_ADDR Register */
  __I   uint8_t                        Reserved4[0x04];
  __IO  uint32_t                       SQI_BDBASEADD;      /**< Offset: 0x140 (R/W  32) BD_BASE_ADDR register */
  __I   uint32_t                       SQI_BDSTAT;         /**< Offset: 0x144 (R/   32) BD_STATUS Register */
  __IO  uint32_t                       SQI_BDPOLLCON;      /**< Offset: 0x148 (R/W  32) BD_POLL_CTRL Register */
  __IO  uint32_t                       SQI_BDTXDSTAT;      /**< Offset: 0x14C (R/W  32) BD_TX_DMA_STATUS Register */
  __I   uint32_t                       SQI_BDRXDSTAT;      /**< Offset: 0x150 (R/   32) BD_RX_DMA_STATUS Register */
  __IO  uint32_t                       SQI_THR;            /**< Offset: 0x154 (R/W  32) SPI Control threshold register */
  __IO  uint32_t                       SQI_INTSIGEN;       /**< Offset: 0x158 (R/W  32) SPI Interrupt Signal Enable Register */
  __IO  uint32_t                       SQI_TAPCON;         /**< Offset: 0x15C (R/W  32) Tap Control Register */
  __IO  uint32_t                       SQI_MEMSTAT;        /**< Offset: 0x160 (R/W  32) SPI Status Control Register */
  __IO  uint32_t                       SQI_XCON3;          /**< Offset: 0x164 (R/W  32) SPI XIP Control 3 Register */
  __IO  uint32_t                       SQI_XCON4;          /**< Offset: 0x168 (R/W  32) SPI XIP Control4 Register */
} sqi_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** \brief SQI_DESCRIPTOR memory section attribute */
#if defined (__GNUC__) || defined (__CC_ARM)
 #define SECTION_SQI_DESCRIPTOR       __attribute__ ((section(".flexram")))
#elif defined (__ICCARM__)
 #define SECTION_SQI_DESCRIPTOR       @".flexram"
#else
 #ifndef SECTION_SQI_DESCRIPTOR
  #error SECTION_SQI_DESCRIPTOR must be defined for compiler to use memory section .flexram
 #endif
#endif

#endif /* _PIC32CZCA80_SQI_COMPONENT_H_ */
