
int led = 13;

void setup(){
 Serial.begin(9600);//set the baud rate
 pinMode(led, OUTPUT);//setup our LED
}

void loop(){
  //listening for processing to talk to us
  if( Serial.available()) {
   
  char ch = Serial.read();
  
  switch(ch){
   case 'p':
    digitalWrite(led, HIGH);
    break;
   case 'P':
     digitalWrite(led, LOW);
     break;
     
  }
  
 } 
}
