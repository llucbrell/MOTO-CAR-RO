#include "motocarroMotors.h"
#include "motocarroLeds.h"

//create a MotocarroMotor object
MotocarroMotors motor;
MotocarroLeds redLed;
MotocarroLeds yelLed;


void setup() {
  // put your setup code here, to run once:
  //set the pins for the H bridge
  motor.setEngineH(5, 6, 7, 10,  11, 12, 1000);
  //set the pins for leds
  redLed.setLed(8);
  yelLed.setLed(9);
  //start lightning for testing advise
  redLed.adviseTest();
  //run test for motors
  motor.testEngine();
  
  
}

void loop() {

  //test if motors works correctly
  yelLed.turnOn(500);
  yelLed.turnOff(500);
  motor.testEngine();

}
