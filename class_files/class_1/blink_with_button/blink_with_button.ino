
//button pin #
int button = 2;

//LED pin #
int led =  13;

//the current state of the button. LOW if up, HIGH if down
int buttonState = LOW;

//called once when booted
void setup() {
  //tell arduino how to use our pin
  pinMode(led, OUTPUT);   
  
  //tell arduino how to use our button
  pinMode(button, INPUT);     
}

//this function is called continuosly when running
void loop(){
  //is out button down
  buttonState = digitalRead(button);

  //is our button down?
  if (buttonState == HIGH) {     
    //if so, turn on the LED   
    digitalWrite(led, HIGH);  
  }else {
    //if not, turn off the LED
    digitalWrite(led, LOW); 
  }
}
