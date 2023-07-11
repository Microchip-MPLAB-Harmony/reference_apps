/*
 * Component description for WDT
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
#ifndef _SAM9X7_WDT_COMPONENT_H_
#define _SAM9X7_WDT_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR WDT                                          */
/* ************************************************************************** */

/* -------- WDT_CR : (WDT Offset: 0x00) ( /W 32) Control Register -------- */
#define WDT_CR_WDRSTT_Pos                     _UINT32_(0)                                          /* (WDT_CR) Watchdog Restart Position */
#define WDT_CR_WDRSTT_Msk                     (_UINT32_(0x1) << WDT_CR_WDRSTT_Pos)                 /* (WDT_CR) Watchdog Restart Mask */
#define WDT_CR_WDRSTT(value)                  (WDT_CR_WDRSTT_Msk & (_UINT32_(value) << WDT_CR_WDRSTT_Pos)) /* Assigment of value for WDRSTT in the WDT_CR register */
#define   WDT_CR_WDRSTT_0_Val                 _UINT32_(0x0)                                        /* (WDT_CR) No effect.  */
#define   WDT_CR_WDRSTT_1_Val                 _UINT32_(0x1)                                        /* (WDT_CR) Restarts the WDT if KEY is written to 0xA5.  */
#define WDT_CR_WDRSTT_0                       (WDT_CR_WDRSTT_0_Val << WDT_CR_WDRSTT_Pos)           /* (WDT_CR) No effect. Position  */
#define WDT_CR_WDRSTT_1                       (WDT_CR_WDRSTT_1_Val << WDT_CR_WDRSTT_Pos)           /* (WDT_CR) Restarts the WDT if KEY is written to 0xA5. Position  */
#define WDT_CR_LOCKMR_Pos                     _UINT32_(4)                                          /* (WDT_CR) Lock Mode Register Write Access Position */
#define WDT_CR_LOCKMR_Msk                     (_UINT32_(0x1) << WDT_CR_LOCKMR_Pos)                 /* (WDT_CR) Lock Mode Register Write Access Mask */
#define WDT_CR_LOCKMR(value)                  (WDT_CR_LOCKMR_Msk & (_UINT32_(value) << WDT_CR_LOCKMR_Pos)) /* Assigment of value for LOCKMR in the WDT_CR register */
#define   WDT_CR_LOCKMR_0_Val                 _UINT32_(0x0)                                        /* (WDT_CR) No effect.  */
#define   WDT_CR_LOCKMR_1_Val                 _UINT32_(0x1)                                        /* (WDT_CR) Locks the configuration registers if KEY is written to 0xA5. Write accesses to WDT_MR, WDT_WLR and WDT_ILR have no effect.  */
#define WDT_CR_LOCKMR_0                       (WDT_CR_LOCKMR_0_Val << WDT_CR_LOCKMR_Pos)           /* (WDT_CR) No effect. Position  */
#define WDT_CR_LOCKMR_1                       (WDT_CR_LOCKMR_1_Val << WDT_CR_LOCKMR_Pos)           /* (WDT_CR) Locks the configuration registers if KEY is written to 0xA5. Write accesses to WDT_MR, WDT_WLR and WDT_ILR have no effect. Position  */
#define WDT_CR_KEY_Pos                        _UINT32_(24)                                         /* (WDT_CR) Password Position */
#define WDT_CR_KEY_Msk                        (_UINT32_(0xFF) << WDT_CR_KEY_Pos)                   /* (WDT_CR) Password Mask */
#define WDT_CR_KEY(value)                     (WDT_CR_KEY_Msk & (_UINT32_(value) << WDT_CR_KEY_Pos)) /* Assigment of value for KEY in the WDT_CR register */
#define   WDT_CR_KEY_PASSWD_Val               _UINT32_(0xA5)                                       /* (WDT_CR) Writing any other value in this field aborts the write operation.  */
#define WDT_CR_KEY_PASSWD                     (WDT_CR_KEY_PASSWD_Val << WDT_CR_KEY_Pos)            /* (WDT_CR) Writing any other value in this field aborts the write operation. Position  */
#define WDT_CR_Msk                            _UINT32_(0xFF000011)                                 /* (WDT_CR) Register Mask  */


