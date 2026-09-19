#include <Servo.h>
Servo servo;

const int SERVO_PIN = 11;

void setup() {
  servo.attach(SERVO_PIN);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Enter servo angle (0-180): ");

  // Wait for user input
  while (Serial.available() == 0) {
  }

  int angle = Serial.parseInt();

  // Clear remaining characters
  while (Serial.available() > 0) {
    Serial.read();
  }

  if (angle >= 0 && angle <= 180) {
    servo.write(angle);
    Serial.println(angle);
  }
  else {
    Serial.println("Please enter an angle between 0 and 180.");
  }
}