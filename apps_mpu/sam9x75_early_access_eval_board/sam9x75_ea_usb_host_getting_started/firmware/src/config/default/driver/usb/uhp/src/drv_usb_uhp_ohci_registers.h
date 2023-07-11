/**
 * \brief Component description for UHP_OHCI
 *
 * Copyright (c) 2019 Microchip Technology Inc. and its subsidiaries.
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

/* file generated from device description version 2019-01-10T17:30:45Z */
#ifndef _DA78_UHP_OHCI_COMPONENT_H_
#define _DA78_UHP_OHCI_COMPONENT_H_
#define _DA78_UHP_OHCI_COMPONENT_         /**< \deprecated  Backward compatibility for ASF */

#ifndef _UINT32_ 
#  define _UINT32_(x)  ((uint32_t)(x))
#endif

/** \addtogroup PIC32CZ_DA78 USB Host Full Speed Port
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR UHP_OHCI */
/* ========================================================================== */
#ifndef COMPONENT_TYPEDEF_STYLE
  #define COMPONENT_TYPEDEF_STYLE 'R'  /**< Defines default style of typedefs for the component header files ('R' = RFO, 'N' = NTO)*/
#endif

#define UHP_OHCI_SYS1                       /**< (UHP_OHCI) Module ID */
#define REV_UHP_OHCI R                      /**< (UHP_OHCI) Module revision */

/* -------- UHP_OHCI_HCREVISION : (UHP_OHCI Offset: 0x00) (R/ 32) UHP OHCI Revision Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t REV:4;                     /**< bit:   0..3  Revision                                 */
    uint32_t :28;                       /**< bit:  4..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCREVISION_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCREVISION_OFFSET          (0x00)                                        /**<  (UHP_OHCI_HCREVISION) UHP OHCI Revision Register  Offset */

#define UHP_OHCI_HCREVISION_REV_Pos         0                                              /**< (UHP_OHCI_HCREVISION) Revision Position */
#define UHP_OHCI_HCREVISION_REV_Msk         (_UINT32_(0xF) << UHP_OHCI_HCREVISION_REV_Pos)      /**< (UHP_OHCI_HCREVISION) Revision Mask */
#define UHP_OHCI_HCREVISION_REV(value)      (UHP_OHCI_HCREVISION_REV_Msk & ((value) << UHP_OHCI_HCREVISION_REV_Pos))
#define UHP_OHCI_HCREVISION_MASK            _UINT32_(0x0F)                                      /**< \deprecated (UHP_OHCI_HCREVISION) Register MASK  (Use UHP_OHCI_HCREVISION_Msk instead)  */
#define UHP_OHCI_HCREVISION_Msk             _UINT32_(0x0F)                                      /**< (UHP_OHCI_HCREVISION) Register Mask  */


/* -------- UHP_OHCI_HCCONTROL : (UHP_OHCI Offset: 0x04) (R/W 32) UHP OHCI HcControl Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t CBSR:2;                    /**< bit:   0..1  ControlBulkServiceRatio                  */
    uint32_t PLE:1;                     /**< bit:      2  PeriodicListEnable                       */
    uint32_t IE:1;                      /**< bit:      3  IsochronousEnable                        */
    uint32_t CLE:1;                     /**< bit:      4  ControlListEnable                        */
    uint32_t BLE:1;                     /**< bit:      5  BulkListEnable                           */
    uint32_t HCFS:2;                    /**< bit:   6..7  HostControllerFunctionalState            */
    uint32_t IR:1;                      /**< bit:      8  InterruptRouting                         */
    uint32_t RWC:1;                     /**< bit:      9  RemoteWakeupConnected                    */
    uint32_t RWE:1;                     /**< bit:     10  RemoteWakeupEnable                       */
    uint32_t :21;                       /**< bit: 11..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCCONTROL_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCCONTROL_OFFSET           (0x04)                                        /**<  (UHP_OHCI_HCCONTROL) UHP OHCI HcControl Register  Offset */

#define UHP_OHCI_HCCONTROL_CBSR_Pos         0                                              /**< (UHP_OHCI_HCCONTROL) ControlBulkServiceRatio Position */
#define UHP_OHCI_HCCONTROL_CBSR_Msk         (_UINT32_(0x3) << UHP_OHCI_HCCONTROL_CBSR_Pos)      /**< (UHP_OHCI_HCCONTROL) ControlBulkServiceRatio Mask */
#define UHP_OHCI_HCCONTROL_CBSR(value)      (UHP_OHCI_HCCONTROL_CBSR_Msk & ((value) << UHP_OHCI_HCCONTROL_CBSR_Pos))
#define UHP_OHCI_HCCONTROL_PLE_Pos          2                                              /**< (UHP_OHCI_HCCONTROL) PeriodicListEnable Position */
#define UHP_OHCI_HCCONTROL_PLE_Msk          (_UINT32_(0x1) << UHP_OHCI_HCCONTROL_PLE_Pos)       /**< (UHP_OHCI_HCCONTROL) PeriodicListEnable Mask */
#define UHP_OHCI_HCCONTROL_PLE              UHP_OHCI_HCCONTROL_PLE_Msk                     /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCCONTROL_PLE_Msk instead */
#define UHP_OHCI_HCCONTROL_IE_Pos           3                                              /**< (UHP_OHCI_HCCONTROL) IsochronousEnable Position */
#define UHP_OHCI_HCCONTROL_IE_Msk           (_UINT32_(0x1) << UHP_OHCI_HCCONTROL_IE_Pos)        /**< (UHP_OHCI_HCCONTROL) IsochronousEnable Mask */
#define UHP_OHCI_HCCONTROL_IE               UHP_OHCI_HCCONTROL_IE_Msk                      /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCCONTROL_IE_Msk instead */
#define UHP_OHCI_HCCONTROL_CLE_Pos          4                                              /**< (UHP_OHCI_HCCONTROL) ControlListEnable Position */
#define UHP_OHCI_HCCONTROL_CLE_Msk          (_UINT32_(0x1) << UHP_OHCI_HCCONTROL_CLE_Pos)       /**< (UHP_OHCI_HCCONTROL) ControlListEnable Mask */
#define UHP_OHCI_HCCONTROL_CLE              UHP_OHCI_HCCONTROL_CLE_Msk                     /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCCONTROL_CLE_Msk instead */
#define UHP_OHCI_HCCONTROL_BLE_Pos          5                                              /**< (UHP_OHCI_HCCONTROL) BulkListEnable Position */
#define UHP_OHCI_HCCONTROL_BLE_Msk          (_UINT32_(0x1) << UHP_OHCI_HCCONTROL_BLE_Pos)       /**< (UHP_OHCI_HCCONTROL) BulkListEnable Mask */
#define UHP_OHCI_HCCONTROL_BLE              UHP_OHCI_HCCONTROL_BLE_Msk                     /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCCONTROL_BLE_Msk instead */
#define UHP_OHCI_HCCONTROL_HCFS_Pos         6                                              /**< (UHP_OHCI_HCCONTROL) HostControllerFunctionalState Position */
#define UHP_OHCI_HCCONTROL_HCFS_Msk         (_UINT32_(0x3) << UHP_OHCI_HCCONTROL_HCFS_Pos)      /**< (UHP_OHCI_HCCONTROL) HostControllerFunctionalState Mask */
#define UHP_OHCI_HCCONTROL_HCFS(value)      (UHP_OHCI_HCCONTROL_HCFS_Msk & ((value) << UHP_OHCI_HCCONTROL_HCFS_Pos))
#define UHP_OHCI_HCCONTROL_IR_Pos           8                                              /**< (UHP_OHCI_HCCONTROL) InterruptRouting Position */
#define UHP_OHCI_HCCONTROL_IR_Msk           (_UINT32_(0x1) << UHP_OHCI_HCCONTROL_IR_Pos)        /**< (UHP_OHCI_HCCONTROL) InterruptRouting Mask */
#define UHP_OHCI_HCCONTROL_IR               UHP_OHCI_HCCONTROL_IR_Msk                      /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCCONTROL_IR_Msk instead */
#define UHP_OHCI_HCCONTROL_RWC_Pos          9                                              /**< (UHP_OHCI_HCCONTROL) RemoteWakeupConnected Position */
#define UHP_OHCI_HCCONTROL_RWC_Msk          (_UINT32_(0x1) << UHP_OHCI_HCCONTROL_RWC_Pos)       /**< (UHP_OHCI_HCCONTROL) RemoteWakeupConnected Mask */
#define UHP_OHCI_HCCONTROL_RWC              UHP_OHCI_HCCONTROL_RWC_Msk                     /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCCONTROL_RWC_Msk instead */
#define UHP_OHCI_HCCONTROL_RWE_Pos          10                                             /**< (UHP_OHCI_HCCONTROL) RemoteWakeupEnable Position */
#define UHP_OHCI_HCCONTROL_RWE_Msk          (_UINT32_(0x1) << UHP_OHCI_HCCONTROL_RWE_Pos)       /**< (UHP_OHCI_HCCONTROL) RemoteWakeupEnable Mask */
#define UHP_OHCI_HCCONTROL_RWE              UHP_OHCI_HCCONTROL_RWE_Msk                     /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCCONTROL_RWE_Msk instead */
#define UHP_OHCI_HCCONTROL_MASK             _UINT32_(0x7FF)                                     /**< \deprecated (UHP_OHCI_HCCONTROL) Register MASK  (Use UHP_OHCI_HCCONTROL_Msk instead)  */
#define UHP_OHCI_HCCONTROL_Msk              _UINT32_(0x7FF)                                     /**< (UHP_OHCI_HCCONTROL) Register Mask  */


/* -------- UHP_OHCI_HCCOMMANDSTATUS : (UHP_OHCI Offset: 0x08) (R/W 32) UHP_OHCI HcInterruptStatus Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t HCR:1;                     /**< bit:      0  HostControllerReset                      */
    uint32_t CLF:1;                     /**< bit:      1  ControlListFilled                        */
    uint32_t BLF:1;                     /**< bit:      2  BulkListFilled                           */
    uint32_t OCR:1;                     /**< bit:      3  OwnershipChangeRequest                   */
    uint32_t :12;                       /**< bit:  4..15  Reserved */
    uint32_t SOC:2;                     /**< bit: 16..17  SchedulingOverrunCount                   */
    uint32_t :14;                       /**< bit: 18..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCCOMMANDSTATUS_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCCOMMANDSTATUS_OFFSET     (0x08)                                        /**<  (UHP_OHCI_HCCOMMANDSTATUS) UHP_OHCI HcInterruptStatus Register  Offset */

#define UHP_OHCI_HCCOMMANDSTATUS_HCR_Pos    0                                              /**< (UHP_OHCI_HCCOMMANDSTATUS) HostControllerReset Position */
#define UHP_OHCI_HCCOMMANDSTATUS_HCR_Msk    (_UINT32_(0x1) << UHP_OHCI_HCCOMMANDSTATUS_HCR_Pos)  /**< (UHP_OHCI_HCCOMMANDSTATUS) HostControllerReset Mask */
#define UHP_OHCI_HCCOMMANDSTATUS_HCR        UHP_OHCI_HCCOMMANDSTATUS_HCR_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCCOMMANDSTATUS_HCR_Msk instead */
#define UHP_OHCI_HCCOMMANDSTATUS_CLF_Pos    1                                              /**< (UHP_OHCI_HCCOMMANDSTATUS) ControlListFilled Position */
#define UHP_OHCI_HCCOMMANDSTATUS_CLF_Msk    (_UINT32_(0x1) << UHP_OHCI_HCCOMMANDSTATUS_CLF_Pos)  /**< (UHP_OHCI_HCCOMMANDSTATUS) ControlListFilled Mask */
#define UHP_OHCI_HCCOMMANDSTATUS_CLF        UHP_OHCI_HCCOMMANDSTATUS_CLF_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCCOMMANDSTATUS_CLF_Msk instead */
#define UHP_OHCI_HCCOMMANDSTATUS_BLF_Pos    2                                              /**< (UHP_OHCI_HCCOMMANDSTATUS) BulkListFilled Position */
#define UHP_OHCI_HCCOMMANDSTATUS_BLF_Msk    (_UINT32_(0x1) << UHP_OHCI_HCCOMMANDSTATUS_BLF_Pos)  /**< (UHP_OHCI_HCCOMMANDSTATUS) BulkListFilled Mask */
#define UHP_OHCI_HCCOMMANDSTATUS_BLF        UHP_OHCI_HCCOMMANDSTATUS_BLF_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCCOMMANDSTATUS_BLF_Msk instead */
#define UHP_OHCI_HCCOMMANDSTATUS_OCR_Pos    3                                              /**< (UHP_OHCI_HCCOMMANDSTATUS) OwnershipChangeRequest Position */
#define UHP_OHCI_HCCOMMANDSTATUS_OCR_Msk    (_UINT32_(0x1) << UHP_OHCI_HCCOMMANDSTATUS_OCR_Pos)  /**< (UHP_OHCI_HCCOMMANDSTATUS) OwnershipChangeRequest Mask */
#define UHP_OHCI_HCCOMMANDSTATUS_OCR        UHP_OHCI_HCCOMMANDSTATUS_OCR_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCCOMMANDSTATUS_OCR_Msk instead */
#define UHP_OHCI_HCCOMMANDSTATUS_SOC_Pos    16                                             /**< (UHP_OHCI_HCCOMMANDSTATUS) SchedulingOverrunCount Position */
#define UHP_OHCI_HCCOMMANDSTATUS_SOC_Msk    (_UINT32_(0x3) << UHP_OHCI_HCCOMMANDSTATUS_SOC_Pos)  /**< (UHP_OHCI_HCCOMMANDSTATUS) SchedulingOverrunCount Mask */
#define UHP_OHCI_HCCOMMANDSTATUS_SOC(value) (UHP_OHCI_HCCOMMANDSTATUS_SOC_Msk & ((value) << UHP_OHCI_HCCOMMANDSTATUS_SOC_Pos))
#define UHP_OHCI_HCCOMMANDSTATUS_MASK       _UINT32_(0x3000F)                                   /**< \deprecated (UHP_OHCI_HCCOMMANDSTATUS) Register MASK  (Use UHP_OHCI_HCCOMMANDSTATUS_Msk instead)  */
#define UHP_OHCI_HCCOMMANDSTATUS_Msk        _UINT32_(0x3000F)                                   /**< (UHP_OHCI_HCCOMMANDSTATUS) Register Mask  */


