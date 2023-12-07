/*
 * Component description for HMATRIX2
 *
 * Copyright (c) 2023 Microchip Technology Inc. and its subsidiaries.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/* file generated from device description file (ATDF) version 2023-11-16T06:44:02Z */
#ifndef _PIC32CKSG01_HMATRIX2_COMPONENT_H_
#define _PIC32CKSG01_HMATRIX2_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR HMATRIX2                                     */
/* ************************************************************************** */

/* -------- HMATRIX2_PRAS : (HMATRIX2 Offset: 0x00) (R/W 32) Priority A for Slave -------- */
#define HMATRIX2_PRAS_RESETVALUE              _UINT32_(0x00)                                       /*  (HMATRIX2_PRAS) Priority A for Slave  Reset Value */

#define HMATRIX2_PRAS_M0PR_Pos                _UINT32_(0)                                          /* (HMATRIX2_PRAS) Master 0 Priority Position */
#define HMATRIX2_PRAS_M0PR_Msk                (_UINT32_(0x3) << HMATRIX2_PRAS_M0PR_Pos)            /* (HMATRIX2_PRAS) Master 0 Priority Mask */
#define HMATRIX2_PRAS_M0PR(value)             (HMATRIX2_PRAS_M0PR_Msk & (_UINT32_(value) << HMATRIX2_PRAS_M0PR_Pos)) /* Assigment of value for M0PR in the HMATRIX2_PRAS register */
#define HMATRIX2_PRAS_LQOSEN0_Pos             _UINT32_(2)                                          /* (HMATRIX2_PRAS) Latency Quality Of Service Enable for Master 0 Position */
#define HMATRIX2_PRAS_LQOSEN0_Msk             (_UINT32_(0x1) << HMATRIX2_PRAS_LQOSEN0_Pos)         /* (HMATRIX2_PRAS) Latency Quality Of Service Enable for Master 0 Mask */
#define HMATRIX2_PRAS_LQOSEN0(value)          (HMATRIX2_PRAS_LQOSEN0_Msk & (_UINT32_(value) << HMATRIX2_PRAS_LQOSEN0_Pos)) /* Assigment of value for LQOSEN0 in the HMATRIX2_PRAS register */
#define HMATRIX2_PRAS_M1PR_Pos                _UINT32_(4)                                          /* (HMATRIX2_PRAS) Master 1 Priority Position */
#define HMATRIX2_PRAS_M1PR_Msk                (_UINT32_(0x3) << HMATRIX2_PRAS_M1PR_Pos)            /* (HMATRIX2_PRAS) Master 1 Priority Mask */
#define HMATRIX2_PRAS_M1PR(value)             (HMATRIX2_PRAS_M1PR_Msk & (_UINT32_(value) << HMATRIX2_PRAS_M1PR_Pos)) /* Assigment of value for M1PR in the HMATRIX2_PRAS register */
#define HMATRIX2_PRAS_LQOSEN1_Pos             _UINT32_(6)                                          /* (HMATRIX2_PRAS) Latency Quality Of Service Enable for Master 1 Position */
#define HMATRIX2_PRAS_LQOSEN1_Msk             (_UINT32_(0x1) << HMATRIX2_PRAS_LQOSEN1_Pos)         /* (HMATRIX2_PRAS) Latency Quality Of Service Enable for Master 1 Mask */
#define HMATRIX2_PRAS_LQOSEN1(value)          (HMATRIX2_PRAS_LQOSEN1_Msk & (_UINT32_(value) << HMATRIX2_PRAS_LQOSEN1_Pos)) /* Assigment of value for LQOSEN1 in the HMATRIX2_PRAS register */
#define HMATRIX2_PRAS_M2PR_Pos                _UINT32_(8)                                          /* (HMATRIX2_PRAS) Master 2 Priority Position */
#define HMATRIX2_PRAS_M2PR_Msk                (_UINT32_(0x3) << HMATRIX2_PRAS_M2PR_Pos)            /* (HMATRIX2_PRAS) Master 2 Priority Mask */
#define HMATRIX2_PRAS_M2PR(value)             (HMATRIX2_PRAS_M2PR_Msk & (_UINT32_(value) << HMATRIX2_PRAS_M2PR_Pos)) /* Assigment of value for M2PR in the HMATRIX2_PRAS register */
#define HMATRIX2_PRAS_LQOSEN2_Pos             _UINT32_(10)                                         /* (HMATRIX2_PRAS) Latency Quality Of Service Enable for Master 2 Position */
#define HMATRIX2_PRAS_LQOSEN2_Msk             (_UINT32_(0x1) << HMATRIX2_PRAS_LQOSEN2_Pos)         /* (HMATRIX2_PRAS) Latency Quality Of Service Enable for Master 2 Mask */
#define HMATRIX2_PRAS_LQOSEN2(value)          (HMATRIX2_PRAS_LQOSEN2_Msk & (_UINT32_(value) << HMATRIX2_PRAS_LQOSEN2_Pos)) /* Assigment of value for LQOSEN2 in the HMATRIX2_PRAS register */
#define HMATRIX2_PRAS_M3PR_Pos                _UINT32_(12)                                         /* (HMATRIX2_PRAS) Master 3 Priority Position */
#define HMATRIX2_PRAS_M3PR_Msk                (_UINT32_(0x3) << HMATRIX2_PRAS_M3PR_Pos)            /* (HMATRIX2_PRAS) Master 3 Priority Mask */
#define HMATRIX2_PRAS_M3PR(value)             (HMATRIX2_PRAS_M3PR_Msk & (_UINT32_(value) << HMATRIX2_PRAS_M3PR_Pos)) /* Assigment of value for M3PR in the HMATRIX2_PRAS register */
#define HMATRIX2_PRAS_LQOSEN3_Pos             _UINT32_(14)                                         /* (HMATRIX2_PRAS) Latency Quality Of Service Enable for Master 3 Position */
#define HMATRIX2_PRAS_LQOSEN3_Msk             (_UINT32_(0x1) << HMATRIX2_PRAS_LQOSEN3_Pos)         /* (HMATRIX2_PRAS) Latency Quality Of Service Enable for Master 3 Mask */
#define HMATRIX2_PRAS_LQOSEN3(value)          (HMATRIX2_PRAS_LQOSEN3_Msk & (_UINT32_(value) << HMATRIX2_PRAS_LQOSEN3_Pos)) /* Assigment of value for LQOSEN3 in the HMATRIX2_PRAS register */
#define HMATRIX2_PRAS_M4PR_Pos                _UINT32_(16)                                         /* (HMATRIX2_PRAS) Master 4 Priority Position */
#define HMATRIX2_PRAS_M4PR_Msk                (_UINT32_(0x3) << HMATRIX2_PRAS_M4PR_Pos)            /* (HMATRIX2_PRAS) Master 4 Priority Mask */
#define HMATRIX2_PRAS_M4PR(value)             (HMATRIX2_PRAS_M4PR_Msk & (_UINT32_(value) << HMATRIX2_PRAS_M4PR_Pos)) /* Assigment of value for M4PR in the HMATRIX2_PRAS register */
#define HMATRIX2_PRAS_LQOSEN4_Pos             _UINT32_(18)                                         /* (HMATRIX2_PRAS) Latency Quality Of Service Enable for Master 4 Position */
#define HMATRIX2_PRAS_LQOSEN4_Msk             (_UINT32_(0x1) << HMATRIX2_PRAS_LQOSEN4_Pos)         /* (HMATRIX2_PRAS) Latency Quality Of Service Enable for Master 4 Mask */
#define HMATRIX2_PRAS_LQOSEN4(value)          (HMATRIX2_PRAS_LQOSEN4_Msk & (_UINT32_(value) << HMATRIX2_PRAS_LQOSEN4_Pos)) /* Assigment of value for LQOSEN4 in the HMATRIX2_PRAS register */
#define HMATRIX2_PRAS_M5PR_Pos                _UINT32_(20)                                         /* (HMATRIX2_PRAS) Master 5 Priority Position */
#define HMATRIX2_PRAS_M5PR_Msk                (_UINT32_(0x3) << HMATRIX2_PRAS_M5PR_Pos)            /* (HMATRIX2_PRAS) Master 5 Priority Mask */
#define HMATRIX2_PRAS_M5PR(value)             (HMATRIX2_PRAS_M5PR_Msk & (_UINT32_(value) << HMATRIX2_PRAS_M5PR_Pos)) /* Assigment of value for M5PR in the HMATRIX2_PRAS register */
#define HMATRIX2_PRAS_LQOSEN5_Pos             _UINT32_(22)                                         /* (HMATRIX2_PRAS) Latency Quality Of Service Enable for Master 5 Position */
#define HMATRIX2_PRAS_LQOSEN5_Msk             (_UINT32_(0x1) << HMATRIX2_PRAS_LQOSEN5_Pos)         /* (HMATRIX2_PRAS) Latency Quality Of Service Enable for Master 5 Mask */
#define HMATRIX2_PRAS_LQOSEN5(value)          (HMATRIX2_PRAS_LQOSEN5_Msk & (_UINT32_(value) << HMATRIX2_PRAS_LQOSEN5_Pos)) /* Assigment of value for LQOSEN5 in the HMATRIX2_PRAS register */
#define HMATRIX2_PRAS_M6PR_Pos                _UINT32_(24)                                         /* (HMATRIX2_PRAS) Master 6 Priority Position */
#define HMATRIX2_PRAS_M6PR_Msk                (_UINT32_(0x3) << HMATRIX2_PRAS_M6PR_Pos)            /* (HMATRIX2_PRAS) Master 6 Priority Mask */
#define HMATRIX2_PRAS_M6PR(value)             (HMATRIX2_PRAS_M6PR_Msk & (_UINT32_(value) << HMATRIX2_PRAS_M6PR_Pos)) /* Assigment of value for M6PR in the HMATRIX2_PRAS register */
#define HMATRIX2_PRAS_LQOSEN6_Pos             _UINT32_(26)                                         /* (HMATRIX2_PRAS) Latency Quality Of Service Enable for Master 6 Position */
#define HMATRIX2_PRAS_LQOSEN6_Msk             (_UINT32_(0x1) << HMATRIX2_PRAS_LQOSEN6_Pos)         /* (HMATRIX2_PRAS) Latency Quality Of Service Enable for Master 6 Mask */
#define HMATRIX2_PRAS_LQOSEN6(value)          (HMATRIX2_PRAS_LQOSEN6_Msk & (_UINT32_(value) << HMATRIX2_PRAS_LQOSEN6_Pos)) /* Assigment of value for LQOSEN6 in the HMATRIX2_PRAS register */
#define HMATRIX2_PRAS_M7PR_Pos                _UINT32_(28)                                         /* (HMATRIX2_PRAS) Master 7 Priority Position */
#define HMATRIX2_PRAS_M7PR_Msk                (_UINT32_(0x3) << HMATRIX2_PRAS_M7PR_Pos)            /* (HMATRIX2_PRAS) Master 7 Priority Mask */
#define HMATRIX2_PRAS_M7PR(value)             (HMATRIX2_PRAS_M7PR_Msk & (_UINT32_(value) << HMATRIX2_PRAS_M7PR_Pos)) /* Assigment of value for M7PR in the HMATRIX2_PRAS register */
#define HMATRIX2_PRAS_LQOSEN7_Pos             _UINT32_(30)                                         /* (HMATRIX2_PRAS) Latency Quality Of Service Enable for Master 7 Position */
#define HMATRIX2_PRAS_LQOSEN7_Msk             (_UINT32_(0x1) << HMATRIX2_PRAS_LQOSEN7_Pos)         /* (HMATRIX2_PRAS) Latency Quality Of Service Enable for Master 7 Mask */
#define HMATRIX2_PRAS_LQOSEN7(value)          (HMATRIX2_PRAS_LQOSEN7_Msk & (_UINT32_(value) << HMATRIX2_PRAS_LQOSEN7_Pos)) /* Assigment of value for LQOSEN7 in the HMATRIX2_PRAS register */
#define HMATRIX2_PRAS_Msk                     _UINT32_(0x77777777)                                 /* (HMATRIX2_PRAS) Register Mask  */


/* -------- HMATRIX2_PRBS : (HMATRIX2 Offset: 0x04) (R/W 32) Priority B for Slave -------- */
#define HMATRIX2_PRBS_RESETVALUE              _UINT32_(0x00)                                       /*  (HMATRIX2_PRBS) Priority B for Slave  Reset Value */

