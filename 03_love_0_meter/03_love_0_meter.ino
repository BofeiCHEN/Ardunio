const int sensorPin = A0;
const float baselineTemp = 22.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for(int pinNumber = 2; pinNumber < 5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);

  Serial.print("Sensor Value:");
  Serial.print(sensorVal);

  //Convert the ADC reading to voltage
  float voltage = (sensorVal / 1024.0)*5.0;

  Serial.print(", Volts:");
  Serial.print(voltage);

  //Convert the voltage to temperature in degree
  float temperature  = (voltage - 0.5)*100;
  Serial.print(", degrees C:");
  Serial.println(temperature);

  if(temperature < baselineTemp +1){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if(temperature >= baselineTemp +1 && 
            temperature < baselineTemp +2){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if(temperature >= baselineTemp +2 && 
            temperature < baselineTemp +3){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if(temperature >= baselineTemp +3 && 
            temperature < baselineTemp +4){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if(temperature >= baselineTemp +4 && 
            temperature < baselineTemp +5){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  } else if(temperature >= baselineTemp +5 && 
            temperature < baselineTemp +6){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  } else if(temperature >= baselineTemp +6 && 
            temperature < baselineTemp +7){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  } else if(temperature >= baselineTemp +7 && 
            temperature < baselineTemp +8){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  } else if(temperature >= baselineTemp +8){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    delay(250);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    delay(250);
  }
  delay(1);
  
}
