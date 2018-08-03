#include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(3);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //delay(1000);
  myservo.write(0);
  Serial.println("Angle=0(0D)");
  delay(3000);
  myservo.write(68);
  Serial.println("Angle=68(90D)");
  delay(3000);
  myservo.write(138);
  Serial.println("Angle=138(180D)");
  delay(3000);
  myservo.write(68);
  Serial.println("Angle=68(90D)");
  delay(3000);/*
  myservo.write(90);
  Serial.println("Angle=90");
  delay(2000);
  myservo.write(135);
  Serial.println("Angle=135");
  delay(2000);
  myservo.write(180);
  Serial.println("Angle=180");
  delay(2000);*/
  

}
