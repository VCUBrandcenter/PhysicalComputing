
//the photo sensor/resistor pin #
int photo = A0;

//the LED to turn on pin #
int led = 13;

//current photo sensor state
int photoValue = 0;

void setup() {
  //tell arduino how to use our pin
  pinMode(led, OUTPUT);  
}

//this function is called continuosly when running
void loop() {
  //what's the current value of the photo sensor
  photoValue = analogRead(photo);
  
  //turn on the LED
  digitalWrite(led, HIGH);
  
  //wait <photoValue> milliseconds moving on
  delay(photoValue);
  
  //turn the LED off        
  digitalWrite(led, LOW);
  
  //wait <photoValue> milliseconds moving on
  delay(photoValue);                  
}
