//モーター 右はPWM_motCD 左はmotAB
//vAxはセンサー　hAxは閾値
int vA0 = 0;
int TINPO = 0;
int vA1 = 0;
int vA2 = 0;
int vA3 = 0;
const int motorA = 11;
const int motorB = 111;
const int PWM_motAB = 6;
const int motorC = 9;
const int motorD = 8;
const int PWM_motCD = 5;
int hA2= 500;
int hA1 = 500;
int jeiejefi = 0;
void setup(){
pinMode(motorA,OUTPUT); 
pinMode(motorB,OUTPUT); 
pinMode(motorC,OUTPUT); 
pinMode(motorD,OUTPUT); 
pinMode(13,OUTPUT);
pinMode(PWM_motAB,OUTPUT); 
pinMode(PWM_motCD,OUTPUT); 
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
  vA0 = analogRead(A0);
  vA1 = analogRead(A1);
  vA2 = analogRead(A2);
  vA3 = analogRead(A3);
  //モーター 右AB左CD
  if (vA1 < hA1 && vA2 < hA2){
    //左、右ともに白なら直進
    digitalWrite(motorA,LOW);
    digitalWrite(motorB,LOW);
    digitalWrite(motorC,LOW);
    digitalWrite(motorD,LOW);
  }else if(vA1 > hA1 && vA2 <= hA2){
    //左が黒、右が白ならに左へ旋回
    digitalWrite(motorA,LOW);
    digitalWrite(motorB,LOW);
    digitalWrite(motorC,LOW);
    digitalWrite(motorD,LOW);   
  }else if(vA1 <= hA1 && vA2 > hA2){
    //左が白、右が黒ならに右へ旋回
    digitalWrite(motorA,LOW);
    digitalWrite(motorB,LOW);
    digitalWrite(motorC,LOW);
    digitalWrite(motorD,LOW);
  }else if(vA1 >= hA1 && vA2 >= hA2){
    digitalWrite(motorA,LOW);
    digitalWrite(motorB,LOW);
    digitalWrite(motorC,LOW);
    digitalWrite(motorD,LOW);  }
    delay(50);
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
}
