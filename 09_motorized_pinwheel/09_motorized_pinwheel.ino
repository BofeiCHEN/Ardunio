const int switchPin = 2;
const int motorPin = 9;
int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin);
  Serial.println(switchState);
  //analogWrite(motorPin, 220);
  if (switchState == 1) {
    //digitalWrite(motorPin, HIGH);
    analogWrite(motorPin, 200);
  }
  else {
    //digitalWrite(motorPin, LOW);
    analogWrite(motorPin, 0);
  }
}
