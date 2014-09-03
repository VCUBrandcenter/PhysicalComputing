
int led = 13;//pin for LED
int potentiometer = 0;//pin for potentiometer
int potValue = 0;//current potentiometer value

void setup(){
 pinMode(led, OUTPUT); 
}

void loop(){
  potValue = analogRead(potentiometer);//get the value of the potentiometer
  digitalWrite(led, HIGH);//turn the LED on
  delay(potValue);//wait a certain amount of time
  digitalWrite(led, LOW);//turn the led back off
  delay(potValue);//wait again
}
