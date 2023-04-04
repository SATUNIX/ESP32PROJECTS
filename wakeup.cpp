#include <Arduino.h>

#define RX_PIN 16 // RX pin for UART communication
#define TX_PIN 17 // TX pin for UART communication

void setup() {
  Serial.begin(115200);
  pinMode(RX_PIN, INPUT_PULLUP);
  pinMode(TX_PIN, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    if (command == "wake\n") {
      digitalWrite(TX_PIN, HIGH);
      delay(10);
      pinMode(RX_PIN, OUTPUT);
      digitalWrite(RX_PIN, HIGH);
    }
  }
}
