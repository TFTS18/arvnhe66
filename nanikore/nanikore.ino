// モーター制御
const int motorA = 8;
const int motorB = 6;
const int PWM_motAB = 9;
const int motorC = 10;
const int motorD = 5;
const int PWM_motCD = 11;
void setup(){
  pinMode(motorA,OUTPUT); //信号用ピン
  pinMode(motorB,OUTPUT); //信号用ピン
  pinMode(motorC,OUTPUT); //信号用ピン
  pinMode(motorD,OUTPUT); //信号用ピン
  pinMode(PWM_motAB,OUTPUT); 
  pinMode(PWM_motCD,OUTPUT); 
}

void loop(){
  //全てのモータを停止
  digitalWrite(motorA,HIGH);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,HIGH);
  digitalWrite(motorD,LOW);
  delay(1000);
  delay(1000);
  digitalWrite(motorA,HIGH);
  digitalWrite(motorB,LOW);
  analogWrite(PWM_motAB,1000); 
  delay(2000);
  digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  delay(500);
  digitalWrite(motorA,LOW);
  digitalWrite(motorB,HIGH);
  analogWrite(PWM_motAB,100); 
  delay(500);
  digitalWrite(motorA,LOW);
  digitalWrite(motorB,HIGH);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,HIGH);
  delay(1000);
}
