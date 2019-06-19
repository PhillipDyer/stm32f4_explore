

//const static int test = 0xDEADBEEF;
//static char hello[] = "Hello World\n";
//static char * hello_ptr = (char *)0x20003000;

//int *counter;
//int *deadbeef;

int main()
{
  /*
  *counter = 0;
  *deadbeef = test;

  //char * ptr = hello;

  while(*ptr != 0)
  {
	*hello_ptr = *ptr;
	++hello_ptr;
	++ptr;
  }

  //Stick a null terminator on.
  *hello_ptr = 0;
  */
  while(1)
  {
	//++*counter;
	asm("ADDS r0, r0, #1");
	asm("LDR r1, =0xDEADBEEF");
	asm("LDR r6, =0xDEADBEEF");
  }
  return 0;
}
