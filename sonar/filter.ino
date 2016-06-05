#define CRITERION 20

void CAS_setup() {
  Serial.begin(9600);
  sonar_init();
}

void CAS_loop() {
  int way = 5;
  //int state = 0; // 기준거리 이상 = 0, 기준거리 = 1, 기준거리 이하 = 2
  double front_data=0, right_data=0, back_data=0, left_data =0;
  
  front_data = sonar_front();
  right_data = sonar_right();
  back_data = sonar_back();
  left_data = sonar_left();

  double sensor_data[4] = {front_data, right_data, back_data, left_data};
  int cas_state[4] = {0};
  /* sensor_data[i], 0-4 is front, right, back, left, upside*/ 
  
  for(int i = 0; i < 4; i++){
    if(sensor_data[i] < CRITERION){
      way = i;
      cas_state[i] = 2;
    }
    else if((sensor_data[i] >= CRITERION) && (sensor_data[i] < CRITERION+3)){
      way = i;
      cas_state[i] = 1;
    }
    else{
      cas_state[i] = 0;
    }
  }

  switch(way){
    case 0:
      if(cas_state[0] == 1){
        Serial.println("front stop");
        //stop(hovering)
      }
      else if(cas_state[0] == 2){
        Serial.println("back");
        //back
      }
      break;
    case 1:
      if(cas_state[1] == 1){
        Serial.println("right stop");
        //stop(hovering)
      }
      else if(cas_state[1] == 2){
        Serial.println("left");
        //left
      }
      break;    
    case 2:
      if(cas_state[2] == 1){
        Serial.println("back stop");
        //stop(hovering)
      }
      else if(cas_state[2] == 2){
        Serial.println("go");
        //go straight
      }
      break;    
    case 3:
      if(cas_state[3] == 1){
        Serial.println("left stop");
        //stop(hovering)
      }
      else if(cas_state[3] == 2){
        Serial.println("right stop");
        //right
      }
      break;
  }
}
