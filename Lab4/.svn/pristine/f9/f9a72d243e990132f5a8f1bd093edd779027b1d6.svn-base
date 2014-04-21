/*
 * currentSensor.c
 *
 *  Created on: Feb 1, 2014
 *      Author: Steven Kordell
 */

#include "main.h"

float calculateCurrent(int ADCValue) {
	return (((float)(ADCValue*((float)VCC/ADC_RESOLUTION)) - CURRENT_SENSOR_OFFSET)/CURRENT_SENSOR_GAIN)/CURRENT_SENSOR_RESISTOR;
}

