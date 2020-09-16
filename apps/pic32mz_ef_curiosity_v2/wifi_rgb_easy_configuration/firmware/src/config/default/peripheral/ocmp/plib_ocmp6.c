/*******************************************************************************
  Output Compare OCMP6 Peripheral Library (PLIB)

  Company:
    Microchip Technology Inc.

  File Name:
    plib_ocmp6.c

  Summary:
    OCMP6 Source File

  Description:
    None

*******************************************************************************/

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
#include "plib_ocmp6.h"

// *****************************************************************************

// *****************************************************************************
// Section: OCMP6 Implementation
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************


void OCMP6_Initialize (void)
{
    /*Setup OC6CON        */
    /*OCM         = 5        */
    /*OCTSEL       = 1        */
    /*OC32         = 0        */
    /*SIDL         = false    */

    OC6CON = 0xd;

    OC6R = 5;
    OC6RS = 5;

}

void OCMP6_Enable (void)
{
    OC6CONSET = _OC6CON_ON_MASK;
}

void OCMP6_Disable (void)
{
    OC6CONCLR = _OC6CON_ON_MASK;
}


void OCMP6_CompareValueSet (uint16_t value)
{
    OC6R = value;
}

uint16_t OCMP6_CompareValueGet (void)
{
    return (uint16_t)OC6R;
}

void OCMP6_CompareSecondaryValueSet (uint16_t value)
{
    OC6RS = value;
}

uint16_t OCMP6_CompareSecondaryValueGet (void)
{
    return (uint16_t)OC6RS;
}

