#include <Servo.h>
Servo servo;

// Pin Definitions
const int TRIG_PIN = 13;
const int ECHO_PIN = 12;
const int SERVO_PIN = 11;
const int LEFT_ENABLE_PIN = 5;     // PWM pin required
const int RIGHT_ENABLE_PIN = 6;    // PWM pin required
const int LEFT_MOTOR_PIN1 = 3;
const int LEFT_MOTOR_PIN2 = 4;
const int RIGHT_MOTOR_PIN1 = 10;
const int RIGHT_MOTOR_PIN2 = 9;


// Motor Speed Calibration
const int MAX_SPEED = 255;
const int SPEED_DIFFERENCE = 0;    // Left motor speed - right motor speed 
const int LEFT_MOTOR_SPEED = (SPEED_DIFFERENCE >= 0) ? MAX_SPEED : MAX_SPEED + SPEED_DIFFERENCE;
const int RIGHT_MOTOR_SPEED = (SPEED_DIFFERENCE <= 0) ? MAX_SPEED : MAX_SPEED - SPEED_DIFFERENCE;


// Control Parameters
const float SPEED_OF_SOUND = 0.0345;         // cm/μs
const float WALL_DISTANCE = 20.0;            // cm
const unsigned long ECHO_TIMEOUT = 30000;    // μs


bool ball_released = false;


void forward() {
    digitalWrite(LEFT_MOTOR_PIN1, HIGH);
    digitalWrite(LEFT_MOTOR_PIN2, LOW);
    digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
    digitalWrite(RIGHT_MOTOR_PIN2, LOW);
    analogWrite(LEFT_ENABLE_PIN, LEFT_MOTOR_SPEED);
    analogWrite(RIGHT_ENABLE_PIN, RIGHT_MOTOR_SPEED);
}


void backward() {
    digitalWrite(LEFT_MOTOR_PIN1, LOW);
    digitalWrite(LEFT_MOTOR_PIN2, HIGH);
    digitalWrite(RIGHT_MOTOR_PIN1, LOW);
    digitalWrite(RIGHT_MOTOR_PIN2, HIGH);
    analogWrite(LEFT_ENABLE_PIN, LEFT_MOTOR_SPEED);
    analogWrite(RIGHT_ENABLE_PIN, RIGHT_MOTOR_SPEED);
}


void stop() {
    digitalWrite(LEFT_MOTOR_PIN1, LOW);
    digitalWrite(LEFT_MOTOR_PIN2, LOW);
    digitalWrite(RIGHT_MOTOR_PIN1, LOW);
    digitalWrite(RIGHT_MOTOR_PIN2, LOW);
    analogWrite(LEFT_ENABLE_PIN, 0);
    analogWrite(RIGHT_ENABLE_PIN, 0);
}


float measureDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    unsigned long duration = pulseIn(ECHO_PIN, HIGH, ECHO_TIMEOUT);
    return duration * SPEED_OF_SOUND / 2;
}


// void releaseBall() {
//     servo.write(90);
//     delay(1000);
//     servo.write(180);
//     ball_released = true;
// }


void setup() {
    pinMode(LEFT_ENABLE_PIN, OUTPUT);
    pinMode(RIGHT_ENABLE_PIN, OUTPUT);
    pinMode(LEFT_MOTOR_PIN1, OUTPUT);
    pinMode(LEFT_MOTOR_PIN2, OUTPUT);
    pinMode(RIGHT_MOTOR_PIN1, OUTPUT);
    pinMode(RIGHT_MOTOR_PIN2, OUTPUT);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    servo.attach(SERVO_PIN);
    servo.write(180);
    Serial.begin(9600);
}



void loop() {
    if (ball_released) {
        backward();
        delay(10);
        return;
    }

    float distance = measureDistance();
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm -> ");

    if (0 < distance && distance < WALL_DISTANCE) {
        Serial.println("stop");
        stop();
        delay(2000);
        ball_released = true;
    } else {
        Serial.println("forward");
        forward();
    }

    delay(10);
}

