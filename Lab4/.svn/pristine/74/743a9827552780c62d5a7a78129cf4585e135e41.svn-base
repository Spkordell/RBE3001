/*
 * currentSensor.c
 *
 *  Created on: Feb 1, 2014
 *      Author: Steven Kordell
 */

#include "main.h"

/*
 * Converts raw ADC measurement from the current sensor into the current in A
 */
float calculateCurrent(int ADCValue) {
	return (((float)(ADCValue*((float)VCC/ADC_RESOLUTION)) - CURRENT_SENSOR_OFFSET)/CURRENT_SENSOR_GAIN)/CURRENT_SENSOR_RESISTOR;
}

