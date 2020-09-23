/*******************************************************************************
 CLOCK PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_clock.c

  Summary:
    CLOCK PLIB Implementation File.

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

#include "plib_clock.h"
#include "device.h"

static void OSCCTRL_Initialize(void)
{
    /**************** OSC16M IniTialization *************/
    OSCCTRL_REGS->OSCCTRL_OSC16MCTRL = OSCCTRL_OSC16MCTRL_FSEL(0x2) | OSCCTRL_OSC16MCTRL_ENABLE_Msk;
}

static void OSC32KCTRL_Initialize(void)
{
    OSC32KCTRL_REGS->OSC32KCTRL_OSC32K = 0x0;

    OSC32KCTRL_REGS->OSC32KCTRL_RTCCTRL = OSC32KCTRL_RTCCTRL_RTCSEL(0);
}




static void GCLK0_Initialize(void)
{

    GCLK_REGS->GCLK_GENCTRL[0] = GCLK_GENCTRL_DIV(1) | GCLK_GENCTRL_SRC(6) | GCLK_GENCTRL_GENEN_Msk;

    while((GCLK_REGS->GCLK_SYNCBUSY & GCLK_SYNCBUSY_GENCTRL0_Msk) == GCLK_SYNCBUSY_GENCTRL0_Msk)
    {
        /* wait for the Generator 0 synchronization */
    }
}


static void GCLK1_Initialize(void)
{
    GCLK_REGS->GCLK_GENCTRL[1] = GCLK_GENCTRL_DIV(12) | GCLK_GENCTRL_SRC(6) | GCLK_GENCTRL_GENEN_Msk;

    while((GCLK_REGS->GCLK_SYNCBUSY & GCLK_SYNCBUSY_GENCTRL1_Msk) == GCLK_SYNCBUSY_GENCTRL1_Msk)
    {
        /* wait for the Generator 1 synchronization */
    }
}


static void GCLK2_Initialize(void)
{
    GCLK_REGS->GCLK_GENCTRL[2] = GCLK_GENCTRL_DIV(1) | GCLK_GENCTRL_SRC(3) | GCLK_GENCTRL_RUNSTDBY_Msk | GCLK_GENCTRL_GENEN_Msk;

    while((GCLK_REGS->GCLK_SYNCBUSY & GCLK_SYNCBUSY_GENCTRL2_Msk) == GCLK_SYNCBUSY_GENCTRL2_Msk)
    {
        /* wait for the Generator 2 synchronization */
    }
}

void CLOCK_Initialize (void)
{
    /* Function to Initialize the Oscillators */
    OSCCTRL_Initialize();

    /* Function to Initialize the 32KHz Oscillators */
    OSC32KCTRL_Initialize();

    /*Initialize low Power Divider*/
    MCLK_REGS->MCLK_LPDIV = MCLK_LPDIV_LPDIV(0x01);

    /*Initialize Backup Divider*/
    MCLK_REGS->MCLK_BUPDIV = MCLK_BUPDIV_BUPDIV(0x08);

    GCLK0_Initialize();
    GCLK1_Initialize();
    GCLK2_Initialize();


    /* Selection of the Generator and write Lock for EIC */
    GCLK_REGS->GCLK_PCHCTRL[3] = GCLK_PCHCTRL_GEN(0x0)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[3] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for EVSYS_0 */
    GCLK_REGS->GCLK_PCHCTRL[5] = GCLK_PCHCTRL_GEN(0x2)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[5] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for SERCOM2_CORE */
    GCLK_REGS->GCLK_PCHCTRL[20] = GCLK_PCHCTRL_GEN(0x0)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[20] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for SERCOM3_CORE */
    GCLK_REGS->GCLK_PCHCTRL[21] = GCLK_PCHCTRL_GEN(0x0)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[21] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for ADC */
    GCLK_REGS->GCLK_PCHCTRL[30] = GCLK_PCHCTRL_GEN(0x1)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[30] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }



}