/* -------- UHP_OHCI_HCINTERRUPTSTATUS : (UHP_OHCI Offset: 0x0c) (R/W 32) UHP OHCI HcInterruptStatus Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t SO:1;                      /**< bit:      0  SchedulingOverrun                        */
    uint32_t WDH:1;                     /**< bit:      1  WritebackDoneHead                        */
    uint32_t SF:1;                      /**< bit:      2  StartofFrame                             */
    uint32_t RD:1;                      /**< bit:      3  ResumeDetected                           */
    uint32_t UE:1;                      /**< bit:      4  UnrecoverableError                       */
    uint32_t FNO:1;                     /**< bit:      5  FrameNumberOverflow                      */
    uint32_t RHSC:1;                    /**< bit:      6  RootHubStatusChange                      */
    uint32_t :23;                       /**< bit:  7..29  Reserved */
    uint32_t OC:1;                      /**< bit:     30  OwnershipChange                          */
    uint32_t :1;                        /**< bit:     31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCINTERRUPTSTATUS_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCINTERRUPTSTATUS_OFFSET   (0x0C)                                        /**<  (UHP_OHCI_HCINTERRUPTSTATUS) UHP OHCI HcInterruptStatus Register  Offset */

#define UHP_OHCI_HCINTERRUPTSTATUS_SO_Pos   0                                              /**< (UHP_OHCI_HCINTERRUPTSTATUS) SchedulingOverrun Position */
#define UHP_OHCI_HCINTERRUPTSTATUS_SO_Msk   (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTSTATUS_SO_Pos)  /**< (UHP_OHCI_HCINTERRUPTSTATUS) SchedulingOverrun Mask */
#define UHP_OHCI_HCINTERRUPTSTATUS_SO       UHP_OHCI_HCINTERRUPTSTATUS_SO_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTSTATUS_SO_Msk instead */
#define UHP_OHCI_HCINTERRUPTSTATUS_WDH_Pos  1                                              /**< (UHP_OHCI_HCINTERRUPTSTATUS) WritebackDoneHead Position */
#define UHP_OHCI_HCINTERRUPTSTATUS_WDH_Msk  (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTSTATUS_WDH_Pos)  /**< (UHP_OHCI_HCINTERRUPTSTATUS) WritebackDoneHead Mask */
#define UHP_OHCI_HCINTERRUPTSTATUS_WDH      UHP_OHCI_HCINTERRUPTSTATUS_WDH_Msk             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTSTATUS_WDH_Msk instead */
#define UHP_OHCI_HCINTERRUPTSTATUS_SF_Pos   2                                              /**< (UHP_OHCI_HCINTERRUPTSTATUS) StartofFrame Position */
#define UHP_OHCI_HCINTERRUPTSTATUS_SF_Msk   (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTSTATUS_SF_Pos)  /**< (UHP_OHCI_HCINTERRUPTSTATUS) StartofFrame Mask */
#define UHP_OHCI_HCINTERRUPTSTATUS_SF       UHP_OHCI_HCINTERRUPTSTATUS_SF_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTSTATUS_SF_Msk instead */
#define UHP_OHCI_HCINTERRUPTSTATUS_RD_Pos   3                                              /**< (UHP_OHCI_HCINTERRUPTSTATUS) ResumeDetected Position */
#define UHP_OHCI_HCINTERRUPTSTATUS_RD_Msk   (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTSTATUS_RD_Pos)  /**< (UHP_OHCI_HCINTERRUPTSTATUS) ResumeDetected Mask */
#define UHP_OHCI_HCINTERRUPTSTATUS_RD       UHP_OHCI_HCINTERRUPTSTATUS_RD_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTSTATUS_RD_Msk instead */
#define UHP_OHCI_HCINTERRUPTSTATUS_UE_Pos   4                                              /**< (UHP_OHCI_HCINTERRUPTSTATUS) UnrecoverableError Position */
#define UHP_OHCI_HCINTERRUPTSTATUS_UE_Msk   (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTSTATUS_UE_Pos)  /**< (UHP_OHCI_HCINTERRUPTSTATUS) UnrecoverableError Mask */
#define UHP_OHCI_HCINTERRUPTSTATUS_UE       UHP_OHCI_HCINTERRUPTSTATUS_UE_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTSTATUS_UE_Msk instead */
#define UHP_OHCI_HCINTERRUPTSTATUS_FNO_Pos  5                                              /**< (UHP_OHCI_HCINTERRUPTSTATUS) FrameNumberOverflow Position */
#define UHP_OHCI_HCINTERRUPTSTATUS_FNO_Msk  (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTSTATUS_FNO_Pos)  /**< (UHP_OHCI_HCINTERRUPTSTATUS) FrameNumberOverflow Mask */
#define UHP_OHCI_HCINTERRUPTSTATUS_FNO      UHP_OHCI_HCINTERRUPTSTATUS_FNO_Msk             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTSTATUS_FNO_Msk instead */
#define UHP_OHCI_HCINTERRUPTSTATUS_RHSC_Pos 6                                              /**< (UHP_OHCI_HCINTERRUPTSTATUS) RootHubStatusChange Position */
#define UHP_OHCI_HCINTERRUPTSTATUS_RHSC_Msk (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTSTATUS_RHSC_Pos)  /**< (UHP_OHCI_HCINTERRUPTSTATUS) RootHubStatusChange Mask */
#define UHP_OHCI_HCINTERRUPTSTATUS_RHSC     UHP_OHCI_HCINTERRUPTSTATUS_RHSC_Msk            /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTSTATUS_RHSC_Msk instead */
#define UHP_OHCI_HCINTERRUPTSTATUS_OC_Pos   30                                             /**< (UHP_OHCI_HCINTERRUPTSTATUS) OwnershipChange Position */
#define UHP_OHCI_HCINTERRUPTSTATUS_OC_Msk   (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTSTATUS_OC_Pos)  /**< (UHP_OHCI_HCINTERRUPTSTATUS) OwnershipChange Mask */
#define UHP_OHCI_HCINTERRUPTSTATUS_OC       UHP_OHCI_HCINTERRUPTSTATUS_OC_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTSTATUS_OC_Msk instead */
#define UHP_OHCI_HCINTERRUPTSTATUS_MASK     _UINT32_(0x4000007F)                                /**< \deprecated (UHP_OHCI_HCINTERRUPTSTATUS) Register MASK  (Use UHP_OHCI_HCINTERRUPTSTATUS_Msk instead)  */
#define UHP_OHCI_HCINTERRUPTSTATUS_Msk      _UINT32_(0x4000007F)                                /**< (UHP_OHCI_HCINTERRUPTSTATUS) Register Mask  */


/* -------- UHP_OHCI_HCINTERRUPTENABLE : (UHP_OHCI Offset: 0x10) (R/W 32) UHP OHCI HcInterruptEnable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t SO:1;                      /**< bit:      0  Enable SchedulingOverrun                 */
    uint32_t WDH:1;                     /**< bit:      1  Enable WritebackDoneHead                 */
    uint32_t SF:1;                      /**< bit:      2  Enable StartofFrame                      */
    uint32_t RD:1;                      /**< bit:      3  Enable ResumeDetected                    */
    uint32_t UE:1;                      /**< bit:      4  Enable UnrecoverableError                */
    uint32_t FNO:1;                     /**< bit:      5  Enable FrameNumberOverflow               */
    uint32_t RHSC:1;                    /**< bit:      6  Enable RootHubStatusChange               */
    uint32_t :23;                       /**< bit:  7..29  Reserved */
    uint32_t OC:1;                      /**< bit:     30  Enable OwnershipChange                   */
    uint32_t MIE:1;                     /**< bit:     31  Enable MasterInterruptEnable             */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCINTERRUPTENABLE_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCINTERRUPTENABLE_OFFSET (0x10)                                        /**<  (UHP_OHCI_HCINTERRUPTENABLE) UHP OHCI HcInterruptEnable Register  Offset */

#define UHP_OHCI_HCINTERRUPTENABLE_SO_Pos 0                                              /**< (UHP_OHCI_HCINTERRUPTENABLE) Enable SchedulingOverrun Position */
#define UHP_OHCI_HCINTERRUPTENABLE_SO_Msk (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTENABLE_SO_Pos)  /**< (UHP_OHCI_HCINTERRUPTENABLE) Enable SchedulingOverrun Mask */
#define UHP_OHCI_HCINTERRUPTENABLE_SO UHP_OHCI_HCINTERRUPTENABLE_SO_Msk     /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTENABLE_SO_Msk instead */
#define UHP_OHCI_HCINTERRUPTENABLE_WDH_Pos 1                                              /**< (UHP_OHCI_HCINTERRUPTENABLE) Enable WritebackDoneHead Position */
#define UHP_OHCI_HCINTERRUPTENABLE_WDH_Msk (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTENABLE_WDH_Pos)  /**< (UHP_OHCI_HCINTERRUPTENABLE) Enable WritebackDoneHead Mask */
#define UHP_OHCI_HCINTERRUPTENABLE_WDH UHP_OHCI_HCINTERRUPTENABLE_WDH_Msk    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTENABLE_WDH_Msk instead */
#define UHP_OHCI_HCINTERRUPTENABLE_SF_Pos 2                                              /**< (UHP_OHCI_HCINTERRUPTENABLE) Enable StartofFrame Position */
#define UHP_OHCI_HCINTERRUPTENABLE_SF_Msk (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTENABLE_SF_Pos)  /**< (UHP_OHCI_HCINTERRUPTENABLE) Enable StartofFrame Mask */
#define UHP_OHCI_HCINTERRUPTENABLE_SF UHP_OHCI_HCINTERRUPTENABLE_SF_Msk     /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTENABLE_SF_Msk instead */
#define UHP_OHCI_HCINTERRUPTENABLE_RD_Pos 3                                              /**< (UHP_OHCI_HCINTERRUPTENABLE) Enable ResumeDetected Position */
#define UHP_OHCI_HCINTERRUPTENABLE_RD_Msk (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTENABLE_RD_Pos)  /**< (UHP_OHCI_HCINTERRUPTENABLE) Enable ResumeDetected Mask */
#define UHP_OHCI_HCINTERRUPTENABLE_RD UHP_OHCI_HCINTERRUPTENABLE_RD_Msk     /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTENABLE_RD_Msk instead */
#define UHP_OHCI_HCINTERRUPTENABLE_UE_Pos 4                                              /**< (UHP_OHCI_HCINTERRUPTENABLE) Enable UnrecoverableError Position */
#define UHP_OHCI_HCINTERRUPTENABLE_UE_Msk (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTENABLE_UE_Pos)  /**< (UHP_OHCI_HCINTERRUPTENABLE) Enable UnrecoverableError Mask */
#define UHP_OHCI_HCINTERRUPTENABLE_UE UHP_OHCI_HCINTERRUPTENABLE_UE_Msk     /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTENABLE_UE_Msk instead */
#define UHP_OHCI_HCINTERRUPTENABLE_FNO_Pos 5                                              /**< (UHP_OHCI_HCINTERRUPTENABLE) Enable FrameNumberOverflow Position */
#define UHP_OHCI_HCINTERRUPTENABLE_FNO_Msk (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTENABLE_FNO_Pos)  /**< (UHP_OHCI_HCINTERRUPTENABLE) Enable FrameNumberOverflow Mask */
#define UHP_OHCI_HCINTERRUPTENABLE_FNO UHP_OHCI_HCINTERRUPTENABLE_FNO_Msk    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTENABLE_FNO_Msk instead */
#define UHP_OHCI_HCINTERRUPTENABLE_RHSC_Pos 6                                              /**< (UHP_OHCI_HCINTERRUPTENABLE) Enable RootHubStatusChange Position */
#define UHP_OHCI_HCINTERRUPTENABLE_RHSC_Msk (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTENABLE_RHSC_Pos)  /**< (UHP_OHCI_HCINTERRUPTENABLE) Enable RootHubStatusChange Mask */
#define UHP_OHCI_HCINTERRUPTENABLE_RHSC UHP_OHCI_HCINTERRUPTENABLE_RHSC_Msk   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTENABLE_RHSC_Msk instead */
#define UHP_OHCI_HCINTERRUPTENABLE_OC_Pos 30                                             /**< (UHP_OHCI_HCINTERRUPTENABLE) Enable OwnershipChange Position */
#define UHP_OHCI_HCINTERRUPTENABLE_OC_Msk (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTENABLE_OC_Pos)  /**< (UHP_OHCI_HCINTERRUPTENABLE) Enable OwnershipChange Mask */
#define UHP_OHCI_HCINTERRUPTENABLE_OC UHP_OHCI_HCINTERRUPTENABLE_OC_Msk     /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTENABLE_OC_Msk instead */
#define UHP_OHCI_HCINTERRUPTENABLE_MIE_Pos 31                                             /**< (UHP_OHCI_HCINTERRUPTENABLE) Enable MasterInterruptEnable Position */
#define UHP_OHCI_HCINTERRUPTENABLE_MIE_Msk (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTENABLE_MIE_Pos)  /**< (UHP_OHCI_HCINTERRUPTENABLE) Enable MasterInterruptEnable Mask */
#define UHP_OHCI_HCINTERRUPTENABLE_MIE UHP_OHCI_HCINTERRUPTENABLE_MIE_Msk    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTENABLE_MIE_Msk instead */
#define UHP_OHCI_HCINTERRUPTENABLE_MASK _UINT32_(0xC000007F)                                /**< \deprecated (UHP_OHCI_HCINTERRUPTENABLE) Register MASK  (Use UHP_OHCI_HCINTERRUPTENABLE_Msk instead)  */
#define UHP_OHCI_HCINTERRUPTENABLE_Msk _UINT32_(0xC000007F)                                /**< (UHP_OHCI_HCINTERRUPTENABLE) Register Mask  */


