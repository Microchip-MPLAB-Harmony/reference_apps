/*
 * Component description for FCW
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
#ifndef _PIC32CZCA90_FCW_COMPONENT_H_
#define _PIC32CZCA90_FCW_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR FCW                                          */
/* ************************************************************************** */

/* -------- FCW_CTRLA : (FCW Offset: 0x00) (R/W 32) NVM Write Control Register -------- */
#define FCW_CTRLA_RESETVALUE                  _UINT32_(0x00)                                       /*  (FCW_CTRLA) NVM Write Control Register  Reset Value */

#define FCW_CTRLA_NVMOP_Pos                   _UINT32_(0)                                          /* (FCW_CTRLA) NVM Operation Position */
#define FCW_CTRLA_NVMOP_Msk                   (_UINT32_(0xF) << FCW_CTRLA_NVMOP_Pos)               /* (FCW_CTRLA) NVM Operation Mask */
#define FCW_CTRLA_NVMOP(value)                (FCW_CTRLA_NVMOP_Msk & (_UINT32_(value) << FCW_CTRLA_NVMOP_Pos)) /* Assigment of value for NVMOP in the FCW_CTRLA register */
#define FCW_CTRLA_PREPG_Pos                   _UINT32_(7)                                          /* (FCW_CTRLA) NVM Pre-Program Configuration Bit Position */
#define FCW_CTRLA_PREPG_Msk                   (_UINT32_(0x1) << FCW_CTRLA_PREPG_Pos)               /* (FCW_CTRLA) NVM Pre-Program Configuration Bit Mask */
#define FCW_CTRLA_PREPG(value)                (FCW_CTRLA_PREPG_Msk & (_UINT32_(value) << FCW_CTRLA_PREPG_Pos)) /* Assigment of value for PREPG in the FCW_CTRLA register */
#define FCW_CTRLA_Msk                         _UINT32_(0x0000008F)                                 /* (FCW_CTRLA) Register Mask  */


/* -------- FCW_CTRLB : (FCW Offset: 0x04) (R/W 32) NVM Control B Register -------- */
#define FCW_CTRLB_RESETVALUE                  _UINT32_(0xFF)                                       /*  (FCW_CTRLB) NVM Control B Register  Reset Value */

#define FCW_CTRLB_SDALCPU0_Pos                _UINT32_(0)                                          /* (FCW_CTRLB) Set DAL for CPU n Position */
#define FCW_CTRLB_SDALCPU0_Msk                (_UINT32_(0x3) << FCW_CTRLB_SDALCPU0_Pos)            /* (FCW_CTRLB) Set DAL for CPU n Mask */
#define FCW_CTRLB_SDALCPU0(value)             (FCW_CTRLB_SDALCPU0_Msk & (_UINT32_(value) << FCW_CTRLB_SDALCPU0_Pos)) /* Assigment of value for SDALCPU0 in the FCW_CTRLB register */
#define FCW_CTRLB_SDALCPU1_Pos                _UINT32_(2)                                          /* (FCW_CTRLB) Set DAL for CPU n Position */
#define FCW_CTRLB_SDALCPU1_Msk                (_UINT32_(0x3) << FCW_CTRLB_SDALCPU1_Pos)            /* (FCW_CTRLB) Set DAL for CPU n Mask */
#define FCW_CTRLB_SDALCPU1(value)             (FCW_CTRLB_SDALCPU1_Msk & (_UINT32_(value) << FCW_CTRLB_SDALCPU1_Pos)) /* Assigment of value for SDALCPU1 in the FCW_CTRLB register */
#define FCW_CTRLB_SDALCPU2_Pos                _UINT32_(4)                                          /* (FCW_CTRLB) Set DAL for CPU n Position */
#define FCW_CTRLB_SDALCPU2_Msk                (_UINT32_(0x3) << FCW_CTRLB_SDALCPU2_Pos)            /* (FCW_CTRLB) Set DAL for CPU n Mask */
#define FCW_CTRLB_SDALCPU2(value)             (FCW_CTRLB_SDALCPU2_Msk & (_UINT32_(value) << FCW_CTRLB_SDALCPU2_Pos)) /* Assigment of value for SDALCPU2 in the FCW_CTRLB register */
#define FCW_CTRLB_SDALCPU3_Pos                _UINT32_(6)                                          /* (FCW_CTRLB) Set DAL for CPU n Position */
#define FCW_CTRLB_SDALCPU3_Msk                (_UINT32_(0x3) << FCW_CTRLB_SDALCPU3_Pos)            /* (FCW_CTRLB) Set DAL for CPU n Mask */
#define FCW_CTRLB_SDALCPU3(value)             (FCW_CTRLB_SDALCPU3_Msk & (_UINT32_(value) << FCW_CTRLB_SDALCPU3_Pos)) /* Assigment of value for SDALCPU3 in the FCW_CTRLB register */
#define FCW_CTRLB_Msk                         _UINT32_(0x000000FF)                                 /* (FCW_CTRLB) Register Mask  */


/* -------- FCW_MUTEX : (FCW Offset: 0x08) (R/W 32) NVM MUTEX Register -------- */
#define FCW_MUTEX_RESETVALUE                  _UINT32_(0x00)                                       /*  (FCW_MUTEX) NVM MUTEX Register  Reset Value */

#define FCW_MUTEX_LOCK_Pos                    _UINT32_(0)                                          /* (FCW_MUTEX) Flash Write Controller (FCW) Lock by Owner Position */
#define FCW_MUTEX_LOCK_Msk                    (_UINT32_(0x1) << FCW_MUTEX_LOCK_Pos)                /* (FCW_MUTEX) Flash Write Controller (FCW) Lock by Owner Mask */
#define FCW_MUTEX_LOCK(value)                 (FCW_MUTEX_LOCK_Msk & (_UINT32_(value) << FCW_MUTEX_LOCK_Pos)) /* Assigment of value for LOCK in the FCW_MUTEX register */
#define FCW_MUTEX_OWNER_Pos                   _UINT32_(1)                                          /* (FCW_MUTEX) Flash Write Controller (FCW) Owner ID Position */
#define FCW_MUTEX_OWNER_Msk                   (_UINT32_(0x3) << FCW_MUTEX_OWNER_Pos)               /* (FCW_MUTEX) Flash Write Controller (FCW) Owner ID Mask */
#define FCW_MUTEX_OWNER(value)                (FCW_MUTEX_OWNER_Msk & (_UINT32_(value) << FCW_MUTEX_OWNER_Pos)) /* Assigment of value for OWNER in the FCW_MUTEX register */
#define FCW_MUTEX_Msk                         _UINT32_(0x00000007)                                 /* (FCW_MUTEX) Register Mask  */


/* -------- FCW_INTENCLR : (FCW Offset: 0x0C) (R/W 32) NVM Interrupt Enable Clear Register -------- */
#define FCW_INTENCLR_RESETVALUE               _UINT32_(0x00)                                       /*  (FCW_INTENCLR) NVM Interrupt Enable Clear Register  Reset Value */

#define FCW_INTENCLR_DONE_Pos                 _UINT32_(0)                                          /* (FCW_INTENCLR) NVM Operation Done Interrupt Enable Bit Position */
#define FCW_INTENCLR_DONE_Msk                 (_UINT32_(0x1) << FCW_INTENCLR_DONE_Pos)             /* (FCW_INTENCLR) NVM Operation Done Interrupt Enable Bit Mask */
#define FCW_INTENCLR_DONE(value)              (FCW_INTENCLR_DONE_Msk & (_UINT32_(value) << FCW_INTENCLR_DONE_Pos)) /* Assigment of value for DONE in the FCW_INTENCLR register */
#define FCW_INTENCLR_KEYERR_Pos               _UINT32_(1)                                          /* (FCW_INTENCLR) Key Error Interrupt Enable Bit Position */
#define FCW_INTENCLR_KEYERR_Msk               (_UINT32_(0x1) << FCW_INTENCLR_KEYERR_Pos)           /* (FCW_INTENCLR) Key Error Interrupt Enable Bit Mask */
#define FCW_INTENCLR_KEYERR(value)            (FCW_INTENCLR_KEYERR_Msk & (_UINT32_(value) << FCW_INTENCLR_KEYERR_Pos)) /* Assigment of value for KEYERR in the FCW_INTENCLR register */
#define FCW_INTENCLR_CFGERR_Pos               _UINT32_(2)                                          /* (FCW_INTENCLR) Configuration Error Interrupt Enable Bit Position */
#define FCW_INTENCLR_CFGERR_Msk               (_UINT32_(0x1) << FCW_INTENCLR_CFGERR_Pos)           /* (FCW_INTENCLR) Configuration Error Interrupt Enable Bit Mask */
#define FCW_INTENCLR_CFGERR(value)            (FCW_INTENCLR_CFGERR_Msk & (_UINT32_(value) << FCW_INTENCLR_CFGERR_Pos)) /* Assigment of value for CFGERR in the FCW_INTENCLR register */
#define FCW_INTENCLR_FIFOERR_Pos              _UINT32_(3)                                          /* (FCW_INTENCLR) FIFO Underrun during Row Write Interrupt Enable Bit Position */
#define FCW_INTENCLR_FIFOERR_Msk              (_UINT32_(0x1) << FCW_INTENCLR_FIFOERR_Pos)          /* (FCW_INTENCLR) FIFO Underrun during Row Write Interrupt Enable Bit Mask */
#define FCW_INTENCLR_FIFOERR(value)           (FCW_INTENCLR_FIFOERR_Msk & (_UINT32_(value) << FCW_INTENCLR_FIFOERR_Pos)) /* Assigment of value for FIFOERR in the FCW_INTENCLR register */
#define FCW_INTENCLR_BUSERR_Pos               _UINT32_(4)                                          /* (FCW_INTENCLR) AHB Bus Error during Row Write Interrupt Enable Bit Position */
#define FCW_INTENCLR_BUSERR_Msk               (_UINT32_(0x1) << FCW_INTENCLR_BUSERR_Pos)           /* (FCW_INTENCLR) AHB Bus Error during Row Write Interrupt Enable Bit Mask */
#define FCW_INTENCLR_BUSERR(value)            (FCW_INTENCLR_BUSERR_Msk & (_UINT32_(value) << FCW_INTENCLR_BUSERR_Pos)) /* Assigment of value for BUSERR in the FCW_INTENCLR register */
#define FCW_INTENCLR_WPERR_Pos                _UINT32_(5)                                          /* (FCW_INTENCLR) Write Protection Error Interrupt Enable Bit Position */
#define FCW_INTENCLR_WPERR_Msk                (_UINT32_(0x1) << FCW_INTENCLR_WPERR_Pos)            /* (FCW_INTENCLR) Write Protection Error Interrupt Enable Bit Mask */
#define FCW_INTENCLR_WPERR(value)             (FCW_INTENCLR_WPERR_Msk & (_UINT32_(value) << FCW_INTENCLR_WPERR_Pos)) /* Assigment of value for WPERR in the FCW_INTENCLR register */
#define FCW_INTENCLR_OPERR_Pos                _UINT32_(6)                                          /* (FCW_INTENCLR) NVMOP Error Interrupt Enable Bit Position */
#define FCW_INTENCLR_OPERR_Msk                (_UINT32_(0x1) << FCW_INTENCLR_OPERR_Pos)            /* (FCW_INTENCLR) NVMOP Error Interrupt Enable Bit Mask */
#define FCW_INTENCLR_OPERR(value)             (FCW_INTENCLR_OPERR_Msk & (_UINT32_(value) << FCW_INTENCLR_OPERR_Pos)) /* Assigment of value for OPERR in the FCW_INTENCLR register */
#define FCW_INTENCLR_SECERR_Pos               _UINT32_(7)                                          /* (FCW_INTENCLR) Security Violation Error Interrupt Enable Bit Position */
#define FCW_INTENCLR_SECERR_Msk               (_UINT32_(0x1) << FCW_INTENCLR_SECERR_Pos)           /* (FCW_INTENCLR) Security Violation Error Interrupt Enable Bit Mask */
#define FCW_INTENCLR_SECERR(value)            (FCW_INTENCLR_SECERR_Msk & (_UINT32_(value) << FCW_INTENCLR_SECERR_Pos)) /* Assigment of value for SECERR in the FCW_INTENCLR register */
#define FCW_INTENCLR_HTDPGM_Pos               _UINT32_(8)                                          /* (FCW_INTENCLR) High Temperature Detect Error Interrupt Enable Bit Position */
#define FCW_INTENCLR_HTDPGM_Msk               (_UINT32_(0x1) << FCW_INTENCLR_HTDPGM_Pos)           /* (FCW_INTENCLR) High Temperature Detect Error Interrupt Enable Bit Mask */
#define FCW_INTENCLR_HTDPGM(value)            (FCW_INTENCLR_HTDPGM_Msk & (_UINT32_(value) << FCW_INTENCLR_HTDPGM_Pos)) /* Assigment of value for HTDPGM in the FCW_INTENCLR register */
#define FCW_INTENCLR_BORERR_Pos               _UINT32_(12)                                         /* (FCW_INTENCLR) Brown Out Detect Error Interrupt Enable Bit Position */
#define FCW_INTENCLR_BORERR_Msk               (_UINT32_(0x1) << FCW_INTENCLR_BORERR_Pos)           /* (FCW_INTENCLR) Brown Out Detect Error Interrupt Enable Bit Mask */
#define FCW_INTENCLR_BORERR(value)            (FCW_INTENCLR_BORERR_Msk & (_UINT32_(value) << FCW_INTENCLR_BORERR_Pos)) /* Assigment of value for BORERR in the FCW_INTENCLR register */
#define FCW_INTENCLR_WRERR_Pos                _UINT32_(13)                                         /* (FCW_INTENCLR) Write Error Interrupt Enable Bit Position */
#define FCW_INTENCLR_WRERR_Msk                (_UINT32_(0x1) << FCW_INTENCLR_WRERR_Pos)            /* (FCW_INTENCLR) Write Error Interrupt Enable Bit Mask */
#define FCW_INTENCLR_WRERR(value)             (FCW_INTENCLR_WRERR_Msk & (_UINT32_(value) << FCW_INTENCLR_WRERR_Pos)) /* Assigment of value for WRERR in the FCW_INTENCLR register */
#define FCW_INTENCLR_Msk                      _UINT32_(0x000031FF)                                 /* (FCW_INTENCLR) Register Mask  */


