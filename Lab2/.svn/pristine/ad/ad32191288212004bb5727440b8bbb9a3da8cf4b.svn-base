/*
 * shape.h
 *
 *  Created on: Feb 10, 2014
 *      Author: Steven Kordell
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include "main.h"

typedef struct {
	volatile float lowAngle1;
	volatile float highAngle1;
	volatile float dLowAngle;
	volatile float dHighAngle;
	volatile float t; //This variable ranges from 0 to 1. When it equals 1, the shape has finished drawing.
	volatile float rateTimerMaxCount;
	volatile float rateTimerCurrentCount;
	volatile float resolution;
	//volatile char shapeBufferEmpty;
	//volatile char* shapeBuffer;
} ShapeVars;

/**
* @brief Declaration for use in other files.
*/
extern ShapeVars shapeVars;

void smoothArc(float lowAngle1, float highAngle1, float lowAngle2, float highAngle2, float rate, float resolution);
/*
void fillShapeBuffer(char* bufferValues);
void drawLine(float x1, float y1, float x2, float y2, float resolution);
void drawEqTriangle(float centerX, float centerY, float size, float resolution);
*/

#endif /* SHAPE_H_ */
