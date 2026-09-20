// Pin Definitions
const int TRIG_PIN = 13;
const int ECHO_PIN = 12;
const int MOTOR_PIN_1 = 5;
const int MOTOR_PIN_2 = 6;

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

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MOTOR_PIN_1, OUTPUT);
  pinMode(MOTOR_PIN_2, OUTPUT);
  Serial.begin(9600);
  digitalWrite(TRIG_PIN, LOW);
}

void loop() {
  float distance = measureDistance();
  Serial.print("Distance: ");
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

