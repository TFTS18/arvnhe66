//4センサー 未完成 if文大量に書く8
//閾値は後で変える
//モーター 右は9 左はmotAB
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
vA0 = 10 - analogRead(A0);
Serial.print(vA0);
delay(1000);
}