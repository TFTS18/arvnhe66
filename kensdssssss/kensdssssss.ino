//4センサー 未完成 if文大量に書く
//閾値は後で変える
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
int hA2 = 300;
int hA1 = 300;
int hA3 = 300;
int hA0 = 300;
void setup(){
pinMode(motorA,OUTPUT); 
pinMode(motorB,OUTPUT); 
pinMode(motorC,OUTPUT); 
pinMode(motorD,OUTPUT); 
pinMode(13,OUTPUT);
pinMode(PWM_motAB,OUTPUT); 
pinMode(PWM_motCD,OUTPUT); 
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
     vA0 = analogRead(A0);
     vA1 = analogRead(A1);
     vA2 = analogRead(A2);
     vA3 = analogRead(A3);
     Serial.print("A0= "); 
     Serial.print(vA0);
     Serial.println();
     Serial.print("A1== "); 
     Serial.println(vA1);
     Serial.print("A2= "); 
     Serial.print(vA2);
     Serial.println();
     Serial.print("A3== "); 
     Serial.println(vA3);
     Serial.println();
     analogWrite(PWM_motAB,235); 
     digitalWrite(motorA,LOW);
     digitalWrite(motorB,HIGH);
     analogWrite(PWM_motCD,190); 
     digitalWrite(motorC,LOW);
     digitalWrite(motorD,HIGH);
     delay(1000);
     analogWrite(PWM_motAB,0); 
     digitalWrite(motorA,LOW);
     digitalWrite(motorB,HIGH);
     analogWrite(PWM_motCD,0); 
     digitalWrite(motorC,LOW);
     digitalWrite(motorD,HIGH);
     delay(1000);
     analogWrite(PWM_motAB,235); 
     digitalWrite(motorA,HIGH);
     digitalWrite(motorB,LOW);
     analogWrite(PWM_motCD,190); 
     digitalWrite(motorC,HIGH);
     digitalWrite(motorD,LOW);
     delay(1000);
     analogWrite(PWM_motAB,-100); 
     digitalWrite(motorA,LOW);
     digitalWrite(motorB,LOW);
     analogWrite(PWM_motCD,-190); 
     digitalWrite(motorC,LOW);
     digitalWrite(motorD,LOW);
     delay(1000);
}
