/**
 * \brief Instance header file for ATSAMD21J17D
 *
 * Copyright (c) 2021 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software and any derivatives
 * exclusively with Microchip products. It is your responsibility to comply with third party license
 * terms applicable to your use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
 * APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
 * MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
 * EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/* file generated from device description version 2020-11-19T13:00:05Z */
#ifndef _SAMD21_GCLK_INSTANCE_
#define _SAMD21_GCLK_INSTANCE_


/* ========== Instance Parameter definitions for GCLK peripheral ========== */
#define GCLK_GENDIV_BITS                         _UL_(16)   
#define GCLK_GEN_NUM                             _UL_(9)    /* Number of Generic Clock Generators */
#define GCLK_GEN_NUM_MSB                         _UL_(8)    /* Number of Generic Clock Generators - 1 */
#define GCLK_GEN_SOURCE_NUM_MSB                  _UL_(8)    /* Number of Generic Clock Sources - 1 */
#define GCLK_NUM                                 _UL_(38)   /* Number of Generic Clock Users */
#define GCLK_SOURCE_DFLL48M                      _UL_(7)    /* DFLL48M output */
#define GCLK_SOURCE_FDPLL                        _UL_(8)    /* FDPLL output */
#define GCLK_SOURCE_GCLKGEN1                     _UL_(2)    /* Generic clock generator 1 output */
#define GCLK_SOURCE_GCLKIN                       _UL_(1)    /* Generator input pad */
#define GCLK_SOURCE_NUM                          _UL_(9)    /* Number of Generic Clock Sources */
#define GCLK_SOURCE_OSCULP32K                    _UL_(3)    /* OSCULP32K oscillator output */
#define GCLK_SOURCE_OSC8M                        _UL_(6)    /* OSC8M oscillator output */
#define GCLK_SOURCE_OSC32K                       _UL_(4)    /* OSC32K oscillator outpur */
#define GCLK_SOURCE_XOSC                         _UL_(0)    /* XOSC oscillator output */
#define GCLK_SOURCE_XOSC32K                      _UL_(5)    /* XOSC32K oscillator output */
#define GCLK_INSTANCE_ID                         _UL_(3)    

#endif /* _SAMD21_GCLK_INSTANCE_ */
