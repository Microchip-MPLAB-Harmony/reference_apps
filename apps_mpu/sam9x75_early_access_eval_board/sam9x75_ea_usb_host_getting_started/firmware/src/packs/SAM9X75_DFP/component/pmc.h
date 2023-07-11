/*
 * Component description for PMC
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
#ifndef _SAM9X7_PMC_COMPONENT_H_
#define _SAM9X7_PMC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR PMC                                          */
/* ************************************************************************** */

/* -------- PMC_SCER : (PMC Offset: 0x00) ( /W 32) System Clock Enable Register -------- */
#define PMC_SCER_DDRCK_Pos                    _UINT32_(2)                                          /* (PMC_SCER) MPDDRC/SDRAMC Clock Enable Position */
#define PMC_SCER_DDRCK_Msk                    (_UINT32_(0x1) << PMC_SCER_DDRCK_Pos)                /* (PMC_SCER) MPDDRC/SDRAMC Clock Enable Mask */
#define PMC_SCER_DDRCK(value)                 (PMC_SCER_DDRCK_Msk & (_UINT32_(value) << PMC_SCER_DDRCK_Pos)) /* Assigment of value for DDRCK in the PMC_SCER register */
#define   PMC_SCER_DDRCK_0_Val                _UINT32_(0x0)                                        /* (PMC_SCER) No effect.  */
#define   PMC_SCER_DDRCK_1_Val                _UINT32_(0x1)                                        /* (PMC_SCER) Enables the MPDDRC or SDRAMC clock.  */
#define PMC_SCER_DDRCK_0                      (PMC_SCER_DDRCK_0_Val << PMC_SCER_DDRCK_Pos)         /* (PMC_SCER) No effect. Position  */
#define PMC_SCER_DDRCK_1                      (PMC_SCER_DDRCK_1_Val << PMC_SCER_DDRCK_Pos)         /* (PMC_SCER) Enables the MPDDRC or SDRAMC clock. Position  */
#define PMC_SCER_UHP_Pos                      _UINT32_(6)                                          /* (PMC_SCER) USB Host OHCI Clocks Enable Position */
#define PMC_SCER_UHP_Msk                      (_UINT32_(0x1) << PMC_SCER_UHP_Pos)                  /* (PMC_SCER) USB Host OHCI Clocks Enable Mask */
#define PMC_SCER_UHP(value)                   (PMC_SCER_UHP_Msk & (_UINT32_(value) << PMC_SCER_UHP_Pos)) /* Assigment of value for UHP in the PMC_SCER register */
#define   PMC_SCER_UHP_0_Val                  _UINT32_(0x0)                                        /* (PMC_SCER) No effect.  */
#define   PMC_SCER_UHP_1_Val                  _UINT32_(0x1)                                        /* (PMC_SCER) Enables the UHP48M and UHP12M OHCI clocks.  */
#define PMC_SCER_UHP_0                        (PMC_SCER_UHP_0_Val << PMC_SCER_UHP_Pos)             /* (PMC_SCER) No effect. Position  */
#define PMC_SCER_UHP_1                        (PMC_SCER_UHP_1_Val << PMC_SCER_UHP_Pos)             /* (PMC_SCER) Enables the UHP48M and UHP12M OHCI clocks. Position  */
#define PMC_SCER_PCK0_Pos                     _UINT32_(8)                                          /* (PMC_SCER) Programmable Clock 0 Output Enable Position */
#define PMC_SCER_PCK0_Msk                     (_UINT32_(0x1) << PMC_SCER_PCK0_Pos)                 /* (PMC_SCER) Programmable Clock 0 Output Enable Mask */
#define PMC_SCER_PCK0(value)                  (PMC_SCER_PCK0_Msk & (_UINT32_(value) << PMC_SCER_PCK0_Pos)) /* Assigment of value for PCK0 in the PMC_SCER register */
#define   PMC_SCER_PCK0_0_Val                 _UINT32_(0x0)                                        /* (PMC_SCER) No effect.  */
#define   PMC_SCER_PCK0_1_Val                 _UINT32_(0x1)                                        /* (PMC_SCER) Enables the corresponding Programmable Clock output.  */
#define PMC_SCER_PCK0_0                       (PMC_SCER_PCK0_0_Val << PMC_SCER_PCK0_Pos)           /* (PMC_SCER) No effect. Position  */
#define PMC_SCER_PCK0_1                       (PMC_SCER_PCK0_1_Val << PMC_SCER_PCK0_Pos)           /* (PMC_SCER) Enables the corresponding Programmable Clock output. Position  */
#define PMC_SCER_PCK1_Pos                     _UINT32_(9)                                          /* (PMC_SCER) Programmable Clock 1 Output Enable Position */
#define PMC_SCER_PCK1_Msk                     (_UINT32_(0x1) << PMC_SCER_PCK1_Pos)                 /* (PMC_SCER) Programmable Clock 1 Output Enable Mask */
#define PMC_SCER_PCK1(value)                  (PMC_SCER_PCK1_Msk & (_UINT32_(value) << PMC_SCER_PCK1_Pos)) /* Assigment of value for PCK1 in the PMC_SCER register */
#define   PMC_SCER_PCK1_0_Val                 _UINT32_(0x0)                                        /* (PMC_SCER) No effect.  */
#define   PMC_SCER_PCK1_1_Val                 _UINT32_(0x1)                                        /* (PMC_SCER) Enables the corresponding Programmable Clock output.  */
#define PMC_SCER_PCK1_0                       (PMC_SCER_PCK1_0_Val << PMC_SCER_PCK1_Pos)           /* (PMC_SCER) No effect. Position  */
#define PMC_SCER_PCK1_1                       (PMC_SCER_PCK1_1_Val << PMC_SCER_PCK1_Pos)           /* (PMC_SCER) Enables the corresponding Programmable Clock output. Position  */
#define PMC_SCER_QSPICLK_Pos                  _UINT32_(19)                                         /* (PMC_SCER) QSPI 2x Clock Enable Position */
#define PMC_SCER_QSPICLK_Msk                  (_UINT32_(0x1) << PMC_SCER_QSPICLK_Pos)              /* (PMC_SCER) QSPI 2x Clock Enable Mask */
#define PMC_SCER_QSPICLK(value)               (PMC_SCER_QSPICLK_Msk & (_UINT32_(value) << PMC_SCER_QSPICLK_Pos)) /* Assigment of value for QSPICLK in the PMC_SCER register */
#define   PMC_SCER_QSPICLK_0_Val              _UINT32_(0x0)                                        /* (PMC_SCER) No effect.  */
#define   PMC_SCER_QSPICLK_1_Val              _UINT32_(0x1)                                        /* (PMC_SCER) Enables the QSPI 2x clock.  */
#define PMC_SCER_QSPICLK_0                    (PMC_SCER_QSPICLK_0_Val << PMC_SCER_QSPICLK_Pos)     /* (PMC_SCER) No effect. Position  */
#define PMC_SCER_QSPICLK_1                    (PMC_SCER_QSPICLK_1_Val << PMC_SCER_QSPICLK_Pos)     /* (PMC_SCER) Enables the QSPI 2x clock. Position  */
#define PMC_SCER_Msk                          _UINT32_(0x00080344)                                 /* (PMC_SCER) Register Mask  */

#define PMC_SCER_PCK_Pos                      _UINT32_(8)                                          /* (PMC_SCER Position) Programmable Clock x Output Enable */
#define PMC_SCER_PCK_Msk                      (_UINT32_(0x3) << PMC_SCER_PCK_Pos)                  /* (PMC_SCER Mask) PCK */
#define PMC_SCER_PCK(value)                   (PMC_SCER_PCK_Msk & (_UINT32_(value) << PMC_SCER_PCK_Pos)) 

/* -------- PMC_SCDR : (PMC Offset: 0x04) ( /W 32) System Clock Disable Register -------- */
#define PMC_SCDR_DDRCK_Pos                    _UINT32_(2)                                          /* (PMC_SCDR) MPDDRC/SDRAMC Clock Disable Position */
#define PMC_SCDR_DDRCK_Msk                    (_UINT32_(0x1) << PMC_SCDR_DDRCK_Pos)                /* (PMC_SCDR) MPDDRC/SDRAMC Clock Disable Mask */
#define PMC_SCDR_DDRCK(value)                 (PMC_SCDR_DDRCK_Msk & (_UINT32_(value) << PMC_SCDR_DDRCK_Pos)) /* Assigment of value for DDRCK in the PMC_SCDR register */
#define   PMC_SCDR_DDRCK_0_Val                _UINT32_(0x0)                                        /* (PMC_SCDR) No effect.  */
#define   PMC_SCDR_DDRCK_1_Val                _UINT32_(0x1)                                        /* (PMC_SCDR) Disables the MPDDRC or SDRAMC clock.  */
#define PMC_SCDR_DDRCK_0                      (PMC_SCDR_DDRCK_0_Val << PMC_SCDR_DDRCK_Pos)         /* (PMC_SCDR) No effect. Position  */
#define PMC_SCDR_DDRCK_1                      (PMC_SCDR_DDRCK_1_Val << PMC_SCDR_DDRCK_Pos)         /* (PMC_SCDR) Disables the MPDDRC or SDRAMC clock. Position  */
#define PMC_SCDR_UHP_Pos                      _UINT32_(6)                                          /* (PMC_SCDR) USB Host OHCI Clocks Disable Position */
#define PMC_SCDR_UHP_Msk                      (_UINT32_(0x1) << PMC_SCDR_UHP_Pos)                  /* (PMC_SCDR) USB Host OHCI Clocks Disable Mask */
#define PMC_SCDR_UHP(value)                   (PMC_SCDR_UHP_Msk & (_UINT32_(value) << PMC_SCDR_UHP_Pos)) /* Assigment of value for UHP in the PMC_SCDR register */
#define   PMC_SCDR_UHP_0_Val                  _UINT32_(0x0)                                        /* (PMC_SCDR) No effect.  */
#define   PMC_SCDR_UHP_1_Val                  _UINT32_(0x1)                                        /* (PMC_SCDR) Disables the UHP48M and UHP12M OHCI clocks.  */
#define PMC_SCDR_UHP_0                        (PMC_SCDR_UHP_0_Val << PMC_SCDR_UHP_Pos)             /* (PMC_SCDR) No effect. Position  */
#define PMC_SCDR_UHP_1                        (PMC_SCDR_UHP_1_Val << PMC_SCDR_UHP_Pos)             /* (PMC_SCDR) Disables the UHP48M and UHP12M OHCI clocks. Position  */
#define PMC_SCDR_PCK0_Pos                     _UINT32_(8)                                          /* (PMC_SCDR) Programmable Clock 0 Output Disable Position */
#define PMC_SCDR_PCK0_Msk                     (_UINT32_(0x1) << PMC_SCDR_PCK0_Pos)                 /* (PMC_SCDR) Programmable Clock 0 Output Disable Mask */
#define PMC_SCDR_PCK0(value)                  (PMC_SCDR_PCK0_Msk & (_UINT32_(value) << PMC_SCDR_PCK0_Pos)) /* Assigment of value for PCK0 in the PMC_SCDR register */
#define   PMC_SCDR_PCK0_0_Val                 _UINT32_(0x0)                                        /* (PMC_SCDR) No effect.  */
#define   PMC_SCDR_PCK0_1_Val                 _UINT32_(0x1)                                        /* (PMC_SCDR) Disables the corresponding Programmable Clock output.  */
#define PMC_SCDR_PCK0_0                       (PMC_SCDR_PCK0_0_Val << PMC_SCDR_PCK0_Pos)           /* (PMC_SCDR) No effect. Position  */
#define PMC_SCDR_PCK0_1                       (PMC_SCDR_PCK0_1_Val << PMC_SCDR_PCK0_Pos)           /* (PMC_SCDR) Disables the corresponding Programmable Clock output. Position  */
#define PMC_SCDR_PCK1_Pos                     _UINT32_(9)                                          /* (PMC_SCDR) Programmable Clock 1 Output Disable Position */
#define PMC_SCDR_PCK1_Msk                     (_UINT32_(0x1) << PMC_SCDR_PCK1_Pos)                 /* (PMC_SCDR) Programmable Clock 1 Output Disable Mask */
#define PMC_SCDR_PCK1(value)                  (PMC_SCDR_PCK1_Msk & (_UINT32_(value) << PMC_SCDR_PCK1_Pos)) /* Assigment of value for PCK1 in the PMC_SCDR register */
#define   PMC_SCDR_PCK1_0_Val                 _UINT32_(0x0)                                        /* (PMC_SCDR) No effect.  */
#define   PMC_SCDR_PCK1_1_Val                 _UINT32_(0x1)                                        /* (PMC_SCDR) Disables the corresponding Programmable Clock output.  */
#define PMC_SCDR_PCK1_0                       (PMC_SCDR_PCK1_0_Val << PMC_SCDR_PCK1_Pos)           /* (PMC_SCDR) No effect. Position  */
#define PMC_SCDR_PCK1_1                       (PMC_SCDR_PCK1_1_Val << PMC_SCDR_PCK1_Pos)           /* (PMC_SCDR) Disables the corresponding Programmable Clock output. Position  */
#define PMC_SCDR_QSPICLK_Pos                  _UINT32_(19)                                         /* (PMC_SCDR) QSPI 2x Clock Disable Position */
#define PMC_SCDR_QSPICLK_Msk                  (_UINT32_(0x1) << PMC_SCDR_QSPICLK_Pos)              /* (PMC_SCDR) QSPI 2x Clock Disable Mask */
#define PMC_SCDR_QSPICLK(value)               (PMC_SCDR_QSPICLK_Msk & (_UINT32_(value) << PMC_SCDR_QSPICLK_Pos)) /* Assigment of value for QSPICLK in the PMC_SCDR register */
#define   PMC_SCDR_QSPICLK_0_Val              _UINT32_(0x0)                                        /* (PMC_SCDR) No effect.  */
#define   PMC_SCDR_QSPICLK_1_Val              _UINT32_(0x1)                                        /* (PMC_SCDR) Disables the QSPI 2x clock.  */
#define PMC_SCDR_QSPICLK_0                    (PMC_SCDR_QSPICLK_0_Val << PMC_SCDR_QSPICLK_Pos)     /* (PMC_SCDR) No effect. Position  */
#define PMC_SCDR_QSPICLK_1                    (PMC_SCDR_QSPICLK_1_Val << PMC_SCDR_QSPICLK_Pos)     /* (PMC_SCDR) Disables the QSPI 2x clock. Position  */
#define PMC_SCDR_Msk                          _UINT32_(0x00080344)                                 /* (PMC_SCDR) Register Mask  */

#define PMC_SCDR_PCK_Pos                      _UINT32_(8)                                          /* (PMC_SCDR Position) Programmable Clock x Output Disable */
#define PMC_SCDR_PCK_Msk                      (_UINT32_(0x3) << PMC_SCDR_PCK_Pos)                  /* (PMC_SCDR Mask) PCK */
#define PMC_SCDR_PCK(value)                   (PMC_SCDR_PCK_Msk & (_UINT32_(value) << PMC_SCDR_PCK_Pos)) 

/* -------- PMC_SCSR : (PMC Offset: 0x08) ( R/ 32) System Clock Status Register -------- */
#define PMC_SCSR_RESETVALUE                   _UINT32_(0x01)                                       /*  (PMC_SCSR) System Clock Status Register  Reset Value */

#define PMC_SCSR_DDRCK_Pos                    _UINT32_(2)                                          /* (PMC_SCSR) MPDDRC/SDRAMC Clock Status Position */
#define PMC_SCSR_DDRCK_Msk                    (_UINT32_(0x1) << PMC_SCSR_DDRCK_Pos)                /* (PMC_SCSR) MPDDRC/SDRAMC Clock Status Mask */
#define PMC_SCSR_DDRCK(value)                 (PMC_SCSR_DDRCK_Msk & (_UINT32_(value) << PMC_SCSR_DDRCK_Pos)) /* Assigment of value for DDRCK in the PMC_SCSR register */
#define   PMC_SCSR_DDRCK_0_Val                _UINT32_(0x0)                                        /* (PMC_SCSR) The MPDDRC or SDRAMC clock is disabled.  */
#define   PMC_SCSR_DDRCK_1_Val                _UINT32_(0x1)                                        /* (PMC_SCSR) The MPDDRC or SDRAMC clock is enabled.  */
#define PMC_SCSR_DDRCK_0                      (PMC_SCSR_DDRCK_0_Val << PMC_SCSR_DDRCK_Pos)         /* (PMC_SCSR) The MPDDRC or SDRAMC clock is disabled. Position  */
#define PMC_SCSR_DDRCK_1                      (PMC_SCSR_DDRCK_1_Val << PMC_SCSR_DDRCK_Pos)         /* (PMC_SCSR) The MPDDRC or SDRAMC clock is enabled. Position  */
#define PMC_SCSR_UHP_Pos                      _UINT32_(6)                                          /* (PMC_SCSR) USB Host OHCI Clocks Status Position */
#define PMC_SCSR_UHP_Msk                      (_UINT32_(0x1) << PMC_SCSR_UHP_Pos)                  /* (PMC_SCSR) USB Host OHCI Clocks Status Mask */
#define PMC_SCSR_UHP(value)                   (PMC_SCSR_UHP_Msk & (_UINT32_(value) << PMC_SCSR_UHP_Pos)) /* Assigment of value for UHP in the PMC_SCSR register */
#define   PMC_SCSR_UHP_0_Val                  _UINT32_(0x0)                                        /* (PMC_SCSR) The UHP48M and UHP12M OHCI clocks are disabled.  */
#define   PMC_SCSR_UHP_1_Val                  _UINT32_(0x1)                                        /* (PMC_SCSR) The UHP48M and UHP12M OHCI clocks are enabled.  */
#define PMC_SCSR_UHP_0                        (PMC_SCSR_UHP_0_Val << PMC_SCSR_UHP_Pos)             /* (PMC_SCSR) The UHP48M and UHP12M OHCI clocks are disabled. Position  */
#define PMC_SCSR_UHP_1                        (PMC_SCSR_UHP_1_Val << PMC_SCSR_UHP_Pos)             /* (PMC_SCSR) The UHP48M and UHP12M OHCI clocks are enabled. Position  */
#define PMC_SCSR_PCK0_Pos                     _UINT32_(8)                                          /* (PMC_SCSR) Programmable Clock 0 Output Status Position */
#define PMC_SCSR_PCK0_Msk                     (_UINT32_(0x1) << PMC_SCSR_PCK0_Pos)                 /* (PMC_SCSR) Programmable Clock 0 Output Status Mask */
#define PMC_SCSR_PCK0(value)                  (PMC_SCSR_PCK0_Msk & (_UINT32_(value) << PMC_SCSR_PCK0_Pos)) /* Assigment of value for PCK0 in the PMC_SCSR register */
#define   PMC_SCSR_PCK0_0_Val                 _UINT32_(0x0)                                        /* (PMC_SCSR) The corresponding Programmable Clock output is disabled.  */
#define   PMC_SCSR_PCK0_1_Val                 _UINT32_(0x1)                                        /* (PMC_SCSR) The corresponding Programmable Clock output is enabled.  */
#define PMC_SCSR_PCK0_0                       (PMC_SCSR_PCK0_0_Val << PMC_SCSR_PCK0_Pos)           /* (PMC_SCSR) The corresponding Programmable Clock output is disabled. Position  */
#define PMC_SCSR_PCK0_1                       (PMC_SCSR_PCK0_1_Val << PMC_SCSR_PCK0_Pos)           /* (PMC_SCSR) The corresponding Programmable Clock output is enabled. Position  */
#define PMC_SCSR_PCK1_Pos                     _UINT32_(9)                                          /* (PMC_SCSR) Programmable Clock 1 Output Status Position */
#define PMC_SCSR_PCK1_Msk                     (_UINT32_(0x1) << PMC_SCSR_PCK1_Pos)                 /* (PMC_SCSR) Programmable Clock 1 Output Status Mask */
#define PMC_SCSR_PCK1(value)                  (PMC_SCSR_PCK1_Msk & (_UINT32_(value) << PMC_SCSR_PCK1_Pos)) /* Assigment of value for PCK1 in the PMC_SCSR register */
#define   PMC_SCSR_PCK1_0_Val                 _UINT32_(0x0)                                        /* (PMC_SCSR) The corresponding Programmable Clock output is disabled.  */
#define   PMC_SCSR_PCK1_1_Val                 _UINT32_(0x1)                                        /* (PMC_SCSR) The corresponding Programmable Clock output is enabled.  */
#define PMC_SCSR_PCK1_0                       (PMC_SCSR_PCK1_0_Val << PMC_SCSR_PCK1_Pos)           /* (PMC_SCSR) The corresponding Programmable Clock output is disabled. Position  */
#define PMC_SCSR_PCK1_1                       (PMC_SCSR_PCK1_1_Val << PMC_SCSR_PCK1_Pos)           /* (PMC_SCSR) The corresponding Programmable Clock output is enabled. Position  */
#define PMC_SCSR_QSPICLK_Pos                  _UINT32_(19)                                         /* (PMC_SCSR) QSPI 2x Clock Status Position */
#define PMC_SCSR_QSPICLK_Msk                  (_UINT32_(0x1) << PMC_SCSR_QSPICLK_Pos)              /* (PMC_SCSR) QSPI 2x Clock Status Mask */
#define PMC_SCSR_QSPICLK(value)               (PMC_SCSR_QSPICLK_Msk & (_UINT32_(value) << PMC_SCSR_QSPICLK_Pos)) /* Assigment of value for QSPICLK in the PMC_SCSR register */
#define   PMC_SCSR_QSPICLK_0_Val              _UINT32_(0x0)                                        /* (PMC_SCSR) The QSPI 2x clock is disabled.  */
#define   PMC_SCSR_QSPICLK_1_Val              _UINT32_(0x1)                                        /* (PMC_SCSR) The QSPI 2x clock is enabled.  */
#define PMC_SCSR_QSPICLK_0                    (PMC_SCSR_QSPICLK_0_Val << PMC_SCSR_QSPICLK_Pos)     /* (PMC_SCSR) The QSPI 2x clock is disabled. Position  */
#define PMC_SCSR_QSPICLK_1                    (PMC_SCSR_QSPICLK_1_Val << PMC_SCSR_QSPICLK_Pos)     /* (PMC_SCSR) The QSPI 2x clock is enabled. Position  */
#define PMC_SCSR_Msk                          _UINT32_(0x00080344)                                 /* (PMC_SCSR) Register Mask  */

#define PMC_SCSR_PCK_Pos                      _UINT32_(8)                                          /* (PMC_SCSR Position) Programmable Clock x Output Status */
#define PMC_SCSR_PCK_Msk                      (_UINT32_(0x3) << PMC_SCSR_PCK_Pos)                  /* (PMC_SCSR Mask) PCK */
#define PMC_SCSR_PCK(value)                   (PMC_SCSR_PCK_Msk & (_UINT32_(value) << PMC_SCSR_PCK_Pos)) 

/* -------- PMC_PLL_CTRL0 : (PMC Offset: 0x0C) (R/W 32) PLL Control Register 0 -------- */
#define PMC_PLL_CTRL0_RESETVALUE              _UINT32_(0x00)                                       /*  (PMC_PLL_CTRL0) PLL Control Register 0  Reset Value */

#define PMC_PLL_CTRL0_DIVPMC_Pos              _UINT32_(0)                                          /* (PMC_PLL_CTRL0) Divider for PMC Position */
#define PMC_PLL_CTRL0_DIVPMC_Msk              (_UINT32_(0xFF) << PMC_PLL_CTRL0_DIVPMC_Pos)         /* (PMC_PLL_CTRL0) Divider for PMC Mask */
#define PMC_PLL_CTRL0_DIVPMC(value)           (PMC_PLL_CTRL0_DIVPMC_Msk & (_UINT32_(value) << PMC_PLL_CTRL0_DIVPMC_Pos)) /* Assigment of value for DIVPMC in the PMC_PLL_CTRL0 register */
#define PMC_PLL_CTRL0_DIVIO_Pos               _UINT32_(12)                                         /* (PMC_PLL_CTRL0) Divider for PAD Position */
#define PMC_PLL_CTRL0_DIVIO_Msk               (_UINT32_(0xFF) << PMC_PLL_CTRL0_DIVIO_Pos)          /* (PMC_PLL_CTRL0) Divider for PAD Mask */
#define PMC_PLL_CTRL0_DIVIO(value)            (PMC_PLL_CTRL0_DIVIO_Msk & (_UINT32_(value) << PMC_PLL_CTRL0_DIVIO_Pos)) /* Assigment of value for DIVIO in the PMC_PLL_CTRL0 register */
#define PMC_PLL_CTRL0_ENPLL_Pos               _UINT32_(28)                                         /* (PMC_PLL_CTRL0) Enable PLL Position */
#define PMC_PLL_CTRL0_ENPLL_Msk               (_UINT32_(0x1) << PMC_PLL_CTRL0_ENPLL_Pos)           /* (PMC_PLL_CTRL0) Enable PLL Mask */
#define PMC_PLL_CTRL0_ENPLL(value)            (PMC_PLL_CTRL0_ENPLL_Msk & (_UINT32_(value) << PMC_PLL_CTRL0_ENPLL_Pos)) /* Assigment of value for ENPLL in the PMC_PLL_CTRL0 register */
#define   PMC_PLL_CTRL0_ENPLL_0_Val           _UINT32_(0x0)                                        /* (PMC_PLL_CTRL0) The PLL is off.  */
#define   PMC_PLL_CTRL0_ENPLL_1_Val           _UINT32_(0x1)                                        /* (PMC_PLL_CTRL0) The PLL is on.  */
#define PMC_PLL_CTRL0_ENPLL_0                 (PMC_PLL_CTRL0_ENPLL_0_Val << PMC_PLL_CTRL0_ENPLL_Pos) /* (PMC_PLL_CTRL0) The PLL is off. Position  */
#define PMC_PLL_CTRL0_ENPLL_1                 (PMC_PLL_CTRL0_ENPLL_1_Val << PMC_PLL_CTRL0_ENPLL_Pos) /* (PMC_PLL_CTRL0) The PLL is on. Position  */
#define PMC_PLL_CTRL0_ENPLLCK_Pos             _UINT32_(29)                                         /* (PMC_PLL_CTRL0) Enable PLL Clock for PMC Position */
#define PMC_PLL_CTRL0_ENPLLCK_Msk             (_UINT32_(0x1) << PMC_PLL_CTRL0_ENPLLCK_Pos)         /* (PMC_PLL_CTRL0) Enable PLL Clock for PMC Mask */
#define PMC_PLL_CTRL0_ENPLLCK(value)          (PMC_PLL_CTRL0_ENPLLCK_Msk & (_UINT32_(value) << PMC_PLL_CTRL0_ENPLLCK_Pos)) /* Assigment of value for ENPLLCK in the PMC_PLL_CTRL0 register */
#define   PMC_PLL_CTRL0_ENPLLCK_0_Val         _UINT32_(0x0)                                        /* (PMC_PLL_CTRL0) The clock generated by the PLL is not send to the IP_Acronym.  */
#define   PMC_PLL_CTRL0_ENPLLCK_1_Val         _UINT32_(0x1)                                        /* (PMC_PLL_CTRL0) The clock generated by the PLL is sent to the IP_Acronym.  */
#define PMC_PLL_CTRL0_ENPLLCK_0               (PMC_PLL_CTRL0_ENPLLCK_0_Val << PMC_PLL_CTRL0_ENPLLCK_Pos) /* (PMC_PLL_CTRL0) The clock generated by the PLL is not send to the IP_Acronym. Position  */
#define PMC_PLL_CTRL0_ENPLLCK_1               (PMC_PLL_CTRL0_ENPLLCK_1_Val << PMC_PLL_CTRL0_ENPLLCK_Pos) /* (PMC_PLL_CTRL0) The clock generated by the PLL is sent to the IP_Acronym. Position  */
#define PMC_PLL_CTRL0_ENIOPLLCK_Pos           _UINT32_(30)                                         /* (PMC_PLL_CTRL0) Enable PLL Clock for IO Position */
#define PMC_PLL_CTRL0_ENIOPLLCK_Msk           (_UINT32_(0x1) << PMC_PLL_CTRL0_ENIOPLLCK_Pos)       /* (PMC_PLL_CTRL0) Enable PLL Clock for IO Mask */
#define PMC_PLL_CTRL0_ENIOPLLCK(value)        (PMC_PLL_CTRL0_ENIOPLLCK_Msk & (_UINT32_(value) << PMC_PLL_CTRL0_ENIOPLLCK_Pos)) /* Assigment of value for ENIOPLLCK in the PMC_PLL_CTRL0 register */
#define   PMC_PLL_CTRL0_ENIOPLLCK_0_Val       _UINT32_(0x0)                                        /* (PMC_PLL_CTRL0) The clock generated by the PLL is not send to the IO.  */
#define   PMC_PLL_CTRL0_ENIOPLLCK_1_Val       _UINT32_(0x1)                                        /* (PMC_PLL_CTRL0) The clock generated by the PLL is sent to the IO.  */
#define PMC_PLL_CTRL0_ENIOPLLCK_0             (PMC_PLL_CTRL0_ENIOPLLCK_0_Val << PMC_PLL_CTRL0_ENIOPLLCK_Pos) /* (PMC_PLL_CTRL0) The clock generated by the PLL is not send to the IO. Position  */
#define PMC_PLL_CTRL0_ENIOPLLCK_1             (PMC_PLL_CTRL0_ENIOPLLCK_1_Val << PMC_PLL_CTRL0_ENIOPLLCK_Pos) /* (PMC_PLL_CTRL0) The clock generated by the PLL is sent to the IO. Position  */
#define PMC_PLL_CTRL0_ENLOCK_Pos              _UINT32_(31)                                         /* (PMC_PLL_CTRL0) Enable PLL Lock Position */
#define PMC_PLL_CTRL0_ENLOCK_Msk              (_UINT32_(0x1) << PMC_PLL_CTRL0_ENLOCK_Pos)          /* (PMC_PLL_CTRL0) Enable PLL Lock Mask */
#define PMC_PLL_CTRL0_ENLOCK(value)           (PMC_PLL_CTRL0_ENLOCK_Msk & (_UINT32_(value) << PMC_PLL_CTRL0_ENLOCK_Pos)) /* Assigment of value for ENLOCK in the PMC_PLL_CTRL0 register */
#define   PMC_PLL_CTRL0_ENLOCK_0_Val          _UINT32_(0x0)                                        /* (PMC_PLL_CTRL0) The lock signal sent by the PLL is ignored. The PLL is considered as locked once the start-up time defined by PMC_PLL_UPDT.STUPTIM has elapsed.  */
#define   PMC_PLL_CTRL0_ENLOCK_1_Val          _UINT32_(0x1)                                        /* (PMC_PLL_CTRL0) The PLL is considered as locked once the start-up time defined by PMC_PLL_UPDT.STUPTIM has elapsed and the lock signal sent by the PLL has risen.  */
#define PMC_PLL_CTRL0_ENLOCK_0                (PMC_PLL_CTRL0_ENLOCK_0_Val << PMC_PLL_CTRL0_ENLOCK_Pos) /* (PMC_PLL_CTRL0) The lock signal sent by the PLL is ignored. The PLL is considered as locked once the start-up time defined by PMC_PLL_UPDT.STUPTIM has elapsed. Position  */
#define PMC_PLL_CTRL0_ENLOCK_1                (PMC_PLL_CTRL0_ENLOCK_1_Val << PMC_PLL_CTRL0_ENLOCK_Pos) /* (PMC_PLL_CTRL0) The PLL is considered as locked once the start-up time defined by PMC_PLL_UPDT.STUPTIM has elapsed and the lock signal sent by the PLL has risen. Position  */
#define PMC_PLL_CTRL0_Msk                     _UINT32_(0xF00FF0FF)                                 /* (PMC_PLL_CTRL0) Register Mask  */


/* -------- PMC_PLL_CTRL1 : (PMC Offset: 0x10) (R/W 32) PLL Control Register 1 -------- */
#define PMC_PLL_CTRL1_RESETVALUE              _UINT32_(0x00)                                       /*  (PMC_PLL_CTRL1) PLL Control Register 1  Reset Value */

#define PMC_PLL_CTRL1_FRACR_Pos               _UINT32_(0)                                          /* (PMC_PLL_CTRL1) Fractional Loop Divider Setting Position */
#define PMC_PLL_CTRL1_FRACR_Msk               (_UINT32_(0x3FFFFF) << PMC_PLL_CTRL1_FRACR_Pos)      /* (PMC_PLL_CTRL1) Fractional Loop Divider Setting Mask */
#define PMC_PLL_CTRL1_FRACR(value)            (PMC_PLL_CTRL1_FRACR_Msk & (_UINT32_(value) << PMC_PLL_CTRL1_FRACR_Pos)) /* Assigment of value for FRACR in the PMC_PLL_CTRL1 register */
#define PMC_PLL_CTRL1_MUL_Pos                 _UINT32_(24)                                         /* (PMC_PLL_CTRL1) Multiplier Factor Value Position */
#define PMC_PLL_CTRL1_MUL_Msk                 (_UINT32_(0xFF) << PMC_PLL_CTRL1_MUL_Pos)            /* (PMC_PLL_CTRL1) Multiplier Factor Value Mask */
#define PMC_PLL_CTRL1_MUL(value)              (PMC_PLL_CTRL1_MUL_Msk & (_UINT32_(value) << PMC_PLL_CTRL1_MUL_Pos)) /* Assigment of value for MUL in the PMC_PLL_CTRL1 register */
#define PMC_PLL_CTRL1_Msk                     _UINT32_(0xFF3FFFFF)                                 /* (PMC_PLL_CTRL1) Register Mask  */


/* -------- PMC_PLL_SSR : (PMC Offset: 0x14) (R/W 32) PLL Spread Spectrum Register -------- */
#define PMC_PLL_SSR_RESETVALUE                _UINT32_(0x00)                                       /*  (PMC_PLL_SSR) PLL Spread Spectrum Register  Reset Value */