/* -------- FCW_INTENSET : (FCW Offset: 0x10) (R/W 32) NVM Interrupt Enable SET Register -------- */
#define FCW_INTENSET_RESETVALUE               _UINT32_(0x00)                                       /*  (FCW_INTENSET) NVM Interrupt Enable SET Register  Reset Value */

#define FCW_INTENSET_DONE_Pos                 _UINT32_(0)                                          /* (FCW_INTENSET) NVM Operation Done Interrupt Enable Bit Position */
#define FCW_INTENSET_DONE_Msk                 (_UINT32_(0x1) << FCW_INTENSET_DONE_Pos)             /* (FCW_INTENSET) NVM Operation Done Interrupt Enable Bit Mask */
#define FCW_INTENSET_DONE(value)              (FCW_INTENSET_DONE_Msk & (_UINT32_(value) << FCW_INTENSET_DONE_Pos)) /* Assigment of value for DONE in the FCW_INTENSET register */
#define FCW_INTENSET_KEYERR_Pos               _UINT32_(1)                                          /* (FCW_INTENSET) Key Error Interrupt Enable Bit Position */
#define FCW_INTENSET_KEYERR_Msk               (_UINT32_(0x1) << FCW_INTENSET_KEYERR_Pos)           /* (FCW_INTENSET) Key Error Interrupt Enable Bit Mask */
#define FCW_INTENSET_KEYERR(value)            (FCW_INTENSET_KEYERR_Msk & (_UINT32_(value) << FCW_INTENSET_KEYERR_Pos)) /* Assigment of value for KEYERR in the FCW_INTENSET register */
#define FCW_INTENSET_CFGERR_Pos               _UINT32_(2)                                          /* (FCW_INTENSET) Configuration Error Interrupt Enable Bit Position */
#define FCW_INTENSET_CFGERR_Msk               (_UINT32_(0x1) << FCW_INTENSET_CFGERR_Pos)           /* (FCW_INTENSET) Configuration Error Interrupt Enable Bit Mask */
#define FCW_INTENSET_CFGERR(value)            (FCW_INTENSET_CFGERR_Msk & (_UINT32_(value) << FCW_INTENSET_CFGERR_Pos)) /* Assigment of value for CFGERR in the FCW_INTENSET register */
#define FCW_INTENSET_FIFOERR_Pos              _UINT32_(3)                                          /* (FCW_INTENSET) FIFO Underrun during Row Write Interrupt Enable Bit Position */
#define FCW_INTENSET_FIFOERR_Msk              (_UINT32_(0x1) << FCW_INTENSET_FIFOERR_Pos)          /* (FCW_INTENSET) FIFO Underrun during Row Write Interrupt Enable Bit Mask */
#define FCW_INTENSET_FIFOERR(value)           (FCW_INTENSET_FIFOERR_Msk & (_UINT32_(value) << FCW_INTENSET_FIFOERR_Pos)) /* Assigment of value for FIFOERR in the FCW_INTENSET register */
#define FCW_INTENSET_BUSERR_Pos               _UINT32_(4)                                          /* (FCW_INTENSET) AHB Bus Error during Row Write Interrupt Enable Bit Position */
#define FCW_INTENSET_BUSERR_Msk               (_UINT32_(0x1) << FCW_INTENSET_BUSERR_Pos)           /* (FCW_INTENSET) AHB Bus Error during Row Write Interrupt Enable Bit Mask */
#define FCW_INTENSET_BUSERR(value)            (FCW_INTENSET_BUSERR_Msk & (_UINT32_(value) << FCW_INTENSET_BUSERR_Pos)) /* Assigment of value for BUSERR in the FCW_INTENSET register */
#define FCW_INTENSET_WPERR_Pos                _UINT32_(5)                                          /* (FCW_INTENSET) Write Protection Error Interrupt Enable Bit Position */
#define FCW_INTENSET_WPERR_Msk                (_UINT32_(0x1) << FCW_INTENSET_WPERR_Pos)            /* (FCW_INTENSET) Write Protection Error Interrupt Enable Bit Mask */
#define FCW_INTENSET_WPERR(value)             (FCW_INTENSET_WPERR_Msk & (_UINT32_(value) << FCW_INTENSET_WPERR_Pos)) /* Assigment of value for WPERR in the FCW_INTENSET register */
#define FCW_INTENSET_OPERR_Pos                _UINT32_(6)                                          /* (FCW_INTENSET) NVMOP Error Interrupt Enable Bit Position */
#define FCW_INTENSET_OPERR_Msk                (_UINT32_(0x1) << FCW_INTENSET_OPERR_Pos)            /* (FCW_INTENSET) NVMOP Error Interrupt Enable Bit Mask */
#define FCW_INTENSET_OPERR(value)             (FCW_INTENSET_OPERR_Msk & (_UINT32_(value) << FCW_INTENSET_OPERR_Pos)) /* Assigment of value for OPERR in the FCW_INTENSET register */
#define FCW_INTENSET_SECERR_Pos               _UINT32_(7)                                          /* (FCW_INTENSET) Security Violation Error Interrupt Enable Bit Position */
#define FCW_INTENSET_SECERR_Msk               (_UINT32_(0x1) << FCW_INTENSET_SECERR_Pos)           /* (FCW_INTENSET) Security Violation Error Interrupt Enable Bit Mask */
#define FCW_INTENSET_SECERR(value)            (FCW_INTENSET_SECERR_Msk & (_UINT32_(value) << FCW_INTENSET_SECERR_Pos)) /* Assigment of value for SECERR in the FCW_INTENSET register */
#define FCW_INTENSET_HTDPGM_Pos               _UINT32_(8)                                          /* (FCW_INTENSET) High Temperature Detect Error Interrupt Enable Bit Position */
#define FCW_INTENSET_HTDPGM_Msk               (_UINT32_(0x1) << FCW_INTENSET_HTDPGM_Pos)           /* (FCW_INTENSET) High Temperature Detect Error Interrupt Enable Bit Mask */
#define FCW_INTENSET_HTDPGM(value)            (FCW_INTENSET_HTDPGM_Msk & (_UINT32_(value) << FCW_INTENSET_HTDPGM_Pos)) /* Assigment of value for HTDPGM in the FCW_INTENSET register */
#define FCW_INTENSET_BORERR_Pos               _UINT32_(12)                                         /* (FCW_INTENSET) Brown Out Detect Error Interrupt Enable Bit Position */
#define FCW_INTENSET_BORERR_Msk               (_UINT32_(0x1) << FCW_INTENSET_BORERR_Pos)           /* (FCW_INTENSET) Brown Out Detect Error Interrupt Enable Bit Mask */
#define FCW_INTENSET_BORERR(value)            (FCW_INTENSET_BORERR_Msk & (_UINT32_(value) << FCW_INTENSET_BORERR_Pos)) /* Assigment of value for BORERR in the FCW_INTENSET register */
#define FCW_INTENSET_WRERR_Pos                _UINT32_(13)                                         /* (FCW_INTENSET) Write Error Interrupt Enable Bit Position */
#define FCW_INTENSET_WRERR_Msk                (_UINT32_(0x1) << FCW_INTENSET_WRERR_Pos)            /* (FCW_INTENSET) Write Error Interrupt Enable Bit Mask */
#define FCW_INTENSET_WRERR(value)             (FCW_INTENSET_WRERR_Msk & (_UINT32_(value) << FCW_INTENSET_WRERR_Pos)) /* Assigment of value for WRERR in the FCW_INTENSET register */
#define FCW_INTENSET_Msk                      _UINT32_(0x000031FF)                                 /* (FCW_INTENSET) Register Mask  */


/* -------- FCW_INTFLAG : (FCW Offset: 0x14) (R/W 32) NVM Interrupt Flag Register -------- */
#define FCW_INTFLAG_RESETVALUE                _UINT32_(0x00)                                       /*  (FCW_INTFLAG) NVM Interrupt Flag Register  Reset Value */

