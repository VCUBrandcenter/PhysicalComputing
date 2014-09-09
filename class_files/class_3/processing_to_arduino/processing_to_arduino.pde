import processing.serial.*;

Serial port; // The serial port we will be using

void setup(){
  size(640, 480);
  frameRate(60);
  
  port = new Serial(this, Serial.list()[2], 9600);
  println(Serial.list());
  
  background(255);
}

void draw(){
  //redraws the background
  background(255);
}

//when someone clicks the mouse, tell the arduino
void mousePressed(){
  port.write('p');
}

//when the mouse is released, let the arduino know that to
void mouseReleased(){
 port.write('P');
}


