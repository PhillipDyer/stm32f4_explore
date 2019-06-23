
#include <unistd.h>
#include "arm_m4_defs.h"

void turn_on(int * gp);
void turn_off(int * gp);
void delay(const unsigned int i);

int main()
{
  
  int counter = 0;
  int * deadbeef = (int *)0x2003000;
  int counter_address = (int)&counter;
  
  int * rcc_register = (int *)RCC_AHB1ENR;
  int * gpio_moder = (int *)GPIOD_MODER;
  int * gpio_otype = (int *)GPIOD_OTYPER;
  int * gpio_speed = (int *)GPIOD_OSPEEDR;
  int * gpio_pupdr = (int *)GPIOD_PUPDR;
  int * gpio_odr = (int *)GPIOD_ODR;
  
  asm("LDR r2, %0"
	  :
	  : "m" (counter_address)
	  );

  /** Let's see if we can set up the clock enable register */
  *rcc_register |= 0x8;  //enable gpio-d clock.
  
  *gpio_moder = (*gpio_moder | 0x55000000 ) & 0x55FFFFFF;

  *gpio_otype &= 0xFFFF0FFF;

  *gpio_speed &= 0x00FFFFFF;

  *gpio_pupdr &= 0x00FFFFFF;
  
  while(1)
  {
	//++*counter;
	asm("ADDS r8, r8, #1");
	turn_on(gpio_odr);
	delay(DELAY_INTERVAL);
	turn_off(gpio_odr);
	delay(DELAY_INTERVAL);

  }
  return 0;
}

void turn_on(int * gp)
{
  *gp |= 0xF000;
}

void turn_off(int * gp)
{
  *gp &= 0xFFFF0FFF;
}

void delay(const unsigned int i)
{
  for(int x =0; x < i; ++x);  //Just loop to eat up time.
}