#define FCW_INTFLAG_DONE_Pos                  _UINT32_(0)                                          /* (FCW_INTFLAG) NVM Operation Done Flag Bit Position */
#define FCW_INTFLAG_DONE_Msk                  (_UINT32_(0x1) << FCW_INTFLAG_DONE_Pos)              /* (FCW_INTFLAG) NVM Operation Done Flag Bit Mask */
#define FCW_INTFLAG_DONE(value)               (FCW_INTFLAG_DONE_Msk & (_UINT32_(value) << FCW_INTFLAG_DONE_Pos)) /* Assigment of value for DONE in the FCW_INTFLAG register */
#define FCW_INTFLAG_KEYERR_Pos                _UINT32_(1)                                          /* (FCW_INTFLAG) Key Error Flag Bit Position */
#define FCW_INTFLAG_KEYERR_Msk                (_UINT32_(0x1) << FCW_INTFLAG_KEYERR_Pos)            /* (FCW_INTFLAG) Key Error Flag Bit Mask */
#define FCW_INTFLAG_KEYERR(value)             (FCW_INTFLAG_KEYERR_Msk & (_UINT32_(value) << FCW_INTFLAG_KEYERR_Pos)) /* Assigment of value for KEYERR in the FCW_INTFLAG register */
#define FCW_INTFLAG_CFGERR_Pos                _UINT32_(2)                                          /* (FCW_INTFLAG) Configuration Error Flag Bit Position */
#define FCW_INTFLAG_CFGERR_Msk                (_UINT32_(0x1) << FCW_INTFLAG_CFGERR_Pos)            /* (FCW_INTFLAG) Configuration Error Flag Bit Mask */
#define FCW_INTFLAG_CFGERR(value)             (FCW_INTFLAG_CFGERR_Msk & (_UINT32_(value) << FCW_INTFLAG_CFGERR_Pos)) /* Assigment of value for CFGERR in the FCW_INTFLAG register */
#define FCW_INTFLAG_FIFOERR_Pos               _UINT32_(3)                                          /* (FCW_INTFLAG) FIFO Underrun during Row Write Flag Bit Position */
#define FCW_INTFLAG_FIFOERR_Msk               (_UINT32_(0x1) << FCW_INTFLAG_FIFOERR_Pos)           /* (FCW_INTFLAG) FIFO Underrun during Row Write Flag Bit Mask */
#define FCW_INTFLAG_FIFOERR(value)            (FCW_INTFLAG_FIFOERR_Msk & (_UINT32_(value) << FCW_INTFLAG_FIFOERR_Pos)) /* Assigment of value for FIFOERR in the FCW_INTFLAG register */
#define FCW_INTFLAG_BUSERR_Pos                _UINT32_(4)                                          /* (FCW_INTFLAG) AHB Bus Error during Row Write Flag Bit Position */
#define FCW_INTFLAG_BUSERR_Msk                (_UINT32_(0x1) << FCW_INTFLAG_BUSERR_Pos)            /* (FCW_INTFLAG) AHB Bus Error during Row Write Flag Bit Mask */
#define FCW_INTFLAG_BUSERR(value)             (FCW_INTFLAG_BUSERR_Msk & (_UINT32_(value) << FCW_INTFLAG_BUSERR_Pos)) /* Assigment of value for BUSERR in the FCW_INTFLAG register */
#define FCW_INTFLAG_WPERR_Pos                 _UINT32_(5)                                          /* (FCW_INTFLAG) Write Protection Error Flag Bit Position */
#define FCW_INTFLAG_WPERR_Msk                 (_UINT32_(0x1) << FCW_INTFLAG_WPERR_Pos)             /* (FCW_INTFLAG) Write Protection Error Flag Bit Mask */
#define FCW_INTFLAG_WPERR(value)              (FCW_INTFLAG_WPERR_Msk & (_UINT32_(value) << FCW_INTFLAG_WPERR_Pos)) /* Assigment of value for WPERR in the FCW_INTFLAG register */
#define FCW_INTFLAG_OPERR_Pos                 _UINT32_(6)                                          /* (FCW_INTFLAG) NVMOP Error Flag Bit Position */
#define FCW_INTFLAG_OPERR_Msk                 (_UINT32_(0x1) << FCW_INTFLAG_OPERR_Pos)             /* (FCW_INTFLAG) NVMOP Error Flag Bit Mask */
#define FCW_INTFLAG_OPERR(value)              (FCW_INTFLAG_OPERR_Msk & (_UINT32_(value) << FCW_INTFLAG_OPERR_Pos)) /* Assigment of value for OPERR in the FCW_INTFLAG register */
#define FCW_INTFLAG_SECERR_Pos                _UINT32_(7)                                          /* (FCW_INTFLAG) Security Violation Error Bit Position */
#define FCW_INTFLAG_SECERR_Msk                (_UINT32_(0x1) << FCW_INTFLAG_SECERR_Pos)            /* (FCW_INTFLAG) Security Violation Error Bit Mask */
#define FCW_INTFLAG_SECERR(value)             (FCW_INTFLAG_SECERR_Msk & (_UINT32_(value) << FCW_INTFLAG_SECERR_Pos)) /* Assigment of value for SECERR in the FCW_INTFLAG register */
#define FCW_INTFLAG_HTDPGM_Pos                _UINT32_(8)                                          /* (FCW_INTFLAG) High Temperature Detect Error Flag Bit Position */
#define FCW_INTFLAG_HTDPGM_Msk                (_UINT32_(0x1) << FCW_INTFLAG_HTDPGM_Pos)            /* (FCW_INTFLAG) High Temperature Detect Error Flag Bit Mask */
#define FCW_INTFLAG_HTDPGM(value)             (FCW_INTFLAG_HTDPGM_Msk & (_UINT32_(value) << FCW_INTFLAG_HTDPGM_Pos)) /* Assigment of value for HTDPGM in the FCW_INTFLAG register */
#define FCW_INTFLAG_BORERR_Pos                _UINT32_(12)                                         /* (FCW_INTFLAG) Brown Out Detect Error Flag Bit Position */
#define FCW_INTFLAG_BORERR_Msk                (_UINT32_(0x1) << FCW_INTFLAG_BORERR_Pos)            /* (FCW_INTFLAG) Brown Out Detect Error Flag Bit Mask */
#define FCW_INTFLAG_BORERR(value)             (FCW_INTFLAG_BORERR_Msk & (_UINT32_(value) << FCW_INTFLAG_BORERR_Pos)) /* Assigment of value for BORERR in the FCW_INTFLAG register */
#define FCW_INTFLAG_WRERR_Pos                 _UINT32_(13)                                         /* (FCW_INTFLAG) Write Error Flag Bit Position */
#define FCW_INTFLAG_WRERR_Msk                 (_UINT32_(0x1) << FCW_INTFLAG_WRERR_Pos)             /* (FCW_INTFLAG) Write Error Flag Bit Mask */
#define FCW_INTFLAG_WRERR(value)              (FCW_INTFLAG_WRERR_Msk & (_UINT32_(value) << FCW_INTFLAG_WRERR_Pos)) /* Assigment of value for WRERR in the FCW_INTFLAG register */
#define FCW_INTFLAG_Msk                       _UINT32_(0x000031FF)                                 /* (FCW_INTFLAG) Register Mask  */


/* -------- FCW_STATUS : (FCW Offset: 0x18) (R/W 32) NVM Status Register -------- */
#define FCW_STATUS_RESETVALUE                 _UINT32_(0x00)                                       /*  (FCW_STATUS) NVM Status Register  Reset Value */

#define FCW_STATUS_BUSY_Pos                   _UINT32_(0)                                          /* (FCW_STATUS) NVM Busy Status Position */
#define FCW_STATUS_BUSY_Msk                   (_UINT32_(0x1) << FCW_STATUS_BUSY_Pos)               /* (FCW_STATUS) NVM Busy Status Mask */
#define FCW_STATUS_BUSY(value)                (FCW_STATUS_BUSY_Msk & (_UINT32_(value) << FCW_STATUS_BUSY_Pos)) /* Assigment of value for BUSY in the FCW_STATUS register */
#define FCW_STATUS_HTDRDY_Pos                 _UINT32_(8)                                          /* (FCW_STATUS) High Temp Detect Ready Status Position */
#define FCW_STATUS_HTDRDY_Msk                 (_UINT32_(0x1) << FCW_STATUS_HTDRDY_Pos)             /* (FCW_STATUS) High Temp Detect Ready Status Mask */
#define FCW_STATUS_HTDRDY(value)              (FCW_STATUS_HTDRDY_Msk & (_UINT32_(value) << FCW_STATUS_HTDRDY_Pos)) /* Assigment of value for HTDRDY in the FCW_STATUS register */
#define FCW_STATUS_Msk                        _UINT32_(0x00000101)                                 /* (FCW_STATUS) Register Mask  */


/* -------- FCW_KEY : (FCW Offset: 0x1C) (R/W 32) SFR Unlock Register -------- */
#define FCW_KEY_RESETVALUE                    _UINT32_(0x00)                                       /*  (FCW_KEY) SFR Unlock Register  Reset Value */

#define FCW_KEY_KEYVALUE_Pos                  _UINT32_(0)                                          /* (FCW_KEY) NVM SFR Key Value Position */
#define FCW_KEY_KEYVALUE_Msk                  (_UINT32_(0xFF) << FCW_KEY_KEYVALUE_Pos)             /* (FCW_KEY) NVM SFR Key Value Mask */
#define FCW_KEY_KEYVALUE(value)               (FCW_KEY_KEYVALUE_Msk & (_UINT32_(value) << FCW_KEY_KEYVALUE_Pos)) /* Assigment of value for KEYVALUE in the FCW_KEY register */
#define FCW_KEY_KEYCODE_Pos                   _UINT32_(8)                                          /* (FCW_KEY) NVM SFR Key Code Position */
#define FCW_KEY_KEYCODE_Msk                   (_UINT32_(0xFFFFFF) << FCW_KEY_KEYCODE_Pos)          /* (FCW_KEY) NVM SFR Key Code Mask */
#define FCW_KEY_KEYCODE(value)                (FCW_KEY_KEYCODE_Msk & (_UINT32_(value) << FCW_KEY_KEYCODE_Pos)) /* Assigment of value for KEYCODE in the FCW_KEY register */
#define FCW_KEY_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (FCW_KEY) Register Mask  */


/* -------- FCW_ADDR : (FCW Offset: 0x20) (R/W 32) Flash Address Register -------- */
#define FCW_ADDR_RESETVALUE                   _UINT32_(0x00)                                       /*  (FCW_ADDR) Flash Address Register  Reset Value */

#define FCW_ADDR_ADDR_Pos                     _UINT32_(2)                                          /* (FCW_ADDR) Flash Address used by NVMOP Position */
#define FCW_ADDR_ADDR_Msk                     (_UINT32_(0x3FFFFFFF) << FCW_ADDR_ADDR_Pos)          /* (FCW_ADDR) Flash Address used by NVMOP Mask */
#define FCW_ADDR_ADDR(value)                  (FCW_ADDR_ADDR_Msk & (_UINT32_(value) << FCW_ADDR_ADDR_Pos)) /* Assigment of value for ADDR in the FCW_ADDR register */
#define FCW_ADDR_Msk                          _UINT32_(0xFFFFFFFC)                                 /* (FCW_ADDR) Register Mask  */


/* -------- FCW_SRCADDR : (FCW Offset: 0x24) (R/W 32) Source Data Address Register -------- */
#define FCW_SRCADDR_RESETVALUE                _UINT32_(0x00)                                       /*  (FCW_SRCADDR) Source Data Address Register  Reset Value */

#define FCW_SRCADDR_SRCADDR_Pos               _UINT32_(2)                                          /* (FCW_SRCADDR) Source Data (Word) Address Position */
#define FCW_SRCADDR_SRCADDR_Msk               (_UINT32_(0x3FFFFFFF) << FCW_SRCADDR_SRCADDR_Pos)    /* (FCW_SRCADDR) Source Data (Word) Address Mask */
#define FCW_SRCADDR_SRCADDR(value)            (FCW_SRCADDR_SRCADDR_Msk & (_UINT32_(value) << FCW_SRCADDR_SRCADDR_Pos)) /* Assigment of value for SRCADDR in the FCW_SRCADDR register */
#define FCW_SRCADDR_Msk                       _UINT32_(0xFFFFFFFC)                                 /* (FCW_SRCADDR) Register Mask  */


/* -------- FCW_DATA : (FCW Offset: 0x28) (R/W 32) Flash Write Data Register -------- */
#define FCW_DATA_RESETVALUE                   _UINT32_(0x00)                                       /*  (FCW_DATA) Flash Write Data Register  Reset Value */

#define FCW_DATA_DATA_Pos                     _UINT32_(0)                                          /* (FCW_DATA) Flash Write Data Position */
#define FCW_DATA_DATA_Msk                     (_UINT32_(0xFFFFFFFF) << FCW_DATA_DATA_Pos)          /* (FCW_DATA) Flash Write Data Mask */
#define FCW_DATA_DATA(value)                  (FCW_DATA_DATA_Msk & (_UINT32_(value) << FCW_DATA_DATA_Pos)) /* Assigment of value for DATA in the FCW_DATA register */
#define FCW_DATA_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (FCW_DATA) Register Mask  */