#define HMATRIX2_PRBS_M8PR_Pos                _UINT32_(0)                                          /* (HMATRIX2_PRBS) Master 8 Priority Position */
#define HMATRIX2_PRBS_M8PR_Msk                (_UINT32_(0x3) << HMATRIX2_PRBS_M8PR_Pos)            /* (HMATRIX2_PRBS) Master 8 Priority Mask */
#define HMATRIX2_PRBS_M8PR(value)             (HMATRIX2_PRBS_M8PR_Msk & (_UINT32_(value) << HMATRIX2_PRBS_M8PR_Pos)) /* Assigment of value for M8PR in the HMATRIX2_PRBS register */
#define HMATRIX2_PRBS_LQOSEN8_Pos             _UINT32_(2)                                          /* (HMATRIX2_PRBS) Latency Quality Of Service Enable for Master 8 Position */
#define HMATRIX2_PRBS_LQOSEN8_Msk             (_UINT32_(0x1) << HMATRIX2_PRBS_LQOSEN8_Pos)         /* (HMATRIX2_PRBS) Latency Quality Of Service Enable for Master 8 Mask */
#define HMATRIX2_PRBS_LQOSEN8(value)          (HMATRIX2_PRBS_LQOSEN8_Msk & (_UINT32_(value) << HMATRIX2_PRBS_LQOSEN8_Pos)) /* Assigment of value for LQOSEN8 in the HMATRIX2_PRBS register */
#define HMATRIX2_PRBS_M9PR_Pos                _UINT32_(4)                                          /* (HMATRIX2_PRBS) Master 9 Priority Position */
#define HMATRIX2_PRBS_M9PR_Msk                (_UINT32_(0x3) << HMATRIX2_PRBS_M9PR_Pos)            /* (HMATRIX2_PRBS) Master 9 Priority Mask */
#define HMATRIX2_PRBS_M9PR(value)             (HMATRIX2_PRBS_M9PR_Msk & (_UINT32_(value) << HMATRIX2_PRBS_M9PR_Pos)) /* Assigment of value for M9PR in the HMATRIX2_PRBS register */
#define HMATRIX2_PRBS_LQOSEN9_Pos             _UINT32_(6)                                          /* (HMATRIX2_PRBS) Latency Quality Of Service Enable for Master 9 Position */
#define HMATRIX2_PRBS_LQOSEN9_Msk             (_UINT32_(0x1) << HMATRIX2_PRBS_LQOSEN9_Pos)         /* (HMATRIX2_PRBS) Latency Quality Of Service Enable for Master 9 Mask */
#define HMATRIX2_PRBS_LQOSEN9(value)          (HMATRIX2_PRBS_LQOSEN9_Msk & (_UINT32_(value) << HMATRIX2_PRBS_LQOSEN9_Pos)) /* Assigment of value for LQOSEN9 in the HMATRIX2_PRBS register */
#define HMATRIX2_PRBS_M10PR_Pos               _UINT32_(8)                                          /* (HMATRIX2_PRBS) Master 10 Priority Position */
#define HMATRIX2_PRBS_M10PR_Msk               (_UINT32_(0x3) << HMATRIX2_PRBS_M10PR_Pos)           /* (HMATRIX2_PRBS) Master 10 Priority Mask */
#define HMATRIX2_PRBS_M10PR(value)            (HMATRIX2_PRBS_M10PR_Msk & (_UINT32_(value) << HMATRIX2_PRBS_M10PR_Pos)) /* Assigment of value for M10PR in the HMATRIX2_PRBS register */
#define HMATRIX2_PRBS_LQOSEN10_Pos            _UINT32_(10)                                         /* (HMATRIX2_PRBS) Latency Quality Of Service Enable for Master 10 Position */
#define HMATRIX2_PRBS_LQOSEN10_Msk            (_UINT32_(0x1) << HMATRIX2_PRBS_LQOSEN10_Pos)        /* (HMATRIX2_PRBS) Latency Quality Of Service Enable for Master 10 Mask */
#define HMATRIX2_PRBS_LQOSEN10(value)         (HMATRIX2_PRBS_LQOSEN10_Msk & (_UINT32_(value) << HMATRIX2_PRBS_LQOSEN10_Pos)) /* Assigment of value for LQOSEN10 in the HMATRIX2_PRBS register */
#define HMATRIX2_PRBS_M11PR_Pos               _UINT32_(12)                                         /* (HMATRIX2_PRBS) Master 11 Priority Position */
#define HMATRIX2_PRBS_M11PR_Msk               (_UINT32_(0x3) << HMATRIX2_PRBS_M11PR_Pos)           /* (HMATRIX2_PRBS) Master 11 Priority Mask */
#define HMATRIX2_PRBS_M11PR(value)            (HMATRIX2_PRBS_M11PR_Msk & (_UINT32_(value) << HMATRIX2_PRBS_M11PR_Pos)) /* Assigment of value for M11PR in the HMATRIX2_PRBS register */
#define HMATRIX2_PRBS_LQOSEN11_Pos            _UINT32_(14)                                         /* (HMATRIX2_PRBS) Latency Quality Of Service Enable for Master 11 Position */
#define HMATRIX2_PRBS_LQOSEN11_Msk            (_UINT32_(0x1) << HMATRIX2_PRBS_LQOSEN11_Pos)        /* (HMATRIX2_PRBS) Latency Quality Of Service Enable for Master 11 Mask */
#define HMATRIX2_PRBS_LQOSEN11(value)         (HMATRIX2_PRBS_LQOSEN11_Msk & (_UINT32_(value) << HMATRIX2_PRBS_LQOSEN11_Pos)) /* Assigment of value for LQOSEN11 in the HMATRIX2_PRBS register */
#define HMATRIX2_PRBS_M12PR_Pos               _UINT32_(16)                                         /* (HMATRIX2_PRBS) Master 12 Priority Position */
#define HMATRIX2_PRBS_M12PR_Msk               (_UINT32_(0x3) << HMATRIX2_PRBS_M12PR_Pos)           /* (HMATRIX2_PRBS) Master 12 Priority Mask */
#define HMATRIX2_PRBS_M12PR(value)            (HMATRIX2_PRBS_M12PR_Msk & (_UINT32_(value) << HMATRIX2_PRBS_M12PR_Pos)) /* Assigment of value for M12PR in the HMATRIX2_PRBS register */
#define HMATRIX2_PRBS_LQOSEN12_Pos            _UINT32_(18)                                         /* (HMATRIX2_PRBS) Latency Quality Of Service Enable for Master 12 Position */
#define HMATRIX2_PRBS_LQOSEN12_Msk            (_UINT32_(0x1) << HMATRIX2_PRBS_LQOSEN12_Pos)        /* (HMATRIX2_PRBS) Latency Quality Of Service Enable for Master 12 Mask */
#define HMATRIX2_PRBS_LQOSEN12(value)         (HMATRIX2_PRBS_LQOSEN12_Msk & (_UINT32_(value) << HMATRIX2_PRBS_LQOSEN12_Pos)) /* Assigment of value for LQOSEN12 in the HMATRIX2_PRBS register */
#define HMATRIX2_PRBS_M13PR_Pos               _UINT32_(20)                                         /* (HMATRIX2_PRBS) Master 13 Priority Position */
#define HMATRIX2_PRBS_M13PR_Msk               (_UINT32_(0x3) << HMATRIX2_PRBS_M13PR_Pos)           /* (HMATRIX2_PRBS) Master 13 Priority Mask */
#define HMATRIX2_PRBS_M13PR(value)            (HMATRIX2_PRBS_M13PR_Msk & (_UINT32_(value) << HMATRIX2_PRBS_M13PR_Pos)) /* Assigment of value for M13PR in the HMATRIX2_PRBS register */
#define HMATRIX2_PRBS_LQOSEN13_Pos            _UINT32_(22)                                         /* (HMATRIX2_PRBS) Latency Quality Of Service Enable for Master 13 Position */
#define HMATRIX2_PRBS_LQOSEN13_Msk            (_UINT32_(0x1) << HMATRIX2_PRBS_LQOSEN13_Pos)        /* (HMATRIX2_PRBS) Latency Quality Of Service Enable for Master 13 Mask */
#define HMATRIX2_PRBS_LQOSEN13(value)         (HMATRIX2_PRBS_LQOSEN13_Msk & (_UINT32_(value) << HMATRIX2_PRBS_LQOSEN13_Pos)) /* Assigment of value for LQOSEN13 in the HMATRIX2_PRBS register */
#define HMATRIX2_PRBS_M14PR_Pos               _UINT32_(24)                                         /* (HMATRIX2_PRBS) Master 14 Priority Position */
#define HMATRIX2_PRBS_M14PR_Msk               (_UINT32_(0x3) << HMATRIX2_PRBS_M14PR_Pos)           /* (HMATRIX2_PRBS) Master 14 Priority Mask */
#define HMATRIX2_PRBS_M14PR(value)            (HMATRIX2_PRBS_M14PR_Msk & (_UINT32_(value) << HMATRIX2_PRBS_M14PR_Pos)) /* Assigment of value for M14PR in the HMATRIX2_PRBS register */
#define HMATRIX2_PRBS_LQOSEN14_Pos            _UINT32_(26)                                         /* (HMATRIX2_PRBS) Latency Quality Of Service Enable for Master 14 Position */
#define HMATRIX2_PRBS_LQOSEN14_Msk            (_UINT32_(0x1) << HMATRIX2_PRBS_LQOSEN14_Pos)        /* (HMATRIX2_PRBS) Latency Quality Of Service Enable for Master 14 Mask */
#define HMATRIX2_PRBS_LQOSEN14(value)         (HMATRIX2_PRBS_LQOSEN14_Msk & (_UINT32_(value) << HMATRIX2_PRBS_LQOSEN14_Pos)) /* Assigment of value for LQOSEN14 in the HMATRIX2_PRBS register */
#define HMATRIX2_PRBS_M15PR_Pos               _UINT32_(28)                                         /* (HMATRIX2_PRBS) Master 15 Priority Position */
#define HMATRIX2_PRBS_M15PR_Msk               (_UINT32_(0x3) << HMATRIX2_PRBS_M15PR_Pos)           /* (HMATRIX2_PRBS) Master 15 Priority Mask */
#define HMATRIX2_PRBS_M15PR(value)            (HMATRIX2_PRBS_M15PR_Msk & (_UINT32_(value) << HMATRIX2_PRBS_M15PR_Pos)) /* Assigment of value for M15PR in the HMATRIX2_PRBS register */
#define HMATRIX2_PRBS_LQOSEN15_Pos            _UINT32_(30)                                         /* (HMATRIX2_PRBS) Latency Quality Of Service Enable for Master 15 Position */
#define HMATRIX2_PRBS_LQOSEN15_Msk            (_UINT32_(0x1) << HMATRIX2_PRBS_LQOSEN15_Pos)        /* (HMATRIX2_PRBS) Latency Quality Of Service Enable for Master 15 Mask */
#define HMATRIX2_PRBS_LQOSEN15(value)         (HMATRIX2_PRBS_LQOSEN15_Msk & (_UINT32_(value) << HMATRIX2_PRBS_LQOSEN15_Pos)) /* Assigment of value for LQOSEN15 in the HMATRIX2_PRBS register */
#define HMATRIX2_PRBS_Msk                     _UINT32_(0x77777777)                                 /* (HMATRIX2_PRBS) Register Mask  */


/* -------- HMATRIX2_MCFG : (HMATRIX2 Offset: 0x00) (R/W 32) Master Configuration -------- */
#define HMATRIX2_MCFG_RESETVALUE              _UINT32_(0x02)                                       /*  (HMATRIX2_MCFG) Master Configuration  Reset Value */

#define HMATRIX2_MCFG_ULBT_Pos                _UINT32_(0)                                          /* (HMATRIX2_MCFG) Undefined Length Burst Type Position */
#define HMATRIX2_MCFG_ULBT_Msk                (_UINT32_(0x7) << HMATRIX2_MCFG_ULBT_Pos)            /* (HMATRIX2_MCFG) Undefined Length Burst Type Mask */
#define HMATRIX2_MCFG_ULBT(value)             (HMATRIX2_MCFG_ULBT_Msk & (_UINT32_(value) << HMATRIX2_MCFG_ULBT_Pos)) /* Assigment of value for ULBT in the HMATRIX2_MCFG register */
#define   HMATRIX2_MCFG_ULBT_INFINITE_Val     _UINT32_(0x0)                                        /* (HMATRIX2_MCFG) Infinite Length  */
#define   HMATRIX2_MCFG_ULBT_SINGLE_Val       _UINT32_(0x1)                                        /* (HMATRIX2_MCFG) Single Access  */
#define   HMATRIX2_MCFG_ULBT_FOUR_BEAT_Val    _UINT32_(0x2)                                        /* (HMATRIX2_MCFG) Four Beat Burst  */
#define   HMATRIX2_MCFG_ULBT_EIGHT_BEAT_Val   _UINT32_(0x3)                                        /* (HMATRIX2_MCFG) Eight Beat Burst  */
#define   HMATRIX2_MCFG_ULBT_SIXTEEN_BEAT_Val _UINT32_(0x4)                                        /* (HMATRIX2_MCFG) Sixteen Beat Burst  */
#define HMATRIX2_MCFG_ULBT_INFINITE           (HMATRIX2_MCFG_ULBT_INFINITE_Val << HMATRIX2_MCFG_ULBT_Pos) /* (HMATRIX2_MCFG) Infinite Length Position  */
#define HMATRIX2_MCFG_ULBT_SINGLE             (HMATRIX2_MCFG_ULBT_SINGLE_Val << HMATRIX2_MCFG_ULBT_Pos) /* (HMATRIX2_MCFG) Single Access Position  */
#define HMATRIX2_MCFG_ULBT_FOUR_BEAT          (HMATRIX2_MCFG_ULBT_FOUR_BEAT_Val << HMATRIX2_MCFG_ULBT_Pos) /* (HMATRIX2_MCFG) Four Beat Burst Position  */
#define HMATRIX2_MCFG_ULBT_EIGHT_BEAT         (HMATRIX2_MCFG_ULBT_EIGHT_BEAT_Val << HMATRIX2_MCFG_ULBT_Pos) /* (HMATRIX2_MCFG) Eight Beat Burst Position  */
#define HMATRIX2_MCFG_ULBT_SIXTEEN_BEAT       (HMATRIX2_MCFG_ULBT_SIXTEEN_BEAT_Val << HMATRIX2_MCFG_ULBT_Pos) /* (HMATRIX2_MCFG) Sixteen Beat Burst Position  */
#define HMATRIX2_MCFG_Msk                     _UINT32_(0x00000007)                                 /* (HMATRIX2_MCFG) Register Mask  */


/* -------- HMATRIX2_SCFG : (HMATRIX2 Offset: 0x40) (R/W 32) Slave Configuration -------- */
#define HMATRIX2_SCFG_RESETVALUE              _UINT32_(0x10)                                       /*  (HMATRIX2_SCFG) Slave Configuration  Reset Value */

