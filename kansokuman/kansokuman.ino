//右モーターは 主電源:9 順回転:5 逆回転:8  
//左モーター 主電源:11 順回転:6 逆回転:10
//vAxはセンサー　hAxは閾値
int vA0 = 0;
int MANKO = 0;
int TINPO = 0;
int vA1 = 500;
int vA2 = 500;
int vA3 = 0;
int hA2 = 350;
int hA1 = 350;
int hA3 = 350;
int hA0 = 350;
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
  if (vA0 >= hA0 && vA1 >= hA1 && vA2 >= hA2 && vA3 >= hA3){
      analogWrite(11,240); 
     digitalWrite(6,HIGH);
     digitalWrite(10,LOW);
     analogWrite(9,240); 
     digitalWrite(5,HIGH);
     digitalWrite(8,LOW);
     delay(300);
  }
}