/*******************************************************************************
  I2S PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_i2s.c

  Summary:
    I2S Source File

  Description:
    This file has the implementation of all the interfaces provided for one
    particular instance of the Inter-IC Sound Controller (I2S) peripheral.

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

#include "plib_i2s.h"

// *****************************************************************************
// *****************************************************************************
// Section: I2S Implementation
// *****************************************************************************
// *****************************************************************************

void I2S_Initialize ( void )
{
    // enable CLK_I2S_APB clock so we can write to I2S registers
    MCLK_REGS->MCLK_APBDMASK |= MCLK_APBDMASK_I2S_Msk;

    // configure clock unit 0
    I2S_REGS->I2S_CLKCTRL[0] =
                                            I2S_CLKCTRL_MCKEN(1-1) |
                                            I2S_CLKCTRL_MCKSEL(1) |
                                            I2S_CLKCTRL_SCKSEL(1) |
                                            I2S_CLKCTRL_FSOUTINV(0) |
                                            I2S_CLKCTRL_FSINV(0) |
                                            I2S_CLKCTRL_FSSEL(1) |
                                            I2S_CLKCTRL_BITDELAY(1) |
                                            I2S_CLKCTRL_NBSLOTS(1) |        // always 2 slots for I2S
                                            I2S_CLKCTRL_SLOTSIZE(0x3);

    // configure clock unit 1
    I2S_REGS->I2S_CLKCTRL[1] =
                                            I2S_CLKCTRL_MCKOUTDIV(3-1) |
                                            I2S_CLKCTRL_MCKDIV(8-1) |
                                            I2S_CLKCTRL_MCKEN(1-0) |
                                            I2S_CLKCTRL_MCKSEL(0) |
                                            I2S_CLKCTRL_SCKSEL(0) |
                                            I2S_CLKCTRL_FSOUTINV(0) |
                                            I2S_CLKCTRL_FSINV(0) |
                                            I2S_CLKCTRL_FSSEL(0) |
                                            I2S_CLKCTRL_BITDELAY(1) |
                                            I2S_CLKCTRL_NBSLOTS(1) |        // always 2 slots for I2S
                                            I2S_CLKCTRL_SLOTSIZE(0x1);

    // configure TX serializer
    I2S_REGS->I2S_TXCTRL = I2S_TXCTRL_MONO(0) |
                                            I2S_TXCTRL_WORDADJ(1) |
                                            I2S_TXCTRL_DATASIZE(0x0) |
                                            I2S_TXCTRL_SLOTADJ(1) |
                                            I2S_TXCTRL_CLKSEL(0) |
                                            I2S_TXCTRL_SERMODE(I2S_TXCTRL_SERMODE_TX_Val);

    // configure RX serializer
    I2S_REGS->I2S_RXCTRL = I2S_RXCTRL_MONO(0) |
                                            I2S_RXCTRL_WORDADJ(1) |
                                            I2S_RXCTRL_DATASIZE(0x0) |
                                            I2S_RXCTRL_SLOTADJ(1) |
                                            I2S_RXCTRL_CLKSEL(0) |
                                            I2S_RXCTRL_SERMODE(I2S_RXCTRL_SERMODE_RX_Val);

    // enable the desired components
    I2S_REGS->I2S_CTRLA =  I2S_CTRLA_RXEN(0) |
                                            I2S_CTRLA_TXEN(1) |
                                            I2S_CTRLA_CKEN0(1)
                                          | I2S_CTRLA_CKEN1(0)
    // and the I2S module
                                          | I2S_CTRLA_ENABLE_Msk;
}

uint32_t I2S_LRCLK_Get(void)
{
    // for inverted (e.g. left-justified format), will sync on high to low transition
    volatile uint32_t ret = 1-((PORT_REGS->GROUP[0].PORT_IN >> 9) & 0x1);
    return ret;    
}


