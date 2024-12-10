#include <ESP8266WiFi.h>
#include <Servo.h>

Servo servo1;               // create servo object to control the first servo
Servo servo2;               // create servo object to control the second servo
const int INPUT_PIN_1 = A0; // the number of the input pin for the first servo (A0)
const int SERVO_PIN_1 = 5;  // the number of the servo pin for the first servo
const int INPUT_PIN_2 = 4; // the number of the input pin for the second servo (A1)
const int SERVO_PIN_2 = 14; // the number of the servo pin for the second servo
int previousInputState1 = LOW; // variable to store the previous input state for the first servo
int previousInputState2 = LOW; // variable to store the previous input state for the second servo
const int THRESHOLD = 512;   // Threshold for considering HIGH or LOW (half of 1023)

void setup() {
  pinMode(INPUT_PIN_1, INPUT);
  pinMode(INPUT_PIN_2, INPUT);

  servo1.attach(SERVO_PIN_1);
  servo2.attach(SERVO_PIN_2);
  +
}

void loop() {
  int switchState1 = analogRead(INPUT_PIN_1) > THRESHOLD ? HIGH : LOW;
  int switchState2 = analogRead(INPUT_PIN_2) > THRESHOLD ? HIGH : LOW;

  if (switchState1 == HIGH && previousInputState1 == LOW) {
    servo1.write(180);
    delay(1500);
  } else if (switchState1 == LOW) {
    servo1.write(0);
    delay(1000);
  }

  if (switchState2 == HIGH && previousInputState2 == LOW) {
    for (int angle = 0; angle <= 180; angle++) {
      servo2.write(angle);
      delay(150);
    }
    delay(3000);
    for (int angle = 180; angle >= 0; angle--) {
      servo2.write(angle);
      delay(200);
    }
  } else if (switchState2 == LOW) {
    servo2.write(60);
  }

  previousInputState1 = switchState1;
  previousInputState2 = switchState2;
}
