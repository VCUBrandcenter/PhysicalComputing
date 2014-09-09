
int button = 2;
int buttonState = LOW;
int previousButtonState = LOW;

void setup(){
 Serial.begin(9600);//set the baud rate
 pinMode(button, INPUT);//setup our button
}

void loop(){
 //talking to processing
  buttonState = digitalRead(button);
  if(buttonState == HIGH){
    Serial.write('p');
    previousButtonState = HIGH;
  }else if(previousButtonState == HIGH){
   Serial.write('P');
   previousButtonState = LOW;
  }

}