/* -------- FCW_SWAP : (FCW Offset: 0x48) (R/W 32) NVM Panel Swap Register -------- */
#define FCW_SWAP_RESETVALUE                   _UINT32_(0x00)                                       /*  (FCW_SWAP) NVM Panel Swap Register  Reset Value */

#define FCW_SWAP_BFSWAP_Pos                   _UINT32_(0)                                          /* (FCW_SWAP) BFM Swap Status/Control Bit Position */
#define FCW_SWAP_BFSWAP_Msk                   (_UINT32_(0x1) << FCW_SWAP_BFSWAP_Pos)               /* (FCW_SWAP) BFM Swap Status/Control Bit Mask */
#define FCW_SWAP_BFSWAP(value)                (FCW_SWAP_BFSWAP_Msk & (_UINT32_(value) << FCW_SWAP_BFSWAP_Pos)) /* Assigment of value for BFSWAP in the FCW_SWAP register */
#define FCW_SWAP_BFSLOCK_Pos                  _UINT32_(1)                                          /* (FCW_SWAP) BFM Swap Lock Bit Position */
#define FCW_SWAP_BFSLOCK_Msk                  (_UINT32_(0x1) << FCW_SWAP_BFSLOCK_Pos)              /* (FCW_SWAP) BFM Swap Lock Bit Mask */
#define FCW_SWAP_BFSLOCK(value)               (FCW_SWAP_BFSLOCK_Msk & (_UINT32_(value) << FCW_SWAP_BFSLOCK_Pos)) /* Assigment of value for BFSLOCK in the FCW_SWAP register */
#define FCW_SWAP_PFSWAP_Pos                   _UINT32_(8)                                          /* (FCW_SWAP) PFM Swap Status/Control Bit Position */
#define FCW_SWAP_PFSWAP_Msk                   (_UINT32_(0x1) << FCW_SWAP_PFSWAP_Pos)               /* (FCW_SWAP) PFM Swap Status/Control Bit Mask */
#define FCW_SWAP_PFSWAP(value)                (FCW_SWAP_PFSWAP_Msk & (_UINT32_(value) << FCW_SWAP_PFSWAP_Pos)) /* Assigment of value for PFSWAP in the FCW_SWAP register */
#define FCW_SWAP_PFSLOCK_Pos                  _UINT32_(9)                                          /* (FCW_SWAP) PFM Swap Lock Bit Position */
#define FCW_SWAP_PFSLOCK_Msk                  (_UINT32_(0x1) << FCW_SWAP_PFSLOCK_Pos)              /* (FCW_SWAP) PFM Swap Lock Bit Mask */
#define FCW_SWAP_PFSLOCK(value)               (FCW_SWAP_PFSLOCK_Msk & (_UINT32_(value) << FCW_SWAP_PFSLOCK_Pos)) /* Assigment of value for PFSLOCK in the FCW_SWAP register */
#define FCW_SWAP_Msk                          _UINT32_(0x00000303)                                 /* (FCW_SWAP) Register Mask  */


/* -------- FCW_PWP : (FCW Offset: 0x4C) (R/W 32) PFM Write Protect Region 0 -------- */
#define FCW_PWP_RESETVALUE                    _UINT32_(0x00)                                       /*  (FCW_PWP) PFM Write Protect Region 0  Reset Value */

#define FCW_PWP_PWPSIZE_Pos                   _UINT32_(0)                                          /* (FCW_PWP) PWP Region 0 Size in 4KB pages Position */
#define FCW_PWP_PWPSIZE_Msk                   (_UINT32_(0xFFF) << FCW_PWP_PWPSIZE_Pos)             /* (FCW_PWP) PWP Region 0 Size in 4KB pages Mask */
#define FCW_PWP_PWPSIZE(value)                (FCW_PWP_PWPSIZE_Msk & (_UINT32_(value) << FCW_PWP_PWPSIZE_Pos)) /* Assigment of value for PWPSIZE in the FCW_PWP register */
#define FCW_PWP_PWPMIR_Pos                    _UINT32_(13)                                         /* (FCW_PWP) Mirror PWP 0 bit Position */
#define FCW_PWP_PWPMIR_Msk                    (_UINT32_(0x1) << FCW_PWP_PWPMIR_Pos)                /* (FCW_PWP) Mirror PWP 0 bit Mask */
#define FCW_PWP_PWPMIR(value)                 (FCW_PWP_PWPMIR_Msk & (_UINT32_(value) << FCW_PWP_PWPMIR_Pos)) /* Assigment of value for PWPMIR in the FCW_PWP register */
#define FCW_PWP_PWPLOCK_Pos                   _UINT32_(14)                                         /* (FCW_PWP) PWP Region 0 Lock Bit Position */
#define FCW_PWP_PWPLOCK_Msk                   (_UINT32_(0x1) << FCW_PWP_PWPLOCK_Pos)               /* (FCW_PWP) PWP Region 0 Lock Bit Mask */
#define FCW_PWP_PWPLOCK(value)                (FCW_PWP_PWPLOCK_Msk & (_UINT32_(value) << FCW_PWP_PWPLOCK_Pos)) /* Assigment of value for PWPLOCK in the FCW_PWP register */
#define FCW_PWP_PWPEN_Pos                     _UINT32_(15)                                         /* (FCW_PWP) PWP Region 0 Enable Bit Position */
#define FCW_PWP_PWPEN_Msk                     (_UINT32_(0x1) << FCW_PWP_PWPEN_Pos)                 /* (FCW_PWP) PWP Region 0 Enable Bit Mask */
#define FCW_PWP_PWPEN(value)                  (FCW_PWP_PWPEN_Msk & (_UINT32_(value) << FCW_PWP_PWPEN_Pos)) /* Assigment of value for PWPEN in the FCW_PWP register */
#define FCW_PWP_PWPBASE_Pos                   _UINT32_(16)                                         /* (FCW_PWP) PWP Region 0 Base Address - 4KB Page Aligned Position */
#define FCW_PWP_PWPBASE_Msk                   (_UINT32_(0xFFF) << FCW_PWP_PWPBASE_Pos)             /* (FCW_PWP) PWP Region 0 Base Address - 4KB Page Aligned Mask */
#define FCW_PWP_PWPBASE(value)                (FCW_PWP_PWPBASE_Msk & (_UINT32_(value) << FCW_PWP_PWPBASE_Pos)) /* Assigment of value for PWPBASE in the FCW_PWP register */
#define FCW_PWP_Msk                           _UINT32_(0x0FFFEFFF)                                 /* (FCW_PWP) Register Mask  */


/* -------- FCW_LBWP : (FCW Offset: 0x6C) (R/W 32) Lower BFM Write Protect Register -------- */
#define FCW_LBWP_RESETVALUE                   _UINT32_(0xFFFF)                                     /*  (FCW_LBWP) Lower BFM Write Protect Register  Reset Value */

#define FCW_LBWP_LBWP_Pos                     _UINT32_(0)                                          /* (FCW_LBWP) Lower Boot Pages Write Protect Bits Position */
#define FCW_LBWP_LBWP_Msk                     (_UINT32_(0xFFFF) << FCW_LBWP_LBWP_Pos)              /* (FCW_LBWP) Lower Boot Pages Write Protect Bits Mask */
#define FCW_LBWP_LBWP(value)                  (FCW_LBWP_LBWP_Msk & (_UINT32_(value) << FCW_LBWP_LBWP_Pos)) /* Assigment of value for LBWP in the FCW_LBWP register */
#define FCW_LBWP_LBWPLOCK_Pos                 _UINT32_(31)                                         /* (FCW_LBWP) LBWP Lock Bit Position */
#define FCW_LBWP_LBWPLOCK_Msk                 (_UINT32_(0x1) << FCW_LBWP_LBWPLOCK_Pos)             /* (FCW_LBWP) LBWP Lock Bit Mask */
#define FCW_LBWP_LBWPLOCK(value)              (FCW_LBWP_LBWPLOCK_Msk & (_UINT32_(value) << FCW_LBWP_LBWPLOCK_Pos)) /* Assigment of value for LBWPLOCK in the FCW_LBWP register */
#define FCW_LBWP_Msk                          _UINT32_(0x8000FFFF)                                 /* (FCW_LBWP) Register Mask  */


/* -------- FCW_UBWP : (FCW Offset: 0x70) (R/W 32) Upper BFM Write Protect Register -------- */
#define FCW_UBWP_RESETVALUE                   _UINT32_(0xFFFF)                                     /*  (FCW_UBWP) Upper BFM Write Protect Register  Reset Value */

#define FCW_UBWP_UBWP_Pos                     _UINT32_(0)                                          /* (FCW_UBWP) Upper Boot Pages Write Protect Bits Position */
#define FCW_UBWP_UBWP_Msk                     (_UINT32_(0xFFFF) << FCW_UBWP_UBWP_Pos)              /* (FCW_UBWP) Upper Boot Pages Write Protect Bits Mask */
#define FCW_UBWP_UBWP(value)                  (FCW_UBWP_UBWP_Msk & (_UINT32_(value) << FCW_UBWP_UBWP_Pos)) /* Assigment of value for UBWP in the FCW_UBWP register */
#define FCW_UBWP_UBWPLOCK_Pos                 _UINT32_(31)                                         /* (FCW_UBWP) UBWP Register Lock Bit Position */
#define FCW_UBWP_UBWPLOCK_Msk                 (_UINT32_(0x1) << FCW_UBWP_UBWPLOCK_Pos)             /* (FCW_UBWP) UBWP Register Lock Bit Mask */
#define FCW_UBWP_UBWPLOCK(value)              (FCW_UBWP_UBWPLOCK_Msk & (_UINT32_(value) << FCW_UBWP_UBWPLOCK_Pos)) /* Assigment of value for UBWPLOCK in the FCW_UBWP register */
#define FCW_UBWP_Msk                          _UINT32_(0x8000FFFF)                                 /* (FCW_UBWP) Register Mask  */


/* -------- FCW_UOWP : (FCW Offset: 0x74) (R/W 32) User OTP Write Protect Register -------- */
#define FCW_UOWP_RESETVALUE                   _UINT32_(0xF0F)                                      /*  (FCW_UOWP) User OTP Write Protect Register  Reset Value */

#define FCW_UOWP_UO1WP_Pos                    _UINT32_(0)                                          /* (FCW_UOWP) User OTP Page 1 Write Protect Row Bit Position */
#define FCW_UOWP_UO1WP_Msk                    (_UINT32_(0xF) << FCW_UOWP_UO1WP_Pos)                /* (FCW_UOWP) User OTP Page 1 Write Protect Row Bit Mask */
#define FCW_UOWP_UO1WP(value)                 (FCW_UOWP_UO1WP_Msk & (_UINT32_(value) << FCW_UOWP_UO1WP_Pos)) /* Assigment of value for UO1WP in the FCW_UOWP register */
#define FCW_UOWP_UO2WP_Pos                    _UINT32_(8)                                          /* (FCW_UOWP) User OTP Page 2 Write Protect Row Bit Position */
#define FCW_UOWP_UO2WP_Msk                    (_UINT32_(0xF) << FCW_UOWP_UO2WP_Pos)                /* (FCW_UOWP) User OTP Page 2 Write Protect Row Bit Mask */
#define FCW_UOWP_UO2WP(value)                 (FCW_UOWP_UO2WP_Msk & (_UINT32_(value) << FCW_UOWP_UO2WP_Pos)) /* Assigment of value for UO2WP in the FCW_UOWP register */
#define FCW_UOWP_UO1WPRLOCK_Pos               _UINT32_(16)                                         /* (FCW_UOWP) User OTP Page 1 WP Row Lock Bit Position */
#define FCW_UOWP_UO1WPRLOCK_Msk               (_UINT32_(0xF) << FCW_UOWP_UO1WPRLOCK_Pos)           /* (FCW_UOWP) User OTP Page 1 WP Row Lock Bit Mask */
#define FCW_UOWP_UO1WPRLOCK(value)            (FCW_UOWP_UO1WPRLOCK_Msk & (_UINT32_(value) << FCW_UOWP_UO1WPRLOCK_Pos)) /* Assigment of value for UO1WPRLOCK in the FCW_UOWP register */
#define FCW_UOWP_UO2WPRLOCK_Pos               _UINT32_(24)                                         /* (FCW_UOWP) User OTP Page 2 WP Row Lock Bit Position */
#define FCW_UOWP_UO2WPRLOCK_Msk               (_UINT32_(0xF) << FCW_UOWP_UO2WPRLOCK_Pos)           /* (FCW_UOWP) User OTP Page 2 WP Row Lock Bit Mask */
#define FCW_UOWP_UO2WPRLOCK(value)            (FCW_UOWP_UO2WPRLOCK_Msk & (_UINT32_(value) << FCW_UOWP_UO2WPRLOCK_Pos)) /* Assigment of value for UO2WPRLOCK in the FCW_UOWP register */
#define FCW_UOWP_Msk                          _UINT32_(0x0F0F0F0F)                                 /* (FCW_UOWP) Register Mask  */


