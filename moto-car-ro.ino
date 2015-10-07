#include "motocarroMotors.h"
 
byte motorLeft = 9;
byte motorRight= 10;

//create a MotocarroMotor object
MotocarroMotors motor;
 

void setup() {
  // put your setup code here, to run once:
motor.setEngine(motorLeft, motorRight);

  //test if motors works correctly
motor.testEngine();



}

void loop() {
 
 
}
