#include "motocarroMotors.h"
#include "motocarroLeds.h"
#include "motocarroPhtCell.h"

//create a Motocarro objects
MotocarroMotors motor;
MotocarroLeds redLed;
MotocarroLeds yelLed;
MotocarroEye eLeft;
MotocarroEye eRight;
char lastTurn = 'N';




void setup() {
  // put your setup code here, to run once:
  //set the pins and light reference for photocells
  eLeft.setEye(0);
  eRight.setEye(1);
  //set the pins for the H bridge
  motor.setEngineH(5, 6, 7, 10,  11, 12, 1000);
  //set the pins for leds
  redLed.setLed(8);
  yelLed.setLed(9);
  //start lightning for testing advise
  redLed.adviseTest();
  //run test for motors
  //motor.testEngine();




  //Serial.begin(9600);
}

void loop() {

  //test if motors works correctly
  //yelLed.turnOn(100);
  // yelLed.turnOff(500);
  //motor.goStraight(150, 100);
  runCar();
  /*
   yelLed.turnOn(100);
   yelLed.turnOff(500);

   motor.goRight(255, 150, 100);
  */
}


void runCar() {
  //store the references in variables
  int refL = eLeft.getRef();
  int refR = eRight.getRef();

  //read the actual light using the sensor
  int left = eLeft.readLight();
  int right = eRight.readLight();

  //if there is more light on the left side of the car
  if (left < (right - 15) ) {
    if (lastTurn == 'L') {
      motor.stopM(100);
      motor.backRight(255, 150, 200);
      motor.stopM(100);
    }
    else {
      motor.goLeft(255, 170, 200);

    }
    lastTurn = 'L'; //right
  }

  //if there is more light on the right side of the car
  else if (right < (left - 15)) {
    if (lastTurn == 'R') {
      motor.stopM(100);
      motor.backLeft(255, 170, 200);
      motor.stopM(100);
    }
    else {
      motor.goRight(255, 170, 200);
    }
    lastTurn = 'R'; //left
  }
  //if there is more light on the both eyes
  /*
   else if(left > refL && right > refR){
     if(lastTurn=='L'){
       motor.stopM(100);
       motor.backRight(255, 150,200);
       motor.stopM(100);
       motor.goLeft(255,150, 200);
     }
     else{
       motor.stopM(100);
       motor.backLeft(255, 150,200);
       motor.stopM(100);
       motor.goRight(255,150, 200);
     }
   }
  */
  else {
    motor.goStraight(170, 200);
    lastTurn = 'N';
  }
  /*
   Serial.print("left--");
  Serial.print(left);
  Serial.print("right--");
  Serial.print(right);
  Serial.print("Lturn--");
  Serial.println(lastTurn);
  Serial.print("refL");
  Serial.print(refL);
  Serial.print("refR");
  Serial.println(refR);

  */
}

