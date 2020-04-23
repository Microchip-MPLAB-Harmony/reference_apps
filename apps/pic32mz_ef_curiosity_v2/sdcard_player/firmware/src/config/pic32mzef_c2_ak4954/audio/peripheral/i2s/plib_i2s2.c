/*******************************************************************************
  SPI-I2S PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_i2s2.c

  Summary:
    I2S2 Source File

  Description:
    This file has implementation of all the interfaces provided for particular
    SPI-I2S peripheral.

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

#include "plib_i2s2.h"

// *****************************************************************************
// *****************************************************************************
// Section: I2S2 Implementation
// *****************************************************************************
// *****************************************************************************

#define SPI2_CON_FRMEN                      (1 << _SPI2CON_FRMEN_POSITION)      // always 1 for I2S
#define SPI2_CON_FRMSYNC                    (0 << _SPI2CON_FRMSYNC_POSITION)
#define SPI2_CON_FRMPOL                     (1 << _SPI2CON_FRMPOL_POSITION)
#define SPI2_CON_MSSEN                      (1 << _SPI2CON_MSSEN_POSITION)      // always 1 for I2S
#define SPI2_CON_FRMSYPW                    (0 << _SPI2CON_FRMSYPW_POSITION)    // always 0 for I2S
#define SPI2_CON_FRMCNT                     (4 << _SPI2CON_FRMCNT_POSITION)
#define SPI2_CON_MCLKSEL                    (1 << _SPI2CON_MCLKSEL_POSITION)    // always 1 for I2S
#define SPI2_CON_SPIFE                      (0 << _SPI2CON_SPIFE_POSITION)
#define SPI2_CON_ENHBUF                     (0 << _SPI2CON_ENHBUF_POSITION)     // always 0 for I2S
#define SPI2_CON_MODE_32_MODE_16            (1 << _SPI2CON_MODE16_POSITION)
#define SPI2_CON_CKE                        (1 << _SPI2CON_CKE_POSITION)
#define SPI2_CON_CKP                        (1 << _SPI2CON_CKP_POSITION)
#define SPI2_CON_MSTEN                      (1 << _SPI2CON_MSTEN_POSITION)

#define SPI2_CON2_IGNROV                    (1 << _SPI2CON2_IGNROV_POSITION)
#define SPI2_CON2_IGNTUR                    (1 << _SPI2CON2_IGNTUR_POSITION)
#define SPI2_CON2_AUDEN                     (1 << _SPI2CON2_AUDEN_POSITION)     // 1 for I2S mode
#define SPI2_CON2_AUDMONO                   (0 << _SPI2CON2_AUDMONO_POSITION)
#define SPI2_CON2_AUDMOD                    (0 << _SPI2CON2_AUDMOD_POSITION)

void I2S2_Initialize ( void )
{
    uint32_t rdata;

    /* Disable SPI2 Interrupts */
    IEC4CLR = 0x4000;
    IEC4CLR = 0x8000;
    IEC4CLR = 0x10000;

    /* STOP and Reset the SPI */
    SPI2CON = 0;

    /* Clear the Receiver buffer */
    rdata = SPI2BUF;
    rdata = rdata;

    /* Clear SPI2 Interrupt flags */
    IFS4CLR = 0x4000;
    IFS4CLR = 0x8000;
    IFS4CLR = 0x10000;

    /* BAUD Rate register Setup */
    SPI2BRG = 1;

    /* CLear the Overflow */
    SPI2STATCLR = _SPI2STAT_SPIROV_MASK;

    SPI2CONSET = SPI2_CON_MSSEN | SPI2_CON_MCLKSEL | SPI2_CON_ENHBUF | SPI2_CON_MODE_32_MODE_16 | SPI2_CON_CKE | SPI2_CON_CKP |
       SPI2_CON_MSTEN | SPI2_CON_FRMEN | SPI2_CON_FRMPOL | SPI2_CON_FRMSYNC | SPI2_CON_FRMSYPW | SPI2_CON_FRMCNT | SPI2_CON_SPIFE;

    SPI2CON2SET = SPI2_CON2_IGNROV | SPI2_CON2_IGNTUR | SPI2_CON2_AUDEN | SPI2_CON2_AUDMONO | SPI2_CON2_AUDMOD;

    /* Enable SPI2 */
    SPI2CONSET = _SPI2CON_ON_MASK;
}

uint32_t I2S2_LRCLK_Get(void)
{
    // for I2S format, will sync on low to high transition
    volatile uint32_t ret = ((PORTC >> 2) & 0x1);
    return ret;
}
