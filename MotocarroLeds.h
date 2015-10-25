#include <Arduino.h>



class MotocarroLeds{

private:
  byte led;

public:

  void setLed(byte pinLed){
 // set pins   
      led= pinLed;
    
 // wake up pins!!!
      pinMode(led, OUTPUT);

 // turn off led

      digitalWrite(led, LOW);
  }

// lights for test
  void adviseTest(){
   
    turnOn(5000);
    turnOff(1000);
    turnOn(1000);
    turnOff(1000);
    turnOn(1000);
    turnOff(1000);
    turnOn(1000);
    turnOff(1000);
    
  }

// power on the led
  void turnOn(int timer){
    digitalWrite(led, HIGH);
    delay(timer);
  }
  // power off the led
  void turnOff(int timer){
    digitalWrite(led, LOW);
    delay(timer);
  }



};
