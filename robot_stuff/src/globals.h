/*
* globals.h
*
* Created on: Feb 6, 2013
* Author:
joest
*/
#ifndef GLOBALS_H_
#define GLOBALS_H_

typedef struct {
	double timeCount;
} Globals;

extern Globals globals; // declaration

void initGlobals();

#endif /* GLOBALS_H_ */
