/*******************************************************************************
  SPI-I2S PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_i2s1.c

  Summary:
    I2S1 Source File

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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>                    // Defines true
#include "plib_i2s1.h"

// *****************************************************************************
// *****************************************************************************
// Section: I2S1 Implementation
// *****************************************************************************
// *****************************************************************************

#define SPI1_CON_FRMEN                      (1 << _SPI1CON_FRMEN_POSITION)      // always 1 for I2S
#define SPI1_CON_FRMSYNC                    (0 << _SPI1CON_FRMSYNC_POSITION)
#define SPI1_CON_FRMPOL                     (1 << _SPI1CON_FRMPOL_POSITION)
#define SPI1_CON_MSSEN                      (1 << _SPI1CON_MSSEN_POSITION)      // always 1 for I2S
#define SPI1_CON_FRMSYPW                    (0 << _SPI1CON_FRMSYPW_POSITION)    // always 0 for I2S
#define SPI1_CON_FRMCNT                     (4 << _SPI1CON_FRMCNT_POSITION)
#define SPI1_CON_MCLKSEL                    (1 << _SPI1CON_MCLKSEL_POSITION)    // always 1 for I2S
#define SPI1_CON_SPIFE                      (0 << _SPI1CON_SPIFE_POSITION)
#define SPI1_CON_ENHBUF                     (0 << _SPI1CON_ENHBUF_POSITION)     // always 0 for I2S
#define SPI1_CON_MODE_32_MODE_16            (1 << _SPI1CON_MODE16_POSITION)
#define SPI1_CON_CKE                        (1 << _SPI1CON_CKE_POSITION)
#define SPI1_CON_CKP                        (1 << _SPI1CON_CKP_POSITION)
#define SPI1_CON_MSTEN                      (1 << _SPI1CON_MSTEN_POSITION)

#define SPI1_CON2_IGNROV                    (1 << _SPI1CON2_IGNROV_POSITION)
#define SPI1_CON2_IGNTUR                    (1 << _SPI1CON2_IGNTUR_POSITION)
#define SPI1_CON2_AUDEN                     (1 << _SPI1CON2_AUDEN_POSITION)     // 1 for I2S mode
#define SPI1_CON2_AUDMONO                   (0 << _SPI1CON2_AUDMONO_POSITION)
#define SPI1_CON2_AUDMOD                    (0 << _SPI1CON2_AUDMOD_POSITION)

void I2S1_Initialize ( void )
{
    uint32_t rdata;

    /* Disable SPI1 Interrupts */
    IEC3CLR = 0x2000;
    IEC3CLR = 0x4000;
    IEC3CLR = 0x8000;

    /* STOP and Reset the SPI */
    SPI1CON = 0;

    /* Clear the Receiver buffer */
    rdata = SPI1BUF;
    rdata = rdata;

    /* Clear SPI1 Interrupt flags */
    IFS3CLR = 0x2000;
    IFS3CLR = 0x4000;
    IFS3CLR = 0x8000;

    /* BAUD Rate register Setup */
    SPI1BRG = 1;

    /* CLear the Overflow */
    SPI1STATCLR = _SPI1STAT_SPIROV_MASK;

    SPI1CONSET = SPI1_CON_MSSEN | SPI1_CON_MCLKSEL | SPI1_CON_ENHBUF | SPI1_CON_MODE_32_MODE_16 | SPI1_CON_CKE | SPI1_CON_CKP |
       SPI1_CON_MSTEN | SPI1_CON_FRMEN | SPI1_CON_FRMPOL | SPI1_CON_FRMSYNC | SPI1_CON_FRMSYPW | SPI1_CON_FRMCNT | SPI1_CON_SPIFE;

    SPI1CON2SET = SPI1_CON2_IGNROV | SPI1_CON2_IGNTUR | SPI1_CON2_AUDEN | SPI1_CON2_AUDMONO | SPI1_CON2_AUDMOD;

    /* Enable SPI1 */
    SPI1CONSET = _SPI1CON_ON_MASK;
}

uint32_t I2S1_LRCLK_Get(void)
{
    // for I2S format, will sync on low to high transition
    volatile uint32_t ret = ((PORTB >> 0) & 0x1);
    return ret;
}

static uint32_t _calcRefclock(uint32_t sysclk, uint32_t rodivInt, uint32_t rotrimInt)
{
    return sysclk / ((uint32_t)2.0*((double)rodivInt+(double)rotrimInt/512.0));    
}