/* -------- WDT_MR : (WDT Offset: 0x04) (R/W 32) Mode Register -------- */
#define WDT_MR_RESETVALUE                     _UINT32_(0x30)                                       /*  (WDT_MR) Mode Register  Reset Value */

#define WDT_MR_PERIODRST_Pos                  _UINT32_(4)                                          /* (WDT_MR) Period Reset Position */
#define WDT_MR_PERIODRST_Msk                  (_UINT32_(0x1) << WDT_MR_PERIODRST_Pos)              /* (WDT_MR) Period Reset Mask */
#define WDT_MR_PERIODRST(value)               (WDT_MR_PERIODRST_Msk & (_UINT32_(value) << WDT_MR_PERIODRST_Pos)) /* Assigment of value for PERIODRST in the WDT_MR register */
#define   WDT_MR_PERIODRST_0_Val              _UINT32_(0x0)                                        /* (WDT_MR) No reset is generated if the WDT down counter reaches 0.  */
#define   WDT_MR_PERIODRST_1_Val              _UINT32_(0x1)                                        /* (WDT_MR) A reset is generated once the WDT down counter reaches 0.  */
#define WDT_MR_PERIODRST_0                    (WDT_MR_PERIODRST_0_Val << WDT_MR_PERIODRST_Pos)     /* (WDT_MR) No reset is generated if the WDT down counter reaches 0. Position  */
#define WDT_MR_PERIODRST_1                    (WDT_MR_PERIODRST_1_Val << WDT_MR_PERIODRST_Pos)     /* (WDT_MR) A reset is generated once the WDT down counter reaches 0. Position  */
#define WDT_MR_RPTHRST_Pos                    _UINT32_(5)                                          /* (WDT_MR) Minimum Restart Period Position */
#define WDT_MR_RPTHRST_Msk                    (_UINT32_(0x1) << WDT_MR_RPTHRST_Pos)                /* (WDT_MR) Minimum Restart Period Mask */
#define WDT_MR_RPTHRST(value)                 (WDT_MR_RPTHRST_Msk & (_UINT32_(value) << WDT_MR_RPTHRST_Pos)) /* Assigment of value for RPTHRST in the WDT_MR register */
#define   WDT_MR_RPTHRST_0_Val                _UINT32_(0x0)                                        /* (WDT_MR) No reset is generated if the WDT is restarted before the RPTH threshold.  */
#define   WDT_MR_RPTHRST_1_Val                _UINT32_(0x1)                                        /* (WDT_MR) A reset is generated if the WDT is restarted before the RPTH threshold.  */
#define WDT_MR_RPTHRST_0                      (WDT_MR_RPTHRST_0_Val << WDT_MR_RPTHRST_Pos)         /* (WDT_MR) No reset is generated if the WDT is restarted before the RPTH threshold. Position  */
#define WDT_MR_RPTHRST_1                      (WDT_MR_RPTHRST_1_Val << WDT_MR_RPTHRST_Pos)         /* (WDT_MR) A reset is generated if the WDT is restarted before the RPTH threshold. Position  */
#define WDT_MR_WDDIS_Pos                      _UINT32_(12)                                         /* (WDT_MR) Watchdog Disable Position */
#define WDT_MR_WDDIS_Msk                      (_UINT32_(0x1) << WDT_MR_WDDIS_Pos)                  /* (WDT_MR) Watchdog Disable Mask */
#define WDT_MR_WDDIS(value)                   (WDT_MR_WDDIS_Msk & (_UINT32_(value) << WDT_MR_WDDIS_Pos)) /* Assigment of value for WDDIS in the WDT_MR register */
#define   WDT_MR_WDDIS_0_Val                  _UINT32_(0x0)                                        /* (WDT_MR) Enables the WDT.  */
#define   WDT_MR_WDDIS_1_Val                  _UINT32_(0x1)                                        /* (WDT_MR) Disables the WDT.  */
#define WDT_MR_WDDIS_0                        (WDT_MR_WDDIS_0_Val << WDT_MR_WDDIS_Pos)             /* (WDT_MR) Enables the WDT. Position  */
#define WDT_MR_WDDIS_1                        (WDT_MR_WDDIS_1_Val << WDT_MR_WDDIS_Pos)             /* (WDT_MR) Disables the WDT. Position  */
#define WDT_MR_WDDBGHLT_Pos                   _UINT32_(28)                                         /* (WDT_MR) Watchdog Debug Halt Position */
#define WDT_MR_WDDBGHLT_Msk                   (_UINT32_(0x1) << WDT_MR_WDDBGHLT_Pos)               /* (WDT_MR) Watchdog Debug Halt Mask */
#define WDT_MR_WDDBGHLT(value)                (WDT_MR_WDDBGHLT_Msk & (_UINT32_(value) << WDT_MR_WDDBGHLT_Pos)) /* Assigment of value for WDDBGHLT in the WDT_MR register */
#define   WDT_MR_WDDBGHLT_0_Val               _UINT32_(0x0)                                        /* (WDT_MR) The WDT runs when the processor is in debug state.  */
#define   WDT_MR_WDDBGHLT_1_Val               _UINT32_(0x1)                                        /* (WDT_MR) The WDT stops when the processor is in debug state.  */
#define WDT_MR_WDDBGHLT_0                     (WDT_MR_WDDBGHLT_0_Val << WDT_MR_WDDBGHLT_Pos)       /* (WDT_MR) The WDT runs when the processor is in debug state. Position  */
#define WDT_MR_WDDBGHLT_1                     (WDT_MR_WDDBGHLT_1_Val << WDT_MR_WDDBGHLT_Pos)       /* (WDT_MR) The WDT stops when the processor is in debug state. Position  */
#define WDT_MR_WDIDLEHLT_Pos                  _UINT32_(29)                                         /* (WDT_MR) Watchdog Idle Halt Position */
#define WDT_MR_WDIDLEHLT_Msk                  (_UINT32_(0x1) << WDT_MR_WDIDLEHLT_Pos)              /* (WDT_MR) Watchdog Idle Halt Mask */
#define WDT_MR_WDIDLEHLT(value)               (WDT_MR_WDIDLEHLT_Msk & (_UINT32_(value) << WDT_MR_WDIDLEHLT_Pos)) /* Assigment of value for WDIDLEHLT in the WDT_MR register */
#define   WDT_MR_WDIDLEHLT_0_Val              _UINT32_(0x0)                                        /* (WDT_MR) The WDT runs when the system is in idle state.  */
#define   WDT_MR_WDIDLEHLT_1_Val              _UINT32_(0x1)                                        /* (WDT_MR) The WDT stops when the system is in idle state.  */
#define WDT_MR_WDIDLEHLT_0                    (WDT_MR_WDIDLEHLT_0_Val << WDT_MR_WDIDLEHLT_Pos)     /* (WDT_MR) The WDT runs when the system is in idle state. Position  */
#define WDT_MR_WDIDLEHLT_1                    (WDT_MR_WDIDLEHLT_1_Val << WDT_MR_WDIDLEHLT_Pos)     /* (WDT_MR) The WDT stops when the system is in idle state. Position  */
#define WDT_MR_Msk                            _UINT32_(0x30001030)                                 /* (WDT_MR) Register Mask  */


