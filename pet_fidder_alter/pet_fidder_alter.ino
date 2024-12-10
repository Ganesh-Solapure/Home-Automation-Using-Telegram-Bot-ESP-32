#include <ESP8266WiFi.h>
#include <Servo.h>

Servo myservo;               // create servo object to control a servo
const int INPUT_PIN = 4;     // the number of the input pin (GPIO4, D2 on NodeMCU)
const int SERVO_PIN = 5;     // the number of the servo pin (GPIO5, D1 on NodeMCU)
int previousInputState = LOW; // variable to store the previous input state

void setup() {
  pinMode(INPUT_PIN, INPUT_PULLUP); // initialize the input pin as an input with pull-up resistor
  myservo.attach(SERVO_PIN);        // attaches the servo on pin 5 (D1) to the servo object
}

void loop() {
  int inputState = digitalRead(INPUT_PIN); // read the state of the input pin

  if (inputState == HIGH && previousInputState == LOW) {
    // Sweep to 180 degrees
    for (int angle = 0; angle <= 180; angle++) {
      myservo.write(angle);
      delay(15);
    }

    // Wait for 3 seconds
    delay(3000);

    // Return to 0 position
    for (int angle = 180; angle >= 0; angle--) {
      myservo.write(angle);
      delay(15);
    }
  }

  // Update the previous input state
  previousInputState = inputState;

  // Stop at 0 degree if input is not high
  if (inputState == LOW) {
    myservo.write(0);
  }
}
