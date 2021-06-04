/*--------------------------------------------------------------------------
 * MPLAB XC32 Compiler -  ATSAML11E16A linker script
 * 
 * Copyright (c) 2021, Microchip Technology Inc. and its subsidiaries ("Microchip")
 * All rights reserved.
 * 
 * This software is developed by Microchip Technology Inc. and its
 * subsidiaries ("Microchip").
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are 
 * met:
 * 
 * 1.      Redistributions of source code must retain the above copyright
 *         notice, this list of conditions and the following disclaimer.
 * 2.      Redistributions in binary form must reproduce the above 
 *         copyright notice, this list of conditions and the following 
 *         disclaimer in the documentation and/or other materials provided 
 *         with the distribution.
 * 3.      Microchip's name may not be used to endorse or promote products
 *         derived from this software without specific prior written 
 *         permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY MICROCHIP "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL MICROCHIP BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWSOEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */


OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
SEARCH_DIR(.)

/*
 *  Define the __XC32_RESET_HANDLER_NAME macro on the command line when you
 *  want to use a different name for the Reset Handler function.
 */
#ifndef __XC32_RESET_HANDLER_NAME
#define __XC32_RESET_HANDLER_NAME Reset_Handler
#endif /* __XC32_RESET_HANDLER_NAME */

/*  Set the entry point in the ELF file. Once the entry point is in the ELF
 *  file, you can then use the --write-sla option to xc32-bin2hex to place
 *  the address into the hex file using the SLA field (RECTYPE 5). This hex
 *  record may be useful for a bootloader that needs to determine the entry
 *  point to the application.
 */
ENTRY(__XC32_RESET_HANDLER_NAME)

/* Device defaults */
#define _DEVICE_ROM_ORIGIN 0x0
#define _DEVICE_ROM_LENGTH 0x10000
#define _DEVICE_RAM_ORIGIN 0x20000000
#define _DEVICE_RAM_LENGTH 0x4000
#define _DEVICE_DATAFLASH_LENGTH 0x800

/* Define sizes if they have not been supplied. */
#ifndef ROM_ORIGIN
#  define ROM_ORIGIN _DEVICE_ROM_ORIGIN
#endif

#ifndef ROM_LENGTH
#  define ROM_LENGTH _DEVICE_ROM_LENGTH
#endif

#ifndef RAM_ORIGIN
#  define RAM_ORIGIN _DEVICE_RAM_ORIGIN
#endif

#ifndef RAM_LENGTH
#  define RAM_LENGTH _DEVICE_RAM_LENGTH
#endif

/* Check that values are sane. */
#if ROM_LENGTH > _DEVICE_ROM_LENGTH
#  error "ROM_LENGTH is greater than the max size of 0x10000"
#endif

#if RAM_LENGTH > _DEVICE_RAM_LENGTH
#  error "RAM_LENGTH is greater than the max size of 0x4000"
#endif

