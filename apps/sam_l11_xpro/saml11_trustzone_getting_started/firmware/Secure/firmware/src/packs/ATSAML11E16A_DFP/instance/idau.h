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
#ifndef _SAML11_IDAU_INSTANCE_
#define _SAML11_IDAU_INSTANCE_


/* ========== Instance Parameter definitions for IDAU peripheral ========== */
#define IDAU_CRYA_AES_DECRYPT_T                  (0x02001908) /* crya_aes_decryp_t function address */
#define IDAU_CRYA_AES_ENCRYPT_T                  (0x02001904) /* crya_aes_encryp_t function address */
#define IDAU_CRYA_GF_MULT128                     (0x0200190C) /* crya_gf_mult128 function address */
#define IDAU_CRYA_SHA_PROCESS                    (0x02001900) /* crya_sha_process function address */
#define IDAU_GRANULARITY_ANSC                    (0x20)     /* Application Non-Secure Callable region granularity */
#define IDAU_GRANULARITY_AS                      (0x100)    /* Application Secure region granularity */
#define IDAU_GRANULARITY_BNSC                    (0x20)     /* Boot Flash Non-Secure Callable region granularity */
#define IDAU_GRANULARITY_BOOTPROT                (0x100)    /* BOOTPROT region granularity */
#define IDAU_GRANULARITY_BS                      (0x100)    /* Boot Flash Secure region granularity */
#define IDAU_GRANULARITY_DS                      (0x100)    /* DS region granularity */
#define IDAU_GRANULARITY_RS                      (0x80)     /* RAM Secure region granularity */
#define IDAU_INSTANCE_ID                         (32)       
#define IDAU_REGION_ANS                          (0x06)     /* Flash Non-Secure APPLICATION region number */
#define IDAU_REGION_ANSC                         (0x05)     /* Flash Non-Secure Callable APPLICATION region number */
#define IDAU_REGION_AS                           (0x04)     /* Flash Secure APPLICATION region number */
#define IDAU_REGION_BNS                          (0x03)     /* Flash Non-Secure BOOT region number */
#define IDAU_REGION_BNSC                         (0x02)     /* Flash Non-Secure Callable BOOT region number */
#define IDAU_REGION_BOOTROM                      (0x09)     /* Boot ROM region number */
#define IDAU_REGION_BS                           (0x01)     /* Flash Secure BOOT region number */
#define IDAU_REGION_DNS                          (0x08)     /* Non-Secure DATA Flash region number */
#define IDAU_REGION_DS                           (0x07)     /* Secure DATA Flash region number */
#define IDAU_REGION_IOBUS                        (0x00)     /* IOBUS region number (invalid) */
#define IDAU_REGION_OTHER                        (0x00)     /* Others region number (invalid) */
#define IDAU_REGION_PERIPHERALS                  (0x00)     /* Peripherals region number (invalid) */
#define IDAU_REGION_RNS                          (0x0B)     /* Non-Secure SRAM region number */
#define IDAU_REGION_RS                           (0x0A)     /* Secure SRAM region number */

#endif /* _SAML11_IDAU_INSTANCE_ */
