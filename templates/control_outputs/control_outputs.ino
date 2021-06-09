const int pinENA = D3;
const int pinIN1 = D5;

const int speed = 200;
bool outs[4] = {0,0,0,0};
int outpins[4] = {D1,D2,D3,D4};
int c = 0;

void outputs(int x[], bool y[]);
void outputs(int x[], bool y[]){
    for (int i = 0; i < 4; i++)
    {
        digitalWrite(x[i], y[i]?HIGH:LOW);
    }
    
}

void setup(){   
   Serial.begin(9600);
   pinMode(pinIN1, OUTPUT);
   pinMode(pinENA, OUTPUT);
}

void loop(){
   analogWrite(pinENA, speed);
   c++;
   outs[0] = bool(int(c%2));
   outs[1] = bool(int((c%4)/4));
   outs[2] = bool(int((c%8)/8));
   outs[3] = bool(int((c%16)/16));
   Serial.print(outs[0]);
   Serial.print(outs[1]);
   Serial.print(outs[2]);
   Serial.print(outs[3]);
   Serial.print('\n');
   outputs(outpins, outs);
   delay(5000);
}