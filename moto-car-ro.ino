byte motorPlus = 9;

 

void setup() {
  // put your setup code here, to run once:

// wake up pins!!!
pinMode(motorPlus, OUTPUT);


// turn-off motor
digitalWrite(motorPlus, LOW);


}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(motorSpeed, HIGH);
  //analogWrite(enable, 200);
  digitalWrite(motorPlus, HIGH); //gira a la derecha
 
  delay(2000);
  digitalWrite(motorPlus, LOW);
 
  delay(2000);
 
}