/* -------- UHP_OHCI_HCINTERRUPTDISABLE : (UHP_OHCI Offset: 0x14) (R/W 32) UHP OHCI HcInterruptDisable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t SO:1;                      /**< bit:      0  Disable SchedulingOverrun                */
    uint32_t WDH:1;                     /**< bit:      1  Disable WritebackDoneHead                */
    uint32_t SF:1;                      /**< bit:      2  Disable StartofFrame                     */
    uint32_t RD:1;                      /**< bit:      3  Disable ResumeDetected                   */
    uint32_t UE:1;                      /**< bit:      4  Disable UnrecoverableError               */
    uint32_t FNO:1;                     /**< bit:      5  Disable FrameNumberOverflow              */
    uint32_t RHSC:1;                    /**< bit:      6  Disable RootHubStatusChange              */
    uint32_t :23;                       /**< bit:  7..29  Reserved */
    uint32_t OC:1;                      /**< bit:     30  Disable OwnershipChange                  */
    uint32_t MIE:1;                     /**< bit:     31  Disable MasterInterruptEnable            */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCINTERRUPTDISABLE_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCINTERRUPTDISABLE_OFFSET  (0x14)                                        /**<  (UHP_OHCI_HCINTERRUPTDISABLE) UHP OHCI HcInterruptDisable Register  Offset */

#define UHP_OHCI_HCINTERRUPTDISABLE_SO_Pos  0                                              /**< (UHP_OHCI_HCINTERRUPTDISABLE) Disable SchedulingOverrun Position */
#define UHP_OHCI_HCINTERRUPTDISABLE_SO_Msk  (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTDISABLE_SO_Pos)  /**< (UHP_OHCI_HCINTERRUPTDISABLE) Disable SchedulingOverrun Mask */
#define UHP_OHCI_HCINTERRUPTDISABLE_SO      UHP_OHCI_HCINTERRUPTDISABLE_SO_Msk             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTDISABLE_SO_Msk instead */
#define UHP_OHCI_HCINTERRUPTDISABLE_WDH_Pos 1                                              /**< (UHP_OHCI_HCINTERRUPTDISABLE) Disable WritebackDoneHead Position */
#define UHP_OHCI_HCINTERRUPTDISABLE_WDH_Msk (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTDISABLE_WDH_Pos)  /**< (UHP_OHCI_HCINTERRUPTDISABLE) Disable WritebackDoneHead Mask */
#define UHP_OHCI_HCINTERRUPTDISABLE_WDH     UHP_OHCI_HCINTERRUPTDISABLE_WDH_Msk            /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTDISABLE_WDH_Msk instead */
#define UHP_OHCI_HCINTERRUPTDISABLE_SF_Pos  2                                              /**< (UHP_OHCI_HCINTERRUPTDISABLE) Disable StartofFrame Position */
#define UHP_OHCI_HCINTERRUPTDISABLE_SF_Msk  (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTDISABLE_SF_Pos)  /**< (UHP_OHCI_HCINTERRUPTDISABLE) Disable StartofFrame Mask */
#define UHP_OHCI_HCINTERRUPTDISABLE_SF      UHP_OHCI_HCINTERRUPTDISABLE_SF_Msk             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTDISABLE_SF_Msk instead */
#define UHP_OHCI_HCINTERRUPTDISABLE_RD_Pos  3                                              /**< (UHP_OHCI_HCINTERRUPTDISABLE) Disable ResumeDetected Position */
#define UHP_OHCI_HCINTERRUPTDISABLE_RD_Msk  (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTDISABLE_RD_Pos)  /**< (UHP_OHCI_HCINTERRUPTDISABLE) Disable ResumeDetected Mask */
#define UHP_OHCI_HCINTERRUPTDISABLE_RD      UHP_OHCI_HCINTERRUPTDISABLE_RD_Msk             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTDISABLE_RD_Msk instead */
#define UHP_OHCI_HCINTERRUPTDISABLE_UE_Pos  4                                              /**< (UHP_OHCI_HCINTERRUPTDISABLE) Disable UnrecoverableError Position */
#define UHP_OHCI_HCINTERRUPTDISABLE_UE_Msk  (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTDISABLE_UE_Pos)  /**< (UHP_OHCI_HCINTERRUPTDISABLE) Disable UnrecoverableError Mask */
#define UHP_OHCI_HCINTERRUPTDISABLE_UE      UHP_OHCI_HCINTERRUPTDISABLE_UE_Msk             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTDISABLE_UE_Msk instead */
#define UHP_OHCI_HCINTERRUPTDISABLE_FNO_Pos 5                                              /**< (UHP_OHCI_HCINTERRUPTDISABLE) Disable FrameNumberOverflow Position */
#define UHP_OHCI_HCINTERRUPTDISABLE_FNO_Msk (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTDISABLE_FNO_Pos)  /**< (UHP_OHCI_HCINTERRUPTDISABLE) Disable FrameNumberOverflow Mask */
#define UHP_OHCI_HCINTERRUPTDISABLE_FNO     UHP_OHCI_HCINTERRUPTDISABLE_FNO_Msk            /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTDISABLE_FNO_Msk instead */
#define UHP_OHCI_HCINTERRUPTDISABLE_RHSC_Pos 6                                              /**< (UHP_OHCI_HCINTERRUPTDISABLE) Disable RootHubStatusChange Position */
#define UHP_OHCI_HCINTERRUPTDISABLE_RHSC_Msk (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTDISABLE_RHSC_Pos)  /**< (UHP_OHCI_HCINTERRUPTDISABLE) Disable RootHubStatusChange Mask */
#define UHP_OHCI_HCINTERRUPTDISABLE_RHSC    UHP_OHCI_HCINTERRUPTDISABLE_RHSC_Msk           /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTDISABLE_RHSC_Msk instead */
#define UHP_OHCI_HCINTERRUPTDISABLE_OC_Pos  30                                             /**< (UHP_OHCI_HCINTERRUPTDISABLE) Disable OwnershipChange Position */
#define UHP_OHCI_HCINTERRUPTDISABLE_OC_Msk  (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTDISABLE_OC_Pos)  /**< (UHP_OHCI_HCINTERRUPTDISABLE) Disable OwnershipChange Mask */
#define UHP_OHCI_HCINTERRUPTDISABLE_OC      UHP_OHCI_HCINTERRUPTDISABLE_OC_Msk             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTDISABLE_OC_Msk instead */
#define UHP_OHCI_HCINTERRUPTDISABLE_MIE_Pos 31                                             /**< (UHP_OHCI_HCINTERRUPTDISABLE) Disable MasterInterruptEnable Position */
#define UHP_OHCI_HCINTERRUPTDISABLE_MIE_Msk (_UINT32_(0x1) << UHP_OHCI_HCINTERRUPTDISABLE_MIE_Pos)  /**< (UHP_OHCI_HCINTERRUPTDISABLE) Disable MasterInterruptEnable Mask */
#define UHP_OHCI_HCINTERRUPTDISABLE_MIE     UHP_OHCI_HCINTERRUPTDISABLE_MIE_Msk            /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCINTERRUPTDISABLE_MIE_Msk instead */
#define UHP_OHCI_HCINTERRUPTDISABLE_MASK    _UINT32_(0xC000007F)                                /**< \deprecated (UHP_OHCI_HCINTERRUPTDISABLE) Register MASK  (Use UHP_OHCI_HCINTERRUPTDISABLE_Msk instead)  */
#define UHP_OHCI_HCINTERRUPTDISABLE_Msk     _UINT32_(0xC000007F)                                /**< (UHP_OHCI_HCINTERRUPTDISABLE) Register Mask  */


/* -------- UHP_OHCI_HCHCCA : (UHP_OHCI Offset: 0x18) (R/W 32) UHP OHCI HcHCCA Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t :8;                        /**< bit:   0..7  Reserved */
    uint32_t HCCA:24;                   /**< bit:  8..31  base address of the Host Controller Communication Area */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCHCCA_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCHCCA_OFFSET              (0x18)                                        /**<  (UHP_OHCI_HCHCCA) UHP OHCI HcHCCA Register  Offset */

#define UHP_OHCI_HCHCCA_HCCA_Pos            8                                              /**< (UHP_OHCI_HCHCCA) base address of the Host Controller Communication Area Position */
#define UHP_OHCI_HCHCCA_HCCA_Msk            (_UINT32_(0xFFFFFF) << UHP_OHCI_HCHCCA_HCCA_Pos)    /**< (UHP_OHCI_HCHCCA) base address of the Host Controller Communication Area Mask */
#define UHP_OHCI_HCHCCA_HCCA(value)         (UHP_OHCI_HCHCCA_HCCA_Msk & ((value) << UHP_OHCI_HCHCCA_HCCA_Pos))
#define UHP_OHCI_HCHCCA_MASK                _UINT32_(0xFFFFFF00)                                /**< \deprecated (UHP_OHCI_HCHCCA) Register MASK  (Use UHP_OHCI_HCHCCA_Msk instead)  */
#define UHP_OHCI_HCHCCA_Msk                 _UINT32_(0xFFFFFF00)                                /**< (UHP_OHCI_HCHCCA) Register Mask  */


/* -------- UHP_OHCI_HCPERIODCURRENTED : (UHP_OHCI Offset: 0x1c) (R/W 32) UHP OHCI HcPeriodCurrentED Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t :4;                        /**< bit:   0..3  Reserved */
    uint32_t PCED:28;                   /**< bit:  4..31  PeriodCurrentED                          */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCPERIODCURRENTED_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCPERIODCURRENTED_OFFSET   (0x1C)                                        /**<  (UHP_OHCI_HCPERIODCURRENTED) UHP OHCI HcPeriodCurrentED Register  Offset */

#define UHP_OHCI_HCPERIODCURRENTED_PCED_Pos 4                                              /**< (UHP_OHCI_HCPERIODCURRENTED) PeriodCurrentED Position */
#define UHP_OHCI_HCPERIODCURRENTED_PCED_Msk (_UINT32_(0xFFFFFFF) << UHP_OHCI_HCPERIODCURRENTED_PCED_Pos)  /**< (UHP_OHCI_HCPERIODCURRENTED) PeriodCurrentED Mask */
#define UHP_OHCI_HCPERIODCURRENTED_PCED(value) (UHP_OHCI_HCPERIODCURRENTED_PCED_Msk & ((value) << UHP_OHCI_HCPERIODCURRENTED_PCED_Pos))
#define UHP_OHCI_HCPERIODCURRENTED_MASK     _UINT32_(0xFFFFFFF0)                                /**< \deprecated (UHP_OHCI_HCPERIODCURRENTED) Register MASK  (Use UHP_OHCI_HCPERIODCURRENTED_Msk instead)  */
#define UHP_OHCI_HCPERIODCURRENTED_Msk      _UINT32_(0xFFFFFFF0)                                /**< (UHP_OHCI_HCPERIODCURRENTED) Register Mask  */


