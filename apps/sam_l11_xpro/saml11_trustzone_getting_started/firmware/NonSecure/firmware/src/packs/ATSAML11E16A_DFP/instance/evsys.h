/*
 * Instance header file for ATSAML11E16A
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

/* file generated from device description version 2023-04-12T14:18:55Z */
#ifndef _SAML11_EVSYS_INSTANCE_
#define _SAML11_EVSYS_INSTANCE_


/* ========== Instance Parameter definitions for EVSYS peripheral ========== */
#define EVSYS_ASYNCHRONOUS_CHANNELS              (0x000000F0) /* Mask of Only Asynchronous Channels */
#define EVSYS_CHANNELS                           (8)        /* Number of Channels */
#define EVSYS_CHANNELS_BITS                      (3)        /* Number of bits to select Channel */
#define EVSYS_GCLK_ID_0                          (6)        /* Index of Generic Clock 0 */
#define EVSYS_GCLK_ID_1                          (7)        /* Index of Generic Clock 1 */
#define EVSYS_GCLK_ID_2                          (8)        /* Index of Generic Clock 2 */
#define EVSYS_GCLK_ID_3                          (9)        /* Index of Generic Clock 3 */
#define EVSYS_GENERATORS                         (49)       /* Total Number of Event Generators */
#define EVSYS_GENERATORS_BITS                    (6)        /* Number of bits to select Event Generator */
#define EVSYS_INSTANCE_ID                        (64)       
#define EVSYS_SECURE_IMPLEMENTED                 (1)        /* Secure Channels/Users supported? */
#define EVSYS_SYNCH_NUM                          (4)        /* Number of Synchronous Channels */
#define EVSYS_SYNCH_NUM_BITS                     (2)        /* Number of bits to select Synchronous Channels */
#define EVSYS_USERS                              (23)       /* Total Number of Event Users */
#define EVSYS_USERS_BITS                         (5)        /* Number of bits to select Event User */
#define EVSYS_USERS_GROUPS                       (1)        /* Number of 32-user groups */

#endif /* _SAML11_EVSYS_INSTANCE_ */
