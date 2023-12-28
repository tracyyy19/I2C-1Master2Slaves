#include <Wire.h>

// Define Slave I2C Address
#define SLAVE_ADDR 10

// Define buffer size for received data
#define BUFFER_SIZE 50

// Buffer to store received data
char receivedData[BUFFER_SIZE];

void setup() {
  // Initialize I2C communications as Slave
  Wire.begin(SLAVE_ADDR);

  // Function to run when data received from master
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  // Setup Serial Monitor
  Serial.begin(9600);
  Serial.println("I2C Slave Demonstration");
}

void receiveEvent() {
  // Read the incoming data and store it in the buffer
  int i = 0;
  while (Wire.available()) {
    receivedData[i] = Wire.read();
    i++;
    // Make sure the buffer doesn't overflow
    if (i >= BUFFER_SIZE) {
      break;
    }
  }
  receivedData[i] = '\0'; // Null-terminate the string

  // Print the received data to Serial Monitor
  Serial.print("<Received>");
  Serial.println(receivedData);
}

void requestEvent() {
  Wire.write("Slave1:ily master"); // respond with message of 6 bytes
  // as expected by master
}

void loop() {
  // Additional processing can be done in the loop if needed
  delay(500);
}
