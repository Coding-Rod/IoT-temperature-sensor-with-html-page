// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = D0;

// the setup routine runs once when you press reset:
bool person();
bool person(){
    return digitalRead(pushButton);
}

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.println(person());
  delay(1);        // delay in between reads for stability
}
