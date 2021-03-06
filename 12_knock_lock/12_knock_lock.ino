#include <Servo.h>
Servo myServo;

const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;
const int servoPin = 9;

int knockVal;
int switchVal;

const int quietKnock = 20;
const int loudKnock = 100;

boolean locked = false;
int numberOfKnocks = 0;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, HIGH);
  myServo.write(0);
  Serial.println("The box is unlocked!");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(locked == false) {
    switchVal = digitalRead(switchPin);

    if(switchVal == HIGH) {
      locked = true;
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      myServo.write(90);
      Serial.println("The box is locked!");
      delay(1000);
    }
  }

  if(locked == true) {
    knockVal = analogRead(piezo);

    if(numberOfKnocks < 3 && knockVal >0) {
      if(checkForKnock(knockVal) == true) {
        numberOfKnocks++;
      }
      Serial.print(3-numberOfKnocks);
      Serial.println(" more knocks to go");
    }

    if(numberOfKnocks >=3) {
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("The box is unlocked!");
      numberOfKnocks = 0;      
    }
  }
}

boolean checkForKnock(int value) {
  if(value > quietKnock && value < loudKnock) {
    digitalWrite(yellowLed, HIGH);
    delay(50);
    digitalWrite(yellowLed, LOW);
    Serial.print("Valid knock of value ");
    Serial.println(value);
    return true;
  }
  else {
    Serial.print("Bad knock value ");
    Serial.println(value);
    return false;
  }
}
