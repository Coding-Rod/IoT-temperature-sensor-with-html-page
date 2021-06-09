int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

int temperature();
int temperature(){
    return (analogRead(sensorPin) / 1023.0) * 500;
}

void setup() {
  Serial.begin(9600);
}

void loop() {  
  Serial.print(temperature());
  Serial.println("°C");
  delay(500);
}