/* -------- UHP_OHCI_HCCONTROLHEADED : (UHP_OHCI Offset: 0x20) (R/W 32) UHP OHCI HcControlHeadED Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t :4;                        /**< bit:   0..3  Reserved */
    uint32_t CHED:28;                   /**< bit:  4..31  ControlHeadED                            */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCCONTROLHEADED_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCCONTROLHEADED_OFFSET     (0x20)                                        /**<  (UHP_OHCI_HCCONTROLHEADED) UHP OHCI HcControlHeadED Register  Offset */

#define UHP_OHCI_HCCONTROLHEADED_CHED_Pos   4                                              /**< (UHP_OHCI_HCCONTROLHEADED) ControlHeadED Position */
#define UHP_OHCI_HCCONTROLHEADED_CHED_Msk   (_UINT32_(0xFFFFFFF) << UHP_OHCI_HCCONTROLHEADED_CHED_Pos)  /**< (UHP_OHCI_HCCONTROLHEADED) ControlHeadED Mask */
#define UHP_OHCI_HCCONTROLHEADED_CHED(value) (UHP_OHCI_HCCONTROLHEADED_CHED_Msk & ((value) << UHP_OHCI_HCCONTROLHEADED_CHED_Pos))
#define UHP_OHCI_HCCONTROLHEADED_MASK       _UINT32_(0xFFFFFFF0)                                /**< \deprecated (UHP_OHCI_HCCONTROLHEADED) Register MASK  (Use UHP_OHCI_HCCONTROLHEADED_Msk instead)  */
#define UHP_OHCI_HCCONTROLHEADED_Msk        _UINT32_(0xFFFFFFF0)                                /**< (UHP_OHCI_HCCONTROLHEADED) Register Mask  */


/* -------- UHP_OHCI_HCCONTROLCURRENTED : (UHP_OHCI Offset: 0x24) (R/W 32) UHP OHCI HcControlCurrentED Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t :4;                        /**< bit:   0..3  Reserved */
    uint32_t CCED:28;                   /**< bit:  4..31  ControlCurrentED                         */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCCONTROLCURRENTED_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCCONTROLCURRENTED_OFFSET  (0x24)                                        /**<  (UHP_OHCI_HCCONTROLCURRENTED) UHP OHCI HcControlCurrentED Register  Offset */

#define UHP_OHCI_HCCONTROLCURRENTED_CCED_Pos 4                                              /**< (UHP_OHCI_HCCONTROLCURRENTED) ControlCurrentED Position */
#define UHP_OHCI_HCCONTROLCURRENTED_CCED_Msk (_UINT32_(0xFFFFFFF) << UHP_OHCI_HCCONTROLCURRENTED_CCED_Pos)  /**< (UHP_OHCI_HCCONTROLCURRENTED) ControlCurrentED Mask */
#define UHP_OHCI_HCCONTROLCURRENTED_CCED(value) (UHP_OHCI_HCCONTROLCURRENTED_CCED_Msk & ((value) << UHP_OHCI_HCCONTROLCURRENTED_CCED_Pos))
#define UHP_OHCI_HCCONTROLCURRENTED_MASK    _UINT32_(0xFFFFFFF0)                                /**< \deprecated (UHP_OHCI_HCCONTROLCURRENTED) Register MASK  (Use UHP_OHCI_HCCONTROLCURRENTED_Msk instead)  */
#define UHP_OHCI_HCCONTROLCURRENTED_Msk     _UINT32_(0xFFFFFFF0)                                /**< (UHP_OHCI_HCCONTROLCURRENTED) Register Mask  */


/* -------- UHP_OHCI_HCBULKHEADED : (UHP_OHCI Offset: 0x28) (R/W 32) UHP OHCI HcBulkHeadED Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t :4;                        /**< bit:   0..3  Reserved */
    uint32_t BHED:28;                   /**< bit:  4..31  BulkHeadED                               */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCBULKHEADED_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCBULKHEADED_OFFSET        (0x28)                                        /**<  (UHP_OHCI_HCBULKHEADED) UHP OHCI HcBulkHeadED Register  Offset */

#define UHP_OHCI_HCBULKHEADED_BHED_Pos      4                                              /**< (UHP_OHCI_HCBULKHEADED) BulkHeadED Position */
#define UHP_OHCI_HCBULKHEADED_BHED_Msk      (_UINT32_(0xFFFFFFF) << UHP_OHCI_HCBULKHEADED_BHED_Pos)  /**< (UHP_OHCI_HCBULKHEADED) BulkHeadED Mask */
#define UHP_OHCI_HCBULKHEADED_BHED(value)   (UHP_OHCI_HCBULKHEADED_BHED_Msk & ((value) << UHP_OHCI_HCBULKHEADED_BHED_Pos))
#define UHP_OHCI_HCBULKHEADED_MASK          _UINT32_(0xFFFFFFF0)                                /**< \deprecated (UHP_OHCI_HCBULKHEADED) Register MASK  (Use UHP_OHCI_HCBULKHEADED_Msk instead)  */
#define UHP_OHCI_HCBULKHEADED_Msk           _UINT32_(0xFFFFFFF0)                                /**< (UHP_OHCI_HCBULKHEADED) Register Mask  */


/* -------- UHP_OHCI_HCBULKCURRENTED : (UHP_OHCI Offset: 0x2c) (R/W 32) UHP OHCI HcBulkCurrentED Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t :4;                        /**< bit:   0..3  Reserved */
    uint32_t BCED:28;                   /**< bit:  4..31  BulkCurrentED                            */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCBULKCURRENTED_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCBULKCURRENTED_OFFSET     (0x2C)                                        /**<  (UHP_OHCI_HCBULKCURRENTED) UHP OHCI HcBulkCurrentED Register  Offset */

#define UHP_OHCI_HCBULKCURRENTED_BCED_Pos   4                                              /**< (UHP_OHCI_HCBULKCURRENTED) BulkCurrentED Position */
#define UHP_OHCI_HCBULKCURRENTED_BCED_Msk   (_UINT32_(0xFFFFFFF) << UHP_OHCI_HCBULKCURRENTED_BCED_Pos)  /**< (UHP_OHCI_HCBULKCURRENTED) BulkCurrentED Mask */
#define UHP_OHCI_HCBULKCURRENTED_BCED(value) (UHP_OHCI_HCBULKCURRENTED_BCED_Msk & ((value) << UHP_OHCI_HCBULKCURRENTED_BCED_Pos))
#define UHP_OHCI_HCBULKCURRENTED_MASK       _UINT32_(0xFFFFFFF0)                                /**< \deprecated (UHP_OHCI_HCBULKCURRENTED) Register MASK  (Use UHP_OHCI_HCBULKCURRENTED_Msk instead)  */
#define UHP_OHCI_HCBULKCURRENTED_Msk        _UINT32_(0xFFFFFFF0)                                /**< (UHP_OHCI_HCBULKCURRENTED) Register Mask  */


/* -------- UHP_OHCI_HCDONEHEAD : (UHP_OHCI Offset: 0x30) (R/W 32) UHP OHCI HcDoneHead Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t :4;                        /**< bit:   0..3  Reserved */
    uint32_t DH:28;                     /**< bit:  4..31  DoneHead                                 */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCDONEHEAD_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCDONEHEAD_OFFSET          (0x30)                                        /**<  (UHP_OHCI_HCDONEHEAD) UHP OHCI HcDoneHead Register  Offset */

#define UHP_OHCI_HCDONEHEAD_DH_Pos          4                                              /**< (UHP_OHCI_HCDONEHEAD) DoneHead Position */
#define UHP_OHCI_HCDONEHEAD_DH_Msk          (_UINT32_(0xFFFFFFF) << UHP_OHCI_HCDONEHEAD_DH_Pos)  /**< (UHP_OHCI_HCDONEHEAD) DoneHead Mask */
#define UHP_OHCI_HCDONEHEAD_DH(value)       (UHP_OHCI_HCDONEHEAD_DH_Msk & ((value) << UHP_OHCI_HCDONEHEAD_DH_Pos))
#define UHP_OHCI_HCDONEHEAD_MASK            _UINT32_(0xFFFFFFF0)                                /**< \deprecated (UHP_OHCI_HCDONEHEAD) Register MASK  (Use UHP_OHCI_HCDONEHEAD_Msk instead)  */
#define UHP_OHCI_HCDONEHEAD_Msk             _UINT32_(0xFFFFFFF0)                                /**< (UHP_OHCI_HCDONEHEAD) Register Mask  */


/* -------- UHP_OHCI_HCFMINTERVAL : (UHP_OHCI Offset: 0x34) (R/W 32) UHP OHCI HcFmInterval Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t FI:14;                     /**< bit:  0..13  FrameInterval                            */
    uint32_t :2;                        /**< bit: 14..15  Reserved */
    uint32_t FSMPS:15;                  /**< bit: 16..30  FSLargestDataPacket                      */
    uint32_t FIT:1;                     /**< bit:     31  FrameIntervalToggle                      */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCFMINTERVAL_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCFMINTERVAL_OFFSET        (0x34)                                        /**<  (UHP_OHCI_HCFMINTERVAL) UHP OHCI HcFmInterval Register  Offset */

#define UHP_OHCI_HCFMINTERVAL_FI_Pos        0                                              /**< (UHP_OHCI_HCFMINTERVAL) FrameInterval Position */
#define UHP_OHCI_HCFMINTERVAL_FI_Msk        (_UINT32_(0x3FFF) << UHP_OHCI_HCFMINTERVAL_FI_Pos)  /**< (UHP_OHCI_HCFMINTERVAL) FrameInterval Mask */
#define UHP_OHCI_HCFMINTERVAL_FI(value)     (UHP_OHCI_HCFMINTERVAL_FI_Msk & ((value) << UHP_OHCI_HCFMINTERVAL_FI_Pos))
#define UHP_OHCI_HCFMINTERVAL_FSMPS_Pos     16                                             /**< (UHP_OHCI_HCFMINTERVAL) FSLargestDataPacket Position */
#define UHP_OHCI_HCFMINTERVAL_FSMPS_Msk     (_UINT32_(0x7FFF) << UHP_OHCI_HCFMINTERVAL_FSMPS_Pos)  /**< (UHP_OHCI_HCFMINTERVAL) FSLargestDataPacket Mask */
#define UHP_OHCI_HCFMINTERVAL_FSMPS(value)  (UHP_OHCI_HCFMINTERVAL_FSMPS_Msk & ((value) << UHP_OHCI_HCFMINTERVAL_FSMPS_Pos))
#define UHP_OHCI_HCFMINTERVAL_FIT_Pos       31                                             /**< (UHP_OHCI_HCFMINTERVAL) FrameIntervalToggle Position */
#define UHP_OHCI_HCFMINTERVAL_FIT_Msk       (_UINT32_(0x1) << UHP_OHCI_HCFMINTERVAL_FIT_Pos)    /**< (UHP_OHCI_HCFMINTERVAL) FrameIntervalToggle Mask */
#define UHP_OHCI_HCFMINTERVAL_FIT           UHP_OHCI_HCFMINTERVAL_FIT_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCFMINTERVAL_FIT_Msk instead */
#define UHP_OHCI_HCFMINTERVAL_MASK          _UINT32_(0xFFFF3FFF)                                /**< \deprecated (UHP_OHCI_HCFMINTERVAL) Register MASK  (Use UHP_OHCI_HCFMINTERVAL_Msk instead)  */
#define UHP_OHCI_HCFMINTERVAL_Msk           _UINT32_(0xFFFF3FFF)                                /**< (UHP_OHCI_HCFMINTERVAL) Register Mask  */


/* -------- UHP_OHCI_HCFMREMAINING : (UHP_OHCI Offset: 0x38) (R/W 32) UHP OHCI HcFmRemaining Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t FR:14;                     /**< bit:  0..13  FrameRemaining                           */
    uint32_t :17;                       /**< bit: 14..30  Reserved */
    uint32_t FRT:1;                     /**< bit:     31  FrameRemainingToggle                     */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCFMREMAINING_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCFMREMAINING_OFFSET       (0x38)                                        /**<  (UHP_OHCI_HCFMREMAINING) UHP OHCI HcFmRemaining Register  Offset */

