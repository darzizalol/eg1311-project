// Pin Definitions
const int MOTOR_PIN_1 = 5;
const int MOTOR_PIN_2 = 6;
const int TRIG_PIN = 12;
const int ECHO_PIN = 13;

// Control Parameters
const float SPEED_OF_SOUND = 0.0345;         // cm/μs
const float WALL_DISTANCE = 20.0;            // cm
const unsigned long ECHO_TIMEOUT = 30000;    // μs

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
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int microsecs = pulseIn(ECHO_PIN, HIGH, ECHO_TIMEOUT);
  return microsecs * SPEED_OF_SOUND / 2;
}

void setup() {
  pinMode(MOTOR_PIN_1, OUTPUT);
  pinMode(MOTOR_PIN_2, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  float distance = measureDistance();
  Serial.print(distance);
  Serial.print(" cm -> ");

  if (0 < distance && distance < WALL_DISTANCE) {
    Serial.println("stop");
    stop();
  } else {
    Serial.println("forward");
    forward();
  }
}


