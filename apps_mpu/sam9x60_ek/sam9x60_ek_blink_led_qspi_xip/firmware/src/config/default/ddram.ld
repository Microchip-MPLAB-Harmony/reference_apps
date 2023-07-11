/*------------------------------------------------------------------------------
 *      Linker script for running in internal DDRAM on the SAM9
 *----------------------------------------------------------------------------*/

OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(entry)
SEARCH_DIR(.)

/* Memory Spaces Definitions */
MEMORY
{
	ram        (WXR) : ORIGIN = 0x300000,   LENGTH = 64K  /* sram */
	/* QSPI flash SST26VF064B  on SAM9X60 EK is 64Mbit- 0x70000000--0x708000000 
	   0x70000000 - 0x7003FFFF is reserved for at91bootstrap*/
	rom         (LRX) : ORIGIN = 0x70040000, LENGTH = 0x07BFFFF  /* qspi */
}

C_STACK_SIZE   = 4096;
IRQ_STACK_SIZE = 96;
FIQ_STACK_SIZE = 96;
SVC_STACK_SIZE = 4096;
ABT_STACK_SIZE = 64;
UND_STACK_SIZE = 64;

/* Section Definitions */
SECTIONS
{
	.text 0x70040000 :
	{
		. = ALIGN(4);
		PROVIDE(_sfixed = .);
		*(.textEntry)
		*(.text .text.* .gnu.linkonce.t.*)
		*(.rodata .rodata* .gnu.linkonce.r.*)
		*(.ARM.extab* .gnu.linkonce.armextab.*)

		. = ALIGN(4);
		KEEP(*(.init))
		. = ALIGN(4);
		PROVIDE(__preinit_array_start = .);
		KEEP(*(.preinit_array))
		PROVIDE(__preinit_array_end = .);

		. = ALIGN(4);
		PROVIDE(__init_array_start = .);
		KEEP(*(SORT(.init_array.*)))
		KEEP(*(.init_array))
		PROVIDE(__init_array_end = .);

		. = ALIGN(0x4);
		KEEP(*crtbegin.o(.ctors))
		KEEP(*(EXCLUDE_FILE (*crtend.o) .ctors))
		KEEP(*(SORT(.ctors.*)))
		KEEP(*crtend.o(.ctors))

		. = ALIGN(4);
		KEEP(*(.fini))

		. = ALIGN(4);
		PROVIDE(__fini_array_start = .);
		KEEP(*(.fini_array))
		KEEP(*(SORT(.fini_array.*)))
		PROVIDE(__fini_array_end = .);

		KEEP(*crtbegin.o(.dtors))
		KEEP(*(EXCLUDE_FILE (*crtend.o) .dtors))
		KEEP(*(SORT(.dtors.*)))
		KEEP(*crtend.o(.dtors))

	    *(.dinit*)
		. = ALIGN(4);
              PROVIDE(_efixed = .);            /* End of text section */
	} >rom

	/* .ARM.exidx is sorted, so has to go in its own output section.  */
	PROVIDE_HIDDEN (__exidx_start = .);
	.ARM.exidx :
	{
		*(.ARM.exidx* .gnu.linkonce.armexidx.*)
	} >rom
	PROVIDE_HIDDEN (__exidx_end = .);

	/* _etext must be just before .relocate section */
	. = ALIGN(4);
	PROVIDE(_etext = .);

	.relocate (NOLOAD) :
	{
		. = ALIGN(4);
		PROVIDE(_srelocate = .);
		KEEP(*(.vectors .vectors.*))
		*(.ramfunc)
		*(.data .data.*);
		. = ALIGN(4);
	} >ram AT>rom
	
    PROVIDE(_erelocate = .);

	/* .bss section which is used for uninitialized data */
	.bss (NOLOAD) :
	{
		. = ALIGN(4);
		PROVIDE(_szero = .);
		*(.bss .bss.*)
		*(COMMON)
		. = ALIGN(4);
		PROVIDE(_ezero = .);
	} >ram

	.region_cache_aligned (NOLOAD) :
	{
		. = ALIGN(32);
		*(.region_cache_aligned .region_cache_aligned.*)
		. = ALIGN(32);
	} >ram

	.stacks (NOLOAD) :
	{
		. += IRQ_STACK_SIZE;
		. = ALIGN(8);
		_irqstack = .;

		. += FIQ_STACK_SIZE;
		. = ALIGN(8);
		_fiqstack = .;

		. += ABT_STACK_SIZE;
		. = ALIGN(8);
		_abtstack = .;

		. += UND_STACK_SIZE;
		. = ALIGN(8);
		_undstack = .;

		. += SVC_STACK_SIZE;
		. = ALIGN(8);
		_svcstack = .;

		. += C_STACK_SIZE;
		. = ALIGN(8);
		_cstack = .;
	} >ram

	_end = .;
	_ramcode_lma = _end;
	.ramcode :
	AT ( _ramcode_lma )
	{
		_sramcode = .; *(.ramcode_section .ramcode_section.*); _eramcode = .;
	} > ram
	_ramdata_lma = _end + _eramcode - _sramcode;
	.ramdata :
	AT ( _ramdata_lma )
	{
		_sramdata = .; *(.ramdata_section .ramdata_section.*); _eramdata = .;
	} > ram
}
