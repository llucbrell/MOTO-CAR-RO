#include <Arduino.h>



class MotocarroMotors {

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

    void setEngineH(byte enable1, byte pin1Mot1, byte pin2Mot1, byte enable2, byte pin1Mot2, byte pin2Mot2, int tiem) {
      // set pins
      _pin1Mot1 =  pin1Mot1;
      _pin2Mot1 =  pin2Mot1;
      _pin1Mot2 =  pin1Mot2;
      _pin2Mot2 =  pin2Mot2;
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
      powerMotor[0] = {_pin1Mot2};
      powerMotor[1] = {_pin2Mot2};
      powerMotor[2] = {_enable2};
      //2
      directionMotor[0] = {_pin1Mot1};
      directionMotor[1] = {_pin2Mot1};
      directionMotor[2] = {_enable1};

      // start the engine -- no power-- turn off the engine

      stopGas(powerMotor, tiem);

      // neutral direction

      stopGas(directionMotor, tiem);

    }

    //test for the engines
    void testEngine() {
      //test the engine moving forward, backward and testing direction
      gas(powerMotor, 120, 500);
      gas(powerMotor, 150, 500);
      stopGas(powerMotor, 1000);
      reverse(powerMotor, 120, 500);
      reverse(powerMotor, 150, 500);
      stopGas(powerMotor, 1000);
      gas(directionMotor, 255, 1000);
      stopGas(directionMotor, 500);
      reverse(directionMotor, 255, 1000);
      stopGas(directionMotor, 1000);

      goLeft(255, 150, 1000);
      backLeft(255, 150, 1000);
      goRight(255, 150, 1000);
      backRight(255, 150, 1000);

    }

    // no power for the engine
    void stopGas(byte motor [], int mytime) {
      digitalWrite(motor[0], LOW);
      digitalWrite(motor[1], LOW);
      analogWrite(motor[2], 0);
      delay(mytime);
    }

    // engine on
    void gas(byte motor [], byte power, int mytime) {
      digitalWrite(motor[0], HIGH);
      digitalWrite(motor[1], LOW);
      analogWrite(motor[2], power);
      delay(mytime);
    }

    // reverse

    void reverse(byte motor [], byte power, int mytime) {
      digitalWrite(motor[0], LOW);
      digitalWrite(motor[1], HIGH);
      analogWrite(motor[2], power);
      delay(mytime);
    }

    void goRight(byte amount, byte power, int mytime) {
      digitalWrite(directionMotor[0], LOW);
      digitalWrite(directionMotor[1], HIGH);
      analogWrite(directionMotor[2], amount);
      digitalWrite(powerMotor[0], HIGH);
      digitalWrite(powerMotor[1], LOW);
      analogWrite(powerMotor[2], power);
      delay(mytime);
      stopGas(powerMotor, 100);
      stopGas(directionMotor, 100);
    }

    void goLeft(byte amount, byte power, int mytime) {
      digitalWrite(directionMotor[0], HIGH);
      digitalWrite(directionMotor[1], LOW);
      analogWrite(directionMotor[2], amount);
      digitalWrite(powerMotor[0], HIGH);
      digitalWrite(powerMotor[1], LOW);
      analogWrite(powerMotor[2], power);
      delay(mytime);
      stopGas(powerMotor, 100);
      stopGas(directionMotor, 100);
    }

    void backRight(byte amount, byte power, int mytime) {
      digitalWrite(directionMotor[0], LOW);
      digitalWrite(directionMotor[1], HIGH);
      analogWrite(directionMotor[2], amount);
      digitalWrite(powerMotor[0], LOW);
      digitalWrite(powerMotor[1], HIGH);
      analogWrite(powerMotor[2], power);
      delay(mytime);
      stopGas(powerMotor, 100);
      stopGas(directionMotor, 100);
    }
    
    void backLeft(byte amount, byte power, int mytime) {
      digitalWrite(directionMotor[0], HIGH);
      digitalWrite(directionMotor[1], LOW);
      analogWrite(directionMotor[2], amount);
      digitalWrite(powerMotor[0], LOW);
      digitalWrite(powerMotor[1], HIGH);
      analogWrite(powerMotor[2], power);
      delay(mytime);
      stopGas(powerMotor, 100);
      stopGas(directionMotor, 100);
    }
};
