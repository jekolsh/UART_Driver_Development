//Header file for structures and functions related to LED
#include "led.h"

//Declaration of LedState_Type variables
LedState_Type led1_state;
LedState_Type led2_state;
LedState_Type led3_state;

//Initialization of led1 object with RED color and ON state
Led led1(RED,ON);

int main(void){ //Main function that constructs and handles the LEDs
//Initializing USART protocol for serial communication
  USART2_Init();
//Initialization of led2 object with BLUE color and ON state
  Led led2(BLUE,ON);
//Dynamically allocating memory for led3 object with YELLOW color and ON state using new operator
  Led *led3 = new Led(YELLOW,ON);
/7Getting and assigning the state of led1 to led1_state variable
  led1_state = led1.getState();
//Setting the state of led1 to OFF
  led1.setState(OFF);
//Deleting the dynamically allocated memory for led3 object using delete operator
  delete led3;
//Looping infinitely
  while(1){}

}