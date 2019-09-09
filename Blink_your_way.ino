int counter;
bool flag;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  counter = 10;
  flag = false;
}

// the loop function runs over and over again forever
void loop() {
  if (counter >= 300){
  flag = true;
  }
  else if (counter <= 10){
    flag = false;
  }
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(counter);    
  if (!flag){
  counter = counter + 10;
  }
  else{
    counter = counter - 10;
  }
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  if (!flag){
  counter = counter + 10;
  }
  else{
    counter = counter - 10;
  }
  delay(counter);     
}
