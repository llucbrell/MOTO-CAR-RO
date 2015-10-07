byte motorLeft = 9;
byte motorRight= 10;

 

void setup() {
  // put your setup code here, to run once:

// wake up pins!!!
pinMode(motorLeft, OUTPUT);
pinMode(motorRight, OUTPUT);


// turn-off motor
digitalWrite(motorLeft, LOW);
digitalWrite(motorRight, LOW);


}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(motorSpeed, HIGH);
  //analogWrite(enable, 200);
  digitalWrite(motorLeft, HIGH); 
 
  delay(2000);
  digitalWrite(motorLeft, LOW);

  digitalWrite(motorRight, HIGH);
 
  delay(2000);
  digitalWrite(motorRight, LOW);
 
  delay(2000);

  digitalWrite(motorLeft, HIGH);
  digitalWrite(motorRight,HIGH);

  delay(2000);

  digitalWrite(motorLeft, LOW);
  digitalWrite(motorRight,LOW);

  delay(2000);
 
}
