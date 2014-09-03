
int potentiometer = 0;//pin for potentiometer
int potValue = 0;//current potentiometer value

void setup(){
 Serial.begin(9600);//set the baud rate 
}

void loop(){
 potValue = analogRead(potentiometer);//get the value of the potentiometer
 Serial.println(potValue);
}