/*  Linker Macros controlling memory regions for TrustZone-M
 *
 *  Linking either the secure or non-secure application requires that the
 *  linker know the address and length of secure, non-secure, and non-secure
 *  callable memory regions. The following are the preprocessor definitions
 *  that are used to set and control memory zones for TrustZone when linking
 *  TrustZone applications. They are passed as -Wl,-DNAME[=value].
 *
 *  When building a secure application, the following preprocessor definitions
 *  affect this linker script.
 *
 *  + SECURE (required): Use the memory layout for a secure application.
 *  + BOOTPROT_SIZE=size (recommended): Defines the boot protection size in bytes.
 *    The default value is 0 if not provided.
 *  + AS_SIZE=size (recommended): Defines the flash application secure size, in
 *    bytes. Defaults to 50% of ROM is not provided.
 *  + ANSC_SIZE=size (recommended): Defines the flash application non-secure
 *    callable size, in bytes. Defaults to 0 if not provided.
 *
 *  When building a non-secure application, the following preprocessor
 *  definitions affect this linker script.
 *
 *  + NONSECURE (required): Use the memory layout for a non-secure application.
 *  + BOOTPROT_SIZE=size (recommended): Defines the boot protections size in bytes.
 *    The default value is 0 if not provided.
 *  + AS_SIZE=size (recommended): Defines the flash secure application size, in
 *    bytes. Defaults to 50% of ROM if not provided.
 *
 *  When building a secure bootloader, the following preprocessor
 *  definitions are used.
 *
 *  + SECURE_BOOTLOADER (required): Use the memory layout for a secure bootloader.
 *  + BS_SIZE=size (recommended): Defines the flash secure boot area size in bytes.
 *    Defaults to 50% of ROM if not provided.
 *  + BNSC_SIZE=size (recommended): Defines the flash non-secure callable boot size
 *    in bytes. Defaults to 0 if not provided.
 *
 *  When building a nonsecure bootloader application, the following
 *  preprocessor definitions are used.
 *
 *  + NONSECURE_BOOTLOADER (required): Use the memory layout for a
 *    nonsecure bootloader application.
 *  + BOOTPROT_SIZE (recommended): Defines the boot protection area, in bytes.
 *    Defaults to 0 if not provided.
 *  + BS_SIZE (recommended): Defines the flash secure boot area size in bytes.
 *    Defaults to 50% of ROM if not provided.
 *
 *  All application types can use the following macro.
 *
 *  + RS_SIZE=size (recommended): Defines the size of secure RAM, in bytes.
 *    Defaults to 50% of RAM if not provided.
 *
 *  In all cases, if a recommended value is not provided it will result in a warning
 *  message from the linker preprocessor.  It is advised to specify all the recommended
 *  macros for an application type to avoid any surprising results.
 *
 *  IMPORTANT: The memory region sizes must match those programmed in the device
 *  configuration bits in NVM User Row (UROW) and NVM Boot Configuration Row (BOCOR).
 *  These can be set as configuration bits via #pragma config in the source code.
 *  If that is done, the values in the config bits must match up with the values in
 *  the linker scripts dictating the memory regions in order to facilitate proper
 *  operation. See the normal config pragma documentation for the names of the fields
 *  and values.
 *
 */

#if (defined(SECURE_BOOTLOADER) + defined(NONSECURE_BOOTLOADER) + defined(SECURE) + defined(NONSECURE)) > 1
#  error "Exactly one of SECURE, NONSECURE, SECURE_BOOTLOADER, or NONSECURE_BOOTLOADER must be defined."
#endif

#if (defined(SECURE_BOOTLOADER) + defined(NONSECURE_BOOTLOADER) + defined(SECURE) + defined(NONSECURE)) == 0
#  warning "Defaulting to a SECURE TrustZone-M project. Please define the linker macro SECURE, NONSECURE, SECURE_BOOTLOADER, or NONSECURE_BOOTLOADER (e.g. -Wl,-DSECURE)."
#  define SECURE
#endif

#if defined(SECURE) || defined(NONSECURE) || defined(NONSECURE_BOOTLOADER)
#  ifndef BOOTPROT_SIZE
#    warning "Boot protection size (BOOTPROT_SIZE) not specified (e.g. -Wl,-DBOOTPROT_SIZE=size). Assuming 0 bytes."
#    define BOOTPROT_SIZE 0x0
#  endif
#endif

#if defined(SECURE) || defined(NONSECURE)
#  ifndef AS_SIZE
#    warning "Secure app length (AS_SIZE) not specified (e.g. -Wl,-DAS_SIZE=size). Assuming half of ROM (0x8000 bytes)."
#    define AS_SIZE 0x8000
#  endif
#endif

#if defined(SECURE_BOOTLOADER) || defined(NONSECURE_BOOTLOADER)
#  ifndef BS_SIZE
#    warning "Secure boot app length (BS_SIZE) not specified (e.g. -Wl,-DBS_SIZE=size). Assuming half of ROM (0x8000 bytes)."
#    define BS_SIZE 0x8000
#  endif
#endif

