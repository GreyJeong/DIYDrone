#include <Wire.h>
#define Baro1
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

#define ACC_ORIENTATION(X, Y, Z)  {imu.accADC[ROLL]  = -X; imu.accADC[PITCH]  = -Y; imu.accADC[YAW]  =  Z;}
#define GYRO_ORIENTATION(X, Y, Z) {imu.gyroADC[ROLL] =  Y; imu.gyroADC[PITCH] = -X; imu.gyroADC[YAW] = -Z;}
#define MAG_ORIENTATION(X, Y, Z)  {imu.magADC[ROLL]  =  X; imu.magADC[PITCH]  =  Y; imu.magADC[YAW]  = -Z;}

/*
 * setup()
 * 드론에 부착된 디바이스를 초기화하는 모든 함수를 호출.
 * Speaker, Motor, Bluetooth Module
 */
int16_t roll;
int16_t pitch;
float currenttime = 0;
float presenttime = 0;
float dtime = 0;
int main_switch = 0;
int initMotorValue = 10;
int initMotorSwitch = 0;
float control_value[4] = { 0, 0, 0, 0 };
int i;

void setup()
{
  bluetooth_initialize();
  speaker_initialize();
  motor_initialize();
  initS();
  Serial.begin(9600);
}

/*
 * loop() 
 * 드론 비행에 필요한 메인 로직이 반복 호출되는 함수
 * 
 */
void loop()
{
	char command = getCommand();
	int16_t dt;

	currentTime = micros();
	cycleTime = currentTime - previousTime;
	previousTime = currentTime;
	ACC_getADC();
	Gyro_getADC();
	Device_Mag_getADC();
	getEstimatedAttitude();
#if defined (Baro1)
	Baro_update();
	getEstimatedAltitude();
#endif
	dt = (micros() - currentTime) / 1000000;
	
	rpyAngle[ROLL] = getrollangle(imu.accADC[PITCH], imu.accADC[YAW], imu.gyroADC[PITCH], dt);
	rpyAngle[PITCH] = getpitchangle(imu.accADC[ROLL], imu.accADC[YAW], imu.gyroADC[ROLL],dt);
	presenttime = micros();  
  getPID2();

  switch(command) {
    case START :
      main_switch = 1;
	  initMotorSwitch = 1;
      break;

    case EXIT : 
      main_switch = 2;
      break;
    }

 if(main_switch == 1) {
	 if (initMotorSwitch = 1)
	 {
		 for (i = 0; i < 4; i++)
		 {
			 control_value[i] = initMotorValue;
		 }
		 initMotorSwitch = 0;
	 }
	 
		 control_value[0] = control_value[0] + axisPID[ROLL] + axisPID[PITCH];
		 control_value[1] = control_value[1] - axisPID[ROLL] + axisPID[PITCH];
		 control_value[2] = control_value[2] - axisPID[ROLL] - axisPID[PITCH];
		 control_value[3] = control_value[3] + axisPID[ROLL] - axisPID[PITCH];

		 for (i = 0; i < 4; i++)
		 {
			 constrain(control_value[i], 10, 100);
		 }

		  motor1_write(control_value[0]);
		  motor2_write(control_value[1]);
		  motor3_write(control_value[2]);
		  motor4_write(control_value[3]);
 }
 else if(main_switch == 2) {
    motor_all_stop();
    main_switch = 0;
  }
 
  
//  Serial.println(presenttime - currentTime);
   /* Serial.print("PID : ");
    Serial.print(axisPID[ROLL]);
    Serial.print(" ");
    Serial.print(axisPID[PITCH]);
    Serial.print(" rollangle: ");
    Serial.print(rpyAngle[ROLL]);

    Serial.print(" pitchangle: ");
    Serial.print(rpyAngle[PITCH]);

    Serial.print("\t heading :");
    Serial.print(att.heading);  
    Serial.print("\t alt :");
    Serial.print(alt.EstAlt);
    Serial.print("\t vel :");
    Serial.print(alt.vario);
    Serial.print("\t BaroPID :");
    Serial.print(BaroPID);
    Serial.println("");*/
  
}
