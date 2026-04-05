#include <ESP32Servo.h>

const int SVnum = 7;0000
Servo Servos[SVnum];
int Inpin[int(SVnum*2)]={
   5,18, 19,21, 22,23, 13,12, 27,14, 26,25, 35,34
// 左上   左裏   左下   右上   右裏   右下   中央下
};
int Outpin[SVnum]={
  15, 2, 4,16,17,32,33
// 1  2  3  4  5  6  7
};

int Inval[int(SVnum*2)];
int Angles[SVnum]={
  180,0,180,180,0,0,0
};

int calc(int val1, int val2, int angle){
  int next=angle;
  if(val1==HIGH && val2==LOW && angle<180){
    next+=1;
  }else if(val2==HIGH && val1==LOW && angle>0){
    next-=1;
  }
  return next;
}

int calc_(int val1, int val2, int angle){
  int next=angle;
  if(val1==LOW && val2==HIGH && angle<180){
    next+=1;
  }else if(val2==LOW && val1==HIGH && angle>0){
    next-=1;
  }
  return next;
}

void setup(){
  for(int n=0;n<int(SVnum*2);n++){
    if(Inpin[n]==34 || Inpin[n]==35){
      pinMode(Inpin[n],INPUT);
    }else{
      pinMode(Inpin[n],INPUT_PULLUP);
    }
  }
  for(int m=0;m<SVnum;m++){
    Servos[m].setPeriodHertz(50);
    Servos[m].attach(Outpin[m],500,2400);
  }
}

void loop(){
  for(int n=0;n<int(SVnum*2);n++){
    Inval[n]=digitalRead(Inpin[n]);
  }
  for(int m=0;m<SVnum;m++){
    if(Inpin[m]==34 || Inpin[m]==35){
      Angles[m]=calc_(Inval[int(m*2)],Inval[int(m*2+1)],Angles[m]);
    }else{
      Angles[m]=calc(Inval[int(m*2)],Inval[int(m*2+1)],Angles[m]);
    }
    Servos[m].write(Angles[m]);
  }
  delay(10);
}
