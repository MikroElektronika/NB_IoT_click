#line 1 "D:/Clicks_git/N/NB-IoT_click/SW/example/c/ARM/STM/Click_NBIoT_STM.c"
#line 1 "d:/clicks_git/n/nb-iot_click/sw/example/c/arm/stm/click_nbiot_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdbool.h"



 typedef char _Bool;
#line 1 "d:/clicks_git/n/nb-iot_click/sw/example/c/arm/stm/click_nbiot_config.h"
#line 1 "d:/clicks_git/n/nb-iot_click/sw/example/c/arm/stm/click_nbiot_types.h"
#line 3 "d:/clicks_git/n/nb-iot_click/sw/example/c/arm/stm/click_nbiot_config.h"
const uint32_t _NBIOT_TIMER_LIMIT = 5;
const uint16_t _NBIOT_BUF_WARNING = 192;
const uint8_t _NBIOT_POLL_ENABLE = 1;
const uint8_t _NBIOT_CALLBACK_ENABLE = 0;

const uint32_t _NBIOT_UART_CFG[ 4 ] =
{
 9600,
 _UART_8_BIT_DATA,
 _UART_NOPARITY,
 _UART_ONE_STOPBIT
};
#line 1 "d:/clicks_git/n/nb-iot_click/sw/example/c/arm/stm/click_nbiot_timer.h"
#line 1 "d:/clicks_git/n/nb-iot_click/sw/example/c/arm/stm/click_nbiot_types.h"
#line 1 "d:/clicks_git/n/nb-iot_click/sw/library/__nbiot_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdbool.h"
#line 53 "d:/clicks_git/n/nb-iot_click/sw/library/__nbiot_driver.h"
extern const uint8_t _NBIOT_UNKNOWN ;
extern const uint8_t _NBIOT_TEST ;
extern const uint8_t _NBIOT_SET ;
extern const uint8_t _NBIOT_GET ;
extern const uint8_t _NBIOT_URC ;
extern const uint8_t _NBIOT_EXEC ;



extern const uint8_t _NBIOT_EVARG_START_T ;
extern const uint8_t _NBIOT_EVARG_END_T ;
extern const uint8_t _NBIOT_EVARG_EVENT_T ;

extern const uint8_t _NBIOT_EVENT_RESPONSE ;
extern const uint8_t _NBIOT_EVENT_TIMEOUT ;
extern const uint8_t _NBIOT_EVENT_BUFFER_OUT ;
extern const uint8_t _NBIOT_EVENT_CALLBACK ;
#line 75 "d:/clicks_git/n/nb-iot_click/sw/library/__nbiot_driver.h"
typedef void ( *T_nbiot_handler )( char *buffer, uint8_t *evArgs );
#line 91 "d:/clicks_git/n/nb-iot_click/sw/library/__nbiot_driver.h"
void nbiot_uartDriverInit( const uint8_t*  gpioObj,  const uint8_t*  uartObj);
#line 103 "d:/clicks_git/n/nb-iot_click/sw/library/__nbiot_driver.h"
void nbiot_coreInit( T_nbiot_handler defaultHdl, uint32_t defaultWdog );
#line 115 "d:/clicks_git/n/nb-iot_click/sw/library/__nbiot_driver.h"
void nbiot_hfcEnable(  _Bool  hfcState );
#line 124 "d:/clicks_git/n/nb-iot_click/sw/library/__nbiot_driver.h"
void nbiot_modulePower(  _Bool  powerState );
#line 135 "d:/clicks_git/n/nb-iot_click/sw/library/__nbiot_driver.h"
void nbiot_putc( char rxInput );
#line 143 "d:/clicks_git/n/nb-iot_click/sw/library/__nbiot_driver.h"
void nbiot_tick();
#line 154 "d:/clicks_git/n/nb-iot_click/sw/library/__nbiot_driver.h"
uint16_t nbiot_setHandler( char *pCmd, uint32_t timeout, T_nbiot_handler pHandler );
#line 164 "d:/clicks_git/n/nb-iot_click/sw/library/__nbiot_driver.h"
void nbiot_cmdSingle( char *pCmd );
#line 176 "d:/clicks_git/n/nb-iot_click/sw/library/__nbiot_driver.h"
void nbiot_cmdDouble( char *pCmd, char *pArg1 );
#line 189 "d:/clicks_git/n/nb-iot_click/sw/library/__nbiot_driver.h"
void nbiot_cmdTriple( char *pCmd, char *pArg1, char *pArg2 );
#line 196 "d:/clicks_git/n/nb-iot_click/sw/library/__nbiot_driver.h"
void nbiot_process();
#line 14 "d:/clicks_git/n/nb-iot_click/sw/example/c/arm/stm/click_nbiot_timer.h"
static void nbiot_configTimer()
{
 RCC_APB1ENR.TIM2EN = 1;
 TIM2_CR1.CEN = 0;
 TIM2_PSC = 1;
 TIM2_ARR = 35999;
 NVIC_IntEnable(IVT_INT_TIM2);
 TIM2_DIER.UIE = 1;
 TIM2_CR1.CEN = 1;
 EnableInterrupts();
}