#define HMATRIX2_SCFG_SLOT_CYCLE_Pos          _UINT32_(0)                                          /* (HMATRIX2_SCFG) Maximum Number of Allowed Cycles for a Burst Position */
#define HMATRIX2_SCFG_SLOT_CYCLE_Msk          (_UINT32_(0x1FF) << HMATRIX2_SCFG_SLOT_CYCLE_Pos)    /* (HMATRIX2_SCFG) Maximum Number of Allowed Cycles for a Burst Mask */
#define HMATRIX2_SCFG_SLOT_CYCLE(value)       (HMATRIX2_SCFG_SLOT_CYCLE_Msk & (_UINT32_(value) << HMATRIX2_SCFG_SLOT_CYCLE_Pos)) /* Assigment of value for SLOT_CYCLE in the HMATRIX2_SCFG register */
#define HMATRIX2_SCFG_DEFMSTR_TYPE_Pos        _UINT32_(16)                                         /* (HMATRIX2_SCFG) Default Master Type Position */
#define HMATRIX2_SCFG_DEFMSTR_TYPE_Msk        (_UINT32_(0x3) << HMATRIX2_SCFG_DEFMSTR_TYPE_Pos)    /* (HMATRIX2_SCFG) Default Master Type Mask */
#define HMATRIX2_SCFG_DEFMSTR_TYPE(value)     (HMATRIX2_SCFG_DEFMSTR_TYPE_Msk & (_UINT32_(value) << HMATRIX2_SCFG_DEFMSTR_TYPE_Pos)) /* Assigment of value for DEFMSTR_TYPE in the HMATRIX2_SCFG register */
#define   HMATRIX2_SCFG_DEFMSTR_TYPE_NO_DEFAULT_Val _UINT32_(0x0)                                        /* (HMATRIX2_SCFG) No Default Master. At the end of current slave access, if no other master request is pending, the slave is deconnected from all masters. This resusts in having a one cycle latency for the first transfer of a burst.  */
#define   HMATRIX2_SCFG_DEFMSTR_TYPE_LAST_DEFAULT_Val _UINT32_(0x1)                                        /* (HMATRIX2_SCFG) Last Default Master At the end of current slave access, if no other master request is pending, the slave stay connected with the last master havingaccessed it.This resusts in not having the one cycle latency when the last master re-trying access on the slave.  */
#define   HMATRIX2_SCFG_DEFMSTR_TYPE_FIXED_DEFAULT_Val _UINT32_(0x2)                                        /* (HMATRIX2_SCFG) Fixed Default Master At the end of current slave access, if no other master request is pending, the slave connects with fixed master which numberis in FIXED_DEFMSTR register.This resusts in not having the one cycle latency when the fixed master re-trying access on the slave.  */
#define HMATRIX2_SCFG_DEFMSTR_TYPE_NO_DEFAULT (HMATRIX2_SCFG_DEFMSTR_TYPE_NO_DEFAULT_Val << HMATRIX2_SCFG_DEFMSTR_TYPE_Pos) /* (HMATRIX2_SCFG) No Default Master. At the end of current slave access, if no other master request is pending, the slave is deconnected from all masters. This resusts in having a one cycle latency for the first transfer of a burst. Position  */
#define HMATRIX2_SCFG_DEFMSTR_TYPE_LAST_DEFAULT (HMATRIX2_SCFG_DEFMSTR_TYPE_LAST_DEFAULT_Val << HMATRIX2_SCFG_DEFMSTR_TYPE_Pos) /* (HMATRIX2_SCFG) Last Default Master At the end of current slave access, if no other master request is pending, the slave stay connected with the last master havingaccessed it.This resusts in not having the one cycle latency when the last master re-trying access on the slave. Position  */
#define HMATRIX2_SCFG_DEFMSTR_TYPE_FIXED_DEFAULT (HMATRIX2_SCFG_DEFMSTR_TYPE_FIXED_DEFAULT_Val << HMATRIX2_SCFG_DEFMSTR_TYPE_Pos) /* (HMATRIX2_SCFG) Fixed Default Master At the end of current slave access, if no other master request is pending, the slave connects with fixed master which numberis in FIXED_DEFMSTR register.This resusts in not having the one cycle latency when the fixed master re-trying access on the slave. Position  */
#define HMATRIX2_SCFG_FIXED_DEFMSTR_Pos       _UINT32_(18)                                         /* (HMATRIX2_SCFG) Fixed Index of Default Master Position */
#define HMATRIX2_SCFG_FIXED_DEFMSTR_Msk       (_UINT32_(0xF) << HMATRIX2_SCFG_FIXED_DEFMSTR_Pos)   /* (HMATRIX2_SCFG) Fixed Index of Default Master Mask */
#define HMATRIX2_SCFG_FIXED_DEFMSTR(value)    (HMATRIX2_SCFG_FIXED_DEFMSTR_Msk & (_UINT32_(value) << HMATRIX2_SCFG_FIXED_DEFMSTR_Pos)) /* Assigment of value for FIXED_DEFMSTR in the HMATRIX2_SCFG register */
#define HMATRIX2_SCFG_Msk                     _UINT32_(0x003F01FF)                                 /* (HMATRIX2_SCFG) Register Mask  */


/* -------- HMATRIX2_MRCR : (HMATRIX2 Offset: 0x100) (R/W 32) Master Remap Control -------- */
#define HMATRIX2_MRCR_RESETVALUE              _UINT32_(0x00)                                       /*  (HMATRIX2_MRCR) Master Remap Control  Reset Value */

