#include <Wire.h>

//byte initialString [

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
 
  int commandLength = Wire.available();
  
  Serial.println("");
  Serial.println((commandLength + 1) / 4);
  
  char sentArr[commandLength];
  char parseArr[1][(commandLength + 1) / 4];
  byte i = 0;
  
  while (1 < Wire.available()) {
    char c = Wire.read(); // receive byte as a character
    sentArr[i] = c;
    i++;
  }
 
  
  
  for (int i = 0; i < sizeof(parseArr); i++) {
    int x = 0;
    int y = x + 1;
    int z = y + 1;
    parseArr[0][i] = sentArr[i];
    Serial.println(parseArr[0][i]);
  }
  
  
    
  //Serial.println(Wire.available());
  
  for (int k = 0; k < commandLength - 1; k++) { //<-FOR TESTING
    //Serial.println(Wire.available());
    //Serial.println(k);
    Serial.print(sentArr[k]); //<- THIS IS WHAT I NEED TO PRINT
  }
  //Serial.println("");
  //Serial.print(sentArr[100]);
}
  //int x = Wire.read();    // receive byte as an integer
  //Serial.print("     ");
  //Serial.println(x);         // print the integer
