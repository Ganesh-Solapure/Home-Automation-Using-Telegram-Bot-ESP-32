// Copyright [2024] [Ganesh Solapure]
// https://github.com/Ganesh-Solapure/Home-Automation-Using-Telegram-Bot-ESP-32/blob/main/LICENSE


#include <ESP8266WiFi.h>
#include <Servo.h>

Servo servo1;               // create servo object to control the first servo
Servo servo2;               // create servo object to control the second servo
const int INPUT_PIN_1 = 2;  // the number of the input pin for the first servo
const int SERVO_PIN_1 = 5;  // the number of the servo pin for the first servo
const int INPUT_PIN_2 = 4;  // the number of the input pin for the second servo
const int SERVO_PIN_2 = 14; // the number of the servo pin for the second servo
int previousInputState1 = LOW; // variable to store the previous input state for the first servo
int previousInputState2 = LOW; // variable to store the previous input state for the second servo

void setup() {
  pinMode(INPUT_PIN_1, OUTPUT);
  pinMode(INPUT_PIN_2, OUTPUT);
  digitalWrite(INPUT_PIN_1, LOW);
  digitalWrite(INPUT_PIN_2, LOW);

  servo1.attach(SERVO_PIN_1);
  servo2.attach(SERVO_PIN_2);
}


void loop() {
  int switchState1 = digitalRead(INPUT_PIN_1);
  int switchState2 = digitalRead(INPUT_PIN_2);

  if (switchState1 == HIGH && previousInputState1 == LOW) {
    servo1.write(180);
    delay(1000);
  } else if (switchState1 == LOW) {
    servo1.write(0);
    delay(1000);
  }

  if (switchState2 == HIGH && previousInputState2 == LOW) {
    for (int angle = 0; angle <= 180; angle++) {
      servo2.write(angle);
      delay(15);
    }
    delay(3000);
    for (int angle = 180; angle >= 0; angle--) {
      servo2.write(angle);
      delay(15);
    }
  } else if (switchState2 == LOW) {
    servo2.write(0);
  }

  previousInputState1 = switchState1;
  previousInputState2 = switchState2;
}
