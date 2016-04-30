#include "Arduino.h"
#include "i2c.h"

void setup()
{
	Serial.begin(9600);
	initS();
  /* add setup code here */

}

void loop()
{
#define ACC_ORIENTATION(X, Y, Z)  {imu.accADC[ROLL]  = -X; imu.accADC[PITCH]  = -Y; imu.accADC[YAW]  =  Z;}
#define GYRO_ORIENTATION(X, Y, Z) {imu.gyroADC[ROLL] =  Y; imu.gyroADC[PITCH] = -X; imu.gyroADC[YAW] = -Z;}
#define MAG_ORIENTATION(X, Y, Z)  {imu.magADC[ROLL]  =  X; imu.magADC[PITCH]  =  Y; imu.magADC[YAW]  = -Z;}
	ACC_getADC();
	Gyro_getADC();
	Device_Mag_getADC();
	
	Serial.print("Mag:");                         //magnetometer values
	Serial.print(imu.magADC[ROLL]);
	Serial.print(',');
	Serial.print(imu.magADC[PITCH]);
	Serial.print(',');
	Serial.print(imu.magADC[YAW]);
	Serial.print(' ');

	Serial.print("Acc:");                         //accelerometer values
	Serial.print(imu.accADC[ROLL]);
	Serial.print(',');
	Serial.print(imu.accADC[PITCH]);
	Serial.print(',');
	Serial.print(imu.accADC[YAW]);
	Serial.print(' ');

	Serial.print("gyro:");                        //gyroscope values
	Serial.print(imu.gyroADC[ROLL]);
	Serial.print(',');
	Serial.print(imu.gyroADC[PITCH]);
	Serial.print(',');
	Serial.print(imu.gyroADC[YAW]);
	Serial.println(' ');

	delay(1000);

}
