//前進し続ける
int vA0 = 0;
int MANKO = 0;
int TINPO = 0;
int vA1 = 0;
int vA2 = 0;
int vA3 = 0;
int hA2 = 600;
int hA1 = 600;
int hA3 = 600;
int hA0 = 600;
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
  //モーター 左11　右9
     analogWrite(11,100); 
     digitalWrite(6,HIGH);
     digitalWrite(10,LOW);
     analogWrite(9,120); 
     digitalWrite(5,HIGH);
     digitalWrite(8,LOW);
     delay(3000);
}
