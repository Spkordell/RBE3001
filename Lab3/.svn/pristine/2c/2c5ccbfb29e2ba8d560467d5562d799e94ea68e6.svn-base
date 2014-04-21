/*
 * accelerometer.h
 *
 *  Created on: Feb 12, 2014
 *      Author: Steven Kordell
 */


#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_

#include "main.h"

#define ACCEL_SS 0 //PORT D

//Conversion constants
#define Cnt2Mv 0xCE4C // millivolts conversion, ^ 0.80586
#define GfCnv  0x3852 //g-force conversion, ^ 0.22

typedef struct {
	volatile int16_t vref;
	volatile int16_t x;
	volatile int16_t y;
	volatile int16_t z;
	volatile uint8_t newDataAvailable;
	volatile uint8_t timerMaxCount;
	volatile uint8_t timerCurrentCount;
} Accel;

extern Accel accel;

void initAccelerometer();
void initAccelerometerWithTimer();
int16_t GetAccelerationH48C(char axis);
float convertAccelmV(int16_t accelValue);
float convertAccelGforce(int16_t accelValue);

#endif /* ACCELEROMETER_H_ */
