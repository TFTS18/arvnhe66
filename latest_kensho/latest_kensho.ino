const int motorA = 8;
const int motorB = 6;
const int PWM_motAB = 9;
const int motorC = 10;
const int motorD = 5;
const int PWM_motCD = 11;
void setup(){
pinMode(motorA,OUTPUT); 
pinMode(motorB,OUTPUT); 
pinMode(motorC,OUTPUT); 
pinMode(motorD,OUTPUT); 
pinMode(PWM_motAB,OUTPUT); 
pinMode(PWM_motCD,OUTPUT); 
Serial.begin(9600);
}

void loop() {
analogWrite(PWM_motAB,110); 
digitalWrite(motorA,LOW);
digitalWrite(motorD,HIGH);
delay(1600);
analogWrite(PWM_motAB,1000); 
digitalWrite(motorA,HIGH);
digitalWrite(motorD,LOW);
delay(1600);
}