Click_NBIoT_STM_nbiot_configTimer:
;click_nbiot_timer.h,14 :: 		static void nbiot_configTimer()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;click_nbiot_timer.h,16 :: 		RCC_APB1ENR.TIM2EN = 1;
MOVS	R1, #1
SXTB	R1, R1
MOVW	R0, #lo_addr(RCC_APB1ENR+0)
MOVT	R0, #hi_addr(RCC_APB1ENR+0)
_SX	[R0, ByteOffset(RCC_APB1ENR+0)]
;click_nbiot_timer.h,17 :: 		TIM2_CR1.CEN = 0;
MOVS	R1, #0
SXTB	R1, R1
MOVW	R0, #lo_addr(TIM2_CR1+0)
MOVT	R0, #hi_addr(TIM2_CR1+0)
_SX	[R0, ByteOffset(TIM2_CR1+0)]
;click_nbiot_timer.h,18 :: 		TIM2_PSC = 1;
MOVS	R1, #1
MOVW	R0, #lo_addr(TIM2_PSC+0)
MOVT	R0, #hi_addr(TIM2_PSC+0)
STR	R1, [R0, #0]
;click_nbiot_timer.h,19 :: 		TIM2_ARR = 35999;
MOVW	R1, #35999
MOVW	R0, #lo_addr(TIM2_ARR+0)
MOVT	R0, #hi_addr(TIM2_ARR+0)
STR	R1, [R0, #0]
;click_nbiot_timer.h,20 :: 		NVIC_IntEnable(IVT_INT_TIM2);
MOVW	R0, #44
BL	_NVIC_IntEnable+0
;click_nbiot_timer.h,21 :: 		TIM2_DIER.UIE = 1;
MOVS	R1, #1
SXTB	R1, R1
MOVW	R0, #lo_addr(TIM2_DIER+0)
MOVT	R0, #hi_addr(TIM2_DIER+0)
_SX	[R0, ByteOffset(TIM2_DIER+0)]
;click_nbiot_timer.h,22 :: 		TIM2_CR1.CEN = 1;
MOVW	R0, #lo_addr(TIM2_CR1+0)
MOVT	R0, #hi_addr(TIM2_CR1+0)
_SX	[R0, ByteOffset(TIM2_CR1+0)]
;click_nbiot_timer.h,23 :: 		EnableInterrupts();
BL	_EnableInterrupts+0
;click_nbiot_timer.h,24 :: 		}
L_end_nbiot_configTimer:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of Click_NBIoT_STM_nbiot_configTimer
_Timer_interrupt:
;click_nbiot_timer.h,26 :: 		void Timer_interrupt() iv IVT_INT_TIM2
SUB	SP, SP, #4
STR	LR, [SP, #0]
;click_nbiot_timer.h,28 :: 		nbiot_tick();
BL	_nbiot_tick+0
;click_nbiot_timer.h,29 :: 		TIM2_SR.UIF = 0;
MOVS	R1, #0
SXTB	R1, R1
MOVW	R0, #lo_addr(TIM2_SR+0)
MOVT	R0, #hi_addr(TIM2_SR+0)
_SX	[R0, ByteOffset(TIM2_SR+0)]
;click_nbiot_timer.h,30 :: 		}
L_end_Timer_interrupt:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _Timer_interrupt
_nbiot_default_handler:
;Click_NBIoT_STM.c,62 :: 		void nbiot_default_handler( uint8_t *rsp, uint8_t *evArgs )
; rsp start address is: 0 (R0)
SUB	SP, SP, #4
STR	LR, [SP, #0]
; rsp end address is: 0 (R0)
; rsp start address is: 0 (R0)
;Click_NBIoT_STM.c,64 :: 		mikrobus_logWrite( rsp, _LOG_TEXT );
MOVS	R1, #1
; rsp end address is: 0 (R0)
BL	_mikrobus_logWrite+0
;Click_NBIoT_STM.c,65 :: 		}
L_end_nbiot_default_handler:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _nbiot_default_handler
_systemInit:
;Click_NBIoT_STM.c,67 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_NBIoT_STM.c,69 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
MOVS	R2, #1
MOVS	R1, #0
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_NBIoT_STM.c,70 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #1
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_NBIoT_STM.c,71 :: 		mikrobus_uartInit( _MIKROBUS1, &_NBIOT_UART_CFG[0] );
MOVW	R0, #lo_addr(__NBIOT_UART_CFG+0)
MOVT	R0, #hi_addr(__NBIOT_UART_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_uartInit+0
;Click_NBIoT_STM.c,72 :: 		mikrobus_logInit( _LOG_USBUART_A, 9600 );
MOVW	R1, #9600
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_NBIoT_STM.c,73 :: 		mikrobus_logWrite("--- System Init ---", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr1_Click_NBIoT_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_NBIoT_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_NBIoT_STM.c,74 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_NBIoT_STM.c,76 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_NBIoT_STM.c,79 :: 		nbiot_configTimer();
BL	Click_NBIoT_STM_nbiot_configTimer+0
;Click_NBIoT_STM.c,82 :: 		nbiot_uartDriverInit((T_NBIOT_P)&_MIKROBUS1_GPIO, (T_NBIOT_P)&_MIKROBUS1_UART);
MOVW	R1, #lo_addr(__MIKROBUS1_UART+0)
MOVT	R1, #hi_addr(__MIKROBUS1_UART+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_nbiot_uartDriverInit+0
;Click_NBIoT_STM.c,83 :: 		nbiot_coreInit( nbiot_default_handler, 1500 );
MOVW	R0, #lo_addr(_nbiot_default_handler+0)
MOVT	R0, #hi_addr(_nbiot_default_handler+0)
MOVW	R1, #1500
BL	_nbiot_coreInit+0
;Click_NBIoT_STM.c,86 :: 		nbiot_hfcEnable( 1 );
MOVS	R0, #1
BL	_nbiot_hfcEnable+0
;Click_NBIoT_STM.c,87 :: 		nbiot_modulePower( 0 );
MOVS	R0, #0
BL	_nbiot_modulePower+0
;Click_NBIoT_STM.c,90 :: 		mikrobus_logWrite("--- Generic AT command ---", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr2_Click_NBIoT_STM+0)
MOVT	R0, #hi_addr(?lstr2_Click_NBIoT_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_NBIoT_STM.c,92 :: 		nbiot_cmdSingle( &AT[0] );
MOVW	R0, #lo_addr(_AT+0)
MOVT	R0, #hi_addr(_AT+0)
BL	_nbiot_cmdSingle+0
;Click_NBIoT_STM.c,94 :: 		nbiot_cmdSingle( &ATE[0] );
MOVW	R0, #lo_addr(_ATE+0)
MOVT	R0, #hi_addr(_ATE+0)
BL	_nbiot_cmdSingle+0
;Click_NBIoT_STM.c,95 :: 		Delay_1sec();
BL	_Delay_1sec+0
;Click_NBIoT_STM.c,97 :: 		nbiot_cmdSingle( &ATI[0] );
MOVW	R0, #lo_addr(_ATI+0)
MOVT	R0, #hi_addr(_ATI+0)
BL	_nbiot_cmdSingle+0
;Click_NBIoT_STM.c,98 :: 		Delay_1sec();
BL	_Delay_1sec+0
;Click_NBIoT_STM.c,100 :: 		nbiot_cmdSingle( &AT_CFUN[0] );
MOVW	R0, #lo_addr(_AT_CFUN+0)
MOVT	R0, #hi_addr(_AT_CFUN+0)
BL	_nbiot_cmdSingle+0
;Click_NBIoT_STM.c,101 :: 		Delay_1sec();
BL	_Delay_1sec+0
;Click_NBIoT_STM.c,103 :: 		nbiot_cmdSingle( &AT_CIMI[0] );
MOVW	R0, #lo_addr(_AT_CIMI+0)
MOVT	R0, #hi_addr(_AT_CIMI+0)
BL	_nbiot_cmdSingle+0
;Click_NBIoT_STM.c,104 :: 		Delay_1sec();
BL	_Delay_1sec+0
;Click_NBIoT_STM.c,106 :: 		nbiot_cmdSingle( &AT_CGDCONT[0] );
MOVW	R0, #lo_addr(_AT_CGDCONT+0)
MOVT	R0, #hi_addr(_AT_CGDCONT+0)
BL	_nbiot_cmdSingle+0
;Click_NBIoT_STM.c,107 :: 		Delay_1sec();
BL	_Delay_1sec+0
;Click_NBIoT_STM.c,108 :: 		mikrobus_logWrite("------------------------", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr3_Click_NBIoT_STM+0)
MOVT	R0, #hi_addr(?lstr3_Click_NBIoT_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_NBIoT_STM.c,109 :: 		mikrobus_logWrite("--- UDP server - AT command ---", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr4_Click_NBIoT_STM+0)
MOVT	R0, #hi_addr(?lstr4_Click_NBIoT_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_NBIoT_STM.c,111 :: 		nbiot_cmdSingle( &AT_NCONFIG[0] );
MOVW	R0, #lo_addr(_AT_NCONFIG+0)
MOVT	R0, #hi_addr(_AT_NCONFIG+0)
BL	_nbiot_cmdSingle+0
;Click_NBIoT_STM.c,112 :: 		nbiot_cmdSingle( &AT_NCONFIG1[0] );
MOVW	R0, #lo_addr(_AT_NCONFIG1+0)
MOVT	R0, #hi_addr(_AT_NCONFIG1+0)
BL	_nbiot_cmdSingle+0
;Click_NBIoT_STM.c,113 :: 		nbiot_cmdSingle( &AT_NCONFIG2[0] );
MOVW	R0, #lo_addr(_AT_NCONFIG2+0)
MOVT	R0, #hi_addr(_AT_NCONFIG2+0)
BL	_nbiot_cmdSingle+0
;Click_NBIoT_STM.c,115 :: 		nbiot_cmdSingle( &AT_NBAND[0] );
MOVW	R0, #lo_addr(_AT_NBAND+0)
MOVT	R0, #hi_addr(_AT_NBAND+0)
BL	_nbiot_cmdSingle+0
;Click_NBIoT_STM.c,117 :: 		nbiot_cmdSingle( &AT_CGDCONT1[0] );
MOVW	R0, #lo_addr(_AT_CGDCONT1+0)
MOVT	R0, #hi_addr(_AT_CGDCONT1+0)
BL	_nbiot_cmdSingle+0
;Click_NBIoT_STM.c,119 :: 		nbiot_cmdSingle( &AT_CEREG[0] );
MOVW	R0, #lo_addr(_AT_CEREG+0)
MOVT	R0, #hi_addr(_AT_CEREG+0)
BL	_nbiot_cmdSingle+0
;Click_NBIoT_STM.c,121 :: 		nbiot_cmdSingle( &AT_COPS[0] );
MOVW	R0, #lo_addr(_AT_COPS+0)
MOVT	R0, #hi_addr(_AT_COPS+0)
BL	_nbiot_cmdSingle+0
;Click_NBIoT_STM.c,123 :: 		nbiot_cmdSingle( &AT_NSOCR[0] );
MOVW	R0, #lo_addr(_AT_NSOCR+0)
MOVT	R0, #hi_addr(_AT_NSOCR+0)
BL	_nbiot_cmdSingle+0
;Click_NBIoT_STM.c,125 :: 		nbiot_cmdSingle( &AT_NSOST[0] );
MOVW	R0, #lo_addr(_AT_NSOST+0)
MOVT	R0, #hi_addr(_AT_NSOST+0)
BL	_nbiot_cmdSingle+0
;Click_NBIoT_STM.c,127 :: 		nbiot_cmdSingle( &AT_NSOCL[0] );
MOVW	R0, #lo_addr(_AT_NSOCL+0)
MOVT	R0, #hi_addr(_AT_NSOCL+0)
BL	_nbiot_cmdSingle+0
;Click_NBIoT_STM.c,128 :: 		mikrobus_logWrite("------------------------", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr5_Click_NBIoT_STM+0)
MOVT	R0, #hi_addr(?lstr5_Click_NBIoT_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_NBIoT_STM.c,129 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_NBIoT_STM.c,131 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_NBIoT_STM.c,133 :: 		nbiot_process();
BL	_nbiot_process+0
;Click_NBIoT_STM.c,134 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_NBIoT_STM.c,136 :: 		void main()
;Click_NBIoT_STM.c,138 :: 		systemInit();
BL	_systemInit+0
;Click_NBIoT_STM.c,139 :: 		applicationInit();
BL	_applicationInit+0
;Click_NBIoT_STM.c,141 :: 		while (1)
L_main0:
;Click_NBIoT_STM.c,143 :: 		applicationTask();
BL	_applicationTask+0
;Click_NBIoT_STM.c,144 :: 		}
IT	AL
BAL	L_main0
;Click_NBIoT_STM.c,145 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