#if defined(SECURE_BOOTLOADER)
#  ifndef BNSC_SIZE
#    warning "Non-secure callable boot length (BNSC_SIZE) not specified (e.g. -Wl,-DBNSC_SIZE=size). Assuming 0 bytes."
#    define BNSC_SIZE 0x0
#  endif
#endif

#if defined(SECURE)
#  ifndef ANSC_SIZE
#    warning "Non-secure callable length (ANSC_SIZE) not specified (e.g. -Wl,-DANSC_SIZE=size). Assuming 0 bytes."
#    define ANSC_SIZE 0x0
#  endif
#endif

#ifndef RS_SIZE
#  warning "Secure SRAM length (RS_SIZE) not specified (e.g. -Wl,-DRS_SIZE=size). Assuming half of SRAM (0x2000 bytes)."
#  define RS_SIZE 0x2000
#endif

#if defined(SECURE_BOOTLOADER)
#  define _SECURE
#  define TZ_ROM_ORIGIN (ROM_ORIGIN)
#  define TZ_ROM_LENGTH (BS_SIZE)
#  define TZ_ROM_NSC_ORIGIN ((ROM_ORIGIN + BS_SIZE) - BNSC_SIZE)
#  define TZ_ROM_NSC_LENGTH (BNSC_SIZE)
#  define TZ_RAM_ORIGIN (RAM_ORIGIN)
#  define TZ_RAM_LENGTH (RS_SIZE)
#elif defined(NONSECURE_BOOTLOADER)
#  define TZ_ROM_ORIGIN (ROM_ORIGIN + BS_SIZE)
#  define TZ_ROM_LENGTH (BOOTPROT_SIZE - BS_SIZE)
#  define TZ_RAM_ORIGIN (RAM_ORIGIN + RS_SIZE)
#  define TZ_RAM_LENGTH (RAM_LENGTH - RS_SIZE)
#elif defined(SECURE)
#  define _SECURE
#  define TZ_ROM_ORIGIN (ROM_ORIGIN + BOOTPROT_SIZE)
#  define TZ_ROM_LENGTH (AS_SIZE)
#  define TZ_ROM_NSC_ORIGIN (ROM_ORIGIN + ((BOOTPROT_SIZE + AS_SIZE) - ANSC_SIZE))
#  define TZ_ROM_NSC_LENGTH (ANSC_SIZE)
#  define TZ_RAM_ORIGIN (RAM_ORIGIN)
#  define TZ_RAM_LENGTH (RS_SIZE)
#elif defined(NONSECURE)
#  define TZ_ROM_ORIGIN (ROM_ORIGIN + (BOOTPROT_SIZE + AS_SIZE))
#  define TZ_ROM_LENGTH (ROM_LENGTH - (BOOTPROT_SIZE + AS_SIZE))
#  define TZ_RAM_ORIGIN (RAM_ORIGIN + RS_SIZE)
#  define TZ_RAM_LENGTH (RAM_LENGTH - RS_SIZE)
#endif

/*************************************************************************
 * Memory-Region Definitions
 * The MEMORY command describes the location and size of blocks of memory
 * on the target device. The command below uses the macros defined above.
 *************************************************************************/
