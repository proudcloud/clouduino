#include <SPI.h>        // We use this library, so it must be called here.
#include <MCP23S17.h>   // The class we use to control the GPIOs

/* 
 *  Blink
 *  Turns an LED on for one second, then off for one second, repeatedly.
 */

MCP IOchip(0,5);  // create an object at address 0 called "IOchip" with SlaveSelect at GPIO5 pin of ESP             
                  // By default Clouduino's GPIO chip is addressed to 0.
                  // Note: You can change the object name "IOchip" to whatever you prefer!

void setup() {
  IOchip.begin();   // Enable to configure object "IOchip"
  
//Initialize digital pin 9 as an output     //In MCP23S17
  IOchip.pinMode(9, OUTPUT);                //GPB-0 [pin 1] 
}

void loop() {
  // put your main code here, to run repeatedly:
 IOchip.digitalWrite(9, HIGH);  //turn the LED on (HIGH is the voltage level)
 delay(1000);                   //wait for a second
 IOchip.digitalWrite(9, LOW);   //turn the LED off by making the voltage LOW
 delay(1000);                   //wait for a second
}
