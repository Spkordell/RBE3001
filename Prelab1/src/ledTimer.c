/*
 * ledTimer.c
 *
 *  Created on: Jan 20, 2014
 *      Author: Steven Kordell
 */

#include "main.h"

void initializeTimerAndLED() {
	// Set output direction on LED (PB0) //Set bit high
	DDRB |= (1 << LED);

	//disable global interrupts while we set up the timer
	cli();
    //Initialize counter to 0
    TCNT1 = 0;

    //set clock prescaler to clk/64
    TCCR1Bbits._CS12 = 0;
    TCCR1Bbits._CS11 = 1;
    TCCR1Bbits._CS10 = 1;

	//enable Timer1 overflow interrupt:
    TIMSK1bits._TOIE1 = 1;

    //Enable Timer1 interrupt flag
    TIFR1bits._TOV1 = 1;

    //enable global interrupts
    sei();
}

void blinkLEDWithTimer() {
	initializeTimerAndLED();
	while(1) {
	}
}

ISR(TIMER1_OVF_vect) {
	//Toggle the pin when the interrupt is called
	PORTB ^= (1 << LED);
}