/* -------- WDT_VR : (WDT Offset: 0x08) ( R/ 32) Value Register -------- */
#define WDT_VR_RESETVALUE                     _UINT32_(0x00)                                       /*  (WDT_VR) Value Register  Reset Value */

#define WDT_VR_COUNTER_Pos                    _UINT32_(0)                                          /* (WDT_VR) Watchdog Down Counter Value Position */
#define WDT_VR_COUNTER_Msk                    (_UINT32_(0xFFF) << WDT_VR_COUNTER_Pos)              /* (WDT_VR) Watchdog Down Counter Value Mask */
#define WDT_VR_COUNTER(value)                 (WDT_VR_COUNTER_Msk & (_UINT32_(value) << WDT_VR_COUNTER_Pos)) /* Assigment of value for COUNTER in the WDT_VR register */
#define WDT_VR_Msk                            _UINT32_(0x00000FFF)                                 /* (WDT_VR) Register Mask  */


/* -------- WDT_WLR : (WDT Offset: 0x0C) (R/W 32) Window Level Register -------- */
#define WDT_WLR_RESETVALUE                    _UINT32_(0xFFF)                                      /*  (WDT_WLR) Window Level Register  Reset Value */

#define WDT_WLR_PERIOD_Pos                    _UINT32_(0)                                          /* (WDT_WLR) Watchdog Period Position */
#define WDT_WLR_PERIOD_Msk                    (_UINT32_(0xFFF) << WDT_WLR_PERIOD_Pos)              /* (WDT_WLR) Watchdog Period Mask */
#define WDT_WLR_PERIOD(value)                 (WDT_WLR_PERIOD_Msk & (_UINT32_(value) << WDT_WLR_PERIOD_Pos)) /* Assigment of value for PERIOD in the WDT_WLR register */
#define WDT_WLR_RPTH_Pos                      _UINT32_(16)                                         /* (WDT_WLR) Repeat Threshold Position */
#define WDT_WLR_RPTH_Msk                      (_UINT32_(0xFFF) << WDT_WLR_RPTH_Pos)                /* (WDT_WLR) Repeat Threshold Mask */
#define WDT_WLR_RPTH(value)                   (WDT_WLR_RPTH_Msk & (_UINT32_(value) << WDT_WLR_RPTH_Pos)) /* Assigment of value for RPTH in the WDT_WLR register */
#define WDT_WLR_Msk                           _UINT32_(0x0FFF0FFF)                                 /* (WDT_WLR) Register Mask  */


