#include <ESP32Servo.h>

Servo servo1;
Servo servo2;//

int In1=5;
int In2=18;

int In3=19;
int In4=21;
int In5=22;
int In6=23;
int In7=13;
int In8=12;
int In9=35;//
int In10=34;//

int Out1=15;
int Out2=2;
int Out3=4;
int Out4=16;
int Out5=17;
int Out6=32;
int Out7=33;
int Out8=26;//

int val1;
int val2;
int val3;
int val4;
int val5;
int val6;
int val7;
int val8;
int val9;//
int val10;//

int angle1=180;
int angle2=0;//

void setup() {
  // put your setup code here, to run once:
  pinMode(In1,INPUT_PULLUP);
  pinMode(In2,INPUT_PULLUP);

  pinMode(In3,INPUT_PULLUP);
  pinMode(In4,INPUT_PULLUP);
  pinMode(In5,INPUT_PULLUP);
  pinMode(In6,INPUT_PULLUP);
  pinMode(In7,INPUT_PULLUP);
  pinMode(In8,INPUT_PULLUP);
  pinMode(In9,INPUT);//
  pinMode(In10,INPUT);//
  
  servo1.setPeriodHertz(50);
  servo1.attach(Out1,500,2400);

  ledcAttach(Out2,12800,8);
  ledcAttach(Out3,12800,8);

  ledcAttach(Out4,12800,8);
  ledcAttach(Out5,12800,8);

  ledcAttach(Out6,12800,8);
  ledcAttach(Out7,12800,8);

  servo2.setPeriodHertz(50);//
  servo2.attach(Out8,500,2400);//
}

void loop() {
  val1=digitalRead(In1);
  val2=digitalRead(In2);
  
  val3=digitalRead(In3);
  val4=digitalRead(In4);
  val5=digitalRead(In5);
  val6=digitalRead(In6);
  val7=digitalRead(In7);
  val8=digitalRead(In8);
  val9=digitalRead(In9);//
  val10=digitalRead(In10);//

  servo1.write(angle1);
  servo2.write(angle2);//
  delay(10);

  if (val1==HIGH && val2==LOW && angle1<180){
    angle1+=1;
  }
  else if (val1==LOW && val2==HIGH && angle1>0){
    angle1-=1;
  }

  if (val3==HIGH && val4==LOW){
    ledcWrite(Out2,50);
    ledcWrite(Out3,0);
  }
  else if (val3==LOW && val4==HIGH){
    ledcWrite(Out2,0);
    ledcWrite(Out3,50);
  }
  else{
    ledcWrite(Out2,0);
    ledcWrite(Out3,0);
  }

  if (val5==HIGH && val6==LOW){
    ledcWrite(Out4,150);
    ledcWrite(Out5,0);
  }
  else if (val5==LOW && val6==HIGH){
    ledcWrite(Out4,0);
    ledcWrite(Out5,150);
  }
  else{
    ledcWrite(Out4,0);
    ledcWrite(Out5,0);
  }

  if (val7==HIGH && val8==LOW){
    ledcWrite(Out6,100);
    ledcWrite(Out7,0);
  }
  else if (val7==LOW && val8==HIGH){
    ledcWrite(Out6,0);
    ledcWrite(Out7,250);
  }
  else{
    ledcWrite(Out6,0);
    ledcWrite(Out7,0);
  }
  ///
  if (val9==LOW && val10==HIGH && angle2<180){
    angle2+=1;
  }
  else if (val9==HIGH && val10==LOW && angle2>0){
    angle2-=1;
  }
  ///
/*
  if (val1==HIGH && val2==LOW && angle1<180){
    angle1+=1;
  }
  else if (val1==LOW && val2==HIGH && angle1>0){
    angle1-=1;
  }
*/

}