#define PMC_PLL_SSR_STEP_Pos                  _UINT32_(0)                                          /* (PMC_PLL_SSR) Spread Spectrum Step Size Position */
#define PMC_PLL_SSR_STEP_Msk                  (_UINT32_(0xFFFF) << PMC_PLL_SSR_STEP_Pos)           /* (PMC_PLL_SSR) Spread Spectrum Step Size Mask */
#define PMC_PLL_SSR_STEP(value)               (PMC_PLL_SSR_STEP_Msk & (_UINT32_(value) << PMC_PLL_SSR_STEP_Pos)) /* Assigment of value for STEP in the PMC_PLL_SSR register */
#define PMC_PLL_SSR_NSTEP_Pos                 _UINT32_(16)                                         /* (PMC_PLL_SSR) Spread Spectrum Number of Steps Position */
#define PMC_PLL_SSR_NSTEP_Msk                 (_UINT32_(0xFF) << PMC_PLL_SSR_NSTEP_Pos)            /* (PMC_PLL_SSR) Spread Spectrum Number of Steps Mask */
#define PMC_PLL_SSR_NSTEP(value)              (PMC_PLL_SSR_NSTEP_Msk & (_UINT32_(value) << PMC_PLL_SSR_NSTEP_Pos)) /* Assigment of value for NSTEP in the PMC_PLL_SSR register */
#define PMC_PLL_SSR_ENSPREAD_Pos              _UINT32_(28)                                         /* (PMC_PLL_SSR) Spread Spectrum Enable Position */
#define PMC_PLL_SSR_ENSPREAD_Msk              (_UINT32_(0x1) << PMC_PLL_SSR_ENSPREAD_Pos)          /* (PMC_PLL_SSR) Spread Spectrum Enable Mask */
#define PMC_PLL_SSR_ENSPREAD(value)           (PMC_PLL_SSR_ENSPREAD_Msk & (_UINT32_(value) << PMC_PLL_SSR_ENSPREAD_Pos)) /* Assigment of value for ENSPREAD in the PMC_PLL_SSR register */
#define   PMC_PLL_SSR_ENSPREAD_0_Val          _UINT32_(0x0)                                        /* (PMC_PLL_SSR) The spread spectrum is not applied to the PLL.  */
#define   PMC_PLL_SSR_ENSPREAD_1_Val          _UINT32_(0x1)                                        /* (PMC_PLL_SSR) The spread spectrum is applied to the PLL.  */
#define PMC_PLL_SSR_ENSPREAD_0                (PMC_PLL_SSR_ENSPREAD_0_Val << PMC_PLL_SSR_ENSPREAD_Pos) /* (PMC_PLL_SSR) The spread spectrum is not applied to the PLL. Position  */
#define PMC_PLL_SSR_ENSPREAD_1                (PMC_PLL_SSR_ENSPREAD_1_Val << PMC_PLL_SSR_ENSPREAD_Pos) /* (PMC_PLL_SSR) The spread spectrum is applied to the PLL. Position  */
#define PMC_PLL_SSR_Msk                       _UINT32_(0x10FFFFFF)                                 /* (PMC_PLL_SSR) Register Mask  */


/* -------- PMC_PLL_ACR : (PMC Offset: 0x18) (R/W 32) PLL Analog Control Register -------- */
#define PMC_PLL_ACR_RESETVALUE                _UINT32_(0x20033)                                    /*  (PMC_PLL_ACR) PLL Analog Control Register  Reset Value */

#define PMC_PLL_ACR_CONTROL_Pos               _UINT32_(0)                                          /* (PMC_PLL_ACR) PLL CONTROL Value Selection Position */
#define PMC_PLL_ACR_CONTROL_Msk               (_UINT32_(0xFFF) << PMC_PLL_ACR_CONTROL_Pos)         /* (PMC_PLL_ACR) PLL CONTROL Value Selection Mask */
#define PMC_PLL_ACR_CONTROL(value)            (PMC_PLL_ACR_CONTROL_Msk & (_UINT32_(value) << PMC_PLL_ACR_CONTROL_Pos)) /* Assigment of value for CONTROL in the PMC_PLL_ACR register */
#define PMC_PLL_ACR_UTMIVR_Pos                _UINT32_(12)                                         /* (PMC_PLL_ACR) UPLL Voltage Regulator Control Position */
#define PMC_PLL_ACR_UTMIVR_Msk                (_UINT32_(0x1) << PMC_PLL_ACR_UTMIVR_Pos)            /* (PMC_PLL_ACR) UPLL Voltage Regulator Control Mask */
#define PMC_PLL_ACR_UTMIVR(value)             (PMC_PLL_ACR_UTMIVR_Msk & (_UINT32_(value) << PMC_PLL_ACR_UTMIVR_Pos)) /* Assigment of value for UTMIVR in the PMC_PLL_ACR register */
#define   PMC_PLL_ACR_UTMIVR_0_Val            _UINT32_(0x0)                                        /* (PMC_PLL_ACR) The UPLL voltage regulator is switched off.  */
#define   PMC_PLL_ACR_UTMIVR_1_Val            _UINT32_(0x1)                                        /* (PMC_PLL_ACR) The UPLL voltage regulator is switched on.  */
#define PMC_PLL_ACR_UTMIVR_0                  (PMC_PLL_ACR_UTMIVR_0_Val << PMC_PLL_ACR_UTMIVR_Pos) /* (PMC_PLL_ACR) The UPLL voltage regulator is switched off. Position  */
#define PMC_PLL_ACR_UTMIVR_1                  (PMC_PLL_ACR_UTMIVR_1_Val << PMC_PLL_ACR_UTMIVR_Pos) /* (PMC_PLL_ACR) The UPLL voltage regulator is switched on. Position  */
#define PMC_PLL_ACR_UTMIBG_Pos                _UINT32_(13)                                         /* (PMC_PLL_ACR) UPLL Bandgap Control Position */
#define PMC_PLL_ACR_UTMIBG_Msk                (_UINT32_(0x1) << PMC_PLL_ACR_UTMIBG_Pos)            /* (PMC_PLL_ACR) UPLL Bandgap Control Mask */
#define PMC_PLL_ACR_UTMIBG(value)             (PMC_PLL_ACR_UTMIBG_Msk & (_UINT32_(value) << PMC_PLL_ACR_UTMIBG_Pos)) /* Assigment of value for UTMIBG in the PMC_PLL_ACR register */
#define   PMC_PLL_ACR_UTMIBG_0_Val            _UINT32_(0x0)                                        /* (PMC_PLL_ACR) The UPLL bandgap is switched off.  */
#define   PMC_PLL_ACR_UTMIBG_1_Val            _UINT32_(0x1)                                        /* (PMC_PLL_ACR) The UPLL bandgap is switched on.  */
#define PMC_PLL_ACR_UTMIBG_0                  (PMC_PLL_ACR_UTMIBG_0_Val << PMC_PLL_ACR_UTMIBG_Pos) /* (PMC_PLL_ACR) The UPLL bandgap is switched off. Position  */
#define PMC_PLL_ACR_UTMIBG_1                  (PMC_PLL_ACR_UTMIBG_1_Val << PMC_PLL_ACR_UTMIBG_Pos) /* (PMC_PLL_ACR) The UPLL bandgap is switched on. Position  */
#define PMC_PLL_ACR_LOCK_THR_Pos              _UINT32_(16)                                         /* (PMC_PLL_ACR) PLL Lock Threshold Value Selection Position */
#define PMC_PLL_ACR_LOCK_THR_Msk              (_UINT32_(0x7) << PMC_PLL_ACR_LOCK_THR_Pos)          /* (PMC_PLL_ACR) PLL Lock Threshold Value Selection Mask */
#define PMC_PLL_ACR_LOCK_THR(value)           (PMC_PLL_ACR_LOCK_THR_Msk & (_UINT32_(value) << PMC_PLL_ACR_LOCK_THR_Pos)) /* Assigment of value for LOCK_THR in the PMC_PLL_ACR register */
#define PMC_PLL_ACR_LOOP_FILTER_Pos           _UINT32_(24)                                         /* (PMC_PLL_ACR) LOOP Filter Selection Position */
#define PMC_PLL_ACR_LOOP_FILTER_Msk           (_UINT32_(0x3F) << PMC_PLL_ACR_LOOP_FILTER_Pos)      /* (PMC_PLL_ACR) LOOP Filter Selection Mask */
#define PMC_PLL_ACR_LOOP_FILTER(value)        (PMC_PLL_ACR_LOOP_FILTER_Msk & (_UINT32_(value) << PMC_PLL_ACR_LOOP_FILTER_Pos)) /* Assigment of value for LOOP_FILTER in the PMC_PLL_ACR register */
#define PMC_PLL_ACR_Msk                       _UINT32_(0x3F073FFF)                                 /* (PMC_PLL_ACR) Register Mask  */


/* -------- PMC_PLL_UPDT : (PMC Offset: 0x1C) (R/W 32) PLL Update Register -------- */
#define PMC_PLL_UPDT_RESETVALUE               _UINT32_(0x30000)                                    /*  (PMC_PLL_UPDT) PLL Update Register  Reset Value */

#define PMC_PLL_UPDT_ID_Pos                   _UINT32_(0)                                          /* (PMC_PLL_UPDT) PLL ID Position */
#define PMC_PLL_UPDT_ID_Msk                   (_UINT32_(0x3) << PMC_PLL_UPDT_ID_Pos)               /* (PMC_PLL_UPDT) PLL ID Mask */
#define PMC_PLL_UPDT_ID(value)                (PMC_PLL_UPDT_ID_Msk & (_UINT32_(value) << PMC_PLL_UPDT_ID_Pos)) /* Assigment of value for ID in the PMC_PLL_UPDT register */
#define PMC_PLL_UPDT_UPDATE_Pos               _UINT32_(8)                                          /* (PMC_PLL_UPDT) PLL Setting Update (write-only) Position */
#define PMC_PLL_UPDT_UPDATE_Msk               (_UINT32_(0x1) << PMC_PLL_UPDT_UPDATE_Pos)           /* (PMC_PLL_UPDT) PLL Setting Update (write-only) Mask */
#define PMC_PLL_UPDT_UPDATE(value)            (PMC_PLL_UPDT_UPDATE_Msk & (_UINT32_(value) << PMC_PLL_UPDT_UPDATE_Pos)) /* Assigment of value for UPDATE in the PMC_PLL_UPDT register */
#define   PMC_PLL_UPDT_UPDATE_0_Val           _UINT32_(0x0)                                        /* (PMC_PLL_UPDT) No effect.  */
#define   PMC_PLL_UPDT_UPDATE_1_Val           _UINT32_(0x1)                                        /* (PMC_PLL_UPDT) The PLL configuration written in PMC_PLL_CTRL0 and PMC_PLL_CTRL1 are applied to the PLL defined by the last ID written in the PMC_PLL_CTRL0 register.  */
#define PMC_PLL_UPDT_UPDATE_0                 (PMC_PLL_UPDT_UPDATE_0_Val << PMC_PLL_UPDT_UPDATE_Pos) /* (PMC_PLL_UPDT) No effect. Position  */
#define PMC_PLL_UPDT_UPDATE_1                 (PMC_PLL_UPDT_UPDATE_1_Val << PMC_PLL_UPDT_UPDATE_Pos) /* (PMC_PLL_UPDT) The PLL configuration written in PMC_PLL_CTRL0 and PMC_PLL_CTRL1 are applied to the PLL defined by the last ID written in the PMC_PLL_CTRL0 register. Position  */
#define PMC_PLL_UPDT_STUPTIM_Pos              _UINT32_(16)                                         /* (PMC_PLL_UPDT) Start-up Time Position */
#define PMC_PLL_UPDT_STUPTIM_Msk              (_UINT32_(0x3F) << PMC_PLL_UPDT_STUPTIM_Pos)         /* (PMC_PLL_UPDT) Start-up Time Mask */
#define PMC_PLL_UPDT_STUPTIM(value)           (PMC_PLL_UPDT_STUPTIM_Msk & (_UINT32_(value) << PMC_PLL_UPDT_STUPTIM_Pos)) /* Assigment of value for STUPTIM in the PMC_PLL_UPDT register */
#define   PMC_PLL_UPDT_STUPTIM_0_Val          _UINT32_(0x0)                                        /* (PMC_PLL_UPDT) Only the lock of the PLL is considered to know the lock status of the PLL. If the lock of the PLL is not enabled, the lock never rises.  */
#define PMC_PLL_UPDT_STUPTIM_0                (PMC_PLL_UPDT_STUPTIM_0_Val << PMC_PLL_UPDT_STUPTIM_Pos) /* (PMC_PLL_UPDT) Only the lock of the PLL is considered to know the lock status of the PLL. If the lock of the PLL is not enabled, the lock never rises. Position  */
#define PMC_PLL_UPDT_Msk                      _UINT32_(0x003F0103)                                 /* (PMC_PLL_UPDT) Register Mask  */


/* -------- CKGR_MOR : (PMC Offset: 0x20) (R/W 32) Main Oscillator Register -------- */
#define CKGR_MOR_RESETVALUE                   _UINT32_(0x08)                                       /*  (CKGR_MOR) Main Oscillator Register  Reset Value */

#define CKGR_MOR_MOSCXTEN_Pos                 _UINT32_(0)                                          /* (CKGR_MOR) Main Crystal Oscillator Enable Position */
#define CKGR_MOR_MOSCXTEN_Msk                 (_UINT32_(0x1) << CKGR_MOR_MOSCXTEN_Pos)             /* (CKGR_MOR) Main Crystal Oscillator Enable Mask */
#define CKGR_MOR_MOSCXTEN(value)              (CKGR_MOR_MOSCXTEN_Msk & (_UINT32_(value) << CKGR_MOR_MOSCXTEN_Pos)) /* Assigment of value for MOSCXTEN in the CKGR_MOR register */
#define   CKGR_MOR_MOSCXTEN_0_Val             _UINT32_(0x0)                                        /* (CKGR_MOR) The main crystal oscillator is disabled.  */
#define   CKGR_MOR_MOSCXTEN_1_Val             _UINT32_(0x1)                                        /* (CKGR_MOR) The main crystal oscillator is enabled or in bypass.  */
#define CKGR_MOR_MOSCXTEN_0                   (CKGR_MOR_MOSCXTEN_0_Val << CKGR_MOR_MOSCXTEN_Pos)   /* (CKGR_MOR) The main crystal oscillator is disabled. Position  */
#define CKGR_MOR_MOSCXTEN_1                   (CKGR_MOR_MOSCXTEN_1_Val << CKGR_MOR_MOSCXTEN_Pos)   /* (CKGR_MOR) The main crystal oscillator is enabled or in bypass. Position  */
#define CKGR_MOR_ULP1_Pos                     _UINT32_(2)                                          /* (CKGR_MOR) ULP Mode 1 Command (write-only) Position */
#define CKGR_MOR_ULP1_Msk                     (_UINT32_(0x1) << CKGR_MOR_ULP1_Pos)                 /* (CKGR_MOR) ULP Mode 1 Command (write-only) Mask */
#define CKGR_MOR_ULP1(value)                  (CKGR_MOR_ULP1_Msk & (_UINT32_(value) << CKGR_MOR_ULP1_Pos)) /* Assigment of value for ULP1 in the CKGR_MOR register */
#define   CKGR_MOR_ULP1_0_Val                 _UINT32_(0x0)                                        /* (CKGR_MOR) No effect.  */
#define   CKGR_MOR_ULP1_1_Val                 _UINT32_(0x1)                                        /* (CKGR_MOR) Puts the device in ULP mode 1.  */
#define CKGR_MOR_ULP1_0                       (CKGR_MOR_ULP1_0_Val << CKGR_MOR_ULP1_Pos)           /* (CKGR_MOR) No effect. Position  */
#define CKGR_MOR_ULP1_1                       (CKGR_MOR_ULP1_1_Val << CKGR_MOR_ULP1_Pos)           /* (CKGR_MOR) Puts the device in ULP mode 1. Position  */
#define CKGR_MOR_MOSCRCEN_Pos                 _UINT32_(3)                                          /* (CKGR_MOR) Main RC Oscillator Enable Position */
#define CKGR_MOR_MOSCRCEN_Msk                 (_UINT32_(0x1) << CKGR_MOR_MOSCRCEN_Pos)             /* (CKGR_MOR) Main RC Oscillator Enable Mask */
#define CKGR_MOR_MOSCRCEN(value)              (CKGR_MOR_MOSCRCEN_Msk & (_UINT32_(value) << CKGR_MOR_MOSCRCEN_Pos)) /* Assigment of value for MOSCRCEN in the CKGR_MOR register */
#define   CKGR_MOR_MOSCRCEN_0_Val             _UINT32_(0x0)                                        /* (CKGR_MOR) The main RC oscillator is disabled.  */
#define   CKGR_MOR_MOSCRCEN_1_Val             _UINT32_(0x1)                                        /* (CKGR_MOR) The main RC oscillator is enabled.  */
#define CKGR_MOR_MOSCRCEN_0                   (CKGR_MOR_MOSCRCEN_0_Val << CKGR_MOR_MOSCRCEN_Pos)   /* (CKGR_MOR) The main RC oscillator is disabled. Position  */
#define CKGR_MOR_MOSCRCEN_1                   (CKGR_MOR_MOSCRCEN_1_Val << CKGR_MOR_MOSCRCEN_Pos)   /* (CKGR_MOR) The main RC oscillator is enabled. Position  */
#define CKGR_MOR_MOSCXTST_Pos                 _UINT32_(8)                                          /* (CKGR_MOR) Main Crystal Oscillator Start-up Time Position */
#define CKGR_MOR_MOSCXTST_Msk                 (_UINT32_(0xFF) << CKGR_MOR_MOSCXTST_Pos)            /* (CKGR_MOR) Main Crystal Oscillator Start-up Time Mask */
#define CKGR_MOR_MOSCXTST(value)              (CKGR_MOR_MOSCXTST_Msk & (_UINT32_(value) << CKGR_MOR_MOSCXTST_Pos)) /* Assigment of value for MOSCXTST in the CKGR_MOR register */
#define CKGR_MOR_KEY_Pos                      _UINT32_(16)                                         /* (CKGR_MOR) Write Access Password Position */
#define CKGR_MOR_KEY_Msk                      (_UINT32_(0xFF) << CKGR_MOR_KEY_Pos)                 /* (CKGR_MOR) Write Access Password Mask */
#define CKGR_MOR_KEY(value)                   (CKGR_MOR_KEY_Msk & (_UINT32_(value) << CKGR_MOR_KEY_Pos)) /* Assigment of value for KEY in the CKGR_MOR register */
#define   CKGR_MOR_KEY_PASSWD_Val             _UINT32_(0x37)                                       /* (CKGR_MOR) Writing any other value in this field aborts the write operation. Always reads as 0.  */
#define CKGR_MOR_KEY_PASSWD                   (CKGR_MOR_KEY_PASSWD_Val << CKGR_MOR_KEY_Pos)        /* (CKGR_MOR) Writing any other value in this field aborts the write operation. Always reads as 0. Position  */
#define CKGR_MOR_MOSCSEL_Pos                  _UINT32_(24)                                         /* (CKGR_MOR) Main Clock Oscillator Selection Position */
#define CKGR_MOR_MOSCSEL_Msk                  (_UINT32_(0x1) << CKGR_MOR_MOSCSEL_Pos)              /* (CKGR_MOR) Main Clock Oscillator Selection Mask */
#define CKGR_MOR_MOSCSEL(value)               (CKGR_MOR_MOSCSEL_Msk & (_UINT32_(value) << CKGR_MOR_MOSCSEL_Pos)) /* Assigment of value for MOSCSEL in the CKGR_MOR register */
#define   CKGR_MOR_MOSCSEL_0_Val              _UINT32_(0x0)                                        /* (CKGR_MOR) The main RC oscillator is selected.  */
#define   CKGR_MOR_MOSCSEL_1_Val              _UINT32_(0x1)                                        /* (CKGR_MOR) The main crystal oscillator is selected.  */
#define CKGR_MOR_MOSCSEL_0                    (CKGR_MOR_MOSCSEL_0_Val << CKGR_MOR_MOSCSEL_Pos)     /* (CKGR_MOR) The main RC oscillator is selected. Position  */
#define CKGR_MOR_MOSCSEL_1                    (CKGR_MOR_MOSCSEL_1_Val << CKGR_MOR_MOSCSEL_Pos)     /* (CKGR_MOR) The main crystal oscillator is selected. Position  */
#define CKGR_MOR_CFDEN_Pos                    _UINT32_(25)                                         /* (CKGR_MOR) Clock Failure Detector Enable Position */
#define CKGR_MOR_CFDEN_Msk                    (_UINT32_(0x1) << CKGR_MOR_CFDEN_Pos)                /* (CKGR_MOR) Clock Failure Detector Enable Mask */
#define CKGR_MOR_CFDEN(value)                 (CKGR_MOR_CFDEN_Msk & (_UINT32_(value) << CKGR_MOR_CFDEN_Pos)) /* Assigment of value for CFDEN in the CKGR_MOR register */
#define   CKGR_MOR_CFDEN_0_Val                _UINT32_(0x0)                                        /* (CKGR_MOR) The clock failure detector is disabled.  */
#define   CKGR_MOR_CFDEN_1_Val                _UINT32_(0x1)                                        /* (CKGR_MOR) The clock failure detector is enabled.  */
#define CKGR_MOR_CFDEN_0                      (CKGR_MOR_CFDEN_0_Val << CKGR_MOR_CFDEN_Pos)         /* (CKGR_MOR) The clock failure detector is disabled. Position  */
#define CKGR_MOR_CFDEN_1                      (CKGR_MOR_CFDEN_1_Val << CKGR_MOR_CFDEN_Pos)         /* (CKGR_MOR) The clock failure detector is enabled. Position  */
#define CKGR_MOR_XT32KFME_Pos                 _UINT32_(26)                                         /* (CKGR_MOR) 32.768 kHz Crystal Oscillator Frequency Monitoring Enable Position */
#define CKGR_MOR_XT32KFME_Msk                 (_UINT32_(0x1) << CKGR_MOR_XT32KFME_Pos)             /* (CKGR_MOR) 32.768 kHz Crystal Oscillator Frequency Monitoring Enable Mask */
#define CKGR_MOR_XT32KFME(value)              (CKGR_MOR_XT32KFME_Msk & (_UINT32_(value) << CKGR_MOR_XT32KFME_Pos)) /* Assigment of value for XT32KFME in the CKGR_MOR register */
#define   CKGR_MOR_XT32KFME_0_Val             _UINT32_(0x0)                                        /* (CKGR_MOR) The 32.768 kHz crystal oscillator frequency monitoring is disabled.  */
#define   CKGR_MOR_XT32KFME_1_Val             _UINT32_(0x1)                                        /* (CKGR_MOR) The 32.768 kHz crystal oscillator frequency monitoring is enabled.  */
#define CKGR_MOR_XT32KFME_0                   (CKGR_MOR_XT32KFME_0_Val << CKGR_MOR_XT32KFME_Pos)   /* (CKGR_MOR) The 32.768 kHz crystal oscillator frequency monitoring is disabled. Position  */
#define CKGR_MOR_XT32KFME_1                   (CKGR_MOR_XT32KFME_1_Val << CKGR_MOR_XT32KFME_Pos)   /* (CKGR_MOR) The 32.768 kHz crystal oscillator frequency monitoring is enabled. Position  */
#define CKGR_MOR_AUTOMAINSW_Pos               _UINT32_(29)                                         /* (CKGR_MOR) Automatic Main Clock Source Switching Position */
#define CKGR_MOR_AUTOMAINSW_Msk               (_UINT32_(0x1) << CKGR_MOR_AUTOMAINSW_Pos)           /* (CKGR_MOR) Automatic Main Clock Source Switching Mask */
#define CKGR_MOR_AUTOMAINSW(value)            (CKGR_MOR_AUTOMAINSW_Msk & (_UINT32_(value) << CKGR_MOR_AUTOMAINSW_Pos)) /* Assigment of value for AUTOMAINSW in the CKGR_MOR register */
#define   CKGR_MOR_AUTOMAINSW_0_Val           _UINT32_(0x0)                                        /* (CKGR_MOR) A main crystal oscillator failure detection has no effect on the main clock source selection.  */
#define   CKGR_MOR_AUTOMAINSW_1_Val           _UINT32_(0x1)                                        /* (CKGR_MOR) If a main crystal oscillator failure is detected, the main clock source selection automatically switches to the main RC.  */
#define CKGR_MOR_AUTOMAINSW_0                 (CKGR_MOR_AUTOMAINSW_0_Val << CKGR_MOR_AUTOMAINSW_Pos) /* (CKGR_MOR) A main crystal oscillator failure detection has no effect on the main clock source selection. Position  */
#define CKGR_MOR_AUTOMAINSW_1                 (CKGR_MOR_AUTOMAINSW_1_Val << CKGR_MOR_AUTOMAINSW_Pos) /* (CKGR_MOR) If a main crystal oscillator failure is detected, the main clock source selection automatically switches to the main RC. Position  */
#define CKGR_MOR_AUTOCPUSW_Pos                _UINT32_(30)                                         /* (CKGR_MOR) Automatic Processor Clock Source Switching Position */
#define CKGR_MOR_AUTOCPUSW_Msk                (_UINT32_(0x1) << CKGR_MOR_AUTOCPUSW_Pos)            /* (CKGR_MOR) Automatic Processor Clock Source Switching Mask */
#define CKGR_MOR_AUTOCPUSW(value)             (CKGR_MOR_AUTOCPUSW_Msk & (_UINT32_(value) << CKGR_MOR_AUTOCPUSW_Pos)) /* Assigment of value for AUTOCPUSW in the CKGR_MOR register */
#define   CKGR_MOR_AUTOCPUSW_0_Val            _UINT32_(0x0)                                        /* (CKGR_MOR) A main crystal oscillator failure detection has no effect on the processor clock source selection.  */
#define   CKGR_MOR_AUTOCPUSW_1_Val            _UINT32_(0x1)                                        /* (CKGR_MOR) If a main crystal oscillator failure is detected, the processor clock source selection automatically switches to the main clock.  */
#define CKGR_MOR_AUTOCPUSW_0                  (CKGR_MOR_AUTOCPUSW_0_Val << CKGR_MOR_AUTOCPUSW_Pos) /* (CKGR_MOR) A main crystal oscillator failure detection has no effect on the processor clock source selection. Position  */
#define CKGR_MOR_AUTOCPUSW_1                  (CKGR_MOR_AUTOCPUSW_1_Val << CKGR_MOR_AUTOCPUSW_Pos) /* (CKGR_MOR) If a main crystal oscillator failure is detected, the processor clock source selection automatically switches to the main clock. Position  */
#define CKGR_MOR_Msk                          _UINT32_(0x67FFFF0D)                                 /* (CKGR_MOR) Register Mask  */

#define CKGR_MOR_ULP_Pos                      _UINT32_(2)                                          /* (CKGR_MOR Position) ULP Mode x Command (write-only) */
#define CKGR_MOR_ULP_Msk                      (_UINT32_(0x1) << CKGR_MOR_ULP_Pos)                  /* (CKGR_MOR Mask) ULP */
#define CKGR_MOR_ULP(value)                   (CKGR_MOR_ULP_Msk & (_UINT32_(value) << CKGR_MOR_ULP_Pos)) 

/* -------- CKGR_MCFR : (PMC Offset: 0x24) (R/W 32) Main Clock Frequency Register -------- */
#define CKGR_MCFR_RESETVALUE                  _UINT32_(0x00)                                       /*  (CKGR_MCFR) Main Clock Frequency Register  Reset Value */

#define CKGR_MCFR_MAINF_Pos                   _UINT32_(0)                                          /* (CKGR_MCFR) Main Clock Frequency Position */
#define CKGR_MCFR_MAINF_Msk                   (_UINT32_(0xFFFF) << CKGR_MCFR_MAINF_Pos)            /* (CKGR_MCFR) Main Clock Frequency Mask */
#define CKGR_MCFR_MAINF(value)                (CKGR_MCFR_MAINF_Msk & (_UINT32_(value) << CKGR_MCFR_MAINF_Pos)) /* Assigment of value for MAINF in the CKGR_MCFR register */
#define CKGR_MCFR_MAINFRDY_Pos                _UINT32_(16)                                         /* (CKGR_MCFR) Main Clock Frequency Measure Ready Position */
#define CKGR_MCFR_MAINFRDY_Msk                (_UINT32_(0x1) << CKGR_MCFR_MAINFRDY_Pos)            /* (CKGR_MCFR) Main Clock Frequency Measure Ready Mask */
#define CKGR_MCFR_MAINFRDY(value)             (CKGR_MCFR_MAINFRDY_Msk & (_UINT32_(value) << CKGR_MCFR_MAINFRDY_Pos)) /* Assigment of value for MAINFRDY in the CKGR_MCFR register */
#define   CKGR_MCFR_MAINFRDY_0_Val            _UINT32_(0x0)                                        /* (CKGR_MCFR) MAINF value is not valid or the measured oscillator is disabled or a measure has just been started by means of RCMEAS.  */
#define   CKGR_MCFR_MAINFRDY_1_Val            _UINT32_(0x1)                                        /* (CKGR_MCFR) The measured oscillator has been enabled previously and MAINF value is available.  */
#define CKGR_MCFR_MAINFRDY_0                  (CKGR_MCFR_MAINFRDY_0_Val << CKGR_MCFR_MAINFRDY_Pos) /* (CKGR_MCFR) MAINF value is not valid or the measured oscillator is disabled or a measure has just been started by means of RCMEAS. Position  */
#define CKGR_MCFR_MAINFRDY_1                  (CKGR_MCFR_MAINFRDY_1_Val << CKGR_MCFR_MAINFRDY_Pos) /* (CKGR_MCFR) The measured oscillator has been enabled previously and MAINF value is available. Position  */
#define CKGR_MCFR_RCMEAS_Pos                  _UINT32_(20)                                         /* (CKGR_MCFR) RC Oscillator Frequency Measure (write-only) Position */
#define CKGR_MCFR_RCMEAS_Msk                  (_UINT32_(0x1) << CKGR_MCFR_RCMEAS_Pos)              /* (CKGR_MCFR) RC Oscillator Frequency Measure (write-only) Mask */
#define CKGR_MCFR_RCMEAS(value)               (CKGR_MCFR_RCMEAS_Msk & (_UINT32_(value) << CKGR_MCFR_RCMEAS_Pos)) /* Assigment of value for RCMEAS in the CKGR_MCFR register */
#define   CKGR_MCFR_RCMEAS_0_Val              _UINT32_(0x0)                                        /* (CKGR_MCFR) No effect.  */
#define   CKGR_MCFR_RCMEAS_1_Val              _UINT32_(0x1)                                        /* (CKGR_MCFR) Restarts measuring of the frequency of MAINCK. MAINF carries the new frequency as soon as a low-to-high transition occurs on the MAINFRDY flag.  */
#define CKGR_MCFR_RCMEAS_0                    (CKGR_MCFR_RCMEAS_0_Val << CKGR_MCFR_RCMEAS_Pos)     /* (CKGR_MCFR) No effect. Position  */
#define CKGR_MCFR_RCMEAS_1                    (CKGR_MCFR_RCMEAS_1_Val << CKGR_MCFR_RCMEAS_Pos)     /* (CKGR_MCFR) Restarts measuring of the frequency of MAINCK. MAINF carries the new frequency as soon as a low-to-high transition occurs on the MAINFRDY flag. Position  */
#define CKGR_MCFR_CCSS_Pos                    _UINT32_(24)                                         /* (CKGR_MCFR) Counter Clock Source Selection Position */
#define CKGR_MCFR_CCSS_Msk                    (_UINT32_(0x1) << CKGR_MCFR_CCSS_Pos)                /* (CKGR_MCFR) Counter Clock Source Selection Mask */
#define CKGR_MCFR_CCSS(value)                 (CKGR_MCFR_CCSS_Msk & (_UINT32_(value) << CKGR_MCFR_CCSS_Pos)) /* Assigment of value for CCSS in the CKGR_MCFR register */
#define   CKGR_MCFR_CCSS_0_Val                _UINT32_(0x0)                                        /* (CKGR_MCFR) The measured clock of the MAINF counter is the main RC oscillator.  */
#define   CKGR_MCFR_CCSS_1_Val                _UINT32_(0x1)                                        /* (CKGR_MCFR) The measured clock of the MAINF counter is the main crystal oscillator.  */
#define CKGR_MCFR_CCSS_0                      (CKGR_MCFR_CCSS_0_Val << CKGR_MCFR_CCSS_Pos)         /* (CKGR_MCFR) The measured clock of the MAINF counter is the main RC oscillator. Position  */
#define CKGR_MCFR_CCSS_1                      (CKGR_MCFR_CCSS_1_Val << CKGR_MCFR_CCSS_Pos)         /* (CKGR_MCFR) The measured clock of the MAINF counter is the main crystal oscillator. Position  */
#define CKGR_MCFR_Msk                         _UINT32_(0x0111FFFF)                                 /* (CKGR_MCFR) Register Mask  */


/* -------- PMC_CPU_CKR : (PMC Offset: 0x28) (R/W 32) CPU Clock Register -------- */
#define PMC_CPU_CKR_RESETVALUE                _UINT32_(0x01)                                       /*  (PMC_CPU_CKR) CPU Clock Register  Reset Value */

