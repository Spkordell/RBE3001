/*
 * externalInterrupt.c
 *
 *  Created on: Jan 25, 2014
 *      Author: Steven Kordell, Cody Wall-Epstein, Jiaqi ren
 *
 *      This file contains a function for configuring the buttons on the RBE3001 board to function as interrupts
 *
 */

#include "main.h"

/*
 * Configures the four buttons connected o pins D4 through D7 to trigger Pin Change interrupts
 */
void configureButtonInterrupts() {
	cli();
	//configure buttons as inputs
	DDRC &= ~(PC7|PC6|PC5|PC4); //clear bits

	//enable pin change interrupts
	PCMSK2bits._PCINT23 = 1;
	PCMSK2bits._PCINT22 = 1;
	PCMSK2bits._PCINT21 = 1;
	PCMSK2bits._PCINT20 = 1;
	//enable pin change interrupts
	PCICRbits._PCIE2 = 1;
	//Clear interrupt flag register
	PCIFRbits._PCIF2 = 1;

	sei();
}



