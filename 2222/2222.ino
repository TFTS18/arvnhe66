//モーター 右はPWM_motCD 左はmotAB
//vAxはセンサー　hAxは閾値
int vA0 = 0;
int TINPO = 0;
int vA1 = 0;
int vA2 = 0;
int vA3 = 0;
const int motorA = 11;
const int motorB = 180;
const int PWM_motAB = 6;
const int motorC = 9;
const int motorD = 8;
const int PWM_motCD = 5;
int hA2= 300;
int hA1 = 300;
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
   if(TINPO == 6){
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
    TINPO = 0;
  }else{
    TINPO = TINPO + 1;
  }
  //モーター 右AB左CD
  if (vA1 >= hA1 && vA2 >= hA2){
    //左、右ともに黒なら直進
    analogWrite(PWM_motAB,235); 
    digitalWrite(motorA,HIGH);
    digitalWrite(motorB,LOW);
    analogWrite(PWM_motCD,180); 
    digitalWrite(motorC,HIGH);
    digitalWrite(motorD,LOW);
  }else if(vA1 < hA1 && vA2 >= hA2){
    //左が黒、右が白ならに右へ旋回
    analogWrite(PWM_motAB,235); 
    digitalWrite(motorA,HIGH);
    digitalWrite(motorB,LOW);
    analogWrite(PWM_motCD,0); 
    digitalWrite(motorC,HIGH);
    digitalWrite(motorD,LOW);
  }else if(vA1 >= hA1 && vA2 < hA2){
    //左が白、右が黒ならに左へ旋回
    analogWrite(PWM_motAB,0);   
    digitalWrite(motorA,HIGH);
    digitalWrite(motorB,LOW);
    analogWrite(PWM_motCD,180); 
    digitalWrite(motorC,HIGH);
    digitalWrite(motorD,LOW);
  }else if(vA1 < hA1 && vA2 < hA2){
    //療法白直進
    analogWrite(PWM_motAB,235); 
    digitalWrite(motorA,HIGH);
    digitalWrite(motorB,LOW);
    analogWrite(PWM_motCD,180); 
    digitalWrite(motorC,HIGH);
    digitalWrite(motorD,LOW);
  }else{
  }
    delay(20);
    analogWrite(PWM_motAB,235); 
    digitalWrite(motorA,HIGH);
    digitalWrite(motorB,LOW);
    analogWrite(PWM_motCD,180); 
    digitalWrite(motorC,HIGH);
    digitalWrite(motorD,LOW);
    delay(20);
}
