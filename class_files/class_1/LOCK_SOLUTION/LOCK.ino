

int led = 13;//PIN for LED
int button = 2;//PIN for button
int isLocked = 0;//Current state of "lock"
int buttonState = LOW;//Current state of button
int buttonWasDown = 0;//if the button was down, the last time the loop function ran

//how fast we want it to blink
int blinkSpeed = 200;

//called once on boot
void setup(){
 pinMode(led, OUTPUT);
 pinMode(button, INPUT); 
}

//called as fast as possible forever
void loop(){
  
  //check the state of the button
  buttonState = digitalRead(button);
  
  //if the button is down, but it wasn't a moment ago
  if(buttonState == HIGH && buttonWasDown == 0){
   
    //is the current lock state true?
   if(isLocked == 1){
    //then blink twice
    blinkIt();
    blinkIt();
    //and unlock it
    isLocked = 0;
   }else{
    //otherwise, blink once and lock it back
    blinkIt();
    isLocked = 1;
   }
   //update that the button was down, for the next loop
   buttonWasDown = 1;
  }else if(buttonState == LOW){
    //if the button is in the up state now, you can set buttonWasDown to 0 for the next iteration through the loop
   buttonWasDown = 0;
  }
  
}

// A shortcut function so we don't have to write the blink code over and over again
void blinkIt(){
 digitalWrite(led, HIGH);
 delay(blinkSpeed);
 digitalWrite(led, LOW);
 delay(blinkSpeed); 
}

