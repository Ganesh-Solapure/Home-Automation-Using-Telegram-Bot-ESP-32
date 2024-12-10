#include <ESP8266WiFi.h>
#include <Servo.h>

Servo myservo;
int inputPin = 2; // Input pin for the switch

void setup() {
  myservo.attach(5); // Servo is attached to GPIO5 (D1) on the ESP8266
  pinMode(inputPin, INPUT);
}

void loop() {
  int switchState = digitalRead(inputPin);

  if (switchState == HIGH) {
    myservo.write(180); // Stop at 180 degrees
    delay(1000);
  } else {
    myservo.write(0); // Stop at 0 degrees
    delay(1000);
  }
}
