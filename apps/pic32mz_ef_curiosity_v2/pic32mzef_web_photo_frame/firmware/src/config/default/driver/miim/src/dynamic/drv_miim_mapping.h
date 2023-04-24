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
#include "driver/ethmac/src/dynamic/drv_eth_pic32_lib.h"



   static const short _MIIMClockDivisorTable[]=
    {
        4, 6, 8, 10, 14, 20, 28, 40, 
#if defined (__PIC32MZ__)
        48, 50,
#endif  // defined (__PIC32MZ__)
    };  // divider values for the Host clock
   
    static  __inline__ DRV_MIIM_RESULT __attribute__((always_inline))_DRV_MIIM_ETH_ENABLE(uintptr_t ethPhyId)
    {        
        DRV_ETHERNET_REGISTERS* ethId = (DRV_ETHERNET_REGISTERS*)_ETH_BASE_ADDRESS;
        DRV_MIIM_RESULT res = DRV_MIIM_RES_OK;

        if(!DRV_ETH_IsEnabled(ethId)) 
        { 
            DRV_ETH_Enable(ethId);  
            res = DRV_MIIM_RES_INIT_WARNING;
        } 
        return res;
    }
    

    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_MII_RELEASE_RESET(uintptr_t ethPhyId)
    {
        DRV_ETHERNET_REGISTERS* ethId = (DRV_ETHERNET_REGISTERS*)_ETH_BASE_ADDRESS;
        DRV_ETH_MIIResetDisable(ethId);

    }
    
    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_SETUP_PREAMBLE(uintptr_t ethPhyId, const DRV_MIIM_SETUP* pSetUp)
    {
        DRV_ETHERNET_REGISTERS* ethId = (DRV_ETHERNET_REGISTERS*)_ETH_BASE_ADDRESS;
        if((pSetUp->setupFlags & DRV_MIIM_SETUP_FLAG_PREAMBLE_SUPPRESSED) != 0)
        {
            DRV_ETH_MIIMNoPreEnable(ethId);            
        }
        else
        {
            DRV_ETH_MIIMNoPreDisable(ethId);
        }

    }
    
    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_SCAN_INCREMENT(uintptr_t ethPhyId, const DRV_MIIM_SETUP* pSetUp)
    {
        DRV_ETHERNET_REGISTERS* ethId = (DRV_ETHERNET_REGISTERS*)_ETH_BASE_ADDRESS;
        if((pSetUp->setupFlags & DRV_MIIM_SETUP_FLAG_SCAN_ADDRESS_INCREMENT) != 0)
        {
            DRV_ETH_MIIMScanIncrEnable(ethId);
        }
        else
        {
            DRV_ETH_MIIMScanIncrDisable(ethId);
        }

    }

    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_MNGMNT_PORT_ENABLE(uintptr_t ethPhyId)
    {
       
    }
    
    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_MNGMNT_PORT_DISABLE(uintptr_t ethPhyId)
    {
       
    }
    
    static  __inline__ bool __attribute__((always_inline))_DRV_MIIM_IS_BUSY(uintptr_t ethPhyId)
    {
        DRV_ETHERNET_REGISTERS* ethId = (DRV_ETHERNET_REGISTERS*)_ETH_BASE_ADDRESS;
        return DRV_ETH_MIIMIsBusy(ethId);
    }
    
    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_PHYADDR_SET(uintptr_t ethPhyId,DRV_MIIM_OP_DCPT* pOpDcpt)
    {
        DRV_ETHERNET_REGISTERS* ethId = (DRV_ETHERNET_REGISTERS*)_ETH_BASE_ADDRESS;
        DRV_ETH_PHYAddressSet(ethId, pOpDcpt->phyAdd);
        DRV_ETH_RegisterAddressSet(ethId,pOpDcpt->regIx);
    }
    
    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_CLEAR_DATA_VALID(uintptr_t ethPhyId)
    {
        DRV_ETHERNET_REGISTERS* ethId = (DRV_ETHERNET_REGISTERS*)_ETH_BASE_ADDRESS;
        DRV_ETH_ClearDataValid(ethId);
    }
   
    static  __inline__ DRV_MIIM_TXFER_STAT __attribute__((always_inline))_DRV_MIIM_OP_SCAN_ENABLE(uintptr_t ethPhyId)
    {   
        DRV_ETHERNET_REGISTERS* ethId = (DRV_ETHERNET_REGISTERS*)_ETH_BASE_ADDRESS;
        DRV_ETH_ClearDataValid(ethId);
        DRV_ETH_MIIMScanModeEnable(ethId);
        return DRV_MIIM_TXFER_SCAN_STALE;
    }
    
    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_OP_WRITE_DATA(uintptr_t ethPhyId,DRV_MIIM_OP_DCPT* pOpDcpt)
    {
        DRV_ETHERNET_REGISTERS* ethId = (DRV_ETHERNET_REGISTERS*)_ETH_BASE_ADDRESS;
        DRV_ETH_MIIMWriteDataSet(ethId, pOpDcpt->opData);
    }
    

    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_WRITE_START(uintptr_t ethPhyId)
    {
        DRV_ETHERNET_REGISTERS* ethId = (DRV_ETHERNET_REGISTERS*)_ETH_BASE_ADDRESS;
        DRV_ETH_MIIMWriteStart(ethId);
    }
    
    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_OP_READ_START(uintptr_t ethPhyId,DRV_MIIM_OP_DCPT* pOpDcpt)
    {
        DRV_ETHERNET_REGISTERS* ethId = (DRV_ETHERNET_REGISTERS*)_ETH_BASE_ADDRESS;
        DRV_ETH_MIIMReadStart(ethId);
    }

    static  __inline__ uint16_t __attribute__((always_inline))_DRV_MIIM_OP_READ_DATA_GET(uintptr_t ethPhyId)
    {
        DRV_ETHERNET_REGISTERS* ethId = (DRV_ETHERNET_REGISTERS*)_ETH_BASE_ADDRESS;
        return DRV_ETH_MIIMReadDataGet(ethId);
    }
    
    static  __inline__ bool __attribute__((always_inline))_DRV_MIIM_IS_DATA_VALID(uintptr_t ethPhyId)
    {
        DRV_ETHERNET_REGISTERS* ethId = (DRV_ETHERNET_REGISTERS*)_ETH_BASE_ADDRESS;
        return !DRV_ETH_DataNotValid(ethId);
    }
      
    static  __inline__ void __attribute__((always_inline))_DRV_MIIM_SCAN_DISABLE(uintptr_t ethPhyId)
    { 
        DRV_ETHERNET_REGISTERS* ethId = (DRV_ETHERNET_REGISTERS*)_ETH_BASE_ADDRESS;
        DRV_ETH_MIIMScanModeDisable(ethId);
    }
    
    static  __inline__ void __attribute__((always_inline)) _DRV_MIIM_SMI_CLOCK_SET(uintptr_t ethPhyId, uint32_t hostClock, uint32_t maxMIIMClock )
    {

        DRV_ETHERNET_REGISTERS* ethId = (DRV_ETHERNET_REGISTERS*)_ETH_BASE_ADDRESS;
        int  ix;
        DRV_ETH_MIIMResetEnable(ethId); // Issue MIIM reset
        DRV_ETH_MIIMResetDisable(ethId); // Clear MIIM reset

        for(ix = 0; ix < sizeof(_MIIMClockDivisorTable) / sizeof(*_MIIMClockDivisorTable); ix++)
        {
            if(hostClock / _MIIMClockDivisorTable[ix] <= maxMIIMClock)
            {   // found it
                break;
            }
        }

        if(ix == sizeof(_MIIMClockDivisorTable) / sizeof(*_MIIMClockDivisorTable))
        {
            ix--;   // max divider; best we can do
        }

        DRV_ETH_MIIMClockSet(ethId, ix + 1);  // program the clock*/

    }

#endif //#ifndef _DRV_MIIM_MAPPING_H

/*******************************************************************************
 End of File
*/

