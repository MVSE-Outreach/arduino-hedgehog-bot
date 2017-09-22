//this code turns on an LED on for one second, then off for one second, repeatedly.
 
int led = 13; // Pin 13 is connected to an LED on the Arduino Nano

//this is the setup function:
void setup() {                
  pinMode(led, OUTPUT); // this sets pin 13 as an output (in this case LED)  
}

//this loop runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
