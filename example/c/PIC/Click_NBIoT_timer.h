/*

Use mikroE Timer Calculator to generate proper timer configuration
and timer ISR.

https://www.mikroe.com/timer-calculator

*/
#include "Click_NBIoT_types.h"

#define __NBIoT_TIMER__

static void nbiot_configTimer()
{
    T1CON          = 0xC5;
    TMR1L          = 0x06;
    GIE_bit        = 1;
    TMR1IE_bit     = 1;
}

void Interrupt()
{
    if (TMR1IF_bit != 0)
    { 
    	nbiot_tick();
    	TMR1IF_bit = 0;
        TMR1L      = 0x06;
    }
}
