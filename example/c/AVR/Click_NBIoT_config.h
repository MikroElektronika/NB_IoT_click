#include "Click_NBIoT_types.h"

const uint32_t _NBIOT_TIMER_LIMIT      = 5;	    // 5 ticks
const uint16_t _NBIOT_BUF_WARNING      = 192;	// 192 bytes activate warning
const uint8_t  _NBIOT_POLL_ENABLE      = 1; 	// poll enabled
const uint8_t  _NBIOT_CALLBACK_ENABLE  = 0;	    // calback disabled

const uint32_t _NBIOT_UART_CFG[ 3 ] = 
{
	9600, 
	_UART_NOPARITY, 
	_UART_ONE_STOPBIT
};
