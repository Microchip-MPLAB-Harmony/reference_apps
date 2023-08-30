/*
 * Instance header file for ATSAMA7G54D4G
 *
 * Copyright (c) 2023 Microchip Technology Inc. and its subsidiaries.
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

/* file generated from device description version 2023-02-02T10:07:15Z */
#ifndef _SAMA7G_TC1_INSTANCE_
#define _SAMA7G_TC1_INSTANCE_


/* ========== Instance Parameter definitions for TC1 peripheral ========== */
#define TC1_CLOCK_ID_CHANNEL0                    (91)       
#define TC1_CLOCK_ID_CHANNEL1                    (92)       
#define TC1_CLOCK_ID_CHANNEL2                    (93)       
#define TC1_DMAC_ID_RX                           (52)       
#define TC1_INSTANCE_ID_CHANNEL0                 (91)       /* 32-bit Timer Counter 1 Channel 0 */
#define TC1_INSTANCE_ID_CHANNEL1                 (92)       /* 32-bit Timer Counter 1 Channel 1 interrupt */
#define TC1_INSTANCE_ID_CHANNEL2                 (93)       /* 32-bit Timer Counter 1 Channel 2 interrupt */
#define TC1_INSTANCE_ID_SINT0                    (148)      /* 32-bit Timer Counter 1 Channel 0, Secure INTerrupt */
#define TC1_INSTANCE_ID_SINT1                    (149)      /* 32-bit Timer Counter 1 Channel 1, Secure INTerrupt */
#define TC1_INSTANCE_ID_SINT2                    (150)      /* 32-bit Timer Counter 1 Channel 2, Secure INTerrupt */
#define TC1_NUM_INTERRUPT_LINES                  (3)        
#define TC1_TCCLKS_                              (0)        /* MCK1 */
#define TC1_TCCLKS_TIMER_CLOCK1                  (1)        /* GCLK */
#define TC1_TCCLKS_TIMER_CLOCK2                  (2)        /* MCK1/8 */
#define TC1_TCCLKS_TIMER_CLOCK3                  (3)        /* MCK1/32 */
#define TC1_TCCLKS_TIMER_CLOCK4                  (4)        /* MCK1/128 */
#define TC1_TCCLKS_TIMER_CLOCK5                  (5)        /* TD_SLCK */
#define TC1_TCCLKS_XC0                           (6)        /* XC0 */
#define TC1_TCCLKS_XC1                           (7)        /* XC1 */
#define TC1_TCCLKS_XC2                           (8)        /* XC2 */
#define TC1_TIMER_WIDTH                          (32)       

#endif /* _SAMA7G_TC1_INSTANCE_ */
