
int led = 9;//pin for LED
int potentiometer = A0;//pin for potentiometer
float potValue = 0.0;//current potentiometer value
int brightness = 0;


void setup(){
 pinMode(led, OUTPUT);//set the LED mode
}

void loop(){
  potValue = analogRead(potentiometer)/1023.0;//get the value of the potentiometer as a float between 0 and 1
  
  brightness = round(potValue * 255.0);//multiply it by the max value we want to set the LED
  
  analogWrite(led, brightness);//set the LED
  
  delay(30);//wait a moment
}
