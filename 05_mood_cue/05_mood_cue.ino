#include <Servo.h>

Servo myServo;
int const potPin = A0;
int potVal;
int angle;
void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  myServo.write(angle);  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  Serial.print("potVal:");
  Serial.print(potVal);

  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(15);
// for(angle = 10; angle < 180; angle++)  
//  {                                  
//    myServo.write(angle);               
//    delay(500);                   
//  } 
//  // now scan back from 180 to 0 degrees
//  for(angle = 180; angle > 10; angle--)    
//  {                                
//    myServo.write(angle);           
//    delay(500);       
//  }
}
