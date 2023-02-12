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
}

void loop() {
        analogWrite(11,80); 
        digitalWrite(6,LOW);
        digitalWrite(10,HIGH);
        analogWrite(9,80); 
        digitalWrite(5,LOW);
        digitalWrite(8,HIGH);  
        delay(2000);
        digitalWrite(10,LOW);
        digitalWrite(8,LOW); 
        delay(400); 
        analogWrite(11,100); 
        digitalWrite(6,HIGH);
        digitalWrite(10,LOW);
        analogWrite(9,120); 
        digitalWrite(5,HIGH);
        digitalWrite(8,LOW);  
        delay(2000);

}