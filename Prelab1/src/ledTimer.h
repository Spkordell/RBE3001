/*
 * ledTimer.h
 *
 *  Created on: Jan 20, 2014
 *      Author: Steven Kordell
 */

#ifndef LEDTIMER_H_
#define LEDTIMER_H_

#include "main.h"

#define LED PB0 // Define ext led pin on PB0

void initializeTimerAndLED();
void blinkLEDWithTimer();

#endif /* LEDTIMER_H_ */
