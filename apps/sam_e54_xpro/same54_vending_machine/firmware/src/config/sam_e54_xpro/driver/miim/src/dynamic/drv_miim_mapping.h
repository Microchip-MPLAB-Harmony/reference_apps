/*******************************************************************************
  MIIM Driver Local Data Structures

  Company:
    Microchip Technology Inc.

  File Name:
    drv_miim_mapping.h

  Summary:
    MIIM driver mapping for different internal MACs.

  Description:
    This file contains routines for MIIM driver register access.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*
Copyright (C) 2018-2023, Microchip Technology Inc., and its subsidiaries. All rights reserved.

The software and documentation is provided by microchip and its contributors
"as is" and any express, implied or statutory warranties, including, but not
limited to, the implied warranties of merchantability, fitness for a particular
purpose and non-infringement of third party intellectual property rights are
disclaimed to the fullest extent permitted by law. In no event shall microchip
or its contributors be liable for any direct, indirect, incidental, special,
exemplary, or consequential damages (including, but not limited to, procurement
of substitute goods or services; loss of use, data, or profits; or business
interruption) however caused and on any theory of liability, whether in contract,
strict liability, or tort (including negligence or otherwise) arising in any way
out of the use of the software and documentation, even if advised of the
possibility of such damage.

Except as expressly permitted hereunder and subject to the applicable license terms
for any third-party software incorporated in the software and any applicable open
source software license terms, no license or other rights, whether express or
implied, are granted under any patent or other intellectual property rights of
Microchip or any third party.
*/

//DOM-IGNORE-END

#ifndef _DRV_MIIM_MAPPING_H
#define _DRV_MIIM_MAPPING_H


// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "device.h"
// *****************************************************************************
// *****************************************************************************
// Section: Data Type Definitions
// *****************************************************************************
// *****************************************************************************

    //*****************************************************************************
    /* MII Clock Selection

      Summary:
        Lists the possible speed selection for the Reduced Media Independent 
        Interface (RMII).

      Description:
        This enumeration lists the possible speed selection for RMII.
        The body contains only two states: RMII_10Mbps or RMII_100Mbps.

      Remarks:
        This enumeration is processor specific and is defined in the processor-
        specific header files (see processor.h).
    */
    
    typedef enum {

        GMAC_MIIM_SYSCLK_DIV_BY_8   /*DOM-IGNORE-BEGIN*/ = 0x00 /*DOM-IGNORE-END*/ ,
        GMAC_MIIM_SYSCLK_DIV_BY_16  /*DOM-IGNORE-BEGIN*/ = 0x01 /*DOM-IGNORE-END*/ ,
        GMAC_MIIM_SYSCLK_DIV_BY_32  /*DOM-IGNORE-BEGIN*/ = 0x02 /*DOM-IGNORE-END*/ ,
        GMAC_MIIM_SYSCLK_DIV_BY_48  /*DOM-IGNORE-BEGIN*/ = 0x03 /*DOM-IGNORE-END*/ ,
        GMAC_MIIM_SYSCLK_DIV_BY_64  /*DOM-IGNORE-BEGIN*/ = 0x04 /*DOM-IGNORE-END*/ ,
        GMAC_MIIM_SYSCLK_DIV_BY_96  /*DOM-IGNORE-BEGIN*/ = 0x05 /*DOM-IGNORE-END*/ ,
        GMAC_MIIM_SYSCLK_DIV_ABOVE_96  /*DOM-IGNORE-BEGIN*/ = 0x06 /*DOM-IGNORE-END*/ ,

    } GMAC_MIIM_CLK;
    
    static  __inline__ DRV_MIIM_RESULT __attribute__((always_inline))_DRV_MIIM_ETH_ENABLE(uintptr_t ethPhyId)
    {
        return DRV_MIIM_RES_OK;
    }
    
    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_MII_RELEASE_RESET(uintptr_t ethPhyId)
    {
    }

    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_SETUP_PREAMBLE(uintptr_t ethPhyId,const DRV_MIIM_SETUP* pSetUp)
    {
    }

    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_SCAN_INCREMENT(uintptr_t ethPhyId,const DRV_MIIM_SETUP* pSetUp)
    {
    }

    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_MNGMNT_PORT_ENABLE(uintptr_t ethPhyId)
    {
        gmac_registers_t *  pGmacRegs = (gmac_registers_t *) ethPhyId;
        pGmacRegs->GMAC_NCR |=  GMAC_NCR_MPE_Msk;
    }
    
    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_MNGMNT_PORT_DISABLE(uintptr_t ethPhyId)
    {
        gmac_registers_t *  pGmacRegs = (gmac_registers_t *) ethPhyId;
        pGmacRegs->GMAC_NCR &= ~GMAC_NCR_MPE_Msk;
 
    }
    
    static  __inline__ bool __attribute__((always_inline))_DRV_MIIM_IS_BUSY(uintptr_t ethPhyId)
    {
        gmac_registers_t *  pGmacRegs = (gmac_registers_t *) ethPhyId;
        bool    phyBusy = (pGmacRegs->GMAC_NSR & GMAC_NSR_IDLE_Msk) != GMAC_NSR_IDLE_Msk;

        return phyBusy;        
    }
    
    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_PHYADDR_SET(uintptr_t ethPhyId,DRV_MIIM_OP_DCPT* pOpDcpt)
    {
      
    }

    static  __inline__ DRV_MIIM_TXFER_STAT __attribute__((always_inline))_DRV_MIIM_OP_SCAN_ENABLE(uintptr_t ethPhyId)
    {        
         return DRV_MIIM_TXFER_SCAN_STALE;
    }

    
    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_OP_WRITE_DATA(uintptr_t ethPhyId,DRV_MIIM_OP_DCPT* pOpDcpt)
    {
        gmac_registers_t *  pGmacRegs = (gmac_registers_t *) ethPhyId;

        pGmacRegs->GMAC_MAN =    (~GMAC_MAN_WZO_Msk & GMAC_MAN_CLTTO_Msk)
                                 | (GMAC_MAN_OP(0x1)) 
                                 | GMAC_MAN_WTN(0x02) 
                                 | GMAC_MAN_PHYA(pOpDcpt->phyAdd) 
                                 | GMAC_MAN_REGA(pOpDcpt->regIx) 
                                 | GMAC_MAN_DATA(pOpDcpt->opData);
        
    }

    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_WRITE_START(uintptr_t ethPhyId)
    {
    }
    
   
    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_OP_READ_START(uintptr_t ethPhyId, DRV_MIIM_OP_DCPT* pOpDcpt)
    {
        gmac_registers_t *  pGmacRegs = (gmac_registers_t *) ethPhyId;
        pGmacRegs->GMAC_MAN =    (~GMAC_MAN_WZO_Msk & GMAC_MAN_CLTTO_Msk) 
                                    | (GMAC_MAN_OP(0x2)) 
                                    | GMAC_MAN_WTN(0x02) 
                                    | GMAC_MAN_PHYA(pOpDcpt->phyAdd) 
                                    | GMAC_MAN_REGA(pOpDcpt->regIx) 
                                    | GMAC_MAN_DATA(0);
     
    }
    
                                 
    static  __inline__ uint16_t __attribute__((always_inline))_DRV_MIIM_OP_READ_DATA_GET(uintptr_t ethPhyId)
    {
        gmac_registers_t *  pGmacRegs = (gmac_registers_t *) ethPhyId;
        return (uint16_t)(pGmacRegs->GMAC_MAN & GMAC_MAN_DATA_Msk) ;  
       
    }

    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_CLEAR_DATA_VALID(uintptr_t ethPhyId)
    {
    }
  
    static  __inline__ bool __attribute__((always_inline))_DRV_MIIM_IS_DATA_VALID(uintptr_t ethPhyId)
    {
        return false;
    }  

 
    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_SCAN_DISABLE(uintptr_t ethPhyId)
    {
    } 
    
    static  __inline__ void __attribute__((always_inline)) _DRV_MIIM_SMI_CLOCK_SET(uintptr_t ethPhyId, uint32_t hostClock, uint32_t maxMIIMClock )
    { 
        gmac_registers_t *  pGmacRegs = (gmac_registers_t *) ethPhyId;
        uint32_t mdc_div; 
        GMAC_MIIM_CLK clock_dividor ; 
        bool tx_stat, rx_stat;
        mdc_div = hostClock/maxMIIMClock; 
        if (mdc_div <= 8 ) 
        { 
            clock_dividor = GMAC_MIIM_SYSCLK_DIV_BY_8; 
        } 
        else if (mdc_div <= 16 ) 
        { 
            clock_dividor = GMAC_MIIM_SYSCLK_DIV_BY_16; 
        } 
        else if (mdc_div <= 32 ) 
        { 
            clock_dividor = GMAC_MIIM_SYSCLK_DIV_BY_32; 
        } 
        else if (mdc_div <= 48 ) 
        { 
            clock_dividor = GMAC_MIIM_SYSCLK_DIV_BY_48; 
        } 
        else if (mdc_div <= 64 ) 
        { 
            clock_dividor = GMAC_MIIM_SYSCLK_DIV_BY_64; 
        } 
        else if (mdc_div <= 96 ) 
        { 
            clock_dividor = GMAC_MIIM_SYSCLK_DIV_BY_96; 
        } 
        else 
        { 
            clock_dividor = GMAC_MIIM_SYSCLK_DIV_ABOVE_96; 
        } 
        
        //disable tx if it is already enabled
        tx_stat = pGmacRegs->GMAC_NCR & GMAC_NCR_TXEN_Msk;
        if (tx_stat)
        {
            pGmacRegs->GMAC_NCR &= ~GMAC_NCR_TXEN_Msk; 
        }
        //disable rx if it is already enabled
        rx_stat = pGmacRegs->GMAC_NCR & GMAC_NCR_RXEN_Msk;
        if (rx_stat)
        {
            pGmacRegs->GMAC_NCR &= ~GMAC_NCR_RXEN_Msk;  
        }
        
        pGmacRegs->GMAC_NCFGR = (pGmacRegs->GMAC_NCFGR & 
                                (~GMAC_NCFGR_CLK_Msk)) | 
                                (clock_dividor << GMAC_NCFGR_CLK_Pos); 
        //enable tx if it was previously enabled
        if (tx_stat)
        {
            pGmacRegs->GMAC_NCR |= GMAC_NCR_TXEN_Msk; 
        }
        //enable rx if it was previously enabled
        if (rx_stat)
        {
            pGmacRegs->GMAC_NCR |= GMAC_NCR_RXEN_Msk;
        }

    } 



#endif //#ifndef _DRV_MIIM_MAPPING_H

/*******************************************************************************
 End of File
*/

