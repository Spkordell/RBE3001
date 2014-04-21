/*
 * armActuator.c
 *
 *  Created on: Jan 31, 2014
 *      Author: Steven Kordell
 */

#include "main.h"

void driveLink(char link, signed int value){
	if(link == 'L') {
		if(value >= 0){
			setDAC(0,value);
			setDAC(1,0);
		} else {
			setDAC(0,0);
			setDAC(1,-value);
		}
	} else if (link == 'H'){
		if(value >= 0){
			setDAC(2,0);
			setDAC(3,value);
		} else {
			setDAC(2,-value);
			setDAC(3,0);
		}
	}
}

void driveLinkPercent(char whichLink, float value){
	driveLink(whichLink,DAC_MAX_VALUE*value);
}

float getLinkAngle(char link) {
	if (link == 'H') {
		return ((float)ADCVars.ADCValues[ARM_HIGH_LINK_POT]-HIGH_POT0_ADC_CENTER)*HIGH_POT_DEG_PER_BIT;
	} else if(link == 'L'){
		return ((float)ADCVars.ADCValues[ARM_LOW_LINK_POT]-LOW_POT0_ADC_CENTER)*LOW_POT_DEG_PER_BIT;
	} else {
		return 0;
	}
}

void setLinkAngle(char link, float angle) {
	if (link == 'H') {
		pidConst.highLinkSetPoint = ((float)HIGH_POT_ADC_RANGE/90)*angle + HIGH_POT0_ADC_CENTER;
	} else if(link == 'L'){
		pidConst.lowLinkSetPoint = ((float)LOW_POT_ADC_RANGE/90)*angle + LOW_POT0_ADC_CENTER;
	}
}


float getLinkSetPointAngle(char link) {
	if (link == 'H') {
		return ((float)pidConst.highLinkSetPoint-HIGH_POT0_ADC_CENTER)*HIGH_POT_DEG_PER_BIT;
	} else if(link == 'L'){
		return ((float)pidConst.lowLinkSetPoint-LOW_POT0_ADC_CENTER)*LOW_POT_DEG_PER_BIT;
	} else {
		return 0;
	}
}

void setArmPosition(float x, float y) {
	float lowLinkAngle;
	float highLinkAngle;
	calcIPK(&lowLinkAngle, &highLinkAngle, x, y);
	setLinkAngle('L',lowLinkAngle);
	setLinkAngle('H',highLinkAngle);
	/*
	p_fl(lowLinkAngle);
	print("\t");
	p_fl(highLinkAngle);
	println("");
	*/
}

void driveLinks() {
	//todo, move gravity compensation functions to kinematics.c
	driveLink('H',pidConst.highLinkPIDOut+((int)cos(getLinkAngle('H')*RADIANS_PER_DEGREE)*500)); //500 is m*l*g
	driveLink('L',pidConst.lowLinkPIDOut+((int)cos(getLinkAngle('L')*RADIANS_PER_DEGREE)*500)); //500 is m*l*g
}


void homeArm() {
	//Move the arm to the zero position
	setLinkAngle('L',0);
	setLinkAngle('H',0);
	//wait for arm to settle
	while (pidConst.highLinkSetPoint != ADCVars.ADCValues[ARM_HIGH_LINK_POT] || pidConst.lowLinkSetPoint != ADCVars.ADCValues[ARM_LOW_LINK_POT]) {
		driveLinks();
	}

	//reset encoder counts
	resetEncoderCounts();
}


