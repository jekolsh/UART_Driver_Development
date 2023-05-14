#include "UART.h" //Include header and function file for UART

void USART2_Init(void) { //Declare a function to initialize USART protocol and its components

// 1. Enable clock access for uart2

RCC->APB1ENR |= 0x20000; //Enable UART2 by setting bit 17 in APB1ENR to 1.

// 2. Enable clock access for portA

RCC->AHB1ENR |= 0x01; //Enable GPIOA by setting bit 0 in AHB1ENR to 1.

// Enable pins related to selected port, for alternative function
GPIOA->MODER &= ~0x00F0; //Clear bits 4-7 to prepare pins PA2 and PA3
  //& and ~ forces an inversion that replaces the bits that are designated as 1 in hex with 0 in real value

GPIOA->MODER |= 0x00A0; //Sets bits 5 and 7 to 1 to activate alternative functionality on pins PA2 and PA3

// 4. Choose the type of alternative function for the selected pins
GPIOA->AFR[0] &= ~0xFF00; //Clears bits 8-15 to prepare pins PA2 and PA3
GPIOA->AFR[0] |= 0x7700; //Sets bits 8-11 and 12-15 to the format 0111

/*  Construction of the device's communication is completed*/

//  Configuration of UART

USART2->BRR = 0x0683; //Set the standard baud rate using hexadecimal 0x0683 (9600bps)
USART2->CR1 = 0x000C; //Set tx and rx to work with 8-bit data. (8-bit data, 1 stop bit, no parity)
USART2->CR2 = 0x000; //Reset CR2
USART2->CR3 = 0x000; //Reset CR3
USART2->CR1 |= 0x2000; //Switch bit 13 (UART activation) to 1

}
// UART Write
int USART2_write(int ch){ //Declare the write function (transferring data to the terminal)

  while(!(USART2->SR & 0x0080)){} //Set a condition that checks if the status of the transfer is empty and can receive the next character (byte)
  USART2->DR = (ch & 0xFF); //Set the transfer of the byte to the data register

  return ch;

}
// UART Read
int USART2_read(void){ //Declare the read function (receiving information)

  while(!(USART2->SR & 0x0020)){} //Set a condition that checks if there is more data to fetch
  return USART2->DR; //Read the data
}