//This is preprocessor directive that checks if the header file "LED_H" is defined or not. If it is not defined, it defines it using "#define LED_H".

#ifndef LED_H
#define LED_H

//Include necessary header files for the code to work. 
#include <stdint.h> //standard header file that defines integer data types
#include "UART.h" //header file specific to the microcontroller used in the project
#include "stm32f4xx.h" //header files specific to the microcontroller used in the project

//Define which specifies which GPIO port will be responsible for controlling the LED.
#define LED_PORT GPIOB

//Define a macro "LED_PORT_CLOCK" as "1U<<1", which sets the clock signal for the LED port. 
//The clock signal is used to synchronize the operations of the microcontroller with the external components.
#define LED_PORT_CLOCK (1U<<1)

//Define which pins on the selected GPIO port are used for each color of the LED. 
//For example, "LED_RED_PIN" is defined as "1U<<14", which sets the 14th pin of the selected GPIO port as the pin for the red LED.
#define LED_RED_PIN (1U<<14)
#define LED_GREEN_PIN (1U<<12)
#define LED_BLUE_PIN (1U<<15)
#define LED_YELLOW_PIN (1U<<13)

//Define the mode bits for each color of the LED. Mode bits are used to configure the pin as an output, input, or other peripheral function. 
//Each LED color has a specific bit that is set to configure it as an output.
#define LED_RED_MODE_BIT (1U<<28)
#define LED_GREEN_MODE_BIT (1U<<24)
#define LED_YELLOW_MODE_BIT (1U<<26)
#define LED_BLUE_MODE_BIT (1U<<30)

//Define an enumerated data type "LedColor_Type" with four possible values: "RED", "GREEN", "YELLOW", and "BLUE". 
//This is used to specify the color of the LED.
typedef enum {
  RED = 0,
  GREEN,
  YELLOW,
  BLUE
}LedColor_Type;

//Define an enumerated data type "LedState_Type" with two possible values: "OFF" and "ON". 
//This is used to specify the state of the LED.
typedef enum {
  OFF = 0,
  ON = 1
}LedState_Type;

// Define a class "Led" for controlling the LED.
class Led{
 //private member variables of the class "Led". 
 //"color" stores the color of the LED, and "state" stores the current state of the LED (ON or OFF).
  private:
      LedColor_Type color;
      LedState_Type state;
  //public member functions of the class "Led".
  public:
      //constructor of the class "Led". 
      //It takes two arguments: "_color" and "_state", which set the color and state of the LED, respectively.
      Led(LedColor_Type _color,LedState_Type _state);
      //a member function that sets the state of the LED to the given argument "_state".
      void setState(LedState_Type _state);
      //a member function that returns the current state of the LED. 
      //It is declared "const" to prevent it from modifying any member variables of the class.
      LedState_Type getState() const;

};
//Close the "#ifndef" directive
#endif