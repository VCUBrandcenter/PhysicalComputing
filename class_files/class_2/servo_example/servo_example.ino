#include <Servo.h>

Servo servo;

int angle;//angle of the servo
int minAngle = 0;
int maxAngle = 179;
int angleSpeed = 1;

void setup(){
 servo.attach(9);//tell the servo what pin it's running on 
}

void loop(){
 
 angle += angleSpeed; 
 
 servo.write(angle);//tell the servo where to go
 
 if(angle + angleSpeed < maxAngle && angle + angleSpeed >= minAngle){
   angle += angleSpeed;
 }else{
   angleSpeed *= -1;
 }
 
 delay(30); //little pause
}
