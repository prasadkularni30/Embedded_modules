#include <SPI.h>
#include <mcp_can.h>
#include <Arduino.h>

// Define CAN SPI CS pin
#define CAN_CS_PIN 5
#define CAN_INT_PIN 4

MCP_CAN CAN(CAN_CS_PIN); // Set CS pin

void setup() {
  Serial.begin(115200);

  // Initialize MCP2515
  while (CAN.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) != CAN_OK) {
    Serial.println("CAN Init Failed");
    delay(100);
  }
  Serial.println("CAN Init Successful");

  CAN.setMode(MCP_NORMAL); // Set operation mode to normal mode
}

void loop() {
  long unsigned int rxId;
  unsigned char len = 0;
  unsigned char rxBuf[8];

  if (CAN_MSGAVAIL == CAN.checkReceive()) { // Check if data received
    CAN.readMsgBuf(&rxId, &len, rxBuf); // Read data

    if (rxId == 0x100) { // Assuming the STM32 sends data with ID 0x100
      float distance_f;
      float distance_r;
      memcpy(&distance_f,(const void *) rxBuf[0], sizeof(distance_f)); // Convert the received bytes to float
      memcpy(&distance_r,(const void *) rxBuf[4], sizeof(distance_r)); // Convert the received bytes to float
      Serial.print("Front Distance: ");
      Serial.print(distance_f);
      Serial.println(" cm");
      Serial.print("Rear Distance: ");
      Serial.print(distance_r);
      Serial.println(" cm");
    }
  }

  delay(10); // Add a delay to prevent task from hogging the CPU
}
