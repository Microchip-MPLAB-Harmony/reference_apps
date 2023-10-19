/*******************************************************************************
  EVSYS Peripheral Library

  Company:
    Microchip Technology Inc.

  File Name:
    plib_evsys.c

  Summary:
    EVSYS Source File

  Description:
    None

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

#include "plib_evsys.h"
#include "interrupts.h"




void EVSYS_Initialize( void )
{
    /*Event Channel User Configuration*/
    EVSYS_REGS->EVSYS_USER[63] = EVSYS_USER_CHANNEL(0x1U);

    /* Event Channel 0 Configuration */
    EVSYS_REGS->CHANNEL[0].EVSYS_CHANNEL = EVSYS_CHANNEL_EVGEN(34U) | EVSYS_CHANNEL_PATH(2U) | EVSYS_CHANNEL_EDGSEL(0U) \
                                     ;
    /* Event Channel 1 Configuration */
    EVSYS_REGS->CHANNEL[1].EVSYS_CHANNEL = EVSYS_CHANNEL_EVGEN(107U) | EVSYS_CHANNEL_PATH(2U) | EVSYS_CHANNEL_EDGSEL(0U) \
                                     ;
}

void EVSYS_GeneratorEnable(EVSYS_CHANNEL channel, uint8_t generator)
{
   EVSYS_REGS->CHANNEL[channel].EVSYS_CHANNEL = (EVSYS_REGS->CHANNEL[channel].EVSYS_CHANNEL & ~EVSYS_CHANNEL_EVGEN_Msk) | EVSYS_CHANNEL_EVGEN(generator);
}

void EVSYS_GeneratorDisable(EVSYS_CHANNEL channel)
{
   EVSYS_REGS->CHANNEL[channel].EVSYS_CHANNEL = (EVSYS_REGS->CHANNEL[channel].EVSYS_CHANNEL & ~EVSYS_CHANNEL_EVGEN_Msk);
}

void EVSYS_UserEnable(EVSYS_CHANNEL channel, uint8_t user)
{
   EVSYS_REGS->EVSYS_USER[user] = EVSYS_USER_CHANNEL(((uint32_t)channel + 1U));
}

void EVSYS_UserDisable(uint8_t user)
{
   EVSYS_REGS->EVSYS_USER[user] = 0x0;
}