void Timer_interrupt() iv IVT_INT_TIM2
{
 nbiot_tick();
 TIM2_SR.UIF = 0;
}
#line 1 "d:/clicks_git/n/nb-iot_click/sw/library/__nbiot_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdbool.h"
#line 45 "D:/Clicks_git/N/NB-IoT_click/SW/example/c/ARM/STM/Click_NBIoT_STM.c"
char AT[5] = "AT";
char ATI[5] = "ATI";
char ATE[5] = "ATE1";
char AT_CFUN[10] = "AT+CFUN=1";
char AT_CIMI[10] = "AT+CIMI";
char AT_CGDCONT[15] = "AT+CGDCONT?";
char AT_NCONFIG[45] = "AT+NCONFIG=CR_0354_0338_SCRAMBLING,TRUE";
char AT_NCONFIG1[40] = "AT+NCONFIG=CR_0859_SI_AVOID,TRUE";
char AT_NCONFIG2[40] = "AT+NCONFIG=AUTOCONNECT,FALSE";
char AT_NBAND[15] = "AT+NBAND=8";
char AT_CGDCONT1[60] = "AT+CGDCONT=1,\"IP\",\"mobile_operator_APN\"";
char AT_CEREG[15] = "AT+CEREG=2";
char AT_COPS[30] = "AT+COPS=1,2,\"12345\"";
char AT_NSOCR[40] = "AT+NSOCR= DGRAM,17,16666,1";
char AT_NSOST[40] = "AT+NSOST=0,83.58.228.64,16666,2,ABCD";
char AT_NSOCL[15] = "AT+NSOCL=0";

void nbiot_default_handler( uint8_t *rsp, uint8_t *evArgs )
{
 mikrobus_logWrite( rsp, _LOG_TEXT );
}

void systemInit()
{
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
 mikrobus_uartInit( _MIKROBUS1, &_NBIOT_UART_CFG[0] );
 mikrobus_logInit( _LOG_USBUART_A, 9600 );
 mikrobus_logWrite("--- System Init ---", _LOG_LINE);
}

void applicationInit()
{

 nbiot_configTimer();


 nbiot_uartDriverInit(( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_UART);
 nbiot_coreInit( nbiot_default_handler, 1500 );


 nbiot_hfcEnable( 1 );
 nbiot_modulePower( 0 );


 mikrobus_logWrite("--- Generic AT command ---", _LOG_LINE);

 nbiot_cmdSingle( &AT[0] );

 nbiot_cmdSingle( &ATE[0] );
 Delay_1sec();

 nbiot_cmdSingle( &ATI[0] );
 Delay_1sec();

 nbiot_cmdSingle( &AT_CFUN[0] );
 Delay_1sec();

 nbiot_cmdSingle( &AT_CIMI[0] );
 Delay_1sec();

 nbiot_cmdSingle( &AT_CGDCONT[0] );
 Delay_1sec();
 mikrobus_logWrite("------------------------", _LOG_LINE);
 mikrobus_logWrite("--- UDP server - AT command ---", _LOG_LINE);

 nbiot_cmdSingle( &AT_NCONFIG[0] );
 nbiot_cmdSingle( &AT_NCONFIG1[0] );
 nbiot_cmdSingle( &AT_NCONFIG2[0] );

 nbiot_cmdSingle( &AT_NBAND[0] );

 nbiot_cmdSingle( &AT_CGDCONT1[0] );

 nbiot_cmdSingle( &AT_CEREG[0] );

 nbiot_cmdSingle( &AT_COPS[0] );

 nbiot_cmdSingle( &AT_NSOCR[0] );

 nbiot_cmdSingle( &AT_NSOST[0] );

 nbiot_cmdSingle( &AT_NSOCL[0] );
 mikrobus_logWrite("------------------------", _LOG_LINE);
}

void applicationTask()
{
 nbiot_process();
}

void main()
{
 systemInit();
 applicationInit();

 while (1)
 {
 applicationTask();
 }
}
