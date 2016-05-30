////#define Baro1
#include <SoftwareSerial.h>
#include "Arduino.h"
//#include "i2c.h"
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
//
//#define ACC_ORIENTATION(X, Y, Z)  {imu.accADC[ROLL]  = -X; imu.accADC[PITCH]  = -Y; imu.accADC[YAW]  =  Z;}
//#define GYRO_ORIENTATION(X, Y, Z) {imu.gyroADC[ROLL] =  Y; imu.gyroADC[PITCH] = -X; imu.gyroADC[YAW] = -Z;}
//#define MAG_ORIENTATION(X, Y, Z)  {imu.magADC[ROLL]  =  X; imu.magADC[PITCH]  =  Y; imu.magADC[YAW]  = -Z;}
//
///*
// * setup()
// * 드론에 부착된 디바이스를 초기화하는 모든 함수를 호출.
// * Speaker, Motor, Bluetooth Module
// */
//int16_t roll;
//int16_t pitch;
//float currenttime = 0;
//float presenttime = 0;
//float dtime = 0;
//void setup()
//{
//  bluetooth_initialize();
//  speaker_initialize();
//  motor_initialize();
//  initS();
//  Serial.begin(9600);
//}
//
///*
// * loop() 
// * 드론 비행에 필요한 메인 로직이 반복 호출되는 함수
// * 
// */
//void loop()
//{
//  char command = getCommand();
//
//  currentTime = micros();
//  cycleTime = currentTime - previousTime;
//  previousTime = currentTime;
//  ACC_getADC();
//  Gyro_getADC();
//  Device_Mag_getADC();
//  getEstimatedAttitude();
//  computeIMU();
//#if defined (Baro1)
//  Baro_update();
//  getEstimatedAltitude();
//#endif
//
////  getPID();
//  presenttime = micros();  
//  roll = att.angle[ROLL];
//  pitch = att.angle[PITCH];
////  motor1_write(50 - pitch);
////  motor2_write(50 - pitch);
////  motor3_write(50 + pitch);
////  motor4_write(30 - pitch);
////  Serial.println(presenttime - currentTime);
//  Serial.print(roll);
//  Serial.print('\t');
//  Serial.print(pitch);
//  Serial.print('\n');  
//  
////  switch(command)
////  {
////    
////  case START : 
////    motor_up();
////    break;
////    
////  case EXIT :
////    motor_down();
////    break;
////
////    case '3' :
////    motor_up3();
////    break;
////    case '5' :
////    motor_up5();
////    break;
////    case '9' :
////    motor_up9();
////    break;
////    case '0' :
////      motor_up10();
////    break;
////      
////  }
//  
//}
