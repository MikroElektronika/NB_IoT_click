/*
Example for NBIoT Click

    Date          : okt 2018.
    Author        : Katarina Perendic

Test configuration PIC32 :
    
    MCU                : P32MX795F512L
    Dev. Board         : EasyPIC Fusion v7
    PIC32 Compiler ver : v4.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes all necessary GPIO pins, UART used for
the communcation with NB IoT module and UART used for infromation logging
- Application Initialization - Initializes driver, power on module and sends few
command for the default module configuration
- Application Task - Running in parallel core state machine.


Additional Functions :

All additional functions such as timer initialization and default handler. 

Notes :

- UART polling works much better with HFC enabled.
- In case of usage of other MCUs Timer initialization must be adjusted according to your MCU.

*/

 

#include "Click_NBIoT_types.h"
#include "Click_NBIoT_config.h"
#include "Click_NBIoT_timer.h"

 

char AT[5]           = "AT";
char ATI[5]          = "ATI";
char ATE[5]          = "ATE1";
char AT_CFUN[10]     = "AT+CFUN=1";
char AT_CIMI[10]     = "AT+CIMI";
char AT_CGDCONT[15]  = "AT+CGDCONT?";
char AT_NCONFIG[45]  = "AT+NCONFIG=CR_0354_0338_SCRAMBLING,TRUE";
char AT_NCONFIG1[40] = "AT+NCONFIG=CR_0859_SI_AVOID,TRUE";
char AT_NCONFIG2[40] = "AT+NCONFIG=AUTOCONNECT,FALSE";
char AT_NBAND[15]    = "AT+NBAND=8";
char AT_CGDCONT1[60] = "AT+CGDCONT=1,\"IP\",\"mobile_operator_APN\"";
char AT_CEREG[15]    = "AT+CEREG=2";
char AT_COPS[30]     = "AT+COPS=1,2,\"12345\"";
char AT_NSOCR[40]    = "AT+NSOCR= DGRAM,17,16666,1";
char AT_NSOST[40]    = "AT+NSOST=0,83.58.228.64,16666,2,ABCD";
char AT_NSOCL[15]    = "AT+NSOCL=0";

void nbiot_default_handler( uint8_t *rsp, uint8_t *evArgs )
{
    mikrobus_logWrite( rsp, _LOG_TEXT );
}

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_uartInit( _MIKROBUS1, &_NBIOT_UART_CFG[0] );
    mikrobus_logInit( _LOG_USBUART_B, 9600 );
    mikrobus_logWrite("--- System Init ---", _LOG_LINE);
}

void applicationInit()
{
// TIMER INIT
    nbiot_configTimer();

// DRIVER INIT
    nbiot_uartDriverInit((T_NBIOT_P)&_MIKROBUS1_GPIO, (T_NBIOT_P)&_MIKROBUS1_UART);
    nbiot_coreInit( nbiot_default_handler, 1500 );

// MODULE POWER ON
    nbiot_hfcEnable( 1 );
    nbiot_modulePower( 0 );
    
// MODULE INIT
    mikrobus_logWrite("--- Generic AT command ---", _LOG_LINE);
    //Command: AT, Basic command
    nbiot_cmdSingle( &AT[0] );
    //Command: ATE, Set Command Echo Mode
    nbiot_cmdSingle( &ATE[0] );
    Delay_1sec();
    //Command: ATI, product information
    nbiot_cmdSingle( &ATI[0] );
    Delay_1sec();
    //Command: AT+CFUN, Set UE Functionality
    nbiot_cmdSingle( &AT_CFUN[0] );
    Delay_1sec();
    //Command: AT+CIMI, Request International Mobile Subscriber Identity
    nbiot_cmdSingle( &AT_CIMI[0] );
    Delay_1sec();
    //Command: AT+CGDCONT, Define a PDP Context
    nbiot_cmdSingle( &AT_CGDCONT[0] );
    Delay_1sec();
    mikrobus_logWrite("------------------------", _LOG_LINE);
    mikrobus_logWrite("--- UDP server - AT command ---", _LOG_LINE);
    //Command: AT+NCONFIG, Enable scrambling function
    nbiot_cmdSingle( &AT_NCONFIG[0] );
    nbiot_cmdSingle( &AT_NCONFIG1[0] );
    nbiot_cmdSingle( &AT_NCONFIG2[0] );
    //Command: AT+NBAND, set band 8=900 MHz, 20=800 MHz provided by operator
    nbiot_cmdSingle( &AT_NBAND[0] );
    //Command: AT+CGDCONT, Set mobile operator APN for PDP context
    nbiot_cmdSingle( &AT_CGDCONT1[0] );
    //Command: AT+CEREG, Enable network registration URCs
    nbiot_cmdSingle( &AT_CEREG[0] );
    //Command: AT+COPS, set MCC and MNC values provided by operator
    nbiot_cmdSingle( &AT_COPS[0] );
    //Command: AT+NSOCR, create an UDP socket
    nbiot_cmdSingle( &AT_NSOCR[0] );
    //Command: AT+NSOST, send UDP message
    nbiot_cmdSingle( &AT_NSOST[0] );
    //Command: AT+NSOCL, close socket
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