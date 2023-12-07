/*
 * Instance header file for PIC32CK2051SG01144
 *
 * Copyright (c) 2023 Microchip Technology Inc. and its subsidiaries.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/* file generated from device description file (ATDF) version 2023-11-16T06:44:02Z */
#ifndef _PIC32CKSG01_EVSYS_INSTANCE_
#define _PIC32CKSG01_EVSYS_INSTANCE_


/* ========== Instance Parameter definitions for EVSYS peripheral ========== */
#define EVSYS_ASYNCHRONOUS_CHANNELS              (0xFFFFF000) /* Mask of Only Asynchronous Channels */
#define EVSYS_CHANNELS                           (32)       /* Total Number of Channels */
#define EVSYS_CHANNELS_BITS                      (5)        /* Number of bits to select Channel */
#define EVSYS_GCLK_ID_0                          (6)        /* Index of Generic Clocks for Synchronous Channels 0 */
#define EVSYS_GCLK_ID_1                          (7)        /* Index of Generic Clocks for Synchronous Channels 1 */
#define EVSYS_GCLK_ID_10                         (16)       /* Index of Generic Clocks for Synchronous Channels 10 */
#define EVSYS_GCLK_ID_11                         (17)       /* Index of Generic Clocks for Synchronous Channels 11 */
#define EVSYS_GCLK_ID_2                          (8)        /* Index of Generic Clocks for Synchronous Channels 2 */
#define EVSYS_GCLK_ID_3                          (9)        /* Index of Generic Clocks for Synchronous Channels 3 */
#define EVSYS_GCLK_ID_4                          (10)       /* Index of Generic Clocks for Synchronous Channels 4 */
#define EVSYS_GCLK_ID_5                          (11)       /* Index of Generic Clocks for Synchronous Channels 5 */
#define EVSYS_GCLK_ID_6                          (12)       /* Index of Generic Clocks for Synchronous Channels 6 */
#define EVSYS_GCLK_ID_7                          (13)       /* Index of Generic Clocks for Synchronous Channels 7 */
#define EVSYS_GCLK_ID_8                          (14)       /* Index of Generic Clocks for Synchronous Channels 8 */
#define EVSYS_GCLK_ID_9                          (15)       /* Index of Generic Clocks for Synchronous Channels 9 */
#define EVSYS_GENERATORS                         (125)      /* Total Number of Event Generators */
#define EVSYS_GENERATORS_BITS                    (7)        /* Number of bits to select Event Generator */
#define EVSYS_INSTANCE_ID                        (39)       /* Instance index for EVSYS */
#define EVSYS_MCLK_ID_APB                        (70)       /* Index for EVSYS APB clock */
#define EVSYS_PAC_ID                             (39)       /* Index for EVSYS registers write protection */
#define EVSYS_SECURE_IMPLEMENTED                 (0)        /* Security Configuration implemented? */
#define EVSYS_SPLIT_IRQ_NUM                      (4)        /* Number of channels with dedicated interrupt line request */
#define EVSYS_SYNCH_NUM                          (12)       /* Number of Synchronous Channels */
#define EVSYS_SYNCH_NUM_BITS                     (4)        /* Number of bits to select Synchronous Channels */
#define EVSYS_USERS                              (104)      /* Total Number of Event Users */
#define EVSYS_USERS_BITS                         (7)        /* Number of bits to select Event User */
#define EVSYS_USERS_GROUPS                       (4)        /* Number of 32-user Groups */

#endif /* _PIC32CKSG01_EVSYS_INSTANCE_ */
