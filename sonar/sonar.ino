#define ECHO1 7
#define TRIG1 9
#define ECHO2 6
#define TRIG2 8
#define ECHO3 5
#define TRIG3 10
#define ECHO4 4
#define TRIG4 11

#define SIZE 50
double preDistance = 0;
float alpha = 0.7;

void sonar_init()
{
  pinMode(ECHO1,INPUT);
  pinMode(TRIG1,OUTPUT);
  pinMode(ECHO2,INPUT);
  pinMode(TRIG2,OUTPUT);
  pinMode(ECHO3,INPUT);
  pinMode(TRIG3,OUTPUT);
  pinMode(ECHO4,INPUT);
  pinMode(TRIG4,OUTPUT);

  float sum = 0;
  float duration, Cm;
  float buffer[SIZE];
  for(int i = 0; i < SIZE; i++)
  {
    digitalWrite(TRIG1,HIGH);
    delayMicroseconds(2);
    digitalWrite(TRIG1,LOW);
    duration = pulseIn(ECHO1,HIGH);
    Cm = duration/(29.1*2);
    
    if(Cm > 400) Cm = 400;
    else if(Cm < 2) Cm = 2;
    
    buffer[i] = Cm;
    sum += buffer[i];     
  }
  preDistance = sum/SIZE;
}

double sonar_front()
{
  double front_data=0;
  long echo_time_us =0;
  float cm0;
  
  digitalWrite(TRIG1,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG1,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG1,LOW);
  echo_time_us = pulseIn(ECHO1,HIGH);
  cm0 = (double)echo_time_us/(double)58;
    
  front_data = alpha * preDistance + (1 - alpha) * cm0;  
  if(front_data > 400) front_data = 400;
  else if(front_data< 2) front_data = 2;
  
  delay(5);
  return front_data;
}

double sonar_right()
{
  double right_data=0;
  long echo_time_us =0;
  float cm1;

  digitalWrite(TRIG2,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG2,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG2,LOW);
  echo_time_us = pulseIn(ECHO2,HIGH);
  cm1 = (double)echo_time_us/(double)58;

  right_data = alpha * preDistance + (1 - alpha) * cm1;  
  if(right_data > 400) right_data = 400;
  else if(right_data < 2) right_data = 2;
  
  delay(5);
   return right_data;
}

double sonar_back()
{
  double back_data=0;
  long echo_time_us =0;  
  float cm2;
  
  digitalWrite(TRIG3,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG3,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG3,LOW);
  echo_time_us = pulseIn(ECHO3,HIGH);
  cm2 = (double)echo_time_us/(double)58;

  back_data = alpha * preDistance + (1 - alpha) * cm2;  
  if(back_data > 400) back_data = 400;
  else if(back_data < 2) back_data = 2;
  
  delay(100);
  return back_data;  
}

double sonar_left()
{
  double left_data=0;
  long echo_time_us =0;  
  float cm3;
    
  digitalWrite(TRIG4,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG4,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG4,LOW);
  echo_time_us = pulseIn(ECHO4,HIGH);
  cm3 = (double)echo_time_us/(double)58;

  left_data = alpha * preDistance + (1 - alpha) * cm3;  
  if(left_data > 400) left_data = 400;
  else if(left_data < 2) left_data = 2;
  
  delay(100);
  return left_data;    
}

/* /////////////////////////////////////////////
double sonar_up()
{
   double up_data=0;
  long echo_time_us =0;  
    
  digitalWrite(TRIG5,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG5,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG5,LOW);
  echo_time_us = pulseIn(ECHO5,HIGH);
  up_data = (double)echo_time_us/(double)58;

  left_data = alpha * preDistance + (1 - alpha) * cm3;  
  if(left_data > 400) left_data = 400;
  else if(left_data < 2) left_data = 2;

  delay(100);
  return up_data;
}
///////////////////////////////////////////////*/