/* -------- WDT_ILR : (WDT Offset: 0x10) (R/W 32) Interrupt Level Register -------- */
#define WDT_ILR_RESETVALUE                    _UINT32_(0xFFF)                                      /*  (WDT_ILR) Interrupt Level Register  Reset Value */

#define WDT_ILR_LVLTH_Pos                     _UINT32_(0)                                          /* (WDT_ILR) Level Threshold Position */
#define WDT_ILR_LVLTH_Msk                     (_UINT32_(0xFFF) << WDT_ILR_LVLTH_Pos)               /* (WDT_ILR) Level Threshold Mask */
#define WDT_ILR_LVLTH(value)                  (WDT_ILR_LVLTH_Msk & (_UINT32_(value) << WDT_ILR_LVLTH_Pos)) /* Assigment of value for LVLTH in the WDT_ILR register */
#define WDT_ILR_Msk                           _UINT32_(0x00000FFF)                                 /* (WDT_ILR) Register Mask  */


/* -------- WDT_IER : (WDT Offset: 0x14) ( /W 32) Interrupt Enable Register -------- */
#define WDT_IER_PERINT_Pos                    _UINT32_(0)                                          /* (WDT_IER) Period Interrupt Enable Position */
#define WDT_IER_PERINT_Msk                    (_UINT32_(0x1) << WDT_IER_PERINT_Pos)                /* (WDT_IER) Period Interrupt Enable Mask */
#define WDT_IER_PERINT(value)                 (WDT_IER_PERINT_Msk & (_UINT32_(value) << WDT_IER_PERINT_Pos)) /* Assigment of value for PERINT in the WDT_IER register */
#define WDT_IER_RPTHINT_Pos                   _UINT32_(1)                                          /* (WDT_IER) Repeat Threshold Interrupt Enable Position */
#define WDT_IER_RPTHINT_Msk                   (_UINT32_(0x1) << WDT_IER_RPTHINT_Pos)               /* (WDT_IER) Repeat Threshold Interrupt Enable Mask */
#define WDT_IER_RPTHINT(value)                (WDT_IER_RPTHINT_Msk & (_UINT32_(value) << WDT_IER_RPTHINT_Pos)) /* Assigment of value for RPTHINT in the WDT_IER register */
#define WDT_IER_LVLINT_Pos                    _UINT32_(2)                                          /* (WDT_IER) Interrupt Level Threshold Interrupt Enable Position */
#define WDT_IER_LVLINT_Msk                    (_UINT32_(0x1) << WDT_IER_LVLINT_Pos)                /* (WDT_IER) Interrupt Level Threshold Interrupt Enable Mask */
#define WDT_IER_LVLINT(value)                 (WDT_IER_LVLINT_Msk & (_UINT32_(value) << WDT_IER_LVLINT_Pos)) /* Assigment of value for LVLINT in the WDT_IER register */
#define WDT_IER_Msk                           _UINT32_(0x00000007)                                 /* (WDT_IER) Register Mask  */


