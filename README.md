# UART_Driver_Development

UART Driver for STM32F411x Platform, with included LED-Application

This project provides a UART driver written in C for the STM32F411x microcontroller platform. The driver offers functions for initializing and configuring the UART peripheral, transmitting and receiving data using the UART interface, and handling UART peripheral interrupts. It also includes a LED function for demonstration purposes.



Requirements

To use this driver, you will need the following:

STM32F411x development board

STM32CubeIDE or other compatible IDE

STM32F411x HAL library

UART cable or USB-to-UART converter



Usage

To use the driver, follow these steps:

Clone the repository or download the source code as a ZIP file.

Import the project into your IDE and add the necessary HAL libraries.

Include the uart_driver.h header file in your application code.

Initialize the UART peripheral using the USART2_Init() function, passing in the desired baud rate and other configuration parameters.



Functions

The UART driver provides the following functions:

int USART2_write()
int USART2_read()



Example

The following example demonstrates how to use the UART driver to transmit and receive data:

c #include "uart.h"

void USART2_Init(void){ //1.enable clock access to uart2 RCC->APB1ENR |= 0x20000; //2.enable closk access to portA RCC->AHB1ENR |=0x01; //3.Enable pins for alternate fucntions, pa2, pa3

GPIOA->MODER &=~0x00F0; GPIOA->MODER |= 0x00A0; /Enable alt. function for PA2, PA3/ //4.Configure type of alternate function

GPIOA->AFR[0] &= ~0xFF00; GPIOA->AFR[0] |= 0x7700;

//Configure uart

USART2->BRR = 0x0683; USART2->CR1 = 0x000C; /Enabled tx rx, 8-bit data/ USART2->CR2 = 0x000; USART2->CR3 = 0x000; USART2->CR1 |= 0x2000; /*Enable uart */

}

License

This project is licensed under the MIT License
