const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 1000;

void setup() {
  // put your setup code here, to run once:
  for(int x = 2; x<8; x++) {
    pinMode(x, OUTPUT);
  }

  pinMode(switchPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();
  Serial.println(currentTime);
  Serial.println(previousTime);

  if((currentTime - previousTime) > interval) {
    previousTime = currentTime;

    if(led == 8) {
      for(int x=2; x<8;x++){
      digitalWrite(x, LOW);
    }
      led = 2;
    }
    
    digitalWrite(led, HIGH);
    led++;
    
  }

  switchState = digitalRead(switchPin);

  if(switchState != prevSwitchState){
    for(int x=2; x<8;x++){
      digitalWrite(x, LOW);
    }
    led = 2;
    previousTime = currentTime;
  }

  prevSwitchState = switchState;
}
