#include <Servo.h>
Servo servo;

// Pin Definitions
const int TRIG_PIN = 13;
const int ECHO_PIN = 12;
const int SERVO_PIN = 11;
const int MOTOR_PIN_1 = 5;
const int MOTOR_PIN_2 = 6;

// Control Parameters
const float SPEED_OF_SOUND = 0.0345;         // cm/μs
const float WALL_DISTANCE = 20.0;            // cm
const unsigned long ECHO_TIMEOUT = 30000;    // μs
const int HOLD_ANGLE = 180;
const int LAUNCH_ANGLE = 90;

bool ball_released = false;

void forward() {
  digitalWrite(MOTOR_PIN_1, HIGH);
  digitalWrite(MOTOR_PIN_2, LOW);
}

void backward() {
  digitalWrite(MOTOR_PIN_1, LOW);
  digitalWrite(MOTOR_PIN_2, HIGH);
}

void stop() {
  digitalWrite(MOTOR_PIN_1, LOW);
  digitalWrite(MOTOR_PIN_2, LOW);
}

float measureDistance() {
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int microsecs = pulseIn(ECHO_PIN, HIGH, ECHO_TIMEOUT);
  return microsecs * SPEED_OF_SOUND / 2;
}

void launchBall() {
  delay(3000);
  servo.write(LAUNCH_ANGLE);
  delay(1000);
  servo.write(HOLD_ANGLE);
  ball_released = true;
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MOTOR_PIN_1, OUTPUT);
  pinMode(MOTOR_PIN_2, OUTPUT);
  Serial.begin(9600);
  digitalWrite(TRIG_PIN, LOW);
  servo.attach(SERVO_PIN);
  servo.write(HOLD_ANGLE);
}

void loop() {
  if (ball_released) {
    backward();
    return;
  }

  float distance = measureDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm -> ");

  if (0 < distance && distance < WALL_DISTANCE) {
    Serial.println("stop");
    stop();
    launchBall()
  } else {
    Serial.println("forward");
    forward();
  }

  delay(10);
}



