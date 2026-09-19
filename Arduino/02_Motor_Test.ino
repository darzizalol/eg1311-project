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

void setup() {
  pinMode(MOTOR_PIN_1, OUTPUT);
  pinMode(MOTOR_PIN_2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Ready!");
  Serial.println("Input: f / b / s");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    switch (command) {
      case 'f':
        Serial.println("forward");
        forward();
        break;

      case 'b':
        Serial.println("backward");
        backward();
        break;

      case 's':
        stop();
        Serial.println("stop");
        break;

      default:
        break;
    }
  }
}