/* -------- FCW_CWP : (FCW Offset: 0x78) (R/W 32) CFM Page Write Protect Register -------- */
#define FCW_CWP_RESETVALUE                    _UINT32_(0x505)                                      /*  (FCW_CWP) CFM Page Write Protect Register  Reset Value */

#define FCW_CWP_UC1WP_Pos                     _UINT32_(0)                                          /* (FCW_CWP) User Configuration Page 1 Write Protect Bit Position */
#define FCW_CWP_UC1WP_Msk                     (_UINT32_(0x1) << FCW_CWP_UC1WP_Pos)                 /* (FCW_CWP) User Configuration Page 1 Write Protect Bit Mask */
#define FCW_CWP_UC1WP(value)                  (FCW_CWP_UC1WP_Msk & (_UINT32_(value) << FCW_CWP_UC1WP_Pos)) /* Assigment of value for UC1WP in the FCW_CWP register */
#define FCW_CWP_BC1WP_Pos                     _UINT32_(2)                                          /* (FCW_CWP) Boot Configuration Page 1 Write Protect Bit Position */
#define FCW_CWP_BC1WP_Msk                     (_UINT32_(0x1) << FCW_CWP_BC1WP_Pos)                 /* (FCW_CWP) Boot Configuration Page 1 Write Protect Bit Mask */
#define FCW_CWP_BC1WP(value)                  (FCW_CWP_BC1WP_Msk & (_UINT32_(value) << FCW_CWP_BC1WP_Pos)) /* Assigment of value for BC1WP in the FCW_CWP register */
#define FCW_CWP_UC2WP_Pos                     _UINT32_(8)                                          /* (FCW_CWP) User Configuration Page 2 Write Protect Bit Position */
#define FCW_CWP_UC2WP_Msk                     (_UINT32_(0x1) << FCW_CWP_UC2WP_Pos)                 /* (FCW_CWP) User Configuration Page 2 Write Protect Bit Mask */
#define FCW_CWP_UC2WP(value)                  (FCW_CWP_UC2WP_Msk & (_UINT32_(value) << FCW_CWP_UC2WP_Pos)) /* Assigment of value for UC2WP in the FCW_CWP register */
#define FCW_CWP_BC2WP_Pos                     _UINT32_(10)                                         /* (FCW_CWP) Boot Configuration Page 2 Write Protect Bit Position */
#define FCW_CWP_BC2WP_Msk                     (_UINT32_(0x1) << FCW_CWP_BC2WP_Pos)                 /* (FCW_CWP) Boot Configuration Page 2 Write Protect Bit Mask */
#define FCW_CWP_BC2WP(value)                  (FCW_CWP_BC2WP_Msk & (_UINT32_(value) << FCW_CWP_BC2WP_Pos)) /* Assigment of value for BC2WP in the FCW_CWP register */
#define FCW_CWP_UC1WPLOCK_Pos                 _UINT32_(16)                                         /* (FCW_CWP) User Configuration Page 1 WP Lock Bit Position */
#define FCW_CWP_UC1WPLOCK_Msk                 (_UINT32_(0x1) << FCW_CWP_UC1WPLOCK_Pos)             /* (FCW_CWP) User Configuration Page 1 WP Lock Bit Mask */
#define FCW_CWP_UC1WPLOCK(value)              (FCW_CWP_UC1WPLOCK_Msk & (_UINT32_(value) << FCW_CWP_UC1WPLOCK_Pos)) /* Assigment of value for UC1WPLOCK in the FCW_CWP register */
#define FCW_CWP_BC1WPLOCK_Pos                 _UINT32_(18)                                         /* (FCW_CWP) Boot Configuration Page 1 WP Lock Bit Position */
#define FCW_CWP_BC1WPLOCK_Msk                 (_UINT32_(0x1) << FCW_CWP_BC1WPLOCK_Pos)             /* (FCW_CWP) Boot Configuration Page 1 WP Lock Bit Mask */
#define FCW_CWP_BC1WPLOCK(value)              (FCW_CWP_BC1WPLOCK_Msk & (_UINT32_(value) << FCW_CWP_BC1WPLOCK_Pos)) /* Assigment of value for BC1WPLOCK in the FCW_CWP register */
#define FCW_CWP_UC2WPLOCK_Pos                 _UINT32_(24)                                         /* (FCW_CWP) User Configuration Page 2 WP Lock Bit Position */
#define FCW_CWP_UC2WPLOCK_Msk                 (_UINT32_(0x1) << FCW_CWP_UC2WPLOCK_Pos)             /* (FCW_CWP) User Configuration Page 2 WP Lock Bit Mask */
#define FCW_CWP_UC2WPLOCK(value)              (FCW_CWP_UC2WPLOCK_Msk & (_UINT32_(value) << FCW_CWP_UC2WPLOCK_Pos)) /* Assigment of value for UC2WPLOCK in the FCW_CWP register */
#define FCW_CWP_BC2WPLOCK_Pos                 _UINT32_(26)                                         /* (FCW_CWP) Boot Configuration Page 2 WP Lock Bit Position */
#define FCW_CWP_BC2WPLOCK_Msk                 (_UINT32_(0x1) << FCW_CWP_BC2WPLOCK_Pos)             /* (FCW_CWP) Boot Configuration Page 2 WP Lock Bit Mask */
#define FCW_CWP_BC2WPLOCK(value)              (FCW_CWP_BC2WPLOCK_Msk & (_UINT32_(value) << FCW_CWP_BC2WPLOCK_Pos)) /* Assigment of value for BC2WPLOCK in the FCW_CWP register */
#define FCW_CWP_Msk                           _UINT32_(0x05050505)                                 /* (FCW_CWP) Register Mask  */


/* -------- FCW_HSMINTENCLR : (FCW Offset: 0x80) (R/W 32) HSM NVM Interrupt Enable Clear Register -------- */
#define FCW_HSMINTENCLR_RESETVALUE            _UINT32_(0x00)                                       /*  (FCW_HSMINTENCLR) HSM NVM Interrupt Enable Clear Register  Reset Value */

#define FCW_HSMINTENCLR_DONE_Pos              _UINT32_(0)                                          /* (FCW_HSMINTENCLR) NVM Operation Done Interrupt Enable Bit Position */
#define FCW_HSMINTENCLR_DONE_Msk              (_UINT32_(0x1) << FCW_HSMINTENCLR_DONE_Pos)          /* (FCW_HSMINTENCLR) NVM Operation Done Interrupt Enable Bit Mask */
#define FCW_HSMINTENCLR_DONE(value)           (FCW_HSMINTENCLR_DONE_Msk & (_UINT32_(value) << FCW_HSMINTENCLR_DONE_Pos)) /* Assigment of value for DONE in the FCW_HSMINTENCLR register */
#define FCW_HSMINTENCLR_KEYERR_Pos            _UINT32_(1)                                          /* (FCW_HSMINTENCLR) Key Error Interrupt Enable Bit Position */
#define FCW_HSMINTENCLR_KEYERR_Msk            (_UINT32_(0x1) << FCW_HSMINTENCLR_KEYERR_Pos)        /* (FCW_HSMINTENCLR) Key Error Interrupt Enable Bit Mask */
#define FCW_HSMINTENCLR_KEYERR(value)         (FCW_HSMINTENCLR_KEYERR_Msk & (_UINT32_(value) << FCW_HSMINTENCLR_KEYERR_Pos)) /* Assigment of value for KEYERR in the FCW_HSMINTENCLR register */
#define FCW_HSMINTENCLR_CFGERR_Pos            _UINT32_(2)                                          /* (FCW_HSMINTENCLR) Configuration Error Interrupt Enable Bit Position */
#define FCW_HSMINTENCLR_CFGERR_Msk            (_UINT32_(0x1) << FCW_HSMINTENCLR_CFGERR_Pos)        /* (FCW_HSMINTENCLR) Configuration Error Interrupt Enable Bit Mask */
#define FCW_HSMINTENCLR_CFGERR(value)         (FCW_HSMINTENCLR_CFGERR_Msk & (_UINT32_(value) << FCW_HSMINTENCLR_CFGERR_Pos)) /* Assigment of value for CFGERR in the FCW_HSMINTENCLR register */
#define FCW_HSMINTENCLR_FIFOERR_Pos           _UINT32_(3)                                          /* (FCW_HSMINTENCLR) FIFO Underrun during Row Write Interrupt Enable Bit Position */
#define FCW_HSMINTENCLR_FIFOERR_Msk           (_UINT32_(0x1) << FCW_HSMINTENCLR_FIFOERR_Pos)       /* (FCW_HSMINTENCLR) FIFO Underrun during Row Write Interrupt Enable Bit Mask */
#define FCW_HSMINTENCLR_FIFOERR(value)        (FCW_HSMINTENCLR_FIFOERR_Msk & (_UINT32_(value) << FCW_HSMINTENCLR_FIFOERR_Pos)) /* Assigment of value for FIFOERR in the FCW_HSMINTENCLR register */
#define FCW_HSMINTENCLR_BUSERR_Pos            _UINT32_(4)                                          /* (FCW_HSMINTENCLR) AHB Bus Error during Row Write Interrupt Enable Bit Position */
#define FCW_HSMINTENCLR_BUSERR_Msk            (_UINT32_(0x1) << FCW_HSMINTENCLR_BUSERR_Pos)        /* (FCW_HSMINTENCLR) AHB Bus Error during Row Write Interrupt Enable Bit Mask */
#define FCW_HSMINTENCLR_BUSERR(value)         (FCW_HSMINTENCLR_BUSERR_Msk & (_UINT32_(value) << FCW_HSMINTENCLR_BUSERR_Pos)) /* Assigment of value for BUSERR in the FCW_HSMINTENCLR register */
#define FCW_HSMINTENCLR_WPERR_Pos             _UINT32_(5)                                          /* (FCW_HSMINTENCLR) Write Protection Error Interrupt Enable Bit Position */
#define FCW_HSMINTENCLR_WPERR_Msk             (_UINT32_(0x1) << FCW_HSMINTENCLR_WPERR_Pos)         /* (FCW_HSMINTENCLR) Write Protection Error Interrupt Enable Bit Mask */
#define FCW_HSMINTENCLR_WPERR(value)          (FCW_HSMINTENCLR_WPERR_Msk & (_UINT32_(value) << FCW_HSMINTENCLR_WPERR_Pos)) /* Assigment of value for WPERR in the FCW_HSMINTENCLR register */
#define FCW_HSMINTENCLR_OPERR_Pos             _UINT32_(6)                                          /* (FCW_HSMINTENCLR) NVMOP Error Interrupt Enable Bit Position */
#define FCW_HSMINTENCLR_OPERR_Msk             (_UINT32_(0x1) << FCW_HSMINTENCLR_OPERR_Pos)         /* (FCW_HSMINTENCLR) NVMOP Error Interrupt Enable Bit Mask */
#define FCW_HSMINTENCLR_OPERR(value)          (FCW_HSMINTENCLR_OPERR_Msk & (_UINT32_(value) << FCW_HSMINTENCLR_OPERR_Pos)) /* Assigment of value for OPERR in the FCW_HSMINTENCLR register */
#define FCW_HSMINTENCLR_SECERR_Pos            _UINT32_(7)                                          /* (FCW_HSMINTENCLR) Security Violation Error Interrupt Enable Bit Position */
#define FCW_HSMINTENCLR_SECERR_Msk            (_UINT32_(0x1) << FCW_HSMINTENCLR_SECERR_Pos)        /* (FCW_HSMINTENCLR) Security Violation Error Interrupt Enable Bit Mask */
#define FCW_HSMINTENCLR_SECERR(value)         (FCW_HSMINTENCLR_SECERR_Msk & (_UINT32_(value) << FCW_HSMINTENCLR_SECERR_Pos)) /* Assigment of value for SECERR in the FCW_HSMINTENCLR register */
#define FCW_HSMINTENCLR_HTDPGM_Pos            _UINT32_(8)                                          /* (FCW_HSMINTENCLR) High Temperature Detect Error Interrupt Enable Bit Position */
#define FCW_HSMINTENCLR_HTDPGM_Msk            (_UINT32_(0x1) << FCW_HSMINTENCLR_HTDPGM_Pos)        /* (FCW_HSMINTENCLR) High Temperature Detect Error Interrupt Enable Bit Mask */
#define FCW_HSMINTENCLR_HTDPGM(value)         (FCW_HSMINTENCLR_HTDPGM_Msk & (_UINT32_(value) << FCW_HSMINTENCLR_HTDPGM_Pos)) /* Assigment of value for HTDPGM in the FCW_HSMINTENCLR register */
#define FCW_HSMINTENCLR_BORERR_Pos            _UINT32_(12)                                         /* (FCW_HSMINTENCLR) Brown Out Detect Error Interrupt Enable Bit Position */
#define FCW_HSMINTENCLR_BORERR_Msk            (_UINT32_(0x1) << FCW_HSMINTENCLR_BORERR_Pos)        /* (FCW_HSMINTENCLR) Brown Out Detect Error Interrupt Enable Bit Mask */
#define FCW_HSMINTENCLR_BORERR(value)         (FCW_HSMINTENCLR_BORERR_Msk & (_UINT32_(value) << FCW_HSMINTENCLR_BORERR_Pos)) /* Assigment of value for BORERR in the FCW_HSMINTENCLR register */
#define FCW_HSMINTENCLR_WRERR_Pos             _UINT32_(13)                                         /* (FCW_HSMINTENCLR) Write Error Interrupt Enable Bit Position */
#define FCW_HSMINTENCLR_WRERR_Msk             (_UINT32_(0x1) << FCW_HSMINTENCLR_WRERR_Pos)         /* (FCW_HSMINTENCLR) Write Error Interrupt Enable Bit Mask */
#define FCW_HSMINTENCLR_WRERR(value)          (FCW_HSMINTENCLR_WRERR_Msk & (_UINT32_(value) << FCW_HSMINTENCLR_WRERR_Pos)) /* Assigment of value for WRERR in the FCW_HSMINTENCLR register */
#define FCW_HSMINTENCLR_Msk                   _UINT32_(0x000031FF)                                 /* (FCW_HSMINTENCLR) Register Mask  */