#define PMC_CPU_CKR_CSS_Pos                   _UINT32_(0)                                          /* (PMC_CPU_CKR) MCK Source Selection Position */
#define PMC_CPU_CKR_CSS_Msk                   (_UINT32_(0x3) << PMC_CPU_CKR_CSS_Pos)               /* (PMC_CPU_CKR) MCK Source Selection Mask */
#define PMC_CPU_CKR_CSS(value)                (PMC_CPU_CKR_CSS_Msk & (_UINT32_(value) << PMC_CPU_CKR_CSS_Pos)) /* Assigment of value for CSS in the PMC_CPU_CKR register */
#define   PMC_CPU_CKR_CSS_SLOW_CLK_Val        _UINT32_(0x0)                                        /* (PMC_CPU_CKR) MD_SLCK is selected  */
#define   PMC_CPU_CKR_CSS_MAIN_CLK_Val        _UINT32_(0x1)                                        /* (PMC_CPU_CKR) MAINCK is selected  */
#define   PMC_CPU_CKR_CSS_PLLACK_Val          _UINT32_(0x2)                                        /* (PMC_CPU_CKR) PLLACK is selected  */
#define   PMC_CPU_CKR_CSS_UPLLCK_Val          _UINT32_(0x3)                                        /* (PMC_CPU_CKR) UPLL is selected  */
#define PMC_CPU_CKR_CSS_SLOW_CLK              (PMC_CPU_CKR_CSS_SLOW_CLK_Val << PMC_CPU_CKR_CSS_Pos) /* (PMC_CPU_CKR) MD_SLCK is selected Position  */
#define PMC_CPU_CKR_CSS_MAIN_CLK              (PMC_CPU_CKR_CSS_MAIN_CLK_Val << PMC_CPU_CKR_CSS_Pos) /* (PMC_CPU_CKR) MAINCK is selected Position  */
#define PMC_CPU_CKR_CSS_PLLACK                (PMC_CPU_CKR_CSS_PLLACK_Val << PMC_CPU_CKR_CSS_Pos)  /* (PMC_CPU_CKR) PLLACK is selected Position  */
#define PMC_CPU_CKR_CSS_UPLLCK                (PMC_CPU_CKR_CSS_UPLLCK_Val << PMC_CPU_CKR_CSS_Pos)  /* (PMC_CPU_CKR) UPLL is selected Position  */
#define PMC_CPU_CKR_PRES_Pos                  _UINT32_(4)                                          /* (PMC_CPU_CKR) Processor Clock Prescaler Position */
#define PMC_CPU_CKR_PRES_Msk                  (_UINT32_(0x7) << PMC_CPU_CKR_PRES_Pos)              /* (PMC_CPU_CKR) Processor Clock Prescaler Mask */
#define PMC_CPU_CKR_PRES(value)               (PMC_CPU_CKR_PRES_Msk & (_UINT32_(value) << PMC_CPU_CKR_PRES_Pos)) /* Assigment of value for PRES in the PMC_CPU_CKR register */
#define   PMC_CPU_CKR_PRES_CLK_1_Val          _UINT32_(0x0)                                        /* (PMC_CPU_CKR) Selected clock  */
#define   PMC_CPU_CKR_PRES_CLK_2_Val          _UINT32_(0x1)                                        /* (PMC_CPU_CKR) Selected clock divided by 2  */
#define   PMC_CPU_CKR_PRES_CLK_4_Val          _UINT32_(0x2)                                        /* (PMC_CPU_CKR) Selected clock divided by 4  */
#define   PMC_CPU_CKR_PRES_CLK_8_Val          _UINT32_(0x3)                                        /* (PMC_CPU_CKR) Selected clock divided by 8  */
#define   PMC_CPU_CKR_PRES_CLK_16_Val         _UINT32_(0x4)                                        /* (PMC_CPU_CKR) Selected clock divided by 16  */
#define   PMC_CPU_CKR_PRES_CLK_32_Val         _UINT32_(0x5)                                        /* (PMC_CPU_CKR) Selected clock divided by 32  */
#define   PMC_CPU_CKR_PRES_CLK_64_Val         _UINT32_(0x6)                                        /* (PMC_CPU_CKR) Selected clock divided by 64  */
#define   PMC_CPU_CKR_PRES_CLK_3_Val          _UINT32_(0x7)                                        /* (PMC_CPU_CKR) Selected clock divided by 3  */
#define PMC_CPU_CKR_PRES_CLK_1                (PMC_CPU_CKR_PRES_CLK_1_Val << PMC_CPU_CKR_PRES_Pos) /* (PMC_CPU_CKR) Selected clock Position  */
#define PMC_CPU_CKR_PRES_CLK_2                (PMC_CPU_CKR_PRES_CLK_2_Val << PMC_CPU_CKR_PRES_Pos) /* (PMC_CPU_CKR) Selected clock divided by 2 Position  */
#define PMC_CPU_CKR_PRES_CLK_4                (PMC_CPU_CKR_PRES_CLK_4_Val << PMC_CPU_CKR_PRES_Pos) /* (PMC_CPU_CKR) Selected clock divided by 4 Position  */
#define PMC_CPU_CKR_PRES_CLK_8                (PMC_CPU_CKR_PRES_CLK_8_Val << PMC_CPU_CKR_PRES_Pos) /* (PMC_CPU_CKR) Selected clock divided by 8 Position  */
#define PMC_CPU_CKR_PRES_CLK_16               (PMC_CPU_CKR_PRES_CLK_16_Val << PMC_CPU_CKR_PRES_Pos) /* (PMC_CPU_CKR) Selected clock divided by 16 Position  */
#define PMC_CPU_CKR_PRES_CLK_32               (PMC_CPU_CKR_PRES_CLK_32_Val << PMC_CPU_CKR_PRES_Pos) /* (PMC_CPU_CKR) Selected clock divided by 32 Position  */
#define PMC_CPU_CKR_PRES_CLK_64               (PMC_CPU_CKR_PRES_CLK_64_Val << PMC_CPU_CKR_PRES_Pos) /* (PMC_CPU_CKR) Selected clock divided by 64 Position  */
#define PMC_CPU_CKR_PRES_CLK_3                (PMC_CPU_CKR_PRES_CLK_3_Val << PMC_CPU_CKR_PRES_Pos) /* (PMC_CPU_CKR) Selected clock divided by 3 Position  */
#define PMC_CPU_CKR_MDIV_Pos                  _UINT32_(8)                                          /* (PMC_CPU_CKR) MCK Division Position */
#define PMC_CPU_CKR_MDIV_Msk                  (_UINT32_(0x7) << PMC_CPU_CKR_MDIV_Pos)              /* (PMC_CPU_CKR) MCK Division Mask */
#define PMC_CPU_CKR_MDIV(value)               (PMC_CPU_CKR_MDIV_Msk & (_UINT32_(value) << PMC_CPU_CKR_MDIV_Pos)) /* Assigment of value for MDIV in the PMC_CPU_CKR register */
#define   PMC_CPU_CKR_MDIV_EQ_PCK_Val         _UINT32_(0x0)                                        /* (PMC_CPU_CKR) MCK is FCLK divided by 1.  */
#define   PMC_CPU_CKR_MDIV_PCK_DIV2_Val       _UINT32_(0x1)                                        /* (PMC_CPU_CKR) MCK is FCLK divided by 2.  */
#define   PMC_CPU_CKR_MDIV_PCK_DIV4_Val       _UINT32_(0x2)                                        /* (PMC_CPU_CKR) MCK is FCLK divided by 4.  */
#define   PMC_CPU_CKR_MDIV_PCK_DIV3_Val       _UINT32_(0x3)                                        /* (PMC_CPU_CKR) MCK is FCLK divided by 3.  */
#define   PMC_CPU_CKR_MDIV_PCK_DIV5_Val       _UINT32_(0x4)                                        /* (PMC_CPU_CKR) MCK is FCLK divided by 5.  */
#define PMC_CPU_CKR_MDIV_EQ_PCK               (PMC_CPU_CKR_MDIV_EQ_PCK_Val << PMC_CPU_CKR_MDIV_Pos) /* (PMC_CPU_CKR) MCK is FCLK divided by 1. Position  */
#define PMC_CPU_CKR_MDIV_PCK_DIV2             (PMC_CPU_CKR_MDIV_PCK_DIV2_Val << PMC_CPU_CKR_MDIV_Pos) /* (PMC_CPU_CKR) MCK is FCLK divided by 2. Position  */
#define PMC_CPU_CKR_MDIV_PCK_DIV4             (PMC_CPU_CKR_MDIV_PCK_DIV4_Val << PMC_CPU_CKR_MDIV_Pos) /* (PMC_CPU_CKR) MCK is FCLK divided by 4. Position  */
#define PMC_CPU_CKR_MDIV_PCK_DIV3             (PMC_CPU_CKR_MDIV_PCK_DIV3_Val << PMC_CPU_CKR_MDIV_Pos) /* (PMC_CPU_CKR) MCK is FCLK divided by 3. Position  */
#define PMC_CPU_CKR_MDIV_PCK_DIV5             (PMC_CPU_CKR_MDIV_PCK_DIV5_Val << PMC_CPU_CKR_MDIV_Pos) /* (PMC_CPU_CKR) MCK is FCLK divided by 5. Position  */
#define PMC_CPU_CKR_Msk                       _UINT32_(0x00000773)                                 /* (PMC_CPU_CKR) Register Mask  */


/* -------- PMC_USB : (PMC Offset: 0x38) (R/W 32) USB Clock Register -------- */
#define PMC_USB_RESETVALUE                    _UINT32_(0x00)                                       /*  (PMC_USB) USB Clock Register  Reset Value */

#define PMC_USB_USBS_Pos                      _UINT32_(0)                                          /* (PMC_USB) USB OHCI/EHCI Input Clock Selection Position */
#define PMC_USB_USBS_Msk                      (_UINT32_(0x3) << PMC_USB_USBS_Pos)                  /* (PMC_USB) USB OHCI/EHCI Input Clock Selection Mask */
#define PMC_USB_USBS(value)                   (PMC_USB_USBS_Msk & (_UINT32_(value) << PMC_USB_USBS_Pos)) /* Assigment of value for USBS in the PMC_USB register */
#define   PMC_USB_USBS_PLLA_Val               _UINT32_(0x0)                                        /* (PMC_USB) USB Clock Input is PLLACK.  */
#define   PMC_USB_USBS_UPLL_Val               _UINT32_(0x1)                                        /* (PMC_USB) USB Clock Input is UPLLCK.  */
#define   PMC_USB_USBS_MAINXTAL_Val           _UINT32_(0x2)                                        /* (PMC_USB) USB Clock Input is MAINXTALCK.  */
#define PMC_USB_USBS_PLLA                     (PMC_USB_USBS_PLLA_Val << PMC_USB_USBS_Pos)          /* (PMC_USB) USB Clock Input is PLLACK. Position  */
#define PMC_USB_USBS_UPLL                     (PMC_USB_USBS_UPLL_Val << PMC_USB_USBS_Pos)          /* (PMC_USB) USB Clock Input is UPLLCK. Position  */
#define PMC_USB_USBS_MAINXTAL                 (PMC_USB_USBS_MAINXTAL_Val << PMC_USB_USBS_Pos)      /* (PMC_USB) USB Clock Input is MAINXTALCK. Position  */
#define PMC_USB_USBDIV_Pos                    _UINT32_(8)                                          /* (PMC_USB) Divider for USB OHCI Clock Position */
#define PMC_USB_USBDIV_Msk                    (_UINT32_(0xF) << PMC_USB_USBDIV_Pos)                /* (PMC_USB) Divider for USB OHCI Clock Mask */
#define PMC_USB_USBDIV(value)                 (PMC_USB_USBDIV_Msk & (_UINT32_(value) << PMC_USB_USBDIV_Pos)) /* Assigment of value for USBDIV in the PMC_USB register */
#define PMC_USB_Msk                           _UINT32_(0x00000F03)                                 /* (PMC_USB) Register Mask  */


/* -------- PMC_PCK : (PMC Offset: 0x40) (R/W 32) Programmable Clock Register x -------- */
#define PMC_PCK_RESETVALUE                    _UINT32_(0x00)                                       /*  (PMC_PCK) Programmable Clock Register x  Reset Value */

#define PMC_PCK_CSS_Pos                       _UINT32_(0)                                          /* (PMC_PCK) Programmable Clock Source Selection Position */
#define PMC_PCK_CSS_Msk                       (_UINT32_(0x1F) << PMC_PCK_CSS_Pos)                  /* (PMC_PCK) Programmable Clock Source Selection Mask */
#define PMC_PCK_CSS(value)                    (PMC_PCK_CSS_Msk & (_UINT32_(value) << PMC_PCK_CSS_Pos)) /* Assigment of value for CSS in the PMC_PCK register */
#define   PMC_PCK_CSS_MD_SLOW_CLK_Val         _UINT32_(0x0)                                        /* (PMC_PCK) MD_SLCK is selected  */
#define   PMC_PCK_CSS_TD_SLOW_CLOCK_Val       _UINT32_(0x1)                                        /* (PMC_PCK) TD_SLCK is selected  */
#define   PMC_PCK_CSS_MAINCK_Val              _UINT32_(0x2)                                        /* (PMC_PCK) MAINCK is selected  */
#define   PMC_PCK_CSS_MCK_Val                 _UINT32_(0x3)                                        /* (PMC_PCK) MCK is selected  */
#define   PMC_PCK_CSS_PLLA_Val                _UINT32_(0x4)                                        /* (PMC_PCK) PLLA is selected.  */
#define   PMC_PCK_CSS_UPLL_Val                _UINT32_(0x5)                                        /* (PMC_PCK) UPLL is selected.  */
#define   PMC_PCK_CSS_AUDIOPLL_Val            _UINT32_(0x6)                                        /* (PMC_PCK) Audio PLL is selected.  */
#define PMC_PCK_CSS_MD_SLOW_CLK               (PMC_PCK_CSS_MD_SLOW_CLK_Val << PMC_PCK_CSS_Pos)     /* (PMC_PCK) MD_SLCK is selected Position  */
#define PMC_PCK_CSS_TD_SLOW_CLOCK             (PMC_PCK_CSS_TD_SLOW_CLOCK_Val << PMC_PCK_CSS_Pos)   /* (PMC_PCK) TD_SLCK is selected Position  */
#define PMC_PCK_CSS_MAINCK                    (PMC_PCK_CSS_MAINCK_Val << PMC_PCK_CSS_Pos)          /* (PMC_PCK) MAINCK is selected Position  */
#define PMC_PCK_CSS_MCK                       (PMC_PCK_CSS_MCK_Val << PMC_PCK_CSS_Pos)             /* (PMC_PCK) MCK is selected Position  */
#define PMC_PCK_CSS_PLLA                      (PMC_PCK_CSS_PLLA_Val << PMC_PCK_CSS_Pos)            /* (PMC_PCK) PLLA is selected. Position  */
#define PMC_PCK_CSS_UPLL                      (PMC_PCK_CSS_UPLL_Val << PMC_PCK_CSS_Pos)            /* (PMC_PCK) UPLL is selected. Position  */
#define PMC_PCK_CSS_AUDIOPLL                  (PMC_PCK_CSS_AUDIOPLL_Val << PMC_PCK_CSS_Pos)        /* (PMC_PCK) Audio PLL is selected. Position  */
#define PMC_PCK_PRES_Pos                      _UINT32_(8)                                          /* (PMC_PCK) Programmable Clock Prescaler Position */
#define PMC_PCK_PRES_Msk                      (_UINT32_(0xFF) << PMC_PCK_PRES_Pos)                 /* (PMC_PCK) Programmable Clock Prescaler Mask */
#define PMC_PCK_PRES(value)                   (PMC_PCK_PRES_Msk & (_UINT32_(value) << PMC_PCK_PRES_Pos)) /* Assigment of value for PRES in the PMC_PCK register */
#define PMC_PCK_Msk                           _UINT32_(0x0000FF1F)                                 /* (PMC_PCK) Register Mask  */


/* -------- PMC_IER : (PMC Offset: 0x60) ( /W 32) Interrupt Enable Register -------- */
#define PMC_IER_MOSCXTS_Pos                   _UINT32_(0)                                          /* (PMC_IER) Main Crystal Oscillator Status Interrupt Enable Position */
#define PMC_IER_MOSCXTS_Msk                   (_UINT32_(0x1) << PMC_IER_MOSCXTS_Pos)               /* (PMC_IER) Main Crystal Oscillator Status Interrupt Enable Mask */
#define PMC_IER_MOSCXTS(value)                (PMC_IER_MOSCXTS_Msk & (_UINT32_(value) << PMC_IER_MOSCXTS_Pos)) /* Assigment of value for MOSCXTS in the PMC_IER register */
#define PMC_IER_MCKRDY_Pos                    _UINT32_(3)                                          /* (PMC_IER) Main System Bus Clock Ready Interrupt Enable Position */
#define PMC_IER_MCKRDY_Msk                    (_UINT32_(0x1) << PMC_IER_MCKRDY_Pos)                /* (PMC_IER) Main System Bus Clock Ready Interrupt Enable Mask */
#define PMC_IER_MCKRDY(value)                 (PMC_IER_MCKRDY_Msk & (_UINT32_(value) << PMC_IER_MCKRDY_Pos)) /* Assigment of value for MCKRDY in the PMC_IER register */
#define PMC_IER_PCKRDY0_Pos                   _UINT32_(8)                                          /* (PMC_IER) Programmable Clock Ready 0 Interrupt Enable Position */
#define PMC_IER_PCKRDY0_Msk                   (_UINT32_(0x1) << PMC_IER_PCKRDY0_Pos)               /* (PMC_IER) Programmable Clock Ready 0 Interrupt Enable Mask */
#define PMC_IER_PCKRDY0(value)                (PMC_IER_PCKRDY0_Msk & (_UINT32_(value) << PMC_IER_PCKRDY0_Pos)) /* Assigment of value for PCKRDY0 in the PMC_IER register */
#define PMC_IER_PCKRDY1_Pos                   _UINT32_(9)                                          /* (PMC_IER) Programmable Clock Ready 1 Interrupt Enable Position */
#define PMC_IER_PCKRDY1_Msk                   (_UINT32_(0x1) << PMC_IER_PCKRDY1_Pos)               /* (PMC_IER) Programmable Clock Ready 1 Interrupt Enable Mask */
#define PMC_IER_PCKRDY1(value)                (PMC_IER_PCKRDY1_Msk & (_UINT32_(value) << PMC_IER_PCKRDY1_Pos)) /* Assigment of value for PCKRDY1 in the PMC_IER register */
#define PMC_IER_MOSCSELS_Pos                  _UINT32_(16)                                         /* (PMC_IER) Main Clock Source Oscillator Selection Status Interrupt Enable Position */
#define PMC_IER_MOSCSELS_Msk                  (_UINT32_(0x1) << PMC_IER_MOSCSELS_Pos)              /* (PMC_IER) Main Clock Source Oscillator Selection Status Interrupt Enable Mask */
#define PMC_IER_MOSCSELS(value)               (PMC_IER_MOSCSELS_Msk & (_UINT32_(value) << PMC_IER_MOSCSELS_Pos)) /* Assigment of value for MOSCSELS in the PMC_IER register */
#define PMC_IER_MOSCRCS_Pos                   _UINT32_(17)                                         /* (PMC_IER) Main RC Oscillator Status Interrupt Enable Position */
#define PMC_IER_MOSCRCS_Msk                   (_UINT32_(0x1) << PMC_IER_MOSCRCS_Pos)               /* (PMC_IER) Main RC Oscillator Status Interrupt Enable Mask */
#define PMC_IER_MOSCRCS(value)                (PMC_IER_MOSCRCS_Msk & (_UINT32_(value) << PMC_IER_MOSCRCS_Pos)) /* Assigment of value for MOSCRCS in the PMC_IER register */
#define PMC_IER_CFDEV_Pos                     _UINT32_(18)                                         /* (PMC_IER) Clock Failure Detector Event Interrupt Enable Position */
#define PMC_IER_CFDEV_Msk                     (_UINT32_(0x1) << PMC_IER_CFDEV_Pos)                 /* (PMC_IER) Clock Failure Detector Event Interrupt Enable Mask */
#define PMC_IER_CFDEV(value)                  (PMC_IER_CFDEV_Msk & (_UINT32_(value) << PMC_IER_CFDEV_Pos)) /* Assigment of value for CFDEV in the PMC_IER register */
#define PMC_IER_XT32KERR_Pos                  _UINT32_(21)                                         /* (PMC_IER) 32.768 kHz Crystal Oscillator Error Interrupt Enable Position */
#define PMC_IER_XT32KERR_Msk                  (_UINT32_(0x1) << PMC_IER_XT32KERR_Pos)              /* (PMC_IER) 32.768 kHz Crystal Oscillator Error Interrupt Enable Mask */
#define PMC_IER_XT32KERR(value)               (PMC_IER_XT32KERR_Msk & (_UINT32_(value) << PMC_IER_XT32KERR_Pos)) /* Assigment of value for XT32KERR in the PMC_IER register */
#define PMC_IER_MCKMON_Pos                    _UINT32_(23)                                         /* (PMC_IER) Main System Bus Clock  Clock Monitor Interrupt Enable Position */
#define PMC_IER_MCKMON_Msk                    (_UINT32_(0x1) << PMC_IER_MCKMON_Pos)                /* (PMC_IER) Main System Bus Clock  Clock Monitor Interrupt Enable Mask */
#define PMC_IER_MCKMON(value)                 (PMC_IER_MCKMON_Msk & (_UINT32_(value) << PMC_IER_MCKMON_Pos)) /* Assigment of value for MCKMON in the PMC_IER register */
#define PMC_IER_PLL_INT_Pos                   _UINT32_(25)                                         /* (PMC_IER) PLL Interrupt Enable Position */
#define PMC_IER_PLL_INT_Msk                   (_UINT32_(0x1) << PMC_IER_PLL_INT_Pos)               /* (PMC_IER) PLL Interrupt Enable Mask */
#define PMC_IER_PLL_INT(value)                (PMC_IER_PLL_INT_Msk & (_UINT32_(value) << PMC_IER_PLL_INT_Pos)) /* Assigment of value for PLL_INT in the PMC_IER register */
#define PMC_IER_Msk                           _UINT32_(0x02A70309)                                 /* (PMC_IER) Register Mask  */

#define PMC_IER_PCKRDY_Pos                    _UINT32_(8)                                          /* (PMC_IER Position) Programmable Clock Ready x Interrupt Enable */
#define PMC_IER_PCKRDY_Msk                    (_UINT32_(0x3) << PMC_IER_PCKRDY_Pos)                /* (PMC_IER Mask) PCKRDY */
#define PMC_IER_PCKRDY(value)                 (PMC_IER_PCKRDY_Msk & (_UINT32_(value) << PMC_IER_PCKRDY_Pos)) 

/* -------- PMC_IDR : (PMC Offset: 0x64) ( /W 32) Interrupt Disable Register -------- */
#define PMC_IDR_MOSCXTS_Pos                   _UINT32_(0)                                          /* (PMC_IDR) Main Crystal Oscillator Status Interrupt Disable Position */
#define PMC_IDR_MOSCXTS_Msk                   (_UINT32_(0x1) << PMC_IDR_MOSCXTS_Pos)               /* (PMC_IDR) Main Crystal Oscillator Status Interrupt Disable Mask */
#define PMC_IDR_MOSCXTS(value)                (PMC_IDR_MOSCXTS_Msk & (_UINT32_(value) << PMC_IDR_MOSCXTS_Pos)) /* Assigment of value for MOSCXTS in the PMC_IDR register */
#define PMC_IDR_MCKRDY_Pos                    _UINT32_(3)                                          /* (PMC_IDR) Main System Bus Clock Ready Interrupt Disable Position */
#define PMC_IDR_MCKRDY_Msk                    (_UINT32_(0x1) << PMC_IDR_MCKRDY_Pos)                /* (PMC_IDR) Main System Bus Clock Ready Interrupt Disable Mask */
#define PMC_IDR_MCKRDY(value)                 (PMC_IDR_MCKRDY_Msk & (_UINT32_(value) << PMC_IDR_MCKRDY_Pos)) /* Assigment of value for MCKRDY in the PMC_IDR register */
#define PMC_IDR_PCKRDY0_Pos                   _UINT32_(8)                                          /* (PMC_IDR) Programmable Clock Ready 0 Interrupt Disable Position */
#define PMC_IDR_PCKRDY0_Msk                   (_UINT32_(0x1) << PMC_IDR_PCKRDY0_Pos)               /* (PMC_IDR) Programmable Clock Ready 0 Interrupt Disable Mask */
#define PMC_IDR_PCKRDY0(value)                (PMC_IDR_PCKRDY0_Msk & (_UINT32_(value) << PMC_IDR_PCKRDY0_Pos)) /* Assigment of value for PCKRDY0 in the PMC_IDR register */
#define PMC_IDR_PCKRDY1_Pos                   _UINT32_(9)                                          /* (PMC_IDR) Programmable Clock Ready 1 Interrupt Disable Position */
#define PMC_IDR_PCKRDY1_Msk                   (_UINT32_(0x1) << PMC_IDR_PCKRDY1_Pos)               /* (PMC_IDR) Programmable Clock Ready 1 Interrupt Disable Mask */
#define PMC_IDR_PCKRDY1(value)                (PMC_IDR_PCKRDY1_Msk & (_UINT32_(value) << PMC_IDR_PCKRDY1_Pos)) /* Assigment of value for PCKRDY1 in the PMC_IDR register */
#define PMC_IDR_MOSCSELS_Pos                  _UINT32_(16)                                         /* (PMC_IDR) Main Clock Source Oscillator Selection Status Interrupt Disable Position */
#define PMC_IDR_MOSCSELS_Msk                  (_UINT32_(0x1) << PMC_IDR_MOSCSELS_Pos)              /* (PMC_IDR) Main Clock Source Oscillator Selection Status Interrupt Disable Mask */
#define PMC_IDR_MOSCSELS(value)               (PMC_IDR_MOSCSELS_Msk & (_UINT32_(value) << PMC_IDR_MOSCSELS_Pos)) /* Assigment of value for MOSCSELS in the PMC_IDR register */
#define PMC_IDR_MOSCRCS_Pos                   _UINT32_(17)                                         /* (PMC_IDR) Main RC Status Interrupt Disable Position */
#define PMC_IDR_MOSCRCS_Msk                   (_UINT32_(0x1) << PMC_IDR_MOSCRCS_Pos)               /* (PMC_IDR) Main RC Status Interrupt Disable Mask */
#define PMC_IDR_MOSCRCS(value)                (PMC_IDR_MOSCRCS_Msk & (_UINT32_(value) << PMC_IDR_MOSCRCS_Pos)) /* Assigment of value for MOSCRCS in the PMC_IDR register */
#define PMC_IDR_CFDEV_Pos                     _UINT32_(18)                                         /* (PMC_IDR) Clock Failure Detector Event Interrupt Disable Position */
#define PMC_IDR_CFDEV_Msk                     (_UINT32_(0x1) << PMC_IDR_CFDEV_Pos)                 /* (PMC_IDR) Clock Failure Detector Event Interrupt Disable Mask */
#define PMC_IDR_CFDEV(value)                  (PMC_IDR_CFDEV_Msk & (_UINT32_(value) << PMC_IDR_CFDEV_Pos)) /* Assigment of value for CFDEV in the PMC_IDR register */
#define PMC_IDR_XT32KERR_Pos                  _UINT32_(21)                                         /* (PMC_IDR) 32.768 kHz Crystal Oscillator Error Interrupt Disable Position */
#define PMC_IDR_XT32KERR_Msk                  (_UINT32_(0x1) << PMC_IDR_XT32KERR_Pos)              /* (PMC_IDR) 32.768 kHz Crystal Oscillator Error Interrupt Disable Mask */
#define PMC_IDR_XT32KERR(value)               (PMC_IDR_XT32KERR_Msk & (_UINT32_(value) << PMC_IDR_XT32KERR_Pos)) /* Assigment of value for XT32KERR in the PMC_IDR register */
#define PMC_IDR_MCKMON_Pos                    _UINT32_(23)                                         /* (PMC_IDR) Main System Bus Clock  Clock Monitor Interrupt Disable Position */
#define PMC_IDR_MCKMON_Msk                    (_UINT32_(0x1) << PMC_IDR_MCKMON_Pos)                /* (PMC_IDR) Main System Bus Clock  Clock Monitor Interrupt Disable Mask */
#define PMC_IDR_MCKMON(value)                 (PMC_IDR_MCKMON_Msk & (_UINT32_(value) << PMC_IDR_MCKMON_Pos)) /* Assigment of value for MCKMON in the PMC_IDR register */
#define PMC_IDR_PLL_INT_Pos                   _UINT32_(25)                                         /* (PMC_IDR) PLL Interrupt Disable Position */
#define PMC_IDR_PLL_INT_Msk                   (_UINT32_(0x1) << PMC_IDR_PLL_INT_Pos)               /* (PMC_IDR) PLL Interrupt Disable Mask */
#define PMC_IDR_PLL_INT(value)                (PMC_IDR_PLL_INT_Msk & (_UINT32_(value) << PMC_IDR_PLL_INT_Pos)) /* Assigment of value for PLL_INT in the PMC_IDR register */
#define PMC_IDR_Msk                           _UINT32_(0x02A70309)                                 /* (PMC_IDR) Register Mask  */

#define PMC_IDR_PCKRDY_Pos                    _UINT32_(8)                                          /* (PMC_IDR Position) Programmable Clock Ready x Interrupt Disable */
#define PMC_IDR_PCKRDY_Msk                    (_UINT32_(0x3) << PMC_IDR_PCKRDY_Pos)                /* (PMC_IDR Mask) PCKRDY */
#define PMC_IDR_PCKRDY(value)                 (PMC_IDR_PCKRDY_Msk & (_UINT32_(value) << PMC_IDR_PCKRDY_Pos)) 

/* -------- PMC_SR : (PMC Offset: 0x68) ( R/ 32) Status Register -------- */
#define PMC_SR_RESETVALUE                     _UINT32_(0x30008)                                    /*  (PMC_SR) Status Register  Reset Value */

