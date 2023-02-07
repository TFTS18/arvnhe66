const int motorA = 11;
const int motorB = 10;
const int PWM_motAB = 6;
const int motorC = 9;
const int motorD = 8;
const int PWM_motCD = 5;
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
digitalWrite(motorC,LOW);
digitalWrite(motorD,HIGH);
analogWrite(PWM_motCD,300); 
delay(1600);
digitalWrite(motorC,HIGH);
digitalWrite(motorD,LOW);
analogWrite(PWM_motCD,300); 
delay(1600);
}