#define HMATRIX2_MRCR_RCB0_Pos                _UINT32_(0)                                          /* (HMATRIX2_MRCR) Remap Command Bit for Master 0 Position */
#define HMATRIX2_MRCR_RCB0_Msk                (_UINT32_(0x1) << HMATRIX2_MRCR_RCB0_Pos)            /* (HMATRIX2_MRCR) Remap Command Bit for Master 0 Mask */
#define HMATRIX2_MRCR_RCB0(value)             (HMATRIX2_MRCR_RCB0_Msk & (_UINT32_(value) << HMATRIX2_MRCR_RCB0_Pos)) /* Assigment of value for RCB0 in the HMATRIX2_MRCR register */
#define   HMATRIX2_MRCR_RCB0_DIS_Val          _UINT32_(0x0)                                        /* (HMATRIX2_MRCR) Disable remapped address decoding for master  */
#define   HMATRIX2_MRCR_RCB0_ENA_Val          _UINT32_(0x1)                                        /* (HMATRIX2_MRCR) Enable remapped address decoding for master  */
#define HMATRIX2_MRCR_RCB0_DIS                (HMATRIX2_MRCR_RCB0_DIS_Val << HMATRIX2_MRCR_RCB0_Pos) /* (HMATRIX2_MRCR) Disable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB0_ENA                (HMATRIX2_MRCR_RCB0_ENA_Val << HMATRIX2_MRCR_RCB0_Pos) /* (HMATRIX2_MRCR) Enable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB1_Pos                _UINT32_(1)                                          /* (HMATRIX2_MRCR) Remap Command Bit for Master 1 Position */
#define HMATRIX2_MRCR_RCB1_Msk                (_UINT32_(0x1) << HMATRIX2_MRCR_RCB1_Pos)            /* (HMATRIX2_MRCR) Remap Command Bit for Master 1 Mask */
#define HMATRIX2_MRCR_RCB1(value)             (HMATRIX2_MRCR_RCB1_Msk & (_UINT32_(value) << HMATRIX2_MRCR_RCB1_Pos)) /* Assigment of value for RCB1 in the HMATRIX2_MRCR register */
#define   HMATRIX2_MRCR_RCB1_DIS_Val          _UINT32_(0x0)                                        /* (HMATRIX2_MRCR) Disable remapped address decoding for master  */
#define   HMATRIX2_MRCR_RCB1_ENA_Val          _UINT32_(0x1)                                        /* (HMATRIX2_MRCR) Enable remapped address decoding for master  */
#define HMATRIX2_MRCR_RCB1_DIS                (HMATRIX2_MRCR_RCB1_DIS_Val << HMATRIX2_MRCR_RCB1_Pos) /* (HMATRIX2_MRCR) Disable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB1_ENA                (HMATRIX2_MRCR_RCB1_ENA_Val << HMATRIX2_MRCR_RCB1_Pos) /* (HMATRIX2_MRCR) Enable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB2_Pos                _UINT32_(2)                                          /* (HMATRIX2_MRCR) Remap Command Bit for Master 2 Position */
#define HMATRIX2_MRCR_RCB2_Msk                (_UINT32_(0x1) << HMATRIX2_MRCR_RCB2_Pos)            /* (HMATRIX2_MRCR) Remap Command Bit for Master 2 Mask */
#define HMATRIX2_MRCR_RCB2(value)             (HMATRIX2_MRCR_RCB2_Msk & (_UINT32_(value) << HMATRIX2_MRCR_RCB2_Pos)) /* Assigment of value for RCB2 in the HMATRIX2_MRCR register */
#define   HMATRIX2_MRCR_RCB2_DIS_Val          _UINT32_(0x0)                                        /* (HMATRIX2_MRCR) Disable remapped address decoding for master  */
#define   HMATRIX2_MRCR_RCB2_ENA_Val          _UINT32_(0x1)                                        /* (HMATRIX2_MRCR) Enable remapped address decoding for master  */
#define HMATRIX2_MRCR_RCB2_DIS                (HMATRIX2_MRCR_RCB2_DIS_Val << HMATRIX2_MRCR_RCB2_Pos) /* (HMATRIX2_MRCR) Disable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB2_ENA                (HMATRIX2_MRCR_RCB2_ENA_Val << HMATRIX2_MRCR_RCB2_Pos) /* (HMATRIX2_MRCR) Enable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB3_Pos                _UINT32_(3)                                          /* (HMATRIX2_MRCR) Remap Command Bit for Master 3 Position */
#define HMATRIX2_MRCR_RCB3_Msk                (_UINT32_(0x1) << HMATRIX2_MRCR_RCB3_Pos)            /* (HMATRIX2_MRCR) Remap Command Bit for Master 3 Mask */
#define HMATRIX2_MRCR_RCB3(value)             (HMATRIX2_MRCR_RCB3_Msk & (_UINT32_(value) << HMATRIX2_MRCR_RCB3_Pos)) /* Assigment of value for RCB3 in the HMATRIX2_MRCR register */
#define   HMATRIX2_MRCR_RCB3_DIS_Val          _UINT32_(0x0)                                        /* (HMATRIX2_MRCR) Disable remapped address decoding for master  */
#define   HMATRIX2_MRCR_RCB3_ENA_Val          _UINT32_(0x1)                                        /* (HMATRIX2_MRCR) Enable remapped address decoding for master  */
#define HMATRIX2_MRCR_RCB3_DIS                (HMATRIX2_MRCR_RCB3_DIS_Val << HMATRIX2_MRCR_RCB3_Pos) /* (HMATRIX2_MRCR) Disable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB3_ENA                (HMATRIX2_MRCR_RCB3_ENA_Val << HMATRIX2_MRCR_RCB3_Pos) /* (HMATRIX2_MRCR) Enable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB4_Pos                _UINT32_(4)                                          /* (HMATRIX2_MRCR) Remap Command Bit for Master 4 Position */
#define HMATRIX2_MRCR_RCB4_Msk                (_UINT32_(0x1) << HMATRIX2_MRCR_RCB4_Pos)            /* (HMATRIX2_MRCR) Remap Command Bit for Master 4 Mask */
#define HMATRIX2_MRCR_RCB4(value)             (HMATRIX2_MRCR_RCB4_Msk & (_UINT32_(value) << HMATRIX2_MRCR_RCB4_Pos)) /* Assigment of value for RCB4 in the HMATRIX2_MRCR register */
#define   HMATRIX2_MRCR_RCB4_DIS_Val          _UINT32_(0x0)                                        /* (HMATRIX2_MRCR) Disable remapped address decoding for master  */
#define   HMATRIX2_MRCR_RCB4_ENA_Val          _UINT32_(0x1)                                        /* (HMATRIX2_MRCR) Enable remapped address decoding for master  */
#define HMATRIX2_MRCR_RCB4_DIS                (HMATRIX2_MRCR_RCB4_DIS_Val << HMATRIX2_MRCR_RCB4_Pos) /* (HMATRIX2_MRCR) Disable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB4_ENA                (HMATRIX2_MRCR_RCB4_ENA_Val << HMATRIX2_MRCR_RCB4_Pos) /* (HMATRIX2_MRCR) Enable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB5_Pos                _UINT32_(5)                                          /* (HMATRIX2_MRCR) Remap Command Bit for Master 5 Position */
#define HMATRIX2_MRCR_RCB5_Msk                (_UINT32_(0x1) << HMATRIX2_MRCR_RCB5_Pos)            /* (HMATRIX2_MRCR) Remap Command Bit for Master 5 Mask */
#define HMATRIX2_MRCR_RCB5(value)             (HMATRIX2_MRCR_RCB5_Msk & (_UINT32_(value) << HMATRIX2_MRCR_RCB5_Pos)) /* Assigment of value for RCB5 in the HMATRIX2_MRCR register */
#define   HMATRIX2_MRCR_RCB5_DIS_Val          _UINT32_(0x0)                                        /* (HMATRIX2_MRCR) Disable remapped address decoding for master  */
#define   HMATRIX2_MRCR_RCB5_ENA_Val          _UINT32_(0x1)                                        /* (HMATRIX2_MRCR) Enable remapped address decoding for master  */
#define HMATRIX2_MRCR_RCB5_DIS                (HMATRIX2_MRCR_RCB5_DIS_Val << HMATRIX2_MRCR_RCB5_Pos) /* (HMATRIX2_MRCR) Disable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB5_ENA                (HMATRIX2_MRCR_RCB5_ENA_Val << HMATRIX2_MRCR_RCB5_Pos) /* (HMATRIX2_MRCR) Enable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB6_Pos                _UINT32_(6)                                          /* (HMATRIX2_MRCR) Remap Command Bit for Master 6 Position */
#define HMATRIX2_MRCR_RCB6_Msk                (_UINT32_(0x1) << HMATRIX2_MRCR_RCB6_Pos)            /* (HMATRIX2_MRCR) Remap Command Bit for Master 6 Mask */
#define HMATRIX2_MRCR_RCB6(value)             (HMATRIX2_MRCR_RCB6_Msk & (_UINT32_(value) << HMATRIX2_MRCR_RCB6_Pos)) /* Assigment of value for RCB6 in the HMATRIX2_MRCR register */
#define   HMATRIX2_MRCR_RCB6_DIS_Val          _UINT32_(0x0)                                        /* (HMATRIX2_MRCR) Disable remapped address decoding for master  */
#define   HMATRIX2_MRCR_RCB6_ENA_Val          _UINT32_(0x1)                                        /* (HMATRIX2_MRCR) Enable remapped address decoding for master  */
#define HMATRIX2_MRCR_RCB6_DIS                (HMATRIX2_MRCR_RCB6_DIS_Val << HMATRIX2_MRCR_RCB6_Pos) /* (HMATRIX2_MRCR) Disable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB6_ENA                (HMATRIX2_MRCR_RCB6_ENA_Val << HMATRIX2_MRCR_RCB6_Pos) /* (HMATRIX2_MRCR) Enable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB7_Pos                _UINT32_(7)                                          /* (HMATRIX2_MRCR) Remap Command Bit for Master 7 Position */
#define HMATRIX2_MRCR_RCB7_Msk                (_UINT32_(0x1) << HMATRIX2_MRCR_RCB7_Pos)            /* (HMATRIX2_MRCR) Remap Command Bit for Master 7 Mask */
#define HMATRIX2_MRCR_RCB7(value)             (HMATRIX2_MRCR_RCB7_Msk & (_UINT32_(value) << HMATRIX2_MRCR_RCB7_Pos)) /* Assigment of value for RCB7 in the HMATRIX2_MRCR register */
#define   HMATRIX2_MRCR_RCB7_DIS_Val          _UINT32_(0x0)                                        /* (HMATRIX2_MRCR) Disable remapped address decoding for master  */
#define   HMATRIX2_MRCR_RCB7_ENA_Val          _UINT32_(0x1)                                        /* (HMATRIX2_MRCR) Enable remapped address decoding for master  */
#define HMATRIX2_MRCR_RCB7_DIS                (HMATRIX2_MRCR_RCB7_DIS_Val << HMATRIX2_MRCR_RCB7_Pos) /* (HMATRIX2_MRCR) Disable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB7_ENA                (HMATRIX2_MRCR_RCB7_ENA_Val << HMATRIX2_MRCR_RCB7_Pos) /* (HMATRIX2_MRCR) Enable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB8_Pos                _UINT32_(8)                                          /* (HMATRIX2_MRCR) Remap Command Bit for Master 8 Position */
#define HMATRIX2_MRCR_RCB8_Msk                (_UINT32_(0x1) << HMATRIX2_MRCR_RCB8_Pos)            /* (HMATRIX2_MRCR) Remap Command Bit for Master 8 Mask */
#define HMATRIX2_MRCR_RCB8(value)             (HMATRIX2_MRCR_RCB8_Msk & (_UINT32_(value) << HMATRIX2_MRCR_RCB8_Pos)) /* Assigment of value for RCB8 in the HMATRIX2_MRCR register */
#define   HMATRIX2_MRCR_RCB8_DIS_Val          _UINT32_(0x0)                                        /* (HMATRIX2_MRCR) Disable remapped address decoding for master  */
#define   HMATRIX2_MRCR_RCB8_ENA_Val          _UINT32_(0x1)                                        /* (HMATRIX2_MRCR) Enable remapped address decoding for master  */
#define HMATRIX2_MRCR_RCB8_DIS                (HMATRIX2_MRCR_RCB8_DIS_Val << HMATRIX2_MRCR_RCB8_Pos) /* (HMATRIX2_MRCR) Disable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB8_ENA                (HMATRIX2_MRCR_RCB8_ENA_Val << HMATRIX2_MRCR_RCB8_Pos) /* (HMATRIX2_MRCR) Enable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB9_Pos                _UINT32_(9)                                          /* (HMATRIX2_MRCR) Remap Command Bit for Master 9 Position */
#define HMATRIX2_MRCR_RCB9_Msk                (_UINT32_(0x1) << HMATRIX2_MRCR_RCB9_Pos)            /* (HMATRIX2_MRCR) Remap Command Bit for Master 9 Mask */
#define HMATRIX2_MRCR_RCB9(value)             (HMATRIX2_MRCR_RCB9_Msk & (_UINT32_(value) << HMATRIX2_MRCR_RCB9_Pos)) /* Assigment of value for RCB9 in the HMATRIX2_MRCR register */
#define   HMATRIX2_MRCR_RCB9_DIS_Val          _UINT32_(0x0)                                        /* (HMATRIX2_MRCR) Disable remapped address decoding for master  */
#define   HMATRIX2_MRCR_RCB9_ENA_Val          _UINT32_(0x1)                                        /* (HMATRIX2_MRCR) Enable remapped address decoding for master  */
#define HMATRIX2_MRCR_RCB9_DIS                (HMATRIX2_MRCR_RCB9_DIS_Val << HMATRIX2_MRCR_RCB9_Pos) /* (HMATRIX2_MRCR) Disable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB9_ENA                (HMATRIX2_MRCR_RCB9_ENA_Val << HMATRIX2_MRCR_RCB9_Pos) /* (HMATRIX2_MRCR) Enable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB10_Pos               _UINT32_(10)                                         /* (HMATRIX2_MRCR) Remap Command Bit for Master 10 Position */
#define HMATRIX2_MRCR_RCB10_Msk               (_UINT32_(0x1) << HMATRIX2_MRCR_RCB10_Pos)           /* (HMATRIX2_MRCR) Remap Command Bit for Master 10 Mask */
#define HMATRIX2_MRCR_RCB10(value)            (HMATRIX2_MRCR_RCB10_Msk & (_UINT32_(value) << HMATRIX2_MRCR_RCB10_Pos)) /* Assigment of value for RCB10 in the HMATRIX2_MRCR register */
#define   HMATRIX2_MRCR_RCB10_DIS_Val         _UINT32_(0x0)                                        /* (HMATRIX2_MRCR) Disable remapped address decoding for master  */
#define   HMATRIX2_MRCR_RCB10_ENA_Val         _UINT32_(0x1)                                        /* (HMATRIX2_MRCR) Enable remapped address decoding for master  */
#define HMATRIX2_MRCR_RCB10_DIS               (HMATRIX2_MRCR_RCB10_DIS_Val << HMATRIX2_MRCR_RCB10_Pos) /* (HMATRIX2_MRCR) Disable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB10_ENA               (HMATRIX2_MRCR_RCB10_ENA_Val << HMATRIX2_MRCR_RCB10_Pos) /* (HMATRIX2_MRCR) Enable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB11_Pos               _UINT32_(11)                                         /* (HMATRIX2_MRCR) Remap Command Bit for Master 11 Position */
#define HMATRIX2_MRCR_RCB11_Msk               (_UINT32_(0x1) << HMATRIX2_MRCR_RCB11_Pos)           /* (HMATRIX2_MRCR) Remap Command Bit for Master 11 Mask */
#define HMATRIX2_MRCR_RCB11(value)            (HMATRIX2_MRCR_RCB11_Msk & (_UINT32_(value) << HMATRIX2_MRCR_RCB11_Pos)) /* Assigment of value for RCB11 in the HMATRIX2_MRCR register */
#define   HMATRIX2_MRCR_RCB11_DIS_Val         _UINT32_(0x0)                                        /* (HMATRIX2_MRCR) Disable remapped address decoding for master  */
#define   HMATRIX2_MRCR_RCB11_ENA_Val         _UINT32_(0x1)                                        /* (HMATRIX2_MRCR) Enable remapped address decoding for master  */
#define HMATRIX2_MRCR_RCB11_DIS               (HMATRIX2_MRCR_RCB11_DIS_Val << HMATRIX2_MRCR_RCB11_Pos) /* (HMATRIX2_MRCR) Disable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB11_ENA               (HMATRIX2_MRCR_RCB11_ENA_Val << HMATRIX2_MRCR_RCB11_Pos) /* (HMATRIX2_MRCR) Enable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB12_Pos               _UINT32_(12)                                         /* (HMATRIX2_MRCR) Remap Command Bit for Master 12 Position */
#define HMATRIX2_MRCR_RCB12_Msk               (_UINT32_(0x1) << HMATRIX2_MRCR_RCB12_Pos)           /* (HMATRIX2_MRCR) Remap Command Bit for Master 12 Mask */
#define HMATRIX2_MRCR_RCB12(value)            (HMATRIX2_MRCR_RCB12_Msk & (_UINT32_(value) << HMATRIX2_MRCR_RCB12_Pos)) /* Assigment of value for RCB12 in the HMATRIX2_MRCR register */
#define   HMATRIX2_MRCR_RCB12_DIS_Val         _UINT32_(0x0)                                        /* (HMATRIX2_MRCR) Disable remapped address decoding for master  */
#define   HMATRIX2_MRCR_RCB12_ENA_Val         _UINT32_(0x1)                                        /* (HMATRIX2_MRCR) Enable remapped address decoding for master  */
#define HMATRIX2_MRCR_RCB12_DIS               (HMATRIX2_MRCR_RCB12_DIS_Val << HMATRIX2_MRCR_RCB12_Pos) /* (HMATRIX2_MRCR) Disable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB12_ENA               (HMATRIX2_MRCR_RCB12_ENA_Val << HMATRIX2_MRCR_RCB12_Pos) /* (HMATRIX2_MRCR) Enable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB13_Pos               _UINT32_(13)                                         /* (HMATRIX2_MRCR) Remap Command Bit for Master 13 Position */
#define HMATRIX2_MRCR_RCB13_Msk               (_UINT32_(0x1) << HMATRIX2_MRCR_RCB13_Pos)           /* (HMATRIX2_MRCR) Remap Command Bit for Master 13 Mask */
#define HMATRIX2_MRCR_RCB13(value)            (HMATRIX2_MRCR_RCB13_Msk & (_UINT32_(value) << HMATRIX2_MRCR_RCB13_Pos)) /* Assigment of value for RCB13 in the HMATRIX2_MRCR register */
#define   HMATRIX2_MRCR_RCB13_DIS_Val         _UINT32_(0x0)                                        /* (HMATRIX2_MRCR) Disable remapped address decoding for master  */
#define   HMATRIX2_MRCR_RCB13_ENA_Val         _UINT32_(0x1)                                        /* (HMATRIX2_MRCR) Enable remapped address decoding for master  */
#define HMATRIX2_MRCR_RCB13_DIS               (HMATRIX2_MRCR_RCB13_DIS_Val << HMATRIX2_MRCR_RCB13_Pos) /* (HMATRIX2_MRCR) Disable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB13_ENA               (HMATRIX2_MRCR_RCB13_ENA_Val << HMATRIX2_MRCR_RCB13_Pos) /* (HMATRIX2_MRCR) Enable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB14_Pos               _UINT32_(14)                                         /* (HMATRIX2_MRCR) Remap Command Bit for Master 14 Position */
#define HMATRIX2_MRCR_RCB14_Msk               (_UINT32_(0x1) << HMATRIX2_MRCR_RCB14_Pos)           /* (HMATRIX2_MRCR) Remap Command Bit for Master 14 Mask */
#define HMATRIX2_MRCR_RCB14(value)            (HMATRIX2_MRCR_RCB14_Msk & (_UINT32_(value) << HMATRIX2_MRCR_RCB14_Pos)) /* Assigment of value for RCB14 in the HMATRIX2_MRCR register */
#define   HMATRIX2_MRCR_RCB14_DIS_Val         _UINT32_(0x0)                                        /* (HMATRIX2_MRCR) Disable remapped address decoding for master  */
#define   HMATRIX2_MRCR_RCB14_ENA_Val         _UINT32_(0x1)                                        /* (HMATRIX2_MRCR) Enable remapped address decoding for master  */
#define HMATRIX2_MRCR_RCB14_DIS               (HMATRIX2_MRCR_RCB14_DIS_Val << HMATRIX2_MRCR_RCB14_Pos) /* (HMATRIX2_MRCR) Disable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB14_ENA               (HMATRIX2_MRCR_RCB14_ENA_Val << HMATRIX2_MRCR_RCB14_Pos) /* (HMATRIX2_MRCR) Enable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB15_Pos               _UINT32_(15)                                         /* (HMATRIX2_MRCR) Remap Command Bit for Master 15 Position */
#define HMATRIX2_MRCR_RCB15_Msk               (_UINT32_(0x1) << HMATRIX2_MRCR_RCB15_Pos)           /* (HMATRIX2_MRCR) Remap Command Bit for Master 15 Mask */
#define HMATRIX2_MRCR_RCB15(value)            (HMATRIX2_MRCR_RCB15_Msk & (_UINT32_(value) << HMATRIX2_MRCR_RCB15_Pos)) /* Assigment of value for RCB15 in the HMATRIX2_MRCR register */
#define   HMATRIX2_MRCR_RCB15_DIS_Val         _UINT32_(0x0)                                        /* (HMATRIX2_MRCR) Disable remapped address decoding for master  */
#define   HMATRIX2_MRCR_RCB15_ENA_Val         _UINT32_(0x1)                                        /* (HMATRIX2_MRCR) Enable remapped address decoding for master  */
#define HMATRIX2_MRCR_RCB15_DIS               (HMATRIX2_MRCR_RCB15_DIS_Val << HMATRIX2_MRCR_RCB15_Pos) /* (HMATRIX2_MRCR) Disable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_RCB15_ENA               (HMATRIX2_MRCR_RCB15_ENA_Val << HMATRIX2_MRCR_RCB15_Pos) /* (HMATRIX2_MRCR) Enable remapped address decoding for master Position  */
#define HMATRIX2_MRCR_Msk                     _UINT32_(0x0000FFFF)                                 /* (HMATRIX2_MRCR) Register Mask  */

#define HMATRIX2_MRCR_RCB_Pos                 _UINT32_(0)                                          /* (HMATRIX2_MRCR Position) Remap Command Bit for Master x5 */
#define HMATRIX2_MRCR_RCB_Msk                 (_UINT32_(0xFFFF) << HMATRIX2_MRCR_RCB_Pos)          /* (HMATRIX2_MRCR Mask) RCB */
#define HMATRIX2_MRCR_RCB(value)              (HMATRIX2_MRCR_RCB_Msk & (_UINT32_(value) << HMATRIX2_MRCR_RCB_Pos)) 

/* -------- HMATRIX2_SFR : (HMATRIX2 Offset: 0x110) (R/W 32) Special Function -------- */
#define HMATRIX2_SFR_RESETVALUE               _UINT32_(0x00)                                       /*  (HMATRIX2_SFR) Special Function  Reset Value */

#define HMATRIX2_SFR_SFR_Pos                  _UINT32_(0)                                          /* (HMATRIX2_SFR) Special Function Register Position */
#define HMATRIX2_SFR_SFR_Msk                  (_UINT32_(0xFFFFFFFF) << HMATRIX2_SFR_SFR_Pos)       /* (HMATRIX2_SFR) Special Function Register Mask */
#define HMATRIX2_SFR_SFR(value)               (HMATRIX2_SFR_SFR_Msk & (_UINT32_(value) << HMATRIX2_SFR_SFR_Pos)) /* Assigment of value for SFR in the HMATRIX2_SFR register */
#define HMATRIX2_SFR_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (HMATRIX2_SFR) Register Mask  */


