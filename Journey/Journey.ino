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
const int motorB = 190;
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
<<<<<<< HEAD
pinMode(PWM_motAB,OUTPUT); 
pinMode(PWM_motCD,OUTPUT); 
=======
>>>>>>> 9963b8ba1b922f605ef4d996eebe30996facaffe
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
  //モーター 左AB　右CD
  if (vA0 < hA0 && vA1 >= hA1 && vA2 >= hA2 && vA3 < hA3){
    //0白1黒2黒3白　
     analogWrite(PWM_motAB,235); 
     digitalWrite(motorA,HIGH);
     digitalWrite(motorB,LOW);
     analogWrite(PWM_motCD,190); 
     digitalWrite(motorC,HIGH);
     digitalWrite(motorD,LOW);
  }else if(vA0 < hA0 && vA1 < hA1 && vA2 >= hA2 && vA3 < hA3){
      //W W B W 右折 
      analogWrite(PWM_motAB,235); 
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,LOW);
      analogWrite(PWM_motCD,0); 
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,LOW);
  }else if(vA0 < hA0 && vA1 >= hA1 && vA2 >= hA2 && vA3 >= hA3){
      //W B B B ┤右折
      analogWrite(PWM_motAB,235); 
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,LOW);
      analogWrite(PWM_motCD,0); 
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,LOW);
      delay(1600);
    }else if(vA0 < hA0 && vA1 < hA1 && vA2 >= hA2 && vA3 >= hA3){
      //W W B B ┤右折
      analogWrite(PWM_motAB,235); 
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,LOW);
      analogWrite(PWM_motCD,0); 
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,LOW);
      delay(1600);
  }else if(vA0 < hA0 && vA1 >= hA1 && vA2 < hA2 && vA3 < hA3){
      //w b w w 左折
      analogWrite(PWM_motAB,0);   
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,LOW);
      analogWrite(PWM_motCD,190); 
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,LOW);
  }else if(vA0 >= hA0 && vA1 >= hA1 && vA2 >= hA2 && vA3 < hA3){
      //B B B W ┤左折
      analogWrite(PWM_motAB,0); 
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,LOW);
      analogWrite(PWM_motCD,190); 
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,LOW);
      delay(1600);
  }else if(vA0 >= hA0 && vA1 >= hA1 && vA2 < hA2 && vA3 < hA3){
      //B B W W ┤左折
      analogWrite(PWM_motAB,0); 
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,LOW);
      analogWrite(PWM_motCD,190); 
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,LOW);
      delay(1600);
  }else if(vA0 < hA0 && vA1 < hA1 && vA2 < hA2 && vA3 < hA3){
      //w w w w
      //現在調査中　適当なプログラムを入れている
      analogWrite(PWM_motAB,235); 
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,LOW);
      analogWrite(PWM_motCD,190); 
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,LOW);
  }else{
      delay(1);
  }
      delay(10);
      analogWrite(PWM_motAB,235); 
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,LOW);
      analogWrite(PWM_motCD,190); 
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,LOW);
      delay(10);
}
