//4センサー 未完成 if文大量に書く
//閾値は後で変える
//モーター 右はPWM_motCD 左はmotAB
//vAxはセンサー　hAxは閾値
int vA0 = 0;
int TINPO = 0;
int vA1 = 0;
int vA2 = 0;
int vA3 = 0;
const int motorA = 8;
const int motorB = 6;
const int PWM_motAB = 9;
const int motorC = 10;
const int motorD = 5;
const int PWM_motCD = 11;
int hA2 = 300;
int hA1 = 300;
int hA3 = 300;
int hA0 = 300;
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
analogWrite(6,100); 
digitalWrite(11,HIGH);
digitalWrite(10,LOW);
delay(1000);
digitalWrite(6,HIGH);
digitalWrite(8,LOW);
delay(1000);
}
