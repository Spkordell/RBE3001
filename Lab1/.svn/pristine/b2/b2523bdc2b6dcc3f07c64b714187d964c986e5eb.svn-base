/*
 * timeStamp.c
 *
 *  Created on: Jan 25, 2014
 *      Author: Steven Kordell, Cody Wall-Epstein, Jiaqi ren
 *
 *      Functions for keeping track of time in an HH:MM:SS format.
 *
 */



#include "main.h"

/*
 * Initializes the time-keeping
 */
void initTimeStamp(void){
	InitTimer(1,NORMAL,0);
}

/*
 * Increments minutes and hours based upon the value of seconds for timekeeping
 */
void timeStamp(void){
	if(globals.Second >= 60){
		globals.Minute++;
		globals.Second = 0;
	}

	else if(globals.Minute >= 60){
		globals.Hour++;
		globals.Minute = 0;
	}
}

/*
 * The ISR which is triggered to keep the time.
 */
ISR(TIMER1_OVF_vect){
	if (globals.timeStamp >= (F_CPU/TIMERMAXCOUNT16)) {
		globals.timeStamp = 0;
		globals.Second++;
	}
	globals.timeStamp++;
	timeStamp();
}
