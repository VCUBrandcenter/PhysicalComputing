#include <ZumoBuzzer.h>
#include <ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>
#include <avr/pgmspace.h>
#include <Wire.h>
#include <LSM303.h>


int LED = 13;

int speed = 400;

Pushbutton button(ZUMO_BUTTON); // pushbutton on pin 12

// Motor 
ZumoMotors motors;

// Sound Effects
ZumoBuzzer buzzer;

void setup(){  
  
  // Initiate the Wire library and join the I2C bus as a master
  Wire.begin();

  //randomSeed((unsigned int) millis());

  pinMode(LED, OUTPUT);
}

bool isRunning = false;

void loop(){
 if(button.isPressed()){
   
   //play the note
   buzzer.playNote(NOTE_G(3), 200, 30);
   
   //see if it's already moving
    isRunning = (isRunning)? false:true;
    
    //if not, stop the motors
    if(!isRunning){
      motors.setSpeeds(0, 0); 
    }
    //set the led to whether or not it's running
    digitalWrite(LED, (isRunning)? HIGH:LOW);
    delay(750);
  }
  
  //if we are running, move it
  if(isRunning){
    motors.setSpeeds(-speed,speed);
    delay(7000);
    motors.setSpeeds(speed/4,speed/4);
    delay(10000);
  }
}


