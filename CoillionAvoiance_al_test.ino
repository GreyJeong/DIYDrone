#define CRITERION 20

#define ECHO1 7
#define TRIG1 9
#define ECHO2 6
#define TRIG2 8
#define ECHO3 5
#define TRIG3 10
#define ECHO4 4
#define TRIG4 11


void setup() {
  Serial.begin(9600);
  pinMode(ECHO1,INPUT);
  pinMode(TRIG1,OUTPUT);
  pinMode(ECHO2,INPUT);
  pinMode(TRIG2,OUTPUT);
  pinMode(ECHO3,INPUT);
  pinMode(TRIG3,OUTPUT);
  pinMode(ECHO4,INPUT);
  pinMode(TRIG4,OUTPUT);
}

void loop() {
  int way = 5;
  int state = 0; // 기준거리 이상 = 0, 기준거리 = 1, 기준거리 이하 = 2
  double front_data=0, right_data=0, back_data=0, left_data =0;
  long echo_time_us =0;

  digitalWrite(TRIG1,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG1,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG1,LOW);
  echo_time_us = pulseIn(ECHO1,HIGH);
  front_data = (double)echo_time_us/(double)58;
  delay(100);
    
  digitalWrite(TRIG2,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG2,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG2,LOW);
  echo_time_us = pulseIn(ECHO2,HIGH);
  right_data = (double)echo_time_us/(double)58;
  delay(100);

  digitalWrite(TRIG3,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG3,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG3,LOW);
  echo_time_us = pulseIn(ECHO3,HIGH);
  back_data = (double)echo_time_us/(double)58;
  delay(100);

  digitalWrite(TRIG4,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG4,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG4,LOW);
  echo_time_us = pulseIn(ECHO4,HIGH);
  left_data = (double)echo_time_us/(double)58;
  delay(100);
  
  double sensor_data[4] = {front_data, right_data, back_data, left_data};
  int state[4] = {0};
  /* sensor_data[i], 0-4 is front, right, back, left, upside*/ 
  
  for(int i=0; i < 4; i++){
    if( sensor_data[i] < CRITERION){
      way = i;
      state[i] = 2;
    }
    else if((sensor_data[i] >= CRITERION) && (sensor_data[i] < CRITERION+1)){
      way = i;
      state[i] = 1;
    }
    else{
      state[i] = 0;
    }
  }

  switch(way){
    case 0:
      if(state[0] == 1){
        Serial.println("front stop");
        //stop(hovering)
      }
      else if(state[0] == 2){
        Serial.println("back");
        //back
      }
      break;
    case 1:
      if(state[1] == 1){
        Serial.println("right stop");
        //stop(hovering)
      }
      else if(state[1] == 2){
        Serial.println("left");
        //left
      }
      break;    
    case 2:
      if(state[2] == 1){
        Serial.println("back stop");
        //stop(hovering)
      }
      else if(state[2] == 2){
        Serial.println("go");
        //go straight
      }
      break;    
    case 3:
      if(state[3] == 1){
        Serial.println("left stop");
        //stop(hovering)
      }
      else if(state[3] == 2){
        Serial.println("right stop");
        //right
      }
      break; 
    /* /////////////////////////////////
    case 4;
      if(state[4] == 1){
        //stop(hovering)
      }
      else(state[4] == 2){
        //upside
      }
      break;
      /////////////////////////////////// */  
  }
}