#define PMC_SR_MOSCXTS_Pos                    _UINT32_(0)                                          /* (PMC_SR) Main Crystal Oscillator Status Position */
#define PMC_SR_MOSCXTS_Msk                    (_UINT32_(0x1) << PMC_SR_MOSCXTS_Pos)                /* (PMC_SR) Main Crystal Oscillator Status Mask */
#define PMC_SR_MOSCXTS(value)                 (PMC_SR_MOSCXTS_Msk & (_UINT32_(value) << PMC_SR_MOSCXTS_Pos)) /* Assigment of value for MOSCXTS in the PMC_SR register */
#define   PMC_SR_MOSCXTS_0_Val                _UINT32_(0x0)                                        /* (PMC_SR) Main crystal oscillator is not stabilized.  */
#define   PMC_SR_MOSCXTS_1_Val                _UINT32_(0x1)                                        /* (PMC_SR) Main crystal oscillator is stabilized.  */
#define PMC_SR_MOSCXTS_0                      (PMC_SR_MOSCXTS_0_Val << PMC_SR_MOSCXTS_Pos)         /* (PMC_SR) Main crystal oscillator is not stabilized. Position  */
#define PMC_SR_MOSCXTS_1                      (PMC_SR_MOSCXTS_1_Val << PMC_SR_MOSCXTS_Pos)         /* (PMC_SR) Main crystal oscillator is stabilized. Position  */
#define PMC_SR_MCKRDY_Pos                     _UINT32_(3)                                          /* (PMC_SR) Main System Bus Clock Status Position */
#define PMC_SR_MCKRDY_Msk                     (_UINT32_(0x1) << PMC_SR_MCKRDY_Pos)                 /* (PMC_SR) Main System Bus Clock Status Mask */
#define PMC_SR_MCKRDY(value)                  (PMC_SR_MCKRDY_Msk & (_UINT32_(value) << PMC_SR_MCKRDY_Pos)) /* Assigment of value for MCKRDY in the PMC_SR register */
#define   PMC_SR_MCKRDY_0_Val                 _UINT32_(0x0)                                        /* (PMC_SR) Main System Bus Clock is not ready.  */
#define   PMC_SR_MCKRDY_1_Val                 _UINT32_(0x1)                                        /* (PMC_SR) Main System Bus Clock is ready.  */
#define PMC_SR_MCKRDY_0                       (PMC_SR_MCKRDY_0_Val << PMC_SR_MCKRDY_Pos)           /* (PMC_SR) Main System Bus Clock is not ready. Position  */
#define PMC_SR_MCKRDY_1                       (PMC_SR_MCKRDY_1_Val << PMC_SR_MCKRDY_Pos)           /* (PMC_SR) Main System Bus Clock is ready. Position  */
#define PMC_SR_PCKRDY0_Pos                    _UINT32_(8)                                          /* (PMC_SR) Programmable Clock Ready Status Position */
#define PMC_SR_PCKRDY0_Msk                    (_UINT32_(0x1) << PMC_SR_PCKRDY0_Pos)                /* (PMC_SR) Programmable Clock Ready Status Mask */
#define PMC_SR_PCKRDY0(value)                 (PMC_SR_PCKRDY0_Msk & (_UINT32_(value) << PMC_SR_PCKRDY0_Pos)) /* Assigment of value for PCKRDY0 in the PMC_SR register */
#define   PMC_SR_PCKRDY0_0_Val                _UINT32_(0x0)                                        /* (PMC_SR) Programmable Clock x is not ready.  */
#define   PMC_SR_PCKRDY0_1_Val                _UINT32_(0x1)                                        /* (PMC_SR) Programmable Clock x is ready.  */
#define PMC_SR_PCKRDY0_0                      (PMC_SR_PCKRDY0_0_Val << PMC_SR_PCKRDY0_Pos)         /* (PMC_SR) Programmable Clock x is not ready. Position  */
#define PMC_SR_PCKRDY0_1                      (PMC_SR_PCKRDY0_1_Val << PMC_SR_PCKRDY0_Pos)         /* (PMC_SR) Programmable Clock x is ready. Position  */
#define PMC_SR_PCKRDY1_Pos                    _UINT32_(9)                                          /* (PMC_SR) Programmable Clock Ready Status Position */
#define PMC_SR_PCKRDY1_Msk                    (_UINT32_(0x1) << PMC_SR_PCKRDY1_Pos)                /* (PMC_SR) Programmable Clock Ready Status Mask */
#define PMC_SR_PCKRDY1(value)                 (PMC_SR_PCKRDY1_Msk & (_UINT32_(value) << PMC_SR_PCKRDY1_Pos)) /* Assigment of value for PCKRDY1 in the PMC_SR register */
#define   PMC_SR_PCKRDY1_0_Val                _UINT32_(0x0)                                        /* (PMC_SR) Programmable Clock x is not ready.  */
#define   PMC_SR_PCKRDY1_1_Val                _UINT32_(0x1)                                        /* (PMC_SR) Programmable Clock x is ready.  */
#define PMC_SR_PCKRDY1_0                      (PMC_SR_PCKRDY1_0_Val << PMC_SR_PCKRDY1_Pos)         /* (PMC_SR) Programmable Clock x is not ready. Position  */
#define PMC_SR_PCKRDY1_1                      (PMC_SR_PCKRDY1_1_Val << PMC_SR_PCKRDY1_Pos)         /* (PMC_SR) Programmable Clock x is ready. Position  */
#define PMC_SR_MOSCSELS_Pos                   _UINT32_(16)                                         /* (PMC_SR) Main Clock Source Oscillator Selection Status Position */
#define PMC_SR_MOSCSELS_Msk                   (_UINT32_(0x1) << PMC_SR_MOSCSELS_Pos)               /* (PMC_SR) Main Clock Source Oscillator Selection Status Mask */
#define PMC_SR_MOSCSELS(value)                (PMC_SR_MOSCSELS_Msk & (_UINT32_(value) << PMC_SR_MOSCSELS_Pos)) /* Assigment of value for MOSCSELS in the PMC_SR register */
#define   PMC_SR_MOSCSELS_0_Val               _UINT32_(0x0)                                        /* (PMC_SR) Selection is in progress.  */
#define   PMC_SR_MOSCSELS_1_Val               _UINT32_(0x1)                                        /* (PMC_SR) Selection is done.  */
#define PMC_SR_MOSCSELS_0                     (PMC_SR_MOSCSELS_0_Val << PMC_SR_MOSCSELS_Pos)       /* (PMC_SR) Selection is in progress. Position  */
#define PMC_SR_MOSCSELS_1                     (PMC_SR_MOSCSELS_1_Val << PMC_SR_MOSCSELS_Pos)       /* (PMC_SR) Selection is done. Position  */
#define PMC_SR_MOSCRCS_Pos                    _UINT32_(17)                                         /* (PMC_SR) Main RC Oscillator Status Position */
#define PMC_SR_MOSCRCS_Msk                    (_UINT32_(0x1) << PMC_SR_MOSCRCS_Pos)                /* (PMC_SR) Main RC Oscillator Status Mask */
#define PMC_SR_MOSCRCS(value)                 (PMC_SR_MOSCRCS_Msk & (_UINT32_(value) << PMC_SR_MOSCRCS_Pos)) /* Assigment of value for MOSCRCS in the PMC_SR register */
#define   PMC_SR_MOSCRCS_0_Val                _UINT32_(0x0)                                        /* (PMC_SR) Main RC oscillator is not stabilized.  */
#define   PMC_SR_MOSCRCS_1_Val                _UINT32_(0x1)                                        /* (PMC_SR) Main RC oscillator is stabilized.  */
#define PMC_SR_MOSCRCS_0                      (PMC_SR_MOSCRCS_0_Val << PMC_SR_MOSCRCS_Pos)         /* (PMC_SR) Main RC oscillator is not stabilized. Position  */
#define PMC_SR_MOSCRCS_1                      (PMC_SR_MOSCRCS_1_Val << PMC_SR_MOSCRCS_Pos)         /* (PMC_SR) Main RC oscillator is stabilized. Position  */
#define PMC_SR_CFDEV_Pos                      _UINT32_(18)                                         /* (PMC_SR) Clock Failure Detector Event Position */
#define PMC_SR_CFDEV_Msk                      (_UINT32_(0x1) << PMC_SR_CFDEV_Pos)                  /* (PMC_SR) Clock Failure Detector Event Mask */
#define PMC_SR_CFDEV(value)                   (PMC_SR_CFDEV_Msk & (_UINT32_(value) << PMC_SR_CFDEV_Pos)) /* Assigment of value for CFDEV in the PMC_SR register */
#define   PMC_SR_CFDEV_0_Val                  _UINT32_(0x0)                                        /* (PMC_SR) No clock failure detection of the main crystal oscillator clock has occurred since the last read of PMC_SR.  */
#define   PMC_SR_CFDEV_1_Val                  _UINT32_(0x1)                                        /* (PMC_SR) At least one clock failure detection of the main crystal oscillator clock has occurred since the last read of PMC_SR.  */
#define PMC_SR_CFDEV_0                        (PMC_SR_CFDEV_0_Val << PMC_SR_CFDEV_Pos)             /* (PMC_SR) No clock failure detection of the main crystal oscillator clock has occurred since the last read of PMC_SR. Position  */
#define PMC_SR_CFDEV_1                        (PMC_SR_CFDEV_1_Val << PMC_SR_CFDEV_Pos)             /* (PMC_SR) At least one clock failure detection of the main crystal oscillator clock has occurred since the last read of PMC_SR. Position  */
#define PMC_SR_CFDS_Pos                       _UINT32_(19)                                         /* (PMC_SR) Clock Failure Detector Status Position */
#define PMC_SR_CFDS_Msk                       (_UINT32_(0x1) << PMC_SR_CFDS_Pos)                   /* (PMC_SR) Clock Failure Detector Status Mask */
#define PMC_SR_CFDS(value)                    (PMC_SR_CFDS_Msk & (_UINT32_(value) << PMC_SR_CFDS_Pos)) /* Assigment of value for CFDS in the PMC_SR register */
#define   PMC_SR_CFDS_0_Val                   _UINT32_(0x0)                                        /* (PMC_SR) A clock failure of the main crystal oscillator clock is not detected.  */
#define   PMC_SR_CFDS_1_Val                   _UINT32_(0x1)                                        /* (PMC_SR) A clock failure of the main crystal oscillator clock is detected.  */
#define PMC_SR_CFDS_0                         (PMC_SR_CFDS_0_Val << PMC_SR_CFDS_Pos)               /* (PMC_SR) A clock failure of the main crystal oscillator clock is not detected. Position  */
#define PMC_SR_CFDS_1                         (PMC_SR_CFDS_1_Val << PMC_SR_CFDS_Pos)               /* (PMC_SR) A clock failure of the main crystal oscillator clock is detected. Position  */
#define PMC_SR_FOS_Pos                        _UINT32_(20)                                         /* (PMC_SR) Clock Failure Detector Fault Output Status Position */
#define PMC_SR_FOS_Msk                        (_UINT32_(0x1) << PMC_SR_FOS_Pos)                    /* (PMC_SR) Clock Failure Detector Fault Output Status Mask */
#define PMC_SR_FOS(value)                     (PMC_SR_FOS_Msk & (_UINT32_(value) << PMC_SR_FOS_Pos)) /* Assigment of value for FOS in the PMC_SR register */
#define   PMC_SR_FOS_0_Val                    _UINT32_(0x0)                                        /* (PMC_SR) The fault output of the clock failure detector is inactive.  */
#define   PMC_SR_FOS_1_Val                    _UINT32_(0x1)                                        /* (PMC_SR) The fault output of the clock failure detector is active. This status is cleared by writing a '1' to FOCLR in PMC_FOCR.  */
#define PMC_SR_FOS_0                          (PMC_SR_FOS_0_Val << PMC_SR_FOS_Pos)                 /* (PMC_SR) The fault output of the clock failure detector is inactive. Position  */
#define PMC_SR_FOS_1                          (PMC_SR_FOS_1_Val << PMC_SR_FOS_Pos)                 /* (PMC_SR) The fault output of the clock failure detector is active. This status is cleared by writing a '1' to FOCLR in PMC_FOCR. Position  */
#define PMC_SR_XT32KERR_Pos                   _UINT32_(21)                                         /* (PMC_SR) Slow Crystal Oscillator Error Position */
#define PMC_SR_XT32KERR_Msk                   (_UINT32_(0x1) << PMC_SR_XT32KERR_Pos)               /* (PMC_SR) Slow Crystal Oscillator Error Mask */
#define PMC_SR_XT32KERR(value)                (PMC_SR_XT32KERR_Msk & (_UINT32_(value) << PMC_SR_XT32KERR_Pos)) /* Assigment of value for XT32KERR in the PMC_SR register */
#define   PMC_SR_XT32KERR_0_Val               _UINT32_(0x0)                                        /* (PMC_SR) The frequency of the 32.768 kHz crystal oscillator is correct (32.768 kHz +- 1%) or the monitoring is disabled.  */
#define   PMC_SR_XT32KERR_1_Val               _UINT32_(0x1)                                        /* (PMC_SR) The frequency of the 32.768 kHz crystal oscillator is incorrect or has been incorrect for an elapsed period of time since the monitoring has been enabled.  */
#define PMC_SR_XT32KERR_0                     (PMC_SR_XT32KERR_0_Val << PMC_SR_XT32KERR_Pos)       /* (PMC_SR) The frequency of the 32.768 kHz crystal oscillator is correct (32.768 kHz +- 1%) or the monitoring is disabled. Position  */
#define PMC_SR_XT32KERR_1                     (PMC_SR_XT32KERR_1_Val << PMC_SR_XT32KERR_Pos)       /* (PMC_SR) The frequency of the 32.768 kHz crystal oscillator is incorrect or has been incorrect for an elapsed period of time since the monitoring has been enabled. Position  */
#define PMC_SR_MCKMON_Pos                     _UINT32_(23)                                         /* (PMC_SR) Main System Bus Clock Clock Monitor Error Position */
#define PMC_SR_MCKMON_Msk                     (_UINT32_(0x1) << PMC_SR_MCKMON_Pos)                 /* (PMC_SR) Main System Bus Clock Clock Monitor Error Mask */
#define PMC_SR_MCKMON(value)                  (PMC_SR_MCKMON_Msk & (_UINT32_(value) << PMC_SR_MCKMON_Pos)) /* Assigment of value for MCKMON in the PMC_SR register */
#define   PMC_SR_MCKMON_0_Val                 _UINT32_(0x0)                                        /* (PMC_SR) Main System Bus Clock is correct or the CPU clock monitor is disabled.  */
#define   PMC_SR_MCKMON_1_Val                 _UINT32_(0x1)                                        /* (PMC_SR) Main System Bus is incorrect or has been incorrect for an elapsed period of time since the monitoring has been enabled.  */
#define PMC_SR_MCKMON_0                       (PMC_SR_MCKMON_0_Val << PMC_SR_MCKMON_Pos)           /* (PMC_SR) Main System Bus Clock is correct or the CPU clock monitor is disabled. Position  */
#define PMC_SR_MCKMON_1                       (PMC_SR_MCKMON_1_Val << PMC_SR_MCKMON_Pos)           /* (PMC_SR) Main System Bus is incorrect or has been incorrect for an elapsed period of time since the monitoring has been enabled. Position  */
#define PMC_SR_GCLKRDY_Pos                    _UINT32_(24)                                         /* (PMC_SR) GCLK Ready Position */
#define PMC_SR_GCLKRDY_Msk                    (_UINT32_(0x1) << PMC_SR_GCLKRDY_Pos)                /* (PMC_SR) GCLK Ready Mask */
#define PMC_SR_GCLKRDY(value)                 (PMC_SR_GCLKRDY_Msk & (_UINT32_(value) << PMC_SR_GCLKRDY_Pos)) /* Assigment of value for GCLKRDY in the PMC_SR register */
#define   PMC_SR_GCLKRDY_0_Val                _UINT32_(0x0)                                        /* (PMC_SR) A GCLK is not ready to use (clock switching in progress).  */
#define   PMC_SR_GCLKRDY_1_Val                _UINT32_(0x1)                                        /* (PMC_SR) All GCLKs are switched to their selected source clock and ready to use.  */
#define PMC_SR_GCLKRDY_0                      (PMC_SR_GCLKRDY_0_Val << PMC_SR_GCLKRDY_Pos)         /* (PMC_SR) A GCLK is not ready to use (clock switching in progress). Position  */
#define PMC_SR_GCLKRDY_1                      (PMC_SR_GCLKRDY_1_Val << PMC_SR_GCLKRDY_Pos)         /* (PMC_SR) All GCLKs are switched to their selected source clock and ready to use. Position  */
#define PMC_SR_PLL_INT_Pos                    _UINT32_(25)                                         /* (PMC_SR) PLL Interrupt Status Position */
#define PMC_SR_PLL_INT_Msk                    (_UINT32_(0x1) << PMC_SR_PLL_INT_Pos)                /* (PMC_SR) PLL Interrupt Status Mask */
#define PMC_SR_PLL_INT(value)                 (PMC_SR_PLL_INT_Msk & (_UINT32_(value) << PMC_SR_PLL_INT_Pos)) /* Assigment of value for PLL_INT in the PMC_SR register */
#define   PMC_SR_PLL_INT_0_Val                _UINT32_(0x0)                                        /* (PMC_SR) No PLL interrupt has occurred.  */
#define   PMC_SR_PLL_INT_1_Val                _UINT32_(0x1)                                        /* (PMC_SR) A PLL interrupt has occurred. PLL interrupt is defined by the configuration of the PMC_IMR register.  */
#define PMC_SR_PLL_INT_0                      (PMC_SR_PLL_INT_0_Val << PMC_SR_PLL_INT_Pos)         /* (PMC_SR) No PLL interrupt has occurred. Position  */
#define PMC_SR_PLL_INT_1                      (PMC_SR_PLL_INT_1_Val << PMC_SR_PLL_INT_Pos)         /* (PMC_SR) A PLL interrupt has occurred. PLL interrupt is defined by the configuration of the PMC_IMR register. Position  */
#define PMC_SR_Msk                            _UINT32_(0x03BF0309)                                 /* (PMC_SR) Register Mask  */

#define PMC_SR_PCKRDY_Pos                     _UINT32_(8)                                          /* (PMC_SR Position) Programmable Clock Ready Status */
#define PMC_SR_PCKRDY_Msk                     (_UINT32_(0x3) << PMC_SR_PCKRDY_Pos)                 /* (PMC_SR Mask) PCKRDY */
#define PMC_SR_PCKRDY(value)                  (PMC_SR_PCKRDY_Msk & (_UINT32_(value) << PMC_SR_PCKRDY_Pos)) 

/* -------- PMC_IMR : (PMC Offset: 0x6C) ( R/ 32) Interrupt Mask Register -------- */
#define PMC_IMR_RESETVALUE                    _UINT32_(0x00)                                       /*  (PMC_IMR) Interrupt Mask Register  Reset Value */

#define PMC_IMR_MOSCXTS_Pos                   _UINT32_(0)                                          /* (PMC_IMR) Main Crystal Oscillator Status Interrupt Mask Position */
#define PMC_IMR_MOSCXTS_Msk                   (_UINT32_(0x1) << PMC_IMR_MOSCXTS_Pos)               /* (PMC_IMR) Main Crystal Oscillator Status Interrupt Mask Mask */
#define PMC_IMR_MOSCXTS(value)                (PMC_IMR_MOSCXTS_Msk & (_UINT32_(value) << PMC_IMR_MOSCXTS_Pos)) /* Assigment of value for MOSCXTS in the PMC_IMR register */
#define PMC_IMR_MCKRDY_Pos                    _UINT32_(3)                                          /* (PMC_IMR) Main System Bus Clock Ready Interrupt Mask Position */
#define PMC_IMR_MCKRDY_Msk                    (_UINT32_(0x1) << PMC_IMR_MCKRDY_Pos)                /* (PMC_IMR) Main System Bus Clock Ready Interrupt Mask Mask */
#define PMC_IMR_MCKRDY(value)                 (PMC_IMR_MCKRDY_Msk & (_UINT32_(value) << PMC_IMR_MCKRDY_Pos)) /* Assigment of value for MCKRDY in the PMC_IMR register */
#define PMC_IMR_PCKRDY0_Pos                   _UINT32_(8)                                          /* (PMC_IMR) Programmable Clock Ready 0 Interrupt Mask Position */
#define PMC_IMR_PCKRDY0_Msk                   (_UINT32_(0x1) << PMC_IMR_PCKRDY0_Pos)               /* (PMC_IMR) Programmable Clock Ready 0 Interrupt Mask Mask */
#define PMC_IMR_PCKRDY0(value)                (PMC_IMR_PCKRDY0_Msk & (_UINT32_(value) << PMC_IMR_PCKRDY0_Pos)) /* Assigment of value for PCKRDY0 in the PMC_IMR register */
#define PMC_IMR_PCKRDY1_Pos                   _UINT32_(9)                                          /* (PMC_IMR) Programmable Clock Ready 1 Interrupt Mask Position */
#define PMC_IMR_PCKRDY1_Msk                   (_UINT32_(0x1) << PMC_IMR_PCKRDY1_Pos)               /* (PMC_IMR) Programmable Clock Ready 1 Interrupt Mask Mask */
#define PMC_IMR_PCKRDY1(value)                (PMC_IMR_PCKRDY1_Msk & (_UINT32_(value) << PMC_IMR_PCKRDY1_Pos)) /* Assigment of value for PCKRDY1 in the PMC_IMR register */
#define PMC_IMR_MOSCSELS_Pos                  _UINT32_(16)                                         /* (PMC_IMR) Main Clock Source Oscillator Selection Status Interrupt Mask Position */
#define PMC_IMR_MOSCSELS_Msk                  (_UINT32_(0x1) << PMC_IMR_MOSCSELS_Pos)              /* (PMC_IMR) Main Clock Source Oscillator Selection Status Interrupt Mask Mask */
#define PMC_IMR_MOSCSELS(value)               (PMC_IMR_MOSCSELS_Msk & (_UINT32_(value) << PMC_IMR_MOSCSELS_Pos)) /* Assigment of value for MOSCSELS in the PMC_IMR register */
#define PMC_IMR_MOSCRCS_Pos                   _UINT32_(17)                                         /* (PMC_IMR) Main RC Status Interrupt Mask Position */
#define PMC_IMR_MOSCRCS_Msk                   (_UINT32_(0x1) << PMC_IMR_MOSCRCS_Pos)               /* (PMC_IMR) Main RC Status Interrupt Mask Mask */
#define PMC_IMR_MOSCRCS(value)                (PMC_IMR_MOSCRCS_Msk & (_UINT32_(value) << PMC_IMR_MOSCRCS_Pos)) /* Assigment of value for MOSCRCS in the PMC_IMR register */
#define PMC_IMR_CFDEV_Pos                     _UINT32_(18)                                         /* (PMC_IMR) Clock Failure Detector Event Interrupt Mask Position */
#define PMC_IMR_CFDEV_Msk                     (_UINT32_(0x1) << PMC_IMR_CFDEV_Pos)                 /* (PMC_IMR) Clock Failure Detector Event Interrupt Mask Mask */
#define PMC_IMR_CFDEV(value)                  (PMC_IMR_CFDEV_Msk & (_UINT32_(value) << PMC_IMR_CFDEV_Pos)) /* Assigment of value for CFDEV in the PMC_IMR register */
#define PMC_IMR_XT32KERR_Pos                  _UINT32_(21)                                         /* (PMC_IMR) 32.768 kHz Crystal Oscillator Error Interrupt Mask Position */
#define PMC_IMR_XT32KERR_Msk                  (_UINT32_(0x1) << PMC_IMR_XT32KERR_Pos)              /* (PMC_IMR) 32.768 kHz Crystal Oscillator Error Interrupt Mask Mask */
#define PMC_IMR_XT32KERR(value)               (PMC_IMR_XT32KERR_Msk & (_UINT32_(value) << PMC_IMR_XT32KERR_Pos)) /* Assigment of value for XT32KERR in the PMC_IMR register */
#define PMC_IMR_MCKMON_Pos                    _UINT32_(23)                                         /* (PMC_IMR) Main System Bus Clock  Monitor Error Interrupt Mask Position */
#define PMC_IMR_MCKMON_Msk                    (_UINT32_(0x1) << PMC_IMR_MCKMON_Pos)                /* (PMC_IMR) Main System Bus Clock  Monitor Error Interrupt Mask Mask */
#define PMC_IMR_MCKMON(value)                 (PMC_IMR_MCKMON_Msk & (_UINT32_(value) << PMC_IMR_MCKMON_Pos)) /* Assigment of value for MCKMON in the PMC_IMR register */
#define PMC_IMR_PLL_INT_Pos                   _UINT32_(25)                                         /* (PMC_IMR) PLL Interrupt Mask Position */
#define PMC_IMR_PLL_INT_Msk                   (_UINT32_(0x1) << PMC_IMR_PLL_INT_Pos)               /* (PMC_IMR) PLL Interrupt Mask Mask */
#define PMC_IMR_PLL_INT(value)                (PMC_IMR_PLL_INT_Msk & (_UINT32_(value) << PMC_IMR_PLL_INT_Pos)) /* Assigment of value for PLL_INT in the PMC_IMR register */
#define PMC_IMR_Msk                           _UINT32_(0x02A70309)                                 /* (PMC_IMR) Register Mask  */

#define PMC_IMR_PCKRDY_Pos                    _UINT32_(8)                                          /* (PMC_IMR Position) Programmable Clock Ready x Interrupt Mask */
#define PMC_IMR_PCKRDY_Msk                    (_UINT32_(0x3) << PMC_IMR_PCKRDY_Pos)                /* (PMC_IMR Mask) PCKRDY */
#define PMC_IMR_PCKRDY(value)                 (PMC_IMR_PCKRDY_Msk & (_UINT32_(value) << PMC_IMR_PCKRDY_Pos)) 

/* -------- PMC_FSMR : (PMC Offset: 0x70) (R/W 32) Fast Startup Mode Register -------- */
#define PMC_FSMR_RESETVALUE                   _UINT32_(0x00)                                       /*  (PMC_FSMR) Fast Startup Mode Register  Reset Value */

#define PMC_FSMR_RTTAL_Pos                    _UINT32_(16)                                         /* (PMC_FSMR) RTT Alarm Enable Position */
#define PMC_FSMR_RTTAL_Msk                    (_UINT32_(0x1) << PMC_FSMR_RTTAL_Pos)                /* (PMC_FSMR) RTT Alarm Enable Mask */
#define PMC_FSMR_RTTAL(value)                 (PMC_FSMR_RTTAL_Msk & (_UINT32_(value) << PMC_FSMR_RTTAL_Pos)) /* Assigment of value for RTTAL in the PMC_FSMR register */
#define   PMC_FSMR_RTTAL_0_Val                _UINT32_(0x0)                                        /* (PMC_FSMR) The RTT alarm has no effect on the IP_Acronym.  */
#define   PMC_FSMR_RTTAL_1_Val                _UINT32_(0x1)                                        /* (PMC_FSMR) The RTT alarm enables a fast restart signal to the IP_Acronym.  */
#define PMC_FSMR_RTTAL_0                      (PMC_FSMR_RTTAL_0_Val << PMC_FSMR_RTTAL_Pos)         /* (PMC_FSMR) The RTT alarm has no effect on the IP_Acronym. Position  */
#define PMC_FSMR_RTTAL_1                      (PMC_FSMR_RTTAL_1_Val << PMC_FSMR_RTTAL_Pos)         /* (PMC_FSMR) The RTT alarm enables a fast restart signal to the IP_Acronym. Position  */
#define PMC_FSMR_RTCAL_Pos                    _UINT32_(17)                                         /* (PMC_FSMR) RTC Alarm Enable Position */
#define PMC_FSMR_RTCAL_Msk                    (_UINT32_(0x1) << PMC_FSMR_RTCAL_Pos)                /* (PMC_FSMR) RTC Alarm Enable Mask */
#define PMC_FSMR_RTCAL(value)                 (PMC_FSMR_RTCAL_Msk & (_UINT32_(value) << PMC_FSMR_RTCAL_Pos)) /* Assigment of value for RTCAL in the PMC_FSMR register */
#define   PMC_FSMR_RTCAL_0_Val                _UINT32_(0x0)                                        /* (PMC_FSMR) The RTC alarm has no effect on the IP_Acronym.  */
#define   PMC_FSMR_RTCAL_1_Val                _UINT32_(0x1)                                        /* (PMC_FSMR) The RTC alarm enables a fast restart signal to the IP_Acronym.  */
#define PMC_FSMR_RTCAL_0                      (PMC_FSMR_RTCAL_0_Val << PMC_FSMR_RTCAL_Pos)         /* (PMC_FSMR) The RTC alarm has no effect on the IP_Acronym. Position  */
#define PMC_FSMR_RTCAL_1                      (PMC_FSMR_RTCAL_1_Val << PMC_FSMR_RTCAL_Pos)         /* (PMC_FSMR) The RTC alarm enables a fast restart signal to the IP_Acronym. Position  */
#define PMC_FSMR_USBAL_Pos                    _UINT32_(18)                                         /* (PMC_FSMR) USB Alarm Enable Position */
#define PMC_FSMR_USBAL_Msk                    (_UINT32_(0x1) << PMC_FSMR_USBAL_Pos)                /* (PMC_FSMR) USB Alarm Enable Mask */
#define PMC_FSMR_USBAL(value)                 (PMC_FSMR_USBAL_Msk & (_UINT32_(value) << PMC_FSMR_USBAL_Pos)) /* Assigment of value for USBAL in the PMC_FSMR register */
#define   PMC_FSMR_USBAL_0_Val                _UINT32_(0x0)                                        /* (PMC_FSMR) The USB alarm has no effect on the IP_Acronym.  */
#define   PMC_FSMR_USBAL_1_Val                _UINT32_(0x1)                                        /* (PMC_FSMR) The USB alarm enables a fast restart signal to the IP_Acronym.  */
#define PMC_FSMR_USBAL_0                      (PMC_FSMR_USBAL_0_Val << PMC_FSMR_USBAL_Pos)         /* (PMC_FSMR) The USB alarm has no effect on the IP_Acronym. Position  */
#define PMC_FSMR_USBAL_1                      (PMC_FSMR_USBAL_1_Val << PMC_FSMR_USBAL_Pos)         /* (PMC_FSMR) The USB alarm enables a fast restart signal to the IP_Acronym. Position  */
#define PMC_FSMR_WLAN0_Pos                    _UINT32_(24)                                         /* (PMC_FSMR) Wakeup on LAN[x] Position */
#define PMC_FSMR_WLAN0_Msk                    (_UINT32_(0x1) << PMC_FSMR_WLAN0_Pos)                /* (PMC_FSMR) Wakeup on LAN[x] Mask */
#define PMC_FSMR_WLAN0(value)                 (PMC_FSMR_WLAN0_Msk & (_UINT32_(value) << PMC_FSMR_WLAN0_Pos)) /* Assigment of value for WLAN0 in the PMC_FSMR register */
#define   PMC_FSMR_WLAN0_0_Val                _UINT32_(0x0)                                        /* (PMC_FSMR) The Wakeup on LAN[x] alarm has no effect on the PMC.  */
#define   PMC_FSMR_WLAN0_1_Val                _UINT32_(0x1)                                        /* (PMC_FSMR) The Wakeup on LAN[x] alarm enables a fast restart signal to the PMC.  */
#define PMC_FSMR_WLAN0_0                      (PMC_FSMR_WLAN0_0_Val << PMC_FSMR_WLAN0_Pos)         /* (PMC_FSMR) The Wakeup on LAN[x] alarm has no effect on the PMC. Position  */
#define PMC_FSMR_WLAN0_1                      (PMC_FSMR_WLAN0_1_Val << PMC_FSMR_WLAN0_Pos)         /* (PMC_FSMR) The Wakeup on LAN[x] alarm enables a fast restart signal to the PMC. Position  */
#define PMC_FSMR_WLAN1_Pos                    _UINT32_(25)                                         /* (PMC_FSMR) Wakeup on LAN[x] Position */
#define PMC_FSMR_WLAN1_Msk                    (_UINT32_(0x1) << PMC_FSMR_WLAN1_Pos)                /* (PMC_FSMR) Wakeup on LAN[x] Mask */
#define PMC_FSMR_WLAN1(value)                 (PMC_FSMR_WLAN1_Msk & (_UINT32_(value) << PMC_FSMR_WLAN1_Pos)) /* Assigment of value for WLAN1 in the PMC_FSMR register */
#define   PMC_FSMR_WLAN1_0_Val                _UINT32_(0x0)                                        /* (PMC_FSMR) The Wakeup on LAN[x] alarm has no effect on the PMC.  */
#define   PMC_FSMR_WLAN1_1_Val                _UINT32_(0x1)                                        /* (PMC_FSMR) The Wakeup on LAN[x] alarm enables a fast restart signal to the PMC.  */
#define PMC_FSMR_WLAN1_0                      (PMC_FSMR_WLAN1_0_Val << PMC_FSMR_WLAN1_Pos)         /* (PMC_FSMR) The Wakeup on LAN[x] alarm has no effect on the PMC. Position  */
#define PMC_FSMR_WLAN1_1                      (PMC_FSMR_WLAN1_1_Val << PMC_FSMR_WLAN1_Pos)         /* (PMC_FSMR) The Wakeup on LAN[x] alarm enables a fast restart signal to the PMC. Position  */
#define PMC_FSMR_Msk                          _UINT32_(0x03070000)                                 /* (PMC_FSMR) Register Mask  */

#define PMC_FSMR_WLAN_Pos                     _UINT32_(24)                                         /* (PMC_FSMR Position) Wakeup on LAN[x] */
#define PMC_FSMR_WLAN_Msk                     (_UINT32_(0x3) << PMC_FSMR_WLAN_Pos)                 /* (PMC_FSMR Mask) WLAN */
#define PMC_FSMR_WLAN(value)                  (PMC_FSMR_WLAN_Msk & (_UINT32_(value) << PMC_FSMR_WLAN_Pos)) 

/* -------- PMC_WCR : (PMC Offset: 0x74) (R/W 32) Wakeup Control Register -------- */
#define PMC_WCR_RESETVALUE                    _UINT32_(0x00)                                       /*  (PMC_WCR) Wakeup Control Register  Reset Value */

#define PMC_WCR_WKPIONB_Pos                   _UINT32_(0)                                          /* (PMC_WCR) Wakeup Input Number Position */
#define PMC_WCR_WKPIONB_Msk                   (_UINT32_(0xF) << PMC_WCR_WKPIONB_Pos)               /* (PMC_WCR) Wakeup Input Number Mask */
#define PMC_WCR_WKPIONB(value)                (PMC_WCR_WKPIONB_Msk & (_UINT32_(value) << PMC_WCR_WKPIONB_Pos)) /* Assigment of value for WKPIONB in the PMC_WCR register */
#define PMC_WCR_EN_Pos                        _UINT32_(16)                                         /* (PMC_WCR) Wakeup Input Enable Position */
#define PMC_WCR_EN_Msk                        (_UINT32_(0x1) << PMC_WCR_EN_Pos)                    /* (PMC_WCR) Wakeup Input Enable Mask */
#define PMC_WCR_EN(value)                     (PMC_WCR_EN_Msk & (_UINT32_(value) << PMC_WCR_EN_Pos)) /* Assigment of value for EN in the PMC_WCR register */
#define   PMC_WCR_EN_0_Val                    _UINT32_(0x0)                                        /* (PMC_WCR) The selected wakeup input has no effect on the IP_Acronym.  */
#define   PMC_WCR_EN_1_Val                    _UINT32_(0x1)                                        /* (PMC_WCR) The selected wakeup input enables a fast restart signal to the IP_Acronym.  */
#define PMC_WCR_EN_0                          (PMC_WCR_EN_0_Val << PMC_WCR_EN_Pos)                 /* (PMC_WCR) The selected wakeup input has no effect on the IP_Acronym. Position  */
#define PMC_WCR_EN_1                          (PMC_WCR_EN_1_Val << PMC_WCR_EN_Pos)                 /* (PMC_WCR) The selected wakeup input enables a fast restart signal to the IP_Acronym. Position  */
#define PMC_WCR_WIP_Pos                       _UINT32_(17)                                         /* (PMC_WCR) Wakeup Input Polarity Position */
#define PMC_WCR_WIP_Msk                       (_UINT32_(0x1) << PMC_WCR_WIP_Pos)                   /* (PMC_WCR) Wakeup Input Polarity Mask */
#define PMC_WCR_WIP(value)                    (PMC_WCR_WIP_Msk & (_UINT32_(value) << PMC_WCR_WIP_Pos)) /* Assigment of value for WIP in the PMC_WCR register */
#define PMC_WCR_CMD_Pos                       _UINT32_(24)                                         /* (PMC_WCR) Command Position */
#define PMC_WCR_CMD_Msk                       (_UINT32_(0x1) << PMC_WCR_CMD_Pos)                   /* (PMC_WCR) Command Mask */
#define PMC_WCR_CMD(value)                    (PMC_WCR_CMD_Msk & (_UINT32_(value) << PMC_WCR_CMD_Pos)) /* Assigment of value for CMD in the PMC_WCR register */
#define   PMC_WCR_CMD_0_Val                   _UINT32_(0x0)                                        /* (PMC_WCR) Read mode.  */
#define   PMC_WCR_CMD_1_Val                   _UINT32_(0x1)                                        /* (PMC_WCR) Write mode.  */
#define PMC_WCR_CMD_0                         (PMC_WCR_CMD_0_Val << PMC_WCR_CMD_Pos)               /* (PMC_WCR) Read mode. Position  */
#define PMC_WCR_CMD_1                         (PMC_WCR_CMD_1_Val << PMC_WCR_CMD_Pos)               /* (PMC_WCR) Write mode. Position  */
#define PMC_WCR_Msk                           _UINT32_(0x0103000F)                                 /* (PMC_WCR) Register Mask  */


/* -------- PMC_FOCR : (PMC Offset: 0x78) ( /W 32) Fault Output Clear Register -------- */
#define PMC_FOCR_FOCLR_Pos                    _UINT32_(0)                                          /* (PMC_FOCR) Fault Output Clear Position */
#define PMC_FOCR_FOCLR_Msk                    (_UINT32_(0x1) << PMC_FOCR_FOCLR_Pos)                /* (PMC_FOCR) Fault Output Clear Mask */
#define PMC_FOCR_FOCLR(value)                 (PMC_FOCR_FOCLR_Msk & (_UINT32_(value) << PMC_FOCR_FOCLR_Pos)) /* Assigment of value for FOCLR in the PMC_FOCR register */
#define PMC_FOCR_Msk                          _UINT32_(0x00000001)                                 /* (PMC_FOCR) Register Mask  */


