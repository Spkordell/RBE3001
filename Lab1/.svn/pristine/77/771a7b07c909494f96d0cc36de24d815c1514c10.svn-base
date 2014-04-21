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
	DDRD &= ~(PD7|PD6|PD5|PD4); //clear bits

	//enable pin change interrupts

	PCMSK3bits._PCINT31 = 1;
	PCMSK3bits._PCINT30 = 1;
	PCMSK3bits._PCINT29 = 1;
	PCMSK3bits._PCINT28 = 1;
	//enable pin change interrupts
	PCICRbits._PCIE3 = 1;
	//Clear interrupt flag register
	PCIFRbits._PCIF3 = 1;

	sei();
}