/* -------- FCW_HSMINTENSET : (FCW Offset: 0x84) (R/W 32) HSM NVM Interrupt Enable SET Register -------- */
#define FCW_HSMINTENSET_RESETVALUE            _UINT32_(0x00)                                       /*  (FCW_HSMINTENSET) HSM NVM Interrupt Enable SET Register  Reset Value */

#define FCW_HSMINTENSET_DONE_Pos              _UINT32_(0)                                          /* (FCW_HSMINTENSET) NVM Operation Done Interrupt Enable Bit Position */
#define FCW_HSMINTENSET_DONE_Msk              (_UINT32_(0x1) << FCW_HSMINTENSET_DONE_Pos)          /* (FCW_HSMINTENSET) NVM Operation Done Interrupt Enable Bit Mask */
#define FCW_HSMINTENSET_DONE(value)           (FCW_HSMINTENSET_DONE_Msk & (_UINT32_(value) << FCW_HSMINTENSET_DONE_Pos)) /* Assigment of value for DONE in the FCW_HSMINTENSET register */
#define FCW_HSMINTENSET_KEYERR_Pos            _UINT32_(1)                                          /* (FCW_HSMINTENSET) Key Error Interrupt Enable Bit Position */
#define FCW_HSMINTENSET_KEYERR_Msk            (_UINT32_(0x1) << FCW_HSMINTENSET_KEYERR_Pos)        /* (FCW_HSMINTENSET) Key Error Interrupt Enable Bit Mask */
#define FCW_HSMINTENSET_KEYERR(value)         (FCW_HSMINTENSET_KEYERR_Msk & (_UINT32_(value) << FCW_HSMINTENSET_KEYERR_Pos)) /* Assigment of value for KEYERR in the FCW_HSMINTENSET register */
#define FCW_HSMINTENSET_CFGERR_Pos            _UINT32_(2)                                          /* (FCW_HSMINTENSET) Configuration Error Interrupt Enable Bit Position */
#define FCW_HSMINTENSET_CFGERR_Msk            (_UINT32_(0x1) << FCW_HSMINTENSET_CFGERR_Pos)        /* (FCW_HSMINTENSET) Configuration Error Interrupt Enable Bit Mask */
#define FCW_HSMINTENSET_CFGERR(value)         (FCW_HSMINTENSET_CFGERR_Msk & (_UINT32_(value) << FCW_HSMINTENSET_CFGERR_Pos)) /* Assigment of value for CFGERR in the FCW_HSMINTENSET register */
#define FCW_HSMINTENSET_FIFOERR_Pos           _UINT32_(3)                                          /* (FCW_HSMINTENSET) FIFO Underrun during Row Write Interrupt Enable Bit Position */
#define FCW_HSMINTENSET_FIFOERR_Msk           (_UINT32_(0x1) << FCW_HSMINTENSET_FIFOERR_Pos)       /* (FCW_HSMINTENSET) FIFO Underrun during Row Write Interrupt Enable Bit Mask */
#define FCW_HSMINTENSET_FIFOERR(value)        (FCW_HSMINTENSET_FIFOERR_Msk & (_UINT32_(value) << FCW_HSMINTENSET_FIFOERR_Pos)) /* Assigment of value for FIFOERR in the FCW_HSMINTENSET register */
#define FCW_HSMINTENSET_BUSERR_Pos            _UINT32_(4)                                          /* (FCW_HSMINTENSET) AHB Bus Error during Row Write Interrupt Enable Bit Position */
#define FCW_HSMINTENSET_BUSERR_Msk            (_UINT32_(0x1) << FCW_HSMINTENSET_BUSERR_Pos)        /* (FCW_HSMINTENSET) AHB Bus Error during Row Write Interrupt Enable Bit Mask */
#define FCW_HSMINTENSET_BUSERR(value)         (FCW_HSMINTENSET_BUSERR_Msk & (_UINT32_(value) << FCW_HSMINTENSET_BUSERR_Pos)) /* Assigment of value for BUSERR in the FCW_HSMINTENSET register */
#define FCW_HSMINTENSET_WPERR_Pos             _UINT32_(5)                                          /* (FCW_HSMINTENSET) Write Protection Error Interrupt Enable Bit Position */
#define FCW_HSMINTENSET_WPERR_Msk             (_UINT32_(0x1) << FCW_HSMINTENSET_WPERR_Pos)         /* (FCW_HSMINTENSET) Write Protection Error Interrupt Enable Bit Mask */
#define FCW_HSMINTENSET_WPERR(value)          (FCW_HSMINTENSET_WPERR_Msk & (_UINT32_(value) << FCW_HSMINTENSET_WPERR_Pos)) /* Assigment of value for WPERR in the FCW_HSMINTENSET register */
#define FCW_HSMINTENSET_OPERR_Pos             _UINT32_(6)                                          /* (FCW_HSMINTENSET) NVMOP Error Interrupt Enable Bit Position */
#define FCW_HSMINTENSET_OPERR_Msk             (_UINT32_(0x1) << FCW_HSMINTENSET_OPERR_Pos)         /* (FCW_HSMINTENSET) NVMOP Error Interrupt Enable Bit Mask */
#define FCW_HSMINTENSET_OPERR(value)          (FCW_HSMINTENSET_OPERR_Msk & (_UINT32_(value) << FCW_HSMINTENSET_OPERR_Pos)) /* Assigment of value for OPERR in the FCW_HSMINTENSET register */
#define FCW_HSMINTENSET_SECERR_Pos            _UINT32_(7)                                          /* (FCW_HSMINTENSET) Security Violation Error Interrupt Enable Bit Position */
#define FCW_HSMINTENSET_SECERR_Msk            (_UINT32_(0x1) << FCW_HSMINTENSET_SECERR_Pos)        /* (FCW_HSMINTENSET) Security Violation Error Interrupt Enable Bit Mask */
#define FCW_HSMINTENSET_SECERR(value)         (FCW_HSMINTENSET_SECERR_Msk & (_UINT32_(value) << FCW_HSMINTENSET_SECERR_Pos)) /* Assigment of value for SECERR in the FCW_HSMINTENSET register */
#define FCW_HSMINTENSET_HTDPGM_Pos            _UINT32_(8)                                          /* (FCW_HSMINTENSET) High Temperature Detect Error Interrupt Enable Bit Position */
#define FCW_HSMINTENSET_HTDPGM_Msk            (_UINT32_(0x1) << FCW_HSMINTENSET_HTDPGM_Pos)        /* (FCW_HSMINTENSET) High Temperature Detect Error Interrupt Enable Bit Mask */
#define FCW_HSMINTENSET_HTDPGM(value)         (FCW_HSMINTENSET_HTDPGM_Msk & (_UINT32_(value) << FCW_HSMINTENSET_HTDPGM_Pos)) /* Assigment of value for HTDPGM in the FCW_HSMINTENSET register */
#define FCW_HSMINTENSET_BORERR_Pos            _UINT32_(12)                                         /* (FCW_HSMINTENSET) Brown Out Detect Error Interrupt Enable Bit Position */
#define FCW_HSMINTENSET_BORERR_Msk            (_UINT32_(0x1) << FCW_HSMINTENSET_BORERR_Pos)        /* (FCW_HSMINTENSET) Brown Out Detect Error Interrupt Enable Bit Mask */
#define FCW_HSMINTENSET_BORERR(value)         (FCW_HSMINTENSET_BORERR_Msk & (_UINT32_(value) << FCW_HSMINTENSET_BORERR_Pos)) /* Assigment of value for BORERR in the FCW_HSMINTENSET register */
#define FCW_HSMINTENSET_WRERR_Pos             _UINT32_(13)                                         /* (FCW_HSMINTENSET) Write Error Interrupt Enable Bit Position */
#define FCW_HSMINTENSET_WRERR_Msk             (_UINT32_(0x1) << FCW_HSMINTENSET_WRERR_Pos)         /* (FCW_HSMINTENSET) Write Error Interrupt Enable Bit Mask */
#define FCW_HSMINTENSET_WRERR(value)          (FCW_HSMINTENSET_WRERR_Msk & (_UINT32_(value) << FCW_HSMINTENSET_WRERR_Pos)) /* Assigment of value for WRERR in the FCW_HSMINTENSET register */
#define FCW_HSMINTENSET_Msk                   _UINT32_(0x000031FF)                                 /* (FCW_HSMINTENSET) Register Mask  */