/* -------- PMC_WPMR : (PMC Offset: 0x80) (R/W 32) Write Protection Mode Register -------- */
#define PMC_WPMR_RESETVALUE                   _UINT32_(0x00)                                       /*  (PMC_WPMR) Write Protection Mode Register  Reset Value */

#define PMC_WPMR_WPEN_Pos                     _UINT32_(0)                                          /* (PMC_WPMR) Write Protection Enable Position */
#define PMC_WPMR_WPEN_Msk                     (_UINT32_(0x1) << PMC_WPMR_WPEN_Pos)                 /* (PMC_WPMR) Write Protection Enable Mask */
#define PMC_WPMR_WPEN(value)                  (PMC_WPMR_WPEN_Msk & (_UINT32_(value) << PMC_WPMR_WPEN_Pos)) /* Assigment of value for WPEN in the PMC_WPMR register */
#define   PMC_WPMR_WPEN_0_Val                 _UINT32_(0x0)                                        /* (PMC_WPMR) Disables the write protection if WPKEY corresponds to 0x504D43 ("PMC" in ASCII).  */
#define   PMC_WPMR_WPEN_1_Val                 _UINT32_(0x1)                                        /* (PMC_WPMR) Enables the write protection if WPKEY corresponds to 0x504D43 ("PMC" in ASCII).  */
#define PMC_WPMR_WPEN_0                       (PMC_WPMR_WPEN_0_Val << PMC_WPMR_WPEN_Pos)           /* (PMC_WPMR) Disables the write protection if WPKEY corresponds to 0x504D43 ("PMC" in ASCII). Position  */
#define PMC_WPMR_WPEN_1                       (PMC_WPMR_WPEN_1_Val << PMC_WPMR_WPEN_Pos)           /* (PMC_WPMR) Enables the write protection if WPKEY corresponds to 0x504D43 ("PMC" in ASCII). Position  */
#define PMC_WPMR_WPITEN_Pos                   _UINT32_(1)                                          /* (PMC_WPMR) Write Protection Interrupt Enable Position */
#define PMC_WPMR_WPITEN_Msk                   (_UINT32_(0x1) << PMC_WPMR_WPITEN_Pos)               /* (PMC_WPMR) Write Protection Interrupt Enable Mask */
#define PMC_WPMR_WPITEN(value)                (PMC_WPMR_WPITEN_Msk & (_UINT32_(value) << PMC_WPMR_WPITEN_Pos)) /* Assigment of value for WPITEN in the PMC_WPMR register */
#define   PMC_WPMR_WPITEN_0_Val               _UINT32_(0x0)                                        /* (PMC_WPMR) Disables the write protection on interrupt registers if WPKEY corresponds to 0x504D43 ("PMC" in ASCII).  */
#define   PMC_WPMR_WPITEN_1_Val               _UINT32_(0x1)                                        /* (PMC_WPMR) Enables the write protection on interrupt registers if WPKEY corresponds to 0x504D43 ("PMC" in ASCII).  */
#define PMC_WPMR_WPITEN_0                     (PMC_WPMR_WPITEN_0_Val << PMC_WPMR_WPITEN_Pos)       /* (PMC_WPMR) Disables the write protection on interrupt registers if WPKEY corresponds to 0x504D43 ("PMC" in ASCII). Position  */
#define PMC_WPMR_WPITEN_1                     (PMC_WPMR_WPITEN_1_Val << PMC_WPMR_WPITEN_Pos)       /* (PMC_WPMR) Enables the write protection on interrupt registers if WPKEY corresponds to 0x504D43 ("PMC" in ASCII). Position  */
#define PMC_WPMR_WPKEY_Pos                    _UINT32_(8)                                          /* (PMC_WPMR) Write Protection Key Position */
#define PMC_WPMR_WPKEY_Msk                    (_UINT32_(0xFFFFFF) << PMC_WPMR_WPKEY_Pos)           /* (PMC_WPMR) Write Protection Key Mask */
#define PMC_WPMR_WPKEY(value)                 (PMC_WPMR_WPKEY_Msk & (_UINT32_(value) << PMC_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the PMC_WPMR register */
#define   PMC_WPMR_WPKEY_PASSWD_Val           _UINT32_(0x504D43)                                   /* (PMC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0.  */
#define PMC_WPMR_WPKEY_PASSWD                 (PMC_WPMR_WPKEY_PASSWD_Val << PMC_WPMR_WPKEY_Pos)    /* (PMC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0. Position  */
#define PMC_WPMR_Msk                          _UINT32_(0xFFFFFF03)                                 /* (PMC_WPMR) Register Mask  */


/* -------- PMC_WPSR : (PMC Offset: 0x84) ( R/ 32) Write Protection Status Register -------- */
#define PMC_WPSR_RESETVALUE                   _UINT32_(0x00)                                       /*  (PMC_WPSR) Write Protection Status Register  Reset Value */

#define PMC_WPSR_WPVS_Pos                     _UINT32_(0)                                          /* (PMC_WPSR) Write Protection Violation Status Position */
#define PMC_WPSR_WPVS_Msk                     (_UINT32_(0x1) << PMC_WPSR_WPVS_Pos)                 /* (PMC_WPSR) Write Protection Violation Status Mask */
#define PMC_WPSR_WPVS(value)                  (PMC_WPSR_WPVS_Msk & (_UINT32_(value) << PMC_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the PMC_WPSR register */
#define   PMC_WPSR_WPVS_0_Val                 _UINT32_(0x0)                                        /* (PMC_WPSR) No write protection violation has occurred since the last read of the PMC_WPSR.  */
#define   PMC_WPSR_WPVS_1_Val                 _UINT32_(0x1)                                        /* (PMC_WPSR) A write protection violation has occurred since the last read of the PMC_WPSR. If this violation is an unauthorized attempt to write a protected register, the associated violation is reported into field WPVSRC.  */
#define PMC_WPSR_WPVS_0                       (PMC_WPSR_WPVS_0_Val << PMC_WPSR_WPVS_Pos)           /* (PMC_WPSR) No write protection violation has occurred since the last read of the PMC_WPSR. Position  */
#define PMC_WPSR_WPVS_1                       (PMC_WPSR_WPVS_1_Val << PMC_WPSR_WPVS_Pos)           /* (PMC_WPSR) A write protection violation has occurred since the last read of the PMC_WPSR. If this violation is an unauthorized attempt to write a protected register, the associated violation is reported into field WPVSRC. Position  */
#define PMC_WPSR_WPVSRC_Pos                   _UINT32_(8)                                          /* (PMC_WPSR) Write Protection Violation Source Position */
#define PMC_WPSR_WPVSRC_Msk                   (_UINT32_(0xFFFF) << PMC_WPSR_WPVSRC_Pos)            /* (PMC_WPSR) Write Protection Violation Source Mask */
#define PMC_WPSR_WPVSRC(value)                (PMC_WPSR_WPVSRC_Msk & (_UINT32_(value) << PMC_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the PMC_WPSR register */
#define PMC_WPSR_Msk                          _UINT32_(0x00FFFF01)                                 /* (PMC_WPSR) Register Mask  */


/* -------- PMC_PCR : (PMC Offset: 0x88) (R/W 32) Peripheral Control Register -------- */
#define PMC_PCR_RESETVALUE                    _UINT32_(0x00)                                       /*  (PMC_PCR) Peripheral Control Register  Reset Value */

#define PMC_PCR_PID_Pos                       _UINT32_(0)                                          /* (PMC_PCR) Peripheral ID Position */
#define PMC_PCR_PID_Msk                       (_UINT32_(0x7F) << PMC_PCR_PID_Pos)                  /* (PMC_PCR) Peripheral ID Mask */
#define PMC_PCR_PID(value)                    (PMC_PCR_PID_Msk & (_UINT32_(value) << PMC_PCR_PID_Pos)) /* Assigment of value for PID in the PMC_PCR register */
#define PMC_PCR_GCLKCSS_Pos                   _UINT32_(8)                                          /* (PMC_PCR) Generic Clock Source Selection Position */
#define PMC_PCR_GCLKCSS_Msk                   (_UINT32_(0x1F) << PMC_PCR_GCLKCSS_Pos)              /* (PMC_PCR) Generic Clock Source Selection Mask */
#define PMC_PCR_GCLKCSS(value)                (PMC_PCR_GCLKCSS_Msk & (_UINT32_(value) << PMC_PCR_GCLKCSS_Pos)) /* Assigment of value for GCLKCSS in the PMC_PCR register */
#define   PMC_PCR_GCLKCSS_MD_SLOW_CLK_Val     _UINT32_(0x0)                                        /* (PMC_PCR) MD_SLCK is selected  */
#define   PMC_PCR_GCLKCSS_TD_SLOW_CLOCK_Val   _UINT32_(0x1)                                        /* (PMC_PCR) TD_SLCK is selected  */
#define   PMC_PCR_GCLKCSS_MAINCK_Val          _UINT32_(0x2)                                        /* (PMC_PCR) MAINCK is selected  */
#define   PMC_PCR_GCLKCSS_MCK_Val             _UINT32_(0x3)                                        /* (PMC_PCR) MCK is selected  */
#define   PMC_PCR_GCLKCSS_PLLA_Val            _UINT32_(0x4)                                        /* (PMC_PCR) PLLA is selected.  */
#define   PMC_PCR_GCLKCSS_UPLL_Val            _UINT32_(0x5)                                        /* (PMC_PCR) UPLL is selected.  */
#define   PMC_PCR_GCLKCSS_AUDIOPLL_Val        _UINT32_(0x6)                                        /* (PMC_PCR) Audio PLL is selected.  */
#define   PMC_PCR_GCLKCSS_PLLADIV2CLK_Val     _UINT32_(0x8)                                        /* (PMC_PCR) PLLADIV2CLK is selected.  */
#define PMC_PCR_GCLKCSS_MD_SLOW_CLK           (PMC_PCR_GCLKCSS_MD_SLOW_CLK_Val << PMC_PCR_GCLKCSS_Pos) /* (PMC_PCR) MD_SLCK is selected Position  */
#define PMC_PCR_GCLKCSS_TD_SLOW_CLOCK         (PMC_PCR_GCLKCSS_TD_SLOW_CLOCK_Val << PMC_PCR_GCLKCSS_Pos) /* (PMC_PCR) TD_SLCK is selected Position  */
#define PMC_PCR_GCLKCSS_MAINCK                (PMC_PCR_GCLKCSS_MAINCK_Val << PMC_PCR_GCLKCSS_Pos)  /* (PMC_PCR) MAINCK is selected Position  */
#define PMC_PCR_GCLKCSS_MCK                   (PMC_PCR_GCLKCSS_MCK_Val << PMC_PCR_GCLKCSS_Pos)     /* (PMC_PCR) MCK is selected Position  */
#define PMC_PCR_GCLKCSS_PLLA                  (PMC_PCR_GCLKCSS_PLLA_Val << PMC_PCR_GCLKCSS_Pos)    /* (PMC_PCR) PLLA is selected. Position  */
#define PMC_PCR_GCLKCSS_UPLL                  (PMC_PCR_GCLKCSS_UPLL_Val << PMC_PCR_GCLKCSS_Pos)    /* (PMC_PCR) UPLL is selected. Position  */
#define PMC_PCR_GCLKCSS_AUDIOPLL              (PMC_PCR_GCLKCSS_AUDIOPLL_Val << PMC_PCR_GCLKCSS_Pos) /* (PMC_PCR) Audio PLL is selected. Position  */
#define PMC_PCR_GCLKCSS_PLLADIV2CLK           (PMC_PCR_GCLKCSS_PLLADIV2CLK_Val << PMC_PCR_GCLKCSS_Pos) /* (PMC_PCR) PLLADIV2CLK is selected. Position  */
#define PMC_PCR_GCLKDIV_Pos                   _UINT32_(16)                                         /* (PMC_PCR) Generic Clock Division Ratio Position */
#define PMC_PCR_GCLKDIV_Msk                   (_UINT32_(0xFFF) << PMC_PCR_GCLKDIV_Pos)             /* (PMC_PCR) Generic Clock Division Ratio Mask */
#define PMC_PCR_GCLKDIV(value)                (PMC_PCR_GCLKDIV_Msk & (_UINT32_(value) << PMC_PCR_GCLKDIV_Pos)) /* Assigment of value for GCLKDIV in the PMC_PCR register */
#define PMC_PCR_EN_Pos                        _UINT32_(28)                                         /* (PMC_PCR) Enable Position */
#define PMC_PCR_EN_Msk                        (_UINT32_(0x1) << PMC_PCR_EN_Pos)                    /* (PMC_PCR) Enable Mask */
#define PMC_PCR_EN(value)                     (PMC_PCR_EN_Msk & (_UINT32_(value) << PMC_PCR_EN_Pos)) /* Assigment of value for EN in the PMC_PCR register */
#define   PMC_PCR_EN_0_Val                    _UINT32_(0x0)                                        /* (PMC_PCR) Selected Peripheral clock is disabled.  */
#define   PMC_PCR_EN_1_Val                    _UINT32_(0x1)                                        /* (PMC_PCR) Selected Peripheral clock is enabled.  */
#define PMC_PCR_EN_0                          (PMC_PCR_EN_0_Val << PMC_PCR_EN_Pos)                 /* (PMC_PCR) Selected Peripheral clock is disabled. Position  */
#define PMC_PCR_EN_1                          (PMC_PCR_EN_1_Val << PMC_PCR_EN_Pos)                 /* (PMC_PCR) Selected Peripheral clock is enabled. Position  */
#define PMC_PCR_GCLKEN_Pos                    _UINT32_(29)                                         /* (PMC_PCR) Generic Clock Enable Position */
#define PMC_PCR_GCLKEN_Msk                    (_UINT32_(0x1) << PMC_PCR_GCLKEN_Pos)                /* (PMC_PCR) Generic Clock Enable Mask */
#define PMC_PCR_GCLKEN(value)                 (PMC_PCR_GCLKEN_Msk & (_UINT32_(value) << PMC_PCR_GCLKEN_Pos)) /* Assigment of value for GCLKEN in the PMC_PCR register */
#define   PMC_PCR_GCLKEN_0_Val                _UINT32_(0x0)                                        /* (PMC_PCR) The selected generic clock is disabled.  */
#define   PMC_PCR_GCLKEN_1_Val                _UINT32_(0x1)                                        /* (PMC_PCR) The selected generic clock is enabled.  */
#define PMC_PCR_GCLKEN_0                      (PMC_PCR_GCLKEN_0_Val << PMC_PCR_GCLKEN_Pos)         /* (PMC_PCR) The selected generic clock is disabled. Position  */
#define PMC_PCR_GCLKEN_1                      (PMC_PCR_GCLKEN_1_Val << PMC_PCR_GCLKEN_Pos)         /* (PMC_PCR) The selected generic clock is enabled. Position  */
#define PMC_PCR_CMD_Pos                       _UINT32_(31)                                         /* (PMC_PCR) Command Position */
#define PMC_PCR_CMD_Msk                       (_UINT32_(0x1) << PMC_PCR_CMD_Pos)                   /* (PMC_PCR) Command Mask */
#define PMC_PCR_CMD(value)                    (PMC_PCR_CMD_Msk & (_UINT32_(value) << PMC_PCR_CMD_Pos)) /* Assigment of value for CMD in the PMC_PCR register */
#define   PMC_PCR_CMD_0_Val                   _UINT32_(0x0)                                        /* (PMC_PCR) Read mode.  */
#define   PMC_PCR_CMD_1_Val                   _UINT32_(0x1)                                        /* (PMC_PCR) Write mode.  */
#define PMC_PCR_CMD_0                         (PMC_PCR_CMD_0_Val << PMC_PCR_CMD_Pos)               /* (PMC_PCR) Read mode. Position  */
#define PMC_PCR_CMD_1                         (PMC_PCR_CMD_1_Val << PMC_PCR_CMD_Pos)               /* (PMC_PCR) Write mode. Position  */
#define PMC_PCR_Msk                           _UINT32_(0xBFFF1F7F)                                 /* (PMC_PCR) Register Mask  */


/* -------- PMC_MCKLIM : (PMC Offset: 0x9C) (R/W 32) MCK Monitor Limits Register -------- */
#define PMC_MCKLIM_RESETVALUE                 _UINT32_(0x00)                                       /*  (PMC_MCKLIM) MCK Monitor Limits Register  Reset Value */

#define PMC_MCKLIM_MCK_LOW_IT_Pos             _UINT32_(0)                                          /* (PMC_MCKLIM) MCK Monitoring Low IT Limit Position */
#define PMC_MCKLIM_MCK_LOW_IT_Msk             (_UINT32_(0xFF) << PMC_MCKLIM_MCK_LOW_IT_Pos)        /* (PMC_MCKLIM) MCK Monitoring Low IT Limit Mask */
#define PMC_MCKLIM_MCK_LOW_IT(value)          (PMC_MCKLIM_MCK_LOW_IT_Msk & (_UINT32_(value) << PMC_MCKLIM_MCK_LOW_IT_Pos)) /* Assigment of value for MCK_LOW_IT in the PMC_MCKLIM register */
#define PMC_MCKLIM_MCK_HIGH_IT_Pos            _UINT32_(8)                                          /* (PMC_MCKLIM) MCK Monitoring High IT Limit Position */
#define PMC_MCKLIM_MCK_HIGH_IT_Msk            (_UINT32_(0xFF) << PMC_MCKLIM_MCK_HIGH_IT_Pos)       /* (PMC_MCKLIM) MCK Monitoring High IT Limit Mask */
#define PMC_MCKLIM_MCK_HIGH_IT(value)         (PMC_MCKLIM_MCK_HIGH_IT_Msk & (_UINT32_(value) << PMC_MCKLIM_MCK_HIGH_IT_Pos)) /* Assigment of value for MCK_HIGH_IT in the PMC_MCKLIM register */
#define PMC_MCKLIM_Msk                        _UINT32_(0x0000FFFF)                                 /* (PMC_MCKLIM) Register Mask  */


/* -------- PMC_CSR0 : (PMC Offset: 0xA0) ( R/ 32) Peripheral Clock Status Register 0 -------- */
#define PMC_CSR0_RESETVALUE                   _UINT32_(0x00)                                       /*  (PMC_CSR0) Peripheral Clock Status Register 0  Reset Value */

#define PMC_CSR0_PID2_Pos                     _UINT32_(2)                                          /* (PMC_CSR0) Peripheral Clock 2 Status Position */
#define PMC_CSR0_PID2_Msk                     (_UINT32_(0x1) << PMC_CSR0_PID2_Pos)                 /* (PMC_CSR0) Peripheral Clock 2 Status Mask */
#define PMC_CSR0_PID2(value)                  (PMC_CSR0_PID2_Msk & (_UINT32_(value) << PMC_CSR0_PID2_Pos)) /* Assigment of value for PID2 in the PMC_CSR0 register */
#define   PMC_CSR0_PID2_0_Val                 _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID2_1_Val                 _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID2_0                       (PMC_CSR0_PID2_0_Val << PMC_CSR0_PID2_Pos)           /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID2_1                       (PMC_CSR0_PID2_1_Val << PMC_CSR0_PID2_Pos)           /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID3_Pos                     _UINT32_(3)                                          /* (PMC_CSR0) Peripheral Clock 3 Status Position */
#define PMC_CSR0_PID3_Msk                     (_UINT32_(0x1) << PMC_CSR0_PID3_Pos)                 /* (PMC_CSR0) Peripheral Clock 3 Status Mask */
#define PMC_CSR0_PID3(value)                  (PMC_CSR0_PID3_Msk & (_UINT32_(value) << PMC_CSR0_PID3_Pos)) /* Assigment of value for PID3 in the PMC_CSR0 register */
#define   PMC_CSR0_PID3_0_Val                 _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID3_1_Val                 _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID3_0                       (PMC_CSR0_PID3_0_Val << PMC_CSR0_PID3_Pos)           /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID3_1                       (PMC_CSR0_PID3_1_Val << PMC_CSR0_PID3_Pos)           /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID4_Pos                     _UINT32_(4)                                          /* (PMC_CSR0) Peripheral Clock 4 Status Position */
#define PMC_CSR0_PID4_Msk                     (_UINT32_(0x1) << PMC_CSR0_PID4_Pos)                 /* (PMC_CSR0) Peripheral Clock 4 Status Mask */
#define PMC_CSR0_PID4(value)                  (PMC_CSR0_PID4_Msk & (_UINT32_(value) << PMC_CSR0_PID4_Pos)) /* Assigment of value for PID4 in the PMC_CSR0 register */
#define   PMC_CSR0_PID4_0_Val                 _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID4_1_Val                 _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID4_0                       (PMC_CSR0_PID4_0_Val << PMC_CSR0_PID4_Pos)           /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID4_1                       (PMC_CSR0_PID4_1_Val << PMC_CSR0_PID4_Pos)           /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID5_Pos                     _UINT32_(5)                                          /* (PMC_CSR0) Peripheral Clock 5 Status Position */
#define PMC_CSR0_PID5_Msk                     (_UINT32_(0x1) << PMC_CSR0_PID5_Pos)                 /* (PMC_CSR0) Peripheral Clock 5 Status Mask */
#define PMC_CSR0_PID5(value)                  (PMC_CSR0_PID5_Msk & (_UINT32_(value) << PMC_CSR0_PID5_Pos)) /* Assigment of value for PID5 in the PMC_CSR0 register */
#define   PMC_CSR0_PID5_0_Val                 _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID5_1_Val                 _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID5_0                       (PMC_CSR0_PID5_0_Val << PMC_CSR0_PID5_Pos)           /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID5_1                       (PMC_CSR0_PID5_1_Val << PMC_CSR0_PID5_Pos)           /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID6_Pos                     _UINT32_(6)                                          /* (PMC_CSR0) Peripheral Clock 6 Status Position */
#define PMC_CSR0_PID6_Msk                     (_UINT32_(0x1) << PMC_CSR0_PID6_Pos)                 /* (PMC_CSR0) Peripheral Clock 6 Status Mask */
#define PMC_CSR0_PID6(value)                  (PMC_CSR0_PID6_Msk & (_UINT32_(value) << PMC_CSR0_PID6_Pos)) /* Assigment of value for PID6 in the PMC_CSR0 register */
#define   PMC_CSR0_PID6_0_Val                 _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID6_1_Val                 _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID6_0                       (PMC_CSR0_PID6_0_Val << PMC_CSR0_PID6_Pos)           /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID6_1                       (PMC_CSR0_PID6_1_Val << PMC_CSR0_PID6_Pos)           /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID7_Pos                     _UINT32_(7)                                          /* (PMC_CSR0) Peripheral Clock 7 Status Position */
#define PMC_CSR0_PID7_Msk                     (_UINT32_(0x1) << PMC_CSR0_PID7_Pos)                 /* (PMC_CSR0) Peripheral Clock 7 Status Mask */
#define PMC_CSR0_PID7(value)                  (PMC_CSR0_PID7_Msk & (_UINT32_(value) << PMC_CSR0_PID7_Pos)) /* Assigment of value for PID7 in the PMC_CSR0 register */
#define   PMC_CSR0_PID7_0_Val                 _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID7_1_Val                 _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID7_0                       (PMC_CSR0_PID7_0_Val << PMC_CSR0_PID7_Pos)           /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID7_1                       (PMC_CSR0_PID7_1_Val << PMC_CSR0_PID7_Pos)           /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID8_Pos                     _UINT32_(8)                                          /* (PMC_CSR0) Peripheral Clock 8 Status Position */
#define PMC_CSR0_PID8_Msk                     (_UINT32_(0x1) << PMC_CSR0_PID8_Pos)                 /* (PMC_CSR0) Peripheral Clock 8 Status Mask */
#define PMC_CSR0_PID8(value)                  (PMC_CSR0_PID8_Msk & (_UINT32_(value) << PMC_CSR0_PID8_Pos)) /* Assigment of value for PID8 in the PMC_CSR0 register */
#define   PMC_CSR0_PID8_0_Val                 _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID8_1_Val                 _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID8_0                       (PMC_CSR0_PID8_0_Val << PMC_CSR0_PID8_Pos)           /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID8_1                       (PMC_CSR0_PID8_1_Val << PMC_CSR0_PID8_Pos)           /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID9_Pos                     _UINT32_(9)                                          /* (PMC_CSR0) Peripheral Clock 9 Status Position */
#define PMC_CSR0_PID9_Msk                     (_UINT32_(0x1) << PMC_CSR0_PID9_Pos)                 /* (PMC_CSR0) Peripheral Clock 9 Status Mask */
#define PMC_CSR0_PID9(value)                  (PMC_CSR0_PID9_Msk & (_UINT32_(value) << PMC_CSR0_PID9_Pos)) /* Assigment of value for PID9 in the PMC_CSR0 register */
#define   PMC_CSR0_PID9_0_Val                 _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID9_1_Val                 _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID9_0                       (PMC_CSR0_PID9_0_Val << PMC_CSR0_PID9_Pos)           /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID9_1                       (PMC_CSR0_PID9_1_Val << PMC_CSR0_PID9_Pos)           /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID10_Pos                    _UINT32_(10)                                         /* (PMC_CSR0) Peripheral Clock 10 Status Position */
#define PMC_CSR0_PID10_Msk                    (_UINT32_(0x1) << PMC_CSR0_PID10_Pos)                /* (PMC_CSR0) Peripheral Clock 10 Status Mask */
#define PMC_CSR0_PID10(value)                 (PMC_CSR0_PID10_Msk & (_UINT32_(value) << PMC_CSR0_PID10_Pos)) /* Assigment of value for PID10 in the PMC_CSR0 register */
#define   PMC_CSR0_PID10_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID10_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID10_0                      (PMC_CSR0_PID10_0_Val << PMC_CSR0_PID10_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID10_1                      (PMC_CSR0_PID10_1_Val << PMC_CSR0_PID10_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID11_Pos                    _UINT32_(11)                                         /* (PMC_CSR0) Peripheral Clock 11 Status Position */
#define PMC_CSR0_PID11_Msk                    (_UINT32_(0x1) << PMC_CSR0_PID11_Pos)                /* (PMC_CSR0) Peripheral Clock 11 Status Mask */
#define PMC_CSR0_PID11(value)                 (PMC_CSR0_PID11_Msk & (_UINT32_(value) << PMC_CSR0_PID11_Pos)) /* Assigment of value for PID11 in the PMC_CSR0 register */
#define   PMC_CSR0_PID11_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID11_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID11_0                      (PMC_CSR0_PID11_0_Val << PMC_CSR0_PID11_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID11_1                      (PMC_CSR0_PID11_1_Val << PMC_CSR0_PID11_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID12_Pos                    _UINT32_(12)                                         /* (PMC_CSR0) Peripheral Clock 12 Status Position */
#define PMC_CSR0_PID12_Msk                    (_UINT32_(0x1) << PMC_CSR0_PID12_Pos)                /* (PMC_CSR0) Peripheral Clock 12 Status Mask */
#define PMC_CSR0_PID12(value)                 (PMC_CSR0_PID12_Msk & (_UINT32_(value) << PMC_CSR0_PID12_Pos)) /* Assigment of value for PID12 in the PMC_CSR0 register */
#define   PMC_CSR0_PID12_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID12_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID12_0                      (PMC_CSR0_PID12_0_Val << PMC_CSR0_PID12_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID12_1                      (PMC_CSR0_PID12_1_Val << PMC_CSR0_PID12_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID13_Pos                    _UINT32_(13)                                         /* (PMC_CSR0) Peripheral Clock 13 Status Position */
#define PMC_CSR0_PID13_Msk                    (_UINT32_(0x1) << PMC_CSR0_PID13_Pos)                /* (PMC_CSR0) Peripheral Clock 13 Status Mask */
#define PMC_CSR0_PID13(value)                 (PMC_CSR0_PID13_Msk & (_UINT32_(value) << PMC_CSR0_PID13_Pos)) /* Assigment of value for PID13 in the PMC_CSR0 register */
#define   PMC_CSR0_PID13_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID13_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID13_0                      (PMC_CSR0_PID13_0_Val << PMC_CSR0_PID13_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID13_1                      (PMC_CSR0_PID13_1_Val << PMC_CSR0_PID13_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID14_Pos                    _UINT32_(14)                                         /* (PMC_CSR0) Peripheral Clock 14 Status Position */
#define PMC_CSR0_PID14_Msk                    (_UINT32_(0x1) << PMC_CSR0_PID14_Pos)                /* (PMC_CSR0) Peripheral Clock 14 Status Mask */
#define PMC_CSR0_PID14(value)                 (PMC_CSR0_PID14_Msk & (_UINT32_(value) << PMC_CSR0_PID14_Pos)) /* Assigment of value for PID14 in the PMC_CSR0 register */
#define   PMC_CSR0_PID14_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID14_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID14_0                      (PMC_CSR0_PID14_0_Val << PMC_CSR0_PID14_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID14_1                      (PMC_CSR0_PID14_1_Val << PMC_CSR0_PID14_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID15_Pos                    _UINT32_(15)                                         /* (PMC_CSR0) Peripheral Clock 15 Status Position */
#define PMC_CSR0_PID15_Msk                    (_UINT32_(0x1) << PMC_CSR0_PID15_Pos)                /* (PMC_CSR0) Peripheral Clock 15 Status Mask */
#define PMC_CSR0_PID15(value)                 (PMC_CSR0_PID15_Msk & (_UINT32_(value) << PMC_CSR0_PID15_Pos)) /* Assigment of value for PID15 in the PMC_CSR0 register */
#define   PMC_CSR0_PID15_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID15_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID15_0                      (PMC_CSR0_PID15_0_Val << PMC_CSR0_PID15_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID15_1                      (PMC_CSR0_PID15_1_Val << PMC_CSR0_PID15_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID16_Pos                    _UINT32_(16)                                         /* (PMC_CSR0) Peripheral Clock 16 Status Position */
#define PMC_CSR0_PID16_Msk                    (_UINT32_(0x1) << PMC_CSR0_PID16_Pos)                /* (PMC_CSR0) Peripheral Clock 16 Status Mask */
#define PMC_CSR0_PID16(value)                 (PMC_CSR0_PID16_Msk & (_UINT32_(value) << PMC_CSR0_PID16_Pos)) /* Assigment of value for PID16 in the PMC_CSR0 register */
#define   PMC_CSR0_PID16_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID16_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID16_0                      (PMC_CSR0_PID16_0_Val << PMC_CSR0_PID16_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID16_1                      (PMC_CSR0_PID16_1_Val << PMC_CSR0_PID16_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID17_Pos                    _UINT32_(17)                                         /* (PMC_CSR0) Peripheral Clock 17 Status Position */
#define PMC_CSR0_PID17_Msk                    (_UINT32_(0x1) << PMC_CSR0_PID17_Pos)                /* (PMC_CSR0) Peripheral Clock 17 Status Mask */
#define PMC_CSR0_PID17(value)                 (PMC_CSR0_PID17_Msk & (_UINT32_(value) << PMC_CSR0_PID17_Pos)) /* Assigment of value for PID17 in the PMC_CSR0 register */
#define   PMC_CSR0_PID17_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID17_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID17_0                      (PMC_CSR0_PID17_0_Val << PMC_CSR0_PID17_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID17_1                      (PMC_CSR0_PID17_1_Val << PMC_CSR0_PID17_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID18_Pos                    _UINT32_(18)                                         /* (PMC_CSR0) Peripheral Clock 18 Status Position */
#define PMC_CSR0_PID18_Msk                    (_UINT32_(0x1) << PMC_CSR0_PID18_Pos)                /* (PMC_CSR0) Peripheral Clock 18 Status Mask */
#define PMC_CSR0_PID18(value)                 (PMC_CSR0_PID18_Msk & (_UINT32_(value) << PMC_CSR0_PID18_Pos)) /* Assigment of value for PID18 in the PMC_CSR0 register */
#define   PMC_CSR0_PID18_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID18_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID18_0                      (PMC_CSR0_PID18_0_Val << PMC_CSR0_PID18_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID18_1                      (PMC_CSR0_PID18_1_Val << PMC_CSR0_PID18_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID19_Pos                    _UINT32_(19)                                         /* (PMC_CSR0) Peripheral Clock 19 Status Position */
#define PMC_CSR0_PID19_Msk                    (_UINT32_(0x1) << PMC_CSR0_PID19_Pos)                /* (PMC_CSR0) Peripheral Clock 19 Status Mask */
#define PMC_CSR0_PID19(value)                 (PMC_CSR0_PID19_Msk & (_UINT32_(value) << PMC_CSR0_PID19_Pos)) /* Assigment of value for PID19 in the PMC_CSR0 register */
#define   PMC_CSR0_PID19_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID19_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID19_0                      (PMC_CSR0_PID19_0_Val << PMC_CSR0_PID19_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID19_1                      (PMC_CSR0_PID19_1_Val << PMC_CSR0_PID19_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID20_Pos                    _UINT32_(20)                                         /* (PMC_CSR0) Peripheral Clock 20 Status Position */
#define PMC_CSR0_PID20_Msk                    (_UINT32_(0x1) << PMC_CSR0_PID20_Pos)                /* (PMC_CSR0) Peripheral Clock 20 Status Mask */
#define PMC_CSR0_PID20(value)                 (PMC_CSR0_PID20_Msk & (_UINT32_(value) << PMC_CSR0_PID20_Pos)) /* Assigment of value for PID20 in the PMC_CSR0 register */
#define   PMC_CSR0_PID20_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID20_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID20_0                      (PMC_CSR0_PID20_0_Val << PMC_CSR0_PID20_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID20_1                      (PMC_CSR0_PID20_1_Val << PMC_CSR0_PID20_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID22_Pos                    _UINT32_(22)                                         /* (PMC_CSR0) Peripheral Clock 22 Status Position */
#define PMC_CSR0_PID22_Msk                    (_UINT32_(0x1) << PMC_CSR0_PID22_Pos)                /* (PMC_CSR0) Peripheral Clock 22 Status Mask */
#define PMC_CSR0_PID22(value)                 (PMC_CSR0_PID22_Msk & (_UINT32_(value) << PMC_CSR0_PID22_Pos)) /* Assigment of value for PID22 in the PMC_CSR0 register */
#define   PMC_CSR0_PID22_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID22_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID22_0                      (PMC_CSR0_PID22_0_Val << PMC_CSR0_PID22_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID22_1                      (PMC_CSR0_PID22_1_Val << PMC_CSR0_PID22_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID23_Pos                    _UINT32_(23)                                         /* (PMC_CSR0) Peripheral Clock 23 Status Position */
#define PMC_CSR0_PID23_Msk                    (_UINT32_(0x1) << PMC_CSR0_PID23_Pos)                /* (PMC_CSR0) Peripheral Clock 23 Status Mask */
#define PMC_CSR0_PID23(value)                 (PMC_CSR0_PID23_Msk & (_UINT32_(value) << PMC_CSR0_PID23_Pos)) /* Assigment of value for PID23 in the PMC_CSR0 register */
#define   PMC_CSR0_PID23_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID23_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID23_0                      (PMC_CSR0_PID23_0_Val << PMC_CSR0_PID23_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID23_1                      (PMC_CSR0_PID23_1_Val << PMC_CSR0_PID23_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID24_Pos                    _UINT32_(24)                                         /* (PMC_CSR0) Peripheral Clock 24 Status Position */
#define PMC_CSR0_PID24_Msk                    (_UINT32_(0x1) << PMC_CSR0_PID24_Pos)                /* (PMC_CSR0) Peripheral Clock 24 Status Mask */
#define PMC_CSR0_PID24(value)                 (PMC_CSR0_PID24_Msk & (_UINT32_(value) << PMC_CSR0_PID24_Pos)) /* Assigment of value for PID24 in the PMC_CSR0 register */
#define   PMC_CSR0_PID24_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID24_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID24_0                      (PMC_CSR0_PID24_0_Val << PMC_CSR0_PID24_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID24_1                      (PMC_CSR0_PID24_1_Val << PMC_CSR0_PID24_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID25_Pos                    _UINT32_(25)                                         /* (PMC_CSR0) Peripheral Clock 25 Status Position */
#define PMC_CSR0_PID25_Msk                    (_UINT32_(0x1) << PMC_CSR0_PID25_Pos)                /* (PMC_CSR0) Peripheral Clock 25 Status Mask */
#define PMC_CSR0_PID25(value)                 (PMC_CSR0_PID25_Msk & (_UINT32_(value) << PMC_CSR0_PID25_Pos)) /* Assigment of value for PID25 in the PMC_CSR0 register */
#define   PMC_CSR0_PID25_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID25_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID25_0                      (PMC_CSR0_PID25_0_Val << PMC_CSR0_PID25_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID25_1                      (PMC_CSR0_PID25_1_Val << PMC_CSR0_PID25_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID26_Pos                    _UINT32_(26)                                         /* (PMC_CSR0) Peripheral Clock 26 Status Position */
#define PMC_CSR0_PID26_Msk                    (_UINT32_(0x1) << PMC_CSR0_PID26_Pos)                /* (PMC_CSR0) Peripheral Clock 26 Status Mask */
#define PMC_CSR0_PID26(value)                 (PMC_CSR0_PID26_Msk & (_UINT32_(value) << PMC_CSR0_PID26_Pos)) /* Assigment of value for PID26 in the PMC_CSR0 register */
#define   PMC_CSR0_PID26_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID26_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID26_0                      (PMC_CSR0_PID26_0_Val << PMC_CSR0_PID26_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID26_1                      (PMC_CSR0_PID26_1_Val << PMC_CSR0_PID26_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID28_Pos                    _UINT32_(28)                                         /* (PMC_CSR0) Peripheral Clock 28 Status Position */
#define PMC_CSR0_PID28_Msk                    (_UINT32_(0x1) << PMC_CSR0_PID28_Pos)                /* (PMC_CSR0) Peripheral Clock 28 Status Mask */
#define PMC_CSR0_PID28(value)                 (PMC_CSR0_PID28_Msk & (_UINT32_(value) << PMC_CSR0_PID28_Pos)) /* Assigment of value for PID28 in the PMC_CSR0 register */
#define   PMC_CSR0_PID28_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID28_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID28_0                      (PMC_CSR0_PID28_0_Val << PMC_CSR0_PID28_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID28_1                      (PMC_CSR0_PID28_1_Val << PMC_CSR0_PID28_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID29_Pos                    _UINT32_(29)                                         /* (PMC_CSR0) Peripheral Clock 29 Status Position */
#define PMC_CSR0_PID29_Msk                    (_UINT32_(0x1) << PMC_CSR0_PID29_Pos)                /* (PMC_CSR0) Peripheral Clock 29 Status Mask */
#define PMC_CSR0_PID29(value)                 (PMC_CSR0_PID29_Msk & (_UINT32_(value) << PMC_CSR0_PID29_Pos)) /* Assigment of value for PID29 in the PMC_CSR0 register */
#define   PMC_CSR0_PID29_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID29_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID29_0                      (PMC_CSR0_PID29_0_Val << PMC_CSR0_PID29_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID29_1                      (PMC_CSR0_PID29_1_Val << PMC_CSR0_PID29_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_PID30_Pos                    _UINT32_(30)                                         /* (PMC_CSR0) Peripheral Clock 30 Status Position */
#define PMC_CSR0_PID30_Msk                    (_UINT32_(0x1) << PMC_CSR0_PID30_Pos)                /* (PMC_CSR0) Peripheral Clock 30 Status Mask */
#define PMC_CSR0_PID30(value)                 (PMC_CSR0_PID30_Msk & (_UINT32_(value) << PMC_CSR0_PID30_Pos)) /* Assigment of value for PID30 in the PMC_CSR0 register */
#define   PMC_CSR0_PID30_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR0) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR0_PID30_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR0) The corresponding peripheral clock is enabled.  */
#define PMC_CSR0_PID30_0                      (PMC_CSR0_PID30_0_Val << PMC_CSR0_PID30_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR0_PID30_1                      (PMC_CSR0_PID30_1_Val << PMC_CSR0_PID30_Pos)         /* (PMC_CSR0) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR0_Msk                          _UINT32_(0x77DFFFFC)                                 /* (PMC_CSR0) Register Mask  */

