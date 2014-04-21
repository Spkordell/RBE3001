/*
 * armActuator.c
 *
 *  Created on: Jan 31, 2014
 *      Author: Steven Kordell
 */

#include "main.h"

/*
 * Ths function sends the DAC commands to set the voltage of a motor for a specific link
 */
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

/*
 * This function allows one to drive a certian link motor at some percentage of its full power
 */
void driveLinkPercent(char whichLink, float value){
	driveLink(whichLink,DAC_MAX_VALUE*value);
}

/*
 * This function retuns the current angle of a given link in degrees
 */
float getLinkAngle(char link) {
	if (link == 'H') {
		return ((float)ADCVars.ADCValues[ARM_HIGH_LINK_POT]-HIGH_POT0_ADC_CENTER)*HIGH_POT_DEG_PER_BIT;
	} else if(link == 'L'){
		return ((float)ADCVars.ADCValues[ARM_LOW_LINK_POT]-LOW_POT0_ADC_CENTER)*LOW_POT_DEG_PER_BIT;
	} else {
		return 0;
	}
}

/*
 * This functions sets the desired angle of a link in degrees. If PID is running, the arm will attempt to move the link to the specified angle
 */
void setLinkAngle(char link, float angle) {
	if (link == 'H') {
		pidConst.highLinkSetPoint = ((float)HIGH_POT_ADC_RANGE/90)*angle + HIGH_POT0_ADC_CENTER;
	} else if(link == 'L'){
		pidConst.lowLinkSetPoint = ((float)LOW_POT_ADC_RANGE/90)*angle + LOW_POT0_ADC_CENTER;
	}
}

/*
 *This function allows one to retrieve the desired link angle set by the user
 */
float getLinkSetPointAngle(char link) {
	if (link == 'H') {
		return ((float)pidConst.highLinkSetPoint-HIGH_POT0_ADC_CENTER)*HIGH_POT_DEG_PER_BIT;
	} else if(link == 'L'){
		return ((float)pidConst.lowLinkSetPoint-LOW_POT0_ADC_CENTER)*LOW_POT_DEG_PER_BIT;
	} else {
		return 0;
	}
}

/*
 * This function uses inverse kinematics to move the arm to a desired cartesion position. PID must be running.
 */
void setArmPosition(float x, float y) {
	float lowLinkAngle;
	float highLinkAngle;
	calcIPK(&lowLinkAngle, &highLinkAngle, x, y);
	setLinkAngle('L',lowLinkAngle);
	setLinkAngle('H',highLinkAngle);
}

/*
 * This function will drive both links based on the output from the PID controller and gravity compensation.
 */
void driveLinks() {
	driveLink('H',pidConst.highLinkPIDOut+((int)cos(getLinkAngle('H')*RADIANS_PER_DEGREE)*500)); //500 is m*l*g
	driveLink('L',pidConst.lowLinkPIDOut+((int)cos(getLinkAngle('L')*RADIANS_PER_DEGREE)*500)); //500 is m*l*g
}

/*
 * This function on will move the arm to its homing position and reset the encoder counts
 */
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
/*
 * This function will print the arm's current configuration as a set of joint angles to the terminal
 */
void printArmConfiguration() {
	p_sl(getLinkAngle('H'));
	print(",");
	p_sl(getLinkAngle('L'));
	println("");
}

