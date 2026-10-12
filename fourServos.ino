// Controls the 4 servos using potentiometers and mapping it to degrees

// C++ code
// Rotimi

#include <Servo.h>

// Potentiometer pins
#define potPin1 A0
#define potPin2 A1
#define potPin3 A2
#define potPin4 A3

// Servo pins
#define servoPin1 12
#define servoPin2 11
#define servoPin3 10
#define servoPin4 9

// Creating servo objects
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

//Creating variables
int potVal1;
int potVal2;
int potVal3;
int potVal4;

void setup()
{
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  
}

void loop()
{
  // Read value from potentiometer
  potVal1 = analogRead(potPin1);
  potVal2 = analogRead(potPin2);
  potVal3 = analogRead(potPin3);
  potVal4 = analogRead(potPin4);
  
  // Map value from potentiometer to an equivalent angle
  int angle1 = map(potVal1, 0, 1023, 0, 180);
  int angle2 = map(potVal2, 0, 1023, 0, 180);
  int angle3 = map(potVal3, 0, 1023, 0, 180);
  int angle4 = map(potVal4, 0, 1023, 0, 180);
  
  // Wrote to servo
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
  servo4.write(angle4);
  
  delay(10);

}
}
