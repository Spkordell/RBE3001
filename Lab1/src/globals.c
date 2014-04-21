/*
 * globals.c
 *
 *  Created on: Jan 22, 2014
 *      Author: Steven Kordell, Cody Wall-Epstein, Jiaqi ren
 *
 *      This file contains a function to initialize all the variables in the Global struct.
 *
 */

#include "main.h"

/*
 * Initalize all the variables in the global struct
 */
void initGlobals() {
	globals.timeStamp = 0;
	globals.Second = 0;
	globals.Minute = 0;
	globals.Hour = 0;
	globals.PWMPort = 'A';
	globals.PWMPin = 0;
	globals.PWMMaxTime = 0;
	globals.PWMCurrentCount = 0;
	globals.PWMHighTime = 0;
	globals.PWMCompare = 0;
	globals.PWMDuty = 0;
	globals.PWMFrequency = 0;
	globals.sampleDataAvailable = 0;
	globals.elapsedCycles = 0;
}
