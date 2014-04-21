/*
 * ledButton.c
 *
 *  Created on: Jan 19, 2014
 *      Author: Steven Kordell
 */

#include "main.h"

/*
 * Initializes direction registers for LED and BUTTON
 */
void initializeButtonAndLED() {
	 //DDRB |= (1 << LED); // Set output direction on LED //Set bit high
	 //DDRD &= ~(1 << BUTTON); // Set input direction on BUTTON //set bit low
	DDRBbits._P0 = OUTPUT; //LED
	DDRDbits._P4 = INPUT; //SWITCH
}

/*
 * LED state copies that of the button. Doesn't return from call.
 */
void lightLEDForButton() {
	initializeButtonAndLED();
	while(1) {
		//If the switch is pressed, turn on the LED, else, turn off the LED
		//PORTB = PINB & (1 << BUTTON) ? PORTB | (1 << LED) : PORTD & ~(1 << BUTTON);
		PORTBbits._P0 = PINDbits._P4;
	}
}
