/*
 * Instance header file for PIC32CM5164JH01100
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

/* file generated from device description version 2023-04-26T09:03:33Z */
#ifndef _PIC32CMJH01_NVMCTRL_INSTANCE_
#define _PIC32CMJH01_NVMCTRL_INSTANCE_


/* ========== Instance Parameter definitions for NVMCTRL peripheral ========== */
#define NVMCTRL_DATAFLASH_ADDR                   (0x00400000) /* Start address of the Data Flash area */
#define NVMCTRL_DATAFLASH_PAGES                  (128)      
#define NVMCTRL_DATAFLASH_SIZE                   (8192)     /* Byte size of the Data Flash area */
#define NVMCTRL_ECC_PRESENT                      (1)        /* define out all the added ECC logic - when =0 there shall be no ECC logic present in the design */
#define NVMCTRL_FACTORY_WORD_IMPLEMENTED_MASK    (0XC0000007FFFFFFFF) 
#define NVMCTRL_FLASH_SIZE                       (524288)   
#define NVMCTRL_INSTANCE_ID                      (34)       /* Instance index for NVMCTRL */
#define NVMCTRL_PAGES                            (8192)     
#define NVMCTRL_PAGES_PR_REGION                  (512)      
#define NVMCTRL_PAGE_SIZE                        (64)       
#define NVMCTRL_PMSB                             (3)        
#define NVMCTRL_PSZ_BITS                         (6)        
#define NVMCTRL_RSTFFLTADDR                      (0x00000000) /* the reset default for FFLTADDR */
#define NVMCTRL_USER_PAGE_OFFSET                 (0x00800000) 
#define NVMCTRL_USER_WORD_IMPLEMENTED_MASK       (0XC01FFFFFFFFFFFFF) 

#endif /* _PIC32CMJH01_NVMCTRL_INSTANCE_ */
