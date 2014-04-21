/*
 * kinematics.h
 *
 *  Created on: Feb 5, 2014
 *      Author: Steven Kordell
 */


#ifndef KINEMATICS_H_
#define KINEMATICS_H_

#include "main.h"

#define LOW_LINK_LENGTH 128//.016 //mm
#define HIGH_LINK_LENGTH 102//.616 //mm

#define RADIANS_PER_DEGREE 0.0174532925
#define DEGREES_PER_RADIAN 57.2957795


void calcFPK(float* x, float* y, float lowLinkAngle, float highLinkAngle);
void calcIPK(float* lowLinkAngle, float* highLinkAngle, float x, float y);

#endif /* KINEMATICS_H_ */
