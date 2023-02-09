//右モーターは 主電源:9 順回転:5 逆回転:8  
//左モーター 主電源:11 順回転:6 逆回転:10
//vAxはセンサー　hAxは閾値
int vA0 = 0;
int MANKO = 0;
int TINPO = 0;
int vA1 = 500;
int vA2 = 500;
int vA3 = 0;
int hA2 = 279;
int hA1 = 279;
int hA3 = 279;
int hA0 = 279;
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
     analogWrite(11,120); 
     digitalWrite(6,HIGH);
     digitalWrite(10,LOW);
     analogWrite(9,120); 
     digitalWrite(5,HIGH);
     digitalWrite(8,LOW);
     delay(20);
  }else if(vA0 < hA0 && vA1 < hA1 && vA2 >= hA2 && vA3 < hA3){
      //W W B W 右折 
      analogWrite(11,120); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,60); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
      delay(10);
  }else if(vA0 < hA0 && vA1 >= hA1 && vA2 >= hA2 && vA3 >= hA3){
      //W B B B ├停止直進
     analogWrite(11,100); 
     digitalWrite(6,HIGH);
     digitalWrite(10,LOW);
     analogWrite(9,100); 
     digitalWrite(5,HIGH);
     digitalWrite(8,LOW);
     delay(200);
  }else if(vA0 < hA0 && vA1 < hA1 && vA2 >= hA2 && vA3 >= hA3){
      //W W B B ├停止直進
     analogWrite(11,240); 
     digitalWrite(6,HIGH);
     digitalWrite(10,LOW);
     analogWrite(9,240); 
     digitalWrite(5,HIGH);
     digitalWrite(8,LOW);
     delay(300);
  }else if(vA0 < hA0 && vA1 >= hA1 && vA2 < hA2 && vA3 < hA3){
      //w b w w 左折
      analogWrite(11,55);   
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,120); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
      delay(10);
  }else if(vA0 >= hA0 && vA1 >= hA1 && vA2 >= hA2 && vA3 < hA3){
    //B B B W ┤左90
     analogWrite(11,40); 
     digitalWrite(6,HIGH);
     digitalWrite(10,LOW);
     analogWrite(9,40); 
     digitalWrite(5,HIGH);
     digitalWrite(8,LOW);
     delay(80);
     analogWrite(11,0); 
     digitalWrite(6,LOW);
     digitalWrite(10,LOW);
     analogWrite(9,40); 
     digitalWrite(5,HIGH);
     digitalWrite(8,LOW);;
    delay(100);
     analogWrite(11,0); 
     digitalWrite(6,LOW);
     digitalWrite(10,LOW);
     analogWrite(9,0); 
     digitalWrite(5,LOW);
     digitalWrite(8,LOW);
     delay(1000);
    vA3 = analogRead(A3);
    if(vA3 < hA3){
      analogWrite(11,45); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,130); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
      delay(1000);
      while(vA2 < hA2){
        vA2 = analogRead(A2);
        delay(10);
      }
    }else{
      analogWrite(11,70); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,40); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
      delay(1000);
    }
  }else if(vA0 >= hA0 && vA1 >= hA1 && vA2 < hA2 && vA3 < hA3){
      //B B W W ┤左90
     analogWrite(11,40); 
     digitalWrite(6,HIGH);
     digitalWrite(10,LOW);
     analogWrite(9,40); 
     digitalWrite(5,HIGH);
     digitalWrite(8,LOW);
     delay(80);
     analogWrite(11,0); 
     digitalWrite(6,LOW);
     digitalWrite(10,LOW);
     analogWrite(9,40); 
     digitalWrite(5,HIGH);
     digitalWrite(8,LOW);;
    delay(100);
     analogWrite(11,0); 
     digitalWrite(6,LOW);
     digitalWrite(10,LOW);
     analogWrite(9,0); 
     digitalWrite(5,LOW);
     digitalWrite(8,LOW);
     delay(1000);
    if(vA3 < hA3){
      analogWrite(11,45); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,130); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
      delay(1000);
      while(vA2 < hA2){
        vA2 = analogRead(A2);
        delay(10);
      }
    }else{
      analogWrite(11,70); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,40); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
      delay(1000);
    }
  }else if(vA0 >= hA0 && vA1 >= hA1 && vA2 >= hA2 && vA3 >= hA3){
      //B B B B ここポイント
      if(MANKO == 3){
      analogWrite(11,100); 
      digitalWrite(6,LOW);
      digitalWrite(10,HIGH);
      analogWrite(9,100); 
      digitalWrite(5,LOW);
      digitalWrite(8,HIGH);
      delay(1100);
      analogWrite(11,120); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,120); 
      digitalWrite(5,LOW);
      digitalWrite(8,HIGH);
      delay(2400);
      while(vA2 < hA2){
        vA2 = analogRead(A2);
        delay(5);
      }
        MANKO = 4;
      }if(MANKO == 4){ 
      analogWrite(11,40); 
      digitalWrite(6,HIGH);
      digitalWrite(10,LOW);
      analogWrite(9,75); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
      delay(1600);
      while(vA1 < hA1){
        vA1 = analogRead(A1);
        delay(20);
      }
      MANKO = 5;
      }if(MANKO == 1){ 
        analogWrite(11,0); 
        digitalWrite(6,LOW);
        digitalWrite(10,LOW);
        analogWrite(9,0); 
        digitalWrite(5,LOW);
        digitalWrite(8,LOW);  
        delay(1000);
        analogWrite(11,220); 
        digitalWrite(6,HIGH);
        digitalWrite(10,LOW);
        analogWrite(9,220); 
        digitalWrite(5,HIGH);
        digitalWrite(8,LOW);  
        delay(500);
        MANKO = 2;
      }else if(MANKO == 2){
        analogWrite(11,0); 
        digitalWrite(6,LOW);
        digitalWrite(10,LOW);
        analogWrite(9,0); 
        digitalWrite(5,LOW);
        digitalWrite(8,LOW);  
        delay(1000);
        analogWrite(11,220); 
        digitalWrite(6,HIGH);
        digitalWrite(10,LOW);
        analogWrite(9,160); 
        digitalWrite(5,HIGH);
        digitalWrite(8,LOW);  
        delay(2000);
        MANKO = 3;
      }else if(MANKO == 0){
        analogWrite(11,240); 
        digitalWrite(6,HIGH);
        digitalWrite(10,LOW);
        analogWrite(9,240); 
        digitalWrite(5,HIGH);
        digitalWrite(8,LOW);  
        delay(300);
        MANKO = 1;
      }else if(MANKO == 5){ 
      analogWrite(11,94); 
      digitalWrite(6,LOW);
      digitalWrite(10,HIGH);
      analogWrite(9,99); 
      digitalWrite(5,HIGH);
      digitalWrite(8,LOW);
      delay(10000);
      MANKO = 0;
      }else{
      }
      }else{
      delay(10);
  }
  delay(5);
}
