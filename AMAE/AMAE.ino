//4センサー 未完成 if文大量に書く8
//閾値は後で変える
//vAxはセンサー　hAxは閾値
int vA0 = 0;
int MANKO = 0;
int TINPO = 0;
int vA1 = 0;
int vA2 = 0;
int vA3 = 0;
int hA2 = 400;
int hA1 = 400;
int hA3 = 400;
int hA0 = 400;
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
   if(TINPO == 60){
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
     analogWrite(11,180); 
     digitalWrite(6,HIGH);
     digitalWrite(10,LOW);
     analogWrite(9,180); 
     digitalWrite(5,HIGH);
     digitalWrite(8,LOW);
  }else if(vA0 < hA0 && vA1 < hA1 && vA2 >= hA2 && vA3 < hA3){
      //W W B W 右折 
      analogWrite(11,170); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,51); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
  }else if(vA0 < hA0 && vA1 >= hA1 && vA2 >= hA2 && vA3 >= hA3){
      //W B B B ├直進
     analogWrite(11,180); 
     digitalWrite(6,HIGH);
     digitalWrite(10,LOW);
     analogWrite(9,180); 
     digitalWrite(5,HIGH);
     digitalWrite(8,LOW);
     delay(50);
  }else if(vA0 < hA0 && vA1 < hA1 && vA2 >= hA2 && vA3 >= hA3){
      //W W B B ├直進
     analogWrite(11,180); 
     digitalWrite(6,HIGH);
     digitalWrite(10,LOW);
     analogWrite(9,180); 
     digitalWrite(5,HIGH);
     digitalWrite(8,LOW);
     delay(50);
  }else if(vA0 < hA0 && vA1 >= hA1 && vA2 < hA2 && vA3 < hA3){
      //w b w w 左折
      analogWrite(11,51);   
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,170); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
  }else if(vA0 >= hA0 && vA1 >= hA1 && vA2 >= hA2 && vA3 < hA3){
      //B B B W ┤左90
      analogWrite(11,20); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,100); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
      delay(1600);
      while(vA2 < hA2){
        delay(30);
      }
  }else if(vA0 >= hA0 && vA1 >= hA1 && vA2 < hA2 && vA3 < hA3){
      //B B W W ┤左90
      analogWrite(11,20); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,100); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
      delay(1600);
      while(vA2 < hA2){
        delay(30);
      }
  }else if(vA0 < hA0 && vA1 < hA1 && vA2 < hA2 && vA3 < hA3){
      //w w w w
      //現在調査中　適当なプログラムを入れている
      analogWrite(11,180); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,180); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
  }else if(vA0 >= hA0 && vA1 >= hA1 && vA2 >= hA2 && vA3 >= hA3){
      //B B B B ここポイント
      if(MANKO == 0){
        analogWrite(11,180); 
        digitalWrite(6,LOW);
        digitalWrite(10,HIGH);
        analogWrite(9,180); 
        digitalWrite(5,HIGH);
        digitalWrite(8,LOW); 
        delay(2600) ;
        MANKO = 1;
      }if(MANKO == 1){ 
      analogWrite(11,50); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,170); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
      delay(3600);
      MANKO = 2;
      }else if(MANKO == 2){
        analogWrite(11,0); 
        digitalWrite(6,LOW);
        digitalWrite(10,LOW);
        analogWrite(9,0); 
        digitalWrite(5,LOW);
        digitalWrite(8,LOW);  
        delay(1000);
        MANKO = 3;
      }else if(MANKO == 3){
        analogWrite(11,180); 
        digitalWrite(6,LOW);
        digitalWrite(10,HIGH);
        analogWrite(9,180); 
        digitalWrite(5,LOW);
        digitalWrite(8,HIGH);  
        delay(1000);
        MANKO = 3;
      }else{
      }
  }else{
      delay(30);
  }
  delay(30);
}