/* -------- WDT_IDR : (WDT Offset: 0x18) ( /W 32) Interrupt Disable Register -------- */
#define WDT_IDR_PERINT_Pos                    _UINT32_(0)                                          /* (WDT_IDR) Period Interrupt Disable Position */
#define WDT_IDR_PERINT_Msk                    (_UINT32_(0x1) << WDT_IDR_PERINT_Pos)                /* (WDT_IDR) Period Interrupt Disable Mask */
#define WDT_IDR_PERINT(value)                 (WDT_IDR_PERINT_Msk & (_UINT32_(value) << WDT_IDR_PERINT_Pos)) /* Assigment of value for PERINT in the WDT_IDR register */
#define WDT_IDR_RPTHINT_Pos                   _UINT32_(1)                                          /* (WDT_IDR) Repeat Threshold Interrupt Disable Position */
#define WDT_IDR_RPTHINT_Msk                   (_UINT32_(0x1) << WDT_IDR_RPTHINT_Pos)               /* (WDT_IDR) Repeat Threshold Interrupt Disable Mask */
#define WDT_IDR_RPTHINT(value)                (WDT_IDR_RPTHINT_Msk & (_UINT32_(value) << WDT_IDR_RPTHINT_Pos)) /* Assigment of value for RPTHINT in the WDT_IDR register */
#define WDT_IDR_LVLINT_Pos                    _UINT32_(2)                                          /* (WDT_IDR) Interrupt Level Threshold Interrupt Disable Position */
#define WDT_IDR_LVLINT_Msk                    (_UINT32_(0x1) << WDT_IDR_LVLINT_Pos)                /* (WDT_IDR) Interrupt Level Threshold Interrupt Disable Mask */
#define WDT_IDR_LVLINT(value)                 (WDT_IDR_LVLINT_Msk & (_UINT32_(value) << WDT_IDR_LVLINT_Pos)) /* Assigment of value for LVLINT in the WDT_IDR register */
#define WDT_IDR_Msk                           _UINT32_(0x00000007)                                 /* (WDT_IDR) Register Mask  */


/* -------- WDT_ISR : (WDT Offset: 0x1C) ( R/ 32) Interrupt Status Register -------- */
#define WDT_ISR_RESETVALUE                    _UINT32_(0x00)                                       /*  (WDT_ISR) Interrupt Status Register  Reset Value */

