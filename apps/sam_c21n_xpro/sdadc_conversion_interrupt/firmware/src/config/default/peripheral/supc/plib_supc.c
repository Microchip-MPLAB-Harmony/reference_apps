/*******************************************************************************
  Supply Controller(SUPC) PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_supc.c

  Summary
    SUPC PLIB Implementation File.

  Description
    This file defines the interface to the SUPC peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/* This section lists the other files that are included in this file.
*/

#include "device.h"
#include "plib_supc.h"



void SUPC_Initialize( void )
{
    uint32_t bodEnable = SUPC_REGS->SUPC_BODVDD & SUPC_BODVDD_ENABLE_Msk;

    /* Configure BODVDD. Mask the values loaded from NVM during reset. */
    SUPC_REGS->SUPC_BODVDD &= ~SUPC_BODVDD_ENABLE_Msk;
    SUPC_REGS->SUPC_BODVDD = (SUPC_REGS->SUPC_BODVDD & (SUPC_BODVDD_ENABLE_Msk | SUPC_BODVDD_ACTION_Msk | SUPC_BODVDD_HYST_Msk | SUPC_BODVDD_LEVEL_Msk)) | SUPC_BODVDD_PSEL(0x0);
    if (bodEnable)
    {
        SUPC_REGS->SUPC_BODVDD |= SUPC_BODVDD_ENABLE_Msk;
    }

    /* Configure VREF */
    SUPC_REGS->SUPC_VREF = SUPC_VREF_SEL(0x3) | SUPC_VREF_VREFOE_Msk;

}