#define UHP_OHCI_HCFMREMAINING_FR_Pos       0                                              /**< (UHP_OHCI_HCFMREMAINING) FrameRemaining Position */
#define UHP_OHCI_HCFMREMAINING_FR_Msk       (_UINT32_(0x3FFF) << UHP_OHCI_HCFMREMAINING_FR_Pos)  /**< (UHP_OHCI_HCFMREMAINING) FrameRemaining Mask */
#define UHP_OHCI_HCFMREMAINING_FR(value)    (UHP_OHCI_HCFMREMAINING_FR_Msk & ((value) << UHP_OHCI_HCFMREMAINING_FR_Pos))
#define UHP_OHCI_HCFMREMAINING_FRT_Pos      31                                             /**< (UHP_OHCI_HCFMREMAINING) FrameRemainingToggle Position */
#define UHP_OHCI_HCFMREMAINING_FRT_Msk      (_UINT32_(0x1) << UHP_OHCI_HCFMREMAINING_FRT_Pos)   /**< (UHP_OHCI_HCFMREMAINING) FrameRemainingToggle Mask */
#define UHP_OHCI_HCFMREMAINING_FRT          UHP_OHCI_HCFMREMAINING_FRT_Msk                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCFMREMAINING_FRT_Msk instead */
#define UHP_OHCI_HCFMREMAINING_MASK         _UINT32_(0x80003FFF)                                /**< \deprecated (UHP_OHCI_HCFMREMAINING) Register MASK  (Use UHP_OHCI_HCFMREMAINING_Msk instead)  */
#define UHP_OHCI_HCFMREMAINING_Msk          _UINT32_(0x80003FFF)                                /**< (UHP_OHCI_HCFMREMAINING) Register Mask  */


/* -------- UHP_OHCI_HCFMNUMBER : (UHP_OHCI Offset: 0x3c) (R/W 32) UHP OHCI HcFmNumber Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t FN:16;                     /**< bit:  0..15  FrameNumber                              */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCFMNUMBER_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCFMNUMBER_OFFSET          (0x3C)                                        /**<  (UHP_OHCI_HCFMNUMBER) UHP OHCI HcFmNumber Register  Offset */

#define UHP_OHCI_HCFMNUMBER_FN_Pos          0                                              /**< (UHP_OHCI_HCFMNUMBER) FrameNumber Position */
#define UHP_OHCI_HCFMNUMBER_FN_Msk          (_UINT32_(0xFFFF) << UHP_OHCI_HCFMNUMBER_FN_Pos)    /**< (UHP_OHCI_HCFMNUMBER) FrameNumber Mask */
#define UHP_OHCI_HCFMNUMBER_FN(value)       (UHP_OHCI_HCFMNUMBER_FN_Msk & ((value) << UHP_OHCI_HCFMNUMBER_FN_Pos))
#define UHP_OHCI_HCFMNUMBER_MASK            _UINT32_(0xFFFF)                                    /**< \deprecated (UHP_OHCI_HCFMNUMBER) Register MASK  (Use UHP_OHCI_HCFMNUMBER_Msk instead)  */
#define UHP_OHCI_HCFMNUMBER_Msk             _UINT32_(0xFFFF)                                    /**< (UHP_OHCI_HCFMNUMBER) Register Mask  */


/* -------- UHP_OHCI_HCPERIODICSTART : (UHP_OHCI Offset: 0x40) (R/W 32) UHP OHCI HcPeriodicStart Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t PS:14;                     /**< bit:  0..13  PeriodicStart                            */
    uint32_t :18;                       /**< bit: 14..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCPERIODICSTART_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCPERIODICSTART_OFFSET     (0x40)                                        /**<  (UHP_OHCI_HCPERIODICSTART) UHP OHCI HcPeriodicStart Register  Offset */

#define UHP_OHCI_HCPERIODICSTART_PS_Pos     0                                              /**< (UHP_OHCI_HCPERIODICSTART) PeriodicStart Position */
#define UHP_OHCI_HCPERIODICSTART_PS_Msk     (_UINT32_(0x3FFF) << UHP_OHCI_HCPERIODICSTART_PS_Pos)  /**< (UHP_OHCI_HCPERIODICSTART) PeriodicStart Mask */
#define UHP_OHCI_HCPERIODICSTART_PS(value)  (UHP_OHCI_HCPERIODICSTART_PS_Msk & ((value) << UHP_OHCI_HCPERIODICSTART_PS_Pos))
#define UHP_OHCI_HCPERIODICSTART_MASK       _UINT32_(0x3FFF)                                    /**< \deprecated (UHP_OHCI_HCPERIODICSTART) Register MASK  (Use UHP_OHCI_HCPERIODICSTART_Msk instead)  */
#define UHP_OHCI_HCPERIODICSTART_Msk        _UINT32_(0x3FFF)                                    /**< (UHP_OHCI_HCPERIODICSTART) Register Mask  */


/* -------- UHP_OHCI_HCLSTHRESHOLD : (UHP_OHCI Offset: 0x44) (R/W 32) UHP OHCI HcLSThreshold Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t LST:12;                    /**< bit:  0..11  LSThreshold                              */
    uint32_t :20;                       /**< bit: 12..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCLSTHRESHOLD_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCLSTHRESHOLD_OFFSET       (0x44)                                        /**<  (UHP_OHCI_HCLSTHRESHOLD) UHP OHCI HcLSThreshold Register  Offset */

#define UHP_OHCI_HCLSTHRESHOLD_LST_Pos      0                                              /**< (UHP_OHCI_HCLSTHRESHOLD) LSThreshold Position */
#define UHP_OHCI_HCLSTHRESHOLD_LST_Msk      (_UINT32_(0xFFF) << UHP_OHCI_HCLSTHRESHOLD_LST_Pos)  /**< (UHP_OHCI_HCLSTHRESHOLD) LSThreshold Mask */
#define UHP_OHCI_HCLSTHRESHOLD_LST(value)   (UHP_OHCI_HCLSTHRESHOLD_LST_Msk & ((value) << UHP_OHCI_HCLSTHRESHOLD_LST_Pos))
#define UHP_OHCI_HCLSTHRESHOLD_MASK         _UINT32_(0xFFF)                                     /**< \deprecated (UHP_OHCI_HCLSTHRESHOLD) Register MASK  (Use UHP_OHCI_HCLSTHRESHOLD_Msk instead)  */
#define UHP_OHCI_HCLSTHRESHOLD_Msk          _UINT32_(0xFFF)                                     /**< (UHP_OHCI_HCLSTHRESHOLD) Register Mask  */


/* -------- UHP_OHCI_HCRHDESCRIPTORA : (UHP_OHCI Offset: 0x48) (R/W 32) UHP OHCI HcRhDescriptorA Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t NDP:8;                     /**< bit:   0..7  NumberDownstreamPorts                    */
    uint32_t PSM:1;                     /**< bit:      8  PowerSwitchingMode                       */
    uint32_t NPS:1;                     /**< bit:      9  NoPowerSwitching                         */
    uint32_t DT:1;                      /**< bit:     10  DeviceType                               */
    uint32_t OCPM:1;                    /**< bit:     11  OverCurrentProtectionMode                */
    uint32_t NOCP:1;                    /**< bit:     12  NoOverCurrentProtection                  */
    uint32_t :11;                       /**< bit: 13..23  Reserved */
    uint32_t POTPGT:8;                  /**< bit: 24..31  PowerOnToPowerGoodTime                   */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCRHDESCRIPTORA_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCRHDESCRIPTORA_OFFSET     (0x48)                                        /**<  (UHP_OHCI_HCRHDESCRIPTORA) UHP OHCI HcRhDescriptorA Register  Offset */

#define UHP_OHCI_HCRHDESCRIPTORA_NDP_Pos    0                                              /**< (UHP_OHCI_HCRHDESCRIPTORA) NumberDownstreamPorts Position */
#define UHP_OHCI_HCRHDESCRIPTORA_NDP_Msk    (_UINT32_(0xFF) << UHP_OHCI_HCRHDESCRIPTORA_NDP_Pos)  /**< (UHP_OHCI_HCRHDESCRIPTORA) NumberDownstreamPorts Mask */
#define UHP_OHCI_HCRHDESCRIPTORA_NDP(value) (UHP_OHCI_HCRHDESCRIPTORA_NDP_Msk & ((value) << UHP_OHCI_HCRHDESCRIPTORA_NDP_Pos))
#define UHP_OHCI_HCRHDESCRIPTORA_PSM_Pos    8                                              /**< (UHP_OHCI_HCRHDESCRIPTORA) PowerSwitchingMode Position */
#define UHP_OHCI_HCRHDESCRIPTORA_PSM_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHDESCRIPTORA_PSM_Pos)  /**< (UHP_OHCI_HCRHDESCRIPTORA) PowerSwitchingMode Mask */
#define UHP_OHCI_HCRHDESCRIPTORA_PSM        UHP_OHCI_HCRHDESCRIPTORA_PSM_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHDESCRIPTORA_PSM_Msk instead */
#define UHP_OHCI_HCRHDESCRIPTORA_NPS_Pos    9                                              /**< (UHP_OHCI_HCRHDESCRIPTORA) NoPowerSwitching Position */
#define UHP_OHCI_HCRHDESCRIPTORA_NPS_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHDESCRIPTORA_NPS_Pos)  /**< (UHP_OHCI_HCRHDESCRIPTORA) NoPowerSwitching Mask */
#define UHP_OHCI_HCRHDESCRIPTORA_NPS        UHP_OHCI_HCRHDESCRIPTORA_NPS_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHDESCRIPTORA_NPS_Msk instead */
#define UHP_OHCI_HCRHDESCRIPTORA_DT_Pos     10                                             /**< (UHP_OHCI_HCRHDESCRIPTORA) DeviceType Position */
#define UHP_OHCI_HCRHDESCRIPTORA_DT_Msk     (_UINT32_(0x1) << UHP_OHCI_HCRHDESCRIPTORA_DT_Pos)  /**< (UHP_OHCI_HCRHDESCRIPTORA) DeviceType Mask */
#define UHP_OHCI_HCRHDESCRIPTORA_DT         UHP_OHCI_HCRHDESCRIPTORA_DT_Msk                /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHDESCRIPTORA_DT_Msk instead */
#define UHP_OHCI_HCRHDESCRIPTORA_OCPM_Pos   11                                             /**< (UHP_OHCI_HCRHDESCRIPTORA) OverCurrentProtectionMode Position */
#define UHP_OHCI_HCRHDESCRIPTORA_OCPM_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHDESCRIPTORA_OCPM_Pos)  /**< (UHP_OHCI_HCRHDESCRIPTORA) OverCurrentProtectionMode Mask */
#define UHP_OHCI_HCRHDESCRIPTORA_OCPM       UHP_OHCI_HCRHDESCRIPTORA_OCPM_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHDESCRIPTORA_OCPM_Msk instead */
#define UHP_OHCI_HCRHDESCRIPTORA_NOCP_Pos   12                                             /**< (UHP_OHCI_HCRHDESCRIPTORA) NoOverCurrentProtection Position */
#define UHP_OHCI_HCRHDESCRIPTORA_NOCP_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHDESCRIPTORA_NOCP_Pos)  /**< (UHP_OHCI_HCRHDESCRIPTORA) NoOverCurrentProtection Mask */
#define UHP_OHCI_HCRHDESCRIPTORA_NOCP       UHP_OHCI_HCRHDESCRIPTORA_NOCP_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHDESCRIPTORA_NOCP_Msk instead */
#define UHP_OHCI_HCRHDESCRIPTORA_POTPGT_Pos 24                                             /**< (UHP_OHCI_HCRHDESCRIPTORA) PowerOnToPowerGoodTime Position */
#define UHP_OHCI_HCRHDESCRIPTORA_POTPGT_Msk (_UINT32_(0xFF) << UHP_OHCI_HCRHDESCRIPTORA_POTPGT_Pos)  /**< (UHP_OHCI_HCRHDESCRIPTORA) PowerOnToPowerGoodTime Mask */
#define UHP_OHCI_HCRHDESCRIPTORA_POTPGT(value) (UHP_OHCI_HCRHDESCRIPTORA_POTPGT_Msk & ((value) << UHP_OHCI_HCRHDESCRIPTORA_POTPGT_Pos))
#define UHP_OHCI_HCRHDESCRIPTORA_MASK       _UINT32_(0xFF001FFF)                                /**< \deprecated (UHP_OHCI_HCRHDESCRIPTORA) Register MASK  (Use UHP_OHCI_HCRHDESCRIPTORA_Msk instead)  */
#define UHP_OHCI_HCRHDESCRIPTORA_Msk        _UINT32_(0xFF001FFF)                                /**< (UHP_OHCI_HCRHDESCRIPTORA) Register Mask  */


/* -------- UHP_OHCI_HCRHDESCRIPTORB : (UHP_OHCI Offset: 0x4c) (R/W 32) UHP OHCI HcRhDescriptorB Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t :16;                       /**< bit:  0..15  Reserved */
    uint32_t PPCM:16;                   /**< bit: 16..31  PortPowerControlMask                     */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCRHDESCRIPTORB_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCRHDESCRIPTORB_OFFSET     (0x4C)                                        /**<  (UHP_OHCI_HCRHDESCRIPTORB) UHP OHCI HcRhDescriptorB Register  Offset */