/* -------- HMATRIX2_MEIER : (HMATRIX2 Offset: 0x150) ( /W 32) Master Error Interrupt Enable -------- */
#define HMATRIX2_MEIER_MERR0_Pos              _UINT32_(0)                                          /* (HMATRIX2_MEIER) Master 0 Access Error Position */
#define HMATRIX2_MEIER_MERR0_Msk              (_UINT32_(0x1) << HMATRIX2_MEIER_MERR0_Pos)          /* (HMATRIX2_MEIER) Master 0 Access Error Mask */
#define HMATRIX2_MEIER_MERR0(value)           (HMATRIX2_MEIER_MERR0_Msk & (_UINT32_(value) << HMATRIX2_MEIER_MERR0_Pos)) /* Assigment of value for MERR0 in the HMATRIX2_MEIER register */
#define HMATRIX2_MEIER_MERR1_Pos              _UINT32_(1)                                          /* (HMATRIX2_MEIER) Master 1 Access Error Position */
#define HMATRIX2_MEIER_MERR1_Msk              (_UINT32_(0x1) << HMATRIX2_MEIER_MERR1_Pos)          /* (HMATRIX2_MEIER) Master 1 Access Error Mask */
#define HMATRIX2_MEIER_MERR1(value)           (HMATRIX2_MEIER_MERR1_Msk & (_UINT32_(value) << HMATRIX2_MEIER_MERR1_Pos)) /* Assigment of value for MERR1 in the HMATRIX2_MEIER register */
#define HMATRIX2_MEIER_MERR2_Pos              _UINT32_(2)                                          /* (HMATRIX2_MEIER) Master 2 Access Error Position */
#define HMATRIX2_MEIER_MERR2_Msk              (_UINT32_(0x1) << HMATRIX2_MEIER_MERR2_Pos)          /* (HMATRIX2_MEIER) Master 2 Access Error Mask */
#define HMATRIX2_MEIER_MERR2(value)           (HMATRIX2_MEIER_MERR2_Msk & (_UINT32_(value) << HMATRIX2_MEIER_MERR2_Pos)) /* Assigment of value for MERR2 in the HMATRIX2_MEIER register */
#define HMATRIX2_MEIER_MERR3_Pos              _UINT32_(3)                                          /* (HMATRIX2_MEIER) Master 3 Access Error Position */
#define HMATRIX2_MEIER_MERR3_Msk              (_UINT32_(0x1) << HMATRIX2_MEIER_MERR3_Pos)          /* (HMATRIX2_MEIER) Master 3 Access Error Mask */
#define HMATRIX2_MEIER_MERR3(value)           (HMATRIX2_MEIER_MERR3_Msk & (_UINT32_(value) << HMATRIX2_MEIER_MERR3_Pos)) /* Assigment of value for MERR3 in the HMATRIX2_MEIER register */
#define HMATRIX2_MEIER_MERR4_Pos              _UINT32_(4)                                          /* (HMATRIX2_MEIER) Master 4 Access Error Position */
#define HMATRIX2_MEIER_MERR4_Msk              (_UINT32_(0x1) << HMATRIX2_MEIER_MERR4_Pos)          /* (HMATRIX2_MEIER) Master 4 Access Error Mask */
#define HMATRIX2_MEIER_MERR4(value)           (HMATRIX2_MEIER_MERR4_Msk & (_UINT32_(value) << HMATRIX2_MEIER_MERR4_Pos)) /* Assigment of value for MERR4 in the HMATRIX2_MEIER register */
#define HMATRIX2_MEIER_MERR5_Pos              _UINT32_(5)                                          /* (HMATRIX2_MEIER) Master 5 Access Error Position */
#define HMATRIX2_MEIER_MERR5_Msk              (_UINT32_(0x1) << HMATRIX2_MEIER_MERR5_Pos)          /* (HMATRIX2_MEIER) Master 5 Access Error Mask */
#define HMATRIX2_MEIER_MERR5(value)           (HMATRIX2_MEIER_MERR5_Msk & (_UINT32_(value) << HMATRIX2_MEIER_MERR5_Pos)) /* Assigment of value for MERR5 in the HMATRIX2_MEIER register */
#define HMATRIX2_MEIER_MERR6_Pos              _UINT32_(6)                                          /* (HMATRIX2_MEIER) Master 6 Access Error Position */
#define HMATRIX2_MEIER_MERR6_Msk              (_UINT32_(0x1) << HMATRIX2_MEIER_MERR6_Pos)          /* (HMATRIX2_MEIER) Master 6 Access Error Mask */
#define HMATRIX2_MEIER_MERR6(value)           (HMATRIX2_MEIER_MERR6_Msk & (_UINT32_(value) << HMATRIX2_MEIER_MERR6_Pos)) /* Assigment of value for MERR6 in the HMATRIX2_MEIER register */
#define HMATRIX2_MEIER_MERR7_Pos              _UINT32_(7)                                          /* (HMATRIX2_MEIER) Master 7 Access Error Position */
#define HMATRIX2_MEIER_MERR7_Msk              (_UINT32_(0x1) << HMATRIX2_MEIER_MERR7_Pos)          /* (HMATRIX2_MEIER) Master 7 Access Error Mask */
#define HMATRIX2_MEIER_MERR7(value)           (HMATRIX2_MEIER_MERR7_Msk & (_UINT32_(value) << HMATRIX2_MEIER_MERR7_Pos)) /* Assigment of value for MERR7 in the HMATRIX2_MEIER register */
#define HMATRIX2_MEIER_MERR8_Pos              _UINT32_(8)                                          /* (HMATRIX2_MEIER) Master 8 Access Error Position */
#define HMATRIX2_MEIER_MERR8_Msk              (_UINT32_(0x1) << HMATRIX2_MEIER_MERR8_Pos)          /* (HMATRIX2_MEIER) Master 8 Access Error Mask */
#define HMATRIX2_MEIER_MERR8(value)           (HMATRIX2_MEIER_MERR8_Msk & (_UINT32_(value) << HMATRIX2_MEIER_MERR8_Pos)) /* Assigment of value for MERR8 in the HMATRIX2_MEIER register */
#define HMATRIX2_MEIER_MERR9_Pos              _UINT32_(9)                                          /* (HMATRIX2_MEIER) Master 9 Access Error Position */
#define HMATRIX2_MEIER_MERR9_Msk              (_UINT32_(0x1) << HMATRIX2_MEIER_MERR9_Pos)          /* (HMATRIX2_MEIER) Master 9 Access Error Mask */
#define HMATRIX2_MEIER_MERR9(value)           (HMATRIX2_MEIER_MERR9_Msk & (_UINT32_(value) << HMATRIX2_MEIER_MERR9_Pos)) /* Assigment of value for MERR9 in the HMATRIX2_MEIER register */
#define HMATRIX2_MEIER_MERR10_Pos             _UINT32_(10)                                         /* (HMATRIX2_MEIER) Master 10 Access Error Position */
#define HMATRIX2_MEIER_MERR10_Msk             (_UINT32_(0x1) << HMATRIX2_MEIER_MERR10_Pos)         /* (HMATRIX2_MEIER) Master 10 Access Error Mask */
#define HMATRIX2_MEIER_MERR10(value)          (HMATRIX2_MEIER_MERR10_Msk & (_UINT32_(value) << HMATRIX2_MEIER_MERR10_Pos)) /* Assigment of value for MERR10 in the HMATRIX2_MEIER register */
#define HMATRIX2_MEIER_MERR11_Pos             _UINT32_(11)                                         /* (HMATRIX2_MEIER) Master 11 Access Error Position */
#define HMATRIX2_MEIER_MERR11_Msk             (_UINT32_(0x1) << HMATRIX2_MEIER_MERR11_Pos)         /* (HMATRIX2_MEIER) Master 11 Access Error Mask */
#define HMATRIX2_MEIER_MERR11(value)          (HMATRIX2_MEIER_MERR11_Msk & (_UINT32_(value) << HMATRIX2_MEIER_MERR11_Pos)) /* Assigment of value for MERR11 in the HMATRIX2_MEIER register */
#define HMATRIX2_MEIER_MERR12_Pos             _UINT32_(12)                                         /* (HMATRIX2_MEIER) Master 12 Access Error Position */
#define HMATRIX2_MEIER_MERR12_Msk             (_UINT32_(0x1) << HMATRIX2_MEIER_MERR12_Pos)         /* (HMATRIX2_MEIER) Master 12 Access Error Mask */
#define HMATRIX2_MEIER_MERR12(value)          (HMATRIX2_MEIER_MERR12_Msk & (_UINT32_(value) << HMATRIX2_MEIER_MERR12_Pos)) /* Assigment of value for MERR12 in the HMATRIX2_MEIER register */
#define HMATRIX2_MEIER_MERR13_Pos             _UINT32_(13)                                         /* (HMATRIX2_MEIER) Master 13 Access Error Position */
#define HMATRIX2_MEIER_MERR13_Msk             (_UINT32_(0x1) << HMATRIX2_MEIER_MERR13_Pos)         /* (HMATRIX2_MEIER) Master 13 Access Error Mask */
#define HMATRIX2_MEIER_MERR13(value)          (HMATRIX2_MEIER_MERR13_Msk & (_UINT32_(value) << HMATRIX2_MEIER_MERR13_Pos)) /* Assigment of value for MERR13 in the HMATRIX2_MEIER register */
#define HMATRIX2_MEIER_MERR14_Pos             _UINT32_(14)                                         /* (HMATRIX2_MEIER) Master 14 Access Error Position */
#define HMATRIX2_MEIER_MERR14_Msk             (_UINT32_(0x1) << HMATRIX2_MEIER_MERR14_Pos)         /* (HMATRIX2_MEIER) Master 14 Access Error Mask */
#define HMATRIX2_MEIER_MERR14(value)          (HMATRIX2_MEIER_MERR14_Msk & (_UINT32_(value) << HMATRIX2_MEIER_MERR14_Pos)) /* Assigment of value for MERR14 in the HMATRIX2_MEIER register */
#define HMATRIX2_MEIER_MERR15_Pos             _UINT32_(15)                                         /* (HMATRIX2_MEIER) Master 15 Access Error Position */
#define HMATRIX2_MEIER_MERR15_Msk             (_UINT32_(0x1) << HMATRIX2_MEIER_MERR15_Pos)         /* (HMATRIX2_MEIER) Master 15 Access Error Mask */
#define HMATRIX2_MEIER_MERR15(value)          (HMATRIX2_MEIER_MERR15_Msk & (_UINT32_(value) << HMATRIX2_MEIER_MERR15_Pos)) /* Assigment of value for MERR15 in the HMATRIX2_MEIER register */
#define HMATRIX2_MEIER_Msk                    _UINT32_(0x0000FFFF)                                 /* (HMATRIX2_MEIER) Register Mask  */

#define HMATRIX2_MEIER_MERR_Pos               _UINT32_(0)                                          /* (HMATRIX2_MEIER Position) Master x5 Access Error */
#define HMATRIX2_MEIER_MERR_Msk               (_UINT32_(0xFFFF) << HMATRIX2_MEIER_MERR_Pos)        /* (HMATRIX2_MEIER Mask) MERR */
#define HMATRIX2_MEIER_MERR(value)            (HMATRIX2_MEIER_MERR_Msk & (_UINT32_(value) << HMATRIX2_MEIER_MERR_Pos)) 

