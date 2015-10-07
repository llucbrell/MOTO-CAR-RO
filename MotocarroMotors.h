#include <Arduino.h>



class MotocarroMotors{

private:
  byte motorLeft;
  byte motorRight;


public:
//set the pins for the engine
  void setEngine(byte pinForLeft, byte pinForRight){
    motorLeft= pinForLeft;
    motorRight=pinForRight;
       
        // wake up pins!!!
    pinMode(motorLeft, OUTPUT);
    pinMode(motorRight, OUTPUT);

        // turn-off motor
   stopAll();

  }

//test for the engines
  void testEngine(){
    runOne(motorLeft, 1000);
    stopOne(motorLeft, 1000);
    runOne(motorRight, 1000);
    stopOne(motorRight, 1000);
    runTwo(1000);
    stopAll();
  }

//run one motor  -- two paramas motor and time of running
  void runOne(byte motor, int tiem){
    digitalWrite(motor, HIGH);
    delay(tiem); 
  }
  void runTwo(int tiem){
    digitalWrite(motorLeft, HIGH);
    digitalWrite(motorRight, HIGH);
    delay(tiem);
  }

  void stopOne(byte motor, int tiem){
    digitalWrite(motor, LOW);
    delay(tiem); 
  }
  void stopAll(){
     digitalWrite(motorLeft, LOW);
     digitalWrite(motorRight, LOW);
  }

  //for speed motor control analogWrite(pin, 0-250)

};