#define PMC_CSR0_PID_Pos                      _UINT32_(2)                                          /* (PMC_CSR0 Position) Peripheral Clock 3x Status */
#define PMC_CSR0_PID_Msk                      (_UINT32_(0x7FFFFFF) << PMC_CSR0_PID_Pos)            /* (PMC_CSR0 Mask) PID */
#define PMC_CSR0_PID(value)                   (PMC_CSR0_PID_Msk & (_UINT32_(value) << PMC_CSR0_PID_Pos)) 

/* -------- PMC_CSR1 : (PMC Offset: 0xA4) ( R/ 32) Peripheral Clock Status Register 1 -------- */
#define PMC_CSR1_RESETVALUE                   _UINT32_(0x00)                                       /*  (PMC_CSR1) Peripheral Clock Status Register 1  Reset Value */

#define PMC_CSR1_PID32_Pos                    _UINT32_(0)                                          /* (PMC_CSR1) Peripheral Clock 32 Status Position */
#define PMC_CSR1_PID32_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID32_Pos)                /* (PMC_CSR1) Peripheral Clock 32 Status Mask */
#define PMC_CSR1_PID32(value)                 (PMC_CSR1_PID32_Msk & (_UINT32_(value) << PMC_CSR1_PID32_Pos)) /* Assigment of value for PID32 in the PMC_CSR1 register */
#define   PMC_CSR1_PID32_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID32_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID32_0                      (PMC_CSR1_PID32_0_Val << PMC_CSR1_PID32_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID32_1                      (PMC_CSR1_PID32_1_Val << PMC_CSR1_PID32_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID33_Pos                    _UINT32_(1)                                          /* (PMC_CSR1) Peripheral Clock 33 Status Position */
#define PMC_CSR1_PID33_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID33_Pos)                /* (PMC_CSR1) Peripheral Clock 33 Status Mask */
#define PMC_CSR1_PID33(value)                 (PMC_CSR1_PID33_Msk & (_UINT32_(value) << PMC_CSR1_PID33_Pos)) /* Assigment of value for PID33 in the PMC_CSR1 register */
#define   PMC_CSR1_PID33_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID33_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID33_0                      (PMC_CSR1_PID33_0_Val << PMC_CSR1_PID33_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID33_1                      (PMC_CSR1_PID33_1_Val << PMC_CSR1_PID33_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID34_Pos                    _UINT32_(2)                                          /* (PMC_CSR1) Peripheral Clock 34 Status Position */
#define PMC_CSR1_PID34_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID34_Pos)                /* (PMC_CSR1) Peripheral Clock 34 Status Mask */
#define PMC_CSR1_PID34(value)                 (PMC_CSR1_PID34_Msk & (_UINT32_(value) << PMC_CSR1_PID34_Pos)) /* Assigment of value for PID34 in the PMC_CSR1 register */
#define   PMC_CSR1_PID34_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID34_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID34_0                      (PMC_CSR1_PID34_0_Val << PMC_CSR1_PID34_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID34_1                      (PMC_CSR1_PID34_1_Val << PMC_CSR1_PID34_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID35_Pos                    _UINT32_(3)                                          /* (PMC_CSR1) Peripheral Clock 35 Status Position */
#define PMC_CSR1_PID35_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID35_Pos)                /* (PMC_CSR1) Peripheral Clock 35 Status Mask */
#define PMC_CSR1_PID35(value)                 (PMC_CSR1_PID35_Msk & (_UINT32_(value) << PMC_CSR1_PID35_Pos)) /* Assigment of value for PID35 in the PMC_CSR1 register */
#define   PMC_CSR1_PID35_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID35_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID35_0                      (PMC_CSR1_PID35_0_Val << PMC_CSR1_PID35_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID35_1                      (PMC_CSR1_PID35_1_Val << PMC_CSR1_PID35_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID36_Pos                    _UINT32_(4)                                          /* (PMC_CSR1) Peripheral Clock 36 Status Position */
#define PMC_CSR1_PID36_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID36_Pos)                /* (PMC_CSR1) Peripheral Clock 36 Status Mask */
#define PMC_CSR1_PID36(value)                 (PMC_CSR1_PID36_Msk & (_UINT32_(value) << PMC_CSR1_PID36_Pos)) /* Assigment of value for PID36 in the PMC_CSR1 register */
#define   PMC_CSR1_PID36_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID36_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID36_0                      (PMC_CSR1_PID36_0_Val << PMC_CSR1_PID36_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID36_1                      (PMC_CSR1_PID36_1_Val << PMC_CSR1_PID36_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID37_Pos                    _UINT32_(5)                                          /* (PMC_CSR1) Peripheral Clock 37 Status Position */
#define PMC_CSR1_PID37_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID37_Pos)                /* (PMC_CSR1) Peripheral Clock 37 Status Mask */
#define PMC_CSR1_PID37(value)                 (PMC_CSR1_PID37_Msk & (_UINT32_(value) << PMC_CSR1_PID37_Pos)) /* Assigment of value for PID37 in the PMC_CSR1 register */
#define   PMC_CSR1_PID37_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID37_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID37_0                      (PMC_CSR1_PID37_0_Val << PMC_CSR1_PID37_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID37_1                      (PMC_CSR1_PID37_1_Val << PMC_CSR1_PID37_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID38_Pos                    _UINT32_(6)                                          /* (PMC_CSR1) Peripheral Clock 38 Status Position */
#define PMC_CSR1_PID38_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID38_Pos)                /* (PMC_CSR1) Peripheral Clock 38 Status Mask */
#define PMC_CSR1_PID38(value)                 (PMC_CSR1_PID38_Msk & (_UINT32_(value) << PMC_CSR1_PID38_Pos)) /* Assigment of value for PID38 in the PMC_CSR1 register */
#define   PMC_CSR1_PID38_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID38_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID38_0                      (PMC_CSR1_PID38_0_Val << PMC_CSR1_PID38_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID38_1                      (PMC_CSR1_PID38_1_Val << PMC_CSR1_PID38_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID39_Pos                    _UINT32_(7)                                          /* (PMC_CSR1) Peripheral Clock 39 Status Position */
#define PMC_CSR1_PID39_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID39_Pos)                /* (PMC_CSR1) Peripheral Clock 39 Status Mask */
#define PMC_CSR1_PID39(value)                 (PMC_CSR1_PID39_Msk & (_UINT32_(value) << PMC_CSR1_PID39_Pos)) /* Assigment of value for PID39 in the PMC_CSR1 register */
#define   PMC_CSR1_PID39_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID39_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID39_0                      (PMC_CSR1_PID39_0_Val << PMC_CSR1_PID39_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID39_1                      (PMC_CSR1_PID39_1_Val << PMC_CSR1_PID39_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID40_Pos                    _UINT32_(8)                                          /* (PMC_CSR1) Peripheral Clock 40 Status Position */
#define PMC_CSR1_PID40_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID40_Pos)                /* (PMC_CSR1) Peripheral Clock 40 Status Mask */
#define PMC_CSR1_PID40(value)                 (PMC_CSR1_PID40_Msk & (_UINT32_(value) << PMC_CSR1_PID40_Pos)) /* Assigment of value for PID40 in the PMC_CSR1 register */
#define   PMC_CSR1_PID40_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID40_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID40_0                      (PMC_CSR1_PID40_0_Val << PMC_CSR1_PID40_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID40_1                      (PMC_CSR1_PID40_1_Val << PMC_CSR1_PID40_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID41_Pos                    _UINT32_(9)                                          /* (PMC_CSR1) Peripheral Clock 41 Status Position */
#define PMC_CSR1_PID41_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID41_Pos)                /* (PMC_CSR1) Peripheral Clock 41 Status Mask */
#define PMC_CSR1_PID41(value)                 (PMC_CSR1_PID41_Msk & (_UINT32_(value) << PMC_CSR1_PID41_Pos)) /* Assigment of value for PID41 in the PMC_CSR1 register */
#define   PMC_CSR1_PID41_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID41_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID41_0                      (PMC_CSR1_PID41_0_Val << PMC_CSR1_PID41_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID41_1                      (PMC_CSR1_PID41_1_Val << PMC_CSR1_PID41_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID42_Pos                    _UINT32_(10)                                         /* (PMC_CSR1) Peripheral Clock 42 Status Position */
#define PMC_CSR1_PID42_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID42_Pos)                /* (PMC_CSR1) Peripheral Clock 42 Status Mask */
#define PMC_CSR1_PID42(value)                 (PMC_CSR1_PID42_Msk & (_UINT32_(value) << PMC_CSR1_PID42_Pos)) /* Assigment of value for PID42 in the PMC_CSR1 register */
#define   PMC_CSR1_PID42_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID42_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID42_0                      (PMC_CSR1_PID42_0_Val << PMC_CSR1_PID42_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID42_1                      (PMC_CSR1_PID42_1_Val << PMC_CSR1_PID42_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID43_Pos                    _UINT32_(11)                                         /* (PMC_CSR1) Peripheral Clock 43 Status Position */
#define PMC_CSR1_PID43_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID43_Pos)                /* (PMC_CSR1) Peripheral Clock 43 Status Mask */
#define PMC_CSR1_PID43(value)                 (PMC_CSR1_PID43_Msk & (_UINT32_(value) << PMC_CSR1_PID43_Pos)) /* Assigment of value for PID43 in the PMC_CSR1 register */
#define   PMC_CSR1_PID43_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID43_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID43_0                      (PMC_CSR1_PID43_0_Val << PMC_CSR1_PID43_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID43_1                      (PMC_CSR1_PID43_1_Val << PMC_CSR1_PID43_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID44_Pos                    _UINT32_(12)                                         /* (PMC_CSR1) Peripheral Clock 44 Status Position */
#define PMC_CSR1_PID44_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID44_Pos)                /* (PMC_CSR1) Peripheral Clock 44 Status Mask */
#define PMC_CSR1_PID44(value)                 (PMC_CSR1_PID44_Msk & (_UINT32_(value) << PMC_CSR1_PID44_Pos)) /* Assigment of value for PID44 in the PMC_CSR1 register */
#define   PMC_CSR1_PID44_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID44_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID44_0                      (PMC_CSR1_PID44_0_Val << PMC_CSR1_PID44_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID44_1                      (PMC_CSR1_PID44_1_Val << PMC_CSR1_PID44_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID45_Pos                    _UINT32_(13)                                         /* (PMC_CSR1) Peripheral Clock 45 Status Position */
#define PMC_CSR1_PID45_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID45_Pos)                /* (PMC_CSR1) Peripheral Clock 45 Status Mask */
#define PMC_CSR1_PID45(value)                 (PMC_CSR1_PID45_Msk & (_UINT32_(value) << PMC_CSR1_PID45_Pos)) /* Assigment of value for PID45 in the PMC_CSR1 register */
#define   PMC_CSR1_PID45_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID45_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID45_0                      (PMC_CSR1_PID45_0_Val << PMC_CSR1_PID45_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID45_1                      (PMC_CSR1_PID45_1_Val << PMC_CSR1_PID45_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID47_Pos                    _UINT32_(15)                                         /* (PMC_CSR1) Peripheral Clock 47 Status Position */
#define PMC_CSR1_PID47_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID47_Pos)                /* (PMC_CSR1) Peripheral Clock 47 Status Mask */
#define PMC_CSR1_PID47(value)                 (PMC_CSR1_PID47_Msk & (_UINT32_(value) << PMC_CSR1_PID47_Pos)) /* Assigment of value for PID47 in the PMC_CSR1 register */
#define   PMC_CSR1_PID47_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID47_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID47_0                      (PMC_CSR1_PID47_0_Val << PMC_CSR1_PID47_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID47_1                      (PMC_CSR1_PID47_1_Val << PMC_CSR1_PID47_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID48_Pos                    _UINT32_(16)                                         /* (PMC_CSR1) Peripheral Clock 48 Status Position */
#define PMC_CSR1_PID48_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID48_Pos)                /* (PMC_CSR1) Peripheral Clock 48 Status Mask */
#define PMC_CSR1_PID48(value)                 (PMC_CSR1_PID48_Msk & (_UINT32_(value) << PMC_CSR1_PID48_Pos)) /* Assigment of value for PID48 in the PMC_CSR1 register */
#define   PMC_CSR1_PID48_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID48_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID48_0                      (PMC_CSR1_PID48_0_Val << PMC_CSR1_PID48_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID48_1                      (PMC_CSR1_PID48_1_Val << PMC_CSR1_PID48_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID49_Pos                    _UINT32_(17)                                         /* (PMC_CSR1) Peripheral Clock 49 Status Position */
#define PMC_CSR1_PID49_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID49_Pos)                /* (PMC_CSR1) Peripheral Clock 49 Status Mask */
#define PMC_CSR1_PID49(value)                 (PMC_CSR1_PID49_Msk & (_UINT32_(value) << PMC_CSR1_PID49_Pos)) /* Assigment of value for PID49 in the PMC_CSR1 register */
#define   PMC_CSR1_PID49_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID49_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID49_0                      (PMC_CSR1_PID49_0_Val << PMC_CSR1_PID49_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID49_1                      (PMC_CSR1_PID49_1_Val << PMC_CSR1_PID49_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID51_Pos                    _UINT32_(19)                                         /* (PMC_CSR1) Peripheral Clock 51 Status Position */
#define PMC_CSR1_PID51_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID51_Pos)                /* (PMC_CSR1) Peripheral Clock 51 Status Mask */
#define PMC_CSR1_PID51(value)                 (PMC_CSR1_PID51_Msk & (_UINT32_(value) << PMC_CSR1_PID51_Pos)) /* Assigment of value for PID51 in the PMC_CSR1 register */
#define   PMC_CSR1_PID51_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID51_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID51_0                      (PMC_CSR1_PID51_0_Val << PMC_CSR1_PID51_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID51_1                      (PMC_CSR1_PID51_1_Val << PMC_CSR1_PID51_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID52_Pos                    _UINT32_(20)                                         /* (PMC_CSR1) Peripheral Clock 52 Status Position */
#define PMC_CSR1_PID52_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID52_Pos)                /* (PMC_CSR1) Peripheral Clock 52 Status Mask */
#define PMC_CSR1_PID52(value)                 (PMC_CSR1_PID52_Msk & (_UINT32_(value) << PMC_CSR1_PID52_Pos)) /* Assigment of value for PID52 in the PMC_CSR1 register */
#define   PMC_CSR1_PID52_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID52_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID52_0                      (PMC_CSR1_PID52_0_Val << PMC_CSR1_PID52_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID52_1                      (PMC_CSR1_PID52_1_Val << PMC_CSR1_PID52_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID53_Pos                    _UINT32_(21)                                         /* (PMC_CSR1) Peripheral Clock 53 Status Position */
#define PMC_CSR1_PID53_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID53_Pos)                /* (PMC_CSR1) Peripheral Clock 53 Status Mask */
#define PMC_CSR1_PID53(value)                 (PMC_CSR1_PID53_Msk & (_UINT32_(value) << PMC_CSR1_PID53_Pos)) /* Assigment of value for PID53 in the PMC_CSR1 register */
#define   PMC_CSR1_PID53_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID53_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID53_0                      (PMC_CSR1_PID53_0_Val << PMC_CSR1_PID53_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID53_1                      (PMC_CSR1_PID53_1_Val << PMC_CSR1_PID53_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID54_Pos                    _UINT32_(22)                                         /* (PMC_CSR1) Peripheral Clock 54 Status Position */
#define PMC_CSR1_PID54_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID54_Pos)                /* (PMC_CSR1) Peripheral Clock 54 Status Mask */
#define PMC_CSR1_PID54(value)                 (PMC_CSR1_PID54_Msk & (_UINT32_(value) << PMC_CSR1_PID54_Pos)) /* Assigment of value for PID54 in the PMC_CSR1 register */
#define   PMC_CSR1_PID54_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID54_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID54_0                      (PMC_CSR1_PID54_0_Val << PMC_CSR1_PID54_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID54_1                      (PMC_CSR1_PID54_1_Val << PMC_CSR1_PID54_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID56_Pos                    _UINT32_(24)                                         /* (PMC_CSR1) Peripheral Clock 56 Status Position */
#define PMC_CSR1_PID56_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID56_Pos)                /* (PMC_CSR1) Peripheral Clock 56 Status Mask */
#define PMC_CSR1_PID56(value)                 (PMC_CSR1_PID56_Msk & (_UINT32_(value) << PMC_CSR1_PID56_Pos)) /* Assigment of value for PID56 in the PMC_CSR1 register */
#define   PMC_CSR1_PID56_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID56_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID56_0                      (PMC_CSR1_PID56_0_Val << PMC_CSR1_PID56_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID56_1                      (PMC_CSR1_PID56_1_Val << PMC_CSR1_PID56_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID58_Pos                    _UINT32_(26)                                         /* (PMC_CSR1) Peripheral Clock 58 Status Position */
#define PMC_CSR1_PID58_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID58_Pos)                /* (PMC_CSR1) Peripheral Clock 58 Status Mask */
#define PMC_CSR1_PID58(value)                 (PMC_CSR1_PID58_Msk & (_UINT32_(value) << PMC_CSR1_PID58_Pos)) /* Assigment of value for PID58 in the PMC_CSR1 register */
#define   PMC_CSR1_PID58_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID58_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID58_0                      (PMC_CSR1_PID58_0_Val << PMC_CSR1_PID58_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID58_1                      (PMC_CSR1_PID58_1_Val << PMC_CSR1_PID58_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_PID59_Pos                    _UINT32_(27)                                         /* (PMC_CSR1) Peripheral Clock 59 Status Position */
#define PMC_CSR1_PID59_Msk                    (_UINT32_(0x1) << PMC_CSR1_PID59_Pos)                /* (PMC_CSR1) Peripheral Clock 59 Status Mask */
#define PMC_CSR1_PID59(value)                 (PMC_CSR1_PID59_Msk & (_UINT32_(value) << PMC_CSR1_PID59_Pos)) /* Assigment of value for PID59 in the PMC_CSR1 register */
#define   PMC_CSR1_PID59_0_Val                _UINT32_(0x0)                                        /* (PMC_CSR1) The corresponding peripheral clock is disabled.  */
#define   PMC_CSR1_PID59_1_Val                _UINT32_(0x1)                                        /* (PMC_CSR1) The corresponding peripheral clock is enabled.  */
#define PMC_CSR1_PID59_0                      (PMC_CSR1_PID59_0_Val << PMC_CSR1_PID59_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is disabled. Position  */
#define PMC_CSR1_PID59_1                      (PMC_CSR1_PID59_1_Val << PMC_CSR1_PID59_Pos)         /* (PMC_CSR1) The corresponding peripheral clock is enabled. Position  */
#define PMC_CSR1_Msk                          _UINT32_(0x0D7BBFFF)                                 /* (PMC_CSR1) Register Mask  */

#define PMC_CSR1_PID_Pos                      _UINT32_(0)                                          /* (PMC_CSR1 Position) Peripheral Clock 59 Status */
#define PMC_CSR1_PID_Msk                      (_UINT32_(0xFFFFFF) << PMC_CSR1_PID_Pos)             /* (PMC_CSR1 Mask) PID */
#define PMC_CSR1_PID(value)                   (PMC_CSR1_PID_Msk & (_UINT32_(value) << PMC_CSR1_PID_Pos)) 

/* -------- PMC_GCSR0 : (PMC Offset: 0xC0) ( R/ 32) Generic Clock Status Register 0 -------- */
#define PMC_GCSR0_RESETVALUE                  _UINT32_(0x00)                                       /*  (PMC_GCSR0) Generic Clock Status Register 0  Reset Value */

