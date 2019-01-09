![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# NBIoT Click

- **CIC Prefix**  : NBIOT
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : okt 2018.

---

### Software Support

We provide a library for the NBIoT Click on our [LibStock](https://libstock.mikroe.com/projects/view/2593/nb-iot-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library carries generic command parser adopted for AT command based modules. 
Generic parser 

Key functions :

- ``` nbiot_cmdSingle ``` - Sends provided command to the module
- ``` nbiot_setHandler ``` - Handler assignation to the provied command
- ``` nbiot_modulePower ``` - Turn on module

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes all necessary GPIO pins, UART used for
the communcation with NB IoT module and UART used for infromation logging
- Application Initialization - Initializes driver, power on module and sends few
command for the default module configuration
- Application Task - Running in parallel core state machine. 

Commands :
- Command: AT, Basic command
- Command: ATE, Set Command Echo Mode
- Command: ATI, product information
- Command: AT+CFUN, Set UE Functionality
- Command: AT+CIMI, Request International Mobile Subscriber Identity
- Command: AT+CGDCONT, Define a PDP Context
- Command: AT+NCONFIG, Enable scrambling function
- Command: AT+NBAND, set band 8=900 MHz, 20=800 MHz provided by operator
- Command: AT+CGDCONT, Set mobile operator APN for PDP context
- Command: AT+CEREG, Enable network registration URCs
- Command: AT+COPS, set MCC and MNC values provided by operator
- Command: AT+NSOCR, create an UDP socket
- Command: AT+NSOST, send UDP message
- Command: AT+NSOCL, close socket

```.c

// MODULE POWER ON
    nbiot_hfcEnable( 1 );
    nbiot_modulePower( 0 );

// MODULE INIT

    //Generic AT command 
    nbiot_cmdSingle( &AT[0] );
    nbiot_cmdSingle( &ATE[0] );
    nbiot_cmdSingle( &ATI[0] );
    nbiot_cmdSingle( &AT_CFUN[0] );
    nbiot_cmdSingle( &AT_CIMI[0] );
    nbiot_cmdSingle( &AT_CGDCONT[0] );
  
    // UDP server - AT command 
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


```

Additional Functions :

All additional functions such as timer initialization and default handler. 

Notes :

- UART polling works much better with HFC enabled.
- In case of usage of other MCUs Timer initialization must be adjusted according to your MCU.

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2593/nb-iot-click) page.

Other mikroE Libraries used in the example:

- String
- Conversion

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
