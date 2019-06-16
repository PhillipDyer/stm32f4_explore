/** Define the end of RAM and the limit of stack memory */
/* (192K SRAM on the STM32F4 line, 192K */
/* 1M of Flash 1024K */
_estack = 0x20002000; /* Take the first 8K of RAM as Stack */

MEMORY
{
	FLASH ( rx )	: ORIGIN = 0x08000000, LENGTH = 1024K
	RAM ( rxw )		: ORIGIN = 0x20000000, LENGTH = 192K
}
