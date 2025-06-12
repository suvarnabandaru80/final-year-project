#include <SoftwareSerial.h>
#include <Servo.h>

#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9
#define TRIG_PIN 10
#define ECHO_PIN 11
#define MQ135_PIN A0

SoftwareSerial bt(0, 1); // RX, TX
Servo scanServo;
char data;

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  scanServo.attach(5);
  scanServo.write(90);  // center position

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
  if (bt.available()) {
    data = bt.read();
    Serial.println(data);

    switch (data) {
      case 'F': forward(); break;
      case 'B': reverse(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      case 'S': stoprobot(); break;
      case 'U': obstacleScan(); break;
    }
  }

  int mq135_value = analogRead(MQ135_PIN);
  Serial.print("Air Quality (MQ135): ");
  Serial.println(mq135_value);
  delay(100);
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(20);
}

void reverse() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(20);
}

void left() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(20);
}

void right() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(20);
}

void stoprobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(20);
}

void obstacleScan() {
  for (int angle = 60; angle <= 120; angle += 15) {
    scanServo.write(angle);
    delay(300);
    long distance = measureDistance();
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print("°, Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  scanServo.write(90);  // Reset to center
}

long measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}