MEMORY
{
  rom (LRX) : ORIGIN = TZ_ROM_ORIGIN, LENGTH = TZ_ROM_LENGTH
#if defined(_SECURE)
  rom_nsc (LRX) : ORIGIN = TZ_ROM_NSC_ORIGIN, LENGTH = TZ_ROM_NSC_LENGTH
#endif
  ram (WX!R) : ORIGIN = TZ_RAM_ORIGIN, LENGTH = TZ_RAM_LENGTH
  config_00804000 : ORIGIN = 0x00804000, LENGTH = 0x4
  config_0080C000 : ORIGIN = 0x0080C000, LENGTH = 0x4
  config_00804004 : ORIGIN = 0x00804004, LENGTH = 0x4
  config_00804008 : ORIGIN = 0x00804008, LENGTH = 0x4
  config_0080C0EC : ORIGIN = 0x0080C0EC, LENGTH = 0x4
  config_0080400C : ORIGIN = 0x0080400C, LENGTH = 0x4
  config_0080C010 : ORIGIN = 0x0080C010, LENGTH = 0x4
  config_00804018 : ORIGIN = 0x00804018, LENGTH = 0x4
  config_00804014 : ORIGIN = 0x00804014, LENGTH = 0x4
  config_0080C018 : ORIGIN = 0x0080C018, LENGTH = 0x4
  config_0080C004 : ORIGIN = 0x0080C004, LENGTH = 0x4
  config_0080C01C : ORIGIN = 0x0080C01C, LENGTH = 0x4
  config_0080C020 : ORIGIN = 0x0080C020, LENGTH = 0x4
  config_0080C024 : ORIGIN = 0x0080C024, LENGTH = 0x4
  config_0080C028 : ORIGIN = 0x0080C028, LENGTH = 0x4
  config_0080401C : ORIGIN = 0x0080401C, LENGTH = 0x4
  config_0080C02C : ORIGIN = 0x0080C02C, LENGTH = 0x4
  config_0080C030 : ORIGIN = 0x0080C030, LENGTH = 0x4
  config_0080C008 : ORIGIN = 0x0080C008, LENGTH = 0x4
  config_0080C034 : ORIGIN = 0x0080C034, LENGTH = 0x4
  config_0080C038 : ORIGIN = 0x0080C038, LENGTH = 0x4
  config_0080C03C : ORIGIN = 0x0080C03C, LENGTH = 0x4
  config_0080C040 : ORIGIN = 0x0080C040, LENGTH = 0x4
  config_0080C0E0 : ORIGIN = 0x0080C0E0, LENGTH = 0x4
  config_0080C044 : ORIGIN = 0x0080C044, LENGTH = 0x4
  config_0080C048 : ORIGIN = 0x0080C048, LENGTH = 0x4
  config_0080C04C : ORIGIN = 0x0080C04C, LENGTH = 0x4
  config_0080C050 : ORIGIN = 0x0080C050, LENGTH = 0x4
  config_0080C054 : ORIGIN = 0x0080C054, LENGTH = 0x4
  config_0080C058 : ORIGIN = 0x0080C058, LENGTH = 0x4
  config_0080C0E4 : ORIGIN = 0x0080C0E4, LENGTH = 0x4
  config_0080C05C : ORIGIN = 0x0080C05C, LENGTH = 0x4
  config_0080C060 : ORIGIN = 0x0080C060, LENGTH = 0x4
  config_00804010 : ORIGIN = 0x00804010, LENGTH = 0x4
  config_0080C064 : ORIGIN = 0x0080C064, LENGTH = 0x4
  config_0080C068 : ORIGIN = 0x0080C068, LENGTH = 0x4
  config_0080C06C : ORIGIN = 0x0080C06C, LENGTH = 0x4
  config_0080C0F0 : ORIGIN = 0x0080C0F0, LENGTH = 0x4
  config_0080C0E8 : ORIGIN = 0x0080C0E8, LENGTH = 0x4
  config_0080C0F4 : ORIGIN = 0x0080C0F4, LENGTH = 0x4
  config_0080C0F8 : ORIGIN = 0x0080C0F8, LENGTH = 0x4
  config_0080C014 : ORIGIN = 0x0080C014, LENGTH = 0x4
  config_0080C0FC : ORIGIN = 0x0080C0FC, LENGTH = 0x4

}

__rom_end = ORIGIN(rom) + LENGTH(rom);
#if defined(_SECURE)
__rom_nsc_end = ORIGIN(rom_nsc) + LENGTH(rom_nsc);
#endif
__ram_end = ORIGIN(ram) + LENGTH(ram);

/*************************************************************************
 * Section Definitions - Map input sections to output sections
 *************************************************************************/
