

int main()
{
  
  int counter = 0;
  int * deadbeef = (int *)0x2003000;
  int counter_address = (int)&counter;

	  
  asm("LDR r2, %0"
	  :
	  : "m" (counter_address)
	  );
  
  while(1)
  {
	//++*counter;
	asm("ADDS r0, r0, #1");
	asm("LDR r1, =0xDEADBEEF");
	asm("LDR r6, =0xDEADBEEF");
  }
  return 0;
}
