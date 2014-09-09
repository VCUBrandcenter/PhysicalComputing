import processing.serial.*;

Serial port; // The serial port we will be using

boolean blink = false;

void setup(){
  size(640, 480);
  frameRate(60);
  
  port = new Serial(this, Serial.list()[2], 9600);
  
  background(255);
  
}

void draw(){  
  if(blink){
   background(#397dce); 
  }else{
   //redraws the background
  background(255); 
  }
}

void serialEvent(Serial myPort) {
  char sent = char(myPort.read());
  switch (sent){
   case 'p':
    blink = true;
    break;
   case 'P':
    blink = false;
    break; 
  }
}



