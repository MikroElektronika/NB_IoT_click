/*

Use mikroE Timer Calculator to generate proper timer configuration
and timer ISR.

https://www.mikroe.com/timer-calculator

*/
#include "Click_NBIoT_types.h"

#define __NBIoT_TIMER__

static void nbiot_configTimer()
{


    // Configure Timer
}

void Timer_interrupt()
{
    nbiot_tick();
    // Reset Flag
}