/* -------- HMATRIX2_MEIDR : (HMATRIX2 Offset: 0x154) ( /W 32) Master Error Interrupt Disable -------- */
#define HMATRIX2_MEIDR_MERR0_Pos              _UINT32_(0)                                          /* (HMATRIX2_MEIDR) Master 0 Access Error Position */
#define HMATRIX2_MEIDR_MERR0_Msk              (_UINT32_(0x1) << HMATRIX2_MEIDR_MERR0_Pos)          /* (HMATRIX2_MEIDR) Master 0 Access Error Mask */
#define HMATRIX2_MEIDR_MERR0(value)           (HMATRIX2_MEIDR_MERR0_Msk & (_UINT32_(value) << HMATRIX2_MEIDR_MERR0_Pos)) /* Assigment of value for MERR0 in the HMATRIX2_MEIDR register */
#define HMATRIX2_MEIDR_MERR1_Pos              _UINT32_(1)                                          /* (HMATRIX2_MEIDR) Master 1 Access Error Position */
#define HMATRIX2_MEIDR_MERR1_Msk              (_UINT32_(0x1) << HMATRIX2_MEIDR_MERR1_Pos)          /* (HMATRIX2_MEIDR) Master 1 Access Error Mask */
#define HMATRIX2_MEIDR_MERR1(value)           (HMATRIX2_MEIDR_MERR1_Msk & (_UINT32_(value) << HMATRIX2_MEIDR_MERR1_Pos)) /* Assigment of value for MERR1 in the HMATRIX2_MEIDR register */
#define HMATRIX2_MEIDR_MERR2_Pos              _UINT32_(2)                                          /* (HMATRIX2_MEIDR) Master 2 Access Error Position */
#define HMATRIX2_MEIDR_MERR2_Msk              (_UINT32_(0x1) << HMATRIX2_MEIDR_MERR2_Pos)          /* (HMATRIX2_MEIDR) Master 2 Access Error Mask */
#define HMATRIX2_MEIDR_MERR2(value)           (HMATRIX2_MEIDR_MERR2_Msk & (_UINT32_(value) << HMATRIX2_MEIDR_MERR2_Pos)) /* Assigment of value for MERR2 in the HMATRIX2_MEIDR register */
#define HMATRIX2_MEIDR_MERR3_Pos              _UINT32_(3)                                          /* (HMATRIX2_MEIDR) Master 3 Access Error Position */
#define HMATRIX2_MEIDR_MERR3_Msk              (_UINT32_(0x1) << HMATRIX2_MEIDR_MERR3_Pos)          /* (HMATRIX2_MEIDR) Master 3 Access Error Mask */
#define HMATRIX2_MEIDR_MERR3(value)           (HMATRIX2_MEIDR_MERR3_Msk & (_UINT32_(value) << HMATRIX2_MEIDR_MERR3_Pos)) /* Assigment of value for MERR3 in the HMATRIX2_MEIDR register */
#define HMATRIX2_MEIDR_MERR4_Pos              _UINT32_(4)                                          /* (HMATRIX2_MEIDR) Master 4 Access Error Position */
#define HMATRIX2_MEIDR_MERR4_Msk              (_UINT32_(0x1) << HMATRIX2_MEIDR_MERR4_Pos)          /* (HMATRIX2_MEIDR) Master 4 Access Error Mask */
#define HMATRIX2_MEIDR_MERR4(value)           (HMATRIX2_MEIDR_MERR4_Msk & (_UINT32_(value) << HMATRIX2_MEIDR_MERR4_Pos)) /* Assigment of value for MERR4 in the HMATRIX2_MEIDR register */
#define HMATRIX2_MEIDR_MERR5_Pos              _UINT32_(5)                                          /* (HMATRIX2_MEIDR) Master 5 Access Error Position */
#define HMATRIX2_MEIDR_MERR5_Msk              (_UINT32_(0x1) << HMATRIX2_MEIDR_MERR5_Pos)          /* (HMATRIX2_MEIDR) Master 5 Access Error Mask */
#define HMATRIX2_MEIDR_MERR5(value)           (HMATRIX2_MEIDR_MERR5_Msk & (_UINT32_(value) << HMATRIX2_MEIDR_MERR5_Pos)) /* Assigment of value for MERR5 in the HMATRIX2_MEIDR register */
#define HMATRIX2_MEIDR_MERR6_Pos              _UINT32_(6)                                          /* (HMATRIX2_MEIDR) Master 6 Access Error Position */
#define HMATRIX2_MEIDR_MERR6_Msk              (_UINT32_(0x1) << HMATRIX2_MEIDR_MERR6_Pos)          /* (HMATRIX2_MEIDR) Master 6 Access Error Mask */
#define HMATRIX2_MEIDR_MERR6(value)           (HMATRIX2_MEIDR_MERR6_Msk & (_UINT32_(value) << HMATRIX2_MEIDR_MERR6_Pos)) /* Assigment of value for MERR6 in the HMATRIX2_MEIDR register */
#define HMATRIX2_MEIDR_MERR7_Pos              _UINT32_(7)                                          /* (HMATRIX2_MEIDR) Master 7 Access Error Position */
#define HMATRIX2_MEIDR_MERR7_Msk              (_UINT32_(0x1) << HMATRIX2_MEIDR_MERR7_Pos)          /* (HMATRIX2_MEIDR) Master 7 Access Error Mask */
#define HMATRIX2_MEIDR_MERR7(value)           (HMATRIX2_MEIDR_MERR7_Msk & (_UINT32_(value) << HMATRIX2_MEIDR_MERR7_Pos)) /* Assigment of value for MERR7 in the HMATRIX2_MEIDR register */
#define HMATRIX2_MEIDR_MERR8_Pos              _UINT32_(8)                                          /* (HMATRIX2_MEIDR) Master 8 Access Error Position */
#define HMATRIX2_MEIDR_MERR8_Msk              (_UINT32_(0x1) << HMATRIX2_MEIDR_MERR8_Pos)          /* (HMATRIX2_MEIDR) Master 8 Access Error Mask */
#define HMATRIX2_MEIDR_MERR8(value)           (HMATRIX2_MEIDR_MERR8_Msk & (_UINT32_(value) << HMATRIX2_MEIDR_MERR8_Pos)) /* Assigment of value for MERR8 in the HMATRIX2_MEIDR register */
#define HMATRIX2_MEIDR_MERR9_Pos              _UINT32_(9)                                          /* (HMATRIX2_MEIDR) Master 9 Access Error Position */
#define HMATRIX2_MEIDR_MERR9_Msk              (_UINT32_(0x1) << HMATRIX2_MEIDR_MERR9_Pos)          /* (HMATRIX2_MEIDR) Master 9 Access Error Mask */
#define HMATRIX2_MEIDR_MERR9(value)           (HMATRIX2_MEIDR_MERR9_Msk & (_UINT32_(value) << HMATRIX2_MEIDR_MERR9_Pos)) /* Assigment of value for MERR9 in the HMATRIX2_MEIDR register */
#define HMATRIX2_MEIDR_MERR10_Pos             _UINT32_(10)                                         /* (HMATRIX2_MEIDR) Master 10 Access Error Position */
#define HMATRIX2_MEIDR_MERR10_Msk             (_UINT32_(0x1) << HMATRIX2_MEIDR_MERR10_Pos)         /* (HMATRIX2_MEIDR) Master 10 Access Error Mask */
#define HMATRIX2_MEIDR_MERR10(value)          (HMATRIX2_MEIDR_MERR10_Msk & (_UINT32_(value) << HMATRIX2_MEIDR_MERR10_Pos)) /* Assigment of value for MERR10 in the HMATRIX2_MEIDR register */
#define HMATRIX2_MEIDR_MERR11_Pos             _UINT32_(11)                                         /* (HMATRIX2_MEIDR) Master 11 Access Error Position */
#define HMATRIX2_MEIDR_MERR11_Msk             (_UINT32_(0x1) << HMATRIX2_MEIDR_MERR11_Pos)         /* (HMATRIX2_MEIDR) Master 11 Access Error Mask */
#define HMATRIX2_MEIDR_MERR11(value)          (HMATRIX2_MEIDR_MERR11_Msk & (_UINT32_(value) << HMATRIX2_MEIDR_MERR11_Pos)) /* Assigment of value for MERR11 in the HMATRIX2_MEIDR register */
#define HMATRIX2_MEIDR_MERR12_Pos             _UINT32_(12)                                         /* (HMATRIX2_MEIDR) Master 12 Access Error Position */
#define HMATRIX2_MEIDR_MERR12_Msk             (_UINT32_(0x1) << HMATRIX2_MEIDR_MERR12_Pos)         /* (HMATRIX2_MEIDR) Master 12 Access Error Mask */
#define HMATRIX2_MEIDR_MERR12(value)          (HMATRIX2_MEIDR_MERR12_Msk & (_UINT32_(value) << HMATRIX2_MEIDR_MERR12_Pos)) /* Assigment of value for MERR12 in the HMATRIX2_MEIDR register */
#define HMATRIX2_MEIDR_MERR13_Pos             _UINT32_(13)                                         /* (HMATRIX2_MEIDR) Master 13 Access Error Position */
#define HMATRIX2_MEIDR_MERR13_Msk             (_UINT32_(0x1) << HMATRIX2_MEIDR_MERR13_Pos)         /* (HMATRIX2_MEIDR) Master 13 Access Error Mask */
#define HMATRIX2_MEIDR_MERR13(value)          (HMATRIX2_MEIDR_MERR13_Msk & (_UINT32_(value) << HMATRIX2_MEIDR_MERR13_Pos)) /* Assigment of value for MERR13 in the HMATRIX2_MEIDR register */
#define HMATRIX2_MEIDR_MERR14_Pos             _UINT32_(14)                                         /* (HMATRIX2_MEIDR) Master 14 Access Error Position */
#define HMATRIX2_MEIDR_MERR14_Msk             (_UINT32_(0x1) << HMATRIX2_MEIDR_MERR14_Pos)         /* (HMATRIX2_MEIDR) Master 14 Access Error Mask */
#define HMATRIX2_MEIDR_MERR14(value)          (HMATRIX2_MEIDR_MERR14_Msk & (_UINT32_(value) << HMATRIX2_MEIDR_MERR14_Pos)) /* Assigment of value for MERR14 in the HMATRIX2_MEIDR register */
#define HMATRIX2_MEIDR_MERR15_Pos             _UINT32_(15)                                         /* (HMATRIX2_MEIDR) Master 15 Access Error Position */
#define HMATRIX2_MEIDR_MERR15_Msk             (_UINT32_(0x1) << HMATRIX2_MEIDR_MERR15_Pos)         /* (HMATRIX2_MEIDR) Master 15 Access Error Mask */
#define HMATRIX2_MEIDR_MERR15(value)          (HMATRIX2_MEIDR_MERR15_Msk & (_UINT32_(value) << HMATRIX2_MEIDR_MERR15_Pos)) /* Assigment of value for MERR15 in the HMATRIX2_MEIDR register */
#define HMATRIX2_MEIDR_Msk                    _UINT32_(0x0000FFFF)                                 /* (HMATRIX2_MEIDR) Register Mask  */

#define HMATRIX2_MEIDR_MERR_Pos               _UINT32_(0)                                          /* (HMATRIX2_MEIDR Position) Master x5 Access Error */
#define HMATRIX2_MEIDR_MERR_Msk               (_UINT32_(0xFFFF) << HMATRIX2_MEIDR_MERR_Pos)        /* (HMATRIX2_MEIDR Mask) MERR */
#define HMATRIX2_MEIDR_MERR(value)            (HMATRIX2_MEIDR_MERR_Msk & (_UINT32_(value) << HMATRIX2_MEIDR_MERR_Pos)) 

/* -------- HMATRIX2_MEIMR : (HMATRIX2 Offset: 0x158) ( R/ 32) Master Error Interrupt Mask -------- */
#define HMATRIX2_MEIMR_MERR0_Pos              _UINT32_(0)                                          /* (HMATRIX2_MEIMR) Master 0 Access Error Position */
#define HMATRIX2_MEIMR_MERR0_Msk              (_UINT32_(0x1) << HMATRIX2_MEIMR_MERR0_Pos)          /* (HMATRIX2_MEIMR) Master 0 Access Error Mask */
#define HMATRIX2_MEIMR_MERR0(value)           (HMATRIX2_MEIMR_MERR0_Msk & (_UINT32_(value) << HMATRIX2_MEIMR_MERR0_Pos)) /* Assigment of value for MERR0 in the HMATRIX2_MEIMR register */
#define HMATRIX2_MEIMR_MERR1_Pos              _UINT32_(1)                                          /* (HMATRIX2_MEIMR) Master 1 Access Error Position */
#define HMATRIX2_MEIMR_MERR1_Msk              (_UINT32_(0x1) << HMATRIX2_MEIMR_MERR1_Pos)          /* (HMATRIX2_MEIMR) Master 1 Access Error Mask */
#define HMATRIX2_MEIMR_MERR1(value)           (HMATRIX2_MEIMR_MERR1_Msk & (_UINT32_(value) << HMATRIX2_MEIMR_MERR1_Pos)) /* Assigment of value for MERR1 in the HMATRIX2_MEIMR register */
#define HMATRIX2_MEIMR_MERR2_Pos              _UINT32_(2)                                          /* (HMATRIX2_MEIMR) Master 2 Access Error Position */
#define HMATRIX2_MEIMR_MERR2_Msk              (_UINT32_(0x1) << HMATRIX2_MEIMR_MERR2_Pos)          /* (HMATRIX2_MEIMR) Master 2 Access Error Mask */
#define HMATRIX2_MEIMR_MERR2(value)           (HMATRIX2_MEIMR_MERR2_Msk & (_UINT32_(value) << HMATRIX2_MEIMR_MERR2_Pos)) /* Assigment of value for MERR2 in the HMATRIX2_MEIMR register */
#define HMATRIX2_MEIMR_MERR3_Pos              _UINT32_(3)                                          /* (HMATRIX2_MEIMR) Master 3 Access Error Position */
#define HMATRIX2_MEIMR_MERR3_Msk              (_UINT32_(0x1) << HMATRIX2_MEIMR_MERR3_Pos)          /* (HMATRIX2_MEIMR) Master 3 Access Error Mask */
#define HMATRIX2_MEIMR_MERR3(value)           (HMATRIX2_MEIMR_MERR3_Msk & (_UINT32_(value) << HMATRIX2_MEIMR_MERR3_Pos)) /* Assigment of value for MERR3 in the HMATRIX2_MEIMR register */
#define HMATRIX2_MEIMR_MERR4_Pos              _UINT32_(4)                                          /* (HMATRIX2_MEIMR) Master 4 Access Error Position */
#define HMATRIX2_MEIMR_MERR4_Msk              (_UINT32_(0x1) << HMATRIX2_MEIMR_MERR4_Pos)          /* (HMATRIX2_MEIMR) Master 4 Access Error Mask */
#define HMATRIX2_MEIMR_MERR4(value)           (HMATRIX2_MEIMR_MERR4_Msk & (_UINT32_(value) << HMATRIX2_MEIMR_MERR4_Pos)) /* Assigment of value for MERR4 in the HMATRIX2_MEIMR register */
#define HMATRIX2_MEIMR_MERR5_Pos              _UINT32_(5)                                          /* (HMATRIX2_MEIMR) Master 5 Access Error Position */
#define HMATRIX2_MEIMR_MERR5_Msk              (_UINT32_(0x1) << HMATRIX2_MEIMR_MERR5_Pos)          /* (HMATRIX2_MEIMR) Master 5 Access Error Mask */
#define HMATRIX2_MEIMR_MERR5(value)           (HMATRIX2_MEIMR_MERR5_Msk & (_UINT32_(value) << HMATRIX2_MEIMR_MERR5_Pos)) /* Assigment of value for MERR5 in the HMATRIX2_MEIMR register */
#define HMATRIX2_MEIMR_MERR6_Pos              _UINT32_(6)                                          /* (HMATRIX2_MEIMR) Master 6 Access Error Position */
#define HMATRIX2_MEIMR_MERR6_Msk              (_UINT32_(0x1) << HMATRIX2_MEIMR_MERR6_Pos)          /* (HMATRIX2_MEIMR) Master 6 Access Error Mask */
#define HMATRIX2_MEIMR_MERR6(value)           (HMATRIX2_MEIMR_MERR6_Msk & (_UINT32_(value) << HMATRIX2_MEIMR_MERR6_Pos)) /* Assigment of value for MERR6 in the HMATRIX2_MEIMR register */
#define HMATRIX2_MEIMR_MERR7_Pos              _UINT32_(7)                                          /* (HMATRIX2_MEIMR) Master 7 Access Error Position */
#define HMATRIX2_MEIMR_MERR7_Msk              (_UINT32_(0x1) << HMATRIX2_MEIMR_MERR7_Pos)          /* (HMATRIX2_MEIMR) Master 7 Access Error Mask */
#define HMATRIX2_MEIMR_MERR7(value)           (HMATRIX2_MEIMR_MERR7_Msk & (_UINT32_(value) << HMATRIX2_MEIMR_MERR7_Pos)) /* Assigment of value for MERR7 in the HMATRIX2_MEIMR register */
#define HMATRIX2_MEIMR_MERR8_Pos              _UINT32_(8)                                          /* (HMATRIX2_MEIMR) Master 8 Access Error Position */
#define HMATRIX2_MEIMR_MERR8_Msk              (_UINT32_(0x1) << HMATRIX2_MEIMR_MERR8_Pos)          /* (HMATRIX2_MEIMR) Master 8 Access Error Mask */
#define HMATRIX2_MEIMR_MERR8(value)           (HMATRIX2_MEIMR_MERR8_Msk & (_UINT32_(value) << HMATRIX2_MEIMR_MERR8_Pos)) /* Assigment of value for MERR8 in the HMATRIX2_MEIMR register */
#define HMATRIX2_MEIMR_MERR9_Pos              _UINT32_(9)                                          /* (HMATRIX2_MEIMR) Master 9 Access Error Position */
#define HMATRIX2_MEIMR_MERR9_Msk              (_UINT32_(0x1) << HMATRIX2_MEIMR_MERR9_Pos)          /* (HMATRIX2_MEIMR) Master 9 Access Error Mask */
#define HMATRIX2_MEIMR_MERR9(value)           (HMATRIX2_MEIMR_MERR9_Msk & (_UINT32_(value) << HMATRIX2_MEIMR_MERR9_Pos)) /* Assigment of value for MERR9 in the HMATRIX2_MEIMR register */
#define HMATRIX2_MEIMR_MERR10_Pos             _UINT32_(10)                                         /* (HMATRIX2_MEIMR) Master 10 Access Error Position */
#define HMATRIX2_MEIMR_MERR10_Msk             (_UINT32_(0x1) << HMATRIX2_MEIMR_MERR10_Pos)         /* (HMATRIX2_MEIMR) Master 10 Access Error Mask */
#define HMATRIX2_MEIMR_MERR10(value)          (HMATRIX2_MEIMR_MERR10_Msk & (_UINT32_(value) << HMATRIX2_MEIMR_MERR10_Pos)) /* Assigment of value for MERR10 in the HMATRIX2_MEIMR register */
#define HMATRIX2_MEIMR_MERR11_Pos             _UINT32_(11)                                         /* (HMATRIX2_MEIMR) Master 11 Access Error Position */
#define HMATRIX2_MEIMR_MERR11_Msk             (_UINT32_(0x1) << HMATRIX2_MEIMR_MERR11_Pos)         /* (HMATRIX2_MEIMR) Master 11 Access Error Mask */
#define HMATRIX2_MEIMR_MERR11(value)          (HMATRIX2_MEIMR_MERR11_Msk & (_UINT32_(value) << HMATRIX2_MEIMR_MERR11_Pos)) /* Assigment of value for MERR11 in the HMATRIX2_MEIMR register */
#define HMATRIX2_MEIMR_MERR12_Pos             _UINT32_(12)                                         /* (HMATRIX2_MEIMR) Master 12 Access Error Position */
#define HMATRIX2_MEIMR_MERR12_Msk             (_UINT32_(0x1) << HMATRIX2_MEIMR_MERR12_Pos)         /* (HMATRIX2_MEIMR) Master 12 Access Error Mask */
#define HMATRIX2_MEIMR_MERR12(value)          (HMATRIX2_MEIMR_MERR12_Msk & (_UINT32_(value) << HMATRIX2_MEIMR_MERR12_Pos)) /* Assigment of value for MERR12 in the HMATRIX2_MEIMR register */
#define HMATRIX2_MEIMR_MERR13_Pos             _UINT32_(13)                                         /* (HMATRIX2_MEIMR) Master 13 Access Error Position */
#define HMATRIX2_MEIMR_MERR13_Msk             (_UINT32_(0x1) << HMATRIX2_MEIMR_MERR13_Pos)         /* (HMATRIX2_MEIMR) Master 13 Access Error Mask */
#define HMATRIX2_MEIMR_MERR13(value)          (HMATRIX2_MEIMR_MERR13_Msk & (_UINT32_(value) << HMATRIX2_MEIMR_MERR13_Pos)) /* Assigment of value for MERR13 in the HMATRIX2_MEIMR register */
#define HMATRIX2_MEIMR_MERR14_Pos             _UINT32_(14)                                         /* (HMATRIX2_MEIMR) Master 14 Access Error Position */
#define HMATRIX2_MEIMR_MERR14_Msk             (_UINT32_(0x1) << HMATRIX2_MEIMR_MERR14_Pos)         /* (HMATRIX2_MEIMR) Master 14 Access Error Mask */
#define HMATRIX2_MEIMR_MERR14(value)          (HMATRIX2_MEIMR_MERR14_Msk & (_UINT32_(value) << HMATRIX2_MEIMR_MERR14_Pos)) /* Assigment of value for MERR14 in the HMATRIX2_MEIMR register */
#define HMATRIX2_MEIMR_MERR15_Pos             _UINT32_(15)                                         /* (HMATRIX2_MEIMR) Master 15 Access Error Position */
#define HMATRIX2_MEIMR_MERR15_Msk             (_UINT32_(0x1) << HMATRIX2_MEIMR_MERR15_Pos)         /* (HMATRIX2_MEIMR) Master 15 Access Error Mask */
#define HMATRIX2_MEIMR_MERR15(value)          (HMATRIX2_MEIMR_MERR15_Msk & (_UINT32_(value) << HMATRIX2_MEIMR_MERR15_Pos)) /* Assigment of value for MERR15 in the HMATRIX2_MEIMR register */
#define HMATRIX2_MEIMR_Msk                    _UINT32_(0x0000FFFF)                                 /* (HMATRIX2_MEIMR) Register Mask  */

