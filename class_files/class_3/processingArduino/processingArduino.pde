import processing.serial.*;
import cc.arduino.*;

Arduino arduino;
int ledPin = 13;

void setup(){
  size(600,400);
  
  println(Arduino.list());
  arduino = new Arduino(this, Arduino.list()[2], 57600);
  arduino.pinMode(ledPin, Arduino.OUTPUT);
}

void draw(){
  background(255);
}

void mousePressed(){
 arduino.digitalWrite(ledPin, Arduino.HIGH); 
}

void mouseReleased(){
 arduino.digitalWrite(ledPin, Arduino.LOW); 
}
