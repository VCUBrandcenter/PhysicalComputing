int count = 0;//just a variable for us to implement


void setup(){
 Serial.begin(9600);//set the baud rate 
}

void loop(){
 Serial.println(count);
 Serial.println("this is a test");
 count++;
}
