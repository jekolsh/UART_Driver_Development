#ifndef __UART_H //the preprocessor directive "#ifndef", which checks whether "__UART_H" has not been defined previously.
// If it has not been defined, then the rest of the header file will be processed. 
//If it has already been defined, then this file will be skipped to avoid multiple definitions.
#define __UART_H

//include the header file "stm32f4xx.h" which contains definitions and declarations specific to STM32 hardware.
#include "stm32f4xx.h" //Hämtar källkoden och hänvisningar för arbete på STM-Hårdvara
//include the standard library for C
#include <stdio.h> //Inkluderar standard I/O för C

//declares the function "USART2_Init" that calls and references our UART function declaration
void USART2_Init(void); 
//declare the function "test_setup" that calls and references our test function from the UART.c
void test_setup(void); 
#endif //End the preprocessor directive "#ifndef" and mark the end of the header file