#define HMATRIX2_MEIMR_MERR_Pos               _UINT32_(0)                                          /* (HMATRIX2_MEIMR Position) Master x5 Access Error */
#define HMATRIX2_MEIMR_MERR_Msk               (_UINT32_(0xFFFF) << HMATRIX2_MEIMR_MERR_Pos)        /* (HMATRIX2_MEIMR Mask) MERR */
#define HMATRIX2_MEIMR_MERR(value)            (HMATRIX2_MEIMR_MERR_Msk & (_UINT32_(value) << HMATRIX2_MEIMR_MERR_Pos)) 

/* -------- HMATRIX2_MESR : (HMATRIX2 Offset: 0x15C) ( R/ 32) Master Error Status -------- */
#define HMATRIX2_MESR_MERR0_Pos               _UINT32_(0)                                          /* (HMATRIX2_MESR) Master 0 Access Error Position */
#define HMATRIX2_MESR_MERR0_Msk               (_UINT32_(0x1) << HMATRIX2_MESR_MERR0_Pos)           /* (HMATRIX2_MESR) Master 0 Access Error Mask */
#define HMATRIX2_MESR_MERR0(value)            (HMATRIX2_MESR_MERR0_Msk & (_UINT32_(value) << HMATRIX2_MESR_MERR0_Pos)) /* Assigment of value for MERR0 in the HMATRIX2_MESR register */
#define HMATRIX2_MESR_MERR1_Pos               _UINT32_(1)                                          /* (HMATRIX2_MESR) Master 1 Access Error Position */
#define HMATRIX2_MESR_MERR1_Msk               (_UINT32_(0x1) << HMATRIX2_MESR_MERR1_Pos)           /* (HMATRIX2_MESR) Master 1 Access Error Mask */
#define HMATRIX2_MESR_MERR1(value)            (HMATRIX2_MESR_MERR1_Msk & (_UINT32_(value) << HMATRIX2_MESR_MERR1_Pos)) /* Assigment of value for MERR1 in the HMATRIX2_MESR register */
#define HMATRIX2_MESR_MERR2_Pos               _UINT32_(2)                                          /* (HMATRIX2_MESR) Master 2 Access Error Position */
#define HMATRIX2_MESR_MERR2_Msk               (_UINT32_(0x1) << HMATRIX2_MESR_MERR2_Pos)           /* (HMATRIX2_MESR) Master 2 Access Error Mask */
#define HMATRIX2_MESR_MERR2(value)            (HMATRIX2_MESR_MERR2_Msk & (_UINT32_(value) << HMATRIX2_MESR_MERR2_Pos)) /* Assigment of value for MERR2 in the HMATRIX2_MESR register */
#define HMATRIX2_MESR_MERR3_Pos               _UINT32_(3)                                          /* (HMATRIX2_MESR) Master 3 Access Error Position */
#define HMATRIX2_MESR_MERR3_Msk               (_UINT32_(0x1) << HMATRIX2_MESR_MERR3_Pos)           /* (HMATRIX2_MESR) Master 3 Access Error Mask */
#define HMATRIX2_MESR_MERR3(value)            (HMATRIX2_MESR_MERR3_Msk & (_UINT32_(value) << HMATRIX2_MESR_MERR3_Pos)) /* Assigment of value for MERR3 in the HMATRIX2_MESR register */
#define HMATRIX2_MESR_MERR4_Pos               _UINT32_(4)                                          /* (HMATRIX2_MESR) Master 4 Access Error Position */
#define HMATRIX2_MESR_MERR4_Msk               (_UINT32_(0x1) << HMATRIX2_MESR_MERR4_Pos)           /* (HMATRIX2_MESR) Master 4 Access Error Mask */
#define HMATRIX2_MESR_MERR4(value)            (HMATRIX2_MESR_MERR4_Msk & (_UINT32_(value) << HMATRIX2_MESR_MERR4_Pos)) /* Assigment of value for MERR4 in the HMATRIX2_MESR register */
#define HMATRIX2_MESR_MERR5_Pos               _UINT32_(5)                                          /* (HMATRIX2_MESR) Master 5 Access Error Position */
#define HMATRIX2_MESR_MERR5_Msk               (_UINT32_(0x1) << HMATRIX2_MESR_MERR5_Pos)           /* (HMATRIX2_MESR) Master 5 Access Error Mask */
#define HMATRIX2_MESR_MERR5(value)            (HMATRIX2_MESR_MERR5_Msk & (_UINT32_(value) << HMATRIX2_MESR_MERR5_Pos)) /* Assigment of value for MERR5 in the HMATRIX2_MESR register */
#define HMATRIX2_MESR_MERR6_Pos               _UINT32_(6)                                          /* (HMATRIX2_MESR) Master 6 Access Error Position */
#define HMATRIX2_MESR_MERR6_Msk               (_UINT32_(0x1) << HMATRIX2_MESR_MERR6_Pos)           /* (HMATRIX2_MESR) Master 6 Access Error Mask */
#define HMATRIX2_MESR_MERR6(value)            (HMATRIX2_MESR_MERR6_Msk & (_UINT32_(value) << HMATRIX2_MESR_MERR6_Pos)) /* Assigment of value for MERR6 in the HMATRIX2_MESR register */
#define HMATRIX2_MESR_MERR7_Pos               _UINT32_(7)                                          /* (HMATRIX2_MESR) Master 7 Access Error Position */
#define HMATRIX2_MESR_MERR7_Msk               (_UINT32_(0x1) << HMATRIX2_MESR_MERR7_Pos)           /* (HMATRIX2_MESR) Master 7 Access Error Mask */
#define HMATRIX2_MESR_MERR7(value)            (HMATRIX2_MESR_MERR7_Msk & (_UINT32_(value) << HMATRIX2_MESR_MERR7_Pos)) /* Assigment of value for MERR7 in the HMATRIX2_MESR register */
#define HMATRIX2_MESR_MERR8_Pos               _UINT32_(8)                                          /* (HMATRIX2_MESR) Master 8 Access Error Position */
#define HMATRIX2_MESR_MERR8_Msk               (_UINT32_(0x1) << HMATRIX2_MESR_MERR8_Pos)           /* (HMATRIX2_MESR) Master 8 Access Error Mask */
#define HMATRIX2_MESR_MERR8(value)            (HMATRIX2_MESR_MERR8_Msk & (_UINT32_(value) << HMATRIX2_MESR_MERR8_Pos)) /* Assigment of value for MERR8 in the HMATRIX2_MESR register */
#define HMATRIX2_MESR_MERR9_Pos               _UINT32_(9)                                          /* (HMATRIX2_MESR) Master 9 Access Error Position */
#define HMATRIX2_MESR_MERR9_Msk               (_UINT32_(0x1) << HMATRIX2_MESR_MERR9_Pos)           /* (HMATRIX2_MESR) Master 9 Access Error Mask */
#define HMATRIX2_MESR_MERR9(value)            (HMATRIX2_MESR_MERR9_Msk & (_UINT32_(value) << HMATRIX2_MESR_MERR9_Pos)) /* Assigment of value for MERR9 in the HMATRIX2_MESR register */
#define HMATRIX2_MESR_MERR10_Pos              _UINT32_(10)                                         /* (HMATRIX2_MESR) Master 10 Access Error Position */
#define HMATRIX2_MESR_MERR10_Msk              (_UINT32_(0x1) << HMATRIX2_MESR_MERR10_Pos)          /* (HMATRIX2_MESR) Master 10 Access Error Mask */
#define HMATRIX2_MESR_MERR10(value)           (HMATRIX2_MESR_MERR10_Msk & (_UINT32_(value) << HMATRIX2_MESR_MERR10_Pos)) /* Assigment of value for MERR10 in the HMATRIX2_MESR register */
#define HMATRIX2_MESR_MERR11_Pos              _UINT32_(11)                                         /* (HMATRIX2_MESR) Master 11 Access Error Position */
#define HMATRIX2_MESR_MERR11_Msk              (_UINT32_(0x1) << HMATRIX2_MESR_MERR11_Pos)          /* (HMATRIX2_MESR) Master 11 Access Error Mask */
#define HMATRIX2_MESR_MERR11(value)           (HMATRIX2_MESR_MERR11_Msk & (_UINT32_(value) << HMATRIX2_MESR_MERR11_Pos)) /* Assigment of value for MERR11 in the HMATRIX2_MESR register */
#define HMATRIX2_MESR_MERR12_Pos              _UINT32_(12)                                         /* (HMATRIX2_MESR) Master 12 Access Error Position */
#define HMATRIX2_MESR_MERR12_Msk              (_UINT32_(0x1) << HMATRIX2_MESR_MERR12_Pos)          /* (HMATRIX2_MESR) Master 12 Access Error Mask */
#define HMATRIX2_MESR_MERR12(value)           (HMATRIX2_MESR_MERR12_Msk & (_UINT32_(value) << HMATRIX2_MESR_MERR12_Pos)) /* Assigment of value for MERR12 in the HMATRIX2_MESR register */
#define HMATRIX2_MESR_MERR13_Pos              _UINT32_(13)                                         /* (HMATRIX2_MESR) Master 13 Access Error Position */
#define HMATRIX2_MESR_MERR13_Msk              (_UINT32_(0x1) << HMATRIX2_MESR_MERR13_Pos)          /* (HMATRIX2_MESR) Master 13 Access Error Mask */
#define HMATRIX2_MESR_MERR13(value)           (HMATRIX2_MESR_MERR13_Msk & (_UINT32_(value) << HMATRIX2_MESR_MERR13_Pos)) /* Assigment of value for MERR13 in the HMATRIX2_MESR register */
#define HMATRIX2_MESR_MERR14_Pos              _UINT32_(14)                                         /* (HMATRIX2_MESR) Master 14 Access Error Position */
#define HMATRIX2_MESR_MERR14_Msk              (_UINT32_(0x1) << HMATRIX2_MESR_MERR14_Pos)          /* (HMATRIX2_MESR) Master 14 Access Error Mask */
#define HMATRIX2_MESR_MERR14(value)           (HMATRIX2_MESR_MERR14_Msk & (_UINT32_(value) << HMATRIX2_MESR_MERR14_Pos)) /* Assigment of value for MERR14 in the HMATRIX2_MESR register */
#define HMATRIX2_MESR_MERR15_Pos              _UINT32_(15)                                         /* (HMATRIX2_MESR) Master 15 Access Error Position */
#define HMATRIX2_MESR_MERR15_Msk              (_UINT32_(0x1) << HMATRIX2_MESR_MERR15_Pos)          /* (HMATRIX2_MESR) Master 15 Access Error Mask */
#define HMATRIX2_MESR_MERR15(value)           (HMATRIX2_MESR_MERR15_Msk & (_UINT32_(value) << HMATRIX2_MESR_MERR15_Pos)) /* Assigment of value for MERR15 in the HMATRIX2_MESR register */
#define HMATRIX2_MESR_Msk                     _UINT32_(0x0000FFFF)                                 /* (HMATRIX2_MESR) Register Mask  */

