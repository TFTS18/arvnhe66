
//モーター 右はPWM_motCD 左はmotAB
//vAxはセンサー　hAxは閾値
int vA0 = 0;
int TINPO = 0;
int vA1 = 0;
int vA2 = 0;
int vA3 = 0;
const int motorA = 11;
const int motorB = 10;
const int PWM_motAB = 6;
const int motorC = 9;
const int motorD = 8;
const int PWM_motCD = 5;
int hA2= 400;
int hA1 = 400;
int jeiejefi = 0;
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
  analogWrite(5,100);
  delay(100);
  digitalWrite(8,HIGH);
}