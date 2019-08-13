/** Define the end of RAM and the limit of stack memory */
/* (192K SRAM on the STM32F4 line, 192K */
/* 1M of Flash 1024K */
_stack_size = 0x2000;
_vector_size = 0x100;

MEMORY
{
	FLASH ( rx )	: ORIGIN = 0x08000000, LENGTH = 1024K
	RAM ( rxw )		: ORIGIN = 0x20000000, LENGTH = 192K
}

SECTIONS
{ 
	.text :
	{
	*(.text)
	} > FLASH
	
	.vectors :
	{
	*(.vectors)
	. = . + _vector_size;
	 } > RAM
	
	.stack : {
	__stack_end = .;
	. = . + _stack_size;
	. = ALIGN(4);
	__stack_start = .;
	} > RAM
	
	.data : {
		  *(.data)
	} > RAM

	__bss_start = .;
	__bss_start__ = .;
	.bss : {
		 *(.bss)
	} > RAM
	__bss_end__ = .;
	_bss_end__ = .;
}
