#include <Servo.h>

Servo servo;

int potentiometer = A0;//pin for potentiometer
int potValue = 0;//value of potentiometer
int angle;//angle of the servo

void setup(){
 servo.attach(9);//tell the servo what pin it's running on
}

void loop(){
 potValue = analogRead(potentiometer);//get the value of the potentiometer
 
 angle = map(potValue, 0, 1023, 0, 179);//map the potentiometer value to a different value
 
 servo.write(angle);//tell the servo where to go
 
 delay(15); //little pause
}
