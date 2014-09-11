import processing.serial.*;
import cc.arduino.*;

Arduino arduino;
int led = 13;
int button = 2;

void setup(){
  size(600,400);
  
  println(Arduino.list());
  arduino = new Arduino(this, Arduino.list()[2], 57600);
  arduino.pinMode(led, Arduino.OUTPUT);
  arduino.pinMode(button, Arduino.INPUT);
}

void draw(){
  
  if(arduino.digitalRead(button) == Arduino.HIGH){
    background(#397dce); 
  }else{
    background(255);
  }
  
}

void mousePressed(){
 arduino.digitalWrite(led, Arduino.HIGH); 
}

void mouseReleased(){
 arduino.digitalWrite(led, Arduino.LOW); 
}
