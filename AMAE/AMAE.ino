//右モーターは 主電源:9 順回転:5 逆回転:8  
//左モーター 主電源:11 順回転:6 逆回転:10
//vAxはセンサー　hAxは閾値 pAxはvAxのバックアップ
int vA0 = 0;
int MANKO = 0;
int TINPO = 0;
int vA1 = 500;
int vA2 = 500;
int vA3 = 0;
int hA2 = 250;
int hA1 = 250;
int hA3 = 250;
int hA0 = 250;
int pA0 = 0;
int pA1 = 0;
int pA2 = 0;
int pA3 = 0;
void setup(){
pinMode(6,OUTPUT); 
pinMode(10,OUTPUT); 
pinMode(5,OUTPUT); 
pinMode(8,OUTPUT); 
pinMode(11,OUTPUT); 
pinMode(9,OUTPUT); 
Serial.begin(9600);
delay(20000);
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
  //モーター 左11　右9
  if (vA0 < hA0 && vA1 >= hA1 && vA2 >= hA2 && vA3 < hA3){
    //0白1黒2黒3白
      analogWrite(11,100); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,120); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
  }else if(vA0 < hA0 && vA1 < hA1 && vA2 >= hA2 && vA3 < hA3){
      //W W B W 右折 
      analogWrite(11,82); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,50); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
  }else if(vA0 < hA0 && vA1 >= hA1 && vA2 >= hA2 && vA3 >= hA3){
      //W B B B ├直進
     analogWrite(11,100); 
     digitalWrite(6,HIGH);
     digitalWrite(10,LOW);
     analogWrite(9,120); 
     digitalWrite(5,HIGH);
     digitalWrite(8,LOW);
     delay(400);
     if(MANKO == 5){
      MANKO = 6;
     }
  }else if(vA0 < hA0 && vA1 < hA1 && vA2 >= hA2 && vA3 >= hA3){
      //W W B B
  }else if(vA0 < hA0 && vA1 < hA1 && vA2 < hA2 && vA3 >= hA3){
      //W W W B
  }else if(vA0 < hA0 && vA1 >= hA1 && vA2 < hA2 && vA3 < hA3){
      //w b w w 左折
      analogWrite(11,50);   
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,99); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
  }else if(vA0 >= hA0 && vA1 >= hA1 && vA2 >= hA2 && vA3 < hA3){
    //B B B W 左折90
     analogWrite(11,0); 
     digitalWrite(6,LOW);
     digitalWrite(10,LOW);
     analogWrite(9,40); 
     digitalWrite(5,HIGH);
     digitalWrite(8,LOW);
    delay(100);
     analogWrite(11,0); 
     digitalWrite(6,LOW);
     digitalWrite(10,LOW);
     analogWrite(9,0); 
     digitalWrite(5,LOW);
     digitalWrite(8,LOW);
     delay(500);
    vA3 = analogRead(A3);
    if(vA3 < hA3){
      analogWrite(11,50); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,120); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
      delay(1000);
      while(vA2 < hA2){
        vA2 = analogRead(A2);
        delay(10);
      }
    }else{
    }
    }else if(vA0 >= hA0 && vA1 >= hA1 && vA2 < hA2 && vA3 < hA3){
    //B B W W ┤
  }else if(vA0 >= hA0 && vA1 >= hA1 && vA2 >= hA2 && vA3 >= hA3){
      //B B B B ここポイント
      analogWrite(11,0); 
      digitalWrite(6,LOW);
      digitalWrite(10,LOW);
      analogWrite(9,0); 
      digitalWrite(5,LOW);
      digitalWrite(8,LOW);  
      delay(1000);
      if(MANKO == 3){
      analogWrite(11,100); 
      digitalWrite(6,LOW);
      digitalWrite(10,HIGH);
      analogWrite(9,100); 
      digitalWrite(5,LOW);
      digitalWrite(8,HIGH);
      delay(400);
      analogWrite(11,50); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,50); 
      digitalWrite(5,LOW);
      digitalWrite(8,HIGH);
      delay(600);
      while(vA2 < hA2){
        vA2 = analogRead(A2);
        delay(3);
      }
        MANKO = 4;
      }else if(MANKO == 4){ 
      analogWrite(11,60); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,90); 
      digitalWrite(5,LOW);
      digitalWrite(8,HIGH);
      delay(1600);
      while(vA1 < hA1){
        vA1 = analogRead(A1);
        delay(3);
      }
      MANKO = 5;
      }else if(MANKO == 1){ 
        analogWrite(11,100); 
        digitalWrite(6,HIGH);
        digitalWrite(10,LOW);
        analogWrite(9,120); 
        digitalWrite(5,HIGH);
        digitalWrite(8,LOW);  
        delay(500);
        MANKO = 2;
      }else if(MANKO == 2){
        analogWrite(11,30); 
        digitalWrite(6,LOW);
        digitalWrite(10,HIGH);
        analogWrite(9,30); 
        digitalWrite(5,LOW);
        digitalWrite(8,HIGH);  
        delay(2000);
        analogWrite(11,100); 
        digitalWrite(6,HIGH);
        digitalWrite(10,LOW);
        analogWrite(9,120); 
        digitalWrite(5,HIGH);
        digitalWrite(8,LOW);  
        delay(1200);
        MANKO = 3;
      }else if(MANKO == 0){
      analogWrite(11,100); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,120); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
      delay(400);
        MANKO = 1;
      }else if(MANKO == 5){
      analogWrite(11,100); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,120); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
      delay(400);
        MANKO = 6;
      }else if(MANKO == 6){ 
      analogWrite(11,0); 
      digitalWrite(6,LOW);
      digitalWrite(10,LOW);
      analogWrite(9,0); 
      digitalWrite(5,LOW);
      digitalWrite(8,LOW);
      delay(10000000);
      }else{
      }
  }else if(vA0 < hA0 && vA1 < hA1 && vA2 < hA2 && vA3 < hA3){
      //W W W W
      if(pA1 < hA1 && pA2 >= hA2){
      //右折 
      analogWrite(11,100); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,50); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
      }else if(pA1 >= hA1 && pA2 < hA2){
      //左折 
      analogWrite(11,50); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,120); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
      }else{
      }
  }
  delay(3);
  pA0 = analogRead(A0);
  pA1 = analogRead(A1);
  pA2 = analogRead(A2);
  pA3 = analogRead(A3);
}