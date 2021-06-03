/**
 * \brief Instance header file for PIC32CM1216MC00032
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

/* file generated from device description version 2020-08-13T21:04:00Z */
#ifndef _PIC32CMMC00_NVMCTRL_INSTANCE_
#define _PIC32CMMC00_NVMCTRL_INSTANCE_


/* ========== Instance Parameter definitions for NVMCTRL peripheral ========== */
#define NVMCTRL_ECC_PRESENT                      _UL_(0)    /* define out all the added ECC logic - when =0 there shall be no ECC logic present in the design */
#define NVMCTRL_FACTORY_WORD_IMPLEMENTED_MASK    _UL_(0XC0000007FFFFFFFF) 
#define NVMCTRL_PMSB                             _UL_(3)    
#define NVMCTRL_PSZ_BITS                         _UL_(6)    
#define NVMCTRL_RSTFFLTADDR                      _UL_(0)    /* the reset default for FFLTADDR */
#define NVMCTRL_USER_PAGE_OFFSET                 _UL_(0x00800000) 
#define NVMCTRL_USER_WORD_IMPLEMENTED_MASK       _UL_(0XC01FFFFFFFFFFFFF) 
#define NVMCTRL_DATAFLASH_PAGES                  _UL_(64)   
#define NVMCTRL_DATAFLASH_ROW_SIZE               _UL_(256)  
#define NVMCTRL_DATAFLASH_ADDR                   _UL_(0x00400000) /* Start address of the WWR EEPROM area */
#define NVMCTRL_DATAFLASH_SIZE                   _UL_(4096) /* Byte size of the WWR EEPROM area */
#define NVMCTRL_FLASH_SIZE                       _UL_(131072) 
#define NVMCTRL_PAGE_SIZE                        _UL_(64)   
#define NVMCTRL_PAGES                            _UL_(2048) 
#define NVMCTRL_PAGES_PR_REGION                  _UL_(128)  
#define NVMCTRL_ROW_SIZE                         _UL_(256)  
#define NVMCTRL_INSTANCE_ID                      _UL_(34)   /* Instance index for NVMCTRL */

#endif /* _PIC32CMMC00_NVMCTRL_INSTANCE_ */