#define WDT_ISR_PERINT_Pos                    _UINT32_(0)                                          /* (WDT_ISR) Period Interrupt Status (cleared on read) Position */
#define WDT_ISR_PERINT_Msk                    (_UINT32_(0x1) << WDT_ISR_PERINT_Pos)                /* (WDT_ISR) Period Interrupt Status (cleared on read) Mask */
#define WDT_ISR_PERINT(value)                 (WDT_ISR_PERINT_Msk & (_UINT32_(value) << WDT_ISR_PERINT_Pos)) /* Assigment of value for PERINT in the WDT_ISR register */
#define   WDT_ISR_PERINT_0_Val                _UINT32_(0x0)                                        /* (WDT_ISR) No period failure has occurred in the WDT since the last read of WDT_ISR.  */
#define   WDT_ISR_PERINT_1_Val                _UINT32_(0x1)                                        /* (WDT_ISR) At least one period failure has occurred in the WDT since the last read of WDT_ISR.  */
#define WDT_ISR_PERINT_0                      (WDT_ISR_PERINT_0_Val << WDT_ISR_PERINT_Pos)         /* (WDT_ISR) No period failure has occurred in the WDT since the last read of WDT_ISR. Position  */
#define WDT_ISR_PERINT_1                      (WDT_ISR_PERINT_1_Val << WDT_ISR_PERINT_Pos)         /* (WDT_ISR) At least one period failure has occurred in the WDT since the last read of WDT_ISR. Position  */
#define WDT_ISR_RPTHINT_Pos                   _UINT32_(1)                                          /* (WDT_ISR) Repeat Threshold Interrupt Status (cleared on read) Position */
#define WDT_ISR_RPTHINT_Msk                   (_UINT32_(0x1) << WDT_ISR_RPTHINT_Pos)               /* (WDT_ISR) Repeat Threshold Interrupt Status (cleared on read) Mask */
#define WDT_ISR_RPTHINT(value)                (WDT_ISR_RPTHINT_Msk & (_UINT32_(value) << WDT_ISR_RPTHINT_Pos)) /* Assigment of value for RPTHINT in the WDT_ISR register */
#define   WDT_ISR_RPTHINT_0_Val               _UINT32_(0x0)                                        /* (WDT_ISR) No repeat threshold failure has occurred in the WDT since the last read of WDT_ISR.  */
#define   WDT_ISR_RPTHINT_1_Val               _UINT32_(0x1)                                        /* (WDT_ISR) At least one repeat threshold failure has occurred in the WDT since the last read of WDT_ISR.  */
#define WDT_ISR_RPTHINT_0                     (WDT_ISR_RPTHINT_0_Val << WDT_ISR_RPTHINT_Pos)       /* (WDT_ISR) No repeat threshold failure has occurred in the WDT since the last read of WDT_ISR. Position  */
#define WDT_ISR_RPTHINT_1                     (WDT_ISR_RPTHINT_1_Val << WDT_ISR_RPTHINT_Pos)       /* (WDT_ISR) At least one repeat threshold failure has occurred in the WDT since the last read of WDT_ISR. Position  */
#define WDT_ISR_LVLINT_Pos                    _UINT32_(2)                                          /* (WDT_ISR) Interrupt Level Threshold Interrupt Status (cleared on read) Position */
#define WDT_ISR_LVLINT_Msk                    (_UINT32_(0x1) << WDT_ISR_LVLINT_Pos)                /* (WDT_ISR) Interrupt Level Threshold Interrupt Status (cleared on read) Mask */
#define WDT_ISR_LVLINT(value)                 (WDT_ISR_LVLINT_Msk & (_UINT32_(value) << WDT_ISR_LVLINT_Pos)) /* Assigment of value for LVLINT in the WDT_ISR register */
#define   WDT_ISR_LVLINT_0_Val                _UINT32_(0x0)                                        /* (WDT_ISR) No level threshold failure has occurred in the WDT since the last read of WDT_ISR.  */
#define   WDT_ISR_LVLINT_1_Val                _UINT32_(0x1)                                        /* (WDT_ISR) At least one level threshold failure has occurred in the WDT since the last read of WDT_ISR.  */
#define WDT_ISR_LVLINT_0                      (WDT_ISR_LVLINT_0_Val << WDT_ISR_LVLINT_Pos)         /* (WDT_ISR) No level threshold failure has occurred in the WDT since the last read of WDT_ISR. Position  */
#define WDT_ISR_LVLINT_1                      (WDT_ISR_LVLINT_1_Val << WDT_ISR_LVLINT_Pos)         /* (WDT_ISR) At least one level threshold failure has occurred in the WDT since the last read of WDT_ISR. Position  */
#define WDT_ISR_Msk                           _UINT32_(0x00000007)                                 /* (WDT_ISR) Register Mask  */


/* -------- WDT_IMR : (WDT Offset: 0x20) ( R/ 32) Interrupt Mask Register -------- */
#define WDT_IMR_RESETVALUE                    _UINT32_(0x00)                                       /*  (WDT_IMR) Interrupt Mask Register  Reset Value */