#define UHP_OHCI_HCRHDESCRIPTORB_PPCM_Pos   16                                             /**< (UHP_OHCI_HCRHDESCRIPTORB) PortPowerControlMask Position */
#define UHP_OHCI_HCRHDESCRIPTORB_PPCM_Msk   (_UINT32_(0xFFFF) << UHP_OHCI_HCRHDESCRIPTORB_PPCM_Pos)  /**< (UHP_OHCI_HCRHDESCRIPTORB) PortPowerControlMask Mask */
#define UHP_OHCI_HCRHDESCRIPTORB_PPCM(value) (UHP_OHCI_HCRHDESCRIPTORB_PPCM_Msk & ((value) << UHP_OHCI_HCRHDESCRIPTORB_PPCM_Pos))
#define UHP_OHCI_HCRHDESCRIPTORB_MASK       _UINT32_(0xFFFF0000)                                /**< \deprecated (UHP_OHCI_HCRHDESCRIPTORB) Register MASK  (Use UHP_OHCI_HCRHDESCRIPTORB_Msk instead)  */
#define UHP_OHCI_HCRHDESCRIPTORB_Msk        _UINT32_(0xFFFF0000)                                /**< (UHP_OHCI_HCRHDESCRIPTORB) Register Mask  */


/* -------- UHP_OHCI_HCRHSTATUS : (UHP_OHCI Offset: 0x50) (R/W 32) UHP OHCI HcRhStatus Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t LPS:1;                     /**< bit:      0  LocalPowerStatus                         */
    uint32_t OCI:1;                     /**< bit:      1  OverCurrentIndicator                     */
    uint32_t :13;                       /**< bit:  2..14  Reserved */
    uint32_t DRWE:1;                    /**< bit:     15  DeviceRemoteWakeupEnable                 */
    uint32_t LPSC:1;                    /**< bit:     16  LocalPowerStatusChange                   */
    uint32_t CCIC:1;                    /**< bit:     17  OverCurrentIndicatorChange               */
    uint32_t :13;                       /**< bit: 18..30  Reserved */
    uint32_t CRWE:1;                    /**< bit:     31  ClearRemoteWakeupEnable                  */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCRHSTATUS_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCRHSTATUS_OFFSET          (0x50)                                        /**<  (UHP_OHCI_HCRHSTATUS) UHP OHCI HcRhStatus Register  Offset */

#define UHP_OHCI_HCRHSTATUS_LPS_Pos         0                                              /**< (UHP_OHCI_HCRHSTATUS) LocalPowerStatus Position */
#define UHP_OHCI_HCRHSTATUS_LPS_Msk         (_UINT32_(0x1) << UHP_OHCI_HCRHSTATUS_LPS_Pos)      /**< (UHP_OHCI_HCRHSTATUS) LocalPowerStatus Mask */
#define UHP_OHCI_HCRHSTATUS_LPS             UHP_OHCI_HCRHSTATUS_LPS_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHSTATUS_LPS_Msk instead */
#define UHP_OHCI_HCRHSTATUS_OCI_Pos         1                                              /**< (UHP_OHCI_HCRHSTATUS) OverCurrentIndicator Position */
#define UHP_OHCI_HCRHSTATUS_OCI_Msk         (_UINT32_(0x1) << UHP_OHCI_HCRHSTATUS_OCI_Pos)      /**< (UHP_OHCI_HCRHSTATUS) OverCurrentIndicator Mask */
#define UHP_OHCI_HCRHSTATUS_OCI             UHP_OHCI_HCRHSTATUS_OCI_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHSTATUS_OCI_Msk instead */
#define UHP_OHCI_HCRHSTATUS_DRWE_Pos        15                                             /**< (UHP_OHCI_HCRHSTATUS) DeviceRemoteWakeupEnable Position */
#define UHP_OHCI_HCRHSTATUS_DRWE_Msk        (_UINT32_(0x1) << UHP_OHCI_HCRHSTATUS_DRWE_Pos)     /**< (UHP_OHCI_HCRHSTATUS) DeviceRemoteWakeupEnable Mask */
#define UHP_OHCI_HCRHSTATUS_DRWE            UHP_OHCI_HCRHSTATUS_DRWE_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHSTATUS_DRWE_Msk instead */
#define UHP_OHCI_HCRHSTATUS_LPSC_Pos        16                                             /**< (UHP_OHCI_HCRHSTATUS) LocalPowerStatusChange Position */
#define UHP_OHCI_HCRHSTATUS_LPSC_Msk        (_UINT32_(0x1) << UHP_OHCI_HCRHSTATUS_LPSC_Pos)     /**< (UHP_OHCI_HCRHSTATUS) LocalPowerStatusChange Mask */
#define UHP_OHCI_HCRHSTATUS_LPSC            UHP_OHCI_HCRHSTATUS_LPSC_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHSTATUS_LPSC_Msk instead */
#define UHP_OHCI_HCRHSTATUS_CCIC_Pos        17                                             /**< (UHP_OHCI_HCRHSTATUS) OverCurrentIndicatorChange Position */
#define UHP_OHCI_HCRHSTATUS_CCIC_Msk        (_UINT32_(0x1) << UHP_OHCI_HCRHSTATUS_CCIC_Pos)     /**< (UHP_OHCI_HCRHSTATUS) OverCurrentIndicatorChange Mask */
#define UHP_OHCI_HCRHSTATUS_CCIC            UHP_OHCI_HCRHSTATUS_CCIC_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHSTATUS_CCIC_Msk instead */
#define UHP_OHCI_HCRHSTATUS_CRWE_Pos        31                                             /**< (UHP_OHCI_HCRHSTATUS) ClearRemoteWakeupEnable Position */
#define UHP_OHCI_HCRHSTATUS_CRWE_Msk        (_UINT32_(0x1) << UHP_OHCI_HCRHSTATUS_CRWE_Pos)     /**< (UHP_OHCI_HCRHSTATUS) ClearRemoteWakeupEnable Mask */
#define UHP_OHCI_HCRHSTATUS_CRWE            UHP_OHCI_HCRHSTATUS_CRWE_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHSTATUS_CRWE_Msk instead */
#define UHP_OHCI_HCRHSTATUS_MASK            _UINT32_(0x80038003)                                /**< \deprecated (UHP_OHCI_HCRHSTATUS) Register MASK  (Use UHP_OHCI_HCRHSTATUS_Msk instead)  */
#define UHP_OHCI_HCRHSTATUS_Msk             _UINT32_(0x80038003)                                /**< (UHP_OHCI_HCRHSTATUS) Register Mask  */


/* -------- UHP_OHCI_HCRHPORTSTATUS0 : (UHP_OHCI Offset: 0x54) (R/W 32) UHP OHCI HcRhPortStatus 0 Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t CCS:1;                     /**< bit:      0  CurrentConnectStatus                     */
    uint32_t PES:1;                     /**< bit:      1  PortEnableStatus                         */
    uint32_t PSS:1;                     /**< bit:      2  PortSuspendStatus                        */
    uint32_t POCI:1;                    /**< bit:      3  PortOverCurrentIndicator                 */
    uint32_t PRS:1;                     /**< bit:      4  PortResetStatus                          */
    uint32_t :3;                        /**< bit:   5..7  Reserved */
    uint32_t PPS:1;                     /**< bit:      8  PortPowerStatus                          */
    uint32_t LSDA:1;                    /**< bit:      9  LowSpeedDeviceAttached                   */
    uint32_t :6;                        /**< bit: 10..15  Reserved */
    uint32_t CSC:1;                     /**< bit:     16  ConnectStatusChange                      */
    uint32_t PESC:1;                    /**< bit:     17  PortEnableStatusChange                   */
    uint32_t PSSC:1;                    /**< bit:     18  PortSuspendStatusChange                  */
    uint32_t OCIC:1;                    /**< bit:     19  PortOverCurrentIndicatorChange           */
    uint32_t PRSC:1;                    /**< bit:     20  PortResetStatusChange                    */
    uint32_t :11;                       /**< bit: 21..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCRHPORTSTATUS0_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCRHPORTSTATUS0_OFFSET     (0x54)                                        /**<  (UHP_OHCI_HCRHPORTSTATUS0) UHP OHCI HcRhPortStatus 0 Register  Offset */

#define UHP_OHCI_HCRHPORTSTATUS0_CCS_Pos    0                                              /**< (UHP_OHCI_HCRHPORTSTATUS0) CurrentConnectStatus Position */
#define UHP_OHCI_HCRHPORTSTATUS0_CCS_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS0_CCS_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS0) CurrentConnectStatus Mask */
#define UHP_OHCI_HCRHPORTSTATUS0_CCS        UHP_OHCI_HCRHPORTSTATUS0_CCS_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS0_CCS_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS0_PES_Pos    1                                              /**< (UHP_OHCI_HCRHPORTSTATUS0) PortEnableStatus Position */
#define UHP_OHCI_HCRHPORTSTATUS0_PES_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS0_PES_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS0) PortEnableStatus Mask */
#define UHP_OHCI_HCRHPORTSTATUS0_PES        UHP_OHCI_HCRHPORTSTATUS0_PES_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS0_PES_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS0_PSS_Pos    2                                              /**< (UHP_OHCI_HCRHPORTSTATUS0) PortSuspendStatus Position */
#define UHP_OHCI_HCRHPORTSTATUS0_PSS_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS0_PSS_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS0) PortSuspendStatus Mask */
#define UHP_OHCI_HCRHPORTSTATUS0_PSS        UHP_OHCI_HCRHPORTSTATUS0_PSS_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS0_PSS_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS0_POCI_Pos   3                                              /**< (UHP_OHCI_HCRHPORTSTATUS0) PortOverCurrentIndicator Position */
#define UHP_OHCI_HCRHPORTSTATUS0_POCI_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS0_POCI_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS0) PortOverCurrentIndicator Mask */
#define UHP_OHCI_HCRHPORTSTATUS0_POCI       UHP_OHCI_HCRHPORTSTATUS0_POCI_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS0_POCI_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS0_PRS_Pos    4                                              /**< (UHP_OHCI_HCRHPORTSTATUS0) PortResetStatus Position */
#define UHP_OHCI_HCRHPORTSTATUS0_PRS_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS0_PRS_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS0) PortResetStatus Mask */
#define UHP_OHCI_HCRHPORTSTATUS0_PRS        UHP_OHCI_HCRHPORTSTATUS0_PRS_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS0_PRS_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS0_PPS_Pos    8                                              /**< (UHP_OHCI_HCRHPORTSTATUS0) PortPowerStatus Position */
#define UHP_OHCI_HCRHPORTSTATUS0_PPS_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS0_PPS_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS0) PortPowerStatus Mask */
#define UHP_OHCI_HCRHPORTSTATUS0_PPS        UHP_OHCI_HCRHPORTSTATUS0_PPS_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS0_PPS_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS0_LSDA_Pos   9                                              /**< (UHP_OHCI_HCRHPORTSTATUS0) LowSpeedDeviceAttached Position */
#define UHP_OHCI_HCRHPORTSTATUS0_LSDA_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS0_LSDA_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS0) LowSpeedDeviceAttached Mask */
#define UHP_OHCI_HCRHPORTSTATUS0_LSDA       UHP_OHCI_HCRHPORTSTATUS0_LSDA_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS0_LSDA_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS0_CSC_Pos    16                                             /**< (UHP_OHCI_HCRHPORTSTATUS0) ConnectStatusChange Position */
#define UHP_OHCI_HCRHPORTSTATUS0_CSC_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS0_CSC_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS0) ConnectStatusChange Mask */
#define UHP_OHCI_HCRHPORTSTATUS0_CSC        UHP_OHCI_HCRHPORTSTATUS0_CSC_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS0_CSC_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS0_PESC_Pos   17                                             /**< (UHP_OHCI_HCRHPORTSTATUS0) PortEnableStatusChange Position */
#define UHP_OHCI_HCRHPORTSTATUS0_PESC_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS0_PESC_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS0) PortEnableStatusChange Mask */
#define UHP_OHCI_HCRHPORTSTATUS0_PESC       UHP_OHCI_HCRHPORTSTATUS0_PESC_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS0_PESC_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS0_PSSC_Pos   18                                             /**< (UHP_OHCI_HCRHPORTSTATUS0) PortSuspendStatusChange Position */
#define UHP_OHCI_HCRHPORTSTATUS0_PSSC_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS0_PSSC_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS0) PortSuspendStatusChange Mask */
#define UHP_OHCI_HCRHPORTSTATUS0_PSSC       UHP_OHCI_HCRHPORTSTATUS0_PSSC_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS0_PSSC_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS0_OCIC_Pos   19                                             /**< (UHP_OHCI_HCRHPORTSTATUS0) PortOverCurrentIndicatorChange Position */
#define UHP_OHCI_HCRHPORTSTATUS0_OCIC_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS0_OCIC_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS0) PortOverCurrentIndicatorChange Mask */
#define UHP_OHCI_HCRHPORTSTATUS0_OCIC       UHP_OHCI_HCRHPORTSTATUS0_OCIC_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS0_OCIC_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS0_PRSC_Pos   20                                             /**< (UHP_OHCI_HCRHPORTSTATUS0) PortResetStatusChange Position */
#define UHP_OHCI_HCRHPORTSTATUS0_PRSC_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS0_PRSC_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS0) PortResetStatusChange Mask */
#define UHP_OHCI_HCRHPORTSTATUS0_PRSC       UHP_OHCI_HCRHPORTSTATUS0_PRSC_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS0_PRSC_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS0_MASK       _UINT32_(0x1F031F)                                  /**< \deprecated (UHP_OHCI_HCRHPORTSTATUS0) Register MASK  (Use UHP_OHCI_HCRHPORTSTATUS0_Msk instead)  */
#define UHP_OHCI_HCRHPORTSTATUS0_Msk        _UINT32_(0x1F031F)                                  /**< (UHP_OHCI_HCRHPORTSTATUS0) Register Mask  */


