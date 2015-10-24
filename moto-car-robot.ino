#include "motocarroMotors.h"

//create a MotocarroMotor object
MotocarroMotors motor;
 

void setup() {
  // put your setup code here, to run once:
motor.setEngineH(5, 6, 7, 10,  11, 12, 1000);




}

void loop() {
 
   //test if motors works correctly
motor.testEngine();

}