/* -------- FCW_HSMINTFLAG : (FCW Offset: 0x88) (R/W 32) HSM NVM Interrupt Flag Register -------- */
#define FCW_HSMINTFLAG_RESETVALUE             _UINT32_(0x00)                                       /*  (FCW_HSMINTFLAG) HSM NVM Interrupt Flag Register  Reset Value */

#define FCW_HSMINTFLAG_DONE_Pos               _UINT32_(0)                                          /* (FCW_HSMINTFLAG) NVM Operation Done Flag Bit Position */
#define FCW_HSMINTFLAG_DONE_Msk               (_UINT32_(0x1) << FCW_HSMINTFLAG_DONE_Pos)           /* (FCW_HSMINTFLAG) NVM Operation Done Flag Bit Mask */
#define FCW_HSMINTFLAG_DONE(value)            (FCW_HSMINTFLAG_DONE_Msk & (_UINT32_(value) << FCW_HSMINTFLAG_DONE_Pos)) /* Assigment of value for DONE in the FCW_HSMINTFLAG register */
#define FCW_HSMINTFLAG_KEYERR_Pos             _UINT32_(1)                                          /* (FCW_HSMINTFLAG) Key Error Flag Bit Position */
#define FCW_HSMINTFLAG_KEYERR_Msk             (_UINT32_(0x1) << FCW_HSMINTFLAG_KEYERR_Pos)         /* (FCW_HSMINTFLAG) Key Error Flag Bit Mask */
#define FCW_HSMINTFLAG_KEYERR(value)          (FCW_HSMINTFLAG_KEYERR_Msk & (_UINT32_(value) << FCW_HSMINTFLAG_KEYERR_Pos)) /* Assigment of value for KEYERR in the FCW_HSMINTFLAG register */
#define FCW_HSMINTFLAG_CFGERR_Pos             _UINT32_(2)                                          /* (FCW_HSMINTFLAG) Configuration Error Flag Bit Position */
#define FCW_HSMINTFLAG_CFGERR_Msk             (_UINT32_(0x1) << FCW_HSMINTFLAG_CFGERR_Pos)         /* (FCW_HSMINTFLAG) Configuration Error Flag Bit Mask */
#define FCW_HSMINTFLAG_CFGERR(value)          (FCW_HSMINTFLAG_CFGERR_Msk & (_UINT32_(value) << FCW_HSMINTFLAG_CFGERR_Pos)) /* Assigment of value for CFGERR in the FCW_HSMINTFLAG register */
#define FCW_HSMINTFLAG_FIFOERR_Pos            _UINT32_(3)                                          /* (FCW_HSMINTFLAG) FIFO Underrun during Row Write Flag Bit Position */
#define FCW_HSMINTFLAG_FIFOERR_Msk            (_UINT32_(0x1) << FCW_HSMINTFLAG_FIFOERR_Pos)        /* (FCW_HSMINTFLAG) FIFO Underrun during Row Write Flag Bit Mask */
#define FCW_HSMINTFLAG_FIFOERR(value)         (FCW_HSMINTFLAG_FIFOERR_Msk & (_UINT32_(value) << FCW_HSMINTFLAG_FIFOERR_Pos)) /* Assigment of value for FIFOERR in the FCW_HSMINTFLAG register */
#define FCW_HSMINTFLAG_BUSERR_Pos             _UINT32_(4)                                          /* (FCW_HSMINTFLAG) AHB Bus Error during Row Write Flag Bit Position */
#define FCW_HSMINTFLAG_BUSERR_Msk             (_UINT32_(0x1) << FCW_HSMINTFLAG_BUSERR_Pos)         /* (FCW_HSMINTFLAG) AHB Bus Error during Row Write Flag Bit Mask */
#define FCW_HSMINTFLAG_BUSERR(value)          (FCW_HSMINTFLAG_BUSERR_Msk & (_UINT32_(value) << FCW_HSMINTFLAG_BUSERR_Pos)) /* Assigment of value for BUSERR in the FCW_HSMINTFLAG register */
#define FCW_HSMINTFLAG_WPERR_Pos              _UINT32_(5)                                          /* (FCW_HSMINTFLAG) Write Protection Error Flag Bit Position */
#define FCW_HSMINTFLAG_WPERR_Msk              (_UINT32_(0x1) << FCW_HSMINTFLAG_WPERR_Pos)          /* (FCW_HSMINTFLAG) Write Protection Error Flag Bit Mask */
#define FCW_HSMINTFLAG_WPERR(value)           (FCW_HSMINTFLAG_WPERR_Msk & (_UINT32_(value) << FCW_HSMINTFLAG_WPERR_Pos)) /* Assigment of value for WPERR in the FCW_HSMINTFLAG register */
#define FCW_HSMINTFLAG_OPERR_Pos              _UINT32_(6)                                          /* (FCW_HSMINTFLAG) NVMOP Error Flag Bit Position */
#define FCW_HSMINTFLAG_OPERR_Msk              (_UINT32_(0x1) << FCW_HSMINTFLAG_OPERR_Pos)          /* (FCW_HSMINTFLAG) NVMOP Error Flag Bit Mask */
#define FCW_HSMINTFLAG_OPERR(value)           (FCW_HSMINTFLAG_OPERR_Msk & (_UINT32_(value) << FCW_HSMINTFLAG_OPERR_Pos)) /* Assigment of value for OPERR in the FCW_HSMINTFLAG register */
#define FCW_HSMINTFLAG_SECERR_Pos             _UINT32_(7)                                          /* (FCW_HSMINTFLAG) Security Violation Error Bit Position */
#define FCW_HSMINTFLAG_SECERR_Msk             (_UINT32_(0x1) << FCW_HSMINTFLAG_SECERR_Pos)         /* (FCW_HSMINTFLAG) Security Violation Error Bit Mask */
#define FCW_HSMINTFLAG_SECERR(value)          (FCW_HSMINTFLAG_SECERR_Msk & (_UINT32_(value) << FCW_HSMINTFLAG_SECERR_Pos)) /* Assigment of value for SECERR in the FCW_HSMINTFLAG register */
#define FCW_HSMINTFLAG_HTDPGM_Pos             _UINT32_(8)                                          /* (FCW_HSMINTFLAG) High Temperature Detect Error Flag Bit Position */
#define FCW_HSMINTFLAG_HTDPGM_Msk             (_UINT32_(0x1) << FCW_HSMINTFLAG_HTDPGM_Pos)         /* (FCW_HSMINTFLAG) High Temperature Detect Error Flag Bit Mask */
#define FCW_HSMINTFLAG_HTDPGM(value)          (FCW_HSMINTFLAG_HTDPGM_Msk & (_UINT32_(value) << FCW_HSMINTFLAG_HTDPGM_Pos)) /* Assigment of value for HTDPGM in the FCW_HSMINTFLAG register */
#define FCW_HSMINTFLAG_BORERR_Pos             _UINT32_(12)                                         /* (FCW_HSMINTFLAG) Brown Out Detect Error Flag Bit Position */
#define FCW_HSMINTFLAG_BORERR_Msk             (_UINT32_(0x1) << FCW_HSMINTFLAG_BORERR_Pos)         /* (FCW_HSMINTFLAG) Brown Out Detect Error Flag Bit Mask */
#define FCW_HSMINTFLAG_BORERR(value)          (FCW_HSMINTFLAG_BORERR_Msk & (_UINT32_(value) << FCW_HSMINTFLAG_BORERR_Pos)) /* Assigment of value for BORERR in the FCW_HSMINTFLAG register */
#define FCW_HSMINTFLAG_WRERR_Pos              _UINT32_(13)                                         /* (FCW_HSMINTFLAG) Write Error Flag Bit Position */
#define FCW_HSMINTFLAG_WRERR_Msk              (_UINT32_(0x1) << FCW_HSMINTFLAG_WRERR_Pos)          /* (FCW_HSMINTFLAG) Write Error Flag Bit Mask */
#define FCW_HSMINTFLAG_WRERR(value)           (FCW_HSMINTFLAG_WRERR_Msk & (_UINT32_(value) << FCW_HSMINTFLAG_WRERR_Pos)) /* Assigment of value for WRERR in the FCW_HSMINTFLAG register */
#define FCW_HSMINTFLAG_Msk                    _UINT32_(0x000031FF)                                 /* (FCW_HSMINTFLAG) Register Mask  */


/* -------- FCW_HSMCWP : (FCW Offset: 0x8C) (R/W 32) HSM CFG Write Protect Register -------- */
#define FCW_HSMCWP_RESETVALUE                 _UINT32_(0xF000)                                     /*  (FCW_HSMCWP) HSM CFG Write Protect Register  Reset Value */

#define FCW_HSMCWP_HCWP_Pos                   _UINT32_(12)                                         /* (FCW_HSMCWP) HSM CFG Page Write Protect Bits Position */
#define FCW_HSMCWP_HCWP_Msk                   (_UINT32_(0xF) << FCW_HSMCWP_HCWP_Pos)               /* (FCW_HSMCWP) HSM CFG Page Write Protect Bits Mask */
#define FCW_HSMCWP_HCWP(value)                (FCW_HSMCWP_HCWP_Msk & (_UINT32_(value) << FCW_HSMCWP_HCWP_Pos)) /* Assigment of value for HCWP in the FCW_HSMCWP register */
#define FCW_HSMCWP_HCWPLOCK_Pos               _UINT32_(28)                                         /* (FCW_HSMCWP) HSMCWP Register Lock Bit Position */
#define FCW_HSMCWP_HCWPLOCK_Msk               (_UINT32_(0xF) << FCW_HSMCWP_HCWPLOCK_Pos)           /* (FCW_HSMCWP) HSMCWP Register Lock Bit Mask */
#define FCW_HSMCWP_HCWPLOCK(value)            (FCW_HSMCWP_HCWPLOCK_Msk & (_UINT32_(value) << FCW_HSMCWP_HCWPLOCK_Pos)) /* Assigment of value for HCWPLOCK in the FCW_HSMCWP register */
#define FCW_HSMCWP_Msk                        _UINT32_(0xF000F000)                                 /* (FCW_HSMCWP) Register Mask  */


/* -------- FCW_HSMLDAT : (FCW Offset: 0x90) (R/W 32) HSM Tamper Lower Overwrite Data Register -------- */
#define FCW_HSMLDAT_RESETVALUE                _UINT32_(0xFFFFFFFF)                                 /*  (FCW_HSMLDAT) HSM Tamper Lower Overwrite Data Register  Reset Value */

#define FCW_HSMLDAT_Msk                       _UINT32_(0x00000000)                                 /* (FCW_HSMLDAT) Register Mask  */


/* -------- FCW_HSMUDAT : (FCW Offset: 0xB0) (R/W 32) HSM Tamper Upper Overwrite Data Register -------- */
#define FCW_HSMUDAT_RESETVALUE                _UINT32_(0xFFFFFFFF)                                 /*  (FCW_HSMUDAT) HSM Tamper Upper Overwrite Data Register  Reset Value */

#define FCW_HSMUDAT_Msk                       _UINT32_(0x00000000)                                 /* (FCW_HSMUDAT) Register Mask  */


