/*
* portB.c
*
* Created on: Jul 4, 2013
* Author: joest
*/
#include "main.h"

void initPB() {
	DDRB = PORT_OUTPUT;
}

void blinkAll(double timeDelay) {
	PORTB = 0xFF;
	_delay_ms(timeDelay);
	PORTB = 0x00;
	_delay_ms(timeDelay);
}
