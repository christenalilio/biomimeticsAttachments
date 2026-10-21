

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

// LED pins
#define led1 6
#define led2 5
#define led3 7

#define voltagePin A5

// Resistors (in kOhms)
int R1 = 10;
int R2 = 47;

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
  Serial.begin(9600);
  
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
}

float readBatteryV()
{
  int reading = analogRead(voltagePin);
    float voltageOut = reading * (5.0 / 1023.0);
    float voltageIn = voltageOut * ((R1+R2)/ R2);

    return voltageIn;
}

void updateLEDS (float voltageIn)
{
  if (voltageIn >= 6.0)
    {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH); 
    } 
    else if (voltageIn >= 4.8)
    {   digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH); 
    }
    else if (voltageIn >= 4.5)
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH); 
    }
  else 
  {
        digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
        digitalWrite(led3, LOW); 
  }
}

void loop()
  
{
  float voltageIn = readBatteryV();
  updateLEDS (voltageIn);
                               
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

  Serial.println(voltageIn);
  
  delay(250);
}

