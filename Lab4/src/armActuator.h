/*
 * armActuator.h
 *
 *  Created on: Jan 31, 2014
 *      Author: Steven Kordell
 */


#ifndef ARMACTUATOR_H_
#define ARMACTUATOR_H_

#include "main.h"

#define POT_ANGLE 314	//http://media.digikey.com/pdf/Data%20Sheets/Precision%20Electronic%20Components%20Ltd%20PDFs/MIL%20Style%20RV4.pdf
#define ADC_RANGE 1023
//Information for the potentiometer reading from the top link
#define HIGH_POT0_ADC_CENTER 680
#define HIGH_POT90_ADC_MAX 1020
#define HIGH_POT_ADC_RANGE (HIGH_POT90_ADC_MAX-HIGH_POT0_ADC_CENTER)
#define HIGH_POT_DEG_PER_BIT ((float)90/HIGH_POT_ADC_RANGE)
//Information for the potentiometer reading from the bottom link
#define LOW_POT0_ADC_CENTER 280
#define LOW_POT90_ADC_MAX 625   //By hand: 550
#define LOW_POT_ADC_RANGE (LOW_POT90_ADC_MAX-LOW_POT0_ADC_CENTER)
#define LOW_POT_DEG_PER_BIT ((float)90/LOW_POT_ADC_RANGE)



void driveLink(char whichLink, signed int value);
void driveLinks();
void driveLinkPercent(char whichLink, float value);
float getLinkAngle(char link);
void setLinkAngle(char link, float angle);
float getLinkSetPointAngle(char link);
void setArmPosition(float x, float y);
void printArmConfiguration();
void homeArm();

#endif /* ARMACTUATOR_H_ */
