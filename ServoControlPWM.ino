// Controls the 4 servos using potentiometers and mapping it to radians

// C++ code
// Rotimi
// Ruth

//https://omartronics.com/arduino-servo-motor-control-guide-for-sg90-pca9685/
//https://industrialmonitordirect.com/blogs/knowledgebase/calibrating-arduino-sg90-servos-pulse-width-range-and-torque?srsltid=AYCX9vJEkRLajNQU8QlfJY4QHhvyCjOh0MFMgOo5bbeqRzk3QJdfHMS1

#include <Servo.h>

#define potPin1 A0
#define potPin2 A1
#define potPin3 A2
#define potPin4 A3

#define servoPin1 12
#define servoPin2 11
#define servoPin3 10
#define servoPin4 9

Servo servo1, servo2, servo3, servo4;

const int minPulse_us = 500;
const int maxPulse_us = 2500;

const float pi = 3.14159;

float curAngle1 = pi/2, curAngle2 = pi/2, curAngle3 = pi/2, curAngle4 = pi/2;

void moveServo(Servo &s, float targetRad, float currentRad, float durationMs) {
  if (abs(targetRad - currentRad) <= ((2.0/360.0)*2*pi)) return; // ignore tiny noise shifts (2 degrees allowance)

  const float steps = 50.0f; //50 steps reduce jerkiness can be changed
  float delta = ((targetRad - currentRad)*2*pi) / steps;
  float delayMs = durationMs / steps;

  for (int i = 0; i <= steps; i++) {
    float nextRad = currentRad + delta * i;
    long us = minPulse_us + (long)((maxPulse_us - minPulse_us) * (nextRad / 180.0f));
    s.writeMicroseconds(us);
    delay((int)delayMs);
  }
}

void setup() {
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);

  servo1.write(curAngle1);
  servo2.write(curAngle2);
  servo3.write(curAngle3);
  servo4.write(curAngle4);
}

void loop() {
  float target1 = map(analogRead(potPin1), 0, 1023, 0, 180);
  float target2 = map(analogRead(potPin2), 0, 1023, 0, 180);
  float target3 = map(analogRead(potPin3), 0, 1023, 0, 180);
  float target4 = map(analogRead(potPin4), 0, 1023, 0, 180);

  moveServo(servo1, target1, curAngle1, 200);
  moveServo(servo2, target2, curAngle2, 200);
  moveServo(servo3, target3, curAngle3, 200);
  moveServo(servo4, target4, curAngle4, 200);

  delay(20);
}
