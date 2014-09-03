#include <Servo.h>

Servo servo;

int left = 2;
int right = 7;
int fire = 8;
int led = 13;

bool isFiring = false;
bool isTurning = false;

int potentiometer = A0;
int maxFireSpeed = 200;
int minFireSpeed = 15;
int fireSpeed = 0;
int angle = 0;
int angleSpeed = 1;
int servoPin = 9;

void setup(){
 servo.attach(servoPin);
 pinMode(left, INPUT);
 pinMode(right, INPUT);
 pinMode(fire, INPUT);
 
 pinMode(led, OUTPUT);
}

void loop(){
  int val = analogRead(potentiometer);
  fireSpeed = map(val, 0, 1023, minFireSpeed, maxFireSpeed);
  
  isFiring = digitalRead(fire) == HIGH;// shortcut, will return true/false
  isTurning = digitalRead(left) + digitalRead(right) >= HIGH;
  
  if(isFiring){
    digitalWrite(led, HIGH);
    delay(fireSpeed);
    digitalWrite(led, LOW);
    delay(fireSpeed);
  }
  
  if(isTurning){
    if(digitalRead(left) == HIGH){
      angle -= angleSpeed;
    }else{//we know it's turning, so we don't need to test both again
      angle += angleSpeed;
    }
    servo.write(angle);
    delay(15);
  }
  
}

