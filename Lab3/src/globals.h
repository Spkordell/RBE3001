/*
* globals.h
*
* Created on: Feb 6, 2013
* Author: Steven Kordell, Cody Wall-Epstein, Jiaqi ren
*
* Defines and declares the global struct.
*
*/
#ifndef GLOBALS_H_
#define GLOBALS_H_

#include "main.h"

typedef struct {
	volatile uint8_t timer2MaxCount;
	volatile uint8_t timer2CurrentCount;
	volatile uint8_t timer2Triggered;
} Globals;

extern Globals globals; // declaration

void initGlobals();

#endif /* GLOBALS_H_ */