#define WDT_IMR_PERINT_Pos                    _UINT32_(0)                                          /* (WDT_IMR) Period Interrupt Mask Position */
#define WDT_IMR_PERINT_Msk                    (_UINT32_(0x1) << WDT_IMR_PERINT_Pos)                /* (WDT_IMR) Period Interrupt Mask Mask */
#define WDT_IMR_PERINT(value)                 (WDT_IMR_PERINT_Msk & (_UINT32_(value) << WDT_IMR_PERINT_Pos)) /* Assigment of value for PERINT in the WDT_IMR register */
#define WDT_IMR_RPTHINT_Pos                   _UINT32_(1)                                          /* (WDT_IMR) Repeat Threshold Interrupt Mask Position */
#define WDT_IMR_RPTHINT_Msk                   (_UINT32_(0x1) << WDT_IMR_RPTHINT_Pos)               /* (WDT_IMR) Repeat Threshold Interrupt Mask Mask */
#define WDT_IMR_RPTHINT(value)                (WDT_IMR_RPTHINT_Msk & (_UINT32_(value) << WDT_IMR_RPTHINT_Pos)) /* Assigment of value for RPTHINT in the WDT_IMR register */
#define WDT_IMR_LVLINT_Pos                    _UINT32_(2)                                          /* (WDT_IMR) Interrupt Level Threshold Interrupt Mask Position */
#define WDT_IMR_LVLINT_Msk                    (_UINT32_(0x1) << WDT_IMR_LVLINT_Pos)                /* (WDT_IMR) Interrupt Level Threshold Interrupt Mask Mask */
#define WDT_IMR_LVLINT(value)                 (WDT_IMR_LVLINT_Msk & (_UINT32_(value) << WDT_IMR_LVLINT_Pos)) /* Assigment of value for LVLINT in the WDT_IMR register */
#define WDT_IMR_Msk                           _UINT32_(0x00000007)                                 /* (WDT_IMR) Register Mask  */


/** \brief WDT register offsets definitions */
#define WDT_CR_REG_OFST                _UINT32_(0x00)      /* (WDT_CR) Control Register Offset */
#define WDT_MR_REG_OFST                _UINT32_(0x04)      /* (WDT_MR) Mode Register Offset */
#define WDT_VR_REG_OFST                _UINT32_(0x08)      /* (WDT_VR) Value Register Offset */
#define WDT_WLR_REG_OFST               _UINT32_(0x0C)      /* (WDT_WLR) Window Level Register Offset */
#define WDT_ILR_REG_OFST               _UINT32_(0x10)      /* (WDT_ILR) Interrupt Level Register Offset */
#define WDT_IER_REG_OFST               _UINT32_(0x14)      /* (WDT_IER) Interrupt Enable Register Offset */
#define WDT_IDR_REG_OFST               _UINT32_(0x18)      /* (WDT_IDR) Interrupt Disable Register Offset */
#define WDT_ISR_REG_OFST               _UINT32_(0x1C)      /* (WDT_ISR) Interrupt Status Register Offset */
#define WDT_IMR_REG_OFST               _UINT32_(0x20)      /* (WDT_IMR) Interrupt Mask Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief WDT register API structure */
typedef struct
{  /* Watchdog Timer */
  __O   uint32_t                       WDT_CR;             /**< Offset: 0x00 ( /W  32) Control Register */
  __IO  uint32_t                       WDT_MR;             /**< Offset: 0x04 (R/W  32) Mode Register */
  __I   uint32_t                       WDT_VR;             /**< Offset: 0x08 (R/   32) Value Register */
  __IO  uint32_t                       WDT_WLR;            /**< Offset: 0x0C (R/W  32) Window Level Register */
  __IO  uint32_t                       WDT_ILR;            /**< Offset: 0x10 (R/W  32) Interrupt Level Register */
  __O   uint32_t                       WDT_IER;            /**< Offset: 0x14 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       WDT_IDR;            /**< Offset: 0x18 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       WDT_ISR;            /**< Offset: 0x1C (R/   32) Interrupt Status Register */
  __I   uint32_t                       WDT_IMR;            /**< Offset: 0x20 (R/   32) Interrupt Mask Register */
} wdt_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X7_WDT_COMPONENT_H_ */