SECTIONS
{
    .config_00804000 : {
      KEEP(*(.config_00804000))
    } > config_00804000
    .config_0080C000 : {
      KEEP(*(.config_0080C000))
    } > config_0080C000
    .config_00804004 : {
      KEEP(*(.config_00804004))
    } > config_00804004
    .config_00804008 : {
      KEEP(*(.config_00804008))
    } > config_00804008
    .config_0080C0EC : {
      KEEP(*(.config_0080C0EC))
    } > config_0080C0EC
    .config_0080400C : {
      KEEP(*(.config_0080400C))
    } > config_0080400C
    .config_0080C010 : {
      KEEP(*(.config_0080C010))
    } > config_0080C010
    .config_00804018 : {
      KEEP(*(.config_00804018))
    } > config_00804018
    .config_00804014 : {
      KEEP(*(.config_00804014))
    } > config_00804014
    .config_0080C018 : {
      KEEP(*(.config_0080C018))
    } > config_0080C018
    .config_0080C004 : {
      KEEP(*(.config_0080C004))
    } > config_0080C004
    .config_0080C01C : {
      KEEP(*(.config_0080C01C))
    } > config_0080C01C
    .config_0080C020 : {
      KEEP(*(.config_0080C020))
    } > config_0080C020
    .config_0080C024 : {
      KEEP(*(.config_0080C024))
    } > config_0080C024
    .config_0080C028 : {
      KEEP(*(.config_0080C028))
    } > config_0080C028
    .config_0080401C : {
      KEEP(*(.config_0080401C))
    } > config_0080401C
    .config_0080C02C : {
      KEEP(*(.config_0080C02C))
    } > config_0080C02C
    .config_0080C030 : {
      KEEP(*(.config_0080C030))
    } > config_0080C030
    .config_0080C008 : {
      KEEP(*(.config_0080C008))
    } > config_0080C008
    .config_0080C034 : {
      KEEP(*(.config_0080C034))
    } > config_0080C034
    .config_0080C038 : {
      KEEP(*(.config_0080C038))
    } > config_0080C038
    .config_0080C03C : {
      KEEP(*(.config_0080C03C))
    } > config_0080C03C
    .config_0080C040 : {
      KEEP(*(.config_0080C040))
    } > config_0080C040
    .config_0080C0E0 : {
      KEEP(*(.config_0080C0E0))
    } > config_0080C0E0
    .config_0080C044 : {
      KEEP(*(.config_0080C044))
    } > config_0080C044
    .config_0080C048 : {
      KEEP(*(.config_0080C048))
    } > config_0080C048
    .config_0080C04C : {
      KEEP(*(.config_0080C04C))
    } > config_0080C04C
    .config_0080C050 : {
      KEEP(*(.config_0080C050))
    } > config_0080C050
    .config_0080C054 : {
      KEEP(*(.config_0080C054))
    } > config_0080C054
    .config_0080C058 : {
      KEEP(*(.config_0080C058))
    } > config_0080C058
    .config_0080C0E4 : {
      KEEP(*(.config_0080C0E4))
    } > config_0080C0E4
    .config_0080C05C : {
      KEEP(*(.config_0080C05C))
    } > config_0080C05C
    .config_0080C060 : {
      KEEP(*(.config_0080C060))
    } > config_0080C060
    .config_00804010 : {
      KEEP(*(.config_00804010))
    } > config_00804010
    .config_0080C064 : {
      KEEP(*(.config_0080C064))
    } > config_0080C064
    .config_0080C068 : {
      KEEP(*(.config_0080C068))
    } > config_0080C068
    .config_0080C06C : {
      KEEP(*(.config_0080C06C))
    } > config_0080C06C
    .config_0080C0F0 : {
      KEEP(*(.config_0080C0F0))
    } > config_0080C0F0
    .config_0080C0E8 : {
      KEEP(*(.config_0080C0E8))
    } > config_0080C0E8
    .config_0080C0F4 : {
      KEEP(*(.config_0080C0F4))
    } > config_0080C0F4
    .config_0080C0F8 : {
      KEEP(*(.config_0080C0F8))
    } > config_0080C0F8
    .config_0080C014 : {
      KEEP(*(.config_0080C014))
    } > config_0080C014
    .config_0080C0FC : {
      KEEP(*(.config_0080C0FC))
    } > config_0080C0FC

    /*
     * The linker moves the .vectors section into itcm when itcm is
     * enabled via the -mitcm option, but only when this .vectors output
     * section exists in the linker script.
     */
    .vectors :
    {
        . = ALIGN(4);
        _sfixed = .;
        KEEP(*(.vectors .vectors.* .vectors_default .vectors_default.*))
        KEEP(*(.isr_vector))
        KEEP(*(.reset*))
        KEEP(*(.after_vectors))
    } > rom
    /*
     * Code Sections - Note that standard input sections such as
     * *(.text), *(.text.*), *(.rodata), & *(.rodata.*)
     * are not mapped here. The best-fit allocator locates them,
     * so that input sections may flow around absolute sections
     * as needed.
     */
    .text :
    {
        . = ALIGN(4);
        *(.glue_7t) *(.glue_7)
        /* Force the inclusion of debug info for veneers. This is
         * sensitive to the name of the .o file containing the
         * cmse_nonsecure_entry functions. What are given are
         * common file names. */
        KEEP(*veneer.o(.text.*))
        KEEP(*nonsecure_entry.o(.text.*))
        *(.gnu.linkonce.r.*)
        *(.ARM.extab* .gnu.linkonce.armextab.*)

        /* Support C constructors, and C destructors in both user code
           and the C library. This also provides support for C++ code. */
        . = ALIGN(4);
        KEEP(*(.init))
        . = ALIGN(4);
        __preinit_array_start = .;
        KEEP (*(.preinit_array))
        __preinit_array_end = .;

        . = ALIGN(4);
        __init_array_start = .;
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array))
        __init_array_end = .;

        . = ALIGN(0x4);
        KEEP (*crtbegin.o(.ctors))
        KEEP (*(EXCLUDE_FILE (*crtend.o) .ctors))
        KEEP (*(SORT(.ctors.*)))
        KEEP (*crtend.o(.ctors))

        . = ALIGN(4);
        KEEP(*(.fini))

        . = ALIGN(4);
        __fini_array_start = .;
        KEEP (*(.fini_array))
        KEEP (*(SORT(.fini_array.*)))
        __fini_array_end = .;

        KEEP (*crtbegin.o(.dtors))
        KEEP (*(EXCLUDE_FILE (*crtend.o) .dtors))
        KEEP (*(SORT(.dtors.*)))
        KEEP (*crtend.o(.dtors))

        . = ALIGN(4);
        _efixed = .;            /* End of text section */
    } > rom

    /* .ARM.exidx is sorted, so has to go in its own output section.  */
    PROVIDE_HIDDEN (__exidx_start = .);
    .ARM.exidx :
    {
      *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > rom
    PROVIDE_HIDDEN (__exidx_end = .);

    . = ALIGN(4);
    _etext = .;

#if defined(_SECURE)
    /* Holds the veneers for calling into secure code. */
    . = ALIGN(4);
    .gnu.sgstubs : {
        _ssgstubs = .;
    } > rom_nsc
#endif /* defined(SECURE) */

    /*
     *  Align here to ensure that the .bss section occupies space up to
     *  _end.  Align after .bss to ensure correct alignment even if the
     *  .bss section disappears because there are no input sections.
     *
     *  Note that input sections named .bss* are no longer mapped here.
     *  The best-fit allocator locates them, so that they may flow
     *  around absolute sections as needed.
     */
    .bss (NOLOAD) :
    {
        . = ALIGN(4);
        __bss_start__ = .;
        _sbss = . ;
        _szero = .;
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .;
        _ebss = . ;
        _ezero = .;
    } > ram

    . = ALIGN(4);
    _end = . ;
    _ram_end_ = ORIGIN(ram) + LENGTH(ram) -1 ;
}