#define PMC_GCSR0_GPID5_Pos                   _UINT32_(5)                                          /* (PMC_GCSR0) Generic Clock 5 Status Position */
#define PMC_GCSR0_GPID5_Msk                   (_UINT32_(0x1) << PMC_GCSR0_GPID5_Pos)               /* (PMC_GCSR0) Generic Clock 5 Status Mask */
#define PMC_GCSR0_GPID5(value)                (PMC_GCSR0_GPID5_Msk & (_UINT32_(value) << PMC_GCSR0_GPID5_Pos)) /* Assigment of value for GPID5 in the PMC_GCSR0 register */
#define   PMC_GCSR0_GPID5_0_Val               _UINT32_(0x0)                                        /* (PMC_GCSR0) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR0_GPID5_1_Val               _UINT32_(0x1)                                        /* (PMC_GCSR0) The corresponding Generic clock is enabled.  */
#define PMC_GCSR0_GPID5_0                     (PMC_GCSR0_GPID5_0_Val << PMC_GCSR0_GPID5_Pos)       /* (PMC_GCSR0) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR0_GPID5_1                     (PMC_GCSR0_GPID5_1_Val << PMC_GCSR0_GPID5_Pos)       /* (PMC_GCSR0) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR0_GPID6_Pos                   _UINT32_(6)                                          /* (PMC_GCSR0) Generic Clock 6 Status Position */
#define PMC_GCSR0_GPID6_Msk                   (_UINT32_(0x1) << PMC_GCSR0_GPID6_Pos)               /* (PMC_GCSR0) Generic Clock 6 Status Mask */
#define PMC_GCSR0_GPID6(value)                (PMC_GCSR0_GPID6_Msk & (_UINT32_(value) << PMC_GCSR0_GPID6_Pos)) /* Assigment of value for GPID6 in the PMC_GCSR0 register */
#define   PMC_GCSR0_GPID6_0_Val               _UINT32_(0x0)                                        /* (PMC_GCSR0) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR0_GPID6_1_Val               _UINT32_(0x1)                                        /* (PMC_GCSR0) The corresponding Generic clock is enabled.  */
#define PMC_GCSR0_GPID6_0                     (PMC_GCSR0_GPID6_0_Val << PMC_GCSR0_GPID6_Pos)       /* (PMC_GCSR0) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR0_GPID6_1                     (PMC_GCSR0_GPID6_1_Val << PMC_GCSR0_GPID6_Pos)       /* (PMC_GCSR0) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR0_GPID7_Pos                   _UINT32_(7)                                          /* (PMC_GCSR0) Generic Clock 7 Status Position */
#define PMC_GCSR0_GPID7_Msk                   (_UINT32_(0x1) << PMC_GCSR0_GPID7_Pos)               /* (PMC_GCSR0) Generic Clock 7 Status Mask */
#define PMC_GCSR0_GPID7(value)                (PMC_GCSR0_GPID7_Msk & (_UINT32_(value) << PMC_GCSR0_GPID7_Pos)) /* Assigment of value for GPID7 in the PMC_GCSR0 register */
#define   PMC_GCSR0_GPID7_0_Val               _UINT32_(0x0)                                        /* (PMC_GCSR0) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR0_GPID7_1_Val               _UINT32_(0x1)                                        /* (PMC_GCSR0) The corresponding Generic clock is enabled.  */
#define PMC_GCSR0_GPID7_0                     (PMC_GCSR0_GPID7_0_Val << PMC_GCSR0_GPID7_Pos)       /* (PMC_GCSR0) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR0_GPID7_1                     (PMC_GCSR0_GPID7_1_Val << PMC_GCSR0_GPID7_Pos)       /* (PMC_GCSR0) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR0_GPID8_Pos                   _UINT32_(8)                                          /* (PMC_GCSR0) Generic Clock 8 Status Position */
#define PMC_GCSR0_GPID8_Msk                   (_UINT32_(0x1) << PMC_GCSR0_GPID8_Pos)               /* (PMC_GCSR0) Generic Clock 8 Status Mask */
#define PMC_GCSR0_GPID8(value)                (PMC_GCSR0_GPID8_Msk & (_UINT32_(value) << PMC_GCSR0_GPID8_Pos)) /* Assigment of value for GPID8 in the PMC_GCSR0 register */
#define   PMC_GCSR0_GPID8_0_Val               _UINT32_(0x0)                                        /* (PMC_GCSR0) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR0_GPID8_1_Val               _UINT32_(0x1)                                        /* (PMC_GCSR0) The corresponding Generic clock is enabled.  */
#define PMC_GCSR0_GPID8_0                     (PMC_GCSR0_GPID8_0_Val << PMC_GCSR0_GPID8_Pos)       /* (PMC_GCSR0) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR0_GPID8_1                     (PMC_GCSR0_GPID8_1_Val << PMC_GCSR0_GPID8_Pos)       /* (PMC_GCSR0) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR0_GPID9_Pos                   _UINT32_(9)                                          /* (PMC_GCSR0) Generic Clock 9 Status Position */
#define PMC_GCSR0_GPID9_Msk                   (_UINT32_(0x1) << PMC_GCSR0_GPID9_Pos)               /* (PMC_GCSR0) Generic Clock 9 Status Mask */
#define PMC_GCSR0_GPID9(value)                (PMC_GCSR0_GPID9_Msk & (_UINT32_(value) << PMC_GCSR0_GPID9_Pos)) /* Assigment of value for GPID9 in the PMC_GCSR0 register */
#define   PMC_GCSR0_GPID9_0_Val               _UINT32_(0x0)                                        /* (PMC_GCSR0) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR0_GPID9_1_Val               _UINT32_(0x1)                                        /* (PMC_GCSR0) The corresponding Generic clock is enabled.  */
#define PMC_GCSR0_GPID9_0                     (PMC_GCSR0_GPID9_0_Val << PMC_GCSR0_GPID9_Pos)       /* (PMC_GCSR0) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR0_GPID9_1                     (PMC_GCSR0_GPID9_1_Val << PMC_GCSR0_GPID9_Pos)       /* (PMC_GCSR0) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR0_GPID10_Pos                  _UINT32_(10)                                         /* (PMC_GCSR0) Generic Clock 10 Status Position */
#define PMC_GCSR0_GPID10_Msk                  (_UINT32_(0x1) << PMC_GCSR0_GPID10_Pos)              /* (PMC_GCSR0) Generic Clock 10 Status Mask */
#define PMC_GCSR0_GPID10(value)               (PMC_GCSR0_GPID10_Msk & (_UINT32_(value) << PMC_GCSR0_GPID10_Pos)) /* Assigment of value for GPID10 in the PMC_GCSR0 register */
#define   PMC_GCSR0_GPID10_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR0) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR0_GPID10_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR0) The corresponding Generic clock is enabled.  */
#define PMC_GCSR0_GPID10_0                    (PMC_GCSR0_GPID10_0_Val << PMC_GCSR0_GPID10_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR0_GPID10_1                    (PMC_GCSR0_GPID10_1_Val << PMC_GCSR0_GPID10_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR0_GPID11_Pos                  _UINT32_(11)                                         /* (PMC_GCSR0) Generic Clock 11 Status Position */
#define PMC_GCSR0_GPID11_Msk                  (_UINT32_(0x1) << PMC_GCSR0_GPID11_Pos)              /* (PMC_GCSR0) Generic Clock 11 Status Mask */
#define PMC_GCSR0_GPID11(value)               (PMC_GCSR0_GPID11_Msk & (_UINT32_(value) << PMC_GCSR0_GPID11_Pos)) /* Assigment of value for GPID11 in the PMC_GCSR0 register */
#define   PMC_GCSR0_GPID11_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR0) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR0_GPID11_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR0) The corresponding Generic clock is enabled.  */
#define PMC_GCSR0_GPID11_0                    (PMC_GCSR0_GPID11_0_Val << PMC_GCSR0_GPID11_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR0_GPID11_1                    (PMC_GCSR0_GPID11_1_Val << PMC_GCSR0_GPID11_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR0_GPID12_Pos                  _UINT32_(12)                                         /* (PMC_GCSR0) Generic Clock 12 Status Position */
#define PMC_GCSR0_GPID12_Msk                  (_UINT32_(0x1) << PMC_GCSR0_GPID12_Pos)              /* (PMC_GCSR0) Generic Clock 12 Status Mask */
#define PMC_GCSR0_GPID12(value)               (PMC_GCSR0_GPID12_Msk & (_UINT32_(value) << PMC_GCSR0_GPID12_Pos)) /* Assigment of value for GPID12 in the PMC_GCSR0 register */
#define   PMC_GCSR0_GPID12_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR0) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR0_GPID12_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR0) The corresponding Generic clock is enabled.  */
#define PMC_GCSR0_GPID12_0                    (PMC_GCSR0_GPID12_0_Val << PMC_GCSR0_GPID12_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR0_GPID12_1                    (PMC_GCSR0_GPID12_1_Val << PMC_GCSR0_GPID12_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR0_GPID13_Pos                  _UINT32_(13)                                         /* (PMC_GCSR0) Generic Clock 13 Status Position */
#define PMC_GCSR0_GPID13_Msk                  (_UINT32_(0x1) << PMC_GCSR0_GPID13_Pos)              /* (PMC_GCSR0) Generic Clock 13 Status Mask */
#define PMC_GCSR0_GPID13(value)               (PMC_GCSR0_GPID13_Msk & (_UINT32_(value) << PMC_GCSR0_GPID13_Pos)) /* Assigment of value for GPID13 in the PMC_GCSR0 register */
#define   PMC_GCSR0_GPID13_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR0) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR0_GPID13_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR0) The corresponding Generic clock is enabled.  */
#define PMC_GCSR0_GPID13_0                    (PMC_GCSR0_GPID13_0_Val << PMC_GCSR0_GPID13_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR0_GPID13_1                    (PMC_GCSR0_GPID13_1_Val << PMC_GCSR0_GPID13_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR0_GPID14_Pos                  _UINT32_(14)                                         /* (PMC_GCSR0) Generic Clock 14 Status Position */
#define PMC_GCSR0_GPID14_Msk                  (_UINT32_(0x1) << PMC_GCSR0_GPID14_Pos)              /* (PMC_GCSR0) Generic Clock 14 Status Mask */
#define PMC_GCSR0_GPID14(value)               (PMC_GCSR0_GPID14_Msk & (_UINT32_(value) << PMC_GCSR0_GPID14_Pos)) /* Assigment of value for GPID14 in the PMC_GCSR0 register */
#define   PMC_GCSR0_GPID14_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR0) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR0_GPID14_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR0) The corresponding Generic clock is enabled.  */
#define PMC_GCSR0_GPID14_0                    (PMC_GCSR0_GPID14_0_Val << PMC_GCSR0_GPID14_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR0_GPID14_1                    (PMC_GCSR0_GPID14_1_Val << PMC_GCSR0_GPID14_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR0_GPID15_Pos                  _UINT32_(15)                                         /* (PMC_GCSR0) Generic Clock 15 Status Position */
#define PMC_GCSR0_GPID15_Msk                  (_UINT32_(0x1) << PMC_GCSR0_GPID15_Pos)              /* (PMC_GCSR0) Generic Clock 15 Status Mask */
#define PMC_GCSR0_GPID15(value)               (PMC_GCSR0_GPID15_Msk & (_UINT32_(value) << PMC_GCSR0_GPID15_Pos)) /* Assigment of value for GPID15 in the PMC_GCSR0 register */
#define   PMC_GCSR0_GPID15_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR0) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR0_GPID15_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR0) The corresponding Generic clock is enabled.  */
#define PMC_GCSR0_GPID15_0                    (PMC_GCSR0_GPID15_0_Val << PMC_GCSR0_GPID15_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR0_GPID15_1                    (PMC_GCSR0_GPID15_1_Val << PMC_GCSR0_GPID15_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR0_GPID16_Pos                  _UINT32_(16)                                         /* (PMC_GCSR0) Generic Clock 16 Status Position */
#define PMC_GCSR0_GPID16_Msk                  (_UINT32_(0x1) << PMC_GCSR0_GPID16_Pos)              /* (PMC_GCSR0) Generic Clock 16 Status Mask */
#define PMC_GCSR0_GPID16(value)               (PMC_GCSR0_GPID16_Msk & (_UINT32_(value) << PMC_GCSR0_GPID16_Pos)) /* Assigment of value for GPID16 in the PMC_GCSR0 register */
#define   PMC_GCSR0_GPID16_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR0) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR0_GPID16_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR0) The corresponding Generic clock is enabled.  */
#define PMC_GCSR0_GPID16_0                    (PMC_GCSR0_GPID16_0_Val << PMC_GCSR0_GPID16_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR0_GPID16_1                    (PMC_GCSR0_GPID16_1_Val << PMC_GCSR0_GPID16_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR0_GPID17_Pos                  _UINT32_(17)                                         /* (PMC_GCSR0) Generic Clock 17 Status Position */
#define PMC_GCSR0_GPID17_Msk                  (_UINT32_(0x1) << PMC_GCSR0_GPID17_Pos)              /* (PMC_GCSR0) Generic Clock 17 Status Mask */
#define PMC_GCSR0_GPID17(value)               (PMC_GCSR0_GPID17_Msk & (_UINT32_(value) << PMC_GCSR0_GPID17_Pos)) /* Assigment of value for GPID17 in the PMC_GCSR0 register */
#define   PMC_GCSR0_GPID17_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR0) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR0_GPID17_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR0) The corresponding Generic clock is enabled.  */
#define PMC_GCSR0_GPID17_0                    (PMC_GCSR0_GPID17_0_Val << PMC_GCSR0_GPID17_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR0_GPID17_1                    (PMC_GCSR0_GPID17_1_Val << PMC_GCSR0_GPID17_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR0_GPID19_Pos                  _UINT32_(19)                                         /* (PMC_GCSR0) Generic Clock 19 Status Position */
#define PMC_GCSR0_GPID19_Msk                  (_UINT32_(0x1) << PMC_GCSR0_GPID19_Pos)              /* (PMC_GCSR0) Generic Clock 19 Status Mask */
#define PMC_GCSR0_GPID19(value)               (PMC_GCSR0_GPID19_Msk & (_UINT32_(value) << PMC_GCSR0_GPID19_Pos)) /* Assigment of value for GPID19 in the PMC_GCSR0 register */
#define   PMC_GCSR0_GPID19_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR0) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR0_GPID19_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR0) The corresponding Generic clock is enabled.  */
#define PMC_GCSR0_GPID19_0                    (PMC_GCSR0_GPID19_0_Val << PMC_GCSR0_GPID19_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR0_GPID19_1                    (PMC_GCSR0_GPID19_1_Val << PMC_GCSR0_GPID19_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR0_GPID24_Pos                  _UINT32_(24)                                         /* (PMC_GCSR0) Generic Clock 24 Status Position */
#define PMC_GCSR0_GPID24_Msk                  (_UINT32_(0x1) << PMC_GCSR0_GPID24_Pos)              /* (PMC_GCSR0) Generic Clock 24 Status Mask */
#define PMC_GCSR0_GPID24(value)               (PMC_GCSR0_GPID24_Msk & (_UINT32_(value) << PMC_GCSR0_GPID24_Pos)) /* Assigment of value for GPID24 in the PMC_GCSR0 register */
#define   PMC_GCSR0_GPID24_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR0) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR0_GPID24_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR0) The corresponding Generic clock is enabled.  */
#define PMC_GCSR0_GPID24_0                    (PMC_GCSR0_GPID24_0_Val << PMC_GCSR0_GPID24_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR0_GPID24_1                    (PMC_GCSR0_GPID24_1_Val << PMC_GCSR0_GPID24_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR0_GPID25_Pos                  _UINT32_(25)                                         /* (PMC_GCSR0) Generic Clock 25 Status Position */
#define PMC_GCSR0_GPID25_Msk                  (_UINT32_(0x1) << PMC_GCSR0_GPID25_Pos)              /* (PMC_GCSR0) Generic Clock 25 Status Mask */
#define PMC_GCSR0_GPID25(value)               (PMC_GCSR0_GPID25_Msk & (_UINT32_(value) << PMC_GCSR0_GPID25_Pos)) /* Assigment of value for GPID25 in the PMC_GCSR0 register */
#define   PMC_GCSR0_GPID25_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR0) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR0_GPID25_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR0) The corresponding Generic clock is enabled.  */
#define PMC_GCSR0_GPID25_0                    (PMC_GCSR0_GPID25_0_Val << PMC_GCSR0_GPID25_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR0_GPID25_1                    (PMC_GCSR0_GPID25_1_Val << PMC_GCSR0_GPID25_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR0_GPID26_Pos                  _UINT32_(26)                                         /* (PMC_GCSR0) Generic Clock 26 Status Position */
#define PMC_GCSR0_GPID26_Msk                  (_UINT32_(0x1) << PMC_GCSR0_GPID26_Pos)              /* (PMC_GCSR0) Generic Clock 26 Status Mask */
#define PMC_GCSR0_GPID26(value)               (PMC_GCSR0_GPID26_Msk & (_UINT32_(value) << PMC_GCSR0_GPID26_Pos)) /* Assigment of value for GPID26 in the PMC_GCSR0 register */
#define   PMC_GCSR0_GPID26_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR0) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR0_GPID26_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR0) The corresponding Generic clock is enabled.  */
#define PMC_GCSR0_GPID26_0                    (PMC_GCSR0_GPID26_0_Val << PMC_GCSR0_GPID26_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR0_GPID26_1                    (PMC_GCSR0_GPID26_1_Val << PMC_GCSR0_GPID26_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR0_GPID29_Pos                  _UINT32_(29)                                         /* (PMC_GCSR0) Generic Clock 29 Status Position */
#define PMC_GCSR0_GPID29_Msk                  (_UINT32_(0x1) << PMC_GCSR0_GPID29_Pos)              /* (PMC_GCSR0) Generic Clock 29 Status Mask */
#define PMC_GCSR0_GPID29(value)               (PMC_GCSR0_GPID29_Msk & (_UINT32_(value) << PMC_GCSR0_GPID29_Pos)) /* Assigment of value for GPID29 in the PMC_GCSR0 register */
#define   PMC_GCSR0_GPID29_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR0) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR0_GPID29_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR0) The corresponding Generic clock is enabled.  */
#define PMC_GCSR0_GPID29_0                    (PMC_GCSR0_GPID29_0_Val << PMC_GCSR0_GPID29_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR0_GPID29_1                    (PMC_GCSR0_GPID29_1_Val << PMC_GCSR0_GPID29_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR0_GPID30_Pos                  _UINT32_(30)                                         /* (PMC_GCSR0) Generic Clock 30 Status Position */
#define PMC_GCSR0_GPID30_Msk                  (_UINT32_(0x1) << PMC_GCSR0_GPID30_Pos)              /* (PMC_GCSR0) Generic Clock 30 Status Mask */
#define PMC_GCSR0_GPID30(value)               (PMC_GCSR0_GPID30_Msk & (_UINT32_(value) << PMC_GCSR0_GPID30_Pos)) /* Assigment of value for GPID30 in the PMC_GCSR0 register */
#define   PMC_GCSR0_GPID30_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR0) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR0_GPID30_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR0) The corresponding Generic clock is enabled.  */
#define PMC_GCSR0_GPID30_0                    (PMC_GCSR0_GPID30_0_Val << PMC_GCSR0_GPID30_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR0_GPID30_1                    (PMC_GCSR0_GPID30_1_Val << PMC_GCSR0_GPID30_Pos)     /* (PMC_GCSR0) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR0_Msk                         _UINT32_(0x670BFFE0)                                 /* (PMC_GCSR0) Register Mask  */

#define PMC_GCSR0_GPID_Pos                    _UINT32_(5)                                          /* (PMC_GCSR0 Position) Generic Clock 3x Status */
#define PMC_GCSR0_GPID_Msk                    (_UINT32_(0x7FFFF) << PMC_GCSR0_GPID_Pos)            /* (PMC_GCSR0 Mask) GPID */
#define PMC_GCSR0_GPID(value)                 (PMC_GCSR0_GPID_Msk & (_UINT32_(value) << PMC_GCSR0_GPID_Pos)) 

/* -------- PMC_GCSR1 : (PMC Offset: 0xC4) ( R/ 32) Generic Clock Status Register 1 -------- */
#define PMC_GCSR1_RESETVALUE                  _UINT32_(0x00)                                       /*  (PMC_GCSR1) Generic Clock Status Register 1  Reset Value */

#define PMC_GCSR1_GPID32_Pos                  _UINT32_(0)                                          /* (PMC_GCSR1) Generic Clock 32 Status Position */
#define PMC_GCSR1_GPID32_Msk                  (_UINT32_(0x1) << PMC_GCSR1_GPID32_Pos)              /* (PMC_GCSR1) Generic Clock 32 Status Mask */
#define PMC_GCSR1_GPID32(value)               (PMC_GCSR1_GPID32_Msk & (_UINT32_(value) << PMC_GCSR1_GPID32_Pos)) /* Assigment of value for GPID32 in the PMC_GCSR1 register */
#define   PMC_GCSR1_GPID32_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR1) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR1_GPID32_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR1) The corresponding Generic clock is enabled.  */
#define PMC_GCSR1_GPID32_0                    (PMC_GCSR1_GPID32_0_Val << PMC_GCSR1_GPID32_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR1_GPID32_1                    (PMC_GCSR1_GPID32_1_Val << PMC_GCSR1_GPID32_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR1_GPID33_Pos                  _UINT32_(1)                                          /* (PMC_GCSR1) Generic Clock 33 Status Position */
#define PMC_GCSR1_GPID33_Msk                  (_UINT32_(0x1) << PMC_GCSR1_GPID33_Pos)              /* (PMC_GCSR1) Generic Clock 33 Status Mask */
#define PMC_GCSR1_GPID33(value)               (PMC_GCSR1_GPID33_Msk & (_UINT32_(value) << PMC_GCSR1_GPID33_Pos)) /* Assigment of value for GPID33 in the PMC_GCSR1 register */
#define   PMC_GCSR1_GPID33_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR1) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR1_GPID33_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR1) The corresponding Generic clock is enabled.  */
#define PMC_GCSR1_GPID33_0                    (PMC_GCSR1_GPID33_0_Val << PMC_GCSR1_GPID33_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR1_GPID33_1                    (PMC_GCSR1_GPID33_1_Val << PMC_GCSR1_GPID33_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR1_GPID34_Pos                  _UINT32_(2)                                          /* (PMC_GCSR1) Generic Clock 34 Status Position */
#define PMC_GCSR1_GPID34_Msk                  (_UINT32_(0x1) << PMC_GCSR1_GPID34_Pos)              /* (PMC_GCSR1) Generic Clock 34 Status Mask */
#define PMC_GCSR1_GPID34(value)               (PMC_GCSR1_GPID34_Msk & (_UINT32_(value) << PMC_GCSR1_GPID34_Pos)) /* Assigment of value for GPID34 in the PMC_GCSR1 register */
#define   PMC_GCSR1_GPID34_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR1) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR1_GPID34_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR1) The corresponding Generic clock is enabled.  */
#define PMC_GCSR1_GPID34_0                    (PMC_GCSR1_GPID34_0_Val << PMC_GCSR1_GPID34_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR1_GPID34_1                    (PMC_GCSR1_GPID34_1_Val << PMC_GCSR1_GPID34_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR1_GPID35_Pos                  _UINT32_(3)                                          /* (PMC_GCSR1) Generic Clock 35 Status Position */
#define PMC_GCSR1_GPID35_Msk                  (_UINT32_(0x1) << PMC_GCSR1_GPID35_Pos)              /* (PMC_GCSR1) Generic Clock 35 Status Mask */
#define PMC_GCSR1_GPID35(value)               (PMC_GCSR1_GPID35_Msk & (_UINT32_(value) << PMC_GCSR1_GPID35_Pos)) /* Assigment of value for GPID35 in the PMC_GCSR1 register */
#define   PMC_GCSR1_GPID35_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR1) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR1_GPID35_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR1) The corresponding Generic clock is enabled.  */
#define PMC_GCSR1_GPID35_0                    (PMC_GCSR1_GPID35_0_Val << PMC_GCSR1_GPID35_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR1_GPID35_1                    (PMC_GCSR1_GPID35_1_Val << PMC_GCSR1_GPID35_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR1_GPID37_Pos                  _UINT32_(5)                                          /* (PMC_GCSR1) Generic Clock 37 Status Position */
#define PMC_GCSR1_GPID37_Msk                  (_UINT32_(0x1) << PMC_GCSR1_GPID37_Pos)              /* (PMC_GCSR1) Generic Clock 37 Status Mask */
#define PMC_GCSR1_GPID37(value)               (PMC_GCSR1_GPID37_Msk & (_UINT32_(value) << PMC_GCSR1_GPID37_Pos)) /* Assigment of value for GPID37 in the PMC_GCSR1 register */
#define   PMC_GCSR1_GPID37_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR1) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR1_GPID37_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR1) The corresponding Generic clock is enabled.  */
#define PMC_GCSR1_GPID37_0                    (PMC_GCSR1_GPID37_0_Val << PMC_GCSR1_GPID37_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR1_GPID37_1                    (PMC_GCSR1_GPID37_1_Val << PMC_GCSR1_GPID37_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR1_GPID42_Pos                  _UINT32_(10)                                         /* (PMC_GCSR1) Generic Clock 42 Status Position */
#define PMC_GCSR1_GPID42_Msk                  (_UINT32_(0x1) << PMC_GCSR1_GPID42_Pos)              /* (PMC_GCSR1) Generic Clock 42 Status Mask */
#define PMC_GCSR1_GPID42(value)               (PMC_GCSR1_GPID42_Msk & (_UINT32_(value) << PMC_GCSR1_GPID42_Pos)) /* Assigment of value for GPID42 in the PMC_GCSR1 register */
#define   PMC_GCSR1_GPID42_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR1) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR1_GPID42_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR1) The corresponding Generic clock is enabled.  */
#define PMC_GCSR1_GPID42_0                    (PMC_GCSR1_GPID42_0_Val << PMC_GCSR1_GPID42_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR1_GPID42_1                    (PMC_GCSR1_GPID42_1_Val << PMC_GCSR1_GPID42_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR1_GPID45_Pos                  _UINT32_(13)                                         /* (PMC_GCSR1) Generic Clock 45 Status Position */
#define PMC_GCSR1_GPID45_Msk                  (_UINT32_(0x1) << PMC_GCSR1_GPID45_Pos)              /* (PMC_GCSR1) Generic Clock 45 Status Mask */
#define PMC_GCSR1_GPID45(value)               (PMC_GCSR1_GPID45_Msk & (_UINT32_(value) << PMC_GCSR1_GPID45_Pos)) /* Assigment of value for GPID45 in the PMC_GCSR1 register */
#define   PMC_GCSR1_GPID45_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR1) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR1_GPID45_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR1) The corresponding Generic clock is enabled.  */
#define PMC_GCSR1_GPID45_0                    (PMC_GCSR1_GPID45_0_Val << PMC_GCSR1_GPID45_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR1_GPID45_1                    (PMC_GCSR1_GPID45_1_Val << PMC_GCSR1_GPID45_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR1_GPID47_Pos                  _UINT32_(15)                                         /* (PMC_GCSR1) Generic Clock 47 Status Position */
#define PMC_GCSR1_GPID47_Msk                  (_UINT32_(0x1) << PMC_GCSR1_GPID47_Pos)              /* (PMC_GCSR1) Generic Clock 47 Status Mask */
#define PMC_GCSR1_GPID47(value)               (PMC_GCSR1_GPID47_Msk & (_UINT32_(value) << PMC_GCSR1_GPID47_Pos)) /* Assigment of value for GPID47 in the PMC_GCSR1 register */
#define   PMC_GCSR1_GPID47_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR1) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR1_GPID47_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR1) The corresponding Generic clock is enabled.  */
#define PMC_GCSR1_GPID47_0                    (PMC_GCSR1_GPID47_0_Val << PMC_GCSR1_GPID47_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR1_GPID47_1                    (PMC_GCSR1_GPID47_1_Val << PMC_GCSR1_GPID47_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR1_GPID55_Pos                  _UINT32_(23)                                         /* (PMC_GCSR1) Generic Clock 55 Status Position */
#define PMC_GCSR1_GPID55_Msk                  (_UINT32_(0x1) << PMC_GCSR1_GPID55_Pos)              /* (PMC_GCSR1) Generic Clock 55 Status Mask */
#define PMC_GCSR1_GPID55(value)               (PMC_GCSR1_GPID55_Msk & (_UINT32_(value) << PMC_GCSR1_GPID55_Pos)) /* Assigment of value for GPID55 in the PMC_GCSR1 register */
#define   PMC_GCSR1_GPID55_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR1) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR1_GPID55_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR1) The corresponding Generic clock is enabled.  */
#define PMC_GCSR1_GPID55_0                    (PMC_GCSR1_GPID55_0_Val << PMC_GCSR1_GPID55_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR1_GPID55_1                    (PMC_GCSR1_GPID55_1_Val << PMC_GCSR1_GPID55_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR1_GPID58_Pos                  _UINT32_(26)                                         /* (PMC_GCSR1) Generic Clock 58 Status Position */
#define PMC_GCSR1_GPID58_Msk                  (_UINT32_(0x1) << PMC_GCSR1_GPID58_Pos)              /* (PMC_GCSR1) Generic Clock 58 Status Mask */
#define PMC_GCSR1_GPID58(value)               (PMC_GCSR1_GPID58_Msk & (_UINT32_(value) << PMC_GCSR1_GPID58_Pos)) /* Assigment of value for GPID58 in the PMC_GCSR1 register */
#define   PMC_GCSR1_GPID58_0_Val              _UINT32_(0x0)                                        /* (PMC_GCSR1) The corresponding Generic clock is disabled.  */
#define   PMC_GCSR1_GPID58_1_Val              _UINT32_(0x1)                                        /* (PMC_GCSR1) The corresponding Generic clock is enabled.  */
#define PMC_GCSR1_GPID58_0                    (PMC_GCSR1_GPID58_0_Val << PMC_GCSR1_GPID58_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is disabled. Position  */
#define PMC_GCSR1_GPID58_1                    (PMC_GCSR1_GPID58_1_Val << PMC_GCSR1_GPID58_Pos)     /* (PMC_GCSR1) The corresponding Generic clock is enabled. Position  */
#define PMC_GCSR1_Msk                         _UINT32_(0x0480A42F)                                 /* (PMC_GCSR1) Register Mask  */

#define PMC_GCSR1_GPID_Pos                    _UINT32_(0)                                          /* (PMC_GCSR1 Position) Generic Clock 58 Status */
#define PMC_GCSR1_GPID_Msk                    (_UINT32_(0x3FF) << PMC_GCSR1_GPID_Pos)              /* (PMC_GCSR1 Mask) GPID */
#define PMC_GCSR1_GPID(value)                 (PMC_GCSR1_GPID_Msk & (_UINT32_(value) << PMC_GCSR1_GPID_Pos)) 

/* -------- PMC_PLL_IER : (PMC Offset: 0xE0) ( /W 32) PLL Interrupt Enable Register -------- */
#define PMC_PLL_IER_LOCKA_Pos                 _UINT32_(0)                                          /* (PMC_PLL_IER) PLLA Lock Interrupt Enable Position */
#define PMC_PLL_IER_LOCKA_Msk                 (_UINT32_(0x1) << PMC_PLL_IER_LOCKA_Pos)             /* (PMC_PLL_IER) PLLA Lock Interrupt Enable Mask */
#define PMC_PLL_IER_LOCKA(value)              (PMC_PLL_IER_LOCKA_Msk & (_UINT32_(value) << PMC_PLL_IER_LOCKA_Pos)) /* Assigment of value for LOCKA in the PMC_PLL_IER register */
#define PMC_PLL_IER_LOCKU_Pos                 _UINT32_(1)                                          /* (PMC_PLL_IER) UPLL Lock Interrupt Enable Position */
#define PMC_PLL_IER_LOCKU_Msk                 (_UINT32_(0x1) << PMC_PLL_IER_LOCKU_Pos)             /* (PMC_PLL_IER) UPLL Lock Interrupt Enable Mask */
#define PMC_PLL_IER_LOCKU(value)              (PMC_PLL_IER_LOCKU_Msk & (_UINT32_(value) << PMC_PLL_IER_LOCKU_Pos)) /* Assigment of value for LOCKU in the PMC_PLL_IER register */
#define PMC_PLL_IER_LOCKAU_Pos                _UINT32_(2)                                          /* (PMC_PLL_IER) AUDIO PLL Lock Interrupt Enable Position */
#define PMC_PLL_IER_LOCKAU_Msk                (_UINT32_(0x1) << PMC_PLL_IER_LOCKAU_Pos)            /* (PMC_PLL_IER) AUDIO PLL Lock Interrupt Enable Mask */
#define PMC_PLL_IER_LOCKAU(value)             (PMC_PLL_IER_LOCKAU_Msk & (_UINT32_(value) << PMC_PLL_IER_LOCKAU_Pos)) /* Assigment of value for LOCKAU in the PMC_PLL_IER register */
#define PMC_PLL_IER_LOCKLV_Pos                _UINT32_(3)                                          /* (PMC_PLL_IER) LVDS PLL Lock Interrupt Enable Position */
#define PMC_PLL_IER_LOCKLV_Msk                (_UINT32_(0x1) << PMC_PLL_IER_LOCKLV_Pos)            /* (PMC_PLL_IER) LVDS PLL Lock Interrupt Enable Mask */
#define PMC_PLL_IER_LOCKLV(value)             (PMC_PLL_IER_LOCKLV_Msk & (_UINT32_(value) << PMC_PLL_IER_LOCKLV_Pos)) /* Assigment of value for LOCKLV in the PMC_PLL_IER register */
#define PMC_PLL_IER_UNLOCKA_Pos               _UINT32_(16)                                         /* (PMC_PLL_IER) PLLA Unlock Interrupt Enable Position */
#define PMC_PLL_IER_UNLOCKA_Msk               (_UINT32_(0x1) << PMC_PLL_IER_UNLOCKA_Pos)           /* (PMC_PLL_IER) PLLA Unlock Interrupt Enable Mask */
#define PMC_PLL_IER_UNLOCKA(value)            (PMC_PLL_IER_UNLOCKA_Msk & (_UINT32_(value) << PMC_PLL_IER_UNLOCKA_Pos)) /* Assigment of value for UNLOCKA in the PMC_PLL_IER register */
#define PMC_PLL_IER_UNLOCKU_Pos               _UINT32_(17)                                         /* (PMC_PLL_IER) UPLL Unlock Interrupt Enable Position */
#define PMC_PLL_IER_UNLOCKU_Msk               (_UINT32_(0x1) << PMC_PLL_IER_UNLOCKU_Pos)           /* (PMC_PLL_IER) UPLL Unlock Interrupt Enable Mask */
#define PMC_PLL_IER_UNLOCKU(value)            (PMC_PLL_IER_UNLOCKU_Msk & (_UINT32_(value) << PMC_PLL_IER_UNLOCKU_Pos)) /* Assigment of value for UNLOCKU in the PMC_PLL_IER register */
#define PMC_PLL_IER_UNLOCKAU_Pos              _UINT32_(18)                                         /* (PMC_PLL_IER) AUDIO PLL Unlock Interrupt Enable Position */
#define PMC_PLL_IER_UNLOCKAU_Msk              (_UINT32_(0x1) << PMC_PLL_IER_UNLOCKAU_Pos)          /* (PMC_PLL_IER) AUDIO PLL Unlock Interrupt Enable Mask */
#define PMC_PLL_IER_UNLOCKAU(value)           (PMC_PLL_IER_UNLOCKAU_Msk & (_UINT32_(value) << PMC_PLL_IER_UNLOCKAU_Pos)) /* Assigment of value for UNLOCKAU in the PMC_PLL_IER register */
#define PMC_PLL_IER_UNLOCKLV_Pos              _UINT32_(19)                                         /* (PMC_PLL_IER) LVDS PLL Unlock Interrupt Enable Position */
#define PMC_PLL_IER_UNLOCKLV_Msk              (_UINT32_(0x1) << PMC_PLL_IER_UNLOCKLV_Pos)          /* (PMC_PLL_IER) LVDS PLL Unlock Interrupt Enable Mask */
#define PMC_PLL_IER_UNLOCKLV(value)           (PMC_PLL_IER_UNLOCKLV_Msk & (_UINT32_(value) << PMC_PLL_IER_UNLOCKLV_Pos)) /* Assigment of value for UNLOCKLV in the PMC_PLL_IER register */
#define PMC_PLL_IER_Msk                       _UINT32_(0x000F000F)                                 /* (PMC_PLL_IER) Register Mask  */


/* -------- PMC_PLL_IDR : (PMC Offset: 0xE4) ( /W 32) PLL Interrupt Disable Register -------- */
#define PMC_PLL_IDR_LOCKA_Pos                 _UINT32_(0)                                          /* (PMC_PLL_IDR) PLLA Lock Interrupt Disable Position */
#define PMC_PLL_IDR_LOCKA_Msk                 (_UINT32_(0x1) << PMC_PLL_IDR_LOCKA_Pos)             /* (PMC_PLL_IDR) PLLA Lock Interrupt Disable Mask */
#define PMC_PLL_IDR_LOCKA(value)              (PMC_PLL_IDR_LOCKA_Msk & (_UINT32_(value) << PMC_PLL_IDR_LOCKA_Pos)) /* Assigment of value for LOCKA in the PMC_PLL_IDR register */
#define PMC_PLL_IDR_LOCKU_Pos                 _UINT32_(1)                                          /* (PMC_PLL_IDR) UPLL Lock Interrupt Disable Position */
#define PMC_PLL_IDR_LOCKU_Msk                 (_UINT32_(0x1) << PMC_PLL_IDR_LOCKU_Pos)             /* (PMC_PLL_IDR) UPLL Lock Interrupt Disable Mask */
#define PMC_PLL_IDR_LOCKU(value)              (PMC_PLL_IDR_LOCKU_Msk & (_UINT32_(value) << PMC_PLL_IDR_LOCKU_Pos)) /* Assigment of value for LOCKU in the PMC_PLL_IDR register */
#define PMC_PLL_IDR_LOCKAU_Pos                _UINT32_(2)                                          /* (PMC_PLL_IDR) AUDIO PLL Lock Interrupt Disable Position */
#define PMC_PLL_IDR_LOCKAU_Msk                (_UINT32_(0x1) << PMC_PLL_IDR_LOCKAU_Pos)            /* (PMC_PLL_IDR) AUDIO PLL Lock Interrupt Disable Mask */
#define PMC_PLL_IDR_LOCKAU(value)             (PMC_PLL_IDR_LOCKAU_Msk & (_UINT32_(value) << PMC_PLL_IDR_LOCKAU_Pos)) /* Assigment of value for LOCKAU in the PMC_PLL_IDR register */
#define PMC_PLL_IDR_LOCKLV_Pos                _UINT32_(3)                                          /* (PMC_PLL_IDR) LVDS PLL Lock Interrupt Disable Position */
#define PMC_PLL_IDR_LOCKLV_Msk                (_UINT32_(0x1) << PMC_PLL_IDR_LOCKLV_Pos)            /* (PMC_PLL_IDR) LVDS PLL Lock Interrupt Disable Mask */
#define PMC_PLL_IDR_LOCKLV(value)             (PMC_PLL_IDR_LOCKLV_Msk & (_UINT32_(value) << PMC_PLL_IDR_LOCKLV_Pos)) /* Assigment of value for LOCKLV in the PMC_PLL_IDR register */
#define PMC_PLL_IDR_UNLOCKA_Pos               _UINT32_(16)                                         /* (PMC_PLL_IDR) PLLA Unlock Interrupt Disable Position */
#define PMC_PLL_IDR_UNLOCKA_Msk               (_UINT32_(0x1) << PMC_PLL_IDR_UNLOCKA_Pos)           /* (PMC_PLL_IDR) PLLA Unlock Interrupt Disable Mask */
#define PMC_PLL_IDR_UNLOCKA(value)            (PMC_PLL_IDR_UNLOCKA_Msk & (_UINT32_(value) << PMC_PLL_IDR_UNLOCKA_Pos)) /* Assigment of value for UNLOCKA in the PMC_PLL_IDR register */
#define PMC_PLL_IDR_UNLOCKU_Pos               _UINT32_(17)                                         /* (PMC_PLL_IDR) UPLL Unlock Interrupt Disable Position */
#define PMC_PLL_IDR_UNLOCKU_Msk               (_UINT32_(0x1) << PMC_PLL_IDR_UNLOCKU_Pos)           /* (PMC_PLL_IDR) UPLL Unlock Interrupt Disable Mask */
#define PMC_PLL_IDR_UNLOCKU(value)            (PMC_PLL_IDR_UNLOCKU_Msk & (_UINT32_(value) << PMC_PLL_IDR_UNLOCKU_Pos)) /* Assigment of value for UNLOCKU in the PMC_PLL_IDR register */
#define PMC_PLL_IDR_UNLOCKAU_Pos              _UINT32_(18)                                         /* (PMC_PLL_IDR) AUDIO PLL Unlock Interrupt Disable Position */
#define PMC_PLL_IDR_UNLOCKAU_Msk              (_UINT32_(0x1) << PMC_PLL_IDR_UNLOCKAU_Pos)          /* (PMC_PLL_IDR) AUDIO PLL Unlock Interrupt Disable Mask */
#define PMC_PLL_IDR_UNLOCKAU(value)           (PMC_PLL_IDR_UNLOCKAU_Msk & (_UINT32_(value) << PMC_PLL_IDR_UNLOCKAU_Pos)) /* Assigment of value for UNLOCKAU in the PMC_PLL_IDR register */
#define PMC_PLL_IDR_UNLOCKLV_Pos              _UINT32_(19)                                         /* (PMC_PLL_IDR) LVDS PLL Unlock Interrupt Disable Position */
#define PMC_PLL_IDR_UNLOCKLV_Msk              (_UINT32_(0x1) << PMC_PLL_IDR_UNLOCKLV_Pos)          /* (PMC_PLL_IDR) LVDS PLL Unlock Interrupt Disable Mask */
#define PMC_PLL_IDR_UNLOCKLV(value)           (PMC_PLL_IDR_UNLOCKLV_Msk & (_UINT32_(value) << PMC_PLL_IDR_UNLOCKLV_Pos)) /* Assigment of value for UNLOCKLV in the PMC_PLL_IDR register */
#define PMC_PLL_IDR_Msk                       _UINT32_(0x000F000F)                                 /* (PMC_PLL_IDR) Register Mask  */


