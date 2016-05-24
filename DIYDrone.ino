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
  speaker_initialize();
  motor_initialize();
  //Serial.begin(9600);
}

/*
 * loop() 
 * 드론 비행에 필요한 메인 로직이 반복 호출되는 함수
 * 
 */
void loop()
{
   volatile char command = getCommand();
    
    switch(command)
    {
      case START : 
        motor_up();
        break;
        
      case EXIT :
        motor_down();
        break;

        case '3' :
        motor_up3();
        break;
        case '5' :
        motor_up5();
        break;
        case '9' :
        motor_up9();
        break;
        case '0' :
        motor_up10();
        break;
        
    }
    
}
