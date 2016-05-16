#include <SoftwareSerial.h>
#include "Arduino.h"
#include "i2c.h"
#include "string.h"


/*
 * Command Define 
 * Bluetooth로 전송된 명령어에 대한 define
 */
 #define START  's'
 #define EXIT   'x'
 #define GOOD   'g'
 #define ERROR1 '1'
 #define ERROR2 '2'
 #define ERROR3 '3'


 
/*
 * setup()
 * 드론에 부착된 디바이스를 초기화하는 모든 함수를 호출.
 * Speaker, Motor, Bluetooth Module
 */
void setup()
{
  bluetooth_initialize();
  motor_initialize();
  speaker_initialize();
 
 // i2c_initialize();
  
}

/*
 * loop() 
 * 드론 비행에 필요한 메인 로직이 반복 호출되는 함수
 * 
 */
void loop()
{
  int index=1;
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
    char command = getCommand();
    switch(command)
    {
      case START : 
        //speaker_activate(START);
        motor_write1(index);
        motor_write2(index);
        motor_write3(index);
        motor_write4(index);
        index++;
        break;
        
      case EXIT :
        //speaker_activate(EXIT);
        motor_write1(0);
        motor_write2(0);
        motor_write3(0);
        motor_write4(0);
        break;
    }
}