uint32_t I2S1_RefClockSet(uint32_t sysclk, uint32_t samplingRate, uint32_t mclk_sampleRate_multiplier)
{   
    // e.g. target sysclk = 198 MHz, samplingRate == 44100, mclk_sampleRate_multiplier = 256, so ideal refclk = 11289600
 
    // refclk = sysclk / (2 * (rodiv + (rotrim / 512) )
    // closest fit: rodiv = 8, rotrim = 394:  198000000 / (2 * (8 + 394/512) ) => 11289086,  /256 = 44097
    
    uint32_t refclk = samplingRate * mclk_sampleRate_multiplier;      // target ref clock
    
    // rodiv = sysclk / (2* refclk) - (rotrim / 512)
    double rodiv = (double)sysclk / (2.0*(double)refclk);
    uint16_t rodivInt = (uint16_t)rodiv;                // integer part becomes rodiv
    
    double rotrim = 512.0*(rodiv - (double)rodivInt);   // fractional part is rotrim/512      
    uint16_t rotrimInt = (uint16_t)rotrim;
     
    uint32_t refclk_m1 = (rotrimInt > 0) ? _calcRefclock(sysclk, rodivInt, rotrimInt-1) : _calcRefclock(sysclk, rodivInt-1, 511);       
    uint32_t refclk_0 = _calcRefclock(sysclk, rodivInt, rotrimInt);    
    uint32_t refclk_p1 = _calcRefclock(sysclk, rodivInt, rotrimInt+1);
    
    uint32_t error_m1 = abs(refclk_m1 - refclk);
    uint32_t error_0 = abs(refclk_0 - refclk);
    uint32_t error_p1 = abs(refclk_p1 - refclk);
    
    uint32_t minError = min(error_m1,error_0);
    minError = min(minError,error_p1);
    
    if (minError == error_m1)
    {
        if (rotrimInt > 0)
        {
            rotrimInt--;
        }
        else
        {
            rotrimInt = 511;
            rodivInt--;
        }
    }
    else if (minError == error_p1)
    {
        rotrimInt++;
    }
    // else rodivInt, rotrimInt ok as is
 
    // for debug
    //printf("%s_RefClockSet: %d %f %d %f %d %d %d %d\r\n","I2S1",
    //        refclock,rodiv,rodivInt,rotrim,rotrimInt,refclock_m1,refclock_0,refclock_p1);
    //printf("                  %d %d %d %d\r\n",error_m1,error_0,error_p1,minError);  
    
    uint32_t refclko = _calcRefclock(sysclk, rodivInt, rotrimInt); 
    uint32_t calcSamplingrate = refclko / mclk_sampleRate_multiplier;
    
    printf("%s_RefClockSet: %d %d %d %d\r\n","I2S1",
            rodivInt,rotrimInt,calcSamplingrate,refclko);
    
    bool int_flag = false;
    int_flag = (bool)__builtin_disable_interrupts();

    /* unlock system for clock configuration */
    SYSKEY = 0x00000000;
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;

    if (int_flag)
    {
        __builtin_mtc0(12, 0,(__builtin_mfc0(12, 0) | 0x0001)); /* enable interrupts */
    }

    uint32_t refclkConOld = REFO1CON;
    REFO1CON = refclkConOld & 7;       // On bit 0, but keep rosel field
    while (REFO1CON & 1);   // wait for Active bit to be 0
    
    REFO1CONSET = rodivInt*0x10000 | 0x200; // replace with new value    
    REFO1TRIM = rotrimInt*0x800000;
    
    REFO1CONSET = 0x9000;      // On bit, OE and Divswen = 1
   
    /* Lock system since done with clock configuration */
    int_flag = (bool)__builtin_disable_interrupts();

    SYSKEY = 0x33333333;

    if (int_flag) /* if interrupts originally were enabled, re-enable them */
    {
        __builtin_mtc0(12, 0,(__builtin_mfc0(12, 0) | 0x0001));
    }
    
    // for debug
    printf("                  %08x %08x\r\n",REFO1CON,REFO1TRIM);   
    return calcSamplingrate;
}

uint32_t I2S1_BaudRateSet(uint32_t bitClk, uint32_t baudRate)
{
    // bitClk is the bit clock, typically 4 * sampling rate
    // BRG = (bitClk/(2 * baudRate)) - 1 
    uint32_t t_brg;
    uint32_t baudHigh;
    uint32_t baudLow;
    uint32_t errorHigh;
    uint32_t errorLow;
    
    t_brg = (((bitClk/baudRate)/2u) - 1u);
    
    baudHigh = bitClk / (2u * (t_brg + 1u));
    baudLow = bitClk / (2u * (t_brg + 2u));
    errorHigh = baudHigh - baudRate;
    errorLow = baudRate - baudLow;

    if (errorHigh > errorLow)
    {
        t_brg++;
    }
    
    printf("%s_BaudRateSet: %d %d\r\n","I2S1",bitClk,t_brg);    
    SPI1BRG = t_brg;
    
    return t_brg;
}
