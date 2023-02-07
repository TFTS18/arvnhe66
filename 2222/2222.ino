//モーター 右は9 左はmotAB
//vAxはセンサー　hAxは閾値
int vA0 = 0;
int TINPO = 0;
int vA1 = 0;
int vA2 = 0;
int vA3 = 0;
int hA2= 300;
int hA1 = 300;
void setup(){
pinMode(11,OUTPUT); 
pinMode(10,OUTPUT); 
pinMode(5,OUTPUT); 
pinMode(8,OUTPUT); 
pinMode(13,OUTPUT);
pinMode(6,OUTPUT); 
pinMode(9,OUTPUT); 
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
    analogWrite(6,235); 
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    analogWrite(9,180); 
    digitalWrite(5,HIGH);
    digitalWrite(8,LOW);
  }else if(vA1 < hA1 && vA2 >= hA2){
    //左が黒、右が白ならに右へ旋回
    analogWrite(6,235); 
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    analogWrite(9,0); 
    digitalWrite(5,HIGH);
    digitalWrite(8,LOW);
  }else if(vA1 >= hA1 && vA2 < hA2){
    //左が白、右が黒ならに左へ旋回
    analogWrite(6,0);   
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    analogWrite(9,180); 
    digitalWrite(5,HIGH);
    digitalWrite(8,LOW);
  }else if(vA1 < hA1 && vA2 < hA2){
    //療法白直進
    analogWrite(6,235); 
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    analogWrite(9,180); 
    digitalWrite(5,HIGH);
    digitalWrite(8,LOW);
  }else{
  }
    delay(20);
    analogWrite(6,235); 
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    analogWrite(9,180); 
    digitalWrite(5,HIGH);
    digitalWrite(8,LOW);
    delay(20);
}
