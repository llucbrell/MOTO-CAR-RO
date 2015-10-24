#include <Arduino.h>



class MotocarroMotors{

private:
  byte motorLeft;
  byte motorRight;
  byte _pin1Mot1;
  byte _pin2Mot1;
  byte _pin1Mot2;
  byte _pin2Mot2;
  byte _enable1;
  byte _enable2;
  byte powerMotor[3];
  byte directionMotor[3];
  

public:

  void setEngineH(byte enable1, byte pin1Mot1, byte pin2Mot1, byte enable2, byte pin1Mot2, byte pin2Mot2, int tiem){
 // set pins   
      _pin1Mot1=  pin1Mot1;
      _pin2Mot1=  pin2Mot1;
      _pin1Mot2=  pin1Mot2;
      _pin2Mot2=  pin2Mot2;
      _enable1 =  enable1;
      _enable2 =  enable2;
 // wake up pins!!!
      pinMode(_pin1Mot1, OUTPUT);
      pinMode(_pin2Mot1, OUTPUT);
      pinMode(_pin1Mot2, OUTPUT);
      pinMode(_pin2Mot2, OUTPUT);
      pinMode(_enable1, OUTPUT);
      pinMode(_enable2, OUTPUT);

 // set the two engines
  //1
  powerMotor[0]={_pin1Mot2};
  powerMotor[1]={_pin2Mot2};
  powerMotor[2]={_enable2};
  //2
  directionMotor[0]={_pin1Mot1};
  directionMotor[1]={_pin2Mot1};
  directionMotor[2]={_enable1};
  
 // start the engine -- no power-- turn off the engine

      stopGas(powerMotor, tiem);
 
 // neutral direction
      
      stopGas(directionMotor, tiem);
      
  }

//test for the engines
  void testEngine(){
   

   gas(powerMotor, 100, 1000);
   gas(powerMotor, 150, 1000);
   stopGas(powerMotor, 1000);
   reverse(powerMotor, 75, 1000);
   reverse(powerMotor, 255, 1000);
   stopGas(powerMotor, 1000);
   gas(directionMotor, 255, 1000);
   gas(powerMotor, 100, 1000);
   stopGas(directionMotor, 1000);
   stopGas(powerMotor, 1000);
        stopGas(powerMotor, 3000);
 
 // neutral direction
      
      stopGas(directionMotor, 3000);
  }

// no power for the engine
  void stopGas(byte motor [], int mytime){
    digitalWrite(motor[0], LOW);
    digitalWrite(motor[1], LOW);
    analogWrite(motor[2], 0);
    delay(mytime);
  }

// engine on 
  void gas(byte motor [], byte power, int mytime){
     digitalWrite(motor[0], HIGH);
     digitalWrite(motor[1], LOW);
     analogWrite(motor[2], power);
     delay(mytime);
  }

// reverse

  void reverse(byte motor [], byte power, int mytime){
     digitalWrite(motor[0], LOW);
     digitalWrite(motor[1], HIGH);
     analogWrite(motor[2], power);
     delay(mytime);
  }
  


};