/** \brief FCW register offsets definitions */
#define FCW_CTRLA_REG_OFST             _UINT32_(0x00)      /* (FCW_CTRLA) NVM Write Control Register Offset */
#define FCW_CTRLB_REG_OFST             _UINT32_(0x04)      /* (FCW_CTRLB) NVM Control B Register Offset */
#define FCW_MUTEX_REG_OFST             _UINT32_(0x08)      /* (FCW_MUTEX) NVM MUTEX Register Offset */
#define FCW_INTENCLR_REG_OFST          _UINT32_(0x0C)      /* (FCW_INTENCLR) NVM Interrupt Enable Clear Register Offset */
#define FCW_INTENSET_REG_OFST          _UINT32_(0x10)      /* (FCW_INTENSET) NVM Interrupt Enable SET Register Offset */
#define FCW_INTFLAG_REG_OFST           _UINT32_(0x14)      /* (FCW_INTFLAG) NVM Interrupt Flag Register Offset */
#define FCW_STATUS_REG_OFST            _UINT32_(0x18)      /* (FCW_STATUS) NVM Status Register Offset */
#define FCW_KEY_REG_OFST               _UINT32_(0x1C)      /* (FCW_KEY) SFR Unlock Register Offset */
#define FCW_ADDR_REG_OFST              _UINT32_(0x20)      /* (FCW_ADDR) Flash Address Register Offset */
#define FCW_SRCADDR_REG_OFST           _UINT32_(0x24)      /* (FCW_SRCADDR) Source Data Address Register Offset */
#define FCW_DATA_REG_OFST              _UINT32_(0x28)      /* (FCW_DATA) Flash Write Data Register Offset */
#define FCW_DATA0_REG_OFST             _UINT32_(0x28)      /* (FCW_DATA0) Flash Write Data Register Offset */
#define FCW_DATA1_REG_OFST             _UINT32_(0x2C)      /* (FCW_DATA1) Flash Write Data Register Offset */
#define FCW_DATA2_REG_OFST             _UINT32_(0x30)      /* (FCW_DATA2) Flash Write Data Register Offset */
#define FCW_DATA3_REG_OFST             _UINT32_(0x34)      /* (FCW_DATA3) Flash Write Data Register Offset */
#define FCW_DATA4_REG_OFST             _UINT32_(0x38)      /* (FCW_DATA4) Flash Write Data Register Offset */
#define FCW_DATA5_REG_OFST             _UINT32_(0x3C)      /* (FCW_DATA5) Flash Write Data Register Offset */
#define FCW_DATA6_REG_OFST             _UINT32_(0x40)      /* (FCW_DATA6) Flash Write Data Register Offset */
#define FCW_DATA7_REG_OFST             _UINT32_(0x44)      /* (FCW_DATA7) Flash Write Data Register Offset */
#define FCW_SWAP_REG_OFST              _UINT32_(0x48)      /* (FCW_SWAP) NVM Panel Swap Register Offset */
#define FCW_PWP_REG_OFST               _UINT32_(0x4C)      /* (FCW_PWP) PFM Write Protect Region 0 Offset */
#define FCW_PWP0_REG_OFST              _UINT32_(0x4C)      /* (FCW_PWP0) PFM Write Protect Region 0 Offset */
#define FCW_PWP1_REG_OFST              _UINT32_(0x50)      /* (FCW_PWP1) PFM Write Protect Region 0 Offset */
#define FCW_PWP2_REG_OFST              _UINT32_(0x54)      /* (FCW_PWP2) PFM Write Protect Region 0 Offset */
#define FCW_PWP3_REG_OFST              _UINT32_(0x58)      /* (FCW_PWP3) PFM Write Protect Region 0 Offset */
#define FCW_PWP4_REG_OFST              _UINT32_(0x5C)      /* (FCW_PWP4) PFM Write Protect Region 0 Offset */
#define FCW_PWP5_REG_OFST              _UINT32_(0x60)      /* (FCW_PWP5) PFM Write Protect Region 0 Offset */
#define FCW_PWP6_REG_OFST              _UINT32_(0x64)      /* (FCW_PWP6) PFM Write Protect Region 0 Offset */
#define FCW_PWP7_REG_OFST              _UINT32_(0x68)      /* (FCW_PWP7) PFM Write Protect Region 0 Offset */
#define FCW_LBWP_REG_OFST              _UINT32_(0x6C)      /* (FCW_LBWP) Lower BFM Write Protect Register Offset */
#define FCW_UBWP_REG_OFST              _UINT32_(0x70)      /* (FCW_UBWP) Upper BFM Write Protect Register Offset */
#define FCW_UOWP_REG_OFST              _UINT32_(0x74)      /* (FCW_UOWP) User OTP Write Protect Register Offset */
#define FCW_CWP_REG_OFST               _UINT32_(0x78)      /* (FCW_CWP) CFM Page Write Protect Register Offset */
#define FCW_HSMINTENCLR_REG_OFST       _UINT32_(0x80)      /* (FCW_HSMINTENCLR) HSM NVM Interrupt Enable Clear Register Offset */
#define FCW_HSMINTENSET_REG_OFST       _UINT32_(0x84)      /* (FCW_HSMINTENSET) HSM NVM Interrupt Enable SET Register Offset */
#define FCW_HSMINTFLAG_REG_OFST        _UINT32_(0x88)      /* (FCW_HSMINTFLAG) HSM NVM Interrupt Flag Register Offset */
#define FCW_HSMCWP_REG_OFST            _UINT32_(0x8C)      /* (FCW_HSMCWP) HSM CFG Write Protect Register Offset */
#define FCW_HSMLDAT_REG_OFST           _UINT32_(0x90)      /* (FCW_HSMLDAT) HSM Tamper Lower Overwrite Data Register Offset */
#define FCW_HSMLDAT0_REG_OFST          _UINT32_(0x90)      /* (FCW_HSMLDAT0) HSM Tamper Lower Overwrite Data Register Offset */
#define FCW_HSMLDAT1_REG_OFST          _UINT32_(0x94)      /* (FCW_HSMLDAT1) HSM Tamper Lower Overwrite Data Register Offset */
#define FCW_HSMLDAT2_REG_OFST          _UINT32_(0x98)      /* (FCW_HSMLDAT2) HSM Tamper Lower Overwrite Data Register Offset */
#define FCW_HSMLDAT3_REG_OFST          _UINT32_(0x9C)      /* (FCW_HSMLDAT3) HSM Tamper Lower Overwrite Data Register Offset */
#define FCW_HSMLDAT4_REG_OFST          _UINT32_(0xA0)      /* (FCW_HSMLDAT4) HSM Tamper Lower Overwrite Data Register Offset */
#define FCW_HSMLDAT5_REG_OFST          _UINT32_(0xA4)      /* (FCW_HSMLDAT5) HSM Tamper Lower Overwrite Data Register Offset */
#define FCW_HSMLDAT6_REG_OFST          _UINT32_(0xA8)      /* (FCW_HSMLDAT6) HSM Tamper Lower Overwrite Data Register Offset */
#define FCW_HSMLDAT7_REG_OFST          _UINT32_(0xAC)      /* (FCW_HSMLDAT7) HSM Tamper Lower Overwrite Data Register Offset */
#define FCW_HSMUDAT_REG_OFST           _UINT32_(0xB0)      /* (FCW_HSMUDAT) HSM Tamper Upper Overwrite Data Register Offset */
#define FCW_HSMUDAT0_REG_OFST          _UINT32_(0xB0)      /* (FCW_HSMUDAT0) HSM Tamper Upper Overwrite Data Register Offset */
#define FCW_HSMUDAT1_REG_OFST          _UINT32_(0xB4)      /* (FCW_HSMUDAT1) HSM Tamper Upper Overwrite Data Register Offset */
#define FCW_HSMUDAT2_REG_OFST          _UINT32_(0xB8)      /* (FCW_HSMUDAT2) HSM Tamper Upper Overwrite Data Register Offset */
#define FCW_HSMUDAT3_REG_OFST          _UINT32_(0xBC)      /* (FCW_HSMUDAT3) HSM Tamper Upper Overwrite Data Register Offset */
#define FCW_HSMUDAT4_REG_OFST          _UINT32_(0xC0)      /* (FCW_HSMUDAT4) HSM Tamper Upper Overwrite Data Register Offset */
#define FCW_HSMUDAT5_REG_OFST          _UINT32_(0xC4)      /* (FCW_HSMUDAT5) HSM Tamper Upper Overwrite Data Register Offset */
#define FCW_HSMUDAT6_REG_OFST          _UINT32_(0xC8)      /* (FCW_HSMUDAT6) HSM Tamper Upper Overwrite Data Register Offset */
#define FCW_HSMUDAT7_REG_OFST          _UINT32_(0xCC)      /* (FCW_HSMUDAT7) HSM Tamper Upper Overwrite Data Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief FCW register API structure */
typedef struct
{  /* Flash Write Control (FCW) */
  __IO  uint32_t                       FCW_CTRLA;          /**< Offset: 0x00 (R/W  32) NVM Write Control Register */
  __IO  uint32_t                       FCW_CTRLB;          /**< Offset: 0x04 (R/W  32) NVM Control B Register */
  __IO  uint32_t                       FCW_MUTEX;          /**< Offset: 0x08 (R/W  32) NVM MUTEX Register */
  __IO  uint32_t                       FCW_INTENCLR;       /**< Offset: 0x0C (R/W  32) NVM Interrupt Enable Clear Register */
  __IO  uint32_t                       FCW_INTENSET;       /**< Offset: 0x10 (R/W  32) NVM Interrupt Enable SET Register */
  __IO  uint32_t                       FCW_INTFLAG;        /**< Offset: 0x14 (R/W  32) NVM Interrupt Flag Register */
  __IO  uint32_t                       FCW_STATUS;         /**< Offset: 0x18 (R/W  32) NVM Status Register */
  __IO  uint32_t                       FCW_KEY;            /**< Offset: 0x1C (R/W  32) SFR Unlock Register */
  __IO  uint32_t                       FCW_ADDR;           /**< Offset: 0x20 (R/W  32) Flash Address Register */
  __IO  uint32_t                       FCW_SRCADDR;        /**< Offset: 0x24 (R/W  32) Source Data Address Register */
  __IO  uint32_t                       FCW_DATA[8];        /**< Offset: 0x28 (R/W  32) Flash Write Data Register */
  __IO  uint32_t                       FCW_SWAP;           /**< Offset: 0x48 (R/W  32) NVM Panel Swap Register */
  __IO  uint32_t                       FCW_PWP[8];         /**< Offset: 0x4C (R/W  32) PFM Write Protect Region 0 */
  __IO  uint32_t                       FCW_LBWP;           /**< Offset: 0x6C (R/W  32) Lower BFM Write Protect Register */
  __IO  uint32_t                       FCW_UBWP;           /**< Offset: 0x70 (R/W  32) Upper BFM Write Protect Register */
  __IO  uint32_t                       FCW_UOWP;           /**< Offset: 0x74 (R/W  32) User OTP Write Protect Register */
  __IO  uint32_t                       FCW_CWP;            /**< Offset: 0x78 (R/W  32) CFM Page Write Protect Register */
  __I   uint8_t                        Reserved1[0x04];
  __IO  uint32_t                       FCW_HSMINTENCLR;    /**< Offset: 0x80 (R/W  32) HSM NVM Interrupt Enable Clear Register */
  __IO  uint32_t                       FCW_HSMINTENSET;    /**< Offset: 0x84 (R/W  32) HSM NVM Interrupt Enable SET Register */
  __IO  uint32_t                       FCW_HSMINTFLAG;     /**< Offset: 0x88 (R/W  32) HSM NVM Interrupt Flag Register */
  __IO  uint32_t                       FCW_HSMCWP;         /**< Offset: 0x8C (R/W  32) HSM CFG Write Protect Register */
  __IO  uint32_t                       FCW_HSMLDAT[8];     /**< Offset: 0x90 (R/W  32) HSM Tamper Lower Overwrite Data Register */
  __IO  uint32_t                       FCW_HSMUDAT[8];     /**< Offset: 0xB0 (R/W  32) HSM Tamper Upper Overwrite Data Register */
} fcw_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA90_FCW_COMPONENT_H_ */
