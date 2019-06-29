/** \brief Adding newlib stuff */
#include <unistd.h>
#include <string.h>
#include "cortex_core/include/f4_disc_leds.h"

#define DELAY_INTERVAL 0x186004

void delay(const unsigned int i);

int main()
{
  
  int counter = 0;
  int counter_address = (int)&counter;

  f4_disc_leds_initialize();
  
  asm("LDR r2, %0"
	  :
	  : "m" (counter_address)
	  );

  char * test = "Test";
  char * str = "Test";
  
  int compare = strcmp(test, str);
  int compare_addr = (int)&compare;
	
  asm("LDR r2, %0"
	  :
	  : "m" (compare_addr)
	  );

  while(1)
  {
	++counter;
	f4_disc_leds_turn_on(Red);
	delay(DELAY_INTERVAL);
	f4_disc_leds_turn_off(Red);
	delay(DELAY_INTERVAL);

  }
  return 0;
}

void delay(const unsigned int i)
{
  for(int x =0; x < i; ++x);  //Just loop to eat up time.
}