/* -------- UHP_OHCI_HCRHPORTSTATUS1 : (UHP_OHCI Offset: 0x58) (R/W 32) UHP OHCI HcRhPortStatus 1 Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t CCS:1;                     /**< bit:      0  CurrentConnectStatus                     */
    uint32_t PES:1;                     /**< bit:      1  PortEnableStatus                         */
    uint32_t PSS:1;                     /**< bit:      2  PortSuspendStatus                        */
    uint32_t POCI:1;                    /**< bit:      3  PortOverCurrentIndicator                 */
    uint32_t PRS:1;                     /**< bit:      4  PortResetStatus                          */
    uint32_t :3;                        /**< bit:   5..7  Reserved */
    uint32_t PPS:1;                     /**< bit:      8  PortPowerStatus                          */
    uint32_t LSDA:1;                    /**< bit:      9  LowSpeedDeviceAttached                   */
    uint32_t :6;                        /**< bit: 10..15  Reserved */
    uint32_t CSC:1;                     /**< bit:     16  ConnectStatusChange                      */
    uint32_t PESC:1;                    /**< bit:     17  PortEnableStatusChange                   */
    uint32_t PSSC:1;                    /**< bit:     18  PortSuspendStatusChange                  */
    uint32_t OCIC:1;                    /**< bit:     19  PortOverCurrentIndicatorChange           */
    uint32_t PRSC:1;                    /**< bit:     20  PortResetStatusChange                    */
    uint32_t :11;                       /**< bit: 21..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCRHPORTSTATUS1_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCRHPORTSTATUS1_OFFSET     (0x58)                                        /**<  (UHP_OHCI_HCRHPORTSTATUS1) UHP OHCI HcRhPortStatus 1 Register  Offset */

#define UHP_OHCI_HCRHPORTSTATUS1_CCS_Pos    0                                              /**< (UHP_OHCI_HCRHPORTSTATUS1) CurrentConnectStatus Position */
#define UHP_OHCI_HCRHPORTSTATUS1_CCS_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS1_CCS_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS1) CurrentConnectStatus Mask */
#define UHP_OHCI_HCRHPORTSTATUS1_CCS        UHP_OHCI_HCRHPORTSTATUS1_CCS_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS1_CCS_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS1_PES_Pos    1                                              /**< (UHP_OHCI_HCRHPORTSTATUS1) PortEnableStatus Position */
#define UHP_OHCI_HCRHPORTSTATUS1_PES_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS1_PES_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS1) PortEnableStatus Mask */
#define UHP_OHCI_HCRHPORTSTATUS1_PES        UHP_OHCI_HCRHPORTSTATUS1_PES_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS1_PES_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS1_PSS_Pos    2                                              /**< (UHP_OHCI_HCRHPORTSTATUS1) PortSuspendStatus Position */
#define UHP_OHCI_HCRHPORTSTATUS1_PSS_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS1_PSS_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS1) PortSuspendStatus Mask */
#define UHP_OHCI_HCRHPORTSTATUS1_PSS        UHP_OHCI_HCRHPORTSTATUS1_PSS_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS1_PSS_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS1_POCI_Pos   3                                              /**< (UHP_OHCI_HCRHPORTSTATUS1) PortOverCurrentIndicator Position */
#define UHP_OHCI_HCRHPORTSTATUS1_POCI_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS1_POCI_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS1) PortOverCurrentIndicator Mask */
#define UHP_OHCI_HCRHPORTSTATUS1_POCI       UHP_OHCI_HCRHPORTSTATUS1_POCI_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS1_POCI_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS1_PRS_Pos    4                                              /**< (UHP_OHCI_HCRHPORTSTATUS1) PortResetStatus Position */
#define UHP_OHCI_HCRHPORTSTATUS1_PRS_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS1_PRS_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS1) PortResetStatus Mask */
#define UHP_OHCI_HCRHPORTSTATUS1_PRS        UHP_OHCI_HCRHPORTSTATUS1_PRS_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS1_PRS_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS1_PPS_Pos    8                                              /**< (UHP_OHCI_HCRHPORTSTATUS1) PortPowerStatus Position */
#define UHP_OHCI_HCRHPORTSTATUS1_PPS_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS1_PPS_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS1) PortPowerStatus Mask */
#define UHP_OHCI_HCRHPORTSTATUS1_PPS        UHP_OHCI_HCRHPORTSTATUS1_PPS_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS1_PPS_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS1_LSDA_Pos   9                                              /**< (UHP_OHCI_HCRHPORTSTATUS1) LowSpeedDeviceAttached Position */
#define UHP_OHCI_HCRHPORTSTATUS1_LSDA_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS1_LSDA_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS1) LowSpeedDeviceAttached Mask */
#define UHP_OHCI_HCRHPORTSTATUS1_LSDA       UHP_OHCI_HCRHPORTSTATUS1_LSDA_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS1_LSDA_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS1_CSC_Pos    16                                             /**< (UHP_OHCI_HCRHPORTSTATUS1) ConnectStatusChange Position */
#define UHP_OHCI_HCRHPORTSTATUS1_CSC_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS1_CSC_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS1) ConnectStatusChange Mask */
#define UHP_OHCI_HCRHPORTSTATUS1_CSC        UHP_OHCI_HCRHPORTSTATUS1_CSC_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS1_CSC_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS1_PESC_Pos   17                                             /**< (UHP_OHCI_HCRHPORTSTATUS1) PortEnableStatusChange Position */
#define UHP_OHCI_HCRHPORTSTATUS1_PESC_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS1_PESC_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS1) PortEnableStatusChange Mask */
#define UHP_OHCI_HCRHPORTSTATUS1_PESC       UHP_OHCI_HCRHPORTSTATUS1_PESC_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS1_PESC_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS1_PSSC_Pos   18                                             /**< (UHP_OHCI_HCRHPORTSTATUS1) PortSuspendStatusChange Position */
#define UHP_OHCI_HCRHPORTSTATUS1_PSSC_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS1_PSSC_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS1) PortSuspendStatusChange Mask */
#define UHP_OHCI_HCRHPORTSTATUS1_PSSC       UHP_OHCI_HCRHPORTSTATUS1_PSSC_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS1_PSSC_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS1_OCIC_Pos   19                                             /**< (UHP_OHCI_HCRHPORTSTATUS1) PortOverCurrentIndicatorChange Position */
#define UHP_OHCI_HCRHPORTSTATUS1_OCIC_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS1_OCIC_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS1) PortOverCurrentIndicatorChange Mask */
#define UHP_OHCI_HCRHPORTSTATUS1_OCIC       UHP_OHCI_HCRHPORTSTATUS1_OCIC_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS1_OCIC_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS1_PRSC_Pos   20                                             /**< (UHP_OHCI_HCRHPORTSTATUS1) PortResetStatusChange Position */
#define UHP_OHCI_HCRHPORTSTATUS1_PRSC_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS1_PRSC_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS1) PortResetStatusChange Mask */
#define UHP_OHCI_HCRHPORTSTATUS1_PRSC       UHP_OHCI_HCRHPORTSTATUS1_PRSC_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS1_PRSC_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS1_MASK       _UINT32_(0x1F031F)                                  /**< \deprecated (UHP_OHCI_HCRHPORTSTATUS1) Register MASK  (Use UHP_OHCI_HCRHPORTSTATUS1_Msk instead)  */
#define UHP_OHCI_HCRHPORTSTATUS1_Msk        _UINT32_(0x1F031F)                                  /**< (UHP_OHCI_HCRHPORTSTATUS1) Register Mask  */


/* -------- UHP_OHCI_HCRHPORTSTATUS2 : (UHP_OHCI Offset: 0x5c) (R/W 32) UHP OHCI HcRhPortStatus 2 Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'N'
typedef union {
  struct {
    uint32_t CCS:1;                     /**< bit:      0  CurrentConnectStatus                     */
    uint32_t PES:1;                     /**< bit:      1  PortEnableStatus                         */
    uint32_t PSS:1;                     /**< bit:      2  PortSuspendStatus                        */
    uint32_t POCI:1;                    /**< bit:      3  PortOverCurrentIndicator                 */
    uint32_t PRS:1;                     /**< bit:      4  PortResetStatus                          */
    uint32_t :3;                        /**< bit:   5..7  Reserved */
    uint32_t PPS:1;                     /**< bit:      8  PortPowerStatus                          */
    uint32_t LSDA:1;                    /**< bit:      9  LowSpeedDeviceAttached                   */
    uint32_t :6;                        /**< bit: 10..15  Reserved */
    uint32_t CSC:1;                     /**< bit:     16  ConnectStatusChange                      */
    uint32_t PESC:1;                    /**< bit:     17  PortEnableStatusChange                   */
    uint32_t PSSC:1;                    /**< bit:     18  PortSuspendStatusChange                  */
    uint32_t OCIC:1;                    /**< bit:     19  PortOverCurrentIndicatorChange           */
    uint32_t PRSC:1;                    /**< bit:     20  PortResetStatusChange                    */
    uint32_t :11;                       /**< bit: 21..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_OHCI_HCRHPORTSTATUS2_Type;
#endif
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_OHCI_HCRHPORTSTATUS2_OFFSET     (0x5C)                                        /**<  (UHP_OHCI_HCRHPORTSTATUS2) UHP OHCI HcRhPortStatus 2 Register  Offset */