#define HMATRIX2_MESR_MERR_Pos                _UINT32_(0)                                          /* (HMATRIX2_MESR Position) Master x5 Access Error */
#define HMATRIX2_MESR_MERR_Msk                (_UINT32_(0xFFFF) << HMATRIX2_MESR_MERR_Pos)         /* (HMATRIX2_MESR Mask) MERR */
#define HMATRIX2_MESR_MERR(value)             (HMATRIX2_MESR_MERR_Msk & (_UINT32_(value) << HMATRIX2_MESR_MERR_Pos)) 

/* -------- HMATRIX2_MEAR : (HMATRIX2 Offset: 0x160) ( R/ 32) Master Error Address -------- */
#define HMATRIX2_MEAR_Msk                     _UINT32_(0x00000000)                                 /* (HMATRIX2_MEAR) Register Mask  */


/** \brief HMATRIX2 register offsets definitions */
#define HMATRIX2_PRAS_REG_OFST         _UINT32_(0x00)      /* (HMATRIX2_PRAS) Priority A for Slave Offset */
#define HMATRIX2_PRBS_REG_OFST         _UINT32_(0x04)      /* (HMATRIX2_PRBS) Priority B for Slave Offset */
#define HMATRIX2_MCFG_REG_OFST         _UINT32_(0x00)      /* (HMATRIX2_MCFG) Master Configuration Offset */
#define HMATRIX2_MCFG0_REG_OFST        _UINT32_(0x00)      /* (HMATRIX2_MCFG0) Master Configuration Offset */
#define HMATRIX2_MCFG1_REG_OFST        _UINT32_(0x04)      /* (HMATRIX2_MCFG1) Master Configuration Offset */
#define HMATRIX2_MCFG2_REG_OFST        _UINT32_(0x08)      /* (HMATRIX2_MCFG2) Master Configuration Offset */
#define HMATRIX2_MCFG3_REG_OFST        _UINT32_(0x0C)      /* (HMATRIX2_MCFG3) Master Configuration Offset */
#define HMATRIX2_MCFG4_REG_OFST        _UINT32_(0x10)      /* (HMATRIX2_MCFG4) Master Configuration Offset */
#define HMATRIX2_MCFG5_REG_OFST        _UINT32_(0x14)      /* (HMATRIX2_MCFG5) Master Configuration Offset */
#define HMATRIX2_MCFG6_REG_OFST        _UINT32_(0x18)      /* (HMATRIX2_MCFG6) Master Configuration Offset */
#define HMATRIX2_MCFG7_REG_OFST        _UINT32_(0x1C)      /* (HMATRIX2_MCFG7) Master Configuration Offset */
#define HMATRIX2_MCFG8_REG_OFST        _UINT32_(0x20)      /* (HMATRIX2_MCFG8) Master Configuration Offset */
#define HMATRIX2_MCFG9_REG_OFST        _UINT32_(0x24)      /* (HMATRIX2_MCFG9) Master Configuration Offset */
#define HMATRIX2_MCFG10_REG_OFST       _UINT32_(0x28)      /* (HMATRIX2_MCFG10) Master Configuration Offset */
#define HMATRIX2_MCFG11_REG_OFST       _UINT32_(0x2C)      /* (HMATRIX2_MCFG11) Master Configuration Offset */
#define HMATRIX2_MCFG12_REG_OFST       _UINT32_(0x30)      /* (HMATRIX2_MCFG12) Master Configuration Offset */
#define HMATRIX2_MCFG13_REG_OFST       _UINT32_(0x34)      /* (HMATRIX2_MCFG13) Master Configuration Offset */
#define HMATRIX2_MCFG14_REG_OFST       _UINT32_(0x38)      /* (HMATRIX2_MCFG14) Master Configuration Offset */
#define HMATRIX2_MCFG15_REG_OFST       _UINT32_(0x3C)      /* (HMATRIX2_MCFG15) Master Configuration Offset */
#define HMATRIX2_SCFG_REG_OFST         _UINT32_(0x40)      /* (HMATRIX2_SCFG) Slave Configuration Offset */
#define HMATRIX2_SCFG0_REG_OFST        _UINT32_(0x40)      /* (HMATRIX2_SCFG0) Slave Configuration Offset */
#define HMATRIX2_SCFG1_REG_OFST        _UINT32_(0x44)      /* (HMATRIX2_SCFG1) Slave Configuration Offset */
#define HMATRIX2_SCFG2_REG_OFST        _UINT32_(0x48)      /* (HMATRIX2_SCFG2) Slave Configuration Offset */
#define HMATRIX2_SCFG3_REG_OFST        _UINT32_(0x4C)      /* (HMATRIX2_SCFG3) Slave Configuration Offset */
#define HMATRIX2_SCFG4_REG_OFST        _UINT32_(0x50)      /* (HMATRIX2_SCFG4) Slave Configuration Offset */
#define HMATRIX2_SCFG5_REG_OFST        _UINT32_(0x54)      /* (HMATRIX2_SCFG5) Slave Configuration Offset */
#define HMATRIX2_SCFG6_REG_OFST        _UINT32_(0x58)      /* (HMATRIX2_SCFG6) Slave Configuration Offset */
#define HMATRIX2_SCFG7_REG_OFST        _UINT32_(0x5C)      /* (HMATRIX2_SCFG7) Slave Configuration Offset */
#define HMATRIX2_SCFG8_REG_OFST        _UINT32_(0x60)      /* (HMATRIX2_SCFG8) Slave Configuration Offset */
#define HMATRIX2_SCFG9_REG_OFST        _UINT32_(0x64)      /* (HMATRIX2_SCFG9) Slave Configuration Offset */
#define HMATRIX2_SCFG10_REG_OFST       _UINT32_(0x68)      /* (HMATRIX2_SCFG10) Slave Configuration Offset */
#define HMATRIX2_SCFG11_REG_OFST       _UINT32_(0x6C)      /* (HMATRIX2_SCFG11) Slave Configuration Offset */
#define HMATRIX2_SCFG12_REG_OFST       _UINT32_(0x70)      /* (HMATRIX2_SCFG12) Slave Configuration Offset */
#define HMATRIX2_MRCR_REG_OFST         _UINT32_(0x100)     /* (HMATRIX2_MRCR) Master Remap Control Offset */
#define HMATRIX2_SFR_REG_OFST          _UINT32_(0x110)     /* (HMATRIX2_SFR) Special Function Offset */
#define HMATRIX2_SFR0_REG_OFST         _UINT32_(0x110)     /* (HMATRIX2_SFR0) Special Function Offset */
#define HMATRIX2_SFR1_REG_OFST         _UINT32_(0x114)     /* (HMATRIX2_SFR1) Special Function Offset */
#define HMATRIX2_SFR2_REG_OFST         _UINT32_(0x118)     /* (HMATRIX2_SFR2) Special Function Offset */
#define HMATRIX2_SFR3_REG_OFST         _UINT32_(0x11C)     /* (HMATRIX2_SFR3) Special Function Offset */
#define HMATRIX2_SFR4_REG_OFST         _UINT32_(0x120)     /* (HMATRIX2_SFR4) Special Function Offset */
#define HMATRIX2_SFR5_REG_OFST         _UINT32_(0x124)     /* (HMATRIX2_SFR5) Special Function Offset */
#define HMATRIX2_SFR6_REG_OFST         _UINT32_(0x128)     /* (HMATRIX2_SFR6) Special Function Offset */
#define HMATRIX2_SFR7_REG_OFST         _UINT32_(0x12C)     /* (HMATRIX2_SFR7) Special Function Offset */
#define HMATRIX2_SFR8_REG_OFST         _UINT32_(0x130)     /* (HMATRIX2_SFR8) Special Function Offset */
#define HMATRIX2_SFR9_REG_OFST         _UINT32_(0x134)     /* (HMATRIX2_SFR9) Special Function Offset */
#define HMATRIX2_SFR10_REG_OFST        _UINT32_(0x138)     /* (HMATRIX2_SFR10) Special Function Offset */
#define HMATRIX2_SFR11_REG_OFST        _UINT32_(0x13C)     /* (HMATRIX2_SFR11) Special Function Offset */
#define HMATRIX2_SFR12_REG_OFST        _UINT32_(0x140)     /* (HMATRIX2_SFR12) Special Function Offset */
#define HMATRIX2_MEIER_REG_OFST        _UINT32_(0x150)     /* (HMATRIX2_MEIER) Master Error Interrupt Enable Offset */
#define HMATRIX2_MEIDR_REG_OFST        _UINT32_(0x154)     /* (HMATRIX2_MEIDR) Master Error Interrupt Disable Offset */
#define HMATRIX2_MEIMR_REG_OFST        _UINT32_(0x158)     /* (HMATRIX2_MEIMR) Master Error Interrupt Mask Offset */
#define HMATRIX2_MESR_REG_OFST         _UINT32_(0x15C)     /* (HMATRIX2_MESR) Master Error Status Offset */
#define HMATRIX2_MEAR_REG_OFST         _UINT32_(0x160)     /* (HMATRIX2_MEAR) Master Error Address Offset */
#define HMATRIX2_MEAR0_REG_OFST        _UINT32_(0x160)     /* (HMATRIX2_MEAR0) Master Error Address Offset */
#define HMATRIX2_MEAR1_REG_OFST        _UINT32_(0x164)     /* (HMATRIX2_MEAR1) Master Error Address Offset */
#define HMATRIX2_MEAR2_REG_OFST        _UINT32_(0x168)     /* (HMATRIX2_MEAR2) Master Error Address Offset */
#define HMATRIX2_MEAR3_REG_OFST        _UINT32_(0x16C)     /* (HMATRIX2_MEAR3) Master Error Address Offset */
#define HMATRIX2_MEAR4_REG_OFST        _UINT32_(0x170)     /* (HMATRIX2_MEAR4) Master Error Address Offset */
#define HMATRIX2_MEAR5_REG_OFST        _UINT32_(0x174)     /* (HMATRIX2_MEAR5) Master Error Address Offset */
#define HMATRIX2_MEAR6_REG_OFST        _UINT32_(0x178)     /* (HMATRIX2_MEAR6) Master Error Address Offset */
#define HMATRIX2_MEAR7_REG_OFST        _UINT32_(0x17C)     /* (HMATRIX2_MEAR7) Master Error Address Offset */
#define HMATRIX2_MEAR8_REG_OFST        _UINT32_(0x180)     /* (HMATRIX2_MEAR8) Master Error Address Offset */
#define HMATRIX2_MEAR9_REG_OFST        _UINT32_(0x184)     /* (HMATRIX2_MEAR9) Master Error Address Offset */
#define HMATRIX2_MEAR10_REG_OFST       _UINT32_(0x188)     /* (HMATRIX2_MEAR10) Master Error Address Offset */
#define HMATRIX2_MEAR11_REG_OFST       _UINT32_(0x18C)     /* (HMATRIX2_MEAR11) Master Error Address Offset */
#define HMATRIX2_MEAR12_REG_OFST       _UINT32_(0x190)     /* (HMATRIX2_MEAR12) Master Error Address Offset */
#define HMATRIX2_MEAR13_REG_OFST       _UINT32_(0x194)     /* (HMATRIX2_MEAR13) Master Error Address Offset */
#define HMATRIX2_MEAR14_REG_OFST       _UINT32_(0x198)     /* (HMATRIX2_MEAR14) Master Error Address Offset */
#define HMATRIX2_MEAR15_REG_OFST       _UINT32_(0x19C)     /* (HMATRIX2_MEAR15) Master Error Address Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief PRS register API structure */
typedef struct
{
  __IO  uint32_t                       HMATRIX2_PRAS;      /**< Offset: 0x00 (R/W  32) Priority A for Slave */
  __IO  uint32_t                       HMATRIX2_PRBS;      /**< Offset: 0x04 (R/W  32) Priority B for Slave */
} hmatrix2_prs_registers_t;

#define HMATRIX2_PRS_NUMBER 13

/** \brief HMATRIX2 register API structure */
typedef struct
{  /* HSB Matrix */
  __IO  uint32_t                       HMATRIX2_MCFG[16];  /**< Offset: 0x00 (R/W  32) Master Configuration */
  __IO  uint32_t                       HMATRIX2_SCFG[13];  /**< Offset: 0x40 (R/W  32) Slave Configuration */
  __I   uint8_t                        Reserved1[0x0C];
        hmatrix2_prs_registers_t       PRS[HMATRIX2_PRS_NUMBER]; /**< Offset: 0x80  */
  __I   uint8_t                        Reserved2[0x18];
  __IO  uint32_t                       HMATRIX2_MRCR;      /**< Offset: 0x100 (R/W  32) Master Remap Control */
  __I   uint8_t                        Reserved3[0x0C];
  __IO  uint32_t                       HMATRIX2_SFR[13];   /**< Offset: 0x110 (R/W  32) Special Function */
  __I   uint8_t                        Reserved4[0x0C];
  __O   uint32_t                       HMATRIX2_MEIER;     /**< Offset: 0x150 ( /W  32) Master Error Interrupt Enable */
  __O   uint32_t                       HMATRIX2_MEIDR;     /**< Offset: 0x154 ( /W  32) Master Error Interrupt Disable */
  __I   uint32_t                       HMATRIX2_MEIMR;     /**< Offset: 0x158 (R/   32) Master Error Interrupt Mask */
  __I   uint32_t                       HMATRIX2_MESR;      /**< Offset: 0x15C (R/   32) Master Error Status */
  __I   uint32_t                       HMATRIX2_MEAR[16];  /**< Offset: 0x160 (R/   32) Master Error Address */
} hmatrix2_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CKSG01_HMATRIX2_COMPONENT_H_ */
