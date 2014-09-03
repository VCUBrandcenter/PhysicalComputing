#include <Servo.h>

Servo servo;

int left = 2;
int right = 7;
int fire = 8;
int led = 13;
int servoPin = 9;
int potentiometer = A0;

//variables to keep track of action
bool isFiring = false;
bool isTurning = false;


//I wanted a max and min firing speed
int maxFireSpeed = 200;
int minFireSpeed = 15;
int fireSpeed = 0;

// max/min angle
int maxAngle = 179;
int minAngle = 0;
int angle = 0;//current set angle
int angleSpeed = 1;


void setup(){
  //setup the servo
  servo.attach(servoPin);
 
 //setup the buttons
 pinMode(left, INPUT);
 pinMode(right, INPUT);
 pinMode(fire, INPUT);
 
 //setup the LED
 pinMode(led, OUTPUT);
}

void loop(){
  //set the firing speed
  int val = analogRead(potentiometer);
  fireSpeed = map(val, 0, 1023, minFireSpeed, maxFireSpeed);//map the value of the potentiometer to the max/min firing speeds
  
  isFiring = digitalRead(fire) == HIGH;// shortcut, will return true/false
  
  /************************************
  
  Because HIGH = 1, and LOW = 0
  we can actually add the 2 values from
  the left/right buttons and make sure
  only one of them is down
  
  *************************************/
  
  isTurning = digitalRead(left) + digitalRead(right) == HIGH;
  
  if(isFiring){
    digitalWrite(led, HIGH);
    delay(fireSpeed);
    digitalWrite(led, LOW);
    delay(fireSpeed);
  }
  
  if(isTurning){
    //now we see which button is actually down and if it can turn
    if(digitalRead(left) == HIGH && angle - angleSpeed >= minAngle){
      angle -= angleSpeed;
      /*******************
      we know 1 of the buttons is down, so if it's not left, then it has to be right
      so we just need to check the angle
      ********************/
    }else if(angle + angleSpeed <= maxAngle){
      angle += angleSpeed;
    }
    
    //because 1 button is down, we move the servo
    //and call the delay
    servo.write(angle);
    delay(15);
  }
  
}

