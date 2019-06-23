#ifndef _ARM_M4_DEFS_H_PD
#define _ARM_M4_DEFS_H_PD

static const int DELAY_INTERVAL = 0x186004;

static const int RCC_AHB1ENR = 0x40023830;

#define GPIOD_BASE 0x40020C00

static const int GPIOD_MODER   = GPIOD_BASE;
static const int GPIOD_OTYPER  = GPIOD_BASE + 0x4;
static const int GPIOD_OSPEEDR = GPIOD_BASE + 0x8;
static const int GPIOD_PUPDR   = GPIOD_BASE + 0xC;
static const int GPIOD_ODR     = GPIOD_BASE + 0x14;

#endif
