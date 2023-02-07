//4センサー 未完成 if文大量に書く8
//閾値は後で変える
//モーター 右は9 左はmotAB
//vAxはセンサー　hAxは閾値
int vA0 = 0;
int TINPO = 0;
int vA1 = 0;
int vA2 = 0;
int vA3 = 0;
int hA2 = 300;
int hA1 = 300;
int hA3 = 300;
int hA0 = 300;
void setup(){
pinMode(6,OUTPUT); 
pinMode(10,OUTPUT); 
pinMode(5,OUTPUT); 
pinMode(8,OUTPUT); 
pinMode(11,OUTPUT); 
pinMode(9,OUTPUT); 
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
  //モーター 左11　右9
  if (vA0 < hA0 && vA1 >= hA1 && vA2 >= hA2 && vA3 < hA3){
    //0白1黒2黒3白　
     analogWrite(11,235); 
     digitalWrite(6,HIGH);
     digitalWrite(10,LOW);
     analogWrite(9,195); 
     digitalWrite(5,HIGH);
     digitalWrite(8,LOW);
  }else if(vA0 < hA0 && vA1 < hA1 && vA2 >= hA2 && vA3 < hA3){
      //W W B W 右折 
      analogWrite(11,235); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,0); 
      digitalWrite(5,LOW);
      digitalWrite(8,LOW);
  }else if(vA0 < hA0 && vA1 >= hA1 && vA2 >= hA2 && vA3 >= hA3){
      //W B B B ┤右折
      analogWrite(11,235); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,195); 
      digitalWrite(5,LOW);
      digitalWrite(8,HIGH);
      delay(1600);
    }else if(vA0 < hA0 && vA1 < hA1 && vA2 >= hA2 && vA3 >= hA3){
      //W W B B ┤右折
      analogWrite(11,235); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,195); 
      digitalWrite(5,LOW);
      digitalWrite(8,HIGH);
      delay(1600);
  }else if(vA0 < hA0 && vA1 >= hA1 && vA2 < hA2 && vA3 < hA3){
      //w b w w 左折
      analogWrite(11,0);   
      digitalWrite(6,LOW);
      digitalWrite(10,LOW);
      analogWrite(9,195); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
  }else if(vA0 >= hA0 && vA1 >= hA1 && vA2 >= hA2 && vA3 < hA3){
      //B B B W ┤左折
      analogWrite(11,235); 
      digitalWrite(6,LOW);
      digitalWrite(10,HIGH);
      analogWrite(9,195); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
      delay(1600);
  }else if(vA0 >= hA0 && vA1 >= hA1 && vA2 < hA2 && vA3 < hA3){
      //B B W W ┤左折
      analogWrite(11,235); 
      digitalWrite(6,LOW);
      digitalWrite(10,HIGH);
      analogWrite(9,195); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
      delay(1600);
  }else if(vA0 < hA0 && vA1 < hA1 && vA2 < hA2 && vA3 < hA3){
      //w w w w
      //現在調査中　適当なプログラムを入れている
      analogWrite(11,235); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,195); 
      digitalWrite(5,LOW);
      digitalWrite(8,HIGH);
  }else{
      delay(1);
  }
}
