/*
 * Instance header file for PIC32CZ8110CA80208
 *
 * Copyright (c) 2022 Microchip Technology Inc. and its subsidiaries.
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

/* file generated from device description version 2022-07-07T22:59:24Z */
#ifndef _PIC32CZCA80_EVSYS_INSTANCE_
#define _PIC32CZCA80_EVSYS_INSTANCE_


/* ========== Instance Parameter definitions for EVSYS peripheral ========== */
#define EVSYS_ASYNCHRONOUS_CHANNELS              (0xFFFFF000) /* Mask of Only Asynchronous Channels */
#define EVSYS_CHANNELS                           (32)       /* Total Number of Channels */
#define EVSYS_CHANNELS_BITS                      (5)        /* Number of bits to select Channel */
#define EVSYS_GCLK_ID_0                          (6)        /* Index of Generic Clocks for Synchronous Channels 0 */
#define EVSYS_GCLK_ID_1                          (7)        /* Index of Generic Clocks for Synchronous Channels 1 */
#define EVSYS_GCLK_ID_2                          (8)        /* Index of Generic Clocks for Synchronous Channels 2 */
#define EVSYS_GCLK_ID_3                          (9)        /* Index of Generic Clocks for Synchronous Channels 3 */
#define EVSYS_GCLK_ID_4                          (10)       /* Index of Generic Clocks for Synchronous Channels 4 */
#define EVSYS_GCLK_ID_5                          (11)       /* Index of Generic Clocks for Synchronous Channels 5 */
#define EVSYS_GCLK_ID_6                          (12)       /* Index of Generic Clocks for Synchronous Channels 6 */
#define EVSYS_GCLK_ID_7                          (13)       /* Index of Generic Clocks for Synchronous Channels 7 */
#define EVSYS_GCLK_ID_8                          (14)       /* Index of Generic Clocks for Synchronous Channels 8 */
#define EVSYS_GCLK_ID_9                          (15)       /* Index of Generic Clocks for Synchronous Channels 9 */
#define EVSYS_GCLK_ID_10                         (16)       /* Index of Generic Clocks for Synchronous Channels 10 */
#define EVSYS_GCLK_ID_11                         (17)       /* Index of Generic Clocks for Synchronous Channels 11 */
#define EVSYS_GENERATORS                         (138)      /* Total Number of Event Generators */
#define EVSYS_GENERATORS_BITS                    (8)        /* Number of bits to select Event Generator */
#define EVSYS_SECURE_IMPLEMENTED                 (0)        /* Security Configuration implemented? */
#define EVSYS_SPLIT_IRQ_NUM                      (12)       /* Number of channels with dedicated interrupt line request */
#define EVSYS_SYNCH_NUM                          (12)       /* Number of Synchronous Channels */
#define EVSYS_SYNCH_NUM_BITS                     (4)        /* Number of bits to select Synchronous Channels */
#define EVSYS_USERS                              (117)      /* Total Number of Event Users */
#define EVSYS_USERS_BITS                         (7)        /* Number of bits to select Event User */
#define EVSYS_USERS_GROUPS                       (4)        /* Number of 32-user Groups */
#define EVSYS_INSTANCE_ID                        (22)       /* Instance index for EVSYS */
#define EVSYS_MCLK_ID_APB                        (30)       /* Index for EVSYS APB clock */
#define EVSYS_PAC_ID                             (22)       /* Index for EVSYS registers write protection */

#endif /* _PIC32CZCA80_EVSYS_INSTANCE_ */
