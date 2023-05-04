/*******************************************************************************
  Timer/Counter(TCC0) PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_tcc0.h

  Summary
    TCC0 PLIB Header File.

  Description
    This file defines the interface to the TCC peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef PLIB_TCC0_H       // Guards against multiple inclusion
#define PLIB_TCC0_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/* This section lists the other files that are included in this file.
*/

#include "device.h"
#include "plib_tcc_common.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
/* The following data type definitions are used by the functions in this
    interface and should be considered part it.
*/

/* Total number of TCC channels in a module */
#define TCC0_NUM_CHANNELS    (4U)

/* TCC Channel numbers

   Summary:
    Identifies channel number within TCC module

   Description:
    This enumeration identifies TCC channel number.

   Remarks:
    None.
*/
typedef enum
{
    TCC0_CHANNEL0,
    TCC0_CHANNEL1,
    TCC0_CHANNEL2,
    TCC0_CHANNEL3,
}TCC0_CHANNEL_NUM;


typedef enum
{
    TCC0_COMPARE_STATUS_OVF = TCC_INTFLAG_OVF_Msk,
    TCC0_COMPARE_STATUS_MC_0 = TCC_INTFLAG_MC0_Msk,
    TCC0_COMPARE_STATUS_MC_1 = TCC_INTFLAG_MC1_Msk,
    TCC0_COMPARE_STATUS_MC_2 = TCC_INTFLAG_MC2_Msk,
    TCC0_COMPARE_STATUS_MC_3 = TCC_INTFLAG_MC3_Msk,
}TCC0_COMPARE_STATUS;

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
/* The following functions make up the methods (set of possible operations) of
   this interface.
*/


void TCC0_CompareInitialize( void );

void TCC0_CompareStart( void );

void TCC0_CompareStop( void );

uint32_t TCC0_CompareFrequencyGet( void );

bool TCC0_Compare24bitPeriodSet( uint32_t period );

uint32_t TCC0_Compare24bitPeriodGet( void );

uint32_t TCC0_Compare24bitCounterGet( void );

void TCC0_Compare24bitCounterSet( uint32_t count );

bool TCC0_Compare24bitMatchSet(TCC0_CHANNEL_NUM channel, uint32_t compareValue );



uint32_t TCC0_CompareStatusGet( void );

void TCC0_CompareCommandSet(TCC_COMMAND command);


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END

#endif /* PLIB_TCC0_H */
