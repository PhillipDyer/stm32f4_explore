/** \brief Adding newlib stuff */
#include <unistd.h>
#include <string.h>
#include "cortex_core/include/f4_disc_leds.h"
#include "cortex_core/include/systick.h"
#include "cortex_core/include/interrupts.h"

#define DELAY_INTERVAL 0x186004

void delay(const unsigned int i);

f4_discovery_led next_led(f4_discovery_led led);

void light_green_isr();

int main()
{
  
  int counter = 0;
  int counter_address = (int)&counter;

  f4_disc_leds_initialize();
  
  asm("LDR r2, %0"
	  :
	  : "m" (counter_address)
	  );

  /*
  char * test = "Test";
  char * str = "Test";

  
  int compare = strcmp(test, str);
  int compare_addr = (int)&compare;
	
  asm("LDR r2, %0"
	  :
	  : "m" (compare_addr)
	  );
  */

  //disable_all_interrupts();
  //configureSysTick();
  //connectSysTickISR(&light_green_isr);
  //enable_all_interrupts(); 
  f4_discovery_led the_led = Red;
  while(1)
  {
	
	++counter;
	f4_disc_leds_turn_on(the_led);
	delay(DELAY_INTERVAL);
	f4_disc_leds_turn_off(the_led);
	delay(DELAY_INTERVAL);
	the_led = next_led(the_led);

  }
  return 0;
}

void delay(const unsigned int i)
{
  for(int x =0; x < i; ++x);  //Just loop to eat up time.
}

f4_discovery_led next_led(f4_discovery_led led)
{
  switch(led)
	{
	case Red:
	  led = Blue;
	  break;
	case Blue:
	  led = Green;
	  break;
   case Green:
	  led = Orange;
	  break;
	case Orange:
	  led = Red;
	  break;
	}

  return led;
}

void light_green_isr()
{
  f4_disc_leds_turn_on(Green);
}
