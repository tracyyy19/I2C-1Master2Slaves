#include <Wire.h>

void setup() {
  // Initialize I2C communications as Master
  Wire.begin();

  // Setup serial monitor
  Serial.begin(9600);
  Serial.println("I2C Master Demonstration");
}

void loop() {
  delay(1000); // Wait for a moment
  Serial.print("<Received from S1> ");
  receiveFromSlave1();
  Serial.print("<Received from S2> ");
  receiveFromSlave2();
  Serial.println("");

  sendToSlave1();
  delay(100);
  sendToSlave2();
}

void sendToSlave1(){
  Wire.beginTransmission(8);
  Wire.write("Master: Iloveyouu somuchh Slave1");
  Wire.endTransmission();

  Serial.println("Reply Sent to slave1!");
}

void sendToSlave2(){
  Wire.beginTransmission(10);
  Wire.write("Master: Iloveyouu too Slave2");
  Wire.endTransmission();

  Serial.println("Reply Sent to slave2!");
}

void receiveFromSlave1(){
  Wire.requestFrom(8, 17);    // request 6 bytes from slave device #8

  while (Wire.available()) { // slave may send less than requested
    char first = Wire.read(); // receive a byte as character
    //Serial.print("<Received>");
    Serial.print(first);         // print the character
  }
  Serial.println("");
  delay(1000);
}

void receiveFromSlave2(){
  Wire.requestFrom(10, 17);    // request 6 bytes from slave device #8
  while (Wire.available()) { // slave may send less than requested
    char second = Wire.read(); // receive a byte as character
    //Serial.print("<Received>");
    Serial.print(second);         // print the character
  }
  delay(1000);
 
}