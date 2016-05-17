#include <SoftwareSerial.h>
#include "Arduino.h"
#include "i2c.h"


/*
 * Command Define 
 * Bluetooth로 전송된 명령어에 대한 define
 */
 #define START 1
 #define EXIT  2

char c;
 
/*
 * setup()
 * 드론에 부착된 디바이스를 초기화하는 모든 함수를 호출.
 * Speaker, Motor, Bluetooth Module
 */
void setup()
{
  bluetooth_initialize();
  Serial.begin(115200);
  speaker_initialize();
  motor_initialize();
  i2c_initialize();
  
}

/*
 * loop() 
 * 드론 비행에 필요한 메인 로직이 반복 호출되는 함수
 * 
 */
void loop()
{
  c = Serial.read();
  
  if(c == 'u')
  {
    motor_up();
  }else if(c == 'd')
  {
    motor_down();
  }
    /* Example Main Logic
     * if(bluetooth.available())
    {
        int command = bluetooth.read();

        switch(command){

          case START :
              speaker_activate(START);
              motor_activate(START);
              break;

          case EXIT :
              speaker_activate(EXIT);
              motor_activate(EXIT);
          }
    }*/
}
