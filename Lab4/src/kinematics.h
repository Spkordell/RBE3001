/*
 * kinematics.h
 *
 *  Created on: Feb 5, 2014
 *      Author: Steven Kordell
 */


#ifndef KINEMATICS_H_
#define KINEMATICS_H_

#include "main.h"

#define LOW_LINK_LENGTH 128 //mm //length of the low link
#define HIGH_LINK_LENGTH  102 //mm //length of the high link

#define LOW_LINK_LENGTH_2 (LOW_LINK_LENGTH*LOW_LINK_LENGTH) //square of low link length (for cleaner code)
#define HIGH_LINK_LENGTH_2 (HIGH_LINK_LENGTH*HIGH_LINK_LENGTH) //square of high link length (for cleaner code)

#define RADIANS_PER_DEGREE 0.0174532925 //conversion factor for radians to degrees
#define DEGREES_PER_RADIAN 57.2957795 //conversion factor for degrees to radians


void calcFPK(float* x, float* y, float lowLinkAngle, float highLinkAngle);
void calcIPK(float* lowLinkAngle, float* highLinkAngle, float x, float y);

#endif /* KINEMATICS_H_ */
