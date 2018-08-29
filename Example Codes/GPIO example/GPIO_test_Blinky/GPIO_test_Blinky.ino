#include <SPI.h>
#include <MCP23S17.h>

MCP IOchip(0,5);  // create an object at address 0 called "IOchip" with SlaveSelect at GPIO5 pin of ESP 
                  // address of the device can be configured with address pins (A0, A1, A2)
                  // In this case, address 0 means to ground all address pins, or binary 0.
                  // Note: Clouduino's GPIO chip is hardware addressed as 0 by default.
void setup() {
  // put your setup code here, to run once:
  // Serial.begin(115200);
  IOchip.begin(); 
  
//Initialize GPIO A             //In MCP23S17
  IOchip.pinMode(1, OUTPUT);    //GPA-0 [pin 21]
  IOchip.pinMode(2, OUTPUT);    //GPA-1 [pin 22]
  IOchip.pinMode(3, OUTPUT);    //GPA-2 [pin 23]
  IOchip.pinMode(4, OUTPUT);    //GPA-3 [pin 24]
  IOchip.pinMode(5, OUTPUT);    //GPA-4 [pin 25]
  IOchip.pinMode(6, OUTPUT);    //GPA-5 [pin 26]
  IOchip.pinMode(7, OUTPUT);    //GPA-6 [pin 27]
  IOchip.pinMode(8, OUTPUT);    //GPA-7 [pin 28]
  
//Initialize GPIO B             //In MCP23S17
  IOchip.pinMode(9, OUTPUT);    //GPB-0 [pin 1]
  IOchip.pinMode(10, OUTPUT);   //GPB-1 [pin 2]
  IOchip.pinMode(11, OUTPUT);   //GPB-2 [pin 3]
  IOchip.pinMode(12, OUTPUT);   //GPB-3 [pin 4]
  IOchip.pinMode(13, OUTPUT);   //GPB-4 [pin 5]
  IOchip.pinMode(14, OUTPUT);   //GPB-5 [pin 6]
  IOchip.pinMode(15, OUTPUT);   //GPB-4 [pin 5]
  IOchip.pinMode(16, OUTPUT);   //GPB-5 [pin 6]  
}

void loop() {
  // put your main code here, to run repeatedly:
//TURN OFF GPA
 IOchip.digitalWrite(1, LOW); 
 IOchip.digitalWrite(2, LOW); 
 IOchip.digitalWrite(3, LOW); 
 IOchip.digitalWrite(4, LOW); 
 IOchip.digitalWrite(5, LOW); 
 IOchip.digitalWrite(6, LOW); 
 IOchip.digitalWrite(7, LOW); 
 IOchip.digitalWrite(8, LOW);
//TURN OFF GPB    
 IOchip.digitalWrite(9, HIGH);
 IOchip.digitalWrite(10, HIGH); 
 IOchip.digitalWrite(11, HIGH); 
 IOchip.digitalWrite(12, HIGH); 
 IOchip.digitalWrite(13, HIGH);
 IOchip.digitalWrite(14, HIGH); 
 IOchip.digitalWrite(15, HIGH);
 IOchip.digitalWrite(16, HIGH);  

 delay(1000);

//TURN ON GPA
 IOchip.digitalWrite(1, HIGH);
 IOchip.digitalWrite(2, HIGH); 
 IOchip.digitalWrite(3, HIGH); 
 IOchip.digitalWrite(4, HIGH);
 IOchip.digitalWrite(5, HIGH); 
 IOchip.digitalWrite(6, HIGH); 
 IOchip.digitalWrite(7, HIGH); 
 IOchip.digitalWrite(8, HIGH);
//TURN ON GPB
 IOchip.digitalWrite(9, LOW);
 IOchip.digitalWrite(10, LOW); 
 IOchip.digitalWrite(11, LOW); 
 IOchip.digitalWrite(12, LOW);
 IOchip.digitalWrite(13, LOW);
 IOchip.digitalWrite(14, LOW); 
 IOchip.digitalWrite(15, LOW);
 IOchip.digitalWrite(16, LOW);
 delay(1000); 
}
