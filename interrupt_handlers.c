#include "cortex_core/include/boot.h"
#include "cortex_core/include/systick.h"

extern void main();
static int sys_tick_test = 0;

void Reset_Handler()
{
  main();
}

void NMI_Handler()
{

}

void MemManager_Handler()
{

}

void HardFault_Handler()
{

}

void UsageFault_Handler()
{

}

void SVC_Handler()
{

}

void DebugMon_Handler()
{

}

void SysTick_Handler()
{
  sys_tick_test++;
}

void MemManage_Handler()
{

}

void BusFault_Handler()
{

}

void PendSV_Handler()
{

}
