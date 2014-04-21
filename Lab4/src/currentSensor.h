/*
 * currentSensor.h
 *
 *  Created on: Feb 1, 2014
 *      Author: Steven Kordell
 */


#ifndef CURRENTSENSOR_H_
#define CURRENTSENSOR_H_

#define CURRENT_SENSOR_GAIN 20
#define CURRENT_SENSOR_OFFSET 2.5
#define CURRENT_SENSOR_RESISTOR 0.05
#define ADC_RESOLUTION 1023
#define VCC 5

#include "main.h"

/*
 * Converts raw ADC measurement from the current sensor into the current in A
 */
float calculateCurrent(int ADCValue);


#endif /* CURRENTSENSOR_H_ */
