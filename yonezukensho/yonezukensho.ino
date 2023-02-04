// センサに応じて左右のモーターを回転
const int motorA = 11;
const int motorB = 10;
const int PWM_motAB = 6;
const int motorC = 9;
const int motorD = 8;
const int PWM_motCD = 5;
// led 
const int ledA = 13;
const int ledB = 2;
//　フォトトランジスタ
const int sensorA = 2;
const int sensorB = 3;
//　センサから読み取った値（analog）
int valA = 0;
int valB = 0;
//　閾値
int alpha = 500;

void setup(){
  pinMode(motorA,OUTPUT); 
  pinMode(motorB,OUTPUT); 
  pinMode(motorC,OUTPUT); 
  pinMode(motorD,OUTPUT); 
  pinMode(PWM_motAB,OUTPUT); 
  pinMode(PWM_motCD,OUTPUT); 
  pinMode(ledA,OUTPUT); 
  pinMode(ledB,OUTPUT); 
  Serial.begin(9600); 
}

void loop(){
    digitalWrite(motorA,HIGH);
    digitalWrite(motorB,LOW);
    analogWrite(PWM_motAB,500); 
    digitalWrite(motorC,HIGH);
    digitalWrite(motorD,LOW);
    analogWrite(PWM_motCD,500); 
    delay(2000);
    //左が黒、右が白ならに左へ旋回
    digitalWrite(motorA,LOW);
    digitalWrite(motorB,LOW);
    digitalWrite(motorC,HIGH);
    digitalWrite(motorD,LOW);
    analogWrite(PWM_motCD,130); 
    delay(2000);
    //左が白、右が黒ならに右へ旋回
    digitalWrite(motorA,HIGH);
    digitalWrite(motorB,LOW);
    analogWrite(PWM_motAB,130); 
    digitalWrite(motorC,LOW);
    digitalWrite(motorD,LOW);    
    delay(2000);
    digitalWrite(motorA,HIGH);
    digitalWrite(motorB,LOW);
    analogWrite(PWM_motAB,500); 
    digitalWrite(motorC,HIGH);
    digitalWrite(motorD,LOW);
    analogWrite(PWM_motCD,500); 
    delay(2000);
}