/* -------- PMC_PLL_IMR : (PMC Offset: 0xE8) ( R/ 32) PLL Interrupt Mask Register -------- */
#define PMC_PLL_IMR_RESETVALUE                _UINT32_(0x00)                                       /*  (PMC_PLL_IMR) PLL Interrupt Mask Register  Reset Value */

#define PMC_PLL_IMR_LOCKA_Pos                 _UINT32_(0)                                          /* (PMC_PLL_IMR) PLLA Lock Interrupt Mask Position */
#define PMC_PLL_IMR_LOCKA_Msk                 (_UINT32_(0x1) << PMC_PLL_IMR_LOCKA_Pos)             /* (PMC_PLL_IMR) PLLA Lock Interrupt Mask Mask */
#define PMC_PLL_IMR_LOCKA(value)              (PMC_PLL_IMR_LOCKA_Msk & (_UINT32_(value) << PMC_PLL_IMR_LOCKA_Pos)) /* Assigment of value for LOCKA in the PMC_PLL_IMR register */
#define PMC_PLL_IMR_LOCKU_Pos                 _UINT32_(1)                                          /* (PMC_PLL_IMR) UPLL Lock Interrupt Mask Position */
#define PMC_PLL_IMR_LOCKU_Msk                 (_UINT32_(0x1) << PMC_PLL_IMR_LOCKU_Pos)             /* (PMC_PLL_IMR) UPLL Lock Interrupt Mask Mask */
#define PMC_PLL_IMR_LOCKU(value)              (PMC_PLL_IMR_LOCKU_Msk & (_UINT32_(value) << PMC_PLL_IMR_LOCKU_Pos)) /* Assigment of value for LOCKU in the PMC_PLL_IMR register */
#define PMC_PLL_IMR_LOCKAU_Pos                _UINT32_(2)                                          /* (PMC_PLL_IMR) AUDIO PLL Lock Interrupt Mask Position */
#define PMC_PLL_IMR_LOCKAU_Msk                (_UINT32_(0x1) << PMC_PLL_IMR_LOCKAU_Pos)            /* (PMC_PLL_IMR) AUDIO PLL Lock Interrupt Mask Mask */
#define PMC_PLL_IMR_LOCKAU(value)             (PMC_PLL_IMR_LOCKAU_Msk & (_UINT32_(value) << PMC_PLL_IMR_LOCKAU_Pos)) /* Assigment of value for LOCKAU in the PMC_PLL_IMR register */
#define PMC_PLL_IMR_LOCKLV_Pos                _UINT32_(3)                                          /* (PMC_PLL_IMR) LVDS PLL Lock Interrupt Mask Position */
#define PMC_PLL_IMR_LOCKLV_Msk                (_UINT32_(0x1) << PMC_PLL_IMR_LOCKLV_Pos)            /* (PMC_PLL_IMR) LVDS PLL Lock Interrupt Mask Mask */
#define PMC_PLL_IMR_LOCKLV(value)             (PMC_PLL_IMR_LOCKLV_Msk & (_UINT32_(value) << PMC_PLL_IMR_LOCKLV_Pos)) /* Assigment of value for LOCKLV in the PMC_PLL_IMR register */
#define PMC_PLL_IMR_UNLOCKA_Pos               _UINT32_(16)                                         /* (PMC_PLL_IMR) PLLA Unlock Interrupt Mask Position */
#define PMC_PLL_IMR_UNLOCKA_Msk               (_UINT32_(0x1) << PMC_PLL_IMR_UNLOCKA_Pos)           /* (PMC_PLL_IMR) PLLA Unlock Interrupt Mask Mask */
#define PMC_PLL_IMR_UNLOCKA(value)            (PMC_PLL_IMR_UNLOCKA_Msk & (_UINT32_(value) << PMC_PLL_IMR_UNLOCKA_Pos)) /* Assigment of value for UNLOCKA in the PMC_PLL_IMR register */
#define PMC_PLL_IMR_UNLOCKU_Pos               _UINT32_(17)                                         /* (PMC_PLL_IMR) UPLL Unlock Interrupt Mask Position */
#define PMC_PLL_IMR_UNLOCKU_Msk               (_UINT32_(0x1) << PMC_PLL_IMR_UNLOCKU_Pos)           /* (PMC_PLL_IMR) UPLL Unlock Interrupt Mask Mask */
#define PMC_PLL_IMR_UNLOCKU(value)            (PMC_PLL_IMR_UNLOCKU_Msk & (_UINT32_(value) << PMC_PLL_IMR_UNLOCKU_Pos)) /* Assigment of value for UNLOCKU in the PMC_PLL_IMR register */
#define PMC_PLL_IMR_UNLOCKAU_Pos              _UINT32_(18)                                         /* (PMC_PLL_IMR) AUDIO PLL Unlock Interrupt Mask Position */
#define PMC_PLL_IMR_UNLOCKAU_Msk              (_UINT32_(0x1) << PMC_PLL_IMR_UNLOCKAU_Pos)          /* (PMC_PLL_IMR) AUDIO PLL Unlock Interrupt Mask Mask */
#define PMC_PLL_IMR_UNLOCKAU(value)           (PMC_PLL_IMR_UNLOCKAU_Msk & (_UINT32_(value) << PMC_PLL_IMR_UNLOCKAU_Pos)) /* Assigment of value for UNLOCKAU in the PMC_PLL_IMR register */
#define PMC_PLL_IMR_UNLOCKLV_Pos              _UINT32_(19)                                         /* (PMC_PLL_IMR) LVDS PLL Unlock Interrupt Mask Position */
#define PMC_PLL_IMR_UNLOCKLV_Msk              (_UINT32_(0x1) << PMC_PLL_IMR_UNLOCKLV_Pos)          /* (PMC_PLL_IMR) LVDS PLL Unlock Interrupt Mask Mask */
#define PMC_PLL_IMR_UNLOCKLV(value)           (PMC_PLL_IMR_UNLOCKLV_Msk & (_UINT32_(value) << PMC_PLL_IMR_UNLOCKLV_Pos)) /* Assigment of value for UNLOCKLV in the PMC_PLL_IMR register */
#define PMC_PLL_IMR_Msk                       _UINT32_(0x000F000F)                                 /* (PMC_PLL_IMR) Register Mask  */


/* -------- PMC_PLL_ISR0 : (PMC Offset: 0xEC) ( R/ 32) PLL Interrupt Status Register 0 -------- */
#define PMC_PLL_ISR0_RESETVALUE               _UINT32_(0x00)                                       /*  (PMC_PLL_ISR0) PLL Interrupt Status Register 0  Reset Value */

#define PMC_PLL_ISR0_LOCKA_Pos                _UINT32_(0)                                          /* (PMC_PLL_ISR0) PLLA Lock Interrupt Status Position */
#define PMC_PLL_ISR0_LOCKA_Msk                (_UINT32_(0x1) << PMC_PLL_ISR0_LOCKA_Pos)            /* (PMC_PLL_ISR0) PLLA Lock Interrupt Status Mask */
#define PMC_PLL_ISR0_LOCKA(value)             (PMC_PLL_ISR0_LOCKA_Msk & (_UINT32_(value) << PMC_PLL_ISR0_LOCKA_Pos)) /* Assigment of value for LOCKA in the PMC_PLL_ISR0 register */
#define   PMC_PLL_ISR0_LOCKA_0_Val            _UINT32_(0x0)                                        /* (PMC_PLL_ISR0) PLLA is not locked.  */
#define   PMC_PLL_ISR0_LOCKA_1_Val            _UINT32_(0x1)                                        /* (PMC_PLL_ISR0) PLLA is locked.  */
#define PMC_PLL_ISR0_LOCKA_0                  (PMC_PLL_ISR0_LOCKA_0_Val << PMC_PLL_ISR0_LOCKA_Pos) /* (PMC_PLL_ISR0) PLLA is not locked. Position  */
#define PMC_PLL_ISR0_LOCKA_1                  (PMC_PLL_ISR0_LOCKA_1_Val << PMC_PLL_ISR0_LOCKA_Pos) /* (PMC_PLL_ISR0) PLLA is locked. Position  */
#define PMC_PLL_ISR0_LOCKU_Pos                _UINT32_(1)                                          /* (PMC_PLL_ISR0) UPLL Lock Interrupt Status Position */
#define PMC_PLL_ISR0_LOCKU_Msk                (_UINT32_(0x1) << PMC_PLL_ISR0_LOCKU_Pos)            /* (PMC_PLL_ISR0) UPLL Lock Interrupt Status Mask */
#define PMC_PLL_ISR0_LOCKU(value)             (PMC_PLL_ISR0_LOCKU_Msk & (_UINT32_(value) << PMC_PLL_ISR0_LOCKU_Pos)) /* Assigment of value for LOCKU in the PMC_PLL_ISR0 register */
#define   PMC_PLL_ISR0_LOCKU_0_Val            _UINT32_(0x0)                                        /* (PMC_PLL_ISR0) UPLL is not locked.  */
#define   PMC_PLL_ISR0_LOCKU_1_Val            _UINT32_(0x1)                                        /* (PMC_PLL_ISR0) UPLL is locked.  */
#define PMC_PLL_ISR0_LOCKU_0                  (PMC_PLL_ISR0_LOCKU_0_Val << PMC_PLL_ISR0_LOCKU_Pos) /* (PMC_PLL_ISR0) UPLL is not locked. Position  */
#define PMC_PLL_ISR0_LOCKU_1                  (PMC_PLL_ISR0_LOCKU_1_Val << PMC_PLL_ISR0_LOCKU_Pos) /* (PMC_PLL_ISR0) UPLL is locked. Position  */
#define PMC_PLL_ISR0_AUDIOLOCK_Pos            _UINT32_(2)                                          /* (PMC_PLL_ISR0) Audio PLL Lock Interrupt Status Position */
#define PMC_PLL_ISR0_AUDIOLOCK_Msk            (_UINT32_(0x1) << PMC_PLL_ISR0_AUDIOLOCK_Pos)        /* (PMC_PLL_ISR0) Audio PLL Lock Interrupt Status Mask */
#define PMC_PLL_ISR0_AUDIOLOCK(value)         (PMC_PLL_ISR0_AUDIOLOCK_Msk & (_UINT32_(value) << PMC_PLL_ISR0_AUDIOLOCK_Pos)) /* Assigment of value for AUDIOLOCK in the PMC_PLL_ISR0 register */
#define   PMC_PLL_ISR0_AUDIOLOCK_0_Val        _UINT32_(0x0)                                        /* (PMC_PLL_ISR0) Audio PLL is not locked.  */
#define   PMC_PLL_ISR0_AUDIOLOCK_1_Val        _UINT32_(0x1)                                        /* (PMC_PLL_ISR0) Audio PLL is locked.  */
#define PMC_PLL_ISR0_AUDIOLOCK_0              (PMC_PLL_ISR0_AUDIOLOCK_0_Val << PMC_PLL_ISR0_AUDIOLOCK_Pos) /* (PMC_PLL_ISR0) Audio PLL is not locked. Position  */
#define PMC_PLL_ISR0_AUDIOLOCK_1              (PMC_PLL_ISR0_AUDIOLOCK_1_Val << PMC_PLL_ISR0_AUDIOLOCK_Pos) /* (PMC_PLL_ISR0) Audio PLL is locked. Position  */
#define PMC_PLL_ISR0_LVDSLOCK_Pos             _UINT32_(3)                                          /* (PMC_PLL_ISR0) LVDS PLL Lock Interrupt Status Position */
#define PMC_PLL_ISR0_LVDSLOCK_Msk             (_UINT32_(0x1) << PMC_PLL_ISR0_LVDSLOCK_Pos)         /* (PMC_PLL_ISR0) LVDS PLL Lock Interrupt Status Mask */
#define PMC_PLL_ISR0_LVDSLOCK(value)          (PMC_PLL_ISR0_LVDSLOCK_Msk & (_UINT32_(value) << PMC_PLL_ISR0_LVDSLOCK_Pos)) /* Assigment of value for LVDSLOCK in the PMC_PLL_ISR0 register */
#define   PMC_PLL_ISR0_LVDSLOCK_0_Val         _UINT32_(0x0)                                        /* (PMC_PLL_ISR0) LVDS PLL is not locked.  */
#define   PMC_PLL_ISR0_LVDSLOCK_1_Val         _UINT32_(0x1)                                        /* (PMC_PLL_ISR0) LVDS PLL is locked.  */
#define PMC_PLL_ISR0_LVDSLOCK_0               (PMC_PLL_ISR0_LVDSLOCK_0_Val << PMC_PLL_ISR0_LVDSLOCK_Pos) /* (PMC_PLL_ISR0) LVDS PLL is not locked. Position  */
#define PMC_PLL_ISR0_LVDSLOCK_1               (PMC_PLL_ISR0_LVDSLOCK_1_Val << PMC_PLL_ISR0_LVDSLOCK_Pos) /* (PMC_PLL_ISR0) LVDS PLL is locked. Position  */
#define PMC_PLL_ISR0_UNLOCKA_Pos              _UINT32_(16)                                         /* (PMC_PLL_ISR0) PLLA Unlock Interrupt Status Position */
#define PMC_PLL_ISR0_UNLOCKA_Msk              (_UINT32_(0x1) << PMC_PLL_ISR0_UNLOCKA_Pos)          /* (PMC_PLL_ISR0) PLLA Unlock Interrupt Status Mask */
#define PMC_PLL_ISR0_UNLOCKA(value)           (PMC_PLL_ISR0_UNLOCKA_Msk & (_UINT32_(value) << PMC_PLL_ISR0_UNLOCKA_Pos)) /* Assigment of value for UNLOCKA in the PMC_PLL_ISR0 register */
#define   PMC_PLL_ISR0_UNLOCKA_0_Val          _UINT32_(0x0)                                        /* (PMC_PLL_ISR0) PLLA is not unlocked.  */
#define   PMC_PLL_ISR0_UNLOCKA_1_Val          _UINT32_(0x1)                                        /* (PMC_PLL_ISR0) PLLA is unlocked. To know the unlock type, the PMC_PISR1 register can be read.  */
#define PMC_PLL_ISR0_UNLOCKA_0                (PMC_PLL_ISR0_UNLOCKA_0_Val << PMC_PLL_ISR0_UNLOCKA_Pos) /* (PMC_PLL_ISR0) PLLA is not unlocked. Position  */
#define PMC_PLL_ISR0_UNLOCKA_1                (PMC_PLL_ISR0_UNLOCKA_1_Val << PMC_PLL_ISR0_UNLOCKA_Pos) /* (PMC_PLL_ISR0) PLLA is unlocked. To know the unlock type, the PMC_PISR1 register can be read. Position  */
#define PMC_PLL_ISR0_UNLOCKU_Pos              _UINT32_(17)                                         /* (PMC_PLL_ISR0) UPLL Unlock Interrupt Status Position */
#define PMC_PLL_ISR0_UNLOCKU_Msk              (_UINT32_(0x1) << PMC_PLL_ISR0_UNLOCKU_Pos)          /* (PMC_PLL_ISR0) UPLL Unlock Interrupt Status Mask */
#define PMC_PLL_ISR0_UNLOCKU(value)           (PMC_PLL_ISR0_UNLOCKU_Msk & (_UINT32_(value) << PMC_PLL_ISR0_UNLOCKU_Pos)) /* Assigment of value for UNLOCKU in the PMC_PLL_ISR0 register */
#define   PMC_PLL_ISR0_UNLOCKU_0_Val          _UINT32_(0x0)                                        /* (PMC_PLL_ISR0) UPLL is not unlocked.  */
#define   PMC_PLL_ISR0_UNLOCKU_1_Val          _UINT32_(0x1)                                        /* (PMC_PLL_ISR0) UPLL is unlocked. To know the unlock type, the PMC_PISR1 register can be read.  */
#define PMC_PLL_ISR0_UNLOCKU_0                (PMC_PLL_ISR0_UNLOCKU_0_Val << PMC_PLL_ISR0_UNLOCKU_Pos) /* (PMC_PLL_ISR0) UPLL is not unlocked. Position  */
#define PMC_PLL_ISR0_UNLOCKU_1                (PMC_PLL_ISR0_UNLOCKU_1_Val << PMC_PLL_ISR0_UNLOCKU_Pos) /* (PMC_PLL_ISR0) UPLL is unlocked. To know the unlock type, the PMC_PISR1 register can be read. Position  */
#define PMC_PLL_ISR0_AUDIOUNLOCK_Pos          _UINT32_(18)                                         /* (PMC_PLL_ISR0) Audio PLL Unlock Interrupt Status Position */
#define PMC_PLL_ISR0_AUDIOUNLOCK_Msk          (_UINT32_(0x1) << PMC_PLL_ISR0_AUDIOUNLOCK_Pos)      /* (PMC_PLL_ISR0) Audio PLL Unlock Interrupt Status Mask */
#define PMC_PLL_ISR0_AUDIOUNLOCK(value)       (PMC_PLL_ISR0_AUDIOUNLOCK_Msk & (_UINT32_(value) << PMC_PLL_ISR0_AUDIOUNLOCK_Pos)) /* Assigment of value for AUDIOUNLOCK in the PMC_PLL_ISR0 register */
#define   PMC_PLL_ISR0_AUDIOUNLOCK_0_Val      _UINT32_(0x0)                                        /* (PMC_PLL_ISR0) Audio PLL is not unlocked.  */
#define   PMC_PLL_ISR0_AUDIOUNLOCK_1_Val      _UINT32_(0x1)                                        /* (PMC_PLL_ISR0) Audio PLL is unlocked. To know the unlock type, the PMC_PISR1 register can be read.  */
#define PMC_PLL_ISR0_AUDIOUNLOCK_0            (PMC_PLL_ISR0_AUDIOUNLOCK_0_Val << PMC_PLL_ISR0_AUDIOUNLOCK_Pos) /* (PMC_PLL_ISR0) Audio PLL is not unlocked. Position  */
#define PMC_PLL_ISR0_AUDIOUNLOCK_1            (PMC_PLL_ISR0_AUDIOUNLOCK_1_Val << PMC_PLL_ISR0_AUDIOUNLOCK_Pos) /* (PMC_PLL_ISR0) Audio PLL is unlocked. To know the unlock type, the PMC_PISR1 register can be read. Position  */
#define PMC_PLL_ISR0_LVDSUNLOCK_Pos           _UINT32_(19)                                         /* (PMC_PLL_ISR0) LVDS PLL Unlock Interrupt Status Position */
#define PMC_PLL_ISR0_LVDSUNLOCK_Msk           (_UINT32_(0x1) << PMC_PLL_ISR0_LVDSUNLOCK_Pos)       /* (PMC_PLL_ISR0) LVDS PLL Unlock Interrupt Status Mask */
#define PMC_PLL_ISR0_LVDSUNLOCK(value)        (PMC_PLL_ISR0_LVDSUNLOCK_Msk & (_UINT32_(value) << PMC_PLL_ISR0_LVDSUNLOCK_Pos)) /* Assigment of value for LVDSUNLOCK in the PMC_PLL_ISR0 register */
#define   PMC_PLL_ISR0_LVDSUNLOCK_0_Val       _UINT32_(0x0)                                        /* (PMC_PLL_ISR0) LVDS PLL is not unlocked.  */
#define   PMC_PLL_ISR0_LVDSUNLOCK_1_Val       _UINT32_(0x1)                                        /* (PMC_PLL_ISR0) LVDS PLL is unlocked.  */
#define PMC_PLL_ISR0_LVDSUNLOCK_0             (PMC_PLL_ISR0_LVDSUNLOCK_0_Val << PMC_PLL_ISR0_LVDSUNLOCK_Pos) /* (PMC_PLL_ISR0) LVDS PLL is not unlocked. Position  */
#define PMC_PLL_ISR0_LVDSUNLOCK_1             (PMC_PLL_ISR0_LVDSUNLOCK_1_Val << PMC_PLL_ISR0_LVDSUNLOCK_Pos) /* (PMC_PLL_ISR0) LVDS PLL is unlocked. Position  */
#define PMC_PLL_ISR0_Msk                      _UINT32_(0x000F000F)                                 /* (PMC_PLL_ISR0) Register Mask  */


/* -------- PMC_PLL_ISR1 : (PMC Offset: 0xF0) ( R/ 32) PLL Interrupt Status Register 1 -------- */
#define PMC_PLL_ISR1_RESETVALUE               _UINT32_(0x00)                                       /*  (PMC_PLL_ISR1) PLL Interrupt Status Register 1  Reset Value */

#define PMC_PLL_ISR1_UDRAU_Pos                _UINT32_(2)                                          /* (PMC_PLL_ISR1) AUDIO PLL Underflow Position */
#define PMC_PLL_ISR1_UDRAU_Msk                (_UINT32_(0x1) << PMC_PLL_ISR1_UDRAU_Pos)            /* (PMC_PLL_ISR1) AUDIO PLL Underflow Mask */
#define PMC_PLL_ISR1_UDRAU(value)             (PMC_PLL_ISR1_UDRAU_Msk & (_UINT32_(value) << PMC_PLL_ISR1_UDRAU_Pos)) /* Assigment of value for UDRAU in the PMC_PLL_ISR1 register */
#define   PMC_PLL_ISR1_UDRAU_0_Val            _UINT32_(0x0)                                        /* (PMC_PLL_ISR1) AUDIO PLL is not in underflow state.  */
#define   PMC_PLL_ISR1_UDRAU_1_Val            _UINT32_(0x1)                                        /* (PMC_PLL_ISR1) AUDIO PLL encountered an underflow.  */
#define PMC_PLL_ISR1_UDRAU_0                  (PMC_PLL_ISR1_UDRAU_0_Val << PMC_PLL_ISR1_UDRAU_Pos) /* (PMC_PLL_ISR1) AUDIO PLL is not in underflow state. Position  */
#define PMC_PLL_ISR1_UDRAU_1                  (PMC_PLL_ISR1_UDRAU_1_Val << PMC_PLL_ISR1_UDRAU_Pos) /* (PMC_PLL_ISR1) AUDIO PLL encountered an underflow. Position  */
#define PMC_PLL_ISR1_OVRAU_Pos                _UINT32_(18)                                         /* (PMC_PLL_ISR1) AUDIO PLL Overflow Position */
#define PMC_PLL_ISR1_OVRAU_Msk                (_UINT32_(0x1) << PMC_PLL_ISR1_OVRAU_Pos)            /* (PMC_PLL_ISR1) AUDIO PLL Overflow Mask */
#define PMC_PLL_ISR1_OVRAU(value)             (PMC_PLL_ISR1_OVRAU_Msk & (_UINT32_(value) << PMC_PLL_ISR1_OVRAU_Pos)) /* Assigment of value for OVRAU in the PMC_PLL_ISR1 register */
#define   PMC_PLL_ISR1_OVRAU_0_Val            _UINT32_(0x0)                                        /* (PMC_PLL_ISR1) AUDIO PLL is not in overflow state.  */
#define   PMC_PLL_ISR1_OVRAU_1_Val            _UINT32_(0x1)                                        /* (PMC_PLL_ISR1) AUDIO PLL encountered an overflow.  */
#define PMC_PLL_ISR1_OVRAU_0                  (PMC_PLL_ISR1_OVRAU_0_Val << PMC_PLL_ISR1_OVRAU_Pos) /* (PMC_PLL_ISR1) AUDIO PLL is not in overflow state. Position  */
#define PMC_PLL_ISR1_OVRAU_1                  (PMC_PLL_ISR1_OVRAU_1_Val << PMC_PLL_ISR1_OVRAU_Pos) /* (PMC_PLL_ISR1) AUDIO PLL encountered an overflow. Position  */
#define PMC_PLL_ISR1_Msk                      _UINT32_(0x00040004)                                 /* (PMC_PLL_ISR1) Register Mask  */


/** \brief PMC register offsets definitions */
#define PMC_SCER_REG_OFST              _UINT32_(0x00)      /* (PMC_SCER) System Clock Enable Register Offset */
#define PMC_SCDR_REG_OFST              _UINT32_(0x04)      /* (PMC_SCDR) System Clock Disable Register Offset */
#define PMC_SCSR_REG_OFST              _UINT32_(0x08)      /* (PMC_SCSR) System Clock Status Register Offset */
#define PMC_PLL_CTRL0_REG_OFST         _UINT32_(0x0C)      /* (PMC_PLL_CTRL0) PLL Control Register 0 Offset */
#define PMC_PLL_CTRL1_REG_OFST         _UINT32_(0x10)      /* (PMC_PLL_CTRL1) PLL Control Register 1 Offset */
#define PMC_PLL_SSR_REG_OFST           _UINT32_(0x14)      /* (PMC_PLL_SSR) PLL Spread Spectrum Register Offset */
#define PMC_PLL_ACR_REG_OFST           _UINT32_(0x18)      /* (PMC_PLL_ACR) PLL Analog Control Register Offset */
#define PMC_PLL_UPDT_REG_OFST          _UINT32_(0x1C)      /* (PMC_PLL_UPDT) PLL Update Register Offset */
#define CKGR_MOR_REG_OFST              _UINT32_(0x20)      /* (CKGR_MOR) Main Oscillator Register Offset */
#define CKGR_MCFR_REG_OFST             _UINT32_(0x24)      /* (CKGR_MCFR) Main Clock Frequency Register Offset */
#define PMC_CPU_CKR_REG_OFST           _UINT32_(0x28)      /* (PMC_CPU_CKR) CPU Clock Register Offset */
#define PMC_USB_REG_OFST               _UINT32_(0x38)      /* (PMC_USB) USB Clock Register Offset */
#define PMC_PCK_REG_OFST               _UINT32_(0x40)      /* (PMC_PCK) Programmable Clock Register x Offset */
#define PMC_PCK0_REG_OFST              _UINT32_(0x40)      /* (PMC_PCK0) Programmable Clock Register x Offset */
#define PMC_PCK1_REG_OFST              _UINT32_(0x44)      /* (PMC_PCK1) Programmable Clock Register x Offset */
#define PMC_IER_REG_OFST               _UINT32_(0x60)      /* (PMC_IER) Interrupt Enable Register Offset */
#define PMC_IDR_REG_OFST               _UINT32_(0x64)      /* (PMC_IDR) Interrupt Disable Register Offset */
#define PMC_SR_REG_OFST                _UINT32_(0x68)      /* (PMC_SR) Status Register Offset */
#define PMC_IMR_REG_OFST               _UINT32_(0x6C)      /* (PMC_IMR) Interrupt Mask Register Offset */
#define PMC_FSMR_REG_OFST              _UINT32_(0x70)      /* (PMC_FSMR) Fast Startup Mode Register Offset */
#define PMC_WCR_REG_OFST               _UINT32_(0x74)      /* (PMC_WCR) Wakeup Control Register Offset */
#define PMC_FOCR_REG_OFST              _UINT32_(0x78)      /* (PMC_FOCR) Fault Output Clear Register Offset */
#define PMC_WPMR_REG_OFST              _UINT32_(0x80)      /* (PMC_WPMR) Write Protection Mode Register Offset */
#define PMC_WPSR_REG_OFST              _UINT32_(0x84)      /* (PMC_WPSR) Write Protection Status Register Offset */
#define PMC_PCR_REG_OFST               _UINT32_(0x88)      /* (PMC_PCR) Peripheral Control Register Offset */
#define PMC_MCKLIM_REG_OFST            _UINT32_(0x9C)      /* (PMC_MCKLIM) MCK Monitor Limits Register Offset */
#define PMC_CSR0_REG_OFST              _UINT32_(0xA0)      /* (PMC_CSR0) Peripheral Clock Status Register 0 Offset */
#define PMC_CSR1_REG_OFST              _UINT32_(0xA4)      /* (PMC_CSR1) Peripheral Clock Status Register 1 Offset */
#define PMC_GCSR0_REG_OFST             _UINT32_(0xC0)      /* (PMC_GCSR0) Generic Clock Status Register 0 Offset */
#define PMC_GCSR1_REG_OFST             _UINT32_(0xC4)      /* (PMC_GCSR1) Generic Clock Status Register 1 Offset */
#define PMC_PLL_IER_REG_OFST           _UINT32_(0xE0)      /* (PMC_PLL_IER) PLL Interrupt Enable Register Offset */
#define PMC_PLL_IDR_REG_OFST           _UINT32_(0xE4)      /* (PMC_PLL_IDR) PLL Interrupt Disable Register Offset */
#define PMC_PLL_IMR_REG_OFST           _UINT32_(0xE8)      /* (PMC_PLL_IMR) PLL Interrupt Mask Register Offset */
#define PMC_PLL_ISR0_REG_OFST          _UINT32_(0xEC)      /* (PMC_PLL_ISR0) PLL Interrupt Status Register 0 Offset */
#define PMC_PLL_ISR1_REG_OFST          _UINT32_(0xF0)      /* (PMC_PLL_ISR1) PLL Interrupt Status Register 1 Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief PMC register API structure */
typedef struct
{  /* Power Management Controller */
  __O   uint32_t                       PMC_SCER;           /**< Offset: 0x00 ( /W  32) System Clock Enable Register */
  __O   uint32_t                       PMC_SCDR;           /**< Offset: 0x04 ( /W  32) System Clock Disable Register */
  __I   uint32_t                       PMC_SCSR;           /**< Offset: 0x08 (R/   32) System Clock Status Register */
  __IO  uint32_t                       PMC_PLL_CTRL0;      /**< Offset: 0x0C (R/W  32) PLL Control Register 0 */
  __IO  uint32_t                       PMC_PLL_CTRL1;      /**< Offset: 0x10 (R/W  32) PLL Control Register 1 */
  __IO  uint32_t                       PMC_PLL_SSR;        /**< Offset: 0x14 (R/W  32) PLL Spread Spectrum Register */
  __IO  uint32_t                       PMC_PLL_ACR;        /**< Offset: 0x18 (R/W  32) PLL Analog Control Register */
  __IO  uint32_t                       PMC_PLL_UPDT;       /**< Offset: 0x1C (R/W  32) PLL Update Register */
  __IO  uint32_t                       CKGR_MOR;           /**< Offset: 0x20 (R/W  32) Main Oscillator Register */
  __IO  uint32_t                       CKGR_MCFR;          /**< Offset: 0x24 (R/W  32) Main Clock Frequency Register */
  __IO  uint32_t                       PMC_CPU_CKR;        /**< Offset: 0x28 (R/W  32) CPU Clock Register */
  __I   uint8_t                        Reserved1[0x0C];
  __IO  uint32_t                       PMC_USB;            /**< Offset: 0x38 (R/W  32) USB Clock Register */
  __I   uint8_t                        Reserved2[0x04];
  __IO  uint32_t                       PMC_PCK[2];         /**< Offset: 0x40 (R/W  32) Programmable Clock Register x */
  __I   uint8_t                        Reserved3[0x18];
  __O   uint32_t                       PMC_IER;            /**< Offset: 0x60 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       PMC_IDR;            /**< Offset: 0x64 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       PMC_SR;             /**< Offset: 0x68 (R/   32) Status Register */
  __I   uint32_t                       PMC_IMR;            /**< Offset: 0x6C (R/   32) Interrupt Mask Register */
  __IO  uint32_t                       PMC_FSMR;           /**< Offset: 0x70 (R/W  32) Fast Startup Mode Register */
  __IO  uint32_t                       PMC_WCR;            /**< Offset: 0x74 (R/W  32) Wakeup Control Register */
  __O   uint32_t                       PMC_FOCR;           /**< Offset: 0x78 ( /W  32) Fault Output Clear Register */
  __I   uint8_t                        Reserved4[0x04];
  __IO  uint32_t                       PMC_WPMR;           /**< Offset: 0x80 (R/W  32) Write Protection Mode Register */
  __I   uint32_t                       PMC_WPSR;           /**< Offset: 0x84 (R/   32) Write Protection Status Register */
  __IO  uint32_t                       PMC_PCR;            /**< Offset: 0x88 (R/W  32) Peripheral Control Register */
  __I   uint8_t                        Reserved5[0x10];
  __IO  uint32_t                       PMC_MCKLIM;         /**< Offset: 0x9C (R/W  32) MCK Monitor Limits Register */
  __I   uint32_t                       PMC_CSR0;           /**< Offset: 0xA0 (R/   32) Peripheral Clock Status Register 0 */
  __I   uint32_t                       PMC_CSR1;           /**< Offset: 0xA4 (R/   32) Peripheral Clock Status Register 1 */
  __I   uint8_t                        Reserved6[0x18];
  __I   uint32_t                       PMC_GCSR0;          /**< Offset: 0xC0 (R/   32) Generic Clock Status Register 0 */
  __I   uint32_t                       PMC_GCSR1;          /**< Offset: 0xC4 (R/   32) Generic Clock Status Register 1 */
  __I   uint8_t                        Reserved7[0x18];
  __O   uint32_t                       PMC_PLL_IER;        /**< Offset: 0xE0 ( /W  32) PLL Interrupt Enable Register */
  __O   uint32_t                       PMC_PLL_IDR;        /**< Offset: 0xE4 ( /W  32) PLL Interrupt Disable Register */
  __I   uint32_t                       PMC_PLL_IMR;        /**< Offset: 0xE8 (R/   32) PLL Interrupt Mask Register */
  __I   uint32_t                       PMC_PLL_ISR0;       /**< Offset: 0xEC (R/   32) PLL Interrupt Status Register 0 */
  __I   uint32_t                       PMC_PLL_ISR1;       /**< Offset: 0xF0 (R/   32) PLL Interrupt Status Register 1 */
} pmc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X7_PMC_COMPONENT_H_ */
