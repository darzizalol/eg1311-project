#include <Servo.h>
Servo servo;

const int SERVO_PIN = 11;
const int HOLD_ANGLE = 180;
const int LAUNCH_ANGLE = 90;

void launchBall() {
  delay(3000);
  servo.write(LAUNCH_ANGLE);
  delay(1000);
  servo.write(HOLD_ANGLE);
}

void setup() {
  Serial.begin(9600);
  servo.attach(SERVO_PIN);
  servo.write(HOLD_ANGLE);
}

void loop() {
  launchBall();
}
