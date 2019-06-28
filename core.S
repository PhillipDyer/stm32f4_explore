// These instrucitons define the attributes of our chip and
// the assembly language we'll use:
.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb

// Global Memory Locations
.global vtable
.global reset_handler

/*
 * The actual vector table
 * Only the size of RAM and the 'reset' handler are
 * included for simplicity.
*/

.type vtable, %object
vtable:
	.word __stack_start
	.word reset_handler
.size vtable, .-vtable
	
/*
 * Reset Handler Called on reset.
*/
.type reset_handler, %function
reset_handler:
	//Set the stack pointer to the end of the stack.
	//The '_estack' value is defined in our linker script
	LDR 	r0, =__stack_start
	MOV		sp, r0

	//Set some dummy values. When we see these values in our debugger,
	//We'll know that our program is loaded on the chip and working
	LDR 	r7, =0xDEADBEEF
	MOVS	r0, #0
	//main_loop:
	//// Add one to register r0.
	//ADDS 	r0, r0, #1
	//Loop back
	//B		main_loop
	BL		main
.size reset_handler, .-reset_handler