#define UHP_OHCI_HCRHPORTSTATUS2_CCS_Pos    0                                              /**< (UHP_OHCI_HCRHPORTSTATUS2) CurrentConnectStatus Position */
#define UHP_OHCI_HCRHPORTSTATUS2_CCS_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS2_CCS_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS2) CurrentConnectStatus Mask */
#define UHP_OHCI_HCRHPORTSTATUS2_CCS        UHP_OHCI_HCRHPORTSTATUS2_CCS_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS2_CCS_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS2_PES_Pos    1                                              /**< (UHP_OHCI_HCRHPORTSTATUS2) PortEnableStatus Position */
#define UHP_OHCI_HCRHPORTSTATUS2_PES_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS2_PES_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS2) PortEnableStatus Mask */
#define UHP_OHCI_HCRHPORTSTATUS2_PES        UHP_OHCI_HCRHPORTSTATUS2_PES_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS2_PES_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS2_PSS_Pos    2                                              /**< (UHP_OHCI_HCRHPORTSTATUS2) PortSuspendStatus Position */
#define UHP_OHCI_HCRHPORTSTATUS2_PSS_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS2_PSS_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS2) PortSuspendStatus Mask */
#define UHP_OHCI_HCRHPORTSTATUS2_PSS        UHP_OHCI_HCRHPORTSTATUS2_PSS_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS2_PSS_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS2_POCI_Pos   3                                              /**< (UHP_OHCI_HCRHPORTSTATUS2) PortOverCurrentIndicator Position */
#define UHP_OHCI_HCRHPORTSTATUS2_POCI_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS2_POCI_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS2) PortOverCurrentIndicator Mask */
#define UHP_OHCI_HCRHPORTSTATUS2_POCI       UHP_OHCI_HCRHPORTSTATUS2_POCI_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS2_POCI_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS2_PRS_Pos    4                                              /**< (UHP_OHCI_HCRHPORTSTATUS2) PortResetStatus Position */
#define UHP_OHCI_HCRHPORTSTATUS2_PRS_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS2_PRS_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS2) PortResetStatus Mask */
#define UHP_OHCI_HCRHPORTSTATUS2_PRS        UHP_OHCI_HCRHPORTSTATUS2_PRS_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS2_PRS_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS2_PPS_Pos    8                                              /**< (UHP_OHCI_HCRHPORTSTATUS2) PortPowerStatus Position */
#define UHP_OHCI_HCRHPORTSTATUS2_PPS_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS2_PPS_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS2) PortPowerStatus Mask */
#define UHP_OHCI_HCRHPORTSTATUS2_PPS        UHP_OHCI_HCRHPORTSTATUS2_PPS_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS2_PPS_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS2_LSDA_Pos   9                                              /**< (UHP_OHCI_HCRHPORTSTATUS2) LowSpeedDeviceAttached Position */
#define UHP_OHCI_HCRHPORTSTATUS2_LSDA_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS2_LSDA_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS2) LowSpeedDeviceAttached Mask */
#define UHP_OHCI_HCRHPORTSTATUS2_LSDA       UHP_OHCI_HCRHPORTSTATUS2_LSDA_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS2_LSDA_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS2_CSC_Pos    16                                             /**< (UHP_OHCI_HCRHPORTSTATUS2) ConnectStatusChange Position */
#define UHP_OHCI_HCRHPORTSTATUS2_CSC_Msk    (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS2_CSC_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS2) ConnectStatusChange Mask */
#define UHP_OHCI_HCRHPORTSTATUS2_CSC        UHP_OHCI_HCRHPORTSTATUS2_CSC_Msk               /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS2_CSC_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS2_PESC_Pos   17                                             /**< (UHP_OHCI_HCRHPORTSTATUS2) PortEnableStatusChange Position */
#define UHP_OHCI_HCRHPORTSTATUS2_PESC_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS2_PESC_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS2) PortEnableStatusChange Mask */
#define UHP_OHCI_HCRHPORTSTATUS2_PESC       UHP_OHCI_HCRHPORTSTATUS2_PESC_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS2_PESC_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS2_PSSC_Pos   18                                             /**< (UHP_OHCI_HCRHPORTSTATUS2) PortSuspendStatusChange Position */
#define UHP_OHCI_HCRHPORTSTATUS2_PSSC_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS2_PSSC_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS2) PortSuspendStatusChange Mask */
#define UHP_OHCI_HCRHPORTSTATUS2_PSSC       UHP_OHCI_HCRHPORTSTATUS2_PSSC_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS2_PSSC_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS2_OCIC_Pos   19                                             /**< (UHP_OHCI_HCRHPORTSTATUS2) PortOverCurrentIndicatorChange Position */
#define UHP_OHCI_HCRHPORTSTATUS2_OCIC_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS2_OCIC_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS2) PortOverCurrentIndicatorChange Mask */
#define UHP_OHCI_HCRHPORTSTATUS2_OCIC       UHP_OHCI_HCRHPORTSTATUS2_OCIC_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS2_OCIC_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS2_PRSC_Pos   20                                             /**< (UHP_OHCI_HCRHPORTSTATUS2) PortResetStatusChange Position */
#define UHP_OHCI_HCRHPORTSTATUS2_PRSC_Msk   (_UINT32_(0x1) << UHP_OHCI_HCRHPORTSTATUS2_PRSC_Pos)  /**< (UHP_OHCI_HCRHPORTSTATUS2) PortResetStatusChange Mask */
#define UHP_OHCI_HCRHPORTSTATUS2_PRSC       UHP_OHCI_HCRHPORTSTATUS2_PRSC_Msk              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_OHCI_HCRHPORTSTATUS2_PRSC_Msk instead */
#define UHP_OHCI_HCRHPORTSTATUS2_MASK       _UINT32_(0x1F031F)                                  /**< \deprecated (UHP_OHCI_HCRHPORTSTATUS2) Register MASK  (Use UHP_OHCI_HCRHPORTSTATUS2_Msk instead)  */
#define UHP_OHCI_HCRHPORTSTATUS2_Msk        _UINT32_(0x1F031F)                                  /**< (UHP_OHCI_HCRHPORTSTATUS2) Register Mask  */


#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'R'
/** \brief UHP_OHCI hardware registers */
typedef struct {
  __I  uint32_t UHP_OHCI_HCREVISION; /**< (UHP_OHCI Offset: 0x00) UHP OHCI Revision Register */
  __IO uint32_t UHP_OHCI_HCCONTROL; /**< (UHP_OHCI Offset: 0x04) UHP OHCI HcControl Register */
  __IO uint32_t UHP_OHCI_HCCOMMANDSTATUS; /**< (UHP_OHCI Offset: 0x08) UHP_OHCI HcInterruptStatus Register */
  __IO uint32_t UHP_OHCI_HCINTERRUPTSTATUS; /**< (UHP_OHCI Offset: 0x0C) UHP OHCI HcInterruptStatus Register */
  __IO uint32_t UHP_OHCI_HCINTERRUPTENABLE; /**< (UHP_OHCI Offset: 0x10) UHP OHCI HcInterruptEnable Register */
  __IO uint32_t UHP_OHCI_HCINTERRUPTDISABLE; /**< (UHP_OHCI Offset: 0x14) UHP OHCI HcInterruptDisable Register */
  __IO uint32_t UHP_OHCI_HCHCCA; /**< (UHP_OHCI Offset: 0x18) UHP OHCI HcHCCA Register */
  __IO uint32_t UHP_OHCI_HCPERIODCURRENTED; /**< (UHP_OHCI Offset: 0x1C) UHP OHCI HcPeriodCurrentED Register */
  __IO uint32_t UHP_OHCI_HCCONTROLHEADED; /**< (UHP_OHCI Offset: 0x20) UHP OHCI HcControlHeadED Register */
  __IO uint32_t UHP_OHCI_HCCONTROLCURRENTED; /**< (UHP_OHCI Offset: 0x24) UHP OHCI HcControlCurrentED Register */
  __IO uint32_t UHP_OHCI_HCBULKHEADED; /**< (UHP_OHCI Offset: 0x28) UHP OHCI HcBulkHeadED Register */
  __IO uint32_t UHP_OHCI_HCBULKCURRENTED; /**< (UHP_OHCI Offset: 0x2C) UHP OHCI HcBulkCurrentED Register */
  __IO uint32_t UHP_OHCI_HCDONEHEAD; /**< (UHP_OHCI Offset: 0x30) UHP OHCI HcDoneHead Register */
  __IO uint32_t UHP_OHCI_HCFMINTERVAL; /**< (UHP_OHCI Offset: 0x34) UHP OHCI HcFmInterval Register */
  __IO uint32_t UHP_OHCI_HCFMREMAINING; /**< (UHP_OHCI Offset: 0x38) UHP OHCI HcFmRemaining Register */
  __IO uint32_t UHP_OHCI_HCFMNUMBER; /**< (UHP_OHCI Offset: 0x3C) UHP OHCI HcFmNumber Register */
  __IO uint32_t UHP_OHCI_HCPERIODICSTART; /**< (UHP_OHCI Offset: 0x40) UHP OHCI HcPeriodicStart Register */
  __IO uint32_t UHP_OHCI_HCLSTHRESHOLD; /**< (UHP_OHCI Offset: 0x44) UHP OHCI HcLSThreshold Register */
  __IO uint32_t UHP_OHCI_HCRHDESCRIPTORA; /**< (UHP_OHCI Offset: 0x48) UHP OHCI HcRhDescriptorA Register */
  __IO uint32_t UHP_OHCI_HCRHDESCRIPTORB; /**< (UHP_OHCI Offset: 0x4C) UHP OHCI HcRhDescriptorB Register */
  __IO uint32_t UHP_OHCI_HCRHSTATUS; /**< (UHP_OHCI Offset: 0x50) UHP OHCI HcRhStatus Register */
  __IO uint32_t UHP_OHCI_HCRHPORTSTATUS0; /**< (UHP_OHCI Offset: 0x54) UHP OHCI HcRhPortStatus 0 Register */
  __IO uint32_t UHP_OHCI_HCRHPORTSTATUS1; /**< (UHP_OHCI Offset: 0x58) UHP OHCI HcRhPortStatus 1 Register */
  __IO uint32_t UHP_OHCI_HCRHPORTSTATUS2; /**< (UHP_OHCI Offset: 0x5C) UHP OHCI HcRhPortStatus 2 Register */
} UhpOhci;

#elif COMPONENT_TYPEDEF_STYLE == 'N'
/** \brief UHP_OHCI hardware registers */
typedef struct {
  __I  UHP_OHCI_HCREVISION_Type       UHP_OHCI_HCREVISION; /**< Offset: 0x00 (R/   32) UHP OHCI Revision Register */
  __IO UHP_OHCI_HCCONTROL_Type        UHP_OHCI_HCCONTROL; /**< Offset: 0x04 (R/W  32) UHP OHCI HcControl Register */
  __IO UHP_OHCI_HCCOMMANDSTATUS_Type  UHP_OHCI_HCCOMMANDSTATUS; /**< Offset: 0x08 (R/W  32) UHP_OHCI HcInterruptStatus Register */
  __IO UHP_OHCI_HCINTERRUPTSTATUS_Type UHP_OHCI_HCINTERRUPTSTATUS; /**< Offset: 0x0C (R/W  32) UHP OHCI HcInterruptStatus Register */
  __IO UHP_OHCI_HCINTERRUPTENABLE_Type UHP_OHCI_HCINTERRUPTENABLE; /**< Offset: 0x10 (R/W  32) UHP OHCI HcInterruptEnable Register */
  __IO UHP_OHCI_HCINTERRUPTDISABLE_Type UHP_OHCI_HCINTERRUPTDISABLE; /**< Offset: 0x14 (R/W  32) UHP OHCI HcInterruptDisable Register */
  __IO UHP_OHCI_HCHCCA_Type           UHP_OHCI_HCHCCA; /**< Offset: 0x18 (R/W  32) UHP OHCI HcHCCA Register */
  __IO UHP_OHCI_HCPERIODCURRENTED_Type UHP_OHCI_HCPERIODCURRENTED; /**< Offset: 0x1C (R/W  32) UHP OHCI HcPeriodCurrentED Register */
  __IO UHP_OHCI_HCCONTROLHEADED_Type  UHP_OHCI_HCCONTROLHEADED; /**< Offset: 0x20 (R/W  32) UHP OHCI HcControlHeadED Register */
  __IO UHP_OHCI_HCCONTROLCURRENTED_Type UHP_OHCI_HCCONTROLCURRENTED; /**< Offset: 0x24 (R/W  32) UHP OHCI HcControlCurrentED Register */
  __IO UHP_OHCI_HCBULKHEADED_Type     UHP_OHCI_HCBULKHEADED; /**< Offset: 0x28 (R/W  32) UHP OHCI HcBulkHeadED Register */
  __IO UHP_OHCI_HCBULKCURRENTED_Type  UHP_OHCI_HCBULKCURRENTED; /**< Offset: 0x2C (R/W  32) UHP OHCI HcBulkCurrentED Register */
  __IO UHP_OHCI_HCDONEHEAD_Type       UHP_OHCI_HCDONEHEAD; /**< Offset: 0x30 (R/W  32) UHP OHCI HcDoneHead Register */
  __IO UHP_OHCI_HCFMINTERVAL_Type     UHP_OHCI_HCFMINTERVAL; /**< Offset: 0x34 (R/W  32) UHP OHCI HcFmInterval Register */
  __IO UHP_OHCI_HCFMREMAINING_Type    UHP_OHCI_HCFMREMAINING; /**< Offset: 0x38 (R/W  32) UHP OHCI HcFmRemaining Register */
  __IO UHP_OHCI_HCFMNUMBER_Type       UHP_OHCI_HCFMNUMBER; /**< Offset: 0x3C (R/W  32) UHP OHCI HcFmNumber Register */
  __IO UHP_OHCI_HCPERIODICSTART_Type  UHP_OHCI_HCPERIODICSTART; /**< Offset: 0x40 (R/W  32) UHP OHCI HcPeriodicStart Register */
  __IO UHP_OHCI_HCLSTHRESHOLD_Type    UHP_OHCI_HCLSTHRESHOLD; /**< Offset: 0x44 (R/W  32) UHP OHCI HcLSThreshold Register */
  __IO UHP_OHCI_HCRHDESCRIPTORA_Type  UHP_OHCI_HCRHDESCRIPTORA; /**< Offset: 0x48 (R/W  32) UHP OHCI HcRhDescriptorA Register */
  __IO UHP_OHCI_HCRHDESCRIPTORB_Type  UHP_OHCI_HCRHDESCRIPTORB; /**< Offset: 0x4C (R/W  32) UHP OHCI HcRhDescriptorB Register */
  __IO UHP_OHCI_HCRHSTATUS_Type       UHP_OHCI_HCRHSTATUS; /**< Offset: 0x50 (R/W  32) UHP OHCI HcRhStatus Register */
  __IO UHP_OHCI_HCRHPORTSTATUS0_Type  UHP_OHCI_HCRHPORTSTATUS0; /**< Offset: 0x54 (R/W  32) UHP OHCI HcRhPortStatus 0 Register */
  __IO UHP_OHCI_HCRHPORTSTATUS1_Type  UHP_OHCI_HCRHPORTSTATUS1; /**< Offset: 0x58 (R/W  32) UHP OHCI HcRhPortStatus 1 Register */
  __IO UHP_OHCI_HCRHPORTSTATUS2_Type  UHP_OHCI_HCRHPORTSTATUS2; /**< Offset: 0x5C (R/W  32) UHP OHCI HcRhPortStatus 2 Register */
} UhpOhci;

#else /* COMPONENT_TYPEDEF_STYLE */
#error Unknown component typedef style
#endif /* COMPONENT_TYPEDEF_STYLE */

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of USB Host Full Speed Port */

#endif /* _DA78_UHP_OHCI_COMPONENT_H_ */
