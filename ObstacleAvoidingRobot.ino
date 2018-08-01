
#include <Servo.h>
int triggerPin = 10;
int echoPin = 11;

int RightDC = 6;
int LeftDC = 5;

Servo myservo;  // create servo object to control a servo



void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RightDC, OUTPUT);
  pinMode(LeftDC, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  float duration;
  float distance, right=0, left=0;
  
  //digitalWrite(triggerPin, ); //triggering the wave(like blinking an LED)
 // delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  //stop=0;
  
  duration = pulseIn(echoPin, HIGH); //a special function for listening and waiting for the wave
  distance = (duration/2) / 29.1; //transforming the number to cm(if you want inches, you have to change the 29.1 with a suitable number

  
  Serial.print("Distance");
  Serial.println(distance);
  if(distance<35 )
  {
          Serial.println("********* Obstacle ************ ");
          digitalWrite(RightDC,LOW);
          digitalWrite(LeftDC, LOW);
          delay(1000);

          
          
          myservo.write(180);
          digitalWrite(triggerPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(triggerPin, LOW);
          duration = pulseIn(echoPin, HIGH); //a special function for listening and waiting for the wave
          left = (duration/2) / 29.1; //transforming the number to cm(if you want inches, you have to change the 29.1 with a suitable number
          delay(1000);

          
          Serial.println(left);

          
          
          myservo.write(0);
          digitalWrite(triggerPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(triggerPin, LOW);
          duration = pulseIn(echoPin, HIGH); //a special function for listening and waiting for the wave
          right = (duration/2) / 29.1; //transforming the number to cm(if you want inches, you have to change the 29.1 with a suitable number
          delay(1000);

          Serial.println(right);
          
          myservo.write(90);

          if(distance<35)
          {
          if(right > left)
          {
          digitalWrite(LeftDC, HIGH);
          delay(3700);
          digitalWrite(LeftDC,LOW);
          delay(1000);
          }
          else
          {
            digitalWrite(RightDC, HIGH);
          delay(3700);
          digitalWrite(RightDC,LOW);
          delay(1000);
          }
          }
  } 
  else
  {
    Serial.println("*********In else*********");
    digitalWrite(RightDC,HIGH);
    digitalWrite(LeftDC,HIGH); 
    delay(1000);  
}
}

