int sensorVal;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while(millis() < 5000) {
    sensorVal = analogRead(A0);

    if (sensorVal > sensorHigh) {
      sensorHigh = sensorVal;
    }

    if (sensorVal < sensorLow) {
      sensorLow = sensorVal;
    }
  }

  digitalWrite(ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorVal = analogRead(A0);
  int pitch = map(sensorVal, sensorLow, sensorHigh, 50, 4000);

  tone(8, pitch, 20);

  delay(10);
}
