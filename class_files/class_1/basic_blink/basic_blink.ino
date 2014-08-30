
//the LED to turn on pin #
int led = 13;

//milliseconds between blinks
int timeBetween = 500;

//called once when booted
void setup() {                
  //tell arduino how to use our pin
  pinMode(led, OUTPUT);     
}

//this function is called continuosly when running
void loop() {
  digitalWrite(led, HIGH);   //turn it on
  delay(timeBetween);        //chill
  digitalWrite(led, LOW);    //turn it off
  delay(timeBetween);        //chill again
}
